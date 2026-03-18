/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                STRPBRK.C  built from template file STRPBRK.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef strpbrk
char  * strpbrk(__CONST__ char  * s1,__CONST__  char  * s2)
{
  while (*s1) {
    if (strchr(s2,*s1))
      return(s1);
    ++s1;
  }
  return(0);
}

