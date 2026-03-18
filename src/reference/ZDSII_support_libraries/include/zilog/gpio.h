/*!\file gpio.h
 * \brief Definition file for the Z8 Encore! GPIO Ports.
 *
 *  This file contains header information required by GPIO Port
 *  driver implementations for Z8 Encore! microcontrollers.
 *
 *  This source file uses Doxygen-style comments to generate documentation
 *  automatically.
 *
 *  Copyright (C) 1999-2004 by  ZiLOG, Inc.
 *  All Rights Reserved.
 */

#pragma once // Include this file only once
#ifndef _GPIO_H_
#define _GPIO_H_

#include <defines.h>


#ifdef _DEBUG
#define GPIOPARAMETER_CHECKING									//!< Parameter validation control macro.
#endif


/*! The GPIO ports available for particular target. Port A, B and C are available for all targets */
#if (defined(EZ8_PORT4) && !defined(_Z8F04)) || defined(EZ8_PORT8)||defined(EZ8_PORT5)
#define PORTD
#endif

#if defined(EZ8_PORT8)||defined(EZ8_PORT5)
#define PORTE
#endif
#if defined(EZ8_PORT8)
#define PORTF
#define PORTG
#define PORTH
#endif

#define GPIOERR_SUCCESS		(CHAR)0			//!< Error code for success returned by GPIO APIs.
#define GPIOERR_INVALIDPINS	(CHAR)1			//!< Error code for invalid GPIO pin for the target.
#define GPIOERR_FAILURE		(CHAR)(-1)		//!< Error code for failure returned by GPIO APIs.


/*! all the ports bits are set to input mode */
#define PORTA_ADDRVAL_DEF   0x01
#define PORTA_CTLVAL_DEF    0xFF
#define PORTA_OUTVAL_DEF    0x00

#define PORTB_ADDRVAL_DEF   0x01
#define PORTB_CTLVAL_DEF    0xFF
#define PORTB_OUTVAL_DEF    0x00

#define PORTC_ADDRVAL_DEF   0x01
#define PORTC_CTLVAL_DEF    0xFF
#define PORTC_OUTVAL_DEF    0x00

#ifdef PORTD
#define PORTD_ADDRVAL_DEF   0x01
#define PORTD_CTLVAL_DEF    0xFF
#define PORTD_OUTVAL_DEF    0x00
#endif

#ifdef PORTE
#define PORTE_ADDRVAL_DEF   0x01
#define PORTE_CTLVAL_DEF    0xFF
#define PORTE_OUTVAL_DEF    0x00
#endif

#ifdef PORTF
#define PORTF_ADDRVAL_DEF   0x01
#define PORTF_CTLVAL_DEF    0xFF
#define PORTF_OUTVAL_DEF    0x00
#endif

#ifdef PORTG
#define PORTG_ADDRVAL_DEF   0x01
#define PORTG_CTLVAL_DEF    0xFF
#define PORTG_OUTVAL_DEF    0x00
#endif

#ifdef PORTH
#define PORTH_ADDRVAL_DEF   0x01
#define PORTH_CTLVAL_DEF    0xFF
#define PORTH_OUTVAL_DEF    0x00
#endif


/*! Control Register access codes used in Address registers */
#define PORTADDR_NOFUNC			0x00
#define PORTADDR_DATADIR		0x01
#define PORTADDR_ALTFUNC		0x02
#if defined(_Z8FMC16) || defined(__ZSLBUILD)
#define PORTADDR_ALTFUNC0		0x02
#endif
#define PORTADDR_OPENDRAIN		0x03
#define PORTADDR_HIGHDRIVE		0x04
#define PORTADDR_STPMDREC		0x05
#if defined (_Z8F1680)||defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F04A_8PIN) || defined(_Z8F04_8PIN) || defined(_Z8F08) || defined(_Z8F0823_8PIN) || defined(_Z8F08A) || defined(_Z8FMC16) || defined(__ZSLBUILD)
#define PORTADDR_PULLUP		0x06
#endif
#if defined (_Z8F1680)||defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F04A_8PIN) || defined(_Z8F04_8PIN) || defined(_Z8F0823_8PIN) || defined(_Z8F08A) || defined(__ZSLBUILD)
#define PORTADDR_ALTFUNCSET1	0x07
#define PORTADDR_ALTFUNCSET2	0x08
#endif
#if defined(_Z8FMC16) || defined(__ZSLBUILD)
#define PORTADDR_ALTFUNC1		0x07
#define PORTADDR_IRQES			0x08
#define PORTADDR_IRQPS			0x09
#endif


