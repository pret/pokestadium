#include "global.h"
#include "6BC0.h"
#include "memory.h"

static unk_D_80068BB0* D_80068BB0 = NULL;

unk_D_800A7440* func_80005FC0(unk_D_800A7440* arg0, s16 x1, s16 y1, s16 x2, s16 y2) {
    if (x2 >= x1) {
        arg0->x1 = x1;
        arg0->y1 = x2;
    } else {
        arg0->x1 = x2;
        arg0->y1 = x1;
    }

    if (y2 >= y1) {
        arg0->x2 = y2;
        arg0->y2 = y1;
    } else {
        arg0->y2 = y2;
        arg0->x2 = y1;
    }

    return arg0;
}

s32 func_80006030(unk_D_800A7440* arg0) {
    s32 ret = 0;

    if (D_80068BB0 != NULL) {
        if (arg0->x1 < D_800A7440.x1) {
            arg0->x1 = D_800A7440.x1;
        }

        if (D_800A7440.y1 < arg0->y1) {
            arg0->y1 = D_800A7440.y1;
        }

        if (arg0->y2 < D_800A7440.y2) {
            arg0->y2 = D_800A7440.y2;
        }

        if (D_800A7440.x2 < arg0->x2) {
            arg0->x2 = D_800A7440.x2;
        }

        ret = arg0->y1 >= arg0->x1 && arg0->x2 >= arg0->y2;
    }

    return ret;
}

void func_800060E0(Gfx** gfx_p, s16 x, s16 y, s16 width, s16 height) {
    if (D_80068BB0 != NULL) {
        Gfx* gfx = *gfx_p;

        gDPPipeSync(gfx++);
        gDPSetScissorFrac(gfx++, G_SC_NON_INTERLACE, (x * 4.0f), (y * 4.0f), (x + width) * 4.0f, (y + height) * 4.0f);

        *gfx_p = gfx;

        func_80005FC0(&D_800A7440, x, y, x + width - 1, y + height - 1);
    }
}

void func_80006200(Gfx** gfx_p) {
    if (D_80068BB0 != NULL) {
        Gfx* gfx = *gfx_p;

        gDPPipeSync(gfx++);
        gDPSetScissorFrac(gfx++, G_SC_NON_INTERLACE, D_800A7440.x1 * 4.0f, D_800A7440.y2 * 4.0f,
                          (D_800A7440.y1 + 1) * 4.0f, (D_800A7440.x2 + 1) * 4.0f);

        *gfx_p = gfx;
    }
}

void func_800062E4(unk_D_80068BB0* arg0, s32 fmt, s32 size, s32 width, s32 height, u32 img_p) {
    arg0->fmt = fmt;
    arg0->size = size;
    arg0->width = width;
    arg0->height = height;
    arg0->img_p = (u8*)ALIGN64(img_p);
    arg0->depth_p = NULL;
}

unk_D_80068BB0* func_80006314(s32 fmt, s32 size, s32 width, s32 height, s32 side) {
    unk_D_80068BB0* sp34;
    s32 size_bytes;
    s32 num_pixels = width * height;

    switch (size) {
        case IMAGE_SIZE_BITS_4b:
            size_bytes = (num_pixels + 1) / 2;
            break;

        case IMAGE_SIZE_BITS_8b:
            size_bytes = num_pixels;
            break;

        case IMAGE_SIZE_BITS_16b:
            size_bytes = num_pixels * 2;
            break;

        case IMAGE_SIZE_BITS_32b:
            size_bytes = num_pixels * 4;
            break;
    }

    sp34 = main_pool_alloc(size_bytes + sizeof(unk_D_80068BB0), side);
    if (sp34 != NULL) {
        // image data follows the header struct
        func_800062E4(sp34, fmt, size, width, height, sp34->unk_10);
    }

    return sp34;
}

void func_80006414(unk_D_80068BB0* img, unk_D_80068BB0* depth) {
    if ((depth->size == IMAGE_SIZE_BITS_16b) && (img->width == depth->width) && (img->height == depth->height)) {
        img->depth_p = depth;
    }
}

void func_80006450(void) {
    D_80068BB0 = NULL;
    func_80005FC0(&D_800A7440, 0, 0, 0, 0);
}

unk_D_80068BB0* func_8000648C(void) {
    return D_80068BB0;
}

void func_80006498(Gfx** gfx_p, unk_D_80068BB0* arg1) {
    Gfx* gfx = *gfx_p;

    gDPPipeSync(gfx++);

    if (arg1->depth_p != NULL) {
        gDPSetDepthSource(gfx++, G_ZS_PIXEL);
        gDPSetDepthImage(gfx++, (u32)arg1->depth_p->img_p & 0x1FFFFFFF);
    }

    gDPSetColorImage(gfx++, arg1->fmt, arg1->size, arg1->width, (u32)arg1->img_p & 0x1FFFFFFF);

    D_80068BB0 = arg1;
    func_800060E0(&gfx, 0, 0, arg1->width, arg1->height);

    *gfx_p = gfx;
}

void func_800065B4(Gfx** gfx_p, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u16 fill_colour) {
    if (D_80068BB0 != NULL) {
        Gfx* gfx = *gfx_p;

        gDPPipeSync(gfx++);
        gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCycleType(gfx++, G_CYC_FILL);

        if (D_80068BB0->depth_p) {
            unk_D_80068BB0* depth = D_80068BB0->depth_p;

            gDPSetColorImage(gfx++, depth->fmt, depth->size, depth->width, (u32)depth->img_p & 0x1FFFFFFF);
            gDPSetFillColor(gfx++, 0xFFFCFFFC);
            gDPFillRectangle(gfx++, arg1, arg2, (arg1 + arg3) - 1, (arg2 + arg4) - 1);
            gDPPipeSync(gfx++);
            gDPSetColorImage(gfx++, D_80068BB0->fmt, D_80068BB0->size, D_80068BB0->width,
                             (u32)D_80068BB0->img_p & 0x1FFFFFFF);
        }

        gDPPipeSync(gfx++);
        gDPSetFillColor(gfx++, (fill_colour << 0x10) | fill_colour);
        gDPFillRectangle(gfx++, arg1, arg2, (arg1 + arg3) - 1, (arg2 + arg4) - 1);

        *gfx_p = gfx;
    }
}

void func_800067E4(Gfx** gfx_p, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (D_80068BB0 != NULL && D_80068BB0->depth_p != NULL) {
        Gfx* gfx = *gfx_p;
        unk_D_80068BB0* depth = D_80068BB0->depth_p;

        gDPPipeSync(gfx++);
        gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPSetColorImage(gfx++, depth->fmt, depth->size, depth->width, (u32)depth->img_p & 0x1FFFFFFF);

        gDPSetFillColor(gfx++, 0xFFFCFFFC);
        gDPFillRectangle(gfx++, arg1, arg2, (arg1 + arg3) - 1, (arg2 + arg4) - 1);

        gDPPipeSync(gfx++);
        gDPSetColorImage(gfx++, D_80068BB0->fmt, D_80068BB0->size, D_80068BB0->width,
                         (u32)D_80068BB0->img_p & 0x1FFFFFFF);

        *gfx_p = gfx;
    }
}

void func_8000699C(Gfx** gfx_p, u16 fill_colour) {
    func_800065B4(gfx_p, 0, 0, D_80068BB0->width, D_80068BB0->height, (fill_colour << 0x10) | fill_colour);
}
