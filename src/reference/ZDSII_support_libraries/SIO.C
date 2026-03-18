/*  SIO.C
 *****************************************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 ****************************************************************************/

#include <stdio.h>
#include <ez8.h>
#include <sio.h>
#include <uartcontrol.h>

// Alternate SFR definitions for single-UART CPUs such as the Z8FXX24 series
// Note that the following #if will work because ez8.h has already been #included
#if  defined(EZ8_UART)
#define U0D			UD
#define U0TXD		UTXD
#define U0RXD		URXD
#define U0STAT0		USTAT0
#define U0CTL0		UCTL0
#define U0CTL1		UCTL1
#define U0MDSTAT	UMDSTAT
#define U0ADDR		UADDR
#define U0BR		UBR
#define U0BRH		UBRH
#define U0BRL		UBRL
#endif



#define BRG(freq,baud) ((unsigned long)((freq)+(baud)*8ul)/((unsigned long)(baud)*16))

static char current_port = _UART0;

/*!
 * IMPORTANT NOTE: This file is modified to provide wrapper function
 * for init_uart(). Other implementations of this file are now moved
 * to Zilog Standard Library (ZSL), which is a new set of libraries
 * that includes the UART implementations. Other details related to
 * this important change is found in ReadMe file of this release.
 */

reentrant int select_port(int port)
{
    return (DEFAULT_UART==port) ? 0 : 1 ;
}

reentrant int init_uart(int port,unsigned long freq, unsigned long baud)
{
	unsigned short brgval = 0 ;



	/*! if the desired port is not the default port being set, return error */
	if( DEFAULT_UART != port )
	{
		return 1 ;						// return failure.
	}
	
	brgval = (freq+(unsigned long)baud*8ul)/((unsigned long)baud * 16) ;

#if (DEFAULT_UART==_UART0)
	/*! Set the baudrate generator */
	U0BRH = brgval >> (unsigned char)8 ;
	U0BRL = brgval & (unsigned char)0xFF ;

	/*! Configure GPIO Port A pins 4 & 5 for alternate function */
	PAADDR = 0x02 ;
	PACTL |= 0x30 ;			//!< Set bits in alternate function register.
	PAADDR = 0x07 ;
	PACTL &= 0xCF ;			//!< Reset bits in alternate function set-1 register.
	PAADDR = 0x08 ;
	PACTL &= 0xCF ;			//!< Reset bits in alternate function set-2 register.
	PAADDR = 0x00 ;

	U0CTL1 = 0x00 ;			//!< no multi-processor operation mode.
	U0CTL0 = 0xC0 ;			//!< Transmit enable, Receive enable, no Parity, 1 Stop bit.
#endif

#ifdef EZ8_UART1
#if (DEFAULT_UART==_UART1)
	/*! Set the baudrate generator */
	U1BRH = brgval >> (unsigned char)8 ;
	U1BRL = brgval & (unsigned char)0xFF ;

	/*! Configure GPIO Port D pins 4 & 5 for alternate function */
	PDADDR = 0x02 ;
	PDCTL |= 0x30 ;			//!< Set bits in alternate function register.
	PDADDR = 0x07 ;
	PDCTL &= 0xCF ;			//!< Reset bits in alternate function set-1 register.
	PDADDR = 0x08 ;
	PDCTL &= 0xCF ;			//!< Reset bits in alternate function set-2 register.
	PDADDR = 0x00 ;

	U1CTL1 = 0x00 ;			//!< no multi-processor operation mode.
	U1CTL0 = 0xC0 ;			//!< Transmit enable, Receive enable, no Parity, 1 Stop bit.
#endif
#endif

    return 0 ;

}
