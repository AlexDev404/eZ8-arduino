/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NMODF.C  built from template file MODF.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <math.h>

/*************************************************
*
* modf - break a double into and integral part and
*	 a fractional part
*
* Inputs:
*	value	- the double to break up
*	dptr	- a pointer to the place to put
*		  the integral part
*
* Returns:
*	The fractional part
*
*************************************************/
#undef n_modf
double n_modf(double val,double near * dptr)
{
  static int exp;
  int i;
  double frac,intgrl,d;
  unsigned int exp_sign;

	/* frexp returns a normalized number so we know	  */
	/* that it is in the range [0.0 to 1.9...]	  */

  if (val < 0) {
    val = -val;
    exp_sign = 1;
  }
  else
    exp_sign = 0;

  d = frexp(val,&exp);
  intgrl = (int)d;	/* [0 - 1] */
  frac = d - intgrl;	/* [0.0 - 0.9...] */
  if (exp > 0) {
    for(;exp > 0;--exp) {
      intgrl *= 2.0;
      frac *= 2.0;
      i = (int)frac;	/* either 0 or 1 */
      intgrl += i;
      frac -= i;
    }
  }
  else if (exp < 0) {
    for(;exp < 0;++exp) {
      intgrl /= 2.0;	/* always 0 or 0.5 */
      frac = frac / 2.0 + intgrl;
    }
  }

  if (exp_sign) {
    intgrl = -intgrl;
    frac = -frac;
  }

  *dptr = intgrl;

  return(frac);
}

