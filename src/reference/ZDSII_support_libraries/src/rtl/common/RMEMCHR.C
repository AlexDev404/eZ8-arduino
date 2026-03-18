/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RMEMCHR.C  built from template file MEMCHR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

/* Define NULL to the right type */
#undef NULL
#define NULL ((void rom *)0)

#undef r_memchr
void rom * r_memchr(__CONST__ void rom * s, int c, size_t n)
{
  register unsigned char c2 = c;
  register unsigned char rom * p = s;

  for (;n;--n,++p)
    if (*p == c2)
      return(p);
  return (NULL);
}


