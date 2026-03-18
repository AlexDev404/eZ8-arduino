/*!\file readuart0.c
 * \brief Implementation file for receiving data bytes on UART0 Device.
 *
 *  This file contains implementation for reading data bytes from the UART0
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
 *
 * This flag indicates that receiver is busy.
 */
volatile UCHAR g_Rxflag0 = FALSE ;

#if (UART0_MODE==MODE_INTERRUPT)
/*!
 * \brief Receive data buffer pointer.
 *
 * This UCHAR pointer points to the data buffer.
 */
CHAR *g_pRxData0 ;

/*!
 * \brief Receive data buffer length.
 *
 * This indicates the number of data bytes to be received from the UART0 device.
 */
UINT16 *g_pRxLen0 ;

/*!
 * \brief Receiver index.
 *
 * This indicates the current status of the number of bytes read.
 */
UINT16 g_rxIndex0 ;
#endif

/*!
 * \brief The receive error for UART0.
 *
 * This variable stores the recent receive error that occured in UART0 device.
 */
#if (UART0_ERRORCHECKING==ENABLED)
UCHAR g_recverr0 = UART_ERR_NONE ;
#endif

/*!
 * \brief Error status for UART0.
 *
 * This variable holds the error status of the UART0 device.
 */
//UCHAR g_errstat_UART0 = UART_ERR_NONE ;



/*!
 \ingroup UART
*/
/*!
@{
*/
/* The read_UART0() API reads data bytes from the UART0. The API accepts
 * a buffer for storing data bytes received and the no of bytes to read.
 * Depending on the mode it will either poll or use interrupt to receive
 * data bytes.
 *
 * Depending on the mode, to which UARTx device is configured viz., poll mode
 * or interrupt mode the API behaves differently as explained below.
 * Reading in Poll mode:
 * In poll mode the data reception is synchronous in nature. In the poll mode
 * the read_UARTx() API receives the data bytes by polling on the UARTX receive 
 * register. The API does not return until all the bytes are received. If the 
 * API is compiled using UART0_ERRORHANDLING macro, any error in the communication 
 * is reported as a return value. See Return values below for more details.
 * 
 * Reading in Interrupt mode.
 * The data reception in interrupt mode is asynchronous in nature. In the interrupt 
 * mode the read_UARTx() API uses the UARTx receive-interrupt to read the data bytes. 
 * The read_UARTx() API enables receive interrupt of the UARTx device and returns 
 * immediately. The data reading then happens in the interrupt service routine of 
 * the UARTx device. 
 * The caller of the API can determine the status of the read operation by using the 
 * API   get_rxstatus_UART0() which returns UART_IO_COMPLETE indicating the completion 
 * of the read operation or returns UART_IO_PENDING indicating that the reading is still 
 * in progress.
 * If the API is compiled using UART0_ERRORHANDLING macro, any error in the received 
 * data byte is reported when a call to get_rxstatus_UARTx the user
 *
 * UART_ERR_NONE 				Indicates the successful transmission of data. 
 * UART_ERR_BUSY				Indicates that the transmission is already in
 *								progress. This error is returned when at the time of read_UARTx()
 *								call is made, the uartx device is still servicing previous read_UARTx call.
 * UART_ERR_FRAMINGERR			Indicates that a framing error occured in the character
 *                              received.		
 * UART_ERR_PARITYERR			Indicates that a Parity error occured in the character
 *                              received.			
 * UART_ERR_OVERRUNERR			Indicates that a returned when overrun error occured in
 *                              the receive buffer.
 * UART_ERR_BREAKINDICATIONERR	Indicates that a Break condition was detected.
 *
 */
