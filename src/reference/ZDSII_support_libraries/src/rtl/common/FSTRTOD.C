/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FSTRTOD.C  built from template file STRTOD.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <math.h>

/*************************************************
*
* strtod - string to double conversion
*
* Inputs:
*	str - pointer to the character string
*	endptr - pointer to pointer to char to
*		 put address of first char past
*		 the end of the string -- or NULL
* Returns:
*	the value of the number
*
*************************************************/
#undef f_strtod
double f_strtod(__CONST__ char far * str, char far * * endptr)
{
  double val = 0.0;
  int frac = 0;
  int exp = 0;
  signed char sign = 1;
  signed char exp_sign = 1;
  double temp;

  while (isspace(*str)) ++str;

  if (*str == '-') {
    sign = -1;
    ++str;
  }
  else if (*str == '+')
    ++str;

  while (*str >= '0' && *str <= '9') {
    val = val * 10 + (*str - '0');
    ++str;
  }

  if (*str == '.') {
    ++str;
    while (*str >= '0' && *str <= '9') {
      val = val * 10 + (*str - '0');
      ++str;
      ++frac;
    }
  }

  if (*str == 'e' || *str == 'E') {
    ++str;
    if (*str == '-') {
      exp_sign = -1;
      ++str;
    }
    else if (*str == '+') {
      exp_sign = 1;
      ++str;
    }
    while (*str >= '0' && *str <= '9') {
     exp = exp * 10 + (*str - '0');
      ++str;
    }
  }

  if (endptr)
    *endptr = str;

  if (exp_sign < 0 )
    exp = -exp;
  exp -= frac;

  while (exp > 0)
  {
    if (val < DBL_MAX/10)
      val *= 10;
    else
    {
      val = HUGE_VAL;
      errno = ERANGE;
    }
    --exp;
  }
  while (exp < 0)
  {
    val *= .1;
    ++exp;
  }
  if (sign < 0 )
    val = -val;
  return val;
}

