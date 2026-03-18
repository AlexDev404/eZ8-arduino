/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RESTRCPY.C  built from template file STRCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef r_e_strcpy
char rom * r_e_strcpy(char rom * d, __CONST__ char pageE * s)
{
  char rom * cp;
  char rom * pd = d;
  __CONST__ char pageE * ps = s;

  cp = d;
  while(*pd++ = *ps++);
  return(cp);
}

