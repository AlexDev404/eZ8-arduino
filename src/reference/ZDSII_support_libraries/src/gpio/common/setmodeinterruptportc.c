/*!\file setmodeinterruptportc.c
 * \brief Implementation file for setting Interrupt mode for Port C bits.
 *
 *  This file contains implementation for setting Port C bit to Interrupt mode
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
 * Set Interrupt mode for Port C.
 *
 *
 * setmodeInterrupt_PortC( PORTPIN_ONE ) ;
 *
 * setmodeInterrupt_PortC( PORTPIN_FIVE|PORTPIN_SEVEN ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeInterrupt_PortC( UCHAR pins, UCHAR priority )
{
#ifdef GPIOPARAMETER_CHECKING
	if( portcmask & pins )
	{
		return GPIOERR_INVALIDPINS ;
	}
#endif /*! GPIOPARAMETER_CHECKING */


	/*! First, set these bits for input mode */
	PCADDR = PORTADDR_DATADIR ;
	SETBIT( PCCTL, pins ) ;
	PCADDR = PORTADDR_NOFUNC ;

	/*! Validate pins because only lower 4 pins support interrupt mode */
#ifdef GPIOPARAMETER_CHECKING
	if( PORTPIN_FOURPINS_U & pins )
	{
		return GPIOERR_INVALIDPINS ;
	}	
#endif /*! GPIOPARAMETER_CHECKING */

	DI() ;

	/*! Enable the interrupt with given priority */
	if( INTPRIORITY_HIGH == priority )
	{
		SETBIT( IRQ2ENH, pins ) ;
		SETBIT( IRQ2ENL, pins ) ;
	}
	else
	{
		RESETBIT( IRQ2ENH, pins ) ;
		RESETBIT( IRQ2ENL, pins ) ;
	}

	if( INTPRIORITY_LOW == priority )
	{
		SETBIT( IRQ2ENL, pins ) ;
	}

	else if( INTPRIORITY_NOMINAL == priority )
	{
		SETBIT( IRQ2ENH, pins ) ;
	}

	EI() ;


	return GPIOERR_SUCCESS ;

}//! end of setmodeInterrupt_PortC()


/*! End of File */


