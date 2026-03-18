/*!\file setmodeoutputportc.c
 * \brief Implementation file for setting output mode for Port C bits.
 *
 *  This file contains implementation for setting Port C bit to output mode
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
 * Set Output Mode for Port C.
 *
 * This API can be used to configure one or more pins of Port C to output mode. The
 * output mode for each pin is controlled by setting each register bit pertinent to
 * the pin to be configured. For example, the output mode for Port C Pin 7 (PC7) is
 * set by the values contained in registers PC_ADDR and PC_CTL[7]. A value of 01h
 * in ADDR registers gives access to Data Direction Register when CTL register is
 * referenced and resetting bit 7 in that register will configure that bit in output
 * mode.
 *
 * As an example to set Pin 1 of Port C into output mode, write 01h in the ADDR to
 * access the Data Direction Register and reset bit 1. To acheive this, call this API
 * by specifying the bit corresponding to the pin by using the definitions given in
 * the gpio.h as shown below.
 * setmodeOutput_PortC( PORTPIN_ONE ) ;
 *
 * Similarly more than one pin can be set to output mode by using ORing the pins in the
 * call to the API. Eg., to set pin 5 and pin 7 of port C into output mode the API
 * can be used as shown below
 * setmodeOutput_PortC( PORTPIN_FIVE|PORTPIN_SEVEN ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeOutput_PortC( UCHAR pins )
{

#ifdef GPIOPARAMETER_CHECKING
	if( portcmask & pins )
	{
		return GPIOERR_INVALIDPINS ;
	}
#endif /*! GPIOPARAMETER_CHECKING */

	PCADDR = PORTADDR_DATADIR ;		//!< Get access to Data Direction register.
	RESETBIT( PCCTL, pins ) ;		//!< Reset bits corresponding to pins in Data Direction register.
	PCADDR = PORTADDR_NOFUNC ;		//!< Protect control registers.


	return GPIOERR_SUCCESS ;

}//! end of setmodeOutput_PortC()


/*! End of File */


