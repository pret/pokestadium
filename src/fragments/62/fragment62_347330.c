#include "fragment62.h"
#include "src/30640.h"
#include "src/6A40.h"
#include "src/math_util.h"
#include "include/math.h"

typedef struct unk_D_843951D0_1010 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ s16 unk_10;
} unk_D_843951D0_1010; // size = 0x14

typedef struct unk_D_843951D0 {
    /* 0x0000 */ s16 unk_0000;
    /* 0x0004 */ f32 unk_0004;
    /* 0x0008 */ s16 unk_0008;
    /* 0x000A */ s16 unk_000A;
    /* 0x000C */ Vtx* unk_000C;
    /* 0x0010 */ char unk0010[0x1000];
    /* 0x1010 */ unk_D_843951D0_1010 unk_1010[16][16];
} unk_D_843951D0; // size >= 0x2410

static unk_D_843925E0 D_843925E0[4];
static s16 D_843951C0;
static s16 D_843951C2;
static s32 pad_D_843951C8[2];
static unk_D_843951D0 D_843951D0;
static s16 D_843975E0;
static s16 D_843975E2;
static s16 D_843975E4;
static unk_D_843975E8 D_843975E8;

func_D_84390320 D_84388280[] = {
    func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_8435BED8, func_84359684, func_843593A0,
    func_84359FE0, func_843593A0, func_843593A0, func_843593A0, func_8435A7F0, func_843593A0, func_843593A0,
    func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_84359C84, func_843593A0,
    func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_8435B8E8, func_843593A0,
    func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_8435A298, func_843593A0,
    func_843593A0, func_84359A00, func_843593A0, func_843593A0, func_8435C96C, func_843593A0, func_843593A0,
    func_8435ABF0, func_8435AC94, func_8435AD38, func_8435ADDC, func_843593A0, func_8435BB64, func_843593A0,
    func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_84359910, func_843593A0,
    func_843593A0, func_8435A9F0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_8435B0B0,
    func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_8435B2C8, func_843593A0, func_843593A0,
    func_8435C448, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0,
    func_8435C220, func_8435B580, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0,
    func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0,
    func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0,
    func_8435A6F8, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0,
    func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0,
    func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0,
    func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0,
    func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0,
    func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0,
    func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0, func_843593A0,
    func_843593A0, func_843593A0, func_843593A0,
};

func_D_84390320 D_843884D8[] = {
    func_843593A8, func_84359750, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8,
    func_843593A8, func_843593A8, func_84359D7C, func_843593A8, func_843593A8, func_843593A8, func_843593A8,
    func_843593A8, func_843593A8, func_84359AE0, func_843593A8, func_843593A8, func_84359820, func_843593A8,
    func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8,
    func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_8435A390, func_8435A480, func_843593A8,
    func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8,
    func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_84359684,
    func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8,
    func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8,
    func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8,
    func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8,
    func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8,
    func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8,
    func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8, func_843593A8,
    func_843593A8, func_843593A8,
};

func_D_84390320 D_84388668[] = {
    func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_8435BF08, func_843596DC, func_843593B0,
    func_8435A014, func_843593B0, func_843593B0, func_843593B0, func_8435A81C, func_843593B0, func_843593B0,
    func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_84359CB8, func_843593B0,
    func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_8435B918, func_843593B0,
    func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_8435A2CC, func_843593B0,
    func_843593B0, func_84359A6C, func_843593B0, func_843593B0, func_8435C9AC, func_843593B0, func_843593B0,
    func_8435AC20, func_8435ACC4, func_8435AD68, func_8435AE08, func_843593B0, func_8435BB98, func_843593B0,
    func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_8435998C, func_843593B0,
    func_843593B0, func_8435AA1C, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_8435B0DC,
    func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_8435B408, func_843593B0, func_843593B0,
    func_8435C478, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0,
    func_8435C250, func_8435B5B4, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0,
    func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0,
    func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0,
    func_8435A72C, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0,
    func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0,
    func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0,
    func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0,
    func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0,
    func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0,
    func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0, func_843593B0,
    func_843593B0, func_843593B0, func_843593B0,
};

func_D_84390320 D_843888C0[] = {
    func_843593B8, func_843597AC, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8,
    func_843593B8, func_843593B8, func_84359DF4, func_843593B8, func_843593B8, func_843593B8, func_843593B8,
    func_843593B8, func_843593B8, func_84359AE8, func_843593B8, func_843593B8, func_8435989C, func_843593B8,
    func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8,
    func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_8435A40C, func_8435A4F8, func_843593B8,
    func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8,
    func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843596DC,
    func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8,
    func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8,
    func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8,
    func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8,
    func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8,
    func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8,
    func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8, func_843593B8,
    func_843593B8, func_843593B8,
};

func_D_84390320 D_84388A50[] = {
    func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_8435BF28, func_843596FC, func_843593C0,
    func_8435A084, func_843593C0, func_843593C0, func_843593C0, func_8435A99C, func_843593C0, func_843593C0,
    func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_84359D28, func_843593C0,
    func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_8435B938, func_843593C0,
    func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_8435A33C, func_843593C0,
    func_843593C0, func_84359A8C, func_843593C0, func_843593C0, func_8435CA08, func_843593C0, func_843593C0,
    func_8435AC40, func_8435ACE4, func_8435AD88, func_8435B048, func_843593C0, func_8435BBEC, func_843593C0,
    func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843599AC, func_843593C0,
    func_843593C0, func_8435AB9C, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_8435B260,
    func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_8435B454, func_843593C0, func_843593C0,
    func_8435C498, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0,
    func_8435C270, func_8435B600, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0,
    func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0,
    func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0,
    func_8435A79C, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0,
    func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0,
    func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0,
    func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0,
    func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0,
    func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0,
    func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0, func_843593C0,
    func_843593C0, func_843593C0, func_843593C0,
};

