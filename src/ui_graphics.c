#include "ui_graphics.h"
#include "src/graphics_textures.h"
#include "src/text_system.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/hal_libc.h"
#include "src/stage_loader.h"

extern u8 D_10025D0[];
extern u8 D_1002650[];
extern u8 D_10026D0[];
extern u8 D_1002750[];
extern u8 D_10027D0[];
extern u8 D_1002850[];
extern u8 D_10028D0[];
extern u8 D_1002950[];
extern u8 D_10029D0[];
extern u8 D_1002A50[];
extern u8 D_1002AD0[];
extern u8 D_1002B50[];
extern u8 D_1002BD0[];
extern u8 D_1002C50[];
extern u8 D_1002CD0[];
extern u8 D_1002D50[];
extern u8 D_1002DD0[];
extern u8 D_1002E50[];
extern u8 D_1002ED0[];
extern u8 D_1002F50[];
extern u8 D_1002FD0[];
extern u8 D_1003050[];
extern u8 D_10030D0[];
extern u8 D_1003150[];
extern u8 D_10031D0[];
extern u8 D_1003750[];
extern u8 D_1003890[];
extern u8 D_1003930[];
extern u8 D_10039F0[];
extern u8 D_1003AB0[];
extern u8 D_1003B70[];
extern u8 D_1003C30[];
extern u8 D_1003CF0[];
extern u8 D_1003DB0[];
extern u8 D_1003E50[];
extern u8 D_1003EA0[];
extern u8 D_1003EC8[];
extern u8 D_1003EF0[];
extern u8 D_2004000[];
extern u8 D_2004320[];

Gfx D_8006F470[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsSPEndDisplayList(),
};

Gfx D_8006F498[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsSPEndDisplayList(),
};

Gfx D_8006F4C0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_FILL),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsSPEndDisplayList(),
};

Gfx D_8006F4E0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_COPY),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPEndDisplayList(),
};

Gfx D_8006F518[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0,
                       ENVIRONMENT, 0),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsSPClearGeometryMode(G_ZBUFFER | G_LIGHTING),
    gsSPEndDisplayList(),
};

Gfx D_8006F558[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetCombineLERP(ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0, ENVIRONMENT, PRIMITIVE,
                       TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetPrimColor(0, 0, 0, 0, 0, 255),
    gsSPClearGeometryMode(G_ZBUFFER | G_LIGHTING),
    gsSPEndDisplayList(),
};

Gfx D_8006F5A0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL1, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsSPEndDisplayList(),
};

Gfx D_8006F5D8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
    gsDPSetCombineLERP(ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0, COMBINED, 0, TEXEL1, 0, 0,
                       0, 0, COMBINED),
    gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
    gsSPEndDisplayList(),
};

Gfx D_8006F608[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0,
                       ENVIRONMENT, 0),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPEndDisplayList(),
};

Gfx D_8006F630[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList(),
};

static u8 D_8006F650[] = {
    0x00, 0x34, 0x35, 0x0F, 0x00, 0x06, 0x0D, 0x37, 0x03, 0x04, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x10, 0x11,
    0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x3E, 0x42, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x1A, 0x1B, 0x1C,
    0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E,
    0x2F, 0x30, 0x31, 0x32, 0x33, 0x07, 0x00, 0x08, 0x00, 0x00, 0x00, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B,
    0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D,
    0x5E, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x8F, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x8D, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x8C, 0x00, 0x43, 0x44,
    0x41, 0x8E, 0x67, 0x66, 0x68, 0x00, 0x5F, 0x00, 0x00, 0x69, 0x6B, 0x6A, 0x6C, 0x6D, 0x7F, 0x7E, 0x80, 0x6F,
    0x00, 0x81, 0x83, 0x82, 0x6E, 0x00, 0x60, 0x36, 0x00, 0x70, 0x84, 0x71, 0x61, 0x00, 0x00, 0x65, 0x73, 0x72,
    0x74, 0x00, 0x62, 0x00, 0x00, 0x75, 0x77, 0x76, 0x78, 0x79, 0x86, 0x85, 0x87, 0x7B, 0x00, 0x88, 0x8A, 0x89,
    0x7A, 0x00, 0x63, 0x00, 0x00, 0x7C, 0x8B, 0x7D, 0x64, 0x00, 0x00, 0x00,
};

Gfx D_8006F710[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0,
                       ENVIRONMENT, 0),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsSPEndDisplayList(),
};

