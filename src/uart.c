/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/
#include "uart.h"
#include "terminal.h"

void init_uart0(void)
{
    init_uart(_UART0,_DEFFREQ, BAUD_115200); // Setup Uart0 
    select_port(_UART0);				 // Select port
	SET_VECTOR(UART0_RX, isr_uart0_rx);  // Define interrupt routine
	IRQ0ENH |= 0x10;					// Set Interrupt Priority High
	IRQ0ENL |= 0x10;					// Set Interrupt Priority High
}
