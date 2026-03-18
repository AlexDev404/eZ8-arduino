/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/
#include <stdio.h>

/* Send a character to the printf/sprintf destination                      */
/* The compiler may generate direct calls to this to bypass the runtime    */
/* parsing of printf formats.                                              */

PF_REENTRANT void __print_putch(PRINT_FMT_ARG char ch)
{
   if (__print_fmt.dest == NULL)
       putch(ch);
   else
       *__print_fmt.dest++ = ch;

   __print_fmt.print_len++;
}
