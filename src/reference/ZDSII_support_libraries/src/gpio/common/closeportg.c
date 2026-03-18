/*!\file closeportg.c
 * \brief Implementation file for closing Port G bits.
 *
 *  This file contains implementation for closing Port G bits required
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
 * Close Port G.
 *
 * This API resets all the Port G registers and configures the Port G as
 * standard digital input pins. All the registers except IN register is
 * filled with reset values.
 *
 * Return Values - None
 */
VOID close_PortG( VOID )
{
	PGADDR = PORTADDR_DATADIR ;			//!< Access Data Direction Register.
	PGCTL  = 0xFF ;						//!< Set all bits in the Data Direction Register.

	/*! Disable all other modes */
	PGADDR = PORTADDR_ALTFUNC ;
	PGCTL = 0x00 ;
	PGADDR = PORTADDR_OPENDRAIN ;
	PGCTL = 0x00 ;
	PGADDR = PORTADDR_HIGHDRIVE ;
	PGCTL = 0x00 ;
	PGADDR = PORTADDR_STPMDREC ;
	PGCTL = 0x00 ;
#if defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F08) || defined(__ZSLBUILD)
	PGADDR = PORTADDR_PULLUP ;
	PGCTL = 0x00 ;
#endif

	/*! Protect the control register */
	PGADDR = PORTADDR_NOFUNC ;


	return ;

}//! end of close_PortG()

/*! End of File */


