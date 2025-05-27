#pragma once
#define FCMD (*(volatile unsigned char far *)0x0FF8)  // Define special function register

void unlockFlash(void) {
	if(FCMD == 0x02 || FCMD == 0x03) return;
    FCMD = 0x73;  // First unlock key
	while (FCMD != 0x01); // Wait for "first key received"

    FCMD = 0x8C;  // Second unlock key
	while (FCMD != 0x02); // Wait for "second key received"
}

unsigned char checkFlash(void) {
    return FCMD;
}