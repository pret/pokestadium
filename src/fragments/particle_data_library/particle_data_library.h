#ifndef _FRAGMENT31_H_
#define _FRAGMENT31_H_

#include "global.h"
#include "gallery.h"

typedef struct DisplayListAddresses {
    /* 0x00 */ u32 segments[2];
    /* 0x08 */ u32 textures[1];
} DisplayListAddresses; // size = 0xC

typedef struct DisplayListState {
    /* 0x00 */ char unk00[0x14];
    /* 0x14 */ DisplayListAddresses* addresses;
    /* 0x18 */ Gfx* gfx;
} DisplayListState; // size = 0x1C

typedef struct unk_arg0_func_81002260 {
    /* 0x00 */ char unk00[0x1A];
    /* 0x1A */ s16 unk_1A;
} unk_arg0_func_81002260; // size >= 0x1C

extern const Gfx D_810041D0[];

void Particle31_ResetAllSlots(DisplayObject*);
void Particle31_ResetCounters(void);
void Particle31_PackSlotData(u8*);
void Particle31_UnpackSlotData(unk_arg0_func_81002260*, u8*);

#endif // _FRAGMENT31_H_
