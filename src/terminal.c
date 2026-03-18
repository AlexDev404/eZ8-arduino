/*
 * STK500v1 Protocol Handler for Z8 Encore!
 * Based on optiboot structure - uses polling loop, not interrupts
 * 
 * Copyright (c) 2024 AlexDev404 (Immanuel DGarcia)
 */

#include "terminal.h"
#include "stk500.h"
#include "util.h"
#include "boot_tools.h"
#include "flash_tools.h"

/* STK500 protocol constants for parameter byte counts */
#define STK_SET_DEVICE_PARAM_COUNT     20  /* SET_DEVICE has 20 parameter bytes */
#define STK_SET_DEVICE_EXT_PARAM_COUNT  5  /* SET_DEVICE_EXT has 5 parameter bytes */

/* UART0 register bit definitions (from uartdefs.h) */
#define UART_STAT0_RDA    0x80  /* Receive Data Available */
#define UART_STAT0_TDRE   0x04  /* Transmit Data Register Empty */
#define UART_STAT0_TXE    0x02  /* Transmitter Empty */

/* Protocol debug mode - shows commands received from avrdude
 * Enable via PROTOCOL_DEBUG=1 in main.c or compiler flag */
#ifndef PROTOCOL_DEBUG
#define PROTOCOL_DEBUG 0
#endif

/*
 * Direct UART I/O functions - bypass ZSL library for reliable binary protocol
 * These match optiboot's approach: simple polling, no buffering, no conversions
 */

/*
 * uart_getchar - Get one character from UART (blocking)
 * Direct register access like optiboot's getch()
 */
static unsigned char uart_getchar(void) {
    /* Wait for Receive Data Available */
    while (!(U0STAT0 & UART_STAT0_RDA))
        ;
    return U0RXD;
}

/*
 * uart_putchar - Send one character to UART (blocking)
 * Direct register access like optiboot's putch()
 * NO newline conversion - critical for binary protocols!
 */
static void uart_putchar(unsigned char ch) {
    /* Wait for Transmit Data Register Empty */
    while (!(U0STAT0 & UART_STAT0_TDRE))
        ;
    U0TXD = ch;
    /* Wait for transmit complete to ensure byte is sent */
    while (!(U0STAT0 & UART_STAT0_TXE))
        ;
}

#if PROTOCOL_DEBUG
/* Send hex representation of a byte for debugging */
static void debug_put_hex(unsigned char ch) {
    const char hex[] = "0123456789ABCDEF";
    uart_putchar('[');
    uart_putchar(hex[(ch >> 4) & 0x0F]);
    uart_putchar(hex[ch & 0x0F]);
    uart_putchar(']');
}
#endif

/* Current address pointer for flash operations */
static rom unsigned char* address = (rom unsigned char*)0x1000;

/* Flag to track if verifySpace succeeded */
static UINT8 sync_ok = 1;

/* Page buffer for PROG_PAGE - placed at file scope to reduce stack usage
 * 256 bytes matches typical AVR page size and is sufficient for STK500 protocol */
static unsigned char page_buffer[256];

/*
 * verifySpace - Read and verify CRC_EOP byte, then send INSYNC
 * This matches optiboot's verifySpace() function
 * Sets sync_ok flag to indicate success/failure
 */
static void verifySpace(void) {
    unsigned char eop = uart_getchar();
    
#if PROTOCOL_DEBUG
    /* Show received EOP byte */
    uart_putchar('E');
    debug_put_hex(eop);
#endif
    
    if (eop != SPECIAL_Sync_CRC_EOP) {
        /* Protocol error - send NOSYNC and set flag */
#if PROTOCOL_DEBUG
        uart_putchar('N');  /* N for NOSYNC */
#endif
        uart_putchar(STK_NOSYNC);
        sync_ok = 0;
        return;
    }
    
#if PROTOCOL_DEBUG
    uart_putchar('I');  /* I for INSYNC */
#endif
    uart_putchar(STK_INSYNC);
    sync_ok = 1;
}

/*
 * getNch - Read n bytes and then verify space
 * Matches optiboot's getNch() function
 */
static void getNch(UINT8 count) {
    do {
        uart_getchar();
    } while (--count);
    verifySpace();
}

/*
 * Main STK500 command processing loop
 * This runs forever, polling for commands from avrdude
 * Structure matches optiboot's main loop
 */
