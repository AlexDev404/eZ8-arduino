/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                ESCANF.C  built from template file SCANF.TPL
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
#undef e_scanf
int e_scanf(__CONST__ char pageE * fmt,...)
{
  va_list ap;
  va_start(ap,fmt);
  /* The space associated with the first argument does not matter. */
  return(_u_n_e_scan(NULL,fmt,ap));
}

