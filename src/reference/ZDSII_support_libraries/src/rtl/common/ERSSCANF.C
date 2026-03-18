/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                ERSSCANF.C  built from template file SSCANF.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <format.h>
#include <stdarg.h>
#include <stddef.h>

/*************************************************
*
* sscanf - scan from a string
*
* Inputs:
*	string - string to print to
*	fmt - format string
*	args - argument list
*
* Returns:
*	Number of characters transmitted, or
*	-1 if an error occured.
*
*************************************************/
#undef e_r_sscanf
int e_r_sscanf(__CONST__ char pageE * string,__CONST__ char rom * fmt,...)
{
  va_list ap;
  va_start(ap,fmt);
  return(_u_e_r_scan(string,fmt,ap));
}

