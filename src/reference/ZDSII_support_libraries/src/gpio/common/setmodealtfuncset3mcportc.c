/*!\file setmodealtfuncset3mcportc.c
 * \brief Implementation file for setting Alternate Function Set-3 mode for Port C bits.
 *
 *  This file contains implementation for setting Port C bit to Alternate Function
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
extern UCHAR portcmask ;
#endif /*! GPIOPARAMETER_CHECKING */

/**
 * \ingroup GPIO
 */

/*!
 * @{
 * Set Alternate Function Set-3 mode for Port C.
 *
 * This API can be used to configure one or more pins of Port C to alternate function set-3
 * mode. The alternate function set-3 mode for each pin is controlled by setting each register
 * bit pertinent to the pin to be configured. For example, the alternate function set-3 mode for
 * Port C Pin 7 (PC7) is set by the values contained in registers PC_ADDR and PC_CTL[7].
 * A value of 02h in ADDR registers gives access to Alternate Function Register when CTL
 * register is referenced and setting bit 7 in that register will configure that bit in
 * alternate function mode. Similarly the alternate function set-1 and set-2 registers are accessed.
 *
 * As an example to set Pin 0 of Port C into alternate function set-3 mode, call this API by
 * specifying the bit corresponding to the pin by using the definitions given in the gpio.h
 * as shown below.
 * setmodeAltFuncSet3_PortC( PORTPIN_ZERO ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeAltFuncSet3_PortC( UCHAR pins )
{
#ifdef GPIOPARAMETER_CHECKING
	if( portcmask & pins )
	{
		return GPIOERR_INVALIDPINS ;
	}
#endif /*! GPIOPARAMETER_CHECKING */

	PCADDR = PORTADDR_ALTFUNC0 ;		//!< Get access to Alternate Function 0 register.
	SETBIT( PCCTL, pins ) ;				//!< Set bits corresponding to pins in Alternate Function 0 register.
	PCADDR = PORTADDR_ALTFUNC1 ;		//!< Get access to Alternate Function 1 register.
	RESETBIT( PCCTL, pins ) ;			//!< Reset bits corresponding to pins in Alternate Function 1 register.

	PCADDR = PORTADDR_NOFUNC ;			//!< Protect control registers.


	return GPIOERR_SUCCESS ;

}//! end of setmodeAltFuncSet3_PortC()


/*! End of File */


