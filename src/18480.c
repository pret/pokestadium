#include "18480.h"
#include "src/11BA0.h"
#include "src/F420.h"
#include "src/util.h"

typedef void (*func_D_8006F2B0)(void);

typedef struct unk_D_800ABE00_cmd0 {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ s32 unk_04;
} unk_D_800ABE00_cmd0; // size = 0x8

typedef struct unk_D_800ABE00_cmd1 {
    /* 0x00 */ u8 cmd;
} unk_D_800ABE00_cmd1; // size = 0x4

typedef struct unk_D_800ABE00_cmd2 {
    /* 0x00 */ u8 cmd;
    /* 0x04 */ u32 unk_04;
} unk_D_800ABE00_cmd2; // size = 0x8

typedef struct unk_D_800ABE00_cmd3 {
    /* 0x00 */ u8 cmd;
    /* 0x04 */ u32 unk_04;
} unk_D_800ABE00_cmd3; // size = 0x8

typedef struct unk_D_800ABE00_cmd4 {
    /* 0x00 */ u8 cmd;
} unk_D_800ABE00_cmd4; // size = 0x4

typedef struct unk_D_800ABE00_cmd5 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[3];
} unk_D_800ABE00_cmd5; // size = 0x4

typedef struct unk_D_800ABE00_cmd6 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[3];
} unk_D_800ABE00_cmd6; // size = 0x4

typedef struct unk_D_800ABE00_cmd7 {
    /* 0x00 */ u8 cmd;
    /* 0x04 */ unk_D_8690A610* unk_04;
} unk_D_800ABE00_cmd7; // size = 0x8

typedef struct unk_D_800ABE00_cmd8 {
    /* 0x00 */ u8 cmd;
    /* 0x04 */ func_D_86002F34_000_010 unk_04;
    /* 0x08 */ unk_D_86002F34_000_014* unk_08;
} unk_D_800ABE00_cmd8; // size = 0xC

typedef struct unk_D_800ABE00_cmd9 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[3];
} unk_D_800ABE00_cmd9; // size = 0x4

typedef struct unk_D_800ABE00_cmdA {
    /* 0x00 */ u8 cmd;
    /* 0x04 */ unk_D_86002F34_000* unk_04;
} unk_D_800ABE00_cmdA; // size = 0x8

typedef struct unk_D_800ABE00_cmdB {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ Vec3s unk_0C;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
} unk_D_800ABE00_cmdB; // size = 0x18

typedef struct unk_D_800ABE00_cmdC {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
} unk_D_800ABE00_cmdC; // size = 0x4

typedef struct unk_D_800ABE00_cmdD {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
} unk_D_800ABE00_cmdD; // size = 0x4

typedef struct unk_D_800ABE00_cmdE {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
} unk_D_800ABE00_cmdE; // size = 0x4

typedef struct unk_D_800ABE00_cmdF {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
} unk_D_800ABE00_cmdF; // size = 0x4

typedef struct unk_D_800ABE00_cmd10 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
} unk_D_800ABE00_cmd10; // size = 0x4

typedef struct unk_D_800ABE00_cmd11 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[3];
} unk_D_800ABE00_cmd11; // size = 0x4

typedef struct unk_D_800ABE00_cmd13 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 r;
    /* 0x02 */ u8 g;
    /* 0x03 */ u8 b;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
} unk_D_800ABE00_cmd13; // size = 0x8

typedef struct unk_D_800ABE00_cmd14 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char unk01[0x3];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8 r;
    /* 0x09 */ u8 g;
    /* 0x0A */ u8 b;
    /* 0x0B */ u8 a;
} unk_D_800ABE00_cmd14; // size = 0xC

typedef struct unk_D_800ABE00_cmd15 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char unk01[0xB];
} unk_D_800ABE00_cmd15; // size = 0xC

typedef struct unk_D_800ABE00_cmd16 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 r;
    /* 0x02 */ u8 g;
    /* 0x03 */ u8 b;
} unk_D_800ABE00_cmd16; // size = 0x4

typedef struct unk_D_800ABE00_cmd17 {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ unk_D_86002F34_018* unk_08;
    /* 0x0C */ unk_D_86002F34_01C* unk_0C;
    /* 0x10 */ Vtx* unk_10;
} unk_D_800ABE00_cmd17; // size = 0x14

typedef struct unk_D_800ABE00_cmd18 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
} unk_D_800ABE00_cmd18; // size = 0x8

typedef struct unk_D_800ABE00_cmd19 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char unk01[0x3];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
} unk_D_800ABE00_cmd19; // size = 0x8

