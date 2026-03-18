/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                STRSPN.C  built from template file STRSPN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef strspn
size_t strspn(__CONST__ char  * s1,__CONST__ char  * s2)
{
  __CONST__ char  * p = s1;

  while (*p) {
    if (!strchr(s2,*p))
      return(p - s1);
    ++p;
  }
  return(p - s1);
}

