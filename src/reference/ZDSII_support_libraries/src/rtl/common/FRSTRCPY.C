/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FRSTRCPY.C  built from template file STRCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_r_strcpy
char far * f_r_strcpy(char far * d, __CONST__ char rom * s)
{
  char far * cp;
  char far * pd = d;
  __CONST__ char rom * ps = s;

  cp = d;
  while(*pd++ = *ps++);
  return(cp);
}

