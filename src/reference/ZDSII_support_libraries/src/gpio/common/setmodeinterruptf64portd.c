/*!\file setmodeinterruptf64portd.c
 * \brief Implementation file for setting Interrupt mode for Port D bits.
 *
 *  This file contains implementation for setting Port D bit to Interrupt mode
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
 * Port mask used for validating port pins. The definition of portdmask
 * can be found in zsldevinit.asm included in the project.
 */
extern UCHAR portdmask ;
#endif /*! GPIOPARAMETER_CHECKING */

/**
 * \ingroup GPIO
 */

/*!
 * @{
 * Set Interrupt mode for Port D.
 *
 *
 * setmodeInterrupt_PortD_F64( PORTPIN_ONE ) ;
 *
 * setmodeInterrupt_PortD_F64( PORTPIN_FIVE|PORTPIN_SEVEN ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeInterrupt_PortD_F64( UCHAR pins, UCHAR edge, UCHAR priority )
{

#ifdef GPIOPARAMETER_CHECKING
	if( portdmask & pins )
	{
		return GPIOERR_INVALIDPINS ;
	}
#endif /*! GPIOPARAMETER_CHECKING */

	/*! First, set these bits for input mode */
	PDADDR = PORTADDR_DATADIR ;
	SETBIT( PDCTL, pins ) ;
	PDADDR = PORTADDR_NOFUNC ;

	DI() ;

	/*! Enable the interrupt with given priority */
	if( INTPRIORITY_HIGH == priority )
	{
		SETBIT( IRQ1ENH, pins ) ;
		SETBIT( IRQ1ENL, pins ) ;
	}
	else
	{
		RESETBIT( IRQ1ENH, pins ) ;
		RESETBIT( IRQ1ENL, pins ) ;
	}

	if( INTPRIORITY_LOW == priority )
	{
		SETBIT( IRQ1ENL, pins ) ;
	}

	else if( INTPRIORITY_NOMINAL == priority )
	{
		SETBIT( IRQ1ENH, pins ) ;
	}

	/*! Program the triggering edge */
	if( edge == EDGE_FALLING )
	{
		RESETBIT( IRQES, pins ) ;
	}
	else
	{
		SETBIT( IRQES, pins ) ;
	}

	/*! Set the GPIO pins for shared pins */
	SETBIT( IRQPS, pins ) ;

	EI() ;


	

	return GPIOERR_SUCCESS ;

}//! end of setmodeInterrupt_PortD_F64()


/*! End of File */


