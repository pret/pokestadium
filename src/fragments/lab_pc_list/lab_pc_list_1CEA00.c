#include "lab_pc_list.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/gb_data.h"
#include "src/pokemon_stats.h"
#include "src/save_data.h"
#include "src/game_state.h"
#include "src/table_view.h"
#include "src/text_system.h"
#include "src/status_icons.h"
#include "src/gb_save.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "src/fragments/pokemon_lab_support/pokemon_lab_support.h"

char** D_8831A4C0;
char** D_8831A4C4;
char** D_8831A4C8;
char** D_8831A4CC;
char** D_8831A4D0;
char** D_8831A4D4;
char** D_8831A4D8;
s32 pad_D_8831A4DC[8];

static Color_RGBA8 D_883171D0[] = {
    { 0x31, 0x48, 0x6B, 0xFF },
    { 0x47, 0x5E, 0x80, 0xFF },
    { 0x2B, 0x40, 0x5F, 0xFF },
    { 0x31, 0x48, 0x6B, 0xFF },
};

void LabPCList_InitHeaderSelectIcon(WidgetNode* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(WidgetNode));
    arg0->unk_18 = LabPCList_HeaderSelectIcon_Draw;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x26; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 LabPCList_HeaderSelectIcon_Draw(WidgetNode* arg0, s32 arg1, s32 arg2) {
    u32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);

    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    gDPLoadTextureBlock(gDisplayListHead++, D_883176D8, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 18, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gDisplayListHead++, (arg1 + 4) << 2, (arg2 + 1) << 2, (arg1 + 0x22) << 2, (arg2 + 0x13) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);

    return 0;
}

