#include "fragment34.h"

static u8 D_8140E470[][3] = {
    { 0, 0, 0 },          { 0, 0x14, 0x1E },    { 0, 0x23, 0x2D },    { 0x40, 0x40, 0x40 }, { 0x46, 0x55, 0x55 },
    { 0x6E, 0x6E, 0x6E }, { 0x80, 0x80, 0x80 }, { 0xB4, 0xC8, 0xC8 }, { 0xC8, 0xFF, 0xFF }, { 0xE6, 0xF0, 0xF0 },
    { 0xFF, 0xFF, 0xFF }, { 0xFF, 0, 0 },       { 0xF0, 0x28, 0x28 }, { 0xFF, 0x80, 0x80 }, { 0xAA, 0x32, 0 },
    { 0x96, 0, 0 },       { 0x64, 0, 0 },       { 0x46, 0x14, 0 },    { 0x32, 0xA, 0xA },   { 0xFF, 0x80, 0 },
    { 0xFF, 0xA0, 0 },    { 0xF0, 0xDC, 0xD8 }, { 0xFF, 0xC8, 0xC8 }, { 0xFF, 0x78, 0xC8 }, { 0xFF, 0, 0x64 },
    { 0xFF, 0xFF, 0 },    { 0xFF, 0xFF, 0x64 }, { 0xFF, 0xFF, 0x9B }, { 0xFF, 0xFF, 0xC8 }, { 0xFF, 0xC8, 0 },
    { 0xD7, 0xFF, 0x73 }, { 0xC8, 0xC8, 0 },    { 0x96, 0x96, 0x32 }, { 0x64, 0x64, 0 },    { 0x80, 0x80, 0x50 },
    { 0, 0xFF, 0 },       { 0x28, 0xFF, 0x28 }, { 0x64, 0xFF, 0x64 }, { 0x80, 0xFF, 0x80 }, { 0x9B, 0xFF, 0xC8 },
    { 0x50, 0x64, 0x3C }, { 0xC8, 0xFF, 0 },    { 0xC8, 0xC8, 0 },    { 0x96, 0xB4, 0 },    { 0, 0x96, 0 },
    { 0, 0x64, 0 },       { 0, 0, 0xFF },       { 0x32, 0x32, 0xFF }, { 0, 0x32, 0xFF },    { 0, 0x64, 0xFF },
    { 0, 0x78, 0xFF },    { 0x20, 0x7C, 0xFF }, { 0x80, 0x80, 0xFF }, { 0x64, 0xC8, 0xFF }, { 0, 0xFF, 0xFF },
    { 0x64, 0xFF, 0xFF }, { 0xB4, 0xFF, 0xFF }, { 0xC8, 0xFF, 0xFF }, { 0x46, 0x64, 0x78 }, { 0xFF, 0, 0xFF },
    { 0xFF, 0x32, 0xFF }, { 0xD7, 0, 0xFF },    { 0x96, 0, 0xC8 },    { 0x64, 0, 0xFF },    { 0xFF, 0x32, 0xFF },
    { 0x78, 0x1E, 0x78 },
};

u8 D_8140E538[] = {
    0x0C, 0x19, 0x23, 0x36, 0x2F, 0x3B,
};

static u8 D_8140E540[] = {
    0x17, 0x19, 0x25, 0x23, 0x35, 0x14,
};

static u8 D_8140E548[] = {
    0x0A, 0x19, 0x36, 0x24, 0x16,
};

