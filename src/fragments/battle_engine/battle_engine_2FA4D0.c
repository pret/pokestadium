#include "battle_engine.h"
#include "src/graphics_textures.h"
#include "src/ui_graphics.h"
#include "src/status_icons.h"
#include "src/game_state.h"
#include "src/text_system.h"
#include "src/3D140.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/matrix.h"
#include "src/controller.h"
#include "src/memmap.h"
#include "src/memory.h"

Vec3f D_84390190;

static unk_D_84385790 D_84385790[] = {
    {
        0x00000000,
        {
            0xFF,
            0xFF,
            0xFF,
            0xFF,
        },
    },
    {
        0x00000001,
        {
            0x4D,
            0x4D,
            0x4D,
            0xFF,
        },
    },
    {
        0x00000002,
        {
            0x9F,
            0x91,
            0xE8,
            0xFF,
        },
    },
    {
        0x00000003,
        {
            0x96,
            0x50,
            0xFF,
            0xFF,
        },
    },
    {
        0x00000004,
        {
            0xF0,
            0x5A,
            0x46,
            0xFF,
        },
    },
    {
        0x00000005,
        {
            0x85,
            0xD5,
            0xF1,
            0xFF,
        },
    },
    {
        0x00000006,
        {
            0xFF,
            0xFF,
            0x00,
            0xFF,
        },
    },
};
static u8* D_843857C8[] = {
    D_30098F0, D_300B630, D_300A1F0, D_30096B0, D_300AAF0, D_300A8B0, D_30098F0, D_300B3F0, D_3009FB0, D_30098F0,
    D_30098F0, D_30098F0, D_30098F0, D_30098F0, D_30098F0, D_30098F0, D_30098F0, D_30098F0, D_30098F0, D_30098F0,
    D_300A430, D_300B1B0, D_300AF70, D_300A670, D_3009D70, D_300AD30, D_3009B30, NULL,
};
static u8* D_84385838[] = {
    D_3007A78, D_3007EB0, D_3007910, D_3008018, D_3007BE0, D_3007D48,
};
static u8* D_84385850[] = {
    D_3006D10,
    D_3007010,
    D_3007310,
    D_3007610,
};

static Color_RGB8 D_84385860[] = {
    { 0, 0, 0x8B }, { 0, 0x32, 0 }, { 0x1E, 0, 0 }, { 0x65, 0x49, 0x11 }, { 0, 0, 0 },
};
static Color_RGB8 D_84385870[] = {
    { 0x00, 0x00, 0xEE },
    { 0x00, 0x79, 0x00 },
    { 0x82, 0x00, 0x00 },
    { 0x97, 0x89, 0x13 },
};
static Color_RGB8 D_8438587C[] = {
    { 0x13, 0x45, 0xFF },
    { 0, 0x99, 0 },
    { 0xCC, 0x51, 0x28 },
    { 0xCC, 0x8F, 0 },
};
static Color_RGB8 D_84385888[] = {
    { 0x00, 0x00, 0x8B },
    { 0x00, 0x00, 0x8B },
    { 0x00, 0x00, 0x8B },
    { 0x00, 0x00, 0x8B },
};
static Color_RGB8 D_84385894[] = {
    { 0x00, 0x00, 0xEE },
    { 0x00, 0x00, 0xEE },
    { 0x00, 0x00, 0xEE },
    { 0x00, 0x00, 0xEE },
};
static Color_RGB8 D_843858A0[] = {
    { 0x00, 0x32, 0x00 },
    { 0x00, 0x32, 0x00 },
    { 0x00, 0x32, 0x00 },
    { 0x00, 0x32, 0x00 },
};
static Color_RGB8 D_843858AC[] = {
    { 0x00, 0x79, 0x00 },
    { 0x00, 0x79, 0x00 },
    { 0x00, 0x79, 0x00 },
    { 0x00, 0x79, 0x00 },
};
static Color_RGB8 D_843858B8[] = {
    { 0x1E, 0x00, 0x00 },
    { 0x1E, 0x00, 0x00 },
    { 0x1E, 0x00, 0x00 },
    { 0x1E, 0x00, 0x00 },
};
static Color_RGB8 D_843858C4[] = {
    { 0x82, 0x00, 0x00 },
    { 0x82, 0x00, 0x00 },
    { 0x82, 0x00, 0x00 },
    { 0x82, 0x00, 0x00 },
};
static Color_RGB8 D_843858D0[] = {
    { 0x65, 0x49, 0x11 },
    { 0x65, 0x49, 0x11 },
    { 0x65, 0x49, 0x11 },
    { 0x65, 0x49, 0x11 },
};
static Color_RGB8 D_843858DC[] = {
    { 0x97, 0x89, 0x13 },
    { 0x97, 0x89, 0x13 },
    { 0x97, 0x89, 0x13 },
    { 0x97, 0x89, 0x13 },
};
static Gfx D_843858E8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetRenderMode(G_RM_TEX_EDGE, G_RM_TEX_EDGE2),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_ZBUFFER | G_LIGHTING),
    gsSPEndDisplayList(),
};

void func_8430FC10(void) {
}

void func_8430FC18(void) {
}

void func_8430FC20(void) {
}

void BattleHud_DrawTranslucentShadowRect(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    DepthBuffer* temp_s1;
    Vtx* temp_s2;
    Mtx* sp84;
    Vp* sp80;

    temp_s1 = GfxImage_GetCurrent();
    temp_s2 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    sp84 = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    sp80 = Gfx_AllocDisplayList(sizeof(Vp) * 1);
    Gfx_SetViewportDimensions(sp80, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)sp80 & 0x1FFFFFFF);

    guOrtho(sp84, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    Gfx_SetVertexAttributes(&temp_s2[0], arg0, arg1, -1, 0, 0, 0, 0, 0, arg4);
    Gfx_SetVertexAttributes(&temp_s2[1], arg0 + arg2, arg1, -1, 0, 0, 0, 0, 0, arg4);
    Gfx_SetVertexAttributes(&temp_s2[2], arg0, arg1 + arg3, -1, 0, 0, 0, 0, 0, arg4);
    Gfx_SetVertexAttributes(&temp_s2[3], arg0 + arg2, arg1 + arg3, -1, 0, 0, 0, 0, 0, arg4);

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)sp84 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&gIdentityMtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
}

void BattleHud_DrawGradientRect(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGB8* arg4, Color_RGB8* arg5) {
    Vtx* temp_s2;
    DepthBuffer* temp_s1;
    Mtx* sp7C;
    Vp* sp78;

    temp_s1 = GfxImage_GetCurrent();
    temp_s2 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    sp7C = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    sp78 = Gfx_AllocDisplayList(sizeof(Vp) * 1);
    Gfx_SetViewportDimensions(sp78, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)sp78 & 0x1FFFFFFF);

    guOrtho(sp7C, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);
    Gfx_SetVertexAttributes(&temp_s2[0], arg0, arg1, -1, 0, 0, arg4->r, arg4->g, arg4->b, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[1], arg0 + arg2, arg1, -1, 0, 0, arg4->r, arg4->g, arg4->b, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[2], arg0, arg1 + arg3, -1, 0, 0, arg5->r, arg5->g, arg5->b, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[3], arg0 + arg2, arg1 + arg3, -1, 0, 0, arg5->r, arg5->g, arg5->b, 0xFF);

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)sp7C & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&gIdentityMtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
}

void Battle_DrawGradientRectWrapper(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGB8* arg4, Color_RGB8* arg5) {
    BattleHud_DrawGradientRect(arg0, arg1, arg2, arg3, arg4, arg5);
}

void func_84310360(void) {
}

