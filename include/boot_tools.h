#pragma once

// TODO: Modify to work with Z80
/*#define __boot_page_erase_short(address)        \
(__extension__({                                 \
    __asm__ __volatile__                         \
    (                                            \
        "out %0, %1\n\t"                         \
        "spm\n\t"                                \
        :                                        \
        : "i" (_SFR_IO_ADDR(__SPM_REG)),        \
          "r" ((UINT16)__BOOT_PAGE_ERASE),      \
          "z" ((UINT16)address)                \
    );                                           \
}))*/