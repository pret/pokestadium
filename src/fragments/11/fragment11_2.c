#include "fragment11.h"
#include "src/49790.h"
#include "src/6A40.h"
#include "src/fragments/2/fragment2.h"
#include "src/fragments/5/fragment5.h"

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

void func_865029C0(void) {
    switch (D_86509254) {
        case 0:
            D_86509250 = func_87B00050(2) + 3;
            break;

        case 1:
            D_86509250 = 4;
            break;

        case 2:
            D_86509250 = 3;
            break;
    }

    D_8650AD84 = 0;
    D_8650AD85 = (func_87B00050(4) * 0xF) + 0x1E;

    if (D_86509254 != 0) {
        func_80048B90(0x11);
    }
}

void func_86502A68(void) {
    Gfx* sp1C;
    Mtx* sp18;

    sp1C = func_80005F5C(sizeof(Gfx) * 16);
    sp18 = func_80005F5C(sizeof(Mtx) * 1);

    D_8650AD80->unk_18 = sp1C;
    guScale(sp18, 0.1f, 0.1f, 0.1f);

    gSPDisplayList(sp1C++, D_86509210);
    gDPLoadTextureBlock(sp1C++, D_86509258[D_86509250], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPMatrix(sp1C++, sp18, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(sp1C++, D_86509238);
    gSPEndDisplayList(sp1C++);
}

void func_86502BB8(void) {
    MainPoolState* sp1C;

    sp1C = func_80002D10(main_pool_get_available(), 0);
    D_8650AD80 = func_80011B94(sp1C, NULL, 1, NULL);
    func_80012094(&D_800AC840, &D_8650AD80->unk_00);
    func_80002D60(sp1C);
}
