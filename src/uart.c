/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/
#include "uart.h"

/*
 * UART Baud Rate Configuration for Z8F082A
 * 
 * The Z8F082A internal RC oscillator varies between parts (~5.5 MHz typical).
 * Using 19200 baud provides better tolerance for clock variation than 115200.
 * 
 * IMPORTANT: avrdude command must specify matching baud rate:
 *   avrdude -c stk500v1 -b 19200 -P /dev/ttyUSB0 ...
 * 
 * Clock Frequency Options:
 *   5.5296 MHz (Internal RC): BRG = 18 for 19200 baud (exact)
 *   18.432 MHz (Crystal):     BRG = 60 for 19200 baud (exact)
 *   20.0 MHz (Crystal):       BRG = 65 for 19200 baud (0.16% error)
 */

/* System clock frequency - adjust to match your actual oscillator */
#define SYSTEM_CLOCK_HZ     5529600UL   /* 5.5296 MHz internal oscillator */

/* Baud rate - using 19200 for better tolerance with RC oscillator */
#define BAUD_RATE           19200UL

/* Calculate baud rate divisor: BRG = (freq + baud*8) / (baud * 16) */
#define BRG_VALUE ((SYSTEM_CLOCK_HZ + BAUD_RATE * 8UL) / (BAUD_RATE * 16UL))

void init_uart0(void)
{
    /* Initialize UART0 for STK500 communication
     * BRG = (5529600 + 19200*8) / (19200*16) = 5683200 / 307200 = 18
     * Actual baud = 5529600 / (16 * 18) = 19200 (exact!)
     */
    
    /* Set baud rate generator */
    U0BRH = (unsigned char)(BRG_VALUE >> 8);   /* High byte */
    U0BRL = (unsigned char)(BRG_VALUE & 0xFF); /* Low byte */
    
    /* Configure GPIO Port A pins 4 & 5 for UART alternate function */
    PAADDR = 0x02;              /* Select alternate function register */
    PACTL |= 0x30;              /* Set bits 4,5 for alternate function */
    PAADDR = 0x07;              /* Select alt function set-1 register */
    PACTL &= 0xCF;              /* Clear bits 4,5 */
    PAADDR = 0x08;              /* Select alt function set-2 register */
    PACTL &= 0xCF;              /* Clear bits 4,5 */
    PAADDR = 0x00;              /* Reset to default address */
    
    /* UART control settings */
    U0CTL1 = 0x00;              /* No multiprocessor mode */
    U0CTL0 = 0xC0;              /* TEN=1 (TX enable), REN=1 (RX enable), 
                                 * no parity, 1 stop bit, no loopback */
}
