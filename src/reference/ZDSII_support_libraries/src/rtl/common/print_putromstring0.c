/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/
#include <string.h>
#include <stdlib.h>
#include <format.h>

/* Send a string from rom to the printf/sprintf destination                */
/* The compiler may generate direct calls to this to bypass the runtime    */
/* parsing of printf formats.                                              */
/*                                                                         */
/* This was formally __print_putromstring().  The name was changed when    */
/* support for the N, F, and R format modifiers was added and the support  */
/* for these called __print_putXXXstring(). This routine justs prints the  */
/* string from ROM, without consulting anything in the print_fmt.  It is   */
/* used for sending the parts of the format specification between the '%'  */
/* specifiers.                                                             */


PF_REENTRANT void __print_putromstring0(PRINT_FMT_ARG __CONST__ rom char * sp)
{
  while (*sp)
      __print_putch(PRNT_FMT_ARG *sp++);
}
