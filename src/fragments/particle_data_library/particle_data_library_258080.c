#include "particle_data_library.h"
#include "src/fragments/clefairy_game/clefairy_game.h"
#include "src/fragments/rattata_game/rattata_game.h"
#include "src/fragments/victory_palace/victory_palace.h"
#include "src/gfx_buffer.h"
#include "src/geo_render.h"
#include "src/battle_hud.h"

typedef struct {
    /* 0x00 */ u8 rgb0[3];      // start color
    /* 0x03 */ u8 frameStart;   // frame where this keyframe begins
} Keyframe;  // size = 0x04

// .bss
static s32 D_81004B70;
static u8 pad_D_81004B78[0x8];
static s32 D_81004B80;
static u8 pad_D_81004B88[0x8];
static s32 D_81004B90;
static u8 pad_D_81004B98[0x8];
static s32 D_81004BA0;
static u8 pad_D_81004BA8[0x8];
static s32 D_81004BB0;
static char D_81004BB8[0x28];

void DisplayList_BuildScrollingIconSegment0(Gfx* gfx, u16* arg1, u8* arg2) {
    gDPPipeSync(gfx++);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(gfx++, arg1);
    gDPLoadTextureTile(gfx++, (arg2 + ((D_862082A0[0] * 4) & ~0x1F) + ((D_81004B70 & 3) << 0xB)), G_IM_FMT_CI, G_IM_SIZ_8b, 0x20, 0x40, 0, 0, 0x20 - 1, 0x40 - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    gSPEndDisplayList(gfx++);
}

void DisplayList_InitScrollingIconSegment0(s32 arg0, DisplayListState* state) {
    Gfx* gfx;
    DisplayListAddresses* addresses;

    addresses = state->addresses;
    switch (arg0) {
    case 0:
        D_81004B70 = 0;
        return;
    case 2:
        gfx = Gfx_AllocDisplayList(0xA0);
        state->gfx = gfx;
        DisplayList_BuildScrollingIconSegment0(gfx, addresses->segments[0], addresses->segments[1]);
        D_81004B70 += 1;
        return;
    }
}

void DisplayList_BuildScrollingIconSegment1(Gfx* gfx, u16* arg1, u8* arg2) {
    gDPPipeSync(gfx++);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(gfx++, arg1);
    gDPLoadTextureTile(gfx++, (arg2 + ((D_862082A0[1] * 4) & ~0x1F) + ((D_81004B80 & 3) << 0xB)), G_IM_FMT_CI, G_IM_SIZ_8b, 0x20, 0x40, 0, 0, 0x20 - 1, 0x40 - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    gSPEndDisplayList(gfx++);
}

void DisplayList_InitScrollingIconSegment1(s32 arg0, DisplayListState* state) {
    Gfx* gfx;
    DisplayListAddresses* addresses;

    addresses = state->addresses;
    switch (arg0) {                                 /* irregular */
    case 0:
        D_81004B80 = 0;
        return;
    case 2:
        gfx = Gfx_AllocDisplayList(0xA0);
        state->gfx = gfx;
        DisplayList_BuildScrollingIconSegment1(gfx, addresses->segments[0], addresses->segments[1]);
        D_81004B80 += 1;
        return;
    }
}

void DisplayList_BuildScrollingIconSegment2(Gfx* gfx, u16* arg1, u8* arg2) {
    gDPPipeSync(gfx++);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(gfx++, arg1);
    gDPLoadTextureTile(gfx++, (arg2 + ((D_862082A0[2] * 4) & ~0x1F) + ((D_81004B90 & 3) << 0xB)), G_IM_FMT_CI, G_IM_SIZ_8b, 0x20, 0x40, 0, 0, 0x20 - 1, 0x40 - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    gSPEndDisplayList(gfx++);
}

void DisplayList_InitScrollingIconSegment2(s32 arg0, DisplayListState* state) {
    Gfx* gfx;
    DisplayListAddresses* addresses;

    addresses = state->addresses;
    switch (arg0) {                                 /* irregular */
    case 0:
        D_81004B90 = 0;
        return;
    case 2:
        gfx = Gfx_AllocDisplayList(0xA0);
        state->gfx = gfx;
        DisplayList_BuildScrollingIconSegment2(gfx, addresses->segments[0], addresses->segments[1]);
        D_81004B90 += 1;
        return;
    }
}

void DisplayList_BuildScrollingIconSegment3(Gfx* gfx, u16* arg1, u8* arg2) {
    gDPPipeSync(gfx++);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(gfx++, arg1);
    gDPLoadTextureTile(gfx++, (arg2 + ((D_862082A0[3] * 4) & ~0x1F) + ((D_81004BA0 & 3) << 0xB)), G_IM_FMT_CI, G_IM_SIZ_8b, 0x20, 0x40, 0, 0, 0x20 - 1, 0x40 - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    gSPEndDisplayList(gfx++);
}

void DisplayList_InitScrollingIconSegment3(s32 arg0, DisplayListState* state) {
    Gfx* gfx;
    DisplayListAddresses* addresses;

    addresses = state->addresses;
    switch (arg0) {                                 /* irregular */
    case 0:
        D_81004BA0 = 0;
        return;
    case 2:
        gfx = Gfx_AllocDisplayList(0xA0);
        state->gfx = gfx;
        DisplayList_BuildScrollingIconSegment3(gfx, addresses->segments[0], addresses->segments[1]);
        D_81004BA0 += 1;
        return;
    }
}

void DisplayList_InitPulsingRectSegment(s32 arg0, DisplayListState* state) {
    static u8 D_81004190 = 0;
    s32 temp_a1;
    s32 temp_a2;
    Gfx* gfx;

    if (arg0 == 2) {
        gfx = Gfx_AllocDisplayList(0x10);
        temp_a1 = D_81004190 * 3;
        temp_a2 = D_81004190 * -6;
        state->gfx = gfx;
        {    Gfx *_gfx = (Gfx *)(gfx++); _gfx->words.w0 = (((temp_a1 & 0xFFF) << 0xC) | 0xF2000000 | (temp_a2 & 0xFFF));    _gfx->words.w1 = ((((0x27F << (temp_a1 + 2)) & 0xFFF) << 0xC) | ((0x7F << (temp_a2 + 2)) & 0xFFF));    }
        gSPEndDisplayList(gfx++);
        D_81004190++;
        D_81004190 &= 0x7F;
    }
}

void DisplayList_InitColorCycleBoxSegment(s32 arg0, DisplayListState* state) {
    static u8 D_81004194 = 0;
    static u8 D_81004198 = 0;
    static Keyframe D_8100419C[6] = {
        { { 0xFF, 0x32, 0x32 }, 0  },
        { { 0xC8, 0xC8, 0x00 }, 10 },
        { { 0x64, 0xFF, 0x00 }, 20 },
        { { 0x00, 0xC8, 0xFF }, 30 },
        { { 0x96, 0x32, 0xC8 }, 40 },
        { { 0xFF, 0x32, 0x32 }, 50 },
    };
    u8 i;
    u8 c;
    Keyframe* kf;
    Gfx* gfx;
    u8 sp48[3];
    
    if (arg0 == 2) {
        gfx = Gfx_AllocDisplayList(sizeof(Gfx) * 4);
        state->gfx = gfx;
        for (i = 0; i < 5; i++) {
            if (D_81004198 == D_8100419C[i].frameStart) {
                for(c = 0; c < 3; c++) {
                    sp48[c] = D_8100419C[i].rgb0[c];
                }
                break;
            }
            if (D_8100419C[i].frameStart < D_81004198 && D_81004198 < D_8100419C[i + 1].frameStart) {
                for(c = 0; c < 3; c++) {
                    sp48[c] = (s32) (((f32) ((D_8100419C[i + 1].rgb0[c] - D_8100419C[i].rgb0[c]) * (D_81004198 - D_8100419C[i].frameStart)) / (f32) (D_8100419C[i + 1].frameStart - D_8100419C[i].frameStart)) + D_8100419C[i].rgb0[c] + 0.5f);
                }
                break;
            }
        }
        gDPSetPrimColor(gfx++, 0, 0x80, sp48[0], sp48[1], sp48[2], 180);
        gDPSetTileSize(gfx++, 0, -2 * D_81004194, 0, (320 - 1) << ((-2 * D_81004194) + 2), (64 - 1) << 2);
        gDPSetTileSize(gfx++, 1, 2 * D_81004194, 0, (320 - 1) << ((2 * D_81004194) + 2), (64 - 1) << 2);
        gSPEndDisplayList(gfx++);
        D_81004194++;
        D_81004194 &= 0x7F;
        D_81004198++;
        D_81004198 &= 0xFF;
        if ((s32) D_81004198 >= 0x32) {
            D_81004198 = 0;
        }
    }
}

void DisplayList_BuildDigitDisplayBackground(Gfx* gfx) {
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

s32 Util_Strlen(s8* arg0) {
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

void func_81003A54(Gfx* gfx) {
    u16 temp_v1;
    u8 sp4D;
    s32 pad[4];
    u8 var_v0 = D_8006F09C->effectSlot % 5;
    u8 temp_t0;
    char* sp34;
    Mtx* sp30;
    s32 sp2C;

    temp_t0 = D_800AF770[var_v0];
    switch (D_81004BB0) {
    case 0:
        sp4D = (((s32) (temp_t0 + 1) / 100) + 0x10) & 0xFF;
        break;
    case 1:
        sp4D = (((s32) ((s32) (temp_t0 + 1) % 100) / 10) + 0x10) & 0xFF;
        break;
    case 2:
        sp4D = (((s32) (temp_t0 + 1) % 10) + 0x10) & 0xFF;
        break;
    default:
        {
        sp34 = Text_GetString(0, 0, D_8267E760, temp_t0);
        sprintf(D_81004BB8, "%s     ", sp34);
        temp_v1 = D_81004BB0 - 3;
        sp4D = Font_MapGlyphCode((u8) D_81004BB8[temp_v1]);
        sp2C = 0xA - Util_Strlen((s8*)sp34);
        sp30 = Gfx_AllocDisplayList(sizeof(Mtx));
        guTranslate(sp30, (f32) sp2C * 32.0f, 0.0f, 0.0f);
        gSPMatrix(gfx++, sp30, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        break;
        }
    }
    gDPLoadTextureTile(gfx++, Util_ConvertAddrToVirtAddr(D_3000000 + ((sp4D & 0xF) << 4) + ((((sp4D & 0xF0) >> 4) << 4) << 8)), G_IM_FMT_IA, G_IM_SIZ_8b, 256, 17, 0, 0, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gSPEndDisplayList(gfx++);
    D_81004BB0++;
}

void DisplayList_InitDigitDisplayBackground(s32 arg0, DisplayListState* state) {
    Gfx* gfx;

    if (arg0 == 2) {
        gfx = Gfx_AllocDisplayList(0xF0);
        state->gfx = gfx;
        DisplayList_BuildDigitDisplayBackground(gfx);
    }
}

void DisplayList_InitDigitOrGlyphSegment(s32 arg0, DisplayListState* state) {
    Gfx* gfx;

    if (arg0 == 2) {
        gfx = Gfx_AllocDisplayList(0xA0);
        state->gfx = gfx;
        func_81003A54(gfx);
    }
}
