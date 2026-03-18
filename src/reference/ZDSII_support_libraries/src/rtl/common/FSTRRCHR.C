/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FSTRRCHR.C  built from template file STRRCHR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_strrchr
char far * f_strrchr(__CONST__ char far * s, int c)
{
  register char far * p = s;

  while (*p) ++p; /* Find end of s */
  for ( ; p >= s; --p)
    if (*p == c)
      return((char far*) p);
  return(NULL);
}