/*! Definitions for Current Drive Levels used in LED Drive Mode */
#if defined(_Z8F04A) ||defined (_Z8F1680)|| defined(__ZSLBUILD)
#define DRIVELEVEL_3MA			0
#define DRIVELEVEL_7MA			1
#define DRIVELEVEL_13MA			2
#define DRIVELEVEL_20MA			3
#endif

/*! Definitions for trigger edges */
#define EDGE_FALLING			0
#define EDGE_RISING				1

/*! GPIO pin patterns */
#define PORTPIN_ZERO		(BYTE)0x01			//!< The bit mask for Port bit 0.
#define PORTPIN_ONE			(BYTE)0x02			//!< The bit mask for Port bit 1.
#define PORTPIN_TWO			(BYTE)0x04			//!< The bit mask for Port bit 2.
#define PORTPIN_THREE		(BYTE)0x08			//!< The bit mask for Port bit 3.
#define PORTPIN_FOUR		(BYTE)0x10			//!< The bit mask for Port bit 4.
#define PORTPIN_FIVE 		(BYTE)0x20			//!< The bit mask for Port bit 5.
#define PORTPIN_SIX			(BYTE)0x40			//!< The bit mask for Port bit 6.
#define PORTPIN_SEVEN		(BYTE)0x80			//!< The bit mask for Port bit 7.
#define PORTPIN_FOURPINS_L	(BYTE)0x0F			//!< The bit mask for lower four Port bits.
#define PORTPIN_FOURPINS_U	(BYTE)0xF0			//!< The bit mask for upper four Port bits.
#define PORTPIN_PATTERN_AA	(BYTE)0xAA			//!< The bit mask for alternate bits (odd numbered pins).
#define PORTPIN_PATTERN_55	(BYTE)0x55			//!< The bit mask for alternate bits (even numbered pins).
#define PORTPIN_ALL			(BYTE)0xFF			//!< The bit mask for all Port bits.

/*! Port mask index used for validating the port pins */
#define MSKINDEX_PORTB		(BYTE)0
#define MSKINDEX_PORTC		(BYTE)1
#define MSKINDEX_PORTD		(BYTE)2
#define MSKINDEX_PORTE		(BYTE)3
#define MSKINDEX_PORTF		(BYTE)4
#define MSKINDEX_PORTG		(BYTE)5
#define MSKINDEX_PORTH		(BYTE)6

/*!
 * \brief The settings required to configure the GPIO Port.
 */
typedef struct
{
	BYTE addr ;					//!< The address register.
	BYTE ctl ;					//!< The control register.
	BYTE out ;					//!< The output register (write-only).
	BYTE in ;					//!< The input register (read-only).

} PORT ;



//! Macro definitions.

/*!
 * Resets all those bits in \a x as specified by the bit pattern in \a y.
 */
#define	RESETBIT( x, y )	( (x) &= (BYTE)(0xFF ^ (y)) )

/*!
 * Sets all those bits in \a x as specified by the bit pattern in \a y.
 */
#define SETBIT( x, y )		( (x) |= ((BYTE)(y)) )

/*!
 * Sets all those Port A pins as specified by the bit pattern in \a x.
 */
#define SETBITPA( x )			SETBIT( PAOUT, x )

