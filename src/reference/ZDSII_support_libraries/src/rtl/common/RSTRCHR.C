/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RSTRCHR.C  built from template file STRCHR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef r_strchr
char rom * r_strchr(__CONST__ char rom * s, int c)
{
  for(;*s;++s)
    if (*s == c)
      return(s);
  if (*s == c)
    return((char rom*)s);
  return(0);
}

