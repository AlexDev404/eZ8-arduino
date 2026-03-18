/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RPUTS.C  built from template file PUTS.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <sio.h>

/*************************************************
*
* puts - put a string to stdout
*
* Inputs:
*	string - address of string
*
* Returns:
*	Non-zero if an error occurs, else zero
*
*************************************************/
#undef r_puts
int r_puts(__CONST__ char rom * str)
{
  for(;*str;++str)
    putch(*str);
  putch('\n');
  putch('\r');
  return(0);
}

