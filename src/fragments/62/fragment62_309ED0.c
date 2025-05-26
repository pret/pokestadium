#include "fragment62.h"
#include "src/17300.h"
#include "src/1C720.h"
#include "src/373A0.h"
#include "src/3D140.h"
#include "src/4BDC0.h"
#include "src/4F410.h"
#include "src/F420.h"

unk_D_84390010* D_84390200;
unk_D_84390010* D_84390204;
f32 D_84390208;
s32 pad_D_84390210[4];
s32 D_84390220;
static s32 D_84390224;
static s32 D_84390228;
s32 D_8439022C;
s32 D_84390230;
s32 D_84390234;

u8 D_84385B70[] = {
    0x00, 0x03, 0x02, 0x06, 0x07,
};
u8 D_84385B78[] = {
    0x00,
    0x02,
    0x06,
    0x07,
};
u8 D_84385B7C[] = {
    0x02,
    0x06,
    0x07,
};
u8 D_84385B80[] = {
    0x04, 0x05, 0x08, 0x09, 0x0A, 0x0B,
};
u8 D_84385B88[] = {
    0x05,
    0x09,
    0x0A,
    0x0B,
};
u16 D_84385B8C = 0x5F92;
Vec3f D_84385B90 = { 0.0f, 100.0f, 0.0f };
Vec3f D_84385B9C = { 0.0f, 10.0f, 0.0f };

void func_8431F610(unk_D_84390010* arg0) {
    unk_D_84390010_654* ptr = &arg0->unk_654;

    if ((arg0->unk_000.unk_01A == 0x32) && (ptr->unk_34 & 0x4000)) {
        unk_D_8438E7B0_A50* tmp = &D_84384570[func_84307F00(arg0)]->unk_000[0x5A];

        func_8001BD04(&arg0->unk_000, tmp->unk_00);
        arg0->unk_000.unk_000.unk_02 &= ~0x20;
    }
}

void func_8431F680(void) {
    D_84390240.unk_00->unk_24 = 0;
}

s32 func_8431F690(unk_D_84390010* arg0) {
    unk_D_84390010_654* ptr = &arg0->unk_654;
    UNUSED s32 pad;
    s32 sp1C = 0;

    if (!(ptr->unk_34 & 0x800)) {
        return 0;
    }

    if (D_84390240.unk_00->unk_48 == 0x19) {
        return 0;
    }

    if ((ptr->unk_34 & 0x800) && (D_84390240.unk_00->unk_48 == 0x1C)) {
        return 0;
    }

    switch (D_84390240.unk_00->unk_24) {
        case 0:
            func_84302148(arg0);
            sp1C = 1;
            D_84390240.unk_00->unk_24++;
            break;

        case 1:
            sp1C = 1;
            if (arg0->unk_720->unk_00 & 0x10) {
                arg0->unk_720->unk_00 &= ~0x90;
                func_84309368(arg0);
                func_8431F610(arg0);
                D_84390240.unk_00->unk_24++;
            }
            break;

        case 2:
            func_8431F680();
            break;
    }
    return sp1C;
}

s32 func_8431F7B0(unk_D_84390010* arg0) {
    UNUSED s32 pad[2];
    s32 sp1C = 0;

    if (!(arg0->unk_654.unk_34 & 0x800)) {
        return 0;
    }

    switch (D_84390240.unk_00->unk_24) {
        case 0:
            func_84302128(arg0);
            sp1C = 1;
            D_84390240.unk_00->unk_24++;
            break;

        case 1:
            sp1C = 1;
            if (arg0->unk_720->unk_00 & 0x10) {
                arg0->unk_720->unk_00 &= ~0x90;
                func_84309328(arg0);
                D_84390240.unk_00->unk_24++;
            }
            break;

        case 2:
            func_8431F680();
            break;
    }
    return sp1C;
}

s32 func_8431F888(unk_D_84390010* arg0) {
    UNUSED s32 pad[2];
    Vec3f sp34;
    s32 var_s0 = 0;

    if (!(arg0->unk_654.unk_34 & 0x1000)) {
        return 0;
    }

    switch (D_84390240.unk_00->unk_24) {
        case 0:
            func_84302148(arg0);
            var_s0 = 1;
            D_84390240.unk_00->unk_24++;
            break;

        case 1:
            var_s0 = 1;
            if (arg0->unk_720->unk_00 & 0x10) {
                arg0->unk_720->unk_00 &= ~0x90;
                func_84309368(arg0);
                func_84306200(arg0, 0x1800);
                var_s0 = 0;
                func_8431F680();
                D_84390240.unk_00->unk_24++;
            }
            break;

        case 2:
            func_8431F680();
            func_843081F0(arg0, &sp34);
            func_8430C1E4(&D_84390240.unk_00->unk_DC->unk_60.at, &sp34);
            break;
    }
    return var_s0;
}

s32 func_8431F998(unk_D_84390010* arg0) {
    UNUSED s32 pad[2];
    s32 sp1C = 0;

    if (D_84390240.unk_00->unk_44 != 2) {
        return 0;
    }

    if (!(arg0->unk_654.unk_34 & 0x800)) {
        return 0;
    }

    if ((D_84390240.unk_00->unk_48 == 0x19) || (D_84390240.unk_00->unk_48 == 0x1C)) {
        return 0;
    }

    switch (D_84390240.unk_00->unk_24) {
        case 0:
            func_84302148(arg0);
            sp1C = 1;
            D_84390240.unk_00->unk_24 += 1;
            break;

        case 1:
            sp1C = 1;
            if (arg0->unk_720->unk_00 & 0x10) {
                arg0->unk_720->unk_00 &= ~0x90;
                func_84309368(arg0);
                func_8431F610(arg0);
                D_84390240.unk_00->unk_24 += 1;
            }
            break;

        case 2:
            func_8431F680();
            break;
    }
    return sp1C;
}

s32 func_8431FAB4(void) {
    UNUSED s32 pad[2];
    s32 sp1C = 0;
    unk_D_84390010_654* temp_a1 = &D_84390010[0]->unk_654;
    unk_D_84390010_654* temp_a2 = &D_84390010[1]->unk_654;

    if (D_84390240.unk_00->unk_44 != 1) {
        return 0;
    }

    if (!(temp_a1->unk_34 & 0x800) && !(temp_a2->unk_34 & 0x800)) {
        return 0;
    }

    switch (D_84390240.unk_00->unk_24) {
        case 0:
            if (temp_a1->unk_34 & 0x800) {
                func_84302128(D_84390010[0]);
            }
            sp1C = 1;
            D_84390240.unk_00->unk_24 = D_84390240.unk_00->unk_24 + 1;
            break;

        case 1:
            sp1C = 1;
            if (temp_a1->unk_34 & 0x800) {
                if (D_84390010[0]->unk_720->unk_00 & 0x10) {
                    D_84390010[0]->unk_720->unk_00 &= ~0x90;
                    func_84309328(D_84390010[0]);
                    D_84390240.unk_00->unk_24 += 1;
                }
            } else {
                D_84390240.unk_00->unk_24 = D_84390240.unk_00->unk_24 + 1;
            }
            break;

        case 2:
            if (temp_a2->unk_34 & 0x800) {
                func_84302128(D_84390010[1]);
            }
            sp1C = 1;
            D_84390240.unk_00->unk_24 = D_84390240.unk_00->unk_24 + 1;
            break;

        case 3:
            sp1C = 1;
            if (temp_a2->unk_34 & 0x800) {
                if (D_84390010[1]->unk_720->unk_00 & 0x10) {
                    D_84390010[1]->unk_720->unk_00 &= ~0x90;
                    func_84309328(D_84390010[1]);
                    D_84390240.unk_00->unk_24 += 1;
                }
            } else {
                D_84390240.unk_00->unk_24 = D_84390240.unk_00->unk_24 + 1;
            }
            break;

        case 4:
            func_8431F680();
            break;
    }

    return sp1C;
}

void func_8431FC74(void) {
    unk_D_84390010_654_038* temp_v0 = &D_84390010[0]->unk_654.unk_38;
    unk_D_84390010_654_038* temp_v1 = &D_84390010[1]->unk_654.unk_38;

    if (temp_v0->unk_4F == 0) {
        temp_v0->unk_4C &= ~0x20;
    }

    if (temp_v1->unk_4F == 0) {
        temp_v1->unk_4C &= ~0x20;
    }
}

void func_8431FCC4(void) {
}

s32 func_8431FCCC(unk_D_84390010* arg0) {
    unk_D_84390010_654_038* temp_s1 = &arg0->unk_654.unk_38;
    unk_func_80026268_arg0* temp_s2 = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];
    f32 temp_fs0;
    UNUSED s16 pad;
    s16 sp30;

    if (D_84390288 != 0) {
        return 1;
    }

    if (temp_s2->unk_02 == temp_s1->unk_0C) {
        return 1;
    }

    temp_fs0 = temp_s1->unk_28 / 90.0f;
    sp30 = func_84307F00(arg0);
    D_843900A8[sp30] = func_800104AC(D_843900A8[func_84307F00(arg0)], temp_s1->unk_0C, temp_fs0, temp_fs0);
    temp_s2->unk_02 = D_843900A8[func_84307F00(arg0)];
    if (temp_s2->unk_02 == temp_s1->unk_0C) {
        temp_fs0 = D_843900A8[func_84307F00(arg0)] - temp_s2->unk_02;
        D_843900A8[func_84307F00(arg0)] -= temp_fs0;
        if (arg0->unk_000.unk_01A == 0x98) {
            return 1;
        }
        return 1;
    }
    return 0;
}

void func_8431FF18(void) {
    D_84390240.unk_00->unk_3C = 0;
}

void func_8431FF28(void) {
    D_84390240.unk_00->unk_3C = 1;
}

void func_8431FF3C(UNUSED unk_D_86002F34_00C* arg0, s32 arg1) {
    D_84390240.unk_00->unk_38 = arg1;
    D_84390240.unk_00->unk_20 = 0;
}

void func_8431FF5C(unk_D_86002F34_00C* arg0) {
    D_84390240.unk_00->unk_60 = arg0->unk_24.fovy;
}

void func_8431FF70(unk_D_86002F34_00C* arg0) {
    arg0->unk_24.fovy = 30.0f;
    D_84390240.unk_00->unk_60 = 30.0f;
}

s32 func_8431FF8C(unk_D_84390010* arg0) {
    unk_D_8438E7B0_A50* ptr = &D_84384570[func_84307F00(arg0)]->unk_000[arg0->unk_654.unk_38.unk_5A - 1];

    return ptr->unk_0D;
}

s32 func_8431FFD0(unk_D_84390010* arg0) {
    UNUSED s32 pad;
    s32 sp18 = D_84384670[arg0->unk_654.unk_38.unk_5A - 1];
    unk_D_8438E7B0_A50* ptr = &D_84384570[func_84307F00(arg0)]->unk_000[sp18];

    return ptr->unk_0D;
}

s32 func_84320020(unk_D_84390010* arg0) {
    unk_D_8438E7B0_A50* ptr = &D_84384570[func_84307F00(arg0)]->unk_000[arg0->unk_654.unk_38.unk_5A - 1];

    return ptr->unk_0E;
}

s32 func_84320064(unk_D_84390010* arg0) {
    UNUSED s32 pad;
    s32 sp18 = D_84384670[arg0->unk_654.unk_38.unk_5A - 1];
    unk_D_8438E7B0_A50* ptr = &D_84384570[func_84307F00(arg0)]->unk_000[sp18];

    return ptr->unk_0E;
}

s32 func_843200B4(unk_D_84390010* arg0) {
    unk_D_8438E7B0_A50* ptr = &D_84384570[func_84307F00(arg0)]->unk_000[arg0->unk_654.unk_38.unk_5A - 1];

    if (ptr->unk_0F == 0) {
        return 0xF;
    }
    return ptr->unk_0F;
}

void func_84320108(void) {
    s32 sp2C;
    unk_D_84390010_654* temp_s0;
    unk_D_84390010_654* temp_s1;
    unk_D_84390010_654_038* ptr;

    temp_s0 = &D_84390010[0]->unk_654;
    temp_s1 = &D_84390010[1]->unk_654;
    func_8431AFE4(1, 1);

    sp2C = D_84390240.unk_00->unk_2C;
    D_84390240.unk_00->unk_2C = func_8436FC7C(D_84390010[0], D_84390010[1]);

    ptr = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;
    if ((ptr->unk_5A & 0xF0) == 0xF0) {
        D_84390240.unk_00->unk_2C = !D_84390240.unk_00->unk_2C;
    }

    if (D_84390010[0]->unk_724->unk_000 & 2) {
        if (D_84390240.unk_00->unk_2C == 0) {
            func_8438363C(temp_s0->unk_08, temp_s1->unk_08, 0);
        } else {
            func_8438363C(temp_s0->unk_08, temp_s1->unk_08, 1);
        }
    } else if (D_84390010[1]->unk_724->unk_000 & 2) {
        if (D_84390240.unk_00->unk_2C == 1) {
            func_8438363C(temp_s1->unk_08, temp_s0->unk_08, 0);
        } else {
            func_8438363C(temp_s1->unk_08, temp_s0->unk_08, 1);
        }
    }

    D_84390240.unk_00->unk_2A = D_84390240.unk_00->unk_2C;
    D_84390240.unk_00->unk_38 = 0;
    temp_s0->unk_30 = 0;
    temp_s1->unk_30 = 0;
    D_84390240.unk_00->unk_44 = 2;
    func_8437345C();
    D_84390240.unk_00->unk_2C = sp2C;
}

