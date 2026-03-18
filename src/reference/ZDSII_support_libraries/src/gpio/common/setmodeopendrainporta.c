/*!\file setmodeopendrainporta.c
 * \brief Implementation file for setting open drain mode for Port A bits.
 *
 *  This file contains implementation for setting Port A bit to open drain mode
 *  required by GPIO driver implementations for Z8 Encore! microcontrollers.
 *
 *  This source file uses Doxygen-style comments to generate documentation
 *  automatically.
 *
 *  Copyright (C) 1999-2004 by  ZiLOG, Inc.
 *  All Rights Reserved.
 */

#include <ez8.h>


#ifdef GPIOPARAMETER_CHECKING
/*!
 * Port mask used for validating port pins. The definition of portamask
 * can be found in zsldevinit.asm included in the project.
 */
extern UCHAR portamask ;
#endif /*! GPIOPARAMETER_CHECKING */

/**
 * \ingroup GPIO
 */

/*!
 * @{
 * Set Open Drain Mode for Port A.
 *
 * This API can be used to configure one or more pins of Port A to Open Drain mode.
 * The open drain mode for each pin is controlled by setting each register bit
 * pertinent to the pin to be configured. For example, the open drain mode for Port A
 * Pin 7 (PA7) is set by the values contained in registers PA_ADDR and PA_CTL[7]. A
 * value of 03h in ADDR registers gives access to Output Control Register when CTL
 * register is referenced and setting bit 7 in that register will configure that bit
 * in open drain mode.
 *
 * As an example to set Pin 1 of Port A into open drain mode, write 03h in the ADDR to
 * access the Output Control Register and set bit 1. To acheive this, call this API
 * by specifying the bit corresponding to the pin by using the definitions given in
 * the gpio.h as shown below.
 * setmodeOpenDrain_PortA( PORTPIN_ONE ) ;
 *
 * Similarly more than one pin can be set to open drain mode by using ORing the pins
 * in the call to the API. For example, to set pin 5 and pin 7 of port A into open
 * drain mode the API can be used as shown below
 * setmodeOpenDrain_PortA( PORTPIN_FIVE|PORTPIN_SEVEN ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeOpenDrain_PortA( UCHAR pins )
{
#ifdef GPIOPARAMETER_CHECKING
	if( portamask & pins )
	{
		return GPIOERR_INVALIDPINS ;
	}
#endif /*! GPIOPARAMETER_CHECKING */

	/*! First, set the port pins to output mode */
	PAADDR = PORTADDR_DATADIR ;		//!< Get access to Data Direction register.
	RESETBIT( PACTL, pins ) ;		//!< Set bits corresponding to pins in Data Direction register.

	PAADDR = PORTADDR_OPENDRAIN ;	//!< Get access to Output Control register.
	SETBIT( PACTL, pins ) ;			//!< Set bits corresponding to pins in Output Control register.
	PAADDR = PORTADDR_NOFUNC ;		//!< Protect control registers.


	return GPIOERR_SUCCESS ;

}//! end of setmodeOpenDrain_PortA()


/*! End of File */