func_D_84390320 D_84388CA8[] = {
    func_843593C8, func_843597CC, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8,
    func_843593C8, func_843593C8, func_84359E14, func_843593C8, func_843593C8, func_843593C8, func_843593C8,
    func_843593C8, func_843593C8, func_84359AF0, func_843593C8, func_843593C8, func_843598BC, func_843593C8,
    func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8,
    func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_8435A42C, func_8435A518, func_843593C8,
    func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8,
    func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843596FC,
    func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8,
    func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8,
    func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8,
    func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8,
    func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8,
    func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8,
    func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8, func_843593C8,
    func_843593C8, func_843593C8,
};

static s32 pad_D_84388E38[2] = { 0, 0 };

static Gfx D_84388E40[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetColorDither(G_CD_NOISE),
    gsSPEndDisplayList(),
};

void func_8435CA70(void) {
    unk_D_843925E0* ptr = &D_843925E0[0];
    s32 i;

    for (i = 0; i < 4; i++) {
        ptr->unk_018 = ptr->unk_000 = 0;
        ptr++;
    }
}

void func_8435CAA8(unk_D_843925E0* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                   s32 arg9) {
    arg0->unk_028 = arg1;
    arg0->unk_02C = arg2;
    arg0->unk_030 = arg3;
    arg0->unk_038 = arg4;
    arg0->unk_03C = arg5;
    arg0->unk_040 = arg6;
    arg0->unk_024 = arg7;
    arg0->unk_034 = arg8;
    arg0->unk_044 = arg9;
}

void func_8435CAE8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    unk_D_843925E0* ptr;
    unk_D_843925E0_430* ptr1;
    unk_D_843925E0_430* ptr2;
    unk_D_843925E0_430* ptr3;
    s32 i;
    u8 temp_lo;
    u8 temp_lo_2;
    s32 temp_v0_2;
    s32 var_v1;
    u8 temp_a0;
    u8 temp_a1;
    u8 temp_v1;

    var_v1 = -1;

    for (i = 0; i < 4; i++) {
        if (D_843925E0[i].unk_000 == 0) {
            var_v1 = i;
            break;
        }
    }

    if (var_v1 == -1) {
        return;
    }

    ptr = &D_843925E0[var_v1];

    ptr->unk_000 = 1;
    ptr->unk_018 = 0;
    ptr->unk_004 = arg0;
    ptr->unk_00C = arg2;
    ptr->unk_010 = arg3 * arg4;
    ptr->unk_014 = arg4;
    ptr->unk_01E = -1;

    switch (arg5) {
        case 0:
            ptr->unk_01C = 1;
            ptr->unk_008 = (arg4 * 0.0) + arg1;
            ptr->unk_01A = 0x3C;
            ptr->unk_020 = 1.5f;
            func_8435CAA8(&D_843925E0[var_v1], 0xFF, 0xFF, 0xC8, 0x20, 0x20, 0xFF, 0x80, 0x80, 0xFF);
            ptr->unk_01E = func_8436E944();
            break;

        case 1:
            ptr->unk_01C = -1;
            ptr->unk_01A = 0x78;
            ptr->unk_008 = (arg4 * 100.0) + arg1;
            ptr->unk_020 = 1.5f;
            func_8435CAA8(&D_843925E0[var_v1], 0xFF, 0xFF, 0xC8, 0xFF, 0x20, 0x20, 0x80, 0x80, 0);
            break;

        default:
        case 2:
            ptr->unk_01C = 1;
            ptr->unk_008 = (arg4 * 0.0) + arg1;
            ptr->unk_01A = 0x1E;
            ptr->unk_020 = 1.5f;
            break;
    }

    ptr1 = &ptr->unk_430[0];
    for (i = 0; i < 31; i++) {
        ptr2 = ptr1++;
        ptr3 = ptr1++;

        switch (arg5) {
            case 0:
                temp_v0_2 = ((i % 3) * 2) + 1;
                temp_lo = 0x44 / temp_v0_2;
                temp_lo_2 = 0xFF / temp_v0_2;

                ptr2->unk_10.r = 0x66;
                ptr2->unk_10.g = ((temp_lo * 6) + 0x3FC) / 10;
                ptr2->unk_10.b = ((temp_lo_2 * 6) + 0x3FC) / 10;
                ptr2->unk_10.a = 0xFF;

                ptr3->unk_10.r = 0;
                ptr3->unk_10.g = temp_lo;
                ptr3->unk_10.b = temp_lo_2;
                ptr3->unk_10.a = 0;

                ptr2->unk_0E = 0x20;
                ptr3->unk_0E = 0x7E0;
                break;

            case 1:
                temp_v0_2 = ((i % 3) * 2) + 1;
                temp_lo = 0xFF / temp_v0_2;
                temp_lo_2 = 0x44 / temp_v0_2;

                ptr2->unk_10.r = ((temp_lo * 4) + 0x5FA) / 10;
                ptr2->unk_10.g = ((temp_lo_2 * 4) + 0x5FA) / 10;
                ptr2->unk_10.b = 0x99;
                ptr2->unk_10.a = 0x10;

                ptr3->unk_10.r = temp_lo;
                ptr3->unk_10.g = temp_lo_2;
                ptr3->unk_10.b = 0;
                ptr3->unk_10.a = 0;

                ptr2->unk_0E = 0x7E0;
                ptr3->unk_0E = 0x20;
                break;

            default:
            case 2:
                temp_v1 = (((u32)(i & 0x3F) >> 4) & 3) << 6;
                temp_a0 = (((u32)(i & 0x3F) >> 2) & 3) << 6;
                temp_a1 = ((u32)(i & 0x3F) & 3) << 6;

                ptr2->unk_10.r = ((temp_v1 * 6) + 0x3FC) / 10;
                ptr2->unk_10.g = ((temp_a0 * 6) + 0x3FC) / 10;
                ptr2->unk_10.b = ((temp_a1 * 6) + 0x3FC) / 10;
                ptr2->unk_10.a = 0xFF;

                ptr3->unk_10.r = temp_v1;
                ptr3->unk_10.g = temp_a0;
                ptr3->unk_10.b = temp_a1;
                ptr3->unk_10.a = 0;

                ptr2->unk_0E = 0x20;
                ptr3->unk_0E = 0x7E0;
                break;
        }

        ptr2->unk_0C = ((i % 31) * 0x3000) / 30;
        ptr3->unk_0C = ptr2->unk_0C;
        ptr2->unk_18 = 0.0f;
        ptr2->unk_14 = (i * TWO_PI) / 30.0;
        ptr2->unk_00 = (__cosf((i * TWO_PI) / 30.0) * (arg3 * arg4)) + arg0;
        ptr2->unk_04 = ptr->unk_008;

        if (ptr2->unk_04 < 0.0) {
            ptr2->unk_04 = 0.0f;
        }
        ptr2->unk_08 = (__sinf(ptr2->unk_14) * (arg3 * arg4)) + arg2;

        ptr3->unk_18 = 0.0f;
        ptr3->unk_14 = ptr2->unk_14;
        ptr3->unk_00 = ptr2->unk_00;
        ptr3->unk_04 = ptr->unk_008;
        if (ptr3->unk_04 < 0.0) {
            ptr3->unk_04 = 0.0f;
        }

        ptr3->unk_08 = ptr2->unk_08;
    }
}

