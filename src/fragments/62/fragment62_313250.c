#include "fragment62.h"
#include "src/11BA0.h"
#include "src/17300.h"
#include "src/2E110.h"
#include "src/373A0.h"
#include "src/F420.h"
#include "src/memory.h"
#include "src/util.h"

void func_84328990(unk_D_86002F34_00C* arg0) {
    func_8431AE5C();
    func_8431AFD0(arg0, 20.0f, 12800.0f);
    func_8432C9C0(D_84390010[0]->unk_720, 3);
    arg0->unk_24.fovy = 40.0f;
    D_84390010[0]->unk_000.unk_000.unk_01 &= ~1;
    D_84390010[1]->unk_000.unk_000.unk_01 &= ~1;
    func_8000E88C(&arg0->unk_60.at, 0.0f, 75.0f, 0.0f);
    func_8000E88C(&arg0->unk_60.eye, -1.79f, 0.075f, 155.2f);
    D_84390240.unk_00->unk_54 = 1;
    func_8432BBC0();
    D_84390240.unk_00->unk_20 += 1;
}

void func_84328A70(UNUSED unk_D_86002F34_00C* arg0) {
    if ((func_8431ADF0(0xA) != 0) && (func_84302000(D_84390010[0]) != 0)) {
        D_84390010[0]->unk_000.unk_000.unk_01 &= ~1;
        D_84390010[1]->unk_000.unk_000.unk_01 &= ~1;
        func_84308654(D_84390010[0], 1, 0);
        func_800367A0(1, 0xFE, 0);
        func_8432C68C(8, D_84390010[0], D_84390010[0], 0xFF, 0xFF);
        D_84390240.unk_00->unk_20 += 1;
    }
}

void func_84328B30(UNUSED unk_D_86002F34_00C* arg0) {
    D_84390010[0]->unk_000.unk_000.unk_01 &= ~1;
    D_84390010[1]->unk_000.unk_000.unk_01 &= ~1;
    if (D_84390010[0]->unk_4EC.unk_024.y == 0.0f) {
        func_8432B808();
        func_800367A0(1, 1, 0);
        func_84308654(D_84390010[1], 1, 0);
        func_8432C68C(0xA, D_84390010[1], D_84390010[1], 0xFF, 0xFF);
        D_84390240.unk_00->unk_20 += 1;
    }
}

void func_84328BF0(unk_D_86002F34_00C* arg0) {
    Vec3f sp3C;

    D_84390010[0]->unk_000.unk_000.unk_01 &= ~1;
    D_84390010[1]->unk_000.unk_000.unk_01 &= ~1;

    if (D_84390010[1]->unk_4EC.unk_024.y == 0.0f) {
        arg0->unk_24.fovy = 30.0f;
        func_84308654(D_84390010[0], 2, 0);
        func_8432C68C(0xB, D_84390010[0], D_84390010[0], 0xFF, 0xFF);
        func_8000E88C(&sp3C, -150.0f, 5.0f, 0.0f);
        func_8431BAB4(D_84390010[0], arg0, sp3C, 0, 0, 0.0f, 0.0f);
        func_8431BB80(arg0, sp3C, D_84390240.unk_00->unk_56 = 0x71C, 0x4000, D_84390240.unk_00->unk_84 = 300.0f, 0.0f);
        D_84390240.unk_00->unk_20 += 1;
    }
}

void func_84328D70(unk_D_86002F34_00C* arg0) {
    Vec3f sp2C;

    func_8000E88C(&sp2C, -150.0f, 5.0f, 0.0f);
    D_84390010[0]->unk_000.unk_000.unk_01 &= ~1;
    D_84390010[1]->unk_000.unk_000.unk_01 &= ~1;
    func_8430C718(&D_84390240.unk_00->unk_84, 40.0f, 0.1f);
    func_8430C4F8(&D_84390240.unk_00->unk_56, 0xB6, 0x1E);
    func_8431BB80(arg0, sp2C, D_84390240.unk_00->unk_56, 0x4000, D_84390240.unk_00->unk_84, 0.0f);

    if ((D_84390240.unk_00->unk_56 >= 0x2E) && (D_84390010[0]->unk_4EC.unk_024.y == 2.5f)) {
        func_800367A0(2, 0, 0);
        D_84390010[0]->unk_4EC.unk_000.unk_02 |= 0x20;
        D_84390240.unk_00->unk_20 += 1;
    }
}

void func_84328EC0(UNUSED unk_D_86002F34_00C* arg0) {
    D_84390010[0]->unk_000.unk_000.unk_01 &= ~1;
    D_84390010[1]->unk_000.unk_000.unk_01 &= ~1;
    if (func_800174E4(&D_84390010[0]->unk_4EC) == 1) {
        D_84390240.unk_00->unk_20 += 1;
    }
}

