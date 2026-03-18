/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RFSTRCPY.C  built from template file STRCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef r_f_strcpy
char rom * r_f_strcpy(char rom * d, __CONST__ char far * s)
{
  char rom * cp;
  char rom * pd = d;
  __CONST__ char far * ps = s;

  cp = d;
  while(*pd++ = *ps++);
  return(cp);
}

