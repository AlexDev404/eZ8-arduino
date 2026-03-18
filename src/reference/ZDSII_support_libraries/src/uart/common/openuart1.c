/*!\file openuart1.c
 * \brief Implementation file for initializing the UART1 Device.
 *
 *  This file contains implementation for initializing the UART1
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
extern UINT32 g_clock1 ;

/*!
 * \brief The UART1 receive interrupt service routine.
 */
extern VOID isr_UART1_RX( VOID ) ;

/*!
 * \brief The UART1 transmit interrupt service routine.
 */
extern VOID isr_UART1_TX( VOID ) ;

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
VOID open_UART1( VOID )
{
	UINT16 brgval = 0 ;



	/*! Compute the baudrate generator value */
//	brgval = ( g_clock1 ) / ( CLOCK_DIVISOR * UART1_BAUDRATE ) ;
	brgval = ( g_clock1 + (8UL*UART1_BAUDRATE) ) / ( CLOCK_DIVISOR * UART1_BAUDRATE ) ;		//with round-off.

	/*! Set baudarate generator */
	U1BRH = brgval >> (BYTE)8 ;
	U1BRL = brgval & (BYTE)0xFF ;


	/*! Configure port bits to alternate function */
#if (UART1_HWFLOW_CTL==ENABLED)
	setmodeAltFunc_PortD( PORTPIN_FOUR|PORTPIN_FIVE|PORTPIN_SIX ) ;
#else
	setmodeAltFunc_PortD( PORTPIN_FOUR|PORTPIN_FIVE ) ;
#endif

#if (UART1_DATABITS==DATABITS_8)
	/*! Disable multiprocessor mode. */
	U1CTL1 &= (~UART_CTL1_MPEN) ;
#else
	/*! not supported in this version */
#endif


	/*!
	 * Enable transmitter, receiver, set parity, stopbits, enable/disable interrupts, set
	 * interrupt priorities, interrupt vector table, and enable the interrupts, as
	 * applicable
	 */

	/*! Disable Tx and Rx interrupts, first */
 	IRQ2ENH &= ~(IRQ_U1RXI|IRQ_U1TXI) ;
	IRQ2ENL &= ~(IRQ_U1RXI|IRQ_U1TXI) ;
	
#if (UART1_MODE==MODE_INTERRUPT)
#if (DMA1_CTL==DMA_UART1)
	DI() ;
	U1CTL0 = (UART1_PARITY<<3) | ((UART1_STOPBITS-1)<<1) | (UART1_HWFLOW_CTL<<5) ;
	IRQ2ENH = ((UART1_RX_INT_PRIORITY&0x02)<<5) ;
	IRQ2ENL = ((UART1_RX_INT_PRIORITY&0x01)<<6) ;
	SET_VECTOR( UART1_RX_IVECT, isr_UART1_RX ) ;
	U1CTL0 |= UART_CTL0_TEN | UART_CTL0_REN ;
	EI() ;
#else
	DI() ;
	U1CTL0 = (UART1_PARITY<<3) | ((UART1_STOPBITS-1)<<1) | (UART1_HWFLOW_CTL<<5) ;
	IRQ2ENH = ((UART1_RX_INT_PRIORITY&0x02)<<5) | ((UART1_TX_INT_PRIORITY&0x02)<<4) ;
	IRQ2ENL = ((UART1_RX_INT_PRIORITY&0x01)<<6) | ((UART1_TX_INT_PRIORITY&0x01)<<5) ;
	SET_VECTOR( UART1_TX_IVECT, isr_UART1_TX ) ;
	SET_VECTOR( UART1_RX_IVECT, isr_UART1_RX ) ;
	U1CTL0 |= UART_CTL0_TEN | UART_CTL0_REN ;
	EI() ;
#endif
#else	//! Polling Mode
	U1CTL0 = (UART1_PARITY<<3) | ((UART1_STOPBITS-1)<<1) | (UART1_HWFLOW_CTL<<5) ;
	U1CTL0 |= UART_CTL0_TEN | UART_CTL0_REN ;
#endif

#if (DMA1_CTL==DMA_UART1)
	/*! Set the IO address to be used in the DMA1. */
	DMA1IO = (BYTE)(REGFILEADDR_U1TXD & (BYTE)0xFF) ;

	DI() ;
	IRQ2ENH = (IRQ2ENH&(~IRQ_DMA)) | ((DMA_INT_PRIORITY&0x02)<<3 ) ;
	IRQ2ENL = (IRQ2ENL&(~IRQ_DMA)) | ((DMA_INT_PRIORITY&0x01)<<4 ) ;
	SET_VECTOR( DMA, isr_DMA ) ;
	DMA1CTL = (BYTE)( (BYTE)0x00 | DMA_CTL_IRQEN | DMA_CTL_RSS_UART1 ) ;
	EI() ;
#endif





	return ;

}//! end of open_UART1()



/*! End of File */


