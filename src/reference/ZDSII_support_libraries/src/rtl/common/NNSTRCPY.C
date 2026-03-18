/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NNSTRCPY.C  built from template file STRCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef n_n_strcpy
char near * n_n_strcpy(char near * d, __CONST__ char near * s)
{
  char near * cp;
  char near * pd = d;
  __CONST__ char near * ps = s;

  cp = d;
  while(*pd++ = *ps++);
  return(cp);
}

