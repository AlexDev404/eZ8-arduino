/*!\file setparityuart0.c
 * \brief Implementation file for configuring parity for UART0 Device.
 *
 *  This file contains implementation for configuring the parity for UART0
 *  device required by UART driver implementations for Z8 Encore!
 *  microcontrollers.
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
 * Set parity for UARTx device.
 *
 * The setparity_UARTx() API configures the parity for the UARTx device. 
 * When used with the debug version of the API which has UARTPARAMETER_CHECKING macro defined, the API performs checks on the 
 * validity of the paramter passed. However in the release version of the API, this check is not performed as the  macro
 * UARTPARAMETER_CHECKING is undefined. In this case the API configures the UARTx with the value passed in the parity parameter
 *  
 * Return values
 * The API returns UART_ERROR_NONE if no error occurs else returns UART_ERR_INVPARITY indicating that an invalid parity was passed
 * Valid parity values are PAR_NOPARITY,PAR_ODPARITY, PAR_EVPARITY as defined in uart.h file.
 */
 /*
@}
*/

UCHAR setparity_UART0( UCHAR parity )
{

#ifdef UARTPARAMETER_CHECKING
	if( (parity!=PAR_NOPARITY ) && (parity!=PAR_ODPARITY ) && (parity!=PAR_EVPARITY ) )
	{
			return UART_ERR_INVPARITY ;
	}
#endif //! UARTPARAMETER_CHECKING

	U0CTL0 = (U0CTL0&~(UART_CTL0_PEN|UART_CTL0_PSEL)) | (parity<<3) ;
	

	return UART_ERR_NONE ;
	
}//! end of setparity_UART0()



/*! End of File */


