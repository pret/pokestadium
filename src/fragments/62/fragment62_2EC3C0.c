#include "fragment62.h"
#include "src/17300.h"
#include "src/18140.h"
#include "src/1C720.h"
#include "src/232C0.h"
#include "src/2E110.h"
#include "src/2E460.h"
#include "src/373A0.h"
#include "src/3FB0.h"
#include "src/485C0.h"
#include "src/48C60.h"
#include "src/4BDC0.h"
#include "src/4F410.h"
#include "src/F420.h"
#include "src/memory.h"

static unk_D_8438E7B0 D_8438E7B0;
static unk_D_8438E7B0 D_8438F390;
static unk_D_8438FF70 D_8438FF70;
static unk_D_8438FF70 D_8438FF90;
static unk_D_8438FF70 D_8438FFB0;
static unk_D_8438FF70 D_8438FFD0;
static unk_D_84384588 D_8438FFF0;
static unk_D_84384588 D_84390000;
unk_D_84390010* D_84390010[2];
unk_D_84390010* D_84390018;
unk_D_84390010* D_8439001C;
static unk_D_8438E7B0_A50* D_84390020;
unk_D_84390028 D_84390028[2];
static unk_D_84390048 D_84390048;
static unk_D_84390068 D_84390068[7];
static s32 D_843900A0;
static s32 D_843900A4;
f32 D_843900A8[2];

unk_D_8438E7B0* D_84384570[] = { &D_8438E7B0, &D_8438F390 };
unk_D_8438FF70* D_84384578[] = {
    &D_8438FF70,
    &D_8438FF90,
};
unk_D_8438FF70* D_84384580[] = {
    &D_8438FFB0,
    &D_8438FFD0,
};
unk_D_84384588* D_84384588[] = { &D_8438FFF0, &D_84390000 };
u8 D_84384590[] = { 0x39, 0x67, 0x64, 0x6D, 0x28, 0x6E, 0x2A, 0x47 };
static u8 D_84384598[] = { 0x64, 0x6E };
static u8 D_8438459C[] = {
    0x06, 0x0C, 0x30, 0x31, 0x32, 0x33, 0x8D, 0x96, 0x97,
};
static u8 D_843845A8[] = {
    0x06,
    0x2E,
};
static u8 D_843845AC[] = {
    0x06,
    0x42,
};
static u8 D_843845B0[] = {
    0x06,
    0x42,
};
static u8 D_843845B4[] = {
    0x06,
    0x42,
};
static u8 D_843845B8[] = {
    0x06,
    0x06,
};
static u8 D_843845BC[] = {
    0x06,
    0x06,
};
static u8 D_843845C0[] = {
    0x06,
    0x16,
};
static u8 D_843845C4[] = {
    0x01,
    0x7F,
};
static u8 D_843845C8[] = {
    0x06,
    0x7F,
};
static u8* D_843845CC[] = {
    D_843845A8, D_843845AC, D_843845B0, D_843845B4, D_843845B8, D_843845BC, D_843845C0, D_843845C4, D_843845C8,
};
u8 D_843845F0 = 0x8E;
u8 D_843845F4 = 0x16;
u8 D_843845F8 = 0x53;
u8 D_843845FC[] = { 0x55, 0x54 };

void func_84301B00(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        D_84390068[i].unk_04 = D_84385380;
    }
}

void func_84301B48(unk_D_84390010* arg0, s32 arg1) {
    func_8432C68C(arg1, &arg0->unk_000, &arg0->unk_000, 0xFF, 0xFF);
}

void func_84301B84(unk_D_84390010* arg0, s32 arg1) {
    UNUSED s16 pad;
    s16 sp24;
    s32 sp20;

    sp20 = func_84307F00(arg0) == 0;
    sp24 = func_84307F24(arg0);
    func_8432C5D4(arg1, arg0, D_84390010[sp20], sp24, func_84307F68(arg0));
}

void func_84301BEC(unk_D_84390010* arg0, s32 arg1) {
    UNUSED s16 pad;
    s16 sp24;
    s32 sp20;

    sp20 = func_84307F00(arg0) == 0;
    sp24 = func_84307F24(arg0);
    func_8432C654(arg1, arg0, D_84390010[sp20], sp24, func_84307F68(arg0));
}

void func_84301C54(unk_D_84390010* arg0, s32 arg1) {
    UNUSED s16 pad;
    s16 sp24;
    s32 sp20;

    sp20 = func_84307F00(arg0) == 0;
    sp24 = func_84307FAC(arg0);
    func_8432C604(arg1, D_84390010[sp20], arg0, sp24, func_84307FE0(arg0));
}

void func_84301CBC(unk_D_84390010* arg0) {
    if (func_84302000(arg0) != 0) {
        arg0->unk_4C4 = 0;
        D_84390068[D_843900A0].unk_04 = D_84385380;
    }
}

void func_84301D08(unk_D_84390010* arg0) {
    UNUSED s32 pad;
    s32 idx = arg0->unk_4C0;
    s32 sp24 = D_84385384[idx].unk_20;

    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[sp24];
    if (func_84302000(arg0) != 0) {
        func_84305A74(arg0, sp24, 2);
        arg0->unk_4C4 = 0;
        D_84390068[D_843900A0].unk_04 = D_84385380;
        func_80017464(&arg0->unk_000, 0);
        func_8001BD04(&arg0->unk_000, D_84390020->unk_00);
    }
}

void func_84301DDC(unk_D_84390010* arg0) {
    s32 idx = arg0->unk_4C0;
    s32 sp28 = D_84385384[idx].unk_20;

    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[sp28];
    if (func_84307BAC(arg0) != 0.0f) {
        D_84390068[D_843900A0].unk_04 = D_84385380;
    } else if ((arg0->unk_4C4 == (D_84390020->unk_04 + 1)) && (func_84301FB0(arg0) == 0)) {
        func_84301B48(arg0, D_84385384[idx].unk_24);
        D_84390068[D_843900A0].unk_04 = D_84385380;
    }
}

void func_84301EEC(unk_D_84390010* arg0) {
    arg0->unk_4C4 = 0;
}

void func_84301EF4(unk_D_84390010* arg0) {
    D_84390010[func_84307F00(arg0) == 0]->unk_4C4 = 0;
}

void func_84301F2C(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* ptr = &arg0->unk_654.unk_38;

    if (ptr->unk_5A == 0x46 || ptr->unk_5A == 0x9D || ptr->unk_5A == 0x58) {
        D_84390010[0]->unk_000.unk_000.unk_02 |= 2;
        D_84390010[1]->unk_000.unk_000.unk_02 |= 2;
    }
}

void func_84301F80(unk_D_84390010* arg0) {
    D_84390010[0]->unk_000.unk_000.unk_02 &= ~2;
    D_84390010[1]->unk_000.unk_000.unk_02 &= ~2;
}

s32 func_84301FB0(unk_D_84390010* arg0) {
    return arg0->unk_720->unk_1D & 0xD0;
}

s32 func_84301FC0(unk_D_84390010* arg0) {
    func_8001C2D8(arg0->unk_720);
    return arg0->unk_720->unk_1D & 0xC0;
}

s32 func_84301FF0(unk_D_84390010* arg0) {
    return arg0->unk_720->unk_00 & 0xD0;
}

s32 func_84302000(unk_D_84390010* arg0) {
    if (func_84301FC0(arg0) == 0) {
        func_8432CAA8(arg0->unk_720);
        return 1;
    }
    return 0;
}

void func_8430203C(unk_D_84390010* arg0) {
    if (D_84390240.unk_00->unk_48 == 0xE) {
        func_8432C958(arg0->unk_720, func_8430808C(arg0));
    } else {
        func_8432C958(arg0->unk_720, func_8430808C(arg0));
    }
}

void func_843020B0(unk_D_84390010* arg0) {
    s32 idx = arg0->unk_4C0;

    func_8432C9C0(arg0->unk_720, D_84385384[idx].unk_24);
}

void func_843020F4(unk_D_84390010* arg0) {
    func_8432C958(arg0->unk_720, func_8430808C(arg0));
}

void func_84302128(unk_D_84390010* arg0) {
    arg0->unk_720->unk_02 = 0x98;
    arg0->unk_720->unk_00 |= 0x80;
}

void func_84302148(unk_D_84390010* arg0) {
    arg0->unk_720->unk_04 = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];
    arg0->unk_720->unk_00 |= 0x80;
    arg0->unk_720->unk_02 = arg0->unk_654.unk_BC;
}

s32 func_84302194(u16 arg0, u8* arg1, s32 arg2) {
    s32 var_v1 = 0;

    while (arg2--) {
        if (arg0 == *arg1) {
            return var_v1;
        }
        arg1++;
        var_v1++;
    }

    return -1;
}

void func_843021E8(unk_D_84390010* arg0, u16 arg1, unk_D_84390010_94C* arg2, unk_D_84390010_94C* arg3) {
    s32 i;
    s32 j;
    s32 temp_v0_3;
    s32 temp_v1_2;
    u8 var_a0;
    unk_D_80070F84* temp_s4;
    unk_D_84390010_654_038* temp_s5;

    temp_s5 = &arg0->unk_654.unk_38;

    for (i = 0; i < 4; i++) {
        if (temp_s5->unk_1F[i] != 0) {
            temp_s4 = &D_80070FA0[arg1];

            for (j = 0; j < 4; j++) {
                if ((temp_s4->unk_0A[j] != 0) && (temp_s4->unk_0A[j] == temp_s5->unk_1F[i])) {
                    arg0->unk_654.unk_C1[i] = 0;
                }
            }

            for (j = 0; j < 10; j++) {
                if ((arg2->unk_00[j] != 0) && (temp_s5->unk_26 >= arg2->unk_00[j]) &&
                    (arg2->unk_0A[j] == temp_s5->unk_1F[i])) {
                    arg0->unk_654.unk_C1[i] = 0;
                }
            }

            for (j = 0; j < 10; j++) {
                if ((arg3->unk_00[j] != 0) && (temp_s5->unk_26 >= arg3->unk_00[j]) &&
                    (arg3->unk_0A[j] == temp_s5->unk_1F[i])) {
                    arg0->unk_654.unk_C1[i] = 0;
                }
            }

            for (j = 0; j < 0x37; j++) {
                temp_v0_3 = func_84302194(arg1 + 1, D_8438459C, 9);
                if (temp_v0_3 >= 0) {
                    temp_v1_2 = j / 8;
                    if (temp_v1_2 == D_843845CC[temp_v0_3][0]) {
                        var_a0 = temp_s4->unk_0F[temp_v1_2] | D_843845CC[temp_v0_3][1];
                    } else {
                        var_a0 = temp_s4->unk_0F[temp_v1_2];
                    }
                } else {
                    var_a0 = temp_s4->unk_0F[j / 8];
                }

                if (((var_a0 >> (j % 8)) & 1) && (func_80022A28(j) == temp_s5->unk_1F[i])) {
                    arg0->unk_654.unk_C1[i] = 0;
                }
            }
        } else {
            arg0->unk_654.unk_C1[i] = 0;
        }
    }
}

