/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/
#include "uart.h"

/*
 * UART Baud Rate Configuration for Z8F082A
 * 
 * The Z8F082A internal RC oscillator varies between parts.
 * Configure SYSTEM_CLOCK_HZ to match your actual oscillator frequency.
 * 
 * IMPORTANT: avrdude command must specify matching baud rate:
 *   avrdude -c arduino -b 115200 -P COM3 ...
 * 
 * Common Clock Frequencies and BRG values for 115200 baud:
 *   5.5296 MHz: BRG = 3  (actual 115200, 0% error) - exact!
 *   18.432 MHz: BRG = 10 (actual 115200, 0% error) - exact!
 *   20.0 MHz:   BRG = 11 (actual 113636, -1.4% error)
 *
 * If you get random garbage responses, try different SYSTEM_CLOCK_HZ values:
 *   - 5529600UL  (5.5296 MHz - standard internal RC)
 *   - 5500000UL  (5.5 MHz - alternate internal RC)
 *   - 18432000UL (18.432 MHz - external crystal)
 *   - 20000000UL (20 MHz - external crystal)
 */

/* System clock frequency - CRITICAL: Must match your actual oscillator!
 * The Z8F082A internal RC is nominally 5.5296 MHz.
 * If you get garbled responses, try 5500000UL or measure with scope. */
#ifndef SYSTEM_CLOCK_HZ
#define SYSTEM_CLOCK_HZ     5529600UL   /* 5.5296 MHz internal oscillator */
#endif

/* Baud rate - using 115200 to match Arduino default bootloader */
#ifndef BAUD_RATE
#define BAUD_RATE           115200UL
#endif

/* Calculate baud rate divisor: BRG = (freq + baud*8) / (baud * 16)
 * This formula rounds to nearest integer for best accuracy */
#define BRG_VALUE ((SYSTEM_CLOCK_HZ + BAUD_RATE * 8UL) / (BAUD_RATE * 16UL))

void init_uart0(void)
{
    /* Initialize UART0 for STK500 communication
     * For 5.5296 MHz @ 115200 baud:
     * BRG = (5529600 + 115200*8) / (115200*16) = 6451200 / 1843200 = 3
     * Actual baud = 5529600 / (16 * 3) = 115200 (exact!)
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
