/*!\file setmodeinterruptmcporta.c
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
 * setmodeInterrupt_PortA( PORTPIN_ONE ) ;
 *
 * setmodeInterrupt_PortA( PORTPIN_FIVE|PORTPIN_SEVEN ) ;
 *
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeInterrupt_PortA( UCHAR pins, UCHAR edge, UCHAR priority )
{
	UCHAR mask = 0 ;
	UCHAR upperNib ;


	/*! Upper nibble. */
	upperNib = 0x0F&(pins >> (BYTE)4) ;

	/*! Determine port selection mask. */
	mask = mask | upperNib ;

	/*! First, set these bits for input mode */
	PAADDR = PORTADDR_DATADIR ;
	SETBIT( PACTL, pins ) ;

	/*! Select port bits. */
	PAADDR = PORTADDR_IRQPS ;
	SETBIT( PACTL, mask ) ;

	/*! Select interrupt trigger edge. */
	PAADDR = PORTADDR_IRQES ;
	if( edge == EDGE_FALLING )
	{
		RESETBIT( PACTL, mask|(pins&0x0F) ) ;
	}
	else
	{
		SETBIT( PACTL, mask|(pins&0x0F) ) ;
	}

	PAADDR = PORTADDR_NOFUNC ;

	DI() ;

	/*! Enable the interrupt with given priority */
	if( INTPRIORITY_HIGH == priority )
	{
		SETBIT( IRQ1ENH, mask|(pins&0x0F) ) ;
		SETBIT( IRQ1ENL, mask|(pins&0x0F) ) ;
	}
	else
	{
		RESETBIT( IRQ1ENH, mask|(pins&0x0F) ) ;
		RESETBIT( IRQ1ENL, mask|(pins&0x0F) ) ;
	}

	if( INTPRIORITY_LOW == priority )
	{
		SETBIT( IRQ1ENL, mask|(pins&0x0F) ) ;
	}

	else if( INTPRIORITY_NOMINAL == priority )
	{
		SETBIT( IRQ1ENH, mask|(pins&0x0F) ) ;
	}


	EI() ;
	

	return GPIOERR_SUCCESS ;

}//! end of setmodeInterrupt_PortA()


/*! End of File */


