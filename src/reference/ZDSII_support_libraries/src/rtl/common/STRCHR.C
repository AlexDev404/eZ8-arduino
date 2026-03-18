/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                STRCHR.C  built from template file STRCHR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef strchr
char  * strchr(__CONST__ char  * s, int c)
{
  for(;*s;++s)
    if (*s == c)
      return(s);
  if (*s == c)
    return((char *)s);
  return(0);
}

