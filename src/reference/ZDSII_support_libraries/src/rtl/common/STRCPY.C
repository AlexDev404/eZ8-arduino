/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                STRCPY.C  built from template file STRCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef strcpy
char  * strcpy(char  * d, __CONST__ char  * s)
{
  char  * cp;
  char  * pd = d;
  __CONST__ char  * ps = s;

  cp = d;
  while(*pd++ = *ps++);
  return(cp);
}