void func_8435D1E8(unk_D_843925E0* arg0) {
    s32 var_v0;

    if (arg0->unk_01C >= 0) {
        if ((arg0->unk_01A - 0x1E) < arg0->unk_018) {
            var_v0 = arg0->unk_044 - 0xA;
            if (var_v0 < 0) {
                var_v0 = 0;
            }
            arg0->unk_044 = var_v0;
        }
    } else {
        var_v0 = arg0->unk_044 + 8;
        if (var_v0 >= 0x100) {
            var_v0 = 0xFF;
        }
        arg0->unk_044 = var_v0;
    }
}

s32 func_8435D24C(unk_D_843925E0* arg0) {
    unk_D_843925E0_430* temp_s0;
    unk_D_843925E0_430* temp_s1;
    unk_D_843925E0_430* ptr;
    s32 i;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 temp_fa0;
    s16 temp_s6;
    s16 var_s5;
    Vtx* var_s2;
    s32 tmp;

    ptr = &arg0->unk_430[0];

    arg0->unk_018++;
    tmp = arg0->unk_018;

    sp9C = arg0->unk_010;
    sp80 = arg0->unk_004;
    sp7C = arg0->unk_008;
    sp78 = arg0->unk_00C;
    sp98 = arg0->unk_014;
    temp_s6 = arg0->unk_01C;
    sp84 = arg0->unk_020 * tmp;

    var_s2 = &arg0->unk_050[0];
    func_8435D1E8(arg0);

    var_s5 = 0;
    sp94 = 0.0f;
    sp90 = 0.0f;
    sp8C = 0.0f;
    sp88 = 0.0f;

    for (i = 0; i < 31; i++) {
        temp_s0 = ptr++;
        temp_s1 = ptr++;

        if (i == 0x1E) {
            sp94 = 0.0f;
            sp90 = 0.0f;
            sp8C = 0.0f;
            sp88 = 0.0f;
        }
        temp_s0->unk_18 += 0.4;
        temp_s0->unk_14 -= 0.06f;

        if (temp_s6 != -1) {
            if (temp_s6 == 1) {
                temp_s0->unk_04 = ((((2.0 * __sinf(temp_s0->unk_14 + temp_s0->unk_18 + sp94)) -
                                     (__cosf(temp_s0->unk_14 + temp_s0->unk_18 + sp90) * 3.0)) +
                                    sp84) *
                                   sp98) +
                                  sp7C;
                temp_s1->unk_04 = (((((5.0 * __sinf(temp_s1->unk_14 + temp_s1->unk_18 + sp8C)) -
                                      (__cosf(temp_s1->unk_14 + temp_s1->unk_18 + sp88) * 3.0)) +
                                     sp84) *
                                    sp98) +
                                   sp7C) -
                                  50.0;

                if (temp_s1->unk_04 > 400.0) {
                    var_s5++;
                }

                if (temp_s0->unk_04 < 0.0) {
                    temp_s0->unk_04 = 0.0f;
                }

                if (temp_s1->unk_04 < 0.0) {
                    temp_s1->unk_04 = 0.0f;
                }
            }
        } else {
            temp_s0->unk_04 = sp7C - ((((2.0 * __sinf(temp_s0->unk_14 + temp_s0->unk_18 + sp94)) -
                                        (__cosf(temp_s0->unk_14 + temp_s0->unk_18 + sp90) * 3.0)) +
                                       sp84) *
                                      sp98);
            temp_s1->unk_04 = (sp7C - ((((5.0 * __sinf(temp_s1->unk_14 + temp_s1->unk_18 + sp8C)) -
                                         (__cosf(temp_s1->unk_14 + temp_s1->unk_18 + sp88) * 3.0)) +
                                        sp84) *
                                       sp98)) -
                              50.0;

            if (temp_s0->unk_04 < 0.0) {
                var_s5++;
                temp_s0->unk_04 = 0.0f;
            }

            if (temp_s1->unk_04 < 0.0) {
                temp_s1->unk_04 = 0.0f;
            }
        }

        temp_s1->unk_18 += 0.3;
        temp_s1->unk_14 += 0.08;

        var_s2->v.ob[0] = temp_s0->unk_00;
        var_s2->v.ob[1] = temp_s0->unk_04;
        var_s2->v.ob[2] = temp_s0->unk_08;
        var_s2->v.tc[0] = temp_s0->unk_0C;
        var_s2->v.tc[1] = temp_s0->unk_0E;
        var_s2->v.cn[0] = temp_s0->unk_10.r;
        var_s2->v.cn[1] = temp_s0->unk_10.g;
        var_s2->v.cn[2] = temp_s0->unk_10.b;
        var_s2->v.cn[3] = temp_s0->unk_10.a;
        var_s2++;

        var_s2->v.ob[0] = temp_s1->unk_00;
        var_s2->v.ob[1] = temp_s1->unk_04;
        var_s2->v.ob[2] = temp_s1->unk_08;
        var_s2->v.tc[0] = temp_s1->unk_0C;
        var_s2->v.tc[1] = temp_s1->unk_0E;
        var_s2->v.cn[0] = temp_s1->unk_10.r;
        var_s2->v.cn[1] = temp_s1->unk_10.g;
        var_s2->v.cn[2] = temp_s1->unk_10.b;
        var_s2->v.cn[3] = temp_s1->unk_10.a;
        var_s2++;

        sp94 += 2.4;
        sp90 += 1.8;
        sp8C += 1.6;
        sp88 += 1.2;
    }

    if (temp_s6 == 1) {
        f32 tmp1;
        f32 tmp2;

        temp_fa0 = ((guRandom() % 360) * TWO_PI_F) / 360.0f;
        tmp1 = __cosf(temp_fa0) * sp9C;
        tmp2 = __sinf(temp_fa0) * sp9C;

        func_8436EA0C(arg0->unk_01E, sp80 + tmp1, sp7C + sp84, sp78 + tmp2, 0xA, 0.75f);
        func_8436EB54(arg0->unk_01E);
    }

    if (var_s5 >= 0x1F) {
        return -1;
    }
    return 0;
}

