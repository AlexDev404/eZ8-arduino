/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

/*************************************************
*
* sabs - absolute value of short int
*
* Inputs:
*	j	- value to calculate abs of
*
* Returns:
*	absloute value of j
*
*************************************************/
short int sabs(short int j)
{
  return(j < 0 ? -j : j);
}
