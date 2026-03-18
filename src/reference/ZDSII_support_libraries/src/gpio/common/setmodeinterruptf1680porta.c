/*!\file setmodeinterruptf1680porta.c
 * \brief Implementation file for setting Interrupt mode for Port A bits.
 *
 *  This file contains implementation for setting Port A bit to Interrupt mode
 *  required by GPIO driver implementations for Z8 Encore! microcontrollers.
 *
 *  This source file uses Doxygen-style comments to generate documentation
 *  automatically.
 *
 *  Copyright (C) 1999-2004 by  ZiLOG, Inc.
 *  All Rights Reserved.
 */

#include <ez8.h>


/**
 * \ingroup GPIO
 */

/*!
 * @{
 * Set Interrupt mode for Port A.
 *
 *
 * setmodeInterrupt_PortA_F1680( PORTPIN_ONE ) ;
 *
 * setmodeInterrupt_PortA_F1680( PORTPIN_FIVE|PORTPIN_SEVEN ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeInterrupt_PortA_F1680( UCHAR pins, UCHAR edge, UCHAR priority )
{


	/*! First, set these bits for input mode */
	PAADDR = PORTADDR_DATADIR ;
	SETBIT( PACTL, pins ) ;
	PAADDR = PORTADDR_NOFUNC ;

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
	RESETBIT( IRQPS, pins ) ;

	EI() ;
	

	return GPIOERR_SUCCESS ;

}//! end of setmodeInterrupt_PortA_F1680()


/*! End of File */