void LabPCList_DrawHeaderPokemon(WidgetNode* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(WidgetNode));
    arg0->unk_18 = LabPCList_HeaderPokemon_Draw;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x5C; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 LabPCList_HeaderPokemon_Draw(WidgetNode* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171E0 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_883171E0.r, D_883171E0.g, D_883171E0.b, D_883171E0.a);
    Font_SetActive(4, 0);

    sp1C = Text_GetString(NULL, 0, D_8831A4C4, 3);
    Font_Printf(((arg0->unk_14.unk_00 - Font_MeasureTextExtent(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    Font_EndTexturedTextRendering();

    return 0;
}

void LabPCList_DrawHeaderNickname(WidgetNode* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(WidgetNode));
    arg0->unk_18 = LabPCList_HeaderNickname_Draw;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x5C; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 LabPCList_HeaderNickname_Draw(WidgetNode* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171E4 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_883171E4.r, D_883171E4.g, D_883171E4.b, D_883171E4.a);
    Font_SetActive(4, 0);

    sp1C = Text_GetString(NULL, 0, D_8831A4C4, 4);
    Font_Printf(((arg0->unk_14.unk_00 - Font_MeasureTextExtent(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    Font_EndTexturedTextRendering();
    return 0;
}

void LabPCList_DrawHeaderID(WidgetNode* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(WidgetNode));
    arg0->unk_18 = LabPCList_HeaderID_Draw;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x34; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 LabPCList_HeaderID_Draw(WidgetNode* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171E8 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_883171E8.r, D_883171E8.g, D_883171E8.b, D_883171E8.a);
    Font_SetActive(4, 0);

    sp1C = Text_GetString(NULL, 0, D_8831A4C4, 5);
    Font_Printf(((arg0->unk_14.unk_00 - Font_MeasureTextExtent(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    Font_EndTexturedTextRendering();
    return 0;
}

void LabPCList_DrawHeaderOT(WidgetNode* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(WidgetNode));
    arg0->unk_18 = LabPCList_HeaderOT_Draw;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x4C; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 LabPCList_HeaderOT_Draw(WidgetNode* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171EC = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_883171EC.r, D_883171EC.g, D_883171EC.b, D_883171EC.a);
    Font_SetActive(4, 0);

    sp1C = Text_GetString(NULL, 0, D_8831A4C4, 6);
    Font_Printf(((arg0->unk_14.unk_00 - Font_MeasureTextExtent(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    Font_EndTexturedTextRendering();
    return 0;
}

void LabPCList_DrawHeaderArea(WidgetNode* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(WidgetNode));
    arg0->unk_18 = LabPCList_HeaderArea_Draw;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x38; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 LabPCList_HeaderArea_Draw(WidgetNode* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171F0 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_883171F0.r, D_883171F0.g, D_883171F0.b, D_883171F0.a);
    Font_SetActive(4, 0);

    sp1C = Text_GetString(NULL, 0, D_8831A4C4, 7);
    Font_Printf(((arg0->unk_14.unk_00 - Font_MeasureTextExtent(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    Font_EndTexturedTextRendering();
    return 0;
}

void LabPCList_DrawHeaderTypes(WidgetNode* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(WidgetNode));
    arg0->unk_18 = LabPCList_HeaderTypes_Draw;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x90; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 LabPCList_HeaderTypes_Draw(WidgetNode* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171F4 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp54;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    {
        // clang-format off
        s32 temp_t3 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
        // clang-format on
        gDPSetFillColor(gDisplayListHead++, (temp_t3 << 0x10) | temp_t3);
        gDPFillRectangle(gDisplayListHead++, arg1, arg2, arg1 + 0x47, (arg2 + arg0->unk_14.unk_02) - 1);
    }

    {
        // clang-format off
        s32 sp34 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g * 8) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
        // clang-format on
        gDPSetFillColor(gDisplayListHead++, (sp34 << 0x10) | sp34);
        gDPFillRectangle(gDisplayListHead++, arg1 + 0x48, arg2, (arg1 + (u32)arg0->unk_14.unk_00) - 1,
                         (arg2 + arg0->unk_14.unk_02) - 1);
    }

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_883171F4.r, D_883171F4.g, D_883171F4.b, D_883171F4.a);
    Font_SetActive(4, 0);

    sp54 = Text_GetString(NULL, 0, D_8831A4C4, 8);
    Font_Printf(((0x48 - Font_MeasureTextExtent(0, 0, sp54)) / 2) + arg1, arg2 + 2, sp54);

    sp54 = Text_GetString(NULL, 0, D_8831A4C4, 9);
    Font_Printf(((0x48 - Font_MeasureTextExtent(0, 0, sp54)) / 2) + arg1 + 0x48, arg2 + 2, sp54);

    Font_EndTexturedTextRendering();
    return 0;
}

void LabPCList_DrawHeaderMoves(WidgetNode* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(WidgetNode));
    arg0->unk_18 = LabPCList_HeaderMoves_Draw;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x1A4; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 LabPCList_HeaderMoves_Draw(WidgetNode* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171F8 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* temp_v0_16;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    {
        // clang-format off
        s32 temp_t3 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
        // clang-format on

        gDPSetFillColor(gDisplayListHead++, (temp_t3 << 0x10) | temp_t3);
        gDPFillRectangle(gDisplayListHead++, arg1, arg2, arg1 + 0x68, (arg2 + arg0->unk_14.unk_02) - 1);
    }

    {
        // clang-format off
        s32 sp5C = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
        // clang-format on

        gDPSetFillColor(gDisplayListHead++, (sp5C << 0x10) | sp5C);
        gDPFillRectangle(gDisplayListHead++, arg1 + 0x69, arg2, arg1 + 0xD1, (arg2 + arg0->unk_14.unk_02) - 1);
    }

    {
        // clang-format off
        s32 temp_a2 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
        // clang-format on

        gDPSetFillColor(gDisplayListHead++, (temp_a2 << 0x10) | temp_a2);
        gDPFillRectangle(gDisplayListHead++, arg1 + 0xD2, arg2, arg1 + 0x13A, (arg2 + arg0->unk_14.unk_02) - 1);
    }

    {
        // clang-format off
        s32 temp_a0 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
        // clang-format on

        gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
        gDPFillRectangle(gDisplayListHead++, arg1 + 0x13B, arg2, arg1 + 0x1A3, (arg2 + arg0->unk_14.unk_02) - 1);
    }

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_883171F8.r, D_883171F8.g, D_883171F8.b, D_883171F8.a);
    Font_SetActive(4, 0);

    temp_v0_16 = Text_GetString(NULL, 0, D_8831A4C4, 0xA);
    Font_Printf(((0x69 - Font_MeasureTextExtent(0, 0, temp_v0_16)) / 2) + arg1, arg2 + 2, temp_v0_16);

    temp_v0_16 = Text_GetString(NULL, 0, D_8831A4C4, 0xB);
    Font_Printf(((0x69 - Font_MeasureTextExtent(0, 0, temp_v0_16)) / 2) + arg1 + 0x69, arg2 + 2, temp_v0_16);

    temp_v0_16 = Text_GetString(NULL, 0, D_8831A4C4, 0xC);
    Font_Printf(((0x69 - Font_MeasureTextExtent(0, 0, temp_v0_16)) / 2) + arg1 + 0xD2, arg2 + 2, temp_v0_16);

    temp_v0_16 = Text_GetString(NULL, 0, D_8831A4C4, 0xD);
    Font_Printf(((0x69 - Font_MeasureTextExtent(0, 0, temp_v0_16)) / 2) + arg1 + 0x13B, arg2 + 2, temp_v0_16);

    Font_EndTexturedTextRendering();
    return 0;
}

void LabPCList_DrawHeaderLevel(WidgetNode* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(WidgetNode));
    arg0->unk_18 = LabPCList_HeaderLevel_Draw;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x46; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 LabPCList_HeaderLevel_Draw(WidgetNode* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171FC = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_883171FC.r, D_883171FC.g, D_883171FC.b, D_883171FC.a);
    Font_SetActive(4, 0);

    sp1C = Text_GetString(NULL, 0, D_8831A4C4, 0xE);
    Font_Printf(((arg0->unk_14.unk_00 - Font_MeasureTextExtent(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);

    Font_EndTexturedTextRendering();
    return 0;
}

void LabPCList_DrawHeaderHp(WidgetNode* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(WidgetNode));
    arg0->unk_18 = LabPCList_HeaderHp_Draw;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x46; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 LabPCList_HeaderHp_Draw(WidgetNode* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88317200 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_88317200.r, D_88317200.g, D_88317200.b, D_88317200.a);
    Font_SetActive(4, 0);

    sp1C = Text_GetString(NULL, 0, D_8831A4C4, 0xF);
    Font_Printf(((arg0->unk_14.unk_00 - Font_MeasureTextExtent(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);

    Font_EndTexturedTextRendering();
    return 0;
}

void LabPCList_DrawHeaderAttack(WidgetNode* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(WidgetNode));
    arg0->unk_18 = LabPCList_HeaderAttack_Draw;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x46; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 LabPCList_HeaderAttack_Draw(WidgetNode* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88317204 = { 0xF0, 0xF0, 0xF0, 0xFF };

    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_88317204.r, D_88317204.g, D_88317204.b, D_88317204.a);
    Font_SetActive(4, 0);
    Font_Printf(arg1 + 4, arg2 + 2, Text_GetString(NULL, 0, D_8831A4C4, 0x10));
    Font_EndTexturedTextRendering();
    return 0;
}

void LabPCList_DrawHeaderDefense(WidgetNode* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(WidgetNode));
    arg0->unk_18 = LabPCList_HeaderDefense_Draw;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x46; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 LabPCList_HeaderDefense_Draw(WidgetNode* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88317208 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_88317208.r, D_88317208.g, D_88317208.b, D_88317208.a);
    Font_SetActive(4, 0);
    sp1C = Text_GetString(NULL, 0, D_8831A4C4, 0x11);
    Font_Printf(((arg0->unk_14.unk_00 - Font_MeasureTextExtent(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    Font_EndTexturedTextRendering();
    return 0;
}

void LabPCList_DrawHeaderSpeed(WidgetNode* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(WidgetNode));
    arg0->unk_18 = LabPCList_HeaderSpeed_Draw;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x46; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 LabPCList_HeaderSpeed_Draw(WidgetNode* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_8831720C = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_8831720C.r, D_8831720C.g, D_8831720C.b, D_8831720C.a);
    Font_SetActive(4, 0);
    sp1C = Text_GetString(NULL, 0, D_8831A4C4, 0x12);
    Font_Printf(((arg0->unk_14.unk_00 - Font_MeasureTextExtent(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    Font_EndTexturedTextRendering();
    return 0;
}

void LabPCList_DrawHeaderSpecial(WidgetNode* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(WidgetNode));
    arg0->unk_18 = LabPCList_HeaderSpecial_Draw;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x46; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 LabPCList_HeaderSpecial_Draw(WidgetNode* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88317210 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_88317210.r, D_88317210.g, D_88317210.b, D_88317210.a);
    Font_SetActive(4, 0);
    sp1C = Text_GetString(NULL, 0, D_8831A4C4, 0x13);
    Font_Printf(((arg0->unk_14.unk_00 - Font_MeasureTextExtent(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    Font_EndTexturedTextRendering();
    return 0;
}

void LabPCList_InitColumnDivider(unk_func_8830867C_02C_050* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   unk_func_8830867C_02C* arg5) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8830867C_02C_050));
    arg0->unk_00.unk_18 = LabPCList_DrawColumnDivider;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_00.unk_14.unk_00 = arg3;
    arg0->unk_00.unk_14.unk_02 = arg4;
    arg0->unk_2C = arg5;
}

s32 LabPCList_DrawColumnDivider(unk_func_8830867C_02C_050* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88317214 = { 0xFF, 0xFF, 0xFF, 0xFF };

    UNUSED s32 pad;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    {
        s32 temp_t7 = ((D_88317214.r << 8) & 0xF800) | ((D_88317214.g << 3) & 0x7C0) | ((D_88317214.b >> 2) & 0x3E) | 1;
        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (temp_t7 << 0x10) | temp_t7);
        gDPFillRectangle(gDisplayListHead++, arg1, arg2 + 0x14, (arg0->unk_00.unk_14.unk_00 + arg1) - 1, arg2 + 0x15);
    }

    {
        s32 temp_t7 = ((D_88317214.r << 8) & 0xF800) | ((D_88317214.g << 3) & 0x7C0) | ((D_88317214.b >> 2) & 0x3E) | 1;
        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (temp_t7 << 0x10) | temp_t7);
        gDPFillRectangle(gDisplayListHead++, arg1 + 0x82, arg2, arg1 + 0x83, arg2 + 0x12D);
    }

    return 0;
}

void LabPCList_InitCornerIcon(WidgetNode* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(WidgetNode));
    arg0->unk_18 = LabPCList_DrawCornerIcon;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
}

s32 LabPCList_DrawCornerIcon(WidgetNode* arg0, s32 arg1, s32 arg2) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    gDPLoadTextureBlock(gDisplayListHead++, D_883198A0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 40, 28, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, (arg1 + 0x100) << 2, (arg2 + 2) << 2, (arg1 + 0x127) << 2,
                        (arg2 + 0x1D) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    gDPPipeSync(gDisplayListHead++);

    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);
    return 0;
}

void LabPCList_LoadDecks(unk_func_8830867C_02C* arg0, MemoryPool* arg1) {
    s32 i;

    LabPCList_InitDeckCategories(arg0->unk_154, arg1);

    for (i = 0; i < 3; i++) {
        if (arg0->unk_154[i].unk_04 != 0) {
            LabPCList_ReadDeckCategory(&arg0->unk_154[i]);
        }
    }
}

void LabPCList_SaveDirtyDecks(unk_func_8830867C_02C* arg0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if ((arg0->unk_154[i].unk_04 != 0) && (arg0->unk_154[i].unk_08 != 0)) {
            LabPCList_WriteDeckCategory(&arg0->unk_154[i]);
        }
    }
}

void LabPCList_InitDeckSlots(unk_func_8830867C_02C* arg0, MemoryPool* arg1) {
    UNUSED s32 pad;

    arg0->unk_0E4[0].unk_00 = 0x20;
    arg0->unk_0E4[0].unk_04 = GbSave_GetActivePort();
    arg0->unk_0E4[0].unk_08 = 0;
    arg0->unk_0E4[0].unk_1C = 6;
    ByteMatrix_Allocate(&arg0->unk_0E4[0].unk_0C, 0x1C, 1, arg1);
    LabPCList_AllocateBoxSlots(&arg0->unk_0E4[0], 6, 1, arg1);

    arg0->unk_0E4[1].unk_00 = 0x21;
    arg0->unk_0E4[1].unk_04 = arg0->unk_0E4[0].unk_04;
    arg0->unk_0E4[1].unk_08 = 1;
    arg0->unk_0E4[1].unk_1C = 0x14;
    ByteMatrix_Allocate(&arg0->unk_0E4[1].unk_0C, 0x1C, 0xC, arg1);
    LabPCList_AllocateBoxSlots(&arg0->unk_0E4[1], 0x14, 0, arg1);

    arg0->unk_0E4[2].unk_00 = 0x11;
    arg0->unk_0E4[2].unk_04 = 0;
    arg0->unk_0E4[2].unk_08 = 2;
    arg0->unk_0E4[2].unk_1C = 0x14;
    ByteMatrix_Allocate(&arg0->unk_0E4[2].unk_0C, 0x1C, 0xC, arg1);
    LabPCList_AllocateBoxSlots(&arg0->unk_0E4[2], 0x14, 0, arg1);

    TableView_Initialize(&arg0->unk_144, arg0->unk_0E4, 0x20, 3, 3);
}

void LabPCList_InitPageHeader(unk_func_88302D98* arg0, s32 arg1, s32 arg2, unk_func_8830867C_02C* arg3) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_88302D98));
    arg0->unk_00.unk_18 = LabPCList_DrawPageHeader;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_2C = arg3;
}

s32 LabPCList_DrawPageHeader(unk_func_88302D98* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88317218 = { 0xF0, 0xF0, 0xF0, 0xFF };

    UNUSED s32 pad[4];
    char spF0[0x10];
    char* spEC;
    s32 spE8;
    s32 spE4;

    Text_SetNumberToken(1, arg0->unk_2C->unk_CD0 + 1);
    Text_GetString(spF0, 0x20, D_8831A4C4, 2);
    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_88317218.r, D_88317218.g, D_88317218.b, D_88317218.a);
    Font_SetActive(8, 0);
    spEC = Text_GetString(NULL, 0, D_8831A4C4, 1);
    spE8 = Font_MeasureTextExtent(0, 0, spEC);
    Font_Printf(arg1 + 0x22, arg2 + 5, spEC);
    spE4 = 0x206 - Font_MeasureTextExtent(0, 0, spF0);
    Font_Printf(arg1 + spE4, arg2 + 5, spF0);
    Font_EndTexturedTextRendering();

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    gDPLoadTextureBlock(gDisplayListHead++, D_88317920, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 24, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, (arg1 + 4) << 2, (arg2 + 3) << 2, (arg1 + 0x1D) << 2, (arg2 + 0x1A) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    gDPLoadTextureBlock(gDisplayListHead++, D_88317F28, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 24, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, ((arg1 + spE8) + 0x26) << 2, (arg2 + 3) << 2, ((arg1 + spE8) + 0x3F) << 2,
                        (arg2 + 0x1A) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    gDPLoadTextureBlock(gDisplayListHead++, D_4005570, G_IM_FMT_RGBA, G_IM_SIZ_16b, 28, 26, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, ((arg1 + spE4) - 0x1E) << 2, (arg2 + 2) << 2, ((arg1 + spE4) - 5) << 2,
                        (arg2 + 0x1B) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    gDPLoadTextureBlock(gDisplayListHead++, D_4004A00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 28, 26, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, (arg1 + 0x20A) << 2, (arg2 + 2) << 2, (arg1 + 0x223) << 2,
                        (arg2 + 0x1B) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    gDPPipeSync(gDisplayListHead++);

    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);

    return 0;
}

void LabPCList_SwitchColumnPage(unk_func_8830867C_02C* arg0) {
    s32 sp1C;
    unk_func_8830867C_02C_04C* ptr = arg0->unk_04C;

    sp1C = ptr->unk_24;

    switch (arg0->unk_038->unk_2C) {
        case 0:
            ptr = arg0->unk_04C;
            ptr->unk_18->unk_08 = arg0->unk_058;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_0C = arg0->unk_05C;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_10 = arg0->unk_060;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_14 = arg0->unk_064;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_18 = arg0->unk_068;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_1C = 0;

            if (sp1C >= 7) {
                sp1C = 6;
            }
            break;

        case 1:
            ptr = arg0->unk_04C;
            ptr->unk_18->unk_08 = arg0->unk_06C;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_0C = 0;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_10 = 0;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_14 = 0;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_18 = 0;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_1C = 0;

            if (sp1C >= 3) {
                sp1C = 2;
            }
            break;

        case 2:
            ptr = arg0->unk_04C;
            ptr->unk_18->unk_08 = arg0->unk_070;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_0C = arg0->unk_074;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_10 = arg0->unk_078;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_14 = arg0->unk_07C;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_18 = arg0->unk_080;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_1C = arg0->unk_084;
            break;
    }

    ((func8850CB48)Memmap_GetFragmentVaddr(WidgetTree_SetGridMenuSelection))(arg0->unk_04C, sp1C);
}

void LabPCList_BuildListScreen(unk_func_8830867C_02C* arg0, s32 arg1, s32 arg2, WidgetNode* arg3,
                   unk_func_8830867C_030* arg4, unk_func_8830867C_034* arg5, unk_func_8830867C_038* arg6,
                   unk_func_8830867C_03C* arg7, unk_func_8830867C_040* arg8, unk_func_8830867C_044* arg9,
                   unk_func_8830867C_048* argA, unk_func_8830867C_04C* argB, unk_func_889000C4* argC,
                   FragmentEntry argD, unk_func_8830867C_054* argE, MemoryPool* argF, FontContext* arg10) {
    static s32 D_8831721C[] = {
        0x0000005C,
        0x00000034,
        0x0000004C,
    };
    static s32 D_88317228[] = { 0x38, 0x48, 0x48 };
    static s32 D_88317234[] = { 0x69, 0x69, 0x69, 0x69 };
    static s32 D_88317244[] = { 0x46, 0x46, 0x46, 0x46, 0x46, 0x46 };
    static s32 D_8831725C[] = {
        0x00000000,
        0x00000006,
        0x0000000A,
        0x00000010,
    };
    static Color_RGBA8 D_8831726C = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88317270 = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317274 = { 0xFF, 0xFF, 0x00, 0xFF };

    UNUSED s32 pad[2];
    WidgetGridMenu* tmp;
    unk_func_88302D98* sp70;
    WidgetNode* sp6C;
    WidgetNode* sp68;
    WidgetNode* sp64;
    WidgetAnimatedFrame* sp60;
    unk_func_8850BD40* sp5C;
    unk_func_88507D4C* sp58;
    unk_func_88507D4C* sp54;
    unk_func_88503298* sp50;

    LabPCList_InitDeckSlots(arg0, argF);
    PointerList_Allocate(&arg0->unk_03C, 0x1E6, argF);
    PointerList_Allocate(&arg0->unk_0CC, 0x1E6, argF);
    LabPCList_LoadAllBoxes(&arg0->unk_144);

    arg0->unk_0DC = D_8831721C;

    LabPCList_FlattenEntries(&arg0->unk_03C, &arg0->unk_144);
    LabPCList_LoadDecks(arg0, argF);

    PointerList_Allocate(&arg0->unk_C48, 0xAA, argF);
    LabPCList_BuildTmHmList(&arg0->unk_C48, arg0->unk_1A8, arg0->unk_154, 3, 0xAA);

    arg0->unk_08C = arg4;
    arg0->unk_094 = arg5;
    arg0->unk_098 = arg6;
    arg0->unk_09C = arg7;
    arg0->unk_0A0 = arg8;
    arg0->unk_0A4 = arg9;
    arg0->unk_0A8 = argA;
    arg0->unk_0AC = argB;
    arg0->unk_0B0 = argC;
    arg0->unk_CC4 = 0;
    arg0->unk_CC8 = 0;
    arg0->unk_0D8 = 0;
    arg0->unk_CD0 = 0;
    arg0->unk_CD4 = D_8831725C;
    arg0->unk_0E0 = 0;
    arg0->unk_CD8 = argD;
    arg0->unk_CDC = argE;

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8830867C_02C));

    arg0->unk_000.unk_20 = LabPCList_RowMenuHandleInput;
    arg0->unk_000.unk_24 = LabPCList_SetRowMenuState;
    arg0->unk_000.unk_10.unk_00 = arg1;
    arg0->unk_000.unk_10.unk_02 = arg2;

    arg0->unk_048 = mem_pool_alloc(argF, sizeof(unk_func_8830867C_02C_048));
    LabPCList_InitColumnSelectionProxy(arg0->unk_048, arg0);

    arg0->unk_04C = mem_pool_alloc(argF, sizeof(WidgetGridMenu));
    ((func8850C284)Memmap_GetFragmentVaddr(WidgetTree_InitGridMenu))(arg0->unk_04C, 1, 8, argF);
    arg0->unk_04C->unk_28 |= 0x200;
    arg0->unk_04C->unk_38 = -4;
    arg0->unk_04C->unk_3A = -4;
    arg0->unk_04C->unk_3C = 8;
    arg0->unk_04C->unk_3E = 8;

    arg0->unk_02C = mem_pool_alloc(argF, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_02C, 0, 0, 0x228, 0x172);
    arg0->unk_02C->unk_00.unk_28 |= 0x200;
    arg0->unk_02C->unk_00.unk_28 |= 0x400;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_02C);

    arg0->unk_030 = mem_pool_alloc(argF, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(WidgetTree_InitDashedBorderFrame))(arg0->unk_030, 0, 0, 0x228, 0x20, D_8831726C, D_88317270);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_02C, arg0->unk_030);

    sp70 = mem_pool_alloc(argF, sizeof(unk_func_88302D98));
    LabPCList_InitPageHeader(sp70, 0, 1, arg0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_030, sp70);

    arg0->unk_088 = mem_pool_alloc(argF, sizeof(WidgetNode));
    LabPCList_InitCornerIcon(arg0->unk_088, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_030, arg0->unk_088);

    arg0->unk_050 = mem_pool_alloc(argF, sizeof(unk_func_8830867C_02C_050));
    LabPCList_InitColumnDivider(arg0->unk_050, 0, 0x34, 0x228, 0x12E, arg0);

    sp6C = mem_pool_alloc(argF, sizeof(WidgetNode));
    LabPCList_InitHeaderSelectIcon(sp6C, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_050, sp6C);
    tmp = arg0->unk_04C;
    tmp->unk_18[0] = sp6C;

    arg0->unk_054 = mem_pool_alloc(argF, sizeof(WidgetNode));
    LabPCList_DrawHeaderPokemon(arg0->unk_054, 0x26, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_050, arg0->unk_054);
    tmp = arg0->unk_04C;
    tmp->unk_18[1] = arg0->unk_054;

    arg0->unk_038 = mem_pool_alloc(argF, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(WidgetTree_InitPagedContainer))(arg0->unk_038, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_050, arg0->unk_038);

    sp68 = mem_pool_alloc(argF, sizeof(WidgetNode));
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(sp68, 0x2C);
    sp68->unk_10.unk_00 = 0;
    sp68->unk_10.unk_02 = 0;
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_038, sp68);

    arg0->unk_058 = mem_pool_alloc(argF, sizeof(WidgetNode));
    LabPCList_DrawHeaderNickname(arg0->unk_058, 0x84, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp68, arg0->unk_058);

    arg0->unk_05C = mem_pool_alloc(argF, sizeof(WidgetNode));
    LabPCList_DrawHeaderID(arg0->unk_05C, 0xE0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp68, arg0->unk_05C);

    arg0->unk_060 = mem_pool_alloc(argF, sizeof(WidgetNode));
    LabPCList_DrawHeaderOT(arg0->unk_060, 0x114, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp68, arg0->unk_060);

    arg0->unk_064 = mem_pool_alloc(argF, sizeof(WidgetNode));
    LabPCList_DrawHeaderArea(arg0->unk_064, 0x160, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp68, arg0->unk_064);

    arg0->unk_068 = mem_pool_alloc(argF, sizeof(WidgetNode));
    LabPCList_DrawHeaderTypes(arg0->unk_068, 0x198, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp68, arg0->unk_068);

    arg0->unk_06C = mem_pool_alloc(argF, sizeof(WidgetNode));
    LabPCList_DrawHeaderMoves(arg0->unk_06C, 0x84, 0);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_038, arg0->unk_06C);

    sp64 = mem_pool_alloc(argF, sizeof(WidgetNode));
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(sp64, 0x2C);
    sp64->unk_10.unk_00 = 0;
    sp64->unk_10.unk_02 = 0;
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_038, sp64);

    arg0->unk_070 = mem_pool_alloc(argF, sizeof(WidgetNode));
    LabPCList_DrawHeaderLevel(arg0->unk_070, 0x84, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, arg0->unk_070);

    arg0->unk_074 = mem_pool_alloc(argF, sizeof(WidgetNode));
    LabPCList_DrawHeaderHp(arg0->unk_074, 0xCA, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, arg0->unk_074);

    arg0->unk_078 = mem_pool_alloc(argF, sizeof(WidgetNode));
    LabPCList_DrawHeaderAttack(arg0->unk_078, 0x110, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, arg0->unk_078);

    arg0->unk_07C = mem_pool_alloc(argF, sizeof(WidgetNode));
    LabPCList_DrawHeaderDefense(arg0->unk_07C, 0x156, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, arg0->unk_07C);

    arg0->unk_080 = mem_pool_alloc(argF, sizeof(WidgetNode));
    LabPCList_DrawHeaderSpeed(arg0->unk_080, 0x19C, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, arg0->unk_080);

    arg0->unk_084 = mem_pool_alloc(argF, sizeof(WidgetNode));
    LabPCList_DrawHeaderSpecial(arg0->unk_084, 0x1E2, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, arg0->unk_084);

    sp60 = mem_pool_alloc(argF, sizeof(WidgetAnimatedFrame));
    ((func88504570)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedFrameVariantC))(sp60, 0, 0, 0x10, 0x10, D_88317274);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_050, sp60);
    arg0->unk_04C->unk_1C = sp60;
    ((func8850CB48)Memmap_GetFragmentVaddr(WidgetTree_SetGridMenuSelection))(arg0->unk_04C, 1);
    LabPCList_SwitchColumnPage(arg0);

    arg0->unk_034 = mem_pool_alloc(argF, sizeof(unk_func_8830867C_02C_034));
    ((func88506DCC)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGrid))(arg0->unk_034, 0, 0x4A, func_88304850, 0x228, 0x14, 0xE,
                                                           argF);
    ((func88506F1C)Memmap_GetFragmentVaddr(WidgetTree_BindScrollableGridPage))(arg0->unk_034, &arg0->unk_03C, argF);
    arg0->unk_034->unk_70 = arg0;
    arg0->unk_034->unk_00.unk_50 = 0x22;
    arg0->unk_034->unk_00.unk_52 = -4;
    arg0->unk_034->unk_00.unk_44->unk_00.unk_14.unk_00 = 0x64;
    arg0->unk_034->unk_00.unk_44->unk_00.unk_14.unk_02 = 0x1C;

    sp5C = mem_pool_alloc(argF, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(sp5C, arg0->unk_034);
    ((func8850CC74)Memmap_GetFragmentVaddr(WidgetTree_AppendChildSelectionProxyItem))(arg0->unk_048, sp5C);
    ((func8850CC74)Memmap_GetFragmentVaddr(WidgetTree_AppendChildSelectionProxyItem))(arg0->unk_048, arg0->unk_04C);

    sp54 = mem_pool_alloc(argF, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(sp54, 0, 0x24, 0x228, 0, arg0->unk_034);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_02C, sp54);

    sp58 = mem_pool_alloc(argF, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(sp58, 0, arg0->unk_02C->unk_00.unk_14.unk_02 - 0x10, 0x228,
                                                           1, arg0->unk_034);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_02C, sp58);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_02C, arg0->unk_050);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_02C, arg0->unk_034);

    sp50 = mem_pool_alloc(argF, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGateBridge))(sp50, arg0->unk_02C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, sp50);

    arg0->unk_0B4 = mem_pool_alloc(argF, sizeof(unk_func_8830867C_02C_0B4));
    BattleInfoWidget_BuildSaveConfirmDialog(arg0->unk_0B4, 0x65, 0x228, argF);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_0B4);

    BattleInfoWidget_BindMoveDestinationData(arg0->unk_0A8, &arg0->unk_144);

    arg0->unk_08C->unk_4C = 0x228;
    arg0->unk_08C->unk_50 = 0x13E;

    arg0->unk_090 = mem_pool_alloc(argF, sizeof(unk_func_88509F48));
    ((func88509F48)Memmap_GetFragmentVaddr(WidgetTree_InitMessagePanel))(arg0->unk_090, 0, 0, 0x228, 0x1A0, argF, arg10);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_090);

    arg0->unk_CCC = mem_pool_alloc(argF, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_CCC, 0, 0,
                                                           mem_pool_alloc(argF, sizeof(char) * 0x140), 0x10);
    arg0->unk_CCC->unk_3C = 0x20;

    arg0->unk_0B8 = mem_pool_alloc(argF, sizeof(unk_func_8850CD44));
    ((func8850CD44)Memmap_GetFragmentVaddr(WidgetTree_InitChildWidgetGroup))(arg0->unk_0B8, 4, argF);

    arg0->unk_0BC = mem_pool_alloc(argF, sizeof(unk_func_882173EC));
    LabPCList_InitTextFadeWidget(arg0->unk_0BC, 0, 0, D_88317234[0], 0x14);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_034, arg0->unk_0BC);
    arg0->unk_0B8->unk_1C[0] = arg0->unk_0BC;

    arg0->unk_0C0 = mem_pool_alloc(argF, sizeof(unk_func_8830867C_02C_0C0));
    LabPCList_InitPpUpAnimWidget(arg0->unk_0C0, 0, 0, D_88317234[0], 0x14);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_034, arg0->unk_0C0);
    arg0->unk_0B8->unk_1C[1] = &arg0->unk_0C0->unk_00;

    arg0->unk_0C4 = mem_pool_alloc(argF, sizeof(unk_func_882173EC));
    LabPCList_InitVitaminAnimWidget(arg0->unk_0C4, 0, 0, D_88317244[0], 0x14);

    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_034, arg0->unk_0C4);
    arg0->unk_0B8->unk_1C[2] = arg0->unk_0C4;

    arg0->unk_0C8 = mem_pool_alloc(argF, sizeof(unk_func_882173EC));
    LabPCList_InitLocationCrossfadeWidget(arg0->unk_0C8, 0, 0, D_88317228[0], 0x14);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_034, arg0->unk_0C8);
    arg0->unk_0B8->unk_1C[3] = arg0->unk_0C8;
    arg0->unk_CB8 = 0;

    LabPCList_ResetFilterState(arg0);
    LabPCList_DiscardFilterBackup(arg0);
    LabPCList_ApplyFiltersAndSort(arg0);
}

