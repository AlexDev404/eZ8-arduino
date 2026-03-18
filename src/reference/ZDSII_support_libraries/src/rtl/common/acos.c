/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

/*
	asin(arg) and acos(arg) return the arcsin, arccos,
	respectively of their arguments.
*/

#include	<errno.h>
#include	<math.h>

#define pio2  1.57079632679490

double acos(double arg)
{

	if((arg > 1.) || (arg < -1.)){
		errno = EDOM;
		return(0.);
	}

	return(pio2 - asin(arg));
}
