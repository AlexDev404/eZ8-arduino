OBSOLETE
/*************************************************
 *  Copyright (C) 1999-2007 by  ZiLOG, Inc.
 *  All Rights Reserved
 *************************************************/
#include <format.h>

/* Send a character to the sprintf destination                             */
far char * __f_print_out;
reentrant void __print_f_sputch(char ch)
{
  *__f_print_out++ = ch;
}
