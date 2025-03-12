#include "fragment24.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/22630.h"
#include "src/29BA0.h"
#include "src/2D340.h"
#include "src/2E110.h"
#include "src/2E460.h"
#include "src/49790.h"
#include "src/hal_libc.h"
#include "src/memmap.h"
#include "src/memory.h"

static u8 D_88317360[] = {
    0x5F, 0x45, 0x21, 0x12, 0x51, 0x58, 0x2A, 0x43, 0x96, 0x6F, 0x9C, 0x36, 0x66, 0x8D, 0x19, 0x37, 0xA1, 0xA0, 0x2F,
    9,    0x77, 0x9D, 0x83, 0x1E, 0x50, 0x44, 0x6D, 0x6E, 0x3A, 0x3C, 0x31, 0x3D, 0x8E, 0xC,  0xA3, 0x90, 0x92, 0x20,
    0x8F, 0x5D, 0x9B, 0x5B, 0x49, 0xA,  0x34, 0x6A, 0x74, 0x8A, 0x7F, 0x1C, 1,    0x27, 0x2D, 0x56, 0x9E, 0x3E, 0x8B,
    0x42, 0xB,  0x60, 0x10, 5,    0x3F, 0x59, 0x24, 0x87, 0x4D, 0x17, 0x71, 0x84, 0,    0x4F, 0x48, 0x35, 0x65, 0x7E,
    0x5E, 0x86, 0x79, 0x5A, 0x85, 0x22, 0x2B, 0x97, 0x95, 0x94, 0x93, 0x6C, 0x25, 0x2C, 0x1B, 0x98, 0x14, 0x61, 0x41,
    0x4E, 3,    0x63, 0x64, 0x91, 0x57, 0x53, 0x70, 0x1F, 0x67, 0x38, 0x54, 0x7C, 0x13, 0xA2, 0x1A, 7,    0x4B, 0x39,
    0x68, 0x30, 8,    0x52, 0x55, 0x72, 0x26, 0x4A, 0x7B, 0x7A, 0xD,  0x29, 0x9F, 0x11, 0x8C, 0x75, 0x80, 0x15, 4,
    0x46, 0x7D, 0x3B, 0x33, 0x23, 0x5C, 6,    0x47, 0x4C, 0x76, 0x99, 0xF,  0x1D, 0x82, 0x2E, 0x62, 0x81, 2,    0x18,
    0x28, 0x32, 0xE,  0x69, 0x6B, 0x40, 0x73, 0x16, 0x9A, 0x89, 0x78, 0x88,
};

void func_88309160(s32 arg0, s32 arg1, unk_func_88309160_arg2* arg2, s32 arg3, u32 arg4,
                   unk_func_88200FA0_030_030* arg5) {
    static Color_RGBA8 D_88317404[] = {
        { 0xF0, 0xF0, 0xF0, 0xFF },
        { 0xF0, 0xF0, 0xF0, 0x4D },
    };

    Color_RGBA8 sp3C;
    UNUSED s32 pad;
    ret_func_8002ED08* sp34;
    s32 new_var;
    s32 var_v0;
    char* sp28;
    s32 var_v1;
    unk_D_80072B00* temp_v0_2;

    if (arg2 != NULL) {
        sp34 = func_8002ED08(arg2->unk_00);
        if (sp34 == NULL) {
            sp28 = "???????";
        } else {
            sp28 = func_8002D7C0(NULL, 0, D_8831A4CC, arg2->unk_00 - 1);
        }

        sp3C = D_88317404[(arg4 & 4) ? 1 : 0];

        func_8001F3F4();
        func_8001F324(sp3C.r, sp3C.g, sp3C.b, sp3C.a);
        func_8001EBE0(8, 0);
        func_8001F1E8(arg0 + 8, arg1 + 4, sp28);
        func_8001F444();

        if (sp34 != NULL) {
            temp_v0_2 = func_8002ED40(arg2->unk_00);

            var_v1 = temp_v0_2->unk_05 / 5;
            if (var_v1 >= 7) {
                var_v1 = 7;
            }

            new_var = temp_v0_2->unk_05 + (var_v1 * (arg2->unk_04 >> 6));
            func_8002E5A0((arg5->unk_00.unk_14.unk_00 + arg0) - 0x19, arg1 + 0xC, new_var, 2);
        }
    }
}

void func_883092C8(unk_func_8830867C_04C_078* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    static Color_RGBA8 D_8831740C = { 0xA0, 0x96, 0x64, 0xFF };

    UNUSED s32 pad;
    s32 sp58;
    UNUSED s32 pad2[2];
    s32 sp4C;
    s32 temp_v1;
    unk_func_885012A4* sp44;

    temp_v1 = func_8001F5B0(8, 0, "WWWWWWWWWWWW") + 0x29;
    sp58 = temp_v1;
    sp4C = temp_v1;
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8830867C_04C_078));

    arg0->unk_00.unk_20 = func_88309728;
    arg0->unk_00.unk_10.unk_00 = (arg2 - sp4C) - 8;
    arg0->unk_00.unk_10.unk_02 = arg1;

    arg0->unk_2C = mem_pool_alloc(arg3, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, sp4C, 0x78);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    sp44 = mem_pool_alloc(arg3, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp44, 0, 0, sp4C, 0x78, D_8831740C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp44);

    arg0->unk_30 = mem_pool_alloc(arg3, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_30, 0, 4, func_88309160, sp58, 0x1C, 4, 1, arg3);
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_30, 4, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp44, arg0->unk_30);
}

void func_883094CC(unk_func_8830867C_04C_078* arg0, unk_func_80026268_arg0* arg1) {
    s32 i;
    s32 temp_v0;
    s32 sp34;

    temp_v0 = func_8002ECDC(arg1);
    if ((temp_v0 - 1) >= arg0->unk_30->unk_38) {
        sp34 = arg0->unk_30->unk_38;
    } else {
        sp34 = (temp_v0 - 1);
    }

    for (i = 0; i < temp_v0; i++) {
        arg0->unk_44[i].unk_00 = arg1->unk_09[i];
        arg0->unk_44[i].unk_04 = arg1->unk_20[i];
    }

    func_8002C740(&arg0->unk_34, arg0->unk_44, 8, 4, temp_v0);
    ((func885063B8)Memmap_GetFragmentVaddr(func_885063B8))(arg0->unk_30, &arg0->unk_34);
    ((func88506BFC)Memmap_GetFragmentVaddr(func_88506BFC))(arg0->unk_30, sp34);
}

typedef struct unk_func_88309614 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ s32 unk_08;
} unk_func_88309614; // size >= 0xC

void func_88309614(unk_func_8830867C_04C_078* arg0) {
    s32 i;

    for (i = 0; i < ((unk_func_88309614*)arg0->unk_30->unk_2C)->unk_08; i++) {
        if ((func_8002ED08(arg0->unk_44[i].unk_00) == NULL) || (arg0->unk_44[i].unk_04 >= 0xC0)) {
            arg0->unk_30->unk_34[i] |= 4;
        }
    }
}

void func_883096BC(unk_func_8830867C_04C_078* arg0) {
    static s32 D_88317410[] = { 0xF, 0x13, 0x39, 0x46, 0x94 };

    s32 j;
    s32 i;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            if (*(s32*)&arg0->unk_44[i].unk_00 == D_88317410[j]) {
                arg0->unk_30->unk_34[i] |= 4;
                break;
            }
        }
    }
}

s32 func_88309728(unk_func_8830867C_04C_078* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void func_88309774(unk_func_8830867C_04C_078* arg0) {
    ((func88506CE4)Memmap_GetFragmentVaddr(func_88506CE4))(arg0->unk_30);

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);
}

void func_883097D4(unk_func_8830867C_04C_078* arg0) {
    arg0->unk_2C->unk_2C = 0xB;
}

void func_883097E4(void) {
}

s32 func_883097EC(unk_func_8830867C_034_03C_038_02C_000* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_08 != 0) {
        var_v1 = 2;
    }
    return var_v1;
}

void func_88309808(void) {
}

void func_88309810(unk_func_8830867C_034_03C* arg0) {
    s32 i;
    s32 j;
    unk_func_8830867C_034_03C_038* temp_s3;
    unk_func_8830867C_034_03C_038_02C_000* var_s0;

    for (i = 0; i < 2; i++) {
        temp_s3 = arg0->unk_38[i];
        var_s0 = temp_s3->unk_2C->unk_00;

        for (j = 0; j < temp_s3->unk_2C->unk_08; j++, var_s0++) {
            temp_s3->unk_34[j] |= func_883097EC(var_s0);
        }
    }
}

void func_883098D0(unk_func_8830867C_034_03C* arg0, s32 arg1) {
    s32 i;
    s32 var_v0;
    unk_func_8830867C_034_03C_038* temp_a1;

    if (arg1 != 0) {
        var_v0 = 2;
    } else {
        var_v0 = 0;
    }

    if (arg0->unk_34->unk_2C != 0) {
        temp_a1 = arg0->unk_38[arg0->unk_34->unk_2C - 1];

        for (i = 0; i < temp_a1->unk_2C->unk_08; i++) {
            temp_a1->unk_34[i] &= ~2;
            temp_a1->unk_34[i] |= var_v0;
        }
    }
}

void func_88309960(unk_func_8830867C_034_03C* arg0) {
    s32 i;
    s32 j;
    unk_func_8830867C_034_03C_038* temp_v0;
    unk_func_8830867C_034_03C_038_02C_000* ptr;

    for (i = 0; i < 2; i++) {
        temp_v0 = arg0->unk_38[i];
        ptr = temp_v0->unk_2C->unk_00;
        for (j = 0; j < temp_v0->unk_2C->unk_08; j++, ptr++) {
            ptr->unk_08 = (temp_v0->unk_34[j] & 2) != 0;
        }
    }
}

void func_883099D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_8002E8E4(arg0, arg1, arg2, 2);
    func_8002E8E4(arg0 + 0x1B, arg1, arg3, 2);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    gDPLoadTextureBlock(gDisplayListHead++, D_4006A60, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 10, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, (arg0 + 0x12) << 2, (arg1 + 2) << 2, (arg0 + 0x1A) << 2, (arg1 + 0xC) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
}

void func_88309C38(s32 arg0, s32 arg1, unk_func_88309C38_arg2* arg2, s32 arg3, s32 arg4,
                   unk_func_8830867C_034_03C_038* arg5) {
    static Color_RGBA8 D_88317424 = { 0xB2, 0xFF, 0xC3, 0xFF };
    static Color_RGBA8 D_88317428 = { 0xF0, 0xF0, 0xF0, 0xFF };

    UNUSED s32 pad;
    char* sp38;
    char sp34[4];
    UNUSED s32 pad2;
    s32 sp2C;
    s32 sp28;

    sp38 = func_8002D7C0(NULL, 0, D_8831A4C4, 0x5F);
    if (arg4 & 2) {
        func_8002D8C8(&D_800758E0, arg0 + 8, arg1 + 2);
    } else {
        func_8002D8C8(&D_800758F0, arg0 + 8, arg1 + 2);
    }

    func_8001F3F4();
    func_8001F324(D_88317428.r, D_88317428.g, D_88317428.b, D_88317428.a);
    func_8001EBE0(8, 0);
    func_8001F1E8(arg0 + 0x2C, arg1 + 2, sp38);

    sprintf(sp34, "%d", arg3 + 1);

    sp28 = func_8001F5B0(0, 0, " 00");
    sp2C = func_8001F5B0(0, 0, sp38);

    func_8001F1E8(((arg0 + sp2C + sp28) - func_8001F5B0(0, 0, sp34)) + 0x2C, arg1 + 2, sp34);
    func_8001F444();
    func_883099D8((arg5->unk_00.unk_14.unk_00 + arg0) - 0x35, arg1 + 8, arg2->unk_18, arg2->unk_14);
}

s32 func_88309DC8(void) {
    UNUSED s32 pad[2];
    s32 sp1C = func_8001F5B0(8, 0, func_8002D7C0(NULL, 0, D_8831A4C4, 0x5F));
    s32 sp20 = func_8001F5B0(8, 0, " 00");

    return sp1C + sp20 + 0x3D;
}

void func_88309E28(unk_func_8830867C_034_03C* arg0, s32 arg1, s32 arg2, s32 arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_8831742C = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88317430 = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317434 = { 0xA0, 0x96, 0x64, 0xFF };

    s32 pad2;
    s32 pad3;
    s32 tmp = arg3 * 0x18;
    s32 sp80;
    s32 temp_v0;
    s32 sp78;
    unk_func_8850B254* sp74;
    unk_func_8850878C* sp70;
    char* sp6C;
    unk_func_885012A4* sp68;
    unk_func_88001300_000* sp64;
    unk_func_8830867C_034_034* sp60;
    unk_func_8830867C_034_034* sp5C;

    temp_v0 = func_88309DC8();
    sp80 = temp_v0 + 0x34;
    sp78 = temp_v0 + 0x46;
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8830867C_034_03C));

    arg0->unk_00.unk_20 = func_8830A474;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, sp78, tmp + 0x20);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    sp74 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(func_8850B254))(sp74, 0, 0, sp78, 0x14, D_8831742C, D_88317430);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp74);

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(func_88500994))(arg0->unk_30, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp74, arg0->unk_30);

    sp70 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp70, 0, 0, "", 8);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_30, sp70);
    sp6C = func_8002D7C0(NULL, 0, D_8831A4C4, 0x60);

    sp70 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(
        sp70, (arg0->unk_2C->unk_00.unk_14.unk_00 - func_8001F5B0(8, 0, sp6C)) / 2, 0, sp6C, 8);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_30, sp70);
    sp6C = func_8002D7C0(NULL, 0, D_8831A4C4, 0x61);

    sp70 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(
        sp70, (arg0->unk_2C->unk_00.unk_14.unk_00 - func_8001F5B0(8, 0, sp6C)) / 2, 0, sp6C, 8);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_30, sp70);

    sp68 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp68, 0, 0x18, sp78, tmp + 8, D_88317434);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp68);

    arg0->unk_34 = mem_pool_alloc(arg4, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(func_88500994))(arg0->unk_34, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp68, arg0->unk_34);

    sp64 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(sp64, 0x2C);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_34, sp64);

    arg0->unk_38[0] = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_034_03C_038));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_38[0], 0x12, 4, func_88309C38, sp80, 0x18, arg3, 1,
                                                           arg4);
    arg0->unk_38[0]->unk_00.unk_28 |= 0x100;
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_38[0], arg3, arg4);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_34, arg0->unk_38[0]);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_034_034));
    func_8830A578(sp60, -0x10, 8, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_38[0]->unk_44, sp60);

    arg0->unk_38[1] = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_034_03C_038));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_38[1], 0x12, 4, func_88309C38, sp80, 0x18, arg3, 1,
                                                           arg4);
    arg0->unk_38[1]->unk_00.unk_28 |= 0x100;
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_38[1], arg3, arg4);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_34, arg0->unk_38[1]);

    sp5C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_034_034));
    func_8830A578(sp5C, -0x10, 8, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_38[1]->unk_44, sp5C);
}

void func_8830A410(unk_func_8830867C_034_03C* arg0, unk_func_8830867C_034_03C_038_02C* arg1,
                   unk_func_8830867C_034_03C_038_02C* arg2) {
    ((func885063B8)Memmap_GetFragmentVaddr(func_885063B8))(arg0->unk_38[0], arg1);
    ((func885063B8)Memmap_GetFragmentVaddr(func_885063B8))(arg0->unk_38[1], arg2);
    func_88309810(arg0);
}

s32 func_8830A474(unk_func_8830867C_034_03C* arg0, Controller* arg1) {
    s32 var_v1 = 0;
    unk_func_8830867C_034_03C_038* sp18;

    if (arg0->unk_2C->unk_30 & 2) {
        if (arg0->unk_34->unk_2C != 0) {
            sp18 = arg0->unk_38[arg0->unk_34->unk_2C - 1];
            var_v1 = sp18->unk_00.unk_20(sp18, arg1);
            if ((var_v1 == 0) && (gPlayer1Controller->buttonPressed & 0x8000)) {
                sp18->unk_34[sp18->unk_38] ^= 2;
                var_v1 = 0x80000004;
            }
        }
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void func_8830A520(unk_func_8830867C_034_03C* arg0, s32 arg1) {
    ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_30, arg1);
    ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_34, arg1);
}

void func_8830A578(unk_func_8830867C_034_034* arg0, s32 arg1, s32 arg2, s32 arg3) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8830867C_034_034));
    arg0->unk_00.unk_18 = func_8830A5E4;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_30 = arg3;
}

s32 func_8830A5E4(unk_func_8830867C_034_034* arg0, s32 arg1, s32 arg2) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPLoadTextureBlock(gDisplayListHead++, (arg0->unk_30 != 0) ? D_883186E8 : D_88318530, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                        12, 18, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                        G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, arg1 << 2, arg2 << 2, (arg1 + 0xA) << 2, (arg2 + 0x11) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
    gDPPipeSync(gDisplayListHead++);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);

    return 0;
}

s32 func_8830A840(unk_func_8830867C_02C_144_000* arg0) {
    s32 i;
    s32 var_v1 = 0;
    unk_func_8830867C_02C_0CC_000_000* ptr = arg0->unk_0C;

    for (i = 0; i < arg0->unk_14; i++) {
        if (ptr[i].unk_08 != 0) {
            var_v1 |= 2;
        }
    }

    return var_v1;
}

void func_8830A88C(unk_func_8830867C_034* arg0, unk_func_8830867C_034_03C* arg1) {
    s32 i;
    unk_func_8830867C_034_03C_038* temp_v0 = arg1->unk_38[arg1->unk_34->unk_2C - 1];
    s32 var_v1 = 0;

    for (i = 0; i < temp_v0->unk_2C->unk_08; i++) {
        if (arg0) {}

        if (temp_v0->unk_34[i] & 2) {
            var_v1 = 2;
            break;
        }
    }

    arg0->unk_30->unk_34[arg0->unk_30->unk_38] &= ~2;
    arg0->unk_30->unk_34[arg0->unk_30->unk_38] |= var_v1;
}

void func_8830A928(unk_func_8830867C_034* arg0) {
    s32 i;
    unk_func_8830867C_02C_144_000* var_s2 = arg0->unk_30->unk_2C->unk_00;

    for (i = 0; i < arg0->unk_30->unk_2C->unk_08; i++, var_s2++) {
        arg0->unk_30->unk_34[i] = 0;
        arg0->unk_30->unk_34[i] |= func_8830A840(var_s2);
    }
}

void func_8830A9D8(unk_func_8830867C_034* arg0) {
    static Color_RGBA8 D_88317438 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_8831743C = { 0xF0, 0xF0, 0xF0, 0x4D };

    s32 i;
    s32 var_a1;
    unk_func_88200FA0_030_030_1CEA00* temp_v0 = arg0->unk_30;
    unk_func_8830867C_02C_0CC* ptr = temp_v0->unk_2C;

    var_a1 = 1;

    for (i = 0; i < ptr->unk_08; i++) {
        if (temp_v0->unk_34[i] & 2) {
            var_a1 = 0;
            break;
        }
    }

    if (var_a1 != 0) {
        arg0->unk_40->unk_00.unk_28 |= 2;
        arg0->unk_40->unk_30 = (0, D_8831743C);
        arg0->unk_40->unk_44 = arg0->unk_40->unk_44;
    } else {
        arg0->unk_40->unk_00.unk_28 &= ~2;
        arg0->unk_40->unk_30 = (0, D_88317438);
        arg0->unk_40->unk_44 = arg0->unk_40->unk_44;
    }
}

void func_8830AAA4(unk_func_8830867C_034* arg0, s32 arg1) {
    unk_func_8830867C_02C_144_000* ptr = &((unk_func_8830867C_02C_144*)(arg0->unk_30->unk_2C))->unk_00[arg1];
    unk_func_8830867C_02C_0CC_000_000* ptr2 = ptr->unk_0C;

    ptr2->unk_08 = (arg0->unk_30->unk_34[arg1] & 2) != 0;
}

