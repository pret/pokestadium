#include "global.h"
#include "11BA0.h"
#include "F420.h"
#include "util.h"

void func_80010FA0(GraphNode* arg0, u8 arg1) {
    if (arg0 != NULL) {
        arg0->unk_00 = arg1;
        arg0->unk_01 = 0x11;
        arg0->unk_02 = 0;
        arg0->unk_03 = 0;
        arg0->unk_04 = arg0;
        arg0->unk_08 = arg0;
        arg0->unk_0C = NULL;
        arg0->unk_10 = NULL;
        arg0->unk_14 = NULL;
    }
}

void func_80010FDC(GraphNode* arg0, func_D_86002F34_000_010 arg1, void* arg2) {
    if (arg1 != NULL) {
        arg1 = Util_ConvertAddrToVirtAddr(arg1);
    }

    if (arg0 != NULL) {
        arg0->unk_14 = arg2;
        arg0->unk_10 = arg1;
        if (arg1 != NULL) {
            arg1(0, arg0);
        }
    }
}

GraphNode* func_8001103C(MainPoolState* arg0, GraphNode* arg1) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(struct GraphNode), 4);
    }

    if (arg1 != NULL) {
        func_80010FA0(arg1, 0);
    }

    return arg1;
}

unk_D_86002F34_alt2* func_80011088(MainPoolState* arg0, unk_D_86002F34_alt2* arg1, GraphNode* arg2) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt2), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        func_80010FA0(arg1, 1);
    }

    return arg1;
}

unk_D_86002F34_00C* func_800110E0(MemoryBlock* arg0, unk_D_86002F34_00C* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_00C), 4);
    }

    if (arg1 != NULL) {
        func_80011DAC(arg1, arg2, arg3, arg4, arg5);
        func_80011E68(arg1, 30.0f, 100.0f, 12800.0f);
        func_80011EB4(arg1, 0.0f, 512.0f, 4096.0f, 0.0f, 0.0f, 0.0f, 0);
        func_80011FC8(arg1, 2, 0, 0, 0, 0);
        func_80010FA0(arg1, 2);
    }
    return arg1;
}

unk_D_86002F34_alt13* func_800111A4(MemoryBlock* arg0, unk_D_86002F34_alt13* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt13), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        func_80010FA0(arg1, 3);
    }

    return arg1;
}

unk_D_86002F34_alt1* func_800111FC(MemoryBlock* arg0, unk_D_86002F34_alt1* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt1), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = 0;
        func_80010FA0(arg1, 4);
    }

    return arg1;
}

unk_D_86002F34_alt14* func_80011258(MainPoolState* arg0, unk_D_86002F34_alt14* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt14), 4);
    }

    if (arg1 != NULL) {
        func_80010FA0(arg1, 5);
        arg1->unk_00.unk_02 |= arg2 & 3;
    }

    return arg1;
}

unk_D_86002F34_alt15* func_800112BC(MainPoolState* arg0, unk_D_86002F34_alt15* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt15), 4);
    }

    if (arg1 != NULL) {
        func_80010FA0(arg1, 6);
        arg1->unk_00.unk_02 |= arg2 & 3;
    }

    return arg1;
}

unk_D_86002F34_alt16* func_80011320(MainPoolState* arg0, unk_D_86002F34_alt16* arg1, u8 arg2, u8 arg3, u8 arg4) {
    u32 temp_v0;

    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt16), 4);
    }

    if (arg1 != NULL) {
        temp_v0 = ((arg2 >> 3) << 0xB) | ((arg3 >> 3) << 6) | ((arg4 >> 3) << 1) | 1;
        arg1->unk_18 = (temp_v0 << 0x10) | temp_v0;
        func_80010FA0(arg1, 7);
    }
    return arg1;
}

unk_D_86002F34_alt17* func_800113AC(MainPoolState* arg0, unk_D_86002F34_alt17* arg1) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt17), 4);
    }

    if (arg1 != NULL) {
        func_80010FA0(arg1, 8);
    }

    return arg1;
}

