/*************************************************
 *  Copyright (C) 1999-2006 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/


#pragma once // Include this file only once
#ifndef STRING_H
#define STRING_H
#include <zconst.h>
#include <format.h> // For PF_REENTRANT macro

#ifndef SIZE_T_DEFINED
#define SIZE_T_DEFINED
typedef unsigned int size_t;
#endif

#define NULL		(void *)0

char * strcpy(char *s1,__CONST__  char *s2);
char near * n_n_strcpy(char near * s1,__CONST__ char near * s2);
char near * n_f_strcpy(char near * s1,__CONST__ char far * s2);
char near * n_r_strcpy(char near * s1,__CONST__ char rom * s2);
char far * f_n_strcpy(char far * s1,__CONST__ char near * s2);
char far * f_f_strcpy(char far * s1,__CONST__ char far * s2);
char far * f_r_strcpy(char far * s1,__CONST__ char rom * s2);
#ifdef _PG_E_ENABLED
char near * n_e_strcpy(char near * s1,__CONST__ char pageE * s2);
char far * f_e_strcpy(char far * s1,__CONST__ char pageE * s2);
char pageE * e_n_strcpy(char pageE * s1,__CONST__ char near * s2);
char pageE * e_f_strcpy(char pageE * s1,__CONST__ char far * s2);
char pageE * e_e_strcpy(char pageE * s1,__CONST__ char pageE * s2);
char pageE * e_r_strcpy(char pageE * s1,__CONST__ char rom * s2);
#endif
#if __MODEL__ == 0
#define strcpy n_n_strcpy
#else
#define strcpy f_f_strcpy
#endif

char * strncpy(char *s1,__CONST__  char *s2, size_t n);
char near * n_n_strncpy(char near *s1,__CONST__ char near *s2, size_t n);
char near * n_f_strncpy(char near *s1,__CONST__ char far *s2, size_t n);
char near * n_r_strncpy(char near *s1,__CONST__ char rom *s2, size_t n);
char far * f_n_strncpy(char far *s1,__CONST__ char near *s2, size_t n);
char far * f_f_strncpy(char far *s1,__CONST__ char far *s2, size_t n);
char far * f_r_strncpy(char far *s1,__CONST__ char rom *s2, size_t n);
#ifdef _PG_E_ENABLED
char near * n_e_strncpy(char near *s1,__CONST__ char pageE *s2, size_t n);
char far * f_e_strncpy(char far *s1,__CONST__ char pageE *s2, size_t n);
char pageE * e_n_strncpy(char pageE *s1,__CONST__ char near *s2, size_t n);
char pageE * e_f_strncpy(char pageE *s1,__CONST__ char far *s2, size_t n);
char pageE * e_e_strncpy(char pageE *s1,__CONST__ char pageE *s2, size_t n);
char pageE * e_r_strncpy(char pageE *s1,__CONST__ char rom *s2, size_t n);
#endif
#if __MODEL__ == 0
#define strncpy n_n_strncpy
#else
#define strncpy f_f_strncpy
#endif

char * strcat(char *s1, __CONST__ char *s2);
char near * n_n_strcat(char near *s1,__CONST__ char near *s2);
char near * n_f_strcat(char near *s1,__CONST__ char far *s2);
char near * n_r_strcat(char near *s1,__CONST__ char rom *s2);
char far * f_n_strcat(char far *s1,__CONST__ char near *s2);
char far * f_f_strcat(char far *s1,__CONST__ char far *s2);
char far * f_r_strcat(char far *s1,__CONST__ char rom *s2);
#ifdef _PG_E_ENABLED
char near * n_e_strcat(char near *s1,__CONST__ char pageE *s2);
char far * f_e_strcat(char far *s1,__CONST__ char pageE *s2);
char pageE * e_n_strcat(char pageE *s1,__CONST__ char near *s2);
char pageE * e_f_strcat(char pageE *s1,__CONST__ char far *s2);
char pageE * e_e_strcat(char pageE *s1,__CONST__ char pageE *s2);
char pageE * e_r_strcat(char pageE *s1,__CONST__ char rom *s2);
#endif
#if __MODEL__ == 0
#define strcat n_n_strcat
#else
#define strcat f_f_strcat
#endif

char * strncat(char *s1, __CONST__ char *s2, size_t n);
char near * n_n_strncat(char near *s1,__CONST__ char near *s2, size_t n);
char near * n_f_strncat(char near *s1,__CONST__ char far *s2, size_t n);
char near * n_r_strncat(char near *s1,__CONST__ char rom *s2, size_t n);
char far * f_n_strncat(char far *s1,__CONST__ char near *s2, size_t n);
char far * f_f_strncat(char far *s1,__CONST__ char far *s2, size_t n);
char far * f_r_strncat(char far *s1,__CONST__ char rom *s2, size_t n);
#ifdef _PG_E_ENABLED
char near * n_e_strncat(char near *s1,__CONST__ char pageE *s2, size_t n);
char far * f_e_strncat(char far *s1,__CONST__ char pageE *s2, size_t n);
char pageE * e_n_strncat(char pageE *s1,__CONST__ char near *s2, size_t n);
char pageE * e_f_strncat(char pageE *s1,__CONST__ char far *s2, size_t n);
char pageE * e_e_strncat(char pageE *s1,__CONST__ char pageE *s2, size_t n);
char pageE * e_r_strncat(char pageE *s1,__CONST__ char rom *s2, size_t n);
#endif
#if __MODEL__ == 0
#define strncat n_n_strncat
#else
#define strncat f_f_strncat
#endif

int strcmp(__CONST__ char *s1,__CONST__  char *s2);
int n_n_strcmp(__CONST__ char near *s1,__CONST__ char near *s2);
int n_f_strcmp(__CONST__ char near *s1,__CONST__ char far *s2);
int n_r_strcmp(__CONST__ char near *s1,__CONST__ char rom *s2);
int f_n_strcmp(__CONST__ char far *s1,__CONST__ char near *s2);
int f_f_strcmp(__CONST__ char far *s1,__CONST__ char far *s2);
int f_r_strcmp(__CONST__ char far *s1,__CONST__ char rom *s2);
int r_n_strcmp(__CONST__ char rom *s1,__CONST__ char near *s2);
int r_f_strcmp(__CONST__ char rom *s1,__CONST__ char far *s2);
int r_r_strcmp(__CONST__ char rom *s1,__CONST__ char rom *s2);
#ifdef _PG_E_ENABLED
int n_e_strcmp(__CONST__ char near *s1,__CONST__ char pageE *s2);
int f_e_strcmp(__CONST__ char far *s1,__CONST__ char pageE *s2);
int r_e_strcmp(__CONST__ char rom *s1,__CONST__ char pageE *s2);
int e_n_strcmp(__CONST__ char pageE *s1,__CONST__ char near *s2);
int e_f_strcmp(__CONST__ char pageE *s1,__CONST__ char far *s2);
int e_e_strcmp(__CONST__ char pageE *s1,__CONST__ char pageE *s2);
int e_r_strcmp(__CONST__ char pageE *s1,__CONST__ char rom *s2);
#endif
#if __MODEL__ == 0
#define strcmp n_n_strcmp
#else
#define strcmp f_f_strcmp
#endif

int strncmp(__CONST__ char *s1,__CONST__  char *s2, size_t n);
int n_n_strncmp(__CONST__ char near *s1,__CONST__ char near *s2, size_t n);
int n_f_strncmp(__CONST__ char near *s1,__CONST__ char far *s2, size_t n);
int n_r_strncmp(__CONST__ char near *s1,__CONST__ char rom *s2, size_t n);
int f_n_strncmp(__CONST__ char far *s1,__CONST__ char near *s2, size_t n);
int f_f_strncmp(__CONST__ char far *s1,__CONST__ char far *s2, size_t n);
int f_r_strncmp(__CONST__ char far *s1,__CONST__ char rom *s2, size_t n);
int r_n_strncmp(__CONST__ char rom *s1,__CONST__ char near *s2, size_t n);
int r_f_strncmp(__CONST__ char rom *s1,__CONST__ char far *s2, size_t n);
int r_r_strncmp(__CONST__ char rom *s1,__CONST__ char rom *s2, size_t n);
#ifdef _PG_E_ENABLED
int n_e_strncmp(__CONST__ char near *s1,__CONST__ char pageE *s2, size_t n);
int f_e_strncmp(__CONST__ char far *s1,__CONST__ char pageE *s2, size_t n);
int r_e_strncmp(__CONST__ char rom *s1,__CONST__ char pageE *s2, size_t n);
int e_n_strncmp(__CONST__ char pageE *s1,__CONST__ char near *s2, size_t n);
int e_f_strncmp(__CONST__ char pageE *s1,__CONST__ char far *s2, size_t n);
int e_e_strncmp(__CONST__ char pageE *s1,__CONST__ char pageE *s2, size_t n);
int e_r_strncmp(__CONST__ char pageE *s1,__CONST__ char rom *s2, size_t n);
#endif
#if __MODEL__ == 0
#define strncmp n_n_strncmp
#else
#define strncmp f_f_strncmp
#endif

char * strchr(__CONST__ char *s,int c);
char near * n_strchr(__CONST__ char near *s, int c);
char far * f_strchr(__CONST__ char far *s, int c);
#ifdef _PG_E_ENABLED
char pageE * e_strchr(__CONST__ char pageE *s, int c);
#endif
char rom * r_strchr(__CONST__ char rom *s, int c);
#if __MODEL__ == 0
#define strchr n_strchr
#else
#define strchr f_strchr
#endif

size_t strcspn(__CONST__ char *s1,__CONST__  char *s2);
size_t n_n_strcspn(__CONST__ char near *s1,__CONST__ char near *s2);
size_t n_f_strcspn(__CONST__ char near *s1,__CONST__ char far *s2);
size_t n_r_strcspn(__CONST__ char near *s1,__CONST__ char rom *s2);
size_t f_n_strcspn(__CONST__ char far *s1,__CONST__ char near *s2);
size_t f_f_strcspn(__CONST__ char far *s1,__CONST__ char far *s2);
size_t f_r_strcspn(__CONST__ char far *s1,__CONST__ char rom *s2);
size_t r_n_strcspn(__CONST__ char rom *s1,__CONST__ char near *s2);
size_t r_f_strcspn(__CONST__ char rom *s1,__CONST__ char far *s2);
size_t r_r_strcspn(__CONST__ char rom *s1,__CONST__ char rom *s2);
#ifdef _PG_E_ENABLED
size_t n_e_strcspn(__CONST__ char near *s1,__CONST__ char pageE *s2);
size_t f_e_strcspn(__CONST__ char far *s1,__CONST__ char pageE *s2);
size_t r_e_strcspn(__CONST__ char rom *s1,__CONST__ char pageE *s2);
size_t e_n_strcspn(__CONST__ char pageE *s1,__CONST__ char near *s2);
size_t e_f_strcspn(__CONST__ char pageE *s1,__CONST__ char far *s2);
size_t e_e_strcspn(__CONST__ char pageE *s1,__CONST__ char pageE *s2);
size_t e_r_strcspn(__CONST__ char pageE *s1,__CONST__ char rom *s2);
#endif
#if __MODEL__ == 0
#define strcspn n_n_strcspn
#else
#define strcspn f_f_strcspn
#endif

char * strpbrk(__CONST__ char *s1,__CONST__  char *s2);
char near * n_n_strpbrk(__CONST__ char near *s1,__CONST__ char near *s2);
char near * n_f_strpbrk(__CONST__ char near *s1,__CONST__ char far *s2);
char near * n_r_strpbrk(__CONST__ char near *s1,__CONST__ char rom *s2);
char far * f_n_strpbrk(__CONST__ char far *s1,__CONST__ char near *s2);
char far * f_f_strpbrk(__CONST__ char far *s1,__CONST__ char far *s2);
char far * f_r_strpbrk(__CONST__ char far *s1,__CONST__ char rom *s2);
char rom * r_n_strpbrk(__CONST__ char rom *s1,__CONST__ char near *s2);
char rom * r_f_strpbrk(__CONST__ char rom *s1,__CONST__ char far *s2);
char rom * r_r_strpbrk(__CONST__ char rom *s1,__CONST__ char rom *s2);
#ifdef _PG_E_ENABLED
char near * n_e_strpbrk(__CONST__ char near *s1,__CONST__ char pageE *s2);
char far * f_e_strpbrk(__CONST__ char far *s1,__CONST__ char pageE *s2);
char rom * r_e_strpbrk(__CONST__ char rom *s1,__CONST__ char pageE *s2);
char pageE * e_n_strpbrk(__CONST__ char pageE *s1,__CONST__ char near *s2);
char pageE * e_f_strpbrk(__CONST__ char pageE *s1,__CONST__ char far *s2);
char pageE * e_e_strpbrk(__CONST__ char pageE *s1,__CONST__ char pageE *s2);
char pageE * e_r_strpbrk(__CONST__ char pageE *s1,__CONST__ char rom *s2);
#endif
#if __MODEL__ == 0
#define strpbrk n_n_strpbrk
#else
#define strpbrk f_f_strpbrk
#endif

char * strrchr(__CONST__ char *s,int c);
char near * n_strrchr(__CONST__ char near *s,int c);
char far * f_strrchr(__CONST__ char far *s,int c);
#ifdef _PG_E_ENABLED
char pageE * e_strrchr(__CONST__ char pageE *s,int c);
#endif
char rom * r_strrchr(__CONST__ char rom *s,int c);
#if __MODEL__ == 0
#define strrchr n_strrchr
#else
#define strrchr f_strrchr
#endif

size_t strspn(__CONST__ char *s1,__CONST__  char *s2);
size_t n_n_strspn(__CONST__ char near *s1,__CONST__ char near *s2);
size_t n_f_strspn(__CONST__ char near *s1,__CONST__ char far *s2);
size_t n_r_strspn(__CONST__ char near *s1,__CONST__ char rom *s2);
size_t f_n_strspn(__CONST__ char far *s1,__CONST__ char near *s2);
size_t f_f_strspn(__CONST__ char far *s1,__CONST__ char far *s2);
size_t f_r_strspn(__CONST__ char far *s1,__CONST__ char rom *s2);
size_t r_n_strspn(__CONST__ char rom *s1,__CONST__ char near *s2);
size_t r_f_strspn(__CONST__ char rom *s1,__CONST__ char far *s2);
size_t r_r_strspn(__CONST__ char rom *s1,__CONST__ char rom *s2);
#ifdef _PG_E_ENABLED
size_t n_e_strspn(__CONST__ char near *s1,__CONST__ char pageE *s2);
size_t f_e_strspn(__CONST__ char far *s1,__CONST__ char pageE *s2);
size_t r_e_strspn(__CONST__ char rom *s1,__CONST__ char pageE *s2);
size_t e_n_strspn(__CONST__ char pageE *s1,__CONST__ char near *s2);
size_t e_f_strspn(__CONST__ char pageE *s1,__CONST__ char far *s2);
size_t e_e_strspn(__CONST__ char pageE *s1,__CONST__ char pageE *s2);
size_t e_r_strspn(__CONST__ char pageE *s1,__CONST__ char rom *s2);
#endif
#if __MODEL__ == 0
#define strspn n_n_strspn
#else
#define strspn f_f_strspn
#endif

char * strstr(__CONST__ char *s1,__CONST__  char *s2);
char near * n_n_strstr(__CONST__ char near *s1,__CONST__ char near *s2);
char near * n_f_strstr(__CONST__ char near *s1,__CONST__ char far *s2);
char near * n_r_strstr(__CONST__ char near *s1,__CONST__ char rom *s2);
char far * f_n_strstr(__CONST__ char far *s1,__CONST__ char near *s2);
char far * f_f_strstr(__CONST__ char far *s1,__CONST__ char far *s2);
char far * f_r_strstr(__CONST__ char far *s1,__CONST__ char rom *s2);
char rom * r_n_strstr(__CONST__ char rom *s1,__CONST__ char near *s2);
char rom * r_f_strstr(__CONST__ char rom *s1,__CONST__ char far *s2);
char rom * r_r_strstr(__CONST__ char rom *s1,__CONST__ char rom *s2);
#ifdef _PG_E_ENABLED
char near * n_e_strstr(__CONST__ char near *s1,__CONST__ char pageE *s2);
char far * f_e_strstr(__CONST__ char far *s1,__CONST__ char pageE *s2);
char rom * r_e_strstr(__CONST__ char rom *s1,__CONST__ char pageE *s2);
char pageE * e_n_strstr(__CONST__ char pageE *s1,__CONST__ char near *s2);
char pageE * e_f_strstr(__CONST__ char pageE *s1,__CONST__ char far *s2);
char pageE * e_e_strstr(__CONST__ char pageE *s1,__CONST__ char pageE *s2);
char pageE * e_r_strstr(__CONST__ char pageE *s1,__CONST__ char rom *s2);
#endif
#if __MODEL__ == 0
#define strstr n_n_strstr
#else
#define strstr f_f_strstr
#endif

char * strtok(char *s1,__CONST__  char *s2);
char near * n_n_strtok(char near *s1,__CONST__ char near *s2);
char near * n_f_strtok(char near *s1,__CONST__ char far *s2);
char near * n_r_strtok(char near *s1,__CONST__ char rom *s2);
char far * f_n_strtok(char far *s1,__CONST__ char near *s2);
char far * f_f_strtok(char far *s1,__CONST__ char far *s2);
char far * f_r_strtok(char far *s1,__CONST__ char rom *s2);
#ifdef _PG_E_ENABLED
char near * n_e_strtok(char near *s1,__CONST__ char pageE *s2);
char far * f_e_strtok(char far *s1,__CONST__ char pageE *s2);
char pageE * e_n_strtok(char pageE *s1,__CONST__ char near *s2);
char pageE * e_f_strtok(char pageE *s1,__CONST__ char far *s2);
char pageE * e_e_strtok(char pageE *s1,__CONST__ char pageE *s2);
char pageE * e_r_strtok(char pageE *s1,__CONST__ char rom *s2);
#endif
#if __MODEL__ == 0
#define strtok n_n_strtok
#else
#define strtok f_f_strtok
#endif

size_t strlen(__CONST__ char *s);
size_t n_strlen(__CONST__ char near *s);
size_t f_strlen(__CONST__ char far *s);
#ifdef _PG_E_ENABLED
size_t e_strlen(__CONST__ char pageE *s);
#endif
size_t r_strlen(__CONST__ char rom *s);
#if __MODEL__ == 0
#define strlen n_strlen
#else
#define strlen f_strlen
#endif

void * memcpy(void *s1,__CONST__  void *s2,size_t n);
void near * n_n_memcpy(void near *s1,__CONST__ void near *s2,size_t n);
void near * n_f_memcpy(void near *s1,__CONST__ void far *s2,size_t n);
void near * n_r_memcpy(void near *s1,__CONST__ void rom *s2,size_t n);
void far * f_n_memcpy(void far *s1,__CONST__ void near *s2,size_t n);
void far * f_f_memcpy(void far *s1,__CONST__ void far *s2,size_t n);
void far * f_r_memcpy(void far *s1,__CONST__ void rom *s2,size_t n);
void rom * r_n_memcpy(void rom *s1,__CONST__ void near *s2,size_t n);
void rom * r_f_memcpy(void rom *s1,__CONST__ void far *s2,size_t n);
void rom * r_r_memcpy(void rom *s1,__CONST__ void rom *s2,size_t n);
#ifdef _PG_E_ENABLED
void near * n_e_memcpy(void near *s1,__CONST__ void pageE *s2,size_t n);
void far * f_e_memcpy(void far *s1,__CONST__ void pageE *s2,size_t n);
void rom * r_e_memcpy(void rom *s1,__CONST__ void pageE *s2,size_t n);
void pageE * e_n_memcpy(void pageE *s1,__CONST__ void near *s2,size_t n);
void pageE * e_f_memcpy(void pageE *s1,__CONST__ void far *s2,size_t n);
void pageE * e_e_memcpy(void pageE *s1,__CONST__ void pageE *s2,size_t n);
void pageE * e_r_memcpy(void pageE *s1,__CONST__ void rom *s2,size_t n);
#endif
#if __MODEL__ == 0
#define memcpy n_n_memcpy
#else
#define memcpy f_f_memcpy
#endif

int memcmp(__CONST__ void *s1,__CONST__ void *s2, size_t n);
int n_n_memcmp(__CONST__ void near *s1,__CONST__ void near *s2, size_t n);
int n_f_memcmp(__CONST__ void near *s1,__CONST__ void far *s2, size_t n);
int n_r_memcmp(__CONST__ void near *s1,__CONST__ void rom *s2, size_t n);
int f_n_memcmp(__CONST__ void far *s1,__CONST__ void near *s2, size_t n);
int f_f_memcmp(__CONST__ void far *s1,__CONST__ void far *s2, size_t n);
int f_r_memcmp(__CONST__ void far *s1,__CONST__ void rom *s2, size_t n);
int r_n_memcmp(__CONST__ void rom *s1,__CONST__ void near *s2, size_t n);
int r_f_memcmp(__CONST__ void rom *s1,__CONST__ void far *s2, size_t n);
int r_r_memcmp(__CONST__ void rom *s1,__CONST__ void rom *s2, size_t n);
#ifdef _PG_E_ENABLED
int n_e_memcmp(__CONST__ void near *s1,__CONST__ void pageE *s2, size_t n);
int f_e_memcmp(__CONST__ void far *s1,__CONST__ void pageE *s2, size_t n);
int r_e_memcmp(__CONST__ void rom *s1,__CONST__ void pageE *s2, size_t n);
int e_n_memcmp(__CONST__ void pageE *s1,__CONST__ void near *s2, size_t n);
int e_f_memcmp(__CONST__ void pageE *s1,__CONST__ void far *s2, size_t n);
int e_e_memcmp(__CONST__ void pageE *s1,__CONST__ void pageE *s2, size_t n);
int e_r_memcmp(__CONST__ void pageE *s1,__CONST__ void rom *s2, size_t n);
#endif
#if __MODEL__ == 0
#define memcmp n_n_memcmp
#else
#define memcmp f_f_memcmp
#endif

void * memchr(__CONST__ void *s,int c, size_t n);
void near * n_memchr(__CONST__ void near *s, int c, size_t n);
void far * f_memchr(__CONST__ void far *s, int c, size_t n);
#ifdef _PG_E_ENABLED
void pageE * e_memchr(__CONST__ void pageE *s, int c, size_t n);
#endif
void rom * r_memchr(__CONST__ void rom *s, int c, size_t n);
#if __MODEL__ == 0
#define memchr n_memchr
#else
#define memchr f_memchr
#endif

/* These are "PF_REENTRANT" because they are called out of the printf code */
PF_REENTRANT void * memset(void *s, int c, size_t n);

