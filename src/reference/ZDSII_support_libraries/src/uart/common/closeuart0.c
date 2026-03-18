/*!\file closeuart0.c
 * \brief Implementation file for closing UART0 Device.
 *
 *  This file contains implementation for closing the UART0
 *  device required by UART driver implementations for Z8 Encore! microcontrollers.
 *
 *  This source file uses Doxygen-style comments to generate documentation
 *  automatically.
 *
 *  Copyright (C) 1999-2004 by  ZiLOG, Inc.
 *  All Rights Reserved.
 */

#include <ez8.h>
#include <uartcontrol.h>


/*!
 \ingroup UART
*/
/*!
@{
*/

/*!
 * Close the UART0 device.
 *
 * This close_UARTx() API is used to close the UART device. Calling this API disables all the 
 * interrupts related to default UART device, and clears all the control registers so as to render 
 * the UART device useless after this call.The application can use the UART again only after making a call to open_UARTx() call.

 */
/*!
@}
*/

VOID close_UART0( VOID )
{
	U0CTL0 = 0 ;

#if (UART0_MODE == MODE_INTERRUPT)
	IRQ0ENH = IRQ0ENH&(~(IRQ_U0RXI|IRQ_U0TXI)) ;
	IRQ0ENL = IRQ0ENL&(~(IRQ_U0RXI|IRQ_U0TXI)) ;
#endif
	
	setmodeInput_PortA( PORTPIN_FOUR|PORTPIN_FIVE ) ;


	
	return ;

}//! end of close_UART0()



/*! End of File */