void BattleHud_DrawHpBar(s32 arg0, s32 arg1, f32 arg2, s32 arg3) {
    u8* spCC;
    s32 temp_ft2 = ((arg3 - arg2) * 48.0f) / arg3;
    s32 sp14 = 0x30 - temp_ft2;

    if ((arg2 * 48.0f) < (arg3 * 0xA)) {
        spCC = D_1003EF0;
    } else if ((arg2 * 48.0f) < (arg3 * 0x1B)) {
        spCC = D_1003EC8;
    } else {
        spCC = D_1003EA0;
    }

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    gDPLoadTextureBlock(gDisplayListHead++, D_1003DB0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 5, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, arg0 << 2, arg1 << 2, (arg0 + 0x10) << 2, (arg1 + 5) << 2, G_TX_RENDERTILE,
                        0, 0, 0x0400, 0x0400);

    gDPLoadTextureBlock(gDisplayListHead++, D_1003E50, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 5, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, (arg0 + 0x40) << 2, arg1 << 2, (arg0 + 0x41) << 2, (arg1 + 5) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);

    if (sp14 > 0) {
        gDPLoadTextureBlock(gDisplayListHead++, spCC, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 5, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, (arg0 + 0x10) << 2, arg1 << 2, ((arg0 + sp14) + 0x10) << 2,
                            (arg1 + 5) << 2, G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    if (temp_ft2 > 0) {
        gDPLoadTextureBlock(gDisplayListHead++, D_1003E78, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 5, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, ((arg0 + sp14) + 0x10) << 2, arg1 << 2,
                            ((arg0 + sp14) + temp_ft2 + 0x10) << 2, (arg1 + 5) << 2, G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void BattleHud_Noop(void) {
}

void BattleHud_DrawLevelNumber(s32 arg0, s32 arg1, s32 arg2) {
    UNUSED s32 pad[2];
    s8* var_s2;
    s8 sp58[2];
    u8** temp_s4;

    var_s2 = &sp58;
    temp_s4 = Memmap_GetSegmentVaddr(D_300B870);
    sprintf(sp58, "%d", arg2);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    if (arg2 >= 0x64) {
        arg0 -= 2;
        Gfx_DrawTextureRgba16(arg0, arg1, 8, 6, temp_s4[sp58[0] - '0'], 8, 0);
        arg0 += 8;
        var_s2 = &sp58[1];
    } else {
        Gfx_DrawTextureRgba16(arg0, arg1, 4, 6, temp_s4[11], 4, 0);
        arg0 += 5;
    }

    while (*var_s2 != 0) {
        Gfx_DrawTextureRgba16(arg0, arg1, 8, 6, temp_s4[*var_s2 - '0'], 8, 0);
        arg0 += 8;
        var_s2++;
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void BattleHud_DrawHpFractionText(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    UNUSED s32 pad[2];
    s8 sp70[7];
    UNUSED s32 pad2;
    u8** temp_s2;
    u8* var_v0;
    s32 i;

    temp_s2 = Memmap_GetSegmentVaddr(D_300B870);
    sprintf(sp70, "%3d/%3d", arg2, arg3);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    for (i = 0; i < sizeof(sp70); i++) {
        switch (sp70[i]) {
            case ' ':
                var_v0 = NULL;
                break;

            case '/':
                var_v0 = temp_s2[10];
                break;

            default:
                var_v0 = temp_s2[sp70[i] - '0'];
                break;
        }

        if (var_v0 != NULL) {
            Gfx_DrawTextureRgba16(arg0, arg1, 8, 6, var_v0, 8, 0);
        }

        arg0 += 8;
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void BattleHud_DrawSpeciesNameLabel(s16 arg0, s16 arg1, s32 arg2, char* arg3, s32 arg4) {
    Battle_DrawGradientRectWrapper(arg0, arg1, 0x46, 0x11, &D_84385860[arg2], &D_84385870[arg2]);
    Font_BeginTranslucentTextRendering();
    if (arg4 != 0) {
        Gfx_SetEnvColor(0xFF, 0x64, 0xFF, 0xFF);
    }
    Font_SetActive(2, 0);
    Font_Printf((arg0 - (Font_MeasureTextExtent(2, 0, arg3) / 2)) + 0x23, arg1 + 2, arg3);
    Font_EndTexturedTextRendering();
}

void BattleHud_DrawSpeciesNameLabelBlink(s16 arg0, s16 arg1, s32 arg2, u8* arg3, s32 arg4, s32 arg5) {
    s32 sp24;
    s16 sp22;
    s16 sp20;

    sp22 = COSS(arg4) * 255.0f;
    sp20 = sp22;
    if (sp22 < 0) {
        sp20 = sp22 * -1;
    }

    Battle_DrawGradientRectWrapper(arg0, arg1, 0x46, 0x11, &D_84385860[arg2], &D_84385870[arg2]);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(2, 0);

    if (arg5 != 0) {
        Gfx_SetEnvColor(0xFF, 0x64, 0xFF, (s8)sp20);
    } else {
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, (s8)sp20);
    }

    if (sp22 > 0) {
        sp24 = Font_MeasureTextExtent(2, 0, Text_GetString(NULL, 0, sBattleMessagesTable, 0xAA)) / 2;
        Font_Printf((arg0 - sp24) + 0x23, arg1 + 2, Text_GetString(NULL, 0, sBattleMessagesTable, 0xAA));
    } else {
        Font_Printf((arg0 - (Font_MeasureTextExtent(2, 0, arg3) / 2)) + 0x23, arg1 + 2, arg3);
    }

    Font_EndTexturedTextRendering();
}

void BattleHud_DrawSpeciesNameLabelAuto(ActivePokemon* arg0, TeamRoster* arg1, s16 arg2, s16 arg3, s32 arg4, u16 arg5, s32 arg6) {
    ActivePokemonState* ptr = &arg0->state;
    s32 var_t0 = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (ptr->moveSlotIllegality[i] == 1) {
            var_t0 = 1;
        }
    }

    if (arg6 == 0) {
        BattleHud_DrawSpeciesNameLabel(arg2, arg3, arg4, &arg1->unk_008, var_t0);
    } else {
        BattleHud_DrawSpeciesNameLabelBlink(arg2, arg3, arg4, &arg1->unk_008, arg5, var_t0);
    }
}

void BattleHud_DrawMonInfoPanel(ActivePokemon* arg0, BattleMon* arg1, unk_D_84385790* arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    s32 sp34;
    s32 temp_a2;

    if (arg3 < 0) {
        temp_a2 = arg5 + arg3;
        if (temp_a2 < 0) {
            Gfx_FillRectWithDisplayState(0, arg4, 0, arg6, arg7, arg8, arg9, argA);
        } else {
            Gfx_FillRectWithDisplayState(0, arg4, temp_a2, arg6, arg7, arg8, arg9, argA);
        }
    } else {
        Gfx_FillRectWithDisplayState(arg3, arg4, arg5, arg6, arg7, arg8, arg9, argA);
    }

    BattleHud_DrawLevelNumber(arg3 + 3, arg4 + 0x10, arg1->unk_24);
    BattleHud_DrawHpBar(arg3 + 2, arg4 + 0x19, D_843900A8[BattleScene_GetParticipantSideIndex(arg0)], arg1->unk_26);
    BattleHud_DrawHpFractionText(arg3 + 0xC, arg4 + 0x1F, arg1->unk_02, arg1->unk_26);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(2, 0);

    sp34 = Font_MeasureTextExtent(2, 0, Battle_GetActiveMonNickname(arg0)) / 2;
    Font_Printf((arg3 - sp34) + 0x23, arg4 + 2, Battle_GetActiveMonNickname(arg0));
    sp34 = Font_MeasureTextExtent(1, 0, Text_GetString(NULL, 0, sStatusConditionNameTable, arg2->unk_00));

    if (sp34 >= 0x28) {
        Font_SetActive(1, -1);
        sp34 = arg3 + 0x1A;
    } else {
        Font_SetActive(1, 0);
        sp34 = (arg3 - (sp34 / 2)) + 0x2C;
    }

    Gfx_SetEnvColor(arg2->unk_04.r, arg2->unk_04.g, arg2->unk_04.b, 0xFF);
    Font_Printf(sp34, arg4 + 0xE, Text_GetString(NULL, 0, sStatusConditionNameTable, arg2->unk_00));
    Font_EndTexturedTextRendering();
}

s32 BattleHud_DrawBorderTile(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4) {
    UNUSED s32 pad[4];
    s32 sp2C;
    s32 sp28;

    if (arg2 < 9) {
        sp2C = 0x400;
    } else {
        sp2C = 0;
    }

    // clang-format off
    if (arg3 < 9) { sp28 = 0x400; } else { sp28 = 0; }
    // clang-format on

    gDPLoadTextureBlock(gDisplayListHead++, arg4, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRect(arg0, arg1, (arg0 + arg2) - 1, (arg1 + arg3) - 1, sp2C, sp28, 0);
}

void func_84311420(void) {
}

void BattleHud_DrawBoxBorder(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 i;

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    BattleHud_DrawBorderTile(arg0, arg1 - 1, 8, 8, D_3008480);
    BattleHud_DrawBorderTile(arg0, (arg1 + arg3) - 6, 8, 8, D_3008400);
    BattleHud_DrawBorderTile((arg0 + arg2) - 6, arg1 - 1, 8, 8, D_3008600);
    BattleHud_DrawBorderTile((arg0 + arg2) - 6, (arg1 + arg3) - 6, 8, 8, D_3008580);

    for (i = 0; i < arg3 / 8; i++) {
        if ((arg3 - 4) >= (6 + i * 8)) {
            BattleHud_DrawBorderTile((arg0 + arg2) - 6, arg1 + (i * 8) + 4, 8, 8, D_3008500);
        }
    }

    for (i = 0; i < arg3 / 8; i++) {
        if ((arg3 - 4) >= (6 + i * 8)) {
            BattleHud_DrawBorderTile(arg0, arg1 + (i * 8) + 4, 8, 8, D_3008380);
        }
    }

    for (i = 0; i < arg2 / 8; i++) {
        if ((arg2 - 4) >= (6 + i * 8)) {
            BattleHud_DrawBorderTile(arg0 + (i * 8) + 3, arg1 - 1, 8, 8, D_3008700);
        }

        if ((arg2 - 4) >= (6 + i * 8)) {
            BattleHud_DrawBorderTile(arg0 + (i * 8) + 3, (arg1 + arg3) - 6, 8, 8, D_3008680);
        }
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void BattleHud_DrawParticipantTimer(s16 arg0, s16 arg1) {
    Color_RGB8 sp54[] = {
        { 0xB4, 0x00, 0x00 },
        { 0xCC, 0x8F, 0x00 },
        { 0x00, 0xB4, 0x00 },
        { 0x00, 0x00, 0x00 },
    };
    char sp44[16];
    UNUSED s32 pad[4];
    s32 var_v1;
    s32 temp_t0;

    temp_t0 = ((s32)((D_84390124 / 30.0f) / 60.0f) * 0x3C) + ((s32)(D_84390124 / 30.0f) % 60);
    if (temp_t0 >= 0xB) {
        var_v1 = 2;
    } else if (temp_t0 >= 4) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }

    Gfx_FillRectWithDisplayState(arg0 - 1, arg1, 0x14, 0xD, sp54[var_v1].r, sp54[var_v1].g, sp54[var_v1].b, 0xBE);
    BattleHud_DrawBoxBorder(arg0 - 2, arg1 - 1, 0x14, 0xC);

    sprintf(sp44, "%02d", temp_t0);

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    Font_SetActive(1, 0);
    Font_Printf(arg0 + 3, arg1, sp44);
    Font_EndTexturedTextRendering();
    BattleHud_DrawTranslucentShadowRect(arg0 - 3, arg1 - 3, 0x19, 0x12, 0);
}

void BattleHud_DrawBattleTimer(s16 arg0, s16 arg1) {
    char sp40[16];
    f32 sp3C = D_84390128 / 30.0f;
    UNUSED s32 pad[2];

    Gfx_FillRectWithDisplayState(arg0, arg1, 0x27, 0xC, 0, 0, 0, 0x5A);
    BattleHud_DrawBoxBorder(arg0 - 2, arg1 - 1, 0x27, 0xC);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(2, 0);
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    sprintf(sp40, "%02d", (s32)(sp3C / 60.0f));
    Font_SetActive(1, 0);
    Font_Printf(arg0 + 3, arg1, sp40);
    Font_Printf(arg0 + 0x10, arg1, ":");
    sprintf(sp40, "%02d", (s32)sp3C % 60);
    Font_SetActive(1, 0);
    Font_Printf(arg0 + 0x17, arg1, sp40);
    Font_EndTexturedTextRendering();
    BattleHud_DrawTranslucentShadowRect(arg0 - 3, arg1 - 3, 0x2C, 0x11, 0);
}

void BattleHud_DrawPartyBallRow(ActivePokemon* arg0, s16 arg1, s16 arg2) {
    u8* sp74[] = { D_3006170, D_30061D0, D_3006230 };
    UNUSED s32 pad;
    s32 i;
    s32 j;
    s32 var_v0_2;

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    if (arg0 == sActivePokemon[0]) {
        if (arg0->sessionTeams->unk_01 == 1) {
            for (i = 0; i < arg0->sessionTeams->teamMember[0]->numberOfPokemonBrought; i++) {
                if (arg0->sessionTeams->teamMember[0]->pokemonPicked[i].unk_02 == 0) {
                    var_v0_2 = 2;
                } else if (arg0->sessionTeams->teamMember[0]->pokemonPicked[i].statusCondition != 0) {
                    var_v0_2 = 1;
                } else {
                    var_v0_2 = 0;
                }
                Gfx_DrawTextureRgba16(arg1 + i * 7, arg2, 8, 6, sp74[var_v0_2], 8, 0);
            }
        } else {
            for (i = 0; i < arg0->sessionTeams->teamMember[0]->numberOfPokemonBrought; i++) {
                if (arg0->sessionTeams->teamMember[0]->pokemonPicked[i].unk_02 == 0) {
                    var_v0_2 = 2;
                } else if (arg0->sessionTeams->teamMember[0]->pokemonPicked[i].statusCondition != 0) {
                    var_v0_2 = 1;
                } else {
                    var_v0_2 = 0;
                }
                Gfx_DrawTextureRgba16(arg1 + i * 7, arg2, 8, 6, sp74[var_v0_2], 8, 0);
            }

            for (j = 0; j < arg0->sessionTeams->teamMember[1]->numberOfPokemonBrought; j++) {
                if (arg0->sessionTeams->teamMember[1]->pokemonPicked[j].unk_02 == 0) {
                    var_v0_2 = 2;
                } else if (arg0->sessionTeams->teamMember[1]->pokemonPicked[j].statusCondition != 0) {
                    var_v0_2 = 1;
                } else {
                    var_v0_2 = 0;
                }
                Gfx_DrawTextureRgba16(arg1 + i * 7 + j * 7, arg2, 8, 6, sp74[var_v0_2], 8, 0);
            }
        }
    }

    if (arg0 == sActivePokemon[1]) {
        if (arg0->sessionTeams->unk_01 == 1) {
            for (i = 0; i < arg0->sessionTeams->teamMember[0]->numberOfPokemonBrought; i++) {
                if (arg0->sessionTeams->teamMember[0]->pokemonPicked[i].unk_02 == 0) {
                    var_v0_2 = 2;
                } else if (arg0->sessionTeams->teamMember[0]->pokemonPicked[i].statusCondition != 0) {
                    var_v0_2 = 1;
                } else {
                    var_v0_2 = 0;
                }
                Gfx_DrawTextureRgba16(arg1 - i * 7, arg2, 8, 6, sp74[var_v0_2], 8, 0);
            }
        } else {
            for (i = 0; i < arg0->sessionTeams->teamMember[0]->numberOfPokemonBrought; i++) {
                if (arg0->sessionTeams->teamMember[0]->pokemonPicked[i].unk_02 == 0) {
                    var_v0_2 = 2;
                } else if (arg0->sessionTeams->teamMember[0]->pokemonPicked[i].statusCondition != 0) {
                    var_v0_2 = 1;
                } else {
                    var_v0_2 = 0;
                }
                Gfx_DrawTextureRgba16(arg1 - i * 7, arg2, 8, 6, sp74[var_v0_2], 8, 0);
            }

            for (j = 0; j < arg0->sessionTeams->teamMember[1]->numberOfPokemonBrought; j++) {
                if (arg0->sessionTeams->teamMember[1]->pokemonPicked[j].unk_02 == 0) {
                    var_v0_2 = 2;
                } else if (arg0->sessionTeams->teamMember[1]->pokemonPicked[j].statusCondition != 0) {
                    var_v0_2 = 1;
                } else {
                    var_v0_2 = 0;
                }
                Gfx_DrawTextureRgba16(arg1 - i * 7 - j * 7, arg2, 8, 6, sp74[var_v0_2], 8, 0);
            }
        }
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void BattleHud_DrawMonStatusBoxPlayer(ActivePokemon* arg0, s16 arg1, s16 arg2, u16 arg3, s32 arg4) {
    UNUSED s32 pad[3];
    TeamRoster* sp80;
    BattleMon* sp7C;
    Color_RGB8* temp_v0_2;
    u32 var_v1;

    sp80 = arg0->sessionTeams->teamMember[arg0->presentationState.unk_16C];
    sp7C = &arg0->sessionTeams->teamMember[arg0->presentationState.unk_16C]->pokemonPicked[arg0->state.rosterIndex];

    if (sp7C->unk_02 == 0) {
        var_v1 = 1;
    } else {
        var_v1 = Status_ToDisplayIconIndex(sp7C->statusCondition);
    }

    temp_v0_2 = &D_84385860[sp80->unk_001];
    BattleHud_DrawMonInfoPanel(arg0, sp7C, &D_84385790[var_v1], arg1 + 1, arg2 + 0x12, 0x46, 0x28, temp_v0_2->r, temp_v0_2->g,
                  temp_v0_2->b, 0xB2);
    BattleHud_DrawSpeciesNameLabelAuto(arg0, sp80, arg1 + 1, arg2 + 1, sp80->unk_001, arg3, arg4);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    BattleHud_DrawBorderTile(arg1, arg2, 8, 8, D_3008480);
    BattleHud_DrawBorderTile(arg1, arg2 + 0xF, 8, 8, D_3008200);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x36, 8, 8, D_3008200);
    BattleHud_DrawBorderTile(arg1 + 0x41, arg2, 8, 8, D_3008600);
    BattleHud_DrawBorderTile(arg1 + 0x41, arg2 + 0xF, 8, 8, D_3008280);
    BattleHud_DrawBorderTile(arg1 + 0x41, arg2 + 0x33, 8, 8, D_3008580);
    BattleHud_DrawBorderTile(arg1 + 8, arg2, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x10, arg2, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x18, arg2, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x20, arg2, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x28, arg2, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x30, arg2, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x38, arg2, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x39, arg2, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 8, arg2 + 0x12, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x10, arg2 + 0x12, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x18, arg2 + 0x12, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x20, arg2 + 0x12, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x28, arg2 + 0x12, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x30, arg2 + 0x12, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x38, arg2 + 0x12, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x39, arg2 + 0x12, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 8, arg2 + 0x33, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0x10, arg2 + 0x33, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0x18, arg2 + 0x33, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0x20, arg2 + 0x33, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0x28, arg2 + 0x33, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0x30, arg2 + 0x33, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0x38, arg2 + 0x33, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0x39, arg2 + 0x33, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1, arg2 + 8, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x15, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x1D, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x25, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x2D, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x2E, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1 + 0x41, arg2 + 8, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x41, arg2 + 0x15, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x41, arg2 + 0x1D, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x41, arg2 + 0x25, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x41, arg2 + 0x2D, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x41, arg2 + 0x2F, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x3D, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x45, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x4D, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x55, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1 + 0x21, arg2 + 0x3A, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x21, arg2 + 0x3D, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x21, arg2 + 0x45, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x21, arg2 + 0x4D, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x21, arg2 + 0x55, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x21, arg2 + 0x59, 8, 8, D_3008580);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x59, 8, 8, D_3008400);
    BattleHud_DrawBorderTile(arg1 + 4, arg2 + 0x59, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0xC, arg2 + 0x59, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0x14, arg2 + 0x59, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0x1C, arg2 + 0x59, 8, 8, D_3008680);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    BattleHud_DrawTranslucentShadowRect(arg1 - 3, arg2 - 2, 0x4E, 0x3F, 0);
    BattleHud_DrawTranslucentShadowRect(arg1 - 3, arg2 + 0x3A, 0x2D, 0x29, 0);
    BattleHud_DrawPartyBallRow(arg0, arg1, arg2 + 0x62);
}

void BattleHud_DrawMonStatusBoxOpponent(ActivePokemon* arg0, s16 arg1, s16 arg2, u16 arg3, s32 arg4) {
    UNUSED s32 pad[3];
    TeamRoster* sp80;
    BattleMon* sp7C;
    Color_RGB8* temp_v0;
    u32 var_v1;

    sp80 = arg0->sessionTeams->teamMember[arg0->presentationState.unk_16C];
    sp7C = &arg0->sessionTeams->teamMember[arg0->presentationState.unk_16C]->pokemonPicked[arg0->state.rosterIndex];

    if (sp7C->unk_02 == 0) {
        var_v1 = 1;
    } else {
        var_v1 = Status_ToDisplayIconIndex(sp7C->statusCondition);
    }

    temp_v0 = &D_84385860[sp80->unk_001];
    BattleHud_DrawMonInfoPanel(arg0, sp7C, &D_84385790[var_v1], arg1, arg2 + 0x28, 0x46, 0x28, temp_v0->r, temp_v0->g, temp_v0->b,
                  0xB2);
    BattleHud_DrawSpeciesNameLabelAuto(arg0, sp80, arg1, arg2 + 0x50, sp80->unk_001, arg3, arg4);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    BattleHud_DrawBorderTile(arg1, arg2 + 0x4C, 8, 8, D_3008200);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x5B, 8, 8, D_3008400);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x27, 8, 8, D_3008480);
    BattleHud_DrawBorderTile(arg1 + 0x3F, arg2 + 0x24, 8, 8, D_3008280);
    BattleHud_DrawBorderTile(arg1 + 0x3F, arg2 + 0x4C, 8, 8, D_3008280);
    BattleHud_DrawBorderTile(arg1 + 0x3F, arg2 + 0x5B, 8, 8, D_3008580);
    BattleHud_DrawBorderTile(arg1 + 7, arg2 + 0x27, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 8, arg2 + 0x27, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x10, arg2 + 0x27, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x18, arg2 + 0x27, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x20, arg2 + 0x27, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x28, arg2 + 0x27, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x30, arg2 + 0x27, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x38, arg2 + 0x27, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 7, arg2 + 0x4F, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 8, arg2 + 0x4F, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x10, arg2 + 0x4F, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x18, arg2 + 0x4F, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x20, arg2 + 0x4F, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x28, arg2 + 0x4F, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x30, arg2 + 0x4F, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x38, arg2 + 0x4F, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 7, arg2 + 0x5B, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 8, arg2 + 0x5B, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0x10, arg2 + 0x5B, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0x18, arg2 + 0x5B, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0x20, arg2 + 0x5B, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0x28, arg2 + 0x5B, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0x30, arg2 + 0x5B, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1 + 0x38, arg2 + 0x5B, 8, 8, D_3008680);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x2C, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x34, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x3C, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x44, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x52, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1, arg2 + 0x53, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1 + 0x3F, arg2 + 0x2C, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x3F, arg2 + 0x34, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x3F, arg2 + 0x3C, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x3F, arg2 + 0x44, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x3F, arg2 + 0x52, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x3F, arg2 + 0x53, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x3F, arg2, 8, 8, D_3008600);
    BattleHud_DrawBorderTile(arg1 + 0x1E, arg2, 8, 8, D_3008480);
    BattleHud_DrawBorderTile(arg1 + 0x3F, arg2 + 8, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x3F, arg2 + 0x10, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x3F, arg2 + 0x18, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x3F, arg2 + 0x20, 8, 8, D_3008500);
    BattleHud_DrawBorderTile(arg1 + 0x1E, arg2 + 8, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1 + 0x1E, arg2 + 0x10, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1 + 0x1E, arg2 + 0x18, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1 + 0x1E, arg2 + 0x1F, 8, 8, D_3008380);
    BattleHud_DrawBorderTile(arg1 + 0x20, arg2, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x28, arg2, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x30, arg2, 8, 8, D_3008700);
    BattleHud_DrawBorderTile(arg1 + 0x37, arg2, 8, 8, D_3008700);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    BattleHud_DrawTranslucentShadowRect(arg1 + 0x1B, arg2 - 2, 0x2F, 0x2A, 0);
    BattleHud_DrawTranslucentShadowRect(arg1 - 4, arg2 + 0x26, 0x4D, 0x3D, 0);
    BattleHud_DrawPartyBallRow(arg0, arg1 + 0x41, arg2 - 7);
}

void BattleHud_DrawThreeOptionLabelBar(ActivePokemon* arg0, s16 arg1, s16 arg2, s32 arg3) {
    UNUSED s32 pad[2];

    Battle_DrawGradientRectWrapper(arg1 + 1, arg2 + 1, 0xC6, 0x10, &D_84385860[arg3], &D_84385870[arg3]);
    BattleHud_DrawBoxBorder(arg1, arg2, 0xC6, 0x10);

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    Gfx_DrawTextureRgba16Ia8(arg1 + 7, arg2 + 3, 0x10, 0xC, D_3008C00, D_3008D80, 0x10, 0x100000);
    Gfx_DrawTextureRgba16Ia8(arg1 + 0x46, arg2 + 3, 0x10, 0xC, D_3008E40, D_3008FC0, 0x10, 0x100000);
    Gfx_DrawTextureRgba16Ia8(arg1 + 0x86, arg2 + 3, 0x10, 0xC, D_3009080, D_3009200, 0x10, 0x100000);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(1, 0);
    Font_Printf(arg1 + 0x18, arg2 + 3, Text_GetString(NULL, 0, sBattleMessagesTable, 0x9E));
    Font_Printf(arg1 + 0x58, arg2 + 3, Text_GetString(NULL, 0, sBattleMessagesTable, 0x9F));
    Font_Printf(arg1 + 0x98, arg2 + 3, Text_GetString(NULL, 0, sBattleMessagesTable, 0xA0));
    Font_EndTexturedTextRendering();
    BattleHud_DrawTranslucentShadowRect(arg1 - 2, arg2 - 2, 0xCC, 0x16, 0);
}

void BattleHud_DrawTwoOptionLabelBar(ActivePokemon* arg0, s16 arg1, s16 arg2, s32 arg3) {
    UNUSED s32 pad[2];

    Battle_DrawGradientRectWrapper(arg1, arg2, 0x7D, 0x10, &D_84385860[arg3], &D_84385870[arg3]);
    BattleHud_DrawBoxBorder(arg1, arg2, 0x7D, 0x10);

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    Gfx_DrawTextureRgba16Ia8(arg1 + 7, arg2 + 3, 0x10, 0xC, D_3008780, D_3008900, 0x10, 0x100000);
    Gfx_DrawTextureRgba16Ia8(arg1 + 0x40, arg2 + 3, 0x10, 0xC, D_30089C0, D_3008B40, 0x10, 0x100000);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(1, 0);
    Font_Printf(arg1 + 0x18, arg2 + 3, Text_GetString(NULL, 0, sBattleMessagesTable, 0xA9));
    Font_Printf(arg1 + 0x51, arg2 + 3, Text_GetString(NULL, 0, sBattleMessagesTable, 0xA8));
    Font_EndTexturedTextRendering();
    BattleHud_DrawTranslucentShadowRect(arg1 - 2, arg2 - 2, 0x83, 0x16, 0);
}

void BattleHud_DrawOneOptionLabelBar(ActivePokemon* arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 pad[2];

    Battle_DrawGradientRectWrapper(arg1 + 1, arg2 + 1, 0x47, 0x10, &D_84385860[arg3], &D_84385870[arg3]);
    BattleHud_DrawBoxBorder(arg1, arg2, 0x47, 0x10);

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    Gfx_DrawTextureRgba16Ia8(arg1 + 7, arg2 + 3, 0x10, 0xC, D_30089C0, D_3008B40, 0x10, 0x100000);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(1, 0);
    Font_Printf(arg1 + 0x18, arg2 + 3, Text_GetString(NULL, 0, sBattleMessagesTable, 0xA8));
    Font_EndTexturedTextRendering();
    BattleHud_DrawTranslucentShadowRect(arg1 - 2, arg2 - 2, 0x4A, 0x16, 0);
}

void Battle_DrawRightAlignedText(s32 arg0, s32 arg1, char* arg2) {
    Font_Printf(arg0 - (strlen(arg2) * 6), arg1, arg2);
}

s32 BattleHud_DrawMovePpTextLTR(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    UNUSED s32 pad[2];
    s8 sp70[7];
    s32 i;
    u8** temp_s2;
    u8* var_v1;

    temp_s2 = Memmap_GetSegmentVaddr(D_300B870);
    sprintf(sp70, "%3d/%3d", arg2 & 0x3F, arg3);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    for (i = 0; i < 7; i++) {
        s32 c = sp70[i];

        switch (c) {
            case ' ':
                var_v1 = NULL;
                break;

            case '/':
                var_v1 = temp_s2[10];
                break;

            default:
                if ((c >= 0x30) && (c < 0x3A)) {
                    var_v1 = temp_s2[c - '0'];
                } else {
                    var_v1 = NULL;
                }
                break;
        }

        if (var_v1 != NULL) {
            Gfx_DrawTextureRgba16(arg0, arg1, 8, 6, var_v1, 8, 0);
            arg0 += 8;
        }
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    return arg0;
}

s32 BattleHud_DrawMovePpTextRTL(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    UNUSED s32 pad[2];
    s8 sp70[7];
    s32 i;
    u8** temp_s2;
    u8* var_v1;

    temp_s2 = Memmap_GetSegmentVaddr(D_300B870);
    sprintf(sp70, "%3d/%3d", arg2 & 0x3F, arg3);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    for (i = 7; i > 0; i--) {
        s32 c = sp70[i];

        switch (c) {
            case ' ':
                var_v1 = NULL;
                break;

            case '/':
                var_v1 = temp_s2[10];
                break;

            default:
                if ((c >= 0x30) && (c < 0x3A)) {
                    var_v1 = temp_s2[c - '0'];
                } else {
                    var_v1 = NULL;
                }
                break;
        }

        if (var_v1 != NULL) {
            Gfx_DrawTextureRgba16(arg0, arg1, 8, 6, var_v1, 8, 0);
            arg0 -= 8;
        }
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    return arg0;
}

void BattleHud_DrawMoveSelectMenu(ActivePokemon* arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 i;
    s32 sp64[] = { 0, 0, 0, 0 };
    u8 sp60[4];
    BattleMonRuntime* temp_s0;
    BattleMon* sp58;
    UNUSED s32 pad;

    sp58 = &arg0->sessionTeams->teamMember[arg0->presentationState.unk_16C]->pokemonPicked[arg0->state.rosterIndex];
    temp_s0 = &arg0->state.runtime;

    Battle_DrawGradientRectWrapper(arg1 + 1, arg2 + 1, 0xC7, 0x38, &D_84385860[arg3], &D_84385870[arg3]);
    BattleHud_DrawBoxBorder(arg1, arg2, 0xC7, 0x38);

    for (i = 0; i < 4; i++) {
        if (temp_s0->unk_4E & 8) {
            sp60[i] = gMoveData[temp_s0->moves[i] - 1].unk_05 / 5;
            if (sp60[i] >= 8) {
                sp60[i] = 7;
            }
            sp60[i] = gMoveData[temp_s0->moves[i] - 1].unk_05 + (((temp_s0->unk_32[i] & 0xC0) >> 6) * sp60[i]);
        } else {
            sp60[i] = gMoveData[sp58->unk_09[i] - 1].unk_05 / 5;
            if (sp60[i] >= 8) {
                sp60[i] = 7;
            }
            sp60[i] = gMoveData[sp58->unk_09[i] - 1].unk_05 + (((sp58->unk_20[i] & 0xC0) >> 6) * sp60[i]);
        }
    }

    if (temp_s0->unk_4E & 8) {
        if ((temp_s0->moves[0] != 0) && (temp_s0->moves[0] < 0xA6)) {
            sp64[0] = BattleHud_DrawMovePpTextRTL(arg1 + 0x52, arg2 + 0xF, temp_s0->unk_32[0], sp60[0]);
        }

        if ((temp_s0->moves[1] != 0) && (temp_s0->moves[1] < 0xA6)) {
            sp64[1] = BattleHud_DrawMovePpTextLTR(arg1 + 0x7C, arg2 + 0x1C, temp_s0->unk_32[1], sp60[1]);
        }

        if ((temp_s0->moves[2] != 0) && (temp_s0->moves[2] < 0xA6)) {
            sp64[2] = BattleHud_DrawMovePpTextLTR(arg1 + 0x70, arg2 + 0x30, temp_s0->unk_32[2], sp60[2]);
        }

        if ((temp_s0->moves[3] != 0) && (temp_s0->moves[3] < 0xA6)) {
            sp64[3] = BattleHud_DrawMovePpTextRTL(arg1 + 0x44, arg2 + 0x23, temp_s0->unk_32[3], sp60[3]);
        }
    } else {
        if ((sp58->unk_09[0] != 0) && (sp58->unk_09[0] < 0xA6)) {
            sp64[0] = BattleHud_DrawMovePpTextRTL(arg1 + 0x52, arg2 + 0xF, sp58->unk_20[0], sp60[0]);
        }

        if ((sp58->unk_09[1] != 0) && (sp58->unk_09[1] < 0xA6)) {
            sp64[1] = BattleHud_DrawMovePpTextLTR(arg1 + 0x7C, arg2 + 0x1C, sp58->unk_20[1], sp60[1]);
        }

        if ((sp58->unk_09[2] != 0) && (sp58->unk_09[2] < 0xA6)) {
            sp64[2] = BattleHud_DrawMovePpTextLTR(arg1 + 0x70, arg2 + 0x30, sp58->unk_20[2], sp60[2]);
        }

        if ((sp58->unk_09[3] != 0) && (sp58->unk_09[3] < 0xA6)) {
            sp64[3] = BattleHud_DrawMovePpTextRTL(arg1 + 0x44, arg2 + 0x23, sp58->unk_20[3], sp60[3]);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    Gfx_DrawTextureRgba16Ia8(arg1 + 0x5D, arg2 + 6, 0x10, 0xE, &D_3006A70, &D_3006C30, 0x10, 0x100000);
    Gfx_DrawTextureRgba16Ia8(arg1 + 0x6C, arg2 + 0x16, 0x10, 0xE, &D_3006290, &D_3006450, 0x10, 0x100000);
    Gfx_DrawTextureRgba16Ia8(arg1 + 0x5D, arg2 + 0x26, 0x10, 0xE, &D_3006530, &D_30066F0, 0x10, 0x100000);
    Gfx_DrawTextureRgba16Ia8(arg1 + 0x4E, arg2 + 0x16, 0x10, 0xE, &D_30067D0, &D_3006990, 0x10, 0x100000);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    if (temp_s0->unk_4E & 8) {
        if ((temp_s0->moves[0] != 0) && (temp_s0->moves[0] < 0xA6)) {
            Gfx_DrawTextureRgba16(sp64[0] - 0x19, arg2 + 0xE, 0x20, 9, D_843857C8[gMoveData[temp_s0->moves[0] - 1].unk_03],
                          0x20, 0);
        }

        if ((temp_s0->moves[1] != 0) && (temp_s0->moves[1] < 0xA6)) {
            Gfx_DrawTextureRgba16(sp64[1], arg2 + 0x1B, 0x20, 9, D_843857C8[gMoveData[temp_s0->moves[1] - 1].unk_03], 0x20,
                          0);
        }

        if ((temp_s0->moves[2] != 0) && (temp_s0->moves[2] < 0xA6)) {
            Gfx_DrawTextureRgba16(sp64[2], arg2 + 0x2F, 0x20, 9, D_843857C8[gMoveData[temp_s0->moves[2] - 1].unk_03], 0x20,
                          0);
        }

        if ((temp_s0->moves[3] != 0) && (temp_s0->moves[3] < 0xA6)) {
            Gfx_DrawTextureRgba16(sp64[3] - 0x18, arg2 + 0x22, 0x20, 9, D_843857C8[gMoveData[temp_s0->moves[3] - 1].unk_03],
                          0x20, 0);
        }
    } else {
        if ((temp_s0->moves[0] != 0) && (temp_s0->moves[0] < 0xA6)) {
            Gfx_DrawTextureRgba16(sp64[0] - 0x19, arg2 + 0xE, 0x20, 9, D_843857C8[gMoveData[temp_s0->moves[0] - 1].unk_03],
                          0x20, 0);
        }

        if ((temp_s0->moves[1] != 0) && (temp_s0->moves[1] < 0xA6)) {
            Gfx_DrawTextureRgba16(sp64[1], arg2 + 0x1B, 0x20, 9, D_843857C8[gMoveData[temp_s0->moves[1] - 1].unk_03], 0x20,
                          0);
        }

        if ((temp_s0->moves[2] != 0) && (temp_s0->moves[2] < 0xA6)) {
            Gfx_DrawTextureRgba16(sp64[2], arg2 + 0x2F, 0x20, 9, D_843857C8[gMoveData[temp_s0->moves[2] - 1].unk_03], 0x20,
                          0);
        }

        if ((temp_s0->moves[3] != 0) && (temp_s0->moves[3] < 0xA6)) {
            Gfx_DrawTextureRgba16(sp64[3] - 0x18, arg2 + 0x22, 0x20, 9, D_843857C8[gMoveData[temp_s0->moves[3] - 1].unk_03],
                          0x20, 0);
        }
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(1, 0);

    if (temp_s0->unk_4E & 8) {
        if ((temp_s0->moves[0] != 0) && (temp_s0->moves[0] < 0xA6)) {
            if (arg0->state.moveSlotIllegality[0] == 1) {
                Gfx_SetEnvColor(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            }
            Battle_DrawRightAlignedText(arg1 + 0x5A, arg2 + 4, Text_GetString(NULL, 0, sMoveNameTable, temp_s0->moves[0] - 1));
        }

        if ((temp_s0->moves[1] != 0) && (temp_s0->moves[1] < 0xA6)) {
            if (arg0->state.moveSlotIllegality[1] == 1) {
                Gfx_SetEnvColor(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            }
            Font_Printf(arg1 + 0x7C, arg2 + 0x11, Text_GetString(NULL, 0, sMoveNameTable, temp_s0->moves[1] - 1));
        }

        if ((temp_s0->moves[2] != 0) && (temp_s0->moves[2] < 0xA6)) {
            if (arg0->state.moveSlotIllegality[2] == 1) {
                Gfx_SetEnvColor(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            }
            Font_Printf(arg1 + 0x6E, arg2 + 0x25, Text_GetString(NULL, 0, sMoveNameTable, temp_s0->moves[2] - 1));
        }

        if ((temp_s0->moves[3] != 0) && (temp_s0->moves[3] < 0xA6)) {
            if (arg0->state.moveSlotIllegality[3] == 1) {
                Gfx_SetEnvColor(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            }
            Battle_DrawRightAlignedText(arg1 + 0x4C, arg2 + 0x18, Text_GetString(NULL, 0, sMoveNameTable, temp_s0->moves[3] - 1));
        }
    } else {
        if ((temp_s0->moves[0] != 0) && (temp_s0->moves[0] < 0xA6)) {
            if (arg0->state.moveSlotIllegality[0] == 1) {
                Gfx_SetEnvColor(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            }
            Battle_DrawRightAlignedText(arg1 + 0x5A, arg2 + 4, Text_GetString(NULL, 0, sMoveNameTable, temp_s0->moves[0] - 1));
        }

        if ((temp_s0->moves[1] != 0) && (temp_s0->moves[1] < 0xA6)) {
            if (arg0->state.moveSlotIllegality[1] == 1) {
                Gfx_SetEnvColor(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            }
            Font_Printf(arg1 + 0x7C, arg2 + 0x11, Text_GetString(NULL, 0, sMoveNameTable, temp_s0->moves[1] - 1));
        }

        if ((temp_s0->moves[2] != 0) && (temp_s0->moves[2] < 0xA6)) {
            if (arg0->state.moveSlotIllegality[2] == 1) {
                Gfx_SetEnvColor(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            }
            Font_Printf(arg1 + 0x6E, arg2 + 0x25, Text_GetString(NULL, 0, sMoveNameTable, temp_s0->moves[2] - 1));
        }

        if ((temp_s0->moves[3] != 0) && (temp_s0->moves[3] < 0xA6)) {
            if (arg0->state.moveSlotIllegality[3] == 1) {
                Gfx_SetEnvColor(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            }
            Battle_DrawRightAlignedText(arg1 + 0x4C, arg2 + 0x18, Text_GetString(NULL, 0, sMoveNameTable, temp_s0->moves[3] - 1));
        }
    }

    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);

    if (temp_s0->moves[0] >= 0xA6) {
        Battle_DrawRightAlignedText(arg1 + 0x5A, arg2 + 4, "？？？？？");
    }

    if (temp_s0->moves[1] >= 0xA6) {
        Font_Printf(arg1 + 0x7C, arg2 + 0x11, "？？？？？");
    }

    if (temp_s0->moves[2] >= 0xA6) {
        Font_Printf(arg1 + 0x6E, arg2 + 0x25, "？？？？？");
    }

    if (temp_s0->moves[3] >= 0xA6) {
        Battle_DrawRightAlignedText(arg1 + 0x4C, arg2 + 0x18, "？？？？？");
    }

    Font_EndTexturedTextRendering();
    BattleHud_DrawTranslucentShadowRect(arg1 - 2, arg2 - 2, 0xCD, 0x3E, 0);
}

void BattleHud_DrawForfeitConfirmDialog(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    UNUSED s32 pad[2];
    s32 var_v1;

    if (Trainer_GetSlots()[arg2].unk_000 & 2) {
        var_v1 = 4;
    } else {
        var_v1 = arg2;
    }

    Battle_DrawGradientRectWrapper(arg0 + 1, arg1 + 1, 0xC6, 0x28, &D_84385860[var_v1], &D_84385870[var_v1]);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(2, 0);
    Font_Printf(arg0 + 0x2E, arg1 + 6, "こうさんしますか?");
    Font_Printf(arg0 + 0x38, arg1 + 0x18, "いいえ");
    Font_Printf(arg0 + 0x81, arg1 + 0x18, "はい");
    Font_EndTexturedTextRendering();

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    Gfx_DrawTextureRgba16Ia8(arg0 + 0x21, arg1 + 0x17, 0x18, 0xE, D_30092C0, D_3009560, 0x18, 0x100000);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    BattleHud_DrawBoxBorder(arg0, arg1, 0xC6, 0x28);
    BattleHud_DrawTranslucentShadowRect(arg0 - 3, arg1 - 2, 0xCC, 0x2D, 0);
}

void BattleHud_DrawPlainText(s16 arg0, s16 arg1, char* arg2) {
    Font_BeginTranslucentTextRendering();
    Font_SetActive(1, 0);
    Font_Printf(arg0, arg1, arg2);
    Font_EndTexturedTextRendering();
}

void BattleHud_DrawDoublesRosterRow(ActivePokemon* arg0, TeamRoster* arg1, BattleMon* arg2, s32 arg3, s32 arg4,
                   s32 arg5) {
    s32 var_t0;

    BattleHud_DrawLevelNumber(arg3 + 3, arg4 + 4, arg2->unk_24);
    BattleHud_DrawHpBar(arg3 + 0x1E, arg4 + 0xE, arg2->unk_02, arg2->unk_26);
    BattleHud_DrawHpFractionText(arg3 + 0x26, arg4 + 0x14, arg2->unk_02, arg2->unk_26);

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    if (arg5 == 0) {
        Gfx_DrawTextureRgba16Ia8(arg3 + 2, arg4 + 0xD, 0x10, 0xE, D_3006A70, D_3006C30, 0x10, 0x100000);
    }

    if (arg5 == 1) {
        Gfx_DrawTextureRgba16Ia8(arg3 + 2, arg4 + 0xD, 0x10, 0xE, D_30067D0, D_3006990, 0x10, 0x100000);
    }

    if (arg5 == 2) {
        Gfx_DrawTextureRgba16Ia8(arg3 + 2, arg4 + 0xD, 0x10, 0xC, D_3008E40, D_3008FC0, 0x10, 0x100000);
    }

    if (arg5 == 3) {
        Gfx_DrawTextureRgba16Ia8(arg3 + 2, arg4 + 0xD, 0x10, 0xE, D_3006290, D_3006450, 0x10, 0x100000);
    }

    if (arg5 == 4) {
        Gfx_DrawTextureRgba16Ia8(arg3 + 2, arg4 + 0xD, 0x10, 0xE, D_3006530, D_30066F0, 0x10, 0x100000);
    }

    if (arg5 == 5) {
        Gfx_DrawTextureRgba16Ia8(arg3 + 2, arg4 + 0xD, 0x10, 0xC, D_3008C00, D_3008D80, 0x10, 0x100000);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(1, 0);
    Font_Printf(arg3 + 0x1D, arg4 + 2, arg2->unk_30);
    Font_EndTexturedTextRendering();

    if (arg1->pokemonPicked[arg5].unk_02 == 0) {
        var_t0 = 1;
    } else {
        var_t0 = Status_ToDisplayIconIndex(arg1->pokemonPicked[arg5].statusCondition);
    }

    if (var_t0 != 0) {
        gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

        Gfx_DrawTextureRgba16(arg3 + 0x11, arg4 + 0x14, 0x14, 9, D_84385838[var_t0 - 1], 0x14, 0);
        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
    }
}

void BattleHud_DrawPartyRosterRow(ActivePokemon* arg0, TeamRoster* arg1, BattleMon* arg2, s32 arg3, s32 arg4,
                   s32 arg5) {
    s32 var_t0;

    BattleHud_DrawLevelNumber(arg3 + 3, arg4 + 4, arg2->unk_24);
    BattleHud_DrawHpBar(arg3 + 0x1E, arg4 + 0xE, arg2->unk_02, arg2->unk_26);
    BattleHud_DrawHpFractionText(arg3 + 0x26, arg4 + 0x14, arg2->unk_02, arg2->unk_26);

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    if (arg5 == 0) {
        Gfx_DrawTextureRgba16Ia8(arg3 + 2, arg4 + 0xD, 0x10, 0xE, D_3006A70, D_3006C30, 0x10, 0x100000);
    }

    if (arg5 == 1) {
        Gfx_DrawTextureRgba16Ia8(arg3 + 2, arg4 + 0xD, 0x10, 0xE, D_3006290, D_3006450, 0x10, 0x100000);
    }

    if (arg5 == 2) {
        Gfx_DrawTextureRgba16Ia8(arg3 + 2, arg4 + 0xD, 0x10, 0xE, D_3006530, D_30066F0, 0x10, 0x100000);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(1, 0);
    Font_Printf(arg3 + 0x1D, arg4 + 2, arg2->unk_30);
    Font_EndTexturedTextRendering();

    if (arg1->pokemonPicked[arg5].unk_02 == 0) {
        var_t0 = 1;
    } else {
        var_t0 = Status_ToDisplayIconIndex(arg1->pokemonPicked[arg5].statusCondition);
    }

    if (var_t0 != 0) {
        gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

        Gfx_DrawTextureRgba16(arg3 + 0x11, arg4 + 0x14, 0x14, 9, D_84385838[var_t0 - 1], 0x14, 0);

        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
    }
}

void BattleHud_DrawTeamStatusList(ActivePokemon* arg0, TeamRoster* arg1, s16 arg2, s16 arg3, s32 arg4) {
    UNUSED s32 pad[2];
    Color_RGB8* sp88[] = {
        D_84385888,
        D_843858A0,
        D_843858B8,
        D_843858D0,
    };
    Color_RGB8* sp78[] = {
        D_84385894,
        D_843858AC,
        D_843858C4,
        D_843858DC,
    };
    UNUSED s32 pad2[4];

    Battle_DrawGradientRectWrapper(arg2 + 1, arg3 + 1, 0x63, 0xF, &sp88[arg4][0], &sp78[arg4][0]);
    Battle_DrawGradientRectWrapper(arg2 + 1, arg3 + 0x10, 0x63, 0x1D, &sp88[arg4][1], &sp78[arg4][1]);
    Battle_DrawGradientRectWrapper(arg2 + 1, arg3 + 0x2D, 0x63, 0x1D, &sp88[arg4][2], &sp78[arg4][2]);
    Battle_DrawGradientRectWrapper(arg2 + 1, arg3 + 0x4A, 0x63, 0x1D, &sp88[arg4][3], &sp78[arg4][3]);

    BattleHud_DrawPlainText((arg2 - (Font_MeasureTextExtent(1, 0, arg1->unk_008) / 2)) + 0x32, arg3 + 3, arg1->unk_008);

    if (arg1->numberOfPokemonBrought > 0) {
        BattleHud_DrawPartyRosterRow(arg0, arg1, &arg1->pokemonPicked[0], arg2 + 1, arg3 + 0x10, 0);
    }

    if (arg1->numberOfPokemonBrought >= 2) {
        BattleHud_DrawPartyRosterRow(arg0, arg1, &arg1->pokemonPicked[1], arg2 + 1, arg3 + 0x2D, 1);
    }

    if (arg1->numberOfPokemonBrought >= 3) {
        BattleHud_DrawPartyRosterRow(arg0, arg1, &arg1->pokemonPicked[2], arg2 + 1, arg3 + 0x4A, 2);
    }

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    Gfx_DrawTextureRgba16(arg2 + 1, arg3, 0x18, 0x10, D_84385850[arg4], 0x18, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    BattleHud_DrawBoxBorder(arg2, arg3, 0x63, 0x66);
    BattleHud_DrawTranslucentShadowRect(arg2 - 2, arg3 - 2, 0x69, 0x6A, 0);
}

void BattleHud_DrawDoublesTeamStatusList(ActivePokemon* arg0, s16 arg1, s16 arg2, s32 arg3) {
    TeamRoster* temp_s0;
    TeamRoster* temp_s1;
    BattleMon* ptr = &arg0->teamRoster->pokemonPicked[0];
    s32 i;
    Color_RGB8* sp88[] = {
        D_84385888,
        D_843858A0,
        D_843858B8,
        D_843858D0,
    };
    Color_RGB8* sp78[] = {
        D_84385894,
        D_843858AC,
        D_843858C4,
        D_843858DC,
    };
    s32 tmp;
    BattleMon* sp5C[6];

    temp_s0 = arg0->sessionTeams->teamMember[arg0->presentationState.unk_16C];
    temp_s1 = arg0->teamRoster;

    sp5C[5] = &temp_s1->pokemonPicked[0];
    sp5C[5] = &temp_s1->pokemonPicked[0];
    sp5C[4] = &temp_s1->pokemonPicked[1];
    sp5C[3] = &temp_s1->pokemonPicked[2];
    sp5C[2] = &temp_s1->pokemonPicked[3];
    sp5C[1] = &temp_s1->pokemonPicked[4];
    sp5C[0] = &temp_s1->pokemonPicked[5];

    Battle_DrawGradientRectWrapper(arg1 + 1, arg2 + 1, 0xC8, 0xF, &sp88[arg3][0], &sp78[arg3][0]);
    Battle_DrawGradientRectWrapper(arg1 + 1, arg2 + 0x10, 0xC8, 0x1D, &sp88[arg3][1], &sp78[arg3][1]);
    Battle_DrawGradientRectWrapper(arg1 + 1, arg2 + 0x2D, 0xC8, 0x1D, &sp88[arg3][2], &sp78[arg3][2]);
    Battle_DrawGradientRectWrapper(arg1 + 1, arg2 + 0x4A, 0xC8, 0x1D, &sp88[arg3][3], &sp78[arg3][3]);
    tmp = Font_MeasureTextExtent(1, 0, temp_s0->unk_008) / 2;
    BattleHud_DrawPlainText((arg1 - tmp) + 0x32, arg2 + 3, temp_s0->unk_008);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    Gfx_DrawTextureRgba16(arg1 + 1, arg2, 0x18, 0x10, *(D_84385850 + arg3), 0x18, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    if (temp_s0->numberOfPokemonBrought > 0) {
        BattleHud_DrawDoublesRosterRow(arg0, temp_s0, sp5C[5], arg1 + 1, arg2 + 0x10, 0);
    }

    if (temp_s0->numberOfPokemonBrought >= 2) {
        BattleHud_DrawDoublesRosterRow(arg0, temp_s0, sp5C[4], arg1 + 1, arg2 + 0x2D, 1);
    }

    if (temp_s0->numberOfPokemonBrought >= 3) {
        BattleHud_DrawDoublesRosterRow(arg0, temp_s0, sp5C[3], arg1 + 1, arg2 + 0x4A, 2);
    }

    if (temp_s0->numberOfPokemonBrought >= 4) {
        BattleHud_DrawDoublesRosterRow(arg0, temp_s0, sp5C[2], arg1 + 0x66, arg2 + 0x10, 3);
    }

    if (temp_s0->numberOfPokemonBrought >= 5) {
        BattleHud_DrawDoublesRosterRow(arg0, temp_s0, sp5C[1], arg1 + 0x66, arg2 + 0x2D, 4);
    }

    if (temp_s0->numberOfPokemonBrought >= 6) {
        BattleHud_DrawDoublesRosterRow(arg0, temp_s0, sp5C[0], arg1 + 0x66, arg2 + 0x4A, 5);
    }

    BattleHud_DrawBoxBorder(arg1, arg2, 0xC8, 0x66);
    BattleHud_DrawTranslucentShadowRect(arg1 - 2, arg2 - 2, 0xCE, 0x6A, 0);
}

void BattleHud_DrawCompactMonStatusBox(ActivePokemon* arg0, s16 arg1, s16 arg2, s32 arg3) {
    UNUSED s32 pad;
    Color_RGB8* var_v0;
    u32 var_t0;
    ActivePokemonState* temp_v0;
    u16 tmp;
    BattleMon* sp40;

    sp40 = &arg0->sessionTeams->teamMember[arg0->presentationState.unk_16C]->pokemonPicked[arg0->state.rosterIndex];
    temp_v0 = &arg0->state;

    if (sp40->unk_02 == 0) {
        var_t0 = 1;
    } else {
        var_t0 = Status_ToDisplayIconIndex(sp40->statusCondition);
    }

    if (temp_v0->unk_30 < 0xFF00) {
        temp_v0->unk_30 -= 0x30;
    }

    tmp = temp_v0->unk_30;
    if ((tmp >> 8) & 1) {
        var_v0 = &D_84385860[arg3];
    } else {
        var_v0 = &D_8438587C[arg3];
    }

    BattleHud_DrawMonInfoPanel(arg0, sp40, &D_84385790[var_t0], arg1 + 1, arg2 + 1, 0x46, 0x28, var_v0->r, var_v0->g, var_v0->b,
                  0xB2);
    BattleHud_DrawBoxBorder(arg1, arg2, 0x46, 0x28);
    BattleHud_DrawTranslucentShadowRect(arg1 - 2, arg2 - 2, 0x4C, 0x2D, 0);
}

void BattleHud_DrawMessageBox(s32 arg0, s16 arg1, s16 arg2, char* arg3) {
    Battle_DrawGradientRectWrapper(arg1 + 1, arg2 + 1, 0xEE, 0x24, &D_84385860[arg0], &D_84385870[arg0]);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(2, 0);
    Font_SetLineHeight(0x10);
    Font_Printf(arg1 + 0xA, arg2 + 5, arg3);
    Font_EndTexturedTextRendering();
    BattleHud_DrawBoxBorder(arg1, arg2, 0xEE, 0x24);
    BattleHud_DrawTranslucentShadowRect(arg1 - 2, arg2 - 1, 0xF4, 0x29, 0);
}

s32 Battle_DrawTextIfNonEmpty(char* arg0, s16 arg1, s16 arg2) {
    if (*(s8*)arg0 == 0) {
        return 0;
    }
    Font_BeginTranslucentTextRendering();
    Font_SetActive(1, 0);
    Font_Printf(arg1, arg2, arg0);
    Font_EndTexturedTextRendering();
    return 1;
}

void BattleHud_DrawExpandingCaptionBox(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2, Vec3f arg3) {
    s16 sp2C;
    s16 sp28;
    Color_RGB8* temp_v0;
    ActivePokemon* temp_v1;
    TeamRoster* tmp;

    temp_v1 = sActivePokemon[arg0->unk_0C];
    tmp = temp_v1->sessionTeams->teamMember[temp_v1->presentationState.unk_16C];
    temp_v0 = &D_84385860[tmp->unk_001];

    sp2C = (arg1 - arg3.x) * 2;
    sp28 = (arg2 - arg3.y) * 2;

    Gfx_FillRectWithDisplayState(arg3.x, arg3.y, sp2C, sp28, temp_v0->r, temp_v0->g, temp_v0->b, 0x96);
    BattleHud_DrawBoxBorder(arg3.x, arg3.y, sp2C, sp28);
    BattleHud_DrawTranslucentShadowRect(arg0->unk_14.x - 2.0f, arg0->unk_14.y - 1.0f, 0xE0, 0x2B, 0);
}

void BattleHud_InitCaptionBoxPopup(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2) {
    Vec3f sp4C;
    Vec3f sp40;
    Vec3f sp34;
    UNUSED s32 pad;

    arg0->unk_08 = 0;
    arg0->unk_10 = 0;
    Vec3f_SetComponentsDuplicate(&sp40, arg1, arg2, 0.0f);
    Vec3f_SetComponentsDuplicate(&sp34, arg1 - 110.0f, arg2 - 19.0f, 0.0f);
    Vec3f_CalculateDistanceAngles(&sp40, &sp34, &arg0->unk_20, &arg0->unk_28, &arg0->unk_2A);
    Camera_ComputeEyeFromAngles(&sp40, &arg0->unk_14, arg0->unk_20, arg0->unk_28, arg0->unk_2A);
    arg0->unk_24 = arg0->unk_20 * 0.3f;
    Camera_ComputeEyeFromAngles(&sp40, &sp4C, arg0->unk_24, arg0->unk_28, arg0->unk_2A);
    BattleHud_DrawExpandingCaptionBox(arg0, arg1, arg2, sp4C);
}

s32 BattleHud_UpdateCaptionBoxPopup(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2) {
    Vec3f sp34;
    Vec3f sp28;

    Vec3f_SetComponentsDuplicate(&sp28, arg1, arg2, 0.0f);
    arg0->unk_24 = Math_StepToF(arg0->unk_24, arg0->unk_20, 15.0f, 15.0f);
    Camera_ComputeEyeFromAngles(&sp28, &sp34, arg0->unk_24, arg0->unk_28, arg0->unk_2A);
    BattleHud_DrawExpandingCaptionBox(arg0, arg1, arg2, sp34);

    if (arg0->unk_24 == arg0->unk_20) {
        return 1;
    }
    return 0;
}

void BattleHud_DrawExpandingCaptionBoxBlack(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2, Vec3f arg3) {
    Gfx_FillRectWithDisplayState(arg3.x, arg3.y, (s16)((arg1 - arg3.x) * 2), (s16)((arg2 - arg3.y) * 2), 0, 0, 0, 0x96);
    BattleHud_DrawBoxBorder(arg3.x, arg3.y, (s16)((arg1 - arg3.x) * 2), (s16)((arg2 - arg3.y) * 2));
    BattleHud_DrawTranslucentShadowRect(arg0->unk_14.x - 2.0f, arg0->unk_14.y - 1.0f, 0xE0, 0x2B, 0);
}

void BattleHud_InitCaptionBoxPopupBlack(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2) {
    Vec3f sp4C;
    Vec3f sp40;
    Vec3f sp34;
    UNUSED s32 pad;

    arg0->unk_08 = 0;
    arg0->unk_10 = 0;
    Vec3f_SetComponentsDuplicate(&sp40, arg1, arg2, 0.0f);
    Vec3f_SetComponentsDuplicate(&sp34, arg1 - 50.0f, arg2 - 10.0f, 0.0f);
    Vec3f_CalculateDistanceAngles(&sp40, &sp34, &arg0->unk_20, &arg0->unk_28, &arg0->unk_2A);
    Camera_ComputeEyeFromAngles(&sp40, &arg0->unk_14, arg0->unk_20, arg0->unk_28, arg0->unk_2A);
    arg0->unk_24 = arg0->unk_20 * 0.3f;
    Camera_ComputeEyeFromAngles(&sp40, &sp4C, arg0->unk_24, arg0->unk_28, arg0->unk_2A);
    BattleHud_DrawExpandingCaptionBoxBlack(arg0, arg1, arg2, sp4C);
}

s32 BattleHud_UpdateCaptionBoxPopupBlack(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2) {
    Vec3f sp34;
    Vec3f sp28;

    Vec3f_SetComponentsDuplicate(&sp28, arg1, arg2, 0.0f);
    arg0->unk_24 = Math_StepToF(arg0->unk_24, arg0->unk_20, 15.0f, 15.0f);
    Camera_ComputeEyeFromAngles(&sp28, &sp34, arg0->unk_24, arg0->unk_28, arg0->unk_2A);
    BattleHud_DrawExpandingCaptionBoxBlack(arg0, arg1, arg2, sp34);

    if (arg0->unk_24 == arg0->unk_20) {
        return 1;
    }
    return 0;
}

void BattleHud_DrawTextBox(s32 arg0, s16 arg1, s16 arg2, char* arg3) {
    Battle_DrawGradientRectWrapper(arg1 + 1, arg2 + 1, 0xC8, 0x24, &D_84385860[arg0], &D_84385870[arg0]);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(2, 0);
    Font_SetLineHeight(0x10);
    Font_Printf(arg1 + 0xA, arg2 + 5, arg3);
    Font_EndTexturedTextRendering();
    BattleHud_DrawBoxBorder(arg1, arg2, 0xC8, 0x25);
    BattleHud_DrawTranslucentShadowRect(arg1 - 2, arg2 - 1, 0xCD, 0x28, 0);
}

void BattleHud_DrawTwoOptionCursorMenu(ActivePokemon* arg0, s16 arg1, s16 arg2, s32 arg3) {
    UNUSED s32 pad;
    s32 sp48;
    UNUSED s32 pad2[2];

    Battle_DrawGradientRectWrapper(arg1 + 1, arg2 + 1, 0xC8, 0x24, &D_84385860[arg3], &D_84385870[arg3]);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(2, 0);
    sp48 = Font_MeasureTextExtent(2, 0, Text_GetString(NULL, 0, sBattleMessagesTable, 0xA1)) / 2;
    Font_Printf((arg1 - sp48) + 0x61, arg2 + 5, Text_GetString(NULL, 0, sBattleMessagesTable, 0xA1));
    Font_Printf(arg1 + 0x32, arg2 + 0x14, Text_GetString(NULL, 0, sBattleMessagesTable, 0xA3));
    Font_Printf(arg1 + 0x7A, arg2 + 0x14, Text_GetString(NULL, 0, sBattleMessagesTable, 0xA2));
    Font_EndTexturedTextRendering();

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    Gfx_DrawTextureRgba16Ia8(arg1 + (arg0->state.unk_2F * 0x49) + 0x1B, arg2 + 0x14, 0x18, 0xE, &D_30092C0, &D_3009560, 0x18,
                  0x100000);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    BattleHud_DrawBoxBorder(arg1, arg2, 0xC8, 0x25);
    BattleHud_DrawTranslucentShadowRect(arg1 - 2, arg2 - 1, 0xCD, 0x28, 0);
}

void BattleScene_DrawStripWipeIfActive(void) {
    if (BattleScene_GetStripWipeState() != 0) {
        BattleScene_DrawStripWipe();
    }
}

void Battle_DrawScrollingTextureRect(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
    unk_D_800A7440 sp30;

    GfxRect_SetBounds(&sp30, arg0, arg1, (arg0 + arg2) - 1, (arg1 + arg3) - 1);

    if (GfxRect_ClipToScissor(&sp30) != 0) {
        if (arg6 != 0) {
            arg4 += ((sp30.x1 - arg0) * arg6) >> 5;
        }

        if (arg7 != 0) {
            arg5 += ((sp30.y2 - arg1) * arg7) >> 5;
        }

        sp30.y1 += 1;
        sp30.x2 += 1;

        gSPTextureRectangle(gDisplayListHead++, sp30.x1 << 2, sp30.y2 << 2, sp30.y1 << 2, sp30.x2 << 2, G_TX_RENDERTILE,
                            arg4, arg5, arg6, arg7);
    }
}

void Battle_DrawTiledStripSegment(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4, s32 arg5) {
    gDPLoadTextureTile(gDisplayListHead++, arg4, G_IM_FMT_RGBA, G_IM_SIZ_32b, arg2, 0, 0, 0, arg2 - 1, arg3 - 1, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    Battle_DrawScrollingTextureRect(arg0, arg1, arg2, arg3, 0, 0, 0x400, 0);
}

void Battle_DrawSpectatorModeBackgroundPanel(void) {
    s32 i;

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    for (i = 0; i < 0x30; i++) {
        Battle_DrawTiledStripSegment(0x1E, i + 0x17, 0x58, 1, &D_3001F70[i * 0x160], 0x58);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    BattleHud_DrawTranslucentShadowRect(0x1C, 0x16, 0x5E, 0x34, 0);
}

void Battle_DrawGradientTextureRect(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9,
                   u8 argA, u8 argB, u8 argC) {
    UNUSED s32 pad;
    DepthBuffer* temp_s1 = GfxImage_GetCurrent();
    Vtx* temp_s2 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    Mtx* spC0 = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    Vp* spBC = Gfx_AllocDisplayList(sizeof(Vp));

    Gfx_SetViewportDimensions(spBC, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)spBC & 0x1FFFFFFF);

    guOrtho(spC0, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    Gfx_SetVertexAttributes(&temp_s2[0], arg1, arg2, -1, argC << 5, 0, 0xFF, 0xF0, 0, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[1], arg1 + arg3, arg2, -1, argB << 5, 0, 0xFF, 0xF0, 0, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[2], arg1, arg2 + arg4, -1, argC << 5, arg6 << 5, 0xFF, 0, 0x64, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[3], arg1 + arg3, arg2 + arg4, -1, argB << 5, arg6 << 5, 0xFF, 0, 0x64, 0xFF);

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL0, COMBINED, 0,
                      SHADE, 0, 0, 0, 0, COMBINED);
    gDPSetRenderMode(gDisplayListHead++, G_RM_PASS, G_RM_XLU_SURF2);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, 255);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    gDPLoadTextureTile(gDisplayListHead++, arg0, G_IM_FMT_IA, G_IM_SIZ_8b, arg5, 0, arg7, arg8, arg9 - 1, argA - 1, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)spC0 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&gIdentityMtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}

void Battle_DrawSpectatorModeIndicator(void) {
    D_84390190.x = Math_StepToF(D_84390190.x, 52.0f, 80.0f, 80.0f);
    Battle_DrawGradientTextureRect(D_3000470, D_84390190.x, D_84390190.y, 0x6C, 0x20, 0xD8, 0x20, 0, 0, 0x6C, 0x20, 0x6B, 0);
    Battle_DrawGradientTextureRect(D_3000470, (s32)D_84390190.x + 0x6C, D_84390190.y, 0x6C, 0x20, 0xD8, 0x20, 0x6C, 0, 0xD8, 0x20, 0xD7,
                  0x6C);
}

void Battle_DrawSpectatorModeScrollingText(void) {
    static s32 D_84385988 = 0;

    s32 sp24;
    s16 temp_s0;

    if (!(Cont_GetControllerBits() & 1)) {
        sp24 = Font_MeasureTextExtent(4, 0, Text_GetString(NULL, 0, sBattleControllerDisconnectedMessage, 0));
        temp_s0 = 0x50 - D_84385988;

        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 16, 0, 304, 240);

        Font_BeginTranslucentTextRendering();
        Font_SetActive(4, 0);
        Font_Printf(temp_s0, 0xB3, Text_GetString(NULL, 0, sBattleControllerDisconnectedMessage, 0));

        temp_s0 += sp24 + 0x1E;
        if (temp_s0 < 0x140) {
            Font_Printf(temp_s0, 0xB3, Text_GetString(NULL, 0, sBattleControllerDisconnectedMessage, 0));
        }
        Font_EndTexturedTextRendering();

        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 320, 240);

        D_84385988++;
        if (D_84385988 >= (sp24 + 0x50)) {
            D_84385988 = 0x32;
        }
    }
}

void BattleHud_DrawOwnSideStatus(ActivePokemon* arg0, ActivePokemonState* arg1) {
    TeamRoster* sp34 = arg0->sessionTeams->teamMember[arg0->presentationState.unk_16C];
    UNUSED s32 pad;
    s32 var_v1;

    if (gSessionContext.mode != 0x10) {
        if (arg1->unk_10 == 3) {
            BattleHud_DrawMonStatusBoxPlayer(arg0, arg0->presentationState.unk_168->unk_1C - 2, arg0->presentationState.unk_168->unk_1E - 0x3A, arg1->unk_1E,
                          1);
        } else {
            BattleHud_DrawMonStatusBoxPlayer(arg0, arg0->presentationState.unk_168->unk_1C - 2, arg0->presentationState.unk_168->unk_1E - 0x3A, arg1->unk_1E,
                          0);
        }

        if ((arg1->unk_10 != 3) && (arg0->presentationState.unk_168->unk_1C == 0x17)) {
            switch (arg1->unk_10) {
                case 2:
                    if (arg1->unk_1C == 1) {
                        if (arg0->sessionTeams->unk_01 == 2) {
                            if (arg0->sessionTeams->teamMember[1]->unk_001 < arg0->sessionTeams->teamMember[0]->unk_001) {
                                var_v1 = 0;
                            } else {
                                var_v1 = 1;
                            }
                            BattleHud_DrawTeamStatusList(arg0, arg0->sessionTeams->teamMember[var_v1], 0x60, 0xF,
                                          arg0->sessionTeams->teamMember[var_v1]->unk_001);
                            BattleHud_DrawTeamStatusList(arg0, arg0->sessionTeams->teamMember[var_v1 == 0], 0xC6, 0xF,
                                          arg0->sessionTeams->teamMember[var_v1 == 0]->unk_001);
                        } else if (arg0->teamRoster->numberOfPokemonBrought < 4) {
                            BattleHud_DrawTeamStatusList(arg0, arg0->sessionTeams->teamMember[0], 0x60, 0xF, sp34->unk_001);
                        } else {
                            BattleHud_DrawDoublesTeamStatusList(arg0, 0x60, 0xF, sp34->unk_001);
                        }
                    } else if (arg1->unk_2D == 0x10) {
                        BattleHud_DrawOneOptionLabelBar(arg0, 0x60, 0xF, sp34->unk_001);
                    } else {
                        BattleHud_DrawTwoOptionLabelBar(arg0, 0x60, 0xF, sp34->unk_001);
                    }
                    break;

                case 1:
                    if (arg1->unk_1C == 1) {
                        BattleHud_DrawMoveSelectMenu(arg0, 0x60, 0xF, sp34->unk_001);
                    } else {
                        BattleHud_DrawTwoOptionLabelBar(arg0, 0x60, 0xF, sp34->unk_001);
                    }
                    break;

                case 4:
                    BattleHud_DrawTwoOptionCursorMenu(arg0, 0x5F, 0xE, sp34->unk_001);
                    break;

                default:
                    BattleHud_DrawThreeOptionLabelBar(arg0, 0x60, 0xF, sp34->unk_001);
                    break;
            }
        }
    }
}

void BattleHud_DrawOpponentSideStatus(ActivePokemon* arg0, ActivePokemonState* arg1) {
    TeamRoster* sp24 = arg0->sessionTeams->teamMember[arg0->presentationState.unk_16C];
    s32 sp20;

    if (gSessionContext.mode != 0x10) {
        if (arg1->unk_10 == 3) {
            BattleHud_DrawMonStatusBoxOpponent(arg0, arg0->presentationState.unk_168->unk_1C - 0x20, arg0->presentationState.unk_168->unk_1E - 2, arg1->unk_1E,
                          1);
        } else {
            BattleHud_DrawMonStatusBoxOpponent(arg0, arg0->presentationState.unk_168->unk_1C - 0x20, arg0->presentationState.unk_168->unk_1E - 2, arg1->unk_1E,
                          0);
        }

        if ((arg1->unk_10 != 3) && (arg0->presentationState.unk_168->unk_1C == 0x103)) {
            switch (arg1->unk_10) {
                case 2:
                    if (arg1->unk_1C == 1) {
                        if (arg0->sessionTeams->unk_01 == 2) {
                            if (arg0->sessionTeams->teamMember[1]->unk_001 < arg0->sessionTeams->teamMember[0]->unk_001) {
                                sp20 = 0;
                            } else {
                                sp20 = 1;
                            }
                            BattleHud_DrawTeamStatusList(arg0, arg0->sessionTeams->teamMember[sp20 == 0], 0x16, 0x79,
                                          arg0->sessionTeams->teamMember[sp20 == 0]->unk_001);
                            BattleHud_DrawTeamStatusList(arg0, arg0->sessionTeams->teamMember[sp20], 0x7C, 0x79,
                                          arg0->sessionTeams->teamMember[sp20]->unk_001);
                        } else if (arg0->teamRoster->numberOfPokemonBrought < 4) {
                            BattleHud_DrawTeamStatusList(arg0, arg0->sessionTeams->teamMember[0], 0x7C, 0x79, sp24->unk_001);
                        } else {
                            BattleHud_DrawDoublesTeamStatusList(arg0, 0x18, 0x79, sp24->unk_001);
                        }
                    } else if (arg1->unk_2D == 0x10) {
                        BattleHud_DrawOneOptionLabelBar(arg0, 0x98, 0xCE, sp24->unk_001);
                    } else {
                        BattleHud_DrawTwoOptionLabelBar(arg0, 0x62, 0xCE, sp24->unk_001);
                    }
                    break;

                case 1:
                    if (arg1->unk_1C == 1) {
                        BattleHud_DrawMoveSelectMenu(arg0, 0x19, 0xA6, sp24->unk_001);
                    } else {
                        BattleHud_DrawTwoOptionLabelBar(arg0, 0x62, 0xCE, sp24->unk_001);
                    }
                    break;

                case 4:
                    BattleHud_DrawTwoOptionCursorMenu(arg0, 0x17, 0xBB, sp24->unk_001);
                    break;

                default:
                    BattleHud_DrawThreeOptionLabelBar(arg0, 0x18, 0xCE, sp24->unk_001);
                    break;
            }
        }
    }
}
