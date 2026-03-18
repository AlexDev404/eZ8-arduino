/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

/*************************************************
*
* abs - int absolute value
*
* Inputs:
*	j	- value to calculate abs of
*
* Returns:
*	absolute value of j
*
*************************************************/
int abs(int j)
{
  return ((j < 0) ? -j : j);
}
