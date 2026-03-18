/*!\file flushuart0.c
 * \brief Implementation file for flushing UART0 receiver and return the last byte present.
 *
 *  This file contains implementation for flushing the receiver and return the last byte
 *  for UART0 device required by UART driver implementations for Z8 Encore!
 *  microcontrollers.
 *
 *  This source file uses Doxygen-style comments to generate documentation
 *  automatically.
 *
 *  Copyright (C) 1999-2004 by  ZiLOG, Inc.
 *  All Rights Reserved.
 */

#include <ez8.h>


/*!
 \ingroup UART
*/
/*!
@{
*/
/*!
 * Flush UART0 receiver.
 *
 * The flush_UARTx API flushes receiver and returns the last data byte.
 * 
 * Return values:
 * None.
 * 
 */
/*
@}
*/
UCHAR flush_UART0( VOID )
{

	return U0RXD ;
	
}//! end of flush_UART0()



/*! End of File */


