/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FNSTRCSPN.C  built from template file STRCSPN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_n_strcspn
size_t f_n_strcspn( __CONST__ char far * s1, __CONST__ char near * s2)
{
   __CONST__ char far * p = s1;

  while (*p) {
    if (n_strchr(s2,*p))
      return(p - s1);
    ++p;
  }
  return(p-s1);
}

