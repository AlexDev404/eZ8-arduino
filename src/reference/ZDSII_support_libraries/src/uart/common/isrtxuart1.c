/*!\file isrrxuart1.c
 * \brief Implementation file for UART1	transmitter ISR.
 *
 *  This file contains implementation for UART1	transmitter ISR required by
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
extern volatile UCHAR g_Txflag1 ;

/*!
 * \brief Transmit data buffer pointer.
 */
extern CHAR *g_pTxData1 ;

/*!
 * \brief Transmit data buffer length.
 */
extern UINT16 g_nTxLen1 ;


/*!
 * UART1 Transmitter Interrupt Service Routine.
 */
#pragma interrupt
#if defined (UART1_ISR_PRAM)
#pragma  PRAM
#endif

VOID isr_UART1_TX( VOID )
{
	if( 0 == g_nTxLen1 )
	{
		g_Txflag1 = FALSE ;									//!< Indicate all the bytes are transmitted.
		
		while( !(UART_STAT0_TXE & U1STAT0) ) ;				//!< Wait until the transmitter becomes idle.
		
		/*! disable the transmitter */
//		U1CTL0 &= ~UART_CTL0_TEN ;

		IRQ2 &= ~IRQ_U1TXI ;								//!< Clear the interrupt.

		return ;
	}
	
	if( FALSE != g_Txflag1 )
	{
		while( !(UART_STAT0_TDRE & U1STAT0) ) ;				//! Wait until the transmit data register becomes empty.

		U1TXD = *g_pTxData1++ ;
		g_nTxLen1-- ;
		IRQ2 &= ~IRQ_U1TXI ;								//!< Clear the interrupt.

	}



}//! end of isr_UART1_TX



/*! End of file */

