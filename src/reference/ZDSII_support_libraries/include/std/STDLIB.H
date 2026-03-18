/*************************************************
 *  Copyright (C) 1999-2006 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/


#pragma once // Include this file only once
#ifndef STDLIB_H
#define STDLIB_H
#include <zconst.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

typedef int onexit_t;

#ifndef WCHAR_T_DEFINED
#define WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#endif

typedef struct {
  int quot;
  int rem;
} div_t;

typedef struct {
  long quot;
  long rem;
} ldiv_t;


extern double _huge_val;

#define EDOM	4		/* domain error */
#define ERANGE	5		/* range error	*/
#define HUGE_VAL _huge_val	/* overflow error */

#define RAND_MAX 32767	/* maximum value returned by rand() */

#ifndef SIZE_T_DEFINED
#define SIZE_T_DEFINED
typedef unsigned int size_t;
#endif

#define NULL	(void *)0

void * calloc(size_t nmemb,size_t size);
void near * n_calloc(size_t nmemb, size_t size);
void far * f_calloc(size_t nmemb, size_t size);
#ifdef _PG_E_ENABLED
void pageE * e_calloc(size_t nmemb, size_t size);
#endif

void free(void * ptr);
void n_free(void near * ptr);
void f_free(void far * ptr);
#ifdef _PG_E_ENABLED
void e_free(void pageE * ptr);
#endif

void * malloc(size_t size);
#if defined(__MODEL__)
  #if __MODEL__ == 0
    #define malloc n_malloc
    #define free   n_free
  #else
    #define malloc f_malloc
    #define free   f_free
  #endif
#endif

void near * n_malloc(size_t size);
void far * f_malloc(size_t size);
#ifdef _PG_E_ENABLED
void pageE * e_malloc(size_t size);
#endif

void * realloc(void * ptr,size_t size);
void near * n_realloc(void near * ptr, size_t size);
void far * f_realloc(void far * ptr, size_t size);
#ifdef _PG_E_ENABLED
void pageE * e_realloc(void pageE * ptr, size_t size);
#endif
#if __MODEL__ == 0
#define realloc n_realloc
#else
#define realloc f_realloc
#endif

double atof(__CONST__ char * nptr);
double n_atof(__CONST__ char near * ptr);
double f_atof(__CONST__ char far * ptr);
#ifdef _PG_E_ENABLED
double e_atof(__CONST__ char pageE * ptr);
#endif

int atoi(__CONST__ char * nptr);
int n_atoi(__CONST__ char near * ptr);
int f_atoi(__CONST__ char far * ptr);
#ifdef _PG_E_ENABLED
int e_atoi(__CONST__ char pageE * ptr);
#endif
#if __MODEL__ == 0
#define atoi n_atoi
#else
#define atoi f_atoi
#endif

long atol(__CONST__ char * nptr);
long n_atol(__CONST__ char near * ptr);
long f_atol(__CONST__ char far * ptr);
#ifdef _PG_E_ENABLED
long e_atol(__CONST__ char pageE * ptr);
#endif
#if __MODEL__ == 0
#define atol n_atol
#else
#define atol f_atol
#endif

// Convert an integer to a decimal string and return a pointer to the result
// ZiLOG extension, provided for use in the assert macro
// but available for general use
char *itod(int);
near char *n_itod(int);
far char *f_itod(int);
#ifdef _PG_E_ENABLED
pageE char *e_itod(int);
#endif
#if __MODEL__ == 0
#define itod n_itod
#else
#define itod f_itod
#endif

double strtod(__CONST__ char * nptr,char ** endptr);
double n_strtod(__CONST__ char near * ptr, char near * * endptr);
double f_strtod(__CONST__ char far * ptr, char far * * endptr);
#ifdef _PG_E_ENABLED
double e_strtod(__CONST__ char pageE * ptr, char pageE * * endptr);
#endif
#if __MODEL__ == 0
#define strtod n_strtod
#else
#define strtod f_strtod
#endif

long strtol(__CONST__ char * nptr,char ** endptr,int base);
long n_strtol(__CONST__ char near * ptr, char near * * endptr, int base);
long f_strtol(__CONST__ char far * ptr, char far * * endptr, int base);
#ifdef _PG_E_ENABLED
long e_strtol(__CONST__ char pageE * ptr, char pageE * * endptr, int base);
#endif
#if __MODEL__ == 0
#define strtol n_strtol
#else
#define strtol f_strtol
#endif