Gfx D_8006F750[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsSPEndDisplayList(),
};

Gfx D_8006F768[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
    gsDPSetCombineLERP(ENVIRONMENT, PRIMITIVE, TEXEL1, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, TEXEL1, 0, TEXEL1, 0,
                       ENVIRONMENT, 0),
    gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
    gsSPEndDisplayList(),
};

Gfx D_8006F798[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0,
                       ENVIRONMENT, 0),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPEndDisplayList(),
};

static s32 pad_D_8006F7C0[] = { 0, 0, 0, 0 };

void Ui_DrawTexturedRect8x8(s32 x1, s32 y1, s32 width, s32 height, u8* texture) {
    s32 texture_step_x = (width < 9) ? 0x400 : 0;
    s32 texture_step_y = (height < 9) ? 0x400 : 0;

    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(x1, y1, width, height, 0, 0, texture_step_x, texture_step_y, 0);
}

void Ui_DrawBorderStyleA(s32 x1, s32 y1, s32 width, s32 height) {
    Ui_DrawTexturedRect8x8(x1, y1, 8, 8, D_10027D0);
    Ui_DrawTexturedRect8x8(x1, (y1 + height) - 8, 8, 8, D_1002850);
    Ui_DrawTexturedRect8x8((x1 + width) - 8, (y1 + height) - 8, 8, 8, D_10028D0);
    Ui_DrawTexturedRect8x8((x1 + width) - 8, y1, 8, 8, D_1002950);

    if (width > 16) {
        Ui_DrawTexturedRect8x8(x1 + 8, y1, width - 0x10, 8, D_10025D0);
        Ui_DrawTexturedRect8x8(x1 + 8, (y1 + height) - 8, width - 0x10, 8, D_1002650);
    }

    if (height > 16) {
        Ui_DrawTexturedRect8x8(x1, y1 + 8, 8, height - 0x10, D_10026D0);
        Ui_DrawTexturedRect8x8((x1 + width) - 8, y1 + 8, 8, height - 0x10, D_1002750);
    }
}

void Ui_DrawBorderStyleB(s32 x1, s32 y1, s32 width, s32 height) {
    Ui_DrawTexturedRect8x8(x1, y1, 8, 8, D_1002BD0);
    Ui_DrawTexturedRect8x8(x1, (y1 + height) - 8, 8, 8, D_1002C50);
    Ui_DrawTexturedRect8x8((x1 + width) - 8, (y1 + height) - 8, 8, 8, D_1002CD0);
    Ui_DrawTexturedRect8x8((x1 + width) - 8, y1, 8, 8, D_1002D50);

    if (width > 16) {
        Ui_DrawTexturedRect8x8(x1 + 8, y1, width - 0x10, 8, D_10029D0);
        Ui_DrawTexturedRect8x8(x1 + 8, (y1 + height) - 8, width - 0x10, 8, D_1002A50);
    }

    if (height > 16) {
        Ui_DrawTexturedRect8x8(x1, y1 + 8, 8, height - 0x10, D_1002AD0);
        Ui_DrawTexturedRect8x8((x1 + width) - 8, y1 + 8, 8, height - 0x10, D_1002B50);
    }
}

void Ui_DrawBorderStyleC(s32 x1, s32 y1, s32 width, s32 height) {
    Ui_DrawTexturedRect8x8(x1, y1, 8, 8, D_1002FD0);
    Ui_DrawTexturedRect8x8(x1, (y1 + height) - 8, 8, 8, D_1003050);
    Ui_DrawTexturedRect8x8((x1 + width) - 8, (y1 + height) - 8, 8, 8, D_10030D0);
    Ui_DrawTexturedRect8x8((x1 + width) - 8, y1, 8, 8, D_1003150);

    if (width > 16) {
        Ui_DrawTexturedRect8x8(x1 + 8, y1, width - 0x10, 8, D_1002DD0);
        Ui_DrawTexturedRect8x8(x1 + 8, (y1 + height) - 8, width - 0x10, 8, D_1002E50);
    }

    if (height > 16) {
        Ui_DrawTexturedRect8x8(x1, y1 + 8, 8, height - 0x10, D_1002ED0);
        Ui_DrawTexturedRect8x8((x1 + width) - 8, y1 + 8, 8, height - 0x10, D_1002F50);
    }
}

