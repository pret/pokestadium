#include "30640.h"
#include "include/math.h"
#include "src/fragments/15/fragment15.h"
#include "src/fragments/34/fragment34.h"
#include "src/11BA0.h"
#include "src/12D80.h"
#include "src/17300.h"
#include "src/18140.h"
#include "src/geo_layout.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/29BA0.h"
#include "src/3FB0.h"
#include "src/37370.h"
#include "src/4BDC0.h"
#include "src/F420.h"
#include "src/math_util.h"
#include "src/memory.h"
#include "src/util.h"

typedef struct {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;

    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
} unk_D_800761B0; /* size = 0x40 */

typedef struct unk_func_8003013C_arg1 {
    /* 0x00 */ u8 pad00[0x1C];
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
} unk_func_8003013C_arg1; // size >= 0x20

extern unk_func_80031270* D_80075F80;
extern unk_func_80031270* D_80075F84;
extern u32* D_80075F88;
extern unk_D_80068BB0* D_80075F90;
extern s32 D_80075F94;
extern s32 D_80075F98;
extern s32 D_80075F9C;
extern u32 D_80075FA0[];
extern u32 D_8007616C[];
extern unk_D_800761B0 D_800761B0[12];
extern f64 D_8007C538;
extern f64 D_8007C540;
extern f64 D_8007C548;
extern f64 D_8007C550;
extern f64 D_8007C558;
extern f64 D_8007C560;
extern f64 D_8007C568;
extern f64 D_8007C570;

void func_800318B8(void);
void func_8340051C(void);

void func_8002FA40(void) {
    s32 var_s6;
    u32* temp_s0;
    u32 var_s0;
    u32 var_s2;
    u32 sp64;
    u32 var_s5;
    u32 sp5C;
    s32 var_v0;
    unk_D_83407B00* val;

    val = &D_83407B30;
    var_s2 = 0;
    var_s5 = 0;

    main_pool_push_state('SNPM');
    func_8004B1CC(0x4B);

    FRAGMENT_LOAD(fragment43)();
    FRAGMENT_LOAD(fragment34);

    do {
        temp_s0 = Util_ConvertAddrToVirtAddr((u32)val);
        var_s6 = 1;

        main_pool_push_state('galy');

        switch (var_s5) {
            case 0:
                var_v0 = 0;
                if (*temp_s0 != 0) {
                    var_s0 = 1;
                } else {

                    switch (var_s2) {
                        case 4:
                            var_s0 = 2;
                            break;

                        default:
                            var_s0 = 0;
                            if (var_s2 == 7) {
                                var_v0 = 1;
                            }
                            break;
                    }
                }
                sp64 = FRAGMENT_LOAD_AND_CALL(fragment42, var_s0, var_v0);
                break;

            case 1:
            case 6:
                FRAGMENT_LOAD(fragment2)();
                // loaded, but doesnt use any GFX from it. speculated to have intended using the
                // button GFX for How to Snap, but it doesnt use them.
                ASSET_LOAD(D_3000000, kids_club_game_ui, 0);
                FRAGMENT_LOAD(fragment3);
                FRAGMENT_LOAD(fragment31);

                // determine if this is "How to Snap" or regular Snap Mode.
                if (var_s5 == 1) {
                    var_s0 = 0;
                } else {
                    var_s0 = 1;
                }

                switch (FRAGMENT_LOAD_AND_CALL(fragment15, var_s0, 0)) {
                    case 1:
                        sp64 = 5;
                        break;

                    case 2:
                        if (var_s0 == 1) {
                            sp64 = 5;
                        } else {
                            sp64 = 2;
                        }
                        break;

                    default:
                        sp64 = 5;
                        break;
                }
                break;

            case 2:
                if (var_s2 == 4) {
                    var_s0 = 0;
                } else {
                    var_s0 = 1;
                }
                sp64 = FRAGMENT_LOAD_AND_CALL(fragment45, var_s0, 0);
                break;

            case 3:
                var_v0 = 1;
                switch (var_s2) {
                    case 4:
                        var_s0 = sp5C;
                        var_v0 = 0;
                        break;

                    case 2:
                        var_s0 = 1;
                        break;

                    default:
                        if (*temp_s0 != 0) {
                            var_s0 = 2;
                        } else {
                            var_s0 = 0;
                        }
                        break;
                }

                sp64 = FRAGMENT_LOAD_AND_CALL(fragment44, var_s0, var_v0);
                if (sp64 == 4) {
                    sp5C = var_s0;
                }
                break;

            case 4:
                FRAGMENT_LOAD_AND_CALL(fragment46, 0, 0);
                sp64 = var_s2;
                break;

            case 5:
                FRAGMENT_LOAD(fragment61);
                switch (var_s2) {
                    case 1:
                        var_s0 = 1;
                        break;

                    case 6:
                        var_s0 = 2;
                        break;

                    default:
                        var_s0 = 0;
                        break;
                }
                sp64 = FRAGMENT_LOAD_AND_CALL(fragment47, var_s0, 0);
                break;

            case 7:
                FRAGMENT_LOAD_AND_CALL(fragment49, 0, 0);
                sp64 = 0;
                break;

            default:
                var_s6 = 0;
                break;
        }

        var_s2 = var_s5;
        var_s5 = sp64;

        main_pool_pop_state('galy');

    } while (var_s6 != 0);

    ((ret_func_80004454)Util_ConvertAddrToVirtAddr(func_8340051C))();

    main_pool_pop_state('SNPM');
}