typedef struct unk_D_800ABE00_cmd1A {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
} unk_D_800ABE00_cmd1A; // size = 0x4

typedef struct unk_D_800ABE00_cmd1B {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char unk01[0x3];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ Vec3s unk_0A;
} unk_D_800ABE00_cmd1B; // size = 0x10

typedef struct unk_D_800ABE00_cmd1C {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char unk01[0x3];
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ u32 unk_08;
    /* 0x0C */ u32 unk_0C;
} unk_D_800ABE00_cmd1C; // size = 0x10

typedef struct unk_D_800ABE00_cmd1D {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ Vec3s unk_04;
    /* 0x0A */ Vec3s unk_0A;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u32 unk_14;
    /* 0x18 */ u32 unk_18;
} unk_D_800ABE00_cmd1D; // size = 0x1C

typedef struct unk_D_800ABE00_cmd1E {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ Gfx* unk_04;
} unk_D_800ABE00_cmd1E; // size = 0x8

typedef struct unk_D_800ABE00_cmd1F {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ Vec3s unk_0A;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ char pad[0x2];
} unk_D_800ABE00_cmd1F; // size = 0x18

typedef struct unk_D_800ABE00_cmd20 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk02[0x2];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ Vec3s unk_0A;
    /* 0x10 */ Gfx* unk_10;
} unk_D_800ABE00_cmd20; // size = 0x14

typedef struct unk_D_800ABE00_cmd21 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ Vec3s unk_02;
    /* 0x08 */ u32 unk_08;
    /* 0x0C */ Gfx* unk_0C;
} unk_D_800ABE00_cmd21; // size = 0x10

typedef struct unk_D_800ABE00_cmd22 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x04 */ Gfx* unk_04;
} unk_D_800ABE00_cmd22; // size = 0x8

typedef struct unk_D_800ABE00_cmd23 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04;
    /* 0x07 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ u8 r;
    /* 0x0D */ u8 g;
    /* 0x0E */ u8 b;
    /* 0x0F */ u8 a;
} unk_D_800ABE00_cmd23; // size = 0x10

typedef struct unk_D_800ABE00_cmd24 {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
} unk_D_800ABE00_cmd24; // size = 0x4

typedef struct unk_D_800ABE00_cmd25 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[3];
} unk_D_800ABE00_cmd25; // size = 0x4

typedef struct unk_D_800ABE00_cmd26 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u8 r;
    /* 0x11 */ u8 g;
    /* 0x12 */ u8 b;
    /* 0x13 */ u8 a;
} unk_D_800ABE00_cmd26; // size = 0x14

extern MemoryBlock* D_800ABD30;
extern unk_D_86002F34* D_800ABD34;
extern u32 D_800ABD38[];
extern unk_D_86002F34_000* D_800ABD78[32];
extern s16 D_800ABDF8;
extern s16 D_800ABDFA;
extern s16 D_800ABDFE;
extern u8* D_800ABE00;

void func_80017880(void) {
    unk_D_800ABE00_cmd0* cmd = (unk_D_800ABE00_cmd0*)D_800ABE00;
    u32 v = (u32)D_800ABE00;

    D_800ABD38[D_800ABDFA++] = v + sizeof(unk_D_800ABE00_cmd0);
    D_800ABD38[D_800ABDFA++] = (D_800ABDF8 << 0x10) + D_800ABDFE;
    D_800ABDFE = D_800ABDFA;

    D_800ABE00 = (u8*)Util_ConvertAddrToVirtAddr(cmd->unk_04);
}

void func_80017914(void) {
    D_800ABDFA = D_800ABDFE;

    D_800ABDFE = D_800ABD38[--D_800ABDFA] & 0xFFFF;
    D_800ABDF8 = D_800ABD38[D_800ABDFA] >> 0x10;
    D_800ABE00 = D_800ABD38[--D_800ABDFA];
}

void func_8001799C(void) {
    unk_D_800ABE00_cmd2* cmd = (unk_D_800ABE00_cmd2*)D_800ABE00;

    D_800ABE00 = Util_ConvertAddrToVirtAddr(cmd->unk_04);
}

void func_800179C8(void) {
    unk_D_800ABE00_cmd3* cmd = (unk_D_800ABE00_cmd3*)D_800ABE00;

    cmd += 0;

    D_800ABD38[D_800ABDFA++] = D_800ABE00 + sizeof(unk_D_800ABE00_cmd3);
    D_800ABE00 = (u8*)Util_ConvertAddrToVirtAddr(cmd->unk_04);
}

