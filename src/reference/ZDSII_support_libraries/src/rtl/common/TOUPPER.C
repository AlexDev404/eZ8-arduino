/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <ctype.h>

int toupper(int c)
{
  return(islower(c)?c-' ':c);
}
