/*!\file closeportf.c
 * \brief Implementation file for closing Port F bits.
 *
 *  This file contains implementation for closing Port F bits required
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
 * Close Port F.
 *
 * This API resets all the Port F registers and configures the Port F as
 * standard digital input pins. All the registers except IN register is
 * filled with reset values.
 *
 * Return Values - None
 */
VOID close_PortF( VOID )
{
	PFADDR = PORTADDR_DATADIR ;			//!< Access Data Direction Register.
	PFCTL  = 0xFF ;						//!< Set all bits in the Data Direction Register.

	/*! Disable all other modes */
	PFADDR = PORTADDR_ALTFUNC ;
	PFCTL = 0x00 ;
	PFADDR = PORTADDR_OPENDRAIN ;
	PFCTL = 0x00 ;
	PFADDR = PORTADDR_HIGHDRIVE ;
	PFCTL = 0x00 ;
	PFADDR = PORTADDR_STPMDREC ;
	PFCTL = 0x00 ;
#if defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F08) || defined(__ZSLBUILD)
	PFADDR = PORTADDR_PULLUP ;
	PFCTL = 0x00 ;
#endif

	/*! Protect the control register */
	PFADDR = PORTADDR_NOFUNC ;


	return ;

}//! end of close_PortF()

/*! End of File */


