/*!\file setmodehighdriveportc.c
 * \brief Implementation file for setting high drive enable mode for
 *        Port C bits.
 *
 *  This file contains implementation for setting Port C bit to high drive
 *  enable mode required by GPIO driver implementations for Z8 Encore!
 *  microcontrollers.
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
 * Set High Drive Enable Mode for Port C.
 *
 * This API can be used to configure one or more pins of Port C to High Drive mode.
 * The high drive mode for each pin is controlled by setting each register bit
 * pertinent to the pin to be configured. For example, the high drive mode for Port C
 * Pin 7 (PC7) is set by the values contained in registers PC_ADDR and PC_CTL[7]. A
 * value of 04h in ADDR registers gives access to High Drive Enable Register when CTL
 * register is referenced and setting bit 7 in that register will configure that bit
 * in high drive mode.
 *
 * As an example to set Pin 1 of Port C into high drive mode, write 04h in the ADDR to
 * access the High Drive Enable Register and set bit 1. To acheive this, call this API
 * by specifying the bit corresponding to the pin by using the definitions given in
 * the gpio.h as shown below.
 * setmodeHighDrive_PortC( PORTPIN_ONE ) ;
 *
 * Similarly more than one pin can be set to high drive mode by using ORing the pins
 * in the call to the API. For example, to set pin 5 and pin 7 of port C into high
 * drive mode the API can be used as shown below
 * setmodeHighDrive_PortC( PORTPIN_FIVE|PORTPIN_SEVEN ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeHighDrive_PortC( UCHAR pins )
{

#ifdef GPIOPARAMETER_CHECKING
	if( portcmask & pins )
	{
		return GPIOERR_INVALIDPINS ;
	}
#endif /*! GPIOPARAMETER_CHECKING */

	/*! First, set the port pins to output mode */
	PCADDR = PORTADDR_DATADIR ;		//!< Get access to Data Direction register.
	RESETBIT( PCCTL, pins ) ;		//!< Set bits corresponding to pins in Data Direction register.

	PCADDR = PORTADDR_HIGHDRIVE ;	//!< Get access to High Drive Enable register.
	SETBIT( PCCTL, pins ) ;			//!< Set bits corresponding to pins in High Drive Enable register.
	PCADDR = PORTADDR_NOFUNC ;		//!< Protect control registers.


	return GPIOERR_SUCCESS ;

}//! end of setmodeHighDrive_PortC()


/*! End of File */


