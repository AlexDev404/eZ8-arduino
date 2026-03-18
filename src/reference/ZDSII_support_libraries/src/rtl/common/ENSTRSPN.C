/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                ENSTRSPN.C  built from template file STRSPN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef e_n_strspn
size_t e_n_strspn(__CONST__ char pageE * s1,__CONST__ char near * s2)
{
  __CONST__ char pageE * p = s1;

  while (*p) {
    if (!n_strchr(s2,*p))
      return(p - s1);
    ++p;
  }
  return(p - s1);
}

