/*************************************************
 *  Copyright (C) 2008 by  ZiLOG, Inc.
 *  All Rights Reserved
 *************************************************/

/*************************************************
*
* RI - Restore Interrupts
*
* Inputs:
*	none
*
* Returns:
*	none
*
*************************************************/

#include <ez8.h>

void RI(unsigned char istat)
{
  asm("\tATM");
  IRQCTL |= istat;
}
