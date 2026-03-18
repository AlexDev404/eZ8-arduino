/*!\file putch.c
 * \brief Implementation file for transmitting a data byte on default UART Device.
 *
 *  This file contains implementation for writing a data byte into the default UART
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
 * Transmit a data byte on UART0.
 *
 * This function writes a data byte into the UARTx transmit buffer. In case of FIFO, the data byte
 * is put into the end of the FIFO.
 *
 * This function is reentrant because it is called by __print_uputch(), which
 * must be reentrant as it is called through a pointer. Likewise, all functions
 * called by this routine must be reentrant.
 */
reentrant UCHAR putch( CHAR ich )
{
	CHAR ch[ 2 ] ;
	CHAR cnt = 1 ;
	UCHAR stat ;

	if( '\n' == ich )						//!< See if this is a new line character.
	{
		ch[ 1 ] = '\n'; 
		ch[ 0 ] = '\r';						//!< Add a carriage-return to this character.
		cnt++ ;								//!< Accommodate this carriage-return character.
	}
	else
	{	
		ch[ 0 ] = ich ;							//!< Copy the character byte to be transmitted.
	}

#if (DEFAULT_UART == UART0)
	stat = write_UART0( ch, cnt ) ;			//!< Transmit this byte on UART0.
	if( UART_ERR_NONE != stat )
	{
		return stat ;
	}
#if (UART0_MODE==MODE_INTERRUPT)
	while( UART_IO_PENDING == get_txstatus_UART0() ) ;
#endif

#endif
#if (DEFAULT_UART == UART1)
	stat = write_UART1( ch, cnt ) ;			//!< Transmit this byte on UART1.
	if( UART_ERR_NONE != stat )
	{
		return stat ;
	}
#if (UART1_MODE==MODE_INTERRUPT)
	while( UART_IO_PENDING == get_txstatus_UART1() ) ;
#endif

#endif



	return UART_ERR_NONE ;

}//! end of putch()



/*! End of File */