void func_843202A0(void) {
    s32 sp2C;
    unk_D_84390010_654* sp28;
    unk_D_84390010_654* sp24;

    sp28 = &D_84390010[0]->unk_654;
    sp24 = &D_84390010[1]->unk_654;
    func_8431AFE4(1, 1);

    sp2C = D_84390240.unk_00->unk_2C;

    if ((sp28->unk_2D == 0xF) || (sp28->unk_2D == 0x10)) {
        if (D_84390010[0]->unk_724->unk_000 & 2) {
            func_8438363C(sp28->unk_08, sp24->unk_08, 2);
        }
        D_84390240.unk_00->unk_2C = 0;
        D_84390240.unk_00->unk_2A = 0;
        D_84390240.unk_00->unk_38 = 0;
        D_84390240.unk_00->unk_44 = 2;
        func_84373570(D_84390010[0]);
        D_84390240.unk_00->unk_2C = sp2C;
    } else {
        if (D_84390010[0]->unk_724->unk_000 & 2) {
            func_8438363C(sp24->unk_08, sp28->unk_08, 2);
        }
        D_84390240.unk_00->unk_2C = 1;
        D_84390240.unk_00->unk_2A = 1;
        D_84390240.unk_00->unk_38 = 0;
        D_84390240.unk_00->unk_44 = 2;
        func_84373570(D_84390010[1]);
        D_84390240.unk_00->unk_2C = sp2C;
    }
}

s32 func_84320400(void) {
    unk_D_84390010_654* sp24 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;
    unk_D_84390010_654* temp_a3 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;
    unk_D_84390010_654* sp20 = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654;

    if ((D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_2D == 0xF) || (sp24->unk_2D == 0x10)) {
        if (D_84390010[D_84390240.unk_00->unk_2C]->unk_724->unk_000 & 2) {
            func_8438363C(temp_a3->unk_08, sp20->unk_08, 2);
        }
        func_84306200(D_84390010[D_84390240.unk_00->unk_2C], 0x1800);
        D_84390240.unk_00->unk_20 = 0;
        D_84390240.unk_00->unk_14 = 0;
        if (sp24->unk_2D == 0x10) {
            D_84390240.unk_00->unk_38 = 0x12;
        } else {
            func_843081F0(D_84390010[D_84390240.unk_00->unk_2C], &D_843901B0.unk_00);
            func_8431D7D8(&D_843848F0, D_84390240.unk_00->unk_DC, D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390240.unk_00->unk_38 = 0xB;
        }
        return 1;
    }

    return 0;
}

void func_8432056C(void) {
    unk_D_84390010_654* sp1C = &D_84390010[0]->unk_654;
    unk_D_84390010_654* sp18 = &D_84390010[1]->unk_654;

    if ((func_8430CD0C() == 0) && (D_84390134 != 1)) {
        func_8003DB84(1);
    }

    func_8431FC74();
    sp1C->unk_10 = 0;
    sp18->unk_10 = 0;

    if ((sp1C->unk_2D == 0x10) || (sp18->unk_2D == 0x10) || (D_84390240.unk_00->unk_2E == 2)) {
        func_8431AFE4(1, 0);
    } else {
        func_8431AFE4(1, 1);
    }

    D_84390240.unk_00->unk_44 = 1;
    D_84390240.unk_00->unk_20 += 1;
}

s32 func_84320658(s32 arg0) {
    func_8431FF18();
    func_8431AE5C();
    D_84390240.unk_00->unk_48 = 0;
    D_84390240.unk_00->unk_4C = 0;
    D_84390240.unk_00->unk_20 = 0;
    D_84390240.unk_00->unk_14 = 0;
    D_84390240.unk_00->unk_38 = arg0;
    return 1;
}

s32 func_843206B8(s32 arg0) {
    func_8431FF18();
    func_8431AE5C();
    D_84390240.unk_00->unk_4C = 0;
    D_84390240.unk_00->unk_20 = 0;
    D_84390240.unk_00->unk_14 = 0;
    D_84390240.unk_00->unk_38 = arg0;
    return 1;
}

s32 func_84320710(s32 arg0) {
    func_8431FF18();
    func_8431AE5C();
    D_84390240.unk_00->unk_4C = 0;
    D_84390240.unk_00->unk_20 = 0;
    D_84390240.unk_00->unk_14 = 0;
    D_84390240.unk_00->unk_38 = arg0;
    return 1;
}

void func_84320768(unk_D_86002F34_00C* arg0) {
    D_84390240.unk_00->unk_2C = !D_84390240.unk_00->unk_2C;
    func_8431FF3C(arg0, 5);
}

void func_8432079C(u8 arg0) {
    unk_D_84390010_654* temp_a3;

    D_84390240.unk_00->unk_2C = !D_84390240.unk_00->unk_2C;
    temp_a3 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;

    if ((temp_a3->unk_2D == 0xF) || (temp_a3->unk_2D == 0x10)) {
        func_84373570(D_84390010[D_84390240.unk_00->unk_2C]);
    } else {
        func_8437345C();
    }

    D_84390240.unk_00->unk_34 = 1;
    D_84390240.unk_00->unk_A0.z = 0.0f;
    func_8431FF3C(D_84390240.unk_00->unk_DC, 0x24);
    D_84390240.unk_00->unk_78 = arg0;
}

void func_84320864(void) {
    if (func_8431F690(D_84390010[D_84390240.unk_00->unk_2C]) == 0) {
        D_84390240.unk_00->unk_38 = D_84390240.unk_00->unk_78;
    }
}

void func_843208B0(void) {
    unk_D_84390010_654_038* sp24;
    unk_D_84390010_654_038* sp20;
    unk_D_84390010_654* sp1C;

    if (D_84390240.unk_00->unk_34 == 0) {
        func_84301F80(D_84390010[D_84390240.unk_00->unk_2C]);
        func_80048014();
        func_8431F680();

        sp24 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;
        sp20 = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654.unk_38;
        sp1C = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654;

        if ((((sp24->unk_5A & 0xF0) == 0xF0) || ((sp20->unk_5A & 0xF0) == 0xF0)) && (sp1C->unk_2D != 0xF) &&
            (sp1C->unk_2D != 0x10)) {
            D_84390240.unk_00->unk_20 = 0;
            D_84390240.unk_00->unk_14 = 0;
            D_84390240.unk_00->unk_38 = 4;

            if ((sp24->unk_5A & 0xF0) == 0xF0) {
                sp24->unk_5A = 0xA5;
            }

            if ((sp20->unk_5A & 0xF0) == 0xF0) {
                sp20->unk_5A = 0xA5;
            }
        } else {
            func_8432079C(3);
            D_84390240.unk_00->unk_20 = 0;
            D_84390240.unk_00->unk_14 = 0;
        }
    } else {
        sp24 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;
        sp20 = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654.unk_38;

        func_84301F80(D_84390010[D_84390240.unk_00->unk_2C]);
        func_80048014();
        func_8431F680();

        D_84390240.unk_00->unk_20 = 0;
        D_84390240.unk_00->unk_14 = 0;
        D_84390240.unk_00->unk_38 = 4;

        if ((sp24->unk_5A & 0xF0) == 0xF0) {
            sp24->unk_5A = 0xA5;
        }

        if ((sp20->unk_5A & 0xF0) == 0xF0) {
            sp20->unk_5A = 0xA5;
        }
    }
}

s32 func_84320A8C(void) {
    unk_D_84390010_654_038* temp_v0 = &D_84390200->unk_654.unk_38;

    if (((temp_v0->unk_4D & 0x80) || (temp_v0->unk_15 & 0x18)) && ((temp_v0->unk_5A & 0xF0) == 0xF0)) {
        func_84301F80(D_84390010[D_84390240.unk_00->unk_2C]);
        func_80048014();
        func_8431F680();
        func_8432079C(3);
        D_84390240.unk_00->unk_20 = 0;
        D_84390240.unk_00->unk_48 = 0;
        D_84390240.unk_00->unk_14 = 0;
        return 1;
    }
    return 0;
}

void func_84320B48(void) {
    if ((D_84390240.unk_00->unk_34 == 0) && ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) != 0xF0)) {
        func_84301F80(D_84390010[D_84390240.unk_00->unk_2C]);
        func_80048014();
        func_8431F680();
        func_8432079C(3);
        D_84390240.unk_00->unk_20 = 0;
        D_84390240.unk_00->unk_14 = 0;
    } else if (func_84320A8C() == 0) {
        func_84301F80(D_84390010[D_84390240.unk_00->unk_2C]);
        func_80048014();
        func_8431F680();
        D_84390240.unk_00->unk_20 = 0;
        D_84390240.unk_00->unk_14 = 0;
        D_84390240.unk_00->unk_38 = 4;
    }
}

void func_84320C38(unk_D_86002F34_00C* arg0) {
    if ((D_84390220 == 1) && (D_84390224 == 1)) {
        if (func_84308164(D_84390010[D_84390240.unk_00->unk_2C]) == 0) {
            func_84320768(arg0);
        } else if (func_84308164(D_84390010[!D_84390240.unk_00->unk_2C]) == 0) {
            func_8431FF3C(arg0, 5);
        } else {
            func_84320B48();
        }
    }
}

void func_84320CEC(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654_038* sp1C = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;

    D_84390220 = func_8431FCCC(D_84390010[0]);
    D_84390224 = func_8431FCCC(D_84390010[1]);
    func_8431FF18();
    func_8431AE5C();

    if (func_84308164(D_84390010[D_84390240.unk_00->unk_2C]) == 0) {
        func_84320768(arg0);
    } else if (func_84308164(D_84390010[!D_84390240.unk_00->unk_2C]) == 0) {
        func_84320C38(arg0);
    } else if (D_84390240.unk_00->unk_4C == 0xA) {
        func_84320710(0xA);
    } else if (D_84390240.unk_00->unk_48 == 9) {
        func_84320658(9);
    } else if ((sp1C->unk_15 & 0x18) || (sp1C->unk_4D & 0x80)) {
        func_84320658(6);
    } else {
        func_84320C38(arg0);
    }
}

void func_84320E54(unk_D_86002F34_00C* arg0) {
    if ((D_84390220 == 1) && (D_84390224 == 1)) {
        func_843184FC();
        func_84320CEC(arg0);
    }
}

s32 func_84320EA0(void) {
    switch (D_84390240.unk_00->unk_48) {
        case 7:
        case 38:
        case 39:
            func_84305760(D_84390204, 3);
            return func_843206B8(0x25);

        case 30:
            func_84305760(D_84390204, 3);
            return func_843206B8(0x25);

        case 28:
            return func_843206B8(0x25);

        case 21:
            func_84305760(D_84390204, 3);
            return func_843206B8(0x25);

        case 15:
            return func_843206B8(0x25);

        case 25:
            return func_843206B8(0x25);

        case 27:
            return func_843206B8(0x25);

        case 29:
            func_84305760(D_84390204, 3);
            return func_843206B8(0x25);

        case 12:
            func_84305760(D_84390204, 8);
            return func_843206B8(0x25);

        case 13:
            func_84305760(D_84390204, 8);
            return func_843206B8(0x25);

        case 14:
            func_84305760(D_84390204, 8);
            return func_843206B8(0x25);

        case 17:
            func_84305760(D_84390204, 9);
            return func_843206B8(0x25);

        case 31:
            return func_843206B8(0x25);
    }
    return 0;
}

s32 func_8432103C(void) {
    s32 tmp = D_84390240.unk_00->unk_48;

    if (tmp != 0x10) {
        if (D_84390240.unk_00->unk_48 == 0x14) {
            return func_84320658(0x14);
        }
    } else {
        return func_84320658(0x10);
    }

    if ((D_843C4DA4 != 0) || (D_84390240.unk_00->unk_48 == 8)) {
        return func_84320658(8);
    }
    return 0;
}

s32 func_843210BC(void) {
    s32 idx = D_84390240.unk_00->unk_2C;
    unk_D_84390010_654_038* temp_v1_2 = &D_84390010[idx]->unk_654.unk_38;

    if (((temp_v1_2->unk_4D & 0x80) || (temp_v1_2->unk_15 & 0x18)) && ((temp_v1_2->unk_5A & 0xF0) == 0xF0)) {
        return func_84320658(0x23);
    }
    return 0;
}

void func_8432113C(void) {
    s32 idx;

    D_84390204 = D_84390010[D_84390240.unk_00->unk_2C];
    idx = D_84390240.unk_00->unk_2C == 0;
    D_84390200 = D_84390010[idx];
}

void func_84321184(unk_D_86002F34_00C* arg0) {
    func_8003DB84(0);
    func_8431AFD0(arg0, 20.0f, 12800.0f);
    func_8431F680();
    D_84390240.unk_00->unk_34 = 0;
    func_8431FF18();
    D_84390240.unk_00->unk_14 = 0;
    func_843087F8(D_84390010[0]);
    func_843087F8(D_84390010[1]);
    D_84390240.unk_00->unk_20++;
}

