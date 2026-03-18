/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RFSTRPBRK.C  built from template file STRPBRK.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef r_f_strpbrk
char rom * r_f_strpbrk(__CONST__ char rom * s1,__CONST__  char far * s2)
{
  while (*s1) {
    if (f_strchr(s2,*s1))
      return(s1);
    ++s1;
  }
  return(0);
}

