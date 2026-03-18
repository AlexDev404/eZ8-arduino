/*!\file closeportd.c
 * \brief Implementation file for closing Port D bits.
 *
 *  This file contains implementation for closing Port D bits required
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
 * Close Port D.
 *
 * This API resets all the Port D registers and configures the Port D as
 * standard digital input pins. All the registers except IN register is
 * filled with reset values.
 *
 * Return Values - None
 */
VOID close_PortD( VOID )
{
	PDADDR = PORTADDR_DATADIR ;			//!< Access Data Direction Register.
#if defined(_Z8F1680)
	PDCTL = 0xfe;			//!< Set all bits in the Data Direction Register.except PD0 for f1680 series
#else
	PDCTL = 0xFF ;			//!< Set all bits in the Data Direction Register.
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
#if defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F08)|| defined(_Z8F1680)|| defined(__ZSLBUILD)
	PDADDR = PORTADDR_PULLUP ;
	PDCTL = 0x00 ;
#endif

	/*! Protect the control register */
	PDADDR = PORTADDR_NOFUNC ;


	return ;

}//! end of close_PortD()

/*! End of File */


