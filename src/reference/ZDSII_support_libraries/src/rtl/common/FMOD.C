/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <math.h>

/*************************************************
*
* fmod - modulo
*
* Inputs:
*	x	- dividend
*	y	- divisor
*
* Returns:
*	x mod y
*
*************************************************/
double fmod(double x,double y)
{
  double z;
  double result;

  if (y == 0.0)
    return(0.0);
  modf(x/y,&z);
  result = x - z*y;
  if ((x < 0) && (result > 0))
    result = -result;
  return(result);
}
