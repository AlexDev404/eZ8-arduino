/*************************************************
 *  Copyright (C) 1999-2011 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#pragma once // Include this file only once
#ifndef LIMITS_H
#define LIMITS_H

#define CHAR_BIT       8            /* number of bits in byte       */
#define SCHAR_MAX      127          /* max value for signed char    */
#define SCHAR_MIN     (-127-1)      /* min value for signed char    */
#define UCHAR_MAX      0xFFu        /* max value for unsigned char  */
#ifdef __UNSIGNED_CHARS__
#define CHAR_MAX       UCHAR_MAX    /* max value for char           */
#define CHAR_MIN       0            /* Min value for char           */
#else
#define CHAR_MAX       SCHAR_MAX    /* max value for char           */
#define CHAR_MIN       SCHAR_MIN    /* Min value for char           */
#endif

#define SHRT_MAX       32767        /* max value for short int      */
#define SHRT_MIN      (-32767-1)    /* min value for short int      */
#define USHRT_MAX      0xFFFFu      /* max value for unsigned short */

#define INT_MAX        32767        /* max value for int            */
#define INT_MIN       (-32767-1)    /* min value for int            */
#define UINT_MAX       0xFFFFu      /* max value for unsigned int   */

#define LONG_MAX       2147483647L  /* max value for long int       */
#define LONG_MIN      (-2147483647L-1) /* min value for long int    */
#define ULONG_MAX      4294967295uL /* max value for unsigned long  */
#define MB_LEN_MAX     1            /* max multibyte char length    */

#endif
