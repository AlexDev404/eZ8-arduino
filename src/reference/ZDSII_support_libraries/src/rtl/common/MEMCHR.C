/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                MEMCHR.C  built from template file MEMCHR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

/* Define NULL to the right type */
#undef NULL
#define NULL ((void  *)0)

#undef memchr
void  * memchr(__CONST__ void  * s, int c, size_t n)
{
  register unsigned char c2 = c;
  register unsigned char  * p = s;

  for (;n;--n,++p)
    if (*p == c2)
      return(p);
  return (NULL);
}


