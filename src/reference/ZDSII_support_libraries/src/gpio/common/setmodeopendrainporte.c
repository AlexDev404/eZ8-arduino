/*!\file setmodeopendrainporte.c
 * \brief Implementation file for setting open drain mode for Port E bits.
 *
 *  This file contains implementation for setting Port E bit to open drain mode
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
 * Port mask used for validating port pins. The definition of portemask
 * can be found in zsldevinit.asm included in the project.
 */
extern UCHAR portemask ;
#endif /*! GPIOPARAMETER_CHECKING */


/**
 * \ingroup GPIO
 */

/*!
 * @{
 * Set Open Drain Mode for Port E.
 *
 * This API can be used to configure one or more pins of Port E to Open Drain mode.
 * The open drain mode for each pin is controlled by setting each register bit
 * pertinent to the pin to be configured. For example, the open drain mode for Port E
 * Pin 7 (PE7) is set by the values contained in registers PE_ADDR and PE_CTL[7]. A
 * value of 03h in ADDR registers gives access to Output Control Register when CTL
 * register is referenced and setting bit 7 in that register will configure that bit
 * in open drain mode.
 *
 * As an example to set Pin 1 of Port E into open drain mode, write 03h in the ADDR to
 * access the Output Control Register and set bit 1. To acheive this, call this API
 * by specifying the bit corresponding to the pin by using the definitions given in
 * the gpio.h as shown below.
 * setmodeOpenDrain_PortE( PORTPIN_ONE ) ;
 *
 * Similarly more than one pin can be set to open drain mode by using ORing the pins
 * in the call to the API. For example, to set pin 5 and pin 7 of port E into open
 * drain mode the API can be used as shown below
 * setmodeOpenDrain_PortE( PORTPIN_FIVE|PORTPIN_SEVEN ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeOpenDrain_PortE( UCHAR pins )
{

#ifdef GPIOPARAMETER_CHECKING
	if( portemask & pins )
	{
		return GPIOERR_INVALIDPINS ;
	}
#endif /*! GPIOPARAMETER_CHECKING */

	/*! First, set the port pins to output mode */
	PEADDR = PORTADDR_DATADIR ;		//!< Get access to Data Direction register.
	RESETBIT( PECTL, pins ) ;		//!< Set bits corresponding to pins in Data Direction register.

	PEADDR = PORTADDR_OPENDRAIN ;	//!< Get access to Output Control register.
	SETBIT( PECTL, pins ) ;			//!< Set bits corresponding to pins in Output Control register.
	PEADDR = PORTADDR_NOFUNC ;		//!< Protect control registers.


	return GPIOERR_SUCCESS ;

}//! end of setmodeOpenDrain_PortE()

/*! End of File */