void func_8430245C(unk_D_84390010* arg0) {
    arg0->unk_654.unk_C1[0] = 1;
    arg0->unk_654.unk_C1[1] = 1;
    arg0->unk_654.unk_C1[2] = 1;
    arg0->unk_654.unk_C1[3] = 1;

    func_843021E8(arg0, arg0->unk_654.unk_38.unk_0B - 1, &arg0->unk_94C, &arg0->unk_9AC);

    if (D_84384588[func_84307F00(arg0)]->unk_00 != 0) {
        func_843021E8(arg0, D_84384588[func_84307F00(arg0)]->unk_00 - 1, &arg0->unk_96C, &arg0->unk_9CC);
    }

    if (D_84384588[func_84307F00(arg0)]->unk_01 != 0) {
        func_843021E8(arg0, D_84384588[func_84307F00(arg0)]->unk_01 - 1, &arg0->unk_98C, &arg0->unk_9EC);
    }
}

void func_8430255C(u8 arg0, u32 arg1) {
    u32 temp_a1 = (u32)_70D3A0_ROM_START + ((u32)&D_72780[arg0 - 1] & 0xFFFFFF);

    func_80003B30(arg1, temp_a1, temp_a1 + 0x20, 0);
}

void func_843025BC(s32 arg0, unk_D_84390010_94C* arg1, unk_D_84390010_94C* arg2) {
    UNUSED s32 pad[3];
    u32 temp_a1;

    temp_a1 = (u32)_70D3A0_ROM_START + ((u32)&D_72780[arg0] & 0xFFFFFF);
    func_80003B30(arg1, temp_a1, temp_a1 + 0x20, 0);
    temp_a1 = (u32)_70D3A0_ROM_START + ((u32)&D_73A60[arg0] & 0xFFFFFF);
    func_80003B30(arg2, temp_a1, temp_a1 + 0x20, 0);
}

