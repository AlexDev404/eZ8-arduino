/*!\file uart.h
 * \brief Header file for Z8 Encore! UART Devices.
 *
 *  This file contains header information required by UART driver
 *  implementations for Z8 Encore! microcontrollers.
 *
 *  This source file uses Doxygen-style comments to generate documentation
 *  automatically.
 *
 *  Copyright (C) 1999-2004 by  ZiLOG, Inc.
 *  All Rights Reserved.
 */

#pragma once // Include this file only once
#ifndef _UART_H_
#define _UART_H_

#include <defines.h>
#include <uartdefs.h>



/*! UART interrupt enable definitions used */
#if defined(_Z8FMC16)
#define IRQ_U0RXI						(BYTE)0x04
#define IRQ_U0TXI						(BYTE)0x02
#else
#define IRQ_U0RXI						(BYTE)0x10
#define IRQ_U0TXI						(BYTE)0x08
#endif

#ifdef EZ8_UART1
#define IRQ_U1RXI						(BYTE)0x40
#define IRQ_U1TXI						(BYTE)0x20
#endif

#define REGFILEADDR_U0TXD				0xF40
#define REGFILEADDR_U1TXD				0xF48

#define CLOCK_DIVISOR					16				//!< The default clock divisor used.
	
#define BAUD_9600						9600UL			//!< Baud rate 9600.
#define BAUD_19200						19200UL			//!< Baud rate 19200.
#define BAUD_38400						38400UL			//!< Baud rate 38400.
#define BAUD_57600						57600UL			//!< Baud rate 57600.
#define BAUD_115200						115200UL		//!< Baud rate 115200.										

#define DATABITS_8						8				//!< 8-bit single processor mode used with UARTs.
#define DATABITS_9						9				//!< 9-bit multiprocessor mode used with UARTs (not supported in this release).

#define STOPBITS_1						1				//!< The number of stop bits used in the driver.
#define STOPBITS_2						2				
														
#define PAR_NOPARITY					0	    			//!< No parity.
#define PAR_ODPARITY					3	    			//!< Odd parity.
#define PAR_EVPARITY					2	    			//!< Even parity.


/*!
 * The error codes consists of both the errors reported by the UART device
 * (through status registers), and the errors that occur in the UART driver
 * software.
 */
#define UART_ERR_NONE					((BYTE)0x00)		//!< The error code for success.
#define UART_ERR_KBHIT					((BYTE)0x01)		//!< The error code for keyboard hit.
#define UART_ERR_FRAMINGERR				((BYTE)0x02)		//!< The error code returned when Framing error occurs in the character received.
#define UART_ERR_PARITYERR				((BYTE)0x03)		//!< The error code returned when Parity error occurs in the character received.
#define UART_ERR_OVERRUNERR				((BYTE)0x04)		//!< The error code returned when Overrun error occurs in the receive buffer register.
#define UART_ERR_BREAKINDICATIONERR		((BYTE)0x05)		//!< The error code returned when Break Indication Error occurs.
#define UART_ERR_INVBAUDRATE			((BYTE)0x06)		//!< The error code returned when baud rate specified is invalid.
#define UART_ERR_INVPARITY				((BYTE)0x07)		//!< The error code returned when parity option specified is invalid.
#define UART_ERR_INVSTOPBITS			((BYTE)0x08)		//!< The error code returned when stop bits specified is invalid.
#define UART_ERR_INVDATABITS			((BYTE)0x09)		//!< The error code returned when data bits per character specified is invalid.
#define UART_ERR_BUSY					((BYTE)0x0A)		//!< Definition for 'UART busy'.
#define UART_ERR_NULLPOINTER			((BYTE)0x0B)		//!< The error code returned when a null pointer is passed by user application.

#define UART_ERR_FAILURE				((BYTE)-1)		//!< The error code for failures.

#define UART_ERR_USERBASE				((BYTE)0xF0)		//!< The error code base value for user applications. Usable values 0xF0 to 0xFE


#define UART_IO_PENDING					((BYTE)1)		//!< Definition for 'IO Pending'.
#define UART_IO_COMPLETE				((BYTE)0)		//!< Definition for 'IO complete'.


/*!
 * \brief The settings required to configure the UART driver.
 *
 * This structure will contain all the information required to
 * configure the UART device. This structure is used for opening
 * (initializing) the UART device as well as for re-configuring
 * the UART device.
 */
typedef struct
{
   INT32 baudRate ;						//!< The baudrate.
   BYTE stopBits ;							//!< The number of stopbits.
   BYTE parity ;							//!< The parity bit option.

} UART ;

typedef UINT8 BUFFSIZE_T ;

/*!
 * \brief The FIFO structure.
 *
 * This structure is used to hold information about the software
 * transmit/receive FIFO buffers implemented in interrupt mode.
 */
typedef struct
{
	UCHAR *pBuffer ;						//!< The FIFO buffer
	BUFFSIZE_T next_in ;					//!< The in-pointer
	BUFFSIZE_T next_out ;					//!< The out-pointer
	BUFFSIZE_T size ;						//!< The FIFO buffer size

} FIFO ;