unk_D_8690A610* func_800113F8(s32 arg0, unk_D_8690A610* arg1, s16 arg2, s16 arg3, u8 r, u8 g, u8 b, u8 a) {
    if (arg0 != 0) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_8690A610), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18.unk_00 = arg2;
        arg1->unk_18.unk_02 = arg3;
        arg1->unk_18.unk_04.rgba = (r << 0x18) | (g << 0x10) | (b << 8) | a;
        func_80010FA0(arg1, 0xA);
    }

    return arg1;
}

unk_D_86002F34_alt18* func_80011484(MainPoolState* arg0, unk_D_86002F34_alt18* arg1, s16 arg2, s16 arg3, u8 r, u8 g,
                                    u8 b, u8 a) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt18), 4);
    }

    if (arg1 != NULL) {
        arg1->r = r;
        arg1->g = g;
        arg1->b = b;
        arg1->a = a;
        arg1->unk_1C = arg2;
        arg1->unk_1E = arg3;
        func_80010FA0(arg1, 0xB);
    }

    return arg1;
}

unk_D_86002F34_alt19* func_80011504(MainPoolState* arg0, unk_D_86002F34_alt19* arg1, u8 r, u8 g, u8 b) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt19), 4);
    }

    if (arg1 != NULL) {
        arg1->r = r;
        arg1->g = g;
        arg1->b = b;
        func_80010FA0(arg1, 0xD);
    }

    return arg1;
}

unk_D_86002F34* func_8001156C(MainPoolState* arg0, unk_D_86002F34* arg1, s32 arg2, unk_D_86002F34_018* arg3, s32 arg4,
                              unk_D_86002F34_01C* arg5, s32 arg6, Vtx* arg7) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg3;
        arg1->unk_1C = arg5;
        arg1->unk_20 = arg7;
        arg1->unk_24 = arg2;
        arg1->unk_25 = arg4;
        arg1->unk_26 = arg6;
        arg1->unk_28 = NULL;
        func_80010FA0(arg1, 0xE);
    }

    return arg1;
}

unk_D_86002F34_alt12* func_800115F0(MainPoolState* arg0, unk_D_86002F34_alt12* arg1, s16 arg2, s16 arg3, s16 arg4,
                                    s16 arg5) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt12), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = arg3;
        arg1->unk_1C = arg4;
        arg1->unk_1E = arg5;
        func_80010FA0(arg1, 0xF);
    }

    return arg1;
}

unk_D_86002F34_alt20* func_80011660(MainPoolState* arg0, unk_D_86002F34_alt20* arg1, s16 arg2, s16 arg3) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt20), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = arg3;
        func_80010FA0(arg1, 0x10);
    }

    return arg1;
}

unk_D_86002F34_alt21* func_800116C0(MainPoolState* arg0, unk_D_86002F34_alt21* arg1, s16 arg2, s16 arg3) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt21), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = arg3;
        func_80010FA0(arg1, 0x11);
    }

    return arg1;
}

unk_D_86002F34_alt5* func_80011720(MainPoolState* arg0, unk_D_86002F34_alt5* arg1, Vec3f* arg2, Vec3s* arg3) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt5), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = *arg2;
        arg1->unk_24 = *arg3;
        func_80010FA0(arg1, 0x12);
    }

    return arg1;
}

unk_D_86002F34_alt22* func_800117A8(MainPoolState* arg0, unk_D_86002F34_alt22* arg1, Vec3f* arg2) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt22), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = *arg2;
        func_80010FA0(arg1, 0x13);
    }

    return arg1;
}

unk_D_86002F34_alt6* func_80011814(MainPoolState* arg0, unk_D_86002F34_alt6* arg1, s16 arg2, s16 arg3, s16 arg4,
                                   Vec3s* arg5, Vec3s* arg6, Vec3f* arg7) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt6), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = *arg5;
        arg1->unk_1E = *arg6;
        arg1->unk_24 = *arg7;
        arg1->unk_30 = arg2;
        arg1->unk_31 = arg3;
        arg1->unk_32 = arg4;
        func_80010FA0(arg1, 0x14);
    }

    return arg1;
}

