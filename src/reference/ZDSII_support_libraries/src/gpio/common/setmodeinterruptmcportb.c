/*!\file setmodeinterruptmcportb.c
 * \brief Implementation file for setting Interrupt mode for Port B bits.
 *
 *  This file contains implementation for setting Port B bit to Interrupt mode
 *  required by GPIO driver implementations for Z8 Encore! microcontrollers. Only
 *  lower four pins of Port B are supported.
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
 * Set Interrupt mode for Port B.
 *
 *
 * setmodeInterrupt_PortB( PORTPIN_ONE ) ;
 *
 * setmodeInterrupt_PortB( PORTPIN_TWO|PORTPIN_THREE ) ;
 *
 * Interrupt mode of operation is supported only for lower four
 * pins of Port B.
 * Note that the API does not alter the states of other pins.
 *
 * Return Values : 
 *                 None.
 *
 * @}
 */
CHAR setmodeInterrupt_PortB( UCHAR pins, UCHAR priority )
{

	/*! First, set these bits for input mode */
	PBADDR = PORTADDR_DATADIR ;
	SETBIT( PBCTL, pins ) ;

	/*! 
	 * Alternate function set 2 is nothing but interrupt mode.
	 * Interrupt mode of operation is supported only for lower
	 * four pins of Port B.
	 */
	setmodeAltFuncSet2_PortB( pins&0x0F ) ;

	DI() ;

	/*! Enable the interrupt with given priority */
	if( INTPRIORITY_HIGH == priority )
	{
		SETBIT( IRQ1ENH, (BYTE)0x10 ) ;
		SETBIT( IRQ1ENL, (BYTE)0x10 ) ;
	}
	else
	{
		RESETBIT( IRQ1ENH, (BYTE)0x10 ) ;
		RESETBIT( IRQ1ENL, (BYTE)0x10 ) ;
	}

	if( INTPRIORITY_LOW == priority )
	{
		SETBIT( IRQ1ENL, (BYTE)0x10 ) ;
	}

	else if( INTPRIORITY_NOMINAL == priority )
	{
		SETBIT( IRQ1ENH, (BYTE)0x10 ) ;
	}


	EI() ;
	

	return GPIOERR_SUCCESS ;

}//! end of setmodeInterrupt_PortB()


/*! End of File */


