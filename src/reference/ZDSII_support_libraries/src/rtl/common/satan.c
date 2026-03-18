/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <math.h>

/*
	satan reduces its argument (known to be positive)
	to the range [0,0.414...] and calls xatan.

	
*/

static double	xatan(double);

#define sq2p1	2.41421356237309e0
#define sq2m1	0.414213562373095e0
#define pio2	1.57079632679489e0
#define pio4	0.785398163397448e0

double satan(double arg)
{

	if(arg < sq2m1)
		return(xatan(arg));
	else if(arg > sq2p1)
		return(pio2 - xatan(1.0/arg));
	else
		return(pio4 + xatan((arg-1.0)/(arg+1.0)));
}

/*
	xatan evaluates a series valid in the
	range [-0.414...,+0.414...].

	coefficients are #5077 from Hart & Cheney. (19.56D)
*/

#define p4	0.161536412982230e2
#define p3	0.268425481955040e3
#define p2	0.115302935154049e4
#define p1	0.178040631643320e4
#define p0	0.896785974036639e3
static rom double p_coeff[] = {p4, p3, p2, p1, p0, 0.0};

#define q4	0.589569705084446e2
#define q3	0.536265374031215e3
#define q2	0.166678381488163e4
#define q1	0.207933497444541e4
#define q0	0.896785974036639e3
static rom double q_coeff[] = {1.0, q4, q3, q2, q1, q0, 0.0};

// From xcoef.c
double expand_coef(rom double *coeff, double argsq);


static double xatan(double arg)
{
	double argsq;
	double value;

	argsq = arg*arg;
	value = expand_coef(p_coeff, argsq);
	value /= expand_coef(q_coeff, argsq);
	return(value*arg);
}
