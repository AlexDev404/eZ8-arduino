/*!\file uartdefs.h
 * \brief UART register bit definitions for Z8 Encore! UART Devices.
 *  
 *  This file contains header information required by UART driver
 *  implementations for Z8 Encore! microcontrollers.
 *
 *  This source file uses Doxygen-style comments to generate
 *  documentation automatically.
 *
 *  Copyright (C) 1999-2004 by  ZiLOG, Inc.
 *  All Rights Reserved.
 */

#pragma once // Include this file only once
#ifndef _UARTDEFS_H_
#define _UARTDEFS_H_


#include <defines.h>


#define UART_STAT0_RDA				((BYTE)0x80)	//!< Receive Data Available indication in status-0 register.
#define UART_STAT0_PE				((BYTE)0x40)	//!< Parity Error indication in status-0 register.
#define UART_STAT0_OE				((BYTE)0x20)	//!< Overrun Error indication in status-0 register.
#define UART_STAT0_FE				((BYTE)0x10)	//!< Framing Error indication in status-0 register.
#define UART_STAT0_BRKD				((BYTE)0x08)	//!< Break Detect indication in status-0 register.
#define UART_STAT0_TDRE				((BYTE)0x04)	//!< Transmitter Data Register Empty indication in status-0 register.
#define UART_STAT0_TXE				((BYTE)0x02)	//!< Transmitter Empty indication in status-0 register.
#define UART_STAT0_CTS				((BYTE)0x01)	//!< CTS signal indication in status-0 regisrer.

#define UART_STAT1_NEWFRM			((BYTE)0x02)	//!< Start of new frame indication in status-1 register.
#define UART_STAT1_MPRX				((BYTE)0x01)	//!< Multiprocessor Receive indication in status-1 register.

#define UART_CTL0_TEN				((BYTE)0x80)	//!< Transmit enable bit in control-0 register.
#define UART_CTL0_REN				((BYTE)0x40)	//!< Receive enable bit in control-0 register.
#define UART_CTL0_CTSE				((BYTE)0x20)	//!< CTS enable bit in control-0 register.
#define UART_CTL0_PEN				((BYTE)0x10)	//!< Parity enable bit in control-0 register.
#define UART_CTL0_PSEL				((BYTE)0x08)	//!< Parity select bit in control-0 register.
#define UART_CTL0_SBRK				((BYTE)0x04)	//!< Send Break bit in control-0 register.
#define UART_CTL0_STOP				((BYTE)0x02)	//!< Stop bit select bit in control-0 register.
#define UART_CTL0_LBEN				((BYTE)0x01)	//!< Loop back enable bit in control-0 register.

#define UART_CTL1_MPMD1				((BYTE)0x80)	//!< Multiprocessor mode select bit 1 in control-1 register.
#define UART_CTL1_MPEN				((BYTE)0x40)	//!< Multiprocessor mode enable bit in control-1 register.
#define UART_CTL1_MPMD0				((BYTE)0x20)	//!< Multiprocessor mode select bit 0 in control-1 register.
#define UART_CTL1_MPBT				((BYTE)0x10)	//!< Multiprocessor Bit Transmit bit in control-1 register.
#define UART_CTL1_DEPOL				((BYTE)0x08)	//!< Driver Enable Polority bit in control-1 register.
#define UART_CTL1_BRGCTL			((BYTE)0x04)	//!< Baud Rate Control bit in control-1 register.
#define UART_CTL1_RDAIRQ			((BYTE)0x02)	//!< Receive Data Interrupt Enable bit in control-1 register.
#define UART_CTL1_IREN				((BYTE)0x01)	//!< Infrared Encoder/Decoder Enable bit in control-1 register.

#endif /*! _UARTDEFS_H_ */


/*! End of File */

