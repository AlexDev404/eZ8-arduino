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


#define twoopi	  0.636619772367581
#define p0	  0.135788409787738e8
#define p1	 -0.494290810090284e7
#define p2	  0.440103053537527e6
#define p3	 -0.138472724998245e5
#define p4	  0.145968840666577e3
static rom double p_coeff[] = {p4, p3, p2, p1, p0, 0.0};

#define q0	  0.864455865292253e7
#define q1	  0.408179225234330e6
#define q2	  0.946309610153821e4
#define q3	  0.132653490878614e3
static rom double q_coeff[] = {1.0, q3, q2, q1, q0, 0.0};

double expand_coef(rom double *coeff, double x);
 
double sinus(double arg, int quad)
{
	double e, f;
	int k;
	double ysq;
	double x,y;
	double value, value1;

	x = arg;
	if(x<0) {
		x = -x;
		quad = quad + 2;
	}
	x = x*twoopi;	/*underflow?*/
	if(x>32764){
		y = modf(x,&e);
		e = e + quad;
		modf(0.25*e,&f);
		quad = e - 4*f;
	}else{
		k = x;
		y = x - k;
		quad = (quad + k) & 03;
	}
	if (quad & 01)
		y = 1-y;
	if(quad > 1)
		y = -y;

	ysq = y*y;
	value = expand_coef(p_coeff, ysq)*y;
	value1 = expand_coef(q_coeff, ysq);
	return(value/value1);
}
