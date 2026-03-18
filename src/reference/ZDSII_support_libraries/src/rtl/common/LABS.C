/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

/*************************************************
*
* labs - long absolute value
*
* Inputs:
*	j	- value to calculate abs of
*
* Returns:
*	absloute value of j
*
*************************************************/
long labs(long j)
{
  if (j < 0)
    return(-j);
  else
    return(j);
}
