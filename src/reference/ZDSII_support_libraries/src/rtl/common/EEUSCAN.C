/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                EEUSCAN.C  built from template file USCAN.TPL
 *                          Do not edit directly
 ******************************************************************************/

/*************************************************************************
 * We now assume that the maximum number of fields processed in a format
 * string is 255.  Then, we can fit the field count into a char, for a
 * slight saving in space and time. <THH>
 *************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <stdarg.h>
#include <format.h>
#include <float.h>
#include <ZilogWarnings.h>

#include <string.h>



static char pageE * _u_e_bptr;
static struct pageE_set_type _u_e_set;

/****************************************/
/*					*/
/*	     get a character		*/
/*					*/
/****************************************/
static int _u_e_get(void)
{
  int c;

  ++_u_len;
  if (_u_e_bptr)
  {
    c = *_u_e_bptr;
    if (c == '\0')
      c = EOF;
    else
      _u_e_bptr++;
    _u_prev_ch = c;
    return c;
  }
  else if (_u_isunget==1) {
    _u_isunget = 0;
    return _u_prev_ch;
  }
  return(_u_prev_ch = getchar());
}


/****************************************/
/*					*/
/*	     unget a character		*/
/*					*/
/****************************************/
static void _u_e_unget(void)
{
  --_u_len;
  _u_isunget = 1;
  if (_u_e_bptr)
    --_u_e_bptr;
}

/****************************************/
/*					*/
/*	  Handle charset conversions	*/
/*					*/
/****************************************/
static unsigned char _u_e_charset(struct fmt_type *print_fmt)
{
  pageE char * p2;
  char neg,ch;
  char * p = NULL;
#if __MODEL__
  near char * np = NULL;
#else
  far char * fp = NULL;
#endif
  char width;

  /* Use (p == 0) to signal the case that we are skipping this input string. <THH> */
  if (!(print_fmt->flags & FMT_FLAG_IGNORE))
  {
     switch(print_fmt->space)
     {
#if __MODEL__
     case 'N':
        np = va_arg(_u_argp,near char *);
        break;
#else
     case 'F':
        fp = va_arg(_u_argp,far char *);
        break;
#endif
     default:
        p = va_arg(_u_argp,char *);
        break;
     }
  }

  if (neg = (* _u_e_set.begin == '^'))
    _u_e_set.begin++;

  width = print_fmt->field_width;
  if (width == 0)
    width = 127;

  while (width--)
  {
    if ((ch = _u_e_get()) == EOF)
      return FALSE;

    /* Look for a match in the set. */
    for(p2 = _u_e_set.begin; p2 < _u_e_set.end; ++p2)
      if (*p2 == ch)
	break;	/* Matched one in the set. */

    if (p2 < _u_e_set.end && *p2 == ch)
    {
      /* We stop scanning if we match a character in the negative set. */
      if (neg)
	break;
    }
    else
    {
      /* Likewise, we stop scanning if we fail to match a character in the positive set. */
      if (!neg)
	break;
    }

    /* Store the valid character. <THH> */
    if (p)
      *(p++) = ch;
    else
#if __MODEL__
    if (np)
      *(np++) = ch;
#else
    if (fp)
      *(fp++) = ch;
#endif
  }

  if (width > 0)
    _u_e_unget();

  if (p)
    *p = '\0';
  else
#if __MODEL__
    *(np++) = '\0';
#else
    *(fp++) = '\0';
#endif

  return TRUE;
}


/****************************************/
/*					*/
/*	Handle scalar conversions	*/
/*					*/
/****************************************/
static unsigned char _u_e_scalar(struct fmt_type *print_fmt, int radix)
{
  unsigned char i;
  char ch;
  char far * bp = _u_fmt_buf;
  long val;
  char size;
  signed char swidth;

  swidth = print_fmt->field_width;

  if (print_fmt->field_width == 0 || print_fmt->field_width > sizeof(_u_fmt_buf)-1)
    print_fmt->field_width = sizeof(_u_fmt_buf)-1;
  do {
    if ((ch = _u_e_get()) == EOF)
      return FALSE;
  } while (isspace(ch));
  _u_e_unget();
  if ((ch = _u_e_get()) == EOF)
    return FALSE;
  for (i=0;radix == 10 && isdigit(ch) ||
	   radix == 16 && isxdigit(ch) ||
	   radix == 8 && ch >= '0' && ch <= '7' ||
	   ch == '-' ||
	   ch == '+';) {
    *(bp++) = ch;
    i++;
    if (i >= print_fmt->field_width)
      break;
    if ((ch = _u_e_get()) == EOF)
    {
      if (i >= swidth)
        break;
      return FALSE;
    }
  }
  if (bp == _u_fmt_buf)
    return FALSE;
  if (i < print_fmt->field_width)
    _u_e_unget();
  *bp = '\0';

  val = f_strtoul(_u_fmt_buf,NULL,radix);

#ifndef __EZ8__
  if (print_fmt->size == 'h')
     size = sizeof(short);
  else
#endif
#ifndef __ZNEO__
  if (print_fmt->size == 'l' || print_fmt->size == 'L')
     size = sizeof(long);
  else
#endif
     size = sizeof(int);
  __uscan_put(print_fmt, size,val);

  return TRUE;
}


