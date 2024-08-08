#include <ultra64.h>
#include "libleo/internal.h"

void LeoBootGame(void* entry);
void __LeoBootGame2(void* entry);
void __LeoBootGame3(void* entry);

void LeoBootGame(void* entry) {
    u8* ptr;
    u8 key;
    u32 i;

    //Descramble __LeoBootGame2
    ptr = (u8*)&__LeoBootGame2;
    //Define difference key (a sum of each byte of __LeoBootGame2 address)
    key = ((((u32)ptr & 0xFF000000) >> 0x18)
         + (((u32)ptr & 0x00FF0000) >> 0x10)
         + (((u32)ptr & 0x0000FF00) >> 0x08)
         + (((u32)ptr & 0x000000FF))) & 0xFF;
    for (i = 0; i < 0x324; i += 4) {
        ptr[0];
        ptr[1];
        ptr[2] -= key;
        ptr[3] += key;
        ptr += 4;
    }
    osWritebackDCacheAll();
    osInvalICache(__LeoBootGame2, 0x324);

    //Descramble __LeoBootGame3
    ptr = (u8*)&__LeoBootGame3;
    for (i = 0; i < 0x60; i += 4) {
        ptr[0];
        ptr[1];
        ptr[2] -= key;
        ptr[3] += key;
        ptr += 4;
    }
    osWritebackDCacheAll();
    osInvalICache(__LeoBootGame3, 0x60);
    
    __LeoBootGame2(entry);
}

// -----------------------------------------
// Encrypted function
// -----------------------------------------

// This MUST be scrambled by the build process or they will not be executable
// at runtime when descrambled.
void __LeoBootGame2(void* entry) {
    u8* entry2 = (u8*)entry;
    u32 i;
    s32 sp134;
    u8 sp34[0x100];
    vu32* var_v0;

    sp134 = 0;
    bzero(LeoBootGame, 0x13C);
    osWritebackDCache(LeoBootGame, 0x13C);
    __osSetSR(0x30000000);

    *(u8*)0xA0000010 = (u32) (LEO_country_code & 0xFF000000) >> 0x18;

    while (!IO_READ(0x4040010) & 1) {}

    IO_WRITE(0x4040010, 0xA);
    
    while (sp134 < 0x50) {
        sp34[(sp134 * 0x11) % 256] = entry2[sp134];
        sp134++;
    }

    while (IO_READ(0x4040018) & 1) {}
    
    IO_WRITE(0x4600010, 3);

    while (sp134 < 0xAA) {
        sp34[(sp134 * 0x11) % 256] = entry2[sp134];
        sp134++;
    }

    while (IO_READ(0x4400010) >= 11) {}

    IO_WRITE(0x440000C, 0x3FF);
    IO_WRITE(0x4400024, 0);
    *(u32* )0xA4400010 = 0;
    *(u8*)0xA0000190 = LEO_country_code & 0xFF;
    IO_WRITE(0x4500000, 0);
    IO_WRITE(0x4500004, 0);
    
    while (sp134 < 0x100) {
        sp34[(sp134 * 0x11) % 256] = entry2[sp134];
        sp134++;
    }
    
    _bcopy(&sp34, entry2, 0x100U);
    *(u8*)0xA0000110 = (u32) (LEO_country_code & 0xFF00) >> 8;
    __osSetCause(0);
    __osSetCount(0);
    __osSetCompare(0);
    IO_WRITE(0x4040010, 0xAAAAAE);
    *(u8*)0xA0000090 = (u32) (LEO_country_code & 0xFF0000) >> 0x10;
    IO_WRITE(0x430000C, 0);
    IO_WRITE(0x4800018, 0);
    IO_WRITE(0x450000C, 0);
    IO_WRITE(0x4300000, 0x800);
    IO_WRITE(0x4600010, 2);
    osResetType = 2;

    var_v0 = (vu32*)0xA4001000;
    for (i = 0; i < 0x100; i++) {\
        *var_v0++ = 0;
    }

    var_v0 = (vu32*)0xA4000000;
    for (i = 0; i < 0x100; i++) {\
        *var_v0++ = 0;
    }
    bzero(__LeoBootGame2, 0x2E4);
    osWritebackDCache(__LeoBootGame2, 0x2E4);
    __LeoBootGame3(entry2);
}