void func_84321208(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654* temp_t2 = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654;
    unk_D_84390010_654* temp_t1 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;
    s16 sp2E = D_84390010[D_84390240.unk_00->unk_2C]->unk_000.unk_01A;
    unk_D_8438E7B0_A50* sp28 = &D_84384570[D_84390240.unk_00->unk_2C]->unk_A50;
    unk_D_84390010* sp24 = D_84390010[D_84390240.unk_00->unk_2C];

    if (((temp_t2->unk_2D == 0x13) && (temp_t1->unk_2D == 0x13)) ||
        ((temp_t2->unk_2D == 0x10) && (temp_t1->unk_2D == 0x13)) ||
        ((temp_t1->unk_2D == 0x10) && (temp_t2->unk_2D == 0x13))) {
        func_843184E4(0xE);
        func_8000E88C(&arg0->unk_60.at, 0.0f, 75.0f, 0.0f);
        func_8000E88C(&arg0->unk_60.eye, 0.0f, 80.0f, 400.0f);
        func_8004153C();
        D_84390240.unk_00->unk_20 = 8;
        return;
    }

    if (temp_t1->unk_34 & 0x4008) {
        sp24->unk_000.unk_01D = 0xFF;
        func_8432C80C(4, sp24);
        sp24->unk_000.unk_024.y = D_84390028[D_84390240.unk_00->unk_2C].unk_08;
        sp24->unk_000.unk_000.unk_02 &= ~0x2;
        sp24->unk_000.unk_000.unk_02 |= 0x20;
        sp24->unk_000.unk_000.unk_01 |= 1;
        func_84306200(sp24, 0x4608);
    }

    if (D_84390010[D_84390240.unk_00->unk_2C]->unk_4B4 == 0xA) {
        func_84308654(D_84390010[D_84390240.unk_00->unk_2C], 0, 0);
    }

    if (D_84390010[D_84390240.unk_00->unk_2C]->unk_4B4 == 0xD) {
        func_84308654(D_84390010[D_84390240.unk_00->unk_2C], 0, 0);
    }

    if (D_84390010[D_84390240.unk_00->unk_2C]->unk_4B4 == 0x10) {
        func_84308654(D_84390010[D_84390240.unk_00->unk_2C], 0, 0);
    }

    D_84390010[D_84390240.unk_00->unk_2C]->unk_000.unk_01E.x = 0;
    if ((sp2E == 0x32) || (sp2E == 0x33)) {
        D_84390010[D_84390240.unk_00->unk_2C]->unk_000.unk_000.unk_02 |= 0x20;
        D_84390010[D_84390240.unk_00->unk_2C]->unk_000.unk_000.unk_01 |= 1;
        func_8001BD04(&D_84390010[D_84390240.unk_00->unk_2C]->unk_000, sp28->unk_00);
    }

    func_843087F8(D_84390010[D_84390240.unk_00->unk_2C]);
    func_8000E88C(&D_84390010[D_84390240.unk_00->unk_2C]->unk_000.unk_030, 1.0f, 1.0f, 1.0f);
    D_84390010[D_84390240.unk_00->unk_2C]->unk_000.unk_024.y = func_84307BAC(D_84390010[D_84390240.unk_00->unk_2C]);
    func_843081F0(D_84390010[D_84390240.unk_00->unk_2C], &D_843901B0.unk_00);
    func_8431D7D8(&D_84384AF8, arg0, D_84390010[D_84390240.unk_00->unk_2C]);
    func_8431D5D0(arg0, D_84390010[D_84390240.unk_00->unk_2C], 1);
    func_8004153C();
    D_84390240.unk_00->unk_20 = 6;
}

s32 func_84321594(unk_D_84390010* arg0) {
    UNUSED s32 pad;
    unk_D_84390010_654* sp28 = &arg0->unk_654;

    D_84390240.unk_00->unk_54 = 0;
    func_8432B13C(arg0);

    if (sp28->unk_34 & 0x200) {
        func_84306200(arg0, 0x60C);
        return 1;
    }

    if (sp28->unk_34 & 0x4008) {
        arg0->unk_000.unk_01D = 0xFF;
        func_8432C80C(4, arg0);
        arg0->unk_000.unk_024.y = D_84390028[func_84307F00(arg0)].unk_08;
        arg0->unk_000.unk_000.unk_02 &= ~0x2;
        arg0->unk_000.unk_000.unk_02 |= 0x20;
        arg0->unk_000.unk_000.unk_01 |= 1;
        func_84306200(arg0, 0x4608);
    }

    func_8432B38C(arg0);
    sp28->unk_2E = 0xFF;
    func_8001BE34(&arg0->unk_000, 0xFF, 0xFF, 0xFF, sp28->unk_2E);
    func_843066E0(arg0);
    arg0->unk_000.unk_01E.x = 0;
    return 0;
}

void func_84321698(unk_D_86002F34_00C* arg0) {
    if (func_8431F690(D_84390010[!D_84390240.unk_00->unk_2C]) == 0) {
        func_84306200(D_84390010[!D_84390240.unk_00->unk_2C], 0x1800);
        func_80048014();
        func_8432E9D8(2);
        func_8431AE5C();
        func_8003F1AC(func_84308D98(D_84390010[!D_84390240.unk_00->unk_2C]));

        if (func_84321594(D_84390010[!D_84390240.unk_00->unk_2C]) != 0) {
            func_84305760(D_84390010[!D_84390240.unk_00->unk_2C], 0x11);
            func_8431BA5C();
            D_84390240.unk_00->unk_20 = 0xA;
        } else {
            func_84305760(D_84390010[!D_84390240.unk_00->unk_2C], 0);
            func_8431BA5C();
            D_84390240.unk_00->unk_20++;
        }

        func_8431F500(D_84390010[!D_84390240.unk_00->unk_2C], arg0, 3);

        if (func_84307B60(D_84390010[!D_84390240.unk_00->unk_2C]) != 0) {
            func_8004E810(0xC8, 1);
        } else {
            func_8004E810(D_84390010[!D_84390240.unk_00->unk_2C]->unk_000.unk_01A, 1);
        }
    }
}

void func_84321860(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad[2];
    unk_D_84390010_654* sp24 = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654;
    unk_D_8438E7B0_A50* sp20 = &D_84384570[!D_84390240.unk_00->unk_2C]->unk_A70;

    if (func_84301FB0(D_84390010[!D_84390240.unk_00->unk_2C]) == 0) {
        if (D_84390240.unk_00->unk_14 == 0x1D) {
            func_8431F500(D_84390010[!D_84390240.unk_00->unk_2C], arg0, 4);
        }

        if (func_8431ADF0(0x1E) != 0) {
            func_8431CFA4(arg0, D_84390010[!D_84390240.unk_00->unk_2C]);
        }

        if (((sp20->unk_04 >> 1) == (D_84390010[!D_84390240.unk_00->unk_2C]->unk_000.unk_040.unk_08 >> 0x10)) &&
            (sp24->unk_2D != 0x12)) {
            func_843184E4(9);
        }

        if (sp20->unk_0A == ((D_84390010[!D_84390240.unk_00->unk_2C]->unk_000.unk_040.unk_08 >> 0x10) + 3)) {
            D_84390010[!D_84390240.unk_00->unk_2C]->unk_000.unk_000.unk_02 &= ~0x20;
            func_843061EC(D_84390010[!D_84390240.unk_00->unk_2C], 0x100);
            func_8431AE5C();
            D_84390240.unk_00->unk_20 += 1;
        }
        func_8431CEF0(arg0, D_84390010[!D_84390240.unk_00->unk_2C], 0);
    }
}

void func_84321A40(unk_D_86002F34_00C* arg0) {
    func_8431CEF0(arg0, D_84390010[!D_84390240.unk_00->unk_2C], 1);
    if (func_8431ADAC(0x19) != 0) {
        func_80048014();
        D_84390240.unk_00->unk_20++;
    }
}

void func_84321AAC(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654* temp_s0 = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654;

    func_8431CEF0(arg0, D_84390010[!D_84390240.unk_00->unk_2C], 1);

    if (func_8431ADAC(5) != 0) {
        func_8432E9D8(1);
        func_80037234(3, 0);

        if (temp_s0->unk_2D != 0x12) {
            temp_s0->unk_2D = 0x10;
        }

        if (temp_s0->unk_2D == 0x12) {
            temp_s0->unk_2D = 0x13;
        }

        D_84390240.unk_00->unk_20++;
    }
}

void func_84321B54(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654* sp24 = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654;
    unk_D_84390010_654* sp20 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;

    if (func_8431ADAC(0xA) != 0) {
        func_8431AE5C();
        func_8431FF18();
        D_84390240.unk_00->unk_20++;
        if (sp24->unk_2D == 0x10) {
            D_84390240.unk_00->unk_14 = 0;
            D_84390240.unk_00->unk_20 = 0;

            if ((sp20->unk_2D == 0x11) || (sp20->unk_2D == 0x12)) {
                D_84390240.unk_00->unk_38 = 5;
                D_84390240.unk_00->unk_2C = !D_84390240.unk_00->unk_2C;
            } else if ((sp24->unk_2D == 0x13) || (sp20->unk_2D == 0x13)) {
                func_843184E4(0xE);
                func_8000E88C(&arg0->unk_60.at, 0.0f, 75.0f, 0.0f);
                func_8000E88C(&arg0->unk_60.eye, 0.0f, 80.0f, 400.0f);
                func_8004153C();
                D_84390240.unk_00->unk_2C = !D_84390240.unk_00->unk_2C;
                D_84390240.unk_00->unk_20 = 8;
            } else {
                D_84390240.unk_00->unk_38 = 4;
            }
        } else if ((sp20->unk_2D == 0x12) || (sp20->unk_2D == 0x11)) {
            D_84390240.unk_00->unk_14 = 0;
            D_84390240.unk_00->unk_20 = 0;
            D_84390240.unk_00->unk_38 = 5;
            D_84390240.unk_00->unk_2C = !D_84390240.unk_00->unk_2C;
        } else {
            func_84321208(arg0);
        }
        func_80048014();
    }
}

void func_84321D34(UNUSED unk_D_86002F34_00C* arg0) {
}

void func_84321D3C(unk_D_86002F34_00C* arg0) {
    unk_D_84390010* temp_s0;
    UNUSED s32 pad;
    f32 sp44;
    f32 sp40;
    s16 sp3E;
    UNUSED s16 pad2;
    u8 sp3B;
    s16 tmp1;

    temp_s0 = D_84390010[D_84390240.unk_00->unk_2C];
    sp3B = temp_s0->unk_000.unk_01A - 1;

    if (func_8431D118(arg0, temp_s0, 1, 0) != 0) {
        func_8431AE5C();
        func_843184E4(0xE);
        func_8431AFD0(arg0, 10.0f, 12800.0f);
        arg0->unk_24.fovy = 60.0f;
        if ((D_84390010[D_84390240.unk_00->unk_2C]->unk_000.unk_01A == 0x5F) && (D_84390240.unk_00->unk_2C == 1)) {
            sp3B = 0x97;
        }

        sp44 = (D_84384580[D_84390240.unk_00->unk_2C]->unk_00.y + temp_s0->unk_000.unk_024.y) + D_84384C30[sp3B].z;
        sp40 = ((D_84384580[D_84390240.unk_00->unk_2C]->unk_00.z + D_84384C30[sp3B].y) * temp_s0->unk_4B0) +
               temp_s0->unk_000.unk_024.x;

        func_8000E88C(&arg0->unk_60.at, sp40, sp44, temp_s0->unk_000.unk_024.z);

        sp40 = D_84384580[D_84390240.unk_00->unk_2C]->unk_00.x * D_84384C30[sp3B].x;
        sp3E = D_84384580[D_84390240.unk_00->unk_2C]->unk_0C;
        tmp1 = (temp_s0->unk_4B0 * D_84384580[D_84390240.unk_00->unk_2C]->unk_0E) + func_84308190(temp_s0);
        func_80010354(&arg0->unk_60.at, &arg0->unk_60.eye, sp40, sp3E, tmp1);
        D_84390240.unk_00->unk_20++;
    }
}

void func_84321F2C(UNUSED unk_D_86002F34_00C* arg0) {
    if (func_8431ADAC(0x50) != 0) {
        D_84390240.unk_00->unk_40 = D_84390240.unk_00->unk_2C + 1;
        func_843184FC();
        func_8004B9C4(0x14);
    }
}

void func_84321F74(UNUSED unk_D_86002F34_00C* arg0) {
    if (func_8431ADAC(0x7D) != 0) {
        D_84390240.unk_00->unk_40 = D_84390240.unk_00->unk_2C + 1;
        func_8004B9C4(0x14);
    }
}

void func_84321FB8(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad[2];
    unk_D_84390010_654* sp24 = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654;
    unk_D_8438E7B0_A50* sp20 = &D_84384570[!D_84390240.unk_00->unk_2C]->unk_B10;

    if (func_84301FB0(D_84390010[!D_84390240.unk_00->unk_2C]) == 0) {
        if (D_84390240.unk_00->unk_14 == 0x1D) {
            func_8431F500(D_84390010[!D_84390240.unk_00->unk_2C], arg0, 4);
        }

        if (func_8431ADF0(0x1E) != 0) {
            func_8431CFA4(arg0, D_84390010[!D_84390240.unk_00->unk_2C]);
        }

        if (((sp20->unk_04 >> 1) == (D_84390010[!D_84390240.unk_00->unk_2C]->unk_000.unk_040.unk_08 >> 0x10)) &&
            (sp24->unk_2D != 0x12)) {
            func_843184E4(9);
        }

        if (sp20->unk_0A == ((D_84390010[!D_84390240.unk_00->unk_2C]->unk_000.unk_040.unk_08 >> 0x10) + 3)) {
            D_84390010[!D_84390240.unk_00->unk_2C]->unk_000.unk_000.unk_02 &= ~0x20;
            func_843061EC(D_84390010[!D_84390240.unk_00->unk_2C], 0x100);
            func_8431AE5C();
            func_8431B858(D_84390010[!D_84390240.unk_00->unk_2C], arg0);
            D_84390240.unk_00->unk_20 = 2;
        }

        func_8431CEF0(arg0, D_84390010[!D_84390240.unk_00->unk_2C], 0);
    }
}

void func_843221A8(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_84321698(arg0);
            break;

        case 1:
            func_84321860(arg0);
            break;

        case 2:
            func_84321A40(arg0);
            break;

        case 3:
            func_84321AAC(arg0);
            break;

        case 4:
            func_84321B54(arg0);
            break;

        case 5:
            func_84321D34(arg0);
            break;

        case 6:
            func_84321D3C(arg0);
            break;

        case 7:
            func_84321F2C(arg0);
            break;

        case 8:
            func_84321F74(arg0);
            break;

        case 10:
            func_84321FB8(arg0);
            break;
    }
}

void func_84322284(UNUSED unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654* sp1C = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654;

    if (func_8431ADAC(2) != 0) {
        func_8431AE5C();
        func_8431FF18();
        D_84390240.unk_00->unk_20 += 1;
        if (sp1C->unk_2D == 0x10) {
            D_84390240.unk_00->unk_14 = 0;
            D_84390240.unk_00->unk_20 = 0;
            D_84390240.unk_00->unk_38 = 4;
        } else {
            D_84390240.unk_00->unk_40 = D_84390240.unk_00->unk_2C + 1;
        }
        func_80048014();
    }
}