void func_8830AADC(s32 arg0, s32 arg1, unk_func_88309C38_arg2* arg2, s32 arg3, s32 arg4,
                   unk_func_88200FA0_030_030* arg5) {
    static Color_RGBA8 D_88317440 = { 0xF0, 0xF0, 0xF0, 0xFF };

    Color_RGBA8 sp34;
    UNUSED s32 pad[2];

    if (arg2 != NULL) {
        if (arg4 & 2) {
            func_8002D8C8(&D_800758E0, arg0 + 8, arg1 + 4);
        } else {
            func_8002D8C8(&D_800758F0, arg0 + 8, arg1 + 4);
        }
        sp34 = D_88317440;
        func_8001F3F4();
        func_8001F324(sp34.r, sp34.g, sp34.b, sp34.a);
        func_8001EBE0(8, 0);
        func_8001F1E8(arg0 + 0x2C, arg1 + 4, func_8002D7C0(NULL, 0, D_8831A4C4, arg3 + 0x3B));
        func_8001F444();
        if (arg2->unk_14 == 1) {
            func_883099D8((arg5->unk_00.unk_14.unk_00 + arg0) - 0x35, arg1 + 0xC, arg2->unk_0C->unk_18,
                          arg2->unk_0C->unk_14);
        }
    }
}

s32 func_8830AC0C(void) {
    s32 i;
    s32 var_s1 = 0;
    s32 var_v1;

    for (i = 0; i < 3; i++) {
        var_v1 = func_8001F5B0(8, 0, func_8002D7C0(NULL, 0, D_8831A4C4, i + 0x3B));

        if (i == 0) {
            var_v1 += 0x3D;
        }

        if (var_s1 < var_v1) {
            var_s1 = var_v1;
        }
    }

    return var_s1;
}

void func_8830ACA0(unk_func_8830867C_034* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_88317444 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88317448 = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_8831744C = { 0xA0, 0x96, 0x64, 0xFF };
    static Color_RGBA8 D_88317450 = { 0xFF, 0xFF, 0x00, 0xFF };

    UNUSED s32 pad[3];
    char* sp88;
    s32 sp84;
    s32 sp80;
    unk_func_8850B254* sp7C;
    unk_func_8850878C* sp78;
    unk_func_885012A4* sp74;
    unk_func_8850BD40* sp70;
    unk_func_88001300_000* sp6C;
    char* sp68;
    s32 sp64;
    s32 sp60;
    unk_func_88001300_03C_01C* sp5C;
    unk_func_8850BD40* sp58;
    unk_func_8850BD40* sp54;
    unk_func_88503298* sp50;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8830867C_034));

    arg0->unk_00.unk_20 = func_8830B380;
    arg0->unk_00.unk_24 = func_8830B354;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    sp80 = func_8830AC0C() + 0x36;
    sp88 = func_8002D7C0(NULL, 0, D_8831A4C4, 0x39);
    sp84 = func_8001F5B0(8, 0, sp88);
    if (sp84 < sp80) {
        sp84 = sp80;
    }
    sp84 += 0x10;

    arg0->unk_38 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_034_038));
    func_8830B404(arg0->unk_38, arg0);

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, sp84, 0xAC);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    sp7C = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(func_8850B254))(sp7C, 0, 0, sp84, 0x2C, D_88317444, D_88317448);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp7C);

    sp78 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp78, 8, 0, sp88, 8);
    sp78->unk_3C = 0x18;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp7C, sp78);

    sp74 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp74, 0, 0x30, sp84, 0x7C, D_8831744C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp74);

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_30, 0, 4, func_8830AADC, sp84 - 0x12, 0x1C, 3, 1,
                                                           arg4);
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_30, 3, arg4);
    arg0->unk_30->unk_00.unk_28 |= 0x300;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp74, arg0->unk_30);

    arg0->unk_34 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_034_034));
    func_8830A578(arg0->unk_34, arg0->unk_30->unk_00.unk_14.unk_00 + 3, 9, 1);
    arg0->unk_34->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_30->unk_44, arg0->unk_34);

    sp70 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(sp70, arg0->unk_30);
    ((func8850CC74)Memmap_GetFragmentVaddr(func_8850CC74))(arg0->unk_38, sp70);
    sp68 = func_8002D7C0(NULL, 0, D_8831A4C4, 0x46);
    sp64 = func_8001F5B0(8, 0, sp68);
    sp60 = sp64 + 0x10;
    if (sp60 < 0x48) {
        sp60 = 0x48;
    }

    sp6C = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func8850A40C)Memmap_GetFragmentVaddr(func_8850A40C))(sp6C, (sp84 - sp60) / 2, 0x5C, sp60, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp74, sp6C);

    arg0->unk_40 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_40, (sp60 - sp64) / 2, 2, sp68, 8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp6C, arg0->unk_40);

    sp5C = mem_pool_alloc(arg4, sizeof(unk_func_88001300_03C_01C));
    ((func88504570)Memmap_GetFragmentVaddr(func_88504570))(sp5C, -3, -3, sp6C->unk_14.unk_00 + 6,
                                                           sp6C->unk_14.unk_02 + 6, D_88317450);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp6C, sp5C);

    sp58 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(sp58, sp6C);
    ((func8850CC74)Memmap_GetFragmentVaddr(func_8850CC74))(arg0->unk_38, sp58);

    arg0->unk_3C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_034_03C));
    func_88309E28(arg0->unk_3C, arg0->unk_2C->unk_00.unk_14.unk_00 + 0x10, 0, 0xC, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_3C);

    sp54 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(sp54, arg0->unk_3C);
    ((func8850CC74)Memmap_GetFragmentVaddr(func_8850CC74))(arg0->unk_38, sp54);

    sp50 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(func_88503298))(sp50, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, sp50);
}

void func_8830B2EC(unk_func_8830867C_034* arg0, unk_func_8830867C_02C_144* arg1) {
    unk_func_8830867C_02C_144_000_alt* sp1C;

    ((func885063B8)Memmap_GetFragmentVaddr(func_885063B8))(arg0->unk_30, arg1);

    sp1C = arg1->unk_00;
    func_8830A928(arg0);
    func_8830A410(arg0->unk_3C, &sp1C->unk_2C, &sp1C->unk_4C);
}

void func_8830B354(unk_func_8830867C_034* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_38->unk_00.unk_14(arg0->unk_38, arg1);
}

s32 func_8830B380(unk_func_8830867C_034* arg0, Controller* arg1) {
    s32 sp1C;

    if (arg0->unk_2C->unk_30 & 2) {
        sp1C = arg0->unk_38->unk_00.unk_10(arg0->unk_38, arg1);
        if (!(sp1C & 1) && (sp1C & 4)) {
            func_8830AAA4(arg0, 0);
            func_88309960(arg0->unk_3C);
        }
    } else {
        sp1C = 1;
    }
    return sp1C;
}

void func_8830B404(unk_func_8830867C_034_038* arg0, unk_func_8830867C_034* arg1) {
    ((func8850CBA8)Memmap_GetFragmentVaddr(func_8850CBA8))(arg0);
    arg0->unk_00.unk_10 = func_8830B450;
    arg0->unk_24 = arg1;
}

s32 func_8830B450(unk_func_8830867C_034_038* arg0, Controller* arg1) {
    s32 var_v1 = 0;
    s32 i;
    unk_func_8830867C_034_038* var_a0;

    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;

        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }

        var_v1 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

    switch (arg0->unk_00.unk_1C) {
        case 0:
            if (var_v1 & 1) {
                if (var_v1 & 8) {
                    arg0->unk_24->unk_34->unk_00.unk_28 &= ~1;
                    if (arg0->unk_24->unk_30->unk_38 != 0) {
                        arg0->unk_24->unk_34->unk_00.unk_28 |= 1;
                    }
                    func_8830A520(arg0->unk_24->unk_3C, arg0->unk_24->unk_30->unk_38);
                }
            } else if (var_v1 & 8) {
                if (arg1->buttonPressed & 0x800) {
                    ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0, 1);
                    func_8830A520(arg0->unk_24->unk_3C, 0);
                    var_v1 |= 0x80000001;
                } else if (arg1->buttonPressed & 0x400) {
                    arg0->unk_24->unk_34->unk_00.unk_28 &= ~1;
                    ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0, 1);
                    func_8830A520(arg0->unk_24->unk_3C, 0);
                    var_v1 |= 0x80000001;
                } else if ((arg1->buttonPressed & 0x100) && (arg0->unk_24->unk_30->unk_38 != 0)) {
                    ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0, 2);
                    var_v1 |= 0x80000001;
                }
            } else {
                if (arg1->buttonPressed & 0x8000) {
                    arg0->unk_24->unk_30->unk_34[arg0->unk_24->unk_30->unk_38] ^= 2;
                    if (arg0->unk_24->unk_30->unk_38 != 0) {
                        func_883098D0(arg0->unk_24->unk_3C,
                                      arg0->unk_24->unk_30->unk_34[arg0->unk_24->unk_30->unk_38] & 2);
                    }
                    func_8830A9D8(arg0->unk_24);
                    var_v1 = 0x80000005;
                } else if (arg1->buttonPressed & 0x4000) {
                    var_v1 = 0x80000002;
                }
            }
            break;

        case 1:
            if (arg1->buttonPressed & 0x800) {
                arg0->unk_24->unk_34->unk_00.unk_28 |= 1;
                ((func88506BFC)Memmap_GetFragmentVaddr(func_88506BFC))(arg0->unk_24->unk_30,
                                                                       arg0->unk_24->unk_30->unk_2C->unk_08 - 1);
                func_8830A520(arg0->unk_24->unk_3C, arg0->unk_24->unk_30->unk_38);
                ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0, 0);
                var_v1 = 0x80000009;
            } else if (arg1->buttonPressed & 0x400) {
                ((func88506BFC)Memmap_GetFragmentVaddr(func_88506BFC))(arg0->unk_24->unk_30, 0);
                func_8830A520(arg0->unk_24->unk_3C, arg0->unk_24->unk_30->unk_38);
                ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0, 0);
                var_v1 = 0x80000009;
            } else if (arg1->buttonPressed & 0x8000) {
                if (arg0->unk_24->unk_40->unk_00.unk_28 & 2) {
                    var_v1 = 0x80000101;
                } else {
                    var_v1 = 0x80000004;
                }
            } else if (arg1->buttonPressed & 0x4000) {
                var_v1 = 0x80000002;
            }
            break;

        case 2:
            if (!(var_v1 & 1)) {
                if (var_v1 & 8) {
                    if (arg1->buttonPressed & 0x200) {
                        ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0, 0);
                        var_v1 = 0x80000009;
                    }
                } else if (var_v1 & 4) {
                    func_8830A88C(arg0->unk_24, arg0->unk_24->unk_3C);
                    func_8830A9D8(arg0->unk_24);
                    var_v1 |= 1;
                } else if (arg1->buttonPressed & 0x4000) {
                    var_v1 = 0x80000002;
                }
            }
            break;
    }
    return var_v1;
}

void func_8830B8A0(unk_func_8830867C_034* arg0) {
    func_8830A520(arg0->unk_3C, 0);
    ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0->unk_38, 1);
    arg0->unk_38->unk_00.unk_14(arg0->unk_38, 1);
    arg0->unk_34->unk_00.unk_28 &= ~1;
    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);
    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_3C->unk_2C);
}

void func_8830B938(unk_func_8830867C_034* arg0) {
    arg0->unk_2C->unk_2C = 0xB;
    arg0->unk_3C->unk_2C->unk_2C = 0xB;
}

s32 func_8830B954(unk_func_8830867C_034* arg0, Controller* arg1) {
    s32 var_s0 = 0;
    s32 temp_v0;

    func_8830B8A0(arg0);
    func_8001F738(arg1);

    while (var_s0 == 0) {
        func_8002EEA8(var_s0);
        temp_v0 = arg0->unk_00.unk_20(arg0, arg1);
        if (!(temp_v0 & 1)) {
            if (temp_v0 & 2) {
                var_s0 = 1;
            } else if (temp_v0 & 4) {
                var_s0 = 2;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(temp_v0);
    }

    func_8830B938(arg0);
    return var_s0 - 1;
}

void func_8830BA1C(s32 arg0, s32 arg1, char* arg2, s32 arg3, s32 arg4) {
    static Color_RGBA8 D_88317454 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_88317458 = { 0xF0, 0xF0, 0xF0, 0x4D };

    Color_RGBA8 sp1C;

    if (arg4 & 4) {
        sp1C = (0, D_88317458);
    } else {
        sp1C = (0, D_88317454);
    }

    func_8001F3F4();
    func_8001F324(sp1C.r, sp1C.g, sp1C.b, sp1C.a);
    func_8001EBE0(8, 0);
    func_8001F1E8(arg0 + 8, arg1 + 4, arg2);
    func_8001F444();
}

void func_8830BAC4(unk_func_8830867C_030* arg0, unk_func_88001300_000* arg1, MemoryPool* arg2) {
    static Color_RGBA8 D_8831745C = { 0xA0, 0x96, 0x64, 0xFF };

    unk_func_88503298* sp44;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8830867C_030));

    arg0->unk_00.unk_20 = func_8830BF5C;
    arg0->unk_00.unk_24 = func_8830BF30;
    arg0->unk_00.unk_10.unk_00 = 0;
    arg0->unk_00.unk_10.unk_02 = 0;

    arg0->unk_2C = mem_pool_alloc(arg2, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, 0x10, 0x10);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    arg0->unk_38 = mem_pool_alloc(arg2, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(arg0->unk_38, 0, 0, 0x10, 0x10, D_8831745C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_38);

    arg0->unk_3C = mem_pool_alloc(arg2, sizeof(unk_func_88200FA0_030_030_1CEA00));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_3C, 0, 4, func_8830BA1C, 0x10, 0x10, 0xA, 1, arg2);
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_3C, 0xA, arg2);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_3C);

    if (arg1 != NULL) {
        sp44 = mem_pool_alloc(arg2, sizeof(unk_func_88503298));
        ((func88503298)Memmap_GetFragmentVaddr(func_88503298))(sp44, arg0->unk_2C, arg1);
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, sp44);
    }
}

void func_8830BCE8(unk_func_8830867C_030* arg0, char** arg1, s32 arg2) {
    s32 temp_v0;
    s32 var_s1;
    s32 i;

    var_s1 = 0;
    for (i = 0; i < arg2; i++) {
        temp_v0 = func_8001F5B0(8, 0, arg1[i]);
        if (var_s1 < temp_v0) {
            var_s1 = temp_v0;
        }
    }

    var_s1 += 0x10;
    func_8002CBB0(&arg0->unk_40, arg1, arg2, arg2);
    ((func8850633C)Memmap_GetFragmentVaddr(func_8850633C))(arg0->unk_3C, &arg0->unk_40);

    arg0->unk_3C->unk_4A = arg2;

    arg0->unk_2C->unk_00.unk_14.unk_00 = var_s1;
    arg0->unk_2C->unk_00.unk_14.unk_02 = (arg0->unk_40.unk_08 * 0x1C) + 8;

    arg0->unk_3C->unk_3C = var_s1;
    arg0->unk_3C->unk_3E = 0x1C;
    arg0->unk_3C->unk_44->unk_00.unk_14.unk_00 = var_s1;
    arg0->unk_3C->unk_44->unk_00.unk_14.unk_02 = 0x22;
    arg0->unk_3C->unk_50 = 0;
    arg0->unk_3C->unk_52 = -3;
    arg0->unk_3C->unk_00.unk_14 = arg0->unk_2C->unk_00.unk_14;
    arg0->unk_38->unk_00.unk_14 = arg0->unk_2C->unk_00.unk_14;
}

void func_8830BE3C(unk_func_8830867C_030* arg0) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1_4;

    temp_v0 = arg0->unk_2C->unk_00.unk_14.unk_00 + 8;
    temp_a1 = arg0->unk_2C->unk_00.unk_14.unk_02 + 8;

    if (arg0->unk_00.unk_28 & 0x100) {
        if (arg0->unk_50 >= (arg0->unk_30.unk_02 + temp_a1)) {
            arg0->unk_00.unk_10.unk_02 = arg0->unk_30.unk_02 + 4;
        } else {
            temp_a1 = ((arg0->unk_30.unk_02 + temp_a1) - arg0->unk_50);
            arg0->unk_00.unk_10.unk_02 = (arg0->unk_30.unk_02 - temp_a1) + 4;
        }

        temp_v0_2 = arg0->unk_30.unk_00 + arg0->unk_34.unk_00;
        if (arg0->unk_4C >= (temp_v0_2 + temp_v0)) {
            arg0->unk_00.unk_10.unk_00 = temp_v0_2 + 4;
        } else {
            arg0->unk_00.unk_10.unk_00 = (arg0->unk_30.unk_00 - temp_v0) + 4;
        }
    } else {
        if (arg0->unk_4C >= (arg0->unk_30.unk_00 + temp_v0)) {
            arg0->unk_00.unk_10.unk_00 = arg0->unk_30.unk_00 + 4;
        } else {
            temp_v1_4 = ((arg0->unk_30.unk_00 + temp_v0) - arg0->unk_4C);
            arg0->unk_00.unk_10.unk_00 = (arg0->unk_30.unk_00 - temp_v1_4) + 4;
        }

        temp_v0 = arg0->unk_30.unk_02 + arg0->unk_34.unk_02;
        if (arg0->unk_50 >= (temp_v0 + temp_a1)) {
            arg0->unk_00.unk_10.unk_02 = temp_v0 + 4;
        } else {
            arg0->unk_00.unk_10.unk_02 = (arg0->unk_30.unk_02 - temp_a1) + 4;
        }
    }
}

void func_8830BF30(unk_func_8830867C_030* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_3C->unk_00.unk_24(&arg0->unk_3C->unk_00, arg1);
}

s32 func_8830BF5C(unk_func_8830867C_030* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_3C->unk_00.unk_20(arg0->unk_3C, arg1);
        if (var_v1 == 0) {
            if (arg1->buttonPressed & 0x4000) {
                var_v1 = 0x80000002;
            } else if (arg1->buttonPressed & 0x8000) {
                var_v1 = 0x80000004;
            }
        }
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void func_8830BFE0(unk_func_8830867C_030* arg0, s32 arg1) {
    arg0->unk_3C->unk_38 = arg1;
    ((func88506CE4)Memmap_GetFragmentVaddr(func_88506CE4))(arg0->unk_3C);
    arg0->unk_00.unk_24(&arg0->unk_00, 1);
    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);
}

void func_8830C048(unk_func_8830867C_030* arg0) {
    arg0->unk_2C->unk_2C = 0xB;
}

