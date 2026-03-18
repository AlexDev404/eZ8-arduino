/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FVPRINTF.C  built from template file VPRINTF.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <format.h>
#include <stdio.h>
#include <stdarg.h>
#include <uart.h>    // for putch

/*************************************************
*
* vprintf - print to stdout (variable args)
*
* Inputs:
*	fmt - format string
*	ap - argument list
*
* Returns:
*	Number of characters transmitted, or
*	-1 if an error occured.
*
*************************************************/
#undef f_vprintf
PF_REENTRANT int f_vprintf(__CONST__ char far * fmt,va_list ap)
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

  __clr_print_fmt(PRNT_FMT_ARG0);
  __print_fmt.print_len = 0;
  __print_fmt.dest = NULL;
  _u_f_print(PRNT_FMT_ARG fmt, ap);
  return __print_fmt.print_len; 
}