#ifdef NON_MATCHING
void func_84302658(unk_D_84390010* arg0, s32 arg1) {
    s16 sp6E;
    s32 sp68;
    s16 sp66;
    u32 var_a1;
    s32 pad[8];
    unk_func_80026268_arg0* ptr;
    unk_D_8438FF70* ptr2;
    u32 tmp;
    s32 var_a2;

    sp68 = func_84307F00(arg0);
    sp66 = arg0->unk_000.unk_01A - 1;

    ptr = &arg0->unk_720->unk_08[arg0->unk_654.unk_2C]->unk_01C[arg0->unk_654.unk_18];

    var_a1 = (u32)_70D3A0_ROM_START + ((u32)D_80075BD0[sp66] & 0xFFFFFF);
    if ((arg0->unk_000.unk_01A == 0x19) && (ptr->unk_52 & 0x80)) {
        var_a1 = (u32)_70D3A0_ROM_START + ((u32)D_80075BD0[152] & 0xFFFFFF);
    }
    func_80003B30(D_84384570[sp68], var_a1, var_a1 + 0xBC0, 0);

    var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_6E910 + (sp66 << 5)) & 0xFFFFFF);
    func_80003B30(D_84384580[sp68], var_a1, var_a1 + 0x20, 0);

    if (sp68 == 1) {
        var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_6E910 + (sp66 << 5)) & 0xFFFFFF);
        func_80003B30(D_84384578[sp68], var_a1, var_a1 + 0x20, 0);

        ptr2 = D_84384578[sp68];
        if (ptr2->unk_10 != 0xFF) {
            sp6E = ptr2->unk_10;

            var_a1 = ((u32)_70D3A0_ROM_START) + (((u32)(D_6E910 + ((ptr2->unk_10 - (tmp = 2)) * 0x20))) & 0xFFFFFF);
            func_80003B30(ptr2, var_a1, var_a1 + 0x20, 0);

            D_84384578[sp68]->unk_10 = sp6E;
        }
    } else {
        var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_6E910 + (sp66 << 5)) & 0xFFFFFF);
        func_80003B30(D_84384578[sp68], var_a1, var_a1 + 0x20, 0);
    }

    var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_70B10 + (sp66 * 0x20)) & 0xFFFFFF);
    func_80003B30(&D_84390048, var_a1, var_a1 + 0x20, 0);

    func_8430C1E4(&arg0->unk_448.unk_24.unk_00, &D_84390048.unk_00);
    func_8430C1E4(&arg0->unk_448.unk_24.unk_0C, &D_84390048.unk_0C);

    arg0->unk_448.unk_24.unk_18 = D_84390048.unk_18;
    arg0->unk_448.unk_24.unk_19 = D_84390048.unk_19;
    arg0->unk_448.unk_24.unk_1A = D_84390048.unk_1A;
    arg0->unk_448.unk_24.unk_1B = D_84390048.unk_1B;
    arg0->unk_448.unk_24.unk_00.x *= arg0->unk_4B0;
    arg0->unk_448.unk_24.unk_0C.x *= arg0->unk_4B0;

    var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_70110 + (sp66 << 4)) & 0xFFFFFF);
    func_80003B30(&D_84390028[sp68], var_a1, var_a1 + 0x10, 0);

    var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_71E10 + (sp66 * 0x10)) & 0xFFFFFF);
    func_80003B30(D_84384588[sp68], var_a1, var_a1 + 0x10, 0);

    func_843025BC(sp66, &arg0->unk_94C, &arg0->unk_9AC);

    if (D_84384588[sp68]->unk_00 != 0) {
        func_843025BC(D_84384588[sp68]->unk_00 - 1, &arg0->unk_96C, &arg0->unk_9CC);
    }

    if (D_84384588[sp68]->unk_01 != 0) {
        func_843025BC(D_84384588[sp68]->unk_01 - 1, &arg0->unk_98C, &arg0->unk_9EC);
    }

    if (arg1 == 1) {
        func_8430245C(arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/62/fragment62_2EC3C0/func_84302658.s")
#endif

void func_843029D0(unk_D_84390010* arg0) {
    if (arg0->unk_4C4 == 0x14) {
        arg0->unk_720->unk_00 |= 0x80;
    }

    if (arg0->unk_720->unk_00 & 0x10) {
        arg0->unk_720->unk_00 &= ~0x90;
        func_8430920C(arg0);
        func_84307748(arg0);
        func_800367A0(2, 0, 0);
        D_84390068[D_843900A0].unk_04 = D_84385380;
        func_84305760(arg0, 0x12);
    }
}

void func_84302A78(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* sp24;
    unk_D_84390010_654* sp20;
    s32 idx;
    s16 sp2A;
    u8 tmp;

    sp2A = arg0->unk_000.unk_01A - 1;
    sp24 = &arg0->unk_654.unk_38;
    sp20 = &arg0->unk_654;
    idx = func_84307F00(arg0);

    D_84390020 = &D_84384570[idx]->unk_000[sp24->unk_5A - 1];

    if (!(sp20->unk_34 & 2)) {
        arg0->unk_4C4 = 0;

        if (func_84307B60(arg0) != 0) {
            tmp = func_84307F00(arg0);
            func_80048060(tmp, sp24->unk_5A, 0xC8, 0);
        } else {
            tmp = func_84307F00(arg0);
            func_80048060(tmp, sp24->unk_5A, sp2A + 1, 0);
        }

        if ((sp20->unk_34 & 0x4000) && ((sp2A == 0x32) || (sp2A == 0x31))) {
            func_84306200(arg0, 8);
            arg0->unk_000.unk_000.unk_02 |= 0x20;
            func_843061EC(arg0, 0x10);
            func_84306200(arg0, 0x4000);
        }

        func_84301F2C(arg0);
        func_8001BD04(&arg0->unk_000, D_84390020->unk_00);
        func_843058C4(arg0, sp24->unk_5A - 1);

        if (D_84390020->unk_0B != 0) {
            func_80017464(&arg0->unk_000, D_84390020->unk_0B);
            func_80017804(&arg0->unk_000, D_84390020->unk_0B);
            arg0->unk_4C4 = D_84390020->unk_0B;
        } else {
            func_80017464(&arg0->unk_000, 0);
        }
    }
}

void func_84302C34(unk_D_84390010* arg0) {
    UNUSED s32 pad;
    s16 sp32 = arg0->unk_000.unk_01A - 1;
    unk_D_84390010_654_038* sp24;

    func_84307F00(arg0);
    sp24 = &arg0->unk_654.unk_38;
    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[sp24->unk_5A - 1];

    if ((sp24->unk_5A == 0x19) && (sp32 == 0x64)) {
        D_84390068[D_843900A0].unk_04 = D_84385380;
    } else if ((arg0->unk_4C4 == (D_84390020->unk_04 + 1)) && (func_84301FB0(arg0) == 0)) {
        if (D_84390240.unk_00->unk_48 == 0x14) {
            D_84390068[D_843900A0].unk_04 = D_84385380;
        } else if (sp24->unk_44.unk_00 == 0x5B) {
            D_84390068[D_843900A0].unk_04 = D_84385380;
        } else {
            if (sp24->unk_44.unk_00 == 0x6E) {
                if ((sp32 != 7) && (sp32 != 8) && (sp32 != 0x5A) && (sp32 != 6)) {
                    func_84308654(arg0, 0xC, 0);
                    func_84301B84(arg0, sp24->unk_5A);
                }
            } else {
                if (sp24->unk_44.unk_00 == 0x45) {
                    func_84308654(arg0, 8, 0);
                } else if (sp24->unk_44.unk_00 == 0x39) {
                    func_84308654(arg0, 0xA, 0);
                } else if (sp24->unk_44.unk_00 == 0x60) {
                    func_84308654(arg0, 0xD, 0);
                } else if (sp24->unk_44.unk_00 == 0x7F) {
                    func_84308654(arg0, 0xE, 0);
                } else if (sp24->unk_44.unk_00 == 0x6B) {
                    func_84308654(arg0, 9, 0);
                } else {
                    func_84308654(arg0, D_84390020->unk_05, 0);
                }

                if ((sp24->unk_5A == 0x9A) && (D_84390230 == D_8439022C)) {
                    func_84301BEC(arg0, sp24->unk_5A);
                } else {
                    func_84301B84(arg0, sp24->unk_5A);
                }
            }
            D_84390068[D_843900A0].unk_04 = D_84385380;
        }
    }
}

void func_84302EF0(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* sp24 = &arg0->unk_654.unk_38;

    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[sp24->unk_5A - 1];

    if (arg0->unk_4C4 == (D_84390020->unk_04 + 1)) {
        if (func_84301FB0(arg0) == 0) {
            if (D_84390240.unk_00->unk_48 == 0x18) {
                D_84390234--;
                if (D_84390234 < 0) {
                    if (D_843C4DA4 != 0) {
                        func_8432B5B8(arg0, sp24, 2);
                    }
                } else {
                    func_8432B5B8(arg0, sp24, 3);
                }
            } else if (D_843C4DA4 != 0) {
                func_8432B5B8(arg0, sp24, 2);
            } else {
                if ((sp24->unk_5A == 0x2D) || (sp24->unk_5A == 0x2E) || (sp24->unk_5A == 0x59)) {
                    func_8431B290(arg0);
                }
                func_8432B5B8(arg0, sp24, 0);
                func_843031A0(arg0);
            }
            D_84390068[D_843900A0].unk_04 = D_84385380;
        }
    }
}

void func_8430305C(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* sp24 = &arg0->unk_654.unk_38;
    UNUSED s16 pad;
    s16 sp18;

    sp18 = sp24->unk_5A;
    func_84307F00(arg0);
    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[sp24->unk_5A - 1];

    if (arg0->unk_4C4 == (D_84390020->unk_09 + 1)) {
        if (func_84301FB0(arg0) == 0) {
            if (((sp18 == 0x4A) || (sp18 == 0x60) || (sp18 == 0x61) || (sp18 == 0x6A) || (sp18 == 0x6E) ||
                 (sp18 == 0xE) || (sp18 == 0x68) || (sp18 == 0x6B) || (sp18 == 0x6F) || (sp18 == 0x70) ||
                 (sp18 == 0x85) || (sp18 == 0x97) || (sp18 == 0x9F)) &&
                (D_843C4E45 == 1)) {
                func_8432C6C4(3, arg0);
                func_800367A0(0x23, 0, 0);
            }
            D_84390068[D_843900A0].unk_04 = D_84385380;
        }
    }
}

void func_843031A0(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* temp_v1 = &arg0->unk_654.unk_38;

    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[temp_v1->unk_5A - 1];

    if (temp_v1->unk_5A == 0x6A) {
        func_8001BE84(&arg0->unk_000, 1);
    }
}

void func_84303208(unk_D_84390010* arg0) {
    UNUSED s32 pad[2];
    unk_D_84390010_654* temp_v1 = &arg0->unk_654;
    s16 sp22;

    sp22 = arg0->unk_000.unk_01A - 1;
    D_84390020 = D_84384570[func_84307F00(arg0)]->unk_000;

    if (!(temp_v1->unk_34 & 2)) {
        arg0->unk_4C4 = 0;
        if ((temp_v1->unk_34 & 0x4000) && ((sp22 == 0x32) || (sp22 == 0x31))) {
            func_84306200(arg0, 8);
            arg0->unk_000.unk_000.unk_02 |= 0x20;
            func_843061EC(arg0, 0x10);
            func_84306200(arg0, 0x4000);
        }
        func_8001BD04(&arg0->unk_000, D_84390020->unk_00);
        func_80017464(&arg0->unk_000, 0);
        func_843058C4(arg0, 4);

        if (D_84390020->unk_0B != 0) {
            func_80017464(&arg0->unk_000, D_84390020->unk_0B);
            func_80017804(&arg0->unk_000, D_84390020->unk_0B);
            arg0->unk_4C4 = D_84390020->unk_0B;
        } else {
            func_80017464(&arg0->unk_000, 0);
        }
    }
}

void func_8430334C(unk_D_84390010* arg0) {
    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[0];
    if ((arg0->unk_4C4 == (D_84390020->unk_04 + 1)) && (func_84301FB0(arg0) == 0)) {
        func_800479C0(1, arg0->unk_000.unk_01A, 0);
        D_84390068[D_843900A0].unk_04 = D_84385380;
    }
}

void func_843033E0(unk_D_84390010* arg0) {
    unk_D_84390010_654* sp20;
    unk_D_84390010_654_038* ptr;

    sp20 = &arg0->unk_654;
    ptr = &arg0->unk_654.unk_38;
    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[ptr->unk_5A - 1];

    if (sp20->unk_34 & 2) {
        return;
    }

    arg0->unk_4C4 = D_84390020->unk_06;
    if (!(sp20->unk_34 & 0x4000)) {
        func_84301F2C(arg0);
        func_8001BD04(&arg0->unk_000, D_84390020->unk_00);
        func_80017464(&arg0->unk_000, D_84390020->unk_06);
        if (D_84390020->unk_01 != 0xFF) {
            func_8001BD9C(&arg0->unk_000, D_84390020->unk_01);
            func_80017804(&arg0->unk_000, D_84390020->unk_06);
            sp20->unk_36 = 1;
        }
    }
}

void func_843034D8(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* sp20;
    s32 var_v0;

    sp20 = &arg0->unk_654.unk_38;
    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[sp20->unk_5A - 1];
    if (sp20->unk_5A == 0x9A) {
        var_v0 = D_84390020->unk_04 + 0x1E;
    } else {
        var_v0 = D_84390020->unk_04 + 1;
    }

    if ((var_v0 == arg0->unk_4C4) && (func_84301FB0(arg0) == 0)) {
        if (D_84390240.unk_00->unk_48 == 0x14) {
            D_84390068[D_843900A0].unk_04 = D_84385380;
            return;
        }

        if ((sp20->unk_5A == 0x9A) && (D_84390230 == D_8439022C)) {
            func_84301BEC(arg0, sp20->unk_5A);
        } else {
            func_84301B84(arg0, sp20->unk_5A);
        }

        if (sp20->unk_44.unk_00 == 0x45) {
            func_84308654(arg0, 8, 0);
        } else if (sp20->unk_44.unk_00 == 0x39) {
            func_84308654(arg0, 0xA, 0);
        } else {
            func_84308654(arg0, D_84390020->unk_05, 0);
        }
        D_84390068[D_843900A0].unk_04 = D_84385380;
    }
}

void func_84303674(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* sp18;
    s32 var_v0;

    sp18 = &arg0->unk_654.unk_38;
    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[sp18->unk_5A - 1];

    if (sp18->unk_5A == 0x9A) {
        var_v0 = D_84390020->unk_04 + 0x1E;
    } else {
        var_v0 = D_84390020->unk_04 + 1;
    }

    if (var_v0 == arg0->unk_4C4) {
        if (func_84301FB0(arg0) == 0) {
            if (D_84390240.unk_00->unk_48 == 0x18) {
                D_84390234--;
                if (D_84390234 < 0) {
                    if (D_843C4DA4 != 0) {
                        func_8432B5B8(arg0, sp18, 2);
                    } else {
                        func_8432B5B8(arg0, sp18, 0);
                    }
                } else {
                    func_8432B5B8(arg0, sp18, 3);
                }
            } else if (D_843C4DA4 != 0) {
                func_8432B5B8(arg0, sp18, 2);
            } else {
                func_8432B5B8(arg0, sp18, 0);
            }
            D_84390068[D_843900A0].unk_04 = D_84385380;
        }
    }
}

void func_843037CC(unk_D_84390010* arg0) {
    UNUSED s32 pad[3];
    s32 sp40;
    unk_D_84390010_654* sp3C;
    UNUSED s32 pad2;
    s32 temp_v0;
    unk_D_84390010_654_038* sp28;
    unk_D_84390010* temp_a1;

    sp28 = &arg0->unk_654.unk_38;
    sp40 = func_84307F00(arg0) == 0;
    sp3C = &D_84390010[sp40]->unk_654;
    temp_a1 = D_84390010[sp40];
    D_84390020 = &D_84384570[sp40]->unk_A80;

    if (sp3C->unk_34 & 1) {
        temp_v0 = func_84307AE0(temp_a1->unk_000.unk_01A, D_84384598, 2);
        if (temp_v0 != 0) {
            D_84390020 = &D_84384570[sp40]->unk_B20;
        }
    }

    D_84390010[sp40]->unk_4C4 = 0;

    if (!(sp3C->unk_34 & 0x200) && !(sp3C->unk_34 & 0x4000) && !(sp3C->unk_34 & 2)) {
        if (((D_843C4DEC.unk_00 < 0xA) || (D_843C4DA4 != 0)) && ((sp28->unk_15 & 0x20) == 0)) {
            D_84390020 = &D_84384570[sp40]->unk_A50;
            if (sp3C->unk_34 & 0x200) {
                D_84390020 = &D_84384570[sp40]->unk_B00;
            }
        } else if (!(sp3C->unk_34 & 1)) {
            func_84305A74(D_84390010[sp40], 0xA8, 1);
        }

        if ((D_843C4DEC.unk_00 >= 0xB) && (func_84307B60(D_84390010[sp40]) != 0)) {
            func_8004E810(0xC8, 6);
        }

        if ((D_843C4DEC.unk_00 == 0xA) && (func_84307B60(D_84390010[sp40]) != 0)) {
            func_8004E810(0xC8, 5);
        }

        if ((D_843C4DA4 == 0) && (sp28->unk_5A == 0x49)) {
            D_84390020 = &D_84384570[sp40]->unk_A80;
        }

        func_80017464(&D_84390010[sp40]->unk_000, 0);
        func_8001BD04(&D_84390010[sp40]->unk_000, D_84390020->unk_00);

        if ((sp28->unk_44.unk_00 == 0x17) || (sp28->unk_44.unk_00 == 0x22) || (sp28->unk_44.unk_00 == 0x45)) {
            func_84308654(D_84390010[sp40], 0xF, 0);
        }
    }
}

void func_84303A48(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* sp20;
    s32 sp28;

    sp20 = &arg0->unk_654.unk_38;
    sp28 = func_84307F00(arg0);

    D_84390020 = &D_84384570[func_84307F00(arg0) == 0]->unk_000[sp20->unk_5A - 1];

    if (D_84390010[sp28 == 0]->unk_4C4 == (D_84390020->unk_07 + 1)) {
        if (func_84301FB0(arg0) == 0) {
            func_8432E9D8(1);
            if (sp20->unk_44.unk_00 == 0x51) {
                if ((D_843C4E45 != 0) && (D_843C4E44 != 0)) {
                    func_84301C54(D_84390010[sp28 == 0], sp20->unk_5A);
                    func_84308654(D_84390010[sp28 == 0], 0x10, 0);
                }
            } else {
                func_84301C54(D_84390010[sp28 == 0], sp20->unk_5A);
                if ((sp20->unk_44.unk_00 == 0x14) || (sp20->unk_44.unk_00 == 0x23) || (sp20->unk_44.unk_00 == 0x84)) {
                    func_84308654(D_84390010[sp28 == 0], 0x10, 0);
                }
            }
            D_84390068[D_843900A0].unk_04 = D_84385380;
        }
    }
}

void func_84303BB8(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* sp20;
    s32 sp28;

    sp28 = func_84307F00(arg0) == 0;
    sp20 = &arg0->unk_654.unk_38;

    D_84390020 = &D_84384570[func_84307F00(arg0) == 0]->unk_000[sp20->unk_5A - 1];

    if ((D_84390020->unk_07 + 1) == D_84390010[sp28]->unk_4C4) {
        if (func_84301FB0(arg0) == 0) {
            if (D_843C4E44 == 1) {
                func_8432B5B8(D_84390010[sp28], sp20, 1);
            } else {
                func_8432B5B8(D_84390010[sp28], sp20, 5);
            }
            D_84390068[D_843900A0].unk_04 = D_84385380;
        }
    }
}

void func_84303CB4(unk_D_84390010* arg0) {
    s32 sp1C = func_84307F00(arg0);

    D_84390020 = &D_84384570[sp1C]->unk_A80;
    D_84390010[sp1C]->unk_4C4 = 0;
    func_80017464(&arg0->unk_000, 0);
    func_8001BD04(&arg0->unk_000, D_84390020->unk_00);
    func_84305A74(D_84390010[sp1C], 0xA8, 1);
    func_8432BF88(arg0, 0x1E);
}

s32 func_84303D50(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* sp1C;

    sp1C = &D_84390010[func_84307F00(arg0) == 0]->unk_654.unk_38;
    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[sp1C->unk_5A - 1];
    if (D_84390020->unk_0C != 0) {
        if (arg0->unk_4C4 == D_84390020->unk_0C) {
            return 1;
        }
        return 0;
    }
    return 0;
}

s32 func_84303DEC(unk_D_84390010* arg0) {
    func_84307F00(arg0);
    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[0];
    if (D_84390020->unk_0C != 0) {
        if (arg0->unk_4C4 == D_84390020->unk_0C) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void func_84303E58(unk_D_84390010* arg0) {
    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_A80;
    func_843058C4(arg0, 0xA8);
    arg0->unk_4C4 = 0;
    func_80017464(&arg0->unk_000, 0);
    func_8001BD04(&arg0->unk_000, D_84390020->unk_00);
}

void func_84303ECC(unk_D_84390010* arg0) {
    s32 idx = arg0->unk_4C0;
    s32 temp_a0;
    s32 sp34;
    unk_func_80026268_arg0* sp30;
    unk_D_84390010_654* sp24;

    sp34 = D_84385384[idx].unk_20;
    sp30 = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];
    sp24 = &arg0->unk_654;
    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[sp34];
    temp_a0 = sp24->unk_34 & 2;

    if ((temp_a0 == 0) && !(sp24->unk_34 & 0x4000) && (temp_a0 == 0)) {
        if (sp30->unk_05 & 7) {
            if (func_84307AE0(arg0->unk_000.unk_01A, D_84384590, 8) != 0) {
                D_84390020 = &D_84384570[func_84307F00(arg0)]->unkA90[0x60];
            } else {
                D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_A50;
            }
        } else if (sp24->unk_34 & 0x200) {
            D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_B00;
        }

        func_80017464(&arg0->unk_000, 0);
        func_8001BD04(&arg0->unk_000, D_84390020->unk_00);

        if (sp24->unk_34 & 0x200) {
            if (func_84307B60(arg0) != 0) {
                func_80048060(func_84307F00(arg0) & 0xFF, 0, 0xC8, 0x1A);
            } else {
                func_80048060(func_84307F00(arg0) & 0xFF, 0, arg0->unk_000.unk_01A, 0x1A);
            }
        } else if (func_84307B60(arg0) != 0) {
            func_80048060(func_84307F00(arg0) & 0xFF, 0, 0xC8, 0xA);
        } else {
            func_80048060(func_84307F00(arg0) & 0xFF, 0, arg0->unk_000.unk_01A, 0xA);
        }
    }
}

void func_84304114(unk_D_84390010* arg0) {
    UNUSED s32 pad;
    unk_D_84390010_654* sp18 = &arg0->unk_654;
    unk_func_80026268_arg0* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];

    if ((sp18->unk_34 & 0x4000) || (sp18->unk_34 & 2) || (ptr->unk_05 & 7)) {
        D_84390068[D_843900A0].unk_04 = D_84385380;
    } else if (arg0->unk_4C4 == 1) {
        if (func_84301FB0(arg0) == 0) {
            if (arg0->unk_000.unk_01A >= 0x98) {
                func_8432B510(arg0, sp18->unk_BC);
            } else {
                func_8432B510(arg0, arg0->unk_000.unk_01A);
            }
            D_84390068[D_843900A0].unk_04 = D_84385380;
        }
    }
}

void func_84304210(unk_D_84390010* arg0) {
    UNUSED s32 pad;
    unk_func_80026268_arg0* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];
    unk_D_84390010_654* sp24 = &arg0->unk_654;

    if ((arg0->unk_654.unk_34 & 0x4000) || (sp24->unk_34 & 2) || (ptr->unk_05 & 7)) {
        D_84390068[D_843900A0].unk_04 = D_84385380;
    } else if ((arg0->unk_4C4 == 1) && (func_84301FB0(arg0) == 0)) {
        if (arg0->unk_000.unk_01A >= 0x98) {
            func_8004E810(sp24->unk_BC, 3);
        } else if (func_84307B60(arg0) != 0) {
            func_8004E810(0xC8, 3);
        } else {
            func_8004E810(arg0->unk_000.unk_01A, 3);
        }

        if (sp24->unk_34 & 0x200) {
            if (func_84307B60(arg0) != 0) {
                func_80048060(func_84307F00(arg0) & 0xFF, 0, 0xC8, 0x1B);
            } else {
                func_80048060(func_84307F00(arg0) & 0xFF, 0, arg0->unk_000.unk_01A, 0x1B);
            }
        } else if (func_84307B60(arg0) != 0) {
            func_80048060(func_84307F00(arg0) & 0xFF, 0, 0xC8, 0xB);
        } else {
            func_80048060(func_84307F00(arg0) & 0xFF, 0, arg0->unk_000.unk_01A, 0xB);
        }
        D_84390068[D_843900A0].unk_04 = D_84385380;
    }
}

void func_843043FC(unk_D_84390010* arg0) {
    UNUSED s32 pad;
    unk_func_80026268_arg0* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];
    unk_D_84390010_654* sp24;

    if ((arg0->unk_654.unk_34 & 0x4000) || (ptr->unk_05 & 0x20) || (ptr->unk_05 & 7)) {
        D_84390068[D_843900A0].unk_04 = D_84385380;
        return;
    }

    if ((arg0->unk_4C4 == 1) && (func_84301FB0(arg0) == 0)) {
        sp24 = &arg0->unk_654;
        if (arg0->unk_000.unk_01A >= 0x98) {
            func_8004E810(sp24->unk_BC, 4);
        } else if (func_84307B60(arg0) != 0) {
            func_8004E810(0xC8, 4);
        } else {
            func_8004E810(arg0->unk_000.unk_01A, 4);
        }

        if (sp24->unk_34 & 0x200) {
            if (func_84307B60(arg0) != 0) {
                func_80048060(func_84307F00(arg0) & 0xFF, 0, 0xC8, 0x1B);
            } else {
                func_80048060(func_84307F00(arg0) & 0xFF, 0, arg0->unk_000.unk_01A, 0x1B);
            }
        } else if (func_84307B60(arg0) != 0) {
            func_80048060(func_84307F00(arg0) & 0xFF, 0, 0xC8, 0xB);
        } else {
            func_80048060(func_84307F00(arg0) & 0xFF, 0, arg0->unk_000.unk_01A, 0xB);
        }

        D_84390068[D_843900A0].unk_04 = D_84385380;
    }
}

