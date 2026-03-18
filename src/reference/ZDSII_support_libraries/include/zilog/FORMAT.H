/*************************************************
 *  Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *  All Rights Reserved
 *************************************************
 *
 * This header is for internal use only. It is NOT
 * an ANSI standard header file.						
 *
 *************************************************/

#pragma once // Include this file only once
#ifndef FORMAT_H
#define FORMAT_H

#include <zconst.h>
#include <stdarg.h>

/* Note: 24 bits times log(2) is 7.224 decimal digits.
   We only need 14 if and when we support doubles. */
#define MAXDIGITS 10
#define MINEXP -4
#define DEFAULT_PRECISION 6


/*  Sizes allowed for various data */
/*  For small model, we must restrict the allowed input */
#if (defined(__MODEL__) && (__MODEL__ == 0)) && !defined(__ACCLAIM__)
#define FLT_CHARS 20  // Only need FLT_DIG+7, but allow for extra data
#define PTR_CHARS 11
#define INT_CHARS 9
#else
#define FLT_CHARS 127
#define PTR_CHARS 127
#define INT_CHARS 127
#endif

/*	structures and defines for format routines	                 */
/*      NOTE: Some fields in this structure, and the bits in flags, are  */
/*            known to the optimizer,  If you change this, check out the */
/*            code in optimizer/genprintfs.c                             */
struct fmt_type {
  char flags;		/* flags bit mask */
  char size;		/* size character h,l or L */
  char space;		/* space character N,F or R */
  char type;		/* type of argument d,i,o,u,x ... */
  char field_width;	/* field width */
  char precision;	/* precision */
  char print_leading_char;  // Initial +, -, or space for number
     /* several print helper functions end by clearing the above fields. 
      * The following need to be preserved across calls to the print
      * utilities.
      */
  far char* dest;       /* Destination for sprintf, NULL for printf */
  unsigned char print_len;
};

/* Some additional data for formatting of floating point values: */

struct flt_fmt_data
{
  unsigned char pad_whole;
  unsigned char pad_pre_fract;
  unsigned char pad_post_fract;
  char * pad_at;
};

/* Data passed between top level driver and scanning routines, not needed
 * when printf's are generated inline */
struct fmt_control_data
{
  char status;		/* status, OK, ERR, or PASS_THRU */
  char chr;		/* pass thru character */
};


struct _set_type{ char * begin; char *end; };
struct near_set_type{ char near * begin; char near *end; };
struct far_set_type{ char far * begin; char far *end; };
#ifdef _PG_E_ENABLED
struct pageE_set_type{ char pageE * begin; char far *end; };
#endif
struct rom_set_type{ char rom * begin; char rom *end; };

/* info flags */
#define FLT_INFO_SIGN	(1<<0)
#define FLT_INFO_INF	(1<<1)
#define FLT_INFO_NAN	(1<<2)


struct flt_info {
  unsigned char flags;			/* 1=sign, 2=inf, 4=nan        */
  char exp;				/* (signed) exponent (base 10) */
  unsigned char digits[MAXDIGITS];	/* max significant digits      */
};

#ifndef __REENTRANT_PRINTFS__
extern far struct fmt_type __print_fmt;
extern far struct flt_fmt_data __flt_data;
extern far struct fmt_control_data __print_ctrl;
#endif

/* Macros used in the printf code: */
/* These macros expand differently depending on whether __REENTRANT_PRINTFS__
 * is defined.  If it is, all the printf functions are reentrant, and key data
 * is passed as a parameter, otherwise functions are not declared reentrant and
 * the global data is used.
 */
#ifdef __REENTRANT_PRINTFS__
// Used in function prototypes to declare function reentrant
#define PF_REENTRANT reentrant

// Used in function prototypes to declare print_fmt argument, note final ','
#define PRINT_FMT_ARG struct fmt_type* print_fmt,

// Used in function prototypes to declare print_fmt argument as only arg
#define PRINT_FMT_ARG0 struct fmt_type* print_fmt

// Used in function call to pass print_fmt argument, note final ','
#define PRNT_FMT_ARG print_fmt,

// Used in function call to pass print_fmt argument when only arg
#define PRNT_FMT_ARG0 print_fmt

