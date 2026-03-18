/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

/*
	exp returns the exponential function of its
	floating-point argument.

	The coefficients are #1069 from Hart and Cheney. (22.35D)
*/

#include <errno.h>
#include <math.h>

#define	p0	0.20803843466947e7
#define	p1	0.30286971697440e5
#define	p2	0.60614853300611e2
static rom double p_coeff[] = {p2, p1, p0, 0.0};

#define	q0	0.60027203602388e7
#define	q1	0.32772515180829e6
#define	q2	0.17492876890931e4
static rom double q_coeff[] = {1.0, q2, q1, q0, 0.0};

#define	log2e	1.44269504088896
#define	sqrt2	1.41421356237310
#define	maxf	10000

// From xcoef.c
double expand_coef(rom double *coeff, double x);

double exp(double arg)
{
	double fraction;
	double temp1, temp2, xsq;
	int ent;

	if(arg == 0.)
		return(1.);
	if(arg < -maxf)
		return(0.);
	if(arg > maxf) {
		errno = ERANGE;
		return(HUGE_VAL);
	}
	arg *= log2e;
	ent = floor(arg);
	fraction = (arg-ent) + (-0.5);
	xsq = fraction*fraction;

	temp1 = expand_coef(p_coeff, xsq);
	temp1 *= fraction;
	temp2 = expand_coef(q_coeff, xsq);

	return(ldexp(sqrt2*(temp2+temp1)/(temp2-temp1), ent));
}
