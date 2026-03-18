/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FFSTRCPY.C  built from template file STRCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_f_strcpy
char far * f_f_strcpy(char far * d, __CONST__ char far * s)
{
  char far * cp;
  char far * pd = d;
  __CONST__ char far * ps = s;

  cp = d;
  while(*pd++ = *ps++);
  return(cp);
}