void func_843045DC(unk_D_84390010* arg0) {
    UNUSED s32 pad[2];
    s32 sp24 = arg0->unk_4C0;
    unk_D_84390010_654* temp_v1 = &arg0->unk_654;

    if (func_84302000(arg0) != 0) {
        arg0->unk_720->unk_02 = arg0->unk_654.unk_38.unk_0B;
        arg0->unk_4C4 = 0;
        func_84301B48(arg0, D_84385384[sp24].unk_24);
        func_800367A0(3, 0, 0);
        arg0->unk_720->unk_04 = &arg0->unk_720->unk_08[temp_v1->unk_2B]->unk_01C[temp_v1->unk_18];
        D_84390068[D_843900A0].unk_04 = D_84385380;
    }
}

void func_843046BC(unk_D_84390010* arg0) {
    func_84307F00(arg0);
    if ((arg0->unk_4C4 == 1) && (func_84301FB0(arg0) == 0)) {
        s32 idx = arg0->unk_4C0;

        func_84301B48(arg0, D_84385384[idx].unk_24);
        func_800367A0(3, 0, 0);
        D_84390068[D_843900A0].unk_04 = D_84385380;
    }
}

void func_84304758(unk_D_84390010* arg0) {
    if (arg0->unk_4C4 == 0x4F) {
        arg0->unk_720->unk_00 |= 0x80;
    }

    if (arg0->unk_720->unk_00 & 0x10) {
        arg0->unk_720->unk_00 &= ~0x90;

        func_8430920C(arg0);
        func_84307748(arg0);
        func_800367A0(2, 0, 0);

        D_84390068[D_843900A0].unk_04 = D_84385380;

        func_84305760(arg0, 0x12);
    }
}

