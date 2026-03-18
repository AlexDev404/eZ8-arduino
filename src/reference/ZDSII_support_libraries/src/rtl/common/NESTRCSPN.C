/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NESTRCSPN.C  built from template file STRCSPN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef n_e_strcspn
size_t n_e_strcspn( __CONST__ char near * s1, __CONST__ char pageE * s2)
{
   __CONST__ char near * p = s1;

  while (*p) {
    if (e_strchr(s2,*p))
      return(p - s1);
    ++p;
  }
  return(p-s1);
}

