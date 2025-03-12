#include "fragment17.h"
#include "src/11BA0.h"
#include "src/12D80.h"
#include "src/18140.h"
#include "src/geo_layout.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/29BA0.h"
#include "src/3FB0.h"
#include "src/4BDC0.h"
#include "src/4CBC0.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/F420.h"
#include "src/controller.h"
#include "src/fragments/3/fragment3.h"
#include "src/fragments/34/fragment34.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "src/util.h"

extern u8 D_3000180[];
extern u8 D_3000780[];
extern u8 D_3001220[];
extern u8 D_3001B80[];
extern u8 D_30024E0[];
extern u8 D_30032A0[];
extern u8 D_3004060[];
extern u8 D_3004E20[];
extern u8 D_3005780[];
extern u8 D_30060E0[];
extern u8 D_3006B80[];
extern u8 D_300C6D0[];

s32 func_86B05CB0(s32, GraphNode*);
s32 func_86B05D18(s32, GraphNode*);
s32 func_86B05D84(s32, GraphNode*);

typedef struct unk_D_86B0DD58 {
    /* 0x00 */ u8 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
} unk_D_86B0DD58; // size = 0xC

static unk_D_86B0DAE0_000 D_86B0DCE0[4] = {
    {
        0x00FF,
        0x00E1,
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000,
    },
    {
        0x00FF,
        0x00FF,
        0x00FF,
        0x00FF,
        0x00FF,
        0x0064,
        0x00FF,
        0x0007,
        0x0040,
        0x0040,
        0x0040,
        0x0019,
    },
    {
        0x00FF,
        0x00FF,
        0x009B,
        0x009B,
        0x009B,
        0x0000,
        0x00FF,
        0x00FF,
        0x0032,
        0x0032,
        0x0032,
        0x0032,
    },
    {
        0x00FF,
        0x00FF,
        0x00FF,
        0x00FF,
        0x00FF,
        0x0064,
        0x00FF,
        0x00FF,
        0x0080,
        0x0080,
        0x0080,
        0x0032,
    },
};
static u8 D_86B0DD40[] = {
    0, 0xFF, 0, 0xE1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xFF, 0, 3, 0, 0x11, 0, 0x11, 0, 0x11, 0, 7,
};

static unk_D_86B0DD58 D_86B0DD58[20] = {
    { 0xA7, 47.5f, 30.0f }, { 0xA8, 47.5f, 30.0f }, { 0xA9, 47.5f, 30.0f }, { 0xAA, 47.5f, 30.0f },
    { 0xA5, 66.5f, 85.0f }, { 0xA5, 66.5f, 85.0f }, { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },
    { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },
    { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },
    { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },
};

static u8 D_86B0DE48[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x11, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
};

static unk_D_8690A610 D_86B0F9D0;
static unk_D_86002F58_004_000_000 D_86B0F9F0;
static unk_D_86002F58_004_000_000 D_86B0FA08;
static unk_D_86002F58_004_000_000 D_86B0FA20;
static u32 D_86B0FA38;
static Color_RGBA8_u32 D_86B0FA3C;
static u8 D_86B0FA40;
static s16 D_86B0FA42;
static s16 D_86B0FA44;
static s16 D_86B0FA46;
static f32 D_86B0FA48;
static void* D_86B0FA4C;
static unk_D_86B0FA50* D_86B0FA50;
static unk_D_86B0FA50* D_86B0FA54;
static unk_D_86B0FA50* D_86B0FA58;
static unk_D_86B0FA50* D_86B0FA5C;
static unk_D_86B0FA50* D_86B0FA60;
static s16 D_86B0FA64;
static s16 D_86B0FA66;
static s16 D_86B0FA68;
static f32 D_86B0FA6C;
static s32 D_86B0FA70;
static s32 D_86B0FA74;
unk_D_86B0FA78* D_86B0FA78;
unk_D_86B0FA7C* D_86B0FA7C;
static u8 D_86B0FA80[0xBE0];
unk_70D3A0 D_86B10660;
static unk_D_70B10 D_86B10670;
static unk_D_800AE540_0004* D_86B10690;
static unk_D_800AE540_1194* D_86B10694;

static u32 D_86B0DE5C[] = {
    0x0C00FFFF, 0x05000000,    0x0B00001E,  0x00000000,    0x014000F0,  0x0000000F,  0x00000000, 0x00000000,
    0x05000000, 0x0D000000,    0x05000000,  0x07000000,    &D_86B0F9D0, 0x14000000,  0x002D0019, 0xFFFFFF28,
    0x08000000, func_86B05CB0, 0x00000000,  0x14000000,    0x002D0019,  0x80808028,  0x08000000, func_86B05D18,
    0x00000000, 0x16646464,    0x0F000002,  0x05000000,    0x1F00FFFF,  0x00000000,  0x00000000, 0x00000000,
    0x00640064, 0x00640000,    0x08000000,  func_86B05D84, 0x00000000,  0x05000000,  0x07000000, &D_86B0F9F0,
    0x06000000, 0x06000000,    0x0F000003,  0x05000000,    0x1F00FFFF,  0x00000000,  0x00000000, 0x00000000,
    0x00640064, 0x00640000,    0x08000000,  func_86B05D84, 0x00000000,  0x05000000,  0x07000000, &D_86B0FA08,
    0x06000000, 0x06000000,    0x0F000002,  0x05000000,    0x1F00FFFF,  0x00000000,  0x00000000, 0x00000000,
    0x00640064, 0x00640000,    0x08000000,  func_86B05D84, 0x00000000,  0x05000000,  0x07000000, &D_86B0FA20,
    0x06000000, 0x06000000,    0x0F000003,  0x05000000,    0x0A000000,  &D_800AC840, 0x06000000, 0x0F000002,
    0x05000000, 0x0A000000,    &D_800AC858, 0x06000000,    0x09000000,  0x06000000,  0x06000000, 0x06000000,
    0x01000000,
};