void func_8002FF00(void) {
    func_800318B8();
}

void func_8002FF20(void) {
    D_80075F90 = 0;
}

s32 func_8002FF2C(unk_D_83403C60* arg0) {
    return ((s32) arg0->unk_6C >> 2) & 3;
}

f32 func_8002FF3C(unk_D_83403C60* arg0) {
    s32 index;
    f32* table;
    index = ((s32) arg0->unk_6C >> 1) & 1;
    table = (f32*)Util_ConvertAddrToVirtAddr(&D_80075F88);
    return table[index];
}

u32 func_8002FF7C(unk_D_83403C60* arg0) {
    u8 v1 = arg0->unk_6C;
    v1 = v1 >> 4;
    return v1 & 0xF;
}

s32 func_8002FF8C(s32 arg0) {
    unk_func_80031270* var_a1;
    UNUSED unk_func_80031270* sp1C;

    var_a1 = NULL;
    switch (arg0) {
    case 0:
        var_a1 = D_80075F80;
        break;
    case 2:
        var_a1 = D_80075F84;
        break;
    case 5:
        var_a1 = D_80075F84;
        break;
    }
    sp1C = var_a1;
    if (func_800317D8(var_a1) != 0) {
        return func_8002FF2C(var_a1->unk_18);
    }
    return 0;
}

