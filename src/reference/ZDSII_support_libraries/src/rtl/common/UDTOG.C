/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <stddef.h>
#include <format.h>


/*************************************************
*
* _u_dtog - convert a double float to ASCII in g format
*
* Inputs:
*	n - value to be converted
*	s - target char array
*	fmt - format structure with conversion info
*
* Returns:
*	next address past the end of the string
*
*************************************************/
PF_REENTRANT void _u_dtog(PRINT_FMT_ARG double n)
{
#ifdef __REENTRANT_PRINTFS__
#define __print_fmt (*print_fmt)
#define PRNT_FMT_ARG print_fmt,
#else
#define PRNT_FMT_ARG
#endif
  struct flt_info info;
  _u_flt_info(n, &info);

  if (__print_fmt.precision < 0)
    __print_fmt.precision = 0;

  if (__print_fmt.field_width < 0)
  {
    __print_fmt.flags |= FMT_FLAG_MINUS;
    __print_fmt.field_width = -__print_fmt.field_width;
  }

  if (!(__print_fmt.flags & FMT_FLAG_POUND))
    __print_fmt.flags |= FMT_FLAG_STRIP;

  // ISO Spec: The precision is the maximal number of significant digits
  //           if the precision is zero it is taken as one.
  if (!__print_fmt.precision)
    __print_fmt.precision=1;

  if (   info.exp < MINEXP
      || info.exp >= __print_fmt.precision)
  {
    --__print_fmt.precision;
    __print_fmt.type = 'e';
  }
  else
  {
    __print_fmt.precision -= (1 + info.exp);
    __print_fmt.type = 'f';
  }

  _u_dtof(PRNT_FMT_ARG n);
}
