/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NESSCANF.C  built from template file SSCANF.TPL
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
#undef n_e_sscanf
int n_e_sscanf(__CONST__ char near * string,__CONST__ char pageE * fmt,...)
{
  va_list ap;
  va_start(ap,fmt);
  return(_u_n_e_scan(string,fmt,ap));
}