u32 func_8830C058(unk_func_8830867C_030* arg0, Controller* arg1, s32 arg2) {
    s32 var_s0;
    s32 var_s1 = 0;

    func_8830BFE0(arg0, arg2);

    while (var_s1 == NULL) {
        func_8002EEA8(var_s1);
        var_s0 = arg0->unk_00.unk_20(arg0, arg1);
        if (var_s0 & 2) {
            var_s1 = 1;
        } else if (var_s0 & 4) {
            if (arg0->unk_3C->unk_34[arg0->unk_3C->unk_38] & 4) {
                var_s0 = (var_s0 & ~4) | 0x100;
            } else {
                var_s1 = arg0->unk_3C->unk_38 + 2;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(var_s0);
    }
    func_8830C048(arg0);
    return var_s1 - 1;
}

void func_8830C150(s32 arg0, s32 arg1, char* arg2, s32 arg3, s32 arg4) {
    static Color_RGBA8 D_88317460 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_88317464 = { 0xF0, 0xF0, 0xF0, 0x4D };
    static Color_RGBA8 D_88317468 = { 0xF0, 0xF0, 0x00, 0xFF };

    Color_RGBA8 sp24;
    UNUSED s32 pad[2];

    if (arg4 & 2) {
        sp24 = (0, D_88317468);
    } else if (arg4 & 4) {
        sp24 = (0, D_88317464);
    } else {
        sp24 = (0, D_88317460);
    }

    func_8001F3F4();
    func_8001F324(sp24.r, sp24.g, sp24.b, sp24.a);
    func_8001EBE0(8, 0);
    func_8001F1E8(arg0 + 0x11, arg1 + 4, arg2);
    func_8001F444();
}

void func_8830C218(unk_func_8830867C_038* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_8831746C = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88317470 = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317474 = { 0xA0, 0x96, 0x64, 0xFF };
    static Color_RGBA8 D_88317478 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_8831747C = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317480 = { 0xA0, 0x96, 0x64, 0xFF };
    static Color_RGBA8 D_88317484 = { 0xB2, 0xFF, 0xC3, 0xFF };
    static Color_RGBA8 D_88317488 = { 0xFF, 0xB2, 0xC3, 0xFF };

    s32 i;
    UNUSED s32 pad;
    s32 spAC;
    UNUSED s32 pad2;
    s32 spA4;
    UNUSED s32 pad3;
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 tmp;
    s32 temp_v0;
    unk_func_8850B254* sp88;
    unk_func_8850878C* sp84;
    s32 temp_v0_6;
    s32 temp_v0_7;
    unk_func_885012A4* temp_s0_2;
    unk_func_88503298* temp_s0_3;
    unk_func_8850B254* sp70;
    char* sp6C;
    unk_func_8850878C* sp68;
    unk_func_885012A4* sp64;
    unk_func_8850878C* sp60;
    char* sp5C;

    spAC = func_8001F5B0(8, 0, func_8002D7C0(NULL, 0, D_8831A4C4, 0x2A));
    func_8002CBC0(&arg0->unk_34, 4, arg4);
    func_8002CC2C(&arg0->unk_34, func_8002D7C0(NULL, 0, D_8831A4C4, 0x2C), 0);
    func_8002CC2C(&arg0->unk_34, func_8002D7C0(NULL, 0, D_8831A4C4, 0x2D), 1);
    func_8002CC2C(&arg0->unk_34, func_8002D7C0(NULL, 0, D_8831A4C4, 0x30), 2);
    func_8002CC2C(&arg0->unk_34, func_8002D7C0(NULL, 0, D_8831A4C4, 0x31), 3);

    for (i = 0; i < 4; i++) {
        temp_v0 = func_8001F5B0(8, 0, arg0->unk_34.unk_00[i]);
        if (spAC < temp_v0) {
            spAC = temp_v0;
        }
    }

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(unk_func_88200FA0_030_030_1CEA00));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_30, 0, 4, func_8830C150, spAC, 0x1C, 4, 1, arg4);
    ((func88506384)Memmap_GetFragmentVaddr(func_88506384))(arg0->unk_30, &arg0->unk_34, arg4);
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, 0x44);

    arg0->unk_00.unk_20 = func_8830CE00;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(unk_func_88001300_038));
    tmp = spAC + 0x10;
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, tmp, 0xA8);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    sp88 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(func_8850B254))(sp88, 0, 0, tmp, 0x2C, D_8831746C, D_88317470);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp88);

    sp84 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp84, 8, 0, func_8002D7C0(NULL, 0, D_8831A4C4, 0x2A), 8);
    sp84->unk_3C = 0x18;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp88, sp84);

    temp_s0_2 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(temp_s0_2, 0, 0x30, tmp, 0x78, D_88317474);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, temp_s0_2);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s0_2, arg0->unk_30);

    temp_s0_3 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(func_88503298))(temp_s0_3, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, temp_s0_3);

    arg0->unk_40 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_038));

    sp9C = 0;
    for (i = 0; i < 3; i++) {
        temp_v0_6 = func_8001F5B0(8, 0, func_8002D7C0(NULL, 0, D_8831A4C4, i + 0x32));
        if (sp9C < temp_v0_6) {
            sp9C = temp_v0_6;
        }
    }

    sp98 = 0;
    for (i = 0; i < 3; i++) {
        temp_v0_7 = func_8001F5B0(8, 0, func_8002D7C0(NULL, 0, D_8831A4C4, i + 0x35));
        if (sp98 < temp_v0_7) {
            sp98 = temp_v0_7;
        }
    }

    spA4 = sp9C + sp98 + 0x10;
    sp94 = func_8001F5B0(8, 0, func_8002D7C0(NULL, 0, D_8831A4C4, 0x38));
    if (spA4 < sp94) {
        spA4 = sp94;
    }
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_40, arg0->unk_2C->unk_00.unk_14.unk_00 + 0x10,
                                                           0x18, spA4 + 0x10, 0x90);
    arg0->unk_40->unk_00.unk_28 |= 0x200;
    arg0->unk_40->unk_00.unk_28 |= 0x400;
    arg0->unk_40->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_40);

    sp70 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(func_8850B254))(sp70, 0, 0, arg0->unk_40->unk_00.unk_14.unk_00, 0x14,
                                                           D_88317478, D_8831747C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_40, sp70);
    sp6C = func_8002D7C0(NULL, 0, D_8831A4C4, 0x2B);

    sp68 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(
        sp68, (arg0->unk_40->unk_00.unk_14.unk_00 - func_8001F5B0(8, 0, sp6C)) / 2, 0, sp6C, 8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp70, sp68);

    sp64 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp64, 0, 0x18, arg0->unk_40->unk_00.unk_14.unk_00, 0x78,
                                                           D_88317480);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_40, sp64);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    sp5C = func_8002D7C0(NULL, 0, D_8831A4C4, 0x32);
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp60, ((sp9C - func_8001F5B0(8, 0, sp5C)) / 2) + 8, 8, sp5C,
                                                           8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, sp60);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    sp5C = func_8002D7C0(NULL, 0, D_8831A4C4, 0x33);
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp60, ((sp9C - func_8001F5B0(8, 0, sp5C)) / 2) + 8, 0x24,
                                                           sp5C, 8);
    sp60->unk_30 = (0, D_88317484);
    sp60->unk_44 = sp60->unk_44;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, sp60);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    sp5C = func_8002D7C0(NULL, 0, D_8831A4C4, 0x34);
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp60, ((sp9C - func_8001F5B0(8, 0, sp5C)) / 2) + 8, 0x40,
                                                           sp5C, 8);
    sp60->unk_30 = (0, D_88317488);
    sp60->unk_44 = sp60->unk_44;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, sp60);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp60, sp9C + 0x18, 8,
                                                           func_8002D7C0(NULL, 0, D_8831A4C4, 0x35), 8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, sp60);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp60, sp9C + 0x18, 0x24,
                                                           func_8002D7C0(NULL, 0, D_8831A4C4, 0x36), 8);
    sp60->unk_30 = (0, D_88317484);
    sp60->unk_44 = sp60->unk_44;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, sp60);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp60, sp9C + 0x18, 0x40,
                                                           func_8002D7C0(NULL, 0, D_8831A4C4, 0x37), 8);
    sp60->unk_30 = (0, D_88317488);
    sp60->unk_44 = sp60->unk_44;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, sp60);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    sp5C = func_8002D7C0(NULL, 0, D_8831A4C4, 0x38);
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp60, (arg0->unk_40->unk_00.unk_14.unk_00 - sp94) / 2, 0x5C,
                                                           sp5C, 8);
    sp60->unk_3C = 0x18;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, sp60);
}

void func_8830CD4C(unk_func_8830867C_038* arg0, s32 arg1) {
    s32 sp1C;

    ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0->unk_30);
    if (arg1 == -1) {
        sp1C = 0;
        arg0->unk_30->unk_34[arg0->unk_30->unk_2C->unk_08 - 1] |= 4;
    } else {
        sp1C = arg1;
        arg0->unk_30->unk_34[arg1] |= 2;
    }
    ((func88506BFC)Memmap_GetFragmentVaddr(func_88506BFC))(arg0->unk_30, sp1C);
}

s32 func_8830CE00(unk_func_8830867C_038* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);
        if (var_v1 == 0) {
            if (arg1->buttonPressed & 0x4000) {
                var_v1 = 0x80000002;
            } else if (arg1->buttonPressed & 0x8000) {
                var_v1 = 0x80000004;
            }
        }
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_8830CE84(unk_func_8830867C_038* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_s0;

    var_s0 = NULL;
    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);
    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_40);

    while (var_s0 == 0) {
        func_8002EEA8(var_s0);
        temp_v0 = arg0->unk_00.unk_20(arg0, arg1);
        if (!(temp_v0 & 1)) {
            if (temp_v0 & 2) {
                var_s0 = 1;
            } else if (temp_v0 & 4) {
                var_s0 = arg0->unk_30->unk_38 + 2;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(temp_v0);
    }
    arg0->unk_2C->unk_2C = 0xB;
    arg0->unk_40->unk_2C = 0xB;
    return var_s0 - 1;
}

void func_8830CF88(unk_func_8830867C_044_038* arg0) {
    s32 tmp = ((arg0->unk_30.unk_0C - arg0->unk_30.unk_10) - 1) * arg0->unk_44->unk_00.unk_14.unk_00;

    arg0->unk_44->unk_00.unk_10.unk_00 = tmp;
    arg0->unk_44->unk_00.unk_10.unk_02 = arg0->unk_44->unk_00.unk_10.unk_02;
}

void func_8830CFBC(unk_func_8830867C_044_038* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    s32 sp2C;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8830867C_044_038));

    arg0->unk_00.unk_18 = func_8830D11C;
    arg0->unk_00.unk_20 = func_8830D268;
    arg0->unk_00.unk_24 = func_8830D0B4;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    sp2C = func_8001F5B0(8, 0, "0");

    arg0->unk_44 = mem_pool_alloc(arg3, sizeof(unk_func_8820E99C_030_044));
    ((func88504F98)Memmap_GetFragmentVaddr(func_88504F98))(arg0->unk_44, -1, 0, sp2C + 2, 0x14);
    arg0->unk_44->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_44);
}

void func_8830D0B4(unk_func_8830867C_044_038* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_44->unk_00.unk_24(&arg0->unk_44->unk_00, arg1);
    arg0->unk_44->unk_00.unk_28 &= ~1;
    if (arg1 & 0x101) {
        arg0->unk_44->unk_00.unk_28 |= 1;
    }
}

s32 func_8830D11C(unk_func_8830867C_044_038* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_8831748C = { 0xF0, 0xF0, 0xF0, 0xFF };

    s32 i;
    s32 var_s2 = arg0->unk_30.unk_00;

    func_8001F3F4();
    func_8001F324(D_8831748C.r, D_8831748C.g, D_8831748C.b, D_8831748C.a);
    func_8001EBE0(8, 2);

    for (i = 0; i < arg0->unk_30.unk_0C; i++) {
        func_8001F2E4((((arg0->unk_30.unk_0C - i) - 1) * arg0->unk_44->unk_00.unk_14.unk_00) + arg1, arg2,
                      (var_s2 % 10) + 0x30);
        var_s2 /= 10;
    }

    func_8001F444();
    return 0;
}

s32 func_8830D268(unk_func_8830867C_044_038* arg0, Controller* arg1) {
    s32 var_v1 = func_8002DF68(&arg0->unk_30, func_8001F750() & 0xFFFF);

    if (!(var_v1 & 1)) {
        if (!(var_v1 & 8)) {
            if (arg1->buttonPressed & 0x4000) {
                var_v1 = 0x80000002;
            } else if (arg1->buttonPressed & 0x8000) {
                var_v1 = 0x80000004;
            }
        }
    } else {
        func_8830CF88(arg0);
    }
    return var_v1;
}

void func_8830D2F8(unk_func_8830867C_044* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_88317490 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88317494 = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317498 = { 0xA0, 0x96, 0x64, 0xFF };
    static Color_RGBA8 D_8831749C = { 0xC8, 0xC8, 0xFF, 0xFF };
    static Color_RGBA8 D_883174A0 = { 0xFF, 0xFF, 0x00, 0xFF };

    s32 i;
    s32 temp_v0;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    unk_func_8850878C* temp_s0_5;
    unk_func_88001300_03C_01C* temp_s0_6;
    unk_func_8850B254* sp80;
    unk_func_88001300_03C* ptr;
    unk_func_885012A4* sp78;
    UNUSED s32 pad;
    unk_func_8850878C* temp_s0;
    unk_func_8850BD40* temp_s0_2;
    unk_func_8850BD40* temp_s0_3;
    unk_func_88001300_000* sp64;
    char* sp60;
    unk_func_8850878C* temp_s0_4;
    s32 sp58;
    s32 tmp;
    unk_func_88503298* temp_s0_7;

    sp94 = func_8001F5B0(4, 0, func_8002D7C0(NULL, 0, D_8831A4C4, 0x48));
    sp90 = (func_8001F5B0(8, 0, "0") * 3) + 6;
    sp8C = 0;

    for (i = 0; i < 2; i++) {
        temp_v0 = func_8001F5B0(8, 0, func_8002D7C0(NULL, 0, D_8831A4C4, i + 0x49));
        if (sp8C < temp_v0) {
            sp8C = temp_v0;
        }
    }

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8830867C_044));

    arg0->unk_00.unk_20 = func_8830DC0C;
    arg0->unk_00.unk_24 = func_8830DBE0;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_40 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_044_040));
    func_8830DD8C(arg0->unk_40, arg0);

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, (sp90 + sp94) + sp90 + sp8C + 0x34,
                                                           0x5C);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    sp80 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(func_8850B254))(sp80, 0, 0, (sp90 + sp94) + sp90 + sp8C + 0x34, 0x14,
                                                           D_88317490, D_88317494);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp80);

    temp_s0 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(temp_s0, 8, 0, func_8002D7C0(NULL, 0, D_8831A4C4, 0x47), 8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp80, temp_s0);

    sp78 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp78, 0, 0x18, (sp90 + sp94) + sp90 + sp8C + 0x34, 0x44,
                                                           D_88317498);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp78);

    arg0->unk_38 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_044_038));
    func_8830CFBC(arg0->unk_38, 8, 0xA, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp78, arg0->unk_38);

    temp_s0_2 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(temp_s0_2, arg0->unk_38);
    ((func8850CC74)Memmap_GetFragmentVaddr(func_8850CC74))(arg0->unk_40, temp_s0_2);

    arg0->unk_3C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_044_038));
    func_8830CFBC(arg0->unk_3C, (sp90 + sp94) + 0x18, 0xA, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp78, arg0->unk_3C);

    temp_s0_3 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(temp_s0_3, arg0->unk_3C);
    ((func8850CC74)Memmap_GetFragmentVaddr(func_8850CC74))(arg0->unk_40, temp_s0_3);

    temp_s0_4 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(temp_s0_4, sp90 + 0x10, 0xD,
                                                           func_8002D7C0(NULL, 0, D_8831A4C4, 0x48), 4);
    temp_s0_4->unk_30 = D_8831749C;
    temp_s0_4->unk_44 = temp_s0_4->unk_44;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp78, temp_s0_4);

    arg0->unk_44 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_03C));
    ((func8850C284)Memmap_GetFragmentVaddr(func_8850C284))(arg0->unk_44, 2, 1, arg4);
    arg0->unk_44->unk_28 |= 0x100;
    ((func8850CC74)Memmap_GetFragmentVaddr(func_8850CC74))(arg0->unk_40, arg0->unk_44);

    sp64 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    tmp = (sp90 * 2) + sp94 + 0x20;
    ((func8850A40C)Memmap_GetFragmentVaddr(func_8850A40C))(sp64, tmp, 8, sp8C + 0xC, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp78, sp64);
    ptr = arg0->unk_44;
    ptr->unk_18[0] = sp64;
    sp60 = func_8002D7C0(NULL, 0, D_8831A4C4, 0x49);
    sp58 = func_8001F5B0(8, 0, sp60);

    temp_s0_5 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(temp_s0_5, ((sp8C - sp58) / 2) + 6, 2, sp60, 8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, temp_s0_5);

    arg0->unk_34 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func8850A40C)Memmap_GetFragmentVaddr(func_8850A40C))(arg0->unk_34, tmp, 0x24, sp8C + 0xC, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp78, arg0->unk_34);
    arg0->unk_44->unk_18[arg0->unk_44->unk_2C] = arg0->unk_34;
    sp60 = func_8002D7C0(NULL, 0, D_8831A4C4, 0x4A);
    sp58 = func_8001F5B0(8, 0, sp60);

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_30, ((sp8C - sp58) / 2) + 6, 2, sp60, 8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_34, arg0->unk_30);
    ((func8850CAB4)Memmap_GetFragmentVaddr(func_8850CAB4))(arg0->unk_44);

    temp_s0_6 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_03C_01C));
    ((func88504570)Memmap_GetFragmentVaddr(func_88504570))(temp_s0_6, 0, 0, 0x10, 0x10, D_883174A0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp78, temp_s0_6);
    arg0->unk_44->unk_1C = temp_s0_6;

    temp_s0_7 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(func_88503298))(temp_s0_7, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, temp_s0_7);
}

void func_8830DAB8(unk_func_8830867C_044* arg0, s32 arg1, s32 arg2, s32 arg3) {
    static Color_RGBA8 D_883174A4 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_883174A8 = { 0xF0, 0xF0, 0xF0, 0x4D };
    static Color_RGBA8 D_883174AC = { 0x66, 0x5B, 0x47, 0xFF };

    unk_func_88001300_000* temp_v0;
    unk_func_88001300_000* temp_v0_2;
    unk_func_8850878C* temp_v1;
    unk_func_8850878C* temp_v1_2;

    arg0->unk_38->unk_30.unk_0C = 3;
    arg0->unk_38->unk_30.unk_00 = arg1;
    arg0->unk_38->unk_30.unk_04 = 1;
    arg0->unk_38->unk_30.unk_08 = 0x64;
    arg0->unk_38->unk_30.unk_10 = 0;

    func_8830CF88(arg0->unk_38);

    arg0->unk_3C->unk_30.unk_0C = 3;
    arg0->unk_3C->unk_30.unk_00 = arg2;
    arg0->unk_3C->unk_30.unk_04 = 1;
    arg0->unk_3C->unk_30.unk_08 = 0x64;
    arg0->unk_3C->unk_30.unk_10 = 0;

    func_8830CF88(arg0->unk_3C);

    if (arg3 == 0) {
        arg0->unk_34->unk_28 |= 2;
        arg0->unk_30->unk_30 = (0, D_883174A8);
        arg0->unk_30->unk_44 = arg0->unk_30->unk_44;
    } else {
        arg0->unk_34->unk_28 &= ~2;
        arg0->unk_30->unk_30 = (0, D_883174A4);
        arg0->unk_30->unk_44 = arg0->unk_30->unk_44;
    }
}

void func_8830DBE0(unk_func_8830867C_044* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_40->unk_00.unk_14(arg0->unk_40, arg1);
}

