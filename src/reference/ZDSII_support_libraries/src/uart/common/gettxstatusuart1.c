/*!\file txstatusuart1.c
 * \brief Implementation file that returns the status of UART1 transmitter.
 *
 *  This file contains implementation that returns the status of the UART1 transmitter 
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
extern volatile UCHAR g_Txflag1 ;


/*!
 * \brief Return transmitter status for UART1.
 *
 * This API returns the status fo the UART1 transmitter. When the transmitter
 * is busy transmitting, then UART_IO_PENDING (=1) is returned. Whereas when
 * the transmitter is not busy, then UART_IO_COMPLETE (=0) is returned.
 */
UCHAR get_txstatus_UART1( VOID )
{
	return (TRUE==g_Txflag1) ? UART_IO_PENDING : UART_IO_COMPLETE ;

}//! end of get_txstatus_UART1()




/*! End of File */


