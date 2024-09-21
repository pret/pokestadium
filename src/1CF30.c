#include "global.h"
#include "1CF30.h"
#include "include/string.h"
#include "src/3FB0.h"
#include "src/6A40.h"
#include "src/20470.h"
#include "src/6BC0.h"
#include "src/F420.h"
#include "src/memory.h"
#include "stdarg.h"
#include "lib/ultralib/src/libc/xstdio.h"

extern Gfx D_8006F4C0[];
extern Gfx D_8006F710[];
extern Gfx D_8006F750[];
extern Gfx D_8006F768[];
extern Gfx D_8006F798[];

void func_8001C330(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s32 arg8) {
    unk_D_800A7440 sp30;

    func_80005FC0(&sp30, arg0, arg1, (arg0 + arg2) - 1, (arg1 + arg3) - 1);

    if (func_80006030(&sp30) != 0) {
        if (arg6 != 0) {
            arg4 += ((sp30.x1 - arg0) * arg6) >> 5;
        }

        if (arg7 != 0) {
            arg5 += ((sp30.y2 - arg1) * arg7) >> 5;
        }

        if (arg8 == 0x200000) {
            arg6 *= 4;
        } else {
            sp30.y1 += 1;
            sp30.x2 += 1;
        }

        gSPTextureRectangle(gDisplayListHead++, sp30.x1 * 4, sp30.y2 * 4, sp30.y1 * 4, sp30.x2 * 4, G_TX_RENDERTILE,
                            arg4, arg5, arg6, arg7);
    }
}

void func_8001C4E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_8001C330(arg0, arg1, (arg2 - arg0) + 1, (arg3 - arg1) + 1, 0, 0, arg4, arg5, arg6);
}

void func_8001C560(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6) {
    gDPSetPrimColor(gDisplayListHead++, 0, 0, arg4, arg5, arg6, 0xFF);

    func_8001C330(arg0, arg1, arg2, arg3, 0, 0, 0, 0, 0);
}

void func_8001C604(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    gDPSetPrimColor(gDisplayListHead++, 0, 0, arg4, arg5, arg6, arg7);

    func_8001C330(arg0, arg1, arg2, arg3, 0, 0, 0, 0, 0);
}

