#include "minigame_select.h"
#include "src/geo_render.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/input.h"
extern Gfx D_8006F518[];
extern Gfx D_8006F630[];
void Ui_DrawGradientPanel(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGB8* arg4, Color_RGB8* arg5);
extern void Ui_DrawTextureMarker();
#include "src/save_data.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/audio_loop_point.h"
#include "src/gfx_buffer.h"
#include "src/matrix.h"
#include "src/controller.h"
#include "src/fragments/widget_toolkit/widget_toolkit.h"
#include "src/geo_layout.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_8250A2A0 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
} unk_D_8250A2A0; // size >= 0x10

static u16 D_82508AF0;
static s32 D_82508AF4;
static unk_D_82508B00* D_82508AF8;
static unk_D_82508B00 D_82508B00[4];
static unk_D_82508B30 D_82508B30[14];
static unk_D_8250A228* D_8250A228[2];
static unk_D_8250A228* D_8250A230[2];
static unk_D_8250A228* D_8250A238;
static unk_D_8250A228* D_8250A240[9];
static BinArchive* D_8250A264;
static void* D_8250A268;
static s16 D_8250A26C;
static s16 D_8250A26E;
static GraphNode* D_8250A270;
static GraphNode* D_8250A274;
static GraphNode* D_8250A278;
static GraphNode* D_8250A27C;
static GraphNode* D_8250A280;
static GraphNode* D_8250A284;
static unk_D_8250A288 D_8250A288;
static s16 D_8250A292;
static s16 D_8250A294;
static s16 D_8250A296;
static s16 D_8250A298;
static unk_D_8250A2A0 D_8250A2A0;
static s32 pad_D_8250A2B0[18];
static s32 pad_D_8250A2F8;
static s16 D_8250A2FC;
static s16 D_8250A2FE;
static s16 D_8250A300;
FontContext* D_8250A304;
static unk_D_8250A308 D_8250A308;
static char** D_8250A47C;