void func_84322350(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_84321698(arg0);
            break;

        case 1:
            func_84321860(arg0);
            break;

        case 2:
            func_84321A40(arg0);
            break;

        case 3:
            func_84321AAC(arg0);
            break;

        case 4:
            func_84322284(arg0);
            break;

        case 5:
            func_84321D34(arg0);
            break;

        case 10:
            func_84321FB8(arg0);
            break;
    }
}

void func_843223FC(unk_D_84390010* arg0) {
    unk_D_84390010_654* ptr = &arg0->unk_654;

    if (ptr->unk_34 & 0x200) {
        arg0->unk_000.unk_024.y = D_84390028[func_84307F00(arg0)].unk_08;
        func_84306200(arg0, 0x608);
    } else if (ptr->unk_34 & 0x4008) {
        arg0->unk_000.unk_01D = 0xFF;
        func_8432C80C(4, arg0);
        arg0->unk_000.unk_024.y = D_84390028[func_84307F00(arg0)].unk_08;
        arg0->unk_000.unk_000.unk_02 &= ~0x2;
        arg0->unk_000.unk_000.unk_02 |= 0x20;
        arg0->unk_000.unk_000.unk_01 |= 1;
        func_84306200(arg0, 0x4608);
    }
}

void func_843224C8(unk_D_86002F34_00C* arg0) {
    s32 sp24;
    unk_D_84390010_654* sp20 = &D_84390010[0]->unk_654;
    unk_D_84390010_654* sp1C = &D_84390010[1]->unk_654;

    func_84301B00();
    func_8431F680();

    sp24 = func_8430C414(5);
    if (sp24 >= 5) {
        sp24 = 0;
    }

    if ((sp20->unk_34 & 0x4000) || ((sp1C->unk_34 & 0x4000) != 0)) {
        sp24 = 2;
    } else if ((sp20->unk_34 & 0x200) || (sp1C->unk_34 & 0x200)) {
        sp24 = 4;
    } else if ((sp20->unk_2D == 0x10) || (sp1C->unk_2D == 0x10)) {
        sp24 = 2;
    }

    func_8430C1E4(&D_843901B0.unk_00, &D_84385B90);
    func_8431D968(&D_84384B2C[sp24], arg0);
    func_8431D5D0(arg0, D_84390204, 0);
    D_84390240.unk_00->unk_20++;
}

void func_84322600(unk_D_86002F34_00C* arg0) {
    if (func_8431D118(arg0, D_84390204, 0, 1) != 0) {
        func_8431FF3C(arg0, 2);
    }
}

void func_84322640(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_843224C8(arg0);
            break;

        case 1:
            func_84322600(arg0);
            break;
    }
}

void func_84322698(unk_D_84390010* arg0) {
    arg0->unk_654.unk_30 = 0x800;
}

void func_843226A4(UNUSED unk_D_86002F34_00C* arg0) {
    func_8432E9D8(2);
    func_84322698(D_84390204);
    func_8430203C(D_84390204);
}

void func_843226E0(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654_038* sp1C = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;
    unk_D_84390010_654* sp18 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;
    s32 var_t0;

    if (D_84390240.unk_00->unk_48 == 0xE) {
        var_t0 = func_8431FFD0(D_84390010[D_84390240.unk_00->unk_2C]);
    } else if ((D_84390240.unk_00->unk_48 == 0x1C) || (D_84390240.unk_00->unk_48 == 0x11) ||
               (D_84390240.unk_00->unk_48 == 0x1F)) {
        var_t0 = 0;
    } else {
        var_t0 = func_8431FF8C(D_84390010[D_84390240.unk_00->unk_2C]);
    }

    if ((sp1C->unk_5A == 0x3A) || (sp1C->unk_5A == 0x8F)) {
        if ((D_84390240.unk_00->unk_48 != 0x1C) && (D_84390240.unk_00->unk_48 != 0x11) &&
            (D_84390240.unk_00->unk_48 != 0x1F)) {
            var_t0 = 0x16;
        }
    }

    switch (var_t0) {
        case 20:
            func_8431F290(D_84390204, arg0,
                          D_84390240.unk_00->unk_50 = D_84385B70[func_8430C384(ARRAY_COUNT(D_84385B70))], 1);
            break;

        case 21:
            func_8431F290(D_84390204, arg0,
                          D_84390240.unk_00->unk_50 = D_84385B78[func_8430C384(ARRAY_COUNT(D_84385B78))], 1);
            break;

        case 22:
            func_8431F290(D_84390204, arg0,
                          D_84390240.unk_00->unk_50 = D_84385B7C[func_8430C384(ARRAY_COUNT(D_84385B7C))], 1);
            break;

        case 23:
            func_8431F290(D_84390204, arg0,
                          D_84390240.unk_00->unk_50 = D_84385B80[func_8430C384(ARRAY_COUNT(D_84385B80))], 1);
            break;

        case 24:
            func_8431F290(D_84390204, arg0,
                          D_84390240.unk_00->unk_50 = D_84385B88[func_8430C384(ARRAY_COUNT(D_84385B88))], 1);
            break;

        default:
            func_8431F290(D_84390204, arg0, D_84390240.unk_00->unk_50 = var_t0, 1);
            if (sp18->unk_34 & 0x4000) {
                arg0->unk_60.at.y = 0.0f;
            }
            break;
    }
}

s32 func_843229A4(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad;
    unk_D_84390010_654* sp20 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;

    func_8431AE5C();
    func_843226E0(arg0);

    if (func_84320EA0() != 0) {
        return 0;
    }

    if (D_84390240.unk_00->unk_48 == 0x14) {
        func_84305760(D_84390010[D_84390240.unk_00->unk_2C], 0x15);
    } else if (D_84390240.unk_00->unk_48 == 0x18) {
        func_84305760(D_84390010[D_84390240.unk_00->unk_2C], 3);
    } else if (sp20->unk_34 & 0x4400) {
        func_84305760(D_84390010[D_84390240.unk_00->unk_2C], 3);
        func_8431F290(D_84390010[D_84390240.unk_00->unk_2C], arg0, D_84390240.unk_00->unk_50 = 2, 1);
    } else {
        func_84305760(D_84390010[D_84390240.unk_00->unk_2C], 3);
    }

    func_8431FF18();
    return 1;
}

void func_84322B04(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654* sp1C = &D_84390204->unk_654;

    func_8430C718(&arg0->unk_24.fovy, 30.0f, 0.05f);

    switch (D_84390240.unk_00->unk_3C) {
        case 0:
            func_843066E0(D_84390010[0]);
            func_843066E0(D_84390010[1]);

            if ((func_84320400() == 0) && (func_843210BC() == 0)) {
                func_84306470(D_84390204);
                func_843226A4(arg0);
                func_8431FF28();

                if ((D_84390240.unk_00->unk_34 == 1) && (D_84390200->unk_4C8 == 1)) {
                    func_843223FC(D_84390200);
                }

                func_843081F0(D_84390204, &D_843901B0.unk_00);

                if (sp1C->unk_34 & 0x4000) {
                    D_843901B0.unk_00.y = 15.000001f;
                }

                if (D_84390240.unk_00->unk_34 == 1) {
                    func_8431FF70(arg0);

                    if ((D_84390240.unk_00->unk_48 == 0x1C) || (D_84390240.unk_00->unk_48 == 0x11) ||
                        (D_84390240.unk_00->unk_48 == 0x1F)) {
                        func_8431F420(D_84390204, arg0, 3);
                    } else {
                        func_8431F420(D_84390204, arg0, 4);
                    }

                    if (sp1C->unk_34 & 0x4000) {
                        arg0->unk_60.at.y = 15.000001f;
                    }
                    func_843087F8(D_84390204);
                } else if ((D_84390240.unk_00->unk_48 == 0x1C) || (D_84390240.unk_00->unk_48 == 0x11) ||
                           (D_84390240.unk_00->unk_48 == 0x1F)) {
                    func_8431D7D8(&D_8438498C, arg0, D_84390204);
                } else {
                    func_8431D7D8(&D_843848F0, arg0, D_84390204);
                }
            }
            break;

        case 1:
            if (func_84302000(D_84390204) != 0) {
                D_84390234 = D_84390230 = D_8439022C;
                func_843184E4(0);
                func_8431AE5C();
                D_84390240.unk_00->unk_3C += 1;
            }
            break;

        case 2:
            if (D_84390240.unk_00->unk_34 == 1) {
                if ((D_84390240.unk_00->unk_48 == 0x1C) || (D_84390240.unk_00->unk_48 == 0x11) ||
                    (D_84390240.unk_00->unk_48 == 0x1F)) {
                    if (func_8431ADAC(0xA) != 0) {
                        func_8431FF70(arg0);
                        if (func_843229A4(arg0) != 0) {
                            D_84390240.unk_00->unk_20 = 1;
                        }
                    }
                } else if (func_8431ADAC(0x28) != 0) {
                    func_8431FF70(arg0);
                    if (func_843229A4(arg0) != 0) {
                        D_84390240.unk_00->unk_20 = 1;
                    }
                }
            } else if (func_8431D118(arg0, D_84390204, 1, 1) != 0) {
                func_8431FF70(arg0);
                if (func_843229A4(arg0) != 0) {
                    D_84390240.unk_00->unk_20 = 1;
                }
            }
            break;
    }
}

void func_84322E70(unk_D_86002F34_00C* arg0) {
    s32 temp_v0;
    s32 temp_t0;

    if (D_84390230 != D_8439022C) {
        temp_v0 = func_84320020(D_84390010[D_84390240.unk_00->unk_2C]) & 0xFFFFFFFF;
        switch (temp_v0) {
            case 20:
                do {
                    temp_t0 = D_84385B70[func_8430C384(5.0f)];
                } while (temp_t0 == D_84390240.unk_00->unk_50);
                D_84390240.unk_00->unk_50 = temp_t0;
                func_8431F290(D_84390204, arg0, D_84390240.unk_00->unk_50, 1);
                break;

            case 21:
                do {
                    temp_t0 = D_84385B78[func_8430C384(4.0f)];
                } while (temp_t0 == D_84390240.unk_00->unk_50);
                D_84390240.unk_00->unk_50 = temp_t0;
                func_8431F290(D_84390204, arg0, D_84390240.unk_00->unk_50, 1);
                break;

            case 22:
                do {
                    temp_t0 = D_84385B7C[func_8430C384(3.0f)];
                } while (temp_t0 == D_84390240.unk_00->unk_50);
                D_84390240.unk_00->unk_50 = temp_t0;
                func_8431F290(D_84390204, arg0, D_84390240.unk_00->unk_50, 1);
                break;

            case 23:
                do {
                    temp_t0 = D_84385B80[func_8430C384(6.0f)];
                } while (temp_t0 == D_84390240.unk_00->unk_50);
                D_84390240.unk_00->unk_50 = temp_t0;
                if (1) {}
                if (1) {}
                if (1) {}
                if (1) {}
                func_8431F290(D_84390204, arg0, D_84390240.unk_00->unk_50, 1);
                break;

            case 24:
                do {
                    temp_t0 = D_84385B88[func_8430C384(4.0f)];
                } while (temp_t0 == D_84390240.unk_00->unk_50);
                D_84390240.unk_00->unk_50 = temp_t0;
                func_8431F290(D_84390204, arg0, D_84390240.unk_00->unk_50, 1);
                break;

            default:
                if (temp_v0 != D_84390240.unk_00->unk_50) {
                    func_8431F290(D_84390204, arg0, temp_v0, 1);
                }
                break;
        }
    }
}

void func_843230D8(unk_D_86002F34_00C* arg0, s32 arg1) {
    unk_D_84390010_654_038* sp1C = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;
    s32 sp18;

    if ((D_84390240.unk_00->unk_50 != 1) && (D_84390240.unk_00->unk_50 != 4) && (D_84390240.unk_00->unk_50 != 5) &&
        (D_84390240.unk_00->unk_50 != 8) && (D_84390240.unk_00->unk_50 != 9) && (D_84390240.unk_00->unk_50 != 0xA) &&
        (D_84390240.unk_00->unk_50 != 0xB)) {
        if (arg1 == 1) {
            sp18 = func_84320064(D_84390010[D_84390240.unk_00->unk_2C]);
        } else {
            sp18 = func_84320020(D_84390010[D_84390240.unk_00->unk_2C]);
        }

        if ((sp1C->unk_5A == 0x3A) || (sp1C->unk_5A == 0x8F)) {
            sp18 = 0x19;
        }

        if (sp18 == 25) {
            return;
        }

        switch (sp18) {
            case 20:
                D_84390240.unk_00->unk_50 = D_84385B70[func_8430C384(ARRAY_COUNT(D_84385B70))];
                if (sp18 != D_84390240.unk_00->unk_50) {
                    func_8431F290(D_84390204, arg0, D_84390240.unk_00->unk_50, 1);
                }
                break;

            case 21:
                D_84390240.unk_00->unk_50 = D_84385B78[func_8430C384(ARRAY_COUNT(D_84385B78))];
                if (sp18 != D_84390240.unk_00->unk_50) {
                    func_8431F290(D_84390204, arg0, D_84390240.unk_00->unk_50, 1);
                }
                break;

            case 22:
                D_84390240.unk_00->unk_50 = D_84385B7C[func_8430C384(ARRAY_COUNT(D_84385B7C))];
                if (sp18 != D_84390240.unk_00->unk_50) {
                    func_8431F290(D_84390204, arg0, D_84390240.unk_00->unk_50, 1);
                }
                break;

            case 23:
                D_84390240.unk_00->unk_50 = D_84385B80[func_8430C384(ARRAY_COUNT(D_84385B80))];
                if (sp18 != D_84390240.unk_00->unk_50) {
                    func_8431F290(D_84390204, arg0, D_84390240.unk_00->unk_50, 1);
                }
                break;

            case 24:
                D_84390240.unk_00->unk_50 = D_84385B88[func_8430C384(ARRAY_COUNT(D_84385B88))];
                if (sp18 != D_84390240.unk_00->unk_50) {
                    func_8431F290(D_84390204, arg0, D_84390240.unk_00->unk_50, 1);
                }
                break;

            default:
                if (sp18 != D_84390240.unk_00->unk_50) {
                    if (1) {}
                    func_8431F290(D_84390204, arg0, sp18, 1);
                }
                break;
        }
    }
}