/****************************************/
/*					*/
/*	Floating point conversions	*/
/*					*/
/****************************************/
static unsigned char _u_e_fpoint(struct fmt_type *print_fmt)
{
  unsigned char i;
  char ch;
  char far * bp = _u_fmt_buf;
  union
  {
     double dval;
     long lval;
  }u;
  unsigned char takeEe=TRUE;
  unsigned char takeDot=TRUE;
  unsigned char takeSign=TRUE;
  signed char swidth;

  swidth = print_fmt->field_width-1;
  if (print_fmt->field_width == 0 || print_fmt->field_width > sizeof(_u_fmt_buf)-1)
    print_fmt->field_width = sizeof(_u_fmt_buf)-1;
  do {
    if ((ch = _u_e_get()) == EOF)
      return FALSE;
  } while (isspace(ch));

  for (i=0; i < print_fmt->field_width; ++i)
  {
    if (takeEe && (ch == 'e' || ch == 'E'))
    {
       takeEe = FALSE;
       takeSign=TRUE;
       takeDot=FALSE;
    } else
    if (takeDot && ch=='.')
    {
      takeDot=FALSE;
    } else
    if (   (takeSign && (ch == '-' || ch == '+'))
       ||  isdigit(ch) )
    {
        takeSign = FALSE;
    } else
    {
        break;
    }
    *(bp++) = ch;
    if ((ch = _u_e_get()) == EOF)
    {
      if (i >= swidth)
        break;
      return FALSE;
    }
  }
  if (bp == _u_fmt_buf)
    return(_u_fields);
  if (i < print_fmt->field_width)
    _u_e_unget();
  *bp = '\0';
  u.dval = f_strtod(_u_fmt_buf,(void *)NULL);

  __uscan_put(print_fmt, sizeof(float), u.lval);

  return TRUE;
}


/****************************************/
/*					*/
/*	Handle character conversions	*/
/*					*/
/****************************************/
static unsigned char _u_e_character(struct fmt_type *print_fmt)
{
  unsigned char i;
  char ch;
  char * p = NULL;
#if __MODEL__
  near char * np = NULL;
#else
  far char * fp = NULL;
#endif

  if (!(print_fmt->flags & FMT_FLAG_IGNORE))
  {
     switch(print_fmt->space)
     {
#if __MODEL__
     case 'N':
        np = va_arg(_u_argp,near char *);
        break;
#else
     case 'F':
        fp = va_arg(_u_argp,far char *);
        break;
#endif
     default:
        p = va_arg(_u_argp,char *);
        break;
     }
  }

  if (print_fmt->field_width == 0)
    print_fmt->field_width = 1;
  for (i=0;i<print_fmt->field_width;++i)
  {
    if ((ch = _u_e_get()) == EOF)
      return FALSE;
    if (p)
      *p++ = ch;
    else
#if __MODEL__
    if (np)
      *(np++) = ch;
#else
    if (fp)
      *(fp++) = ch;
#endif
  }
  if (!(print_fmt->flags & FMT_FLAG_IGNORE))
    ++_u_fields;
  return TRUE;
}


/****************************************/
/*					*/
/*	Handle string conversions	*/
/*					*/
/****************************************/
static unsigned char _u_e_string(struct fmt_type *print_fmt)
{
  unsigned char i;
  char ch;
  char * p = NULL;
#if __MODEL__
  near char * np = NULL;
#else
  far char * fp = NULL;
#endif
  signed char swidth;

  swidth = print_fmt->field_width;

  if (!(print_fmt->flags & FMT_FLAG_IGNORE))
  {
     switch(print_fmt->space)
     {
#if __MODEL__
     case 'N':
        np = va_arg(_u_argp,near char *);
        break;
#else
     case 'F':
        fp = va_arg(_u_argp,far char *);
        break;
#endif
     default:
        p = va_arg(_u_argp,char *);
        break;
     }
  }
  if (print_fmt->field_width == 0)
    print_fmt->field_width = 127;
  do {
    if ((ch = _u_e_get()) == EOF)
      return FALSE;
  } while (isspace(ch));
  _u_e_unget();
  if ((ch = _u_e_get()) == EOF)
    return FALSE;
  for (i=0; !isspace(ch) && ch;) {
    if (p)
      *(p++) = ch;
    else
#if __MODEL__
    if (np)
      *(np++) = ch;
#else
    if (fp)
      *(fp++) = ch;
#endif
    i++;
    if (i >= print_fmt->field_width)
      break;
    if ((ch = _u_e_get()) == EOF)
    {
      if (i >= swidth)
        break;
      return FALSE;
    }
  }
  if (i < print_fmt->field_width)
    _u_e_unget();
  if (p)
    *p = '\0';
  else
#if __MODEL__
  if (np)
    *np = '\0';
#else
  if (fp)
    *fp = '\0';
#endif
  if (!(print_fmt->flags & FMT_FLAG_IGNORE))
     ++_u_fields;
  return TRUE;
}


