OBSOLETE
 
/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/
#include <format.h>
#include <uart.h>

/* Send a character to the printf destination                      */

reentrant void __print_uputch(char ch)
{
  /* If putch returns an error, set print_len very negative, since       */
  /* caller will blindly increment it (if it cares)                   */
  if (putch(ch)!=UART_ERR_NONE)
    __print_len = -0x7fff;
}
