/*!\file closeportb.c
 * \brief Implementation file for closing Port B bits.
 *
 *  This file contains implementation for closing Port B bits required
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
 * Close Port B.
 *
 * This API resets all the Port B registers and configures the Port B as
 * standard digital input pins. All the registers except IN register is
 * filled with reset values.
 *
 * Return Values - None
 */
VOID close_PortB( VOID )
{
	PBADDR = PORTADDR_DATADIR ;		//!< Access Data Direction Register.
	PBCTL  = 0xFF ;					//!< Set all bits in the Data Direction Register.

	/*! Disable all other modes */
	PBADDR = PORTADDR_ALTFUNC ;
	PBCTL = 0x00 ;
	PBADDR = PORTADDR_OPENDRAIN ;
	PBCTL = 0x00 ;
	PBADDR = PORTADDR_HIGHDRIVE ;
	PBCTL = 0x00 ;
	PBADDR = PORTADDR_STPMDREC ;
	PBCTL = 0x00 ;
#if defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F08) || defined(__ZSLBUILD)||defined(_Z8F1680)
	PBADDR = PORTADDR_PULLUP ;
	PBCTL = 0x00 ;
#endif
#if defined(_Z8F04) || defined(_Z8F04A) || defined(__ZSLBUILD)
	PBADDR = PORTADDR_ALTFUNCSET1 ;
	PBCTL = 0x00 ;
	PBADDR = PORTADDR_ALTFUNCSET2 ;
	PBCTL = 0x00 ;
#endif

	/*! Protect the control register */
	PBADDR = PORTADDR_NOFUNC ;


	return ;

}//! end of close_PortB()


/*! End of File */