#ifdef NON_MATCHING
s32 func_80030010(s32 arg0, unk_D_86002F34_00C* arg1) {
    s32* src;
    s32* dst;

    if (arg0 == 2) {
        src = (s32*)((u8*)D_80075F84->unk_18 + 0x50);
        func_80011DAC(arg1, 0, 0, D_80075F84->unk_04, D_80075F84->unk_06);
        func_80011E68(arg1, func_8002FF3C(D_80075F84->unk_18), 20.0f, 10000.0f);
        dst = (s32*)((u8*)arg1 + 0xA8);
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        dst[4] = src[4];
        dst[5] = src[5];
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80030010.s")
#endif

#ifdef NON_MATCHING
s32 func_800300CC(s32 arg0, unk_D_86002F34_00C* arg1) {
    if ((func_8002FF8C(arg0) != 0) && (arg0 == 2)) {
        func_80011DAC(arg1, 0, 0, D_80075F84->unk_04, D_80075F84->unk_06);
        func_80011E68(arg1, 45.0f, 20.0f, 8000.0f);
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_800300CC.s")
#endif

s32 func_8003013C(s32 arg0, unk_func_8003013C_arg1* arg1) {
    UNUSED s32 pad;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        func_800102A4(&D_8006F088->unk_60.at, &D_8006F088->unk_60.eye, &sp28, &sp26, &sp24);
        arg1->unk_1C = (s16) (sp26 + 0x2000);
        arg1->unk_1E = (s16) (sp24 - 0x2000);
    }
    return 0;
}

s32 func_800301A4(s32 arg0, unk_func_8003013C_arg1* arg1) {
    UNUSED s32 pad;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        func_800102A4(&D_8006F088->unk_60.at, &D_8006F088->unk_60.eye, &sp28, &sp26, &sp24);
        arg1->unk_1C = (s16) (-0x2000 - sp26);
        arg1->unk_1E = (s16) (sp24 + 0x6000);
    }
    return 0;
}

s32 func_80030210(s32 arg0, unk_D_86002F58_004_000* arg1) {
    if (arg0 == 0) {
        D_80075F80->unk_20 = arg1;
    }
    return 0;
}

s32 func_80030228(s32 arg0, unk_func_80031270_024* arg1) {
    if (arg0 == 0) {
        D_80075F80->unk_24 = arg1;
    }
    return 0;
}

s32 func_80030240(s32 arg0, GraphNode* arg1) {
    s32 temp_v0;

    if (arg0 == 0) {
        temp_v0 = arg1->unk_14;
        switch (temp_v0) {                          /* irregular */
        case 0:
            D_80075F80->unk_28 = arg1;
            break;
        case 1:
            D_80075F80->unk_2C = arg1;
            break;
        case 2:
            D_80075F80->unk_30 = arg1;
            break;
        }
        arg1->unk_14 = 0;
    }
    return 0;
}

void func_800302A4(s32 arg0, s32 arg1) {
    s16 temp_a0;
    s16 temp_a1;
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_a2;
    s32 i;
    unk_D_800761B0* var = &D_800761B0[10];
    unk_D_800761B0* var2 = &D_800761B0[11];

    temp_v0 = arg0 - 0xC8;
    temp_v1 = arg0 + 0xC8;
    temp_a2 = arg1 + 0x2B;
    temp_a3 = arg1 - 0x2B;
    for(i = 0; i < 12; i+=2) {
        D_800761B0[i].unk_00 = temp_v0;
        D_800761B0[i].unk_08 = 0;
        D_800761B0[i + 1].unk_00 = temp_v1;
        D_800761B0[i + 1].unk_08 = 0x18E0;
        if (i < 10) {
            temp_a0 = temp_a2 - (i * 0xA);
            D_800761B0[i].unk_02 = temp_a0;
            D_800761B0[i + 1].unk_02 = temp_a0;
            temp_a1 = (i * 5) << 5;
            D_800761B0[i].unk_0A = temp_a1;
            D_800761B0[i + 1].unk_0A = temp_a1;
        } else {
            D_800761B0[10].unk_02 = temp_a3;
            var->unk_0A = 0x540;
            D_800761B0[11].unk_02 = temp_a3;
            var2->unk_0A = 0x540;
        }
    }
}

#ifdef NON_MATCHING
s32 func_800303C8(s32 arg0, UNUSED GraphNode* arg1) {
     char* sp16C;
    u8* sp40;
    char* temp_s2;
    s32 temp_v0;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_ra;
    s32 var_ra_2;
    s32 var_s1;
    s32 var_s2;
    s32 var_s4;
    s32 var_s5;
    s32 var_t4;
    s32 var_t4_2;
    s32 var_t5;
    s32 var_v0;
    s32 var_v1;

    temp_v0 = func_8002FF8C(arg0);
    if ((temp_v0 != 0) && (arg0 == 2)) {
        temp_s2 = (char*)((u8*)D_80075F84->unk_18 + 0x73);
        D_80075F9C = func_8001F5B0(0x10, 0, temp_s2);
        func_800302A4(0, -0x96);
        func_80006498(&gDisplayListHead, D_80075F90);
        func_8000699C(&gDisplayListHead, 0);
        gDPPipeSync(gDisplayListHead++);
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE3000C00;    _gfx->words.w1 = 0;    }
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE3001201;    _gfx->words.w1 = 0x2000;    }
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE3001402;    _gfx->words.w1 = 0xC00;    }
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE3000F00;    _gfx->words.w1 = 0;    }
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE3000D01;    _gfx->words.w1 = 0;    }
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE3000A01;    _gfx->words.w1 = 0;    }
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xFCFFFFFF;    _gfx->words.w1 = 0xFFFCF279;    }
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE200001C;    _gfx->words.w1 = 0x553048;    }
        sp16C = temp_s2;
        if (temp_v0 == 1) {
            var_t4 = 0;
            var_ra = 0xF;
            for (var_t5 = 0xE; var_t5 < 0x2C; var_t5 += 0xF) {
                {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xFD100063;    _gfx->words.w1 = &D_5001950;    }
                {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF5103200;    _gfx->words.w1 = 0x07080200;    }
                gDPLoadSync(gDisplayListHead++);
                {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = (s32) (((var_t4 * 4) & 0xFFF) | 0xF4000000);    _gfx->words.w1 = (s32) (((var_t5 * 4) & 0xFFF) | 0x0718C000);    }
                gDPPipeSync(gDisplayListHead++);
                {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF5103200;    _gfx->words.w1 = 0x80200;    }
                {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = (s32) (((var_t4 * 4) & 0xFFF) | 0xF2000000);    _gfx->words.w1 = (s32) (((var_t5 * 4) & 0xFFF) | 0x18C000);    }
                {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = (s32) (((var_ra * 4) & 0xFFF) | 0xE4190000);    _gfx->words.w1 = (var_t4 * 4) & 0xFFF;    }
                {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE1000000;    _gfx->words.w1 = (var_t4 << 5) & 0xFFFF;    }
                {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF1000000;    _gfx->words.w1 = 0x04000400;    }
                {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = (s32) (((var_ra * 4) & 0xFFF) | 0xE4320000);    _gfx->words.w1 = (s32) (((var_t4 * 4) & 0xFFF) | 0x190000);    }
                {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE1000000;    _gfx->words.w1 = (s32) (((var_t4 << 5) & 0xFFFF) | 0x0C800000);    }
                var_t4 += 0xF;
                var_ra += 0xF;
            }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xFD100063;    _gfx->words.w1 = &D_5001950;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF5103200;    _gfx->words.w1 = 0x07080200;    }
            gDPLoadSync(gDisplayListHead++);
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF4000078;    _gfx->words.w1 = 0x0718C0A8;    }
            gDPPipeSync(gDisplayListHead++);
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF5103200;    _gfx->words.w1 = 0x80200;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF2000078;    _gfx->words.w1 = 0x18C0A8;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE41900AC;    _gfx->words.w1 = 0x78;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE1000000;    _gfx->words.w1 = 0x3C0;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF1000000;    _gfx->words.w1 = 0x04000400;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE43200AC;    _gfx->words.w1 = 0x190078;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE1000000;    _gfx->words.w1 = 0x0C8003C0;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF1000000;    _gfx->words.w1 = 0xFC000400;    }
            func_8001F3F4();
            func_8001F470();
            func_8001F324(0xF0, 0x78, 0x6E, 0xFF);
            func_8001F36C(0xF0, 0xF0, 0x78, 0xFF);
            func_8001EBE0(0x10, 0);
            func_8001F1E8(0x64 - ((s32) D_80075F9C / 2), 5, sp16C);
            func_8001F4C4();
            func_8001F444();
        } else {
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xFD10001F;    _gfx->words.w1 = &D_5003AE8;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF5101000;    _gfx->words.w1 = 0x07080200;    }
            gDPLoadSync(gDisplayListHead++);
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF4000000;    _gfx->words.w1 = 0x0707C09C;    }
            gDPPipeSync(gDisplayListHead++);
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF5101000;    _gfx->words.w1 = 0x80200;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF2000000;    _gfx->words.w1 = 0x7C09C;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE42600A0;    _gfx->words.w1 = 0x40000;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE1000000;    _gfx->words.w1 = 0;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF1000000;    _gfx->words.w1 = 0x04000400;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE42E40A0;    _gfx->words.w1 = 0x260000;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE1000000;    _gfx->words.w1 = 0x04000000;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF1000000;    _gfx->words.w1 = 0xFC000400;    }
            func_8001F3F4();
            func_8001F470();
            func_8001F324(0xDC, 0xFF, 0xDC, 0xFF);
            func_8001F36C(0x78, 0xB4, 0xFF, 0xFF);
            func_8001EBE0(0x10, 0);
            func_8001F1E8(0x64 - ((s32) D_80075F9C / 2), 7, sp16C);
            func_8001F4C4();
            func_8001F444();
        }
        func_80006498(&gDisplayListHead, D_80075F84->unk_08);
        gDPPipeSync(gDisplayListHead++);
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE3000A01;    _gfx->words.w1 = 0;    }
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xFCFFFFFF;    _gfx->words.w1 = 0xFFFCF279;    }
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE200001C;    _gfx->words.w1 = 0x553048;    }
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xD7000002;    _gfx->words.w1 = -1;    }
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xDA380003;    _gfx->words.w1 = &D_8006F010;    }
        var_s4 = 0;
        var_s5 = 9;
        var_ra_2 = 0;
        var_s1 = 4;
        var_s2 = 2;
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0x0100C018;    _gfx->words.w1 = &D_800761B0;    }
        for (var_t4_2 = 6; var_t4_2 < 0x1A; var_t4_2 += 4) {
            var_s5 += 0xA;
            var_s4 += 0xA;
            var_v1 = var_s2 & 0xFF;
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = (s32) (((D_80075F94 - 1) & 0xFFF) | 0xFD100000);    _gfx->words.w1 = (s32) D_80075F90->img_p;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = (s32) (((((s32) ((D_80075F94 * 2) + 7) >> 3) & 0x1FF) << 9) | 0xF5100000);    _gfx->words.w1 = 0x07080200;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xE6000000;    _gfx->words.w1 = 0;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = (s32) (((var_s4 * 4) & 0xFFF) | 0xF4000000);    _gfx->words.w1 = (s32) (((((D_80075F94 - 1) * 4) & 0xFFF) << 0xC) | 0x07000000 | ((var_s5 * 4) & 0xFFF));    }
            gDPPipeSync(gDisplayListHead++);
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = (s32) (((((s32) ((D_80075F94 * 2) + 7) >> 3) & 0x1FF) << 9) | 0xF5100000);    _gfx->words.w1 = 0x80200;    }
            {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = (s32) (((var_s4 * 4) & 0xFFF) | 0xF2000000);    _gfx->words.w1 = (s32) (((((D_80075F94 - 1) * 4) & 0xFFF) << 0xC) | ((var_s5 * 4) & 0xFFF));    }
            {   
                Gfx *_gfx = (Gfx *)(gDisplayListHead++);
                var_v0 = var_s1 & 0xFF;
                if (var_t4_2 == 6) {
                    var_a0 = ((var_ra_2 & 0xFF) << 0x10) | (var_v0 << 8) | var_v1;
                } else {
                    var_v1 = var_s2 & 0xFF;
                    if (var_t4_2 == 8) {
                        var_v0 = var_s1 & 0xFF;
                        var_v1 = var_s2 & 0xFF;
                        var_a1 = (var_v0 << 0x10) | (var_v1 << 8) | (var_ra_2 & 0xFF);
                    } else {
                        var_v0 = var_s1 & 0xFF;
                        var_a1 = (var_v1 << 0x10) | ((var_ra_2 & 0xFF) << 8) | var_v0;
                    }
                    var_a0 = var_a1;
                }
                _gfx->words.w0 = (s32) (var_a0 | 0x06000000);
                if (var_t4_2 == 6) {
                    _gfx->words.w1 = (s32) ((var_v1 << 0x10) | (var_v0 << 8) | (var_t4_2 & 0xFF));
                } else {
                    if (var_t4_2 == 8) {
                        var_a0_2 = (var_v0 << 0x10) | ((var_t4_2 & 0xFF) << 8) | var_v1;
                    } else {
                        var_a0_2 = ((var_t4_2 & 0xFF) << 0x10) | (var_v1 << 8) | var_v0;
                    }
                    _gfx->words.w1 = var_a0_2;
                }
            }
            var_ra_2 += 4;
            var_s1 += 4;
            var_s2 += 4;
        }
        gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80075F94, D_80075F90->img_p);
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = (s32) (((((s32) ((D_80075F94 * 2) + 7) >> 3) & 0x1FF) << 9) | 0xF5100000);    _gfx->words.w1 = 0;    }
        gDPLoadSync(gDisplayListHead++);
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF40000A0;    _gfx->words.w1 = (s32) (((((D_80075F94 - 1) * 4) & 0xFFF) << 0xC) | 0x07000000 | (((D_80075F98 - 1) * 4) & 0xFFF));    }
        gDPPipeSync(gDisplayListHead++);
        gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, (((D_80075F94 * 2) + 7) >> 3), 0, 0, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        {    Gfx *_gfx = (Gfx *)(gDisplayListHead++);    _gfx->words.w0 = 0xF20000A0;    _gfx->words.w1 = (s32) (((((D_80075F94 - 1) * 4) & 0xFFF) << 0xC) | (((D_80075F98 - 1) * 4) & 0xFFF));    }
        gSP2Triangles(gDisplayListHead++, 9, 8, 10, 0, 11, 9, 10, 0);
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_800303C8.s")
#endif