void LabPCList_DrawTypeName(s32 arg0, s32 arg1, s32 arg2, u8* arg3, s32 arg4) {
    Color_RGBA8 sp2C;
    s32 sp28;
    UNUSED s32 pad;
    char* sp20;

    if ((*arg3 <= 0) || (*arg3 >= 0x98)) {
        if (arg4 != 1) {
            sp2C = ((func884000C4)Memmap_GetFragmentVaddr(LabPC_GetTypeColor))(0)->unk_04;
            sp20 = "????";
        } else {
            return;
        }
    } else {
        sp28 = Species_GetMoveSlot(arg3, arg4);
        if (sp28 != -1) {
            sp2C = ((func884000C4)Memmap_GetFragmentVaddr(LabPC_GetTypeColor))(sp28)->unk_04;
            sp20 = Text_GetString(NULL, 0, D_8831A4D4, PokemonType_ToDisplayIndex(sp28));
        } else {
            return;
        }
    }

    Font_BeginTranslucentTextRendering();
    Font_SetActive(4, 0);
    Gfx_SetEnvColor(sp2C.r, sp2C.g, sp2C.b, sp2C.a);
    Font_Printf(((arg2 - Font_MeasureTextExtent(0, 0, sp20)) / 2) + arg0, arg1, sp20);
    Font_EndTexturedTextRendering();
}

void LabPCList_DrawMoveNameCell(s32 arg0, s32 arg1, s32 arg2, u8* arg3, s32 arg4) {
    static Color_RGBA8 D_88317278 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp2C;
    Color_RGBA8 sp28;
    ret_func_8002ED08* sp24;
    u8* sp18 = &arg3[arg4];

    if (arg4 < BattleMon_CountMoves(arg3)) {
        sp24 = Move_GetDisplayInfo(sp18[9]);
        if (sp24 == NULL) {
            sp28 = D_88317278;
            sp2C = " ????? ";
        } else {
            sp28 = ((func884000C4)Memmap_GetFragmentVaddr(LabPC_GetTypeColor))(sp24->unk_00[1])->unk_04;
            sp2C = Text_GetString(NULL, 0, D_8831A4CC, sp18[9] - 1);
        }
        Font_BeginTranslucentTextRendering();
        Font_SetActive(4, 0);
        Gfx_SetEnvColor(sp28.r, sp28.g, sp28.b, sp28.a);
        Font_Printf(((arg2 - Font_MeasureTextExtent(0, 0, sp2C)) / 2) + arg0, arg1, sp2C);
        Font_EndTexturedTextRendering();
    }
}

Color_RGBA8 D_8831727C = { 0xF0, 0x96, 0x96, 0xFF };
Color_RGBA8 D_88317280 = { 0xF0, 0xD2, 0x8C, 0xFF };
Color_RGBA8 D_88317284 = { 0x96, 0xDC, 0xB4, 0xFF };

void LabPCList_DrawAreaCell(s32 arg0, s32 arg1, s32 arg2, unk_func_88304850_arg2* arg3) {
    LabPCList_DrawLocationCaption(arg0, arg1, arg2, 0x14, *(s32*)arg3->unk_00[0], arg3->unk_00[1], 0xFF);
}

void LabPCList_DrawPlainText(s32 arg0, s32 arg1, s8* arg2, s32 arg3) {
    static Color_RGBA8 D_88317288 = { 0xF0, 0xF0, 0xF0, 0xFF };

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_88317288.r, D_88317288.g, D_88317288.b, D_88317288.a);
    Font_SetActive(4, 0);
    Font_Printf(arg0, arg1, arg2, arg3);
    Font_EndTexturedTextRendering();
}

void LabPCList_DrawFormattedNumber(s32 arg0, s32 arg1, char* arg2, s32 arg3) {
    static Color_RGBA8 D_8831728C = { 0xF0, 0xF0, 0xF0, 0xFF };
    char sp1C[12];

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_8831728C.r, D_8831728C.g, D_8831728C.b, D_8831728C.a);
    Font_SetActive(4, 0);

    sprintf(&sp1C, arg2, arg3);

    Font_Printf(arg0 - Font_MeasureTextExtent(0, 0, sp1C), arg1, sp1C);
    Font_EndTexturedTextRendering();
}

void LabPCList_DrawStatNumber(s32 arg0, s32 arg1, char* arg2, s32 arg3, u8* arg4) {
    static Color_RGBA8 D_88317290 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static char D_88317294[] = "?";

    if ((*arg4 <= 0) || (*arg4 >= 0x98)) {
        Font_BeginTranslucentTextRendering();
        Gfx_SetEnvColor(D_88317290.r, D_88317290.g, D_88317290.b, D_88317290.a);
        Font_SetActive(4, 0);
        Font_Printf(arg0 - Font_MeasureTextExtent(0, 0, D_88317294), arg1, D_88317294);
        Font_EndTexturedTextRendering();
    } else {
        LabPCList_DrawFormattedNumber(arg0, arg1, arg2, arg3);
    }
}

typedef struct unk_D_88317298 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} unk_D_88317298; // size = 0x8

s32 LabPCList_CheckStatFilterRange(unk_func_8830867C_02C* arg0, unk_func_88304850_arg2* arg1) {
    static unk_D_88317298 D_88317298[] = {
        { 0x19, 0x1E }, { 0xF, 0x14 }, { 0x32, 0x37 }, { 0x1, 0x1E }, { 0x1, 0x32 },
    };

    unk_D_88317298* ptr;
    s32 sp18 = 0;

    if (LabPCList_HasFilterFlag(arg0, 0x20) != 0) {
        ptr = &D_88317298[arg0->unk_C54.unk_2C];
        if (arg1->unk_2C < ptr->unk_00) {
            sp18 = 1;
        } else if (ptr->unk_04 < arg1->unk_2C) {
            sp18 = 2;
        }
    }
    return sp18;
}

