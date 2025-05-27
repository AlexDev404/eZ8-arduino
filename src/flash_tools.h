#pragma once
#define FCMD (*(volatile unsigned char far *)0x0FF8)  // Define special function register

void unlockFlash(void) {
    FCMD = 0x73;  // First unlock key
    FCMD = 0x8C;  // Second unlock key
}

unsigned char checkFlash(void) {
    return FCMD;
}