/*!
 * Resets all those Port A pins as specified by the bit pattern in \a x.
 */
#define RESETBITPA( x )		RESETBIT( PAOUT, x )

/*!
 * Sets all those Port B pins as specified by the bit pattern in \a x.
 */
#define SETBITPB( x )			SETBIT( PBOUT, x )

/*!
 * Resets all those Port B pins as specified by the bit pattern in \a x.
 */
#define RESETBITPB( x )		RESETBIT( PBOUT, x )

/*!
 * Sets all those Port C pins as specified by the bit pattern in \a x.
 */
#define SETBITPC( x )			SETBIT( PCOUT, x )

/*!
 * Resets all those Port C pins as specified by the bit pattern in \a x.
 */
#define RESETBITPC( x )		RESETBIT( PCOUT, x )

#ifdef PORTD
/*!
 * Sets all those Port D pins as specified by the bit pattern in \a x.
 */
#define SETBITPD( x )			SETBIT( PDOUT, x )

/*!
 * Resets all those Port D pins as specified by the bit pattern in \a x.
 */
#define RESETBITPD( x )		RESETBIT( PDOUT, x )
#endif
#ifdef PORTE
/*!
 * Sets all those Port E pins as specified by the bit pattern in \a x.
 */
#define SETBITPE( x )			SETBIT( PEOUT, x )

/*!
 * Resets all those Port E pins as specified by the bit pattern in \a x.
 */
#define RESETBITPE( x )		RESETBIT( PEOUT, x )
#endif
#ifdef PORTF
/*!
 * Sets all those Port F pins as specified by the bit pattern in \a x.
 */
#define SETBITPF( x )			SETBIT( PFOUT, x )

/*!
 * Resets all those Port F pins as specified by the bit pattern in \a x.
 */
#define RESETBITPF( x )		RESETBIT( PFOUT, x )
#endif
#ifdef PORTG
/*!
 * Sets all those Port G pins as specified by the bit pattern in \a x.
 */
#define SETBITPG( x )			SETBIT( PGOUT, x )

/*!
 * Resets all those Port G pins as specified by the bit pattern in \a x.
 */
#define RESETBITPG( x )		RESETBIT( PGOUT, x )
#endif
#ifdef PORTH
/*!
 * Sets all those Port H pins as specified by the bit pattern in \a x.
 */
#define SETBITPH( x )			SETBIT( PHOUT, x )

/*!
 * Resets all those Port H pins as specified by the bit pattern in \a x.
 */
#define RESETBITPH( x )		RESETBIT( PHOUT, x )
#endif


/*!
 * \brief Initialize the Port A.
 */
VOID open_PortA( VOID ) ;

/*!
 * \brief Configure the Port A.
 */
VOID control_PortA( PORT *port ) ;

/*!
 * \brief Set Input mode for Port A bits.
 */
CHAR setmodeInput_PortA( UCHAR pins ) ;

/*!
 * \brief Set Output mode for Port A bits.
 */
CHAR setmodeOutput_PortA( UCHAR pins ) ;

/*!
 * \brief Set Open Drain mode for Port A bits.
 */
CHAR setmodeOpenDrain_PortA( UCHAR pins ) ;

/*!
 * \brief Set High Drive Enable mode for Port A bits.
 */
CHAR setmodeHighDrive_PortA( UCHAR pins ) ;

/*!
 * \brief Set STOP Mode Recovery Source Enable mode for Port A bits.
 */
CHAR setmodeStopRecovery_PortA( UCHAR pins ) ;

#if defined (_Z8F1680)||defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F04A_8PIN) || defined(_Z8F04_8PIN) || defined(_Z8F08) || defined(_Z8F0823_8PIN) || defined(_Z8F08A) || defined(_Z8FMC16)  || defined(__ZSLBUILD)
/*!
 * \brief Set Pull Up mode for Port A bits.
 */
CHAR setmodePullUp_PortA( UCHAR pins ) ;
#endif

