/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FSTRTOUL.C  built from template file STRTOUL.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>
#include <ctype.h>
#include <errno.h>

/*************************************************
*
* strtol - string to long conversion
*
* Inputs:
*	cp - pointer to the character string
*	endptr - place to put ptr to first invalid character
*	base - radix
*
* Returns:
*	the value of the number
*
*************************************************/
#undef f_strtoul
unsigned long f_strtoul(__CONST__ char far * cp, char far * * endptr, int base)
{
  register unsigned long sum,psum;
  register int sign;
  register int radix = base;
  register int ovf = 0;
  register int digit;

  while (isspace(*cp))
    ++cp;

  sign = 0;
  if ( *cp == '-' ) {
    sign = 1;
    ++cp;
  }
  else if ( *cp == '+' )
    ++cp;

  if (base == 0) {
    if (*cp == '0')
      if (cp[1] == 'x' || cp[1] == 'X')
	radix = 16;
      else
	radix = 8;
    else
      radix = 10;
  }

  if (base == 16 && *cp == '0' && (cp[1] == 'x' || cp[1] == 'X'))
    cp += 2;

  sum = 0;
  for (;;) {
    digit = toupper(*(cp++));
    if (digit >= 'A')
      digit = (digit - 'A') + 10;
    else
      digit -= '0';
    if (digit < 0 || digit >= radix)
      break;
    psum = sum;
    sum = sum * radix + digit;
    if (sum < psum) {	/* overflow */
      ovf = 1;
      break;
    }
  }

  if (endptr) {
    --cp;
    if (base == 0) {
      while (*cp == 'h' || *cp == 'u' || *cp == 'l' || *cp == 'L')
	++cp;
    }
    *endptr = cp;
  }

  if (ovf)
  {
    errno = ERANGE;
    return ULONG_MAX;
  }

  return(sign ? -sum : sum);
}

