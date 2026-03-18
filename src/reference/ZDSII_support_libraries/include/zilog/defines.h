/*!\file defines.h
 * \brief Definition file for data type and other definitions used
 *        across Z8 Encore! ZiLOG Standard Library.
 *
 *  This file contains data type and other definitions that are
 *  used across ZiLOG Standard Library implementations for Z8 Encore!
 *  microcontrollers.
 *
 *  This source file uses Doxygen-style comments to generate documentation
 *  automatically.
 *
 *  Copyright (C) 1999-2004 by  ZiLOG, Inc.
 *  All Rights Reserved.
 */

#pragma once // Include this file only once
#ifndef _DEFINES_H_
#define _DEFINES_H_


#ifndef TRUE			
#define TRUE			1			//!< The TRUE definition.
#endif					
#ifndef FALSE			
#define FALSE			0			//!< The FALSE definition.
#endif
#ifndef ALWAYS
#define ALWAYS			1
#endif

#define INTPRIORITY_DISABLE					(BYTE)0x00				//!< Interrupt priorities.
#define INTPRIORITY_LOW						(BYTE)0x01
#define INTPRIORITY_NOMINAL					(BYTE)0x02
#define INTPRIORITY_HIGH					(BYTE)0x03


/*! The type name for void data type char */
typedef void VOID ;

/*! The type name for standard C data type char */
typedef char CHAR ;

/*! The type name for standard C data type unsigned char */
typedef unsigned char UCHAR ;

/*! The type name for standard C data type unsigned char as byte */
typedef unsigned char BYTE ;

/*! The type name for standard C data type unsigned char as bool */
typedef	unsigned char BOOL ;

/*! The type name for standard C data type char as integer */
typedef char INT8 ;

/*! The type name for standard C data type unsigned char as unsigned integer */
typedef unsigned char UINT8 ;

/*! The type name for standard C data type short */
typedef short INT16 ;

/*! The type name for standard C data type unsigned short */
typedef unsigned short UINT16 ;

/*! The type name for standard C data type unsigned short as word*/
typedef unsigned short WORD ;

/*! The type name for standard C data type int */
typedef int INT ;

/*! The type name for standard C data type unsigned int */
typedef unsigned int UINT ;

/*! The type name for standard C data type long */
typedef long INT32 ;

/*! The type name for standard C data type unsigned long */
typedef unsigned long UINT32 ;

/*! The type name for standard C data type unsigned long as dword */
typedef unsigned long DWORD ;

/*! The type name for standard C data type float */
typedef float FLOAT ;

/*! The type name for standard C data type float */
typedef float FLOAT32 ;

/*! The type name for standard C data type double */
typedef double DOUBLE ;

#endif /*! _DEFINES_H_ */