/*
@}
*/
UCHAR read_UART0( CHAR *pData, UINT16 *nbytes )
{
	BYTE stat0 ;
	BYTE status = UART_ERR_NONE ;
#if (UART0_MODE==MODE_POLLING)
	UINT16 index = 0 ;
#endif	
	
	/*! Check if there is a reading already in progress */
	if(g_Rxflag0)
	{
		return UART_ERR_BUSY ;
	}
	
	/*! set the rxflag to busy */
	g_Rxflag0 = TRUE ;

#if (UART0_ERRORCHECKING==ENABLED)
	/*! clear the receive error status */
	g_recverr0 = UART_ERR_NONE ;
#endif



#if (UART0_MODE==MODE_INTERRUPT)
	DI() ;

	/*! copy the buffer and the length pointer */
	g_pRxData0 = pData ;
	g_pRxLen0 = nbytes ;

	/*! initialize the index */
	g_rxIndex0 = 0 ;

	stat0 = U0STAT0 ;
	if( UART_STAT0_RDA & stat0 )
	{
#if (UART0_ERRORCHECKING==ENABLED)
		/*! check for any error */													
		if( UART_STAT0_PE & stat0 )									//!< on parity error return parity error code.
		{																			
			g_recverr0 = UART_ERR_PARITYERR ;
		}																			
																					
		else if ( UART_STAT0_OE & stat0 )								//!< on overrun error return overrun error code.
		{																			
			g_recverr0 = UART_ERR_OVERRUNERR ;
		}

		else if ( UART_STAT0_FE & stat0 )								//!< on framing error return framing error code.
		{
			g_recverr0 = UART_ERR_FRAMINGERR ;
		}

		else if( UART_STAT0_BRKD & stat0 )								//!< on break detection return break indication error code.
		{
			g_recverr0 = UART_ERR_BREAKINDICATIONERR ;
		}

		status = g_recverr0 ;

		/*! on error */
		if( UART_ERR_NONE != status )
		{
			/*! Reset the rxflag  */
			g_Rxflag0 = FALSE ;

			//! Update nbytes to indicate number of bytes read.
			*nbytes = 1 ;
		}
#endif //! UART0_ERRORCHECKING

		*g_pRxData0++ = U0RXD ;

		/*! check if we are done */
		if( (UINT16)1 == *nbytes )
		{
			g_Rxflag0 = FALSE ;
		}
		else
		{
			g_rxIndex0++ ;
		}

	}//! If data byte is ready.

	/*! Enable the receiver */
	U0CTL0 |= UART_CTL0_REN ;

	EI() ;

	
#else	//! Polling Mode.


	while( UART_ERR_NONE == status )
	{

		//!< wait until there is a data byte available.
		while( ALWAYS )
		{
			stat0 = U0STAT0 ;												//!< read the status-0 register.

			if( stat0 & UART_STAT0_RDA )
			{
				break ;
			}
		}


#if (UART0_ERRORCHECKING==ENABLED)
		/*! check for any error */													
		if( UART_STAT0_PE & stat0 )									//!< on parity error return parity error code.
		{																			
			g_recverr0 = UART_ERR_PARITYERR ;
		}																			
																					
		else if ( UART_STAT0_OE & stat0 )								//!< on overrun error return overrun error code.
		{																			
			g_recverr0 = UART_ERR_OVERRUNERR ;
		}

		else if ( UART_STAT0_FE & stat0 )								//!< on framing error return framing error code.
		{
			g_recverr0 = UART_ERR_FRAMINGERR ;
		}

		else if( UART_STAT0_BRKD & stat0 )								//!< on break detection return break indication error code.
		{
			g_recverr0 = UART_ERR_BREAKINDICATIONERR ;
		}

		status = g_recverr0 ;
#endif //! UART0_ERRORCHECKING

		pData[ index++ ] = U0RXD ;

		if( index == (*nbytes) )										//! On completion, break the while loop.
		{
			break ;
		}

	}//! Loop until all nbytes are read.

	/*! Reset the rxflag  */
	g_Rxflag0 = FALSE ;

	//! Update nbytes with the index to indicate number of bytes read.
	*nbytes = index ;

	/*! Disable the receiver */
//	U0CTL0 &= ~UART_CTL0_REN ;
#endif




	return status ;

}//! end of read_UART0()



/*! End of File */