s32 func_86B05CB0(s32 arg0, GraphNode* arg1) {
    unk_D_86002F34_alt18* ptr = (unk_D_86002F34_alt18*)arg1;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        func_800102A4(&D_8006F088->unk_60.at, &D_8006F088->unk_60.eye, &sp28, &sp26, &sp24);
        ptr->unk_1C = sp26 + 0x2000;
        ptr->unk_1E = sp24 - 0x2000;
    }

    return 0;
}

s32 func_86B05D18(s32 arg0, GraphNode* arg1) {
    unk_D_86002F34_alt18* ptr = (unk_D_86002F34_alt18*)arg1;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        func_800102A4(&D_8006F088->unk_60.at, &D_8006F088->unk_60.eye, &sp28, &sp26, &sp24);
        ptr->unk_1C = -0x2000 - sp26;
        ptr->unk_1E = sp24 + 0x6000;
    }

    return 0;
}

s32 func_86B05D84(s32 arg0, GraphNode* arg1) {
    unk_D_86002F58_004_000* ptr = (unk_D_86002F58_004_000*)arg1;

    if (arg0 == 2) {
        ptr->unk_03C.rgba = D_86B0FA3C.rgba;
    }

    return 0;
}

void func_86B05DA0(u8 arg0, u8 arg1, u8 arg2) {
    u8 v = arg0 & arg1 & arg2;

    D_86B0FA3C.r = arg0;
    D_86B0FA3C.g = arg1;
    D_86B0FA3C.b = arg2;

    if (v == 0xFF) {
        if (D_86B0F9D0.unk_00.unk_14 == 1) {
            D_86B0F9D0.unk_00.unk_01 |= 1;
        }
    } else {
        D_86B0F9D0.unk_00.unk_01 &= ~1;
    }
}

void func_86B05E18(void) {
    UNUSED s32 pad[2];
    u8* sp24;
    u8* temp_a1;
    u8* sp1C;

    temp_a1 = (u32)_70D3A0_ROM_START + (D_80075BCC[D_86B0FA78->unk_174] & 0xFFFFFF);
    sp24 = (u32)_70D3A0_ROM_START +
           ((((D_86B0FA78->unk_174 ^ 0) * sizeof(unk_D_70B10)) - sizeof(unk_D_70B10) + (u32)D_70B10) & 0xFFFFFF);
    sp1C = (u32)_70D3A0_ROM_START +
           (((D_86B0FA78->unk_174 * sizeof(unk_70D3A0)) - sizeof(unk_70D3A0) + (u32)D_70110) & 0xFFFFFF);

    func_80003B30(D_86B0FA80, temp_a1, temp_a1 + 0xBC0, 0);
    func_80003B30(&D_86B10660, sp1C, sp1C + sizeof(unk_70D3A0), 0);
    func_80003B30(&D_86B10670, sp24, sp24 + sizeof(unk_D_70B10), 0);
}

void func_86B05EE8(void) {
    D_86B0FA78->unk_174 = D_86B10690->unk_01C[D_86B0FA78->unk_17C].unk_00.unk_00;
    func_8001BB58(&D_86B0FA78->unk_004);
    func_8001987C();

    D_86B0FA78->unk_000 = func_80019D90(&D_86B10690->unk_01C[D_86B0FA78->unk_17C]);
    func_8001BC34(&D_86B0FA78->unk_004, 0, D_86B0FA78->unk_174, D_86B0FA78->unk_000->unk_08->unk_00[0]);
    func_8001BD04(&D_86B0FA78->unk_004, 0);
    D_86B0FA78->unk_004.unk_0A6 = 0;
    func_86B05E18();
    D_86B0FA78->unk_004.unk_024.y += D_86B10660.unk_08;
    D_86B0FA78->unk_170 = 0;
    func_80017804(&D_86B0FA78->unk_004, 0);
    func_8001BD9C(&D_86B0FA78->unk_004, -1);
}

void func_86B06008(void) {
    func_8001BCF0(&D_86B0FA78->unk_004);

    main_pool_pop_state('MONS');

    main_pool_push_state('MONS');

    func_86B05EE8();
}

void func_86B06050(void) {
    D_86B0FA7C->unk_00->unk_24.fovy = 30.0f;
    D_86B0FA7C->unk_00->unk_24.near = 30.0f;
    D_86B0FA7C->unk_00->unk_24.far = 6400.0f;
    func_86B087E8(D_86B0FA78, &D_86B0FA7C->unk_04);
    func_86B08AEC(&D_86B0E040[D_86B0FA78->unk_17C], D_86B0FA7C->unk_00);
    func_86B088E4();
}