void func_84328F2C(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654* sp2C = &D_84390010[0]->unk_654;
    unk_D_800AE540_0004* sp28 = D_84390010[0]->unk_720->unk_08[sp2C->unk_2C];

    D_84390010[0]->unk_728.unk_168->unk_00.unk_01 |= 1;
    D_84390010[0]->unk_728.unk_000.unk_000.unk_01 |= 1;
    func_843074A0(D_84390010[0]);
    D_84390010[0]->unk_000.unk_000.unk_01 &= ~1;
    D_84390010[1]->unk_000.unk_000.unk_01 &= ~1;
    func_8432C68C(3, D_84390010[0], D_84390010[0], 0xFF, 0xFF);
    D_84390010[0]->unk_000.unk_000.unk_01 |= 1;
    D_84390010[0]->unk_4EC.unk_000.unk_01 &= ~1;
    func_8431F420(D_84390010[0], arg0, 3);
    func_84305760(D_84390010[0], 0x10);
    D_84390240.unk_00->unk_2C = 0;
    func_8002D5D4(0x19, (u32)sp28->unk_01C[sp2C->unk_18].unk_30);
    func_843179F4(D_843901A0->unk_088, 0x21);
    func_843184E4(0xC);
    func_8432B588(D_84390010[0]);
    D_84390240.unk_00->unk_10 = 0;
    D_84390240.unk_00->unk_20 += 1;
}

void func_843290A0(unk_D_86002F34_00C* arg0) {
    if (D_84390240.unk_00->unk_10++ == 1) {
        func_8431F420(D_84390010[0], arg0, 3);
    }

    D_84390010[0]->unk_728.unk_168->unk_00.unk_01 &= ~1;
    D_84390010[0]->unk_728.unk_000.unk_000.unk_01 &= ~1;
    D_84390010[1]->unk_000.unk_000.unk_01 &= ~1;
    func_8431C750(arg0, D_84390010[0]);

    if (func_84305BD8(D_84390010[0], 0x3C) != 0) {
        D_84390240.unk_00->unk_20 += 1;
    }
}

void func_84329164(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654* sp2C = &D_84390010[1]->unk_654;
    unk_D_800AE540_0004* sp28 = D_84390010[1]->unk_720->unk_08[sp2C->unk_2C];

    D_84390010[1]->unk_728.unk_168->unk_00.unk_01 |= 1;
    D_84390010[1]->unk_728.unk_000.unk_000.unk_01 |= 1;
    func_843074A0(D_84390010[1]);
    func_800367A0(2, 0, 0);
    func_8432C68C(3, D_84390010[1], D_84390010[1], 0xFF, 0xFF);
    func_8431AE5C();
    D_84390010[1]->unk_000.unk_000.unk_01 |= 1;
    func_8431F420(D_84390010[1], arg0, 3);
    func_84305760(D_84390010[1], 0x10);
    D_84390240.unk_00->unk_10 = 0;
    D_84390240.unk_00->unk_2C = 1;
    func_8002D5D4(0x19, (u32)sp28->unk_01C[sp2C->unk_18].unk_30);
    func_843179F4(D_843901A0->unk_088, 0x21);
    if (D_800AE540.unk_0000 != 8) {
        func_843184E4(0xC);
    }
    func_8432B588(D_84390010[1]);
    D_84390240.unk_00->unk_20 += 1;
}

void func_843292D8(unk_D_86002F34_00C* arg0) {
    if (D_84390240.unk_00->unk_10++ == 1) {
        func_8431F420(D_84390010[1], arg0, 3);
    }
    D_84390010[1]->unk_728.unk_168->unk_00.unk_01 &= ~1;
    D_84390010[1]->unk_728.unk_000.unk_000.unk_01 &= ~1;
    D_84390010[0]->unk_000.unk_000.unk_01 &= ~1;
    func_8431C750(arg0, D_84390010[1]);
    if (func_84305BD8(D_84390010[1], 0x3C) != 0) {
        func_8432056C();
        D_84390240.unk_00->unk_20 += 1;
    }
}

void func_843293A8(UNUSED unk_D_86002F34_00C* arg0) {
}

void func_843293B0(void) {
}

void func_843293B8(unk_D_86002F34_00C* arg0) {
    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_84328990(arg0);

        case 1:
            func_84328A70(arg0);
            break;

        case 2:
            func_84328B30(arg0);
            break;

        case 3:
            func_84328BF0(arg0);
            break;

        case 4:
            func_84328D70(arg0);
            break;

        case 5:
            func_84328EC0(arg0);
            break;

        case 6:
            func_84328F2C(arg0);
            break;

        case 7:
            func_843290A0(arg0);
            break;

        case 8:
            func_84329164(arg0);
            break;

        case 9:
            func_843292D8(arg0);
            break;

        case 10:
            func_843293A8(arg0);
            break;
    }
}
