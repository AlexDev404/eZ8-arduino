/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                ERSTRCMP.C  built from template file STRCMP.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef e_r_strcmp
int e_r_strcmp(register __CONST__ char pageE * s1, register __CONST__ char rom * s2)
{
  while (*s1 && *s1 == *s2)
    s1++, s2++;
  return(*s1 - *s2);
}