void func_8001C6AC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8* arg4, s16 arg5, s32 arg6) {
    gDPLoadTextureBlock(gDisplayListHead++, arg4, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg5, arg3, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    func_8001C330(arg0, arg1, arg2, arg3, 0, 0, 0x400, 0x400, arg6);
}

void func_8001C8C4(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8* arg4, s16 arg5, s32 arg6) {
    gDPLoadTextureBlock(gDisplayListHead++, arg4, G_IM_FMT_RGBA, G_IM_SIZ_32b, arg5, arg3, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    func_8001C330(arg0, arg1, arg2, arg3, 0, 0, 0x400, 0x400, arg6);
}

void func_8001CADC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8* arg4, s16 arg5, s32 arg6) {
    gDPLoadTextureBlock(gDisplayListHead++, arg4, G_IM_FMT_IA, G_IM_SIZ_8b, arg5, arg3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    func_8001C330(arg0, arg1, arg2, arg3, 0, 0, 0x400, 0x400, arg6);
}

void func_8001CCF8(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8* arg4, s16 arg5, s32 arg6) {
    gDPLoadTextureBlock(gDisplayListHead++, arg4, G_IM_FMT_IA, G_IM_SIZ_16b, arg5, arg3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    func_8001C330(arg0, arg1, arg2, arg3, 0, 0, 0x400, 0x400, arg6);
}

void func_8001CF10(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8* arg4, s16 arg5, s32 arg6) {
    gDPLoadTextureBlock_4b(gDisplayListHead++, arg4, G_IM_FMT_I, arg5, arg3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, arg2, arg3, 0, 0, 0x400, 0x400, arg6);
}

void func_8001D12C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8* arg4, s16 arg5, s32 arg6) {
    gDPLoadTextureBlock(gDisplayListHead++, arg4, G_IM_FMT_I, G_IM_SIZ_8b, arg5, arg3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, arg2, arg3, 0, 0, 0x400, 0x400, arg6);
}

void func_8001D348(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8* arg4, s16 arg5, s32 arg6) {
    gDPLoadTextureBlock(gDisplayListHead++, arg4, G_IM_FMT_I, G_IM_SIZ_16b, arg5, arg3, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, arg2, arg3, 0, 0, 0x400, 0x400, arg6);
}

void func_8001D560(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8* arg4, u8* arg5, s16 arg6, s32 arg7) {
    gDPLoadTextureBlock(gDisplayListHead++, arg4, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg6, arg3, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gDPLoadMultiBlock(gDisplayListHead++, arg5, 0x0100, 1, G_IM_FMT_I, G_IM_SIZ_8b, arg6, arg3, 0,
                      G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                      G_TX_NOLOD);

    func_8001C330(arg0, arg1, arg2, arg3, 0, 0, 0x400, 0x400, arg7);
}

void func_8001D924(u8* arg0) {
    s32 i;
    s32 j;

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 640, 480);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGB, G_CC_DECALRGB);
    gDPPipeSync(gDisplayListHead++);

    for (i = 0; i < 0x1E0; i += 0x20) {
        for (j = 0; j < 0x280; j += 0x20) {
            gDPLoadTextureBlock(gDisplayListHead++, arg0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, j << 2, i << 2, (j + 0x20) << 2, (i + 0x20) << 2, G_TX_RENDERTILE,
                                0, 0, 0x0200, 0x0200);
            arg0 += 0x200;
        }
    }
}

void func_8001DBDC(u32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    s32 div = 32;
    s16 sp9A;
    s16 sp98;
    s16 sp36;
    s16 sp30;
    s16 j;
    s16 i;
    s16 temp_t4;
    s16 temp_t5;
    s16 var_s2;
    s16 var_t1;
    s16 s1;
    s16 s2;

    sp9A = arg1 + arg3;
    sp98 = arg2 + arg4;

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 640, 480);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGB, G_CC_DECALRGB);
    gDPPipeSync(gDisplayListHead++);

    for (i = (arg2 >> 5) << 5; i < sp98; i += 0x20) {
        for (j = (arg1 >> 5) << 5; j < sp9A; j += 0x20) {
            if (j < arg1) {
                temp_t5 = arg1;
            } else {
                temp_t5 = j;
            }

            if (sp9A < j + 0x20) {
                var_s2 = sp9A;
            } else {
                var_s2 = j + 0x20;
            }

            if (i < arg2) {
                temp_t4 = arg2;
            } else {
                temp_t4 = i;
            }

            if (sp98 < i + 0x20) {
                var_t1 = sp98;
            } else {
                var_t1 = i + 0x20;
            }

            s1 = temp_t5 - j;
            s2 = temp_t4 - i;

            gDPLoadTextureBlock(gDisplayListHead++, ((((i / div) * 0x14) + (j / div)) << 9) + arg0, G_IM_FMT_RGBA,
                                G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, temp_t5 * 4, temp_t4 * 4, var_s2 * 4, var_t1 * 4, G_TX_RENDERTILE,
                                s1 << 4, s2 << 4, 0x0200, 0x0200);
        }
    }
}

void func_8001E000(s16 arg0, s16 arg1, s16 arg2, f32 arg3, Vtx* arg4, u32 arg5) {
    s16 j;
    s16 i;
    Vec3s spCC;
    Vec3f spC0;
    Vec3f spB4;
    MtxF* temp_s4;
    unk_D_80068BB0* temp_s1;
    Vp* temp_s2;
    MtxF* temp_s0;
    MtxF* temp_s3;

    temp_s3 = func_80005F5C(0x40);
    temp_s4 = func_80005F5C(0x40);
    temp_s0 = func_80005F5C(0x40);
    temp_s2 = func_80005F5C(0x10);
    temp_s1 = func_8000648C();

    func_8000EB70(&spCC, 0, 0, arg2);
    func_8000E88C(&spC0, arg0, arg1, 0.0f);
    func_8000E88C(&spB4, arg3, arg3, 1.0f);
    func_8000F2C4(temp_s0, &spC0, &spCC);
    func_8000FDE4(temp_s0, temp_s0, &spB4);
    func_80010090(temp_s3, temp_s0);
    func_8001E6E8(temp_s2, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF);

    guOrtho(temp_s4, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    gSPMatrix(gDisplayListHead++, (u32)temp_s4 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)temp_s3 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGB, G_CC_DECALRGB);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_CULL_BOTH | G_LIGHTING);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    for (i = 0; i < 15; i++) {
        for (j = 0; j < 20; j++) {
            gDPLoadTextureBlock(gDisplayListHead++, arg5, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
            gSPVertex(gDisplayListHead++, arg4, 4, 0);
            gSP2Triangles(gDisplayListHead++, 0, 1, 2, 0, 0, 2, 3, 0);

            arg5 += 0x200;
            arg4 += 4;
        }
    }
}

