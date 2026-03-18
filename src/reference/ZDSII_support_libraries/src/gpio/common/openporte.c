/*!\file openporte.c
 * \brief Implementation file for initializing the Z8 Encore! GPIO Port E.
 *
 *  This file contains implementation for initializing the Port E
 *  required by GPIO driver implementations for Z8 Encore! microcontrollers.
 *
 *  This source file uses Doxygen-style comments to generate documentation
 *  automatically.
 *
 *  Copyright (C) 1999-2004 by  ZiLOG, Inc.
 *  All Rights Reserved.
 */

#include <ez8.h>

/** @defgroup GPIO GPIO-APIs
 */
/* @{ */
/**
 * @ingroup GPIO
 */
/*!
 * Open GPIO Port E.
 *
 * This API opens the Port E by initializing Port registers with default values defined in the
 * header file gpio.h.
*/
 /* @} */

VOID open_PortE( VOID )
{
	PEADDR = PORTE_ADDRVAL_DEF ;
	PECTL = PORTE_CTLVAL_DEF ;

	/*! Disable all other modes */
	PEADDR = PORTADDR_ALTFUNC ;
	PECTL = 0x00 ;
	PEADDR = PORTADDR_OPENDRAIN ;
	PECTL = 0x00 ;
	PEADDR = PORTADDR_HIGHDRIVE ;
	PECTL = 0x00 ;
	PEADDR = PORTADDR_STPMDREC ;
	PECTL = 0x00 ;
#if defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F08) || defined(__ZSLBUILD)||defined (_Z8F1680)
	PEADDR = PORTADDR_PULLUP ;
	PECTL = 0x00 ;
#endif

	/*! Protect the control register */
	PEADDR = PORTADDR_NOFUNC ;

	
	return ;

}//! end of open_PortE()


/*! End of File */