#ifdef NON_MATCHING
void func_88304850(s32 arg0, s32 arg1, unk_func_88304850_arg2* arg2, s32 arg3, s32 arg4,
                   unk_func_8830867C_02C_034* arg5) {
    static Color_RGBA8 D_883172C0[] = {
        { 0xF0, 0xF0, 0xF0, 0xFF },
        { 0xB2, 0xFF, 0xC3, 0xFF },
        { 0xFF, 0xB2, 0xC3, 0xFF },
    };
    static Color_RGBA8 D_883172CC[][2] = {
        {
            { 0x50, 0x51, 0x54, 0xFF },
            { 0x59, 0x5B, 0x5E, 0xFF },
        },
        {
            { 0x43, 0x44, 0x46, 0xFF },
            { 0x4B, 0x4C, 0x4F, 0xFF },
        },
    };

    Color_RGBA8 spBC;
    s32 spA8;
    s32 sp58;
    s32 var_s3;
    s32 var_s1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a3;
    s32 temp_s7;
    s32 var_s6;
    s32 var_s7;
    unk_func_8830867C_02C* temp_s5;
    temp_s5 = arg5->unk_70;

    var_s1 = (temp_s5->unk_0AC->unk_2C->unk_30 & 2)
                 ? temp_s5->unk_0AC->unk_00.unk_10.unk_00 - temp_s5->unk_000.unk_10.unk_00
                 : arg5->unk_00.unk_00.unk_14.unk_00;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    temp_s7 = arg3 & 1;
    // clang-format off
    temp_a3 = ((((Color_RGBA8(*)[2])D_883171D0)[temp_s7][0].r << 8) & 0xF800) | ((((Color_RGBA8(*)[2])D_883171D0)[temp_s7][0].g << 3) & 0x7C0) | ((((Color_RGBA8(*)[2])D_883171D0)[temp_s7][0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    var_s7 = var_s1 + arg0;
    gDPSetFillColor(gDisplayListHead++, (temp_a3 << 0x10) | temp_a3);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, arg0 + 0x25, arg1 + 0x13);

    // clang-format off
    temp_a0 = ((((Color_RGBA8(*)[2])D_883171D0)[temp_s7][1].r << 8) & 0xF800) | ((((Color_RGBA8(*)[2])D_883171D0)[temp_s7][1].g << 3) & 0x7C0) | ((((Color_RGBA8(*)[2])D_883171D0)[temp_s7][1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0 + 0x26, arg1, arg0 + 0x81, arg1 + 0x13);

    var_s6 = temp_s5->unk_CD4[temp_s5->unk_CD0];

    for (var_s3 = arg0 + 0x84; var_s3 < var_s7; var_s3 += ((s32*)temp_s5->unk_0DC)[var_s6], var_s6++) {
        temp_a0_2 = ((D_883172CC[temp_s7][var_s6 & 1].r << 8) & 0xF800) |
                    ((D_883172CC[temp_s7][var_s6 & 1].g << 3) & 0x7C0) |
                    ((D_883172CC[temp_s7][var_s6 & 1].b >> 2) & 0x3E) | 1;
        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (temp_a0_2 << 0x10) | temp_a0_2);
        gDPFillRectangle(gDisplayListHead++, var_s3, arg1,
                         (((s32*)temp_s5->unk_0DC)[var_s6] + var_s3) - 1, arg1 + 0x13);
    }

    if (arg2 != NULL) {
        Gfx_DrawNumberDigits(arg0 + 6, arg1 + 4, arg3 + 1, 3);
        spBC = D_883172C0[LabPCList_CheckStatFilterRange(temp_s5, arg2)];
        if (arg4 & 4) {
            spBC.a = 0x4D;
        } else {
            spBC.a = 0xFF;
        }
        Font_BeginTranslucentTextRendering();
        Gfx_SetEnvColor(spBC.r, spBC.g, spBC.b, spBC.a);
        Font_SetActive(4, 0);
        spA8 = (0x5C - Font_MeasureTextExtent(0, 0, "WWWWWWWWWW")) / 2;

        if ((arg2->unk_08 <= 0) || (arg2->unk_08 >= 0x98)) {
            Font_Printf(arg0 + spA8 + 0x26, arg1 + 2, "?????");
        } else {
            Font_Printf(arg0 + spA8 + 0x26, arg1 + 2, Text_GetString(NULL, 0, D_8831A4D0, arg2->unk_08 - 1));
        }

        Font_EndTexturedTextRendering();

        var_s6 = temp_s5->unk_CD4[temp_s5->unk_CD0];

        for (var_s3 = arg0 + 0x84; var_s3 < var_s7; var_s3 += ((s32*)temp_s5->unk_0DC)[var_s6], var_s6++) {
            switch (var_s6) {
                case 0:
                    LabPCList_DrawPlainText(var_s3 + spA8, arg1 + 2, arg2->unk_40, 0);
                    break;

                case 1:
                    Gfx_DrawNumberDigits(var_s3 + 4, arg1 + 4, arg2->unk_16, 5);
                    break;

                case 2:
                    LabPCList_DrawPlainText(var_s3 + ((((s32*)temp_s5->unk_0DC)[var_s6] - Font_MeasureTextExtent(0, 0, "WWWWWWW")) / 2), arg1 + 2,
                                  arg2->unk_43, 0);
                    break;

                case 3:
                    LabPCList_DrawAreaCell(var_s3, arg1, ((s32*)temp_s5->unk_0DC)[var_s6], arg2);
                    break;

                case 4:
                case 5:
                    LabPCList_DrawTypeName(var_s3, arg1 + 2, ((s32*)temp_s5->unk_0DC)[var_s6], &arg2->unk_08, var_s6 - 4);
                    break;

                case 6:
                case 7:
                case 8:
                case 9:
                    LabPCList_DrawMoveNameCell(var_s3, arg1 + 2, ((s32*)temp_s5->unk_0DC)[var_s6], &arg2->unk_08, var_s6 - 6);
                    break;

                case 10:
                    LabPCList_DrawStatNumber(var_s3 + (((s32*)temp_s5->unk_0DC)[var_s6] -
                                          ((((s32*)temp_s5->unk_0DC)[var_s6] - Font_MeasureTextExtent(0, 0, "000")) / 2)),
                                  arg1 + 2, "%3d", arg2->unk_2C, &arg2->unk_08);
                    break;

                case 11:
                    LabPCList_DrawStatNumber(var_s3 + (((s32*)temp_s5->unk_0DC)[var_s6] -
                                          ((((s32*)temp_s5->unk_0DC)[var_s6] - Font_MeasureTextExtent(0, 0, "000")) / 2)),
                                  arg1 + 2, "%3d", arg2->unk_2E, &arg2->unk_08);
                    break;

                case 12:
                    LabPCList_DrawStatNumber(var_s3 + (((s32*)temp_s5->unk_0DC)[var_s6] -
                                          ((((s32*)temp_s5->unk_0DC)[var_s6] - Font_MeasureTextExtent(0, 0, "000")) / 2)),
                                  arg1 + 2, "%3d", arg2->unk_30, &arg2->unk_08);
                    break;

                case 13:
                    LabPCList_DrawStatNumber(var_s3 + (((s32*)temp_s5->unk_0DC)[var_s6] -
                                          ((((s32*)temp_s5->unk_0DC)[var_s6] - Font_MeasureTextExtent(0, 0, "000")) / 2)),
                                  arg1 + 2, "%3d", arg2->unk_32, &arg2->unk_08);
                    break;

                case 14:
                    LabPCList_DrawStatNumber(var_s3 + (((s32*)temp_s5->unk_0DC)[var_s6] -
                                          ((((s32*)temp_s5->unk_0DC)[var_s6] - Font_MeasureTextExtent(0, 0, "000")) / 2)),
                                  arg1 + 2, "%3d", arg2->unk_34, &arg2->unk_08);
                    break;

                case 15:
                    LabPCList_DrawStatNumber(var_s3 + (((s32*)temp_s5->unk_0DC)[var_s6] -
                                          ((((s32*)temp_s5->unk_0DC)[var_s6] - Font_MeasureTextExtent(0, 0, "000")) / 2)),
                                  arg1 + 2, "%3d", arg2->unk_36, &arg2->unk_08);
                    break;
            }
        }
    }
}
#else
static Color_RGBA8 D_883172C0[] = {
    { 0xF0, 0xF0, 0xF0, 0xFF },
    { 0xB2, 0xFF, 0xC3, 0xFF },
    { 0xFF, 0xB2, 0xC3, 0xFF },
};
static Color_RGBA8 D_883172CC[][2] = {
    {
        { 0x50, 0x51, 0x54, 0xFF },
        { 0x59, 0x5B, 0x5E, 0xFF },
    },
    {
        { 0x43, 0x44, 0x46, 0xFF },
        { 0x4B, 0x4C, 0x4F, 0xFF },
    },
};
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/lab_pc_list/lab_pc_list_1CEA00/func_88304850.s")
#endif

void LabPCList_SaveFilterState(unk_func_8830867C_02C* arg0) {
    arg0->unk_C84 = arg0->unk_C54;

    arg0->unk_CBC = arg0->unk_034->unk_00.unk_38;
    arg0->unk_CC0 = arg0->unk_034->unk_00.unk_38 - (arg0->unk_034->unk_58 / arg0->unk_034->unk_00.unk_3E);
    arg0->unk_CB4 = 1;
    arg0->unk_CB8 = 1;

    arg0->unk_088->unk_28 |= 1;
}

void LabPCList_RestoreFilterState(unk_func_8830867C_02C* arg0) {
    arg0->unk_C54 = arg0->unk_C84;

    arg0->unk_CB4 = 0;
    arg0->unk_088->unk_28 &= ~1;
}

void LabPCList_DiscardFilterBackup(unk_func_8830867C_02C* arg0) {
    arg0->unk_C84 = arg0->unk_C54;
    arg0->unk_CB4 = 0;
    arg0->unk_088->unk_28 &= ~1;
}

void LabPCList_ResetFilterState(unk_func_8830867C_02C* arg0) {
    arg0->unk_C54.unk_04 = NULL;
    arg0->unk_C54.unk_00 = 0;
    // clang-format off
    arg0->unk_C54.unk_08 = 1; arg0->unk_C54.unk_09 = 0x64;
    // clang-format on
    arg0->unk_C54.unk_0C = 0;
    arg0->unk_C54.unk_1C.unk_00 = 0;
    arg0->unk_C54.unk_24.unk_04 = 0;
}

s32 LabPCList_HasFilterFlag(unk_func_8830867C_02C* arg0, s32 arg1) {
    return (arg0->unk_C54.unk_04 & arg1) != 0;
}

void LabPCList_SetFilterFlag(unk_func_8830867C_02C* arg0, s32 arg1) {
    arg0->unk_C54.unk_04 |= arg1;
}

void LabPCList_ClearFilterFlag(unk_func_8830867C_02C* arg0, s32 arg1) {
    arg0->unk_C54.unk_04 &= ~arg1;
}

s32 LabPCList_ToggleFilterFlag(unk_func_8830867C_02C* arg0, s32 arg1) {
    arg0->unk_C54.unk_04 ^= arg1;
    return arg0->unk_C54.unk_04 & arg1;
}

void LabPCList_SetSortMode(unk_func_8830867C_02C* arg0, s32 arg1) {
    arg0->unk_C54.unk_00 = arg1;
}

void LabPCList_ApplyFiltersAndSort(unk_func_8830867C_02C* arg0) {
    ((func88506EE4)Memmap_GetFragmentVaddr(WidgetTree_BindScrollableGridData))(arg0->unk_034, &arg0->unk_03C);

    if (arg0->unk_C54.unk_04 != 0) {
        if (arg0->unk_C54.unk_04 & 1) {
            PointerList_Filter(arg0->unk_034->unk_00.unk_2C, &arg0->unk_0CC, LabPCList_FilterByLevelRange, &arg0->unk_C54.unk_08);
            ((func88506EE4)Memmap_GetFragmentVaddr(WidgetTree_BindScrollableGridData))(arg0->unk_034, &arg0->unk_0CC);
        }

        if (arg0->unk_C54.unk_04 & 2) {
            PointerList_Filter(arg0->unk_034->unk_00.unk_2C, &arg0->unk_0CC, LabPCList_FilterByAnyType, &arg0->unk_C54.unk_1C);
            ((func88506EE4)Memmap_GetFragmentVaddr(WidgetTree_BindScrollableGridData))(arg0->unk_034, &arg0->unk_0CC);
        }

        if (arg0->unk_C54.unk_04 & 4) {
            PointerList_Filter(arg0->unk_034->unk_00.unk_2C, &arg0->unk_0CC, LabPCList_FilterByAnyMove, &arg0->unk_C54.unk_24);
            ((func88506EE4)Memmap_GetFragmentVaddr(WidgetTree_BindScrollableGridData))(arg0->unk_034, &arg0->unk_0CC);
        }

        if (arg0->unk_C54.unk_04 & 8) {
            PointerList_Filter(arg0->unk_034->unk_00.unk_2C, &arg0->unk_0CC, LabPCList_FilterBySpeciesId, &arg0->unk_C54.unk_10);
            ((func88506EE4)Memmap_GetFragmentVaddr(WidgetTree_BindScrollableGridData))(arg0->unk_034, &arg0->unk_0CC);
        }

        if (arg0->unk_C54.unk_04 & 0x10) {
            PointerList_Filter(arg0->unk_034->unk_00.unk_2C, &arg0->unk_0CC, LabPCList_FilterByExactTypePair, &arg0->unk_C54.unk_14);
            ((func88506EE4)Memmap_GetFragmentVaddr(WidgetTree_BindScrollableGridData))(arg0->unk_034, &arg0->unk_0CC);
        }

        if (arg0->unk_C54.unk_04 & 0x20) {
            PointerList_Filter(arg0->unk_034->unk_00.unk_2C, &arg0->unk_0CC, LabPCList_FilterByCategoryBit, &arg0->unk_C54.unk_2C);
            ((func88506EE4)Memmap_GetFragmentVaddr(WidgetTree_BindScrollableGridData))(arg0->unk_034, &arg0->unk_0CC);
        }
    }

    PointerList_Sort(arg0->unk_034->unk_00.unk_2C, D_8831A1F8[arg0->unk_C54.unk_00]);
}

s32 LabPCList_CheckAnyDirty(unk_func_8830867C_02C* arg0) {
    s32 var_a0 = LabPCList_CheckDirtyBoxes(&arg0->unk_144);
    s32 i;

    for (i = 0; i < 3; i++) {
        if ((arg0->unk_154[i].unk_04 != 0) && (arg0->unk_154[i].unk_08 != 0)) {
            if (i == 0) {
                var_a0 |= 2;
            } else if (i == 1) {
                var_a0 |= 8;
            } else {
                var_a0 |= 0x20;
            }
        }
    }

    return var_a0;
}

s32 LabPCList_FindEntryIndex(unk_func_8830867C_02C_0CC* arg0, unk_func_8830867C_02C_0CC_000* arg1) {
    unk_func_8830867C_02C_0CC_000** ptr = arg0->unk_00;
    s32 i;

    for (i = 0; i < arg0->unk_08; i++) {
        if (arg1 == ptr[i]) {
            return i;
        }
    }

    return -1;
}

void LabPCList_PerformMoveMon(unk_func_8830867C_02C* arg0, unk_func_8830867C_02C_0CC_000* arg1, Controller* arg2) {
    func88500A6C temp_v0_4;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    WidgetPoint sp78;
    unk_func_8830867C_02C_0CC_000* sp74;
    s32 sp70;
    char sp50[0x20];
    char sp30[0x20];
    unk_func_88500994* tmp;

    sp84 = 0;
    sp80 = (arg1->unk_00->unk_00->unk_08 << 0x10) | arg1->unk_00->unk_04;
    sp88 = arg0->unk_0A8->unk_34->unk_38;

    if (sp88 != 0) {
        sp84 = arg0->unk_0A8->unk_38[arg0->unk_0A8->unk_4C->unk_1C]->unk_38;
    }

    sp90 = arg0->unk_034->unk_00.unk_38;
    sp8C = arg0->unk_034->unk_00.unk_38 - (arg0->unk_034->unk_58 / arg0->unk_034->unk_00.unk_3E);
    sp74 = arg0->unk_034->unk_00.unk_2C->unk_00[sp90];

    LabPCList_MoveEntryToBox(arg0, sp74, sp88, sp84);
    sp7C = (arg1->unk_00->unk_00->unk_08 << 0x10) | arg1->unk_00->unk_04;

    temp_v0_4 = ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage));
    tmp = arg0->unk_038;
    arg0->unk_CD0 = 0;
    temp_v0_4(tmp, 0);

    LabPCList_SwitchColumnPage(arg0);

    sp78.unk_00 = arg0->unk_0DC->unk_08 + (s32)arg0->unk_0DC->unk_00 + arg0->unk_0DC->unk_04 + 0x84;
    sp78.unk_02 = arg0->unk_034->unk_5C - arg0->unk_034->unk_58;

    LabPCList_LocationCrossfadeWidget_Start(arg0->unk_0C8, sp80, sp7C, sp78);
    Audio_PlaySoundEffectById(0x0120000D);

    ((func8850CF00)Memmap_GetFragmentVaddr(WidgetTree_RunChildWidgetGroup))(arg0->unk_0B8, arg2);

    Audio_PlaySoundEffectById(0x29);
    LabPCList_FlattenEntries(&arg0->unk_03C, &arg0->unk_144);
    LabPCList_ApplyFiltersAndSort(arg0);
    LabPCList_DiscardFilterBackup(arg0);

    sp70 = LabPCList_FindEntryIndex(arg0->unk_034->unk_00.unk_2C, sp74);
    if (sp70 == -1) {
        ((func88507C0C)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelectionWithOffset))(arg0->unk_034, sp90, sp8C);
        Text_SetStringToken(0x1A, arg1->unk_38);
        BattleInfoWidget_FormatLocationName(sp50, sp80 >> 0x10, sp80 & 0xFFFF);
        Text_SetStringToken(0x25, sp50);
        BattleInfoWidget_FormatLocationName(sp30, sp88, sp84);
        Text_SetStringToken(0x28, sp30);
        Text_GetString(arg0->unk_CCC->unk_40, 0x140, D_8831A4C4, 0x5C);
        ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(arg0->unk_090, arg0->unk_CCC, 0, 0);
        ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_090, arg2);
    } else {
        ((func88507C0C)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelectionWithOffset))(arg0->unk_034, sp70, sp8C);
    }
}

void LabPCList_ReindexBoxSlots(unk_func_8830867C_02C_0CC_000_000* arg0) {
    unk_func_8830867C_02C_0CC_000_000_010_000* ptr = arg0->unk_10.unk_00;
    s32 i;

    for (i = 0; i < arg0->unk_10.unk_08; i++, ptr++) {
        ptr->unk_00->unk_04 = i;
    }
}

void LabPCList_MoveEntryToBox(unk_func_8830867C_02C* arg0, unk_func_8830867C_02C_0CC_000* arg1, s32 arg2, s32 arg3) {
    unk_func_8830867C_02C_144_000* ptr = arg0->unk_144.unk_00;
    unk_func_8830867C_02C_0CC_000_000* temp_s0 = &ptr[arg2].unk_0C[arg3];
    unk_func_8830867C_02C_0CC_000_000* sp24 = arg1->unk_00;

    PointerList_Remove(&sp24->unk_10, arg1->unk_04);
    LabPCList_ReindexBoxSlots(sp24);

    arg1->unk_00 = &temp_s0->unk_00;
    arg1->unk_04 = temp_s0->unk_10.unk_08;

    PointerList_Insert(&temp_s0->unk_10, arg1, temp_s0->unk_10.unk_08);

    sp24->unk_0C = 1;
    temp_s0->unk_0C = 1;
}

