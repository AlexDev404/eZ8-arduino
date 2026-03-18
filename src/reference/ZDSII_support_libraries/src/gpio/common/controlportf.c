/*!\file controlportf.c
 * \brief Implementation file for configuring Z8 Encore! GPIO Port F.
 *
 *  This file contains implementation for configuring Port F bits required
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
 *  Configure Port F.
 *
 * This API sets the values of the Port F registers by using the values in the PORT structure parameter.
 * This API can be used to set when setting all the registers of the Port. For setting an individual register
 * the an application may use predefined macros defined in gpio.h.
 */
VOID control_PortF( PORT *pPort )
{
	PFADDR = pPort->addr ;
	PFCTL = pPort->ctl ;
	PFOUT = pPort->out ;
	PFADDR = PORTADDR_NOFUNC ;

	return ;

}//! end of control_PortF()

/*! End of File */


