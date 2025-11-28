#include "fragment31.h"
#include "12D80.h"

typedef struct unk_arg1_func_81002490 {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u32 unk_04;
} unk_arg1_func_81002490; // size >= 0x8

typedef struct unk_arg1_func_81002968 {
    /* 0x00 */ char unk00[0x14];
    /* 0x14 */ unk_arg1_func_81002490* unk_14;
    /* 0x18 */ Gfx* unk_18;
} unk_arg1_func_810024E4; // size >= 0x1C

void func_81002490(Gfx* gfx, unk_arg1_func_81002490* arg1) {
    if (D_8006F09C->unk_01C == 0) {
        gSPDisplayList(gfx++, arg1->unk_00);
    }
    gSPDisplayList(gfx++, arg1->unk_04);
    gSPEndDisplayList(gfx++);
}

void func_810024E4(s32 arg0, unk_arg1_func_810024E4* arg1) {
    s32 temp_v0;
    s32 sp18;

    if (arg0 == 2) {
        sp18 = arg1->unk_14;
        temp_v0 = func_80005F5C(0x50);
        arg1->unk_18 = temp_v0;
        func_81002490(temp_v0, sp18);
    }
}
