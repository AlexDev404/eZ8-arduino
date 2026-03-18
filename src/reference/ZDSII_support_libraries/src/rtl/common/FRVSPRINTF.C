/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FRVSPRINTF.C  built from template file VSPRINTF.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <format.h>
#include <stdio.h>
#include <stdarg.h>

/*************************************************
*
* vsprintf - print to a string (variable args)
*
* Inputs:
*	string - pointer to string to write to
*	fmt - format string
*	args - argument list
*
* Returns:
*	Number of characters transmitted, or
*	-1 if an error occured.
*
*************************************************/
#undef f_r_vsprintf
PF_REENTRANT int f_r_vsprintf(char far * string,__CONST__ char rom * fmt,va_list args)
{
#ifdef __REENTRANT_PRINTFS__
  struct fmt_type print_fmt;
#undef __print_fmt
#define __print_fmt print_fmt
#undef PRNT_FMT_ARG0
#define PRNT_FMT_ARG0 &print_fmt
#undef PRNT_FMT_ARG
#define PRNT_FMT_ARG &print_fmt,
#endif

  int retVal;

  __clr_print_fmt(PRNT_FMT_ARG0);
  __print_fmt.print_len = 0;
  __print_fmt.dest = (far char*)string;
  _u_r_print(PRNT_FMT_ARG fmt, args);
  return __print_fmt.print_len; 
}
