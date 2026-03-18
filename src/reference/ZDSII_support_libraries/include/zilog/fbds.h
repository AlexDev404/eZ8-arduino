/*!
*\file   <fbds.h>
*\brief Header file for Z8 Encore! FBDS 
*	    ZILOG DISCLAIMER
*      THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY 
*      KIND,EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE 
*      WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
*      PURPOSE AND NONINFRINGEMENT. 
*      IN NO EVENT SHALL ZILOG, INC BE LIABLE FOR ANY CLAIM, DAMAGES
*      OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR 
*      OTHERWISE,ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
*      SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*        Copyright (C) 2006-xxxx by  ZILOG, Inc.
*        All Rights Reserved
*/

#pragma once // Include this file only once
#ifndef _FBDS_H_
#define _FBDS_H_

/* System Includes */
#include <defines.h>


/* Constant Definition */
#define FLASH_PAGE_SIZE     512
#define MAX_PAGE_ADDRESS	511
/*!FBDS error definitions */
#define FBDS_WRITE_ERROR		03
#define FBDS_MEMORY_ERROR		02
#define FBDS_PARITY_ERROR		01
#define FBDS_SUCCESS			00



/* Global Function Prototypes */

/*!
*\brief   API to write a single char/byte into FBDS.
*/
reentrant UCHAR write_byte_FBDS (UCHAR byte ,UINT log_add);

/*!
*\brief   API to write an integer into FBDS.
*/
reentrant UCHAR write_word_FBDS(UINT word,UINT log_add);

/*!
*\brief   API to write a long int into FBDS.
*/
reentrant UCHAR write_dword_FBDS(DWORD lword,UINT log_add);

/*!
*\brief   API to read byte from FBDS.
*/
reentrant UCHAR read_byte_FBDS (UINT log_add);

/*!
*\brief   API to read a integer from FBDS.
*/
reentrant UINT  read_word_FBDS (UINT log_add);

/*!
*\brief   API to read a long from FBDS.
*/
reentrant DWORD read_dword_FBDS (UINT log_add);

/*!
*\brief   API to write a char into the next logical address of FBDS.
*/
reentrant UCHAR writenext_byte_FBDS (UCHAR byte);

/*!
*\brief   API to write an integer into the next logical address of FBDS.
*/
reentrant UCHAR writenext_word_FBDS(UINT word);

/*!
*\brief   API to write a long integer into the next logical address of FBDS.
*/
reentrant UCHAR writenext_dword_FBDS(DWORD lword);

/*!
*\brief   API to read a char from the next logical address of FBDS.
*/
reentrant UCHAR readnext_byte_FBDS (VOID);

/*!
*\brief   API to read an integer from the next logical address of FBDS.
*/
reentrant UINT  readnext_word_FBDS (VOID);

/*!
*\brief   API to read a long from the next logical address of FBDS.
*/
reentrant DWORD readnext_dword_FBDS (VOID);

/*!
*\brief   API to read the error status of FBDS.
*/
reentrant UCHAR get_error_FBDS(VOID);


#endif

/* End of File */
