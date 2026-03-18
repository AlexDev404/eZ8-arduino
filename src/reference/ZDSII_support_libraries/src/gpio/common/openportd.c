/*!\file openportd.c
 * \brief Implementation file for initializing the Z8 Encore! GPIO Port D.
 *
 *  This file contains implementation for initializing the Port D
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
 * Open GPIO Port D.
 *
 * This API opens the Port D by initializing Port registers with default values defined in the
 * header file gpio.h.
*/
 /* @} */

VOID open_PortD( VOID )
{
 
	PDADDR = PORTD_ADDRVAL_DEF ;
#if defined(_Z8F1680)
	PDCTL = 0xfe;
#else
	PDCTL = PORTD_CTLVAL_DEF ;
#endif	

	/*! Disable all other modes */
	PDADDR = PORTADDR_ALTFUNC ;
	PDCTL = 0x01 ;
	PDADDR = PORTADDR_OPENDRAIN ;
	PDCTL = 0x00 ;
	PDADDR = PORTADDR_HIGHDRIVE ;
	PDCTL = 0x00 ;
	PDADDR = PORTADDR_STPMDREC ;
	PDCTL = 0x00 ;
#if defined(_Z8F04)|| defined (_Z8F1680) || defined(_Z8F04A) || defined(_Z8F08) || defined(__ZSLBUILD)
	PDADDR = PORTADDR_PULLUP ;
	PDCTL = 0x00 ;
#endif

	/*! Protect the control register */
	PDADDR = PORTADDR_NOFUNC ;


	return ;

}//! end of open_PortD()


/*! End of File */


