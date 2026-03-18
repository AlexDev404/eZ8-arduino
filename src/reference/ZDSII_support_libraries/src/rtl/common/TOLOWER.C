/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <ctype.h>

int tolower(int c)
{
  return(isupper(c)?c+' ':c);
}