void func_8003107C(unk_D_83402EE0_070* arg0, unk_func_80026268_arg0* arg1) {
    s32 i;

    bzero(arg0, sizeof(unk_D_83402EE0_070));
    arg0->unk_00 = arg1->unk_0E;
    arg0->unk_02 = arg1->unk_00.unk_00;

    for (i = 0; i < 11; i++) {
        arg0->unk_03[i] = ((s8*)arg1->unk_30)[i];
    }

    for (i = 0; i < 11; i++) {
        arg0->unk_0E[i] = ((s8*)arg1->unk_3B)[i];
    }
}

void func_80031140(unk_func_80026268_arg0* arg0, unk_D_83407AC8* arg1) {
    s32 i;

    bzero(arg0, sizeof(unk_func_80026268_arg0));

    arg0->unk_0E = arg1->unk_00;
    arg0->unk_00.unk_00 = arg1->unk_02;

    for (i = 0; i < 11; i++) {
        arg0->unk_30[i] = arg1->unk_03[i];
    }

    for (i = 0; i < 11; i++) {
        arg0->unk_3B[i] = arg1->unk_0E[i];
    }
}

void func_80031204(unk_func_80031270* arg0, UNUSED s16 arg1, UNUSED s16 arg2) {
    UNUSED s32 pad;
    MemoryBlock* sp18;

    sp18 = func_80002D10(main_pool_get_available(), 0);
    D_80075F80 = arg0;
    arg0->unk_1C = process_geo_layout(sp18, D_80075FA0);
    D_80075F80 = NULL;
    func_80002D60(sp18);
}