/*!
 * \brief Set Alternate Function mode for Port A bits.
 */
CHAR setmodeAltFunc_PortA( UCHAR pins ) ;

#if defined(_Z8F04A_8PIN) || defined(_Z8F04_8PIN) || defined(_Z8F0823_8PIN) || defined(_Z8FMC16) || defined(__ZSLBUILD)
/*!
 * \brief Set Alternate Function Set-2 mode for Port A bits.
 */
CHAR setmodeAltFuncSet2_PortA( UCHAR pins ) ;

/*!
 * \brief Set Alternate Function Set-3 mode for Port A bits.
 */
CHAR setmodeAltFuncSet3_PortA( UCHAR pins ) ;

/*!
 * \brief Set Alternate Function Set-4 mode for Port A bits.
 */
CHAR setmodeAltFuncSet4_PortA( UCHAR pins ) ;
#endif

/*!
 * \brief Set Interrupt mode for Port A bits.
 */
#if defined(_Z8FMC16)
CHAR setmodeInterrupt_PortA( UCHAR pins, UCHAR edge, UCHAR priority ) ;
#endif

#if defined(_Z8F04A) || defined(_Z8F08A) || defined(__ZSLBUILD)
CHAR setmodeInterrupt_PortA_XP( UCHAR pins, UCHAR edge, UCHAR priority ) ;
#endif

#if defined(_Z8F04A_8PIN) || defined(_Z8F04_8PIN) || defined(_Z8F0823_8PIN) || defined(__ZSLBUILD)
CHAR setmodeInterrupt_PortA_8Pn( UCHAR pins, UCHAR edge, UCHAR priority ) ;
#endif

#if defined(_Z8F04) || defined(__ZSLBUILD)
CHAR setmodeInterrupt_PortA_4K( UCHAR pins, UCHAR edge, UCHAR priority ) ;
#endif

#if defined(_Z8F08) || defined(__ZSLBUILD)
CHAR setmodeInterrupt_PortA_F08( UCHAR pins, UCHAR edge, UCHAR priority ) ;
#endif

#if defined(_Z8ENCORE_F0823_SERIES) || defined(__ZSLBUILD)
CHAR setmodeInterrupt_PortA_F0823( UCHAR pins, UCHAR edge, UCHAR priority ) ;
#endif

#if defined(_Z8F640) || defined(_Z8F642) || defined(__ZSLBUILD)
CHAR setmodeInterrupt_PortA_F64( UCHAR pins, UCHAR edge, UCHAR priority ) ;
#endif

#if defined (_Z8F1680)|| defined(__ZSLBUILD)
CHAR setmodeInterrupt_PortA_F1680( UCHAR pins, UCHAR edge, UCHAR priority ) ;
#endif


/*!
 * \brief Close the Port A.
 */
VOID close_PortA( VOID ) ;




/*!
 * \brief Initialize the Port B.
 */
VOID open_PortB( VOID ) ;

/*!
 * \brief Configure the Port B.
 */
VOID control_PortB( PORT *port ) ;

/*!
 * \brief Set Input mode for Port B bits.
 */
CHAR setmodeInput_PortB( UCHAR pins ) ;

/*!
 * \brief Set Output mode for Port B bits.
 */
CHAR setmodeOutput_PortB( UCHAR pins ) ;

/*!
 * \brief Set Open Drain mode for Port B bits.
 */
CHAR setmodeOpenDrain_PortB( UCHAR pins ) ;

/*!
 * \brief Set High Drive Enable mode for Port B bits.
 */
CHAR setmodeHighDrive_PortB( UCHAR pins ) ;

/*!
 * \brief Set STOP Mode Recovery Source Enable mode for Port B bits.
 */
CHAR setmodeStopRecovery_PortB( UCHAR pins ) ;

#if defined(_Z8F1680)||defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F08) || defined(_Z8FMC16) || defined(_Z8F08A) || defined(__ZSLBUILD)
/*!
 * \brief Set Pull Up mode for Port B bits.
 */
