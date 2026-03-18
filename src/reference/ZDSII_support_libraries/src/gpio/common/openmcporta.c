/*!\file openmcporta.c
 * \brief Implementation file for initializing the Z8 Encore! GPIO Port A.
 *
 *  This file contains implementation for initializing the Port A
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
 * Open GPIO Port A.
 *
 * This API opens the Port A by initializing Port registers with default values defined in the
 * header file gpio.h.
*/
 /* @} */

VOID open_PortA( VOID )
{
	PAADDR = PORTA_ADDRVAL_DEF ;
	PACTL = PORTA_CTLVAL_DEF ;

	/*! Disable all other modes */
	PAADDR = PORTADDR_ALTFUNC0 ;
	PACTL = 0x00 ;
	PAADDR = PORTADDR_OPENDRAIN ;
	PACTL = 0x00 ;
	PAADDR = PORTADDR_HIGHDRIVE ;
	PACTL = 0x00 ;
	PAADDR = PORTADDR_STPMDREC ;
	PACTL = 0x00 ;
	PAADDR = PORTADDR_PULLUP ;
	PACTL = 0x00 ;
	PAADDR = PORTADDR_ALTFUNC1 ;
	PACTL = 0x00 ;
	PAADDR = PORTADDR_IRQES ;
	PACTL = 0x00 ;
	PAADDR = PORTADDR_IRQPS ;
	PACTL = 0x00 ;

	/*! Protect the control register */
	PAADDR = PORTADDR_NOFUNC ;


	return ;
	
}//! end of open_PortA()



/*! End of File */


