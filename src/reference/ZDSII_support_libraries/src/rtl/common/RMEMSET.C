/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RMEMSET.C  built from template file MEMSET.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>
#undef r_memset

void rom * r_memset(void rom * s, int c, size_t n)
{
  unsigned char rom * p = s;

  for (;n;--n)
    *p++ = c;
  return(s);
}