void Ui_FillInsetRectangleA(s32 x1, s32 y1, s32 width, s32 height, u16 color) {
    gSPDisplayList(gDisplayListHead++, D_8006F4C0);
    gDPSetFillColor(gDisplayListHead++, (color << 0x10) | color);

    if (StageContext_IsHighResolution() != 0) {
        gDPFillRectangle(gDisplayListHead++, x1 + 7, y1 + 7, (x1 + width) - 8, (y1 + height) - 8);
    } else {
        gDPFillRectangle(gDisplayListHead++, x1 + 3, y1 + 3, (x1 + width) - 4, (y1 + height) - 4);
    }
}

void Ui_FillInsetRectangleB(s32 x1, s32 y1, s32 width, s32 height, u16 color) {
    gSPDisplayList(gDisplayListHead++, D_8006F4C0);
    gDPSetFillColor(gDisplayListHead++, (color << 0x10) | color);

    if (StageContext_IsHighResolution() != 0) {
        gDPFillRectangle(gDisplayListHead++, x1 + 5, y1 + 5, (x1 + width) - 6, (y1 + height) - 6);
    } else {
        gDPFillRectangle(gDisplayListHead++, x1 + 3, y1 + 3, (x1 + width) - 4, (y1 + height) - 4);
    }
}

void Ui_DrawGradientRectangle(s32 x1, s32 y1, s32 width, s32 height, Color_RGB8* top_color,
                              Color_RGB8* bottom_color) {
    Vtx* temp_s2;
    unk_D_80068BB0* temp_s1;
    Mtx* sp7C;
    Vp* sp78;

    temp_s1 = GfxImage_GetCurrent();
    temp_s2 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    sp7C = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    sp78 = Gfx_AllocDisplayList(sizeof(Vp) * 1);

    Gfx_SetViewportDimensions(sp78, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)sp78 & 0x1FFFFFFF);

    guOrtho(sp7C, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);
    Gfx_SetVertexAttributes(&temp_s2[0], x1, y1, -1, 0, 0, top_color->r, top_color->g, top_color->b, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[1], x1 + width, y1, -1, 0, 0, top_color->r, top_color->g, top_color->b, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[2], x1, y1 + height, -1, 0, 0, bottom_color->r, bottom_color->g,
                            bottom_color->b, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[3], x1 + width, y1 + height, -1, 0, 0, bottom_color->r, bottom_color->g,
                            bottom_color->b, 0xFF);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);

    gSPMatrix(gDisplayListHead++, (u32)sp7C & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
}

