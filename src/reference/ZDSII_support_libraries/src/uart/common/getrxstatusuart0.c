/*!\file rxstatusuart0.c
 * \brief Implementation file that returns the status of UART0 receiver.
 *
 *  This file contains implementation that returns the status of the UART0 receiver 
 *  required by UART driver implementations for Z8 Encore! microcontrollers.
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
 * \brief Receive busy flag.
 *
 */
extern volatile UCHAR g_Rxflag0 ;

/*!
 * \brief The receive error for UART0.
 *
 * This variable stores the recent receive error that occured in UART0 device.
 */
#if (UART0_ERRORCHECKING==ENABLED)
extern UCHAR g_recverr0 ;
#endif


/*!
 * \brief Return receiver status for UART0.
 *
 * This API returns the status fo the UART0 receiver. When the receiver
 * is busy receiving, then UART_IO_PENDING (=1) is returned. Whereas when
 * the receiver is not busy, then UART_IO_COMPLETE (=0) is returned.
 */
UCHAR get_rxstatus_UART0( VOID )
{
	if(TRUE==g_Rxflag0)
	{
		return UART_IO_PENDING ;
	}

#if (UART0_ERRORCHECKING==ENABLED)
	if( UART_ERR_NONE != g_recverr0 ) 
	{
		return g_recverr0 ;
	}
#endif

	return UART_IO_COMPLETE ;

}//! end of get_rxstatus_UART0()




/*! End of File */



