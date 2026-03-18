/*!\file writeuart1.c
 * \brief Implementation file for transmitting data bytes on UART1 Device.
 *
 *  This file contains implementation for writing data bytes into the UART1
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
volatile UCHAR g_Txflag1 = FALSE ;

/*!
 * \brief Simulator-used flag.
 *
 * This flag indicates whether a simulator is being used. The definition
 * is found in zsldevinit.asm file.
 */
extern UCHAR g_simulate ;

#if (UART1_MODE==MODE_INTERRUPT)
/*!
 * \brief Transmit data buffer pointer.
 *
 * This UCHAR pointer points to the data to be transmitted over the UART1 device.
 */
CHAR *g_pTxData1 ;

/*!
 * \brief Transmit data buffer length.
 *
 * This indicates the number of data bytes to be transmitted over the UART1 device.
 */
UINT16 g_nTxLen1 ;
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
 * make use of txstatus_UART1() API which returns UART_NOTBUSY after the successful completion
 * of data transfer. If the DMA transfer is enabled, this routine uses DMA1 for data transfers.
 */
 /*
@}
*/
reentrant UCHAR write_UART1( CHAR *pData, UINT16 nbytes )
{
	UINT16 index = 0 ;
#if (DMA1_CTL==DMA_UART1)
	UINT16 endaddr = 0 ;
#endif


	/*! Check if there is a transmission already in progress */
	if( g_Txflag1 )
	{
		return UART_ERR_BUSY ;
	}
	
	/*! set the txflag to busy */
	g_Txflag1 = TRUE ;

	/*! if simulator is being used */
	if( TRUE == g_simulate )
	{
		while( nbytes-- )
		{
			U1TXD = *pData++ ;
		}

		/*! Reset the txflag  */
		g_Txflag1 = FALSE ;

		return UART_ERR_NONE ;
	}

#if (DMA1_CTL==DMA_UART1)
	/*! compute the end address for the DMA transfer */
#ifdef _MODEL_LARGE
	endaddr = (UINT16)pData + (UINT16)(nbytes - (UINT16)1) ;
#else
	nbytes-- ;
	endaddr = (UINT16)pData ;
	endaddr &= 0x00FF ;				//remove any undesired sign-extension.
	endaddr += nbytes ;
#endif

	/*! write high nibbles of start and end address register into Address High Nibble Register */
#ifdef _MODEL_LARGE
	DMA1H = (((UINT16)pData&(UINT16)0x0F00)>>8) | ((endaddr&(UINT16)0x0F00)>>4) ;
#else
	DMA1H = (endaddr&(UINT16)0x0F00)>>4 ;
#endif

	/*! write the low byte of the start address register to the Start/Current Address register */
	DMA1START = (BYTE)pData ;

	/*! write the low byte of the end address register to the End Address register */
	DMA1END = (BYTE)endaddr ;

	/*! enable the transmitter */
	U1CTL0 |= UART_CTL0_TEN ;
	
	/*! enable DMA1 to start the data transfer */
	DMA1CTL |= DMA_CTL_DEN ;
	
#elif (UART1_MODE==MODE_INTERRUPT)

	/*! copy the buffer pointer and the length */
	g_pTxData1 = pData + 1 ;
	//g_nTxLen1 = nbytes - 1 ;
	g_nTxLen1 = (UINT32)nbytes - 1 ;					//!Fix for the compiler bug (generates improper code in Small-Static-Debug configuration).

	
	/*! Enable the transmitter */
//	U1CTL0 |= UART_CTL0_TEN ;

	while( 0 == (UART_STAT0_TDRE & U1STAT0) ) ;		//!< Wait until the transmitter is ready to accept new data byte.

	/*! Initiate transmission by sending first byte */
	U1TXD = pData[ 0 ] ;
#else
	/*! Enable the transmitter */
//	U1CTL0 |= UART_CTL0_TEN ;

	while( ALWAYS )
	{
		while( 0 == (UART_STAT0_TDRE & U1STAT0) ) ;		//!< Wait until the transmit data register is empty.

		if( index == nbytes )							//!< If there are no bytes to be transmitted break the loop.
		{
			/*! Reset the txflag  */
			g_Txflag1 = FALSE ;
			break ;
		}

		U1TXD = pData[ index++ ] ;

	}

	while( 0 == (UART_STAT0_TXE & U1STAT0) ) ;		//!< Wait until the transmitter becomes idle.

	/*! Disable the transmitter */
//	U1CTL0 &= ~UART_CTL0_TEN ;

#endif

	return UART_ERR_NONE ;
	
}//! end of write_UART1()




/*! End of File */


