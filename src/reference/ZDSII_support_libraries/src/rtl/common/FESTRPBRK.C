/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FESTRPBRK.C  built from template file STRPBRK.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_e_strpbrk
char far * f_e_strpbrk(__CONST__ char far * s1,__CONST__  char pageE * s2)
{
  while (*s1) {
    if (e_strchr(s2,*s1))
      return(s1);
    ++s1;
  }
  return(0);
}

