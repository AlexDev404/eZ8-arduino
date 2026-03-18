/*!\file closemcporta.c
 * \brief Implementation file for closing Port A bits.
 *
 *  This file contains implementation for closing Port A bits required
 *  by GPIO driver implementations for Z8 Encore! microcontrollers.
 *
 *  This source file uses Doxygen-style comments to generate documentation
 *  automatically.
 *
 *  Copyright (C) 1999-2004 by  ZiLOG, Inc.
 *  All Rights Reserved.
 */
#include <ez8.h>

/**
 * \ingroup GPIO
 */
/*!
 * Close Port A.
 *
 * This API resets all the Port A registers and configures the Port A as
 * standard digital input pins. All the registers except IN register is
 * filled with reset values.
 *
 * Return Values - None
 */
VOID close_PortA( VOID )
{
	PAADDR = PORTADDR_DATADIR ;			//!< Access Data Direction Register.
	PACTL  = 0xFF ;						//!< Set all bits in the Data Direction Register.

	/*! Disable all other modes */
	PAADDR = PORTADDR_ALTFUNC0 ;
	PACTL = 0x00 ;
	PAADDR = PORTADDR_OPENDRAIN ;
	PACTL = 0x00 ;
	PAADDR = PORTADDR_HIGHDRIVE ;
	PACTL = 0x00 ;
	PAADDR = PORTADDR_STPMDREC ;
	PACTL = 0x00 ;
	PAADDR = PORTADDR_PULLUP ;
	PACTL = 0x00 ;
	PAADDR = PORTADDR_ALTFUNC1 ;
	PACTL = 0x00 ;
	PAADDR = PORTADDR_IRQES ;
	PACTL = 0x00 ;
	PAADDR = PORTADDR_IRQPS ;
	PACTL = 0x00 ;

	/*! Protect the control register */
	PAADDR = PORTADDR_NOFUNC ;


	return ;

}//! end of close_PortA()


/*! End of File */


