/*!\file closeportc.c
 * \brief Implementation file for closing Port C bits.
 *
 *  This file contains implementation for closing Port C bits required
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
 * Close Port C.
 *
 * This API resets all the Port C registers and configures the Port C as
 * standard digital input pins. All the registers except IN register is
 * filled with reset values.
 *
 * Return Values - None
 */
VOID close_PortC( VOID )
{
	PCADDR = PORTADDR_DATADIR ;			//!< Access Data Direction Register.
	PCCTL  = 0xFF ;						//!< Set all bits in the Data Direction Register.

	/*! Disable all other modes */
	PCADDR = PORTADDR_ALTFUNC ;
	PCCTL = 0x00 ;
	PCADDR = PORTADDR_OPENDRAIN ;
	PCCTL = 0x00 ;
	PCADDR = PORTADDR_HIGHDRIVE ;
	PCCTL = 0x00 ;
	PCADDR = PORTADDR_STPMDREC ;
	PCCTL = 0x00 ;
#if defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F08) ||defined(_Z8F1680)||defined(__ZSLBUILD)
	PCADDR = PORTADDR_PULLUP ;
	PCCTL = 0x00 ;
#endif
#if defined(_Z8F04) || defined(_Z8F04A) || defined(__ZSLBUILD)
	PCADDR = PORTADDR_ALTFUNCSET1 ;
	PCCTL = 0x00 ;
	PCADDR = PORTADDR_ALTFUNCSET2 ;
	PCCTL = 0x00 ;
#endif

	/*! Protect the control register */
	PCADDR = PORTADDR_NOFUNC ;

	return ;

}//! end of close_PortC()


/*! End of File */


