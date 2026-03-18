/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <stddef.h>
#include <format.h>
#include <ctype.h>
#include <string.h>
#include <float.h>

#if __MODEL__ == 0
#define STRCPY n_r_strcpy
#else
#define STRCPY f_r_strcpy
#endif



/*
 * exp+1- counts the number of digits to the left of the decimal point
 * ndig	- counts the number of significant digits to print.
 */
static PF_REENTRANT char * write_f_digits(PRINT_FMT_ARG
      FLT_DATA_ARG
        char * s
      , signed char exp
      , signed char ndig
      , struct flt_info* info)
{
  unsigned char i = 0;

  /* Emit a leading zero, if needed. */
  if (exp < 0) {
    *(s++) = '0';
	--ndig;
  }

  while (exp >= 0 && i < MAXDIGITS)
  {
    *(s++) = info->digits[i++] + '0';
    --ndig; --exp;
  }
  __flt_data.pad_at = s;
  if (exp >= 0) {
    __flt_data.pad_whole = exp+1;
    ndig -= (exp+1);
	exp = -1;
  }

  *(s++) = '.';


  if (exp < -1) {
    if (ndig > (-exp-1)) {
      __flt_data.pad_pre_fract = -(exp+1);
	  ndig -= -(exp+1);
	  exp = -1;
    }
    else {
      __flt_data.pad_pre_fract = ndig;
	  ndig = 0;
    }
  } 
  while (ndig > 0 && i < MAXDIGITS)
  {
    *(s++) = info->digits[i++] + '0';
    --ndig;
  }
  if (ndig > 0) {
    __flt_data.pad_post_fract =ndig;
	ndig = 0;
  }
 
  return s;
}

static PF_REENTRANT char * write_e_digits(char * s, signed char exp, signed char ndig,struct flt_info* info)
{
  unsigned char i = 0;

  /* Emit the single digit to the left of the decimal point. */
  *(s++) = info->digits[i++] + '0';
  --ndig;

  /* Emit the decimal point. */
  *(s++) = '.';

  /* Emit the digits. */
  while (ndig-- && i < MAXDIGITS)
    *(s++) = info->digits[i++] + '0';

  return s;
}

static PF_REENTRANT char * write_exponent(char * s, char e, signed char exp)
{
  /* Emit the exponent specifier. */
  *(s++) = e;

  /* Emit the exponent sign. */
  if (exp < 0) {
    *(s++) = '-';
    exp = -exp;
  }
  else
    *(s++) = '+';

  /* Emit the two-digit exponent. */
  /* For 4-byte floats, the exponent is between -37 and +38, or simply 0
     to 38 after folding. */
  *(s++) = exp / 10 + '0';
  *(s++) = exp % 10 + '0';

  return s;
}

/*************************************************
*
* _u_dtof - convert a double float to ASCII in f format
*
* Inputs:
*	n - value to be converted
*	s - target char array
*	fmt - format structure with conversion info
*
* Locals:
*	ndig - The number of significant digits to print.
*		Assumed to lie in the range [0,127].
*		For e format, this is 1 + precision.
*		For f format, this is 1 + precision + exp.
*
*		Up to MAXDIGITS+6 chars generated, including null char
*		+ or -        1
*		decimal point 1
*		digits        MAXDIGITS
*		exponent E-XX 4
*		null char     0
*		Total         MAXDIGITS+6
*
*
*************************************************/
PF_REENTRANT void _u_dtof(PRINT_FMT_ARG double n)
{
#ifdef __REENTRANT_PRINTFS__
  struct flt_fmt_data flt_data;
#undef __flt_data
#define __flt_data flt_data
#else
#undef memset
#define memset f_memset
#endif
  struct flt_info info;
  register signed char ndig, rdig;
  register signed char exp;
  register char e;
  char print_buff[MAXDIGITS+6];
  char*  s = print_buff;

  memset(&__flt_data, 0, sizeof(__flt_data));

  if (__print_fmt.precision < 0)
    __print_fmt.precision = DEFAULT_PRECISION;

  if (__print_fmt.field_width < 0)
  {
    __print_fmt.flags |= FMT_FLAG_MINUS;
    __print_fmt.field_width = -__print_fmt.field_width;
  }
  ndig = __print_fmt.precision + 1;
#if defined(__ENCORE__) || defined(__ZNEO__)
  _u_flt_info(n,&info);
#endif
#ifdef __ACCLAIM__
  _u_flt_info(n,&info, __print_fmt.type=='f'?MAXDIGITS:ndig);
#endif

  rdig = ndig;
  if ((__print_fmt.type == 'f') && (info.exp > 0))
    rdig += info.exp;
  _u_flt_rnd(&info, rdig);	
  exp = info.exp;
  if ((__print_fmt.type == 'f') && (exp > 0))
    ndig += exp;		// May be <0.
 
  if (info.flags & FLT_INFO_SIGN)
    e = '-';
  else if (__print_fmt.flags & FMT_FLAG_PLUS)
    e = '+';
  else if (__print_fmt.flags & FMT_FLAG_SPACE)
    e = ' ';
  else
   e = '\0';
  if (__print_fmt.flags & FMT_FLAG_PAD_ZERO)
    __print_fmt.print_leading_char = e;
  else if (e)
    *(s++) = e;

  if (info.flags & FLT_INFO_INF)
  {
    /* This is infinity (+ or -). */
    if (__print_fmt.flags & FMT_FLAG_UPPERCASE)
      STRCPY(s,"INF");
    else
      STRCPY(s,"inf");
    goto out;
  }

  if (info.flags & FLT_INFO_NAN)
  {
    /* This is not a number (+ or -). */
    if (__print_fmt.flags & FMT_FLAG_UPPERCASE)
      STRCPY(s,"NAN");
    else
      STRCPY(s,"nan");
    goto out;
  }

  if (__print_fmt.type == 'e')
    s = write_e_digits(s, exp, ndig, &info);
  if (__print_fmt.type == 'f')
    s = write_f_digits(PRNT_FMT_ARG FLT_DAT_ARG  s, exp, ndig, &info);

  /* If g format and not #, strip of trailing zeros. */
  if (__print_fmt.flags & FMT_FLAG_STRIP)
  {
    __flt_data.pad_post_fract = 0;
    while (s[-1] == '0')	/* strip off trailing zero's */
      --s;
	if (s[-1] == '.')
	  __flt_data.pad_pre_fract = 0;
  }
  /* Strip off the trailing decimal point, unless prevented by #. */
  if (s[-1] == '.' && 
      ((__flt_data.pad_pre_fract+__flt_data.pad_post_fract) == 0) &&
      !(__print_fmt.flags & FMT_FLAG_POUND))
    --s;

  if (__print_fmt.type == 'e')
  {
    e = __print_fmt.flags & FMT_FLAG_UPPERCASE ? 'E' : 'e';
    s = write_exponent(s, e, exp);
  }

  *s = '\0';
out:
  __fprint_send(PRNT_FMT_ARG FLT_DAT_ARG  print_buff);
}