void func_80017A1C(void) {
    D_800ABE00 = D_800ABD38[--D_800ABDFA];
}

void func_80017A54(void) {
    D_800ABD78[D_800ABDF8 + 1] = D_800ABD78[D_800ABDF8];
    D_800ABDF8++;

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd5);
}

void func_80017A98(void) {
    D_800ABDF8--;

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd6);
}

void func_80017AC4(unk_D_86002F34_000* arg0) {
    if (arg0 != NULL) {
        D_800ABD78[D_800ABDF8] = arg0;
        if (D_800ABDF8 == 0) {
            if (D_800ABD34 == NULL) {
                D_800ABD34 = arg0;
            }
        } else {
            func_80012094(D_800ABD78[D_800ABDF8 - 1], arg0);
        }
    }
}

void func_80017B28(void) {
    unk_D_800ABE00_cmd7* cmd = (unk_D_800ABE00_cmd7*)D_800ABE00;

    func_80017AC4(&cmd->unk_04->unk_00);

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd7);
}

void func_80017B60(void) {
    unk_D_800ABE00_cmd8* cmd = (unk_D_800ABE00_cmd8*)D_800ABE00;

    if (D_800ABD78[D_800ABDF8] != NULL) {
        func_80010FDC(D_800ABD78[D_800ABDF8], cmd->unk_04, cmd->unk_08);
    }

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd8);
}

void func_80017BBC(void) {
    func_80017AC4(func_8001103C(D_800ABD30, NULL));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd9);
}

void func_80017BFC(void) {
    unk_D_800ABE00_cmdA* cmd = (unk_D_800ABE00_cmdA*)D_800ABE00;

    func_80017AC4(func_80011088(D_800ABD30, NULL, cmd->unk_04));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmdA);
}

void func_80017C48(void) {
    unk_D_800ABE00_cmdB* cmd = (unk_D_800ABE00_cmdB*)D_800ABE00;
    unk_D_86002F34_00C* temp_v0 = func_800110E0(D_800ABD30, NULL, cmd->unk_04, cmd->unk_06, cmd->unk_08, cmd->unk_0A);

    if (temp_v0 != NULL) {
        temp_v0->unk_24.fovy = cmd->unk_02;
        func_8000E990(&temp_v0->unk_60.at, &cmd->unk_0C);
        func_80010354(&temp_v0->unk_60.at, &temp_v0->unk_60.eye, cmd->unk_16, (cmd->unk_12 << 0xF) / 180,
                      (cmd->unk_14 << 0xF) / 180);
    }

    func_80017AC4(&temp_v0->unk_00);

    D_800ABE00 += sizeof(unk_D_800ABE00_cmdB);
}

void func_80017D94(void) {
    unk_D_800ABE00_cmdC* cmd = (unk_D_800ABE00_cmdC*)D_800ABE00;

    func_80017AC4(func_800111A4(D_800ABD30, NULL, cmd->unk_02));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmdC);
}

void func_80017DE0(void) {
    unk_D_800ABE00_cmdD* cmd = (unk_D_800ABE00_cmdD*)D_800ABE00;

    func_80017AC4(func_800111FC(D_800ABD30, NULL, cmd->unk_02));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmdD);
}

void func_80017E2C(void) {
    unk_D_800ABE00_cmdE* cmd = (unk_D_800ABE00_cmdE*)D_800ABE00;

    func_80017AC4(func_80011258(D_800ABD30, NULL, cmd->unk_02));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmdE);
}

void func_80017E78(void) {
    unk_D_800ABE00_cmdF* cmd = (unk_D_800ABE00_cmdF*)D_800ABE00;

    func_80017AC4(func_800112BC(D_800ABD30, NULL, cmd->unk_02));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmdF);
}

void func_80017EC4(void) {
    unk_D_800ABE00_cmd10* cmd = (unk_D_800ABE00_cmd10*)D_800ABE00;

    func_80017AC4(func_80011320(D_800ABD30, NULL, cmd->unk_01, cmd->unk_02, cmd->unk_03));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd10);
}

void func_80017F1C(void) {
    func_80017AC4(func_800113AC(D_800ABD30, NULL));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd11);
}

void func_80017F5C(void) {
}

void func_80017F64(void) {
    unk_D_800ABE00_cmd13* cmd = (unk_D_800ABE00_cmd13*)D_800ABE00;

    func_80017AC4(func_800113F8(D_800ABD30, NULL, cmd->unk_04, cmd->unk_06, cmd->r, cmd->g, cmd->b, 0xFF));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd13);
}

