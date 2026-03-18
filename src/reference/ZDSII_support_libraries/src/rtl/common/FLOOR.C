/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <math.h>

double floor(double d)
{
	double fraction;

	if (d<0.0) {
		d = -d;
		fraction = modf(d, (double *)&d);
		if (fraction != 0.0)
			d += 1;
		d = -d;
	} else {
		fraction = modf(d, (double *)&d);
	}
	return(d);
}

