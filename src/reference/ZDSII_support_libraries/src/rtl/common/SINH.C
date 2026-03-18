/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

/*
	sinh(arg) returns the hyperbolic sine of its floating-
	point argument.

	The exponential function is called for arguments
	greater in magnitude than 0.5.

	A series is used for arguments smaller in magnitude than 0.5.
	The coefficients are #2029 from Hart & Cheney. (20.36D)

*/

#include <math.h>

#define p0  -0.630767364049772e+6
#define p1  -0.899127202203951e+5
#define p2  -0.289421135598956e+4
#define p3  -0.263056321339750e+2
static rom double p_coeff[] = {p3, p2, p1, p0, 0.0};

#define q0  -0.630767364049772e+6
#define q1  0.152151737879002e+5
#define q2  -0.173678953558234e+3
static rom double q_coeff[] = {1.0, q2, q1, q0, 0.0};

// From xcoef.c
double expand_coef(rom double *coeff, double x);

double sinh(double arg)
{
	double temp, argsq;
	register int sign;

	sign = 1;
	if(arg < 0) {
		arg = - arg;
		sign = -1;
	}

	if(arg > 21.) {
		temp = exp(arg)/2;
		if (sign>0)
			return(temp);
		else
			return(-temp);
	}

	if(arg > 0.5) {
		return(sign*(exp(arg) - exp(-arg))/2);
	}

	argsq = arg*arg;

	temp = expand_coef(p_coeff, argsq);
	temp /= expand_coef(q_coeff, argsq);
	temp *= arg;

	if (sign < 0)
	  temp = -temp;
	return temp;
}