s32 func_8435D8C0(void) {
    s32 i;
    s32 var_s2;
    unk_D_843925E0* ptr = &D_843925E0[0];

    D_843951C0 = (D_843951C0 + 1) & 0x3FFF;
    D_843951C2 = (D_843951C2 - 1) & 0x3FFF;
    var_s2 = -1;

    for (i = 0; i < 4; i++, ptr++) {
        if (ptr->unk_000 == 1) {
            if (func_8435D24C(ptr) == 0) {
                var_s2 = 0;
            } else {
                ptr->unk_000 = 0;
            }
        }
    }

    return var_s2;
}

Gfx* func_8435D97C(Gfx* arg0, unk_D_843925E0* arg1) {
    s32 i;
    Vtx* temp_v0 = func_80005F5C(sizeof(Vtx) * 62);
    Vtx* vtx = temp_v0;
    Vtx* var_a0 = &arg1->unk_050[0];

    for (i = 0; i < 31; i++) {
        *vtx++ = *var_a0++;
        *vtx++ = *var_a0++;
    }

    vtx = temp_v0;
    for (i = 0; i < 30; i++) {
        gSPVertex(arg0++, vtx, 4, 0);
        gSP2Triangles(arg0++, 0, 2, 1, 0, 2, 3, 1, 0);
        vtx += 2;
    }

    return arg0;
}

