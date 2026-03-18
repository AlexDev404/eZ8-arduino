/*!\file writeuart0.c
 * \brief Implementation file for transmitting data bytes on UART0 Device.
 *
 *  This file contains implementation for writing data bytes into the UART0
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
 * \brief Transmit busy flag.
 *
 * This flag indicates that transmitter is busy.
 */
volatile UCHAR g_Txflag0 = FALSE ;

/*!
 * \brief Simulator-used flag.
 *
 * This flag indicates whether a simulator is being used. The definition
 * is found in zsldevinit.asm file.
 */
extern UCHAR g_simulate ;

#if (UART0_MODE==MODE_INTERRUPT)
/*!
 * \brief Transmit data buffer pointer.
 *
 * This UCHAR pointer points to the data to be transmitted over the UART0 device.
 */
CHAR *g_pTxData0 ;

/*!
 * \brief Transmit data buffer length.
 *
 * This indicates the number of data bytes to be transmitted over the UART0 device.
 */
UINT16 g_nTxLen0 = 0 ;
#endif

/*!
 \ingroup UART
*/
/*!
@{
*/

/*!
 *
 * The write_UARTx() API writes data bytes into the UARTx. The API accepts
 * a buffer containing data to be transmitted and the number of bytes to transmit.
 * In the POLL mode the API does not return untill all the bytes are transmitted.
 * However in the interrupt mode, the API returns immediately and the data transmission
 * happens asynchronously. To know the completion of the transmission the caller can 
 * make use of txstatus_UART0() API which returns UART_NOTBUSY after the successful completion
 * of data transfer. If the DMA transfer is enabled, this routine uses DMA1 for data transfers.
 */
 /*
@}
*/
reentrant UCHAR write_UART0( CHAR *pData, UINT16 nbytes )
{
	UINT16 index = 0 ;



	/*! Check if there is a transmission already in progress */
	if( g_Txflag0 )
	{
		return UART_ERR_BUSY ;
	}
	
	/*! set the txflag to busy */
	g_Txflag0 = TRUE ;

	/*! if simulator is being used */
	if( TRUE == g_simulate )
	{
		while( nbytes-- )
		{
			U0TXD = *pData++ ;
		}

		/*! Reset the txflag  */
		g_Txflag0 = FALSE ;

		return UART_ERR_NONE ;
	}

#if (UART0_MODE==MODE_INTERRUPT)

	/*! copy the buffer pointer and the length */
	g_pTxData0 = pData + 1 ;
	//g_nTxLen0 = nbytes - (UINT16)1 ;
	g_nTxLen0 = (UINT32)nbytes - 1 ;					//!Fix for the compiler bug (generates improper code in Small-Static-Debug configuration).

	
	/*! Enable the transmitter */
//	U0CTL0 |= UART_CTL0_TEN ;

	while( 0 == (UART_STAT0_TDRE & U0STAT0) ) ;		//!< Wait until the transmitter is ready to accept new data byte.

	/*! Initiate transmission by sending first byte */
	U0TXD = pData[ 0 ] ;
#else
	/*! Enable the transmitter */
//	U0CTL0 |= UART_CTL0_TEN ;

	while( ALWAYS )
	{
		while( 0 == (UART_STAT0_TDRE & U0STAT0) ) ;		//!< Wait until the transmit data register is empty.

		if( index == nbytes )							//!< If there are no bytes to be transmitted break the loop.
		{
			/*! Reset the txflag  */
			g_Txflag0 = FALSE ;
			break ;
		}

		U0TXD = pData[ index++ ] ;

	}

	while( 0 == (UART_STAT0_TXE & U0STAT0) ) ;		//!< Wait until the transmitter becomes idle.

	/*! Disable the transmitter */
//	U0CTL0 &= ~UART_CTL0_TEN ;

#endif

	return UART_ERR_NONE ;
	
}//! end of write_UART0()




/*! End of File */


