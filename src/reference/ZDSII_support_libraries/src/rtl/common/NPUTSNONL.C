/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NPUTSNONL.C  built from template file PUTSNONL.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <sio.h>

/*************************************************
*
* putsNOnl - put a string to stdout (without the trailing new line)
*
* Inputs:
*	string - address of string
*
* Returns:
*	Non-zero if an error occurs, else zero
*
*************************************************/
#undef n_putsNOnl
int n_putsNOnl(__CONST__ char near * str)
{
  for(;*str;++str)
    putch(*str);
  return(0);
}

