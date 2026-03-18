/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RSTRRCHR.C  built from template file STRRCHR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef r_strrchr
char rom * r_strrchr(__CONST__ char rom * s, int c)
{
  register char rom * p = s;

  while (*p) ++p; /* Find end of s */
  for ( ; p >= s; --p)
    if (*p == c)
      return((char rom*) p);
  return(NULL);
}

