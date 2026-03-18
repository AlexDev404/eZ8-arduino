/*!\file isrrxuart1.c
 * \brief Implementation file for receiving data bytes on UART1 Device.
 *
 *  This file contains implementation for reading data bytes from the UART1
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
 * \brief Receive busy flag.
 */
extern volatile UCHAR g_Rxflag1 ;

/*!
 * \brief Receive data buffer pointer.
 */
extern CHAR *g_pRxData1 ;

/*!
 * \brief Receive data buffer length.
 */
extern UINT16 *g_pRxLen1 ;

/*!
 * \brief Receiver index.
 */
extern UINT16 g_rxIndex1 ;

/*!
 * \brief The receive error for UART1.
 */
#if (UART1_ERRORCHECKING==ENABLED)
extern UCHAR g_recverr1 ;
#endif

#pragma interrupt
#if defined (UART1_ISR_PRAM)
#pragma  PRAM
#endif

VOID isr_UART1_RX( VOID )
{
	BYTE stat0 ;


	/*! if reception is enabled */
	if( TRUE == g_Rxflag1 )
	{
		/*! read the status-0 register */
		stat0 = U1STAT0 ;

#if (UART1_ERRORCHECKING==ENABLED)
		/*! check for any error */													
		if( UART_STAT0_PE & stat0 )										//!< on parity error.
		{
			g_recverr1 = UART_ERR_PARITYERR ;
		}

		else if ( UART_STAT0_OE & stat0 )									//!< on overrun error.
		{
			g_recverr1 = UART_ERR_OVERRUNERR ;
		}

		else if ( UART_STAT0_FE & stat0 )									//!< on framing error.
		{
			g_recverr1 = UART_ERR_FRAMINGERR ;
		}

		else if( UART_STAT0_BRKD & stat0 )									//!< on break detection.
		{
			g_recverr1 = UART_ERR_BREAKINDICATIONERR ;
		}
#endif //! UART1_ERRORCHECKING

		if( UART_STAT0_RDA & stat0 )
		{
			*g_pRxData1++ = U1RXD ;							//! Read this byte and add it to the receive data buffer.
			g_rxIndex1++ ;

		}
		
	}


	/*! If data reception is complete, or if there is any receive error */	
	if( 
				(g_rxIndex1 == (*g_pRxLen1))
#if (UART1_ERRORCHECKING==ENABLED)
	           			||
			( UART_ERR_NONE != g_recverr1)
#endif
	  )
	{
		/*! Disable the receiver. */
//		U1CTL0 &= ~UART_CTL0_REN ;
		
		/*! Indicate data reception is either complete or stopped due to receive error and receiver is disabled. */
		g_Rxflag1 = FALSE ;

		/*! Indicate number of bytes read. */
		*g_pRxLen1 = g_rxIndex1 ;

		g_rxIndex1 = 0 ;

	}



	return ;

}//! end of isr_UART1_RX



/*! End of file */