Gfx* func_8435DB14(Gfx* arg0) {
    static Gfx D_84388E88[] = {
        gsDPPipeSync(),
        gsDPSetCycleType(G_CYC_2CYCLE),
        gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                              G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
        gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
        gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
        gsDPPipeSync(),
        gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
        gsDPSetTexturePersp(G_TP_PERSP),
        gsDPSetTextureDetail(G_TD_CLAMP),
        gsDPSetTextureLOD(G_TL_TILE),
        gsDPSetTextureLUT(G_TT_NONE),
        gsDPSetTextureConvert(G_TC_FILT),
        gsDPSetTextureFilter(G_TF_BILERP),
        gsDPSetCombineLERP(TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, TEXEL1, TEXEL0, PRIMITIVE, TEXEL0, PRIMITIVE,
                           ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, ENVIRONMENT, 0),
        gsSPEndDisplayList(),
    };

    static Gfx D_84388F00[] = {
        gsDPPipeSync(),
        gsDPSetCycleType(G_CYC_1CYCLE),
        gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                              G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
        gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
        gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
        gsDPPipeSync(),
        gsDPSetRenderMode(AA_EN | Z_CMP | IM_RD | CLR_ON_CVG | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL |
                              GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA),
                          AA_EN | Z_CMP | IM_RD | CLR_ON_CVG | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL |
                              GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)),
        gsDPSetTexturePersp(G_TP_PERSP),
        gsDPSetTextureDetail(G_TD_CLAMP),
        gsDPSetTextureLOD(G_TL_TILE),
        gsDPSetTextureLUT(G_TT_NONE),
        gsDPSetTextureConvert(G_TC_FILT),
        gsDPSetTextureFilter(G_TF_BILERP),
        gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
        gsSPEndDisplayList(),
    };

    unk_D_843925E0* ptr = &D_843925E0[0];
    s32 i;

    gSPDisplayList(arg0++, D_84388E88);
    gDPPipeSync(arg0++);
    gDPLoadTextureTile_4b(arg0++, D_843920C0[0x43], G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                          G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetTileSize(arg0++, G_TX_RENDERTILE, D_843951C0, 0, (D_843951C0 + 0x1F), 0x001F);
    gDPLoadMultiTile_4b(arg0++, D_843920C0[0x44], 0x0100, 1, G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetTileSize(arg0++, 1, D_843951C2, 0, (D_843951C2 + 0x1F), 0x001F);

    for (i = 0; i < 4; i++, ptr++) {
        if (ptr->unk_000 == 1) {
            gDPSetPrimColor(arg0++, 0, ptr->unk_024, ptr->unk_028, ptr->unk_02C, ptr->unk_030, ptr->unk_034);
            gDPSetEnvColor(arg0++, ptr->unk_038, ptr->unk_03C, ptr->unk_040, ptr->unk_044);

            gSPClearGeometryMode(arg0++, G_CULL_BACK);
            gSPSetGeometryMode(arg0++, G_CULL_FRONT);

            arg0 = func_8435D97C(arg0, ptr);

            gSPClearGeometryMode(arg0++, G_CULL_FRONT);
            gSPSetGeometryMode(arg0++, G_CULL_BACK);

            arg0 = func_8435D97C(arg0, ptr);
        }
    }

    ptr = &D_843925E0[0];
    for (i = 0; i < 4; i++, ptr++) {
        if (ptr->unk_000 == 1) {
            arg0 = func_8436EDE8(ptr->unk_01E, arg0);
        }
    }

    return arg0;
}

void func_8435DED0(unk_D_843975E8* arg0, f32 arg1) {
    unk_D_86002F34_00C* spB4 = func_8432FD64();
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 var_fs0;
    f32 sp94;
    UNUSED s32 pad;
    f32 sp8C;
    f32 sp44;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp40;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;

    spB0 = spB4->unk_60.eye.x;
    spAC = spB4->unk_60.eye.y;
    spA8 = spB4->unk_60.eye.z;

    sp9C = spB4->unk_60.at.x;
    spA0 = spB4->unk_60.at.y;
    spA4 = spB4->unk_60.at.z;

    sp78 = spB4->unk_60.up.x;
    sp74 = spB4->unk_60.up.y;
    sp70 = spB4->unk_60.up.z;

    sp4C = spB4->unk_24.fovy;
    sp48 = sp4C / 30.0f;
    sp8C = spB4->unk_24.near;

    sp84 = sp9C - spB0;
    sp80 = spA0 - spAC;
    sp7C = spA4 - spA8;

    func_80031B04(&sp84, &sp80, &sp7C);

    sp44 = (sp4C * TWO_PI) / 720.0;
    sp40 = sp8C + arg1;

    arg0->unk_00 = (sp40 * sp84) + spB0;
    arg0->unk_04 = (sp40 * sp80) + spAC;
    arg0->unk_08 = (sp40 * sp7C) + spA8;

    sp50 = __cosf(sp44);
    if (sp50 != 0.0) {
        var_fs0 = (__sinf(sp44) * sp40) / sp50;
    } else {
        var_fs0 = 0.0f;
    }

    var_fs0 = func_80031A6C(var_fs0);
    sp94 = spB4->unk_24.aspect * var_fs0 * sp48 * 1.2f;

    func_80031A94(sp84, sp80, sp7C, sp78, sp74, sp70, &sp68, &sp64, &sp60);
    func_80031A94(sp84, sp80, sp7C, sp68, sp64, sp60, &sp5C, &sp58, &sp54);
    func_80031B04(&sp68, &sp64, &sp60);
    func_80031B04(&sp5C, &sp58, &sp54);

    arg0->unk_0C = sp68 * sp94;
    arg0->unk_10 = sp64 * sp94;
    arg0->unk_14 = sp60 * sp94;

    arg0->unk_18 = sp5C * var_fs0;
    arg0->unk_1C = sp58 * var_fs0;
    arg0->unk_20 = sp54 * var_fs0;
}

f32 func_8435E158(f32 arg0, f32 arg1, f32* arg2) {
    UNUSED s32 pad1[2];
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    UNUSED s32 pad2[8];
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;
    s32 var_a0;
    s32 var_v1;
    f32 sp54;
    f32 sp50;
    f32 sp4C;

    var_v1 = ((arg0 + 440.0f) / 150.0f) + 8.0f;
    var_a0 = (arg1 / 200.0f) + 8.0f;

    if (var_v1 < 0) {
        var_v1 = 0;
    }

    if (var_v1 >= 0xF) {
        var_v1 = 0xE;
    }

    if (var_a0 < 0) {
        var_a0 = 0;
    }

    if (var_a0 >= 0xF) {
        var_a0 = 0xE;
    }

    spC0 = D_843951D0.unk_1010[var_v1][var_a0].unk_00;
    spBC = D_843951D0.unk_1010[var_v1][var_a0].unk_04;
    spB8 = D_843951D0.unk_1010[var_v1][var_a0].unk_08;
    spB4 = D_843951D0.unk_1010[var_v1 + 1][var_a0].unk_00;
    spB0 = D_843951D0.unk_1010[var_v1 + 1][var_a0].unk_04;
    spAC = D_843951D0.unk_1010[var_v1 + 1][var_a0].unk_08;
    spA8 = D_843951D0.unk_1010[var_v1][var_a0 + 1].unk_00;
    spA4 = D_843951D0.unk_1010[var_v1][var_a0 + 1].unk_04;
    spA0 = D_843951D0.unk_1010[var_v1][var_a0 + 1].unk_08;
    sp9C = D_843951D0.unk_1010[var_v1 + 1][var_a0 + 1].unk_00;
    sp98 = D_843951D0.unk_1010[var_v1 + 1][var_a0 + 1].unk_04;
    sp94 = D_843951D0.unk_1010[var_v1 + 1][var_a0 + 1].unk_08;

    temp_fv0 = spB4 - arg0;
    spBC = D_843951D0.unk_1010[var_v1][var_a0].unk_04;
    temp_fv1 = spAC - arg1;
    temp_fa0 = sp9C - arg0;
    temp_fa1 = sp94 - arg1;

    if ((SQ(temp_fv0) + SQ(temp_fv1)) <= (SQ(temp_fa0) + SQ(temp_fa1))) {
        func_80031A94(spB4 - spC0, spB0 - spBC, spAC - spB8, spA8 - spC0, spA4 - spBC, spA0 - spB8, &sp54, &sp50,
                      &sp4C);
        if (sp50 != 0.0) {
            spC4 = spBC - ((((arg0 - spC0) * sp54) + (sp4C * (arg1 - spB8))) / sp50);
        } else {
            spC4 = (spBC + spB0 + spA4) / 3.0;
        }
    } else {
        func_80031A94(spB4 - sp9C, spB0 - sp98, spAC - sp94, spA8 - sp9C, spA4 - sp98, spA0 - sp94, &sp54, &sp50,
                      &sp4C);
        if (sp50 != 0.0) {
            spC4 = sp98 - ((((arg0 - sp9C) * sp54) + (sp4C * (arg1 - sp94))) / sp50);
        } else {
            spC4 = (sp98 + spB0 + spA4) / 3.0;
        }
    }

    temp_fv0_2 = MathUtil_Atan2s(sp50, sp54);
    temp_fv0_2 = (temp_fv0_2 * 360.0) / 65536.0;
    if (temp_fv0_2 > 90.0f) {
        temp_fv0_2 -= 180.0f;
    }

    if (temp_fv0_2 < -90.0f) {
        temp_fv0_2 += 180.0f;
    }

    *arg2 = temp_fv0_2;
    return spC4;
}

s32 func_8435E530(void) {
    s32 i;
    s32 j;
    unk_D_843951D0_1010* ptr;
    f32 var_fv0;
    s32 temp_v0;
    f32 tmp;

    D_843951D0.unk_0000++;
    if (D_843951D0.unk_000A < D_843951D0.unk_0000) {
        return -1;
    }

    if (D_843951D0.unk_0000 < 0x3C) {
        ptr = &D_843951D0.unk_1010[0][0];
        for (j = 0; j < 16; j++) {
            ptr->unk_04 += (30.0 * __sinf((((D_843951D0.unk_0000 + j) % 15) * TWO_PI_F) / 15.0f)) + 10.0;
            ptr++;
        }
        D_843951D0.unk_0004 += 0.001;
    } else {
        if (((D_843951D0.unk_0000 - 0x3C) % 90) < 0x46) {
            ptr = &D_843951D0.unk_1010[0][2];
            for (j = 0; j < 13; j++) {
                if (0) {}
                if (ptr->unk_04 > 0.0) {
                    ptr->unk_04 -= 40.0;
                    if (ptr->unk_04 < 0.0) {
                        ptr->unk_04 = 0.0f;
                    }
                }
                ptr++;
            }
        } else {
            ptr = &D_843951D0.unk_1010[0][2];
            for (j = 0; j < 13; j++) {
                ptr->unk_04 += 30.0;
                ptr++;
            }
        }

        D_843951D0.unk_0004 += 0.04;
        if (D_843951D0.unk_0004 > 0.3) {
            D_843951D0.unk_0004 = 0.3f;
        }
    }

    ptr = &D_843951D0.unk_1010[0][0];
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            temp_v0 = 1;

            tmp = ptr->unk_04;
            var_fv0 = 0.0f;
            if (i > 0) {
                temp_v0 = 2;
                var_fv0 += D_843951D0.unk_1010[i - 1][j].unk_04 - tmp;
            }

            if ((!ptr) && (!ptr)) {}

            if (j > 0) {
                var_fv0 += D_843951D0.unk_1010[i][j - 1].unk_04 - tmp;
            }

            if (j < 0xF) {
                var_fv0 += D_843951D0.unk_1010[i][j + 1].unk_04 - tmp;
            }

            temp_v0++;
            temp_v0++;
            if (temp_v0) {}

            ptr->unk_0C = (var_fv0 * D_843951D0.unk_0004) + tmp;
            ptr++;
        }
    }

    ptr = &D_843951D0.unk_1010[0][0];
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++, ptr++) {
            ptr->unk_04 = ptr->unk_0C;
            if (ptr->unk_04 < 0.0) {
                ptr->unk_04 = 0.0f;
            }
        }
    }

    return 0;
}