s32 func_843233E0(unk_D_86002F34_00C* arg0, s32 arg1) {
    UNUSED s32 pad;
    s32 sp18 = 0;

    switch (D_84390240.unk_00->unk_50) {
        case 1:
            func_8430C718(&arg0->unk_24.fovy, 60.0f, 0.03f);
            sp18 = 1;
            break;

        case 4:
        case 5:
        case 8:
        case 9:
        case 10:
        case 11:
            func_8431D318(arg0, D_84390204);
            sp18 = 1;
            break;

        default:
            if ((D_84390204->unk_4B4 != 6) && (D_84390204->unk_4B4 != 4) && (arg1 != 0)) {
                func_8431C71C(arg0, D_84390204);
            }
            break;
    }
    return sp18;
}

void func_843234A0(UNUSED unk_D_86002F34_00C* arg0) {
    func_84306584(D_84390204);
    func_84306200(D_84390204, 0x10);
    if (func_8432103C() == 0) {
        D_84390240.unk_00->unk_20 = 2;
    }
    func_8432E9D8(1);
}

s32 func_843234FC(UNUSED unk_D_86002F34_00C* arg0) {
    if (func_8431ADAC(func_843200B4(D_84390204)) != 0) {
        return 1;
    }
    return 0;
}

void func_84323538(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_3C) {
        case 0:
            func_843233E0(arg0, 1);
            if (func_843234FC(arg0) != 0) {
                func_8431AE5C();
                func_8431FF28();
                func_843230D8(arg0, 0);
            }
            break;

        case 1:
            func_843233E0(arg0, 1);
            if (func_84305CAC(D_84390204, 0x32) != 0) {
                func_8431AE5C();
                func_8431FF18();
                func_843234A0(arg0);
            }
            break;
    }
}

void func_843235F4(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_3C) {
        case 0:
            func_8431C71C(arg0, D_84390204);
            if (func_84305CAC(D_84390204, 0x32) != 0) {
                func_8431FF5C(arg0);
                D_84390230--;
                func_84322E70(arg0);
                if ((D_84390230 < 0) || (D_843C4DA4 != 0)) {
                    D_84390230 = D_8439022C;
                    D_84390240.unk_00->unk_3C++;
                } else {
                    func_84305760(D_84390010[D_84390240.unk_00->unk_2C], 0x13);
                    func_80048014();
                    func_8432E9D8(1);
                    D_84390240.unk_00->unk_3C = 0;
                }
            }
            break;

        case 1:
            func_8431C71C(arg0, D_84390204);
            func_8431AE5C();
            func_8431FF18();
            D_84390240.unk_00->unk_48 = 0;
            func_80048014();
            func_843234A0(arg0);
            break;
    }
}

void func_84323740(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_3C) {
        case 0:
            if (func_8431ADAC(0xF) != 0) {
                func_8432C7A0(7, D_84390204);
                func_8431AE5C();
                func_8431FF28();
                func_8431F420(D_84390204, arg0, 3);
            }
            break;

        case 1:
            func_8431C71C(arg0, D_84390204);
            if (func_84305CAC(D_84390204, 0x1E) != 0) {
                func_8431AE5C();
                func_8431FF18();
                func_843234A0(arg0);
            }
            break;
    }
}

void func_84323808(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad;
    unk_D_84390010_654_038* sp18 = &D_84390204->unk_654.unk_38;

    func_84307F00(D_84390204);

    switch (D_84390240.unk_00->unk_3C) {
        case 0:
            func_8431AE5C();
            func_8431FF28();
            func_8000E88C(&D_843901B0.unk_00, D_84390204->unk_4B0 * -175.0f, 25.0f, 0.0f);
            func_8431D7D8(&D_84384958, arg0, D_84390204);
            if ((D_84390204->unk_000.unk_01A != 0x33) && (D_84390204->unk_000.unk_01A != 0x32)) {
                func_84301B84(D_84390204, sp18->unk_5A);
            }
            break;

        case 1:
            if (func_8431D118(arg0, D_84390204, 1, 0) != 0) {
                func_8431AE5C();
                func_8431FF18();
                func_843234A0(arg0);
            }
            break;
    }
}

void func_84323928(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_3C) {
        case 0:
            func_8431AE5C();
            func_8431FF28();
            func_843081F0(D_84390204, &D_843901B0.unk_00);
            func_8431D7D8(&D_84384924, arg0, D_84390204);
            break;

        case 1:
            func_8431D318(arg0, D_84390204);
            if (func_84305CAC(D_84390204, 0x1E) != 0) {
                func_8431AE5C();
                func_8431FF18();
                func_843234A0(arg0);
            }
            break;
    }
}

void func_843239EC(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654* temp_a2 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;
    u32 var_v1 = 0;

    if (D_84390240.unk_00->unk_48 == 0x18) {
        var_v1 = 0xA;
    } else if (D_84390240.unk_00->unk_48 == 0x14) {
        var_v1 = 0xB;
    } else if (temp_a2->unk_34 & 0x4000) {
        var_v1 = 0xC;
    } else if (temp_a2->unk_34 & 0x10) {
        var_v1 = 0xC;
    } else if (temp_a2->unk_34 & 0x400) {
        var_v1 = 0xD;
    }

    switch (var_v1) {
        case 0:
            func_84323538(arg0);
            break;

        case 10:
            func_843235F4(arg0);
            break;

        case 11:
            func_84323740(arg0);
            break;

        case 12:
            func_84323808(arg0);
            break;

        case 13:
            func_84323928(arg0);
            break;

        default:
            func_84323538(arg0);
            break;
    }
}

void func_84323AFC(unk_D_84390010* arg0) {
    if (arg0->unk_654.unk_38.unk_5A == 0x45) {
        func_8430AE90(arg0);
    }
}

s32 func_84323B2C(unk_D_84390010* arg0) {
    if (arg0->unk_654.unk_38.unk_5A == 0x53) {
        return 1;
    }
    return 0;
}

void func_84323B50(unk_D_86002F34_00C* arg0, s32* arg1, s32* arg2) {
    if ((*arg1 == 1) && (*arg2 == 1)) {
        func_843184FC();
        func_843087F8(D_84390204);
        D_84390240.unk_00->unk_1A = 0;
        func_8431AE5C();
        func_8431AE6C();
        func_8431FF18();
        func_8431F680();
        func_84320CEC(arg0);
    }
}

void func_84323BCC(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_3C) {
        case 0:
            if (func_8431F7B0(D_84390200) == 0) {
                func_8431F500(D_84390200, arg0, 0);
                func_8431AE5C();
                func_8431FF28();
                func_84305760(D_84390204, 0xE);
                func_843065C4(D_84390200);
                func_84370ADC(D_84390200);
                func_843184E4(1);
            }
            break;

        case 1:
            func_8431C8E0(arg0, D_84390200);
            if ((func_84303D50(D_84390200) != 0) || (func_8431ADAC(0x5A) != 0)) {
                D_84390220 = func_8431FCCC(D_84390200);
                D_84390224 = func_8431FCCC(D_84390204);
                func_84323B50(arg0, &D_84390220, &D_84390224);
            }
            break;
    }
}

void func_84323CE4(unk_D_86002F34_00C* arg0) {
    s32 sp1C;

    switch (D_84390240.unk_00->unk_3C) {
        case 0:
            if (func_8431F7B0(D_84390200) == 0) {
                func_84370ADC(D_84390200);
                func_8431F500(D_84390200, arg0, 0);
                func_8431AE5C();
                func_8431FF28();
                func_84305760(D_84390204, 0xB);
                func_843065C4(D_84390200);
                func_843184E4(1);
            }
            break;

        case 1:
            func_8431C8E0(arg0, D_84390200);
            D_84390220 = func_8431FCCC(D_84390200);
            D_84390224 = func_8431FCCC(D_84390204);
            sp1C = func_84305458(D_84390204);
            if ((sp1C == 2) && ((func_84303D50(D_84390200) != 0) || (func_8431ADAC(0x64) != 0))) {
                func_84323B50(arg0, &D_84390220, &D_84390224);
            } else if (sp1C == 1) {
                func_84323B50(arg0, &D_84390220, &D_84390224);
            }
            break;
    }
}

void func_84323E44(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654_038* sp34 = &D_84390204->unk_654.unk_38;
    UNUSED s32 pad;
    UNUSED s16 pad2;
    s16 sp2C;

    switch (D_84390240.unk_00->unk_3C) {
        case 0:
            if (func_8431F7B0(D_84390200) == 0) {
                func_84370ADC(D_84390200);
                func_8431F500(D_84390200, arg0, 0);
                func_8431AE5C();
                func_8431FF28();
                func_843065C4(D_84390200);
                func_843184E4(1);
                sp2C = func_84307FAC(D_84390200);
                func_8432C604(sp34->unk_5A, D_84390204, D_84390200, sp2C, func_84307FE0(D_84390200));
                func_84308654(D_84390200, 0x10, 0);
            }
            break;

        case 1:
            func_8431C8E0(arg0, D_84390200);
            D_84390220 = func_8431FCCC(D_84390200);
            D_84390224 = func_8431FCCC(D_84390204);
            if ((func_84303D50(D_84390200) != 0) || (func_8431ADAC(0x5A) != 0)) {
                func_84323B50(arg0, &D_84390220, &D_84390224);
            }
            break;
    }
}

void func_84323FA0(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654_038* sp24 = &D_84390200->unk_654.unk_38;
    UNUSED s32 pad;
    s32 sp1C;
    s32 temp_v0;
    s32 var_a0;

    switch (D_84390240.unk_00->unk_3C) {
        case 0:
            if (func_8431F7B0(D_84390200) == 0) {
                func_84323AFC(D_84390204);
                func_843184E4(1);
                func_8431AE5C();
                func_8431FF28();
                func_8431B078(D_84390200);
                if (D_84390240.unk_00->unk_1A == 3) {
                    func_84305760(D_84390204, 0xB);
                } else {
                    func_84305760(D_84390204, 4);
                }
                func_8431F500(D_84390200, arg0, 0);
                func_84370ADC(D_84390200);
                func_843065C4(D_84390200);
                func_8432B1BC(D_84390200);
            }
            break;

        case 1:
            if (func_8431ADAC(5) != 0) {
                func_843223FC(D_84390204);
                D_84390240.unk_00->unk_3C++;
            }
            break;

        case 2:
            func_8431F680();
            D_84390220 = func_8431FCCC(D_84390200);
            D_84390224 = func_8431FCCC(D_84390204);
            if (sp24->unk_0C != 0) {
                if (func_84303D50(D_84390200) != 0) {
                    D_84390240.unk_00->unk_3C = 4;
                } else if (func_8430602C(D_84390200, 2) != 0) {
                    D_84390240.unk_00->unk_3C = 5;
                } else if (func_8431C8E0(arg0, D_84390200) != 0) {
                    D_84390240.unk_00->unk_3C = 3;
                }
            } else if (func_8431C8E0(arg0, D_84390200) != 0) {
                D_84390240.unk_00->unk_3C = 4;
            }
            break;

        case 3:
            D_84390220 = func_8431FCCC(D_84390200);
            D_84390224 = func_8431FCCC(D_84390204);
            func_8431C8E0(arg0, D_84390200);
            if (func_84303D50(D_84390200) != 0) {
                D_84390240.unk_00->unk_3C++;
            } else if (func_8430602C(D_84390200, 0xF) != 0) {
                D_84390240.unk_00->unk_3C++;
            }
            break;

        case 4:
            D_84390220 = func_8431FCCC(D_84390200);
            D_84390224 = func_8431FCCC(D_84390204);
            temp_v0 = func_8431C8E0(arg0, D_84390200);
            if ((D_84390220 == 1) && (D_84390224 == 1) && (temp_v0 != 0) && (func_8431ADAC(0xF) != 0)) {
                D_84390240.unk_00->unk_3C = 6;
            }
            break;

        case 5:
            D_84390220 = func_8431FCCC(D_84390200);
            D_84390224 = func_8431FCCC(D_84390204);
            sp1C = func_8431C8E0(arg0, D_84390200);
            if ((func_84323B2C(D_84390204) != 0) && ((D_843C4DEC.unk_00 < 0xA) || (D_843C4DA4 != 0)) &&
                !(sp24->unk_15 & 0x20)) {
                var_a0 = 0x5A;
            } else {
                var_a0 = 0xF;
            }

            if ((D_84390220 == 1) && (D_84390224 == 1) && (sp1C != 0) && (func_8431ADAC(var_a0) != 0)) {
                D_84390240.unk_00->unk_3C++;
            }
            break;

        case 6:
            if (func_8431F888(D_84390200) == 0) {
                D_84390220 = func_8431FCCC(D_84390200);
                D_84390224 = func_8431FCCC(D_84390204);
                func_8431C8E0(arg0, D_84390200);
                func_84323B50(arg0, &D_84390220, &D_84390224);
            }
            break;
    }
}

void func_84324404(void) {
}

void func_8432440C(void) {
}

