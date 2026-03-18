/*!\file setmodeinterruptmcportc.c
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
CHAR setmodeInterrupt_PortC( UCHAR pins, UCHAR edge, UCHAR priority )
{
	/*! Validate pins because only PC0 pin is supported */
#ifdef GPIOPARAMETER_CHECKING
	if( 0xFE & pins )
	{
		return GPIOERR_INVALIDPINS ;
	}	
#endif /*! GPIOPARAMETER_CHECKING */
	
	/*! First, set these bits for input mode */
	PCADDR = PORTADDR_DATADIR ;
	SETBIT( PCCTL, pins ) ;

	/*! Select interrupt trigger edge. */
	PCADDR = PORTADDR_IRQES ;
	if( EDGE_FALLING == edge )
	{
		RESETBIT( PCCTL, 0x01 ) ;
	}
	else
	{
		SETBIT( PACTL, 0x01 ) ;
	}

	PCADDR = PORTADDR_NOFUNC ;

	DI() ;

	/*! Enable the interrupt with given priority */
	if( INTPRIORITY_HIGH == priority )
	{
		SETBIT( IRQ1ENH, 0x01 ) ;
		SETBIT( IRQ1ENL, 0x01 ) ;
	}
	else
	{
		RESETBIT( IRQ1ENH, 0x01 ) ;
		RESETBIT( IRQ1ENL, 0x01 ) ;
	}

	if( INTPRIORITY_LOW == priority )
	{
		SETBIT( IRQ1ENL, 0x01 ) ;
	}

	else if( INTPRIORITY_NOMINAL == priority )
	{
		SETBIT( IRQ1ENH, 0x01 ) ;
	}

	EI() ;


	return GPIOERR_SUCCESS ;

}//! end of setmodeInterrupt_PortC()


/*! End of File */