unk_func_80031270* func_80031270(s16 arg0, s16 arg1, unk_D_80068BB0* arg2, unk_D_80068BB0* arg3,
                                 unk_D_86002F58_004_000_010* arg4, BinArchive* arg5, unk_D_83403C60* arg6) {
    UNUSED unk_D_80068BB0* var_v0;
    unk_func_80031270* temp_v0 = main_pool_alloc(sizeof(unk_func_80031270), 0);

    if (temp_v0 != NULL) {
        temp_v0->unk_00 = 0;
        temp_v0->unk_02 = 0;
        temp_v0->unk_04 = arg0;
        temp_v0->unk_06 = arg1;

        if (arg2 != NULL) {
            temp_v0->unk_08 = arg2;
        } else {
            temp_v0->unk_08 = func_80006314(0, 2, arg0, arg1, 0);
        }

        if (arg3 != NULL) {
            temp_v0->unk_0C = arg3;
        } else {
            temp_v0->unk_0C = func_80006314(0, 2, arg0, arg1, 1);
        }

        func_80006414(temp_v0->unk_08, temp_v0->unk_0C);

        temp_v0->unk_10 = arg4;
        temp_v0->unk_14 = arg5;
        temp_v0->unk_18 = arg6;
        temp_v0->unk_34 = 0;

        if (D_80075F90 == 0) {
            D_80075F90 = func_80006314(0, 2, 0xC8, 0x2B, 0);
        }

        func_80031204(temp_v0, arg0, arg1);
    }
    return temp_v0;
}

