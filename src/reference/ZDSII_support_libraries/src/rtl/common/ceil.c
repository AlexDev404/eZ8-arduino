/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <math.h>

double ceil(double d)
{
	return(-floor(-d));
}
