/*!\file flushuart1.c
 * \brief Implementation file for flushing UART1 receiver and return the last byte present.
 *
 *  This file contains implementation for flushing the receiver and return the last byte
 *  for UART1 device required by UART driver implementations for Z8 Encore!
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
 * Flush UART1 receiver.
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
UCHAR flush_UART1( VOID )
{

	return U1RXD ;
	
}//! end of flush_UART1()



/*! End of File */