s32 LabPCList_ApplyVitaminItem(unk_func_8830867C_02C_0CC_000* arg0, unk_func_8830867C_04C_030_02C_000* arg1, u32** arg2,
                  u32** arg3) {
    unk_func_8830867C_02C_0CC_000_008* temp_s0 = &arg0->unk_08;
    u16 sp3A;
    s32 sp34;

    switch (arg1->unk_00[0]->unk_00) {
        case 35:
            sp34 = 1;

            *arg2 = temp_s0->unk_26;
            temp_s0->unk_14 += 0xA00;
            if (temp_s0->unk_14 >= 0x6401) {
                temp_s0->unk_14 = 0x6400;
            }
            temp_s0->unk_26 = CalculateStatValue(STAT_HP, temp_s0->unk_00, temp_s0->unk_14, temp_s0->unk_24, temp_s0->unk_1E);
            *arg3 = temp_s0->unk_26;
            break;

        case 36:
            sp34 = 2;
            *arg2 = temp_s0->unk_28;
            temp_s0->unk_16 += 0xA00;
            if (temp_s0->unk_16 >= 0x6401) {
                temp_s0->unk_16 = 0x6400;
            }
            temp_s0->unk_28 = CalculateStatValue(STAT_SPECIAL, temp_s0->unk_00, temp_s0->unk_16, temp_s0->unk_24, temp_s0->unk_1E);
            *arg3 = temp_s0->unk_28;
            break;

        case 37:
            sp34 = 3;
            *arg2 = temp_s0->unk_2A;
            temp_s0->unk_18 += 0xA00;
            if (temp_s0->unk_18 >= 0x6401) {
                temp_s0->unk_18 = 0x6400;
            }
            temp_s0->unk_2A = CalculateStatValue(STAT_SPEED, temp_s0->unk_00, temp_s0->unk_18, temp_s0->unk_24, temp_s0->unk_1E);
            *arg3 = temp_s0->unk_2A;
            break;

        case 38:
            sp34 = 4;
            *arg2 = temp_s0->unk_2C;
            temp_s0->unk_1A += 0xA00;
            if (temp_s0->unk_1A >= 0x6401) {
                temp_s0->unk_1A = 0x6400;
            }
            temp_s0->unk_2C = CalculateStatValue(STAT_DEFENSE, temp_s0->unk_00, temp_s0->unk_1A, temp_s0->unk_24, temp_s0->unk_1E);
            *arg3 = temp_s0->unk_2C;
            break;

        case 39:
            sp34 = 5;
            *arg2 = temp_s0->unk_2E;
            temp_s0->unk_1C += 0xA00;
            if (temp_s0->unk_1C >= 0x6401) {
                temp_s0->unk_1C = 0x6400;
            }
            temp_s0->unk_2E = CalculateStatValue(STAT_ATTACK, temp_s0->unk_00, temp_s0->unk_1C, temp_s0->unk_24, temp_s0->unk_1E);
            *arg3 = temp_s0->unk_2E;
            break;

        case 40:
            sp34 = 0;
            *arg2 = temp_s0->unk_24;
            sp3A = temp_s0->unk_26;
            *(s32*)&temp_s0->unk_10 = Pokemon_ExpForLevel(temp_s0->unk_00, (temp_s0->unk_24 + 1) & 0xFFFF);
            Pokemon_RecalcStats(&arg0->unk_08);
            temp_s0->unk_02 = (temp_s0->unk_02 + temp_s0->unk_26) - sp3A;
            *arg3 = temp_s0->unk_24;
            break;
    }

    LabPCList_ConsumeUsedTmItem(arg1);
    arg0->unk_00->unk_0C = 1;
    return sp34;
}

void LabPCList_ApplyPpUpItem(unk_func_8830867C_02C_0CC_000* arg0, unk_func_8830867C_04C_030_02C_000* arg1, s32 arg2, s32* arg3,
                   s32* arg4) {
    s32 var_v1;
    MoveData* temp_v0;
    unk_func_8830867C_02C_0CC_000_008* ptr = &arg0->unk_08;

    temp_v0 = Move_GetData(ptr->unk_09[arg2]);

    var_v1 = temp_v0->unk_05 / 5;
    if (var_v1 >= 7) {
        var_v1 = 7;
    }

    *arg3 = ((ptr->unk_20[arg2] >> 6) * var_v1) + temp_v0->unk_05;
    *arg4 = *arg3 + var_v1;

    ptr->unk_20[arg2] += var_v1 + 0x40;

    LabPCList_ConsumeUsedTmItem(arg1);

    arg0->unk_00->unk_0C = 1;
}

void LabPCList_ClearMovesFrom(unk_func_8830867C_02C_0CC_000_008* arg0, s32 arg1) {
    s32 i;

    for (i = arg1; i < 4; i++) {
        arg0->unk_09[i] = 0;
    }
}

void LabPCList_TeachTmMove(unk_func_8830867C_02C_0CC_000* arg0, unk_func_8830867C_04C_030_02C_000* arg1, s32 arg2) {
    unk_func_8830867C_02C_0CC_000_008* ptr = &arg0->unk_08;
    s32 var_a0;

    if (arg1->unk_00[0]->unk_00 >= 0xC9) {
        var_a0 = arg1->unk_00[0]->unk_00 - 0xC9;
    } else {
        var_a0 = arg1->unk_00[0]->unk_00 - 0x92;
    }

    ptr->unk_09[arg2] = Move_GetIdFromTableIndex(var_a0);
    ptr->unk_20[arg2] = Move_GetData(ptr->unk_09[arg2])->unk_05;

    if (arg1->unk_00[0]->unk_00 >= 0xC9) {
        LabPCList_ConsumeUsedTmItem(arg1);
    }
    arg0->unk_00->unk_0C = 1;
}

void LabPCList_SetRowMenuState(unk_func_8830867C_02C* arg0, s32 arg1) {
    arg0->unk_000.unk_2A = arg1;
    arg0->unk_048->unk_00.unk_14(arg0->unk_048, arg1);
}

s32 LabPCList_RowMenuHandleInput(unk_func_8830867C_02C* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_02C->unk_30 & 2) {
        var_v1 = arg0->unk_048->unk_00.unk_10(arg0->unk_048, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void LabPCList_RunPartySelectionModal(unk_func_8830867C_02C* arg0, Controller* arg1) {
    s32 var_s3 = 0;
    s32 temp_v0;

    arg0->unk_048->unk_00.unk_14(arg0->unk_048, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_02C);

    while (!(arg0->unk_02C->unk_30 & 2)) {
        Ui_SendMessageAndPollInput(NULL);
    }

    BattleInfoWidget_BindData(arg0->unk_094, &arg0->unk_144);
    if (BattleInfoWidget_RunSelectionModal(arg0->unk_094, arg1) == 1) {
        LabPCList_FlattenEntries(&arg0->unk_03C, &arg0->unk_144);
        LabPCList_ApplyFiltersAndSort(arg0);
    }

    while (var_s3 == 0) {
        Ui_SendMessageAndPollInput(NULL);
        temp_v0 = LabPCList_RowMenuHandleInput(arg0, arg1);
        if (!(temp_v0 & 1) && (temp_v0 & 2)) {
            var_s3 = 1;
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(temp_v0);
    }
    arg0->unk_02C->unk_2C = 0xB;
}

void func_88305F28(unk_func_8830867C_02C* arg0) {
    unk_func_8830867C_04C_030_02C_000_000* spDC;
    unk_func_8830867C_02C_0CC_000* spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    WidgetPoint spC8;
    func88500A6C temp_v0_4;
    s32 spC0;
    s32 spBC;
    WidgetPoint spB8;
    s32 spB4;
    s32 spB0;
    s32 spAC;
    WidgetPoint spA8;
    unk_func_8830867C_02C_0CC_000 sp4C;
    char* sp48;
    char* sp44;
    s32 sp40;
    unk_func_8830867C_02C_0CC_000_008* sp34;

    spDC = arg0->unk_0AC->unk_30->unk_2C->unk_00->unk_00[arg0->unk_0AC->unk_30->unk_38];
    spD8 = arg0->unk_034->unk_00.unk_2C->unk_00[arg0->unk_034->unk_00.unk_38];
    spD0 = arg0->unk_034->unk_00.unk_38;
    spCC = arg0->unk_034->unk_00.unk_38 - (arg0->unk_034->unk_58 / arg0->unk_034->unk_00.unk_3E);

    if (spDC->unk_08 >= 0x64) {
        sp34 = &spD8->unk_08;
        spC0 = BattleMon_CountMoves(sp34);
        if (spC0 < 4) {
            LabPCList_ClearMovesFrom(sp34, spC0);
            spBC = -1;
            sp34 = (u8*)spD8 + spC0;
        } else {
            do {
                spC0 = arg0->unk_0AC->unk_78->unk_30->unk_38;
            } while (0);
            sp34 = (u8*)spD8 + spC0;
            spBC = sp34->unk_11;
        }
        LabPCList_TeachTmMove(spD8, spDC, spC0);

        temp_v0_4 = ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage));
        arg0->unk_CD0 = 1;
        temp_v0_4(arg0->unk_038, 1);

        spC8.unk_00 = (arg0->unk_0DC->unk_18 * spC0) + 0x84;
        spC8.unk_02 = arg0->unk_034->unk_5C - arg0->unk_034->unk_58;

        LabPCList_TextFadeWidget_Start(arg0->unk_0BC, spBC, sp34->unk_11, spC8);
        LabPCList_SwitchColumnPage(arg0);
        ((func8850CF00)Memmap_GetFragmentVaddr(WidgetTree_RunChildWidgetGroup))(arg0->unk_0B8, gPlayer1Controller);
        LabPCList_ApplyFiltersAndSort(arg0);
        LabPCList_DiscardFilterBackup(arg0);
        spD4 = LabPCList_FindEntryIndex(arg0->unk_034->unk_00.unk_2C, spD8);
        if (spD4 == -1) {
            ((func88507C0C)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelectionWithOffset))(arg0->unk_034, spD0, spCC);
            Text_SetStringToken(0x1A, spD8->unk_38);
            Text_SetStringToken(0x1D, Text_GetString(NULL, 0, D_8831A4CC, spBC - 1));
            Text_SetStringToken(0x1E, Text_GetString(NULL, 0, D_8831A4CC, sp34->unk_11 - 1));
            Text_GetString(arg0->unk_CCC->unk_40, 0x140, D_8831A4C4, 0x5D);
            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(arg0->unk_090, arg0->unk_CCC, 0, 0);
            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_090, gPlayer1Controller);
        } else {
            ((func88507C0C)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelectionWithOffset))(arg0->unk_034, spD4, spCC);
        }
    } else if (spDC->unk_08 >= 0x32) {
        spB4 = arg0->unk_0AC->unk_78->unk_30->unk_38;
        LabPCList_ApplyPpUpItem(spD8, spDC, spB4, &spB0, &spAC);

        temp_v0_4 = ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage));
        arg0->unk_CD0 = 1;
        temp_v0_4(arg0->unk_038, 1);

        spB8.unk_00 = (arg0->unk_0DC->unk_18 * spB4) + 0x84;
        spB8.unk_02 = arg0->unk_034->unk_5C - arg0->unk_034->unk_58;
        LabPCList_PpUpAnimWidget_Start(arg0->unk_0C0, spD8->unk_08.unk_09[spB4], spB0, spAC, spB8);
        LabPCList_SwitchColumnPage(arg0);
        ((func8850CF00)Memmap_GetFragmentVaddr(WidgetTree_RunChildWidgetGroup))(arg0->unk_0B8, gPlayer1Controller);
    } else {
        sp4C = *spD8;

        sp40 = LabPCList_ApplyVitaminItem(&sp4C, spDC, &sp48, &sp44);

        temp_v0_4 = ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage));
        arg0->unk_CD0 = 2;
        temp_v0_4(arg0->unk_038, 2);

        spA8.unk_00 = (arg0->unk_0DC->unk_28 * sp40) + 0x84;
        spA8.unk_02 = arg0->unk_034->unk_5C - arg0->unk_034->unk_58;

        LabPCList_TextCrossfadeWidget_Start(arg0->unk_0C4, sp48, sp44, spA8);
        LabPCList_SwitchColumnPage(arg0);
        ((func8850CF00)Memmap_GetFragmentVaddr(WidgetTree_RunChildWidgetGroup))(arg0->unk_0B8, gPlayer1Controller);

        *spD8 = sp4C;

        LabPCList_ApplyFiltersAndSort(arg0);
        LabPCList_DiscardFilterBackup(arg0);
        spD4 = LabPCList_FindEntryIndex(arg0->unk_034->unk_00.unk_2C, spD8);
        if (spD4 == -1) {
            ((func88507C0C)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelectionWithOffset))(arg0->unk_034, spD0, spCC);
            Text_SetStringToken(0x1A, spD8->unk_38);
            Text_SetNumberToken(2, sp48);
            Text_SetNumberToken(3, sp44);
            Text_GetString(arg0->unk_CCC->unk_40, 0x140, D_8831A4C4, 0x5E);
            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(arg0->unk_090, arg0->unk_CCC, 0, 0);
            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_090, gPlayer1Controller);
        } else {
            ((func88507C0C)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelectionWithOffset))(arg0->unk_034, spD4, spCC);
        }
    }
    LabPCList_BuildTmHmList(&arg0->unk_C48, arg0->unk_1A8, arg0->unk_154, 3, 0xAA);
}

s32 LabPCList_OpenListMenu(unk_func_8830867C_02C* arg0, Controller* arg1) {
    char* sp28[6];
    u32 sp24;

    sp28[0] = Text_GetString(NULL, 0, D_8831A4C4, 0x17);
    sp28[1] = Text_GetString(NULL, 0, D_8831A4C4, 0x18);
    sp28[2] = Text_GetString(NULL, 0, D_8831A4C4, 0x19);
    sp28[3] = Text_GetString(NULL, 0, D_8831A4C4, 0x1A);
    sp28[4] = Text_GetString(NULL, 0, D_8831A4C4, 0x1B);
    sp28[5] = Text_GetString(NULL, 0, D_8831A4C4, 0x1C);

    BattleInfoWidget_SetLabels(arg0->unk_08C, sp28, 6);

    arg0->unk_08C->unk_30 = arg0->unk_054->unk_10;
    arg0->unk_08C->unk_34 = arg0->unk_054->unk_14;

    BattleInfoWidget_UpdateViewport(arg0->unk_08C);

    if ((arg0->unk_034->unk_00.unk_2C->unk_08 == 0) || (arg0->unk_C48.unk_08 == 0)) {
        arg0->unk_08C->unk_3C->unk_34[3] |= 4;
    }

    if ((arg0->unk_C54.unk_00 == 0) && (arg0->unk_C54.unk_04 == 0)) {
        arg0->unk_08C->unk_3C->unk_34[5] |= 4;
    }

    arg0->unk_04C->unk_14(arg0->unk_04C, 0x100);
    sp24 = BattleInfoWidget_RunEntryModal(arg0->unk_08C, arg1, arg0->unk_CC4);
    arg0->unk_04C->unk_14(arg0->unk_04C, 1);

    arg0->unk_CC4 = arg0->unk_08C->unk_3C->unk_38;

    switch (sp24) {
        case 0:
            sp24 = 0;
            break;

        case 1:
            LabPCList_SaveFilterState(arg0);
            LabPCList_SetSortMode(arg0, 0x11);
            PointerList_Sort(arg0->unk_034->unk_00.unk_2C, D_8831A1F8[arg0->unk_C54.unk_00]);
            ((func88507AE4)Memmap_GetFragmentVaddr(WidgetTree_SetScrollableGridIndex))(arg0->unk_034, 0);
            sp24 = 0;
            break;

        case 2:
            LabPCList_SaveFilterState(arg0);
            LabPCList_SetSortMode(arg0, 0x12);
            PointerList_Sort(arg0->unk_034->unk_00.unk_2C, D_8831A1F8[arg0->unk_C54.unk_00]);
            ((func88507AE4)Memmap_GetFragmentVaddr(WidgetTree_SetScrollableGridIndex))(arg0->unk_034, 0);
            sp24 = 0;
            break;

        case 3:
            sp24 = 1;
            break;

        case 4:
            sp24 = 2;
            break;

        case 5:
            sp24 = 3;
            break;

        case 6:
            LabPCList_ResetFilterState(arg0);
            LabPCList_ApplyFiltersAndSort(arg0);
            LabPCList_DiscardFilterBackup(arg0);
            arg0->unk_CB8 = 0;
            sp24 = 0;
            break;
    }

    return sp24;
}

