/*!\file setmodealtfuncset3mcportb.c
 * \brief Implementation file for setting Alternate Function Set-3 mode for Port B bits.
 *
 *  This file contains implementation for setting Port B bit to Alternate Function
 *  Set-3 required by GPIO driver implementations for Z8 Encore! microcontrollers.
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
extern UCHAR portbmask ;
#endif /*! GPIOPARAMETER_CHECKING */

/**
 * \ingroup GPIO
 */

/*!
 * @{
 * Set Alternate Function Set-3 mode for Port B.
 *
 * This API can be used to configure one or more pins of Port B to alternate function set-3
 * mode. The alternate function set-3 mode for each pin is controlled by setting each register
 * bit pertinent to the pin to be configured. For example, the alternate function set-3 mode for
 * Port B Pin 7 (PB7) is set by the values contained in registers PB_ADDR and PB_CTL[7].
 * A value of 02h in ADDR registers gives access to Alternate Function Register when CTL
 * register is referenced and setting bit 7 in that register will configure that bit in
 * alternate function mode. Similarly the alternate function set-1 and set-2 registers are accessed.
 *
 * As an example to set Pin 1 of Port B into alternate function set-3 mode, call this API by
 * specifying the bit corresponding to the pin by using the definitions given in the gpio.h
 * as shown below.
 * setmodeAltFuncSet3_PortB( PORTPIN_ONE ) ;
 *
 * Similarly more than one pin can be set to alternate function set-3 mode by using ORing the pins
 * in the call to the API. For example, to set pin 5 and pin 7 of port A into alternate 
 * function set-3 mode the API can be used as shown below
 * setmodeAltFuncSet3_PortB( PORTPIN_FIVE|PORTPIN_SEVEN ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeAltFuncSet3_PortB( UCHAR pins )
{
#ifdef GPIOPARAMETER_CHECKING
	if( portbmask & pins )
	{
		return GPIOERR_INVALIDPINS ;
	}
#endif /*! GPIOPARAMETER_CHECKING */

	PBADDR = PORTADDR_ALTFUNC0 ;
	SETBIT( PBCTL, pins ) ;

	PBADDR = PORTADDR_ALTFUNC1 ;	//!< Get access to Alternate Function Set-1 register.
	RESETBIT( PBCTL, pins ) ;		//!< Reset bits corresponding to pins in Alternate Function Set-1 register.

	PBADDR = PORTADDR_NOFUNC ;		//!< Protect control registers.


	return GPIOERR_SUCCESS ;

}//! end of setmodeAltFuncSet3_PortB()


/*! End of File */


