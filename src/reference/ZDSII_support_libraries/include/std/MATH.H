/*************************************************
 *  Copyright (C) 1999-2006 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#pragma once // Include this file only once
#ifndef MATH_H
#define MATH_H

extern double _huge_val;
#define HUGE_VAL _huge_val	/* overflow error */

double acos(double x);
double asin(double x);
double atan(double x);
double atan2(double y,double x);
double cos(double x);
double sin(double x);
double tan(double x);
double cosh(double x);
double sinh(double x);
double tanh(double x);
double exp(double x);
double ldexp(double x, int exp);
double log(double x);
double log10(double x);
double pow(double x,double y);
double sqrt(double x);
double ceil(double x);
double fabs(double x);
double floor(double x);
double fmod(double x, double y);

double frexp(double value, int * exp);
double n_frexp(double value, int near * exp);
double f_frexp(double value, int far * exp);
#ifdef _PG_E_ENABLED
double e_frexp(double value, int pageE * exp);
#endif
#if __MODEL__ == 0
#define frexp n_frexp
#else
#define frexp f_frexp
#endif

double modf(double value, double * iptr);
double n_modf(double value, double near * iptr);
double f_modf(double value, double far * iptr);
#ifdef _PG_E_ENABLED
double e_modf(double value, double pageE * iptr);
#endif
#if __MODEL__ == 0
#define modf n_modf
#else
#define modf f_modf
#endif

#endif
