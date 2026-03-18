/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                EFSSCANF.C  built from template file SSCANF.TPL
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
#undef e_f_sscanf
int e_f_sscanf(__CONST__ char pageE * string,__CONST__ char far * fmt,...)
{
  va_list ap;
  va_start(ap,fmt);
  return(_u_e_f_scan(string,fmt,ap));
}