CHAR setmodePullUp_PortB( UCHAR pins ) ;
#endif

#if defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F08A) || defined(__ZSLBUILD)
/*!
 * \brief Set Alternate Function Set-1 mode for Port B bits.
 */
CHAR setmodeAltFuncSet1_PortB( UCHAR pins ) ;

/*!
 * \brief Set Alternate Function Set-2 mode for Port B bits.
 */
CHAR setmodeAltFuncSet2_PortB( UCHAR pins ) ;
#endif

#if defined(_Z8FMC16)
/*!
 * \brief Set Alternate Function Set-2 mode for Port B bits.
 */
CHAR setmodeAltFuncSet2_PortB( UCHAR pins ) ;

/*!
 * \brief Set Alternate Function Set-3 mode for Port B bits.
 */
CHAR setmodeAltFuncSet3_PortB( UCHAR pins ) ;

/*!
 * \brief Set Alternate Function Set-4 mode for Port B bits.
 */
CHAR setmodeAltFuncSet4_PortB( UCHAR pins ) ;

/*!
 * \brief Set Interrupt mode for Port B bits.
 */
CHAR setmodeInterrupt_PortB( UCHAR pins, UCHAR priority ) ;
#endif

#if (!defined(_Z8F04A) && !defined(_Z8F04)) || defined(_Z8F08A) || defined(_Z8FMC16)|| defined(_Z8F1680) || defined(__ZSLBUILD)
/*!
 * \brief Set Alternate Function mode for Port B bits.
 */
CHAR setmodeAltFunc_PortB( UCHAR pins ) ;
#endif

/*!
 * \brief Close the Port B.
 */
VOID close_PortB( VOID ) ;



/*!
 * \brief Initialize the Port C.
 */
VOID open_PortC( VOID ) ;

/*!
 * \brief Configure the Port C.
 */
VOID control_PortC( PORT *port ) ;

/*!
 * \brief Set Input mode for Port C bits.
 */
CHAR setmodeInput_PortC( UCHAR pins ) ;

/*!
 * \brief Set Output mode for Port C bits.
 */
CHAR setmodeOutput_PortC( UCHAR pins ) ;

/*!
 * \brief Set Open Drain mode for Port C bits.
 */
CHAR setmodeOpenDrain_PortC( UCHAR pins ) ;

/*!
 * \brief Set High Drive Enable mode for Port C bits.
 */
CHAR setmodeHighDrive_PortC( UCHAR pins ) ;

/*!
 * \brief Set STOP Mode Recovery Source Enable mode for Port C bits.
 */
CHAR setmodeStopRecovery_PortC( UCHAR pins ) ;

#if defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F08) || defined(_Z8F08A) || defined(_Z8FMC16) ||defined (_Z8F1680)|| defined(__ZSLBUILD)
/*!
 * \brief Set Pull Up mode for Port C bits.
 */
CHAR setmodePullUp_PortC( UCHAR pins ) ;
#endif

#if defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F08A) || defined(__ZSLBUILD)
/*!
 * \brief Set Alternate Function Set-1 mode for Port C bits.
 */
CHAR setmodeAltFuncSet1_PortC( UCHAR pins ) ;

/*!
 * \brief Set Alternate Function Set-2 mode for Port C bits.
 */
CHAR setmodeAltFuncSet2_PortC( UCHAR pins ) ;

#if defined(_Z8F04A) || defined(_Z8F08A) || defined (_Z8F1680)||defined(__ZSLBUILD)
/*!
 * \brief Set LED Drive mode for Port C bits.
 */
CHAR setmodeLEDDrive_PortC( UCHAR pins, BYTE drivelevels ) ;
#endif
#endif

#if (!defined(_Z8F04) && !defined(_Z8F04A)) ||defined (_Z8F1680)|| defined(_Z8F08A) || defined(_Z8FMC16) || defined(__ZSLBUILD)
/*!
 * \brief Set Alternate Function mode for Port C bits.
 */
