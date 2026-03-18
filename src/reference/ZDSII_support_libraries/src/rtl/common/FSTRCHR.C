/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FSTRCHR.C  built from template file STRCHR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_strchr
char far * f_strchr(__CONST__ char far * s, int c)
{
  for(;*s;++s)
    if (*s == c)
      return(s);
  if (*s == c)
    return((char far*)s);
  return(0);
}