/*! Macro definitions */
#define SETBRK_UART0()					U0CTL0 |= UART_CTL0_SBRK
#define RESETBRK_UART0()				U0CTL0 &= ~UART_CTL0_SBRK
#define ENABLEPARITY_UART0()			U0CTL0 |= UART_CTL0_PEN
#define DISABLEPARITY_UART0()			U0CTL0 &= ~UART_CTL0_PEN
#define SETODDPARITY_UART0()			U0CTL0 = (U0CTL0&~(UART_CTL0_PEN|UART_CTL0_PSEL)) | (PAR_ODPARITY<<3)
#define SETEVENPARITY_UART0()			U0CTL0 = (U0CTL0&~(UART_CTL0_PEN|UART_CTL0_PSEL)) | (PAR_EVPARITY<<3)

#ifdef EZ8_UART1
#define SETBRK_UART1()					U1CTL0 |= UART_CTL0_SBRK
#define RESETBRK_UART1()				U1CTL0 &= ~UART_CTL0_SBRK
#define ENABLEPARITY_UART1()			U1CTL0 |= UART_CTL0_PEN
#define DISABLEPARITY_UART1()			U1CTL0 &= ~UART_CTL0_PEN
#define SETODDPARITY_UART1()			U1CTL0 = (U1CTL0&~(UART_CTL0_PEN|UART_CTL0_PSEL)) | (PAR_ODPARITY<<3)
#define SETEVENPARITY_UART1()			U1CTL0 = (U1CTL0&~(UART_CTL0_PEN|UART_CTL0_PSEL)) | (PAR_EVPARITY<<3)
#endif


/*!
 * \brief Receive a character.
 */
INT getch( VOID ) ;

/*!
 * \brief Detect any key strokes in the keyboard connected to the default UART device.
 */
UCHAR kbhit( VOID ) ;

/*!
 * \brief Transmit a character.
 */
reentrant UCHAR putch( CHAR ) ;

/*!
 * \brief Initialize the UART0 device.
 */
VOID open_UART0( VOID ) ;

/*!
 * \brief Configure the UART0 device.
 */
UCHAR control_UART0( UART *pUART ) ;

/*!
 * \brief Set baudrate for UART0 device.
 */
UCHAR setbaud_UART0( UINT32 baud ) ;

/*!
 * \brief Set Parity for the UART0 device.
 */
UCHAR setparity_UART0( UCHAR parity ) ;

/*!
 * \brief Set Stopbits for the UART0 device.
 */
UCHAR setstopbits_UART0( UCHAR stopbits ) ;

/*!
 * \brief Write data bytes to the UART0 device.
 */
reentrant UCHAR write_UART0( CHAR *pData, UINT16 nbytes ) ;

/*!
 * \brief Return transmitter status for UART0.
 */
UCHAR get_txstatus_UART0( VOID ) ;

/*!
 * \brief Read data bytes from the UART0 device.
 */
UCHAR read_UART0( CHAR *pData, UINT16 *nbytes ) ;

/*!
 * \brief Return receiver status for UART0.
 */
UCHAR get_rxstatus_UART0( VOID ) ;

/*!
 * \brief Flush receiver for UART0.
 */
UCHAR flush_UART0( VOID ) ;

/*!
 * \brief Close the UART0 device.
 */
VOID close_UART0( VOID ) ;


#ifdef EZ8_UART1
/*!
 * \brief Initialize the UART1 device.
 */
VOID open_UART1( VOID ) ;

/*!
 * \brief Configure the UART1 device.
 */
UCHAR control_UART1( UART *pUART ) ;

/*!
 * \brief Set baudrate for UART1 device.
 */
UCHAR setbaud_UART1( UINT32 baud ) ;

/*!
 * \brief Set Parity for the UART1 device.
 */
UCHAR setparity_UART1( UCHAR parity ) ;

/*!
 * \brief Set Stopbits for the UART1 device.
 */
UCHAR setstopbits_UART1( UCHAR stopbits ) ;

/*!
 * \brief Write data bytes to the UART1 device.
 */
reentrant UCHAR write_UART1( CHAR *pData, UINT16 nbytes ) ;

/*!
 * \brief Return transmitter status for UART1.
 */
UCHAR get_txstatus_UART1( VOID ) ;

/*!
 * \brief Read data bytes from the UART1 device.
 */
UCHAR read_UART1( CHAR *pData, UINT16 *nbytes ) ;

/*!
 * \brief Return receiver status for UART1.
 */
UCHAR get_rxstatus_UART1( VOID ) ;

/*!
 * \brief Flush receiver for UART1.
 */
UCHAR flush_UART1( VOID ) ;

/*!
 * \brief Close the UART1 device.
 */
VOID close_UART1( VOID ) ;
#endif /*! EZ8_UART1 */



#endif /*! _UART_H_ */


/*! End of File */