CHAR setmodeAltFunc_PortC( UCHAR pins ) ;
#endif

#if defined(_Z8FMC16)
/*!
 * \brief Set Alternate Function Set-3 mode for Port C bits.
 */
CHAR setmodeAltFuncSet3_PortC( UCHAR pins ) ;
#endif

/*!
 * \brief Set Interrupt mode for Port C bits.
 */
#if defined(_Z8FMC16)
CHAR setmodeInterrupt_PortC( UCHAR pins, UCHAR edge, UCHAR priority ) ;
#else
CHAR setmodeInterrupt_PortC( UCHAR pins, UCHAR priority ) ;
#endif

/*!
 * \brief Close the Port C.
 */
VOID close_PortC( VOID ) ;




#ifdef PORTD
/*!
 * \brief Initialize the Port D.
 */
VOID open_PortD( VOID ) ;

/*!
 * \brief Configure the Port D.
 */
VOID control_PortD( PORT *port ) ;

/*!
 * \brief Set Input mode for Port D bits.
 */
CHAR setmodeInput_PortD( UCHAR pins ) ;

/*!
 * \brief Set Output mode for Port D bits.
 */
CHAR setmodeOutput_PortD( UCHAR pins ) ;

/*!
 * \brief Set Open Drain mode for Port D bits.
 */
CHAR setmodeOpenDrain_PortD( UCHAR pins ) ;

/*!
 * \brief Set High Drive Enable mode for Port D bits.
 */
CHAR setmodeHighDrive_PortD( UCHAR pins ) ;

/*!
 * \brief Set STOP Mode Recovery Source Enable mode for Port D bits.
 */
CHAR setmodeStopRecovery_PortD( UCHAR pins ) ;

#if defined(_Z8F04) || defined(_Z8F04A) || defined(_Z8F08A) || defined (_Z8F1680)||defined(__ZSLBUILD)
/*!
 * \brief Set Pull Up mode for Port D bits.
 */
CHAR setmodePullUp_PortD( UCHAR pins ) ;
#endif

#if defined(_Z8F640) || defined(_Z8F642)||defined(_Z8F1680) || defined(__ZSLBUILD)
/*!
 * \brief Set Alternate Function mode for Port D bits.
 */
CHAR setmodeAltFunc_PortD( UCHAR pins ) ;
#endif

/*!
 * \brief Set Interrupt mode for Port D bits.
 */
#if  defined(_Z8F640) || defined(_Z8F642) || defined(__ZSLBUILD)
CHAR setmodeInterrupt_PortD_F64( UCHAR pins, UCHAR edge, UCHAR priority ) ;
#endif
#if defined (_Z8F1680)|| defined(__ZSLBUILD)
CHAR setmodeInterrupt_PortD_F1680( UCHAR pins, UCHAR edge, UCHAR priority ) ;
#endif

/*!
 * \brief Close the Port D.
 */
VOID close_PortD( VOID ) ;
#endif



#ifdef PORTE
/*!
 * \brief Initialize the Port E.
 */
VOID open_PortE( VOID ) ;

/*!
 * \brief Configure the Port E.
 */
VOID control_PortE( PORT *port ) ;

/*!
 * \brief Set Input mode for Port E bits.
 */
CHAR setmodeInput_PortE( UCHAR pins ) ;

/*!
 * \brief Set Output mode for Port E bits.
 */
CHAR setmodeOutput_PortE( UCHAR pins ) ;

/*!
 * \brief Set Open Drain mode for Port E bits.
 */
CHAR setmodeOpenDrain_PortE( UCHAR pins ) ;

/*!
 * \brief Set High Drive Enable mode for Port E bits.
 */
CHAR setmodeHighDrive_PortE( UCHAR pins ) ;

/*!
 * \brief Set STOP Mode Recovery Source Enable mode for Port E bits.
 */
