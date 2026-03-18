/*!\file closeporte.c
 * \brief Implementation file for closing Port E bits.
 *
 *  This file contains implementation for closing Port E bits required
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
 * Close Port E.
 *
 * This API resets all the Port E registers and configures the Port E as
 * standard digital input pins. All the registers except IN register is
 * filled with reset values.
 *
 * Return Values - None
 */
VOID close_PortE( VOID )
{
	PEADDR = PORTADDR_DATADIR ;			//!< Access Data Direction Register.
	PECTL  = 0xFF ;						//!< Set all bits in the Data Direction Register.

	/*! Disable all other modes */
	PEADDR = PORTADDR_ALTFUNC ;
	PECTL = 0x00 ;
	PEADDR = PORTADDR_OPENDRAIN ;
	PECTL = 0x00 ;
	PEADDR = PORTADDR_HIGHDRIVE ;
	PECTL = 0x00 ;
	PEADDR = PORTADDR_STPMDREC ;
	PECTL = 0x00 ;
#if defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F08) || defined(__ZSLBUILD)||defined(_Z8F1680)
	PEADDR = PORTADDR_PULLUP ;
	PECTL = 0x00 ;
#endif

	/*! Protect the control register */
	PEADDR = PORTADDR_NOFUNC ;


	return ;

}//! end of close_PortE()

/*! End of File */


