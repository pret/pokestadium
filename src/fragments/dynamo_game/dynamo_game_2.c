#include "dynamo_game.h"
#include "src/audio_sfx.h"
#include "src/gfx_buffer.h"
#include "src/fragments/widget_toolkit/widget_toolkit.h"
#include "src/fragments/minigame_shared_library/minigame_shared_library.h"

static Vtx D_865091D0[] = {
    VTX(-1, 545, -834, 0, 1024, 0x00, 0x00, 0x78, 0xFF),
    VTX(219, 545, -834, 1024, 1024, 0x00, 0x00, 0x78, 0xFF),
    VTX(219, 764, -834, 1024, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(-1, 764, -834, 0, 0, 0x00, 0x00, 0x78, 0xFF),
};

static Gfx D_86509210[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetCombineMode(G_CC_DECALRGB, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};

static Gfx D_86509238[] = {
    gsSPVertex(D_865091D0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

s32 D_86509250 = 0;
s32 D_86509254 = 0;
static u32* D_86509258[] = {
    D_86506750, D_86506F50, D_86507750, D_86507F50, D_86508750,
};

const char D_865092C0[] = "%d : TIME = %d\n";

static unk_func_80011B94* D_8650AD80;
u8 D_8650AD84;
u8 D_8650AD85;

void DynamoGame_PickNextCrankCue(void) {
    switch (D_86509254) {
        case 0:
            D_86509250 = MiniGame_RandomRange(2) + 3;
            break;

        case 1:
            D_86509250 = 4;
            break;

        case 2:
            D_86509250 = 3;
            break;
    }

    D_8650AD84 = 0;
    D_8650AD85 = (MiniGame_RandomRange(4) * 0xF) + 0x1E;

    if (D_86509254 != 0) {
        Audio_PlaySoundEffectById(0x11);
    }
}

void DynamoGame_DrawCrankIcon(void) {
    Gfx* sp1C;
    Mtx* sp18;

    sp1C = Gfx_AllocDisplayList(sizeof(Gfx) * 16);
    sp18 = Gfx_AllocDisplayList(sizeof(Mtx) * 1);

    D_8650AD80->gfx = sp1C;
    guScale(sp18, 0.1f, 0.1f, 0.1f);

    gSPDisplayList(sp1C++, D_86509210);
    gDPLoadTextureBlock(sp1C++, D_86509258[D_86509250], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPMatrix(sp1C++, sp18, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(sp1C++, D_86509238);
    gSPEndDisplayList(sp1C++);
}

void DynamoGame_InitCrankIconDisplay(void) {
    MainPoolState* sp1C;

    sp1C = MainPool_AllocState(main_pool_get_available(), 0);
    D_8650AD80 = GeoNode_CreateDisplayList(sp1C, NULL, 1, NULL);
    GraphNode_AppendChild(&D_800AC840, &D_8650AD80->display_node_header);
    MainPool_FinalizeAllocation(sp1C);
}
