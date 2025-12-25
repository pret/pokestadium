#include "fragment31.h"
#include "src/fragments/7/fragment7.h"
#include "src/fragments/8/fragment8.h"
#include "src/6A40.h"
#include "src/32D10.h"

typedef struct {
    /* 0x00 */ u8 rgb0[3];      // start color
    /* 0x03 */ u8 frameStart;   // frame where this keyframe begins
    /* 0x04 */ u8 rgb1[3];      // end color
    /* 0x07 */ u8 frameEnd;     // frame where keyframe ends
} Keyframe;  // size = 0x08

extern Keyframe* D_8100419C[];
extern s32 D_810041D0;
extern s32 D_81004B70;
extern s32 D_81004B80;
extern s32 D_81004B90;
extern s32 D_81004BA0;
extern s32 D_81004BB0;

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

#ifdef NON_MATCHING
// Matching, needs more data
void func_810035C0(s32 arg0, DisplayListState* state) {
    static u8 D_81004190 = 0;
    s32 temp_a1;
    s32 temp_a2;
    Gfx* gfx;

    if (arg0 == 2) {
        gfx = func_80005F5C(0x10);
        temp_a1 = D_81004190 * 3;
        temp_a2 = D_81004190 * -6;
        state->gfx = gfx;
        {    Gfx *_gfx = (Gfx *)(gfx++); _gfx->words.w0 = (((temp_a1 & 0xFFF) << 0xC) | 0xF2000000 | (temp_a2 & 0xFFF));    _gfx->words.w1 = ((((0x27F << (temp_a1 + 2)) & 0xFFF) << 0xC) | ((0x7F << (temp_a2 + 2)) & 0xFFF));    }
        gSPEndDisplayList(gfx++);
        D_81004190++;
        D_81004190 &= 0x7F;
    }
}
#else
void func_810035C0(s32, DisplayListState*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_258080/func_810035C0.s")
#endif

#ifdef NON_MATCHING
void func_81003678(s32 arg0, DisplayListState* state) {
    static u8 D_81004194 = 0;
    static u8 D_81004198 = 0;
    Keyframe* kf;
    Gfx* gfx;
    u8 rgbInterp[3];
    f32 var_ft2;
    s32 temp_a3_2;
    s32 temp_t1_2;
    s32 i;
    s32 c;
    u8 start;
    u8 span;
    u8 delta;
    u8 t;
    
    if (arg0 == 2) {
        gfx = func_80005F5C(0x20);
        state->gfx = gfx;
        for (i = 0; i < 5; i++) {
            kf = D_8100419C[i];
            if (D_81004198 == kf->frameStart) {
                for(c = 0; c < 3; c++) {
                    rgbInterp[c] = kf->rgb0[c];
                }
            } else if (kf->frameStart < D_81004198 && D_81004198 < kf->frameEnd) {
                span = (kf->frameEnd - kf->frameStart);
                t = D_81004198 - kf->frameStart;
                for(c = 0; c < 3; c++) {
                    start = kf->rgb0[c];
                    var_ft2 = (f32) start;
                    if ((s32) start < 0) {
                        var_ft2 += 4294967296.0f;
                    }
                    delta = (kf->rgb1[c] - start);
                    rgbInterp[c] = (var_ft2 + ((f32) (delta * t) / (f32) span) + 0.5f);
                }
            }
        }
        temp_a3_2 = D_81004194 * -2;
        temp_t1_2 = D_81004194 * 2;
        // set prim color?
        {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xFA000080;    _gfx->words.w1 = ((rgbInterp[2] << 8) | (rgbInterp[1] << 0x18) | (rgbInterp[0] << 0x10) | 0xB4);    }
        {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = (((temp_a3_2 & 0xFFF) << 0xC) | 0xF2000000);    _gfx->words.w1 = ((((0x13F << (temp_a3_2 + 2)) & 0xFFF) << 0xC) | 0xFC);    }
        {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = (((temp_t1_2 & 0xFFF) << 0xC) | 0xF2000000);    _gfx->words.w1 = ((((0x13F << (temp_t1_2 + 2)) & 0xFFF) << 0xC) | 0x01000000 | 0xFC);    }
        gSPEndDisplayList(gfx++);
        D_81004194++;
        D_81004194 &= 0x7F;
        D_81004198++;
        if ((s32) D_81004198 >= 0x32) {
            D_81004198 = 0;
        }
    }
}
#else
void func_81003678(s32, DisplayListState*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_258080/func_81003678.s")
#endif

void func_810038D0(Gfx* gfx) {
    s32 temp_a3;

    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xDE000000;    _gfx->words.w1 = &D_810041D0;    }
    temp_a3 = ((s32) ((D_800AF770[5]) * 0x55) / 255) + 0xAA;
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = ((temp_a3 & 0xFF) | 0xFA000000);    _gfx->words.w1 = -0x3701;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xFB000000;    _gfx->words.w1 = 0x501E0AFF;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xFD700000;    _gfx->words.w1 = Util_ConvertAddrToVirtAddr(&D_3008000);    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF5700000;    _gfx->words.w1 = 0x07094260;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE6000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF3000000;    _gfx->words.w1 = 0x070FF200;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xE7000000;    _gfx->words.w1 = 0;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF5680800;    _gfx->words.w1 = 0x94260;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xF2000000;    _gfx->words.w1 = 0x7C03C;    }
    gSPEndDisplayList(gfx++);
    D_81004BB0 = 0;
}

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
