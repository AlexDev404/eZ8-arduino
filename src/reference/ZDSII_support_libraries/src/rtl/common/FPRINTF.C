/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FPRINTF.C  built from template file PRINTF.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <format.h>
#include <uart.h>    // for putch

/*************************************************
*
* printf - print to stdout
*
* Inputs:
*	fmt - format string
*	args - argument list
*
* Returns:
*	Number of characters transmitted, or
*	-1 if an error occured.
*
*************************************************/
#undef f_printf
PF_REENTRANT int f_printf(__CONST__ char far * fmt, ...)
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

  va_list ap;
  va_start(ap,fmt);
  __clr_print_fmt(PRNT_FMT_ARG0);
  __print_fmt.print_len = 0;
  __print_fmt.dest = NULL;
  _u_f_print(PRNT_FMT_ARG fmt,  ap);
  va_end(ap);

  return __print_fmt.print_len;
}