// Used in function prototypes to declare print_ctrl argument, note final ','
#define PRINT_CTRL_ARG struct fmt_control_data * print_ctrl,

// Used in function call to pass print_ctrl argument, note final ','
#define PRNT_CTRL_ARG &print_ctrl,

// Used in function prototypes to declare flt_data argument, note final ','
#define FLT_DATA_ARG struct flt_fmt_data *flt_data,

// Used in function call to pass flt_data argument, note final ','
#define FLT_DAT_ARG &flt_data,

// Used to replace accesses to global data with accesses to pointer passed as arg
#define __print_fmt (*print_fmt)
#define __print_ctrl (*print_ctrl)
#define __flt_data (*flt_data)
#else
/* Otherwise most of the above macros expand to empty space */
#define PF_REENTRANT
#define PRINT_FMT_ARG
#define PRINT_FMT_ARG0
#define PRNT_FMT_ARG
#define PRNT_FMT_ARG0
#define PRINT_CTRL_ARG
#define PRNT_CTRL_ARG
#define FLT_DATA_ARG
#define FLT_DAT_ARG
#endif

extern PF_REENTRANT void __print_send(PRINT_FMT_ARG  char* s);
extern  PF_REENTRANT void __fprint_send(PRINT_FMT_ARG  FLT_DATA_ARG  char* s);
extern PF_REENTRANT void __print_sendstring(PRINT_FMT_ARG  __CONST__ char *);
extern PF_REENTRANT void __print_putch(PRINT_FMT_ARG char ch);
extern PF_REENTRANT void __print_putromstring0(PRINT_FMT_ARG  __CONST__ char rom * sp);
extern PF_REENTRANT void __print_putromstring(PRINT_FMT_ARG  __CONST__ char rom * sp);
extern PF_REENTRANT void __print_putfarstring(PRINT_FMT_ARG  __CONST__ char far * sp);
#ifdef _PG_E_ENABLED
extern PF_REENTRANT void __print_putpageEstring(PRINT_FMT_ARG  __CONST__ char pageE * sp);
#endif
extern PF_REENTRANT void __print_putnearstring(PRINT_FMT_ARG  __CONST__ char near * sp);
#if __MODEL__ == 0
#define __print_sendstring __print_putnearstring
#else
#define __print_sendstring __print_putfarstring
#endif

extern char _u_sscan_state(char ch, char state);
extern void __uscan_put(struct fmt_type* print_fmt,  char size, unsigned long val);



extern char far _u_fmt_buf[FLT_CHARS];
extern struct flt_info far _u_fmt_info;

extern far int _u_prev_ch;
extern far char _u_isunget;
extern far int _u_len;
extern far unsigned char _u_fields;
extern far va_list _u_argp;




/* status codes */

#define FMT_OK 0
#define FMT_ERR 1
#define FMT_PASS_THRU 2

/* flags */

#define FMT_FLAG_MINUS	0x01
#define FMT_FLAG_PLUS	0x02
#define FMT_FLAG_SPACE	0x04
#define FMT_FLAG_POUND	0x08
#define FMT_FLAG_IGNORE 0x10    // scanf only.
#define FMT_FLAG_PRECISION 0x10 // Only needed for %s, as 0 is valid precision
#define FMT_FLAG_UPPERCASE 0x20	// Added.
#define FMT_FLAG_PAD_ZERO 0x40
#define FMT_FLAG_STRIP	0x80	// Output only.
#define FMT_FLAG_SET	0x80	// Input only; maybe not needed if
				// set_begin != 0 is used instead.
PF_REENTRANT void _u_ltoa(PRINT_FMT_ARG  long);
PF_REENTRANT void _u_stoa(PRINT_FMT_ARG  short);
PF_REENTRANT void _u_ultoa(PRINT_FMT_ARG  unsigned long);
PF_REENTRANT void _u_ustoa(PRINT_FMT_ARG  unsigned short);

PF_REENTRANT int _u_print(PRINT_FMT_ARG  __CONST__  char *fmt, va_list);
PF_REENTRANT int _u_n_print(PRINT_FMT_ARG  __CONST__  char near *fmt, va_list);
PF_REENTRANT int _u_f_print(PRINT_FMT_ARG  __CONST__  char far *fmt, va_list);
#ifdef _PG_E_ENABLED
PF_REENTRANT int _u_e_print(PRINT_FMT_ARG  __CONST__  char pageE *fmt, va_list);
#endif
PF_REENTRANT int _u_r_print(PRINT_FMT_ARG  __CONST__  char rom *fmt, va_list);

