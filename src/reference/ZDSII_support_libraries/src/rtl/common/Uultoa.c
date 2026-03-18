/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <stddef.h>
#include <format.h>


/*************************************************
*
* _u_ultoa - convert an unsigned long to a number
*	    of base rad
*
* Inputs:
*	ulg - unsigned long to be converted
*	str - target char array
*	rad - radix
*	fmt - format structure with conversion info
*
* Returns:
*	next address past the end of the string
*
*************************************************/
PF_REENTRANT void _u_ultoa(PRINT_FMT_ARG unsigned long n)
{
  unsigned char a;
  unsigned char t;
  char print_buff[MAXDIGITS+3];
  char * s = print_buff;
  unsigned char nz = (n != 0);
  unsigned char rad;

  if (__print_fmt.precision < 0)
    __print_fmt.precision = 1;
 
  if (__print_fmt.field_width < 0)
  {
    __print_fmt.flags |= FMT_FLAG_MINUS;
    __print_fmt.field_width = -__print_fmt.field_width;
  }
 
  a = 'A';
  switch (__print_fmt.type)
  {
  default:
  case 'd':
  case 'i':
  case 'u':
    rad = 10;
    break;
  case 'o':
    rad = 8;
    break;
  case 'x':
  case 'p':
    if ( !(__print_fmt.flags&FMT_FLAG_UPPERCASE))
      a = 'a';
    // Fall into next case
  case 'X':
  case 'P':
    rad = 16;
    break;
  }

  do
    {	/* generate digits in reverse order */
    t = n % rad;
    if (t > 9)
      *(s++) = (t - 10) + a;
    else
      *(s++) = t + '0';
    }  while (n /= rad);

  while (s - print_buff < (unsigned char) __print_fmt.precision) {
    *(s++) = '0';
  }
  if (__print_fmt.flags & FMT_FLAG_POUND) {
    if (nz) {
      if (rad == 16) {
	*(s++) = ('X'-'A')+a;
	*(s++) = '0';
      }
      else if (rad == 8) {
	*(s++) = '0';
      }
    }
  }

  // ISO Spec:  If a precision is specified  the zero flag is ignored
  if (__print_fmt.precision )
    __print_fmt.flags &= ~FMT_FLAG_PAD_ZERO;

  *s = '\0';

  _u_reverse(print_buff);
  __print_send(PRNT_FMT_ARG print_buff);
}
