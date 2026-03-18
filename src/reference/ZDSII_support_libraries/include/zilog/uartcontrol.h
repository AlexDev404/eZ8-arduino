/*!\file  uartcontrol.h
 * \brief Device Control Macro Definitions for Z8 Encore! Microcontrollers.
 *  
 *  This file contains device control macro definitions required
 *  by ZSL implementations for Z8 Encore! microcontrollers.
 *
 *  This source file uses Doxygen-style comments to generate
 *  documentation automatically.
 *
 *  Copyright (C) 1999-2004 by  ZiLOG, Inc.
 *  All Rights Reserved.
 */

#pragma once // Include this file only once
#ifndef _UARTCONTROL_H_
#define _UARTCONTROL_H_

#include <defines.h>
#include <uart.h>


#define ENABLED								1						//!< Generic symbols.
#define DISABLED							0

#define MODE_INTERRUPT						1						//!< Modes of operation.
#define MODE_POLLING						2

#define UART0								0						//!< UART device identification.
#define UART1								1



/*!
 * Device control macro definitions.
 */

/*!
 * Control macros used with UART drivers.
 * These control macros can be used for configuring the UART driver at compile time.
 */
#define DEFAULT_UART						UART0					//!< Default device control macro.

#ifdef _DEBUG
#define UARTPARAMETER_CHECKING									//!< Parameter validation control macro.
#endif

#define UART0_MODE							MODE_POLLING			//!< UART0 mode control macro.
#define UART0_BAUDRATE						BAUD_38400				//!< UART0 baudrate control macro.
#define UART0_DATABITS						DATABITS_8				//!< UART0 databits control macro.
#define UART0_STOPBITS						STOPBITS_1				//!< UART0 stopbits control macro.
#define UART0_PARITY						PAR_NOPARITY			//!< UART0 parity control macro.
#define UART0_ERRORCHECKING					DISABLED				//!< UART0 error handling control macro.
#define UART0_HWFLOW_CTL					DISABLED				//!< UART0 hardware flow control macro for transmitter.
#define UART0_RX_INT_PRIORITY				INTPRIORITY_NOMINAL		//!< UART0 receiver priority.
#define UART0_TX_INT_PRIORITY				INTPRIORITY_NOMINAL		//!< UART0 transmitter priority.

#ifdef EZ8_UART1
#define UART1_MODE							MODE_POLLING			//!< UART1 mode control macro.
#define UART1_BAUDRATE						BAUD_38400				//!< UART1 baudrate control macro.
#define UART1_DATABITS						DATABITS_8				//!< UART1 databits control macro.
#define UART1_STOPBITS						STOPBITS_1				//!< UART1 stopbits control macro.
#define UART1_PARITY						PAR_NOPARITY			//!< UART1 parity control macro.
#define UART1_ERRORCHECKING					DISABLED				//!< UART1 error handling control macro.
#define UART1_HWFLOW_CTL					DISABLED				//!< UART1 hardware flow control macro for transmitter.
#define UART1_RX_INT_PRIORITY				INTPRIORITY_NOMINAL		//!< UART1 receiver priority.
#define UART1_TX_INT_PRIORITY				INTPRIORITY_NOMINAL		//!< UART1 transmitter priority.
#endif

#define DMA_DISABLED						3						//!< DMA control definitions.
#if (UART0_MODE==MODE_INTERRUPT)
#define DMA_UART0							1						//!< For UART0 transmission (available only when UART0 is operated in interrupt mode).
#endif
#if (UART1_MODE==MODE_INTERRUPT)
#define DMA_UART1							2						//!< For UART1 transmission (available only when UART1 is operated in interrupt mode).
#endif

#ifdef EZ8_DMA
#define DMA1_CTL							DMA_DISABLED			//!< DMA for use with.
#define DMA_INT_PRIORITY					INTPRIORITY_NOMINAL		//!< DMA interrupt priority. Other valied values are defined in defines.h
#else
#define DMA1_CTL							DMA_DISABLED
#endif

#endif /*! _UARTCONTROL_H_ */

/*! End of File */