void Ui_DrawBorderedPanel(s32 x1, s32 y1, s32 width, s32 height, u16 color) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (StageContext_IsHighResolution() != 0) {
        Ui_DrawBorderStyleA(x1, y1, width, height);
    } else {
        Ui_DrawBorderStyleC(x1, y1, width, height);
    }

    if ((width >= 0xF) && (height >= 0xF)) {
        Ui_FillInsetRectangleA(x1, y1, width, height, color);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void Ui_DrawGradientPanel(s32 x1, s32 y1, s32 width, s32 height, Color_RGB8* top_color, Color_RGB8* bottom_color) {
    if ((width >= 0xF) && (height >= 0xF)) {
        if (StageContext_IsHighResolution() != 0) {
            Ui_DrawGradientRectangle(x1 + 6, y1 + 6, width - 0xC, height - 0xC, top_color, bottom_color);
        } else {
            Ui_DrawGradientRectangle(x1 + 2, y1 + 2, width - 4, height - 4, top_color, bottom_color);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (StageContext_IsHighResolution() != 0) {
        Ui_DrawBorderStyleA(x1, y1, width, height);
    } else {
        Ui_DrawBorderStyleC(x1, y1, width, height);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void Ui_DrawBorderedPanelStyleB(s32 x1, s32 y1, s32 width, s32 height, u16 color) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (StageContext_IsHighResolution() != 0) {
        Ui_DrawBorderStyleB(x1, y1, width, height);
    } else {
        Ui_DrawBorderStyleC(x1, y1, width, height);
    }

    if ((width >= 0xF) && (height >= 0xF)) {
        Ui_FillInsetRectangleB(x1, y1, width, height, color);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void Ui_DrawBorderedPanelNoFill(s32 x1, s32 y1, s32 width, s32 height) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (StageContext_IsHighResolution() != 0) {
        Ui_DrawBorderStyleA(x1, y1, width, height);
    } else {
        Ui_DrawBorderStyleC(x1, y1, width, height);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void Ui_DrawTextureMarker(s32 x, s32 y) {
    if (StageContext_IsHighResolution() != 0) {
        gSPDisplayList(gDisplayListHead++, D_8006F4E0);
        Gfx_DrawTextureRgba16(x, y, 0x20, 0x16, D_10031D0, 0x20, 0x200000);
    } else {
        gSPDisplayList(gDisplayListHead++, D_8006F5A0);
        Gfx_DrawTextureRgba16Ia8(x, y, 0xC, 0xA, D_1003750, D_1003890, 0x10, 0x100000);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void Ui_DrawAnimatedTextureMarker(s16 x, s16 y) {
    static s16 D_8006F7D0 = 0;

    if (D_8006F7D0 < 6) {
        x += D_8006F7D0;
    } else {
        x = (x - D_8006F7D0) + 0xC;
    }
    Ui_DrawTextureMarker(x, y);
    D_8006F7D0 = (D_8006F7D0 + 1) % 12;
}

void Ui_Draw20x20Icon(s32 arg0, s32 arg1, s32 arg2) {
    u8* var_t4;

    if (arg2 != 0) {
        var_t4 = D_2004320;
    } else {
        var_t4 = D_2004000;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F4E0);
    gDPLoadTextureBlock(gDisplayListHead++, var_t4, G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, arg0 << 2, arg1 << 2, (arg0 + 0x13) << 2, (arg1 + 0x13) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void BattleHud_DrawHpBarTexture(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8* spDC;
    s32 spD8 = arg2 - 4;
    s32 temp_lo = ((arg4 - arg3) * (arg2 - 4)) / arg4;
    s32 sp1C = (arg2 - temp_lo) - 4;

    if ((arg3 * 0x30) < (arg4 * 0xA)) {
        spDC = D_1003CF0;
    } else if ((arg3 * 0x30) < (arg4 * 0x1B)) {
        spDC = D_1003C30;
    } else {
        spDC = D_1003B70;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F4E0);

    gDPLoadTextureBlock(gDisplayListHead++, D_1003930, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 12, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, arg0 << 2, arg1 << 2, (arg0 + 1) << 2, (arg1 + 0xB) << 2, G_TX_RENDERTILE,
                        0, 0, 0x1000, 0x0400);

    gDPLoadTextureBlock(gDisplayListHead++, D_10039F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 12, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, ((arg0 + spD8) + 2) << 2, arg1 << 2, ((arg0 + spD8) + 3) << 2,
                        (arg1 + 0xB) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    if (sp1C > 0) {
        gDPLoadTextureBlock(gDisplayListHead++, spDC, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, (arg0 + 2) << 2, arg1 << 2, (arg0 + sp1C + 1) << 2, (arg1 + 0xB) << 2,
                            G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    if (temp_lo > 0) {
        gDPLoadTextureBlock(gDisplayListHead++, D_1003AB0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 12, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, ((arg0 + sp1C) + 2) << 2, arg1 << 2, ((arg0 + sp1C) + temp_lo + 1) << 2,
                            (arg1 + 0xB) << 2, G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void BattleHud_DrawHpBar16x5(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8* spCC;
    s32 temp_lo = ((arg3 - arg2) * 0x30) / arg3;
    s32 sp14 = 0x30 - temp_lo;

    if ((arg2 * 0x30) < (arg3 * 0xA)) {
        spCC = D_1003EF0;
    } else if ((arg2 * 0x30) < (arg3 * 0x1B)) {
        spCC = D_1003EC8;
    } else {
        spCC = D_1003EA0;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

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
        gSPTextureRectangle(gDisplayListHead++, (arg0 + 0x10) << 2, arg1 << 2, (arg0 + sp14 + 0x10) << 2,
                            (arg1 + 5) << 2, G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    if (temp_lo > 0) {
        gDPLoadTextureBlock(gDisplayListHead++, D_1003E78, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 5, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, ((arg0 + sp14) + 0x10) << 2, arg1 << 2,
                            ((arg0 + sp14) + temp_lo + 0x10) << 2, (arg1 + 5) << 2, G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void Text_LoadNameTable(void) {
    char** temp_s2 = Text_GetStringTable(0x24);
    s32 i;

    for (i = 0; i < 151; i++) {
        HAL_Strcpy(D_8006FF00[i].name, Text_GetString(NULL, 0, temp_s2, i));
    }
}
