/*!\file isrtxuart0.c
 * \brief Implementation file for UART0	transmitter ISR.
 *
 *  This file contains implementation for UART0	transmitter ISR required by
 *  UART driver implementations for Z8 Encore! microcontrollers.
 *
 *  This source file uses Doxygen-style comments to generate documentation
 *  automatically.
 *
 *  Copyright (C) 1999-2004 by  ZiLOG, Inc.
 *  All Rights Reserved.
 */

#include <ez8.h>

/*!
 * \brief Transmit busy flag.
 */
extern volatile UCHAR g_Txflag0 ;

/*!
 * \brief Transmit data buffer pointer.
 */
extern CHAR *g_pTxData0 ;

/*!
 * \brief Transmit data buffer length.
 */
extern UINT16 g_nTxLen0 ;


/*!
 * UART0 Transmitter Interrupt Service Routine.
 */
#pragma interrupt
#if defined (UART0_ISR_PRAM)
#pragma  PRAM
#endif

VOID isr_UART0_TX( VOID )
{
	if( 0 == g_nTxLen0 )
	{
		g_Txflag0 = FALSE ;									//!< Indicate all the bytes are transmitted.
		
		while( !(UART_STAT0_TXE & U0STAT0) ) ;				//!< Wait until the transmitter becomes idle.
		
		/*! disable the transmitter */
//		U0CTL0 &= ~UART_CTL0_TEN ;

		IRQ0 &= ~IRQ_U0TXI ;								//!< Clear the interrupt.

		return ;
	}
	
	if( FALSE != g_Txflag0 )
	{
		while( !(UART_STAT0_TDRE & U0STAT0) ) ;				//! Wait until the transmit data register becomes empty.

		U0TXD = *g_pTxData0++ ;
		g_nTxLen0-- ;
		IRQ0 &= ~IRQ_U0TXI ;								//!< Clear the interrupt.

	}



}//! end of isr_UART0_TX



/*! End of file */

