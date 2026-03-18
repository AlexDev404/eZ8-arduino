/*!\file openuart0.c
 * \brief Implementation file for initializing the UART0 Device.
 *
 *  This file contains implementation for initializing the UART0
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
 \ingroup UART
*/
/*!
@{
*/

/*!
 * Initialize the UART1 device.
 *
 * The open_UARTx() API opens the UARTx device by initializing the UARTx 
 * Control registers with default values. This API configures the appropriate 
 * port registers for alternate functions.
 * The following default values will be set.
 * uartmode = Interrupt
 * baudrate = 38400 
 * databits = 8 
 * stopbits = 2 
 * parity = disable 
 * hwflowcontrol = disable
 * swflowcontrol = disable
 *  */
/*
@}
*/
VOID open_UART0( VOID )
{
	UINT16 brgval = 0 ;



	/*! Compute the baudrate generator value */
//	brgval = ( g_clock0 ) / ( CLOCK_DIVISOR * UART0_BAUDRATE ) ;
	brgval = ( g_clock0 + (8UL*UART0_BAUDRATE) ) / ( CLOCK_DIVISOR * UART0_BAUDRATE ) ;		//with round-off.


	/*! Set baudarate generator */
	U0BRH = brgval >> (BYTE)8 ;
	U0BRL = brgval & (BYTE)0xFF ;


	/*! Configure port bits to alternate function */
#if (UART0_HWFLOW_CTL==ENABLED)
	setmodeAltFunc_PortA( PORTPIN_THREE|PORTPIN_FOUR|PORTPIN_FIVE ) ;
#else
	setmodeAltFunc_PortA( PORTPIN_FOUR|PORTPIN_FIVE ) ;
#endif

#if (UART0_DATABITS==DATABITS_8)
	/*! Disable multiprocessor mode. */
	U0CTL1 &= (~UART_CTL1_MPEN) ;
#else
	/*! not supported in this version */
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
	U0CTL0 = (UART0_PARITY<<3) | ((UART0_STOPBITS-1)<<1) | (UART0_HWFLOW_CTL<<5) ;
	IRQ0ENH = ((UART0_RX_INT_PRIORITY&0x02)<<3) ;
	IRQ0ENL = ((UART0_RX_INT_PRIORITY&0x01)<<4) ;
	SET_VECTOR( UART0_RX_IVECT, isr_UART0_RX ) ;
	U0CTL0 |= UART_CTL0_TEN | UART_CTL0_REN ;
	EI() ;
#else
	DI() ;
	U0CTL0 = (UART0_PARITY<<3) | ((UART0_STOPBITS-1)<<1) | (UART0_HWFLOW_CTL<<5) ;
	IRQ0ENH = ((UART0_RX_INT_PRIORITY&0x02)<<3) | ((UART0_TX_INT_PRIORITY&0x02)<<2) ;
	IRQ0ENL = ((UART0_RX_INT_PRIORITY&0x01)<<4) | ((UART0_TX_INT_PRIORITY&0x01)<<3) ;
	SET_VECTOR( UART0_TX_IVECT, isr_UART0_TX ) ;
	SET_VECTOR( UART0_RX_IVECT, isr_UART0_RX ) ;
	U0CTL0 |= UART_CTL0_TEN | UART_CTL0_REN ;
	EI() ;
#endif
#else		//! Polling Mode
	U0CTL0 = (UART0_PARITY<<3) | ((UART0_STOPBITS-1)<<1) | (UART0_HWFLOW_CTL<<5) ;
	U0CTL0 |= UART_CTL0_TEN | UART_CTL0_REN ;
#endif

#if (DMA1_CTL==DMA_UART0)
	/*! Set the IO address to be used in the DMA1. */
	DMA1IO = (BYTE)(REGFILEADDR_U0TXD & (BYTE)0xFF) ;

	DI() ;
	IRQ2ENH = (IRQ2ENH&(~IRQ_DMA)) | ((DMA_INT_PRIORITY&0x02)<<3 ) ;
	IRQ2ENL = (IRQ2ENL&(~IRQ_DMA)) | ((DMA_INT_PRIORITY&0x01)<<4 ) ;
	SET_VECTOR( DMA, isr_DMA ) ;
	DMA1CTL = (BYTE)( (BYTE)0x00 | DMA_CTL_IRQEN | DMA_CTL_RSS_UART0 ) ;
	EI() ;
#endif



	return ;

}//! end of open_UART0()



/*! End of File */


