/*!\file openporth.c
 * \brief Implementation file for initializing the Z8 Encore! GPIO Port H.
 *
 *  This file contains implementation for initializing the Port H
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
 * Open GPIO Port H.
 *
 * This API opens the Port H by initializing Port registers with default values defined in the
 * header file gpio.h.
*/
 /* @} */

VOID open_PortH( VOID )
{
	PHADDR = PORTH_ADDRVAL_DEF ;
	PHCTL = PORTH_CTLVAL_DEF ;

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

}//! end of open_PortH()


/*! End of File */