void func_8435EB9C(s32 arg0, s16 arg1, s16 arg2) {
    s32 i;
    s32 j;
    unk_D_843951D0_1010* ptr;

    D_843951D0.unk_000A = arg2;
    D_843951D0.unk_0000 = 0;
    D_843951D0.unk_0004 = 0.0f;
    D_843951D0.unk_0008 = arg1;

    ptr = &D_843951D0.unk_1010[0][0];

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++, ptr++) {
            ptr->unk_00 = arg0 * (((i * 150.0f) - 1200.0f) - 440.0f);
            ptr->unk_04 = 1.0f;
            ptr->unk_08 = (j * 200.0f) - 1600.0f;
            ptr->unk_0C = 1.0f;
            ptr->unk_10 = 0xFF;

            if (i == 0xF) {
                ptr->unk_10 = 0;
            }

            if (j == 0xF) {
                ptr->unk_10 = 0;
            }

            if (j == 0) {
                ptr->unk_10 = 0;
            }
        }
    }

    D_843975E0 = 0;
    D_843975E2 = 8;
    D_843975E4 = 0;

    if (arg1 > 0) {
        for (i = 0; i < arg1; i++) {
            func_8435E530();
        }

        func_8435DED0(&D_843975E8, 50.0f);
    }
}

s32 func_8435EDF8(void) {
    UNUSED s32 pad[2];
    s32 sp1C = func_8435E530();

    D_843975E0 = (D_843975E0 - 1) & 0x3FFF;
    D_843975E2 = (D_843975E2 - 1) & 0x3FFF;
    D_843975E4 = (D_843975E4 - 1) & 0x3FFF;
    func_8435DED0(&D_843975E8, 50.0f);

    return sp1C;
}

