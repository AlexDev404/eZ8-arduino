#define CLOCK_INTERNAL 0
#define CLOCK_EXTERNAL 1

#ifndef CLOCKSOURCE
#define CLOCKSOURCE    CLOCK_INTERNAL
#endif

void osc_delay()
{
    // wait for oscillator to stabilize.
	asm("DELAY_COUNT	.set (15000/36)");      // cycles / cycles-per-loop
	asm("\tpush R12");
	asm("\tpush R13");
	asm("\tpush R14");
	asm("\tpush R15");

	asm("\tLD   R12, #HIGH(DELAY_COUNT>>16)");
    asm("\tLD   R13, #LOW(DELAY_COUNT>>16)");
    asm("\tLD   R14, #HIGH(DELAY_COUNT)");
	asm("\tLD   R15, #LOW(DELAY_COUNT)");
	
	asm("$delayCountDown:");					//this loop takes about 36 cycles"
	asm("\tCP   R15,#%0");
	asm("\tCPC  R14,#%0");
	asm("\tCPC  R13,#%0");
	asm("\tCPC  R12,#%0");
    asm("\tJR   ule,$delay_done");
	asm("\tSUB  R15,#%1");
    asm("\tSBC  R14,#%0");
    asm("\tSBC  R13,#%0");
    asm("\tSBC  R12,#%0");
	asm("\tjr $delayCountDown");
	asm("$delay_done:");
	asm("\tpop R15");
	asm("\tpop R14");
	asm("\tpop R13");
	asm("\tpop R12");
}

////////////////////////////////////////////////////////
// Initialize system clock source to use external crystal
//
void init_systemclock()
{
#if (CLOCKSOURCE == CLOCK_EXTERNAL)
	if((OSCCTL & 0x42) != 0x42)		//not currently external ?
	{
		OSCCTL = 0xE7;					// Unlock sequence for OSCTL write
		OSCCTL = 0x18;					//
   		OSCCTL	=0xc0;					//start external oscillator
		osc_delay();					//wait for oscillator to stabilize
				
		OSCCTL = 0xE7;					// Unlock sequence
		OSCCTL = 0x18;					//
	   	OSCCTL	=0x42;					// switch to external
	 }
#else
	if((OSCCTL & 0x87) != 0x80)		//not currently internal ?
	{
		OSCCTL = 0xE7;					// Unlock sequence for OSCTL write
		OSCCTL = 0x18;					//
   		OSCCTL	=0x80;					// switch to internal
	}
#endif								
}