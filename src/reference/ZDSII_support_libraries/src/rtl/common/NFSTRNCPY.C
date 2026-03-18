/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NFSTRNCPY.C  built from template file STRNCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef n_f_strncpy
char near * n_f_strncpy(char near * s1,__CONST__ char far * s2,size_t n)
{
  register size_t i;
  char near * t = s1;

  for (i=0;i<n && *s2;++i)
    *(s1++) = *(s2++);
  for (;i<n;++i)
    *(s1++) = '\0';
  return(t);
}

