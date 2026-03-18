/*!\file setmodepullupporte.c
 * \brief Implementation file for setting pull up mode for Port A bits.
 *
 *  This file contains implementation for setting Port E bit to pull up mode
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
extern UCHAR portemask ;
#endif /*! GPIOPARAMETER_CHECKING */

/**
 * \ingroup GPIO
 */

/*!
 * @{
 * Set Pull Up Mode for Port E.
 *
 * This API can be used to configure one or more pins of Port E to pull up mode. The
 * pull up mode for each pin is controlled by setting each register bit pertinent to
 * the pin to be configured. For example, the pull up mode for Port E Pin 2 (PE7) is
 * set by the values contained in registers PE_ADDR and PE_CTL[7]. A value of 06h
 * in ADDR registers gives access to Pull Up Enable Register when CTL register is
 * referenced and setting bit 2 in that register will configure that bit in pull up
 * mode.
 *
 * As an example to set Pin 1 of Port E into pull up mode, write 06h in the ADDR to
 * access the Pull Up Enable Register and reset bit 1. To acheive this, call this API
 * by specifying the bit corresponding to the pin by using the definitions given in
 * the gpio.h as shown below.
 * setmodePullUp_PortE( PORTPIN_ONE ) ;
 *
 * Similarly more than one pin can be set to pull up mode by using ORing the pins in the
 * call to the API. Eg., to set pin 5 and pin 1 of port A into pull up mode the API
 * can be used as shown below
 * setmodePullUp_PortE( PORTPIN_FIVE|PORTPIN_ONE ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodePullUp_PortE( UCHAR pins )
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

	PEADDR = PORTADDR_PULLUP ;		//!< Get access to Pull Up Enable register.
	SETBIT( PECTL, pins ) ;			//!< Set bits corresponding to pins in Pull Up Enable register.
	PEADDR = PORTADDR_NOFUNC ;		//!< Protect control registers.


	return GPIOERR_SUCCESS ;

}//! end of setmodePullUp_PortA()


/*! End of File */