s32 func_8830DC0C(unk_func_8830867C_044* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_40->unk_00.unk_10(arg0->unk_40, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_8830DC58(unk_func_8830867C_044* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_v0;
    s32 var_s0 = 0;

    ((func8850CB48)Memmap_GetFragmentVaddr(func_8850CB48))(arg0->unk_44, 0);
    ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0->unk_40, 0);

    arg0->unk_40->unk_00.unk_14(arg0->unk_40, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);
    while (var_s0 == 0) {
        func_8002EEA8(var_s0);

        temp_v0 = arg0->unk_00.unk_20(arg0, arg1);

        if (!(temp_v0 & 1)) {
            if (temp_v0 & 2) {
                var_s0 = 1;
            } else if (temp_v0 & 4) {
                if (arg0->unk_44->unk_24 == 0) {
                    var_v0 = 1;
                } else {
                    var_v0 = 2;
                }
                var_s0 = var_v0 + 1;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(temp_v0);
    }
    arg0->unk_2C->unk_2C = 0xB;
    return var_s0 - 1;
}

void func_8830DD8C(unk_func_8830867C_044_040* arg0, unk_func_8830867C_044* arg1) {
    ((func8850CBA8)Memmap_GetFragmentVaddr(func_8850CBA8))(arg0);
    arg0->unk_00.unk_10 = func_8830DDD8;
    arg0->unk_24 = arg1;
}

s32 func_8830DDD8(unk_func_8830867C_044_040* arg0, Controller* arg1) {
    s32 var_v1;
    UNUSED s32 pad;
    s32 i;
    unk_func_8830867C_034_038* var_a0;

    var_v1 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;

        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }
        var_v1 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

    if (var_v1 & 1) {
        return var_v1;
    }

    if (var_v1 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_v1 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_v1 = 0x80000004;
        }
    }

    if (var_v1 & 8) {
        if (arg1->buttonPressed & 0x200) {
            s32 var_a1 = arg0->unk_00.unk_1C;

            if (var_a1 == 0) {
                var_a1 = 3;
            }
            var_a1--;

            switch (var_a1) {
                case 0:
                    arg0->unk_24->unk_38->unk_30.unk_10 = 0;
                    func_8830CF88(arg0->unk_24->unk_38);
                    break;

                case 1:
                    arg0->unk_24->unk_3C->unk_30.unk_10 = 0;
                    func_8830CF88(arg0->unk_24->unk_3C);
                    break;
            }
            ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0, var_a1);
            var_v1 |= 0x80000001;
        } else if (arg1->buttonPressed & 0x100) {
            s32 var_a1 = arg0->unk_00.unk_1C + 1;

            if (var_a1 == 3) {
                var_a1 = 0;
            }

            switch (var_a1) {
                case 0:
                    arg0->unk_24->unk_38->unk_30.unk_10 = 2;
                    func_8830CF88(arg0->unk_24->unk_38);
                    break;

                case 1:
                    arg0->unk_24->unk_3C->unk_30.unk_10 = 2;
                    func_8830CF88(arg0->unk_24->unk_3C);
                    break;
            }
            ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0, var_a1);
            var_v1 |= 0x80000001;
        }
    } else if (!(var_v1 & 2) && (var_v1 & 4)) {
        switch (arg0->unk_00.unk_1C) {
            case 2:
                break;

            case 0:
            case 1:
                var_v1 = 1;
                break;
        }
    }
    return var_v1;
}

void func_8830E090(s32 arg0, s32 arg1, unk_func_88309C38_arg2* arg2, s32 arg3, s32 arg4,
                   unk_func_8821421C_038_034* arg5) {
    static Color_RGBA8 D_883174B0 = { 0x54, 0x4B, 0x3A, 0xFF };
    static Color_RGBA8 D_883174B4 = { 0x99, 0x89, 0x6A, 0xFF };

    Color_RGBA8 sp84;
    UNUSED s32 pad;
    s32 sp7C;
    s32 sp78;
    char sp74[4];
    char* sp70;
    UNUSED s32 pad2;
    s32 temp_a0;
    s32 temp_a3;

    sp7C = func_8001F5B0(4, 0, "00");
    sp78 = (arg5->unk_00.unk_3C - sp7C) - 0x18;
    if (arg4 & 2) {
        sp84 = func_8002D444(D_883174B0, 1.4f);
    } else {
        sp84 = (0, D_883174B0);
    }

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    temp_a3 = ((sp84.r << 8) & 0xF800) | ((sp84.g << 3) & 0x7C0) | ((sp84.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a3 << 0x10) | temp_a3);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, (arg5->unk_00.unk_3C + arg0) - 1,
                     (arg1 + arg5->unk_00.unk_3E) - 2);

    temp_a0 = ((D_883174B4.r << 8) & 0xF800) | ((D_883174B4.g << 3) & 0x7C0) | ((D_883174B4.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg5->unk_00.unk_3C + arg0) - 1, arg1);

    temp_a0 = ((D_883174B4.r << 8) & 0xF800) | ((D_883174B4.g << 3) & 0x7C0) | ((D_883174B4.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0, (arg1 + arg5->unk_00.unk_3E) - 1, (arg5->unk_00.unk_3C + arg0) - 1,
                     (arg1 + arg5->unk_00.unk_3E) - 1);

    sprintf(sp74, "%d", arg3 + 1);

    func_8001F3F4();
    func_8001EBE0(4, 0);
    func_8001F324(0xF0, 0xF0, 0xF0, 0xFF);
    func_8001F1E8(((arg0 + sp7C) - func_8001F5B0(0, 0, sp74)) + 8, arg1 + 8, sp74);
    func_8001F324(arg2->unk_04->unk_04.r, arg2->unk_04->unk_04.g, arg2->unk_04->unk_04.b, arg2->unk_04->unk_04.a);
    func_8001EBE0(8, 0);
    sp70 = func_8002D7C0(NULL, 0, D_8831A4D4, arg2->unk_04->unk_00);
    func_8001F1E8(((sp78 - func_8001F5B0(0, 0, sp70)) / 2) + arg0 + sp7C + 0x10, arg1 + 4, sp70);
    func_8001F444();
}

void func_8830E4A4(unk_func_8830867C_03C* arg0, unk_func_8850878C* arg1, char* arg2) {
    arg1->unk_00.unk_10.unk_00 = ((arg0->unk_E0 - func_8001F5B0(8, 0, arg2)) / 2) + 6;
    arg1->unk_40 = arg2;
}

void func_8830E504(unk_func_8830867C_03C* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_883174B8 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_883174BC = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_883174C0 = { 0xA0, 0x96, 0x64, 0xFF };
    static Color_RGBA8 D_883174C4 = { 0xFF, 0xFF, 0x00, 0xFF };
    static s32 D_883174C8[] = { 0, 1, 2, 3, 4, 5, 7, 8, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A };

    s32 spCC;
    s32 i;
    s32 spC4;
    char* temp_v0_10;
    UNUSED s32 pad;
    unk_func_8830867C_03C* var_s1;
    unk_func_8830867C_03C* var_s1_2;
    s32 spB0;
    UNUSED s32 pad2;
    s32 temp_s1_3;
    s32 temp_v0_2;
    unk_func_885012A4* spA0;
    unk_func_88001300_000* sp98[2];
    s32 var_v1;
    s32 var_v1_2;
    unk_func_8850878C* temp_s0;
    unk_func_88001300_03C_01C* temp_s0_2;
    unk_func_8850BD40* temp_s0_3;
    unk_func_88503298* temp_s0_4;
    unk_func_8850B254* temp_s1;
    unk_func_88001300_000* temp_s1_4;
    unk_func_88001300_03C* ptr;
    unk_func_88507D4C* sp6C[2];
    unk_func_88001300_000* temp_s2_2;

    arg0->unk_E0 = func_8001F5B0(8, 0, "WWWWWWWW");
    spC4 = func_8001F5B0(4, 0, "00") + arg0->unk_E0 + 0x18;
    spB0 = 0;

    for (i = 0; i < 2; i++) {
        temp_v0_2 = func_8001F5B0(8, 0, func_8002D7C0(NULL, 0, D_8831A4C4, i + 0x49));
        if (spB0 < temp_v0_2) {
            spB0 = temp_v0_2;
        }
    }

    spCC = ((arg0->unk_E0 < spB0) ? spB0 : arg0->unk_E0) + spC4 + 0x30;
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8830867C_03C));

    arg0->unk_00.unk_20 = func_8830F0C8;
    arg0->unk_00.unk_24 = func_8830F09C;
    // clang-format off
    arg0->unk_00.unk_10.unk_00 = arg1; arg0->unk_00.unk_10.unk_02 = arg2;
    // clang-format on

    arg0->unk_4C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_03C_04C));
    func_8830F254(arg0->unk_4C, arg0);

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, spCC, 0x12C);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    temp_s1 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(func_8850B254))(temp_s1, 0, 0, spCC, 0x14, D_883174B8, D_883174BC);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, temp_s1);

    temp_s0 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(temp_s0, 8, 0, func_8002D7C0(NULL, 0, D_8831A4C4, 0x4B), 8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s1, temp_s0);

    spA0 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spA0, 0, 0x18, spCC, 0x114, D_883174C0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spA0);

    arg0->unk_50 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_03C));
    ((func8850C284)Memmap_GetFragmentVaddr(func_8850C284))(arg0->unk_50, 4, 1, arg4);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_4C, arg0->unk_50);

    for (i = 0; i < 2; i++) {
        sp98[i] = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
        ((func8850A40C)Memmap_GetFragmentVaddr(func_8850A40C))(sp98[i], 0xC, 0x1C + (i * 0x1C), arg0->unk_E0 + 0xC,
                                                               0x18);
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spA0, sp98[i]);

        arg0->unk_50->unk_18[i * arg0->unk_50->unk_2C] = sp98[i];

        arg0->unk_30[i].unk_00 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
        ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_30[i].unk_00, 6, 2, "----", 8);
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp98[i], arg0->unk_30[i].unk_00);
    }

    temp_s2_2 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func8850A40C)Memmap_GetFragmentVaddr(func_8850A40C))(temp_s2_2, 0xC, 0xC4, spB0 + 0xC, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spA0, temp_s2_2);
    ptr = arg0->unk_50;
    ptr->unk_18[2] = temp_s2_2;
    temp_v0_10 = func_8002D7C0(NULL, 0, D_8831A4C4, 0x49);
    temp_s1_3 = func_8001F5B0(8, 0, temp_v0_10);

    arg0->unk_44 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_44, ((spB0 - temp_s1_3) / 2) + 6, 2, temp_v0_10,
                                                           8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s2_2, arg0->unk_44);

    arg0->unk_48 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func8850A40C)Memmap_GetFragmentVaddr(func_8850A40C))(arg0->unk_48, 0xC, 0xE0, spB0 + 0xC, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spA0, arg0->unk_48);
    arg0->unk_50->unk_18[arg0->unk_50->unk_2C + 2] = arg0->unk_48;
    temp_v0_10 = func_8002D7C0(NULL, 0, D_8831A4C4, 0x4A);
    temp_s1_3 = func_8001F5B0(8, 0, temp_v0_10);

    arg0->unk_40 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_40, ((spB0 - temp_s1_3) / 2) + 6, 2, temp_v0_10,
                                                           8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_48, arg0->unk_40);
    ((func8850CAB4)Memmap_GetFragmentVaddr(func_8850CAB4))(arg0->unk_50);

    temp_s0_2 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_03C_01C));
    ((func88504570)Memmap_GetFragmentVaddr(func_88504570))(temp_s0_2, 0, 0, 0x10, 0x10, D_883174C4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spA0, temp_s0_2);
    arg0->unk_50->unk_1C = temp_s0_2;

    func_8002C740(&arg0->unk_D0, arg0->unk_58, 8, 0xF, 0xF);

    for (i = 0; i < 15; i++) {
        arg0->unk_58[i].unk_00 = D_883174C8[i];
        arg0->unk_58[i].unk_04 = ((func884000C4)Memmap_GetFragmentVaddr(func_884000C4))(D_883174C8[i]);
    }

    var_v1_2 = ((arg0->unk_E0 < spB0) ? spB0 : arg0->unk_E0) + 0x24;

    temp_s1_4 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func8850AB48)Memmap_GetFragmentVaddr(func_8850AB48))(temp_s1_4, var_v1_2, 0xA, spC4, 0x100);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spA0, temp_s1_4);

    arg0->unk_54 = mem_pool_alloc(arg4, sizeof(unk_func_8821421C_038_034));
    ((func88506DCC)Memmap_GetFragmentVaddr(func_88506DCC))(arg0->unk_54, 0, 0x10, func_8830E090, spC4, 0x1C, 8, arg4);
    ((func88506F8C)Memmap_GetFragmentVaddr(func_88506F8C))(arg0->unk_54, &arg0->unk_D0, arg4);

    temp_s0_3 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(temp_s0_3, arg0->unk_54);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_4C, temp_s0_3);

    sp6C[0] = mem_pool_alloc(arg4, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(sp6C[0], 0, 0, spC4, 0, arg0->unk_54);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s1_4, sp6C[0]);

    sp6C[1] = mem_pool_alloc(arg4, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(sp6C[1], 0, arg0->unk_54->unk_00.unk_00.unk_14.unk_02 + 0x10,
                                                           spC4, 1, arg0->unk_54);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s1_4, sp6C[1]);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s1_4, arg0->unk_54);

    temp_s0_4 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(func_88503298))(temp_s0_4, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, temp_s0_4);
}

void func_8830EE58(unk_func_8830867C_03C* arg0, unk_func_8830867C_02C_C54_01C* arg1) {
    static Color_RGBA8 D_88317504 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_88317508 = { 0xF0, 0xF0, 0xF0, 0x4D };
    static Color_RGBA8 D_8831750C = { 0x66, 0x5B, 0x47, 0xFF };

    s32 i;
    char* var_s3;

    ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0->unk_54);

    for (i = 0; i < 2; i++) {
        if (i < arg1->unk_00) {
            arg0->unk_30[i].unk_04 = arg1->unk_04[i];
            var_s3 =
                func_8002D7C0(NULL, 0, D_8831A4D4,
                              ((func884000C4)Memmap_GetFragmentVaddr(func_884000C4))(arg0->unk_30[i].unk_04)->unk_00);
            arg0->unk_30[i].unk_00->unk_30 =
                ((func884000C4)Memmap_GetFragmentVaddr(func_884000C4))(arg0->unk_30[i].unk_04)->unk_04;
            arg0->unk_30[i].unk_00->unk_44 = arg0->unk_30[i].unk_00->unk_44;
            arg0->unk_54->unk_00.unk_34[func_8002EDEC(arg0->unk_30[i].unk_04)] |= 2;
        } else {
            arg0->unk_30[i].unk_04 = -1;
            var_s3 = "----";
            arg0->unk_30[i].unk_00->unk_30 = (0, D_88317504);
            arg0->unk_30[i].unk_00->unk_44 = arg0->unk_30[i].unk_00->unk_44;
        }
        func_8830E4A4(arg0, arg0->unk_30[i].unk_00, var_s3);
    }

    if (arg1->unk_00 == 0) {
        arg0->unk_48->unk_28 |= 2;
        arg0->unk_40->unk_30 = (0, D_88317508);
        arg0->unk_40->unk_44 = arg0->unk_40->unk_44;
    } else {
        arg0->unk_48->unk_28 &= ~2;
        arg0->unk_40->unk_30 = (0, D_88317504);
        arg0->unk_40->unk_44 = arg0->unk_40->unk_44;
    }
}

void func_8830F05C(unk_func_8830867C_03C* arg0, unk_func_8830867C_02C_C54_01C* arg1) {
    s32 i;
    s32 var_v0 = 0;

    for (i = 0; i < 2; i++) {
        if (arg0->unk_30[i].unk_04 != -1) {
            arg1->unk_04[var_v0] = arg0->unk_30[i].unk_04;
            var_v0++;
        }
    }

    arg1->unk_00 = var_v0;
}

void func_8830F09C(unk_func_8830867C_03C* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_4C->unk_00.unk_14(arg0->unk_4C, arg1);
}

s32 func_8830F0C8(unk_func_8830867C_03C* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_4C->unk_00.unk_10(arg0->unk_4C, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_8830F114(unk_func_8830867C_03C* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_v0;
    s32 var_s0 = 0;

    ((func88507AE4)Memmap_GetFragmentVaddr(func_88507AE4))(arg0->unk_54, 0);
    ((func8850CB48)Memmap_GetFragmentVaddr(func_8850CB48))(arg0->unk_50, 0);

    arg0->unk_4C->unk_00.unk_14(arg0->unk_4C, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);

    while (var_s0 == NULL) {
        func_8002EEA8(var_s0);

        temp_v0 = arg0->unk_00.unk_20(arg0, arg1);

        if (!(temp_v0 & 1)) {
            if (temp_v0 & 2) {
                var_s0 = 1;
            } else if (temp_v0 & 4) {
                if (arg0->unk_50->unk_24 == 2) {
                    var_v0 = 1;
                } else {
                    var_v0 = 2;
                }
                var_s0 = var_v0 + 1;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(temp_v0);
    }
    arg0->unk_2C->unk_2C = 0xB;
    return var_s0 - 1;
}

void func_8830F254(unk_func_8830867C_03C_04C* arg0, unk_func_8830867C_03C* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(func_8850BDF0))(arg0);
    arg0->unk_00.unk_10 = func_8830F2A0;
    arg0->unk_24 = arg1;
}

s32 func_8830F2A0(unk_func_8830867C_03C_04C* arg0, Controller* arg1) {
    s32 var_t2;
    unk_func_8830867C_03C_04C* var_a0;
    s32 i;

    var_t2 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;
        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }

        var_t2 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

    if (var_t2 & 1) {
        return var_t2;
    }

    if (var_t2 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_t2 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_t2 = 0x80000004;
        }
    }

    if (var_t2 & 2) {
        if (arg0->unk_00.unk_1C == 1) {
            ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 0);
            var_t2 |= 1;
        }
    } else if (var_t2 & 4) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                switch (arg0->unk_24->unk_50->unk_24) {
                    case 2:
                    case 3:
                        break;

                    case 0:
                    case 1:
                        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                        var_t2 |= 1;
                        break;
                }
                break;

            case 1:
                if (arg0->unk_24->unk_54->unk_00.unk_34[arg0->unk_24->unk_54->unk_00.unk_38] & 2) {
                    var_t2 = (var_t2 & ~4) | 0x101;
                } else {
                    if (arg0->unk_24->unk_30[arg0->unk_24->unk_50->unk_24].unk_04 != -1) {
                        arg0->unk_24->unk_54->unk_00
                            .unk_34[func_8002EDEC(arg0->unk_24->unk_30[arg0->unk_24->unk_50->unk_24].unk_04)] &= ~2;
                    }
                    arg0->unk_24->unk_54->unk_00.unk_34[arg0->unk_24->unk_54->unk_00.unk_38] |= 2;

                    arg0->unk_24->unk_30[arg0->unk_24->unk_50->unk_24].unk_04 =
                        arg0->unk_24->unk_58[arg0->unk_24->unk_54->unk_00.unk_38].unk_00;
                    func_8830E4A4(
                        arg0->unk_24, arg0->unk_24->unk_30[arg0->unk_24->unk_50->unk_24].unk_00,
                        func_8002D7C0(NULL, 0, D_8831A4D4,
                                      arg0->unk_24->unk_58[arg0->unk_24->unk_54->unk_00.unk_38].unk_04->unk_00));
                    arg0->unk_24->unk_30[arg0->unk_24->unk_50->unk_24].unk_00->unk_30 =
                        arg0->unk_24->unk_58[arg0->unk_24->unk_54->unk_00.unk_38].unk_04->unk_04;
                    arg0->unk_24->unk_30[arg0->unk_24->unk_50->unk_24].unk_00->unk_44 =
                        arg0->unk_24->unk_30[arg0->unk_24->unk_50->unk_24].unk_00->unk_44;
                    arg0->unk_24->unk_50->unk_24++;
                    ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 0);
                    var_t2 |= 1;
                }
                break;
        }
    }
    return var_t2;
}

void func_8830F5DC(s32 arg0, s32 arg1, unk_func_88309C38_arg2* arg2, s32 arg3, s32 arg4,
                   unk_func_8821421C_038_034* arg5) {
    static Color_RGBA8 D_88317510 = { 0x54, 0x4B, 0x3A, 0xFF };
    static Color_RGBA8 D_88317514 = { 0x99, 0x89, 0x6A, 0xFF };

    Color_RGBA8 sp84;
    UNUSED s32 pad;
    s32 sp7C;
    s32 sp78;
    char sp74[4];
    char* sp70;
    UNUSED s32 pad2;
    s32 temp_a0;
    s32 temp_a3;

    sp7C = func_8001F5B0(4, 0, "000");
    sp78 = (arg5->unk_00.unk_3C - sp7C) - 0x18;
    if (arg4 & 2) {
        sp84 = func_8002D444(D_88317510, 1.4f);
    } else {
        sp84 = (0, D_88317510);
    }

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    temp_a3 = ((sp84.r << 8) & 0xF800) | ((sp84.g << 3) & 0x7C0) | ((sp84.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a3 << 0x10) | temp_a3);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, (arg5->unk_00.unk_3C + arg0) - 1,
                     (arg1 + arg5->unk_00.unk_3E) - 2);

    temp_a0 = ((D_88317514.r << 8) & 0xF800) | ((D_88317514.g << 3) & 0x7C0) | ((D_88317514.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg5->unk_00.unk_3C + arg0) - 1, arg1);

    temp_a0 = ((D_88317514.r << 8) & 0xF800) | ((D_88317514.g << 3) & 0x7C0) | ((D_88317514.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0, (arg1 + arg5->unk_00.unk_3E) - 1, (arg5->unk_00.unk_3C + arg0) - 1,
                     (arg1 + arg5->unk_00.unk_3E) - 1);

    sprintf(sp74, "%d", arg3 + 1);
    func_8001F3F4();
    func_8001EBE0(4, 0);
    func_8001F324(0xF0, 0xF0, 0xF0, 0xFF);
    func_8001F1E8(((arg0 + sp7C) - func_8001F5B0(0, 0, sp74)) + 8, arg1 + 8, sp74);

    sp84 = (((func884000C4)Memmap_GetFragmentVaddr(func_884000C4))(arg2->unk_01))->unk_04;
    func_8001F324(sp84.r, sp84.g, sp84.b, sp84.a);
    func_8001EBE0(8, 0);

    sp70 = func_8002D7C0(NULL, 0, D_8831A4CC, arg2->unk_00 - 1);
    func_8001F1E8(((sp78 - func_8001F5B0(0, 0, sp70)) / 2) + arg0 + sp7C + 0x10, arg1 + 4, sp70);
    func_8001F444();
}

