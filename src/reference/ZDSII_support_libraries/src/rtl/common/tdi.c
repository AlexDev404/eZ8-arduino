/*************************************************
 *  Copyright (C) 2008 by  ZiLOG, Inc.
 *  All Rights Reserved
 *************************************************/

/*************************************************
*
* TDI - Test and Disable Interrupts
*
* Inputs:
*	IRQCTL (interrupt control) register
*
* Returns:
*	Non-zero if interrupts were enabled before the call
*
*************************************************/

#include <ez8.h>
#include <ZilogWarnings.h>

/*
 * Disable the "Not all paths return a value" warning; OK here
 */
#pragma warning disable NOT_ALL_PATHS_RET

unsigned char TDI(void)
{
#pragma asm
    ATM
    LDX r0, FCFH
    AND r0, #80H
    DI
#pragma endasm
}
