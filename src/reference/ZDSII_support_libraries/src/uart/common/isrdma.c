/*!\file isrdma.c
 * \brief Implementation file for DMA interrupt.
 *
 *  This file contains implementation for handling DMA Interrupt
 *  required by UART driver implementations for Z8 Encore! microcontrollers.
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
 * \brief Transmit busy flag.
 *
 * This flag indicates that transmitter is busy.
 */
extern UCHAR g_Txflag0 ;
extern UCHAR g_Txflag1 ;

#pragma interrupt
VOID isr_DMA( VOID )
{
#if (DMA1_CTL!=DMA_DISABLED)
	if( DMAASTAT & DMAA_STAT_IRQ1 )
	{
#if (DMA1_CTL==DMA_UART0)
		/*! wait until the transmitter shift register becomes empty */
		while( !(UART_STAT0_TXE & U0STAT0) ) ;

		/*! Indicate data transmission is complete and transmitter is disabled. */
		g_Txflag0 = FALSE ;
#elif (DMA1_CTL==DMA_UART1)
		/*! wait until the transmitter shift register becomes empty */
		while( !(UART_STAT0_TXE & U1STAT0) ) ;

		/*! Indicate data transmission is complete and transmitter is disabled. */
		g_Txflag1 = FALSE ;
#endif

		/*! disable the DMA1 */
		DMA1CTL &= ~DMA_CTL_DEN ;


	}
#endif


}//! end of isr_DMA



/*! End of File */


