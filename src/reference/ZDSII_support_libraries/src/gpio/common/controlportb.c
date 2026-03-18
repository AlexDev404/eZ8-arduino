/*!\file controlportb.c
 * \brief Implementation file for configuring Z8 Encore! GPIO Port B.
 *
 *  This file contains implementation for configuring Port B bits required
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
 *  Configure Port B.
 *
 * This API sets the values of the Port B registers by using the values in the PORT structure parameter.
 * This API can be used to set when setting all the registers of the Port. For setting an individual register
 * the an application may use predefined macros defined in gpio.h.
 */
VOID control_PortB( PORT *pPort )
{
	PBADDR = pPort->addr ;
	PBCTL = pPort->ctl ;
	PBOUT = pPort->out ;
	PBADDR = PORTADDR_NOFUNC ;

	return ;

}//! end of control_PortB()


/*! End of File */


