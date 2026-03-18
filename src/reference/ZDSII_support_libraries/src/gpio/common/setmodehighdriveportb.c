/*!\file setmodehighdriveportb.c
 * \brief Implementation file for setting high drive enable mode for
 *        Port B bits.
 *
 *  This file contains implementation for setting Port B bit to high drive
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
 * Port mask used for validating port pins. The definition of portbmask
 * can be found in zsldevinit.asm included in the project.
 */
extern UCHAR portbmask ;
#endif /*! GPIOPARAMETER_CHECKING */


/**
 * \ingroup GPIO
 */

/*!
 * @{
 * Set High Drive Enable Mode for Port B.
 *
 * This API can be used to configure one or more pins of Port B to High Drive mode.
 * The high drive mode for each pin is controlled by setting each register bit
 * pertinent to the pin to be configured. For example, the high drive mode for Port B
 * Pin 7 (PB7) is set by the values contained in registers PB_ADDR and PB_CTL[7]. A
 * value of 04h in ADDR registers gives access to High Drive Enable Register when CTL
 * register is referenced and setting bit 7 in that register will configure that bit
 * in high drive mode.
 *
 * As an example to set Pin 1 of Port B into high drive mode, write 04h in the ADDR to
 * access the High Drive Enable Register and set bit 1. To acheive this, call this API
 * by specifying the bit corresponding to the pin by using the definitions given in
 * the gpio.h as shown below.
 * setmodeHighDrive_PortB( PORTPIN_ONE ) ;
 *
 * Similarly more than one pin can be set to high drive mode by using ORing the pins
 * in the call to the API. For example, to set pin 5 and pin 7 of port B into high
 * drive mode the API can be used as shown below
 * setmodeHighDrive_PortB( PORTPIN_FIVE|PORTPIN_SEVEN ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeHighDrive_PortB( UCHAR pins )
{

#ifdef GPIOPARAMETER_CHECKING
	if( portbmask & pins )
	{
		return GPIOERR_INVALIDPINS ;
	}
#endif /*! GPIOPARAMETER_CHECKING */

	/*! First, set the port pins to output mode */
	PBADDR = PORTADDR_DATADIR ;		//!< Get access to Data Direction register.
	RESETBIT( PBCTL, pins ) ;		//!< Set bits corresponding to pins in Data Direction register.

	PBADDR = PORTADDR_HIGHDRIVE ;	//!< Get access to High Drive Enable register.
	SETBIT( PBCTL, pins ) ;			//!< Set bits corresponding to pins in High Drive Enable register.
	PBADDR = PORTADDR_NOFUNC ;		//!< Protect control registers.


	return GPIOERR_SUCCESS ;

}//! end of setmodeHighDrive_PortB()


/*! End of File */


