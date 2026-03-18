/*!\file openportf.c
 * \brief Implementation file for initializing the Z8 Encore! GPIO Port F.
 *
 *  This file contains implementation for initializing the Port F
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
 * Open GPIO Port F.
 *
 * This API opens the Port F by initializing Port registers with default values defined in the
 * header file gpio.h.
*/
 /* @} */

VOID open_PortF( VOID )
{
	PFADDR = PORTF_ADDRVAL_DEF ;
	PFCTL = PORTF_CTLVAL_DEF ;

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

}//! end of open_PortF()


/*! End of File */