unsigned long strtoul(__CONST__ char * nptr,char ** endptr,int base);
unsigned long n_strtoul(__CONST__ char near * ptr, char near * * endptr, int base);
unsigned long f_strtoul(__CONST__ char far * ptr, char far * * endptr, int base);
#ifdef _PG_E_ENABLED
unsigned long e_strtoul(__CONST__ char pageE * ptr, char pageE * * endptr, int base);
#endif
#if __MODEL__ == 0
#define strtoul n_strtoul
#else
#define strtoul f_strtoul
#endif

int rand(void);
void srand(unsigned int seed);
void exit(int status);
void abort(void);

void * bsearch(__CONST__ void * key, __CONST__ void * base, 
	size_t nmemb, size_t size, 
	reentrant int (*compar)(__CONST__ void * , __CONST__ void * ));
void near * n_n_bsearch(__CONST__ void near * key, __CONST__ void near * base, 
	size_t nmemb, size_t size, 
	reentrant int (*compar)(__CONST__ void near * , __CONST__ void near * ));
void far * n_f_bsearch(__CONST__ void near * key, __CONST__ void far * base, 
	size_t nmemb, size_t size, 
	reentrant int (*compar)(__CONST__ void near * , __CONST__ void far * ));
void rom * n_r_bsearch(__CONST__ void near * key, __CONST__ void rom * base, 
	size_t nmemb, size_t size, 
	reentrant int (*compar)(__CONST__ void near * , __CONST__ void rom * ));
void near * f_n_bsearch(__CONST__ void far * key, __CONST__ void near * base, 
	size_t nmemb, size_t size, 
	reentrant int (*compar)(__CONST__ void far * , __CONST__ void near * ));
void far * f_f_bsearch(__CONST__ void far * key, __CONST__ void far * base, 
	size_t nmemb, size_t size, 
	reentrant int (*compar)(__CONST__ void far * , __CONST__ void far * ));
void rom * f_r_bsearch(__CONST__ void far * key, __CONST__ void rom * base, 
	size_t nmemb, size_t size, 
	reentrant int (*compar)(__CONST__ void far * , __CONST__ void rom * ));
#ifdef _PG_E_ENABLED
void pageE * n_e_bsearch(__CONST__ void near * key, __CONST__ void pageE * base, 
	size_t nmemb, size_t size, 
	reentrant int (*compar)(__CONST__ void near * , __CONST__ void pageE * ));
void pageE * f_e_bsearch(__CONST__ void far * key, __CONST__ void pageE * base, 
	size_t nmemb, size_t size, 
	reentrant int (*compar)(__CONST__ void far * , __CONST__ void pageE * ));
void near * e_n_bsearch(__CONST__ void pageE * key, __CONST__ void near * base, 
	size_t nmemb, size_t size, 
	reentrant int (*compar)(__CONST__ void pageE * , __CONST__ void near * ));
void far * e_f_bsearch(__CONST__ void pageE * key, __CONST__ void far * base, 
	size_t nmemb, size_t size, 
	reentrant int (*compar)(__CONST__ void pageE * , __CONST__ void far * ));
void pageE * e_e_bsearch(__CONST__ void pageE * key, __CONST__ void pageE * base, 
	size_t nmemb, size_t size, 
	reentrant int (*compar)(__CONST__ void pageE * , __CONST__ void pageE * ));
void rom * e_r_bsearch(__CONST__ void pageE * key, __CONST__ void rom * base, 
	size_t nmemb, size_t size, 
	reentrant int (*compar)(__CONST__ void pageE * , __CONST__ void rom * ));
#endif
#if __MODEL__ == 0
#define bsearch n_n_bsearch
#else
#define bsearch f_f_bsearch
#endif

void qsort(void * base,size_t nmemb,size_t size, 
	reentrant int (*compar)(__CONST__ void * ,__CONST__ void * ));
void n_qsort(void near * base,size_t nmemb,size_t size, 
	reentrant int (*compar)(__CONST__ void near * ,__CONST__ void near * ));
void f_qsort(void far * base,size_t nmemb,size_t size, 
	reentrant int (*compar)(__CONST__ void far * ,__CONST__ void far * ));
#ifdef _PG_E_ENABLED
void e_qsort(void pageE * base,size_t nmemb,size_t size, 
	reentrant int (*compar)(__CONST__ void pageE * ,__CONST__ void pageE * ));
#endif
#if __MODEL__ == 0
#define qsort n_qsort
#else
#define qsort f_qsort
#endif

int abs(int j);
div_t div(int numer,int denom);
long labs(long j);
ldiv_t ldiv(long numer, long denom);

#endif
