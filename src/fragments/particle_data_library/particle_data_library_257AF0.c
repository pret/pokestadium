#include "particle_data_library.h"
#include "src/gfx_buffer.h"
#include "src/geo_render.h"
#include "src/battle_hud.h"

typedef struct unk_arg1_func_81002830 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04[6];
} unk_arg1_func_81002830; // size = 0x1C

typedef struct unk_arg1_func_81002968 {
    /* 0x00 */ char unk00[0x14];
    /* 0x14 */ u32* unk_14;
    /* 0x18 */ Gfx* unk_18;
} unk_arg1_func_81002968; // size = 0x1C

typedef struct TextureState {
    /* 0x00 */ char unk00[0x14];
    /* 0x14 */ u32* textures;
    /* 0x18 */ Gfx* gfx;
} TextureState; // size = 0x1C

void func_81002830(Gfx* gfx, unk_arg1_func_81002830* arg1) {
    s16 temp_v0;
    s32 var_a3;
    unk_arg1_func_81002830* p;
    p = arg1;
    if (D_8006F09C->textureMode == 0) {
        temp_v0 = 0x4000;
        // FAKE
        if ((arg1 && arg1) && arg1) {}
        var_a3 = D_800AF7AE;
        temp_v0 = temp_v0 - (arg1->unk_00 * var_a3);
        // FAKE
        arg1 = NULL;
        var_a3 = D_800AF7AE;
        gDPLoadTextureBlock(gfx++, p->unk_04[var_a3 & 0x7], G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                    G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetTileSize(gfx++, 0, temp_v0, 0, ((temp_v0 + 63) << 2), 124);
    }
    gSPEndDisplayList(gfx++);
}

void DisplayList_InitAnimatedFrameSegment(s32 arg0, unk_arg1_func_81002968* arg1) {
    s32 temp_v0;
    s32 sp18;

    if (arg0 == 2) {
        sp18 = arg1->unk_14;
        temp_v0 = Gfx_AllocDisplayList(0x50);
        arg1->unk_18 = temp_v0;
        func_81002830(temp_v0, sp18);
    }
}

Gfx* DisplayList_BuildSelectedTextureSegment(Gfx* gfx, u32* textures, s32 index) {
    gDPLoadTextureBlock(gfx++, textures[index + 1], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD, G_TX_NOLOD);
    gSPEndDisplayList(gfx++);
    return gfx;
}

void DisplayList_InitSelectedTextureSegment(s32 arg0, TextureState* state) {
    s32 index;
    u32* textures;

    if (arg0 == 2) {
        textures = state->textures;
        state->gfx = (Gfx*)Gfx_AllocDisplayList(0x50);
        if (D_8006F09C->objectType == 0x58) {
            index = (s32) D_8006F09C->transformAnim.frameFixed >> 0x10;
            if (index >= 0x42) {
                index = index - 0x42;
            } else {
                index = 0;
            }
            if (index >= 8) {
                index = 0;
            }
            if (D_8006F09C->transformAnim.animationId >= 2) {
                index = 0;
            }
        } else {
            index = D_8006F084 & 7;
        }
        DisplayList_BuildSelectedTextureSegment(state->gfx, textures, index);
    }
}
