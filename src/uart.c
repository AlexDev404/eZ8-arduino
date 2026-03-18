/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/
#include "uart.h"

/* System clock frequency in Hz - must match actual oscillator */
#define SYSTEM_CLOCK_HZ     5529600UL   /* 5.5296 MHz internal oscillator */
#define BAUD_RATE           115200UL    /* Target baud rate for avrdude */

/* Calculate baud rate divisor: BRG = (freq + baud*8) / (baud * 16) */
#define BRG_VALUE ((SYSTEM_CLOCK_HZ + BAUD_RATE * 8UL) / (BAUD_RATE * 16UL))

void init_uart0(void)
{
    /* Initialize UART0 for STK500 communication
     * Direct register configuration for reliable baud rate
     * at 5.5296 MHz system clock with 115200 baud.
     * 
     * BRG = (5529600 + 115200*8) / (115200*16) = 6451200 / 1843200 = 3
     * Actual baud = 5529600 / (16 * 3) = 115200 (exact!)
     */
    
    /* Set baud rate generator */
    U0BRH = (unsigned char)(BRG_VALUE >> 8);   /* High byte = 0 */
    U0BRL = (unsigned char)(BRG_VALUE & 0xFF); /* Low byte = 3 */
    
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