static Vtx D_825061B0[] = {
    VTX(0, 40, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 36, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 36, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 40, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

static Vtx D_825061F0[] = {
    VTX(0, 36, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 32, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 32, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 36, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

static Vtx D_82506230[] = {
    VTX(0, 32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 28, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 28, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 32, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82506270[] = {
    VTX(0, 28, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 24, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 24, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 28, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825062B0[] = {
    VTX(0, 24, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 20, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 20, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 24, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825062F0[] = {
    VTX(0, 20, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 16, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 16, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 20, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82506330[] = {
    VTX(0, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 12, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 12, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 16, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82506370[] = {
    VTX(0, 12, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 8, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 8, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 12, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825063B0[] = {
    VTX(0, 8, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 4, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 4, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 8, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825063F0[] = {
    VTX(0, 4, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 0, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 0, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 4, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82506430[] = {
    VTX(0, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -4, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -4, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 0, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82506470[] = {
    VTX(0, -4, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -8, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -8, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -4, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825064B0[] = {
    VTX(0, -8, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -12, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -12, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -8, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825064F0[] = {
    VTX(0, -12, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -16, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -16, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -12, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82506530[] = {
    VTX(0, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -20, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -20, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -16, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82506570[] = {
    VTX(0, -20, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -24, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -24, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -20, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825065B0[] = {
    VTX(0, -24, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -28, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -28, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -24, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825065F0[] = {
    VTX(0, -28, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -32, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -32, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -28, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82506630[] = {
    VTX(0, -32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -36, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -36, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -32, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82506670[] = {
    VTX(0, -36, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -40, 0, 0, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -40, 0, 9600, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -36, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825066B0[] = {
    VTX(130, 35, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(130, 25, 0, 0, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(290, 25, 0, 5120, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(290, 35, 0, 5120, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825066F0[] = {
    VTX(130, 25, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(130, 15, 0, 0, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(290, 15, 0, 5120, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(290, 25, 0, 5120, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82506730[] = {
    VTX(130, 15, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(130, 5, 0, 0, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(290, 5, 0, 5120, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(290, 15, 0, 5120, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82506770[] = {
    VTX(130, 5, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(130, -5, 0, 0, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(290, -5, 0, 5120, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(290, 5, 0, 5120, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825067B0[] = {
    VTX(130, -5, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(130, -15, 0, 0, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(290, -15, 0, 5120, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(290, -5, 0, 5120, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825067F0[] = {
    VTX(130, -15, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(130, -25, 0, 0, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(290, -25, 0, 5120, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(290, -15, 0, 5120, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82506830[] = {
    VTX(130, -25, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(130, -35, 0, 0, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(290, -35, 0, 5120, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(290, -25, 0, 5120, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82506870[] = {
    VTX(150, 35, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(150, 25, 0, 0, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(260, 25, 0, 3520, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(260, 35, 0, 3520, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825068B0[] = {
    VTX(150, 25, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(150, 15, 0, 0, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(260, 15, 0, 3520, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(260, 25, 0, 3520, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825068F0[] = {
    VTX(150, 15, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(150, 5, 0, 0, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(260, 5, 0, 3520, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(260, 15, 0, 3520, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82506930[] = {
    VTX(150, 5, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(150, -5, 0, 0, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(260, -5, 0, 3520, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(260, 5, 0, 3520, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82506970[] = {
    VTX(150, -5, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(150, -15, 0, 0, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(260, -15, 0, 3520, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(260, -5, 0, 3520, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825069B0[] = {
    VTX(150, -15, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(150, -25, 0, 0, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(260, -25, 0, 3520, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(260, -15, 0, 3520, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825069F0[] = {
    VTX(150, -25, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(150, -35, 0, 0, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(260, -35, 0, 3520, 320, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(260, -25, 0, 3520, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

static Gfx D_82506A30[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825061B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000960, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825061F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F0012C0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506230, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F001C20, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506270, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F002580, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825062B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F002EE0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825062F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F003840, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506330, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F0041A0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506370, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F004B00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825063B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F005460, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825063F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F005DC0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506430, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F006720, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506470, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F007080, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825064B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F0079E0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825064F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F008340, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506530, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F008CA0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506570, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F009600, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825065B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F009F60, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825065F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F00A8C0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506630, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F00B220, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506670, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static Gfx D_82506FF0[] = {
    gsDPLoadTextureTile(0x0E000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 0, 159, 9, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825066B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0E000C80, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 0, 159, 9, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825066F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0E001900, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 0, 159, 9, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506730, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0E002580, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 0, 159, 9, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506770, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0E003200, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 0, 159, 9, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825067B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0E003E80, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 0, 159, 9, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825067F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0E004B00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 0, 159, 9, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506830, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static Gfx D_825071F0[] = {
    gsDPLoadTextureTile(0x0E000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 110, 0, 0, 0, 109, 9, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506870, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0E000898, G_IM_FMT_RGBA, G_IM_SIZ_16b, 110, 0, 0, 0, 109, 9, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825068B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0E001130, G_IM_FMT_RGBA, G_IM_SIZ_16b, 110, 0, 0, 0, 109, 9, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825068F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0E0019C8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 110, 0, 0, 0, 109, 9, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506930, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0E002260, G_IM_FMT_RGBA, G_IM_SIZ_16b, 110, 0, 0, 0, 109, 9, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82506970, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0E002AF8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 110, 0, 0, 0, 109, 9, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825069B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0E003390, G_IM_FMT_RGBA, G_IM_SIZ_16b, 110, 0, 0, 0, 109, 9, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825069F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

static u32 D_825073F0[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_825061B0, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, MiniGameSelect_DrawMenuBackdrop, 0x00000000, 0x06000000, 0x01000000, 0x00000000,
};

static Vtx D_82507428[] = {
    VTX(0, 40, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 35, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 35, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 40, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82507468[] = {
    VTX(0, 35, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 30, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 30, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 35, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825074A8[] = {
    VTX(0, 30, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 25, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 25, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 30, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825074E8[] = {
    VTX(0, 25, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 20, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 20, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 25, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82507528[] = {
    VTX(0, 20, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 15, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 15, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 20, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82507568[] = {
    VTX(0, 15, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 10, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 10, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 15, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825075A8[] = {
    VTX(0, 10, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 5, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 5, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 10, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825075E8[] = {
    VTX(0, 5, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 0, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 0, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 5, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82507628[] = {
    VTX(0, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -5, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -5, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 0, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82507668[] = {
    VTX(0, -5, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -10, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -10, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -5, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825076A8[] = {
    VTX(0, -10, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -15, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -15, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -10, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825076E8[] = {
    VTX(0, -15, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -20, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -20, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -15, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82507728[] = {
    VTX(0, -20, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -25, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -25, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -20, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82507768[] = {
    VTX(0, -25, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -30, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -30, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -25, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825077A8[] = {
    VTX(0, -30, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -35, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -35, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -30, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_825077E8[] = {
    VTX(0, -35, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -40, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -40, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -35, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

static Gfx D_82507828[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507428, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000BB8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507468, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F001770, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825074A8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F002328, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825074E8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F002EE0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507528, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F003A98, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507568, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F004650, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825075A8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F005208, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825075E8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F005DC0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507628, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F006978, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507668, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F007530, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825076A8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F0080E8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825076E8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F008CA0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507728, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F009858, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507768, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F00A410, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825077A8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F00AFC8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825077E8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

static u32 D_82507CC8[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82507428, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, MiniGameSelect_DrawGameBackdrop, 0x00000000, 0x06000000, 0x01000000, 0x00000000,
};

static Vtx D_82507D00[] = {
    VTX(0, 40, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),         VTX(0, 35, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 35, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(300, 40, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 35, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),         VTX(0, 30, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 30, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(300, 35, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 30, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),         VTX(0, 25, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 25, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(300, 30, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 25, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),         VTX(0, 20, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 20, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(300, 25, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 20, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),         VTX(0, 15, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 15, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(300, 20, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 15, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),         VTX(0, 10, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 10, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(300, 15, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 10, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),         VTX(0, 5, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 5, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(300, 10, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 5, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),          VTX(0, 0, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, 0, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(300, 5, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),          VTX(0, -5, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -5, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(300, 0, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -5, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),         VTX(0, -10, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -10, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF), VTX(300, -5, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -10, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),        VTX(0, -15, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -15, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF), VTX(300, -10, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -15, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),        VTX(0, -20, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -20, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF), VTX(300, -15, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -20, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),        VTX(0, -25, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -25, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF), VTX(300, -20, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -25, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),        VTX(0, -30, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -30, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF), VTX(300, -25, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -30, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),        VTX(0, -35, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -35, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF), VTX(300, -30, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -35, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),        VTX(0, -40, 0, 0, 160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(300, -40, 0, 9600, 160, 0xFF, 0xFF, 0xFF, 0xFF), VTX(300, -35, 0, 9600, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_82508100[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507428, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000BB8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507468, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F001770, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825074A8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F002328, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825074E8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F002EE0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507528, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F003A98, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507568, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F004650, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825075A8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F005208, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825075E8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F005DC0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507628, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F006978, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507668, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F007530, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825076A8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F0080E8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825076E8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F008CA0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507728, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F009858, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82507768, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F00A410, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825077A8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F00AFC8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_825077E8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_825085A0[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82507D00, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, MiniGameSelect_DrawStaticBackdrop, 0x00000000, 0x06000000, 0x01000000, 0x00000000,
};

static Vtx D_825085D8[][4] = {
    {
        VTX(-32, 32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
        VTX(-32, 16, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
        VTX(32, 16, 0, 2048, 512, 0xFF, 0xFF, 0xFF, 0xFF),
        VTX(32, 32, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    },
    {
        VTX(-32, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
        VTX(-32, 0, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
        VTX(32, 0, 0, 2048, 512, 0xFF, 0xFF, 0xFF, 0xFF),
        VTX(32, 16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    },
    {
        VTX(-32, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
        VTX(-32, -16, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
        VTX(32, -16, 0, 2048, 512, 0xFF, 0xFF, 0xFF, 0xFF),
        VTX(32, 0, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    },
    {
        VTX(-32, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
        VTX(-32, -32, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
        VTX(32, -32, 0, 2048, 512, 0xFF, 0xFF, 0xFF, 0xFF),
        VTX(32, -16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    },
};
static Gfx D_825086D8[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(TEXEL0, TEXEL1, PRIM_LOD_FRAC, TEXEL1, 0, 0, 0, TEXEL0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};
static u32 D_825086F8[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_825085D8, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, MiniGameSelect_DrawLabelStrips, 0x00000000, 0x06000000, 0x01000000, 0x00000000,
};

static Vtx D_82508730[] = {
    VTX(-32, 22, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 0, 0, 0, 704, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 0, 0, 1024, 704, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 22, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_82508770[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(0x010031D0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 22, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82508730, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_825087D8[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82508730, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, MiniGameSelect_CursorNodeCallback, 0x00000000, 0x06000000, 0x01000000,
};
static u32 D_8250880C[] = {
    0x0C000000,  0x05000000, 0x0B00002D, 0x00000000, 0x028001E0, 0x00000000, 0xFDBD0000,
    0x00000243,  0x05000000, 0x0D000000, 0x05000000, 0x0F000002, 0x05000000, 0x0A000000,
    &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};

static s32 gMiniGameSelectIdTable[] = { 1, 2, 3, 5, 6, 9, 0xD, 0xF, 0x10 };
static u8* D_82508880[] = {
    D_0302EE00, D_03034580, D_03039D00, D_0303F480, D_03044C00,
    D_0304A380, D_0304FB00, D_03055280, D_0305AA00, D_03060180,
};
static u8* D_825088A8[] = {
    D_03065900, D_03069528, D_0306D150, D_03070D78, D_030749A0,
    D_030785C8, D_0307C1F0, D_0307FE18, D_03083A40, D_03087668,
};
static s16 D_825088D0[] = { 2, 1, 0, 0 };
static s16 D_825088D8[] = { 3, 2, 1, 0 };
static s16 D_825088E0[] = { 4, 0, 1, 6, 3, 2, 7, 8, 5, 0 };
static s16 D_825088F4[] = { 2, 0, 1, 4, 5, 3, 8, 6, 7, 0, 0x8250, 0x8A20 };
static u8* D_8250890C[] = { D_0300BB80, D_03017700 };
static u8* D_82508914[9][4] = {
    D_0308B290, D_0308D290, D_0308F290, D_0308D290, D_03091290, D_03093290, D_03095290, D_03093290, D_03097290,
    D_03099290, D_0309B290, D_03099290, D_0309D290, D_0309F290, D_030A1290, D_0309F290, D_030A3290, D_030A5290,
    D_030A7290, D_030A5290, D_030A9290, D_030AB290, D_030AD290, D_030AB290, D_030AF290, D_030B1290, D_030B3290,
    D_030B1290, D_030B5290, D_030B7290, D_030B9290, D_030B7290, D_030BB290, D_030BD290, D_030BF290, D_030BD290,
};

s32 MiniGameSelect_DrawMenuBackdrop(s32 arg0, GraphNode* arg1) {
    s32 var_v0;
    s32 tmp;
    u32 var_a2;
    Gfx* var_a3;

    if (arg0 == 5) {
        tmp = D_8006F09C->node.callbackArg;
        var_v0 = 0;
        if ((tmp == D_8250A288.unk_00) && (D_8250A26C != 7)) {
            var_v0 = (D_82508AF4 % 30u) / 3;
        }

        if (tmp == 0) {
            var_a2 = D_82508880[var_v0];
            var_a3 = D_82506FF0;
        } else {
            var_a2 = D_825088A8[var_v0];
            var_a3 = D_825071F0;
        }

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, Memmap_GetSegmentVaddr(D_8250890C[tmp]));
        gSPSegment(gDisplayListHead++, 0x0E, Memmap_GetSegmentVaddr(var_a2));
        gSPDisplayList(gDisplayListHead++, D_82506A30);
        gSPDisplayList(gDisplayListHead++, var_a3);

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

s32 MiniGameSelect_DrawGameBackdrop(s32 arg0, GraphNode* arg1) {
    if (arg0 == 5) {
        s32 tmp = D_8006F09C->node.callbackArg;

        gDPPipeSync(gDisplayListHead++);

        if (tmp == 0) {
            gSPSegment(gDisplayListHead++, 0x0F, (u32)D_8250A230[tmp]->unk_38->img_p & 0x1FFFFFFF);
            gSPDisplayList(gDisplayListHead++, D_82507828);
        } else {
            u8* var_a2;
            s32 temp_lo = (D_82508AF4 % 30u) / 3;
            Gfx* var_a3;

            if (D_8250A230[1]->unk_0A == 0) {
                var_a2 = D_82508880[temp_lo];
                var_a3 = D_82506FF0;
            } else {
                var_a2 = D_825088A8[temp_lo];
                var_a3 = D_825071F0;
            }

            gSPSegment(gDisplayListHead++, 0x0F, Memmap_GetSegmentVaddr(D_3023280));
            gSPSegment(gDisplayListHead++, 0x0E, Memmap_GetSegmentVaddr(var_a2));
            gSPDisplayList(gDisplayListHead++, D_82507828);
            gSPDisplayList(gDisplayListHead++, var_a3);
        }
        GeoRender_ApplyMaterialState();
    }

    return 0;
}

s32 MiniGameSelect_DrawStaticBackdrop(s32 arg0, GraphNode* arg1) {
    if (arg0 == 5) {
        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)D_8250A238->unk_38->img_p & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, D_82508100);

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

s32 MiniGameSelect_DrawLabelStrips(s32 arg0, GraphNode* arg1) {
    UNUSED s32 pad;
    s32 var_a0;
    u32 var_a2;
    s32 i;
    void* ptr1;
    void* ptr2;
    s32 idx;
    s32 idx2;
    s32 idx3;

    if (arg0 == 5) {
        idx = D_8006F09C->node.callbackArg;

        idx2 = D_8250A240[idx]->unk_0A;
        idx3 = D_8250A240[idx]->unk_0C;

        var_a0 = 0;

        if ((D_8250A288.unk_06 == idx2) && (D_8250A26C == 5)) {
            var_a0 = 1;
        }

        if (var_a0 != 0) {
            var_a2 = (D_82508AF4 % 12u) / 3;
        } else {
            var_a2 = 0;
        }

        ptr1 = D_82508914[idx2][var_a2];
        ptr2 = D_82508914[idx3][var_a2];

        gSPSegment(gDisplayListHead++, 0x0F, Memmap_GetSegmentVaddr(ptr1));
        gSPSegment(gDisplayListHead++, 0x0E, Memmap_GetSegmentVaddr(ptr2));
        gSPDisplayList(gDisplayListHead++, D_825086D8);

        for (i = 0; i < 4; i++) {
            gDPPipeSync(gDisplayListHead++);

            var_a2 = i * 0x800;

            gDPSetPrimColor(gDisplayListHead++, 0, D_8250A240[idx]->unk_0E[i], 0, 0, 0, 255);
            gDPLoadTextureBlock(gDisplayListHead++, 0x0F000000 + var_a2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 16, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gDPLoadMultiBlock(gDisplayListHead++, 0x0E000000 + var_a2, 0x0100, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 16,
                              0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                              G_TX_NOLOD, G_TX_NOLOD);
            gSPVertex(gDisplayListHead++, &D_825085D8[i], 4, 0);
            gSP2Triangles(gDisplayListHead++, 0, 1, 2, 0, 0, 2, 3, 0);
        }

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

void MiniGameSelect_CreateCursor(void) {
    DisplayNodeHeader* ptr = &D_8250A308.unk_000.node;

    D_8250A308.unk_16C = 0;
    D_8250A308.unk_168 = 0;
    D_8250A308.unk_16A = 0;
    D_8250A308.unk_16E = 0;
    D_8250A308.unk_170 = 0;
    ModelRenderer_AttachDisplayObject(&D_8250A308.unk_000);
    Vec3f_SetComponentsDuplicate(&D_8250A308.unk_000.position, -220.0f, 140.0f, -579.0f);
    Model_InitDisplayObject(&D_8250A308.unk_000, 0, 0, D_8250A284);
    ptr->flags &= ~1;
}

void MiniGameSelect_UpdateCursor(DisplayObject* a0) {
    unk_D_8250A308* arg0 = (unk_D_8250A308*)a0;
    s32 var_v0;

    arg0->unk_16E = 0;
    arg0->unk_170 = 0;

    switch (D_8250A26C) {
        case 1:
            if (MiniGameSelect_IsWidgetInState(D_8250A228[0], 2) != 0) {
                arg0->unk_16E = 1;
                arg0->unk_168 = 0x8C;
                arg0->unk_16A = (D_8250A288.unk_00 * 0x58) + 0xBA;
                break;
            }
            break;

        case 2:
            if (MiniGameSelect_IsWidgetInState(D_8250A230[0], 2) != 0) {
                arg0->unk_16E = 1;
                arg0->unk_168 = 0x96;
                arg0->unk_16A = (D_8250A288.unk_02 * 0x62) + 0xBA;
            }
            break;

        case 3:
            if (MiniGameSelect_IsWidgetInState(D_8250A238, 2) != 0) {
                arg0->unk_16E = 1;
                arg0->unk_168 = 0xE4;
                arg0->unk_16A = 0xDA;
            }
            break;

        case 4:
            if (D_8250A2A0.unk_00 == 2) {
                arg0->unk_16E = 1;
                arg0->unk_168 = 0xF0;
                if (D_82508AF0 & 1) {
                    var_v0 = 0x36;
                } else {
                    var_v0 = 0x48;
                }
                arg0->unk_16A = var_v0 + 0xA4 + (D_8250A288.unk_08 * 0x18);
            }
            break;

        case 5:
            if ((MiniGameSelect_IsWidgetInState(D_8250A240[0], 2) != 0) && (D_8780FA48 != -1)) {
                arg0->unk_16E = 1;
                arg0->unk_170 = 1;
                arg0->unk_168 = ((D_8250A288.unk_06 % 3) * 0x60) + 0xA5;
                arg0->unk_16A = ((D_8250A288.unk_06 / 3) * 0x60) + 0xAA;
            }
            break;
    }

    if (arg0->unk_16E != 0) {
        f32 tmp1;
        f32 tmp2;

        a0->rotation.z = ((SINS(arg0->unk_16C) * 0.5f) + 0.5f) * -8192.0f;

        tmp1 = (((SINS(arg0->unk_16C) * 0.5f) + 0.5f) * 6.0f) + arg0->unk_168 + 32.0f;
        tmp2 = arg0->unk_16A + 22.0f;

        a0->position.x = tmp1 - 320.0f;
        a0->position.y = 240.0f - tmp2;
        a0->lodFraction = 0xFF;
    } else {
        a0->lodFraction = 0;
    }
    arg0->unk_16C += 0x1000;
}

s32 MiniGameSelect_CursorNodeCallback(s32 arg0, GraphNode* arg1) {
    switch (arg0) {
        case 0:
            break;

        case 2:
            MiniGameSelect_UpdateCursor(D_8006F09C);
            break;

        case 5:
            gDPPipeSync(gDisplayListHead++);
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_8006F09C->lodFraction);
            gSPDisplayList(gDisplayListHead++, D_82508770);

            GeoRender_ApplyMaterialState();
            break;
    }
    return 0;
}

void MiniGameSelect_ResetInputStates(void) {
    s32 i;
    unk_D_82508B00* ptr = &D_82508B00[0];

    for (i = 0; i < 4; i++, ptr++) {
        ptr->unk_00 = 0;
        ptr->unk_02 = 0;
        ptr->unk_04 = 0;
        ptr->unk_06 = 0;
        ptr->unk_08 = 0;
        ptr->unk_0A = 0xA;
    }
}

void MiniGameSelect_ReadInputsWithRepeat(void) {
    Controller* var_a0;
    unk_D_82508B00* var_v1;
    s32 i;
    u16 tmp;

    for (i = 0, var_v1 = &D_82508B00[0], var_a0 = &gControllers[0]; i < 4; i++, var_a0++, var_v1++) {
        var_v1->unk_00 = var_v1->unk_02;

        if (var_a0->rawStickX < -0x32) {
            var_v1->unk_02 = 0x200;
        } else if (var_a0->rawStickX > 0x32) {
            var_v1->unk_02 = 0x100;
        } else {
            var_v1->unk_02 = 0;
        }

        if (var_a0->rawStickY < -0x32) {
            var_v1->unk_02 |= 0x400;
        } else if (var_a0->rawStickY > 0x32) {
            var_v1->unk_02 |= 0x800;
        }

        tmp = var_v1->unk_00 ^ var_v1->unk_02;
        var_v1->unk_04 = tmp & var_v1->unk_02;
        var_v1->unk_06 = tmp & var_v1->unk_00;
        var_v1->unk_02 |= var_a0->buttonDown;
        var_v1->unk_04 |= var_a0->buttonPressed;
        var_v1->unk_08 = 0;

        if (var_v1->unk_04 & 0x800) {
            var_v1->unk_0A = 0xA;
            var_v1->unk_08 = 0x800;
        } else if (var_v1->unk_04 & 0x400) {
            var_v1->unk_0A = 0xA;
            var_v1->unk_08 = 0x400;
        } else if (var_v1->unk_04 & 0x200) {
            var_v1->unk_0A = 0xA;
            var_v1->unk_08 = 0x200;
        } else if (var_v1->unk_04 & 0x100) {
            var_v1->unk_0A = 0xA;
            var_v1->unk_08 = 0x100;
        } else {
            var_v1->unk_0A--;
            if (var_v1->unk_0A <= 0) {
                var_v1->unk_0A = 0;
                if (var_v1->unk_02 & 0x800) {
                    var_v1->unk_0A = 2;
                    var_v1->unk_08 = 0x800;
                } else if (var_v1->unk_02 & 0x400) {
                    var_v1->unk_0A = 2;
                    var_v1->unk_08 = 0x400;
                } else if (var_v1->unk_02 & 0x200) {
                    var_v1->unk_0A = 2;
                    var_v1->unk_08 = 0x200;
                } else if (var_v1->unk_02 & 0x100) {
                    var_v1->unk_0A = 2;
                    var_v1->unk_08 = 0x100;
                }
            }
        }
    }
}

void MiniGameSelect_PollInputs(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
    MiniGameSelect_ReadInputsWithRepeat();
}

s32 MiniGameSelect_ResolveGameID(void) {
    s32 sp1C;

    if ((D_8250A288.unk_06 >= 0) && (D_8250A288.unk_06 < 9)) {
        sp1C = gMiniGameSelectIdTable[D_8250A288.unk_06];
    } else {
        sp1C = 0;
    }

    if (sp1C != 0) {
        KidsClub_SetSelectedGameId(sp1C);
    } else {
        KidsClub_SetSelectedGameId(-1);
    }
    return sp1C;
}

s32 MiniGameSelect_GameIDToIndex(s32 arg0) {
    s32 ret = 0;
    s32 i;

    for (i = 0; i < 9; i++) {
        if (arg0 == gMiniGameSelectIdTable[i]) {
            ret = i;
            break;
        }
    }

    return ret;
}

s32 MiniGameSelect_FindTableIndex(s16 arg0, s32 arg1) {
    s16* var_a0;
    s32 var_v0;
    s32 ret = 0;
    s32 i;

    if (arg1 != 0) {
        var_v0 = 4;
        var_a0 = D_825088D8;
    } else {
        var_v0 = 3;
        var_a0 = D_825088D0;
    }

    for (i = 0; i < var_v0; i++) {
        if (arg0 == var_a0[i]) {
            ret = i;
            break;
        }
    }

    return ret;
}

void MiniGameSelect_ResetAttractShuffle(void) {
    D_8250A296 = 0x78;
    D_8250A298 = Rand_Range(3);
}

void MiniGameSelect_ClearWidgetSlot(unk_D_82508B30* arg0) {
    arg0->unk_00C = 0;
    arg0->unk_000 = 0;
    arg0->unk_002 = 0;
    arg0->unk_004 = 0;
    arg0->unk_006 = 0;
    arg0->unk_008 = 0;
    arg0->unk_00E[0] = 0;
    arg0->unk_00E[1] = 0;
    arg0->unk_00E[2] = 0;
    arg0->unk_00E[3] = 0;
    arg0->unk_034 = 0;
    arg0->unk_030 = NULL;
    arg0->unk_02C = NULL;
    arg0->unk_038 = 0;
    arg0->unk_00A = arg0->unk_00C;
}

void MiniGameSelect_RenderPlayerPanel(unk_D_82508B30* arg0) {
    static s16 D_825089A4 = 0;
    static s16 D_825089A8 = 0x3200;

    u8* var_s2;
    f32 temp_fs3 = (SINS(D_825089A4) * 0.2f) + 1.0f;
    f32 temp_fs4 = (SINS(D_825089A4 + D_825089A8) * 0.2f) + 1.0f;
    s16 temp_fa0;
    s16 temp_fv1;
    s32 i;

    D_825089A4 += 0x2000;

    GfxImage_SetRenderTarget(&gDisplayListHead, arg0->unk_038);
    GfxImage_FillCurrent(&gDisplayListHead, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetBlendColor(gDisplayListHead++, 255, 255, 255, 128);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);

    var_s2 = D_30C1290;
    for (i = 0; i < 16; i++) {
        gDPLoadTextureTile(gDisplayListHead++, var_s2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                           G_TX_NOLOD);

        Gfx_DrawTexturedRectClipped(0, i * 5, 0x12C, 5, 0, 0, 0x400, 0x400, 0);
        var_s2 += 0xBB8;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 4; i++) {
        if (D_8780FA30[i] == 0) {
            temp_fv1 = ROUND_MAX((temp_fs3 - 1.0f) * 36.0f * 0.5f);
            temp_fa0 = ROUND_MAX((temp_fs4 - 1.0f) * 26.0f * 0.5f);

            Widget_DrawPlayerIconScaled(i, ((i * 0x48) - temp_fv1) + 0x1A, 0x1A - temp_fa0, temp_fs3, temp_fs4);
        } else {
            Widget_DrawPlayerIcon(-5, (i * 0x48) + 0x1A, 0x1A, 1.0f);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

static const char D_82508A20[] = "コンピュータのつよさ";

void MiniGameSelect_RenderNumberSpinner(unk_D_82508B30* arg0) {
    s32 var_v1;
    u8* var_s2;
    s16 temp_v0;
    s16 sp90[3];
    s32 i;

    GfxImage_SetRenderTarget(&gDisplayListHead, arg0->unk_038);
    GfxImage_FillCurrent(&gDisplayListHead, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetBlendColor(gDisplayListHead++, 255, 255, 255, 128);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);

    var_s2 = D_3000000;
    for (i = 0; i < 16; i++) {
        gDPLoadTextureTile(gDisplayListHead++, var_s2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 300, 0, 0, 0, 299, 4, 0,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                           G_TX_NOLOD);

        Gfx_DrawTexturedRectClipped(0, i * 5, 0x12C, 5, 0, 0, 0x400, 0x400, 0);
        var_s2 += 0xBB8;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    if ((D_8250A2FC == 1) || (D_8250A2FC == 2)) {
        var_v1 = D_8250A288.unk_04 - 1;
        for (i = 0; i < 3; i++) {
            temp_v0 = var_v1++;
            if ((temp_v0 <= 0) || (temp_v0 >= 0xA)) {
                temp_v0 = -1;
            }
            sp90[i] = temp_v0;
        }
    } else {
        for (i = 0; i < 3; i++) {
            sp90[i] = -1;
        }
        sp90[1] = D_8250A288.unk_04;
    }

    Gfx_SetScissorRect(&gDisplayListHead, 0x6E, 0xE, 0x1C, 0x1A);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);

    for (i = 0; i < 3; i++) {
        if (sp90[i] == -1) {
            continue;
        }
        Font_Printf(0x76, (D_8250A300 - (i * 0x1A)) + 0x28, "%d", sp90[i]);
    }

    Font_EndTexturedTextRendering();
}

unk_D_8250A228* MiniGameSelect_FindFreeWidgetSlot(void) {
    s32 i;
    unk_D_82508B30* var_v1 = D_82508B30;

    for (i = 0; i < 14; i++, var_v1++) {
        if (var_v1->unk_000 == 0) {
            break;
        }
    }

    if (i == 0xE) {
        var_v1 = NULL;
    }
    return var_v1;
}

unk_D_8250A228* MiniGameSelect_CreateMenuWidget(s16 arg0, s16 arg1, GraphNode* arg2) {
    unk_D_8250A228* temp_v0 = MiniGameSelect_FindFreeWidgetSlot();
    unk_D_82508B30_03C* temp_s1;

    if (temp_v0 == NULL) {
        return NULL;
    }

    temp_s1 = &temp_v0->unk_3C;

    temp_v0->unk_00 = arg0;
    temp_v0->unk_02 = 0;
    temp_v0->unk_04 = arg1;
    ModelRenderer_AttachDisplayObject(temp_s1);
    temp_s1->unk_1E = -0x4000;
    Model_InitDisplayObject(temp_s1, 0, 0, arg2);
    temp_s1->unk_01 &= ~1;

    switch (temp_v0->unk_00) {
        case 1:
            temp_v0->unk_38 = NULL;
            Vec3f_SetComponentsDuplicate(&temp_s1->unk_24, -150.0f, 240.0f - ((arg1 * 88.0f) + 196.0f), -579.0f);
            temp_s1->unk_14 = arg1;
            break;

        case 2:
            if (arg1 == 0) {
                temp_v0->unk_38 = GfxImage_Allocate(0, 2, 0x12C, 0x50, 1);
                temp_v0->unk_06 |= 1;
            } else {
                temp_v0->unk_38 = NULL;
            }
            Vec3f_SetComponentsDuplicate(&temp_s1->unk_24, -150.0f, 240.0f - ((arg1 * 98.0f) + 190.0f), -579.0f);
            temp_s1->unk_14 = arg1;
            break;

        case 3:
            temp_v0->unk_38 = GfxImage_Allocate(0, 2, 0x12C, 0x50, 1);
            temp_v0->unk_06 |= 1;
            Vec3f_SetComponentsDuplicate(&temp_s1->unk_24, -150.0f, 0.0f, -579.0f);
            break;

        case 4:
            temp_v0->unk_38 = NULL;
            temp_v0->unk_0C = temp_v0->unk_04;
            temp_v0->unk_0A = temp_v0->unk_04;
            Vec3f_SetComponentsDuplicate(&temp_s1->unk_24, (((arg1 % 3) * 96.0f) + 224.0f) - 320.0f,
                          240.0f - (((arg1 / 3) * 96.0f) + 156.0f), -579.0f);
            temp_s1->unk_14 = arg1;
            temp_s1->unk_30.x = temp_s1->unk_30.y = temp_s1->unk_30.z = 1.2f;
            break;
    }
    return temp_v0;
}

void MiniGameSelect_LinkWidgets(unk_D_8250A228* arg0, unk_D_8250A228* arg1) {
    if (arg0 != NULL) {
        arg0->unk_30 = arg1;
    }

    if (arg1 != NULL) {
        arg1->unk_2C = arg0;
    }
}

void MiniGameSelect_ChainWidget(unk_D_8250A228* arg0, unk_D_8250A228* arg1) {
    if (arg0 != NULL) {
        arg0->unk_34 = arg1;
    }
}

void func_82501B18(unk_D_8250A228* arg0, s16 arg1) {
    s32 var_v0;
    s32 i;

    arg0->unk_02 = arg1;
    if ((arg0 == NULL) || (arg0->unk_00 == 0)) {
        return;
    }

    var_v0 = 0;

    switch (arg0->unk_02) {
        case 1:
            arg0->unk_06 |= 1;
            arg0->unk_08 = 0xA;
            arg0->unk_3C.unk_01 |= 1;

            arg0->unk_0E[0] = 0xFF;
            arg0->unk_0E[1] = 0xFF;
            arg0->unk_0E[2] = 0xFF;
            arg0->unk_0E[3] = 0xFF;

            if (arg0->unk_34 != NULL) {
                var_v0 = 1;
            }

            if ((arg0->unk_00 == 4) && (D_8780FA48 == -1)) {
                arg0->unk_06 |= 2;
            }
            break;

        case 3:
            arg0->unk_08 = 0xA;
            if (arg0->unk_34 != NULL) {
                var_v0 = 1;
            }
            break;

        case 5:
            arg0->unk_08 = 0xA;
            arg0->unk_0C = D_8250A288.unk_06;

            for (i = 0; i < 4; i++) {
                arg0->unk_0E[i] = 0xFF;
            }

            if (arg0->unk_34 != NULL) {
                var_v0 = 1;
            }
            break;

        case 8:
            arg0->unk_08 = 0xA;
            if (arg0->unk_34 != NULL) {
                var_v0 = 1;
            }
            break;

        case 7:
            arg0->unk_08 = 0xA;
            if (arg0->unk_34 != NULL) {
                var_v0 = 1;
            }
            arg0->unk_3C.unk_01 |= 1;
            break;
    }

    if (var_v0 != 0) {
        func_82501B18(arg0->unk_34, arg0->unk_02);
    }
}


void MiniGameSelect_SetWidgetTargetState(unk_D_8250A228* arg0, s16 arg1, s32 arg2) {
    if (arg2 != 0) {
        if (arg0->unk_0A != arg0->unk_0C) {
            arg0->unk_0A = arg0->unk_0C;
        }
    }
    arg0->unk_08 = 6;
    arg0->unk_0C = arg1;
}

s32 MiniGameSelect_IsWidgetInState(unk_D_8250A228* arg0, s16 arg1) {
    s32 ret = 0;

    if (arg0 == NULL) {
        return 0;
    }

    if (arg0->unk_00 == 0) {
        return 0;
    }

    if (arg1 == arg0->unk_02) {
        ret = 1;
    }
    return ret;
}

void MiniGameSelect_UpdateWidgetFade(unk_D_82508B30* arg0) {
    s32 i;

    arg0->unk_008 -= 1;
    arg0->unk_00E[0] = (arg0->unk_008 * 0xFF) / 6;

    for (i = 1; i < 4; i++) {
        arg0->unk_00E[i] = arg0->unk_00E[0];
    }

    if (arg0->unk_008 <= 0) {
        arg0->unk_00A = arg0->unk_00C;
    }
}

s32 MiniGameSelect_CountWidgetChannels(unk_D_8250A228* arg0, s16 arg1) {
    s32 var_v1 = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (arg0->unk_0E[i] == arg1) {
            var_v1++;
        }
    }

    return var_v1;
}

s32 MiniGameSelect_StaggerWidgetFade(unk_D_82508B30* arg0) {
    s16 var_v0;
    s32 var_a1;
    s32 var_v1;
    s32 i;

    if (arg0->unk_008 >= -0x10) {
        arg0->unk_008--;
    }

    for (i = 0; i < 4; i++) {
        if (arg0->unk_004 & 1) {
            var_a1 = 3 - i;
        } else {
            var_a1 = i;
        }

        var_v0 = arg0->unk_008 + (i * 4);
        if (var_v0 < 0) {
            var_v0 = 0;
        }

        if (var_v0 >= 0xB) {
            var_v0 = 0xA;
        }

        arg0->unk_00E[var_a1] = (var_v0 * 0xFF) / 10;
    }

    if (MiniGameSelect_CountWidgetChannels(arg0, 0) >= 2) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }

    return var_v1;
}

void MiniGameSelect_UpdateWidgets(void) {
    UNUSED s32 pad;
    s32 i;
    f32 temp_fa1;
    unk_D_82508B30* var_s0 = &D_82508B30;
    unk_D_82508B30_03C* temp_v0;

    for (i = 0; i < 14; i++, var_s0++) {
        temp_v0 = &var_s0->unk_03C;

        if (var_s0->unk_000 == 0) {
            continue;
        }

        switch (var_s0->unk_002) {
            case 0:
                break;

            case 1:
                var_s0->unk_008--;
                temp_v0->unk_1E = (((0xA - var_s0->unk_008) << 0xE) / 10) - 0x4000;
                if (var_s0->unk_008 <= 0) {
                    temp_v0->unk_1E = 0;
                    var_s0->unk_002 = 2;
                    var_s0->unk_008 = 0;
                }
                break;

            case 2:
                if ((var_s0->unk_006 & 2) && (var_s0->unk_00A != var_s0->unk_00C)) {
                    MiniGameSelect_UpdateWidgetFade(var_s0);
                }
                break;

            case 3:
                var_s0->unk_008--;
                temp_v0->unk_1E = ((0xA - var_s0->unk_008) << 0xE) / 10;
                if (var_s0->unk_008 <= 0) {
                    var_s0->unk_002 = 4;
                    var_s0->unk_008 = 0;
                    temp_v0->unk_1E = 0x4000;
                    temp_v0->unk_01 &= ~1;
                    if (var_s0->unk_030 != NULL) {
                        func_82501B18(var_s0->unk_030, 1);
                    }
                }
                break;

            case 5:
                if (MiniGameSelect_StaggerWidgetFade(var_s0) != 0) {
                    Vec3f sp58[] = {
                        { -1.0f, 1.0f, -1.0f }, { 0.0f, 1.0f, -1.0f }, { 1.0f, 1.0f, -1.0f },
                        { -1.0f, 0.0f, 0.0f },  { 0.0f, 0.0f, 1.0f },  { 1.0f, 0.0f, 0.0f },
                        { -1.0f, -1.0f, 1.0f }, { 0.0f, -1.0f, 1.0f }, { 1.0f, -1.0f, 1.0f },
                    };

                    var_s0->unk_002 = 6;
                    var_s0->unk_018 = 5.0f;
                    var_s0->unk_01C = 10.0f;
                    var_s0->unk_020 = sp58[var_s0->unk_004];

                    temp_fa1 = SQ(var_s0->unk_020.x) + SQ(var_s0->unk_020.y) + SQ(var_s0->unk_020.z);
                    if (temp_fa1 > 0.001f) {
                        temp_fa1 = 1.0f / sqrtf(temp_fa1);
                        var_s0->unk_020.x *= temp_fa1;
                        var_s0->unk_020.y *= temp_fa1;
                        var_s0->unk_020.z *= temp_fa1;
                    }
                }
                break;

            case 6:
                MiniGameSelect_StaggerWidgetFade(var_s0);
                var_s0->unk_018 -= 0.5f;
                if (var_s0->unk_018 < 0.0f) {
                    var_s0->unk_018 = 0.0f;
                }

                var_s0->unk_01C += var_s0->unk_018;
                temp_v0->unk_24.x += (var_s0->unk_020.x * var_s0->unk_01C);
                temp_v0->unk_24.y += (var_s0->unk_020.y * var_s0->unk_01C);
                temp_v0->unk_24.z += (var_s0->unk_020.z * var_s0->unk_01C);

                if ((var_s0->unk_004 & 0xFFFFFFFF) != 4) {
                    if (var_s0->unk_004 & 1) {
                        temp_v0->unk_22 += 0x1400;
                    } else {
                        temp_v0->unk_22 -= 0x1400;
                    }
                    temp_v0->unk_1E += 0x1000;
                    temp_v0->unk_20 += 0x1000;
                } else {
                    temp_v0->unk_30.x += 0.05f;
                    temp_v0->unk_30.y = temp_v0->unk_30.z = temp_v0->unk_30.x;
                }
                break;

            case 8:
                var_s0->unk_008--;
                temp_v0->unk_1E = ((0xA - var_s0->unk_008) * -0x4000) / 10;
                if (var_s0->unk_008 <= 0) {
                    temp_v0->unk_1E = -0x4000;
                    var_s0->unk_002 = 0;
                    var_s0->unk_008 = 0;
                    temp_v0->unk_01 &= ~1;
                    if (var_s0->unk_02C != NULL) {
                        func_82501B18(var_s0->unk_02C, 7);
                    }
                }
                break;

            case 7:
                var_s0->unk_008--;
                temp_v0->unk_1E = 0x4000 - (((0xA - var_s0->unk_008) << 0xE) / 10);
                if (var_s0->unk_008 <= 0) {
                    var_s0->unk_002 = 2;
                    var_s0->unk_008 = 0;
                    temp_v0->unk_1E = 0;
                }

                break;
        }
    }
}

void MiniGameSelect_ClearOptionPanelState(void) {
    D_8250A2A0.unk_00 = 0;
    D_8250A2A0.unk_02 = 0;
    D_8250A2A0.unk_04 = 0;
    D_8250A2A0.unk_06 = 0;
    D_8250A2A0.unk_08 = 0;
    D_8250A2A0.unk_0A = 0;
    D_8250A2A0.unk_0C = 0;
    D_8250A2A0.unk_0E = 0;
}

void MiniGameSelect_ResetSelection(void) {
    D_8250A288.unk_00 = 0;
    D_8250A288.unk_02 = 0;
    D_8250A288.unk_04 = 3;
    D_8250A288.unk_06 = 0;

    if (D_82508AF0 & 1) {
        D_8250A288.unk_08 = 2;
    } else {
        D_8250A288.unk_08 = 1;
    }
}

void MiniGameSelect_LoadSavedSelection(s16 arg0, s16 arg1) {
    D_8250A288.unk_00 = D_8780FA2A;
    D_8250A288.unk_02 = arg0;
    D_8250A288.unk_04 = D_8780FA3A;
    D_8250A288.unk_06 = MiniGameSelect_GameIDToIndex(arg1);
    D_8250A288.unk_08 = MiniGameSelect_FindTableIndex(D_8780FA38, D_82508AF0 & 1);
}

void MiniGameSelect_InitMenuNodes(s16 arg0, s16 arg1) {
    s32 i;
    s32 j;
    unk_D_82508B30* ptr;

    D_8250A26E = arg0;
    if (arg1 == 0) {
        KidsClub_LoadDifficultySetting();
    }

    D_8250A26C = 0;
    D_82508AF0 = 0;
    if (D_8780FA28 & 1) {
        D_82508AF0 |= 1;
    }

    MiniGameSelect_ResetSelection();
    KidsClub_ResetTournamentState(D_8250A26E);
    D_8250A292 = -1;

    switch (D_8250A26E) {
        case 0:
            break;

        case 1:
            MiniGameSelect_LoadSavedSelection(0, arg1);
            if (D_8780FA30[D_8780FA48] == 0) {
                D_8250A292 = -1;
            } else {
                D_8250A292 = KidsClub_PickUnplayedGame();
                D_8250A294 = 0x1E;
            }
            break;

        case 4:
            MiniGameSelect_LoadSavedSelection(1, arg1);
            if (D_8780FA2A == 0) {
                D_8780FA48 = 0;
            } else {
                D_8780FA48 = -1;
                MiniGameSelect_ResetAttractShuffle();
            }

            // clang-format off
            for (i = 0; i < 9; i++) {                D_8780FA50[i] = 0;            }
            // clang-format on
            break;
    }

    ptr = D_82508B30;
    for (i = 0; i < 14; i++, ptr++) {
        MiniGameSelect_ClearWidgetSlot(ptr);
    }

    for (i = 0; i < 2; i++) {
        D_8250A228[i] = MiniGameSelect_CreateMenuWidget(1, i, D_8250A274);
    }

    for (i = 0; i < 2; i++) {
        D_8250A230[i] = MiniGameSelect_CreateMenuWidget(2, i, D_8250A278);
    }

    D_8250A238 = MiniGameSelect_CreateMenuWidget(3, 0, D_8250A27C);

    for (i = 0; i < 9; i++) {
        if (i != 4) {
            D_8250A240[i] = MiniGameSelect_CreateMenuWidget(4, i, D_8250A280);
        }
    }

    D_8250A240[4] = MiniGameSelect_CreateMenuWidget(4, 4, D_8250A280);
    MiniGameSelect_LinkWidgets(D_8250A228[0], D_8250A230[0]);

    for (i = 0; i < 1; i++) {
        MiniGameSelect_ChainWidget(D_8250A228[i], D_8250A228[i + 1]);
    }

    for (i = 0; i < 1; i++) {
        MiniGameSelect_ChainWidget(D_8250A230[i], D_8250A230[i + 1]);
    }

    for (i = 0; i < 8; i++) {
        MiniGameSelect_ChainWidget(D_8250A240[i], D_8250A240[i + 1]);
    }

    KidsClub_InitMatchBanner(D_8250A47C);
    KidsClub_InitRoundBanner(D_8250A47C);
    MiniGameSelect_ClearOptionPanelState();
    MiniGameSelect_CreateCursor();
}

void func_8250281C(void) {
    s32 sp44;
    s32 sp40;
    s32 ptr;
    s32 sp38;
    s32 tmp;
    u32 var_a2 = 0;
    s32 sp2C = 0;


    switch (D_8250A26C) {
        case 1:
            var_a2 = 0;
            if (MiniGameSelect_IsWidgetInState(D_8250A228[0], 2) != 0) {
                var_a2 = 1;
                sp40 = 0x8C;
                sp38 = (D_8250A288.unk_00 * 0x58) + 0xBA;
                break;
            }
            break;

        case 2:
            var_a2 = 0;
            if (MiniGameSelect_IsWidgetInState(D_8250A230[0], 2) != 0) {
                var_a2 = 1;
                sp40 = 0x96;
                sp38 = (D_8250A288.unk_02 * 0x62) + 0xBA;
                break;
            }
            break;

        case 3:
            var_a2 = 0;
            if (MiniGameSelect_IsWidgetInState(D_8250A238, 2) != 0) {
                var_a2 = 1;
                sp40 = 0xE4;
                sp38 = 0xDA;
                break;
            }
            break;

        case 4:
            if (D_8250A2A0.unk_00 == 2) {
                s16 var_v0;

                var_a2 = 1;
                sp40 = 0xDC;
                if (D_82508AF0 & 1) {
                    var_v0 = 0x36;
                } else {
                    var_v0 = 0x48;
                }
                sp38 = var_v0 + (D_8250A288.unk_08 * 0x18) + 0xA4;
                break;
            }
            break;

        case 5:
            var_a2 = 0;
            if ((MiniGameSelect_IsWidgetInState(D_8250A240[0], 2) != 0) && (D_8780FA48 != -1)) {
                var_a2 = 1;
                sp2C = 1;
                sp40 = ((D_8250A288.unk_06 % 3) * 0x60) + 0xA5;
                sp38 = ((D_8250A288.unk_06 / 3) * 0x60) + 0xAA;
                break;
            }
            break;
    }

    if (var_a2 != 0) {
        tmp = D_82508AF4 & 7;

        var_a2 = (tmp * 6) / 7u;
        if (D_82508AF4 & 8) {
            var_a2 = 6 - var_a2;
        }

        Ui_DrawTextureMarker(sp40 + var_a2, sp38, var_a2);

        if (sp2C != 0) {
            ptr = (s32)&D_8780FA48;

            if (*(s16*)ptr >= 0) {
            gSPDisplayList(gDisplayListHead++, D_8006F518);
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

            sp44 = *(s16*)ptr;
            if (D_8780FA30[sp44] == 0) {
                Widget_DrawPlayerIcon(sp44, (sp40 + var_a2) - 0x20, sp38 - 2, 1.0f);
            } else {
                Widget_DrawPlayerIcon(-1 - sp44, (sp40 + var_a2) - 0x20, sp38 - 2, 1.0f);
            }

            gSPDisplayList(gDisplayListHead++, D_8006F630);
        }
        }
    }
}

void MiniGameSelect_RenderDirtyPanels(void) {
    s32 i;
    unk_D_82508B30* var_s0 = D_82508B30;

    for (i = 0; i < 14; i++, var_s0++) {
        if (!(var_s0->unk_006 & 1)) {
            continue;
        }

        switch (var_s0->unk_000) {
            case 2:
                if (var_s0->unk_004 == 0) {
                    MiniGameSelect_RenderPlayerPanel(var_s0);
                }
                break;

            case 3:
                MiniGameSelect_RenderNumberSpinner(var_s0);
                break;
        }
        var_s0->unk_006 &= ~1;
    }
}

void MiniGameSelect_DrawOptionPanel(void) {
    char** var_v0;
    s32 i;
    s32 var_s5;
    Color_RGB8 sp80 = { 0, 0, 30 };
    Color_RGB8 sp7C = { 0, 0, 250 };
    s32 var_s4;
    char* sp6C[3];
    char* sp5C[4];

    sp6C[0] = Text_GetString(NULL, 0, D_8250A47C, 4);
    sp6C[1] = Text_GetString(NULL, 0, D_8250A47C, 5);
    sp6C[2] = Text_GetString(NULL, 0, D_8250A47C, 6);
    sp5C[0] = Text_GetString(NULL, 0, D_8250A47C, 3);
    sp5C[1] = Text_GetString(NULL, 0, D_8250A47C, 4);
    sp5C[2] = Text_GetString(NULL, 0, D_8250A47C, 5);
    sp5C[3] = Text_GetString(NULL, 0, D_8250A47C, 6);

    if (D_8250A2A0.unk_00 != 0) {
        Ui_DrawGradientPanel(D_8250A2A0.unk_08, D_8250A2A0.unk_0A, D_8250A2A0.unk_0C, D_8250A2A0.unk_0E, &sp80, &sp7C);
        if (D_8250A2A0.unk_00 == 2) {
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_Printf(0x140 - (Text_MeasureStringWidth(D_8250A304, Text_GetString(NULL, 0, D_8250A47C, 2)) / 2),
                          D_8250A2A0.unk_0A + 0x18, Text_GetString(NULL, 0, D_8250A47C, 2));

            if (D_82508AF0 & 1) {
                var_s4 = 4;
                var_s5 = 0x36;
                var_v0 = sp5C;
            } else {
                var_s4 = 3;
                var_s5 = 0x48;
                var_v0 = sp6C;
            }

            for (i = 0; i < var_s4; i++) {
                if (i != D_8250A288.unk_08) {
                    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
                } else {
                    Gfx_SetEnvColor(0xFF, 0xFF, 0, 0xFF);
                }
                Font_Printf(0x140 - (Text_MeasureStringWidth(D_8250A304, var_v0[i]) / 2),
                              D_8250A2A0.unk_0A + var_s5 + (i * 0x18), var_v0[i]);
            }

            Font_EndTexturedTextRendering();
        }
    }
}

void MiniGameSelect_DrawFrame(void) {
    MiniGameSelect_RenderDirtyPanels();
    BgStage_DrawFrame();
    Gfx_DrawTiledRgba16Image(D_8250A268);
    Geo_RenderRootNode(D_8250A270);
    KidsClub_DrawMatchBanner();
    KidsClub_DrawRoundBanner();
    MiniGameSelect_DrawOptionPanel();
    func_8250281C();
    BgStage_AdvanceFrame();
}

void MiniGameSelect_ReturnToIdle(void) {
    s16 tmp = D_8250A26C;
    s16 sp1C;
    s32 sp18;

    sp18 = 0;
    if (tmp == 0) {
        sp18 = 1;
    }

    D_8250A26C = 1;
    sp1C = D_8250A288.unk_00;
    MiniGameSelect_ResetSelection();

    if (sp18 == 0) {
        D_8250A288.unk_00 = sp1C;
    }
    D_8250A26E = 0;
    KidsClub_ResetTournamentState(D_8250A26E);
}

void MiniGameSelect_UpdateMainMenu(void) {
    s32 i;
    s32 tmp;

    if (MiniGameSelect_IsWidgetInState(D_8250A228[0], 2) == 0) {
        return;
    }

    Rand_Range(0x80);

    tmp = D_8250A288.unk_00;
    if (D_82508AF8->unk_04 & 0x800) {
        D_8250A288.unk_00--;
        if (D_8250A288.unk_00 < 0) {
            D_8250A288.unk_00 = 1;
        }
    }

    if (D_82508AF8->unk_04 & 0x400) {
        D_8250A288.unk_00++;
        if (D_8250A288.unk_00 >= 2) {
            D_8250A288.unk_00 = 0;
        }
    }

    if (tmp != D_8250A288.unk_00) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    if (D_82508AF8->unk_04 & 0x8000) {
        D_8780FA2A = D_8250A288.unk_00;
        D_8250A26C = 2;
        KidsClub_SetMatchBannerState(1);
        D_8250A288.unk_02 = 0;

        for (i = 0; i < 4; i++) {
            D_8780FA30[i] = 1;
        }

        D_8250A230[0]->unk_06 |= 1;
        if (D_8780FA2A == 0) {
            D_8780FA48 = 0;
            Audio_PlaySoundEffectById(0xB);
        } else {
            D_8780FA48 = -1;
            MiniGameSelect_ResetAttractShuffle();
            Audio_PlaySoundEffectById(0xC);
        }
        func_82501B18(D_8250A228[0], 3);
    } else if (D_82508AF8->unk_04 & 0x4000) {
        D_8250A26C = 7;
        D_8250A288.unk_06 = -1;
        StageContext_SetClearColor(1);
        StageFade_StartFromTransparent(0xF);
        Audio_FadeOutAll(0xF);
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    }
}

void MiniGameSelect_LeaveJoinMenu(void) {
    KidsClub_SetMatchBannerState(3);
    if (D_8250A288.unk_00 == 0) {
        D_8250A26C = 5;
        MiniGameSelect_LinkWidgets(D_8250A230[0], D_8250A240[0]);
        KidsClub_SetRoundBannerState(1, D_8250A288.unk_06);
    } else {
        D_8250A26C = 3;
        D_8250A2FC = 0;
        D_8250A2FE = 0;
        D_8250A300 = 0;
        MiniGameSelect_LinkWidgets(D_8250A230[0], D_8250A238);
        MiniGameSelect_LinkWidgets(D_8250A238, D_8250A240[0]);
    }
    func_82501B18(*D_8250A230, 3);
}

void MiniGameSelect_PlayerJoinUpdate(void) {
    s32 temp_a1;
    s32 var_v1;
    s32 var_s4;
    s32 i;

    D_8250A230[1]->unk_0A = D_8780FA2A;
    if ((MiniGameSelect_IsWidgetInState(D_8250A230[0], 2) != 0) && (KidsClub_GetMatchBannerState() == 2)) {
        var_v1 = D_8250A288.unk_02;
        if ((D_82508AF8->unk_04 & 0x800) && (D_8780FA30[0] == 0)) {
            D_8250A288.unk_02--;
            if (D_8250A288.unk_02 < 0) {
                D_8250A288.unk_02 = 1;
            }
        }

        if ((D_82508AF8->unk_04 & 0x400) && (D_8780FA30[0] == 0)) {
            D_8250A288.unk_02++;
            if (D_8250A288.unk_02 >= 2) {
                D_8250A288.unk_02 = 0;
            }
        }

        if (var_v1 != D_8250A288.unk_02) {
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        }

        var_s4 = 0;
        switch (D_8250A288.unk_02) {
            case 0:
                for (i = 0; i < 4; i++) {
                    if ((D_82508B00[i].unk_04 & 0x8000) && (D_8780FA30[i] != 0)) {
                        var_s4 = 1;
                        D_8780FA30[i] = 0;
                        Audio_PlaySoundEffectById(0xD);
                    } else if (D_82508B00[i].unk_04 & 0x4000) {
                        if (D_8780FA30[i] != 1) {
                            var_s4 = 1;
                            D_8780FA30[i] = 1;
                            Audio_PlaySoundEffectById(SFX_MENU_BACK);
                        }
                    }
                }
                break;

            case 1:
                if (D_82508AF8->unk_04 & 0x8000) {
                    var_s4 = 1;
                    D_8780FA2C = 0;

                    for (i = 0; i < 4; i++) {
                        if (D_8780FA30[i] == 0) {
                            D_8780FA2C++;
                        }
                    }

                    if (D_8780FA2C != 4) {
                        D_8250A26C = 4;
                    } else {
                        MiniGameSelect_LeaveJoinMenu();
                    }
                    Audio_PlaySoundEffectById(0xE);
                }
                break;
        }

        if ((var_s4 == 0) && (D_82508AF8->unk_04 & 0x4000)) {
            MiniGameSelect_ReturnToIdle();
            KidsClub_SetMatchBannerState(3);
            func_82501B18(D_8250A230[0], 8);
            Audio_PlaySoundEffectById(SFX_MENU_BACK);
        }

        if (D_8250A26C == 2) {
            D_8250A230[0]->unk_06 |= 1;
        }
    }
}

void MiniGameSelect_UpdateOptionPanel(void) {
    s32 var_a2;
    s32 var_v0;
    s32 tmp;

    switch (D_8250A2A0.unk_00) {
        case 0:
            D_8250A2A0.unk_00 = 1;
            D_8250A2A0.unk_02 = 0;
            D_8250A2A0.unk_04 = 8;
            D_8250A2A0.unk_06 = 0x12C;
            D_8250A2A0.unk_08 = 0x140;
            D_8250A2A0.unk_0A = 0xF0;
            D_8250A2A0.unk_0C = D_8250A2A0.unk_0E = 0;
            break;

        case 1:
            D_8250A2A0.unk_04 -= 1;
            D_8250A2A0.unk_08 = ((D_8250A2A0.unk_04 * 0x8C) / 8) + 0xB4;
            D_8250A2A0.unk_0A = ((D_8250A2A0.unk_04 * 0x54) / 8) + 0x9C;
            D_8250A2A0.unk_0C = 0x118 - ((D_8250A2A0.unk_04 * 0x118) / 8);
            D_8250A2A0.unk_0E = 0xA8 - ((D_8250A2A0.unk_04 * 0xA8) / 8);
            if (D_8250A2A0.unk_04 <= 0) {
                D_8250A2A0.unk_00 = 2;
            }
            break;

        case 2:
            var_v0 = 0;
            if (D_82508AF0 & 1) {
                var_a2 = 4;
                if (!(D_82508AF8->unk_02 & 0xCC00)) {
                    var_v0 = 1;
                }
            } else {
                var_a2 = 3;
            }

            if (var_v0 == 0) {
                D_8250A2A0.unk_06 = 0x12C;
            } else if (D_8250A2A0.unk_06 > 0) {
                D_8250A2A0.unk_06 -= 1;
            }

            tmp = D_8250A288.unk_08;
            if (D_82508AF8->unk_04 & 0x800) {
                D_8250A288.unk_08 -= 1;
                if (D_8250A288.unk_08 < 0) {
                    D_8250A288.unk_08 = var_a2 - 1;
                }
            }

            if (D_82508AF8->unk_04 & 0x400) {
                D_8250A288.unk_08 += 1;
                if (D_8250A288.unk_08 >= var_a2) {
                    D_8250A288.unk_08 = 0;
                }
            }

            if (tmp != D_8250A288.unk_08) {
                Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            }

            if (D_82508AF8->unk_04 & 0x8000) {
                if (D_82508AF0 & 1) {
                    D_8780FA38 = D_825088D8[D_8250A288.unk_08];
                } else {
                    D_8780FA38 = D_825088D0[D_8250A288.unk_08];
                }
                D_8250A2A0.unk_00 = 3;
                D_8250A2A0.unk_02 = 1;
                D_8250A2A0.unk_04 = 8;
                D_8250A2A0.unk_08 = 0xB4;
                D_8250A2A0.unk_0A = 0x9C;
                D_8250A2A0.unk_0C = 0x118;
                D_8250A2A0.unk_0E = 0xA8;
                Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
            } else if (D_82508AF8->unk_04 & 0x4000) {
                D_8250A2A0.unk_00 = 3;
                D_8250A2A0.unk_02 = 0;
                D_8250A2A0.unk_04 = 8;
                D_8250A2A0.unk_08 = 0xB4;
                D_8250A2A0.unk_0A = 0x9C;
                D_8250A2A0.unk_0C = 0x118;
                D_8250A2A0.unk_0E = 0xA8;
                Audio_PlaySoundEffectById(SFX_MENU_BACK);
            }
            break;

        case 3:
            D_8250A2A0.unk_04 -= 1;
            D_8250A2A0.unk_08 = ((D_8250A2A0.unk_04 * -0x8C) / 8) + 0x140;
            D_8250A2A0.unk_0A = ((D_8250A2A0.unk_04 * -0x54) / 8) + 0xF0;
            D_8250A2A0.unk_0C = (D_8250A2A0.unk_04 * 0x118) / 8;
            D_8250A2A0.unk_0E = (D_8250A2A0.unk_04 * 0xA8) / 8;
            if (D_8250A2A0.unk_04 <= 0) {
                D_8250A2A0.unk_00 = 0;
                if (D_8250A2A0.unk_02 != 0) {
                    MiniGameSelect_LeaveJoinMenu();
                } else {
                    D_8250A26C = 2;
                }
            }
            break;
    }

    if (D_8250A2A0.unk_00 != 2) {
        D_8250A230[0]->unk_06 |= 1;
    }
}

void MiniGameSelect_UpdateRoundSpinner(void) {
    s32 i;

    if (MiniGameSelect_IsWidgetInState(D_8250A238, 2) != 0) {
        switch (D_8250A2FC) {
            case 0:
                if (D_82508AF8->unk_04 & 0x8000) {
                    D_8780FA3A = D_8250A288.unk_04;

                    for (i = 0; i < 4; i++) {
                        D_8780FA40[i] = 0;
                    }

                    Widget_PauseMenuResetWinStreak();
                    D_8250A26C = 5;
                    func_82501B18(D_8250A238, 3);
                    Audio_PlaySoundEffectById(0xE);
                    KidsClub_SetRoundBannerState(1, D_8250A288.unk_06);
                } else if (D_82508AF8->unk_04 & 0x4000) {
                    D_8250A26C = 2;
                    KidsClub_SetMatchBannerState(1);
                    func_82501B18(D_8250A238, 8);
                    Audio_PlaySoundEffectById(SFX_MENU_BACK);
                } else if ((D_82508AF8->unk_08 & 0x800) && (D_8250A288.unk_04 < 9)) {
                    D_8250A2FC = 2;
                    D_8250A2FE = 5;
                } else if ((D_82508AF8->unk_08 & 0x400) && (D_8250A288.unk_04 >= 2)) {
                    D_8250A2FC = 1;
                    D_8250A2FE = 5;
                }

                if ((D_8250A2FC == 2) || (D_8250A2FC == 1)) {
                    Audio_PlaySoundEffectById(0x10);
                }
                break;

            case 1:
                D_8250A2FE -= 1;
                D_8250A300 = ((D_8250A2FE * 0x1A) / 5) - 0x1A;
                if (D_8250A2FE <= 0) {
                    D_8250A2FC = 0;
                    D_8250A300 = 0;
                    D_8250A288.unk_04 -= 1;
                }
                break;

            case 2:
                D_8250A2FE -= 1;
                D_8250A300 = 0x1A - ((D_8250A2FE * 0x1A) / 5);
                if (D_8250A2FE <= 0) {
                    D_8250A2FC = 0;
                    D_8250A300 = 0;
                    D_8250A288.unk_04 += 1;
                }
                break;
        }
        D_8250A238->unk_06 |= 1;
    }
}

s32 MiniGameSelect_UpdateGridCursor(s16* arg0, s16 arg1) {
    s32 var_a3;
    s32 var_t0;
    s32 sp2C;
    UNUSED s32 pad[2];
    s32 temp_v0_2;
    s16 sp1E;
    s32 temp_v0_3;

    sp1E = 0;
    sp2C = *arg0;
    var_a3 = *arg0 % 3;
    var_t0 = *arg0 / 3;

    if (D_8250A292 == -1) {
        if (D_82508B00[arg1].unk_04 & 0x800) {
            var_t0 -= 1;
            if (var_t0 < 0) {
                var_t0 = 2;
            }
        }

        if (D_82508B00[arg1].unk_04 & 0x400) {
            var_t0 += 1;
            if (var_t0 >= 3) {
                var_t0 = 0;
            }
        }

        if (D_82508B00[arg1].unk_04 & 0x200) {
            var_a3 -= 1;
            if (var_a3 < 0) {
                var_a3 = 2;
            }
        }

        if (D_82508B00[arg1].unk_04 & 0x100) {
            var_a3 += 1;
            if (var_a3 >= 3) {
                var_a3 = 0;
            }
        }

        if (D_82508B00[arg1].unk_04 & 0x8000) {
            sp1E = 1;
        } else if (D_82508B00[arg1].unk_04 & 0x4000) {
            switch (D_8250A26E) {
                case 0:
                    sp1E = -1;
                    break;

                case 1:
                case 4:
                    if (D_8250A288.unk_00 == 0) {
                        sp1E = -1;
                        D_8250A26E = 0;
                        MiniGameSelect_LinkWidgets(D_8250A230[0], D_8250A240[0]);
                    }
                    break;
            }
        }
    } else {
        D_8250A294 -= 1;
        if (D_8250A294 <= 0) {
            D_8250A294 = 0xF;

            temp_v0_2 = (D_8250A292 % 3) - var_a3;
            if (temp_v0_2 > 0) {
                var_a3 += 1;
            } else if (temp_v0_2 < 0) {
                var_a3 -= 1;
            } else {
                temp_v0_2 = (D_8250A292 / 3) - var_t0;
                if (temp_v0_2 > 0) {
                    var_t0 += 1;
                } else if (temp_v0_2 < 0) {
                    var_t0 -= 1;
                } else {
                    sp1E = 1;
                }
            }
        }
    }

    *arg0 = (var_t0 * 3) + var_a3;
    if (sp2C != *arg0) {
        KidsClub_SetRoundBannerLabel(*arg0);
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    return sp1E;
}

s32 MiniGameSelect_AttractCursorShuffle(s16* arg0, s16 arg1) {
    s32 i;
    s32 sp68;
    s16 temp_s3;
    s16 tmp;
    s16 sp50[9];

    sp68 = 0;
    if (arg1 >= 0) {
        Rand_Range(2);
        if ((arg1 % 6) == 0) {
            *arg0 = Rand_Range(9);
            KidsClub_SetRoundBannerLabel(*arg0);

            if (arg1 != 0) {
                for (i = 0; i < 9; i++) {
                    sp50[i] = D_8250A240[i]->unk_0C;
                }
            }

            for (i = 0; i < 9; i++) {
                if (arg1 != 0) {
                    switch (D_8250A298) {
                        case 0:
                            tmp = Rand_Range(9);
                            temp_s3 = D_8250A240[i]->unk_0C;
                            MiniGameSelect_SetWidgetTargetState(D_8250A240[i], D_8250A240[tmp]->unk_0C, 0);
                            D_8250A240[tmp]->unk_0C = temp_s3;
                            break;

                        case 1:
                            tmp = D_825088E0[i];
                            MiniGameSelect_SetWidgetTargetState(D_8250A240[i], sp50[tmp], 0);
                            break;

                        case 2:
                            tmp = D_825088F4[i];
                            MiniGameSelect_SetWidgetTargetState(D_8250A240[i], sp50[tmp], 0);
                            break;
                    }
                } else {
                    MiniGameSelect_SetWidgetTargetState(D_8250A240[i], *arg0, 1);
                }
            }
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        }
    }

    if (arg1 < -0x1D) {
        sp68 = 1;
    }

    return sp68;
}

void MiniGameSelect_GameGridUpdate(void) {
    s32 sp1C;
    s32 sp18;
    s32 temp_v0;
    s32 var_a2;
    s32 var_v1;

    Rand_Advance();
    if (MiniGameSelect_IsWidgetInState(D_8250A240[0], 2) != 0) {
        sp1C = 0;
        sp18 = 0;
        if (D_8780FA48 >= 0) {
            switch (MiniGameSelect_UpdateGridCursor(&D_8250A288.unk_06, D_8780FA48)) {
                case 1:
                    sp1C = 1;

                case -1:
                    sp18 = 1;
                    break;
            }
        } else {
            D_8250A296 -= 1;
            sp1C = MiniGameSelect_AttractCursorShuffle(&D_8250A288.unk_06, D_8250A296);
        }

        if (sp1C != 0) {
            D_8250A26C = 6;
            func_82501B18(D_8250A240[0], 5);
            D_8780FA50[D_8250A288.unk_06] = 1;
            Audio_PlaySoundEffectById(0x11);
        } else if (sp18 != 0) {
            KidsClub_SetRoundBannerState(3, -1);
            func_82501B18(D_8250A240[0], 8);
            D_8250A26C = 2;
            KidsClub_SetMatchBannerState(1);
            Audio_PlaySoundEffectById(SFX_MENU_BACK);
        }
    }
}

void MiniGameSelect_ConfirmUpdate(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_8780FA30[i] != 0) {
            continue;
        }

        if (D_82508B00[i].unk_02 & 0x20) {
            D_8780FA68[i] = 1;
        } else if (D_82508B00[i].unk_02 & 0x10) {
            D_8780FA68[i] = 2;
        }
    }

    if (MiniGameSelect_CountWidgetChannels(D_8250A240[4], 0) >= 3) {
        D_8250A26C = 7;
        StageContext_SetClearColor(1);
        StageFade_StartFromTransparent(0xA);
    }
}

void MiniGameSelect_MainLoop(s16 arg0, s16 arg1) {
    s32 var_s6 = 1;
    s32 i;

    MiniGameSelect_InitMenuNodes(arg0, arg1);
    Audio_StartMusicTrack(0x16);
    StageFade_StartFromOpaque(0xF);
    D_82508AF4 = 0;

    while (var_s6 != 0) {
        MiniGameSelect_PollInputs();
        KidsClub_UpdateMatchBanner();
        KidsClub_UpdateRoundBanner();
        MiniGameSelect_UpdateWidgets();
        MiniGameSelect_DrawFrame();

        switch (D_8250A26C) {
            case 0:
                if (StageContext_GetFadeMode() == 0) {
                    switch (D_8250A26E) {
                        case 0:
                            MiniGameSelect_ReturnToIdle();
                            func_82501B18(D_8250A228[0], 1);
                            break;

                        case 1:
                            D_8250A26C = 5;
                            for (i = 0; i < 9; i++) {
                                func_82501B18(D_8250A240[i], 1);
                            }
                            KidsClub_SetRoundBannerState(1, D_8250A288.unk_06);
                            break;

                        case 4:
                            D_8250A26C = 2;
                            for (i = 0; i < 2; i++) {
                                func_82501B18(D_8250A230[i], 1);
                            }
                            KidsClub_SetMatchBannerState(1);
                            break;
                    }
                }
                break;

            case 1:
                MiniGameSelect_UpdateMainMenu();
                break;

            case 2:
                MiniGameSelect_PlayerJoinUpdate();
                break;

            case 4:
                MiniGameSelect_UpdateOptionPanel();
                break;

            case 3:
                MiniGameSelect_UpdateRoundSpinner();
                break;

            case 5:
                MiniGameSelect_GameGridUpdate();
                break;

            case 6:
                MiniGameSelect_ConfirmUpdate();
                break;

            case 7:
                if (StageContext_GetFadeMode() == 1) {
                    var_s6 = 0;
                }
                break;
        }
        D_82508AF4++;
    }
}

void MiniGameSelect_LoadScene(void) {
    MemoryBlock* temp_v0;

    D_82508AF8 = &D_82508B00;
    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    D_8250A270 = process_geo_layout(temp_v0, D_8250880C);
    D_8250A274 = process_geo_layout(temp_v0, D_825073F0);
    D_8250A278 = process_geo_layout(temp_v0, D_82507CC8);
    D_8250A27C = process_geo_layout(temp_v0, D_825085A0);
    D_8250A280 = process_geo_layout(temp_v0, D_825086F8);
    D_8250A284 = process_geo_layout(temp_v0, D_825087D8);
    MainPool_FinalizeAllocation(temp_v0);
    ModelRenderer_InitDisplayRoots();
    MiniGameSelect_ResetInputStates();
}

s32 MiniGameSelect_Entry(s32 arg0, s32 arg1) {
    unk_func_80007444* sp24;
    BinArchive* temp_v0;

    main_pool_push_state('KIDC');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    D_8250A304 = Font_Init(0x10, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, kids_club_select_ui, 0);
    D_8250A264 = ASSET_LOAD2(backgrounds, 1, 1);

    D_8250A268 = BinArchive_GetFile(D_8250A264, 4);
    D_8250A47C = D_87806330;
    Save_EnsureBankLoaded(2);
    MiniGameSelect_LoadScene();
    StageContext_Activate(sp24);
    MiniGameSelect_MainLoop(arg0, arg1);
    StageLoader_RunFrames(2);
    StageContext_Deactivate();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('KIDC');

    return MiniGameSelect_ResolveGameID();
}
