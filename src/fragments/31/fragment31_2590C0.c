#include "fragment31.h"
#include "src/6A40.h"
#include "src/12D80.h"

typedef struct unk_arg1_func_81003E00_14 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 unk_04;
} unk_arg1_func_81003E00_14; // size = 0x6

typedef struct unk_arg1_func_81003E00_04 {
    /* 0x00 */ char unk00[0x1];
    /* 0x01 */ u8 unk_01;
} unk_arg1_func_81003E00_04; // size = 0x2

typedef struct unk_arg1_func_81003E00 {
    /* 0x00 */ char unk00[0x4];
    /* 0x04 */ unk_arg1_func_81003E00_04* unk_04;
    /* 0x08 */ char unk08[0xC];
    /* 0x14 */ unk_arg1_func_81003E00_14* unk_14;
} unk_arg1_func_81003E00; // size = 0x18

void func_81003E00(s32 arg0, unk_arg1_func_81003E00* arg1) {
    s32 temp_a2;
    s32 var_v1;
    unk_arg1_func_81003E00_14* temp_v0;
    unk_arg1_func_81003E00_04* temp_v0_2;

    if (arg0 == 2) {
        temp_v0 = arg1->unk_14;
        var_v1 = 0;
        if (D_8006F09C->unk_040.unk_00 == temp_v0->unk_00) {
            temp_a2 = ((s32) D_8006F09C->unk_040.unk_08 >> 0x10) & 0xFFFF;
            if ((temp_a2 >= (s32) temp_v0->unk_02) && ((s32) temp_v0->unk_04 >= temp_a2)) {
                var_v1 = 1;
            }
        }
        if (var_v1 == 1) {
            temp_v0_2 = arg1->unk_04;
            temp_v0_2->unk_01 |= 1;
            return;
        }
        temp_v0_2 = arg1->unk_04;
        temp_v0_2->unk_01 &= 0xFFFE;
    }
}

void func_81003E90(s32 arg0, unk_arg1_func_81003E00* arg1) {
    s32 temp_a2;
    s32 var_v1;
    unk_arg1_func_81003E00_14* temp_v0;
    unk_arg1_func_81003E00_04* temp_v0_2;

    if (arg0 == 2) {
        temp_v0 = arg1->unk_14;
        var_v1 = 1;
        if (D_8006F09C->unk_040.unk_00 == temp_v0->unk_00) {
            temp_a2 = ((s32) D_8006F09C->unk_040.unk_08 >> 0x10) & 0xFFFF;
            if ((temp_a2 >= (s32) temp_v0->unk_02) && ((s32) temp_v0->unk_04 >= temp_a2)) {
                var_v1 = 0;
            }
        }
        if (var_v1 == 1) {
            temp_v0_2 = arg1->unk_04;
            temp_v0_2->unk_01 |= 1;
            return;
        }
        temp_v0_2 = arg1->unk_04;
        temp_v0_2->unk_01 &= 0xFFFE;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2590C0/func_81003F20.s")
