/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RUPRINT.C  built from template file UPRINT.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <format.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

/*************************************************
*
* _u_print - print formated string to a file
*
* Inputs:
*       fmt - format string
*       argp - argument list pointer
*
* Returns:
*       Number of characters transmitted, or
*       -1 if an error occured.
*
*************************************************/
PF_REENTRANT int _u_r_print(PRINT_FMT_ARG
     __CONST__  char rom * fmt
   , va_list argp)
{
#ifdef __REENTRANT_PRINTFS__
  struct fmt_control_data print_ctrl;
#undef __print_ctrl
#define __print_ctrl print_ctrl
#endif
  char print_buff[2];
  register char rom * sp;
  char*         p;
#if __MODEL__
  near char*    np;
#else
  far char*     fp;
#endif
  rom char*     rp;
  double d;
  char radix;

  while (*fmt) {
    while (*fmt && *fmt != '%') {
      __print_putch(PRNT_FMT_ARG *fmt++);
    }

    if (*fmt) {		/* we found a % in format string */
      fmt = _u_r_pscan(PRNT_FMT_ARG PRNT_CTRL_ARG sp = fmt, &argp);
      if (__print_ctrl.status == FMT_ERR) {

	/* error in format string, just dump out from p to fmt */

        for (;sp < fmt;++sp)
          __print_putch(PRNT_FMT_ARG *sp++);
	return(-1);
      }
      else if (__print_ctrl.status == FMT_PASS_THRU) {
	__print_putch(PRNT_FMT_ARG __print_ctrl.chr);
      }
      else {
	switch (__print_fmt.type) {
          case 'd':
          case 'i':
                if (__print_fmt.size == 'l' || __print_fmt.size == 'L') {
                  _u_ltoa(PRNT_FMT_ARG va_arg(argp,long));
                }
                else /* %d */ {
                  _u_ltoa(PRNT_FMT_ARG (long)va_arg(argp,int));
                }
                break;
          case 'x':
          case 'X':
          case 'u':
          case 'o':
                if (__print_fmt.size == 'l' || __print_fmt.size == 'L') {
                  _u_ultoa(PRNT_FMT_ARG va_arg(argp,long));
                }
                else /* %x */ {
                  _u_ultoa(PRNT_FMT_ARG (unsigned long)va_arg(argp,unsigned int));
                }
                break;
	  case 'f':
	  case 'e':
	  case 'E':
	  case 'g':
	  case 'G':
                d = va_arg(argp,double);
                if (__print_fmt.type == 'g')
                  _u_dtog(PRNT_FMT_ARG d);
		else
                  _u_dtof(PRNT_FMT_ARG d);
		break;
          case 'c':
                print_buff[0] = va_arg(argp,int);
                print_buff[1] = '\0';
                __print_send(PRNT_FMT_ARG print_buff);
		break;
	  case 's':
                switch (__print_fmt.space)
                {
#if __MODEL__
                case 'N':
                   np = va_arg(argp,near char *);
                   __print_putnearstring(PRNT_FMT_ARG np);
		   break;
#else
                case 'F':
                   fp = va_arg(argp,far char *);
                   __print_putfarstring(PRNT_FMT_ARG fp);
		   break;
#endif
                case 'R':
                   rp = va_arg(argp,rom char *);
                   __print_putromstring(PRNT_FMT_ARG rp);
		   break;
                default:
                   p = va_arg(argp,char *);
                   __print_sendstring(PRNT_FMT_ARG p);
		   break;
                }
		break;
	  case 'p':
                switch (__print_fmt.space)
                {
#if __MODEL__
                case 'N':
		   _u_ultoa(PRNT_FMT_ARG (long)va_arg(argp,near unsigned char*));
		   break;
#else
                case 'F':
		   _u_ultoa(PRNT_FMT_ARG (long)va_arg(argp,far unsigned char*));
		   break;
#endif
                case 'R':
		   _u_ultoa(PRNT_FMT_ARG (long)va_arg(argp,rom unsigned char*));
		   break;
                default:
                   switch(__print_fmt.size)
                   {
#if __MODEL__
                   case 'h':
		      _u_ultoa(PRNT_FMT_ARG (long)va_arg(argp,near unsigned char*));
                      break;
#else
                   case 'l':
                   case 'L':
		      _u_ultoa(PRNT_FMT_ARG (long)va_arg(argp,far unsigned char*));
                      break;
#endif
                   default:
		     _u_ultoa(PRNT_FMT_ARG (long)va_arg(argp,unsigned char*));
                      break;
                   }
		   break;
                }
		break;
	  case 'n':
                switch (__print_fmt.space)
                {
#if __MODEL__
                case 'N':
                   np = va_arg(argp,near char *);
                   if (__print_fmt.size == 'l' || __print_fmt.size == 'L')
                     *((near long *)np) = __print_fmt.print_len;
                   else if (__print_fmt.size == 'h')
                     *((near short *)np) = __print_fmt.print_len;
                   else
                     *((near int *)np) = __print_fmt.print_len;
		   break;
#else
                case 'F':
                   fp = va_arg(argp,far char *);
                   if (__print_fmt.size == 'l' || __print_fmt.size == 'L')
                     *((far long *)fp) = __print_fmt.print_len;
                   else if (__print_fmt.size == 'h')
                     *((far short *)fp) = __print_fmt.print_len;
                   else
                     *((far int *)fp) = __print_fmt.print_len;
		   break;
#endif
                default:
                   p = va_arg(argp,char *);
                   if (__print_fmt.size == 'l' || __print_fmt.size == 'L')
                     *((long *)p) = __print_fmt.print_len;
                   else if (__print_fmt.size == 'h')
                     *((short *)p) = __print_fmt.print_len;
                   else
                     *((int *)p) = __print_fmt.print_len;
		   break;
                }
		break;
	}
      }
    }
  }

  /* For sprintf, put a null char at the end, but don't count towards length */
  if (__print_fmt.dest)
  {
    __print_putch(PRNT_FMT_ARG 0);
    __print_fmt.print_len--;
  }
  return __print_fmt.print_len;
}


