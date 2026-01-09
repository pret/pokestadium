#include "4A3E0.h"
#include "src/4B940.h"
#include "src/373A0.h"

typedef struct unk_D_800FD008 {
    /* 0x00 */ u16 unk_00[20];
    /* 0x28 */ u8 unk_28;
    /* 0x29 */ u8 unk_29;
    /* 0x2A */ u8 unk_2A;
    /* 0x2B */ char unk2B[1];
    /* 0x2C */ u8 unk_2C;
} unk_D_800FD008; // size >= 0x2D

typedef struct unk_D_800FD068 {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x06 */ u16 unk_06;
} unk_D_800FD068; // size = 0x8

extern unk_D_800FD008 D_800FD008;
extern unk_D_800FD068 D_800FD068[199];
extern u32 D_800FD6A8;
extern u8 D_800FD6E0;
extern u8 D_800FD6E1;
extern f32 D_800FD6E4;
extern u32 D_800FD6F0;
extern u32 D_800FD6F4;
extern s16 D_800FD6F8[0x1140];
extern u8 D_800FD6A0[8];
extern u32 D_800FD6AC;
extern u32 D_800FF978;
extern u8 D_800FF97C;
extern s32 D_800FF980;
void func_80049A60(u32);

void func_800497E0(s16* arg0, s32 arg1, u32 arg2, f32 arg3) {
    func_80049A60(arg2);
}

void func_8004980C(u16 arg0, u8 arg1, u16 arg2) {
    D_800FD068[D_800FD6AC].unk_00 = (u8*)&D_800FD008.unk_00[(arg0 & 0xFF) - 0x10];
    D_800FD068[D_800FD6AC].unk_04 = arg1;
    D_800FD068[D_800FD6AC].unk_06 = arg2 + 1;
    D_800FD6A0[arg0 & 0xFF] = arg1;
    D_800FD6AC++;
    D_800FD6AC %= 200;
    D_800FD068[D_800FD6AC].unk_06 = 0;
}

u8 func_80049890(u16 arg0) {
    return D_800FD6A0[arg0 & 0xFF];
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/4A3E0/func_800498A8.s")

void func_80049D5C(u16);
s16 func_80049DF0(void);
s16 func_8004A474(void);
s16 func_8004A89C(void);

#ifdef NON_MATCHING
void func_80049A60(u32 arg0) {
    s32 pad[3];
    s16 sp4C[4];
    u32 i;
    f32 var_fs0;
    s16 var_a0;
    u32 var_a2;
    u32 var_a3;
    u32 tmp2;
    s32 var_s4;
    u32 var_v1;
    s16 tmp;

    var_fs0 = 0.0f;
    var_s4 = 1;
    arg0 >>= 1;

    if (D_800FD6F4 < D_800FD6F0) {
        if ((0xB80 - (arg0 * 4)) < (D_800FD6F0 - D_800FD6F4)) {
            arg0++;
        }
    } else if ((D_800FD6F4 - D_800FD6F0) < (arg0 * 4)) {
        arg0++;
    }

    for (i = 0; i < arg0; i++) {
        if (var_fs0 <= i) {
            func_80049D5C(var_s4);
        }

        if (D_800FD008.unk_2C & 0x80) {
            if (D_800FD008.unk_29 != 0) {
                D_800FD6E0 = D_800FD008.unk_28 & 7;
                D_800FD6E1 = (D_800FD008.unk_28 & 0x70) >> 4;
                D_800FD008.unk_29 = 0;
            }

            sp4C[0] = func_80049DF0();
            sp4C[1] = func_8004A474();
            sp4C[3] = func_8004A89C();

            var_a0 =
                ((u32)((sp4C[0] & ((D_800FD008.unk_2A & 1) ? -1 : 0)) + (sp4C[1] & ((D_800FD008.unk_2A & 2) ? -1 : 0)) +
                       (sp4C[3] & ((D_800FD008.unk_2A & 8) ? -1 : 0))) >>
                 5) *
                (D_800FD6E0 + 1);
        } else {
            var_a0 = 0;
        }

        if (D_800FF97C != 0) {
            if (1) {}
            if (1) {}
            if (1) {}
            if (1) {}
            tmp = (f32)D_800FD6F8[((D_800FF978 - D_800FF980) + 0x1140) % 4416];

            var_a0 += (s16)(((tmp - var_a0) * D_800FF97C) >> 8);
            D_800FD6F8[D_800FF978++] = var_a0;
            if (D_800FF978 >= 0x1140) {
                D_800FF978 -= 0x1140;
            }
        }

        D_800FC6D8[D_800FD6F4 + 0] = var_a0;
        D_800FC6D8[D_800FD6F4 + 1] = var_a0;

        D_800FD6F4 += 2;
        if (D_800FD6F4 >= 0xB80) {
            D_800FD6F4 -= 0xB80;
        }

        var_s4++;
        var_fs0 += D_800FD6E4;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/4A3E0/func_80049A60.s")
#endif

void func_80049D5C(u16 arg0) {
    while (D_800FD068[D_800FD6A8].unk_06 >= arg0) {
        D_800FD068[D_800FD6A8].unk_00[0] = D_800FD068[D_800FD6A8].unk_04;
        D_800FD068[D_800FD6A8].unk_00[1] = 1;
        D_800FD6A8++;
        if (D_800FD6A8 >= 0xC8) {
            D_800FD6A8 -= 0xC8;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/4A3E0/func_80049DF0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/4A3E0/func_8004A474.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/4A3E0/func_8004A89C.s")

void func_8004AC9C(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800FD6F8); i++) {
        D_800FD6F8[i] = 0;
    }
    D_800FF978 = 0;
}

void func_8004ACD0(void) {
    s32 i;

    for (i = 0; i < 0xB80; i++) {
        D_800FC6D8[i] = 0;
    }
    D_800FD6F0 = 0;
    D_800FD6F4 = 0;
}

void func_8004AD2C(void) {

}
