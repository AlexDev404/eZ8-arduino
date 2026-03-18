/*!\file setstopbitsuart0.c
 * \brief Implementation file for configuring stopbits for UART0 Device.
 *
 *  This file contains implementation for configuring the stopbits for UART0
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
 \ingroup UART
*/
/*!
@{
*/
/*!
 * Set stopbits for UART0 device.
 *
 * The setstopbits_UARTx() API sets the stopbits for the UARTx device. 
 * When used with the debug version of the API which has UARTPARAMETER_CHECKING macro defined, the API performs checks on the 
 * validity of the paramter passed. However in the release version of the API, this check is not performed as the  macro
 * UARTPARAMETER_CHECKING is undefined. In this case the API configures the UARTx with the value passed in the stopbits parameter
 *  
 * Return values
 * The API returns UART_ERROR_NONE if no error occurs else returns UART_ERR_INVSTOPBITS indicating that an invalid stop bits value was passed
 * Valid stopbits values are 1 or 2 as defined in uart.h file.
 */
 /*
@}
*/
UCHAR setstopbits_UART0( UCHAR stopbits )
{

#ifdef UARTPARAMETER_CHECKING
	if( stopbits < 1 || stopbits > 2 )
	{
			return UART_ERR_INVSTOPBITS ;
	}
#endif //! UARTPARAMETER_CHECKING

	U0CTL0 = (U0CTL0&~UART_CTL0_STOP) | ((stopbits-(BYTE)1)<<1) ;
	

	return UART_ERR_NONE ;
	
}//! end of setstopbits_UART0()



/*! End of File */