void func_8830FA10(void) {
}

void func_8830FA18(void) {
}

void func_8830FA20(unk_func_8830867C_040* arg0, unk_func_8850878C* arg1, char* arg2) {
    arg1->unk_00.unk_10.unk_00 = ((arg0->unk_74 - func_8001F5B0(8, 0, arg2)) / 2) + 6;
    arg1->unk_40 = arg2;
}

void func_8830FA80(unk_func_8830867C_040* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_88317518 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_8831751C = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317520 = { 0xA0, 0x96, 0x64, 0xFF };
    static Color_RGBA8 D_88317524 = { 0xFF, 0xFF, 0x00, 0xFF };

    s32 spCC;
    s32 i;
    s32 spC4;
    unk_func_8850878C* temp_s0;
    unk_func_88001300_03C_01C* temp_s0_2;
    unk_func_8850BD40* temp_s0_3;
    unk_func_88503298* temp_s0_4;
    s32 spB0;
    s32 temp_s1_2;
    s32 temp_s1_3;
    s32 temp_v0_2;
    unk_func_885012A4* spA0;
    unk_func_88001300_000* sp90[4];
    unk_func_88001300_03C* ptr;
    s32 var_v1_2;
    char* temp_v0_10;
    UNUSED s32 pad[2];
    unk_func_8850B254* temp_s1;
    unk_func_88001300_000* temp_s1_4;
    unk_func_88001300_000* temp_s2_2;
    unk_func_88507D4C* sp68[2];
    s32* temp_s2_3;

    arg0->unk_74 = func_8001F5B0(8, 0, "WWWWWWWWWWWW");
    spC4 = func_8001F5B0(4, 0, "000") + arg0->unk_74 + 0x18;
    spB0 = 0;

    for (i = 0; i < 2; i++) {
        temp_v0_2 = func_8001F5B0(8, 0, func_8002D7C0(NULL, 0, D_8831A4C4, i + 0x49));
        if (spB0 < temp_v0_2) {
            spB0 = temp_v0_2;
        }
    }

    spCC = ((arg0->unk_74 < spB0) ? spB0 : arg0->unk_74) + spC4 + 0x30;
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8830867C_040));

    arg0->unk_00.unk_20 = func_8831067C;
    arg0->unk_00.unk_24 = func_88310650;
    // clang-format off
    arg0->unk_00.unk_10.unk_00 = arg1; arg0->unk_00.unk_10.unk_02 = arg2;
    // clang-format on

    arg0->unk_5C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_040_05C));
    func_88310808(arg0->unk_5C, arg0);

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, spCC, 0x12C);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    temp_s1 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(func_8850B254))(temp_s1, 0, 0, spCC, 0x14, D_88317518, D_8831751C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, temp_s1);

    temp_s0 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(temp_s0, 8, 0, func_8002D7C0(NULL, 0, D_8831A4C4, 0x4C), 8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s1, temp_s0);

    spA0 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spA0, 0, 0x18, spCC, 0x114, D_88317520);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spA0);

    arg0->unk_60 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_03C));
    ((func8850C284)Memmap_GetFragmentVaddr(func_8850C284))(arg0->unk_60, 6, 1, arg4);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_5C, arg0->unk_60);

    for (i = 0; i < 4; i++) {
        sp90[i] = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
        ((func8850A40C)Memmap_GetFragmentVaddr(func_8850A40C))(sp90[i], 0xC, (i + 1) * 0x1C, arg0->unk_74 + 0xC, 0x18);
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spA0, sp90[i]);
        arg0->unk_60->unk_18[i * arg0->unk_60->unk_2C] = sp90[i];

        arg0->unk_30[i].unk_00 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
        ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_30[i].unk_00, 6, 2, "-------", 8);
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp90[i], arg0->unk_30[i].unk_00);
    }

    temp_s2_2 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func8850A40C)Memmap_GetFragmentVaddr(func_8850A40C))(temp_s2_2, 0xC, 0xC4, spB0 + 0xC, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spA0, temp_s2_2);
    ptr = arg0->unk_60;
    ptr->unk_18[4] = temp_s2_2;
    temp_v0_10 = func_8002D7C0(NULL, 0, D_8831A4C4, 0x49);
    temp_s1_3 = func_8001F5B0(8, 0, temp_v0_10);

    arg0->unk_54 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_54, ((spB0 - temp_s1_3) / 2) + 6, 2, temp_v0_10,
                                                           8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s2_2, arg0->unk_54);

    arg0->unk_58 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func8850A40C)Memmap_GetFragmentVaddr(func_8850A40C))(arg0->unk_58, 0xC, 0xE0, spB0 + 0xC, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spA0, arg0->unk_58);
    arg0->unk_60->unk_18[arg0->unk_60->unk_2C + 4] = arg0->unk_58;
    temp_v0_10 = func_8002D7C0(NULL, 0, D_8831A4C4, 0x4A);
    temp_s1_3 = func_8001F5B0(8, 0, temp_v0_10);

    arg0->unk_50 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_50, ((spB0 - temp_s1_3) / 2) + 6, 2, temp_v0_10,
                                                           8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_58, arg0->unk_50);
    ((func8850CAB4)Memmap_GetFragmentVaddr(func_8850CAB4))(arg0->unk_60);

    temp_s0_2 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_03C_01C));
    ((func88504570)Memmap_GetFragmentVaddr(func_88504570))(temp_s0_2, 0, 0, 0x10, 0x10, D_88317524);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spA0, temp_s0_2);
    arg0->unk_60->unk_1C = temp_s0_2;

    temp_s2_3 = mem_pool_alloc(arg4, sizeof(s32) * 0xA4);

    for (i = 0; i < 0xA4; i++) {
        temp_s2_3[D_88317360[i]] = func_8002ED08(i + 1);
    }

    func_8002CBB0(&arg0->unk_68, temp_s2_3, 0xA4, 0xA4);

    var_v1_2 = ((arg0->unk_74 < spB0) ? spB0 : arg0->unk_74) + 0x24;

    temp_s1_4 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func8850AB48)Memmap_GetFragmentVaddr(func_8850AB48))(temp_s1_4, var_v1_2, 0xA, spC4, 0x100);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spA0, temp_s1_4);

    arg0->unk_64 = mem_pool_alloc(arg4, sizeof(unk_func_8821421C_038_034));
    ((func88506DCC)Memmap_GetFragmentVaddr(func_88506DCC))(arg0->unk_64, 0, 0x10, func_8830F5DC, spC4, 0x1C, 8, arg4);
    ((func88506F1C)Memmap_GetFragmentVaddr(func_88506F1C))(arg0->unk_64, &arg0->unk_68, arg4);

    temp_s0_3 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(temp_s0_3, arg0->unk_64);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_5C, temp_s0_3);

    sp68[0] = mem_pool_alloc(arg4, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(sp68[0], 0, 0, spC4, 0, arg0->unk_64);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s1_4, sp68[0]);

    sp68[1] = mem_pool_alloc(arg4, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(sp68[1], 0, arg0->unk_64->unk_00.unk_00.unk_14.unk_02 + 0x10,
                                                           spC4, 1, arg0->unk_64);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s1_4, sp68[1]);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s1_4, arg0->unk_64);

    temp_s0_4 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(func_88503298))(temp_s0_4, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, temp_s0_4);
}

void func_883103CC(unk_func_8830867C_040* arg0, unk_func_8830867C_02C_C54_024* arg1) {
    static Color_RGBA8 D_88317528 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_8831752C = { 0xF0, 0xF0, 0xF0, 0x4D };

    s32 i;
    char* var_s1;
    ret_func_8002ED08* temp_v0;

    ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0->unk_64);

    for (i = 0; i < 4; i++) {
        if (i < arg1->unk_04) {
            temp_v0 = func_8002ED08(arg1->unk_00[i]);
            arg0->unk_30[i].unk_04 = temp_v0;
            var_s1 = func_8002D7C0(NULL, 0, D_8831A4CC, temp_v0->unk_00[0] - 1);
            arg0->unk_30[i].unk_00->unk_30 =
                (((func884000C4)Memmap_GetFragmentVaddr(func_884000C4))(arg0->unk_30[i].unk_04[1]))->unk_04;
            arg0->unk_30[i].unk_00->unk_44 = arg0->unk_30[i].unk_00->unk_44;
            arg0->unk_64->unk_00.unk_34[D_88317360[arg0->unk_30[i].unk_04[0] - 1]] |= 2;
        } else {
            arg0->unk_30[i].unk_04 = NULL;
            var_s1 = "-------";
            arg0->unk_30[i].unk_00->unk_30 = (0, D_88317528);
            arg0->unk_30[i].unk_00->unk_44 = arg0->unk_30[i].unk_00->unk_44;
        }
        func_8830FA20(arg0, arg0->unk_30[i].unk_00, var_s1);
    }

    if (arg1->unk_04 == 0) {
        arg0->unk_58->unk_28 |= 2;
        arg0->unk_50->unk_30 = (0, D_8831752C);
        arg0->unk_50->unk_44 = arg0->unk_50->unk_44;
    } else {
        arg0->unk_58->unk_28 &= ~2;
        arg0->unk_50->unk_30 = (0, D_88317528);
        arg0->unk_50->unk_44 = arg0->unk_50->unk_44;
    }
}

void func_883105D4(unk_func_8830867C_040* arg0, unk_func_8830867C_02C_C54_024* arg1) {
    s32 var_v0 = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (arg0->unk_30[i].unk_04 != NULL) {
            arg1->unk_00[var_v0++] = arg0->unk_30[i].unk_04[0];
        }
    }

    arg1->unk_04 = var_v0;
}

void func_88310650(unk_func_8830867C_040* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_5C->unk_00.unk_14(arg0->unk_5C, arg1);
}

s32 func_8831067C(unk_func_8830867C_040* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_5C->unk_00.unk_10(arg0->unk_5C, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_883106C8(unk_func_8830867C_040* arg0, Controller* arg1) {
    s32 i;
    s32 temp_v0;
    s32 var_v0;
    s32 var_s0 = 0;

    ((func88507AE4)Memmap_GetFragmentVaddr(func_88507AE4))(arg0->unk_64, 0);
    ((func8850CB48)Memmap_GetFragmentVaddr(func_8850CB48))(arg0->unk_60, 0);
    arg0->unk_5C->unk_00.unk_14(arg0->unk_5C, 1);
    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);

    while (var_s0 == 0) {
        func_8002EEA8(var_s0);
        temp_v0 = arg0->unk_00.unk_20(arg0, arg1);

        if (!(temp_v0 & 1)) {
            if (temp_v0 & 2) {
                var_s0 = 1;
            } else if (temp_v0 & 4) {
                if (arg0->unk_60->unk_24 == 4) {
                    var_v0 = 1;
                } else {
                    var_v0 = 2;
                }
                var_s0 = var_v0 + 1;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(temp_v0);
    }

    arg0->unk_2C->unk_2C = 0xB;
    return var_s0 - 1;
}

void func_88310808(unk_func_8830867C_040_05C* arg0, unk_func_8830867C_040* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(func_8850BDF0))(arg0);
    arg0->unk_00.unk_10 = func_88310854;
    arg0->unk_24 = arg1;
}

#ifdef NON_MATCHING
s32 func_88310854(unk_func_8830867C_040_05C* arg0, Controller* arg1) {
    s32 var_t2;
    s32 i;
    unk_func_8830867C_040_05C* var_a0;
    unk_func_88205880_A030* ptr;
    u8* ptr2;

    var_t2 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;

        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }

        var_t2 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

    if (var_t2 & 1) {
        return var_t2;
    }

    if (var_t2 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_t2 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_t2 = 0x80000004;
        }
    }

    if (var_t2 & 2) {
        if (arg0->unk_00.unk_1C == 1) {
            ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 0);
            var_t2 |= 1;
        }
    } else if (var_t2 & 4) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                switch (arg0->unk_24->unk_60->unk_24) {
                    case 4:
                    case 5:
                        break;

                    case 0:
                    case 1:
                    case 2:
                    case 3:
                        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                        var_t2 |= 1;
                        break;
                }
                break;

            case 1:
                if (arg0->unk_24->unk_64->unk_00.unk_34[arg0->unk_24->unk_64->unk_00.unk_38] & 2) {
                    var_t2 = (var_t2 & ~4) | 0x101;
                } else {
                    if (arg0->unk_24->unk_30[arg0->unk_24->unk_60->unk_24].unk_04 != NULL) {
                        arg0->unk_24->unk_64->unk_00
                            .unk_34[D_88317360[arg0->unk_24->unk_30[arg0->unk_24->unk_60->unk_24].unk_04[0]]] &= ~2;
                    }
                    arg0->unk_24->unk_64->unk_00.unk_34[arg0->unk_24->unk_64->unk_00.unk_38] |= 2;

                    ptr = arg0->unk_24->unk_64->unk_00.unk_2C;
                    ptr2 = ptr->unk_00[arg0->unk_24->unk_64->unk_00.unk_38];
                    arg0->unk_24->unk_30[arg0->unk_24->unk_60->unk_24].unk_04 = ptr2;

                    func_8830FA20(arg0->unk_24, arg0->unk_24->unk_30[arg0->unk_24->unk_60->unk_24].unk_00,
                                  func_8002D7C0(NULL, 0, D_8831A4CC, ptr2[0] - 1));

                    arg0->unk_24->unk_30[arg0->unk_24->unk_60->unk_24].unk_00->unk_30 =
                        ((func884000C4)Memmap_GetFragmentVaddr(func_884000C4))(ptr2[1])->unk_04;
                    arg0->unk_24->unk_30[arg0->unk_24->unk_60->unk_24].unk_00->unk_44 =
                        arg0->unk_24->unk_30[arg0->unk_24->unk_60->unk_24].unk_00->unk_44;

                    arg0->unk_24->unk_60->unk_24++;
                    ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 0);
                    var_t2 |= 1;
                }
                break;
        }
    }
    return var_t2;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_1D7B40/func_88310854.s")
#endif

void func_88310B70(unk_func_88310B70* arg0, s32 arg1, s32 arg2, unk_func_8830867C_04C_030* arg3, MemoryPool* arg4) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88310B70));

    arg0->unk_00.unk_1C = func_88310C38;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_30, 0, 0, 0, 8);
    arg0->unk_30->unk_3C = 0x18;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_30);

    arg0->unk_2C = arg3;
}

s32 func_88310C38(unk_func_88310B70* arg0) {
    arg0->unk_30->unk_40 =
        func_8002D7C0(NULL, 0, D_8831A4C8, **(u8**)arg0->unk_2C->unk_2C->unk_00[arg0->unk_2C->unk_38].unk_00[0] - 1);
    return 0;
}

