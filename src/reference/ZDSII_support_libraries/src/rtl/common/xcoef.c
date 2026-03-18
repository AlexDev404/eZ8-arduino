/*************************************************
 *  Copyright (C) 2006-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

/*************************************************************************
 * expand coefficients
 *
 * Given the array of coefficients in coeff[], computes the expansion:
 *
 *	value = ((coeff[0] * x + coeff[1]) * x + coeff[2]) ... + coeff[n-2]
 *
 * The final value in the array (coeff[n-1]) must be equal to 0.0.
 *************************************************************************/
double expand_coef(rom double *coeff, double x)
{
  double value = 0.0;
  register double c;
  while (c = *coeff++)
  {
    value *= x;
    value += c;
  }
  return value;
}