void func_80017FD4(void) {
    unk_D_800ABE00_cmd14* cmd = (unk_D_800ABE00_cmd14*)D_800ABE00;

    func_80017AC4(func_80011484(D_800ABD30, NULL, (cmd->unk_04 << 0xF) / 180, (cmd->unk_06 << 0xF) / 180, cmd->r,
                                cmd->g, cmd->b, cmd->a));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd14);
}

void func_800180BC(void) {
    D_800ABE00 += sizeof(unk_D_800ABE00_cmd15);
}

void func_800180D4(void) {
    unk_D_800ABE00_cmd16* cmd = (unk_D_800ABE00_cmd16*)D_800ABE00;

    func_80017AC4(func_80011504(D_800ABD30, NULL, cmd->r, cmd->g, cmd->b));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd16);
}

void func_8001812C(void) {
    unk_D_800ABE00_cmd17* cmd = (unk_D_800ABE00_cmd17*)D_800ABE00;

    func_80017AC4(
        func_8001156C(D_800ABD30, NULL, cmd->unk_02, cmd->unk_08, cmd->unk_04, cmd->unk_0C, cmd->unk_06, cmd->unk_10));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd17);
}

void func_8001819C(void) {
    unk_D_800ABE00_cmd18* cmd = (unk_D_800ABE00_cmd18*)D_800ABE00;

    func_80017AC4(func_800115F0(D_800ABD30, NULL, cmd->unk_01, cmd->unk_04, cmd->unk_06, cmd->unk_02));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd18);
}

void func_800181FC(void) {
    unk_D_800ABE00_cmd19* cmd = (unk_D_800ABE00_cmd19*)D_800ABE00;

    func_80017AC4(func_80011660(D_800ABD30, NULL, cmd->unk_04, cmd->unk_06));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd19);
}

void func_8001824C(void) {
    unk_D_800ABE00_cmd1A* cmd = (unk_D_800ABE00_cmd1A*)D_800ABE00;

    func_80017AC4(func_800116C0(D_800ABD30, NULL, cmd->unk_01, cmd->unk_02));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd1A);
}

void func_8001829C(void) {
    Vec3s sp30;
    Vec3f sp24;
    UNUSED s32 pad;
    unk_D_800ABE00_cmd1B* cmd = (unk_D_800ABE00_cmd1B*)D_800ABE00;

    func_8000E990(&sp24, &cmd->unk_0A);
    func_8000EB70(&sp30, (cmd->unk_04 << 0xF) / 180, (cmd->unk_06 << 0xF) / 180, (cmd->unk_08 << 0xF) / 180);
    func_80017AC4(func_80011720(D_800ABD30, NULL, &sp24, &sp30));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd1B);
}

void func_800183C4(void) {
    Vec3f sp24;
    unk_D_800ABE00_cmd1C* cmd = (unk_D_800ABE00_cmd1C*)D_800ABE00;

    sp24.x = cmd->unk_04 / 65536.0f;
    sp24.y = cmd->unk_08 / 65536.0f;
    sp24.z = cmd->unk_0C / 65536.0f;
    func_80017AC4(func_800117A8(D_800ABD30, NULL, &sp24));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd1C);
}

void func_80018490(void) {
    Vec3f sp3C;
    s16 var_a3 = 1;
    unk_D_800ABE00_cmd1D* cmd = (unk_D_800ABE00_cmd1D*)D_800ABE00;

    sp3C.x = cmd->unk_10 / 65536.0f;
    sp3C.y = cmd->unk_14 / 65536.0f;
    sp3C.z = cmd->unk_18 / 65536.0f;

    if (cmd->unk_02 & 1) {
        var_a3 = 0;
    }

    if (cmd->unk_02 & 2) {
        var_a3 |= 2;
    }

    func_80017AC4(func_80011814(D_800ABD30, NULL, cmd->unk_01, var_a3, cmd->unk_03, &cmd->unk_04, &cmd->unk_0A, &sp3C));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd1D);
}

void func_800185A8(void) {
    unk_D_800ABE00_cmd1E* cmd = (unk_D_800ABE00_cmd1E*)D_800ABE00;

    func_80017AC4(func_800118D0(D_800ABD30, NULL, cmd->unk_01, cmd->unk_04, cmd->unk_02));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd1E);
}