void func_88310CA4(s32 arg0, s32 arg1, unk_func_88310CA4_arg2* a2, s32 arg3, s32 arg4,
                   unk_func_8830867C_04C_030* arg5) {
    static Color_RGBA8 D_88317530[2] = {
        { 0x80, 0x79, 0x6C, 0xFF },
        { 0x67, 0x60, 0x53, 0xFF },
    };
    static Color_RGBA8 D_88317538 = { 0x99, 0x91, 0x81, 0xFF };
    static Color_RGBA8 D_8831753C = { 0xB4, 0x82, 0xDC, 0xFF };
    static Color_RGBA8 D_88317540[] = {
        { 0xF0, 0xF0, 0xF0, 0xFF },
        { 0xF0, 0xF0, 0xF0, 0x4D },
    };

    Color_RGBA8 sp8C;
    unk_func_88310CA4_arg2* arg2 = a2;
    char* sp84;
    s32 temp_a0;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_88317530[0].r << 8) & 0xF800) | ((D_88317530[0].g << 3) & 0x7C0) | ((D_88317530[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on
    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, arg0 + 0x105, (arg1 + arg5->unk_00.unk_14.unk_02) - 4);

    temp_a0 =
        ((D_88317530[1].r << 8) & 0xF800) | ((D_88317530[1].g << 3) & 0x7C0) | ((D_88317530[1].b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0 + 0x106, arg1 + 1, (arg0 + (u32)arg5->unk_00.unk_14.unk_00) - 1,
                     (arg1 + arg5->unk_00.unk_14.unk_02) - 2);

    temp_a0 = ((D_88317538.r << 8) & 0xF800) | ((D_88317538.g << 3) & 0x7C0) | ((D_88317538.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg5->unk_00.unk_14.unk_00 + arg0) - 1, arg1);

    temp_a0 = ((D_88317538.r << 8) & 0xF800) | ((D_88317538.g << 3) & 0x7C0) | ((D_88317538.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0, (arg1 + arg5->unk_00.unk_14.unk_02) - 1,
                     (arg5->unk_00.unk_14.unk_00 + arg0) - 1, (arg1 + arg5->unk_00.unk_14.unk_02) - 1);

    if (arg2 != NULL) {
        char sp30[0x10];

        sp8C = D_88317540[(arg4 & 4) ? 1 : 0];

        func_8001F3F4();
        func_8001F324(sp8C.r, sp8C.g, sp8C.b, sp8C.a);
        func_8001EBE0(8, 0);
        func_8001F1E8(arg0 + 0x19, arg1 + 4, func_8002D7C0(NULL, 0, D_8831A4D8, arg2->unk_00[0] - 1));

        if (arg2->unk_04[0] == 0x12) {
            sp84 = func_8002D7C0(NULL, 0, D_8831A4C4, 0x51);
            func_8001EBE0(8, 0);
            func_8001F1E8((((arg5->unk_00.unk_14.unk_00 - func_8001F5B0(0, 0, sp84)) - 0x106) / 2) + arg0 + 0x106,
                          arg1 + 4, sp84);
        } else if (arg2->unk_04[0] == 0x22) {
            sp84 = func_8002D7C0(NULL, 0, D_8831A4C4, 0x50);
            func_8001EBE0(8, 0);
            func_8001F1E8((((arg5->unk_00.unk_14.unk_00 - func_8001F5B0(0, 0, sp84)) - 0x106) / 2) + arg0 + 0x106,
                          arg1 + 4, sp84);
        } else {
            sp84 = func_8002D7C0(NULL, 0, D_8831A4C4, 0x4F);
            func_8001EBE0(8, 0);
            func_8001F1E8((((arg5->unk_00.unk_14.unk_00 - func_8001F5B0(0, 0, sp84)) - 0x106) / 2) + arg0 + 0x106,
                          arg1 + 4, sp84);
        }

        if (func_8002F264(arg2->unk_00[0]) == 0) {
            func_8001EBE0(8, 0);
            sprintf(sp30, "%s%02d", func_8002D7C0(NULL, 0, D_8831A4C4, 0x64), arg2->unk_00[1]);
            func_8001F1E8((arg0 - func_8001F5B0(0, 0, sp30)) + 0xED, arg1 + 4, sp30);
        }
        func_8001F444();
    }
}

void func_883112B0(unk_func_8830867C_04C* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_88317548 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_8831754C = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317550 = { 0x43, 0x35, 0x1C, 0xFF };
    static Color_RGBA8 D_88317554 = { 0xFF, 0xFF, 0xFF, 0xFF };
    static Color_RGBA8 D_88317558 = { 0x14, 0xF0, 0xB4, 0xFF };
    static Color_RGBA8 D_8831755C = { 0x71, 0xE9, 0xF9, 0xFF };
    static Color_RGBA8 D_88317560 = { 0x3C, 0x7B, 0x84, 0xFF };
    static Color_RGBA8 D_88317564 = { 0x93, 0xFA, 0x71, 0xFF };
    static Color_RGBA8 D_88317568 = { 0x51, 0x89, 0x3E, 0xFF };
    static Color_RGBA8 D_8831756C = { 0xFE, 0x73, 0xFE, 0xFF };
    static Color_RGBA8 D_88317570 = { 0x97, 0x44, 0x97, 0xFF };
    static Color_RGBA8 D_88317574 = { 0xFF, 0x73, 0x73, 0xFF };
    static Color_RGBA8 D_88317578 = { 0x83, 0x3B, 0x3B, 0xFF };

    UNUSED s32 pad[3];
    unk_func_8850B254* sp88;
    unk_func_8850878C* sp84;
    unk_func_88507D4C* sp80;
    unk_func_88507D4C* sp7C;
    unk_func_8850BD40* sp78;
    unk_func_885012A4* sp74;
    unk_func_8850878C* sp70;
    unk_func_8850878C* sp6C;
    unk_func_8850878C* sp68;
    unk_func_8850878C* sp64;
    unk_func_8850878C* sp60;
    unk_func_88310B70* sp5C;
    unk_func_8850BD40* sp58;
    unk_func_8850BD40* sp54;
    char** sp50;
    unk_func_8850BD40* sp4C;

    func_88312018(arg0, NULL);
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8830867C_04C));

    arg0->unk_00.unk_20 = func_8831286C;
    arg0->unk_00.unk_24 = func_883121F0;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_80 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_04C_080));
    func_88312298(arg0->unk_80, arg0);

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_04C_02C));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, 0x166, 0x118);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    sp88 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(func_8850B254))(sp88, 0, 0, 0x166, 0x14, D_88317548, D_8831754C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp88);
    arg0->unk_38[0] = '\0';

    sp84 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp84, 8, 0, arg0->unk_38, 8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp88, sp84);

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_04C_030));
    ((func88506DCC)Memmap_GetFragmentVaddr(func_88506DCC))(arg0->unk_30, 0, 0x28, func_88310CA4, 0x166, 0x1C, 5, arg4);
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_30, 0xAA, arg4);

    sp7C = mem_pool_alloc(arg4, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(sp7C, 0, 0x18, arg0->unk_30->unk_00.unk_14.unk_00, 0,
                                                           arg0->unk_30);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp7C);

    sp80 = mem_pool_alloc(arg4, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(sp80, 0, arg0->unk_30->unk_00.unk_14.unk_02 + 0x28,
                                                           arg0->unk_30->unk_00.unk_14.unk_00, 1, arg0->unk_30);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp80);

    sp78 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(sp78, arg0->unk_30);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_80, sp78);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_30);

    sp74 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp74, 0, 0xC4, 0x166, 0x54, D_88317550);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp74);

    arg0->unk_34 = mem_pool_alloc(arg4, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(func_88500994))(arg0->unk_34, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp74, arg0->unk_34);

    sp70 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp70, 0x12, 8, func_8002D7C0(NULL, 0, D_8831A4C4, 0x52), 8);
    sp70->unk_30 = (0, D_88317554);
    sp70->unk_44 = sp70->unk_44;
    sp70->unk_34 = (0, D_88317558);
    sp70->unk_44 = 1;
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_34, sp70);

    sp6C = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp6C, 0x17, 8, func_8002D7C0(NULL, 0, D_8831A4C4, 0x53), 8);
    sp6C->unk_30 = (0, D_8831755C);
    sp6C->unk_44 = sp6C->unk_44;
    sp6C->unk_34 = (0, D_88317560);
    sp6C->unk_44 = 1;
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_34, sp6C);

    sp68 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp68, 0x1C, 8, func_8002D7C0(NULL, 0, D_8831A4C4, 0x54), 8);
    sp68->unk_30 = (0, D_88317564);
    sp68->unk_44 = sp68->unk_44;
    sp68->unk_34 = (0, D_88317568);
    sp68->unk_44 = 1;
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_34, sp68);

    sp64 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp64, 0x21, 8, func_8002D7C0(NULL, 0, D_8831A4C4, 0x55), 8);
    sp64->unk_30 = (0, D_8831756C);
    sp64->unk_44 = sp64->unk_44;
    sp64->unk_34 = (0, D_88317570);
    sp64->unk_44 = 1;
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_34, sp64);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp60, 0x26, 8, func_8002D7C0(NULL, 0, D_8831A4C4, 0x56), 8);
    sp60->unk_30 = (0, D_88317574);
    sp60->unk_44 = sp60->unk_44;
    sp60->unk_34 = (0, D_88317578);
    sp60->unk_44 = 1;
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_34, sp60);

    sp5C = mem_pool_alloc(arg4, sizeof(unk_func_88310B70));
    func_88310B70(sp5C, 8, 0x20, arg0->unk_30, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp74, sp5C);

    sp58 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(sp58, arg0->unk_34);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_80, sp58);

    arg0->unk_78 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_04C_078));
    func_883092C8(arg0->unk_78, 0x35, arg0->unk_2C->unk_00.unk_14.unk_00, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_78);

    sp54 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(sp54, arg0->unk_78);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_80, sp54);

    sp50 = mem_pool_alloc(arg4, sizeof(char*) * 2);
    sp50[0] = func_8002D7C0(NULL, 0, D_8831A4C4, 0x57);
    sp50[1] = func_8002D7C0(NULL, 0, D_8831A4C4, 0x58);

    arg0->unk_7C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_030));
    func_8830BAC4(arg0->unk_7C, NULL, arg4);
    arg0->unk_7C->unk_4C = 0x280;
    arg0->unk_7C->unk_50 = 0x1E0;
    func_8830BCE8(arg0->unk_7C, sp50, 1);
    arg0->unk_7C->unk_30.unk_00 = arg0->unk_2C->unk_00.unk_14.unk_00 - 0x57;
    arg0->unk_7C->unk_30.unk_02 = 0xB4;
    arg0->unk_7C->unk_34.unk_00 = 0x20;
    arg0->unk_7C->unk_34.unk_02 = 0x10;
    func_8830BE3C(arg0->unk_7C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_7C);

    sp4C = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(sp4C, arg0->unk_7C);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_80, sp4C);

    arg0->unk_90 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(func_88503298))(arg0->unk_90, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_90);
}

s32 func_88311C64(s32 arg0, s32 arg1) {
    static unk_D_80070F84 D_8831757C[] = {
        {
            0x06,
            {
                0x4E,
                0x54,
                0x4E,
                0x64,
            },
            0x55,
            0x14,
            0x02,
            0x2D,
            0xD1,
            0x0A,
            {
                0x2D,
                0x34,
                0x2B,
                0x03,
            },
            {
                0xB5,
            },
            {
                0x43,
                0x4F,
                0xCE,
            },
            0xE3,
            {
                0x08,
                0x2E,
                0x00,
            },
        },
        {
            0x0C,
            {
                0x3C,
                0x2D,
                0x32,
                0x46,
            },
            0x50,
            0x07,
            0x02,
            0x2D,
            0xA0,
            0x5D,
            {
                0x00,
                0x00,
                0x00,
                0x00,
            },
            {
                0x2A,
            },
            {
                0x43,
                0x38,
                0xF0,
            },
            0x43,
            {
                0x28,
                0x42,
                0x00,
            },
        },
        {
            0x30,
            {
                0x3C,
                0x37,
                0x32,
                0x2D,
            },
            0x28,
            0x07,
            0x03,
            0xBE,
            0x4B,
            0x21,
            {
                0x32,
                0x00,
                0x00,
                0x00,
            },
            {
                0x20,
            },
            {
                0x03,
                0x38,
                0xD0,
            },
            0x03,
            {
                0x28,
                0x42,
                0x00,
            },
        },
        {
            0x31,
            {
                0x46,
                0x41,
                0x3C,
                0x5A,
            },
            0x5A,
            0x07,
            0x03,
            0x4B,
            0x8A,
            0x21,
            {
                0x32,
                0x4D,
                0x8D,
                0x00,
            },
            {
                0x2A,
            },
            {
                0x43,
                0x38,
                0xF0,
            },
            0x43,
            {
                0x28,
                0x42,
                0x00,
            },
        },
        {
            0x32,
            {
                0x0A,
                0x37,
                0x19,
                0x5F,
            },
            0x2D,
            0x04,
            0x04,
            0xFF,
            0x51,
            0x0A,
            {
                0x00,
                0x00,
                0x00,
                0x00,
            },
            {
                0xA0,
            },
            {
                0x03,
                0x08,
                0xCE,
            },
            0x02,
            {
                0x88,
                0x06,
                0x00,
            },
        },
        {
            0x33,
            {
                0x23,
                0x50,
                0x32,
                0x78,
            },
            0x46,
            0x04,
            0x04,
            0x32,
            0x99,
            0x0A,
            {
                0x2D,
                0x5B,
                0x00,
                0x00,
            },
            {
                0xA0,
            },
            {
                0x43,
                0x08,
                0xCE,
            },
            0x02,
            {
                0x88,
                0x06,
                0x00,
            },
        },
        {
            0x8D,
            {
                0x3C,
                0x73,
                0x69,
                0x50,
            },
            0x46,
            0x05,
            0x15,
            0x2D,
            0xC9,
            0x0A,
            {
                0x6A,
                0x47,
                0x00,
                0x00,
            },
            {
                0xB6,
            },
            {
                0x7F,
                0x0D,
                0xC0,
            },
            0x83,
            {
                0x08,
                0x16,
                0x00,
            },
        },
        {
            0x96,
            {
                0x6A,
                0x6E,
                0x5A,
                0x82,
            },
            0x9A,
            0x18,
            0x18,
            0x03,
            0xDC,
            0x5D,
            {
                0x32,
                0x81,
                0x5E,
                0x05,
            },
            {
                0xB1,
            },
            {
                0x7F,
                0xAF,
                0xF1,
            },
            0xAF,
            {
                0x38,
                0x63,
                0x00,
            },
        },
        {
            0x97,
            {
                0x64,
                0x64,
                0x64,
                0x64,
            },
            0x64,
            0x18,
            0x18,
            0x2D,
            0x40,
            0x01,
            {
                0x00,
                0x00,
                0x00,
                0x03,
            },
            {
                0xFF,
            },
            {
                0xFF,
                0xFF,
                0xFF,
            },
            0xFF,
            {
                0xFF,
                0x7F,
                0x00,
            },
        },
    };

    unk_D_80070F84* var_v1;
    s32 i;

    var_v1 = &D_80070FA0[arg0 - 1];

    if (func_80024F68(func_80029080()) == 7) {
        for (i = 0; i < 9; i++) {
            if (arg0 == D_8831757C[i].unk_00) {
                var_v1 = &D_8831757C[i];
            }
        }
    }
    return ((var_v1->unk_0F[arg1 / 8] >> (arg1 % 8)) & 1) != 0;
}

s32 func_88311D6C(s32 arg0, unk_func_8830867C_02C_0CC_000_008* arg1) {
    s32 i;
    s32 temp_v0;
    s32 var_s3;
    s32 var_s4;

    if (arg0 >= 0xC9) {
        var_s3 = arg0 - 0xC9;
    } else {
        var_s3 = arg0 - 0x92;
    }

    temp_v0 = func_8002ECDC(arg1);
    var_s4 = 0;
    for (i = 0; i < temp_v0; i++) {
        if (func_80022A28(var_s3) == arg1->unk_09[i]) {
            break;
        }
    }

    if (i < temp_v0) {
        var_s4 = 8;
    }

    if (func_88311C64(arg1->unk_00, var_s3) == 0) {
        var_s4 |= 0x10;
    }
    return var_s4;
}

s32 func_88311E28(unk_func_8830867C_02C_0CC_000_008* arg0) {
    s32 sp2C = 0;
    s32 temp_v0 = func_8002ECDC(arg0);
    s32 i;

    for (i = 0; i < temp_v0; i++) {
        if ((func_8002ED08(arg0->unk_09[i]) != NULL) && (arg0->unk_20[i] < 0xC0)) {
            break;
        }
    }

    if (i >= temp_v0) {
        sp2C = 4;
    }

    return sp2C;
}

s32 func_88311EB4(s32 arg0, unk_func_8830867C_02C_0CC_000_008* arg1) {
    s32 var_v1 = 0;

    switch (arg0) {
        case 35:
            if (arg1->unk_14 >= 0x6400) {
                var_v1 = 1;
            }
            break;

        case 36:
            if (arg1->unk_16 >= 0x6400) {
                var_v1 = 1;
            }
            break;

        case 37:
            if (arg1->unk_18 >= 0x6400) {
                var_v1 = 1;
            }
            break;

        case 38:
            if (arg1->unk_1A >= 0x6400) {
                var_v1 = 1;
            }
            break;

        case 39:
            if (arg1->unk_1C >= 0x6400) {
                var_v1 = 1;
            }
            break;

        case 40:
            if (arg1->unk_24 >= 0x64) {
                var_v1 = 2;
            }
            break;
    }
    return var_v1;
}

void func_88311F70(unk_func_8830867C_04C* arg0, unk_func_88200FA0_030_038* arg1) {
    s32 sp1C;
    s32 sp18;

    sp18 = arg0->unk_30->unk_38;
    sp1C = sp18 - (arg0->unk_30->unk_58 / arg0->unk_30->unk_3E);

    ((func88506EE4)Memmap_GetFragmentVaddr(func_88506EE4))(arg0->unk_30, arg1);
    ((func88507C0C)Memmap_GetFragmentVaddr(func_88507C0C))(arg0->unk_30, sp18, sp1C);
}

void func_88312018(unk_func_8830867C_04C* arg0, unk_func_80026268_arg0* arg1) {
    arg0->unk_88 = arg1;
}

void func_88312020(unk_func_8830867C_04C* arg0) {
    s32 i;
    s32 var_v0;
    unk_func_8830867C_04C_030_02C_000* var_s2 = arg0->unk_30->unk_2C->unk_00;

    for (i = 0; i < arg0->unk_30->unk_2C->unk_08; i++) {
        if (var_s2->unk_00[i]->unk_08 >= 0x64) {
            var_v0 = func_88311D6C(**(u8**)&var_s2->unk_00[i]->unk_00, arg0->unk_88);
        } else if (var_s2->unk_00[i]->unk_08 >= 0x32) {
            var_v0 = func_88311E28(arg0->unk_88);
        } else {
            var_v0 = func_88311EB4(**(u8**)&var_s2->unk_00[i]->unk_00, arg0->unk_88);
        }

        if (var_v0 != 0) {
            arg0->unk_30->unk_34[i] |= 4;
        }
    }
}

void func_88312108(unk_func_8830867C_04C* arg0) {
    u32 sp1C;

    if (arg0->unk_88 != NULL) {
        sp1C = 0x4D;
        func_8002D5D4(0x19, func_8002D7C0(NULL, 0, D_8831A4D0, arg0->unk_88->unk_00.unk_00 - 1));
    } else {
        sp1C = 0x4E;
    }
    func_8002D7C0(arg0->unk_38, 0x40, D_8831A4C4, sp1C);
}

void func_88312188(unk_func_8830867C_04C* arg0, s32 arg1) {
    arg0->unk_8C = arg1;

    if (arg1 != 0) {
        arg0->unk_90->unk_00.unk_28 &= ~1;
    } else {
        arg0->unk_90->unk_00.unk_28 |= 1;
    }

    func_88312108(arg0);

    if (arg1 == 0) {
        func_88312020(arg0);
    }
}

void func_883121F0(unk_func_8830867C_04C* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_80->unk_00.unk_14(arg0->unk_80, arg1);
}

s32 func_8831221C(unk_func_8830867C_04C* arg0, s32* arg1) {
    s32 sp1C = 0;
    unk_func_8830867C_04C_030_02C_000_000* ptr = arg0->unk_30->unk_2C->unk_00[arg0->unk_30->unk_38].unk_00[0];

    if (ptr->unk_08 >= 0x64) {
        sp1C = 0;
        if (func_8002ECDC(arg1) >= 4) {
            sp1C = 2;
        }
    } else if (ptr->unk_08 >= 0x32) {
        sp1C = 1;
    }
    return sp1C;
}

void func_88312298(unk_func_8830867C_04C_080* arg0, unk_func_8830867C_04C* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(func_8850BDF0))(arg0);
    arg0->unk_00.unk_10 = func_883125B4;
    arg0->unk_24 = arg1;
}

s32 func_883122E4(unk_func_8830867C_04C_080* arg0) {
    s32 sp24 = 0;

    if (arg0->unk_24->unk_8C != 0) {
        func_88312018(arg0->unk_24, NULL);
        ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_24->unk_34, 1);
        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
        sp24 = 1;
    } else {
        ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_24->unk_34, 0);
        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 0);
    }
    return sp24;
}

s32 func_8831239C(unk_func_8830867C_04C_080* arg0) {
    s32 sp24 = 0;

    switch (arg0->unk_24->unk_84) {
        case 0:
            sp24 = func_883122E4(arg0);
            break;

        case 1:
            ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 2);
            ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_24->unk_34, 2);
            break;

        case 2:
            ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 2);
            ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_24->unk_34, 3);
            break;
    }

    func_8830C048(arg0->unk_24->unk_7C);
    return sp24;
}

void func_8831247C(unk_func_8830867C_04C_080* arg0) {
    arg0->unk_24->unk_84 = func_8831221C(arg0->unk_24, arg0->unk_24->unk_88);
    if (arg0->unk_24->unk_84 > 0) {
        func_883094CC(arg0->unk_24->unk_78, arg0->unk_24->unk_88);
        if (arg0->unk_24->unk_84 == 1) {
            func_88309614(arg0->unk_24->unk_78);
            ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_24->unk_34, 2);
        } else if (arg0->unk_24->unk_84 == 2) {
            func_883096BC(arg0->unk_24->unk_78);
            ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_24->unk_34, 3);
        }
        func_88309774(arg0->unk_24->unk_78);
        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 2);
    } else {
        ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_24->unk_34, 4);
        func_8830BFE0(arg0->unk_24->unk_7C, 0);
        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 3);
    }
}

s32 func_883125B4(unk_func_8830867C_04C_080* arg0, Controller* arg1) {
    s32 i;
    s32 var_s0;
    unk_func_8830867C_04C_080* var_a0;

    var_s0 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;
        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }
        var_s0 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

    if (var_s0 & 1) {
        return var_s0;
    }

    if (var_s0 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_s0 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_s0 = 0x80000004;
        }
    }

    if (var_s0 & 2) {
        switch (arg0->unk_00.unk_1C) {
            case 2:
                func_883097D4(arg0->unk_24->unk_78);
                if (func_883122E4(arg0) == 0) {
                    var_s0 |= 1;
                }
                break;

            case 3:
                if (func_8831239C(arg0) == 0) {
                    var_s0 |= 1;
                }
                break;
        }
    } else if (var_s0 & 4) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                if (arg0->unk_24->unk_8C != 0) {
                    ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_24->unk_34, 1);
                    ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                } else {
                    if (arg0->unk_24->unk_30->unk_34[arg0->unk_24->unk_30->unk_38] & 4) {
                        var_s0 = (var_s0 & ~4) | 0x100;
                    } else {
                        func_8831247C(arg0);
                        var_s0 |= 1;
                    }
                }
                break;

            case 2:
                ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_24->unk_34, 4);
                func_8830BFE0(arg0->unk_24->unk_7C, 0);
                ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 3);
                var_s0 |= 1;
                break;

            case 3:
                switch (arg0->unk_24->unk_7C->unk_3C->unk_38) {
                    case 0:
                        func_80048B90(0x22);
                        func_80048B90(0x0120000D);
                        var_s0 &= 0x7FFFFFFF;
                        break;

                    case 1:
                        var_s0 = (var_s0 & ~4) | 2;
                        if (func_8831239C(arg0) == 0) {
                            var_s0 |= 1;
                        }
                        break;
                }
                break;
        }
    }

    return var_s0;
}