unk_D_86002F34_alt7* func_800118D0(MainPoolState* arg0, unk_D_86002F34_alt7* arg1, s32 arg2, Gfx* arg3, s16 arg4) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt7), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg3;
        arg1->unk_1C = arg4;
        func_80010FA0(arg1, 0x15);
        arg1->unk_00.unk_03 = arg2;
    }

    return arg1;
}

unk_D_86002F58_004_000* func_80011938(MainPoolState* arg0, unk_D_86002F58_004_000* arg1, s16 arg2, Vec3f* arg3,
                                      Vec3s* arg4, Vec3f* arg5) {
    if (arg0 != 0) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F58_004_000), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_018 = 0;
        arg1->unk_01A = arg2;
        arg1->unk_024 = *arg3;
        arg1->unk_030 = *arg5;
        arg1->unk_01E = *arg4;
        arg1->unk_01D = 0xFF;
        arg1->unk_01C = 0;
        arg1->unk_0A6 = 0;
        arg1->unk_0A0.rgba = 0xFFFFFF00;
        arg1->unk_03C.rgba = 0xFFFFFF00;
        arg1->unk_040.unk_00 = 0;
        arg1->unk_040.unk_04 = NULL;
        arg1->unk_040.unk_08 = 0;
        arg1->unk_040.unk_0C = 0x10000;
        arg1->unk_040.unk_12 = 0;
        arg1->unk_054.unk_00 = 0;
        arg1->unk_054.unk_04 = NULL;
        arg1->unk_054.unk_08 = 0;
        arg1->unk_054.unk_0A = 0;
        func_80010FA0(&arg1->unk_000, 0x16);
        arg1->unk_000.unk_02 |= 0x60;
    }

    return arg1;
}

unk_D_86002F34_alt8* func_80011A3C(MainPoolState* arg0, unk_D_86002F34_alt8* arg1, s32 arg2, Gfx* arg3, MtxF* arg4) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt8), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg3;
        if (arg4 == NULL) {
            func_8000ED98(&arg1->unk_1C);
        } else {
            func_8000ED4C(&arg1->unk_1C, arg4);
        }
        func_80010FA0(arg1, 0x17);
        arg1->unk_00.unk_03 = arg2;
    }

    return arg1;
}

unk_D_86002F34_alt8* func_80011ABC(MainPoolState* arg0, unk_D_86002F34_alt8* arg1, s32 arg2, Gfx* arg3, Vec3f* arg4,
                                   Vec3s* arg5) {
    MtxF sp20;

    func_8000F2C4(&sp20, arg4, arg5);
    return func_80011A3C(arg0, arg1, arg2, arg3, &sp20);
}

unk_D_86002F34_alt9* func_80011B10(MainPoolState* arg0, unk_D_86002F34_alt9* arg1, s32 arg2, Gfx* arg3, Vec3f* arg4,
                                   f32 arg5) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt9), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_1C = *arg4;
        arg1->unk_28 = arg5;
        arg1->unk_18 = arg3;
        func_80010FA0(arg1, 0x18);
        arg1->unk_00.unk_03 = arg2;
    }

    return arg1;
}

unk_func_80011B94* func_80011B94(MainPoolState* arg0, unk_func_80011B94* arg1, s32 arg2, Gfx* arg3) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_func_80011B94), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg3;
        func_80010FA0(arg1, 0x19);
        arg1->unk_00.unk_03 = arg2;
    }

    return arg1;
}

unk_D_86002F34_alt10* func_80011BF4(MainPoolState* arg0, unk_D_86002F34_alt10* arg1, s16 arg2, s16 arg3, Gfx* arg4,
                                    s16 arg5, s16 arg6, u8 r, u8 g, u8 b, u8 a) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt10), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_22 = arg2;
        arg1->unk_20 = arg3;
        arg1->unk_18 = arg4;
        arg1->unk_1C = arg5;
        arg1->unk_1E = arg6;
        arg1->unk_24.rgba = (r << 0x18) | (g << 0x10) | (b << 8) | a;
        func_80010FA0(arg1, 0x1A);
    }

    return arg1;
}

