No longer used, first parm removed.
/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NFUPRINT.C  built from template file UPRINT.TPL
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
*       dest - address to put string, NULL = output via putch
*       fmt - format string
*       argp - argument list pointer
*
* Returns:
*       Number of characters transmitted, or
*       -1 if an error occured.
*
*************************************************/
int _u_n_f_print(char near * dest
   , __CONST__  char far * fmt
   , struct fmt_type* print_fmt
   , va_list argp)
{
  struct fmt_control_data print_ctrl;
  char print_buff[2];
  register char far * sp;
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
      __print_putch(print_fmt, *fmt++);
    }

    if (*fmt) {		/* we found a % in format string */
      fmt = _u_f_pscan(sp = fmt,print_fmt, &print_ctrl,&argp);
      if (print_ctrl.status == FMT_ERR) {

	/* error in format string, just dump out from p to fmt */

        for (;sp < fmt;++sp)
          __print_putch(print_fmt, *sp++);
	return(-1);
      }
      else if (print_ctrl.status == FMT_PASS_THRU) {
	__print_putch(print_fmt, print_ctrl.chr);
      }
      else {
	switch (print_fmt->type) {
          case 'd':
          case 'i':
                if (print_fmt->size == 'l' || print_fmt->size == 'L') {
                  _u_ltoa(print_fmt, va_arg(argp,long));
                }
                else /* %d */ {
                  _u_ltoa(print_fmt, (long)va_arg(argp,int));
                }
                break;
          case 'x':
          case 'X':
          case 'u':
          case 'o':
                if (print_fmt->size == 'l' || print_fmt->size == 'L') {
                  _u_ultoa(print_fmt, va_arg(argp,long));
                }
                else /* %x */ {
                  _u_ultoa(print_fmt, (unsigned long)va_arg(argp,unsigned int));
                }
                break;
	  case 'f':
	  case 'e':
	  case 'E':
	  case 'g':
	  case 'G':
                d = va_arg(argp,double);
                if (print_fmt->type == 'g')
                  _u_dtog(print_fmt,d);
		else
                  _u_dtof(print_fmt,d);
		break;
          case 'c':
                print_buff[0] = va_arg(argp,int);
                print_buff[1] = '\0';
                __print_send(print_fmt, print_buff);
		break;
	  case 's':
                switch (print_fmt->space)
                {
#if __MODEL__
                case 'N':
                   np = va_arg(argp,near char *);
                   __print_putnearstring(print_fmt, np);
		   break;
#else
                case 'F':
                   fp = va_arg(argp,far char *);
                   __print_putfarstring(print_fmt, fp);
		   break;
#endif
                case 'R':
                   rp = va_arg(argp,rom char *);
                   __print_putromstring(print_fmt, rp);
		   break;
                default:
                   p = va_arg(argp,char *);
                   __print_sendstring(print_fmt, p);
		   break;
                }
		break;
	  case 'p':
                switch (print_fmt->space)
                {
#if __MODEL__
                case 'N':
		   _u_ultoa(print_fmt, (long)va_arg(argp,near unsigned char*));
		   break;
#else
                case 'F':
		   _u_ultoa(print_fmt, (long)va_arg(argp,far unsigned char*));
		   break;
#endif
                case 'R':
		   _u_ultoa(print_fmt, (long)va_arg(argp,rom unsigned char*));
		   break;
                default:
                   switch(print_fmt->size)
                   {
#if __MODEL__
                   case 'h':
		      _u_ultoa(print_fmt, (long)va_arg(argp,near unsigned char*));
                      break;
#else
                   case 'l':
                   case 'L':
		      _u_ultoa(print_fmt, (long)va_arg(argp,far unsigned char*));
                      break;
#endif
                   default:
		     _u_ultoa(print_fmt, (long)va_arg(argp,unsigned char*));
                      break;
                   }
		   break;
                }
		break;
	  case 'n':
                switch (print_fmt->space)
                {
#if __MODEL__
                case 'N':
                   np = va_arg(argp,near char *);
                   if (print_fmt->size == 'l' || print_fmt->size == 'L')
                     *((near long *)np) = print_fmt->print_len;
                   else if (print_fmt->size == 'h')
                     *((near short *)np) = print_fmt->print_len;
                   else
                     *((near int *)np) = print_fmt->print_len;
		   break;
#else
                case 'F':
                   fp = va_arg(argp,far char *);
                   if (print_fmt->size == 'l' || print_fmt->size == 'L')
                     *((far long *)fp) = print_fmt->print_len;
                   else if (print_fmt->size == 'h')
                     *((far short *)fp) = print_fmt->print_len;
                   else
                     *((far int *)fp) = print_fmt->print_len;
		   break;
#endif
                default:
                   p = va_arg(argp,char *);
                   if (print_fmt->size == 'l' || print_fmt->size == 'L')
                     *((long *)p) = print_fmt->print_len;
                   else if (print_fmt->size == 'h')
                     *((short *)p) = print_fmt->print_len;
                   else
                     *((int *)p) = print_fmt->print_len;
		   break;
                }
		break;
	}
      }
    }
  }

  if (dest)
  {
    __print_putch(print_fmt, 0);
    print_fmt->print_len--;
  }
  return print_fmt->print_len;
}


