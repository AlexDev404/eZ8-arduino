/*!\file closeporth.c
 * \brief Implementation file for closing Port H bits.
 *
 *  This file contains implementation for closing Port H bits required
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
 * Close Port H.
 *
 * This API resets all the Port H registers and configures the Port H as
 * standard digital input pins. All the registers except IN register is
 * filled with reset values.
 *
 * Return Values - None
 */
VOID close_PortH( VOID )
{
	PHADDR = PORTADDR_DATADIR ;			//!< Access Data Direction Register.
	PHCTL  = 0xFF ;						//!< Set all bits in the Data Direction Register.

	/*! Disable all other modes */
	PHADDR = PORTADDR_ALTFUNC ;
	PHCTL = 0x00 ;
	PHADDR = PORTADDR_OPENDRAIN ;
	PHCTL = 0x00 ;
	PHADDR = PORTADDR_HIGHDRIVE ;
	PHCTL = 0x00 ;
	PHADDR = PORTADDR_STPMDREC ;
	PHCTL = 0x00 ;
#if defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F08) || defined(__ZSLBUILD)
	PHADDR = PORTADDR_PULLUP ;
	PHCTL = 0x00 ;
#endif

	/*! Protect the control register */
	PHADDR = PORTADDR_NOFUNC ;


	return ;

}//! end of close_PortH()

/*! End of File */