s32 LabPCList_OpenRowMenu(unk_func_8830867C_02C* arg0, Controller* arg1) {
    static char D_8831A500[0x20];

    char* sp44[5];
    u32 sp40;
    unk_func_8830867C_02C_0CC_000* sp3C;
    u32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;

    sp3C = arg0->unk_034->unk_00.unk_2C->unk_00[arg0->unk_034->unk_00.unk_38];
    if (arg0->unk_C54.unk_04 & 8) {
        sp38 = 0x24;
    } else {
        sp38 = 0x23;
    }

    Text_SetStringToken(0x19, Text_GetString(NULL, 0, D_8831A4D0, sp3C->unk_08.unk_00 - 1));
    Text_GetString(D_8831A500, 0x20, D_8831A4C4, sp38);

    sp44[0] = D_8831A500;
    sp38 = (arg0->unk_C54.unk_04 & 0x10) ? (0x26) : (0x25);
    sp44[1] = Text_GetString(NULL, 0, D_8831A4C4, sp38);
    sp44[2] = Text_GetString(NULL, 0, D_8831A4C4, 0x27);
    sp44[3] = Text_GetString(NULL, 0, D_8831A4C4, 0x28);
    sp44[4] = Text_GetString(NULL, 0, D_8831A4C4, 0x29);

    BattleInfoWidget_SetLabels(arg0->unk_08C, sp44, 5);

    arg0->unk_08C->unk_30.unk_00 = 0x26;
    arg0->unk_08C->unk_30.unk_02 = (arg0->unk_034->unk_5C - arg0->unk_034->unk_58) + 0x16;
    arg0->unk_08C->unk_34.unk_00 = 0x50;
    arg0->unk_08C->unk_34.unk_02 = 0x14;

    BattleInfoWidget_UpdateViewport(arg0->unk_08C);

    if (arg0->unk_C48.unk_08 == 0) {
        arg0->unk_08C->unk_3C->unk_34[3] |= 4;
    }

    if ((sp3C->unk_08.unk_00 <= 0) || (sp3C->unk_08.unk_00 >= 0x98)) {
        arg0->unk_08C->unk_3C->unk_34[0] |= 4;
        arg0->unk_08C->unk_3C->unk_34[1] |= 4;
        arg0->unk_08C->unk_3C->unk_34[3] |= 4;
    }

    arg0->unk_034->unk_00.unk_00.unk_24(&arg0->unk_034->unk_00.unk_00, 0x100);

    sp40 = BattleInfoWidget_RunEntryModal(arg0->unk_08C, arg1, arg0->unk_CC8);

    arg0->unk_034->unk_00.unk_00.unk_24(&arg0->unk_034->unk_00.unk_00, 1);
    arg0->unk_CC8 = arg0->unk_08C->unk_3C->unk_38;

    switch (sp40) {
        case 0:
            sp40 = 0;
            break;

        case 1:
            sp34 = arg0->unk_034->unk_00.unk_38 - (arg0->unk_034->unk_58 / arg0->unk_034->unk_00.unk_3E);

            LabPCList_SaveFilterState(arg0);
            if (LabPCList_ToggleFilterFlag(arg0, 8) != 0) {
                arg0->unk_C54.unk_10 = sp3C->unk_08.unk_00;
            }
            LabPCList_ApplyFiltersAndSort(arg0);
            ((func88507C0C)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelectionWithOffset))(
                arg0->unk_034, LabPCList_FindEntryIndex(arg0->unk_034->unk_00.unk_2C, sp3C), sp34);
            sp40 = 0;
            break;

        case 2:
            sp30 = arg0->unk_034->unk_00.unk_38 - (arg0->unk_034->unk_58 / arg0->unk_034->unk_00.unk_3E);

            LabPCList_SaveFilterState(arg0);
            if (LabPCList_ToggleFilterFlag(arg0, 0x10) != 0) {
                sp2C = sp3C->unk_08.unk_00 - 1;

                arg0->unk_C54.unk_14.unk_00 = 1;

                arg0->unk_C54.unk_14.unk_04[0] = D_80070FA0[sp2C].unk_06;

                if (D_80070FA0[sp2C].unk_06 != D_80070FA0[sp2C].unk_07) {
                    arg0->unk_C54.unk_14.unk_04[1] = D_80070FA0[sp2C].unk_07;
                    arg0->unk_C54.unk_14.unk_00++;
                }
            }

            LabPCList_ApplyFiltersAndSort(arg0);
            ((func88507C0C)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelectionWithOffset))(
                arg0->unk_034, LabPCList_FindEntryIndex(arg0->unk_034->unk_00.unk_2C, sp3C), sp30);
            sp40 = 0;
            break;

        case 3:
            sp40 = 1;
            break;

        case 4:
            sp40 = 2;
            break;

        case 5:
            sp40 = 3;
            break;
    }

    return sp40;
}

typedef struct unk_D_883172F4 {
    /* 0x00 */ u16* unk_00;
    /* 0x04 */ s32 unk_04;
} unk_D_883172F4; // size = 0x8

s32 LabPCList_HandleColumnHeaderClick(unk_func_8830867C_02C* arg0, WidgetNode* arg1, s32 arg2, Controller* arg3) {
    static s16 D_883172DC[] = {
        0x001E,
        0x001F,
        0x0020,
        0x0000,
    };
    static s16 D_883172E4[] = {
        0x001E,
        0x001F,
    };
    static s16 D_883172E8[] = {
        0x001D,
        0x0000,
    };
    static s16 D_883172EC[] = {
        0x0021,
        0x0000,
    };
    static s16 D_883172F0[] = {
        0x0022,
        0x0000,
    };
    static unk_D_883172F4 D_883172F4[] = {
        {
            D_883172EC,
            0x00000001,
        },
        {
            D_883172E8,
            0x00000001,
        },
        {
            D_883172EC,
            0x00000001,
        },
        {
            D_883172F0,
            0x00000001,
        },
        {
            NULL,
            0x00000000,
        },
        {
            NULL,
            0x00000000,
        },
        {
            D_883172DC,
            0x00000003,
        },
        {
            D_883172E4,
            0x00000002,
        },
        {
            D_883172E4,
            0x00000002,
        },
        {
            D_883172E4,
            0x00000002,
        },
        {
            D_883172E4,
            0x00000002,
        },
        {
            D_883172E4,
            0x00000002,
        },
    };

    u32 var_s0;
    s32 sp50;
    s32 i;
    char* sp40[3];

    for (i = 0; i < D_883172F4[arg2 - 2].unk_04; i++) {
        sp40[i] = Text_GetString(NULL, 0, D_8831A4C4, D_883172F4[arg2 - 2].unk_00[i]);
    }

    BattleInfoWidget_SetLabels(arg0->unk_08C, sp40, D_883172F4[arg2 - 2].unk_04);

    arg0->unk_08C->unk_30 = arg1->unk_10;
    arg0->unk_08C->unk_34 = arg1->unk_14;

    BattleInfoWidget_UpdateViewport(arg0->unk_08C);
    arg0->unk_04C->unk_14(arg0->unk_04C, 0x100);
    var_s0 = BattleInfoWidget_RunEntryModal(arg0->unk_08C, arg3, 0);
    arg0->unk_04C->unk_14(arg0->unk_04C, 1);

    switch (var_s0) {
        case 0:
            var_s0 = 0;
            break;

        case 1:
            switch (arg2) {
                case 2:
                    sp50 = 0x10;
                    break;

                case 3:
                    sp50 = 0xE;
                    break;

                case 4:
                    sp50 = 0xF;
                    break;

                case 5:
                    sp50 = 1;
                    break;

                case 8:
                    sp50 = 3;
                    break;

                case 9:
                    sp50 = 5;
                    break;

                case 10:
                    sp50 = 7;
                    break;

                case 11:
                    sp50 = 9;
                    break;

                case 12:
                    sp50 = 0xB;
                    break;

                case 13:
                    sp50 = 0xD;
                    break;
            }

            LabPCList_SaveFilterState(arg0);
            LabPCList_SetSortMode(arg0, sp50);
            PointerList_Sort(arg0->unk_034->unk_00.unk_2C, D_8831A1F8[arg0->unk_C54.unk_00]);
            ((func88507AE4)Memmap_GetFragmentVaddr(WidgetTree_SetScrollableGridIndex))(arg0->unk_034, 0);
            var_s0 = 0;
            break;

        case 2:
            switch (arg2) {
                case 8:
                    sp50 = 2;
                    break;

                case 9:
                    sp50 = 4;
                    break;

                case 10:
                    sp50 = 6;
                    break;

                case 11:
                    sp50 = 8;
                    break;

                case 12:
                    sp50 = 0xA;
                    break;

                case 13:
                    sp50 = 0xC;
                    break;
            }

            LabPCList_SaveFilterState(arg0);
            LabPCList_SetSortMode(arg0, sp50);
            PointerList_Sort(arg0->unk_034->unk_00.unk_2C, D_8831A1F8[arg0->unk_C54.unk_00]);

            ((func88507AE4)Memmap_GetFragmentVaddr(WidgetTree_SetScrollableGridIndex))(arg0->unk_034, 0);
            var_s0 = 0;
            break;

        case 3:
            var_s0 = 1;
            break;
    }

    return var_s0;
}

u32 LabPCList_GetColumnMenuIndex(unk_func_8830867C_02C* arg0) {
    s32 var_v1 = arg0->unk_04C->unk_24;

    if (var_v1 >= 2) {
        switch (arg0->unk_038->unk_2C) {
            case 0:
                break;

            case 1:
                var_v1 += 5;
                break;

            case 2:
                var_v1 += 6;
                break;
        }
    }

    return var_v1;
}

void func_88306FE4(void) {
}

void LabPCList_InitColumnSelectionProxy(unk_func_8830867C_02C_048* arg0, unk_func_8830867C_02C* arg1) {
    ((func8850CBA8)Memmap_GetFragmentVaddr(WidgetTree_InitChildSelectionProxy))(arg0);
    arg0->unk_00.unk_10 = LabPCList_HandleTopLevelInput;
    arg0->unk_24 = arg1;
}

void LabPCList_SaveAll(unk_func_8830867C_02C* arg0, s32 arg1) {
    s32 sp24 = GbSave_GetActivePort();

    ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_0B0->unk_40, 2);

    Ui_SendMessageAndPollInput(NULL);
    LabPCList_SaveDirtyBoxes(&arg0->unk_144, arg1);
    LabPCList_SaveDirtyDecks(arg0);

    if (arg1 & 0x30) {
        Save_FlushBank(3);
    }

    if (arg1 & 0xF) {
        if (arg1 & 5) {
            GbSave_RebuildSeenBitfield(sp24);
        }
        ((func88900970)Memmap_GetFragmentVaddr(LabUI_ShowSavingPrompt))(arg0->unk_0B0, sp24);
    }

    if (arg1 & 0x30) {
        Save_CommitBankRecords(3);
        Save_FlushBank(3);
    }
}

void LabPCList_MarkIneligibleEntries(unk_func_8830867C_02C* arg0) {
    s32 i;
    s32 var_v0;
    unk_func_8830867C_02C_0CC_000** temp_v0_2;
    unk_func_8830867C_04C_030_02C_000_000* temp_s1;

    temp_s1 = arg0->unk_0AC->unk_30->unk_2C->unk_00[arg0->unk_0AC->unk_30->unk_38].unk_00[0];
    temp_v0_2 = arg0->unk_034->unk_00.unk_2C->unk_00;

    for (i = 0; i < arg0->unk_034->unk_00.unk_2C->unk_08; i++) {
        if ((temp_v0_2[i]->unk_08.unk_00 <= 0) || (temp_v0_2[i]->unk_08.unk_00 >= 0x98)) {
            arg0->unk_034->unk_00.unk_34[i] |= 4;
        } else {
            if (temp_s1->unk_08 >= 0x64) {
                var_v0 = LabPCList_CheckTmHmIneligibility(**(u8**)&temp_s1->unk_00, &temp_v0_2[i]->unk_08);
            } else if (temp_s1->unk_08 >= 0x32) {
                var_v0 = LabPCList_CheckPpUpIneligibility(&temp_v0_2[i]->unk_08);
            } else {
                var_v0 = LabPCList_CheckVitaminIneligibility(**(u8**)&temp_s1->unk_00, &temp_v0_2[i]->unk_08);
            }

            if (var_v0 != 0) {
                arg0->unk_034->unk_00.unk_34[i] |= 4;
            }
        }
    }
}

s32 LabPCList_IsGamePakBoxEmpty(unk_func_8830867C_02C* arg0) {
    return arg0->unk_144.unk_00->unk_0C->unk_10.unk_08 == 0;
}

s32 LabPCList_ConfirmExit(unk_func_8830867C_02C* arg0, Controller* arg1, s32 arg2) {
    s32 sp34;
    s32 sp30;
    s32 temp_v0_2;

    sp34 = 1;
    sp30 = LabPCList_CheckAnyDirty(arg0);
    if (sp30 != 0) {
        arg0->unk_048->unk_00.unk_14(arg0->unk_048, 0);
        ((func889006D4)Memmap_GetFragmentVaddr(LabUI_OpenConfirmDialog))(arg0->unk_0B0, LabPCList_IsGamePakBoxEmpty(arg0));

        temp_v0_2 = ((func88900808)Memmap_GetFragmentVaddr(LabUI_RunConfirmDialog))(arg0->unk_0B0, arg1, 1);
        if (temp_v0_2 == 0) {
            LabPCList_SaveAll(arg0, sp30);
            ((func889007AC)Memmap_GetFragmentVaddr(LabUI_CloseConfirmDialog))(arg0->unk_0B0);
        } else if (temp_v0_2 == 1) {
            ((func889007AC)Memmap_GetFragmentVaddr(LabUI_CloseConfirmDialog))(arg0->unk_0B0);
        } else if (temp_v0_2 == 2) {
            ((func889007AC)Memmap_GetFragmentVaddr(LabUI_CloseConfirmDialog))(arg0->unk_0B0);
            sp34 = 0;
        }

        arg0->unk_048->unk_00.unk_14(arg0->unk_048, 1);
    } else if ((arg2 == 0) && (arg0->unk_CB8 != 0)) {
        arg0->unk_048->unk_00.unk_14(arg0->unk_048, 0);
        if (BattleInfoWidget_RunSaveConfirmModal(arg0->unk_0B4, arg1) == 1) {
            sp34 = 0;
        }
        arg0->unk_048->unk_00.unk_14(arg0->unk_048, 1);
    }
    return sp34;
}

void LabPCList_SetGridInteractive(unk_func_8830867C_02C* arg0, s32 arg1) {
    if (arg1 != 0) {
        arg0->unk_02C->unk_00.unk_28 |= 0x200;
        arg0->unk_030->unk_00.unk_28 |= 1;
        arg0->unk_04C->unk_14(arg0->unk_04C, 1);
    } else {
        arg0->unk_02C->unk_00.unk_28 &= ~0x200;
        arg0->unk_030->unk_00.unk_28 &= ~1;
        arg0->unk_04C->unk_14(arg0->unk_04C, 0);
    }
}

void LabPCList_ResetGridSelection(unk_func_8830867C_02C_048* arg0) {
    ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0->unk_24->unk_034);
    arg0->unk_24->unk_0E0 = 0;
    ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0, 1);
}

