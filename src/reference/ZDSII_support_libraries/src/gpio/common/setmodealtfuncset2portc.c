/*!\file setmodealtfuncset2portc.c
 * \brief Implementation file for setting Alternate Function Set-2 mode for Port C bits.
 *
 *  This file contains implementation for setting Port C bit to Alternate Function
 *  Set-2 required by GPIO driver implementations for Z8 Encore! microcontrollers.
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
 * Set Alternate Function Set-2 mode for Port C.
 *
 * This API can be used to configure one or more pins of Port C to alternate function set-2
 * mode. The alternate function set-2 mode for each pin is controlled by setting each register
 * bit pertinent to the pin to be configured. For example, the alternate function set-3 mode for
 * Port A Pin 7 (PA7) is set by the values contained in registers PA_ADDR and PA_CTL[7].
 * A value of 02h in ADDR registers gives access to Alternate Function Register when CTL
 * register is referenced and setting bit 7 in that register will configure that bit in
 * alternate function mode. Similarly the alternate function set-1 register is accessed.
 *
 * As an example to set Pin 1 of Port C into alternate function set-2 mode, call this API by
 * specifying the bit corresponding to the pin by using the definitions given in the gpio.h
 * as shown below.
 * setmodeAltFuncSet2_PortC( PORTPIN_ONE ) ;
 *
 * Similarly more than one pin can be set to alternate function set-2 mode by using ORing the pins
 * in the call to the API. For example, to set pin 5 and pin 7 of port C into alternate 
 * function set-2 mode the API can be used as shown below
 * setmodeAltFuncSet2_PortC( PORTPIN_FIVE|PORTPIN_SEVEN ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeAltFuncSet2_PortC( UCHAR pins )
{

#ifdef GPIOPARAMETER_CHECKING
	if( portcmask & pins )
	{
		return GPIOERR_INVALIDPINS ;
	}
#endif /*! GPIOPARAMETER_CHECKING */

	/*! Configure these pins to alternate function mode, first */
	PCADDR = PORTADDR_ALTFUNC ;
	SETBIT( PCCTL, pins ) ;

	PCADDR = PORTADDR_ALTFUNCSET1 ;	//!< Get access to Alternate Function Set-1 register.
	SETBIT( PCCTL, pins ) ;			//!< Set bits corresponding to pins in Alternate Function Set-1 register.

	PCADDR = PORTADDR_NOFUNC ;		//!< Protect control registers.

	RESETBIT( LEDEN, pins ) ;		//!< Reset LED Drive Enable register bits to tri-state the pins.
									//!< (for 4K devices this statement does not have any effect)


	return GPIOERR_SUCCESS ;

}//! end of setmodeAltFuncSet2_PortC()


/*! End of File */