#ifdef NON_MATCHING
Vtx* func_8001E490(void) {
    s16 i;
    s16 j;
    Vtx* sp54;
    Vtx* var_s0;

    sp54 = main_pool_alloc(0x4B00, 0);
    if (sp54 != NULL) {
        var_s0 = sp54;

        for (i = -0xF0; i < 0xF0; i += 0x20) {
            for (j = -0x140; j < 0x140; j += 0x20) {
                func_8001E680(var_s0++, j, i, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                func_8001E680(var_s0++, j, i + 0x20, 0, 0, 0x200, 0xFF, 0xFF, 0xFF, 0xFF);
                func_8001E680(var_s0++, j + 0x20, i + 0x20, 0, 0x200, 0x200, 0xFF, 0xFF, 0xFF, 0xFF);
                func_8001E680(var_s0++, j + 0x20, i, 0, 0x200, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            }
        }
    }

    return sp54;
}
#else
Vtx* func_8001E490(void);
#pragma GLOBAL_ASM("asm/us/nonmatchings/1CF30/func_8001E490.s")
#endif

void func_8001E680(Vtx* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9) {
    arg0->v.ob[0] = arg1;
    arg0->v.ob[1] = arg2;
    arg0->v.ob[2] = arg3;
    arg0->v.flag = 0;
    arg0->v.tc[0] = arg4;
    arg0->v.tc[1] = arg5;
    arg0->v.cn[0] = arg6;
    arg0->v.cn[1] = arg7;
    arg0->v.cn[2] = arg8;
    arg0->v.cn[3] = arg9;
}

void func_8001E6E8(Vp* arg0, s16 arg1, s16 arg2) {
    arg0->vp.vtrans[0] = arg1 * 2;
    arg0->vp.vtrans[1] = arg2 * 2;
    arg0->vp.vtrans[2] = 0x1FF;
    arg0->vp.vtrans[3] = 0;
    arg0->vp.vscale[0] = arg1 * 2;
    arg0->vp.vscale[1] = arg2 * 2;
    arg0->vp.vscale[2] = 0x1FF;
    arg0->vp.vscale[3] = 0;
}

u8 func_8001E730(u16 arg0) {
    u8 var_v1 = 0;

    if ((arg0 >= 0x20) && (arg0 < 0x80)) {
        var_v1 = ((u8*)D_8006F630)[arg0];
    } else if ((arg0 >= 0xA0) && (arg0 < 0x100)) {
        var_v1 = ((u8*)D_8006F608)[sizeof(Gfx) + arg0];
    }

    return var_v1;
}

u8 func_8001E78C(unk_D_800AC870_sub* arg0, u16 arg1) {
    s32 idx = func_8001E730(arg1);

    return arg0->unk_04[idx];
}

void func_8001E7C0(UNUSED s32 arg0, UNUSED s32 arg1) {
    D_800AC870 = NULL;
}

void func_8001E7D4(UNUSED s32 arg0, s32 arg1) {
    if (D_800AC870 != NULL) {
        D_800AC870->unk_00[arg1].unk_04 = 0;
        D_800AC870->unk_00[arg1].unk_08 = 0;
    }
}

s32 func_8001E810(s32 arg0) {
    s32 var_v1 = 0;

    if (arg0 != 1) {
        if (arg0 == 2) {
            var_v1 = 1;
        } else if (arg0 == 4) {
            var_v1 = 2;
        } else if (arg0 == 8) {
            var_v1 = 3;
        } else if (arg0 == 0x10) {
            var_v1 = 4;
        } else if (arg0 == 0x20) {
            var_v1 = 5;
        }
    }

    return var_v1;
}

void func_8001E884(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp1C;
    ret_func_8000484C* temp_v0_2;

    sp1C = func_8001E810(arg0);
    if (D_800AC870->unk_00[sp1C].unk_04 == 0) {
        temp_v0_2 = func_8000484C(D_800AC870->unk_48, sp1C);
        D_800AC870->unk_50 = sp1C;
        D_800AC870->unk_00[sp1C].unk_00 = arg1;
        D_800AC870->unk_00[sp1C].unk_02 = arg2;
        D_800AC870->unk_00[sp1C].unk_04 = temp_v0_2;
        D_800AC870->unk_00[sp1C].unk_08 = &temp_v0_2->unk_90;
        main_pool_set_func(temp_v0_2, sp1C, &func_8001E7D4);
    }
}

unk_D_800AC870* func_8001E94C(s32 arg0, s32 arg1) {
    D_800AC870 = main_pool_alloc_with_func(sizeof(*D_800AC870), arg1, 'PRNT', func_8001E7C0);
    bzero(D_800AC870, sizeof(*D_800AC870));
    D_800AC870->unk_48 = ASSET_LOAD2(func_800044F4, _3BA190, 1, 1);
    func_8001E9F0(arg0);

    return D_800AC870;
}

void func_8001E9CC(void) {
    main_pool_try_free(D_800AC870);
}

void func_8001E9F0(s32 arg0) {
    if (D_800AC870 != NULL) {
        if (arg0 & 0x20) {
            func_8001E884(0x20, 0x20, 0x20);
        }

        if (arg0 & 0x10) {
            func_8001E884(0x10, 0x18, 0x18);
        }

        if (arg0 & 8) {
            func_8001E884(8, 0x18, 0x14);
        }

        if (arg0 & 4) {
            func_8001E884(4, 0x10, 0x10);
        }

        if (arg0 & 2) {
            func_8001E884(2, 0x10, 0xC);
        }

        if (arg0 & 1) {
            func_8001E884(1, 0x10, 0xA);
        }
    }
}

void func_8001EAD0(s32 arg0) {
    if (D_800AC870 != NULL) {
        if (arg0 & 1) {
            if (D_800AC870->unk_00[0].unk_04 != NULL) {
                main_pool_try_free(D_800AC870->unk_00[0].unk_04);
            }
        }

        if (arg0 & 2) {
            if (D_800AC870->unk_00[1].unk_04 != NULL) {
                main_pool_try_free(D_800AC870->unk_00[1].unk_04);
            }
        }

        if (arg0 & 4) {
            if (D_800AC870->unk_00[2].unk_04 != NULL) {
                main_pool_try_free(D_800AC870->unk_00[2].unk_04);
            }
        }

        if (arg0 & 8) {
            if (D_800AC870->unk_00[3].unk_04 != NULL) {
                main_pool_try_free(D_800AC870->unk_00[3].unk_04);
            }
        }

        if (arg0 & 0x10) {
            if (D_800AC870->unk_00[4].unk_04 != NULL) {
                main_pool_try_free(D_800AC870->unk_00[4].unk_04);
            }
        }

        if (arg0 & 0x20) {
            if (D_800AC870->unk_00[5].unk_04 != NULL) {
                main_pool_try_free(D_800AC870->unk_00[5].unk_04);
            }
        }
    }
}

void func_8001EBE0(s32 arg0, s32 arg1) {
    if (D_800AC870 != NULL) {
        D_800AC870->unk_50 = func_8001E810(arg0);
        D_800AC870->unk_51 = arg1;
        D_800AC870->unk_53 &= ~2;
    }
}

s32 func_8001EC40(s32 arg0, unk_D_800AC870_sub* arg1) {
    s32 var_v1 = 0;

    if ((arg1 != NULL) && (D_800AC870 != NULL)) {
        *arg1 = D_800AC870->unk_00[func_8001E810(arg0)];
        var_v1 = 1;
    }

    return var_v1;
}

s16 func_8001ECB4(s16 arg0, s16 arg1, s16 arg2) {
    unk_D_800AC870_sub* temp_s0;
    s32 sp88;
    s16 sp86;

    temp_s0 = &D_800AC870->unk_00[D_800AC870->unk_50];
    sp88 = func_8001E730(arg2) * temp_s0->unk_00 * temp_s0->unk_02;
    sp86 = func_8001E78C(temp_s0, arg2);

    if ((D_800AC870->unk_53 & 1) && !(D_800AC870->unk_53 & 2)) {
        D_800AC870->unk_53 |= 2;

        gDPLoadMultiBlock(gDisplayListHead++, (u32)temp_s0->unk_08 + (temp_s0->unk_00 * 0x90 * temp_s0->unk_02), 0x0100,
                          1, G_IM_FMT_I, G_IM_SIZ_8b, temp_s0->unk_00, temp_s0->unk_02, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                          G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    }

    if ((u32)temp_s0->unk_08 + sp88 != D_800AC870->unk_4C) {
        D_800AC870->unk_4C = (u32)temp_s0->unk_08 + sp88;

        gDPLoadTextureBlock(gDisplayListHead++, (u32)temp_s0->unk_08 + sp88, G_IM_FMT_IA, G_IM_SIZ_8b, temp_s0->unk_00,
                            temp_s0->unk_02, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                            G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    }

    func_8001C330(arg0, arg1, sp86, temp_s0->unk_02, 0, 0, 0x400, 0x400, 0);

    arg0 += sp86 + D_800AC870->unk_51;
    if (D_800AC870->unk_50 >= 2) {
        arg0 -= 2;
    } else {
        arg0 -= 1;
    }

    return arg0;
}

char* func_8001F1C4(char* buffer, const char* data, u32 size) {
    return (char*)memcpy(buffer, data, size) + size;
}

void func_8001F1E8(s32 x, s32 y, const char* fmt, ...) {
    char sp50[0x100];
    s32 temp_s5 = x - 1;
    s32 var_s1 = x - 1;
    s32 temp_v0;
    s32 var_v0;
    char* var_s0;
    s16 chr;

    va_list args;
    va_start(args, fmt);

    temp_v0 = _Printf(func_8001F1C4, sp50, fmt, args);

    if (temp_v0 > 0) {
        sp50[temp_v0] = 0;
        chr = *sp50;
        var_s0 = &sp50[1];

        while (chr != 0) {
            var_v0 = 1;

            if (!(D_800AC870->unk_53 & 4) && (chr == 0xA)) {
                var_s1 = temp_s5;
                var_v0 = 0;
                y += D_800AC870->unk_52;
            }

            if (var_v0 != 0) {
                var_s1 = func_8001ECB4(var_s1, y, chr & 0xFF);
            }

            chr = *var_s0;
            var_s0++;
        }
    }

    va_end(args);
}

void func_8001F2E4(s32 arg0, s32 arg1, s32 arg2) {
    func_8001ECB4(arg0 - 1, arg1, arg2 & 0xFF);
}

void func_8001F324(s32 r, s32 g, s32 b, s32 a) {
    gDPSetEnvColor(gDisplayListHead++, r, g, b, a);
}

void func_8001F36C(s32 r, s32 g, s32 b, s32 a) {
    gDPSetPrimColor(gDisplayListHead++, 0, 0, r, g, b, a);
}

void func_8001F3B4(s32 arg0) {
    D_800AC870->unk_52 = arg0;
}

void func_8001F3C4(void) {
    D_800AC870->unk_53 |= 4;
}

void func_8001F3DC(void) {
    D_800AC870->unk_53 &= ~4;
}

void func_8001F3F4(void) {
    D_800AC870->unk_53 = 0;
    D_800AC870->unk_52 = 0x28;
    D_800AC870->unk_4C = 0;

    gSPDisplayList(gDisplayListHead++, D_8006F710);
}

void func_8001F444(void) {
    gSPDisplayList(gDisplayListHead++, D_8006F750);
}

void func_8001F470(void) {
    D_800AC870->unk_53 |= 1;
    D_800AC870->unk_53 &= ~2;

    gSPDisplayList(gDisplayListHead++, D_8006F768);
}

void func_8001F4C4(void) {
    D_800AC870->unk_53 &= ~3;
    gSPDisplayList(gDisplayListHead++, D_8006F798);
}

void func_8001F504(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    gSPDisplayList(gDisplayListHead++, D_8006F498);

    func_8001C604(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

s32 func_8001F5B0(s32 x, s32 y, const char* fmt, ...) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_s2;
    char sp5C[0x100];
    s32 var_a0;
    s32 chr;
    u8* var_s1;
    unk_D_800AC870_sub* temp_s4;

    va_list args;
    va_start(args, fmt);

    var_s2 = 0;
    if (x == 0) {
        var_a0 = D_800AC870->unk_50;
    } else {
        var_a0 = func_8001E810(x);
    }

    temp_s4 = &D_800AC870->unk_00[var_a0];
    if (temp_s4->unk_04 != NULL) {
        temp_s0 = 0;
        temp_v0 = _Printf(func_8001F1C4, sp5C, fmt, args);
        if (temp_v0 > 0) {
            sp5C[temp_v0] = 0;

            chr = *sp5C;
            var_s1 = &sp5C[1];

            while (chr != 0) {
                if (chr == 0xA) {
                    temp_s0 = 0;
                } else {
                    temp_s0 += func_8001E78C(temp_s4, chr & 0xFF) + y;
                    if (var_a0 >= 2) {
                        temp_s0 -= 2;
                    } else {
                        temp_s0 -= 1;
                    }
                }

                if (var_s2 < temp_s0) {
                    var_s2 = temp_s0;
                }

                chr = *var_s1;
                var_s1++;
            }
        }
    }

    va_end(args);

    return var_s2;
}

void func_8001F6E8(s32 arg0, s32 arg1) {
    func_8001E78C(&D_800AC870->unk_00[D_800AC870->unk_50], arg1 & 0xFF);
}
