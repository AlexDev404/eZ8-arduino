/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                ENSTRCPY.C  built from template file STRCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef e_n_strcpy
char pageE * e_n_strcpy(char pageE * d, __CONST__ char near * s)
{
  char pageE * cp;
  char pageE * pd = d;
  __CONST__ char near * ps = s;

  cp = d;
  while(*pd++ = *ps++);
  return(cp);
}

