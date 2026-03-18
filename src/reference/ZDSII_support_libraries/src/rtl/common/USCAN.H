/*************************************************
 *  Copyright (C) 1999-2005 by  ZiLOG, Inc.
 *  All Rights Reserved
 *************************************************/

/*************************************************************************
 * We now assume that the maximum number of fields processed in a format
 * string is 255.  Then, we can fit the field count into a char, for a
 * slight saving in space and time. <THH>
 *************************************************************************/

#pragma once    // Include this file only once
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <stdarg.h>
#include <format.h>
#include <float.h>

#include <string.h>


#define BPTR_TEMPLATE(EXTRN,PREFIX,SPACE) \
EXTRN char SPACE * _u_##PREFIX##bptr;
BPTR_TEMPLATE(extern,,)
BPTR_TEMPLATE(extern,n_,near)
BPTR_TEMPLATE(extern,f_,far)

#define SET_STR_TEMPLATE(EXTRN,PREFIX,SPACE) \
EXTRN struct SPACE##_set_type _u_##PREFIX##set;
SET_STR_TEMPLATE(extern,,)
SET_STR_TEMPLATE(extern,n_,near)
SET_STR_TEMPLATE(extern,f_,far)
SET_STR_TEMPLATE(extern,r_,rom)

#define GET_S_TEMPLATE(PREFIX) \
int _u_##PREFIX##get(void);
GET_S_TEMPLATE()
GET_S_TEMPLATE(n_)
GET_S_TEMPLATE(f_)