static u8 D_8140E550[][2] = {
    { 0x19, 0xC },  { 0xA, 0x3B },  { 0, 0xC },     { 8, 0x31 },    { 0x2A, 0x23 }, { 0x19, 0x1F }, { 0x36, 0x32 },
    { 0x19, 0xB },  { 0x3B, 0x3C }, { 0xC, 0xC },   { 0xA, 0x1C },  { 0xA, 0x14 },  { 0xA, 0x35 },  { 0xA, 0x24 },
    { 0xA, 0xC },   { 0x19, 0x14 }, { 0x19, 0xC },  { 0x15, 0xA },  { 0xE, 0x11 },  { 8, 0x37 },    { 0x36, 0x30 },
    { 0xA, 0x3F },  { 0xB, 0 },     { 0xA, 0x19 },  { 0xA, 0x36 },  { 0x37, 0x31 }, { 0x19, 0xB },  { 0, 0x3B },
    { 0, 1 },       { 0xA, 0xA },   { 4, 2 },       { 0x29, 0x2C }, { 0xA, 0 },     { 0xC, 0x10 },  { 0x1B, 0x3B },
    { 0xA, 0x27 },  { 0x14, 0xB },  { 0xA, 0x1C },  { 0xA, 0x35 },  { 0xA, 8 },     { 0xA, 0x31 },  { 0x1C, 0x1A },
    { 0x1A, 0xB },  { 0x14, 0xF },  { 0x1A, 0x14 }, { 0x14, 0 },    { 0xB, 0 },     { 0x36, 0x2D }, { 0x23, 0x2C },
    { 0x1A, 0x20 }, { 0x21, 0x21 }, { 0xA, 0xA },   { 0x19, 0x2C }, { 0x3B, 0x3C }, { 0x2B, 0xA },  { 0x3E, 0xA },
    { 0x19, 0x23 }, { 0xA, 0x23 },  { 0xB, 0 },     { 0xA, 0x1A },  { 0xA, 0x35 },  { 0xA, 0x35 },  { 0xA, 0x17 },
    { 0xA, 0x3F },  { 0xA, 0x31 },  { 0xA, 0x17 },  { 0xA, 0x13 },  { 0x3C, 0x3E }, { 0x15, 0x15 }, { 0x3E, 0x3E },
    { 0x23, 0x23 }, { 0x13, 0xC },  { 0x19, 0x13 }, { 0x16, 0xC },  { 0x1C, 0x19 }, { 0x39, 0x2F }, { 0xA, 0x39 },
    { 0x38, 0x35 }, { 0x38, 0x39 }, { 0x1C, 0x1A }, { 9, 0x35 },
};

void func_8140C760(UNUSED unk_D_8140E720* arg0, u8* texture) {
    func_81403AB8(texture, 32, 32);
}

void func_8140C78C(unk_D_8140E720* arg0, u8* texture) {
    func_81403F8C(&texture[arg0->unk_C7 * 32 * 32], 32, 32);
}

void func_8140C7C0(UNUSED unk_D_8140E720* arg0, u8* texture) {
    func_81403F8C(texture, 32, 32);
}

void func_8140C7EC(unk_D_8140E720* arg0, u8* texture) {
    func_81403F8C(&texture[arg0->unk_C7 * 32 * 64], 32, 64);
}

void func_8140C820(UNUSED unk_D_8140E720* arg0, u8* texture) {
    func_8140437C(texture, 32, 32);
}

void func_8140C84C(unk_D_8140E720* arg0, u8* texture) {
    func_8140437C(&texture[arg0->unk_C7 * (32 * 32 / 2)], 32, 32);
}

void func_8140C880(UNUSED unk_D_8140E720* arg0, u8* texture) {
    func_8140437C(&texture[D_8140E6CC * (32 * 32 / 2)], 32, 32);
}

void func_8140C8B8(UNUSED unk_D_8140E720* arg0, u8* texture) {
    func_8140437C(&texture[(D_8140E6F0 & 3) * (32 * 32 / 2)], 32, 32);
}

void func_8140C8F4(UNUSED unk_D_8140E720* arg0, u8* texture) {
    func_8140437C(&texture[(D_8140E6E8 & 3) * (32 * 32 / 2)], 32, 32);
}

void func_8140C930(UNUSED unk_D_8140E720* arg0, u8* texture) {
    func_8140437C(&texture[(D_8140E6F0 & 7) * (32 * 32 / 2)], 32, 32);
}

void func_8140C96C(UNUSED unk_D_8140E720* arg0, u8* texture) {
    func_8140439C(&texture[(D_8140E6F0 & 7) * (24 * 24 / 2)], 24, 24);
}

void func_8140C9B0(unk_D_8140E720* arg0, u8* texture) {
    func_8140439C(&texture[arg0->unk_C7 * (24 * 24 / 2)], 24, 24);
}

void func_8140C9EC(UNUSED unk_D_8140E720* arg0, u8* texture) {
    func_8140437C(&texture[(D_8140E6B8 % 10) * (32 * 64 / 2)], 32, 64);
}

void func_8140CA30(unk_D_8140E720* arg0, u8* texture) {
    func_8140437C(&texture[arg0->unk_C7 * (32 * 64 / 2)], 32, 64);
}

