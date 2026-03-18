/*************************************************
 *  Copyright (C) 1999-2013 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/
#include <string.h>
#include <format.h>

/* Clear out fields in a print_fmt.  The print_type, print_len, and 
 * destination/putch union are not modified.
 */


PF_REENTRANT void __clr_print_fmt(PRINT_FMT_ARG0)
{
#ifndef __REENTRANT_PRINTFS__
#undef memset
#define memset f_memset
#endif
  memset(&__print_fmt, 0, (size_t)&((struct fmt_type*)NULL)->dest);
}
