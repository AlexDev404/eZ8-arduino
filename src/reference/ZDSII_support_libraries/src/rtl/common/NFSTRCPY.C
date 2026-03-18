/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NFSTRCPY.C  built from template file STRCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef n_f_strcpy
char near * n_f_strcpy(char near * d, __CONST__ char far * s)
{
  char near * cp;
  char near * pd = d;
  __CONST__ char far * ps = s;

  cp = d;
  while(*pd++ = *ps++);
  return(cp);
}

