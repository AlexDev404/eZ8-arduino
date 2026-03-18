/*!\file controluart0.c
 * \brief Implementation file for configuring the UART0 Device.
 *
 *  This file contains implementation for configuring the UART0
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
 * \brief The system clock.
 */
extern UINT32 g_clock0 ;


/*!
 * \brief The UART0 receive interrupt service routine.
 */
extern VOID isr_UART0_RX( VOID ) ;

/*!
 * \brief The UART0 transmit interrupt service routine.
 */
 extern VOID isr_UART0_TX( VOID ) ;

/*!
 * \brief The DMA transmit interrupt service routine.
 */
extern VOID isr_DMA( VOID ) ;



/*!
 \defgroup UART UART APIs
*/
/*!
 \ingroup UART
*/
/*!
@{
*/
/*!
 * Configure the UART0 device.
 *
 * This API is used to configure UART0 device with the values specified
 * by the pointer to the UART structure passed as the parameter. The values
 * in the structure are used for writing into appropriate uart device control
 * registers. When used with the debug version of the API which has macro
 * UARTPARAMETER_CHECKING defined, the API performs checks on the validity of the
 * paramters passed. However in the release version of the API, this check is
 * not performed as the macro UARTPARAMETER_CHECKING is not defined. In this case
 * the API configures the UART0 with the values passed in the UART structure
 * parameter.
 *  
 * Return values
 * The API returns UART_ERROR_NONE if no error occurs; else returns one of the
 * following values.
 *	UART_ERR_INVBAUDRATE			Invalid baudrate value passed. Valid baudrate
 *									values are 9600, 19200, 38400, 57600, 115200.
 *	UART_ERR_INVDATABITS			Invalid databits value passed. Valid databits
 *									values are 8,7,6,5.
 *	UART_ERR_INVSTOPBITS			Invalid stopbits value passed. Valid stopbits
 *									values are 1,2.
 *	UART_ERR_INVPARITY				Invalid parity value passed. Valid parity values
 *									are PAR_NOPARITY, PAR_ODPARITY, PAR_EVPARITY.
 */
/*
@}
*/
UCHAR control_UART0( UART *pUART )
{
	UCHAR status = UART_ERR_NONE ;
	UINT16 brgval = 0 ;


#ifdef UARTPARAMETER_CHECKING
	if( ( pUART->baudRate != BAUD_9600 ) && ( pUART->baudRate != BAUD_19200 ) && ( pUART->baudRate != BAUD_38400 ) && 
		( pUART->baudRate != BAUD_57600 ) && ( pUART->baudRate != BAUD_115200 ) )
	{
			return UART_ERR_INVBAUDRATE ;
	}

	if( pUART->stopBits < 1 || pUART->stopBits > 2 )
	{
			return UART_ERR_INVSTOPBITS ;
	}
	
	if( (pUART->parity!=PAR_NOPARITY )&& (pUART->parity!=PAR_ODPARITY )&& (pUART->parity!=PAR_EVPARITY ))
	{
			return UART_ERR_INVPARITY ;
	}
#endif //! UARTPARAMETER_CHECKING


	/*! Compute the baudrate generator value */
//	brgval = ( g_clock0 ) / ( CLOCK_DIVISOR * pUART->baudRate ) ;
	brgval = ( g_clock0 + (pUART->baudRate)*8UL ) / ( CLOCK_DIVISOR * pUART->baudRate ) ;		//with round-off.

	/*! Set baudarate generator */
	U0BRH = brgval >> (BYTE)8 ;
	U0BRL = brgval & (BYTE)0xFF ;


	/*! Configure port bits to alternate function */
#if (UART0_HWFLOW_CTL==ENABLED)
	setmodeAltFunc_PortA( PORTPIN_THREE|PORTPIN_FOUR|PORTPIN_FIVE ) ;
#else
	setmodeAltFunc_PortA( PORTPIN_FOUR|PORTPIN_FIVE ) ;
#endif


	/*!
	 * Enable transmitter, receiver, set parity, stopbits, enable/disable interrupts, set
	 * interrupt priorities, interrupt vector table, and enable the interrupts, as
	 * applicable
	 */

	/*! Disable Tx and Rx interrupts, first */
	IRQ0ENH &= ~(IRQ_U0RXI|IRQ_U0TXI) ;
	IRQ0ENL &= ~(IRQ_U0RXI|IRQ_U0TXI) ;
	
#if (UART0_MODE==MODE_INTERRUPT)
#if (DMA1_CTL==DMA_UART0)
	DI() ;
	U0CTL0 = (pUART->parity<<(BYTE)3) | ((pUART->stopBits-(BYTE)1)<<(BYTE)1) | (UART0_HWFLOW_CTL<<5) ;
	IRQ0ENH = ((UART0_RX_INT_PRIORITY&0x02)<<3) ;
	IRQ0ENL = ((UART0_RX_INT_PRIORITY&0x01)<<4) ;
//	SET_VECTOR( UART0_RX_IVECT, isr_UART0_RX ) ;
	U0CTL0 |= UART_CTL0_TEN | UART_CTL0_REN ;
	EI() ;
#else
	DI() ;
	U0CTL0 = (pUART->parity<<(BYTE)3) | ((pUART->stopBits-(BYTE)1)<<(BYTE)1) | (UART0_HWFLOW_CTL<<5) ;
	IRQ0ENH = ((UART0_RX_INT_PRIORITY&0x02)<<3) | ((UART0_TX_INT_PRIORITY&0x02)<<2) ;
	IRQ0ENL = ((UART0_RX_INT_PRIORITY&0x01)<<4) | ((UART0_TX_INT_PRIORITY&0x01)<<3) ;
//	SET_VECTOR( UART0_TX_IVECT, isr_UART0_TX ) ;
//	SET_VECTOR( UART0_RX_IVECT, isr_UART0_RX ) ;
	U0CTL0 |= UART_CTL0_TEN | UART_CTL0_REN ;
	EI() ;
#endif
#else	//! Polling Mode 
	U0CTL0 = (pUART->parity<<(BYTE)3) | ((pUART->stopBits-(BYTE)1)<<(BYTE)1) | (UART0_HWFLOW_CTL<<5) ;
	U0CTL0 |= UART_CTL0_TEN | UART_CTL0_REN ;
#endif



#if (DMA1_CTL==DMA_UART0)
	/*! Set the IO address to be used in the DMA1. */
	DMA1IO = (BYTE)(REGFILEADDR_U0TXD & (BYTE)0xFF) ;

	DI() ;
	IRQ2ENH = (IRQ2ENH&(~IRQ_DMA)) | ((DMA_INT_PRIORITY&0x02)<<3 ) ;
	IRQ2ENL = (IRQ2ENL&(~IRQ_DMA)) | ((DMA_INT_PRIORITY&0x01)<<4 ) ;
//	SET_VECTOR( DMA, isr_DMA ) ;
	DMA1CTL = (BYTE)( (BYTE)0x00 | DMA_CTL_IRQEN | DMA_CTL_RSS_UART0 ) ;
	EI() ;
#endif

	return status ;

}//! end of control_UART0()



/*! End of File */


