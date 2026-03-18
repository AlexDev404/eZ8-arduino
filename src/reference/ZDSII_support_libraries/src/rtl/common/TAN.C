/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

/*
	floating point tangent

	A series is used after range reduction.
	Coefficients are #4285 from Hart & Cheney. (19.74D)
*/

#include <errno.h>
#include <math.h>

#define invpi 	1.27323954473516
#define p0 	-0.130682026475483e+5
#define p1	0.105597090171495e+4
#define p2	-0.155068565348327e+2
#define p3	0.342255438724100e-1
#define p4	0.338663864267717e-4
static rom double p_coeff[] = {p4, p3, p2, p1, p0, 0.0};

#define q0	-0.166389523894712e+5
#define q1	0.476575136291648e+4
#define q2	-0.155503316403171e+3
static rom double q_coeff[] = {1.0, q2, q1, q0, 0.0};

// From xcoef.c
double expand_coef(rom double *coeff, double x);

double tan(double arg)
{
	double sign, temp, e, x, xsq;
	int flag, i;

	flag = 0;
	sign = 1.;
	if(arg < 0.){
		arg = -arg;
		sign = -1.;
	}
	arg = arg*invpi;   /*overflow?*/
	x = modf(arg,(double *)&e);
	i = e;
	switch(i%4) {
	case 1:
		x = 1. - x;
		flag = 1;
		break;

	case 2:
		sign = - sign;
		flag = 1;
		break;

	case 3:
		x = 1. - x;
		sign = - sign;
		break;

	case 0:
		break;
	}

	xsq = x*x;
	temp = expand_coef(p_coeff, xsq);
	temp /= expand_coef(q_coeff, xsq);
	temp *= x;

	if(flag == 1) {
		if(temp == 0.) {
			errno = ERANGE;
			if (sign>0)
				return(HUGE_VAL);
			return(-HUGE_VAL);
		}
		temp = 1./temp;
	}
	if (sign < 0)
	  temp = -temp;

	return(temp);
}
