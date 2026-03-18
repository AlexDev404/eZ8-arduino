/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                EMEMCHR.C  built from template file MEMCHR.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

/* Define NULL to the right type */
#undef NULL
#define NULL ((void pageE *)0)

#undef e_memchr
void pageE * e_memchr(__CONST__ void pageE * s, int c, size_t n)
{
  register unsigned char c2 = c;
  register unsigned char pageE * p = s;

  for (;n;--n,++p)
    if (*p == c2)
      return(p);
  return (NULL);
}


