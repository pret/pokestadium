#include "fragment31.h"

typedef struct unk_D_810047E0 {
    /* 0x00 */ s16 unk_00;
    /* 0x04 */ Vec3f unk_04;
    /* 0x10 */ Vec3f unk_10;
    /* 0x1C */ Vec3f unk_1C;
    /* 0x28 */ s16 unk_28;
} unk_D_810047E0; // size = 0x2C

extern unk_D_810047E0 D_810047E0[2][10];
extern s32 D_81004B50;
extern s32 D_81004B54;

// Matching, just needs data to be done
#ifdef NON_MATCHING
void func_810005F0(unk_D_86002F58_004_000* arg0, s32 arg1) {
    u8 var_v0 = arg0->unk_0A6;
    UNUSED s32 pad[2];
    Vec3f sp50 = { 0.0f, 0.0f, 0.0f };
    Vec3f sp44 = { 0.0f, 0.0f, 0.0f };
    Vec3f sp38 = { 1.0f, 1.0f, 1.0f };
    UNUSED Vec3f sp2C = { 2.0f, 2.0f, 2.0f };
    UNUSED Vec3f sp20 = { 0.0f, 10.0f, 0.0f };
    UNUSED Vec3f sp14 = { 10000.0f, 10000.0f, 10000.0f };
    UNUSED Vec3f sp8 = { -10000.0f, -10000.0f, -10000.0f };

    if (var_v0 == 0xFF) {
        var_v0 = 0;
    } else if (var_v0 == 0xFE) {
        var_v0 = 0;
    }

    D_810047E0[var_v0 & 1][arg1].unk_00 = 0;
    D_810047E0[var_v0 & 1][arg1].unk_28 = 0;
    D_810047E0[var_v0 & 1][arg1].unk_04 = sp50;
    D_810047E0[var_v0 & 1][arg1].unk_10 = sp44;
    D_810047E0[var_v0 & 1][arg1].unk_1C = sp38;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2558B0/func_810005F0.s")
#endif

void func_810007A8(unk_D_86002F58_004_000* arg0) {
    s32 i;

    for (i = 0; i < 10; i++) {
        func_810005F0(arg0, i);
    }
}

void func_810007F8(void) {
    D_81004B50 = 0;
    D_81004B54 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2558B0/func_8100080C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2558B0/func_81000E78.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2558B0/func_810010BC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2558B0/func_81001D80.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2558B0/func_81001E24.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2558B0/func_81002174.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2558B0/func_81002260.s")