void func_84324414(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654_038* sp24 = &D_84390204->unk_654.unk_38;
    unk_D_8438E7B0_A50* temp_v1 = &D_84384570[func_84307F00(D_84390200)]->unk_000[sp24->unk_5A - 1];
    volatile s32 sp1C;
    s32 temp_v0_2;

    if (D_84390200->unk_000.unk_01A == 0x98) {
        sp1C = 0xF;
    } else if (temp_v1->unk_0A == 0xFF) {
        sp1C = D_84390204->unk_000.unk_040.unk_04->unk_0A - temp_v1->unk_06;
    } else {
        sp1C = temp_v1->unk_0A - temp_v1->unk_06;
    }

    switch (D_84390240.unk_00->unk_3C) {
        case 0:
            if (func_8431F7B0(D_84390200) == 0) {
                func_8431F680();
                func_8431B078(D_84390200);
                func_84305760(D_84390204, 4);
                D_84390230--;
                func_8431F500(D_84390200, arg0, D_84390230 + 1);
                if (D_84390230 < 0) {
                    func_8431F500(D_84390200, arg0, D_84390230 + 1);
                    func_8431C8E0(arg0, D_84390200);
                    func_84370ADC(D_84390200);
                    func_8431AE5C();
                    D_84390240.unk_00->unk_3C = 2;
                    func_843065C4(D_84390200);
                    func_843184E4(1);
                } else {
                    D_84390240.unk_00->unk_3C++;
                }
            }
            break;

        case 1:
            func_8431C71C(arg0, D_84390200);
            if (func_8431ADAC(sp1C) != 0) {
                func_80048014();
                func_8432E9D8(1);
                D_84390240.unk_00->unk_3C = 0;
            }
            break;

        case 2:
            D_84390220 = func_8431FCCC(D_84390200);
            D_84390224 = func_8431FCCC(D_84390204);

            if (sp24->unk_0C != 0) {
                if (func_84303D50(D_84390200) != 0) {
                    D_84390240.unk_00->unk_3C = 5;
                }

                if (func_8430602C(D_84390200, 0xF) != 0) {
                    D_84390240.unk_00->unk_3C = 5;
                }

                if (func_8431C8E0(arg0, D_84390200) != 0) {
                    D_84390240.unk_00->unk_3C = 4;
                }
            } else if (func_8431C8E0(arg0, D_84390200) != 0) {
                func_8431AE5C();
                D_84390240.unk_00->unk_3C = 5;
            }
            break;

        case 3:
            D_84390220 = func_8431FCCC(D_84390200);
            D_84390224 = func_8431FCCC(D_84390204);

            if (func_84303D50(D_84390200) != 0) {
                D_84390240.unk_00->unk_3C = 5;
            }

            if (func_8431C8E0(arg0, D_84390200) != 0) {
                D_84390240.unk_00->unk_3C = 9;
            }
            break;

        case 4:
            D_84390220 = func_8431FCCC(D_84390200);
            D_84390224 = func_8431FCCC(D_84390204);

            if (func_84303D50(D_84390200) != 0) {
                D_84390240.unk_00->unk_3C = 5;
            }

            func_8431C8E0(arg0, D_84390200);

            if (func_8430602C(D_84390200, 0xF) != 0) {
                D_84390240.unk_00->unk_3C++;
            }
            break;

        case 5:
            D_84390220 = func_8431FCCC(D_84390200);
            D_84390224 = func_8431FCCC(D_84390204);
            temp_v0_2 = func_8431C8E0(arg0, D_84390200);
            if ((D_84390220 == 1) && (D_84390224 == 1) && (temp_v0_2 != 0) && (func_8431ADAC(0xF) != 0)) {
                D_84390240.unk_00->unk_3C++;
            }
            break;

        case 6:
            if (func_8431F888(D_84390200) == 0) {
                D_84390220 = func_8431FCCC(D_84390200);
                D_84390224 = func_8431FCCC(D_84390204);
                func_8431C8E0(arg0, D_84390200);
                func_84323B50(arg0, &D_84390220, &D_84390224);
            }
            break;
    }
}

void func_843248B8(unk_D_86002F34_00C* arg0) {
    func_8431FF70(arg0);
    func_84370ADC(D_84390010[!D_84390240.unk_00->unk_2C]);
    if (D_84390240.unk_00->unk_48 == 0x16) {
        func_84323BCC(arg0);
    } else if (D_84390240.unk_00->unk_48 == 0x20) {
        func_84323E44(arg0);
    } else if (D_84390240.unk_00->unk_48 == 0x1A) {
        func_84323CE4(arg0);
    } else if (D_84390240.unk_00->unk_1A == 1) {
        func_84324414(arg0);
    } else {
        func_84323FA0(arg0);
    }
}

void func_84324988(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_84322B04(arg0);
            break;

        case 1:
            func_843239EC(arg0);
            break;

        case 2:
            func_843248B8(arg0);
            break;
    }
}

void func_843249F8(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_84322B04(arg0);
            break;

        case 1:
            func_843239EC(arg0);
            break;

        case 2:
            func_843248B8(arg0);
            break;
    }
}

s32 func_84324A68(void) {
    func_843233E0(D_84390240.unk_00->unk_DC, 0);

    if (func_8431ADAC(func_843200B4(D_84390204)) == 0) {
        return 0;
    }

    if ((D_84390240.unk_00->unk_48 != 0x1E) && (D_84390240.unk_00->unk_48 != 0x27)) {
        func_843184E4(3);
    }

    if (D_84390240.unk_00->unk_48 == 0x1B) {
        func_800414B8(func_84308D98(D_84390204));
    }

    switch (D_84390240.unk_00->unk_48) {
        case 7:
            return func_84320658(7);

        case 21:
            return func_84320658(7);

        case 39:
            return func_84320658(7);

        case 27:
            return func_84320658(0x1B);

        case 30:
            return func_84320658(0x1E);

        case 28:
            return func_84320658(0x1C);

        case 15:
            return func_84320658(0xF);

        case 25:
            return func_84320658(0x19);

        case 29:
            return func_84320658(0x1D);

        case 38:
            return func_84320658(0x26);

        case 12:
            return func_84320658(0xC);

        case 13:
            return func_84320658(0xD);

        case 14:
            return func_84320658(0xE);

        case 17:
            return func_84320658(0x11);

        case 31:
            return func_84320658(0x1F);
    }

    return 0;
}

void func_84324C28(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654_038* sp1C = &D_84390204->unk_654.unk_38;
    unk_D_8438E7B0_A50* sp18 = &D_84384570[func_84307F00(D_84390204)]->unk_000[sp1C->unk_5A - 1];

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_8431FF5C(arg0);
            func_843230D8(arg0, 0);
            func_8431AE5C();
            func_8431AE6C();
            if (sp18->unk_04 < 0x15) {
                func_84370ADC(D_84390204);
            }
            D_84390240.unk_00->unk_20++;
            break;

        case 1:
            func_843233E0(arg0, 1);
            if (D_84390204->unk_4C4 == (sp18->unk_04 + 1)) {
                func_84370ADC(D_84390204);
            }

            if (D_84390204->unk_4C4 >= (sp18->unk_04 + 0xA)) {
                D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
                D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            }

            if ((D_84390204->unk_4C4 == (sp18->unk_04 + 0x12)) && (sp1C->unk_5A == 0x64)) {
                func_843184E4(0xF);
            }

            if (func_84305CAC(D_84390204, 0x3C) != 0) {
                func_8431AE5C();
                D_84390240.unk_00->unk_20++;
            }
            break;

        case 2:
            if (D_84390204->unk_4C4 == (sp18->unk_04 + 1)) {
                func_84370ADC(D_84390204);
            }
            func_843233E0(arg0, 1);
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if ((D_84390220 == 1) && (D_84390224 == 1) && (func_8431ADAC(0xF) != 0)) {
                if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                    D_84390240.unk_00->unk_34 = 3;
                }
                func_8431AE5C();
                func_8431F680();
                func_84320E54(arg0);
            }
            break;
    }
}

void func_84324F1C(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_8431FF5C(arg0);
            func_8431DF98(arg0, D_84390204);
            func_8431B858(D_84390204, arg0);
            func_84370ADC(D_84390204);
            func_8431AE5C();
            func_8431AE6C();
            D_84390240.unk_00->unk_20++;
            break;

        case 1:
            if (func_84305CAC(D_84390204, 0x3C) != 0) {
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                D_84390240.unk_00->unk_34 = 3;
            }
            func_8431AE5C();
            func_8431F680();
            func_84320E54(arg0);
            break;
    }
}

void func_84325080(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_8431FF5C(arg0);
            func_84370ADC(D_84390204);
            func_843230D8(arg0, 0);
            func_8431AE5C();
            D_84390240.unk_00->unk_20++;
            break;

        case 1:
            func_843233E0(arg0, 1);
            if (func_8431ADAC(0x28) != 0) {
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            func_843233E0(arg0, 1);
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                D_84390240.unk_00->unk_34 = 3;
            }
            func_8431AE5C();
            func_8431F680();
            func_84320E54(arg0);
            break;
    }
}

void func_843251D4(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654_038* sp1C = &D_84390200->unk_654.unk_38;

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_84306200(D_84390204, 0x1800);
            func_8431FF5C(arg0);
            func_8431AE5C();
            func_843230D8(arg0, 0);
            func_84370ADC(D_84390204);
            func_8431AE5C();
            D_84390240.unk_00->unk_20++;
            break;

        case 1:
            func_843233E0(arg0, 1);
            if (func_84305CAC(D_84390204, 0x3C) != 0) {
                func_8431AE5C();
                D_84390240.unk_00->unk_20++;
            }
            break;

        case 2:
            if (func_8431F7B0(D_84390200) == 0) {
                func_8432E9D8(1);
                func_80048014();
                func_8431F500(D_84390200, arg0, func_8430C414(2));
                func_84305760(D_84390204, 4);
                func_8431AE5C();
                D_84390240.unk_00->unk_20++;
            }
            break;

        case 3:
            if (func_8431F888(D_84390200) == 0) {
                func_8431C71C(arg0, D_84390200);
                if (D_84390240.unk_00->unk_14 == 0) {
                    func_843184E4(1);
                }
                D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
                D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
                if (func_8431ADAC(0x32) != 0) {
                    D_84390240.unk_00->unk_20 += 1;
                }
                if (func_84303D50(D_84390200) != 0) {
                    func_8431AE5C();
                    D_84390240.unk_00->unk_20++;
                }
            }
            break;

        case 4:
            func_8431C71C(arg0, D_84390200);
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if ((D_84390224 == 1) && (D_84390220 == 1)) {
                if (sp1C->unk_0C != 0) {
                    func_8432E9D8(1);
                    func_80048014();
                    func_8431F420(D_84390204, arg0, 3);
                    D_84390240.unk_00->unk_20++;
                } else {
                    if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                        D_84390240.unk_00->unk_34 = 3;
                    }
                    func_8431AE5C();
                    func_8431F680();
                    func_8431FF3C(arg0, 5);
                }
            }
            break;

        case 5:
            func_8431F420(D_84390204, arg0, 3);
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                D_84390240.unk_00->unk_34 = 3;
            }
            func_8431AE5C();
            func_8431F680();
            func_84320C38(arg0);
            break;
    }
}

void func_843255DC(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_8431FF5C(arg0);
            func_84370ADC(D_84390204);
            func_8431F420(D_84390204, arg0, 3);
            func_8431AE5C();
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 1:
            if (func_8431ADAC(0x28) != 0) {
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                D_84390240.unk_00->unk_34 = 3;
            }
            func_8431AE5C();
            func_8431F680();
            func_84320E54(arg0);
            break;
    }
}

void func_84325724(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad[3];
    unk_D_84390010_654_038* sp30 = &D_84390204->unk_654.unk_38;
    unk_D_84390010_654_038* sp2C = &D_84390200->unk_654.unk_38;
    unk_D_84390010_654* sp28 = &D_84390204->unk_654;
    unk_D_84390010_654* sp24 = &D_84390200->unk_654;

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_843230D8(arg0, 0);
            func_8431CCFC(arg0, D_84390204);
            if (sp30->unk_4D & 0x10) {
                if (sp2C->unk_4E & 8) {
                    sp28->unk_BC = D_84390204->unk_720->unk_02 = sp24->unk_BE;
                } else if (D_84390200->unk_720->unk_02 == 0x98) {
                    sp28->unk_BC = D_84390204->unk_720->unk_02 = sp2C->unk_0B;
                } else {
                    sp28->unk_BC = D_84390204->unk_720->unk_02 = D_84390200->unk_720->unk_02;
                }
            } else if (sp2C->unk_4E & 8) {
                D_84390204->unk_720->unk_02 = sp24->unk_BE;
            } else if (D_84390200->unk_720->unk_02 == 0x98) {
                D_84390204->unk_720->unk_02 = sp2C->unk_0B;
            } else {
                D_84390204->unk_720->unk_02 = D_84390200->unk_720->unk_02;
            }
            D_84390204->unk_720->unk_04 = &D_84390204->unk_724->unk_01C[D_84390204->unk_654.unk_08];
            D_84390204->unk_720->unk_00 |= 0x80;
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 1:
            func_8431CCFC(arg0, D_84390204);
            if (D_84390204->unk_720->unk_00 & 0x10) {
                D_84390204->unk_720->unk_00 &= ~0x90;
                func_84309168(D_84390204);
                func_84307748(D_84390204);
                func_84301B84(D_84390204, sp30->unk_5A);
                func_8432B5B8(D_84390204, sp30, 0);
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            func_8431CCFC(arg0, D_84390204);
            func_8432B5B8(D_84390204, sp30, 0);
            func_84305760(D_84390204, 0x12);
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 3:
            func_8431CCFC(arg0, D_84390204);
            D_84390204->unk_728.unk_168->unk_00.unk_01 |= 1;
            D_84390204->unk_728.unk_000.unk_000.unk_01 |= 1;
            func_843074A0(D_84390204);
            if (func_84305B6C(D_84390204, 0x32) != 0) {
                func_8431F680();
                func_84320CEC(arg0);
            }
            break;
    }
}

void func_84325A10(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654_038* sp1C = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;
    unk_D_84390010_654* sp18 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_8431FF5C(arg0);
            func_84301B84(D_84390204, sp1C->unk_5A);
            func_843230D8(arg0, 0);
            if (!(sp18->unk_34 & 0x800)) {
                func_84302128(D_84390204);
            }
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 1:
            func_843233E0(arg0, 0);
            if (!(sp18->unk_34 & 0x800)) {
                func_84304800(D_84390204);
            }
            if (func_84301FF0(D_84390204) == 0) {
                func_8432B5B8(D_84390204, sp1C, 0);
                func_8431F420(D_84390204, arg0, 3);
                func_8431AE5C();
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            func_8431F420(D_84390204, arg0, 3);
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if (func_8431ADAC(0x2E) != 0) {
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 3:
            if (!(sp18->unk_34 & 0x800)) {
                func_843061EC(D_84390204, 0x800);
            }
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                D_84390240.unk_00->unk_34 = 3;
            }
            func_8431F680();
            func_84320E54(arg0);
            break;
    }
}

