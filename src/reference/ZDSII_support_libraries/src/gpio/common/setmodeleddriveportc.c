/*!\file setmodeleddriveportc.c
 * \brief Implementation file for setting LED Drive mode for Port C bits.
 *
 *  This file contains implementation for setting Port C bit to LED Drive mode
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
 * Port mask used for validating port pins. The definition of portcmask
 * can be found in zsldevinit.asm included in the project.
 */
extern UCHAR portcmask ;
#endif /*! GPIOPARAMETER_CHECKING */


/**
 * \ingroup GPIO
 */

/*!
 * @{
 * Set LED Drive mode for Port C.
 *
 * This API can be used to configure one or more pins of Port C to LED Drive 
 * mode. The LED Drive mode for each pin is controlled by setting each register
 * bit pertinent to the pin to be configured. For example, the LED Drive mode for
 * Port C Pin 7 (PC7) is set by the values contained in registers PC_ADDR, PC_CTL[7], LEDEN[7],
 * LEDLVLH[7], and LEDLVLL[7]. A value of 02h in ADDR registers gives access to Alternate Function
 * Register when CTL register is referenced and setting bit 7 in that register will configure that bit in
 * alternate function mode. Similarly the alternate function set-1 register is accessed. LED Drive Enable,
 * LED drive level high and level low register are accessed directly.
 *
 * As an example to set Pin 1 of Port C into LED Drive mode, write 02h in the ADDR to
 * access the Alternate Function Register and set bit 1. To acheive this, call this API by
 * specifying the bit corresponding to the pin by using the definitions given in the gpio.h
 * as shown below.
 * setmodeLEDDrive_PortC( PORTPIN_ONE ) ;
 *
 * Similarly more than one pin can be set to LED Drive mode by using ORing the pins
 * in the call to the API. For example, to set pin 5 and pin 7 of port C into LED Drive
 * mode the API can be used as shown below
 * setmodeLEDDrive_PortC( PORTPIN_FIVE|PORTPIN_SEVEN ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeLEDDrive_PortC( UCHAR pins, BYTE drivelevels )
{

#ifdef GPIOPARAMETER_CHECKING
	if( portcmask & pins )
	{
		return GPIOERR_INVALIDPINS ;
	}
#endif /*! GPIOPARAMETER_CHECKING */

	/*! Configure these pins to output mode, first */
	PCADDR = PORTADDR_DATADIR ;
	RESETBIT( PCCTL, pins ) ;

	PCADDR = PORTADDR_ALTFUNCSET1 ;	//!< Get access to Alternate Function Set-1 register.
	SETBIT( PCCTL, pins ) ;			//!< Set bits corresponding to pins in Alternate Function Set-1 register.

	PCADDR = PORTADDR_NOFUNC ;		//!< Protect control registers.

	SETBIT( LEDEN, pins ) ;			//!< Set LED Drive Enable register bits to connect controlled current source.

	/*! Set current drive levels */
	if( DRIVELEVEL_20MA == drivelevels )
	{
		SETBIT( LEDLVLH, pins ) ;
		SETBIT( LEDLVLL, pins ) ;
	}
	else
	{
		RESETBIT( LEDLVLH, pins ) ;
		RESETBIT( LEDLVLL, pins ) ;
	}

	if( DRIVELEVEL_7MA == drivelevels )
	{
		SETBIT( LEDLVLL, pins ) ;
	}

	else if( DRIVELEVEL_13MA == drivelevels )
	{
		SETBIT( LEDLVLH, pins ) ;
	}
	


	return GPIOERR_SUCCESS ;

}//! end of setmodeLEDDrive_PortC()


/*! End of File */


