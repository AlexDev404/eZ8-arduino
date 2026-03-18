/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FPUTS.C  built from template file PUTS.TPL
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
#undef f_puts
int f_puts(__CONST__ char far * str)
{
  for(;*str;++str)
    putch(*str);
  putch('\n');
  putch('\r');
  return(0);
}

