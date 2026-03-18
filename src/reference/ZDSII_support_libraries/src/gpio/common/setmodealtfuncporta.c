/*!\file setmodealtfuncporta.c
 * \brief Implementation file for setting Alternate Function mode for Port A bits.
 *
 *  This file contains implementation for setting Port A bit to Alternate Function
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
 * Set Alternate Function mode for Port A.
 *
 * This API can be used to configure one or more pins of Port A to alternate function
 * mode. The alternate function mode for each pin is controlled by setting each register
 * bit pertinent to the pin to be configured. For example, the alternate function mode for
 * Port A Pin 7 (PA7) is set by the values contained in registers PA_ADDR and PA_CTL[7].
 * A value of 02h in ADDR registers gives access to Alternate Function Register when CTL
 * register is referenced and setting bit 7 in that register will configure that bit in
 * alternate function mode.
 *
 * As an example to set Pin 1 of Port A into alternate function mode, write 02h in the ADDR to
 * access the Alternate Function Register and set bit 1. To acheive this, call this API by
 * specifying the bit corresponding to the pin by using the definitions given in the gpio.h
 * as shown below.
 * setmodeAltFunc_PortA( PORTPIN_ONE ) ;
 *
 * Similarly more than one pin can be set to alternate function mode by using ORing the pins
 * in the call to the API. For example, to set pin 5 and pin 7 of port A into alternate 
 * function mode the API can be used as shown below
 * setmodeAltFunc_PortA( PORTPIN_FIVE|PORTPIN_SEVEN ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeAltFunc_PortA( UCHAR pins )
{
#ifdef GPIOPARAMETER_CHECKING
	if( portamask & pins )
	{
		return GPIOERR_INVALIDPINS ;
	}
#endif /*! GPIOPARAMETER_CHECKING */

	PAADDR = PORTADDR_ALTFUNC ;		//!< Get access to Alternate Function register.
	SETBIT( PACTL, pins ) ;			//!< Set bits corresponding to pins in Alternate Function register.

#if defined(_Z8F04A_8PIN) || defined(__ZSLBUILD)
	PAADDR = PORTADDR_ALTFUNCSET1 ;
	RESETBIT( PACTL, pins ) ;
	PAADDR = PORTADDR_ALTFUNCSET2 ;
	RESETBIT( PACTL, pins ) ;
#endif

	PAADDR = PORTADDR_NOFUNC ;		//!< Protect control registers.


	return GPIOERR_SUCCESS ;

}//! end of setmodeAltFunc_PortA()


/*! End of File */