void func_84304800(unk_D_84390010* arg0) {
    if (arg0->unk_720->unk_00 & 0x10) {
        arg0->unk_720->unk_00 &= ~0x90;
        func_843092B4(arg0);
    }
}

void func_84304834(unk_D_84390010* arg0) {
    UNUSED s32 pad[2];
    s32 sp24 = D_84384670[arg0->unk_654.unk_38.unk_5A - 1];

    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[sp24];
    arg0->unk_4C4 = 0;
    func_80017464(&arg0->unk_000, 0);
    func_8001BD04(&arg0->unk_000, D_84390020->unk_00);
    func_843058C4(arg0, sp24);
}

void func_843048C8(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* temp_s1_2;
    s16 sp22;
    s16 temp_s1;

    sp22 = arg0->unk_000.unk_01A - 1;
    temp_s1_2 = &arg0->unk_654.unk_38;
    temp_s1 = D_84384670[temp_s1_2->unk_5A - 1];

    func_84307F00(arg0);

    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[temp_s1];

    if ((arg0->unk_4C4 == (D_84390020->unk_04 + 1)) && (func_84301FB0(arg0) == 0)) {
        func_84301BEC(arg0, temp_s1_2->unk_5A);

        if (temp_s1_2->unk_5A == 0x13) {
            func_84308654(arg0, 3, 0);
        }

        if ((temp_s1_2->unk_5A == 0x5B) && (sp22 != 0x31) && (sp22 != 0x32)) {
            func_84308654(arg0, 5, 0);
            func_8432C7A0(4, arg0);
        }

        D_84390068[D_843900A0].unk_04 = D_84385380;

        func_8432B5B8(arg0, temp_s1_2, 4);
    }
}

void func_843049FC(unk_D_84390010* arg0) {
    UNUSED s32 pad[3];
    unk_func_80026268_arg0* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];
    s32 sp1C;

    arg0->unk_4C4 = 0;
    if (!(arg0->unk_654.unk_34 & 2)) {
        if (ptr->unk_05 & 7) {
            if (func_84307AE0(arg0->unk_000.unk_01A, D_84384590, 8) != 0) {
                sp1C = 0xAF;
            } else {
                sp1C = 0xA5;
            }
        } else {
            sp1C = 0xA5;
        }
        D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_000[sp1C];
        func_843058C4(arg0, sp1C);
    }
}

void func_84304ACC(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* ptr = &D_84390010[func_84307F00(arg0) == 0]->unk_654.unk_38;

    if (ptr->unk_4C & 0x20) {
        if ((ptr->unk_5A == 0x14) || (ptr->unk_5A == 0x23) || (ptr->unk_5A == 0x51)) {
            func_8432C6C4(2, arg0);
            func_84308654(arg0, 0x10, 0);
        }
    }
}

void func_84304B50(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* sp20;
    s32 sp28;

    sp28 = func_84307F00(arg0) == 0;
    sp20 = &arg0->unk_654.unk_38;
    D_84390020 = &D_84384570[func_84307F00(arg0) == 0]->unk_000[sp20->unk_5A - 1];

    if ((D_84390020->unk_07 + 1) == D_84390010[sp28]->unk_4C4) {
        if (func_84301FB0(arg0) == 0) {
            func_8432B5B8(arg0, sp20, 5);
            D_84390068[D_843900A0].unk_04 = D_84385380;
        }
    }
}

void func_84304C20(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* sp20 = &arg0->unk_654.unk_38;

    if (sp20->unk_15 & 8) {
        func_8432BF88(arg0, 0x14);
    }

    if (sp20->unk_15 & 0x10) {
        func_8432BF88(arg0, 0x21);
    }

    D_84390068[D_843900A0].unk_04 = D_84385380;
}

void func_84304C8C(unk_D_84390010* arg0) {
    UNUSED s32 pad;
    u16 sp22 = arg0->unk_000.unk_01A;

    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_A70;
    if ((func_84307BAC(arg0) != 0.0f) && (sp22 != 0x16) && (sp22 != 0x52) && (sp22 != 0x8E)) {
        D_84390068[D_843900A0].unk_04 = D_84385380;
    } else if ((arg0->unk_4C4 == (D_84390020->unk_04 + 1)) && (func_84301FB0(arg0) == 0)) {
        func_8432B554(arg0);
        D_84390068[D_843900A0].unk_04 = D_84385380;
    }
}

void func_84304D84(unk_D_84390010* arg0) {
    s32 sp24;

    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_A70;
    if (D_84390020->unk_09 == 1) {
        sp24 = D_84390020->unk_0A - 0x4C;
    } else {
        sp24 = D_84390020->unk_0A - 0x31;
    }

    if (func_84301FB0(arg0) == 0) {
        if (func_84307BAC(arg0) != 0.0f) {
            if ((sp24 <= 0) || (sp24 == arg0->unk_4C4)) {
                if (D_84390020->unk_09 == 1) {
                    func_8432C68C(2, arg0, arg0, 0xFF, 0xFF);
                } else {
                    func_8432C68C(0xC, arg0, arg0, 0xFF, 0xFF);
                }
                func_800367A0(3, 0, 0);
                D_84390068[D_843900A0].unk_04 = D_84385380;
            }
        } else if ((sp24 <= 0) || (sp24 == arg0->unk_4C4)) {
            if (D_84390020->unk_09 == 1) {
                func_8432C68C(2, arg0, arg0, 0xFF, 0xFF);
            } else {
                func_8432C68C(0xC, arg0, arg0, 0xFF, 0xFF);
            }
            func_800367A0(3, 0, 0);
            D_84390068[D_843900A0].unk_04 = D_84385380;
        }
    }
}

void func_84304F54(unk_D_84390010* arg0) {
    s32 sp24;

    D_84390020 = D_84384570[func_84307F00(arg0)]->unkB10;
    if (D_84390020->unk_09 == 1) {
        sp24 = D_84390020->unk_0A - 0x4C;
    } else {
        sp24 = D_84390020->unk_0A - 0x31;
    }

    if ((func_84301FB0(arg0) == 0) && ((sp24 <= 0) || (sp24 == arg0->unk_4C4))) {
        if (D_84390020->unk_09 == 1) {
            func_8432C68C(2, arg0, arg0, 0xFF, 0xFF);
        } else {
            func_8432C68C(0xC, arg0, arg0, 0xFF, 0xFF);
        }
        func_800367A0(3, 0, 0);
        D_84390068[D_843900A0].unk_04 = D_84385380;
    }
}

