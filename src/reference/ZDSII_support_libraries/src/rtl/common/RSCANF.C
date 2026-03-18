/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RSCANF.C  built from template file SCANF.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <format.h>
#include <stdarg.h>
#include <stdio.h>

/*************************************************
*
* scanf - scan from stdin
*
* Inputs:
*	fmt - format string
*	args - argument list
*
* Returns:
*	Number of characters transmitted, or
*	-1 if an error occured.
*
*************************************************/
#undef r_scanf
int r_scanf(__CONST__ char rom * fmt,...)
{
  va_list ap;
  va_start(ap,fmt);
  /* The space associated with the first argument does not matter. */
  return(_u_n_r_scan(NULL,fmt,ap));
}

