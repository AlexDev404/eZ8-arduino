/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                ESTRCHR.C  built from template file STRCHR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef e_strchr
char pageE * e_strchr(__CONST__ char pageE * s, int c)
{
  for(;*s;++s)
    if (*s == c)
      return(s);
  if (*s == c)
    return((char pageE*)s);
  return(0);
}

