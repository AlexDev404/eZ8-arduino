/*************************************************
 *  Copyright (C) 2009 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

/*************************************************
*
* intrp - working register group for next interrupt
*   C interupt handlers begin with
*   	PUSHX  RP
*   	LDX    RP,__intrp
*   	ADDX  __intrp,#%10
*
*   and end with
*       SUBX  __intrp,#%10
*       POPX  RP
*
*   initial value here assumes an initial RP of 0 for the small model, and
*   of 0xE0 for the large model
*
*************************************************/

#if __MODEL__ == 0
unsigned char _intrp = 0x10;		// Small model
#else
unsigned char _intrp = 0x00;		// Large model
#endif
