#include "46680.h"

typedef struct unk_arg1_func_80045A80 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
} unk_arg1_func_80045A80; // size 0x10

typedef struct unk_arg1_func_80045D60 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
} unk_arg1_func_80045D60; // size 0x7

typedef struct AnimBlock19 {
    s16 xRotA;
    s16 xRotB;
    s16 flag0;
    s16 yRotA;
    s16 yRotB;
    s16 flag1;
    s16 zRotA;
    s16 zRotB;
    s16 flag2;
    s16 unkA;
    s16 unkB;
    s16 unkC;
    s16 unkD;
} AnimBlock19; // size 0x1A

typedef struct unk_arg0_func_80045A80 {
    char pad0[0x168];
    unk_arg1_func_80045A80 unk168[2];
    s16 unk188;       // 0x188
} unk_arg0_func_80045A80;

void func_80045A80(unk_arg0_func_80045A80* arg0, unk_arg1_func_80045A80* arg1, s32 arg2, s32 arg3) {
    unk_arg1_func_80045A80* temp_v0_2;

    temp_v0_2 = &arg0->unk168[arg0->unk188];
    temp_v0_2->unk0 = (s16) (((s32) ((((arg1->unk0 - 0x20) << 0xA) * 0x3333) + 0x4000) >> 0xF) * 2);
    temp_v0_2->unk2 = (s16) (((s32) ((((arg1->unk2 - 0x20) << 0xA) * 0x3333) + 0x4000) >> 0xF) * 2);
    temp_v0_2->unk4 = (s16) (((s32) ((((arg1->unk4 - 0x10) << 0xA) * 0x3333) - 0x0332F000) >> 0xF) * 2);
    temp_v0_2->unk6 = (s16) (((s32) ((((arg1->unk6 - 0x10) << 0xA) * 0x3333) + 0x04003C00) >> 0xF) * 2);
    temp_v0_2->unk8 = (s16) (((s32) ((((arg1->unk8 - 8) << 0xA) * 0x4B17) - 0x0036E4E4) >> 0xF) * 2);
    temp_v0_2->unkA = (s16) (((s32) ((((arg1->unkA - 8) << 0xA) * 0x4444) + 0x03BBF800) >> 0xF) * 2);
    temp_v0_2->unkC = (s16) (((s32) ((((arg1->unkC - 4) << 0xA) * 0x7ADE) + 0x0147936C) >> 0xF) * 2);
    temp_v0_2->unkE = (s16) (((s32) ((((arg1->unkE - 4) << 0xA) * 0x740C) + 0x040D6B40) >> 0xF) * 2);

    func_80048904((s32)arg0, arg2, arg3);
    arg0->unk188 ^= 1;
}

void func_80045C78(unk_arg0_func_80045A80* arg0, unk_arg1_func_80045A80* arg1, s16* arg2, s16* arg3, s16* arg4, s16* arg5, AnimBlock19* arg6, s32 arg7) {
    s32 i;
    s16 sp44[40];
    
    for (i = 0; i < 4; i++) {
        func_80048590(*arg5, *arg4, arg6, sp44);
        func_80048684(arg0, *arg2, *arg3, sp44);
        arg5++;
        arg3++;
        arg2++;
        arg4++;
        arg6++;
    }


    func_80045A80(arg0, arg1, arg0, arg7);
}

s32 func_80045D60(unk_arg0_func_80045A80* arg0, unk_arg1_func_80045D60* arg1, s32 arg2) {
    unk_arg1_func_80045A80 header;
    s16 spC8[4];
    s16 spC0[4];
    s16 spB8[4];
    s16 spB0[4];
    AnimBlock19 sp48[4];
    s32 i;

    header.unk0 = ((arg1[0].unk0 & 0xF) << 2) | ((arg1[0].unk1 >> 6) & 3);
    header.unk2 = arg1[0].unk1 & 0x3F;
    header.unk4 = (arg1[0].unk2 >> 3) & 0x1F;
    header.unk6 = ((arg1[0].unk2 & 7) << 2) | ((arg1[0].unk3 >> 6) & 3);
    header.unk8 = (arg1[0].unk3 >> 2) & 0xF;
    header.unkA = ((arg1[0].unk3 & 3) << 2) | ((arg1[0].unk4 >> 6) & 3);
    header.unkC = (arg1[0].unk4 >> 3) & 7;
    header.unkE = arg1[0].unk4 & 7;
    for (i = 0; i < 4; i++)  {
        spC8[i] = (arg1[i].unk5 >> 1) & 0x7F;
        spB8[i] = ((arg1[i].unk5 & 1) << 1) | ((arg1[i].unk6 >> 7) & 1);
        spC0[i] = (arg1[i].unk6 >> 5) & 3;
        spB0[i] = ((arg1[i].unk6 & 0x1F) << 1) | ((arg1[i + 1].unk0 >> 7) & 1);

        sp48[i].xRotA = (arg1[i + 1].unk0 >> 4) & 7;
        sp48[i].xRotB = (arg1[i + 1].unk0 >> 1) & 7;
        sp48[i].flag0 = ((arg1[i + 1].unk0 & 1) << 2) | ((arg1[i + 1].unk1 >> 6) & 3);
        sp48[i].yRotA = (arg1[i + 1].unk1 >> 3) & 7;
        sp48[i].yRotB = arg1[i + 1].unk1 & 7;
        sp48[i].flag1 = (arg1[i + 1].unk2 >> 5) & 7;
        sp48[i].zRotA = (arg1[i + 1].unk2 >> 2) & 7;
        sp48[i].zRotB = ((arg1[i + 1].unk2 & 3) << 1) | ((arg1[i + 1].unk3 >> 7) & 1);
        sp48[i].flag2 = (arg1[i + 1].unk3 >> 4) & 7;
        sp48[i].unkA = (arg1[i + 1].unk3 >> 1) & 7;
        sp48[i].unkB = ((arg1[i + 1].unk3 & 1) << 2) | ((arg1[i + 1].unk4 >> 6) & 3);
        sp48[i].unkC = (arg1[i + 1].unk4 >> 3) & 7;
        sp48[i].unkD = arg1[i + 1].unk4 & 7;
    }
    func_80045C78(arg0, &header, spC8, spB8, spC0, spB0, sp48, arg2);
    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/46680/func_80045FF0.s")
