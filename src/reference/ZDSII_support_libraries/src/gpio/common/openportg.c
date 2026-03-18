/*!\file openportg.c
 * \brief Implementation file for initializing the Z8 Encore! GPIO Port G.
 *
 *  This file contains implementation for initializing the Port G
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
 * Open GPIO Port G.
 *
 * This API opens the Port G by initializing Port registers with default values defined in the
 * header file gpio.h.
*/
 /* @} */

VOID open_PortG( VOID )
{
	PGADDR = PORTG_ADDRVAL_DEF ;
	PGCTL = PORTG_CTLVAL_DEF ;

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

}//! end of open_PortG()


/*! End of File */


