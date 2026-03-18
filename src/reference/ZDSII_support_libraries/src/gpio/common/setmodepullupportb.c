/*!\file setmodepullupportb.c
 * \brief Implementation file for setting pull up mode for Port B bits.
 *
 *  This file contains implementation for setting Port B bit to pull up mode
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
 * Set Pull Up Mode for Port B.
 *
 * This API can be used to configure one or more pins of Port B to pull up mode. The
 * pull up mode for each pin is controlled by setting each register bit pertinent to
 * the pin to be configured. For example, the pull up mode for Port B Pin 7 (PB7) is
 * set by the values contained in registers PB_ADDR and PB_CTL[7]. A value of 06h
 * in ADDR registers gives access to Pull Up Enable Register when CTL register is
 * referenced and setting bit 7 in that register will configure that bit in pull up
 * mode.
 *
 * As an example to set Pin 1 of Port B into pull up mode, write 06h in the ADDR to
 * access the Pull Up Enable Register and reset bit 1. To acheive this, call this API
 * by specifying the bit corresponding to the pin by using the definitions given in
 * the gpio.h as shown below.
 * setmodePullUp_PortB( PORTPIN_ONE ) ;
 *
 * Similarly more than one pin can be set to pull up mode by using ORing the pins in the
 * call to the API. Eg., to set pin 5 and pin 7 of port B into pull up mode the API
 * can be used as shown below
 * setmodePullUp_PortB( PORTPIN_FIVE|PORTPIN_SEVEN ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodePullUp_PortB( UCHAR pins )
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

	PBADDR = PORTADDR_PULLUP ;		//!< Get access to Pull Up Enable register.
	SETBIT( PBCTL, pins ) ;			//!< Set bits corresponding to pins in Pull Up Enable register.
	PBADDR = PORTADDR_NOFUNC ;		//!< Protect control registers.


	return GPIOERR_SUCCESS ;

}//! end of setmodePullUp_PortB()


/*! End of File */