s32 func_8831286C(unk_func_8830867C_04C* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_80->unk_00.unk_10(arg0->unk_80, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void func_883128B8(unk_func_8830867C_04C* arg0) {
    arg0->unk_00.unk_24(&arg0->unk_00, 1);
    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);
}

void func_883128FC(unk_func_8830867C_04C* arg0) {
    if (arg0->unk_7C->unk_2C->unk_00.unk_28 & 1) {
        arg0->unk_7C->unk_2C->unk_2C = 0xB;
    }

    if (arg0->unk_78->unk_2C->unk_00.unk_28 & 1) {
        arg0->unk_78->unk_2C->unk_2C = 0xB;
    }

    arg0->unk_2C->unk_2C = 0xB;
    ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0->unk_80, 0);
    ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_34, 0);
}

s32 func_88312998(unk_func_8830867C_04C* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_s0 = 0;

    if (arg0->unk_80->unk_00.unk_1C == 0) {
        func_883128B8(arg0);
    }

    if (arg0->unk_80->unk_00.unk_1C == 1) {
        if (arg0->unk_88 == NULL) {
            ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0->unk_80, 0);
            ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_34, 0);
        } else {
            func_8831247C(arg0->unk_80);
        }
    }

    while (var_s0 == 0) {
        func_8002EEA8(var_s0);

        temp_v0 = arg0->unk_00.unk_20(arg0, arg1);
        if (!(temp_v0 & 1)) {
            if (temp_v0 & 2) {
                if (arg0->unk_80->unk_00.unk_1C == 1) {
                    var_s0 = 3;
                } else {
                    var_s0 = 1;
                }
            } else if (temp_v0 & 4) {
                if (arg0->unk_80->unk_00.unk_1C == 1) {
                    var_s0 = 3;
                } else {
                    var_s0 = 2;
                }
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(temp_v0);
    }

    if (var_s0 != 3) {
        func_883128FC(arg0);
    }
    return var_s0 - 1;
}

void func_88312B10(s32 arg0, s32 arg1, unk_func_88309160_arg2* arg2, s32 arg3, s32 arg4,
                   unk_func_88200FA0_030_030_1CEA00* arg5) {
    static Color_RGBA8 D_8831764C = { 0xFF, 0xB2, 0xC3, 0xFF };
    static Color_RGBA8 D_88317650[] = {
        { 0xF0, 0xF0, 0xF0, 0xFF },
        { 0xF0, 0xF0, 0xF0, 0x4D },
        { 0xFF, 0xB2, 0xC3, 0xFF },
    };

    Color_RGBA8 sp34;
    s32 var_v0;
    char* sp2C;
    char sp28[4];

    sp2C = func_8002D7C0(NULL, 0, D_8831A4C4, 0x5F);
    if (arg4 & 4) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }

    sp34 = D_88317650[var_v0];

    func_8001F3F4();
    func_8001F324(sp34.r, sp34.g, sp34.b, sp34.a);
    func_8001EBE0(8, 0);
    func_8001F1E8(arg0 + 8, arg1 + 2, sp2C);

    sprintf(sp28, "%d", arg3 + 1);

    func_8001F1E8(((arg0 + func_8001F5B0(0, 0, sp2C) + func_8001F5B0(0, 0, " 00")) - func_8001F5B0(0, 0, sp28)) + 8,
                  arg1 + 2, sp28);
    func_8001F444();
    func_883099D8((arg5->unk_00.unk_14.unk_00 + arg0) - 0x35, arg1 + 8, arg2->unk_18, arg2->unk_14);
}

void func_88312C7C(s32 arg0, s32 arg1, unk_func_88309160_arg2* arg2, s32 arg3, s32 arg4,
                   unk_func_88200FA0_030_030_1CEA00* arg5) {
    static Color_RGBA8 D_8831765C[] = {
        { 0xF0, 0xF0, 0xF0, 0xFF },
        { 0xF0, 0xF0, 0xF0, 0x4D },
    };

    Color_RGBA8 sp2C;
    UNUSED s32 pad[2];
    s32 var_v0;

    if (arg4 & 4) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }

    sp2C = D_8831765C[var_v0];

    func_8001F3F4();
    func_8001F324(sp2C.r, sp2C.g, sp2C.b, sp2C.a);
    func_8001EBE0(8, 0);
    func_8001F1E8(arg0 + 8, arg1 + 4, func_8002D7C0(NULL, 0, D_8831A4C4, arg3 + 0x3B));
    func_8001F444();
    if (arg2->unk_14 == 1) {
        func_883099D8((arg5->unk_00.unk_14.unk_00 + arg0) - 0x35, arg1 + 0xC, arg2->unk_0C->unk_18,
                      arg2->unk_0C->unk_14);
    }
}

void func_88312D7C(unk_func_8830867C_048* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_88317664 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88317668 = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_8831766C = { 0xA0, 0x96, 0x64, 0xFF };
    static Color_RGBA8 D_88317670 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88317674 = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317678 = { 0xA0, 0x96, 0x64, 0xFF };

    UNUSED s32 pad[2];
    s32 spBC;
    UNUSED s32 pad3;
    unk_func_8850B254* spB4;
    unk_func_8850878C* spB0;
    unk_func_885012A4* spAC;
    unk_func_8850BD40* spA8;
    UNUSED s32 pad4;
    s32 spA0;
    s32 temp_v0_2;
    s32 sp98;
    UNUSED s32 pad5;
    char* sp90;
    char* sp8C;
    s32 sp88;
    s32 sp84;
    unk_func_8850B254* sp80;
    unk_func_8850878C* sp7C;
    unk_func_885012A4* sp78;
    unk_func_88001300_000* sp74;
    unk_func_8850BD40* sp70;
    unk_func_8850BD40* sp6C;
    unk_func_88503298* sp68;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8830867C_048));

    arg0->unk_00.unk_20 = func_88313B90;
    arg0->unk_00.unk_24 = func_88313B64;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_48 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_048_048));
    func_88313C24(arg0->unk_48, arg0);
    spBC = func_8830AC0C();

    func_883139E8(arg0, 0, 0);
    temp_v0_2 = func_8001F5B0(8, 0, arg0->unk_50);
    if (spBC < temp_v0_2) {
        spBC = temp_v0_2;
    }

    func_883139E8(arg0, 1, 0xB);
    temp_v0_2 = func_8001F5B0(8, 0, arg0->unk_50);
    if (spBC < temp_v0_2) {
        spBC = temp_v0_2;
    }

    func_883139E8(arg0, 2, 0xB);
    temp_v0_2 = func_8001F5B0(8, 0, arg0->unk_50);
    if (spBC < temp_v0_2) {
        spBC = temp_v0_2;
    }

    spBC += 0x10;

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, spBC, 0x8C);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    spB4 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(func_8850B254))(spB4, 0, 0, spBC, 0x2C, D_88317664, D_88317668);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spB4);
    arg0->unk_50[0] = '\0';

    spB0 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(spB0, 8, 0, arg0->unk_50, 8);
    spB0->unk_3C = 0x18;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spB4, spB0);

    spAC = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spAC, 0, 0x30, spBC, 0x5C, D_8831766C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spAC);

    arg0->unk_34 = mem_pool_alloc(arg4, sizeof(unk_func_88200FA0_030_030_1CEA00));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_34, 0, 4, func_88312C7C, spBC, 0x1C, 3, 1, arg4);
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_34, 3, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spAC, arg0->unk_34);

    spA8 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(spA8, arg0->unk_34);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_48, spA8);

    arg0->unk_4C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_048_04C));
    ((func8850CBA8)Memmap_GetFragmentVaddr(func_8850CBA8))(arg0->unk_4C);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_48, arg0->unk_4C);

    spA0 = func_88309DC8();
    sp90 = func_8002D7C0(NULL, 0, D_8831A4C4, 0x60);
    sp8C = func_8002D7C0(NULL, 0, D_8831A4C4, 0x61);
    sp88 = func_8001F5B0(8, 0, sp90);
    sp84 = func_8001F5B0(8, 0, sp8C);

    sp98 = spA0;
    if (spA0 < sp88) {
        sp98 = sp88;
    }

    if (sp98 < sp84) {
        sp98 = sp84;
    }
    sp98 += 0x10;
    spA0 += 0x10;

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_30, arg0->unk_2C->unk_00.unk_14.unk_00 + 0x10, 0,
                                                           sp98, 0x140);
    arg0->unk_30->unk_00.unk_28 |= 0x200;
    arg0->unk_30->unk_00.unk_28 |= 0x400;
    arg0->unk_30->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_30);

    sp80 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(func_8850B254))(sp80, 0, 0, sp98, 0x14, D_88317670, D_88317674);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_30, sp80);

    arg0->unk_40 = mem_pool_alloc(arg4, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(func_88500994))(arg0->unk_40, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp80, arg0->unk_40);

    sp7C = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp7C, 0, 0, "", 8);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_40, sp7C);

    sp7C = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp7C, (sp98 - sp88) / 2, 0, sp90, 8);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_40, sp7C);

    sp7C = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp7C, (sp98 - sp84) / 2, 0, sp8C, 8);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_40, sp7C);

    sp78 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp78, 0, 0x18, sp98, 0x128, D_88317678);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_30, sp78);

    arg0->unk_44 = mem_pool_alloc(arg4, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(func_88500994))(arg0->unk_44, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp78, arg0->unk_44);

    sp74 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(sp74, 0x2C);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_44, sp74);

    arg0->unk_38[0] = mem_pool_alloc(arg4, sizeof(unk_func_88200FA0_030_030_1CEA00));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_38[0], (sp98 - spA0) / 2, 4, func_88312B10, spA0,
                                                           0x18, 0xC, 1, arg4);
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_38[0], 0xC, arg4);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_44, arg0->unk_38[0]);

    sp70 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(sp70, arg0->unk_38[0]);
    ((func8850CC74)Memmap_GetFragmentVaddr(func_8850CC74))(arg0->unk_4C, sp70);

    arg0->unk_38[1] = mem_pool_alloc(arg4, sizeof(unk_func_88200FA0_030_030_1CEA00));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_38[1], 0, 4, func_88312B10, spA0, 0x18, 0xC, 1,
                                                           arg4);
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_38[1], 0xC, arg4);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_44, arg0->unk_38[1]);

    sp6C = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(sp6C, arg0->unk_38[1]);
    ((func8850CC74)Memmap_GetFragmentVaddr(func_8850CC74))(arg0->unk_4C, sp6C);

    sp68 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(func_88503298))(sp68, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, sp68);
}

void func_88313740(unk_func_8830867C_048* arg0, unk_func_8830867C_02C_144* arg1) {
    unk_func_8830867C_02C_144_000_alt* sp24;

    ((func885063B8)Memmap_GetFragmentVaddr(func_885063B8))(arg0->unk_34, arg1);
    sp24 = arg1->unk_00;
    ((func885063B8)Memmap_GetFragmentVaddr(func_885063B8))(arg0->unk_38[0], &sp24->unk_2C);
    ((func885063B8)Memmap_GetFragmentVaddr(func_885063B8))(arg0->unk_38[1], &sp24->unk_4C);
}

typedef struct unk_func_88313894 {
    /* 0x00 */ char unk00[0xC];
    /* 0x0C */ unk_func_8830867C_02C_0CC_000_000* unk_0C;
    /* 0x10 */ char unk10[0xC];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ unk_func_88313894_020 unk_20;
    /* 0x40 */ unk_func_88313894_020 unk_40;
} unk_func_88313894; // size >= 0x60

void func_883137C4(unk_func_88200FA0_030_030_1CEA00* arg0, unk_func_8830867C_02C_0CC_000* arg1,
                   unk_func_88313894_020* arg2) {
    unk_func_8830867C_02C_0CC_000_000* sp24 = arg2->unk_0C;
    s32 i;

    ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0);

    for (i = 0; i < arg2->unk_14; i++, sp24++) {
        if (sp24 == arg1->unk_00) {
            arg0->unk_34[i] |= 4;
        } else if (sp24->unk_10.unk_08 >= arg2->unk_1C) {
            arg0->unk_34[i] |= 4;
        }
    }
}

void func_88313894(unk_func_8830867C_048* arg0, unk_func_8830867C_02C_0CC_000* arg1) {
    u16* temp_v0_2;
    u16* temp_v0_3;
    unk_func_88313894* temp_s1;
    unk_func_8830867C_02C_0CC_000_000* temp_v0;

    temp_s1 = arg0->unk_34->unk_2C->unk_00;
    ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0->unk_34);

    temp_v0 = temp_s1->unk_0C;
    if (temp_v0 == arg1->unk_00) {
        arg0->unk_34->unk_34[0] |= 4;
    } else if (temp_v0->unk_10.unk_08 >= temp_s1->unk_1C) {
        arg0->unk_34->unk_34[0] |= 4;
    }

    func_883137C4(arg0->unk_38[0], arg1, &temp_s1->unk_20);
    func_883137C4(arg0->unk_38[1], arg1, &temp_s1->unk_40);
}

void func_88313950(char* arg0, s32 arg1, s32 arg2) {
    static u16 D_8831767C[4] = { 0x3B, 0x62, 0x63, 0 };

    HAL_Strcpy(arg0, func_8002D7C0(NULL, 0, D_8831A4C4, D_8831767C[arg1]));
    if (arg1 != 0) {
        sprintf(&arg0[strlen(arg0)], " %d", arg2 + 1);
    }
}

void func_883139E8(unk_func_8830867C_048* arg0, s32 arg1, s32 arg2) {
    char sp18[32];

    func_88313950(sp18, arg1, arg2);
    func_8002D5D4(0x25, sp18);
    func_8002D7C0(arg0->unk_50, 0x80, D_8831A4C4, 0x3A);
}

void func_88313A34(unk_func_8830867C_048* arg0) {
    s32 sp24 = arg0->unk_34->unk_38;

    ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_44, sp24);
    ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_40, sp24);
}

void func_88313A94(unk_func_8830867C_048* arg0) {
    ((func88506CE4)Memmap_GetFragmentVaddr(func_88506CE4))(arg0->unk_34);
    ((func88506CE4)Memmap_GetFragmentVaddr(func_88506CE4))(arg0->unk_38[0]);
    ((func88506CE4)Memmap_GetFragmentVaddr(func_88506CE4))(arg0->unk_38[1]);
    func_88313A34(arg0);
    ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0->unk_48, 0);

    arg0->unk_48->unk_00.unk_14(arg0->unk_48, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);
    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_30);
}

void func_88313B4C(unk_func_8830867C_048* arg0) {
    arg0->unk_2C->unk_2C = 0xB;
    arg0->unk_30->unk_2C = 0xB;
}

void func_88313B64(unk_func_8830867C_048* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_48->unk_00.unk_14(arg0->unk_48, arg1);
}

s32 func_88313B90(unk_func_8830867C_048* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_48->unk_00.unk_10(arg0->unk_48, arg1);
        if (!(var_v1 & 1)) {
            if (var_v1 & 2) {
                func_88313B4C(arg0);
            } else if (var_v1 & 4) {
                func_88313B4C(arg0);
            }
        }
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void func_88313C24(unk_func_8830867C_048_048* arg0, unk_func_8830867C_048* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(func_8850BDF0))(arg0);
    arg0->unk_00.unk_10 = func_88313C70;
    arg0->unk_24 = arg1;
}

s32 func_88313C70(unk_func_8830867C_048_048* arg0, Controller* arg1) {
    s32 var_a2;
    s32 i;
    unk_func_8830867C_048_048* var_a0;
    unk_func_88200FA0_030_030_1CEA00* temp_v0_4;

    var_a2 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;

        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }

        var_a2 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

    switch (arg0->unk_00.unk_1C) {
        case 0:
            if (var_a2 & 1) {
                if (var_a2 & 8) {
                    func_88313A34(arg0->unk_24);
                }
            } else if (arg1->buttonPressed & 0x8000) {
                if (arg0->unk_24->unk_34->unk_38 != 0) {
                    ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0->unk_24->unk_4C,
                                                                           arg0->unk_24->unk_34->unk_38 - 1);
                    ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                    var_a2 |= 1;
                }
                var_a2 |= 0x80000004;
            } else if (arg1->buttonPressed & 0x4000) {
                var_a2 |= 0x80000002;
            }
            break;

        case 1:
            if (!(var_a2 & 1)) {
                if (arg1->buttonPressed & 0x8000) {
                    temp_v0_4 = arg0->unk_24->unk_38[arg0->unk_24->unk_34->unk_38 - 1];
                    if (temp_v0_4->unk_34[temp_v0_4->unk_38] & 4) {
                        var_a2 = 0x80000101;
                    } else {
                        var_a2 = 0x80000004;
                    }
                } else if (arg1->buttonPressed & 0x4000) {
                    ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 0);
                    var_a2 = 0x80000003;
                }
            }
            break;
    }
    return var_a2;
}

s32 func_88313E50(unk_func_8830867C_048* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1 = 0;

    func_88313A94(arg0);

    while (var_s1 == 0) {
        func_8002EEA8(var_s1);

        var_s0 = arg0->unk_00.unk_20(arg0, arg1);
        if (!(var_s0 & 1)) {
            if (var_s0 & 2) {
                var_s1 = 1;
            } else if (var_s0 & 4) {
                var_s0 = 0x80000801;
                var_s1 = 2;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(var_s0);
    }

    func_88313B4C(arg0);
    return var_s1 - 1;
}

void func_88313F24(s32 arg0, s32 arg1, s8* arg2, s32 arg3) {
    static Color_RGBA8 D_88317684 = { 0xF0, 0xF0, 0xF0, 0xFF };

    func_8001F3F4();
    func_8001F324(D_88317684.r, D_88317684.g, D_88317684.b, D_88317684.a);
    func_8001EBE0(8, 0);
    func_8001F1E8(arg0 + 8, arg1 + 4, arg2);
    func_8001F444();
}

void func_88313FA0(unk_func_8830867C_02C_0B4* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    static Color_RGBA8 D_88317688 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_8831768C = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317690 = { 0xA0, 0x96, 0x64, 0xFF };

    UNUSED s32 pad;
    s32 sp68;
    UNUSED s32 pad2[2];
    s32 sp5C;
    s32 temp_v1;
    unk_func_8850B254* sp54;
    char* sp50;
    unk_func_8850878C* sp4C;
    unk_func_885012A4* sp48;

    sp54 = mem_pool_alloc(arg3, sizeof(unk_func_8850B254));
    sp50 = func_8002D7C0(NULL, 0, D_8831A4C4, 0x59);

    sp4C = mem_pool_alloc(arg3, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp4C, 8, 0, sp50, 8);
    temp_v1 = func_8001F5B0(8, 0, sp50) + 0x10;
    sp68 = temp_v1;
    sp5C = temp_v1;
    ((func8850B254)Memmap_GetFragmentVaddr(func_8850B254))(sp54, 0, 0, sp5C, 0x14, D_88317688, D_8831768C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp54, sp4C);
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, 0x40);

    arg0->unk_00.unk_20 = func_883142F4;
    arg0->unk_00.unk_10.unk_00 = (arg2 - sp5C) / 2;
    arg0->unk_00.unk_10.unk_02 = arg1;

    arg0->unk_2C = mem_pool_alloc(arg3, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, sp5C, 0x58);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp54);

    sp48 = mem_pool_alloc(arg3, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp48, 0, 0x18, sp5C, 0x40, D_88317690);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp48);

    arg0->unk_30 = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_02C_0B4_030));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_30, 0, 4, func_88313F24, sp68, 0x1C, 2, 1, arg3);

    func_8002CBC0(&arg0->unk_34, 2, arg3);
    func_8002CC2C(&arg0->unk_34, func_8002D7C0(NULL, 0, D_8831A4C4, 0x5A), 0);
    func_8002CC2C(&arg0->unk_34, func_8002D7C0(NULL, 0, D_8831A4C4, 0x5B), 1);

    ((func88506384)Memmap_GetFragmentVaddr(func_88506384))(arg0->unk_30, &arg0->unk_34, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp48, arg0->unk_30);
}