static s32 pad_D_84388F78[2] = { 0, 0 };

Gfx* func_8435EE78(Gfx* arg0) {
    static Gfx D_84388F80[] = {
        gsDPPipeSync(),
        gsDPSetCycleType(G_CYC_2CYCLE),
        gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                              G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
        gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
        gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
        gsDPPipeSync(),
        gsDPSetTexturePersp(G_TP_PERSP),
        gsDPSetTextureDetail(G_TD_CLAMP),
        gsDPSetTextureLOD(G_TL_TILE),
        gsDPSetTextureLUT(G_TT_NONE),
        gsDPSetTextureConvert(G_TC_FILT),
        gsDPSetTextureFilter(G_TF_BILERP),
        gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_XLU_SURF2),
        gsDPSetCombineLERP(TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, PRIMITIVE, PRIMITIVE, ENVIRONMENT, COMBINED,
                           ENVIRONMENT, COMBINED, 0, SHADE, 0),
        gsSPEndDisplayList(),
    };
    static Gfx D_84388FF8[] = {
        gsDPPipeSync(),
        gsDPSetCycleType(G_CYC_2CYCLE),
        gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                              G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
        gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
        gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
        gsDPPipeSync(),
        gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
        gsDPSetCombineLERP(TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, PRIMITIVE,
                           ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0),
        gsDPSetColorDither(G_CD_NOISE),
        gsDPSetPrimColor(0, 0x80, 0, 50, 255, 100),
        gsDPSetEnvColor(0, 100, 255, 100),
        gsSPEndDisplayList(),
    };

    unk_D_843951D0_1010* var_v1;
    Vtx* vtx;
    s32 i;
    s32 j;
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp11C;
    f32 temp_fv0;
    Vtx* temp_v0;
    f32 sp110;
    s16 var_a2;
    s16 var_t0;
    s32 idx1;
    s32 idx2;

    D_843951D0.unk_000C = func_80005F5C(sizeof(Vtx) * 16 * 16);
    vtx = D_843951D0.unk_000C;
    var_v1 = &D_843951D0.unk_1010[0][0];

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            vtx->v.ob[0] = var_v1->unk_00;
            vtx->v.ob[1] = var_v1->unk_04;
            vtx->v.ob[2] = var_v1->unk_08;
            vtx->v.tc[0] = (i * 0x800) / 3;
            vtx->v.tc[1] = (j * 0x800) / 3;
            vtx->v.cn[3] = var_v1->unk_10;
            vtx++;
            var_v1++;
        }
    }

    gSPDisplayList(arg0++, D_84388F80);
    gDPPipeSync(arg0++);

    if (D_843951D0.unk_0000 < 0xA) {
        var_a2 = 0;
        var_t0 = (D_843951D0.unk_0000 * 0xFF) / 10;
    } else if (D_843951D0.unk_0000 < 0x14) {
        var_a2 = ((D_843951D0.unk_0000 * 0xFF) - 0x9F6) / 10;
        var_t0 = 0xFF;
    } else {
        var_a2 = 0xFF;
        var_t0 = 0xFF;
    }

    gDPSetPrimColor(arg0++, 0, 0xB4, 255, 255, 255, var_t0);
    gDPSetEnvColor(arg0++, 0, 0x64, 0xC8, var_a2);
    gDPSetBlendColor(arg0++, 255, 255, 255, 255);

    gDPLoadTextureTile_4b(arg0++, D_843920C0[0xB8], G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                          G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 1, 1);
    gDPSetTileSize(arg0++, G_TX_RENDERTILE, D_843975E0, -D_843975E0, D_843975E0 + 0x1F, 0x1F - D_843975E0);

    gDPLoadMultiTile_4b(arg0++, D_843920C0[0xB9], 0x0100, 1, G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 1, 1);
    gDPSetTileSize(arg0++, 1, D_843975E2, D_843975E2, D_843975E2 + 0x1F, D_843975E2 + 0x1F);

    vtx = D_843951D0.unk_000C;
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            idx1 = (i + 0) * 16 + j;
            idx2 = (i + 1) * 16 + j;
            gSPVertex(arg0++, &vtx[idx1 + 0], 1, 0);
            gSPVertex(arg0++, &vtx[idx1 + 1], 1, 1);
            gSPVertex(arg0++, &vtx[idx2 + (0 * 16) + 0], 1, 2);
            gSPVertex(arg0++, &vtx[idx1 + (1 * 16) + 1], 1, 3);
            gSP2Triangles(arg0++, 0, 2, 1, 0, 2, 3, 1, 0);
        }
    }

    sp12C = (D_843975E8.unk_00 - D_843975E8.unk_0C) + D_843975E8.unk_18;
    sp130 = (D_843975E8.unk_04 - D_843975E8.unk_10) + D_843975E8.unk_1C;
    sp134 = (D_843975E8.unk_08 - D_843975E8.unk_14) + D_843975E8.unk_20;
    sp11C = func_8435E158(sp12C, sp134, &sp110);

    sp120 = D_843975E8.unk_00 + D_843975E8.unk_0C + D_843975E8.unk_18;
    sp124 = D_843975E8.unk_04 + D_843975E8.unk_10 + D_843975E8.unk_1C;
    sp128 = D_843975E8.unk_08 + D_843975E8.unk_14 + D_843975E8.unk_20;
    temp_fv0 = func_8435E158(sp120, sp128, &sp110);

    if ((sp130 < sp11C) || (sp124 < temp_fv0)) {
        temp_v0 = func_80005F5C(sizeof(Vtx) * 4);

        temp_v0[0].v.ob[0] = (D_843975E8.unk_00 - D_843975E8.unk_0C) - D_843975E8.unk_18;
        temp_v0[0].v.ob[1] = sp11C;
        temp_v0[0].v.ob[2] = (D_843975E8.unk_08 - D_843975E8.unk_14) - D_843975E8.unk_20;
        temp_v0[0].v.tc[0] = 0;
        temp_v0[0].v.tc[1] = 0;

        temp_v0[1].v.ob[0] = (D_843975E8.unk_00 + D_843975E8.unk_0C) - D_843975E8.unk_18;
        temp_v0[1].v.ob[1] = sp11C;
        temp_v0[1].v.ob[2] = (D_843975E8.unk_08 + D_843975E8.unk_14) - D_843975E8.unk_20;
        temp_v0[1].v.tc[0] = 0x3E0;
        temp_v0[1].v.tc[1] = 0;

        temp_v0[2].v.ob[0] = sp12C;
        temp_v0[2].v.ob[1] = sp130;
        temp_v0[2].v.ob[2] = sp134;
        temp_v0[2].v.tc[0] = 0;
        temp_v0[2].v.tc[1] = 0x3E0;

        temp_v0[3].v.ob[0] = sp120;
        temp_v0[3].v.ob[1] = sp124;
        temp_v0[3].v.ob[2] = sp128;
        temp_v0[3].v.tc[0] = 0x3E0;
        temp_v0[3].v.tc[1] = 0x3E0;

        gSPDisplayList(arg0++, D_84388FF8);
        gDPLoadTextureTile_4b(arg0++, D_843920C0[0xBA], G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                              G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 15, G_TX_NOLOD);
        gDPSetTileSize(arg0++, G_TX_RENDERTILE, D_843975E4, 0, D_843975E4 + 0x1F, 0x001F);
        gDPLoadMultiTile_4b(arg0++, D_843920C0[0xBA], 0x0100, 1, G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 14, G_TX_NOLOD);
        gDPSetTileSize(arg0++, 1, -D_843975E4, 0, 0x1F - D_843975E4, 0x001F);
        gSPVertex(arg0++, temp_v0, 4, 0);
        gSP2Triangles(arg0++, 0, 2, 1, 0, 2, 3, 1, 0);
    }

    return arg0;
}
