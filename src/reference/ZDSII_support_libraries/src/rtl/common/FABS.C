/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

/*************************************************
*
* fabs - absolute value
*
* Inputs:
*	j	- value to calculate abs of
*
* Returns:
*	absloute value of j
*
*************************************************/
double fabs(double j)
{
  return(j >= 0.0 ? j : -j);
}
