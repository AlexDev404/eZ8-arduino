/*!\file kbhit.c
 * \brief Implementation file detecting keyboard hit on default UART Device.
 *
 *  This file contains implementation for detecting keyboard hit on default UART
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
 * \brief Detect keyboard from default UART.
 *
 * This API detects for any keystrokes from the default UART. If a keystroke is detected
 * this function returns a 1 else returns 0. The API returns immediately
 * without blocking both when the uart is configured to work in poll mode and in the
 * interrupt mode. Also note that the API does not read the data but only returns
 * the status. However, this function will return a 0xFF if FIFO has an error in it.
 * When it returns 0xFF error code, the application can use geterr_UART() to know the
 * exact error that occurred.
 */
UCHAR kbhit( VOID )
{

#if (DEFAULT_UART == UART0)
	return ( U0STAT0 & UART_STAT0_RDA ) ;
#endif

#if (DEFAULT_UART == UART1)
	return ( U1STAT0 & UART_STAT0_RDA ) ;
#endif

}//! end of kbhit()




/*! End of File */


