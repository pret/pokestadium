#include "fragment31.h"
#include "src/fragments/7/fragment7.h"
#include "src/fragments/8/fragment8.h"
#include "src/6A40.h"

extern u8 D_81004190;
extern s32 D_81004B70;
extern s32 D_81004B80;
extern s32 D_81004B90;
extern s32 D_81004BA0;

#ifdef NON_MATCHING
void func_81002DC0(Gfx* gfx, s32 arg1, s32 arg2) {
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE7000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xD7000002;    _gfx->words.w1 = -1;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE3001001;    _gfx->words.w1 = 0x8000;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xFD100000;    _gfx->words.w1 = arg1;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE8000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF5000100;    _gfx->words.w1 = 0x07000000;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE6000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF0000000;    _gfx->words.w1 = 0x073FC000;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE7000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xFD48001F;    _gfx->words.w1 = (((D_862082A0[0] * 4) & ~0x1F) + arg2 + ((D_81004B70 & 3) << 0xB));    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF5480800;    _gfx->words.w1 = 0x07098250;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE6000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF4000000;    _gfx->words.w1 = 0x0707C0FC;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE7000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF5480800;    _gfx->words.w1 = 0x98250;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF2000000;    _gfx->words.w1 = 0x7C0FC;    }
    gSPEndDisplayList(gfx++);
}
#else
void func_81002DC0(Gfx*, s32, s32);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_258080/func_81002DC0.s")
#endif

void func_81002F38(s32 arg0, DisplayListState* state) {
    Gfx* gfx;
    DisplayListAddresses* addresses;

    addresses = state->addresses;
    switch (arg0) {
    case 0:
        D_81004B70 = 0;
        return;
    case 2:
        gfx = func_80005F5C(0xA0);
        state->gfx = gfx;
        func_81002DC0(gfx, addresses->segments[0], addresses->segments[1]);
        D_81004B70 += 1;
        return;
    }
}

#ifdef NON_MATCHING
void func_81002FC0(Gfx* gfx, s32 arg1, s32 arg2) {
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE7000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xD7000002;    _gfx->words.w1 = -1;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE3001001;    _gfx->words.w1 = 0x8000;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xFD100000;    _gfx->words.w1 = arg1;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE8000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF5000100;    _gfx->words.w1 = 0x07000000;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE6000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF0000000;    _gfx->words.w1 = 0x073FC000;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE7000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xFD48001F;    _gfx->words.w1 = (((D_862082A0[1] * 4) & ~0x1F) + arg2 + ((D_81004B80 & 3) << 11));    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF5480800;    _gfx->words.w1 = 0x07098250;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE6000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF4000000;    _gfx->words.w1 = 0x0707C0FC;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE7000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF5480800;    _gfx->words.w1 = 0x98250;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF2000000;    _gfx->words.w1 = 0x7C0FC;    }
    gSPEndDisplayList(gfx++);
}
#else
void func_81002FC0(Gfx*, s32, s32);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_258080/func_81002FC0.s")
#endif

void func_81003138(s32 arg0, DisplayListState* state) {
    Gfx* gfx;
    DisplayListAddresses* addresses;

    addresses = state->addresses;
    switch (arg0) {                                 /* irregular */
    case 0:
        D_81004B80 = 0;
        return;
    case 2:
        gfx = func_80005F5C(0xA0);
        state->gfx = gfx;
        func_81002FC0(gfx, addresses->segments[0], addresses->segments[1]);
        D_81004B80 += 1;
        return;
    }
}

#ifdef NON_MATCHING
void func_810031C0(Gfx* gfx, s32 arg1, s32 arg2) {
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE7000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xD7000002;    _gfx->words.w1 = -1;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE3001001;    _gfx->words.w1 = 0x8000;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xFD100000;    _gfx->words.w1 = arg1;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE8000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF5000100;    _gfx->words.w1 = 0x07000000;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE6000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF0000000;    _gfx->words.w1 = 0x073FC000;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE7000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xFD48001F;    _gfx->words.w1 = ((((D_862082A0[2]) * 4) & ~0x1F) + arg2 + ((D_81004B90 & 3) << 0xB));    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF5480800;    _gfx->words.w1 = 0x07098250;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE6000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF4000000;    _gfx->words.w1 = 0x0707C0FC;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE7000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF5480800;    _gfx->words.w1 = 0x98250;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF2000000;    _gfx->words.w1 = 0x7C0FC;    }
    gSPEndDisplayList(gfx++);
}
#else
void func_810031C0(Gfx*, s32, s32);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_258080/func_810031C0.s")
#endif

void func_81003338(s32 arg0, DisplayListState* state) {
    Gfx* gfx;
    DisplayListAddresses* addresses;

    addresses = state->addresses;
    switch (arg0) {                                 /* irregular */
    case 0:
        D_81004B90 = 0;
        return;
    case 2:
        gfx = func_80005F5C(0xA0);
        state->gfx = gfx;
        func_810031C0(gfx, addresses->segments[0], addresses->segments[1]);
        D_81004B90 += 1;
        return;
    }
}

#ifdef NON_MATCHING
void func_810033C0(Gfx* gfx, s32 arg1, s32 arg2) {
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE7000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xD7000002;    _gfx->words.w1 = -1;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE3001001;    _gfx->words.w1 = 0x8000;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xFD100000;    _gfx->words.w1 = arg1;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE8000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF5000100;    _gfx->words.w1 = 0x07000000;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE6000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF0000000;    _gfx->words.w1 = 0x073FC000;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE7000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xFD48001F;    _gfx->words.w1 = ((((D_862082A0[3]) * 4) & ~0x1F) + arg2 + ((D_81004BA0 & 3) << 0xB));    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF5480800;    _gfx->words.w1 = 0x07098250;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE6000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF4000000;    _gfx->words.w1 = 0x0707C0FC;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE7000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF5480800;    _gfx->words.w1 = 0x98250;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF2000000;    _gfx->words.w1 = 0x7C0FC;    }
    gSPEndDisplayList(gfx++);
}
#else
void func_810033C0(Gfx*, s32, s32);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_258080/func_810033C0.s")
#endif

void func_81003538(s32 arg0, DisplayListState* state) {
    Gfx* gfx;
    DisplayListAddresses* addresses;

    addresses = state->addresses;
    switch (arg0) {                                 /* irregular */
    case 0:
        D_81004BA0 = 0;
        return;
    case 2:
        gfx = func_80005F5C(0xA0);
        state->gfx = gfx;
        func_810033C0(gfx, addresses->segments[0], addresses->segments[1]);
        D_81004BA0 += 1;
        return;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_258080/func_810035C0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_258080/func_81003678.s")

void func_810038D0(Gfx*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_258080/func_810038D0.s")

s32 func_81003A24(s8* arg0) {
    s32 var_v1;
    s8 temp_t7;
    s8* var_v0;

    var_v1 = 0;
    var_v0 = arg0;
    if (*arg0 != 0) {
        do {
            var_v1 += 1;
            var_v0 += 1;
        } while (var_v0[0] != 0);
    }
    return var_v1;
}

void func_81003A54(Gfx*); 
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_258080/func_81003A54.s")

void func_81003CF0(s32 arg0, DisplayListState* state) {
    Gfx* gfx;

    if (arg0 == 2) {
        gfx = func_80005F5C(0xF0);
        state->gfx = gfx;
        func_810038D0(gfx);
    }
}

void func_81003D2C(s32 arg0, DisplayListState* state) {
    Gfx* gfx;

    if (arg0 == 2) {
        gfx = func_80005F5C(0xA0);
        state->gfx = gfx;
        func_81003A54(gfx);
    }
}
