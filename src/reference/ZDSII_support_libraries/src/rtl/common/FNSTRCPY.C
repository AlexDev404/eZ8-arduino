/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FNSTRCPY.C  built from template file STRCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_n_strcpy
char far * f_n_strcpy(char far * d, __CONST__ char near * s)
{
  char far * cp;
  char far * pd = d;
  __CONST__ char near * ps = s;

  cp = d;
  while(*pd++ = *ps++);
  return(cp);
}