void func_86B06100(void) {
    func_8001BCF0(&D_86B0FA78->unk_004);

    main_pool_pop_state('MONS');

    main_pool_push_state('MONS');

    D_86B0FA78->unk_174 = D_86B0DD58[D_86B0FA44].unk_00;
    func_8001BB58(&D_86B0FA78->unk_004);
    func_8001987C();
    D_86B0FA78->unk_000 = func_80019D18(D_86B0FA78->unk_174);
    func_8001BC34(&D_86B0FA78->unk_004, 0, D_86B0FA78->unk_174, D_86B0FA78->unk_000->unk_08->unk_00[0]);
    func_8001BD04(&D_86B0FA78->unk_004, 0);
    func_8000E88C(&D_86B0FA78->unk_004.unk_024, 0.0f, 300.0f, 0.0f);
}

void func_86B061E8(void) {
    D_86B0FA46 = 0;
    D_86B0FA48 = 0.0f;
    D_86B0FA7C->unk_00->unk_24.fovy = 40.0f;
    D_86B0FA7C->unk_00->unk_24.near = 30.0f;
    D_86B0FA7C->unk_00->unk_24.far = 6400.0f;

    func_8000E88C(&D_86B0FA7C->unk_00->unk_60.at, D_86B0FA78->unk_004.unk_024.x,
                  D_86B0DD58[D_86B0FA44].unk_04 + D_86B0FA78->unk_004.unk_024.y, D_86B0FA78->unk_004.unk_024.z);

    if ((D_86B0FA44 == 4) || (D_86B0FA44 == 5)) {
        func_8000E88C(&D_86B0FA7C->unk_00->unk_60.eye, 0, 100.0f, 328.0f);
    } else {
        func_8000E88C(&D_86B0FA7C->unk_00->unk_60.eye, 0, 100.0f, 250.0f);
    }
}

s32 func_86B0630C(unk_D_86002F58_004_000* arg0, s16 arg1, s16 arg2) {
    if (arg1 > 0) {
        arg0->unk_01E.y -= arg1;
        if ((arg0->unk_01E.y < arg2) && ((arg2 - arg1) < arg0->unk_01E.y)) {
            return 1;
        }
    } else {
        arg0->unk_01E.y -= arg1;
        if ((arg2 < arg0->unk_01E.y) && (arg0->unk_01E.y < (arg2 - arg1))) {
            return 1;
        }
    }
    return 0;
}

s32 func_86B06394(unk_D_86002F58_004_000* arg0, s16 arg1, s16 arg2) {
    if ((((arg0->unk_01E.y - arg2) / 182) < 0x3D) && (((arg0->unk_01E.y - arg2) / 182) >= 0)) {
        arg1 = (arg0->unk_01E.y - arg2) / 9;
    }
    arg0->unk_01E.y -= arg1;

    if (arg1 > 0) {
        if ((arg2 >= arg0->unk_01E.y) && (arg0->unk_01E.y >= (arg2 - arg1))) {
            arg0->unk_01E.y = arg2;
            return 1;
        }
    } else if ((arg0->unk_01E.y >= arg2) && ((arg2 - arg1) >= arg0->unk_01E.y)) {
        arg0->unk_01E.y = arg2;
        return 1;
    }
    return 0;
}

s32 func_86B06440(void) {
    if (D_86B0FA46 < 3) {
        if ((D_86B0FA46 <= 0) && (func_86B0630C(&D_86B0FA78->unk_004, 0x71C, 0) != 0)) {
            D_86B0FA46++;
        }

        if ((D_86B0FA46 > 0) && (func_86B06394(&D_86B0FA78->unk_004, 0x71C, 0) != 0)) {
            D_86B0FA46++;
        }
    }

    func_86B0145C(&D_86B0FA48, 0.1f, 0.02f);
    func_86B0145C(&D_86B0FA78->unk_004.unk_024.y, 0.0f, D_86B0FA48);

    if (D_86B0FA78->unk_004.unk_024.y <= 0.25f) {
        D_86B0FA78->unk_004.unk_024.y = 0.0f;
    }

    func_8000E88C(&D_86B0FA7C->unk_00->unk_60.at, D_86B0FA78->unk_004.unk_024.x,
                  D_86B0DD58[D_86B0FA44].unk_04 + D_86B0FA78->unk_004.unk_024.y, D_86B0FA78->unk_004.unk_024.z);

    if (D_86B0FA78->unk_004.unk_024.y <= 0.5f) {
        return 1;
    }
    return 0;
}

