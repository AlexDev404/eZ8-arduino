/*!\file closeuart1.c
 * \brief Implementation file for closing UART1 Device.
 *
 *  This file contains implementation for closing the UART1
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
 * Close the UART1 device.
 *
 * This close_UARTx() API is used to close the UART device. Calling this API disables all the 
 * interrupts related to default UART device, and clears all the control registers so as to render 
 * the UART device useless after this call.The application can use the UART again only after making a call to open_UARTx() call.

 */
/*!
@}
*/

VOID close_UART1( VOID )
{
	U1CTL0 = 0 ;

#if (UART1_MODE == MODE_INTERRUPT)
	IRQ2ENH = IRQ2ENH&(~(IRQ_U1RXI|IRQ_U1TXI)) ;
	IRQ2ENL = IRQ2ENL&(~(IRQ_U1RXI|IRQ_U1TXI)) ;
#endif
	
#if (UART1_HWFLOW_CTL==ENABLED)
	setmodeAltFunc_PortD( PORTPIN_FOUR|PORTPIN_FIVE|PORTPIN_SIX ) ;
#else
	setmodeAltFunc_PortD( PORTPIN_FOUR|PORTPIN_FIVE ) ;
#endif


	
	return ;

}//! end of close_UART1()



/*! End of File */


