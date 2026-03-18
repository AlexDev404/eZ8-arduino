/*!\file openmcuart0.c
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
 \ingroup UART
*/
/*!
@{
*/

/*!
 * Initialize the UART0 device.
 *
 * The open_UART0() API opens the UAR device by initializing the UART0
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
	setmodeAltFuncSet3_PortA( PORTPIN_THREE|PORTPIN_FOUR|PORTPIN_FIVE ) ;
#else
	setmodeAltFuncSet3_PortA( PORTPIN_FOUR|PORTPIN_FIVE ) ;
	//setmodeAltFunc_PortA( PORTPIN_FOUR|PORTPIN_FIVE ) ;
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
	DI() ;
	U0CTL0 = (UART0_PARITY<<3) | ((UART0_STOPBITS-1)<<1) | (UART0_HWFLOW_CTL<<5) ;
	IRQ0ENH = ((UART0_RX_INT_PRIORITY&0x02)<<1) | (UART0_TX_INT_PRIORITY&0x02) ;
	IRQ0ENL = ((UART0_RX_INT_PRIORITY&0x01)<<2) | ((UART0_TX_INT_PRIORITY&0x01)<<1) ;
	SET_VECTOR( UART0_TX_IVECT, isr_UART0_TX ) ;
	SET_VECTOR( UART0_RX_IVECT, isr_UART0_RX ) ;
	U0CTL0 |= UART_CTL0_TEN | UART_CTL0_REN ;
	EI() ;
#else		//! Polling Mode
	U0CTL0 = (UART0_PARITY<<3) | ((UART0_STOPBITS-1)<<1) | (UART0_HWFLOW_CTL<<5) ;
	U0CTL0 |= UART_CTL0_TEN | UART_CTL0_REN ;
#endif



	return ;

}//! end of open_UART0()



/*! End of File */