s32 func_84325CAC(unk_D_84390010* arg0) {
    func_8432B0E4(arg0);
    func_8432B38C(arg0);
    func_84370ADC(arg0);
}

void func_84325CDC(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_8431FF5C(arg0);
            func_84370ADC(D_84390204);
            func_843230D8(arg0, 0);
            func_8431AE5C();
            func_8431AE6C();
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 1:
            func_843233E0(arg0, 1);
            if (func_84305CAC(D_84390204, 0x3C) != 0) {
                func_84325CAC(D_84390200);
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            func_843233E0(arg0, 1);
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                D_84390240.unk_00->unk_34 = 3;
            }
            func_8000E88C(&D_84390204->unk_000.unk_030, 1.0f, 1.0f, 1.0f);
            func_8000E88C(&D_84390200->unk_000.unk_030, 1.0f, 1.0f, 1.0f);
            func_8431AE5C();
            func_8431F680();
            func_84320E54(arg0);
            break;
    }
}

void func_84325E94(unk_D_86002F34_00C* arg0) {
    unk_D_8438E7B0_A50* sp4C = &D_84384570[D_84390240.unk_00->unk_2C]->unk_B00;
    UNUSED s32 pad;
    Vec3f sp3C;

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_8431AE5C();
            func_8431FF18();
            func_8431F420(D_84390204, arg0, 3);
            func_8431CB54(arg0, D_84390204);
            func_843061EC(D_84390204, 0x200);
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 1:
            if (D_84390204->unk_000.unk_024.y >= 100.0f) {
                func_843081F0(D_84390204, &sp3C);
                sp3C.y += func_84308548(D_84390204);
                D_84390208 = func_8431AD20(D_84390204, 3.0f, 500.0f);
                func_8431BB80(arg0, sp3C, 0x11C6, func_84308190(D_84390204) - (D_84390204->unk_4B0 * 0x754E),
                              D_84390208, func_84308548(D_84390204));
                func_8000E88C(&sp3C, 0.0f, 200.0f, 0.0f);
                func_8430C1E4(&arg0->unk_60.at, &sp3C);
                func_8432E9D8(2);
                func_8001BD04(&D_84390204->unk_000, sp4C->unk_00);
                arg0->unk_24.fovy = 60.0f;
                D_84390240.unk_00->unk_20 += 1;
            } else {
                func_8431CB54(arg0, D_84390204);
            }
            break;

        case 2:
            func_8430C718(&arg0->unk_24.fovy, 60.0f, 0.2f);
            if (D_84390204->unk_000.unk_024.y >= 200.0f) {
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 3:
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if ((D_84390220 == 1) && (D_84390224 == 1) && (func_8431ADF0(0x1E) != 0)) {
                func_843061EC(D_84390010[D_84390240.unk_00->unk_2C], 4);
                func_8432F9B4();
                func_8431AE5C();
                func_8431F680();
                func_84320CEC(arg0);
            }
            break;
    }
}

void func_843261CC(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad;
    f32 sp28;
    UNUSED s16 pad2;
    u16 sp24 = D_84385B8C;

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_8431FF5C(arg0);
            func_8431AE5C();
            func_8431FF18();
            func_8431F420(D_84390204, arg0, 3);
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 1:
            if (D_84390204->unk_4B8 == 2) {
                func_8431CC38(arg0, D_84390204);
                D_84390204->unk_000.unk_000.unk_02 &= 0xFFBF;
            }

            if ((D_84390204->unk_000.unk_01A == 0x32) || (D_84390204->unk_000.unk_01A == 0x33)) {
                if (func_84305B6C(D_84390204, 0x1E) != 0) {
                    func_843184FC();
                    func_843061EC(D_84390204, 0x4000);
                    D_84390204->unk_000.unk_000.unk_02 &= 0xFFDF;
                    D_84390240.unk_00->unk_20 += 1;
                }
            } else if (func_84301FB0(D_84390204) == 0) {
                if (func_84307AE0(D_84390204->unk_000.unk_01A, (u8*)&sp24, 2) != 0) {
                    sp28 = 10.0f;
                } else {
                    sp28 = 3.5f;
                }

                if (D_84390204->unk_000.unk_024.y <= (-func_84308548(D_84390204) * sp28)) {
                    func_843061EC(D_84390204, 0x4000);
                    D_84390204->unk_000.unk_000.unk_02 &= 0xFFDF;
                    D_84390240.unk_00->unk_20 += 1;
                }
            }
            break;

        case 2:
            if ((D_84390204->unk_000.unk_01A != 0x32) && (D_84390204->unk_000.unk_01A != 0x33)) {
                D_84390204->unk_000.unk_000.unk_02 |= 0x40;
            }
            func_8431CC38(arg0, D_84390204);
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            func_8431F680();
            func_84320E54(arg0);
            break;
    }
}

void func_84326460(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_843230D8(arg0, 1);
            func_8431FF5C(arg0);
            func_8431AE5C();
            func_8431AE6C();
            func_84370ADC(D_84390204);
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 1:
            func_843233E0(arg0, 1);
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if (func_84305E54(D_84390204, 0x1E) != 0) {
                func_8431F680();
                func_84320E54(arg0);
            }
            break;
    }
}

void func_84326570(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654* sp1C = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_8431AE5C();
            func_8431FF5C(arg0);
            func_84370ADC(D_84390204);
            if (!(sp1C->unk_34 & 2)) {
                func_843230D8(arg0, 0);
            }
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 1:
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if (func_8431ADAC(0x3C) != 0) {
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            func_8431F680();
            func_84320E54(arg0);
            break;
    }
}

