/*************************************************
 *  Copyright (C) 2007 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#pragma once    // Include this file only once
extern char _current_port;


// Alternate SFR definitions for single-UART CPUs such as the Z8FXX24 series
// Note that the following #if will work because ez8.h is always #included before csio.h
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
