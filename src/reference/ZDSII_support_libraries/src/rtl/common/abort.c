/*************************************************
 *  Copyright (C) 2007-2008 by  ZiLOG, Inc.
 *  All Rights Reserved
 *************************************************/

#include <stdlib.h>

/*
 *  Implement the abort function
 *    abnormal program termination
 *    Causes program termination, preferably in a way that facilitates 
 *    postmortem debugging
 *
 */


void abort(void)
{
  exit(-1);
}
