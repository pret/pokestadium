#include "global.h"
#include "11BA0.h"

void func_80010FA0(unk_D_86002F58_004_000_000* arg0, u8 arg1) {
    if (arg0 != NULL) {
        arg0->unk_00 = arg1;
        arg0->unk_01 = 0x11;
        arg0->unk_02 = 0;
        arg0->unk_03 = 0;
        arg0->unk_04 = arg0;
        arg0->unk_08 = arg0;
        arg0->unk_0C = NULL;
        arg0->unk_10 = 0;
        arg0->unk_14 = 0;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80010FDC.s")

unk_D_86002F58_004_000_000* func_8001103C(MainPoolState* arg0, void* arg1) {
    if (arg0 != 0) {
        arg1 = func_80002DCC(arg0, sizeof(unk_D_86002F58_004_000_000), 4);
    }

    if (arg1 != NULL) {
        func_80010FA0(arg1, 0);
    }

    return arg1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011088.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_800110E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_800111A4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_800111FC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011258.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_800112BC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011320.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_800113AC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_800113F8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011484.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011504.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_8001156C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_800115F0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011660.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_800116C0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011720.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_800117A8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011814.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_800118D0.s")

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
        arg1->unk_052 = 0;
        arg1->unk_054.unk_00 = 0;
        arg1->unk_054.unk_04 = NULL;
        arg1->unk_054.unk_08 = 0;
        arg1->unk_054.unk_0A = 0;
        func_80010FA0(&arg1->unk_000, 0x16);
        arg1->unk_000.unk_02 |= 0x60;
    }

    return arg1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011A3C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011ABC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011B10.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011B94.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011BF4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011C98.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011CF0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011DAC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011E68.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011EB4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80011FC8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/11BA0/func_80012044.s")

void func_80012094(unk_D_86002F58_004_000_000* arg0, unk_D_86002F58_004_000_000* arg1) {
    unk_D_86002F58_004_000_000* temp_v0;
    unk_D_86002F58_004_000_000* temp_v1;

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
