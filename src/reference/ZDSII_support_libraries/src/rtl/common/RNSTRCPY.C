/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RNSTRCPY.C  built from template file STRCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef r_n_strcpy
char rom * r_n_strcpy(char rom * d, __CONST__ char near * s)
{
  char rom * cp;
  char rom * pd = d;
  __CONST__ char near * ps = s;

  cp = d;
  while(*pd++ = *ps++);
  return(cp);
}

