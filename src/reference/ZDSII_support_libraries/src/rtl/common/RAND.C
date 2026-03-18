/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

unsigned long _next = 1;

/*************************************************
*
* rand - get a random number
*
* Inputs:
*	none
*
* Returns:
*	 a random number
*
*************************************************/
int rand(void)
{
  _next = _next * 1103515245 + 12345;
  return((unsigned long)(_next/65536) % 32768);
}