#ifdef NON_MATCHING
void func_8430506C(unk_D_84390010* arg0) {
    unk_D_8438E7B0* ptr;
    s32 sp48;
    s32 pad2[1];
    s32 sp40;
    unk_D_84390010_654* sp3C;
    s32 pad[2];
    unk_D_84390010* sp30;
    unk_D_84390010_654_038* sp28;
    unk_D_8438E7B0* ptr2;

    sp48 = 0xA5;
    sp40 = func_84307F00(arg0) == 0;
    sp3C = &D_84390010[sp40]->unk_654;
    sp30 = D_84390010[sp40];
    sp28 = &arg0->unk_654.unk_38;

    D_84390020 = &D_84384570[sp40]->unk_A80;

    if (sp3C->unk_34 & 1) {
        if (func_84307AE0(sp30->unk_000.unk_01A, D_84384598, 2) != 0) {
            D_84390020 = &D_84384570[sp40]->unk_B20;
        }
    }

    if ((sp3C->unk_34 & 1) && func_84307AE0(sp30->unk_000.unk_01A, D_84384590, 8)) {
        sp48 = 0xAF;
    }

    D_84390010[sp40]->unk_4C4 = 0;

    if (!(sp3C->unk_34 & 0x4000) && !(sp3C->unk_34 & 2)) {
        if ((sp28->unk_5A == 0x91) && (D_843C4DEC.unk_00 < 0xA)) {
            D_84390020 = &D_84384570[sp40]->unk_000[sp48];
        }

        if ((D_843C4E44 == 0) || (D_843C4DA4 != 0)) {
            ptr = D_84384570[sp40];
            ptr2 = ptr;
            D_84390020 = &ptr2->unk_000[sp48];
            if (sp3C->unk_34 & 0x200) {
                D_84390020 = &ptr2->unk_000[0xB0];
            }
        } else if (!(sp3C->unk_34 & 1)) {
            func_843058C4(D_84390010[sp40], 0xA8);
        }

        func_80017464(&D_84390010[sp40]->unk_000, 0);
        func_8001BD04(&D_84390010[sp40]->unk_000, D_84390020->unk_00);

        if ((sp28->unk_44.unk_00 == 0x17) || (sp28->unk_44.unk_00 == 0x22) || (sp28->unk_44.unk_00 == 0x45)) {
            func_84308654(D_84390010[sp40], 0xF, 0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/62/fragment62_2EC3C0/func_8430506C.s")
#endif

void func_843052C0(unk_D_84390010* arg0) {
    s32 sp2C;
    UNUSED s32 pad;
    unk_D_84390010_654_038* sp24;
    unk_D_84390010_654_038* sp1C;

    sp2C = func_84307F00(arg0);
    sp24 = &D_84390010[sp2C == 0]->unk_654.unk_38;
    sp1C = &arg0->unk_654.unk_38;

    D_84390020 = &D_84384570[sp2C == 0]->unk_000[sp1C->unk_5A - 1];

    if ((D_84390010[sp2C == 0]->unk_4C4 == (D_84390020->unk_07 + 1)) && (func_84301FB0(arg0) == 0)) {
        func_8432E9D8(1);
        if (((sp1C->unk_5A == 0x30) || (sp1C->unk_5A == 0x6D)) && (sp24->unk_4C & 0x80) && (D_843C4DA4 == 0) &&
            (D_843C4E44 == 1)) {
            func_8432BF88(D_84390010[sp2C == 0], 0x12);
        }

        func_84301C54(D_84390010[sp2C == 0], sp1C->unk_5A);
        if ((D_843C4DA4 == 0) || (D_843C4E44 == 1)) {
            func_8432B5B8(D_84390010[sp2C == 0], &arg0->unk_654.unk_38, 1);
        }

        D_84390068[D_843900A0].unk_04 = D_84385380;
    }
}

s32 func_84305458(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* ptr = &arg0->unk_654.unk_38;
    s32 temp_v1;

    temp_v1 = func_84307F00(arg0) == 0;
    D_84390020 = &D_84384570[temp_v1]->unk_000[ptr->unk_5A - 1];

    if (D_843C4E45 != 1) {
        return 2;
    }

    if ((D_84390020->unk_08 + 0x50) == D_84390010[temp_v1]->unk_4C4) {
        return 1;
    }

    return 0;
}

void func_843054F0(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* ptr = &arg0->unk_654.unk_38;
    s32 sp28;

    sp28 = func_84307F00(arg0) == 0;
    D_84390020 = &D_84384570[func_84307F00(arg0) == 0]->unk_000[ptr->unk_5A - 1];
    if (D_84390010[sp28]->unk_4C4 == (D_84390020->unk_08 + 1)) {
        if (func_84301FB0(arg0) == 0) {
            if (D_843C4E45 == 1) {
                func_8432C6C4(1, D_84390010[sp28]);
                func_8432BF88(arg0, 0x20);
            }
            D_84390068[D_843900A0].unk_04 = D_84385380;
        }
    }
}

void func_843055E0(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* sp20;
    s32 sp28;

    sp28 = func_84307F00(arg0) == 0;
    sp20 = &arg0->unk_654.unk_38;
    D_84390020 = &D_84384570[func_84307F00(arg0) == 0]->unk_000[sp20->unk_5A - 1];

    if ((D_84390020->unk_07 + 1) == D_84390010[sp28]->unk_4C4) {
        if (func_84301FB0(arg0) == 0) {
            if (D_843C4E44 == 1) {
                func_8432B5B8(D_84390010[sp28], sp20, 1);
            } else {
                func_8432B5B8(D_84390010[sp28], sp20, 5);
            }
            D_84390068[D_843900A0].unk_04 = D_84385380;
        }
    }
}

void func_843056DC(unk_D_84390010* arg0) {
}

void func_843056E4(unk_D_84390010* arg0, unk_D_84385384_func arg1) {
    unk_D_84390068* var_a2;
    s32 i;

    for (i = 0; i < 7; i++) {
        if (D_84385380 == D_84390068[i].unk_04) {
            D_84390068[i].unk_04 = arg1;
            D_84390068[i].unk_00 = arg0;
            break;
        }
    }
}

void func_84305728(unk_D_84390010* arg0) {
    func_843058C4(D_84390010[func_84307F00(arg0)], 0xA6);
}

void func_84305760(unk_D_84390010* arg0, s32 arg1) {
    arg0->unk_4C0 = arg1;

    D_84385384[arg1].unk_04[0](arg0);
    D_84385384[arg1].unk_04[1](arg0);
    D_84385384[arg1].unk_04[2](arg0);

    func_843056E4(arg0, D_84385384[arg1].unk_04[3]);
    func_843056E4(arg0, D_84385384[arg1].unk_04[4]);
    func_843056E4(arg0, D_84385384[arg1].unk_04[5]);
    func_843056E4(arg0, D_84385384[arg1].unk_04[6]);
}

void func_84305808(void) {
    D_84390010[0]->unk_4C4++;
    D_84390010[1]->unk_4C4++;

    for (D_843900A0 = 0; D_843900A0 < 7; D_843900A0++) {
        D_84390068[D_843900A0].unk_04(D_84390068[D_843900A0].unk_00);
    }
}

void func_843058A8(unk_D_84390010* arg0) {
    if (arg0->unk_654.unk_38.unk_5A == 0x6A) {
        arg0->unk_000.unk_01C = 0;
    }
}

void func_843058C4(unk_D_84390010* arg0, s32 arg1) {
    s32 temp_v0;
    s32 sp30;
    unk_D_84390010_654* sp24 = &arg0->unk_654;

    if (func_84301FF0(arg0) == 0) {
        sp30 = D_84384570[func_84307F00(arg0)]->unk_000[arg1].unk_01;
        if ((sp30 != 0xFF) && (sp24->unk_36 != 2)) {
            if ((arg1 == 165) && (arg0->unk_000.unk_01A == 0x33)) {
                func_80017804(&arg0->unk_000, 0);
                temp_v0 = func_8430C414(3);
                if (temp_v0 >= 3) {
                    temp_v0 = 2;
                }
                func_8001BD9C(&arg0->unk_000, sp30 + temp_v0);
            } else {
                func_80017804(&arg0->unk_000, 0);
                func_8001BD9C(&arg0->unk_000, sp30);
                sp24->unk_36 = 1;
            }
        }
    }
}

s32 func_843059C0(unk_D_84390010* arg0, s32 arg1, s32 arg2) {
    UNUSED s32 pad;
    s32 sp20;

    if (func_84301FF0(arg0) != 0) {
        return 0;
    }

    sp20 = D_84384570[func_84307F00(arg0)]->unk_000[arg1].unk_01;
    if (sp20 == 0xFF) {
        return 1;
    }

    func_80017804(&arg0->unk_000, 0);
    func_8001BD9C(&arg0->unk_000, sp20);
    func_80017804(&arg0->unk_000, arg0->unk_000.unk_054.unk_04->unk_0A);

    arg0->unk_654.unk_36 = arg2;
    return 0;
}

void func_84305A74(unk_D_84390010* arg0, s32 arg1, s32 arg2) {
    u8 temp_a1;

    if (func_84301FF0(arg0) == 0) {
        temp_a1 = D_84384570[func_84307F00(arg0)]->unk_000[arg1].unk_01;
        if (temp_a1 != 0xFF) {
            func_8001BD9C(&arg0->unk_000, temp_a1);
            func_80017804(&arg0->unk_000, 0);
            arg0->unk_654.unk_36 = arg2;
        }
    }
}

s32 func_84305AFC(unk_D_84390010* arg0) {
    unk_D_84390010_654* sp20 = &arg0->unk_654;
    unk_func_80026268_arg0* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];

    if ((sp20->unk_34 & 2) || (ptr->unk_05 & 7) || ((sp20->unk_34 & 0x200) && !(sp20->unk_34 & 0x400)) ||
        (sp20->unk_34 & 0x4000)) {
        return 1;
    }
    return 0;
}

s32 func_84305B6C(unk_D_84390010* arg0, s32 arg1) {
    if (func_84305AFC(arg0) != 0) {
        if (func_8431ADAC(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    if (arg0->unk_000.unk_040.unk_00 == -1) {
        return 1;
    }
    return func_800174E4(&arg0->unk_000);
}

s32 func_84305BD8(unk_D_84390010* arg0, s32 arg1) {
    u8 temp_v0;

    D_84390020 = D_84384570[func_84307F00(arg0)]->unkA60;
    if (func_84305AFC(arg0) != 0) {
        if (func_8431ADAC(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    if ((D_84390020->unk_0A < 0xB) || (D_84390020->unk_0A == 0xFF)) {
        if (arg0->unk_000.unk_040.unk_00 == -1) {
            return 1;
        }
        return func_800174E4(&arg0->unk_000);
    }

    if (func_8431ADAC(D_84390020->unk_0A + 1) != 0) {
        return 1;
    }

    return 0;
}

s32 func_84305CAC(unk_D_84390010* arg0, s32 arg1) {
    unk_D_84390010_654_038* ptr = &arg0->unk_654.unk_38;
    unk_D_8438E7B0_A50* sp20;
    unk_D_8438E7B0_A50* sp1C;

    if (arg0) {}

    sp20 = &D_84384570[func_84307F00(arg0)]->unk_000[ptr->unk_5A - 1];
    sp1C = &D_84384570[func_84307F00(arg0)]->unk_A50;

    if (func_84305AFC(arg0) != 0) {
        if (func_8431ADAC(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    if (arg0->unk_000.unk_040.unk_00 == -1) {
        return 1;
    }

    if (D_84390240.unk_00->unk_48 == 0x14) {
        sp20 = &D_84384570[func_84307F00(arg0)]->unk_000[0];
    }

    if (sp20->unk_00 == sp1C->unk_00) {
        if (sp20->unk_0A != 0xFF) {
            D_84390240.unk_00->unk_14++;
            if (sp20->unk_0A == arg0->unk_4C4) {
                return 1;
            }
            return 0;
        }

        if (func_8431ADAC(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    D_84390240.unk_00->unk_14++;

    if (sp20->unk_0A != 0xFF) {
        if (sp20->unk_0A == arg0->unk_4C4) {
            return 1;
        }
        return 0;
    }

    return func_800174E4(&arg0->unk_000);
}

s32 func_84305E54(unk_D_84390010* arg0, s32 arg1) {
    unk_D_8438E7B0_A50* temp_a2;
    unk_func_80026268_arg0* sp28;
    UNUSED s32 pad;
    s32 sp20;
    unk_D_8438E7B0_A50* sp1C;

    sp28 = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];
    sp20 = D_84384670[arg0->unk_654.unk_38.unk_5A - 1];
    sp1C = &D_84384570[func_84307F00(arg0)]->unk_000[sp20];
    temp_a2 = &D_84384570[func_84307F00(arg0)]->unk_A50;

    if ((arg0->unk_654.unk_34 & 2) || (sp28->unk_05 & 7) ||
        ((arg0->unk_654.unk_34 & 0x200) && !(arg0->unk_654.unk_34 & 0x400)) || (arg0->unk_654.unk_34 & 0x4000)) {
        if (func_8431ADAC(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    if (arg0->unk_000.unk_040.unk_00 == -1) {
        return 1;
    }

    if (sp1C->unk_00 == temp_a2->unk_00) {
        if (sp1C->unk_0A != 0xFF) {
            D_84390240.unk_00->unk_14++;
            if (sp1C->unk_0A == arg0->unk_4C4) {
                return 1;
            }
            return 0;
        }
        if (func_8431ADAC(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    D_84390240.unk_00->unk_14++;

    if (sp1C->unk_0A != 0xFF) {
        if (sp1C->unk_0A == arg0->unk_4C4) {
            return 1;
        }
        return 0;
    }
    return func_800174E4(&arg0->unk_000);
}

s32 func_8430602C(unk_D_84390010* arg0, s32 arg1) {
    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_A80;

    if ((arg0->unk_654.unk_34 & 2) || ((arg0->unk_654.unk_34 & 0x200) && !(arg0->unk_654.unk_34 & 0x400))) {
        if (func_8431ADAC(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    if (arg0->unk_000.unk_040.unk_00 == -1) {
        return 1;
    }

    if (arg0->unk_000.unk_040.unk_00 != D_84390020->unk_00) {
        return 1;
    }

    return func_800174E4(&arg0->unk_000);
}

void func_843060EC(unk_D_84390010* arg0) {
    D_84390020 = &D_84384570[func_84307F00(arg0)]->unk_A50;
    if (func_84301FF0(arg0) == 0) {
        if ((arg0->unk_000.unk_040.unk_00 != -1) && (arg0->unk_000.unk_000.unk_01 & 1) &&
            (arg0->unk_000.unk_000.unk_02 & 0x20) && (D_84390240.unk_00->unk_1C == 1) &&
            (D_84390020->unk_00 == arg0->unk_000.unk_040.unk_00) &&
            (D_84390020->unk_04 == (arg0->unk_000.unk_040.unk_08 >> 0x10)) && (D_84390020->unk_05 != 0) &&
            (func_8430C414(2) == 1)) {
            func_8432C68C(D_84390020->unk_05, &arg0->unk_000, &arg0->unk_000, D_84390020->unk_02, D_84390020->unk_02);
        }
    }
}

void func_843061EC(unk_D_84390010* arg0, u16 arg1) {
    arg0->unk_654.unk_34 |= arg1;
}

s32 func_84306200(unk_D_84390010* arg0, u16 arg1) {
    arg0->unk_654.unk_34 &= ~arg1;
}

void func_84306218(unk_D_84390010* arg0) {
    unk_D_84390010_654* sp24 = &arg0->unk_654;

    if (arg0->unk_4C8 != 0) {
        if (sp24->unk_34 & 0x200) {
            arg0->unk_000.unk_024.y = D_84390028[func_84307F00(arg0)].unk_08;
            func_84306200(arg0, 0x608);
        }

        if (sp24->unk_34 & 0x4008) {
            arg0->unk_000.unk_01D = 0xFF;
            func_8432C80C(4, arg0);
            arg0->unk_000.unk_024.y = D_84390028[func_84307F00(arg0)].unk_08;
            arg0->unk_000.unk_000.unk_02 &= ~2;
            arg0->unk_000.unk_000.unk_02 |= 0x20;
            arg0->unk_000.unk_000.unk_01 |= 1;
            func_84306200(arg0, 0x4608);
        }
    }
}

void func_843062F0(void) {
    unk_D_84390010_654* sp34;
    unk_D_84390010_654* sp30;
    UNUSED s32 pad[2];
    unk_D_84390010* sp24;
    unk_D_84390010* sp20;

    sp34 = &D_84390010[0]->unk_654;
    sp30 = &D_84390010[1]->unk_654;
    sp24 = D_84390010[0];
    sp20 = D_84390010[1];

    if (sp34->unk_34 & 4) {
        D_84390010[0]->unk_000.unk_024.y = 200.0f;
        func_843061EC(D_84390010[0], 0x200);
        func_84306200(D_84390010[0], 4);
    }

    if (sp30->unk_34 & 4) {
        D_84390010[1]->unk_000.unk_024.y = 200.0f;
        func_843061EC(D_84390010[1], 0x200);
        func_84306200(D_84390010[1], 4);
    }

    if ((sp34->unk_34 & 0x4000) && (sp24->unk_000.unk_01A == 0x33)) {
        D_84390020 = &D_84384570[0]->unk_000[0x5A];
        func_80017464(&D_84390010[0]->unk_000, 0);
        func_8001BD04(&D_84390010[0]->unk_000, D_84390020->unk_00);
    }

    if ((sp30->unk_34 & 0x4000) && (sp20->unk_000.unk_01A == 0x33)) {
        D_84390020 = &D_84384570[1]->unk_000[0x5A];
        func_80017464(&D_84390010[1]->unk_000, 0);
        func_8001BD04(&D_84390010[1]->unk_000, D_84390020->unk_00);
    }

    func_84306218(D_84390010[0]);
    func_84306218(D_84390010[1]);
}

void func_84306470(unk_D_84390010* arg0) {
    UNUSED s32 pad;
    unk_D_84390010_654* sp20;

    sp20 = &D_84390010[func_84307F00(arg0) == 0]->unk_654;
    func_84307F00(arg0);
    func_84307F00(arg0);
    func_843058A8(D_84390010[func_84307F00(arg0) == 0]);

    if (sp20->unk_34 & 4) {
        D_84390010[func_84307F00(arg0) == 0]->unk_000.unk_024.y = 200.0f;
        func_843061EC(D_84390010[func_84307F00(arg0) == 0], 0x200);
        func_84306200(D_84390010[func_84307F00(arg0) == 0], 4);
    }

    if (arg0->unk_654.unk_34 & 0x200) {
        func_843061EC(arg0, 0x400);
    }
}

void func_84306584(unk_D_84390010* arg0) {
    if (arg0->unk_654.unk_34 & 8) {
        arg0->unk_000.unk_024.y = func_84307BAC(arg0);
        func_84306200(arg0, 0x608);
    }
}

void func_843065C4(unk_D_84390010* arg0) {
    UNUSED s32 pad[2];
    unk_D_84390010* sp1C = D_84390010[func_84307F00(arg0) == 0];

    if (sp1C->unk_654.unk_34 & 0x4000) {
        sp1C->unk_000.unk_000.unk_02 |= 0x20;
        sp1C->unk_000.unk_000.unk_01 |= 1;
        func_8432C80C(4, sp1C);
        func_84306200(sp1C, 0x4000);
    }
}

void func_8430663C(unk_D_84390010* arg0) {
    unk_D_84390010* temp_s0 = D_84390010[func_84307F00(arg0) == 0];
    unk_D_84390010_654* ptr = &temp_s0->unk_654;

    if (ptr->unk_34 & 0x4000) {
        temp_s0->unk_000.unk_000.unk_02 |= 0x20;
        temp_s0->unk_000.unk_000.unk_01 |= 1;
        func_8432C80C(4, temp_s0);
        func_84306200(temp_s0, 0x4000);
    }

    if (ptr->unk_34 & 8) {
        temp_s0->unk_000.unk_024.y = func_84307BAC(arg0);
        func_84306200(temp_s0, 0x608);
    }
}

void func_843066E0(unk_D_84390010* arg0) {
    switch (arg0->unk_4B4) {
        case 14:
            func_84308654(arg0, 0, 0);
            func_84307C5C(arg0);
            break;

        case 13:
        case 15:
        case 16:
            func_84308654(arg0, 0, 0);
            if (arg0->unk_654.unk_38.unk_56 == 0) {
                func_8000E88C(&arg0->unk_000.unk_030, 1.0f, 1.0f, 1.0f);
            } else {
                func_8000E88C(&arg0->unk_000.unk_030, 0.8f, 0.8f, 0.8f);
            }
            break;

        case 12:
            func_84308654(arg0, 0, 0);
            if (arg0->unk_654.unk_38.unk_56 == 0) {
                func_8000E88C(&arg0->unk_000.unk_030, 1.0f, 1.0f, 1.0f);
            } else {
                func_8000E88C(&arg0->unk_000.unk_030, 0.8f, 0.8f, 0.8f);
            }
            break;

        case 10:
            func_84308654(arg0, 0, 0);
            arg0->unk_000.unk_024.y = func_84307BAC(arg0);
            arg0->unk_000.unk_01E.x = 0;
            break;

        case 9:
            func_84308654(arg0, 0, 0);
            func_8000E88C(&arg0->unk_000.unk_030, 0.8f, 0.8f, 0.8f);
            func_843096EC(arg0);
            break;

        case 7:
            func_84308654(arg0, 0, 0);
            func_843096EC(arg0);
            break;

        case 6:
            func_84308654(arg0, 0, 0);
            func_843096EC(arg0);
            func_84307C5C(arg0);
            func_8000EB70(&arg0->unk_000.unk_01E, 0, arg0->unk_4B0 << 0xE, 0);
            break;

        case 4:
            func_84308654(arg0, 0, 0);
            arg0->unk_000.unk_01E.y = arg0->unk_4B0 << 0xE;
            func_843096EC(arg0);
            break;
    }
}

void func_84306914(unk_D_84390010* arg0) {
    unk_D_84390010_654* temp_s1 = &arg0->unk_654;

    func_8432AF70(arg0);
    func_8432B228(arg0);

    if (temp_s1->unk_34 & 0x100) {
        arg0->unk_000.unk_000.unk_02 &= 0xFFDF;
    }

    if ((temp_s1->unk_2D == 0x10) || (temp_s1->unk_2D == 0x13)) {
        func_84306200(arg0, 0x100);
    }

    temp_s1->unk_2E = func_8001046C(temp_s1->unk_2E, 0, 0x1E, 0x1E);
    if (temp_s1->unk_2E != 0) {
        func_8001BE34(&arg0->unk_000, 0xFF, 0xFF, 0xFF, temp_s1->unk_2E);
    }

    switch (temp_s1->unk_36) {
        case 2:
            break;

        case 0:
            if (func_8430C414(0x32) == 2) {
                func_843058C4(arg0, 0xA5);
            }
            break;

        case 1:
            if (func_8001783C(&arg0->unk_000) == 1) {
                func_8001BD9C(&arg0->unk_000, -1);
                func_80017804(&arg0->unk_000, 0);
                temp_s1->unk_36 = 0;
            }
            break;
    }

    if (temp_s1->unk_34 & 0x4000) {
        if ((arg0->unk_000.unk_01A != 0x32) && (arg0->unk_000.unk_01A != 0x33)) {
            arg0->unk_000.unk_01D = 0;
        }
    }
}

void func_84306A68(unk_D_84390010* arg0) {
    unk_func_80026268_arg0* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];

    if ((ptr->unk_05 & 7) && !(arg0->unk_654.unk_34 & 1)) {
        func_84305A74(arg0, 0xAF, 2);
        func_8432C7A0(3, arg0);
        func_8432BF88(arg0, 0x32);
    }
}

void func_84306AF0(unk_D_800AE540_1194* arg0, s32 arg1) {
    unk_D_84390010* ptr = main_pool_alloc(sizeof(unk_D_84390010), 0);

    D_84390010[arg1] = ptr;

    bzero(ptr, sizeof(unk_D_84390010));
    bzero(&D_84390010[arg1]->unk_654, sizeof(unk_D_84390010_654));
    bzero(&D_84390010[arg1]->unk_654.unk_38, sizeof(unk_D_84390010_654_038));
    bzero(&D_84390010[arg1]->unk_728, sizeof(unk_D_84390010_728));
    bzero(&D_84390010[arg1]->unk_654.unk_38.unk_44, sizeof(unk_D_84390010_654_038_044));
    bzero(&D_84390010[arg1]->unk_654.unk_9C, sizeof(unk_D_84390010_654_09C));
    bzero(&D_84390010[arg1]->unk_654.unk_AC, sizeof(unk_D_84390010_654_0AC));
    bzero(&D_84390010[arg1]->unk_8C4, sizeof(unk_D_84390010_8C4));
    D_84390010[arg1]->unk_720 = arg0;
}

void func_84306BC4(unk_D_800AE540_1194* arg0) {
    func_84306AF0(&arg0[0], 0);
    func_84306AF0(&arg0[1], 1);
    func_8431962C();
    D_84390018 = D_84390010[0];
    D_8439001C = D_84390010[1];
}

void func_84306C1C(unk_D_84390010* arg0) {
    Controller* sp24 = &gControllers[arg0->unk_720->unk_08[0]->unk_001];

    func_843089DC(arg0, 0);
    func_843089F4(arg0, 0);
    func_843089FC(arg0, sp24);
    arg0->unk_728.unk_16C = 0;
}

void func_84306C8C(unk_D_84390010* arg0) {
    UNUSED s32 pad[2];
    unk_D_86002F58_004_000_004* sp24;
    s16 sp22;

    func_84307F00(arg0);
    sp24 = func_843085C4(arg0, 0);
    sp22 = func_843085E0(arg0, 0);
    func_8001BB58(&arg0->unk_000);

    if (arg0 == D_84390010[0]) {
        arg0->unk_000.unk_0A6 = 0;
    } else {
        arg0->unk_000.unk_0A6 = 1;
    }

    func_8001BC34(&arg0->unk_000, 0, sp22, sp24);
    func_84302658(arg0, 1);
    func_8001BD04(&arg0->unk_000, 0);
    func_80017464(&arg0->unk_000, 0);

    arg0->unk_720->unk_04 = arg0->unk_724->unk_01C;
    if ((arg0->unk_000.unk_01A == 0x32) || (arg0->unk_000.unk_01A == 0x33)) {
        arg0->unk_000.unk_000.unk_02 &= ~0x40;
    } else {
        arg0->unk_000.unk_000.unk_02 |= 0x40;
    }

    if (arg0 == D_84390010[0]) {
        func_84307C5C(arg0);
        arg0->unk_000.unk_01E.y = 0x4000;
    } else {
        func_84307C5C(arg0);
        arg0->unk_000.unk_01E.y = -0x4000;
    }
}

void func_84306DA8(unk_D_84390010* arg0) {
    unk_D_84390010_728* ptr = &arg0->unk_728;
    unk_D_86002F58_004_000_004* sp28;
    s16 sp26;

    sp28 = func_843085C4(arg0, 0);
    sp26 = func_843085E0(arg0, 0);
    func_8001BB58(&ptr->unk_000);

    if (arg0 == D_84390010[0]) {
        ptr->unk_000.unk_0A6 = -1;
        func_8001BC34(&ptr->unk_000, 1, sp26, sp28);
    } else {
        ptr->unk_000.unk_0A6 = -1;
        func_8001BC34(&ptr->unk_000, 2, sp26, sp28);
    }

    func_8001BD04(&ptr->unk_000, 0);
    func_80017464(&ptr->unk_000, 0);
    ptr->unk_000.unk_000.unk_02 &= ~0x40;
    func_8000E88C(&ptr->unk_000.unk_024, 0.0f, 0.0f, 0.0f);
}

void func_84306E80(unk_D_84390010* arg0, s32* arg1) {
    unk_D_86002F58_004_000_004* sp44;
    s16 sp42;
    s32 i;
    unk_D_84390010_168* ptr;

    sp44 = func_843085C4(arg0, 0);
    sp42 = func_843085E0(arg0, 0);

    for (i = 0; i < 2; i++) {
        ptr = &arg0->unk_168[i];

        func_8001BB58(ptr);

        if (arg0 == D_84390010[0]) {
            ptr->unk_000.unk_0A6 = 0xFF;
        } else {
            ptr->unk_000.unk_0A6 = 0xFF;
        }

        func_8001BC34(ptr, 0, sp42, sp44);
        func_80017464(ptr, 0);
        func_8001BD04(ptr, 0);

        ptr->unk_000.unk_000.unk_02 &= ~0x40;

        if (arg0 == D_84390010[0]) {
            func_84307C5C(arg0);
        } else {
            func_84307C5C(arg0);
        }
        ptr->unk_000.unk_000.unk_01 &= ~1;
    }
}

void func_84306FB8(unk_D_84390010* arg0) {
    unk_D_86002F58_004_000* ptr = &arg0->unk_4EC;
    unk_D_86002F58_004_000_004* sp20 = arg0->unk_720->unk_18;

    func_8001BB58(ptr);
    ptr->unk_0A6 = 0xFF;
    func_8001BC34(ptr, 0, 0x9A, sp20);
    func_8001BD04(ptr, 0);

    ptr->unk_000.unk_02 &= ~0x20;
    ptr->unk_000.unk_01 &= ~1;

    if (arg0 == D_84390010[0]) {
        func_8000E88C(&ptr->unk_024, -50.0f, 2.0f, 0.0f);
    } else {
        func_8000E88C(&ptr->unk_024, 50.0f, 2.0f, 0.0f);
    }
}

void func_84307078(unk_D_800AE540_1194* arg0) {
    D_84390174 = 0;
    D_84390178.unk_00 = 0;

    func_84306C1C(D_84390010[0]);
    func_84306C1C(D_84390010[1]);
    func_84306C8C(D_84390010[0]);
    func_84306C8C(D_84390010[1]);
    func_84306DA8(D_84390010[0]);
    func_84306DA8(D_84390010[1]);
    func_84306E80(D_84390010[0], &D_84390010[0]->unk_168);
    func_84306E80(D_84390010[1], &D_84390010[1]->unk_168);
    func_84306FB8(D_84390010[0]);
    func_84306FB8(D_84390010[1]);

    switch (D_800AE540.unk_0000) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            func_8431AFB4(4, 0);
            break;

        case 16:
            func_8431AFB4(1, 0x32);
            func_8004B1CC(1);
            break;

        default:
            func_8431AFB4(4, 0);
            break;
    }

    func_84308654(D_84390010[0], 0, 0);
    func_84308654(D_84390010[1], 0, 0);
    func_84319668();
    func_843193F4(D_84390010[0]);
    func_843193F4(D_84390010[1]);
    func_8432B704();
    func_8432B604();
}

void func_843071B8(unk_D_84390010* arg0, unk_D_84390010* arg1, s32 arg2) {
    func_8000E88C(&arg1->unk_448, 0.0f, 0.0f, 0.0f);
    func_8000E88C(&arg1->unk_448.unk_0C, 0.0f, 0.0f, 0.0f);
    arg1->unk_4B0 = arg2;
}

void func_84307220(unk_D_800AE540_1194* arg0) {
    s32 i;

    func_8002D510();

    D_843900B0 = func_8002D5AC(0x1E);
    D_843900B4 = func_8002D5AC(0x24);
    D_843900B8 = func_8002D5AC(0x25);
    D_843900BC = func_8002D5AC(0x29);
    D_843900C0 = func_8002D5AC(0x14);

    for (i = 0; i < 7; i++) {
        D_84390068[i].unk_04 = D_84385380;
    }

    func_843071B8(D_84390010[0], D_84390010[0], 1);
    func_843071B8(D_84390010[1], D_84390010[1], -1);
    func_84307078(arg0);
    func_8430D814();
    func_8430245C(D_84390010[0]);
    func_8430245C(D_84390010[1]);
    func_843184FC();
}

void func_8430732C(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    func_84308660(D_84390010[0], D_84390010[0]);
    func_84308660(D_84390010[1], D_84390010[1]);
    func_8430BC44(0);
    func_8430BC44(1);
    func_843060EC(D_84390010[0]);
    func_843060EC(D_84390010[1]);
}

s32 func_84307394(s32 arg0, unk_D_800AE540_1194* arg1) {
    switch (arg0) {
        case 0:
            func_84306BC4(arg1);
            break;

        case 1:
        case 2:
            func_8430732C(D_84390010[0], D_84390010[1]);
            break;

        case 3:
            func_84307220(arg1);
            break;

        case 5:
            func_843196A4();
            break;
    }

    return 0;
}

void func_84307414(unk_D_84390010* arg0) {
}

void func_8430741C(unk_D_84390010* arg0) {
}

void func_84307424(unk_D_84390010* arg0) {
}

void func_8430742C(unk_D_84390010* arg0) {
}

void func_84307434(unk_D_84390010* arg0) {
}

void func_8430743C(unk_D_84390010* arg0) {
}

void func_84307444(unk_D_84390010* arg0) {
}

void func_8430744C(unk_D_84390010* arg0) {
}

void func_84307454(unk_D_84390010* arg0) {
}

void func_8430745C(unk_D_84390010* arg0) {
}

void func_84307464(unk_D_84390010* arg0) {
}

void func_8430746C(unk_D_84390010* arg0) {
}

void func_84307474(unk_D_84390010* arg0, s32 arg1) {
}

void func_84307480(unk_D_84390010* arg0, s32 arg1) {
}

void func_8430748C(unk_D_84390010* arg0) {
}
