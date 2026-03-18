/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

/*
	C program for floating point sin/cos.
	Calls modf.
	There are no error exits.
	Coefficients are #3370 from Hart & Cheney (18.80D).
*/
#include <math.h>

double cos(double arg)
{
	double sinus(double,int);

	if(arg<0)
		arg = -arg;
	return(sinus(arg, 1));
}