PF_REENTRANT void near * n_memset(void near *s, int c, size_t n);
PF_REENTRANT void far * f_memset(void far *s, int c, size_t n);
#ifdef _PG_E_ENABLED
PF_REENTRANT void pageE * e_memset(void pageE *s, int c, size_t n);
#endif
PF_REENTRANT void rom * r_memset(void rom *s, int c, size_t n);
#if __MODEL__ == 0
#define memset n_memset
#else
#define memset f_memset
#endif

void * memmove(void *s1,__CONST__ void *s2,size_t n);
void near * n_n_memmove(void near *s1,__CONST__ void near *s2,size_t n);
void near * n_f_memmove(void near *s1,__CONST__ void far *s2,size_t n);
void near * n_r_memmove(void near *s1,__CONST__ void rom *s2,size_t n);
void far * f_n_memmove(void far *s1,__CONST__ void near *s2,size_t n);
void far * f_f_memmove(void far *s1,__CONST__ void far *s2,size_t n);
void far * f_r_memmove(void far *s1,__CONST__ void rom *s2,size_t n);
void rom * r_n_memmove(void rom *s1,__CONST__ void near *s2,size_t n);
void rom * r_f_memmove(void rom *s1,__CONST__ void far *s2,size_t n);
void rom * r_r_memmove(void rom *s1,__CONST__ void rom *s2,size_t n);
#ifdef _PG_E_ENABLED
void near * n_e_memmove(void near *s1,__CONST__ void pageE *s2,size_t n);
void far * f_e_memmove(void far *s1,__CONST__ void pageE *s2,size_t n);
void rom * r_e_memmove(void rom *s1,__CONST__ void pageE *s2,size_t n);
void pageE * e_n_memmove(void pageE *s1,__CONST__ void near *s2,size_t n);
void pageE * e_f_memmove(void pageE *s1,__CONST__ void far *s2,size_t n);
void pageE * e_e_memmove(void pageE *s1,__CONST__ void pageE *s2,size_t n);
void pageE * e_r_memmove(void pageE *s1,__CONST__ void rom *s2,size_t n);
#endif
#if __MODEL__ == 0
#define memmove n_n_memmove
#else
#define memmove f_f_memmove
#endif

#endif