void func_86B065C4(void) {
    Vec3f sp44;

    if (D_86B0FA40 == 0) {
        D_86B0FA40 = 1;
        func_8004DF94(0x0110000F, 0, 0);
    }

    if (D_86B0FA78->unk_178 & 1) {
        func_8000E88C(&sp44, D_86B0FA78->unk_004.unk_024.x,
                      D_86B0DD58[D_86B0FA44].unk_08 + (func_86B01320(0x28) - 0x14), D_86B0FA78->unk_004.unk_024.z);
        func_81407D48(1.0f, sp44, D_86B0FA78->unk_004.unk_01E, func_879027F0, &D_87903E40, 1);

        if ((D_86B0FA78->unk_178 >= 0xA) && (D_86B0FA78->unk_178 & 1)) {
            func_8000E88C(&sp44, D_86B0FA78->unk_004.unk_024.x,
                          D_86B0DD58[D_86B0FA44].unk_08 + (func_86B01320(0x28) - 0x14), D_86B0FA78->unk_004.unk_024.z);
            func_81407D48(1.0f, sp44, D_86B0FA78->unk_004.unk_01E, func_879027F0, &D_87903E40, 1);
        }

        if ((D_86B0FA78->unk_178 >= 0x14) && (D_86B0FA78->unk_178 & 1)) {
            func_8000E88C(&sp44, D_86B0FA78->unk_004.unk_024.x,
                          D_86B0DD58[D_86B0FA44].unk_08 + (func_86B01320(0x28) - 0x14), D_86B0FA78->unk_004.unk_024.z);
            func_81407D48(1.0f, sp44, D_86B0FA78->unk_004.unk_01E, func_879027F0, &D_87903E40, 1);
        }

        if ((D_86B0FA78->unk_178 >= 0x1E) && (D_86B0FA78->unk_178 & 1)) {
            func_8000E88C(&sp44, D_86B0FA78->unk_004.unk_024.x,
                          D_86B0DD58[D_86B0FA44].unk_08 + (func_86B01320(0x28) - 0x14), D_86B0FA78->unk_004.unk_024.z);
            func_81407D48(1.0f, sp44, D_86B0FA78->unk_004.unk_01E, func_879027F0, &D_87903E40, 1);
        }
    }
}

void func_86B06960(void) {
    D_86B0FA78->unk_180 = func_800104AC(D_86B0FA78->unk_180, 100.0f, 2.0f, 2.0f);
    func_86B05DA0(D_86B0FA78->unk_180, D_86B0FA78->unk_180, D_86B0FA78->unk_180);
}

void func_86B069D8(void) {
    if (((D_86B0FA78->unk_178 % 50) == 0) && (D_86B0FA78->unk_170 == 0) && (D_86B0FA80[0xA51] != 0xFF)) {
        func_80017788(&D_86B0FA78->unk_004);
        func_8001BD9C(&D_86B0FA78->unk_004, D_86B0FA80[0xA51]);
        D_86B0FA78->unk_170 = 1;
    } else if ((D_86B0FA78->unk_170 == 1) && (func_8001783C(&D_86B0FA78->unk_004) == 1)) {
        D_86B0FA78->unk_170 = 0;
        func_80017804(&D_86B0FA78->unk_004, 0);
        func_8001BD9C(&D_86B0FA78->unk_004, -1);
    }
}

void func_86B06AB4(unk_D_86B0FA50* arg0, u8* arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5) {
    arg0->unk_80 = arg1;
    arg0->unk_98 = arg2;
    arg0->unk_9C = arg3;
    arg0->unk_9E = arg4;
    arg0->unk_A0 = arg5;

    arg0->unk_88 = 0;
    arg0->unk_8C = 0;
    arg0->unk_84 = 0;
    arg0->unk_A4 = 0;
    arg0->unk_AC = 0.0f;

    arg0->unk_B0.unk_00 = D_86B0DCE0->unk_00;
    arg0->unk_B0.unk_02 = D_86B0DCE0->unk_02;
    arg0->unk_B0.unk_04 = D_86B0DCE0->unk_04;
    arg0->unk_B0.unk_06 = D_86B0DCE0->unk_06;
    arg0->unk_B0.unk_08 = D_86B0DCE0->unk_08;
    arg0->unk_B0.unk_0A = D_86B0DCE0->unk_0A;
}

void func_86B06B38(void) {
    if (D_800AE540.unk_11F2 == 1) {
        func_86B06AB4(D_86B0FA60, &D_300C6D0, -250.0f, 0xC8, 0x18, 0x18);
    }

    func_86B06AB4(D_86B0FA54, &D_3000180, -250.0f, 0xC8, 0x40, 0x18);

    if (D_800AE540.unk_0002 == 0) {
        func_86B06AB4(D_86B0FA5C, &D_30060E0, -170.0f, 0x3C, 0x88, 0x14);
    } else if (D_800AE540.unk_0002 == 1) {
        func_86B06AB4(D_86B0FA5C, &D_3006B80, -170.0f, 0x3C, 0x78, 0x14);
    } else if (D_800AE540.unk_0002 == 2) {
        func_86B06AB4(D_86B0FA5C, &D_3004E20, -170.0f, 0x3C, 0x78, 0x14);
    } else if (D_800AE540.unk_0002 == 3) {
        func_86B06AB4(D_86B0FA5C, &D_3005780, -170.0f, 0x3C, 0x78, 0x14);
    }

    switch (D_800AE540.unk_0001) {
        case 1:
            func_86B06AB4(D_86B0FA58, &D_30024E0, -100.0f, 0x1E, 0xB0, 0x14);
            break;

        case 2:
            func_86B06AB4(D_86B0FA58, &D_30032A0, -100.0f, 0x1E, 0xB0, 0x14);
            break;

        case 3:
            func_86B06AB4(D_86B0FA58, &D_3004060, -100.0f, 0x1E, 0xB0, 0x14);
            break;

        case 4:
            func_86B06AB4(D_86B0FA58, &D_3000780, -100.0f, 0x1E, 0x88, 0x14);
            break;

        case 5:
            func_86B06AB4(D_86B0FA58, &D_3001220, -100.0f, 0x1E, 0x78, 0x14);
            break;

        case 6:
            func_86B06AB4(D_86B0FA58, &D_3001B80, -100.0f, 0x1E, 0x78, 0x14);
            break;

        default:
            func_86B06AB4(D_86B0FA58, &D_30024E0, -100.0f, 0x1E, 0xB0, 0x14);
            break;
    }
}

