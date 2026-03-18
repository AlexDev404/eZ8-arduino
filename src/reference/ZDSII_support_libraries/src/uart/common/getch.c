/*!\file getch.c
 * \brief Implementation file for receiving a data byte on default UART Device.
 *
 *  This file contains implementation for reading a data byte from the default UART
 *  device required by UART driver implementations for Z8 Encore! microcontrollers.
 *
 *  This source file uses Doxygen-style comments to generate documentation
 *  automatically.
 *
 *  Copyright (C) 1999-2004 by  ZiLOG, Inc.
 *  All Rights Reserved.
 */

#include <stdio.h>
#include <ez8.h>
#include <uartcontrol.h>



/*!
 * Receive a data byte from UART0.
 * 
 * The getch() API reads a data byte from the default UART device. If there is no data in the UART device
 * the API blocks till it becomes available. When the FIFO is enabled this API returns the data byte
 * at the top of the FIFO.
 */
INT getch( VOID )
{
	CHAR ch ;
	UINT16 nbytes = 1 ;
	UCHAR stat ;



#if (DEFAULT_UART == UART0)

	stat = read_UART0( &ch, &nbytes ) ;
	if( UART_ERR_NONE != stat )
	{
		return EOF ;
	}
#if (UART0_MODE==MODE_INTERRUPT)
	do
	{
		stat = get_rxstatus_UART0() ;

	}while( UART_IO_PENDING == stat ) ;
#endif

#endif

#if (DEFAULT_UART == UART1)

	stat = read_UART1( &ch, &nbytes ) ;
	if( UART_ERR_NONE != stat )
	{
		return EOF ;
	}
#if (UART1_MODE==MODE_INTERRUPT)
	do
	{
		stat = get_rxstatus_UART1() ;

	}while( UART_IO_PENDING == stat ) ;
#endif

#endif

	nbytes = (UINT16) ch ;
	nbytes = (nbytes & 0x00FF) ;


	return (UART_IO_COMPLETE!=stat) ? EOF : nbytes ;

}//! end of getch()




/*! End of File */