/****************************************/
/*					*/
/*	     get a character		*/
/*					*/
/****************************************/
#define GET_TEMPLATE(PREFIX) \
int _u_##PREFIX##get(void)	\
{			\
  ++_u_len;		\
  if (_u_##PREFIX##bptr)	\
    return(*(_u_##PREFIX##bptr++));	\
  else if (_u_isunget==1) {\
    _u_isunget = 0;	\
    return _u_prev_ch;	\
  }			\
  return(_u_prev_ch = getchar());	\
}


#define UNGET_S_TEMPLATE(PREFIX) \
void _u_##PREFIX##unget(void);
UNGET_S_TEMPLATE()
UNGET_S_TEMPLATE(n_)
UNGET_S_TEMPLATE(f_)

/****************************************/
/*					*/
/*	     unget a character		*/
/*					*/
/****************************************/
#define UNGET_TEMPLATE(PREFIX) \
void _u_##PREFIX##unget(void)	\
{			\
  --_u_len;		\
  _u_isunget = 1;		\
  if (_u_##PREFIX##bptr)	\
    --_u_##PREFIX##bptr; 	\
}

#define CHARSET_S_TEMPLATE(PREFIX) \
unsigned char _u_##PREFIX##charset(void);
CHARSET_S_TEMPLATE()
CHARSET_S_TEMPLATE(n_)
CHARSET_S_TEMPLATE(f_)

/****************************************/
/*					*/
/*	  Handle charset conversions	*/
/*					*/
/****************************************/
#define CHARSET_TEMPLATE(PREFIX, SPACE) \
unsigned char _u_##PREFIX##charset(void)	\
{			\
  SPACE char * p2;		\
  char neg,ch;		\
  char * p = 0;		\
  char width;		\
			\
  /* Use (p == 0) to signal the case that we are skipping this input string. <THH> */	\
  if (!(__print_fmt.flags & FMT_FLAG_IGNORE))	\
    p = va_arg(_u_argp,char *);			\
			\
  if (neg = (* _u_##PREFIX##set.begin == '^'))	\
    _u_##PREFIX##set.begin++;	\
				\
  width = __print_fmt.field_width;	\
  if (width == 0)		\
    width = 127;		\
				\
  while (width--)		\
  {				\
    if ((ch = _u_##PREFIX##get()) == EOF)	\
      return FALSE;		\
				\
    /* Look for a match in the set. */	\
    for(p2 = _u_##PREFIX##set.begin; p2 < _u_##PREFIX##set.end; ++p2)	\
      if (*p2 == ch)		\
	break;	/* Matched one in the set. */	\
				\
    if (p2 < _u_##PREFIX##set.end && *p2 == ch)	\
    {				\
      /* We stop scanning if we match a character in the negative set. */	\
      if (neg)		\
	break;		\
    }			\
    else		\
    {			\
      /* Likewise, we stop scanning if we fail to match a character in the positive set. */	\
      if (!neg)		\
	break;		\
    }			\
			\
    /* Store the valid character. <THH> */	\
    if (p)		\
      *(p++) = ch;	\
  }			\
			\
  if (width > 0)	\
    _u_##PREFIX##unget();	\
			\
  if (p)		\
    *p = '\0';		\
			\
  return TRUE;		\
}


#define SCALAR_S_TEMPLATE(PREFIX) \
unsigned char _u_##PREFIX##scalar(int radix);
SCALAR_S_TEMPLATE()
SCALAR_S_TEMPLATE(n_)
SCALAR_S_TEMPLATE(f_)

#ifdef NEAR_FMT_BUFFERS
#define STRTOL strtol
#define STRTOD strtod
#else
#define STRTOL f_strtol
#define STRTOD f_strtod
#endif

/****************************************/
/*					*/
/*	Handle scalar conversions	*/
/*					*/
/****************************************/
#define SCALAR_TEMPLATE(PREFIX) \
unsigned char _u_##PREFIX##scalar(int radix)	\
{					\
  unsigned char i;			\
  char ch;				\
  char FAR_FMT_BUFFERS * bp = _u_fmt_buf;		\
  long val;				\
					\
  if (__print_fmt.field_width == 0 || __print_fmt.field_width > sizeof(_u_fmt_buf)-1)	\
    __print_fmt.field_width = sizeof(_u_fmt_buf)-1;	\
  do {					\
    if ((ch = _u_##PREFIX##get()) == EOF)	\
      return FALSE;			\
  } while (isspace(ch));		\
  _u_##PREFIX##unget();			\
  if ((ch = _u_##PREFIX##get()) == EOF)	\
    return FALSE;			\
  for (i=0;radix == 10 && isdigit(ch) ||	\
	   radix == 16 && isxdigit(ch) ||	\
	   radix == 8 && ch >= '0' && ch <= '7' ||	\
	   ch == '-' ||			\
	   ch == '+';) {		\
    *(bp++) = ch;			\
    i++;				\
    if (i >= __print_fmt.field_width)	\
      break;				\
    if ((ch = _u_##PREFIX##get()) == EOF)	\
      return FALSE;			\
  }					\
  if (bp == _u_fmt_buf)			\
    return FALSE;			\
  if (i < __print_fmt.field_width)		\
    _u_##PREFIX##unget();			\
  *bp = '\0';				\
					\
  val = STRTOL(_u_fmt_buf,NULL,radix);	\
					\
  if (!(__print_fmt.flags & FMT_FLAG_IGNORE)) {	\
    if (__print_fmt.size == 'h')		\
      *(va_arg(_u_argp,short *)) = val;	\
    else if (__print_fmt.size == 'l' || __print_fmt.size == 'L')\
      *(va_arg(_u_argp,long *)) = val;	\
    else				\
      *(va_arg(_u_argp,int *)) = val;	\
    ++_u_fields;				\
  }					\
					\
  return TRUE;				\
}


#define FPOINT_S_TEMPLATE(PREFIX) \
unsigned char _u_##PREFIX##fpoint(void);
FPOINT_S_TEMPLATE()
FPOINT_S_TEMPLATE(n_)
FPOINT_S_TEMPLATE(f_)

/****************************************/
/*					*/
/*	Floating point conversions	*/
/*					*/
/****************************************/
#define FPOINT_TEMPLATE(PREFIX) \
unsigned char _u_##PREFIX##fpoint(void)	\
{				\
  unsigned char i;		\
  char ch;			\
  char FAR_FMT_BUFFERS * bp = _u_fmt_buf;	\
  double dval;			\
  unsigned char takeEe=TRUE;	\
  unsigned char takeDot=TRUE;	\
  unsigned char takeSign=TRUE;	\
				\
  if (__print_fmt.field_width == 0 || __print_fmt.field_width > sizeof(_u_fmt_buf)-1)	\
    __print_fmt.field_width = sizeof(_u_fmt_buf)-1;	\
  do {				\
    if ((ch = _u_##PREFIX##get()) == EOF)	\
      return FALSE;		\
  } while (isspace(ch));	\
				\
  for (i=0; i < __print_fmt.field_width; ++i)	\
  {				\
    if (takeEe && (ch == 'e' || ch == 'E'))	\
    {				\
       takeEe = FALSE;		\
       takeSign=TRUE;		\
       takeDot=FALSE;		\
    } else			\
    if (takeDot && ch=='.')	\
    {				\
      takeDot=FALSE;		\
    } else			\
    if (   (takeSign && (ch == '-' || ch == '+'))	\
       ||  isdigit(ch) )	\
    {				\
        takeSign = FALSE;	\
    } else			\
    {				\
        break;			\
    }				\
    *(bp++) = ch;		\
    if ((ch = _u_##PREFIX##get()) == EOF)	\
      return FALSE;		\
  }				\
  if (bp == _u_fmt_buf)		\
    return(_u_fields);		\
  if (i < __print_fmt.field_width)	\
    _u_##PREFIX##unget();		\
  *bp = '\0';			\
  dval = STRTOD(_u_fmt_buf,(void _PTR_)NULL);	\
				\
  if (!(__print_fmt.flags & FMT_FLAG_IGNORE)) {	\
    *(va_arg(_u_argp, float *)) = dval;	\
    ++_u_fields;			\
  }				\
				\
  return TRUE;			\
}


#define CHARACTER_S_TEMPLATE(PREFIX) \
unsigned char _u_##PREFIX##character(void);
CHARACTER_S_TEMPLATE()
CHARACTER_S_TEMPLATE(n_)
CHARACTER_S_TEMPLATE(f_)

/****************************************/
/*					*/
/*	Handle character conversions	*/
/*					*/
/****************************************/
#define CHARACTER_TEMPLATE(PREFIX) \
unsigned char _u_##PREFIX##character(void)	\
{				\
  unsigned char i;		\
  char ch;			\
  char * p=NULL;		\
				\
  if (!(__print_fmt.flags & FMT_FLAG_IGNORE))	\
    p = va_arg(_u_argp,char *);			\
  if (__print_fmt.field_width == 0)			\
    __print_fmt.field_width = 1;			\
  for (i=0;i<__print_fmt.field_width;++i)		\
  {				\
    if ((ch = _u_##PREFIX##get()) == EOF)	\
      return FALSE;		\
    if (p)			\
      *(p++) = ch;		\
    ++_u_fields;			\
  }				\
  return TRUE;			\
}


#define STRING_S_TEMPLATE(PREFIX) \
unsigned char _u_##PREFIX##string(void);
STRING_S_TEMPLATE()
STRING_S_TEMPLATE(n_)
STRING_S_TEMPLATE(f_)

/****************************************/
/*					*/
/*	Handle string conversions	*/
/*					*/
/****************************************/
#define STRING_TEMPLATE(PREFIX) \
unsigned char _u_##PREFIX##string(void)	\
{				\
  unsigned char i;		\
  char ch;			\
  char * p = NULL;		\
				\
  if (!(__print_fmt.flags & FMT_FLAG_IGNORE))	\
     p = va_arg(_u_argp,char _PTR_);		\
  if (__print_fmt.field_width == 0)		\
    __print_fmt.field_width = 127;		\
  do {					\
    if ((ch = _u_##PREFIX##get()) == EOF)	\
      return FALSE;			\
  } while (isspace(ch));		\
  _u_##PREFIX##unget();			\
  if ((ch = _u_##PREFIX##get()) == EOF)	\
    return FALSE;			\
  for (i=0; !isspace(ch) && ch;) {	\
    if (p)				\
      *(p++) = ch;			\
    i++;				\
    if (i >= __print_fmt.field_width)	\
      break;				\
    if ((ch = _u_##PREFIX##get()) == EOF)	\
      return FALSE;			\
  }				\
  if (i < __print_fmt.field_width)	\
    _u_##PREFIX##unget();		\
  if (p)			\
  {				\
    *p = '\0';			\
    ++_u_fields;			\
  }				\
  return TRUE;			\
}


#define POINTER_S_TEMPLATE(PREFIX) \
unsigned char _u_##PREFIX##pointer(void);
POINTER_S_TEMPLATE()
POINTER_S_TEMPLATE(n_)
POINTER_S_TEMPLATE(f_)

/****************************************/
/*					*/
/*	Handle pointer conversions	*/
/*					*/
/****************************************/
#define POINTER_TEMPLATE(PREFIX) \
unsigned char _u_##PREFIX##pointer(void)	\
{				\
  unsigned char i;		\
  char ch;			\
  char FAR_FMT_BUFFERS * bp = _u_fmt_buf;	\
  unsigned addr;		\
				\
  if (__print_fmt.field_width == 0 || __print_fmt.field_width > sizeof(_u_fmt_buf)-1)	\
    __print_fmt.field_width = sizeof(_u_fmt_buf)-1;				\
  if ((ch = _u_##PREFIX##get()) == EOF)				\
    return FALSE;					\
  for (i=0;isxdigit(ch);) {			\
    *(bp++) = ch;			\
    i++;				\
    if (i >= __print_fmt.field_width)	\
      break;				\
    if ((ch = _u_##PREFIX##get()) == EOF)	\
      return FALSE;			\
  }				\
  if (bp == _u_fmt_buf)		\
    return FALSE;		\
  if (i < __print_fmt.field_width)	\
    _u_##PREFIX##unget();		\
  *bp = '\0';			\
  addr = STRTOL(_u_fmt_buf,NULL,16);	\
				\
  if (!(__print_fmt.flags & FMT_FLAG_IGNORE))	\
  {				\
    *(va_arg(_u_argp,char **)) = (char *)addr;	\
    ++_u_fields;				\
  }				\
				\
  return TRUE;			\
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
#define USCAN_TEMPLATE(PREFIX1,PREFIX2,SPACE1,SPACE2) \
int _u_##PREFIX1##PREFIX2##scan(char SPACE1 * src, char SPACE2 * fmt, va_list ap) \
{							\
  int i;						\
  int ch;						\
  unsigned char ok=TRUE;				\
							\
  _u_argp = ap;						\
  _u_fields = 0;					\
  _u_len = 0;						\
  _u_prev_ch = 0;					\
  _u_isunget = 0;					\
  _u_##PREFIX1##bptr = NULL;				\
							\
  if (src)						\
    _u_##PREFIX1##bptr = src;				\
							\
  while ( ok && _u_prev_ch!=EOF && *fmt) {		\
    fmt = _u_##PREFIX2##sscan(fmt, &__print_fmt, & _u_##PREFIX2##set);	\
    if (__print_fmt.status == FMT_ERR)			\
      return(_u_fields);				\
    else if (__print_fmt.status == FMT_PASS_THRU) {	\
      if (isspace(__print_fmt.chr))			\
      {							\
        do ch=_u_##PREFIX1##get();			\
        while(isspace(ch));				\
        _u_##PREFIX1##unget();				\
      } else						\
      {							\
        ch = _u_##PREFIX1##get();			\
        if (ch && ch != __print_fmt.chr)			\
	  break;					\
      }							\
    }							\
    else if (__print_fmt.flags & FMT_FLAG_SET) {		\
      ok = _u_##PREFIX1##charset();			\
    }							\
    else {						\
      switch (__print_fmt.type) {			\
	  case 'd':					\
	  case 'i':					\
	  case 'u':					\
                ok = _u_##PREFIX1##scalar(10);		\
		break;					\
	  case 'x':					\
	  case 'X':					\
                ok = _u_##PREFIX1##scalar(16);		\
		break;					\
	  case 'o':					\
                ok = _u_##PREFIX1##scalar(8);		\
		break;					\
	  case 'A':					\
	  case 'E':					\
	  case 'F':					\
	  case 'G':					\
	  case 'a':					\
	  case 'e':					\
	  case 'f':					\
	  case 'g':					\
                ok = _u_##PREFIX1##fpoint();		\
		break;					\
	  case 'c':					\
		ok = _u_##PREFIX1##character();		\
		break;					\
	  case 's':					\
		ok = _u_##PREFIX1##string(); 		\
		break;					\
	  case 'p':					\
		ok = _u_##PREFIX1##pointer();		\
		break;					\
	  case 'n':					\
		if (!(__print_fmt.flags & FMT_FLAG_IGNORE)) {	\
		  *(va_arg(_u_argp,int *)) = _u_len;		\
		  ++_u_fields;				\
		}					\
		break;					\
      }						\
    }						\
  }						\
  /* A sucessful passthrough counts as a conversion, so we look at _u_len, */	\
  /* which will be 1 for an unsucessful call to get() on the first try.	*/	\
  if (_u_prev_ch == EOF && _u_len<=1)			\
     return EOF;				\
  return _u_fields;				\
}