void func_843266D4(unk_D_86002F34_00C* arg0) {
    func_8431FF70(arg0);

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            if (func_8431F7B0(D_84390204) == 0) {
                func_843184E4(2);
                func_843223FC(D_84390204);
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 1:
            func_8431F680();
            func_84301B00();
            func_84305760(D_84390204, 0xF);
            func_8431F500(D_84390204, arg0, 3);
            func_8431B078(D_84390204);
            func_8432C7A0(8, D_84390204);
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 2:
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            func_8431C8E0(arg0, D_84390204);
            if (func_84303DEC(D_84390204) != 0) {
                D_84390240.unk_00->unk_20 += 1;
            } else if (func_84305B6C(D_84390204, 0x32) != 0) {
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 3:
            func_8431C8E0(arg0, D_84390204);
            if (func_8431F888(D_84390204) == 0) {
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 4:
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            func_8431C8E0(arg0, D_84390204);
            func_8431F680();
            func_84320CEC(arg0);
            break;
    }
}

void func_8432691C(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_8431FF5C(arg0);
            func_84370ADC(D_84390204);
            D_84390204->unk_4C8 = 1;
            func_8431AE5C();
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 1:
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if (func_8431ADAC(0x3C) != 0) {
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            func_8431F680();
            func_84320E54(arg0);
            break;
    }
}

void func_84326A70(void) {
}

void func_84326A78(UNUSED unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_8432056C();

        case 1:
            break;
    }
}

void func_84326AC4(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad;
    s32 idx = D_84390240.unk_00->unk_2C;
    unk_D_8438E7B0_A50* sp1C = &D_84384570[idx]->unk_A80;

    func_8431FF70(arg0);

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_8431F680();
            func_843184E4(2);
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 1:
            if (func_8431F7B0(D_84390204) == 0) {
                func_843087F8(D_84390204);
                func_8432E9D8(1);
                func_84305760(D_84390204, 0xF);
                func_8431F500(D_84390204, arg0, 3);
                func_8431B078(D_84390204);
                func_8431F680();
                func_8001BD04(&D_84390204->unk_000, sp1C->unk_00);
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            if (func_8431ADAC(0x28) != 0) {
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 3:
            if (func_8431F888(D_84390204) == 0) {
                func_843184FC();
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 4:
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if ((D_84390220 != 0) && (D_84390224 != 0)) {
                func_8431F680();
                func_84320CEC(arg0);
            }
            break;
    }
}

void func_84326CB4(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654* sp1C = &D_84390200->unk_654;

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            if (func_8431F7B0(D_84390200) == 0) {
                func_843184E4(2);
                func_84323AFC(D_84390204);
                func_8431FF70(arg0);
                func_8432E9D8(1);

                if (sp1C->unk_34 & 0x200) {
                    func_8431F500(D_84390200, arg0, D_84390228 = 2);
                } else {
                    if (D_84390200->unk_000.unk_01A == 0xF) {
                        func_8431F500(D_84390200, arg0, 0);
                    }
                    func_8431F500(D_84390200, arg0, D_84390228 = func_8430C414(2));
                }

                func_84305760(D_84390204, 0xC);
                func_8431AE5C();
                func_8432E8BC();
                D_84390240.unk_00->unk_20 += 1;
                func_8430663C(D_84390200);
            }
            break;

        case 1:
            if ((D_84390200->unk_000.unk_01A == 0xF) && !(sp1C->unk_34 & 0x200)) {
                func_8431C8E0(arg0, D_84390200);
            }

            if (func_8431ADAC(0x32) != 0) {
                func_843184FC();
                func_843223FC(D_84390204);
                func_843066E0(D_84390204);
                func_8431FF18();
                func_8431AE5C();
                func_8431F680();
                func_84320CEC(arg0);
            }
            break;
    }
}

void func_84326E84(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654_038* sp24 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;
    unk_D_84390010_654_038* sp20 = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654.unk_38;

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_843058A8(D_84390204);
            func_8431F194(arg0, D_84390010[D_84390240.unk_00->unk_2C]);
            func_8431F680();
            func_843066E0(D_84390204);
            func_8432E9D8(2);
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 1:
            if (func_8431F690(D_84390010[D_84390240.unk_00->unk_2C]) == 0) {
                func_843087F8(D_84390204);
                func_80048014();
                func_8432E9D8(1);
                func_8431F194(arg0, D_84390010[D_84390240.unk_00->unk_2C]);
                func_84305760(D_84390010[D_84390240.unk_00->unk_2C], 0xD);

                if (sp24->unk_15 & 0x18) {
                    func_843184E4(4);
                    sp24->unk_0C = sp24->unk_0E;
                    sp20->unk_0C = sp20->unk_0E;
                    if (sp24->unk_15 & 0x10) {
                        func_8432C7A0(6, D_84390204);
                    } else {
                        func_8432C7A0(5, D_84390204);
                    }
                    D_84390240.unk_00->unk_20 += 1;
                } else {
                    func_843184E4(5);
                    func_800367A0(0x22, 0, 0);
                    sp24->unk_0C = sp24->unk_10;
                    sp20->unk_0C = sp20->unk_10;
                    func_8432C7A0(0xA, D_84390204);
                    func_8431AE5C();
                    D_84390240.unk_00->unk_20 = 3;
                }
            }
            break;

        case 2:
            func_8431F194(arg0, D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);

            if ((D_84390220 == 1) && (D_84390224 == 1) && (func_8431ADF0(0x32) != 0)) {
                func_8431AE5C();
                if (func_84308164(D_84390010[D_84390240.unk_00->unk_2C]) == 0) {
                    func_8431FF18();
                    func_8431FF3C(arg0, 5);
                    D_84390240.unk_00->unk_2C = !D_84390240.unk_00->unk_2C;
                } else if (sp24->unk_4D & 0x80) {
                    func_8431AE5C();
                    func_800367A0(0x22, 0, 0);
                    sp24->unk_0C = sp24->unk_10;
                    sp20->unk_0C = sp20->unk_10;
                    func_8432C7A0(0xA, D_84390204);
                    D_84390240.unk_00->unk_20 += 1;
                } else {
                    D_84390240.unk_00->unk_20 = 4;
                }
            }
            break;

        case 3:
            func_8431F194(arg0, D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);

            if ((func_8431ADF0(0x32) != 0) && (D_84390220 == 1) && (D_84390224 == 1)) {
                D_84390240.unk_00->unk_20 += 1;
                func_8431AE5C();
            }
            break;

        case 4:
            if (func_8431F888(D_84390200) == 0) {
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 5:
            func_8431F680();
            func_8431F194(arg0, D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            func_84320C38(arg0);
            break;
    }
}

void func_8432734C(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654_038* sp1C = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;
    unk_D_84390010_654_038* sp18 = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654.unk_38;

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_843066E0(D_84390204);
            func_8432E9D8(2);
            func_8431E118(arg0, D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 1:
            if (func_8431F690(D_84390010[D_84390240.unk_00->unk_2C]) == 0) {
                func_843087F8(D_84390204);
                func_80048014();
                func_8432E9D8(1);
                func_8432C7A0(9, D_84390204);
                func_8431AE5C();
                func_8431E118(arg0, D_84390010[D_84390240.unk_00->unk_2C]);
                sp1C->unk_0C = sp1C->unk_12;
                sp18->unk_0C = sp18->unk_12;
                func_843184E4(6);
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            if (func_8431D048(arg0, D_84390010[D_84390240.unk_00->unk_2C]) != 0) {
                func_8431F500(D_84390204, arg0, 3);
                func_84303E58(D_84390204);
                func_8432BF88(D_84390204, 0x1F);
                func_8431B078(D_84390204);
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 3:
            if (func_8431F888(D_84390200) == 0) {
                func_8431C8E0(arg0, D_84390204);
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 4:
            func_8431F680();
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            func_8431C8E0(arg0, D_84390204);
            if ((D_84390220 == 1) && (D_84390224 == 1) && (func_8431ADF0(0x3C) != 0)) {
                func_84320CEC(arg0);
            }
            break;
    }
}

void func_843275F8(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_843066E0(D_84390204);
            if (func_8431F690(D_84390010[D_84390240.unk_00->unk_2C]) == 0) {
                func_843087F8(D_84390204);
                func_80048014();
                func_8432E9D8(1);
                func_8431AE5C();
                func_8432C6C4(3, D_84390200);
                func_800367A0(0x23, 0, 0);
                func_8431F194(arg0, D_84390200);
                func_843184E4(7);
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 1:
            if (func_8431ADAC(0x37) != 0) {
                D_84390240.unk_00->unk_20 += 1;
            }

        case 2:
            if (func_8431ADAC(0x3C) != 0) {
                func_84320CEC(arg0);
            }
            break;
    }
}

void func_84327720(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654_038* sp24 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;
    unk_D_84390010_654_038* sp20 = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654.unk_38;

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_843066E0(D_84390204);
            func_8432E9D8(2);
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 1:
            if (func_8431F690(D_84390010[D_84390240.unk_00->unk_2C]) == 0) {
                func_843087F8(D_84390204);
                func_80048014();
                func_8432E9D8(1);
                func_8431F194(arg0, D_84390010[D_84390240.unk_00->unk_2C]);
                func_84305760(D_84390010[D_84390240.unk_00->unk_2C], 0xD);

                if (sp24->unk_15 & 0x18) {
                    func_843184E4(4);
                    sp24->unk_0C = sp24->unk_0E;
                    sp20->unk_0C = sp20->unk_0E;
                    if (sp24->unk_15 & 0x10) {
                        func_8432C7A0(6, D_84390204);
                    } else {
                        func_8432C7A0(5, D_84390204);
                    }
                    D_84390240.unk_00->unk_20 += 1;
                } else {
                    func_843184E4(5);
                    sp24->unk_0C = sp24->unk_10;
                    sp20->unk_0C = sp20->unk_10;
                    func_8432C7A0(0xA, D_84390204);
                    D_84390240.unk_00->unk_20 = 3;
                }
            }
            break;

        case 2:
            func_8431F194(arg0, D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if ((D_84390220 == 1) && (D_84390224 == 1) && (func_8431ADF0(0x32) != 0)) {
                func_8431AE5C();
                if (func_84308164(D_84390010[D_84390240.unk_00->unk_2C]) == 0) {
                    func_8431FF18();
                    func_8431FF3C(arg0, 5);
                    D_84390240.unk_00->unk_2C = !D_84390240.unk_00->unk_2C;
                } else if (sp24->unk_4D & 0x80) {
                    func_800367A0(0x22, 0, 0);
                    sp24->unk_0C = sp24->unk_10;
                    sp20->unk_0C = sp20->unk_10;
                    func_8432C7A0(0xA, D_84390204);
                    D_84390240.unk_00->unk_20 += 1;
                } else {
                    D_84390240.unk_00->unk_20 = 4;
                }
            }
            break;

        case 3:
            func_8431F194(arg0, D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            if ((func_8431ADF0(0x32) != 0) && (D_84390220 == 1) && (D_84390224 == 1)) {
                D_84390240.unk_00->unk_20 += 1;
                func_8431AE5C();
            }
            break;

        case 4:
            if (func_8431F888(D_84390200) == 0) {
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 5:
            func_8431F680();
            func_8431F194(arg0, D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = func_8431FCCC(D_84390010[!D_84390240.unk_00->unk_2C]);
            func_84320C38(arg0);
            break;
    }
}

void func_84327B90(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654_038* sp1C = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;
    unk_D_84390010_654_038* sp18 = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654.unk_38;

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_843066E0(D_84390204);
            func_8432E9D8(2);
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 1:
            func_843087F8(D_84390204);
            func_80048014();
            func_8432E9D8(1);
            func_8431EF54(arg0, D_84390010[D_84390240.unk_00->unk_2C]);
            func_84305760(D_84390010[D_84390240.unk_00->unk_2C], 0xD);
            sp1C->unk_0C = sp1C->unk_0E;
            sp18->unk_0C = sp18->unk_0E;
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 2:
            func_8431EF54(arg0, D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390220 = func_8431FCCC(D_84390010[D_84390240.unk_00->unk_2C]);
            D_84390224 = 1;

            if ((D_84390220 == 1) && (D_84390224 == 1) && (func_8431ADF0(0x32) != 0)) {
                func_8431AE5C();
                if (func_84308164(D_84390010[D_84390240.unk_00->unk_2C]) == 0) {
                    func_8431FF18();
                    func_8431FF3C(arg0, 0x22);
                    D_84390240.unk_00->unk_2C = !D_84390240.unk_00->unk_2C;
                } else {
                    func_843208B0();
                }
            }
            break;
    }
}

void func_84327D98(unk_D_84390010* arg0) {
    func_8432B0E4(arg0);
    func_8432B448(arg0);
}

void func_84327DC0(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654* sp34 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;
    unk_D_84390010* temp_s0 = D_84390010[D_84390240.unk_00->unk_2C];
    unk_D_84390010_654_038* sp2C = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;

    if (D_84390240.unk_00->unk_2C) {}

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            if (D_84390240.unk_00->unk_34 == 1) {
                func_8431FF70(arg0);
                func_8431F420(temp_s0, arg0, 4);
                func_8003F4C0(func_84308D98(temp_s0));
                D_84390240.unk_00->unk_20 += 1;
            } else if (func_8431D118(arg0, temp_s0, 1, 1) != 0) {
                func_843184E4(0xA);
                func_8003F4C0(func_84308D98(temp_s0));
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 1:
            func_8431CFA4(arg0, temp_s0);
            func_84305760(temp_s0, 2);
            func_84327D98(temp_s0);
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 2:
            func_8431CFA4(arg0, temp_s0);
            if (func_8431ADAC(0x69) != 0) {
                func_8000E88C(&arg0->unk_60.at, temp_s0->unk_4B0 * -150.0f, 0.0, 0.0f);
                if (D_84390240.unk_00 && D_84390240.unk_00) {}
                func_8000E88C(&arg0->unk_60.eye, temp_s0->unk_4B0 * -50.0f, 5.0f, 0.0f);
                func_84308654(temp_s0, 2, 0);
                func_8432C68C(0xD, temp_s0, temp_s0, 0xFF, 0xFF);
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 3:
            if (temp_s0->unk_4EC.unk_024.y == 2.5f) {
                temp_s0->unk_4EC.unk_000.unk_02 |= 0x20;
            }

            if (func_800174E4(&temp_s0->unk_4EC) == 1) {
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 4:
            temp_s0->unk_4EC.unk_000.unk_01 &= ~1;
            temp_s0->unk_720->unk_04 = &temp_s0->unk_720->unk_08[sp34->unk_2C]->unk_01C[sp34->unk_18];
            temp_s0->unk_720->unk_00 |= 0x80;
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 5:
            if (temp_s0->unk_720->unk_00 & 0x10) {
                temp_s0->unk_720->unk_00 &= ~0x90;
                func_8430920C(temp_s0);
                func_84307748(temp_s0);
                D_843900A8[D_84390240.unk_00->unk_2C] = temp_s0->unk_654.unk_38.unk_0C;
                func_8432C68C(3, temp_s0, temp_s0, 0xFF, 0xFF);
                func_800367A0(2, 0, 0);
                func_84308A04(temp_s0, sp34->unk_2C);
                arg0->unk_24.fovy = 40.0f;
                func_843184E4(0xC);
                func_8432B588(temp_s0);
                D_843C4DC4 = 0;
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 6:
            func_84305760(temp_s0, 0x12);
            func_8431F420(temp_s0, arg0, 3);
            func_8431AE5C();
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 7:
            func_8431C750(arg0, temp_s0);
            if (func_84305BD8(temp_s0, 0x3C) != 0) {
                func_80048014();
                func_8432E9D8(2);
                func_8431AE5C();
                func_8000E88C(&temp_s0->unk_000.unk_030, 1.0f, 1.0f, 1.0f);
                if (sp2C->unk_5A == 0xFE) {
                    sp2C->unk_5A = 0xA5;
                }
                func_843208B0();
                sp34->unk_34 &= ~0x1800;
                func_843184FC();
                D_84390240.unk_00->unk_54 = !D_84390240.unk_00->unk_2C + 1;
            }
            break;
    }
}

void func_84328250(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654* sp3C = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;
    unk_D_84390010_654* sp38 = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654;
    UNUSED s32 pad;
    unk_D_84390010* temp_s0 = D_84390010[D_84390240.unk_00->unk_2C];
    unk_D_84390010_654_038* sp2C = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            if (D_84390240.unk_00->unk_34 == 1) {
                func_8431FF70(arg0);
                func_8431AE5C();
                func_843184E4(0xB);
                func_8432C9C0(temp_s0->unk_720, 3);
                func_8000E88C(&arg0->unk_60.at, temp_s0->unk_4B0 * -150.0f, 0.0, 0.0f);
                func_8000E88C(&arg0->unk_60.eye, temp_s0->unk_4B0 * -50.0f, 5.0f, 0.0f);
                func_8000E88C(&temp_s0->unk_000.unk_024, temp_s0->unk_4B0 * -150.0f, 25.0f, 0.0f);
                D_84390240.unk_00->unk_20 += 1;
            } else {
                func_8430C718(&arg0->unk_24.fovy, 30.0f, 0.05f);
                if (func_8431DA38(arg0, temp_s0) != 0) {
                    func_8431FF70(arg0);
                    func_8431AE5C();
                    func_843184E4(0xB);
                    func_8432C9C0(temp_s0->unk_720, 3);
                    D_84390240.unk_00->unk_20 += 1;
                }
            }
            break;

        case 1:
            if (func_84302000(temp_s0) != 0) {
                temp_s0->unk_720->unk_02 = sp2C->unk_0B;
                func_84308654(temp_s0, 2, 0);
                func_8432C68C(0xD, temp_s0, temp_s0, 0xFF, 0xFF);
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            if (temp_s0->unk_4EC.unk_024.y == 2.5f) {
                temp_s0->unk_4EC.unk_000.unk_02 |= 0x20;
            }

            if (func_800174E4(&temp_s0->unk_4EC) == 1) {
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 3:
            temp_s0->unk_4EC.unk_000.unk_01 &= ~1;
            temp_s0->unk_720->unk_00 |= 0x80;
            temp_s0->unk_720->unk_04 = &temp_s0->unk_720->unk_08[sp3C->unk_2C]->unk_01C[sp3C->unk_18];
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 4:
            if (temp_s0->unk_720->unk_00 & 0x10) {
                temp_s0->unk_720->unk_00 &= ~0x90;
                func_8430920C(temp_s0);
                func_84307748(temp_s0);
                D_843900A8[func_84307F00(temp_s0)] = temp_s0->unk_654.unk_38.unk_0C;
                func_800367A0(2, 0, 0);
                func_84308A04(temp_s0, sp3C->unk_2C);
                func_8431AE5C();
                func_8432C68C(3, temp_s0, temp_s0, 0xFF, 0xFF);
                arg0->unk_24.fovy = 40.0f;
                func_8432B588(temp_s0);
                D_843C4DC4 = 0;
                D_84390240.unk_00->unk_20 += 1;
            }
            break;

        case 5:
            func_84305760(temp_s0, 0x12);
            func_8431F420(temp_s0, arg0, 3);
            D_84390240.unk_00->unk_20 += 1;
            break;

        case 6:
            func_8431C750(arg0, temp_s0);
            if (func_84305BD8(temp_s0, 0x3C) != 0) {
                if ((sp2C->unk_5A & 0xF0) == 0xF0) {
                    sp2C->unk_5A = 0xA5;
                }
                func_80048014();
                func_8432E9D8(2);
                func_8431AE5C();
                func_8000E88C(&temp_s0->unk_000.unk_030, 1.0f, 1.0f, 1.0f);
                if (sp38->unk_2D != 0x10) {
                    D_84390240.unk_00->unk_34 = 3;
                }
                D_84390240.unk_00->unk_2E = 2;
                func_843208B0();
                sp3C->unk_34 &= 0xE7FF;
                D_84390240.unk_00->unk_54 = !D_84390240.unk_00->unk_2C + 1;
            }
            break;
    }
}

void func_84328734(unk_D_86002F34_00C* arg0) {
    func_8432113C();

    switch (D_84390240.unk_00->unk_38) {
        case 0:
            func_84321184(arg0);
            func_8431FF3C(arg0, 1);

        case 1:
            func_84322640(arg0);
            break;
        case 2:
            func_84324988(arg0);
            break;
        case 3:
            func_843249F8(arg0);
            break;
        case 4:
            func_84326A78(arg0);
            break;
        case 7:
            func_84324C28(arg0);
            break;
        case 38:
            func_84324F1C(arg0);
            break;
        case 27:
            func_84325080(arg0);
            break;
        case 30:
            func_843251D4(arg0);
            break;
        case 29:
            func_84325CDC(arg0);
            break;
        case 28:
            func_843255DC(arg0);
            break;
        case 25:
            func_84325A10(arg0);
            break;
        case 12:
            func_84325E94(arg0);
            break;
        case 13:
            func_843261CC(arg0);
            break;
        case 14:
            func_84326460(arg0);
            break;
        case 15:
            func_84325724(arg0);
            break;
        case 17:
            func_84326570(arg0);
            break;
        case 31:
            func_8432691C(arg0);
            break;
        case 20:
            func_843266D4(arg0);
            break;
        case 8:
            func_84326CB4(arg0);
            break;
        case 10:
            func_843275F8(arg0);
            break;
        case 6:
            func_84326E84(arg0);
            break;
        case 33:
            func_84327B90(arg0);
            break;
        case 35:
            func_84327720(arg0);
            break;
        case 9:
            func_8432734C(arg0);
            break;
        case 16:
            func_84326AC4(arg0);
            break;
        case 11:
            func_84327DC0(arg0);
            break;
        case 18:
            func_84328250(arg0);
            break;
        case 5:
            func_843221A8(arg0);
            break;
        case 34:
            func_84322350(arg0);
            break;
        case 36:
            func_84320864();
            break;
        case 37:
            func_84324A68();
            break;
    }
}
