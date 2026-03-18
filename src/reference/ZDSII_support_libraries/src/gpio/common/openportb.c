/*!\file openportb.c
 * \brief Implementation file for initializing the Z8 Encore! GPIO Port B.
 *
 *  This file contains implementation for initializing the Port B
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
 * Open GPIO Port B.
 *
 * This API opens the Port B by initializing Port registers with default values defined in the
 * header file gpio.h.
*/
 /* @} */

VOID open_PortB( VOID )
{
	PBADDR = PORTB_ADDRVAL_DEF ;
	PBCTL = PORTB_CTLVAL_DEF ;

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

}//! end of open_PortB()



/*! End of File */