s32 func_883142F4(unk_func_8830867C_02C_0B4* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_88314340(unk_func_8830867C_02C_0B4* arg0, Controller* arg1) {
    s32 temp_v0_3;
    s32 var_s0;
    s32 var_s1 = 0;

    ((func88506BFC)Memmap_GetFragmentVaddr(func_88506BFC))(arg0->unk_30, 0);

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);

    while (var_s1 == 0) {
        func_8002EEA8(var_s1);

        var_s0 = arg0->unk_00.unk_20(arg0, arg1);

        if (!(var_s0 & 1)) {
            if (arg1->buttonPressed & 0x4000) {
                var_s0 = 0x80000003;
                var_s1 = 2;
            } else if (arg1->buttonPressed & 0x8000) {
                temp_v0_3 = arg0->unk_30->unk_38;
                var_s1 = temp_v0_3 + 1;
                if (temp_v0_3 == 0) {
                    var_s0 = 4;
                } else {
                    var_s0 = 2;
                }
                var_s0 |= 0x80000001;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(var_s0);
    }

    arg0->unk_2C->unk_2C = 0xB;
    return var_s1 - 1;
}

void func_88314484(unk_func_882173EC* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_882173EC));
    arg0->unk_00.unk_1C = func_88314518;
    arg0->unk_00.unk_18 = func_88314574;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_00.unk_14.unk_00 = arg3;
    arg0->unk_00.unk_14.unk_02 = arg4;
    arg0->unk_2C = 0x3C;
    arg0->unk_00.unk_28 &= ~1;
}

s32 func_88314518(unk_func_882173EC* arg0) {
    if (arg0->unk_2C >= 0x3C) {
        arg0->unk_00.unk_28 &= ~0x101;
        return 0;
    }

    arg0->unk_00.unk_28 |= 0x100;
    arg0->unk_2C++;
    if ((*((s32*)&arg0->unk_30) == -1) && (arg0->unk_2C == 0x15)) {
        arg0->unk_2C = 0x29;
    }
    return 0;
}

s32 func_88314574(unk_func_882173EC* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88317694[] = {
        { 0x00, 0x00, 0x00, 0xFF },
        { 0x32, 0x32, 0x32, 0xFF },
    };

    char* sp6C = NULL;
    Color_RGBA8 sp68;
    s32 sp64 = arg0->unk_2C - 1;
    s32 temp_t3;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t3 = ((D_88317694[(sp64 / 3) & 1].r << 8) & 0xF800) | ((D_88317694[(sp64 / 3) & 1].g << 3) & 0x7C0) | ((D_88317694[(sp64 / 3) & 1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on
    gDPSetFillColor(gDisplayListHead++, (temp_t3 << 0x10) | temp_t3);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_00.unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_00.unk_14.unk_02) - 1);

    if (sp64 < 0x14) {
        if (*(s32*)&arg0->unk_30 != -1) {
            ret_func_8002ED08* sp44;
            UNUSED s32 pad[2];

            sp44 = func_8002ED08(*(s32*)&arg0->unk_30);
            sp68 = ((func884000C4)Memmap_GetFragmentVaddr(func_884000C4))(sp44->unk_00[1])->unk_04;
            sp6C = func_8002D7C0(NULL, 0, D_8831A4CC, *(s32*)&arg0->unk_30 - 1);
            sp68.a = 0xFF;
        }
    } else if (sp64 < 0x28) {
        ret_func_8002ED08* sp38;
        UNUSED s32 pad2[2];

        sp38 = func_8002ED08(*(s32*)&arg0->unk_30);
        sp68 = ((func884000C4)Memmap_GetFragmentVaddr(func_884000C4))(sp38->unk_00[1])->unk_04;
        sp6C = func_8002D7C0(NULL, 0, D_8831A4CC, *(s32*)&arg0->unk_30 - 1);
        sp68.a = ((-sp64 * 0xFF) + 0x26D9) / 20;
    } else {
        ret_func_8002ED08* sp2C;

        sp2C = func_8002ED08(*(s32*)&arg0->unk_34);
        sp68 = ((func884000C4)Memmap_GetFragmentVaddr(func_884000C4))(sp2C->unk_00[1])->unk_04;
        sp6C = func_8002D7C0(NULL, 0, D_8831A4CC, *(s32*)&arg0->unk_34 - 1);
        sp68.a = ((sp64 * 0xFF) - 0x27D8) / 20;
    }

    if (sp6C != NULL) {
        func_8001F3F4();
        func_8001EBE0(4, 0);
        func_8001F324(sp68.r, sp68.g, sp68.b, sp68.a);
        func_8001F1E8(((arg0->unk_00.unk_14.unk_00 - func_8001F5B0(0, 0, sp6C)) / 2) + arg1,
                      ((arg0->unk_00.unk_14.unk_02 - 0x10) / 2) + arg2, sp6C);
        func_8001F444();
    }
    return 0;
}

void func_88314920(unk_func_882173EC* arg0, s32 arg1, s32 arg2, unk_func_88001300_000_010 arg3) {
    arg0->unk_2C = 0;
    *(s32*)&arg0->unk_30 = arg1;
    *(s32*)&arg0->unk_34 = arg2;
    arg0->unk_00.unk_10 = arg3;
    arg0->unk_00.unk_28 |= 1;
}

void func_88314950(unk_func_8830867C_02C_0C0* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8830867C_02C_0C0));
    arg0->unk_00.unk_00.unk_1C = func_883149E4;
    arg0->unk_00.unk_00.unk_18 = func_88314A38;
    arg0->unk_00.unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_00.unk_10.unk_02 = arg2;
    arg0->unk_00.unk_00.unk_14.unk_00 = arg3;
    arg0->unk_00.unk_00.unk_14.unk_02 = arg4;
    arg0->unk_00.unk_2C = 0x5C;
    arg0->unk_00.unk_00.unk_28 &= ~1;
}

s32 func_883149E4(unk_func_8830867C_02C_0C0* arg0) {
    if (arg0->unk_00.unk_2C >= 0x5C) {
        arg0->unk_00.unk_00.unk_28 &= ~1;
        return 0;
    }

    if (arg0->unk_00.unk_2C >= 0x5B) {
        arg0->unk_00.unk_00.unk_28 &= ~0x100;
    }

    arg0->unk_00.unk_2C++;
    return 0;
}

s32 func_88314A38(unk_func_8830867C_02C_0C0* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_8831769C = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_883176A0[] = {
        { 0x00, 0x00, 0x00, 0xFF },
        { 0x32, 0x32, 0x32, 0xFF },
    };

    UNUSED s32 pad;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    Color_RGBA8 sp8C;
    char* sp88;
    char sp84[4];
    s32 sp80;
    ret_func_8002ED08* temp_s0;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 temp_t0;

    sp90 = arg0->unk_00.unk_2C - 1;
    sp80 = func_8001F5B0(4, 0, "00") + 4;
    sp74 = (arg0->unk_00.unk_00.unk_14.unk_02 - 0x10) / 2;
    temp_s0 = func_8002ED08(*(s32*)&arg0->unk_00.unk_30);
    sp8C = (((func884000C4)Memmap_GetFragmentVaddr(func_884000C4))(temp_s0->unk_00[1]))->unk_04;
    sp88 = func_8002D7C0(NULL, 0, D_8831A4CC, *(s32*)&arg0->unk_00.unk_30 - 1);
    sp70 = strlen(sp88);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    temp_t0 = ((D_883176A0[(sp90 / 3) & 1].r << 8) & 0xF800) | ((D_883176A0[(sp90 / 3) & 1].g << 3) & 0x7C0) |
              ((D_883176A0[(sp90 / 3) & 1].b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_t0 << 0x10) | temp_t0);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_00.unk_00.unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_00.unk_00.unk_14.unk_02) - 1);

    if (sp90 < 0x10) {
        sp78 = arg0->unk_00.unk_00.unk_14.unk_00 - ((sp80 * sp90) / 16);
        sp98 = (((sp78 - func_8001F5B0(4, 0, sp88, arg1)) - sp70) - 7) / sp70;
        if (arg2) {}
        sp94 = arg2 + sp74;
    } else if (sp90 < 0x24) {
        sp78 = arg0->unk_00.unk_00.unk_14.unk_00 - sp80;
        sp98 = (((sp78 - func_8001F5B0(4, 0, sp88, arg1)) - sp70) - 7) / sp70;
        sp94 = arg2 + sp74;
    } else if (sp90 < 0x38) {
        s32 sp50 = sp90 - 0x24;
        UNUSED s32 pad3[3];

        sp78 = arg0->unk_00.unk_00.unk_14.unk_00 - sp80;
        sp98 = (((sp78 - func_8001F5B0(4, 0, sp88, arg1)) - sp70) - 7) / sp70;
        sp94 = (arg2 + sp74) - ((arg0->unk_00.unk_00.unk_14.unk_02 * sp50) / 20);
    } else if (sp90 < 0x4C) {
        sp78 = arg0->unk_00.unk_00.unk_14.unk_00 - sp80;
        sp98 = (((sp78 - func_8001F5B0(4, 0, sp88, arg1)) - sp70) - 7) / sp70;
        sp94 = (arg2 + sp74) - arg0->unk_00.unk_00.unk_14.unk_02;
    } else if (sp90 < 0x5C) {
        sp78 = arg0->unk_00.unk_00.unk_14.unk_00 - ((sp80 * (0x5B - sp90)) / 16);
        sp98 = (((sp78 - func_8001F5B0(4, 0, sp88, arg1)) - sp70) - 7) / sp70;
        sp94 = (arg2 + sp74) - arg0->unk_00.unk_00.unk_14.unk_02;
    }

    if (sp98 > 0) {
        if (1) {}
        sp98 = 0;
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetScissorFrac(gDisplayListHead++, G_SC_NON_INTERLACE, arg1 * 4.0f, arg2 * 4.0f,
                      (arg0->unk_00.unk_00.unk_14.unk_00 + arg1) * 4.0f,
                      (arg2 + arg0->unk_00.unk_00.unk_14.unk_02) * 4.0f);

    func_8001F3F4();
    func_8001EBE0(4, sp98);
    func_8001F324(sp8C.r, sp8C.g, sp8C.b, sp8C.a);
    func_8001F1E8(((sp78 - func_8001F5B0(4, sp98, sp88)) / 2) + arg1, arg2 + sp74, sp88);
    func_8001EBE0(4, 0);
    func_8001F324(D_8831769C.r, D_8831769C.g, D_8831769C.b, D_8831769C.a);

    sprintf(sp84, "%d", *(s32*)&arg0->unk_00.unk_34);

    func_8001F1E8(((arg1 + sp78 + sp80) - func_8001F5B0(0, 0, sp84)) - 4, sp94, sp84);

    sprintf(sp84, "%d", arg0->unk_38);

    func_8001F1E8(((arg1 + sp78 + sp80) - func_8001F5B0(0, 0, sp84)) - 4, arg0->unk_00.unk_00.unk_14.unk_02 + sp94,
                  sp84);
    func_8001F444();

    gDPPipeSync(gDisplayListHead++);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 640, 480);

    return 0;
}

void func_883151B8(unk_func_8830867C_02C_0C0* arg0, s32 arg1, s32 arg2, s32 arg3, unk_func_88001300_000_010 arg4) {
    arg0->unk_00.unk_2C = 0;
    *(s32*)&arg0->unk_00.unk_30 = arg1;
    *(s32*)&arg0->unk_00.unk_34 = arg2;
    arg0->unk_38 = arg3;
    arg0->unk_00.unk_00.unk_10 = arg4;
    arg0->unk_00.unk_00.unk_28 |= 0x101;
}

void func_883151E8(unk_func_882173EC* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_882173EC));
    arg0->unk_00.unk_1C = func_8831527C;
    arg0->unk_00.unk_18 = func_883152D0;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_00.unk_14.unk_00 = arg3;
    arg0->unk_00.unk_14.unk_02 = arg4;
    arg0->unk_2C = 0x28;
    arg0->unk_00.unk_28 &= ~1;
}

s32 func_8831527C(unk_func_882173EC* arg0) {
    if (arg0->unk_2C >= 0x28) {
        arg0->unk_00.unk_28 &= ~1;
        return 0;
    }
    if (arg0->unk_2C >= 0x27) {
        arg0->unk_00.unk_28 &= ~0x100;
    }
    arg0->unk_2C += 1;
    return 0;
}

s32 func_883152D0(unk_func_882173EC* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883176A8 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_883176AC[] = {
        { 0x00, 0x00, 0x00, 0xFF },
        { 0x32, 0x32, 0x32, 0xFF },
    };

    char sp7C[4];
    s32 sp78;
    s32 sp74;
    UNUSED s32 pad;
    s32 temp_t0;
    s32 temp_t3;
    s32 var_s4;

    sp78 = func_8001F5B0(4, 0, "000");
    temp_t3 = arg0->unk_2C - 1;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    temp_t0 = ((D_883176AC[(temp_t3 / 3) & 1].r << 8) & 0xF800) | ((D_883176AC[(temp_t3 / 3) & 1].g << 3) & 0x7C0) |
              ((D_883176AC[(temp_t3 / 3) & 1].b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_t0 << 0x10) | temp_t0);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_00.unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_00.unk_14.unk_02) - 1);

    sp74 = ((arg0->unk_00.unk_14.unk_00 - sp78) / 2) + arg1;
    var_s4 = ((arg0->unk_00.unk_14.unk_02 - 0x10) / 2) + arg2;
    if (temp_t3 >= 0x14) {
        var_s4 -= (arg0->unk_00.unk_14.unk_02 * (temp_t3 - 0x14)) / 20;
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetScissorFrac(gDisplayListHead++, G_SC_NON_INTERLACE, arg1 * 4.0f, arg2 * 4.0f,
                      (arg0->unk_00.unk_14.unk_00 + arg1) * 4.0f, (arg2 + arg0->unk_00.unk_14.unk_02) * 4.0f);

    func_8001F3F4();
    func_8001EBE0(4, 0);
    func_8001F324(D_883176A8.r, D_883176A8.g, D_883176A8.b, D_883176A8.a);

    sprintf(sp7C, "%d", *(s32*)&arg0->unk_30);

    func_8001F1E8((sp74 + sp78) - func_8001F5B0(0, 0, sp7C), var_s4, sp7C);

    sprintf(sp7C, "%d", *(s32*)&arg0->unk_34);

    func_8001F1E8((sp74 + sp78) - func_8001F5B0(0, 0, sp7C), arg0->unk_00.unk_14.unk_02 + var_s4, sp7C);
    func_8001F444();

    gDPPipeSync(gDisplayListHead++);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 640, 480);

    return 0;
}

void func_883156B8(unk_func_882173EC* arg0, char* arg1, char* arg2, unk_func_88001300_000_010 arg3) {
    arg0->unk_2C = 0;
    *(char**)&arg0->unk_30 = arg1;
    *(char**)&arg0->unk_34 = arg2;
    arg0->unk_00.unk_10 = arg3;
    arg0->unk_00.unk_28 |= 0x101;
}

void func_883156E8(unk_func_882173EC* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_882173EC));

    arg0->unk_00.unk_1C = func_8831577C;
    arg0->unk_00.unk_18 = func_88315A6C;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_00.unk_14.unk_00 = arg3;
    arg0->unk_00.unk_14.unk_02 = arg4;
    arg0->unk_2C = 0x3C;
    arg0->unk_00.unk_28 &= ~1;
}

s32 func_8831577C(unk_func_882173EC* arg0) {
    if (arg0->unk_2C >= 0x3C) {
        arg0->unk_00.unk_28 &= ~1;
        return 0;
    }
    if (arg0->unk_2C >= 0x3B) {
        arg0->unk_00.unk_28 &= ~0x100;
    }
    arg0->unk_2C++;
    return 0;
}

void func_883157D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    static Color_RGBA8 D_883176B4 = { 0xF0, 0xF0, 0xF0, 0xFF };

    Color_RGBA8 sp2C;
    char sp24[8];
    UNUSED s32 pad;

    func_8001F3F4();
    func_8001EBE0(4, 0);

    switch (arg4) {
        case 32:
            sp2C = (0, D_8831727C);
            func_8001F324(sp2C.r, sp2C.g, sp2C.b, arg6);
            func_8001F1E8(arg0 + 4, ((arg3 - 0x10) / 2) + arg1, func_8002D7C0(NULL, 0, D_8831A4C4, 0x14));
            break;

        case 33:
            func_8001F324(D_883176B4.r, D_883176B4.g, D_883176B4.b, arg6);
            sprintf(sp24, "%d", arg5 + 1);
            func_8001F1E8(((arg0 + arg2) - func_8001F5B0(0, 0, sp24)) - 4, ((arg3 - 0x10) / 2) + arg1, sp24);

            sp2C = (0, D_88317280);
            func_8001F324(sp2C.r, sp2C.g, sp2C.b, arg6);
            func_8001F1E8(arg0 + 4, ((arg3 - 0x10) / 2) + arg1, func_8002D7C0(NULL, 0, D_8831A4C4, 0x15));
            break;

        case 17:
            func_8001F324(D_883176B4.r, D_883176B4.g, D_883176B4.b, arg6);
            sprintf(sp24, "%d", arg5 + 1);
            func_8001F1E8(((arg0 + arg2) - func_8001F5B0(0, 0, sp24)) - 4, ((arg3 - 0x10) / 2) + arg1, sp24);

            sp2C = (0, D_88317284);
            func_8001F324(sp2C.r, sp2C.g, sp2C.b, arg6);
            func_8001F1E8(arg0 + 4, ((arg3 - 0x10) / 2) + arg1, func_8002D7C0(NULL, 0, D_8831A4C4, 0x16));
            break;
    }
    func_8001F444();
}

s32 func_88315A6C(unk_func_882173EC* arg0, s32 arg1, s32 arg2) {
    static s32 D_883176B8[] = { 0x20, 0x21, 0x11 };
    static Color_RGBA8 D_883176C4[] = {
        { 0x00, 0x00, 0x00, 0xFF },
        { 0x32, 0x32, 0x32, 0xFF },
    };

    s32 temp_t0 = arg0->unk_2C - 1;
    s32 temp_t4;
    s32 var_v0;
    s32 var_v1;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t4 = ((D_883176C4[(temp_t0 / 3) & 1].r << 8) & 0xF800) | ((D_883176C4[(temp_t0 / 3) & 1].g << 3) & 0x7C0) | ((D_883176C4[(temp_t0 / 3) & 1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on
    gDPSetFillColor(gDisplayListHead++, (temp_t4 << 0x10) | temp_t4);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_00.unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_00.unk_14.unk_02) - 1);

    if (temp_t0 < 0x14) {
        var_v1 = 0xFF;
        var_v0 = *(s32*)&arg0->unk_30;
    } else if (temp_t0 < 0x28) {
        var_v1 = ((-temp_t0 * 0xFF) + 0x26D9) / 20;
        var_v0 = *(s32*)&arg0->unk_30;
    } else {
        var_v1 = ((temp_t0 * 0xFF) - 0x27D8) / 20;
        var_v0 = *(s32*)&arg0->unk_34;
    }

    func_883157D0(arg1, arg2, arg0->unk_00.unk_14.unk_00, arg0->unk_00.unk_14.unk_02, D_883176B8[var_v0 >> 0x10],
                  var_v0 & 0xFFFF, var_v1);
    return 0;
}

void func_88315C98(unk_func_882173EC* arg0, s32 arg1, s32 arg2, unk_func_88001300_000_010 arg3) {
    arg0->unk_2C = 0;
    *(s32*)&arg0->unk_30 = arg1;
    *(s32*)&arg0->unk_34 = arg2;
    arg0->unk_00.unk_10 = arg3;
    arg0->unk_00.unk_28 |= 0x101;
}