void stk500_loop(void) {
    UINT8 ch;
    
#if PROTOCOL_DEBUG
    /* Send startup marker for protocol debug mode */
    uart_putchar('P');
    uart_putchar('D');
    uart_putchar(':');
#endif
    
    /* Forever loop - process STK500 commands */
    for (;;) {
        /* Reset sync flag at start of each command */
        sync_ok = 1;
        
        /* Get command byte from UART (blocking poll) */
        ch = uart_getchar();
        
#if PROTOCOL_DEBUG
        /* Show received command byte */
        debug_put_hex(ch);
#endif
        
        if (ch == CMD_STK_GET_SYNC) {
            /* GET_SYNC - used to establish communication */
            verifySpace();
        }
        else if (ch == CMD_STK_GET_PARAMETER) {
            /* GET_PARAMETER - return version info etc */
            UINT8 which = uart_getchar();
            verifySpace();
            
            if (sync_ok) {
                if (which == PARAM_STK_SW_MINOR) {
                    uart_putchar(SW_MINOR);
                } else if (which == PARAM_STK_SW_MAJOR) {
                    uart_putchar(SW_MAJOR);
                } else if (which == PARAM_STK_HW_VER) {
                    uart_putchar(HW_VER);
                } else {
                    /* Return 0x03 for unknown parameters (keeps avrdude happy) */
                    uart_putchar(0x03);
                }
            }
        }
        else if (ch == CMD_STK_SET_DEVICE) {
            /* SET_DEVICE - receive device parameters per STK500 protocol */
            getNch(STK_SET_DEVICE_PARAM_COUNT);
        }
        else if (ch == CMD_STK_SET_DEVICE_EXT) {
            /* SET_DEVICE_EXT - receive extended parameters per STK500 protocol */
            getNch(STK_SET_DEVICE_EXT_PARAM_COUNT);
        }
        else if (ch == CMD_STK_LOAD_ADDRESS) {
            /* LOAD_ADDRESS - receive word address (low, high) */
            UINT16 newAddress;
            newAddress = (UINT16)uart_getchar();          /* Low byte */
            newAddress |= ((UINT16)uart_getchar() << 8);  /* High byte */
            newAddress *= 2;  /* Convert word address to byte address */
            /* Add base offset for our flash area */
            address = (rom unsigned char*)(0x1000 + newAddress);
            verifySpace();
        }
        else if (ch == CMD_STK_UNIVERSAL) {
            /* UNIVERSAL - ISP command passthrough (4 bytes) */
            uart_getchar();  /* byte 1 */
            uart_getchar();  /* byte 2 */
            uart_getchar();  /* byte 3 */
            uart_getchar();  /* byte 4 */
            verifySpace();
            if (sync_ok) {
                uart_putchar(0x00);  /* Return dummy result */
            }
        }
        else if (ch == CMD_STK_PROG_PAGE) {
            /* PROG_PAGE - program a page of flash
             * CRITICAL: Must buffer all data first, then verify, then program.
             * This matches optiboot's approach and prevents UART buffer overflow
             * during slow flash programming operations.
             */
            unsigned int length;
            unsigned long addrPtr;
            unsigned int i;
            
            /* Get length (big endian) */
            length = ((unsigned int)uart_getchar() << 8);  /* High byte */
            length |= uart_getchar();                       /* Low byte */
            
            uart_getchar();  /* Skip memory type (we only support flash) */
            
            /* First: Buffer ALL incoming data bytes (like optiboot does) */
            for (i = 0; i < length; i++) {
                page_buffer[i] = uart_getchar();
            }
            
            /* Verify space (read CRC_EOP and send INSYNC) BEFORE programming */
            verifySpace();
            
            if (sync_ok) {
                addrPtr = (unsigned long)address;
                
                /* Erase page if in our target range */
                if (addrPtr >= 0x1000 && addrPtr < 0x2000) {
                    UINT16 pageAddr = addrPtr & ~0x1FF;  /* Page-align */
                    pageEraseFlash(pageAddr);
                    while (FCMD != 0x03);  /* Wait for completion */
                }
                
                /* Program each byte from buffer */
                for (i = 0; i < length; i++) {
                    programFlashByte(addrPtr, page_buffer[i]);
                    while (FCMD != 0x03);  /* Wait for completion */
                    addrPtr++;
                }
                
                /* Update address for next operation */
                address = (rom unsigned char*)addrPtr;
            }
        }
        else if (ch == CMD_STK_READ_PAGE) {
            /* READ_PAGE - read a page of flash */
            unsigned int length;
            unsigned long addrPtr;
            unsigned int i;
            
            /* Get length (big endian) */
            length = ((unsigned int)uart_getchar() << 8);  /* High byte */
            length |= uart_getchar();                       /* Low byte */
            
            uart_getchar();  /* Skip memory type */
            
            verifySpace();
            
            if (sync_ok) {
                /* Send flash contents */
                addrPtr = (unsigned long)address;
                for (i = 0; i < length; i++) {
                    uart_putchar(flash_read_byte(addrPtr++));
                }
                
                /* Update address for next operation */
                address = (rom unsigned char*)addrPtr;
            }
        }
        else if (ch == CMD_STK_READ_SIGN) {
            /* READ_SIGN - return device signature */
            verifySpace();
            if (sync_ok) {
                uart_putchar(PROPS_SIGNATURE_H);
                uart_putchar(PROPS_SIGNATURE_M);
                uart_putchar(PROPS_SIGNATURE_L);
            }
        }
        else {
            /* For all other commands (ENTER_PROGMODE, LEAVE_PROGMODE, 
             * CHIP_ERASE, SET_PARAMETER, etc), just verify and acknowledge */
            verifySpace();
        }
        
        /* Send STK_OK at end of every command (only if sync was OK) */
        if (sync_ok) {
#if PROTOCOL_DEBUG
            uart_putchar('O');  /* O for OK */
#endif
            uart_putchar(STK_OK);
        }
    }
}
