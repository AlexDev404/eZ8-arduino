OBSOLETE
/*************************************************
 *  Copyright (C) 1999-2007 by  ZiLOG, Inc.
 *  All Rights Reserved
 *************************************************/
#include <format.h>

/* Send a character to the sprintf destination                             */
near char * __n_print_out;
reentrant void __print_n_sputch(char ch)
{
  *__n_print_out++ = ch;
}