int _u_scan(__CONST__ char * src,__CONST__  char * fmt, va_list ap);
int _u_n_n_scan(__CONST__ char near * src,__CONST__  char near * fmt, va_list ap);
int _u_n_f_scan(__CONST__ char near * src,__CONST__  char far * fmt, va_list ap);
int _u_n_r_scan(__CONST__ char near * src,__CONST__  char rom * fmt, va_list ap);
int _u_f_n_scan(__CONST__ char far * src,__CONST__  char near * fmt, va_list ap);
int _u_f_f_scan(__CONST__ char far * src,__CONST__  char far * fmt, va_list ap);
int _u_f_r_scan(__CONST__ char far * src,__CONST__  char rom * fmt, va_list ap);
#ifdef _PG_E_ENABLED
int _u_n_e_scan(__CONST__ char near * src,__CONST__  char pageE * fmt, va_list ap);
int _u_f_e_scan(__CONST__ char far * src,__CONST__  char pageE * fmt, va_list ap);
int _u_e_n_scan(__CONST__ char pageE * src,__CONST__  char near * fmt, va_list ap);
int _u_e_f_scan(__CONST__ char pageE * src,__CONST__  char far * fmt, va_list ap);
int _u_e_e_scan(__CONST__ char pageE * src,__CONST__  char pageE * fmt, va_list ap);
int _u_e_r_scan(__CONST__ char pageE * src,__CONST__  char rom * fmt, va_list ap);
#endif
#define _u_n_scan _u_scan

PF_REENTRANT __CONST__ char * _u_pscan(PRINT_FMT_ARG PRINT_CTRL_ARG __CONST__ char * fmt, va_list *argp);
PF_REENTRANT char near * _u_n_pscan(PRINT_FMT_ARG PRINT_CTRL_ARG __CONST__ char near * fmt, va_list *argp);
PF_REENTRANT char far * _u_f_pscan(PRINT_FMT_ARG PRINT_CTRL_ARG __CONST__ char far * fmt, va_list *argp);
#ifdef _PG_E_ENABLED
PF_REENTRANT char pageE * _u_e_pscan(PRINT_FMT_ARG PRINT_CTRL_ARG __CONST__ char pageE * fmt, va_list *argp);
#endif
PF_REENTRANT char rom * _u_r_pscan(PRINT_FMT_ARG PRINT_CTRL_ARG __CONST__ char rom * fmt, va_list *argp);

PF_REENTRANT void _u_reverse(char * s);
PF_REENTRANT void _u_dtof(PRINT_FMT_ARG double);
PF_REENTRANT void _u_dtog(PRINT_FMT_ARG double);

PF_REENTRANT void __clr_print_fmt(PRINT_FMT_ARG0);

char _u_sscan_state(char ch, char state);

__CONST__ char * _u_sscan(__CONST__ char * fmt, struct fmt_type *print_fmt 
                      , struct fmt_control_data * print_ctrl
		      , struct _set_type * setp);
__CONST__ char near * _u_n_sscan(__CONST__ char near * fmt, struct fmt_type *print_fmt 
                      , struct fmt_control_data * print_ctrl
		      , struct near_set_type * setp);
__CONST__ char far * _u_f_sscan(__CONST__ char far * fmt, struct fmt_type *print_fmt
                      , struct fmt_control_data * print_ctrl
		      , struct far_set_type * setp);
#ifdef _PG_E_ENABLED
__CONST__ char pageE * _u_e_sscan(__CONST__ char pageE * fmt, struct fmt_type *print_fmt
                      , struct fmt_control_data * print_ctrl
		      , struct pageE_set_type * setp);
#endif
__CONST__ char rom * _u_r_sscan(__CONST__ char rom * fmt, struct fmt_type *print_fmt
                      , struct fmt_control_data * print_ctrl
		      , struct rom_set_type * setp);

void _u_flt_info(double,struct flt_info * );
void _u_flt_rnd(struct flt_info* ,char);

reentrant unsigned char putch( char ) ;
#endif
