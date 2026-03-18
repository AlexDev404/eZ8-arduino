/*!\file rxstatusuart1.c
 * \brief Implementation file that returns the status of UART1 receiver.
 *
 *  This file contains implementation that returns the status of the UART1 receiver 
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
extern volatile UCHAR g_Rxflag1 ;

/*!
 * \brief The receive error for UART1.
 *
 * This variable stores the recent receive error that occured in UART1 device.
 */
#if (UART1_ERRORCHECKING==ENABLED)
extern UCHAR g_recverr1 ;
#endif


/*!
 * \brief Return receiver status for UART1.
 *
 * This API returns the status fo the UART1 receiver. When the receiver
 * is busy receiving, then UART_IO_PENDING (=1) is returned. Whereas when
 * the receiver is not busy, then UART_IO_COMPLETE (=0) is returned.
 */
UCHAR get_rxstatus_UART1( VOID )
{
	if(TRUE==g_Rxflag1)
	{
		return UART_IO_PENDING ;
	}

#if (UART1_ERRORCHECKING==ENABLED)
	if( UART_ERR_NONE != g_recverr1 ) 
	{
		return g_recverr1 ;
	}
#endif

	return UART_IO_COMPLETE ;

}//! end of get_rxstatus_UART1()




/*! End of File */