void LabPCList_HandleGridSelectionEntry(unk_func_8830867C_02C_048* arg0, Controller* arg1) {
    LabPCList_SetGridInteractive(arg0->unk_24, 0);
    Ui_SendMessageAndPollInput(NULL);
    Ui_SendMessageAndPollInput(NULL);

    if (BattleInfoWidget_RunItemMenuModal(arg0->unk_24->unk_0AC, arg1) == 2) {
        arg0->unk_24->unk_0E0 = 1;
        LabPCList_MarkIneligibleEntries(arg0->unk_24);
        ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0, 0);
    } else {
        Ui_SendMessageAndPollInput(NULL);
        LabPCList_SetGridInteractive(arg0->unk_24, 1);
    }
}

s32 LabPCList_HandleBackButton(unk_func_8830867C_02C_048* arg0, Controller* arg1) {
    s32 sp1C = 2;

    Audio_PlaySoundEffectById(SFX_MENU_BACK);

    if (arg0->unk_24->unk_CB4 != 0) {
        LabPCList_RestoreFilterState(arg0->unk_24);
        LabPCList_ApplyFiltersAndSort(arg0->unk_24);
        ((func88507C0C)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelectionWithOffset))(arg0->unk_24->unk_034, arg0->unk_24->unk_CBC,
                                                               arg0->unk_24->unk_CC0);
        sp1C = 3;
    } else if (LabPCList_ConfirmExit(arg0->unk_24, arg1, 0) == 0) {
        sp1C = 3;
    }
    return sp1C;
}

s32 LabPCList_HandlePageSwitchInput(unk_func_8830867C_02C_048* arg0, Controller* arg1) {
    s32 var_v1 = 0;

    if (gPlayer1Controller->buttonPressed & 2) {
        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
        if (arg0->unk_24->unk_CD0 == 0) {
            arg0->unk_24->unk_CD0 += 3;
        }
        arg0->unk_24->unk_CD0--;
        ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_24->unk_038, arg0->unk_24->unk_CD0);
        LabPCList_SwitchColumnPage(arg0->unk_24);
        var_v1 = 0x80000005;
    } else if (gPlayer1Controller->buttonPressed & 1) {
        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
        if (arg0->unk_24->unk_CD0 >= 2) {
            arg0->unk_24->unk_CD0 -= 3;
        }
        arg0->unk_24->unk_CD0++;
        ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_24->unk_038, arg0->unk_24->unk_CD0);
        LabPCList_SwitchColumnPage(arg0->unk_24);
        var_v1 = 0x80000005;
    }

    return var_v1;
}

s32 LabPCList_HandleGridInput(unk_func_8830867C_02C_048* arg0, Controller* arg1, s32 arg2) {
    UNUSED s32 pad;
    s32 temp_v0;
    unk_func_8830867C_02C_0CC_000* sp24;
    unk_func_8830867C_02C_0CC_000* sp20;

    if (arg0->unk_24->unk_0E0 != 0) {
        if (arg2 & 2) {
            Audio_PlaySoundEffectById(SFX_MENU_BACK);
            LabPCList_ResetGridSelection(arg0);
            LabPCList_HandleGridSelectionEntry(arg0, arg1);
            arg2 = 1;
        } else if (arg2 & 4) {
            if (arg0->unk_24->unk_034->unk_00.unk_34[arg0->unk_24->unk_034->unk_00.unk_38] & 4) {
                Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                arg2 = 1;
            } else {
                Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                BattleInfoWidget_SetItemMenuMon(
                    arg0->unk_24->unk_0AC,
                    &arg0->unk_24->unk_034->unk_00.unk_2C->unk_00[arg0->unk_24->unk_034->unk_00.unk_38]->unk_08);

                arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 0x100);

                if (BattleInfoWidget_RunItemMenuModal(arg0->unk_24->unk_0AC, arg1) == 1) {
                    Ui_SendMessageAndPollInput(NULL);
                    func_88305F28(arg0->unk_24);
                    LabPCList_ResetGridSelection(arg0);
                    LabPCList_SetGridInteractive(arg0->unk_24, 1);
                } else {
                    arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 1);
                }
            }
        }
        arg2 = 1;
    } else if (arg2 & 8) {
        if (arg1->buttonPressed & 0x800) {
            ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0, 1);
            ((func8850CB48)Memmap_GetFragmentVaddr(WidgetTree_SetGridMenuSelection))(arg0->unk_24->unk_04C, 1);
            arg2 |= 0x80000001;
        }
    } else {
        if (arg2 & 2) {
            arg2 = LabPCList_HandleBackButton(arg0, arg1);
        } else if (arg2 & 4) {
            if (arg0->unk_24->unk_034->unk_00.unk_2C->unk_08 == 0) {
                Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                arg2 = 1;
            } else {
                Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                temp_v0 = LabPCList_OpenRowMenu(arg0->unk_24, arg1);
                if (temp_v0 == 1) {
                    sp24 = arg0->unk_24->unk_034->unk_00.unk_2C->unk_00[arg0->unk_24->unk_034->unk_00.unk_38];

                    BattleInfoWidget_SetMoveDestinationTitle(arg0->unk_24->unk_0A8, sp24->unk_00->unk_00->unk_08, sp24->unk_00->unk_04);
                    BattleInfoWidget_MarkIneligibleDestinations(arg0->unk_24->unk_0A8, sp24);

                    arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 0x100);

                    Ui_SendMessageAndPollInput(NULL);
                    Ui_SendMessageAndPollInput(NULL);
                    if (BattleInfoWidget_RunMoveDestinationModal(arg0->unk_24->unk_0A8, arg1) == 1) {
                        LabPCList_PerformMoveMon(arg0->unk_24, sp24, arg1);
                    }
                    Ui_SendMessageAndPollInput(NULL);

                    arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 1);

                    arg2 = 1;
                } else if (temp_v0 == 2) {
                    BattleInfoWidget_RebindItemGrid(arg0->unk_24->unk_0AC, &arg0->unk_24->unk_C48);
                    BattleInfoWidget_SetItemMenuMon(
                        arg0->unk_24->unk_0AC,
                        &arg0->unk_24->unk_034->unk_00.unk_2C->unk_00[arg0->unk_24->unk_034->unk_00.unk_38]->unk_08);
                    BattleInfoWidget_SetItemMenuMode(arg0->unk_24->unk_0AC, 0);

                    arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 0x100);

                    Ui_SendMessageAndPollInput(NULL);
                    Ui_SendMessageAndPollInput(NULL);
                    if (BattleInfoWidget_RunItemMenuModal(arg0->unk_24->unk_0AC, arg1) == 1) {
                        func_88305F28(arg0->unk_24);
                    }
                    Ui_SendMessageAndPollInput(NULL);

                    arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 1);

                    arg2 = 1;
                } else {
                    if (temp_v0 == 3) {
                        sp20 = arg0->unk_24->unk_034->unk_00.unk_2C->unk_00[arg0->unk_24->unk_034->unk_00.unk_38];

                        arg0->unk_24->unk_CDC->unk_0C = &sp20->unk_08;
                        arg0->unk_24->unk_CDC->unk_10 = sp20->unk_00->unk_00->unk_08;

                        arg0->unk_24->unk_CD8(1, arg0->unk_24->unk_CDC);

                        arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 0x100);

                        if (arg0->unk_24->unk_CD8(4, arg0->unk_24->unk_CDC) == 1) {
                            sp20->unk_00->unk_0C = 1;
                        }
                        Ui_SendMessageAndPollInput(NULL);

                        arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 1);
                    }
                    arg2 = 1;
                }
            }
        } else if (gPlayer1Controller->buttonPressed & 0x10) {
            ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0, 1);
            arg2 = 0x80000005;
        } else {
            arg2 = LabPCList_HandlePageSwitchInput(arg0, arg1);
        }
    }

    return arg2;
}

s32 LabPCList_HandleColumnMenuInput(unk_func_8830867C_02C_048* arg0, Controller* arg1, s32 arg2) {
    u32 sp34;
    s32 temp_s0_11;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 temp_s0_23;
    s32 temp_s0_27;
    s32 temp_v0_2;

    if (arg2 & 8) {
        if ((arg1->buttonPressed == 0x400) && (arg0->unk_24->unk_04C->unk_24 == 1)) {
            ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0, 0);
            ((func88507AE4)Memmap_GetFragmentVaddr(WidgetTree_SetScrollableGridIndex))(
                arg0->unk_24->unk_034, arg0->unk_24->unk_034->unk_58 / arg0->unk_24->unk_034->unk_00.unk_3E);
            arg0->unk_24->unk_034->unk_6C = 8;
            arg0->unk_24->unk_034->unk_54 = 0x400;
            arg2 |= 0x80000001;
        }
    } else {
        if (arg2 & 2) {
            arg2 = LabPCList_HandleBackButton(arg0, arg1);
        } else if (arg2 & 4) {
            sp34 = LabPCList_GetColumnMenuIndex(arg0->unk_24);
            switch (sp34) {
                case 0:
                    Audio_PlaySoundEffectById(SFX_MENU_BACK);
                    arg2 = 2;
                    if (LabPCList_ConfirmExit(arg0->unk_24, arg1, 1) == 0) {
                        arg2 = 3;
                    }
                    break;

                case 1:
                    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                    temp_v0_2 = LabPCList_OpenListMenu(arg0->unk_24, arg1);
                    if (temp_v0_2 == 1) {
                        sp2C = -1;
                        if (LabPCList_HasFilterFlag(arg0->unk_24, 0x20) != 0) {
                            sp2C = arg0->unk_24->unk_C54.unk_2C;
                        }
                        BattleInfoWidget_SetStatusSelection(arg0->unk_24->unk_098, sp2C);

                        arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 0x100);

                        Ui_SendMessageAndPollInput(NULL);
                        Ui_SendMessageAndPollInput(NULL);

                        sp2C = BattleInfoWidget_RunStatusModal(arg0->unk_24->unk_098, arg1);
                        Ui_SendMessageAndPollInput(NULL);

                        arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 1);

                        if (sp2C > 0) {
                            sp2C--;
                            LabPCList_SaveFilterState(arg0->unk_24);

                            if ((sp2C + 1) == arg0->unk_24->unk_098->unk_30->unk_2C->unk_08) {
                                LabPCList_ClearFilterFlag(arg0->unk_24, 0x20);
                            } else {
                                LabPCList_SetFilterFlag(arg0->unk_24, 0x20);
                                arg0->unk_24->unk_C54.unk_2C = sp2C;
                            }

                            LabPCList_ApplyFiltersAndSort(arg0->unk_24);
                            arg2 = 1;
                        }
                    } else if (temp_v0_2 == 2) {
                        BattleInfoWidget_RebindItemGrid(arg0->unk_24->unk_0AC, &arg0->unk_24->unk_C48);
                        BattleInfoWidget_SetItemMenuMon(arg0->unk_24->unk_0AC, 0);
                        BattleInfoWidget_SetItemMenuMode(arg0->unk_24->unk_0AC, 1);
                        LabPCList_HandleGridSelectionEntry(arg0, arg1);
                        arg2 = 1;
                    } else {
                        if (temp_v0_2 == 3) {
                            BattleInfoWidget_BindData(arg0->unk_24->unk_094, &arg0->unk_24->unk_144);

                            arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 0x100);

                            Ui_SendMessageAndPollInput(NULL);
                            Ui_SendMessageAndPollInput(NULL);
                            if (BattleInfoWidget_RunSelectionModal(arg0->unk_24->unk_094, arg1) == 1) {
                                LabPCList_FlattenEntries(&arg0->unk_24->unk_03C, &arg0->unk_24->unk_144);
                                LabPCList_ApplyFiltersAndSort(arg0->unk_24);
                                LabPCList_DiscardFilterBackup(arg0->unk_24);
                            }
                            Ui_SendMessageAndPollInput(NULL);
                            arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 1);
                        }
                    }
                    arg2 = 1;
                    break;

                case 2:
                    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                    LabPCList_HandleColumnHeaderClick(arg0->unk_24, arg0->unk_24->unk_058, sp34, arg1);
                    arg2 = 1;
                    break;

                case 3:
                    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                    LabPCList_HandleColumnHeaderClick(arg0->unk_24, arg0->unk_24->unk_05C, sp34, arg1);
                    arg2 = 1;
                    break;

                case 4:
                    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                    LabPCList_HandleColumnHeaderClick(arg0->unk_24, arg0->unk_24->unk_060, sp34, arg1);
                    arg2 = 1;
                    break;

                case 5:
                    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                    LabPCList_HandleColumnHeaderClick(arg0->unk_24, arg0->unk_24->unk_064, sp34, arg1);
                    arg2 = 1;
                    break;

                case 8:
                    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                    if (LabPCList_HandleColumnHeaderClick(arg0->unk_24, arg0->unk_24->unk_070, sp34, arg1) == 1) {
                        if (arg0->unk_24->unk_C54.unk_0C != 0) {
                            sp28 = arg0->unk_24->unk_C54.unk_09;
                            sp24 = arg0->unk_24->unk_C54.unk_08;
                        } else {
                            sp28 = arg0->unk_24->unk_C54.unk_08;
                            sp24 = arg0->unk_24->unk_C54.unk_09;
                        }
                        BattleInfoWidget_SetLevelRange(arg0->unk_24->unk_0A4, sp28, sp24, LabPCList_HasFilterFlag(arg0->unk_24, 1));

                        arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 0x100);

                        Ui_SendMessageAndPollInput(NULL);
                        Ui_SendMessageAndPollInput(NULL);
                        temp_s0_11 = BattleInfoWidget_RunLevelRangeModal(arg0->unk_24->unk_0A4, arg1);
                        Ui_SendMessageAndPollInput(NULL);

                        arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 1);

                        if (temp_s0_11 != 0) {
                            if (temp_s0_11 == 1) {
                                LabPCList_SaveFilterState(arg0->unk_24);
                                if (arg0->unk_24->unk_0A4->unk_3C->unk_30.unk_00 >=
                                    arg0->unk_24->unk_0A4->unk_38->unk_30.unk_00) {
                                    arg0->unk_24->unk_C54.unk_0C = 0;
                                    arg0->unk_24->unk_C54.unk_08 = arg0->unk_24->unk_0A4->unk_38->unk_30.unk_00;
                                    arg0->unk_24->unk_C54.unk_09 = arg0->unk_24->unk_0A4->unk_3C->unk_30.unk_00;
                                    LabPCList_SetSortMode(arg0->unk_24, 2);
                                } else {
                                    arg0->unk_24->unk_C54.unk_0C = 1;
                                    arg0->unk_24->unk_C54.unk_09 = arg0->unk_24->unk_0A4->unk_38->unk_30.unk_00;
                                    arg0->unk_24->unk_C54.unk_08 = arg0->unk_24->unk_0A4->unk_3C->unk_30.unk_00;
                                    LabPCList_SetSortMode(arg0->unk_24, 3);
                                }
                                LabPCList_SetFilterFlag(arg0->unk_24, 1);
                                LabPCList_ApplyFiltersAndSort(arg0->unk_24);
                                arg2 = 1;
                            } else {
                                if (temp_s0_11 == 2) {
                                    LabPCList_SaveFilterState(arg0->unk_24);
                                    arg0->unk_24->unk_C54.unk_08 = 1;
                                    arg0->unk_24->unk_C54.unk_09 = 0x64;
                                    arg0->unk_24->unk_C54.unk_0C = 0;
                                    LabPCList_ClearFilterFlag(arg0->unk_24, 1);
                                    LabPCList_ApplyFiltersAndSort(arg0->unk_24);
                                }
                            }
                        }
                    }
                    arg2 = 1;
                    break;

                case 9:
                    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                    LabPCList_HandleColumnHeaderClick(arg0->unk_24, arg0->unk_24->unk_074, sp34, arg1);
                    arg2 = 1;
                    break;

                case 10:
                    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                    LabPCList_HandleColumnHeaderClick(arg0->unk_24, arg0->unk_24->unk_078, sp34, arg1);
                    arg2 = 1;
                    break;

                case 11:
                    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                    LabPCList_HandleColumnHeaderClick(arg0->unk_24, arg0->unk_24->unk_07C, sp34, arg1);
                    arg2 = 1;
                    break;

                case 12:
                    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                    LabPCList_HandleColumnHeaderClick(arg0->unk_24, arg0->unk_24->unk_080, sp34, arg1);
                    arg2 = 1;
                    break;

                case 13:
                    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                    LabPCList_HandleColumnHeaderClick(arg0->unk_24, arg0->unk_24->unk_084, sp34, arg1);
                    arg2 = 1;
                    break;

                case 6:
                    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                    BattleInfoWidget_SetTypeEntries(arg0->unk_24->unk_09C, &arg0->unk_24->unk_C54.unk_1C);

                    arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 0x100);

                    temp_s0_23 = BattleInfoWidget_RunTypeSelectionModal(arg0->unk_24->unk_09C, arg1);
                    arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 1);

                    if (temp_s0_23 != 0) {
                        if (temp_s0_23 == 1) {
                            LabPCList_SaveFilterState(arg0->unk_24);
                            BattleInfoWidget_GetTypeEntries(arg0->unk_24->unk_09C, &arg0->unk_24->unk_C54.unk_1C);
                            if (arg0->unk_24->unk_C54.unk_1C.unk_00 == 0) {
                                LabPCList_ClearFilterFlag(arg0->unk_24, 2);
                            } else {
                                LabPCList_SetFilterFlag(arg0->unk_24, 2);
                            }
                            LabPCList_ApplyFiltersAndSort(arg0->unk_24);
                        } else if (temp_s0_23 == 2) {
                            LabPCList_SaveFilterState(arg0->unk_24);
                            LabPCList_ClearFilterFlag(arg0->unk_24, 2);
                            arg0->unk_24->unk_C54.unk_1C.unk_00 = 0;
                            LabPCList_ApplyFiltersAndSort(arg0->unk_24);
                        }
                    }
                    arg2 = 1;
                    break;

                case 7:
                    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                    BattleInfoWidget_SetMoveSlots(arg0->unk_24->unk_0A0, &arg0->unk_24->unk_C54.unk_24);

                    arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 0x100);

                    temp_s0_27 = BattleInfoWidget_RunMovePanelModal(arg0->unk_24->unk_0A0, arg1);

                    arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 1);

                    if (temp_s0_27 != 0) {
                        if (temp_s0_27 == 1) {
                            LabPCList_SaveFilterState(arg0->unk_24);
                            BattleInfoWidget_GetMoveSlots(arg0->unk_24->unk_0A0, &arg0->unk_24->unk_C54.unk_24);
                            if (arg0->unk_24->unk_C54.unk_24.unk_04 == 0) {
                                LabPCList_ClearFilterFlag(arg0->unk_24, 4);
                            } else {
                                LabPCList_SetFilterFlag(arg0->unk_24, 4);
                            }
                            LabPCList_ApplyFiltersAndSort(arg0->unk_24);
                            arg2 = 1;
                        } else if (temp_s0_27 == 2) {
                            LabPCList_SaveFilterState(arg0->unk_24);
                            LabPCList_ClearFilterFlag(arg0->unk_24, 4);
                            arg0->unk_24->unk_C54.unk_24.unk_04 = 0;
                            LabPCList_ApplyFiltersAndSort(arg0->unk_24);
                        }
                    }
                    arg2 = 1;
                    break;
            }
        } else if (gPlayer1Controller->buttonPressed & 0x20) {
            ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0, 0);
            arg2 = 0x80000005;
        } else {
            arg2 = LabPCList_HandlePageSwitchInput(arg0, arg1);
        }
    }

    return arg2;
}