unk_D_86002F34_alt23* func_80011C98(MainPoolState* arg0, unk_D_86002F34_alt23* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt23), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        func_80010FA0(arg1, 0x1B);
    }

    return arg1;
}

unk_D_86002F34_alt24* func_80011CF0(MainPoolState* arg0, unk_D_86002F34_alt24* arg1, s32 arg2, s16 arg3, s16 arg4,
                                    s16 arg5, s16 arg6, s16 arg7, s16 arg8, s32 arg9, u8 r, u8 g, u8 b, u8 a) {
    if (arg0 != NULL) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F34_alt24), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_1C = arg3;
        arg1->unk_1E = arg4;
        arg1->unk_20 = arg5;
        arg1->unk_22 = arg6;
        arg1->unk_18 = arg7;
        arg1->unk_1A = arg8;
        arg1->unk_24 = arg9;
        arg1->unk_28.rgba = (r << 0x18) | (g << 0x10) | (b << 8) | a;
        func_80010FA0(arg1, 0x1C);
        arg1->unk_00.unk_03 = arg2;
    }

    return arg1;
}

void func_80011DAC(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk_18.x = arg1;
    arg0->unk_18.y = arg2;
    arg0->unk_18.width = arg3;
    arg0->unk_18.height = arg4;

    arg0->unk_40.l = -arg3 * 0.5f;
    arg0->unk_40.r = arg3 * 0.5f;
    arg0->unk_40.t = arg4 * 0.5f;
    arg0->unk_40.b = -arg4 * 0.5f;
    arg0->unk_40.n = -2.0f;
    arg0->unk_40.f = 2.0f;
    arg0->unk_40.scale = 1.0f;
}

void func_80011E68(unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->unk_24.aspect = (f32)arg0->unk_18.width / arg0->unk_18.height;
    arg0->unk_24.fovy = arg1;
    arg0->unk_24.near = arg2;
    arg0->unk_24.far = arg3;
    arg0->unk_24.scale = 1.0f;
}

void func_80011EB4(unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7) {
    unk_D_86002F34_00C_060* sp1C = &arg0->unk_60;
    f32 sp28 = arg4 - arg1;
    f32 sp24 = arg6 - arg3;
    f32 temp_fv1_2 = -1.0 / sqrtf(SQ(sp28) + SQ(sp24));

    sp28 *= temp_fv1_2;
    sp24 *= temp_fv1_2;

    func_8000E88C(&sp1C->eye, arg1, arg2, arg3);
    func_8000E88C(&sp1C->at, arg4, arg5, arg6);
    func_8000E88C(&sp1C->up, SINS(arg7) * sp24, COSS(arg7), -SINS(arg7) * sp28);
}

void func_80011FC8(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4, u8 arg5) {
    unk_D_86002F34_00C_0CC* ptr = &arg0->unk_CC;

    if (arg2 < 2) {
        if ((arg1 == 2) || (arg1 == 4)) {
            ptr->unk_00 = 0;
        } else {
            ptr->unk_00 = 1;
        }
    } else {
        ptr->unk_00 = arg1;
        ptr->unk_08 = arg2;
        ptr->unk_0A = 1;
        ptr->color.r = arg3;
        ptr->color.g = arg4;
        ptr->color.b = arg5;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80012044.s")

void func_80012094(GraphNode* arg0, GraphNode* arg1) {
    GraphNode* temp_v0;
    GraphNode* temp_v1;

    if ((arg0 != NULL) && (arg1 != NULL)) {
        temp_v0 = arg0->unk_0C;
        if (temp_v0 == NULL) {
            arg0->unk_0C = arg1;
            arg1->unk_04 = arg1;
            arg1->unk_08 = arg1;
        } else {
            temp_v1 = temp_v0->unk_04;
            arg1->unk_08 = temp_v0;
            arg1->unk_04 = temp_v1;
            temp_v0->unk_04 = arg1;
            temp_v1->unk_08 = arg1;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_800120DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80012120.s")