CHAR setmodeStopRecovery_PortE( UCHAR pins ) ;

/*!
 * \brief Close the Port E.
 */
VOID close_PortE( VOID ) ;

/*!
 * \brief Set Pull Up mode for Port E bits.
 */
CHAR setmodePullUp_PortE( UCHAR pins );
/*!
 * \brief Set Alternate Function mode for Port D bits.
 */
CHAR setmodeAltFunc_PortE( UCHAR pins );
#endif




#ifdef PORTF
/*!
 * \brief Initialize the Port F.
 */
VOID open_PortF( VOID ) ;

/*!
 * \brief Configure the Port F.
 */
VOID control_PortF( PORT *port ) ;

/*!
 * \brief Set Input mode for Port F bits.
 */
CHAR setmodeInput_PortF( UCHAR pins ) ;

/*!
 * \brief Set Output mode for Port F bits.
 */
CHAR setmodeOutput_PortF( UCHAR pins ) ;

/*!
 * \brief Set Open Drain mode for Port F bits.
 */
CHAR setmodeOpenDrain_PortF( UCHAR pins ) ;

/*!
 * \brief Set High Drive Enable mode for Port F bits.
 */
CHAR setmodeHighDrive_PortF( UCHAR pins ) ;

/*!
 * \brief Set STOP Mode Recovery Source Enable mode for Port F bits.
 */
CHAR setmodeStopRecovery_PortF( UCHAR pins ) ;

/*!
 * \brief Close the Port F.
 */
VOID close_PortF( VOID ) ;
#endif



#ifdef PORTG
/*!
 * \brief Initialize the Port G.
 */
VOID open_PortG( VOID ) ;

/*!
 * \brief Configure the Port G.
 */
VOID control_PortG( PORT *port ) ;

/*!
 * \brief Set Input mode for Port G bits.
 */
CHAR setmodeInput_PortG( UCHAR pins ) ;

/*!
 * \brief Set Output mode for Port G bits.
 */
CHAR setmodeOutput_PortG( UCHAR pins ) ;

/*!
 * \brief Set Open Drain mode for Port G bits.
 */
CHAR setmodeOpenDrain_PortG( UCHAR pins ) ;

/*!
 * \brief Set High Drive Enable mode for Port G bits.
 */
CHAR setmodeHighDrive_PortG( UCHAR pins ) ;

/*!
 * \brief Set STOP Mode Recovery Source Enable mode for Port G bits.
 */
CHAR setmodeStopRecovery_PortG( UCHAR pins ) ;

/*!
 * \brief Close the Port G.
 */
VOID close_PortG( VOID ) ;
#endif



#ifdef PORTH
/*!
 * \brief Initialize the Port H.
 */
VOID open_PortH( VOID ) ;

/*!
 * \brief Configure the Port H.
 */
VOID control_PortH( PORT *port ) ;

/*!
 * \brief Set Input mode for Port H bits.
 */
CHAR setmodeInput_PortH( UCHAR pins ) ;

/*!
 * \brief Set Output mode for Port H bits.
 */
CHAR setmodeOutput_PortH( UCHAR pins ) ;

/*!
 * \brief Set Open Drain mode for Port H bits.
 */
CHAR setmodeOpenDrain_PortH( UCHAR pins ) ;

/*!
 * \brief Set High Drive Enable mode for Port H bits.
 */
CHAR setmodeHighDrive_PortH( UCHAR pins ) ;

/*!
 * \brief Set STOP Mode Recovery Source Enable mode for Port H bits.
 */
CHAR setmodeStopRecovery_PortH( UCHAR pins ) ;

/*!
 * \brief Set Alternate Function mode for Port H bits.
 */
CHAR setmodeAltFunc_PortH( UCHAR pins ) ;

/*!
 * \brief Close the Port H.
 */
VOID close_PortH( VOID ) ;
#endif



#endif /*! _GPIO_H_ */


