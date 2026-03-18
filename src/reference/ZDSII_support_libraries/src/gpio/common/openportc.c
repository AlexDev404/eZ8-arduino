/*!\file openportc.c
 * \brief Implementation file for initializing the Z8 Encore! GPIO Port C.
 *
 *  This file contains implementation for initializing the Port C
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
 * Open GPIO Port C.
 *
 * This API opens the Port C by initializing Port registers with default values defined in the
 * header file gpio.h.
*/
 /* @} */

VOID open_PortC( VOID )
{
	PCADDR = PORTC_ADDRVAL_DEF ;
	PCCTL = PORTC_CTLVAL_DEF ;

	/*! Disable all other modes */
	PCADDR = PORTADDR_ALTFUNC ;
	PCCTL = 0x00 ;
	PCADDR = PORTADDR_OPENDRAIN ;
	PCCTL = 0x00 ;
	PCADDR = PORTADDR_HIGHDRIVE ;
	PCCTL = 0x00 ;
	PCADDR = PORTADDR_STPMDREC ;
	PCCTL = 0x00 ;
#if defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F08) || defined(__ZSLBUILD)||defined(_Z8F1680)
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

}//! end of open_PortC()



/*! End of File */