/****************************************/
/*					*/
/*	Handle pointer conversions	*/
/*					*/
/****************************************/
static unsigned char _u_e_pointer(struct fmt_type *print_fmt)
{
  unsigned char i;
  char ch;
  char far * bp = _u_fmt_buf;
  unsigned long addr;
  char size;
  signed char swidth;

  swidth = print_fmt->field_width;
  if (print_fmt->field_width == 0 || print_fmt->field_width > sizeof(_u_fmt_buf)-1)
    print_fmt->field_width = sizeof(_u_fmt_buf)-1;
  if ((ch = _u_e_get()) == EOF)
    return FALSE;
  for (i=0;isxdigit(ch);) {
    *(bp++) = ch;
    i++;
    if (i >= print_fmt->field_width)
      break;
    if ((ch = _u_e_get()) == EOF)
    {
      if (i >= swidth)
        break;
      return FALSE;
    }
  }
  if (bp == _u_fmt_buf)
    return FALSE;
  if (i < print_fmt->field_width)
    _u_e_unget();
  *bp = '\0';
  addr = f_strtoul(_u_fmt_buf,NULL,16);

  /* The h/l/L modifiers give the space the address should live in,
   * the N/F modifiers give the space the destination pointer lives in.
   * So %Nhp reads a far address and saves it in near memory.
   */
#if __MODEL__
  if (print_fmt->size == 'h')
    size = sizeof(near char*);
#else
  if (print_fmt->size == 'l' || print_fmt->size == 'L')
    size = sizeof(far char*);
#endif
  else
    size = sizeof(char*);

  __uscan_put(print_fmt, size, addr);
  return TRUE;
}


/*************************************************
*
* _u_scan - scan formated string from a file or string
*
* ISO Spec:  Return EOF if an input error occurs before any conversion.
* Otherwise return the number of input items assigned. 
*
* Inputs:
*	src - NULL = input from keyboard, else input from string
*       fmt - format string
*	ap - argument list pointer
*
* Returns:
*	Number of characters transmitted, or
*	-1 if an error occured.
*
*************************************************/
int _u_e_e_scan(__CONST__ char pageE * src,__CONST__  char pageE * fmt, va_list ap)
{
  int i;
  int ch;
  char size;
  struct fmt_type print_fmt;
  struct fmt_control_data print_ctrl;
  unsigned char ok=TRUE;


  _u_argp = ap;
  _u_fields = 0;
  _u_len = 0;
  _u_prev_ch = 0;
  _u_isunget = 0;
  _u_e_bptr = NULL;

  if (src)
    _u_e_bptr = src;

  while ( ok && /*_u_prev_ch!=EOF &&*/ *fmt) {
    fmt = _u_e_sscan(fmt, &print_fmt, &print_ctrl, &_u_e_set);
    if (print_ctrl.status == FMT_ERR)
      return(_u_fields);
    else if (print_ctrl.status == FMT_PASS_THRU) {
      if (isspace(print_ctrl.chr))
      {
        do ch=_u_e_get();
        while(isspace(ch));
        _u_e_unget();
      } else
      {
        ch = _u_e_get();
        if (ch && ch != print_ctrl.chr)
	  break;
      }
    }
    else if (print_fmt.flags & FMT_FLAG_SET) {
      ok = _u_e_charset(&print_fmt);
    }
    else {
      switch (print_fmt.type) {
	  case 'd':
	  case 'i':
	  case 'u':
                ok = _u_e_scalar(&print_fmt, 10);
		break;
	  case 'x':
	  case 'X':
                ok = _u_e_scalar(&print_fmt, 16);
		break;
	  case 'o':
                ok = _u_e_scalar(&print_fmt, 8);
		break;
	  case 'A':
	  case 'E':
	  case 'F':
	  case 'G':
	  case 'a':
	  case 'e':
	  case 'f':
	  case 'g':
                ok = _u_e_fpoint(&print_fmt);
		break;
	  case 'c':
		ok = _u_e_character(&print_fmt);
		break;
	  case 's':
		ok = _u_e_string(&print_fmt);
		break;
	  case 'p':
		ok = _u_e_pointer(&print_fmt);
		break;
	  case 'n':
                switch(print_fmt.size)
                {
#ifndef __EZ8__
                case 'h':
                   size = sizeof(short);
#endif
#ifndef __ZNEO__
                   break;
                case 'l':
                case 'L':
                   size = sizeof(long);
                   break;
#endif
                  default:
                   size = sizeof(int);
                   break;
                }
                __uscan_put(&print_fmt, size,(long)_u_len);
		break;
      }
    }
  }

  /* A sucessful passthrough counts as a conversion, so we look at _u_len, */
  /* which will be 1 for an unsucessful call to get() on the first try.	*/
  if (_u_prev_ch == EOF && _u_len<=1 && _u_fields == 0)
     return EOF;
  return _u_fields;
}


