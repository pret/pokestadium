#ifndef _FRAGMENT31_H_
#define _FRAGMENT31_H_

#include "global.h"
#include "30640.h"

typedef struct GraphicState {
    /* 0x00 */ char unk00[0x18];
    /* 0x18 */ Gfx* gfx;
} GraphicState; // size >= 0x1C

void func_810007A8(unk_D_86002F58_004_000*);
void func_810007F8(void);
void func_81002174(unk_D_83402EE0_00A*);

#endif // _FRAGMENT31_H_
