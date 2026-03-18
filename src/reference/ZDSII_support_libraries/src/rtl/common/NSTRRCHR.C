/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NSTRRCHR.C  built from template file STRRCHR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef n_strrchr
char near * n_strrchr(__CONST__ char near * s, int c)
{
  register char near * p = s;

  while (*p) ++p; /* Find end of s */
  for ( ; p >= s; --p)
    if (*p == c)
      return((char near*) p);
  return(NULL);
}