void func_86B06E34(void) {
    D_86B0FA78->unk_16C = 0;
    D_86B0FA78->unk_17C = 0;
    D_86B0FA78->unk_174 = 0;

    main_pool_push_state('MONS');

    func_86B05EE8();
}

void func_86B06E80(void) {
    D_86B0FA7C->unk_00 = D_87906050->unk_00.unk_0C;
    D_87906054 = D_86B0FA7C->unk_00;
    func_86B06050();
}

void func_86B06EC8(void) {
    D_86B0FA78->unk_16C = 6;
    D_86B0FA78->unk_17C = 6;
    D_86B0FA78->unk_174 = 0;

    main_pool_push_state('MONS');

    func_86B06100();
}

void func_86B06F18(void) {
    D_86B0FA7C->unk_00 = D_87906050->unk_00.unk_0C;
    D_87906054 = D_86B0FA7C->unk_00;
    func_86B061E8();
}

void func_86B06F60(void) {
    D_86B0FA50->unk_90 = 3;
}

void func_86B06F74(void) {
    if (D_800AE540.unk_1194[0].unk_1C == 1) {
        D_86B10690 = D_800AE540.unk_1194[0].unk_08[0];
        D_86B10694 = &D_800AE540.unk_1194[0];
    } else {
        D_86B10690 = D_800AE540.unk_1194[1].unk_08[0];
        D_86B10694 = &D_800AE540.unk_1194[1];
    }
}

