#include "fragment31.h"
#include "src/6A40.h"
#include "src/12D80.h"

typedef struct unk_arg1_func_81002968 {
    /* 0x00 */ char unk00[0x14];
    /* 0x14 */ u32* unk_14;
    /* 0x18 */ Gfx* unk_18;
} unk_arg1_func_81002968; // size >= 0x1C

typedef struct TextureState {
    /* 0x00 */ char unk00[0x14];
    /* 0x14 */ u32* textures;
    /* 0x18 */ Gfx* gfx;
} TextureState; // size >= 0x1C

void func_81002830(s32, s32);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_257AF0/func_81002830.s")

void func_81002968(s32 arg0, unk_arg1_func_81002968* arg1) {
    s32 temp_v0;
    s32 sp18;

    if (arg0 == 2) {
        sp18 = arg1->unk_14;
        temp_v0 = func_80005F5C(0x50);
        arg1->unk_18 = temp_v0;
        func_81002830(temp_v0, sp18);
    }
}

Gfx* func_810029B0(Gfx* gfx, u32* textures, s32 index) {
    gDPLoadTextureBlock(gfx++, textures[index + 1], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD, G_TX_NOLOD);
    gSPEndDisplayList(gfx++);
    return gfx;
}

void func_81002A68(s32 arg0, TextureState* state) {
    s32 index;
    u32* textures;

    if (arg0 == 2) {
        textures = state->textures;
        state->gfx = (Gfx*)func_80005F5C(0x50);
        if (D_8006F09C->unk_01A == 0x58) {
            index = (s32) D_8006F09C->unk_040.unk_08 >> 0x10;
            if (index >= 0x42) {
                index = index - 0x42;
            } else {
                index = 0;
            }
            if (index >= 8) {
                index = 0;
            }
            if (D_8006F09C->unk_040.unk_00 >= 2) {
                index = 0;
            }
        } else {
            index = D_8006F084 & 7;
        }
        func_810029B0(state->gfx, textures, index);
    }
}