s32 LabPCList_HandleTopLevelInput(unk_func_8830867C_02C_048* arg0, Controller* arg1) {
    s32 i;
    s32 var_a2 = 0;
    unk_func_8830867C_02C_048* var_a0;

    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;

        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }

        var_a2 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

    if (var_a2 & 1) {
        return var_a2;
    }

    if (var_a2 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_a2 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_a2 = 0x80000004;
        }
    }

    switch (arg0->unk_00.unk_1C) {
        case 0:
            var_a2 = LabPCList_HandleGridInput(arg0, arg1, var_a2);
            break;

        case 1:
            var_a2 = LabPCList_HandleColumnMenuInput(arg0, arg1, var_a2);
            break;
    }

    return var_a2;
}

void LabPCList_BuildWidget(unk_func_8830867C* arg0, s32 arg1, s32 arg2, MemoryPool* arg3, FontContext* arg4, char** arg5,
                   char** arg6, char** arg7, char** arg8, char** arg9) {
    static Color_RGBA8 D_88317354 = { 0x1E, 0x50, 0x50, 0xFF };
    static Color_RGBA8 D_88317358 = { 0x00, 0x0A, 0x0A, 0xFF };

    WidgetNode* sp8C;
    WidgetNode* sp88;
    FragmentEntry sp84;
    unk_func_88500EE4* sp80;
    unk_func_885088F4* sp7C;
    unk_func_88509A2C* sp78;
    unk_func_88509E34* sp74;
    WidgetNode* sp70;

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8830867C));

    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    sp8C = mem_pool_alloc(arg3, sizeof(WidgetNode));
    ((func885031E8)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGate))(sp8C, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&arg0->unk_00.unk_00, &sp8C->unk_00);

    sp80 = mem_pool_alloc(arg3, sizeof(unk_func_88500EE4));
    ((func88500EE4)Memmap_GetFragmentVaddr(WidgetTree_InitTintedTexture))(sp80, 0, 0, 0x280, 0x1E0, D_88318898, D_88317354,
                                                           D_88317358);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&sp8C->unk_00, &sp80->unk_00.unk_00);

    sp7C = mem_pool_alloc(arg3, sizeof(unk_func_885088F4));
    ((func885088F4)Memmap_GetFragmentVaddr(WidgetTree_InitSlideTransition))(sp7C, 0x41, 0x15C, 0xDC);
    sp7C->unk_2C = 5;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&sp8C->unk_00, &sp7C->unk_00.unk_00);

    sp78 = mem_pool_alloc(arg3, sizeof(unk_func_88509A2C));
    ((func88509A2C)Memmap_GetFragmentVaddr(WidgetTree_InitSaveSlotLabel))(sp78, 0x38, 0x22, GbSave_GetActivePort(),
                                                           Text_GetString(NULL, 0, D_8831A4C0, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&sp7C->unk_00.unk_00, &sp78->unk_00.unk_00);

    sp74 = mem_pool_alloc(arg3, sizeof(unk_func_88509E34));
    ((func88509E34)Memmap_GetFragmentVaddr(WidgetTree_InitTextMessage))(sp74, 0, 0, Text_GetString(NULL, 0, D_8831A4C4, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&sp7C->unk_00.unk_00, &sp74->unk_00.unk_00);

    sp88 = mem_pool_alloc(arg3, sizeof(WidgetNode));
    ((func885031E8)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGate))(sp88, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&arg0->unk_00.unk_00, &sp88->unk_00);

    arg0->unk_30 = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_030));
    BattleInfoWidget_InitDropdownMenu(arg0->unk_30, sp88, arg3);

    arg0->unk_34 = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_034));
    BattleInfoWidget_Build(arg0->unk_34, 0x56, 0x78, sp88, arg3);

    arg0->unk_38 = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_038));
    BattleInfoWidget_BuildStatusMenu(arg0->unk_38, 0x56, 0x96, sp88, arg3);

    arg0->unk_3C = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_03C));
    BattleInfoWidget_BuildTypePanel(arg0->unk_3C, 0xAA, 0x78, sp88, arg3);

    arg0->unk_40 = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_040));
    BattleInfoWidget_BuildMovePanel(arg0->unk_40, 0xAA, 0x78, sp88, arg3);

    arg0->unk_44 = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_044));
    BattleInfoWidget_BuildLevelRangeMenu(arg0->unk_44, 0xAA, 0xF5, sp88, arg3);

    arg0->unk_48 = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_048));
    BattleInfoWidget_BuildMoveDestinationMenu(arg0->unk_48, 0xAA, 0x78, sp88, arg3);

    arg0->unk_4C = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_04C));
    BattleInfoWidget_BuildItemMenu(arg0->unk_4C, 0xE7, 0x94, sp88, arg3);

    arg0->unk_50 = mem_pool_alloc(arg3, sizeof(unk_func_889000C4));

    ((func889000C4)Memmap_GetFragmentVaddr(LabUI_BuildConfirmDialog))(arg0->unk_50, 0, 0, 0, arg5, arg3);

    sp84 = FRAGMENT_LOAD(fragment27);

    arg0->unk_54.unk_04 = arg3;
    // clang-format off
    arg0->unk_54.unk_00 = 0x38; arg0->unk_54.unk_02 = 0x4E;
    // clang-format on
    arg0->unk_54.unk_14 = sp88;
    arg0->unk_6C = 0;
    arg0->unk_70 = arg6;
    arg0->unk_74 = D_8831A4D0;
    arg0->unk_78 = D_8831A4CC;
    arg0->unk_7C = D_8831A4D4;
    arg0->unk_80 = arg7;
    arg0->unk_84 = arg8;
    arg0->unk_88 = arg9;

    sp84(0, &arg0->unk_54);

    arg0->unk_2C = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_02C));
    LabPCList_BuildListScreen(arg0->unk_2C, 0x2C, 0x48, sp8C, arg0->unk_30, arg0->unk_34, arg0->unk_38, arg0->unk_3C, arg0->unk_40,
                  arg0->unk_44, arg0->unk_48, arg0->unk_4C, arg0->unk_50, sp84, &arg0->unk_54, arg3, arg4);

    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&sp88->unk_00, &arg0->unk_2C->unk_000.unk_00);

    sp70 = mem_pool_alloc(arg3, sizeof(WidgetNode));

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(sp70, 0x2C);

    // clang-format off
    sp70->unk_10.unk_00 = 0x2C; sp70->unk_10.unk_02 = 0x7C;
    // clang-format on

    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&arg0->unk_00.unk_00, &sp70->unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&sp70->unk_00, &arg0->unk_30->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&arg0->unk_00.unk_00, &arg0->unk_34->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&arg0->unk_00.unk_00, &arg0->unk_38->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&arg0->unk_00.unk_00, &arg0->unk_3C->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&arg0->unk_00.unk_00, &arg0->unk_40->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&arg0->unk_00.unk_00, &arg0->unk_44->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&arg0->unk_00.unk_00, &arg0->unk_48->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&arg0->unk_00.unk_00, &arg0->unk_4C->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&arg0->unk_00.unk_00, &arg0->unk_50->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&arg0->unk_00.unk_00, &arg0->unk_54.unk_08->unk_00);

    arg0->unk_50->unk_00.unk_10.unk_00 =
        arg0->unk_2C->unk_000.unk_10.unk_00 +
        ((arg0->unk_2C->unk_02C->unk_00.unk_14.unk_00 - arg0->unk_50->unk_2C->unk_00.unk_14.unk_00) / 2);
    arg0->unk_50->unk_00.unk_10.unk_02 =
        arg0->unk_2C->unk_000.unk_10.unk_02 +
        ((arg0->unk_2C->unk_02C->unk_00.unk_14.unk_02 - arg0->unk_50->unk_2C->unk_00.unk_14.unk_02) / 2);
}

void LabPCList_RunWidgetLoop(unk_func_8830867C* arg0) {
    s32 sp34 = 0;

    while (sp34 == 0) {
        BgStage_DrawFrame();

        ((func885008C4)Memmap_GetFragmentVaddr(WidgetTree_Update))(&arg0->unk_00);
        ((func88500828)Memmap_GetFragmentVaddr(WidgetTree_Draw))(&arg0->unk_00, 0, 0);

        BgStage_AdvanceFrame();
        Ui_ReceiveMessage(&sp34);
    }
}

void LabPCList_ScreenThreadEntry(unk_func_8830867C* arg0) {
    Input_SetRepeatController(gPlayer1Controller);
    LabPCList_RunPartySelectionModal(arg0->unk_2C, gPlayer1Controller);

    while (arg0->unk_2C->unk_02C->unk_00.unk_28 & 1) {
        Ui_SendMessageAndPollInput(NULL);
    }

    Ui_SendMessageAndPollInput(1);
    osStopThread(NULL);
}

s32 LabPCList_ShowListScreen(UNUSED s32 arg0, UNUSED s32 arg1) {
    FontContext* sp54;
    MemoryPool* sp50;
    void* sp4C;
    u8* sp48;
    func_88002628_sp38* sp44;
    char** sp40;
    char** sp3C;
    char** sp38;
    char** sp34;
    char** sp30;

    main_pool_push_state('PCHK');

    sp54 = Font_Init(0x1C, 0);

    ASSET_LOAD(D_04000000, fragment29_misc_1, 0);
    FRAGMENT_LOAD(fragment26);
    FRAGMENT_LOAD(fragment25);
    FRAGMENT_LOAD(fragment29);

    Text_InitStringTables();

    D_8831A4C0 = Text_GetStringTable(0x2A);
    D_8831A4CC = Text_GetStringTable(0x25);
    D_8831A4D0 = Text_GetStringTable(0x24);
    D_8831A4D4 = Text_GetStringTable(0x26);
    D_8831A4C4 = Text_GetStringTable(5);
    D_8831A4D8 = Text_GetStringTable(0x27);
    D_8831A4C8 = Text_GetStringTable(0xC);

    sp40 = Text_GetStringTable(7);
    sp3C = Text_GetStringTable(6);
    sp38 = Text_GetStringTable(0x28);
    sp34 = Text_GetStringTable(0x29);
    sp30 = Text_GetStringTable(0xB);

    sp48 = main_pool_alloc(0x1000, 0);

    sp50 = mem_pool_try_init(0x18000, 0);

    sp4C = mem_pool_alloc(sp50, sizeof(unk_func_8830867C));
    LabPCList_BuildWidget(sp4C, 0, 0, sp50, sp54, sp40, sp3C, sp38, sp34, sp30);

    sp44 = ALIGN16((u32)mem_pool_alloc(sp50, sizeof(func_88002628_sp38)));

    osCreateThread(&sp44->thread, 0x32, LabPCList_ScreenThreadEntry, sp4C, sp48 + 0x1000, osGetThreadPri(NULL) - 1);

    Ui_InitInputMessageQueue();

    osStartThread(&sp44->thread);

    StageLoader_UpdateSegments();
    LabPCList_RunWidgetLoop(sp4C);

    osDestroyThread(&sp44->thread);

    StageLoader_WaitForRetrace();

    main_pool_pop_state('PCHK');

    FRAGMENT_LOAD_AND_CALL2(fragment23, 4, 0);

    return 0x25;
}
