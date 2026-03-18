/*!\file txstatusuart0.c
 * \brief Implementation file that returns the status of UART0 transmitter.
 *
 *  This file contains implementation that returns the status of the UART0 transmitter 
 *  required by UART driver implementations for Z8 Encore! microcontrollers.
 *
 *  This source file uses Doxygen-style comments to generate documentation
 *  automatically.
 *
 *  Copyright (C) 1999-2004 by  ZiLOG, Inc.
 *  All Rights Reserved.
 */

#include <ez8.h>

/*!
 * \brief Transmit busy flag.
 *
 */
extern volatile UCHAR g_Txflag0 ;


/*!
 * \brief Return transmitter status for UART0.
 *
 * This API returns the status fo the UART0 transmitter. When the transmitter
 * is busy transmitting, then UART_IO_PENDING (=1) is returned. Whereas when
 * the transmitter is not busy, then UART_IO_COMPLETE (=0) is returned.
 */
UCHAR get_txstatus_UART0( VOID )
{
	return (TRUE==g_Txflag0) ? UART_IO_PENDING : UART_IO_COMPLETE ;

}//! end of get_txstatus_UART0()




/*! End of File */


