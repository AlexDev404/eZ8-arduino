/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                EFSTRNCPY.C  built from template file STRNCPY.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef e_f_strncpy
char pageE * e_f_strncpy(char pageE * s1,__CONST__ char far * s2,size_t n)
{
  register size_t i;
  char pageE * t = s1;

  for (i=0;i<n && *s2;++i)
    *(s1++) = *(s2++);
  for (;i<n;++i)
    *(s1++) = '\0';
  return(t);
}

