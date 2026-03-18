/*!\file setbauduart0.c
 * \brief Implementation file for configuring baudrate for UART0 Device.
 *
 *  This file contains implementation for configuring the baudrate for UART0
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
 * \brief The system clock.
 */
extern UINT32 g_clock0 ;

/*!
 \ingroup UART
*/
/*!
@{
*/
/*!
 * Set baudrate for UART0 device.
 *
 * The setbaud_UARTx() API configures the baudrate for the UARTx device with the specified value.
 * The API uses the values of clock frequency and the divisor passed as part of the open call.
 * When used with the debug version of the API which has UARTPARAMETER_CHECKING macro defined, the API performs checks on the 
 * validity of the paramter passed. However in the release version of the API, this check is not performed as the  macro
 * UARTPARAMETER_CHECKING is undefined. In this case the API configures the UARTx with the value passed in the baud parameter
 *  
 * Return values
 * The API returns UART_ERROR_NONE if no error occurs else returns UART_ERR_INVBAUDRATE to indicate invalid baud rate value
 * was passed. Valid baudrate values are 9600,19200,38400,57600,115200 as defined in uart.h file.
 */
/*
@}
*/

UCHAR setbaud_UART0( UINT32 baud )
{
	UINT16 brgval ;

#ifdef UARTPARAMETER_CHECKING

	if( ( baud != BAUD_9600 ) && ( baud != BAUD_19200 ) && ( baud != BAUD_38400 ) && 
		( baud != BAUD_57600 ) && ( baud != BAUD_115200 ) )
	{
			return UART_ERR_INVBAUDRATE ;
	}
#endif	//! UARTPARAMETER_CHECKING

//	brgval = ( g_clock0 ) / ( CLOCK_DIVISOR * baud ) ;						//! Compute the baudrate generator value.
	brgval = ( g_clock0 + (baud*8UL) ) / ( CLOCK_DIVISOR * baud ) ;			//! with round-off.

	/*! Set baudarate generator */
	U0BRH = brgval >> (BYTE)8 ;
	U0BRL = brgval & (BYTE)0xFF ;



	return UART_ERR_NONE ;
	
}//! end of setbaud_UART0()



/*! End of File */