void func_80018600(void) {
    Vec3s sp40;
    Vec3f sp34;
    Vec3f sp28;
    unk_D_86002F58_004_000* tmp;
    unk_D_800ABE00_cmd1F* cmd = (unk_D_800ABE00_cmd1F*)D_800ABE00;

    func_8000E990(&sp34, &cmd->unk_0A);

    sp28.x = cmd->unk_10 / 100.0f;
    sp28.y = cmd->unk_12 / 100.0f;
    sp28.z = cmd->unk_14 / 100.0f;

    func_8000EB70(&sp40, (cmd->unk_04 << 0xF) / 180, (cmd->unk_06 << 0xF) / 180, (cmd->unk_08 << 0xF) / 180);
    tmp = func_80011938(D_800ABD30, NULL, cmd->unk_02, &sp34, &sp40, &sp28);
    func_80017AC4(tmp);

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd1F);
}

void func_8001878C(void) {
    Vec3f sp34;
    Vec3s sp2C;
    unk_D_86002F34_alt8* tmp;
    unk_D_800ABE00_cmd20* cmd = (unk_D_800ABE00_cmd20*)D_800ABE00;

    func_8000E990(&sp34, &cmd->unk_0A);
    func_8000EB70(&sp2C, (cmd->unk_04 << 0xF) / 180, (cmd->unk_06 << 0xF) / 180, (cmd->unk_08 << 0xF) / 180);
    tmp = func_80011ABC(D_800ABD30, NULL, cmd->unk_01, cmd->unk_10, &sp34, &sp2C);
    func_80017AC4(tmp);

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd20);
}

void func_800188C8(void) {
    Vec3f sp2C;
    unk_D_86002F34_alt9* tmp;
    unk_D_800ABE00_cmd21* cmd = (unk_D_800ABE00_cmd21*)D_800ABE00;

    func_8000E990(&sp2C, &cmd->unk_02);
    tmp = func_80011B10(D_800ABD30, NULL, cmd->unk_01, cmd->unk_0C, &sp2C, cmd->unk_08 / 65536.0f);
    func_80017AC4(tmp);

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd21);
}

void func_80018968(void) {
    unk_D_800ABE00_cmd22* cmd = (unk_D_800ABE00_cmd22*)D_800ABE00;

    func_80017AC4(func_80011B94(D_800ABD30, NULL, cmd->unk_01, cmd->unk_04));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd22);
}

void func_800189B8(void) {
    unk_D_800ABE00_cmd23* cmd = (unk_D_800ABE00_cmd23*)D_800ABE00;

    func_80017AC4(func_80011BF4(D_800ABD30, NULL, cmd->unk_01, cmd->unk_02, cmd->unk_04, cmd->unk_08, cmd->unk_0A,
                                cmd->r, cmd->g, cmd->b, cmd->a));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd23);
}

void func_80018A40(void) {
    unk_D_800ABE00_cmd24* cmd = (unk_D_800ABE00_cmd24*)D_800ABE00;

    func_80017AC4(func_80011C98(D_800ABD30, NULL, cmd->unk_02));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd24);
}

void func_80018A8C(void) {
    unk_D_800ABE00_cmd25* cmd = (unk_D_800ABE00_cmd25*)D_800ABE00;

    if (D_800ABD78[D_800ABDF8] != NULL) {
        D_800ABD78[D_800ABDF8]->unk_02 |= 4;
    }

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd25);
}

void func_80018AD0(void) {
    unk_D_800ABE00_cmd26* cmd = (unk_D_800ABE00_cmd26*)D_800ABE00;

    func_80017AC4(func_80011CF0(D_800ABD30, NULL, cmd->unk_01, cmd->unk_04, cmd->unk_06, cmd->unk_08, cmd->unk_0A,
                                cmd->unk_02, cmd->unk_03, cmd->unk_0C, cmd->r, cmd->g, cmd->b, cmd->a));

    D_800ABE00 += sizeof(unk_D_800ABE00_cmd26);
}

unk_D_86002F34_000* func_80018B70(MemoryBlock* arg0, void* arg1) {
    extern func_D_8006F2B0 D_8006F2B0[];

    D_800ABD34 = NULL;
    D_800ABDF8 = 0;
    D_800ABDFA = 2;
    D_800ABDFE = 2;
    D_800ABE00 = Util_ConvertAddrToVirtAddr((uintptr_t)arg1);
    D_800ABD30 = arg0;
    D_800ABD78[0] = NULL;
    D_800ABD38[0] = 0;
    D_800ABD38[1] = 0;

    while (D_800ABE00 != NULL) {
        D_8006F2B0[*D_800ABE00]();
    }

    return D_800ABD34;
}
