/*!\file controlportc.c
 * \brief Implementation file for configuring Z8 Encore! GPIO Port C.
 *
 *  This file contains implementation for configuring Port C bits required
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
 *  Configure Port C.
 *
 * This API sets the values of the Port C registers by using the values in the PORT structure parameter.
 * This API can be used to set when setting all the registers of the Port. For setting an individual register
 * the an application may use predefined macros defined in gpio.h.
 */
VOID control_PortC( PORT *pPort )
{
	PCADDR = pPort->addr ;
	PCCTL = pPort->ctl ;
	PCOUT = pPort->out ;
	PCADDR = PORTADDR_NOFUNC ;

	return ;

}//! end of control_PortC()


/*! End of File */