void func_80031390(unk_func_80031270*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031390.s")

void func_800314BC(unk_func_80031270* arg0) {
    MemoryBlock* sp24;
    FragmentEntry sp20;
    u32* temp_v0;
    u32* temp_v0_2;
    u32* temp_v0_3;
    unk_func_800314BC_temp_v4* temp_v0_4;
    unk_func_80031270_024* temp_v1;

    func_8001103C(0, arg0->unk_28);
    func_8001103C(0, arg0->unk_2C);
    func_8001103C(0, arg0->unk_30);
    sp20 = func_8000484C(arg0->unk_14, D_8007616C[func_8002FF7C(arg0->unk_18)]);
    sp24 = func_80002D10(main_pool_get_available(), 0);
    temp_v0 = sp20(0, 0);
    if (temp_v0 != NULL) {
        func_80012094(arg0->unk_28, process_geo_layout(sp24, temp_v0));
    }
    temp_v0_2 = sp20(1, 0);
    if (temp_v0_2 != NULL) {
        func_80012094(arg0->unk_2C, process_geo_layout(sp24, temp_v0_2));
    }
    temp_v0_3 = sp20(3, 0);
    if (temp_v0_3 != NULL) {
        func_80012094(arg0->unk_30, process_geo_layout(sp24, temp_v0_3));
    }
    arg0->unk_34 = sp20(2, 0);
    func_80002D60(sp24);
    temp_v0_4 = sp20(4, 0);
    if (temp_v0_4 == NULL) {
        temp_v1 = arg0->unk_24;
        temp_v1->unk_01 = (u8) (temp_v1->unk_01 & 0xFFFE);
        arg0->unk_24->unk_14 = 0;
        return;
    }
    arg0->unk_24->unk_18 = (s16) temp_v0_4->unk_00;
    arg0->unk_24->unk_1A = (s16) temp_v0_4->unk_02;
    arg0->unk_24->unk_1C = (s32) temp_v0_4->unk_04;
    arg0->unk_24->unk_14 = 1;
    temp_v1 = arg0->unk_24;
    temp_v1->unk_01 = (u8) (temp_v1->unk_01 | 1);
}

#ifdef NON_MATCHING
u8* func_80031660(unk_func_80031270* arg0) {
    void* sp24;
    void (*sp20)();
    u32 temp_v0_2;
    void* v0_ptr;

    sp24 = (arg0->unk_18 + 0x50);
    sp20 = Util_ConvertAddrToVirtAddr(&func_8140C734);
    D_80075F84 = arg0;
    if (arg0->unk_00 == 1) {
        if (arg0->unk_02 != 1) {
            if (arg0->unk_02 == 2) {
                func_80031390(arg0);
                func_800314BC(arg0);
            }
        } else {
            func_80006498(&gDisplayListHead, arg0->unk_08);
            temp_v0_2 = arg0->unk_34;
            if ((temp_v0_2 == -1U) || (temp_v0_2 == 0)) {
                func_8000699C(&gDisplayListHead, 1);
            } else if (temp_v0_2 < 0x10000U) {
                func_8000699C(&gDisplayListHead, temp_v0_2 & 0xFFFF);
            } else {
                func_8000699C(&gDisplayListHead, 0xA6BF);
            }
            func_80015348();
            v0_ptr = Util_ConvertAddrToVirtAddr(&D_8140E6B8);
            v0_ptr = (s32) sp24;
            sp20();
            func_80015094(arg0->unk_1C);
        }
    }
    switch (arg0->unk_00) {                           /* irregular */
    case 0:
        arg0->unk_00 = 1U;
        arg0->unk_02 = 2;
        break;
    case 1:
        arg0->unk_02--;
        if (arg0->unk_02 <= 0) {
            arg0->unk_00 = 2U;
        }
        break;
    case 2:
        break;
    }
    return arg0->unk_08->img_p;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031660.s")
#endif
s32 func_800317D8(unk_func_80031270* arg0) {
    s32 var_v1;
    s32 sp1C;
    unk_D_83403C60* temp_a0;

    var_v1 = 0;
    if (arg0 != NULL) {
        temp_a0 = arg0->unk_18;
        if (temp_a0 != 0) {
            sp1C = 0;
            var_v1 = sp1C;
            if (func_800318C4(temp_a0) != 0) {
                var_v1 = 1;
            }
        }
    }
    return var_v1;
}

s32 func_8003181C(unk_func_80031270** arg0, s32 arg1) {
    unk_func_80031270* temp_s1;
    s32 sp30;
    s32 i;

    sp30 = -1;

    for (i = 0; i < arg1; i++) {
        temp_s1 = arg0[i];
        if ((func_800317D8(temp_s1) != 0) && (temp_s1->unk_00 == 1)) {
            sp30 = i;
            break;
        }
    }
    return sp30;
}

unk_func_80031270* func_800318AC(void) {
    return D_80075F84;
}

void func_800318B8(void) {
    D_80075F84 = 0;
}

s32 func_800318C4(unk_D_83403C60* arg0) {
    s32 v1 = 0;

    if ((arg0->unk_00.unk_04 > 0 && arg0->unk_00.unk_04 < 0x98) || arg0->unk_00.unk_04 == 0x99) {
        v1 = 1;
    }
    return v1;
}

void func_800318F0(void) {
    func_80036790();
}

void func_80031910(Mtx* mtx, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 sp144;
    f32 sp140;
    f32 temp_fa0;
    f32 temp_fa1;
    UNUSED s32 pad[1];
    Mtx spF0;
    Mtx spB0;
    Mtx sp70;
    UNUSED s32 pad2[16];

    temp_fa1 = arg4 - arg1;
    temp_fa0 = arg6 - arg3;
    sp140 = (f32) (((f64) (f32) MathUtil_Atan2s(temp_fa0, temp_fa1) * D_8007C538) / D_8007C540);
    sp144 = (f32) (((f64) (f32) MathUtil_Atan2s(arg5 - arg2, sqrtf((temp_fa1 * temp_fa1) + (temp_fa0 * temp_fa0))) * D_8007C548) / D_8007C550);
    guRotate(&spB0, sp140, 0.0f, 1.0f, 0.0f);
    guRotate(&sp70, sp144, 0.0f, 0.0f, 1.0f);
    guMtxCatL(&spB0, &sp70, &spF0);
    *mtx = spF0;
}

f32 func_80031A6C(f32 arg0) {
    if (arg0 < 0.0) {
        arg0 = -arg0;
    }
    return arg0;
}

void func_80031A94(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32* arg6, f32* arg7, f32* arg8) {
    *arg6 = (arg1 * arg5) - (arg2 * arg4);
    *arg7 = (arg2 * arg3) - (arg0 * arg5);
    *arg8 = (arg0 * arg4) - (arg1 * arg3);
}

void func_80031B04(f32* arg0, f32* arg1, f32* arg2) {
    f32 temp_fv1;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_fv0;

    temp_fv1 = *arg0;
    temp_fa1 = *arg1;
    temp_ft4 = *arg2;
    temp_fv0 = sqrtf((temp_fv1 * temp_fv1) + (temp_fa1 * temp_fa1) + (temp_ft4 * temp_ft4));
    if (temp_fv0 > 0.0f) {
        temp_fv1 /= temp_fv0;
        temp_fa1 /= temp_fv0;
        temp_ft4 /= temp_fv0;
    }
    *arg0 = temp_fv1;
    *arg1 = temp_fa1;
    *arg2 = temp_ft4;
}

void func_80031B98(const f32* a, const f32* b, f32* out) {
    f32 ax = a[0];
    f32 ay = a[1];
    f32 az = a[2];

    f32 bx = b[0];
    f32 by = b[1];
    f32 bz = b[2];

    out[0] = (ay * bz) - (az * by);
    out[1] = (az * bx) - (ax * bz);
    out[2] = (ax * by) - (ay * bx);
}

void func_80031BE8(Vec3f* vec) {
    f32 x;
    f32 y;
    f32 z;
    f32 len;

    x = vec->x;
    y = vec->y;
    z = vec->z;

    len = sqrtf((x * x) + (y * y) + (z * z));

    if (len > 0.0f) {
        x = x / len;
        y = y / len;
        z = z / len;
    }

    vec->x = x;
    vec->y = y;
    vec->z = z;
}

void func_80031C6C(Mtx* mtx, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 sp10C;
    f32 sp108;
    UNUSED s32 pad;
    UNUSED s32 pad2;
    f32 temp_fa1;
    f32 temp_fv0;
    Mtx spB8;
    Mtx sp78;
    Mtx sp38;

    temp_fa1 = arg4 - arg1;
    temp_fv0 = arg6 - arg3;
    sp108 = (f32) (((f64) (f32) MathUtil_Atan2s(-temp_fv0, temp_fa1) * D_8007C558) / D_8007C560);
    sp10C = (f32) (((f64) (f32) MathUtil_Atan2s(-(arg5 - arg2), sqrtf((temp_fa1 * temp_fa1) + (temp_fv0 * temp_fv0))) * D_8007C568) / D_8007C570);
    guTranslate(&spB8, arg1, arg2, arg3);
    guRotate(&sp78, sp108, 0.0f, -1.0f, 0.0f);
    guMtxCatL(&sp78, &spB8, &spB8);
    guRotate(&sp38, sp10C, 1.0f, 0.0f, 0.0f);
    guMtxCatL(&sp38, &spB8, &spB8);
    *mtx = spB8;
}

void func_80031DF8(
    f32 px, f32 py, f32 pz,
    f32 ax, f32 ay, f32 az,
    f32 bx, f32 by, f32 bz,
    f32* outX, f32* outY, f32* outZ
) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 t;
    f32 lenSq = SQ(bx - ax) + SQ(by - ay) + SQ(bz - az);
    f32 dx2;
    f32 dy2;
    f32 dz2;

    if (lenSq == 0.0) {
        *outX = ax;
        *outY = ay;
        *outZ = az;
        return;
    }

    
    dx = bx - ax;
    dy = by - ay;
    dz = bz - az;
    dx2 = px - ax;
    dy2 = py - ay;
    dz2 = pz - az;

    t = ((dx * dx2) + (dy * dy2) + (dz * dz2)) / lenSq;

    *outX = ax + (t * dx);
    *outY = ay + (t * dy);
    *outZ = az + (t * dz);
}

void func_80031EF4(MtxF* arg0, MtxF* arg1) {
    f32 sp24 = sqrtf(SQ(arg1->mf[0][0]) + SQ(arg1->mf[0][1]) + SQ(arg1->mf[0][2]));
    f32 sp20 = sqrtf(SQ(arg1->mf[1][0]) + SQ(arg1->mf[1][1]) + SQ(arg1->mf[1][2]));
    f32 sp1C = sqrtf(SQ(arg1->mf[2][0]) + SQ(arg1->mf[2][1]) + SQ(arg1->mf[2][2]));

    arg0->mf[0][0] = arg1->mf[0][0] * sp24;
    arg0->mf[0][1] = arg1->mf[1][0] * sp24;
    arg0->mf[0][2] = arg1->mf[2][0] * sp24;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = arg1->mf[0][1] * sp20;
    arg0->mf[1][1] = arg1->mf[1][1] * sp20;
    arg0->mf[1][2] = arg1->mf[2][1] * sp20;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = arg1->mf[0][2] * sp1C;
    arg0->mf[2][1] = arg1->mf[1][2] * sp1C;
    arg0->mf[2][2] = arg1->mf[2][2] * sp1C;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = 0.0f;
    arg0->mf[3][1] = 0.0f;
    arg0->mf[3][2] = 0.0f;
    arg0->mf[3][3] = 1.0f;
}

void func_80032034(MtxF* arg0, Vec3f* arg1) {
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    temp_fv0 = arg0->mf[0][0];
    temp_fv1 = arg0->mf[0][1];
    temp_fa1 = arg0->mf[0][2];

    sp30 = arg0->mf[1][0];
    sp2C = arg0->mf[1][1];
    sp28 = arg0->mf[1][2];

    sp24 = arg0->mf[2][0];
    sp20 = arg0->mf[2][1];
    sp1C = arg0->mf[2][2];

    arg1->x = sqrtf(SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_fa1));
    arg1->y = sqrtf(SQ(sp30) + SQ(sp2C) + SQ(sp28));
    arg1->z = sqrtf(SQ(sp24) + SQ(sp20) + SQ(sp1C));
}
