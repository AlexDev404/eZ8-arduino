/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                ESTRRCHR.C  built from template file STRRCHR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef e_strrchr
char pageE * e_strrchr(__CONST__ char pageE * s, int c)
{
  register char pageE * p = s;

  while (*p) ++p; /* Find end of s */
  for ( ; p >= s; --p)
    if (*p == c)
      return((char pageE*) p);
  return(NULL);
}