void func_86B06FCC(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

s32 func_86B06FFC(void) {
    switch (D_86B0FA78->unk_16C) {
        case 0:
            func_86B06050();
            func_86B08C44(D_86B0FA7C->unk_00);
            D_86B0FA78->unk_170 = 0;
            D_86B0FA78->unk_16C += 1;
            break;

        case 1:
            func_86B069D8();
            if (D_86B0FA78->unk_178++ == 0x19) {
                D_86B0FA50->unk_90 = 0;
            }

            if (func_86B08C44(D_86B0FA7C->unk_00) != 0) {
                if ((D_800AE540.unk_0001 == 7) && (D_86B0FA78->unk_17C == 5)) {
                    return 1;
                }
                func_86B08E50(3, 0x1E);
                D_86B0FA78->unk_16C += 1;
            }
            break;

        case 2:
            func_86B08EB4();
            if (func_86B08EA8() == 1) {
                D_86B0FA78->unk_17C++;
                if (D_86B0FA78->unk_17C == 6) {
                    D_86B0FA78->unk_170 = 0;
                    func_86B06100();
                    func_86B061E8();
                    D_86B0FA50->unk_90 = 3;
                    D_86B0FA78->unk_178 = 0;
                    func_86B08E50(2, 0x1E);
                    D_86B0FA78->unk_16C = 6;
                } else {
                    D_86B0FA78->unk_170 = 0;
                    func_86B06008();
                    func_86B06050();
                    D_86B0FA50->unk_90 = 3;
                    D_86B0FA78->unk_178 = 0;
                    func_86B08E50(2, 0x1E);
                    D_86B0FA78->unk_16C++;
                }
            }
            break;

        case 3:
            func_86B08EB4();
            if (D_86B0FA78->unk_178++ > 0) {
                func_86B08C44(D_86B0FA7C->unk_00);
            }

            if (func_86B08EA8() == 0) {
                D_86B0FA78->unk_178 = 0;
                D_86B0FA78->unk_16C = 1;
            }
            break;

        case 6:
            D_86B0FA78->unk_180 = 0xFF;
            func_86B08EB4();
            func_86B06440();
            if (func_86B08EA8() == 0) {
                D_86B0FA78->unk_16C++;
            }
            break;

        case 7:
            if (func_86B06440() != 0) {
                D_86B0FA78->unk_178 = 0;
                D_86B0FA50->unk_90 = 0;
                func_8004DF94(0x01100002, 0, 0);
                D_86B0FA40 = 0;
                D_86B0FA78->unk_16C++;
            }
            break;

        case 8:
            if (D_86B0FA58->unk_84 != 0) {
                func_86B065C4();
            }
            if (D_86B0FA78->unk_178++ >= 0x41) {
                D_86B0FA64 = 0;
                func_800102A4(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, &D_86B0FA6C, &D_86B0FA66, &D_86B0FA68);
                D_86B0FA78->unk_16C++;
            }
            break;

        case 9:
            func_86B06960();

            if (D_86B0FA58->unk_84 != 0) {
                func_86B065C4();
            }

            if (gPlayer1Controller->buttonDown & 0xC000) {
                return 1;
            }

            if (D_86B0FA78->unk_178++ >= 0x3E9) {
                D_86B0FA78->unk_178 = 0x64;
            }

            D_86B0FA64 = func_8001046C(D_86B0FA64, 0x3C, 1, 1);
            D_86B0FA68 += D_86B0FA64;
            func_80010354(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, D_86B0FA6C, D_86B0FA66, D_86B0FA68);
            break;
    }

    if ((D_86B0FA74 == 2) && (D_86B0FA70 == 0x12C)) {
        func_8004B1CC(0x5B);
    }
    return 0;
}

s32 func_86B07450(unk_D_86B0FA50* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 temp_fa1;
    f32 sp20;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_4;
    f32* new_var;

    sp20 = arg0->unk_A4;

    temp_fv0 = func_800104AC(sp20, 0.0f, 0.0f, 0.0f);
    arg0->unk_A4 = temp_fv0;
    if (temp_fv0 >= 0.0f) {
        temp_fv0 = 0;
        if ((arg0 && arg0) && arg0) {}
    }
    temp_fv0_2 = COSS(0) * temp_fv0;
    temp_fa1 = -arg3;

    new_var = &arg0->unk_AC;

    temp_fv0_4 = (-temp_fa1) - (arg2 * ((sp20 * arg0->unk_AC) + temp_fv0_2));
    arg0->unk_AC = (temp_fv0_4 * arg5) + ((*new_var) + temp_fv0_2);

    if (arg0->unk_AC >= 28.0) {
        arg0->unk_AC = 28.0f;
    }

    arg0->unk_98 += arg0->unk_AC;
    if (temp_fa1 >= 0) {
        if ((arg0->unk_98 < arg4) && (arg0->unk_98 >= 0.0f)) {
            arg0->unk_98 = arg4;
            arg0->unk_AC *= -arg1;
        }
    } else if ((arg4 < arg0->unk_98) && (arg0->unk_98 >= 0.0f)) {
        arg0->unk_98 = arg4;
        arg0->unk_AC *= -arg1;
        if (arg0->unk_A8 == arg0->unk_AC) {
            return 1;
        }
        arg0->unk_A8 = arg0->unk_AC;
    }

    return 0;
}

void func_86B075EC(void) {
    if (D_86B0FA78->unk_17C == 6) {
        switch (D_86B0FA50->unk_90) {
            case 3:
                break;

            case 0:
                func_86B06B38();
                D_86B0FA50->unk_90++;
                break;

            case 1:
                func_86B07450(D_86B0FA54, 0.25f, 0.0f, 3.0f, 0xA3 - (D_86B0FA54->unk_9E / 2), 1.7f);
                func_86B09928(D_86B0FA54->unk_80, D_86B0FA54->unk_98, D_86B0FA54->unk_9C, D_86B0FA54->unk_9E,
                              D_86B0FA54->unk_A0, &D_86B0FA54->unk_B0);
                D_86B0FA58->unk_84 =
                    func_86B07450(D_86B0FA58, 0.25f, 0.0f, 3.0f, 0xA3 - (D_86B0FA58->unk_9E / 2), 1.7f);
                func_86B09928(D_86B0FA58->unk_80, D_86B0FA58->unk_98, D_86B0FA58->unk_9C, D_86B0FA58->unk_9E,
                              D_86B0FA58->unk_A0, &D_86B0FA54->unk_B0);

                if (D_800AE540.unk_11F2 == 1) {
                    func_86B09AD8(D_86B0FA60->unk_80, (s16)D_86B0FA58->unk_98 + D_86B0FA58->unk_9E,
                                  D_86B0FA58->unk_9C - 2, D_86B0FA60->unk_9E, D_86B0FA60->unk_A0);
                }

                if ((D_86B0FA44 != 4) && (D_86B0FA44 != 5)) {
                    func_86B07450(D_86B0FA5C, 0.25f, 0.0f, 3.0f, 0xA3 - (D_86B0FA5C->unk_9E / 2), 1.7f);
                    func_86B09928(D_86B0FA5C->unk_80, D_86B0FA5C->unk_98, D_86B0FA5C->unk_9C, D_86B0FA5C->unk_9E,
                                  D_86B0FA5C->unk_A0, &D_86B0FA54->unk_B0);
                }

                if (D_86B0FA58->unk_84 != 0) {
                    D_86B0FA54->unk_B0.unk_00 = func_8001046C(
                        D_86B0FA54->unk_B0.unk_00, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_00,
                        D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_0C, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_0C);
                    D_86B0FA54->unk_B0.unk_02 = func_8001046C(
                        D_86B0FA54->unk_B0.unk_02, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_02,
                        D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_0E, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_0E);
                    D_86B0FA54->unk_B0.unk_04 = func_8001046C(
                        D_86B0FA54->unk_B0.unk_04, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_04,
                        D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_10, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_10);
                    D_86B0FA54->unk_B0.unk_06 = func_8001046C(
                        D_86B0FA54->unk_B0.unk_06, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_06,
                        D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_12, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_12);
                    D_86B0FA54->unk_B0.unk_08 = func_8001046C(
                        D_86B0FA54->unk_B0.unk_08, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_08,
                        D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_14, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_14);
                    D_86B0FA54->unk_B0.unk_0A = func_8001046C(
                        D_86B0FA54->unk_B0.unk_0A, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_0A,
                        D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_16, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_16);
                    if ((D_86B0FA54->unk_B0.unk_00 == D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_00) &&
                        (D_86B0FA54->unk_B0.unk_02 == D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_02) &&
                        (D_86B0FA54->unk_B0.unk_04 == D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_04) &&
                        (D_86B0FA54->unk_B0.unk_06 == D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_06) &&
                        (D_86B0FA54->unk_B0.unk_08 == D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_08) &&
                        (D_86B0FA54->unk_B0.unk_0A == D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_0A)) {

                        D_86B0FA54->unk_88++;
                        if (D_86B0FA54->unk_88 == 4) {
                            D_86B0FA50->unk_90++;
                        }
                    }
                }
                break;

            case 2:
                func_86B09928(D_86B0FA54->unk_80, D_86B0FA54->unk_98, D_86B0FA54->unk_9C, D_86B0FA54->unk_9E,
                              D_86B0FA54->unk_A0, D_86B0DD40);
                func_86B09928(D_86B0FA58->unk_80, D_86B0FA58->unk_98, D_86B0FA58->unk_9C, D_86B0FA58->unk_9E,
                              D_86B0FA58->unk_A0, D_86B0DD40);

                if (D_800AE540.unk_11F2 == 1) {
                    func_86B09AD8(D_86B0FA60->unk_80, (s16)D_86B0FA58->unk_98 + D_86B0FA58->unk_9E,
                                  D_86B0FA58->unk_9C - 2, D_86B0FA60->unk_9E, D_86B0FA60->unk_A0);
                }

                if ((D_86B0FA44 != 4) && (D_86B0FA44 != 5)) {
                    func_86B09928(D_86B0FA5C->unk_80, D_86B0FA5C->unk_98, D_86B0FA5C->unk_9C, D_86B0FA5C->unk_9E,
                                  D_86B0FA5C->unk_A0, D_86B0DD40);
                }
                break;
        }
    } else {
        switch (D_86B0FA50->unk_90) {
            case 3:
                break;

            case 0:
                D_86B0FA50->unk_98 = -80.0f;
                D_86B0FA50->unk_9C = 0xB4;
                D_86B0FA50->unk_A4 = 0.0f;
                D_86B0FA50->unk_AC = 0.0f;
                sprintf(D_86B0FA50->unk00, "%s", D_86B10690->unk_01C[D_86B0FA78->unk_17C].unk_30);
                D_86B0FA50->unk_90++;
                break;

            case 1:
                func_8001F3F4();
                func_8001F470();
                func_8001EBE0(0x10, 0);
                func_8001F36C(0, 0x82, 0xFF, 0xFF);
                func_8001F324(0xC8, 0xFF, 0xFF, 0xFF);
                func_86B07450(D_86B0FA50, 0.35f, 0.0f, 4.0f, 160.0f, 1.4f);
                func_8001F1E8((s32)D_86B0FA50->unk_98 - (func_8001F5B0(0x10, 0, D_86B0FA50->unk00) / 2),
                              D_86B0FA50->unk_9C, D_86B0FA50->unk00);
                func_8001F4C4();
                func_8001F444();
                break;
        }
    }

    func_86B095C4();
}

void func_86B07DF4(void) {
    func_800079C4();

    if ((D_86B0FA38 == -1) || (D_86B0FA38 == 0)) {
        func_8000699C(&gDisplayListHead, 1);
    } else if (D_86B0FA38 < 0x10000) {
        func_8000699C(&gDisplayListHead, D_86B0FA38);
    } else {
        func_8000699C(&gDisplayListHead, 0xA6BF);
    }

    func_80015348();
    func_80015094(&D_87906050->unk_00);
    func_86B075EC();
    func_87901C98();
    func_80007778();
}

void func_86B07EA0(void) {
    func_800079C4();
    func_8000699C(&gDisplayListHead, 1);
    func_80015348();
    func_80015094(&D_87906050->unk_00);
    func_8001F504(0, 0, 0x140, 0xF0, 0, 0, 0, 0xFF);
    func_80007778();
}

void func_86B07F14(void) {
    s32 i;

    for (i = 0; i < 18; i++) {
        func_86B06FCC();

        if (i < 3) {
            func_80007990(1);
            func_80006C6C(0x10);
            func_86B07EA0();
        }
    }

    if (D_86B0FA74 == 2) {
        func_8004B1CC(0x44);
    } else {
        func_8004B1CC(8);
    }
}

void func_86B07FA4(void) {
    s32 var_s0 = 1;
    void (*temp_s2)(void) = (void*)Util_ConvertAddrToVirtAddr(func_8140C734);

    D_86B0FA70 = 0;
    while (var_s0 != 0) {
        D_86B0FA70++;

        func_86B06FCC();
        func_87901C20();

        if (func_86B06FFC() != 0) {
            var_s0 = 0;
        }

        temp_s2();
        func_86B07DF4();
    }
}

void func_86B08034(void) {
    s32 i;
    s32 var_s1;
    void (*temp_s2)(void) = Util_ConvertAddrToVirtAddr(func_8140C734);

    if (D_800AE540.unk_0001 == 7) {
        for (i = 0; i < 100; i++) {
            func_86B06FCC();
            func_87901C20();

            temp_s2();

            func_86B07DF4();
        }
    }

    if (D_800AE540.unk_0001 == 7) {
        var_s1 = 0x64;
    } else {
        var_s1 = 0xA;
    }

    func_80006CB4(var_s1);
    func_8004B9C4(var_s1 - 2);

    for (i = 0; i < var_s1; i++) {
        if (D_800AE540.unk_0001 == 7) {
            func_86B06FCC();
            func_87901C20();
            temp_s2();
            func_86B07DF4();
        } else {
            func_86B06FCC();
            func_87901C20();
            func_86B06FFC();
            temp_s2();
            func_86B07DF4();
        }
    }

    if (D_800AE540.unk_0001 == 7) {
        for (i = 0; i < 30; i++) {
            func_86B06FCC();
            func_87901C20();

            temp_s2();

            func_86B07DF4();
        }
    }
}

void func_86B0819C(void) {
    MemoryBlock* sp34;
    UNUSED s32 pad;
    FragmentEntry sp2C;
    void* temp_v0_3;
    unk_D_8690A610_018* temp_v0_6;

    D_86B0FA42 = D_86B0DE48[D_800AE540.unk_0001];
    if (D_800AE540.unk_0001 == 7) {
        D_86B0FA42 += D_800AE540.unk_0002;
    }

    switch (D_800AE540.unk_0001) {
        case 1:
            D_86B0FA44 = 4;
            break;

        case 2:
            D_86B0FA44 = 4;
            break;

        case 3:
            D_86B0FA44 = D_800AE540.unk_0002;
            break;

        case 4:
            D_86B0FA44 = 5;
            break;

        case 5:
            D_86B0FA44 = 5;
            break;

        case 6:
            D_86B0FA44 = D_800AE540.unk_0002;
            break;

        default:
            D_86B0FA44 = 0;
            break;
    }

    sp2C = func_8000484C(func_800044F4(stadium_models_ROM_START, _5C7A70_ROM_START, 1, 1), D_86B0FA42);

    D_86B0FA4C = sp2C(2, 0);
    func_800113F8(0, &D_86B0F9D0, 0x3C0, 0x3E8, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001103C(NULL, &D_86B0F9F0);
    func_8001103C(NULL, &D_86B0FA08);
    func_8001103C(NULL, &D_86B0FA20);
    sp34 = func_80002D10(main_pool_get_available(), 0);
    D_87906050 = process_geo_layout(sp34, D_86B0DE5C);

    temp_v0_3 = sp2C(0, 0);
    if (temp_v0_3 != NULL) {
        func_80012094(&D_86B0F9F0, process_geo_layout(sp34, temp_v0_3));
    }

    temp_v0_3 = sp2C(1, 0);
    if (temp_v0_3 != NULL) {
        func_80012094(&D_86B0FA08, process_geo_layout(sp34, temp_v0_3));
    }

    temp_v0_3 = sp2C(3, 0);
    if (temp_v0_3 != NULL) {
        func_80012094(&D_86B0FA20, process_geo_layout(sp34, temp_v0_3));
    }

    D_86B0FA38 = sp2C(2, 0);
    func_80002D60(sp34);

    temp_v0_6 = sp2C(4, 0);
    if (temp_v0_6 == NULL) {
        D_86B0F9D0.unk_00.unk_14 = 0;
        D_86B0F9D0.unk_00.unk_01 &= ~1;
    } else {
        D_86B0F9D0.unk_18.unk_00 = temp_v0_6->unk_00;
        D_86B0F9D0.unk_18.unk_02 = temp_v0_6->unk_02;
        D_86B0F9D0.unk_18.unk_04.rgba = temp_v0_6->unk_04.rgba;
        D_86B0F9D0.unk_00.unk_14 = 1;
    }

    func_8001BB20();
    func_86B05DA0(0xFF, 0xFF, 0xFF);
    func_87901620();

    D_86B0FA78 = main_pool_alloc(sizeof(unk_D_86B0FA78), 0);
    bzero(D_86B0FA78, sizeof(unk_D_86B0FA78));

    D_86B0FA7C = main_pool_alloc(sizeof(unk_D_86B0FA7C), 0);
    bzero(D_86B0FA7C, sizeof(unk_D_86B0FA7C));

    D_86B0FA50 = main_pool_alloc(sizeof(unk_D_86B0FA50), 0);
    bzero(D_86B0FA50, sizeof(unk_D_86B0FA50));

    D_86B0FA54 = main_pool_alloc(sizeof(unk_D_86B0FA50), 0);
    bzero(D_86B0FA54, sizeof(unk_D_86B0FA50));

    D_86B0FA58 = main_pool_alloc(sizeof(unk_D_86B0FA50), 0);
    bzero(D_86B0FA58, sizeof(unk_D_86B0FA50));

    D_86B0FA5C = main_pool_alloc(sizeof(unk_D_86B0FA50), 0);
    bzero(D_86B0FA5C, sizeof(unk_D_86B0FA50));

    D_86B0FA60 = main_pool_alloc(sizeof(unk_D_86B0FA50), 0);
    bzero(D_86B0FA60, sizeof(unk_D_86B0FA50));

    func_86B06F74();

    switch (D_800AE540.unk_0001) {
        case 1:
        case 2:
        case 4:
        case 5:
        case 7:
            func_86B06E34();
            func_86B06E80();
            func_86B06F60();
            D_86B0FA74 = 0;
            break;

        default:
            if (D_800AE540.unk_0002 == 3) {
                D_86B0FA74 = 1;
                func_86B06E34();
                func_86B06E80();
                func_86B06F60();
            } else {
                D_86B0FA74 = 2;
                func_86B06EC8();
                func_86B06F18();
                func_86B06F60();
            }
            break;
    }
}

s32 func_86B08644(void) {
    unk_func_80007444* sp24;

    main_pool_push_state('DEMO');

    func_80005E40(0x10000, 0);
    sp24 = func_80007444(0, 1, 3, 1, 2, 1);
    func_8001E94C(0x10, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, cup_clear_ui, 0);

    FRAGMENT_LOAD(fragment31);

    func_86B0819C();
    func_80007678(sp24);
    func_86B07F14();
    func_86B07FA4();
    func_86B08034();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('DEMO');

    return 0;
}
