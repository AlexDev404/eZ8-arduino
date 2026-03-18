/*************************************************
*  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/
#include <format.h>
#include <string.h>
#include <stdlib.h>

/* Send the contents of string s to the printf/sprintf destination and */
/* update the count of characters output                                   */
/* The compiler may generate direct calls to this to bypass the runtime    */
/* parsing of printf formats.                                              */

PF_REENTRANT void __print_send(PRINT_FMT_ARG char* s)
{
  int i;
  int i0=0;
  char padch = ' ';
  char * p1;
  char padRight = ((__print_fmt.flags & FMT_FLAG_MINUS) || __print_fmt.field_width < 0);

  /*   Output any initial +, -, or space.  This needs to come before any     */
  /*   zeros inserted for padding.                                           */
  if (__print_fmt.print_leading_char)
  {
    __print_putch(PRNT_FMT_ARG __print_fmt.print_leading_char);
    __print_fmt.print_leading_char = '\0';
    i0=1;
  }

        /* look at flag and field width */
        /* and do proper padding.       */

  if (__print_fmt.field_width != 0) {
    padch = ' ';
    if (!padRight)
    {
      if (__print_fmt.flags & FMT_FLAG_PAD_ZERO)
        padch = '0';
      i=abs(__print_fmt.field_width)-strlen(s)-i0;
      for (;i > 0;--i)
      {
        __print_putch(PRNT_FMT_ARG padch);
      }
    }
  }

  for (p1=s;*p1;++p1)
    __print_putch(PRNT_FMT_ARG *p1);
    if (padRight)
    {
      i=abs(__print_fmt.field_width)-(p1-s);
      for (;i > 0;--i)
        __print_putch(PRNT_FMT_ARG padch);
    }
    /*  Reset the data manipulated by the compiler, so that no code is needed */
    /*  to set default values.                                                */
    __clr_print_fmt(PRNT_FMT_ARG0);
    

    
}