void func_8140CA64(UNUSED unk_D_8140E720* arg0, u8* texture) {
    func_8140437C(texture, 64, 64);
}

void func_8140CA90(UNUSED unk_D_8140E720* arg0, u8* texture) {
    func_8140437C(&texture[D_8140E6C8 * (64 * 64 / 2)], 64, 64);
}

void func_8140CAC8(UNUSED unk_D_8140E720* arg0, u8* texture) {
    func_8140437C(&texture[(D_8140E6F0 & 7) * (64 * 64 / 2)], 64, 64);
}

void func_8140CB04(unk_D_8140E720* arg0, u8* texture) {
    func_8140437C(&texture[arg0->unk_C7 * (64 * 64 / 2)], 64, 64);
}

void func_8140CB38(UNUSED unk_D_8140E720* arg0, u8* texture) {
    func_8140430C(texture, 64, 64);
}

void func_8140CB64(UNUSED unk_D_8140E720* arg0, u8* texture) {
    func_81404024(texture, 64, 64);
}

void func_8140CB90(unk_D_8140E720* arg0, unk_D_86002F34_00C* arg1) {
    func_81405B70(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a);
    func_81404DB4(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E018);
}

void func_8140CC04(unk_D_8140E720* arg0, unk_D_86002F34_00C* arg1) {
    func_81405C70(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    func_81404DB4(arg1, arg0->unk_2C, arg0->unk_1C, D_8140DFD8);
}

s32 func_8140CC90(unk_D_8140E720* arg0, UNUSED unk_D_86002F34_00C* arg1) {
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    func_81405C70(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    func_81404ABC(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, D_8140DFD8);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void func_8140CD80(unk_D_8140E720* arg0, unk_D_86002F34_00C* arg1) {
    func_81404DB4(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E018);
}

void func_8140CDDC(unk_D_8140E720* arg0, unk_D_86002F34_00C* arg1) {
    func_81405C70(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    func_81404DB4(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E018);
}

void func_8140CE68(unk_D_8140E720* arg0, unk_D_86002F34_00C* arg1) {
    func_81405C04(arg0->prim_a);
    func_81404E4C(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E108, arg0->unk_94.z);
}

void func_8140CED4(unk_D_8140E720* arg0, unk_D_86002F34_00C* arg1) {
    func_81404DB4(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E058);
}

void func_8140CF30(unk_D_8140E720* arg0, unk_D_86002F34_00C* arg1) {
    func_81405D38(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    func_81404DB4(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E018);
}

void func_8140CFBC(unk_D_8140E720* arg0, unk_D_86002F34_00C* arg1) {
    func_81405C70(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    func_81404E4C(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E018, arg0->unk_94.z);
}

void func_8140D050(unk_D_8140E720* arg0, unk_D_86002F34_00C* arg1) {
    func_81405C70(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    func_814050BC(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E0D8, arg0->unk_94.z);
}

void func_8140D0E4(unk_D_8140E720* arg0, unk_D_86002F34_00C* arg1) {
    func_81405C70(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    func_81404DB4(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E178);
}

void func_8140D170(unk_D_8140E720* arg0, unk_D_86002F34_00C* arg1) {
    func_81405C70(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    func_81404DB4(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E1F8);
}

void func_8140D1FC(unk_D_8140E720* arg0, unk_D_86002F34_00C* arg1) {
    func_81405C70(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    func_81404DB4(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E1B8);
}

void func_8140D288(unk_D_8140E720* arg0, unk_D_86002F34_00C* arg1) {
    func_81405C70(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    func_81404DB4(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E2B8);
}

s32 func_8140D314(unk_D_8140E720* arg0, UNUSED unk_D_86002F34_00C* arg1) {
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    func_81405C70(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    func_81404ABC(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, D_8140E2B8);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void func_8140D404(unk_D_8140E720* arg0, unk_D_86002F34_00C* arg1) {
    func_81405C70(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    func_81404ABC(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, D_8140E378);
}

void func_8140D4A8(u8* arg0, u16 arg1) {
    arg0[0] = D_8140E470[arg1][0];
    arg0[1] = D_8140E470[arg1][1];
    arg0[2] = D_8140E470[arg1][2];
}

void func_8140D4E0(u8* arg0, u8* arg1, u16 arg2) {
    u8 sp1C = D_8140E550[arg2][0];
    u8 sp1E = D_8140E550[arg2][1];

    func_8140D4A8(arg0, sp1C);
    func_8140D4A8(arg1, sp1E);
}

void func_8140D530(unk_D_8140E720* arg0, u16 arg1) {
    arg0->prim_r = D_8140E470[arg1][0];
    arg0->prim_g = D_8140E470[arg1][1];
    arg0->prim_b = D_8140E470[arg1][2];
}

void func_8140D568(unk_D_8140E720* arg0, u16 arg1) {
    arg0->env_r = D_8140E470[arg1][0];
    arg0->env_g = D_8140E470[arg1][1];
    arg0->env_b = D_8140E470[arg1][2];
}

void func_8140D5A0(unk_D_8140E720* arg0, u16 arg1) {
    u8 sp1C = D_8140E550[arg1][0];
    u8 sp1E = D_8140E550[arg1][1];

    func_8140D530(arg0, sp1C);
    func_8140D568(arg0, sp1E);
}

void func_8140D5F0(unk_D_8140E720* arg0, s16 arg1) {
    func_8140D530(arg0, D_8140E538[arg1]);
}

void func_8140D624(unk_D_8140E720* arg0, s16 arg1) {
    func_8140D568(arg0, D_8140E538[arg1]);
}

void func_8140D658(unk_D_8140E720* arg0, s16 arg1) {
    func_8140D530(arg0, D_8140E540[arg1]);
}

void func_8140D68C(unk_D_8140E720* arg0, s16 arg1) {
    func_8140D568(arg0, D_8140E540[arg1]);
}

void func_8140D6C0(unk_D_8140E720* arg0, s16 arg1) {
    u8 sp1F = D_8140E538[arg1];

    func_8140D530(arg0, sp1F);
    func_8140D568(arg0, sp1F);
}

void func_8140D708(unk_D_8140E720* arg0, s16 arg1) {
    u8 sp1F = D_8140E540[arg1];

    func_8140D530(arg0, sp1F);
    func_8140D568(arg0, sp1F);
}

void func_8140D750(unk_D_8140E720* arg0) {
    func_8140D530(arg0, D_8140E548[(func_81400A78(5) & 0xFF)]);
}

void func_8140D78C(unk_D_8140E720* arg0) {
    func_8140D568(arg0, D_8140E548[func_81400A78(5) & 0xFF]);
}

s32 func_8140D7C8(unk_D_8140E720* arg0, u16 arg1, u8 arg2) {
    s32 sp2C = 0;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    u8 sp1C[3];

    func_8140D4A8(sp1C, arg1);

    sp28 = func_8140BAE4(arg0, sp1C[0], arg2);
    sp24 = func_8140BB14(arg0, sp1C[1], arg2);
    sp20 = func_8140BB44(arg0, sp1C[2], arg2);

    if ((sp28 * sp24 * sp20) != 0) {
        sp2C = 1;
    }
    return sp2C;
}

s32 func_8140D868(unk_D_8140E720* arg0, u16 arg1, u8 arg2) {
    s32 sp2C = 0;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    u8 sp1C[3];

    func_8140D4A8(&sp1C, arg1);

    sp28 = func_8140BB90(arg0, sp1C[0], arg2);
    sp24 = func_8140BBF0(arg0, sp1C[1], arg2);
    sp20 = func_8140BBC0(arg0, sp1C[2], arg2);

    if ((sp28 * sp24 * sp20) != 0) {
        sp2C = 1;
    }
    return sp2C;
}

s32 func_8140D908(unk_D_8140E720* arg0, u16 arg1, u8 arg2) {
    s32 sp44 = 0;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    u8 sp28[3];
    u8 sp24[3];

    func_8140D4E0(sp28, sp24, arg1);

    sp40 = func_8140BAE4(arg0, sp28[0], arg2);
    sp3C = func_8140BB14(arg0, sp28[1], arg2);
    sp38 = func_8140BB44(arg0, sp28[2], arg2);
    sp34 = func_8140BB90(arg0, sp24[0], arg2);
    sp30 = func_8140BBF0(arg0, sp24[1], arg2);
    sp2C = func_8140BBC0(arg0, sp24[2], arg2);

    if ((sp40 * sp3C * sp38 * sp34 * sp30 * sp2C) != 0) {
        sp44 = 1;
    }
    return sp44;
}
