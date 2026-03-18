/*************************************************
 *  Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *  All Rights Reserved
 *************************************************/
	/* Heap packet header for malloc */

#pragma once    // Include this file only once
#define HEADER_TEMPLATE(SPACE,SIZE_TYPE)                                       \
                                                                               \
typedef SIZE_TYPE  SPACE##_size_type;                                          \
struct SPACE##_header {			                                       \
  struct SPACE##_header SPACE * ptr;     /* next free block */	               \
  SPACE##_size_type size;		 /* size of block in  bytes   */       \
};                                                                             \
                                                                               \
typedef struct SPACE##_header SPACE##HEADER;

HEADER_TEMPLATE(near,unsigned char)
#define near_size_max 0xFF
HEADER_TEMPLATE(far,unsigned int)
#define far_size_max 0
HEADER_TEMPLATE(pageE,unsigned int)
#define pageE_size_max 0

#define ADD_SIZE_TOfarHEADER(_p) ((farHEADER far*)(((far char*)(_p))+ (_p)->size))
#define ADD_SIZE_TOnearHEADER(_p) ((nearHEADER near*)(((near char*)(_p))+ (_p)->size))
#define ADD_SIZE_TOpageEHEADER(_p) ((pageEHEADER pageE*)(((pageE char*)(_p))+ (_p)->size))

extern near nearHEADER* near n_allocp;
extern far farHEADER* far  f_allocp;
extern pageE pageEHEADER* pageE  e_allocp;

#if __MODEL__ == 0
# define HEADER nearHEADER
# define allocp n_allocp
# define _size_type near_size_type
#else
# define HEADER farHEADER
# define allocp f_allocp
# define _size_type far_size_type
#endif
