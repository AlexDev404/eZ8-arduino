/*!\file isrrxuart0.c
 * \brief Implementation file for UART0	receiver ISR.
 *
 *  This file contains implementation for UART0	receiver ISR required by
 *  UART driver implementations for Z8 Encore! microcontrollers.
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
 * \brief Receive busy flag.
 */
extern volatile UCHAR g_Rxflag0 ;

/*!
 * \brief Receive data buffer pointer.
 */
extern CHAR *g_pRxData0 ;

/*!
 * \brief Receive data buffer length.
 */
extern UINT16 *g_pRxLen0 ;

/*!
 * \brief Receiver index.
 */
extern UINT16 g_rxIndex0 ;


/*!
 * \brief The receive error for UART0.
 */
#if (UART0_ERRORCHECKING==ENABLED)
extern UCHAR g_recverr0 ;
#endif


/*!
 * UART0 Receiver Interrupt Service Routine.
 */
#pragma interrupt
#if defined (UART0_ISR_PRAM)
#pragma  PRAM
#endif
VOID isr_UART0_RX( VOID )
{
	BYTE stat0 ;


	/*! if reception is enabled */
	if( TRUE == g_Rxflag0 )
	{
		/*! read the status-0 register */
		stat0 = U0STAT0 ;

#if (UART0_ERRORCHECKING==ENABLED)
		/*! check for any error */													
		if( UART_STAT0_PE & stat0 )										//!< on parity error.
		{
			g_recverr0 = UART_ERR_PARITYERR ;
		}

		else if ( UART_STAT0_OE & stat0 )									//!< on overrun error.
		{
			g_recverr0 = UART_ERR_OVERRUNERR ;
		}

		else if ( UART_STAT0_FE & stat0 )									//!< on framing error.
		{
			g_recverr0 = UART_ERR_FRAMINGERR ;
		}

		else if( UART_STAT0_BRKD & stat0 )									//!< on break detection.
		{
			g_recverr0 = UART_ERR_BREAKINDICATIONERR ;
		}
#endif //! UART0_ERRORCHECKING

		if( UART_STAT0_RDA & stat0 )
		{
			*g_pRxData0++ = U0RXD ;							//! Read this byte and add it to the receive data buffer.
			g_rxIndex0++ ;

		}
		
	}


	/*! If data reception is complete, or if there is any receive error */	
	if( 
				(g_rxIndex0 == (*g_pRxLen0))
#if (UART0_ERRORCHECKING==ENABLED)
	           			||
			( UART_ERR_NONE != g_recverr0)
#endif
	  )
	{
		/*! Disable the receiver. */
//		U0CTL0 &= ~UART_CTL0_REN ;
		
		/*! Indicate data reception is either complete or stopped due to receive error and receiver is disabled. */
		g_Rxflag0 = FALSE ;

		/*! Indicate number of bytes read. */
		*g_pRxLen0 = g_rxIndex0 ;

		g_rxIndex0 = 0 ;

	}



	return ;

}//! end of isr_UART0_RX



/*! End of file */

