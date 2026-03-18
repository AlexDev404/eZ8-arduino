/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

/*
	floating-point arctangent

	atan returns the value of the arctangent of its
	argument in the range [-pi/2,pi/2].

	there are no error returns.

*/
 

/*
	atan makes its argument positive and
	calls the inner routine satan.
*/

double atan(double arg)
{
	double satan(double);

	if(arg>0)
		return(satan(arg));
	else
		return(-satan(-arg));
}

