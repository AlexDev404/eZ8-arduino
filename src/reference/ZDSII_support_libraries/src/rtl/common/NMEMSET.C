/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NMEMSET.C  built from template file MEMSET.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>
#undef n_memset

PF_REENTRANT void near * n_memset(void near * s, int c, size_t n)
{
  unsigned char near * p = s;

  for (;n;--n)
    *p++ = c;
  return(s);
}

