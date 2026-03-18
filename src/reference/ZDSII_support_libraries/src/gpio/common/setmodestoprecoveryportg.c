/*!\file setmodestoprecoveryportg.c
 * \brief Implementation file for setting STOP Mode Recovery Source Enable
 *        mode for Port G bits.
 *
 *  This file contains implementation for setting Port G bit to STOP Mode
 *  Recovery mode required by GPIO driver implementations for Z8 Encore!
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
 * Port mask used for validating port pins. The definition of portgmask
 * can be found in zsldevinit.asm included in the project.
 */
extern UCHAR portgmask ;
#endif /*! GPIOPARAMETER_CHECKING */


/**
 * \ingroup GPIO
 */

/*!
 * @{
 * Set STOP Mode Recovery Source Enable mode for Port G.
 *
 * This API can be used to configure one or more pins of Port G to STOP Mode Recovery
 * mode. The STOP Mode Recovery mode for each pin is controlled by setting each register
 * bit pertinent to the pin to be configured. For example, the STOP recovery mode for
 * Port G Pin 7 (PG7) is set by the values contained in registers PG_ADDR and PG_CTL[7].
 * A value of 05h in ADDR registers gives access to STOP Mode Recovery Source Enable
 * Register when CTL register is referenced and setting bit 7 in that register will
 * configure that bit in STOP recovery mode.
 *
 * As an example to set Pin 1 of Port G into STOP recovery mode, write 05h in the ADDR to
 * access the STOP Recovery Source Enable Register and set bit 1. To acheive this, call
 * this API by specifying the bit corresponding to the pin by using the definitions given
 * in the gpio.h as shown below.
 * setmodeStopRecovery_PortG( PORTPIN_ONE ) ;
 *
 * Similarly more than one pin can be set to STOP recovery mode by using ORing the pins
 * in the call to the API. For example, to set pin 5 and pin 7 of port G into STOP
 * recovery mode the API can be used as shown below
 * setmodeStopRecovery_PortG( PORTPIN_FIVE|PORTPIN_SEVEN ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeStopRecovery_PortG( UCHAR pins )
{

#ifdef GPIOPARAMETER_CHECKING
	if( portgmask & pins )
	{
		return GPIOERR_INVALIDPINS ;
	}
#endif /*! GPIOPARAMETER_CHECKING */

	PGADDR = PORTADDR_DATADIR ;		//!< Get access to Data Direction register.
	SETBIT( PGCTL, pins ) ;			//!< Set bits corresponding to pins in Data Direction register.

	PGADDR = PORTADDR_STPMDREC ;	//!< Get access to STOP Mode Recovery Source Enable register.
	SETBIT( PGCTL, pins ) ;			//!< Set bits corresponding to pins in STOP Mode Recovery Source Enable register.
	PGADDR = PORTADDR_NOFUNC ;		//!< Protect control registers.


	return GPIOERR_SUCCESS ;

}//! end of setmodeStopRecovery_PortG()

/*! End of File */


