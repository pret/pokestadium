#include "fragment24.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/22630.h"
#include "src/232C0.h"
#include "src/26820.h"
#include "src/29BA0.h"
#include "src/2D340.h"
#include "src/2E110.h"
#include "src/225A0.h"
#include "src/2E460.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "src/fragments/25/fragment25.h"

char** D_8831A4C0;
char** D_8831A4C4;
char** D_8831A4C8;
char** D_8831A4CC;
char** D_8831A4D0;
char** D_8831A4D4;
char** D_8831A4D8;
s32 pad_D_8831A4DC[8];

static Color_RGBA8 D_883171D0[] = {
    { 0x31, 0x48, 0x6B, 0xFF },
    { 0x47, 0x5E, 0x80, 0xFF },
    { 0x2B, 0x40, 0x5F, 0xFF },
    { 0x31, 0x48, 0x6B, 0xFF },
};

void func_88300020(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88001300_000));
    arg0->unk_18 = func_88300090;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x26; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 func_88300090(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    u32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);

    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    gDPLoadTextureBlock(gDisplayListHead++, D_883176D8, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 18, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gDisplayListHead++, (arg1 + 4) << 2, (arg2 + 1) << 2, (arg1 + 0x22) << 2, (arg2 + 0x13) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);

    return 0;
}

void func_883003E4(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88001300_000));
    arg0->unk_18 = func_88300454;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x5C; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 func_88300454(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171E0 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    func_8001F3F4();
    func_8001F324(D_883171E0.r, D_883171E0.g, D_883171E0.b, D_883171E0.a);
    func_8001EBE0(4, 0);

    sp1C = func_8002D7C0(NULL, 0, D_8831A4C4, 3);
    func_8001F1E8(((arg0->unk_14.unk_00 - func_8001F5B0(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    func_8001F444();

    return 0;
}

void func_88300640(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88001300_000));
    arg0->unk_18 = func_883006B0;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x5C; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 func_883006B0(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171E4 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    func_8001F3F4();
    func_8001F324(D_883171E4.r, D_883171E4.g, D_883171E4.b, D_883171E4.a);
    func_8001EBE0(4, 0);

    sp1C = func_8002D7C0(NULL, 0, D_8831A4C4, 4);
    func_8001F1E8(((arg0->unk_14.unk_00 - func_8001F5B0(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    func_8001F444();
    return 0;
}

void func_8830089C(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88001300_000));
    arg0->unk_18 = func_8830090C;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x34; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 func_8830090C(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171E8 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    func_8001F3F4();
    func_8001F324(D_883171E8.r, D_883171E8.g, D_883171E8.b, D_883171E8.a);
    func_8001EBE0(4, 0);

    sp1C = func_8002D7C0(NULL, 0, D_8831A4C4, 5);
    func_8001F1E8(((arg0->unk_14.unk_00 - func_8001F5B0(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    func_8001F444();
    return 0;
}

void func_88300AF8(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88001300_000));
    arg0->unk_18 = func_88300B68;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x4C; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 func_88300B68(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171EC = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    func_8001F3F4();
    func_8001F324(D_883171EC.r, D_883171EC.g, D_883171EC.b, D_883171EC.a);
    func_8001EBE0(4, 0);

    sp1C = func_8002D7C0(NULL, 0, D_8831A4C4, 6);
    func_8001F1E8(((arg0->unk_14.unk_00 - func_8001F5B0(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    func_8001F444();
    return 0;
}

void func_88300D54(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88001300_000));
    arg0->unk_18 = func_88300DC4;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x38; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 func_88300DC4(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171F0 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    func_8001F3F4();
    func_8001F324(D_883171F0.r, D_883171F0.g, D_883171F0.b, D_883171F0.a);
    func_8001EBE0(4, 0);

    sp1C = func_8002D7C0(NULL, 0, D_8831A4C4, 7);
    func_8001F1E8(((arg0->unk_14.unk_00 - func_8001F5B0(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    func_8001F444();
    return 0;
}

void func_88300FB0(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88001300_000));
    arg0->unk_18 = func_88301020;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x90; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 func_88301020(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171F4 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp54;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    {
        // clang-format off
        s32 temp_t3 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
        // clang-format on
        gDPSetFillColor(gDisplayListHead++, (temp_t3 << 0x10) | temp_t3);
        gDPFillRectangle(gDisplayListHead++, arg1, arg2, arg1 + 0x47, (arg2 + arg0->unk_14.unk_02) - 1);
    }

    {
        // clang-format off
        s32 sp34 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g * 8) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
        // clang-format on
        gDPSetFillColor(gDisplayListHead++, (sp34 << 0x10) | sp34);
        gDPFillRectangle(gDisplayListHead++, arg1 + 0x48, arg2, (arg1 + (u32)arg0->unk_14.unk_00) - 1,
                         (arg2 + arg0->unk_14.unk_02) - 1);
    }

    func_8001F3F4();
    func_8001F324(D_883171F4.r, D_883171F4.g, D_883171F4.b, D_883171F4.a);
    func_8001EBE0(4, 0);

    sp54 = func_8002D7C0(NULL, 0, D_8831A4C4, 8);
    func_8001F1E8(((0x48 - func_8001F5B0(0, 0, sp54)) / 2) + arg1, arg2 + 2, sp54);

    sp54 = func_8002D7C0(NULL, 0, D_8831A4C4, 9);
    func_8001F1E8(((0x48 - func_8001F5B0(0, 0, sp54)) / 2) + arg1 + 0x48, arg2 + 2, sp54);

    func_8001F444();
    return 0;
}

void func_8830133C(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88001300_000));
    arg0->unk_18 = func_883013AC;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x1A4; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 func_883013AC(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171F8 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* temp_v0_16;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    {
        // clang-format off
        s32 temp_t3 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
        // clang-format on

        gDPSetFillColor(gDisplayListHead++, (temp_t3 << 0x10) | temp_t3);
        gDPFillRectangle(gDisplayListHead++, arg1, arg2, arg1 + 0x68, (arg2 + arg0->unk_14.unk_02) - 1);
    }

    {
        // clang-format off
        s32 sp5C = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
        // clang-format on

        gDPSetFillColor(gDisplayListHead++, (sp5C << 0x10) | sp5C);
        gDPFillRectangle(gDisplayListHead++, arg1 + 0x69, arg2, arg1 + 0xD1, (arg2 + arg0->unk_14.unk_02) - 1);
    }

    {
        // clang-format off
        s32 temp_a2 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
        // clang-format on

        gDPSetFillColor(gDisplayListHead++, (temp_a2 << 0x10) | temp_a2);
        gDPFillRectangle(gDisplayListHead++, arg1 + 0xD2, arg2, arg1 + 0x13A, (arg2 + arg0->unk_14.unk_02) - 1);
    }

    {
        // clang-format off
        s32 temp_a0 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
        // clang-format on

        gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
        gDPFillRectangle(gDisplayListHead++, arg1 + 0x13B, arg2, arg1 + 0x1A3, (arg2 + arg0->unk_14.unk_02) - 1);
    }

    func_8001F3F4();
    func_8001F324(D_883171F8.r, D_883171F8.g, D_883171F8.b, D_883171F8.a);
    func_8001EBE0(4, 0);

    temp_v0_16 = func_8002D7C0(NULL, 0, D_8831A4C4, 0xA);
    func_8001F1E8(((0x69 - func_8001F5B0(0, 0, temp_v0_16)) / 2) + arg1, arg2 + 2, temp_v0_16);

    temp_v0_16 = func_8002D7C0(NULL, 0, D_8831A4C4, 0xB);
    func_8001F1E8(((0x69 - func_8001F5B0(0, 0, temp_v0_16)) / 2) + arg1 + 0x69, arg2 + 2, temp_v0_16);

    temp_v0_16 = func_8002D7C0(NULL, 0, D_8831A4C4, 0xC);
    func_8001F1E8(((0x69 - func_8001F5B0(0, 0, temp_v0_16)) / 2) + arg1 + 0xD2, arg2 + 2, temp_v0_16);

    temp_v0_16 = func_8002D7C0(NULL, 0, D_8831A4C4, 0xD);
    func_8001F1E8(((0x69 - func_8001F5B0(0, 0, temp_v0_16)) / 2) + arg1 + 0x13B, arg2 + 2, temp_v0_16);

    func_8001F444();
    return 0;
}

void func_883018D8(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88001300_000));
    arg0->unk_18 = func_88301948;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x46; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 func_88301948(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883171FC = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    func_8001F3F4();
    func_8001F324(D_883171FC.r, D_883171FC.g, D_883171FC.b, D_883171FC.a);
    func_8001EBE0(4, 0);

    sp1C = func_8002D7C0(NULL, 0, D_8831A4C4, 0xE);
    func_8001F1E8(((arg0->unk_14.unk_00 - func_8001F5B0(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);

    func_8001F444();
    return 0;
}

void func_88301B34(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88001300_000));
    arg0->unk_18 = func_88301BA4;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x46; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 func_88301BA4(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88317200 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    func_8001F3F4();
    func_8001F324(D_88317200.r, D_88317200.g, D_88317200.b, D_88317200.a);
    func_8001EBE0(4, 0);

    sp1C = func_8002D7C0(NULL, 0, D_8831A4C4, 0xF);
    func_8001F1E8(((arg0->unk_14.unk_00 - func_8001F5B0(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);

    func_8001F444();
    return 0;
}

void func_88301D90(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88001300_000));
    arg0->unk_18 = func_88301E00;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x46; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 func_88301E00(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88317204 = { 0xF0, 0xF0, 0xF0, 0xFF };

    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    func_8001F3F4();
    func_8001F324(D_88317204.r, D_88317204.g, D_88317204.b, D_88317204.a);
    func_8001EBE0(4, 0);
    func_8001F1E8(arg1 + 4, arg2 + 2, func_8002D7C0(NULL, 0, D_8831A4C4, 0x10));
    func_8001F444();
    return 0;
}

void func_88301FB8(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88001300_000));
    arg0->unk_18 = func_88302028;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x46; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 func_88302028(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88317208 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    func_8001F3F4();
    func_8001F324(D_88317208.r, D_88317208.g, D_88317208.b, D_88317208.a);
    func_8001EBE0(4, 0);
    sp1C = func_8002D7C0(NULL, 0, D_8831A4C4, 0x11);
    func_8001F1E8(((arg0->unk_14.unk_00 - func_8001F5B0(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    func_8001F444();
    return 0;
}

void func_88302214(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88001300_000));
    arg0->unk_18 = func_88302284;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x46; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 func_88302284(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_8831720C = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[0].r << 8) & 0xF800) | ((D_883171D0[0].g << 3) & 0x7C0) | ((D_883171D0[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    func_8001F3F4();
    func_8001F324(D_8831720C.r, D_8831720C.g, D_8831720C.b, D_8831720C.a);
    func_8001EBE0(4, 0);
    sp1C = func_8002D7C0(NULL, 0, D_8831A4C4, 0x12);
    func_8001F1E8(((arg0->unk_14.unk_00 - func_8001F5B0(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    func_8001F444();
    return 0;
}

void func_88302470(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88001300_000));
    arg0->unk_18 = func_883024E0;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
    // clang-format off
    arg0->unk_14.unk_00 = 0x46; arg0->unk_14.unk_02 = 0x14;
    // clang-format on
}

s32 func_883024E0(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88317210 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp1C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_883171D0[1].r << 8) & 0xF800) | ((D_883171D0[1].g << 3) & 0x7C0) | ((D_883171D0[1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_14.unk_02) - 1);

    func_8001F3F4();
    func_8001F324(D_88317210.r, D_88317210.g, D_88317210.b, D_88317210.a);
    func_8001EBE0(4, 0);
    sp1C = func_8002D7C0(NULL, 0, D_8831A4C4, 0x13);
    func_8001F1E8(((arg0->unk_14.unk_00 - func_8001F5B0(0, 0, sp1C)) / 2) + arg1, arg2 + 2, sp1C);
    func_8001F444();
    return 0;
}

void func_883026CC(unk_func_8830867C_02C_050* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   unk_func_8830867C_02C* arg5) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8830867C_02C_050));
    arg0->unk_00.unk_18 = func_88302748;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_00.unk_14.unk_00 = arg3;
    arg0->unk_00.unk_14.unk_02 = arg4;
    arg0->unk_2C = arg5;
}

s32 func_88302748(unk_func_8830867C_02C_050* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88317214 = { 0xFF, 0xFF, 0xFF, 0xFF };

    UNUSED s32 pad;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    {
        s32 temp_t7 = ((D_88317214.r << 8) & 0xF800) | ((D_88317214.g << 3) & 0x7C0) | ((D_88317214.b >> 2) & 0x3E) | 1;
        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (temp_t7 << 0x10) | temp_t7);
        gDPFillRectangle(gDisplayListHead++, arg1, arg2 + 0x14, (arg0->unk_00.unk_14.unk_00 + arg1) - 1, arg2 + 0x15);
    }

    {
        s32 temp_t7 = ((D_88317214.r << 8) & 0xF800) | ((D_88317214.g << 3) & 0x7C0) | ((D_88317214.b >> 2) & 0x3E) | 1;
        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (temp_t7 << 0x10) | temp_t7);
        gDPFillRectangle(gDisplayListHead++, arg1 + 0x82, arg2, arg1 + 0x83, arg2 + 0x12D);
    }

    return 0;
}

void func_8830290C(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88001300_000));
    arg0->unk_18 = func_88302968;
    arg0->unk_10.unk_00 = arg1;
    arg0->unk_10.unk_02 = arg2;
}

s32 func_88302968(unk_func_88001300_000* arg0, s32 arg1, s32 arg2) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    gDPLoadTextureBlock(gDisplayListHead++, D_883198A0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 40, 28, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, (arg1 + 0x100) << 2, (arg2 + 2) << 2, (arg1 + 0x127) << 2,
                        (arg2 + 0x1D) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    gDPPipeSync(gDisplayListHead++);

    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);
    return 0;
}

void func_88302BB4(unk_func_8830867C_02C* arg0, MemoryPool* arg1) {
    s32 i;

    func_88316BEC(arg0->unk_154, arg1);

    for (i = 0; i < 3; i++) {
        if (arg0->unk_154[i].unk_04 != 0) {
            func_88316D5C(&arg0->unk_154[i]);
        }
    }
}

void func_88302C18(unk_func_8830867C_02C* arg0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if ((arg0->unk_154[i].unk_04 != 0) && (arg0->unk_154[i].unk_08 != 0)) {
            func_88316DB8(&arg0->unk_154[i]);
        }
    }
}

void func_88302C7C(unk_func_8830867C_02C* arg0, MemoryPool* arg1) {
    UNUSED s32 pad;

    arg0->unk_0E4[0].unk_00 = 0x20;
    arg0->unk_0E4[0].unk_04 = func_80029080();
    arg0->unk_0E4[0].unk_08 = 0;
    arg0->unk_0E4[0].unk_1C = 6;
    func_8002C758(&arg0->unk_0E4[0].unk_0C, 0x1C, 1, arg1);
    func_883164C0(&arg0->unk_0E4[0], 6, 1, arg1);

    arg0->unk_0E4[1].unk_00 = 0x21;
    arg0->unk_0E4[1].unk_04 = arg0->unk_0E4[0].unk_04;
    arg0->unk_0E4[1].unk_08 = 1;
    arg0->unk_0E4[1].unk_1C = 0x14;
    func_8002C758(&arg0->unk_0E4[1].unk_0C, 0x1C, 0xC, arg1);
    func_883164C0(&arg0->unk_0E4[1], 0x14, 0, arg1);

    arg0->unk_0E4[2].unk_00 = 0x11;
    arg0->unk_0E4[2].unk_04 = 0;
    arg0->unk_0E4[2].unk_08 = 2;
    arg0->unk_0E4[2].unk_1C = 0x14;
    func_8002C758(&arg0->unk_0E4[2].unk_0C, 0x1C, 0xC, arg1);
    func_883164C0(&arg0->unk_0E4[2], 0x14, 0, arg1);

    func_8002C740(&arg0->unk_144, arg0->unk_0E4, 0x20, 3, 3);
}

void func_88302D98(unk_func_88302D98* arg0, s32 arg1, s32 arg2, unk_func_8830867C_02C* arg3) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88302D98));
    arg0->unk_00.unk_18 = func_88302E04;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_2C = arg3;
}

s32 func_88302E04(unk_func_88302D98* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88317218 = { 0xF0, 0xF0, 0xF0, 0xFF };

    UNUSED s32 pad[4];
    char spF0[0x10];
    char* spEC;
    s32 spE8;
    s32 spE4;

    func_8002D600(1, arg0->unk_2C->unk_CD0 + 1);
    func_8002D7C0(spF0, 0x20, D_8831A4C4, 2);
    func_8001F3F4();
    func_8001F324(D_88317218.r, D_88317218.g, D_88317218.b, D_88317218.a);
    func_8001EBE0(8, 0);
    spEC = func_8002D7C0(NULL, 0, D_8831A4C4, 1);
    spE8 = func_8001F5B0(0, 0, spEC);
    func_8001F1E8(arg1 + 0x22, arg2 + 5, spEC);
    spE4 = 0x206 - func_8001F5B0(0, 0, spF0);
    func_8001F1E8(arg1 + spE4, arg2 + 5, spF0);
    func_8001F444();

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    gDPLoadTextureBlock(gDisplayListHead++, D_88317920, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 24, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, (arg1 + 4) << 2, (arg2 + 3) << 2, (arg1 + 0x1D) << 2, (arg2 + 0x1A) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    gDPLoadTextureBlock(gDisplayListHead++, D_88317F28, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 24, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, ((arg1 + spE8) + 0x26) << 2, (arg2 + 3) << 2, ((arg1 + spE8) + 0x3F) << 2,
                        (arg2 + 0x1A) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    gDPLoadTextureBlock(gDisplayListHead++, D_4005570, G_IM_FMT_RGBA, G_IM_SIZ_16b, 28, 26, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, ((arg1 + spE4) - 0x1E) << 2, (arg2 + 2) << 2, ((arg1 + spE4) - 5) << 2,
                        (arg2 + 0x1B) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    gDPLoadTextureBlock(gDisplayListHead++, D_4004A00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 28, 26, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, (arg1 + 0x20A) << 2, (arg2 + 2) << 2, (arg1 + 0x223) << 2,
                        (arg2 + 0x1B) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    gDPPipeSync(gDisplayListHead++);

    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);

    return 0;
}

void func_88303520(unk_func_8830867C_02C* arg0) {
    s32 sp1C;
    unk_func_8830867C_02C_04C* ptr = arg0->unk_04C;

    sp1C = ptr->unk_24;

    switch (arg0->unk_038->unk_2C) {
        case 0:
            ptr = arg0->unk_04C;
            ptr->unk_18->unk_08 = arg0->unk_058;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_0C = arg0->unk_05C;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_10 = arg0->unk_060;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_14 = arg0->unk_064;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_18 = arg0->unk_068;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_1C = 0;

            if (sp1C >= 7) {
                sp1C = 6;
            }
            break;

        case 1:
            ptr = arg0->unk_04C;
            ptr->unk_18->unk_08 = arg0->unk_06C;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_0C = 0;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_10 = 0;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_14 = 0;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_18 = 0;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_1C = 0;

            if (sp1C >= 3) {
                sp1C = 2;
            }
            break;

        case 2:
            ptr = arg0->unk_04C;
            ptr->unk_18->unk_08 = arg0->unk_070;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_0C = arg0->unk_074;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_10 = arg0->unk_078;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_14 = arg0->unk_07C;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_18 = arg0->unk_080;

            ptr = arg0->unk_04C;
            ptr->unk_18->unk_1C = arg0->unk_084;
            break;
    }

    ((func8850CB48)Memmap_GetFragmentVaddr(func_8850CB48))(arg0->unk_04C, sp1C);
}

void func_883036AC(unk_func_8830867C_02C* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3,
                   unk_func_8830867C_030* arg4, unk_func_8830867C_034* arg5, unk_func_8830867C_038* arg6,
                   unk_func_8830867C_03C* arg7, unk_func_8830867C_040* arg8, unk_func_8830867C_044* arg9,
                   unk_func_8830867C_048* argA, unk_func_8830867C_04C* argB, unk_func_889000C4* argC,
                   FragmentEntry argD, unk_func_8830867C_054* argE, MemoryPool* argF, unk_D_800AC870* arg10) {
    static s32 D_8831721C[] = {
        0x0000005C,
        0x00000034,
        0x0000004C,
    };
    static s32 D_88317228[] = { 0x38, 0x48, 0x48 };
    static s32 D_88317234[] = { 0x69, 0x69, 0x69, 0x69 };
    static s32 D_88317244[] = { 0x46, 0x46, 0x46, 0x46, 0x46, 0x46 };
    static s32 D_8831725C[] = {
        0x00000000,
        0x00000006,
        0x0000000A,
        0x00000010,
    };
    static Color_RGBA8 D_8831726C = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88317270 = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317274 = { 0xFF, 0xFF, 0x00, 0xFF };

    UNUSED s32 pad[2];
    unk_func_88001300_03C* tmp;
    unk_func_88302D98* sp70;
    unk_func_88001300_000* sp6C;
    unk_func_88001300_000* sp68;
    unk_func_88001300_000* sp64;
    unk_func_88001300_03C_01C* sp60;
    unk_func_8850BD40* sp5C;
    unk_func_88507D4C* sp58;
    unk_func_88507D4C* sp54;
    unk_func_88503298* sp50;

    func_88302C7C(arg0, argF);
    func_8002CBC0(&arg0->unk_03C, 0x1E6, argF);
    func_8002CBC0(&arg0->unk_0CC, 0x1E6, argF);
    func_883166A0(&arg0->unk_144);

    arg0->unk_0DC = D_8831721C;

    func_883167CC(&arg0->unk_03C, &arg0->unk_144);
    func_88302BB4(arg0, argF);

    func_8002CBC0(&arg0->unk_C48, 0xAA, argF);
    func_88316F98(&arg0->unk_C48, arg0->unk_1A8, arg0->unk_154, 3, 0xAA);

    arg0->unk_08C = arg4;
    arg0->unk_094 = arg5;
    arg0->unk_098 = arg6;
    arg0->unk_09C = arg7;
    arg0->unk_0A0 = arg8;
    arg0->unk_0A4 = arg9;
    arg0->unk_0A8 = argA;
    arg0->unk_0AC = argB;
    arg0->unk_0B0 = argC;
    arg0->unk_CC4 = 0;
    arg0->unk_CC8 = 0;
    arg0->unk_0D8 = 0;
    arg0->unk_CD0 = 0;
    arg0->unk_CD4 = D_8831725C;
    arg0->unk_0E0 = 0;
    arg0->unk_CD8 = argD;
    arg0->unk_CDC = argE;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8830867C_02C));

    arg0->unk_000.unk_20 = func_88305DA8;
    arg0->unk_000.unk_24 = func_88305D7C;
    arg0->unk_000.unk_10.unk_00 = arg1;
    arg0->unk_000.unk_10.unk_02 = arg2;

    arg0->unk_048 = mem_pool_alloc(argF, sizeof(unk_func_8830867C_02C_048));
    func_88306FEC(arg0->unk_048, arg0);

    arg0->unk_04C = mem_pool_alloc(argF, sizeof(unk_func_88001300_03C));
    ((func8850C284)Memmap_GetFragmentVaddr(func_8850C284))(arg0->unk_04C, 1, 8, argF);
    arg0->unk_04C->unk_28 |= 0x200;
    arg0->unk_04C->unk_38 = -4;
    arg0->unk_04C->unk_3A = -4;
    arg0->unk_04C->unk_3C = 8;
    arg0->unk_04C->unk_3E = 8;

    arg0->unk_02C = mem_pool_alloc(argF, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_02C, 0, 0, 0x228, 0x172);
    arg0->unk_02C->unk_00.unk_28 |= 0x200;
    arg0->unk_02C->unk_00.unk_28 |= 0x400;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_02C);

    arg0->unk_030 = mem_pool_alloc(argF, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(func_8850B254))(arg0->unk_030, 0, 0, 0x228, 0x20, D_8831726C, D_88317270);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_02C, arg0->unk_030);

    sp70 = mem_pool_alloc(argF, sizeof(unk_func_88302D98));
    func_88302D98(sp70, 0, 1, arg0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_030, sp70);

    arg0->unk_088 = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    func_8830290C(arg0->unk_088, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_030, arg0->unk_088);

    arg0->unk_050 = mem_pool_alloc(argF, sizeof(unk_func_8830867C_02C_050));
    func_883026CC(arg0->unk_050, 0, 0x34, 0x228, 0x12E, arg0);

    sp6C = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    func_88300020(sp6C, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_050, sp6C);
    tmp = arg0->unk_04C;
    tmp->unk_18[0] = sp6C;

    arg0->unk_054 = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    func_883003E4(arg0->unk_054, 0x26, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_050, arg0->unk_054);
    tmp = arg0->unk_04C;
    tmp->unk_18[1] = arg0->unk_054;

    arg0->unk_038 = mem_pool_alloc(argF, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(func_88500994))(arg0->unk_038, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_050, arg0->unk_038);

    sp68 = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(sp68, 0x2C);
    sp68->unk_10.unk_00 = 0;
    sp68->unk_10.unk_02 = 0;
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_038, sp68);

    arg0->unk_058 = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    func_88300640(arg0->unk_058, 0x84, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp68, arg0->unk_058);

    arg0->unk_05C = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    func_8830089C(arg0->unk_05C, 0xE0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp68, arg0->unk_05C);

    arg0->unk_060 = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    func_88300AF8(arg0->unk_060, 0x114, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp68, arg0->unk_060);

    arg0->unk_064 = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    func_88300D54(arg0->unk_064, 0x160, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp68, arg0->unk_064);

    arg0->unk_068 = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    func_88300FB0(arg0->unk_068, 0x198, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp68, arg0->unk_068);

    arg0->unk_06C = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    func_8830133C(arg0->unk_06C, 0x84, 0);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_038, arg0->unk_06C);

    sp64 = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(sp64, 0x2C);
    sp64->unk_10.unk_00 = 0;
    sp64->unk_10.unk_02 = 0;
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_038, sp64);

    arg0->unk_070 = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    func_883018D8(arg0->unk_070, 0x84, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, arg0->unk_070);

    arg0->unk_074 = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    func_88301B34(arg0->unk_074, 0xCA, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, arg0->unk_074);

    arg0->unk_078 = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    func_88301D90(arg0->unk_078, 0x110, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, arg0->unk_078);

    arg0->unk_07C = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    func_88301FB8(arg0->unk_07C, 0x156, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, arg0->unk_07C);

    arg0->unk_080 = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    func_88302214(arg0->unk_080, 0x19C, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, arg0->unk_080);

    arg0->unk_084 = mem_pool_alloc(argF, sizeof(unk_func_88001300_000));
    func_88302470(arg0->unk_084, 0x1E2, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, arg0->unk_084);

    sp60 = mem_pool_alloc(argF, sizeof(unk_func_88001300_03C_01C));
    ((func88504570)Memmap_GetFragmentVaddr(func_88504570))(sp60, 0, 0, 0x10, 0x10, D_88317274);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_050, sp60);
    arg0->unk_04C->unk_1C = sp60;
    ((func8850CB48)Memmap_GetFragmentVaddr(func_8850CB48))(arg0->unk_04C, 1);
    func_88303520(arg0);

    arg0->unk_034 = mem_pool_alloc(argF, sizeof(unk_func_8830867C_02C_034));
    ((func88506DCC)Memmap_GetFragmentVaddr(func_88506DCC))(arg0->unk_034, 0, 0x4A, func_88304850, 0x228, 0x14, 0xE,
                                                           argF);
    ((func88506F1C)Memmap_GetFragmentVaddr(func_88506F1C))(arg0->unk_034, &arg0->unk_03C, argF);
    arg0->unk_034->unk_70 = arg0;
    arg0->unk_034->unk_00.unk_50 = 0x22;
    arg0->unk_034->unk_00.unk_52 = -4;
    arg0->unk_034->unk_00.unk_44->unk_00.unk_14.unk_00 = 0x64;
    arg0->unk_034->unk_00.unk_44->unk_00.unk_14.unk_02 = 0x1C;

    sp5C = mem_pool_alloc(argF, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(sp5C, arg0->unk_034);
    ((func8850CC74)Memmap_GetFragmentVaddr(func_8850CC74))(arg0->unk_048, sp5C);
    ((func8850CC74)Memmap_GetFragmentVaddr(func_8850CC74))(arg0->unk_048, arg0->unk_04C);

    sp54 = mem_pool_alloc(argF, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(sp54, 0, 0x24, 0x228, 0, arg0->unk_034);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_02C, sp54);

    sp58 = mem_pool_alloc(argF, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(sp58, 0, arg0->unk_02C->unk_00.unk_14.unk_02 - 0x10, 0x228,
                                                           1, arg0->unk_034);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_02C, sp58);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_02C, arg0->unk_050);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_02C, arg0->unk_034);

    sp50 = mem_pool_alloc(argF, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(func_88503298))(sp50, arg0->unk_02C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, sp50);

    arg0->unk_0B4 = mem_pool_alloc(argF, sizeof(unk_func_8830867C_02C_0B4));
    func_88313FA0(arg0->unk_0B4, 0x65, 0x228, argF);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_0B4);

    func_88313740(arg0->unk_0A8, &arg0->unk_144);

    arg0->unk_08C->unk_4C = 0x228;
    arg0->unk_08C->unk_50 = 0x13E;

    arg0->unk_090 = mem_pool_alloc(argF, sizeof(unk_func_88509F48));
    ((func88509F48)Memmap_GetFragmentVaddr(func_88509F48))(arg0->unk_090, 0, 0, 0x228, 0x1A0, argF, arg10);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_090);

    arg0->unk_CCC = mem_pool_alloc(argF, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_CCC, 0, 0,
                                                           mem_pool_alloc(argF, sizeof(char) * 0x140), 0x10);
    arg0->unk_CCC->unk_3C = 0x20;

    arg0->unk_0B8 = mem_pool_alloc(argF, sizeof(unk_func_8850CD44));
    ((func8850CD44)Memmap_GetFragmentVaddr(func_8850CD44))(arg0->unk_0B8, 4, argF);

    arg0->unk_0BC = mem_pool_alloc(argF, sizeof(unk_func_882173EC));
    func_88314484(arg0->unk_0BC, 0, 0, D_88317234[0], 0x14);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_034, arg0->unk_0BC);
    arg0->unk_0B8->unk_1C[0] = arg0->unk_0BC;

    arg0->unk_0C0 = mem_pool_alloc(argF, sizeof(unk_func_8830867C_02C_0C0));
    func_88314950(arg0->unk_0C0, 0, 0, D_88317234[0], 0x14);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_034, arg0->unk_0C0);
    arg0->unk_0B8->unk_1C[1] = &arg0->unk_0C0->unk_00;

    arg0->unk_0C4 = mem_pool_alloc(argF, sizeof(unk_func_882173EC));
    func_883151E8(arg0->unk_0C4, 0, 0, D_88317244[0], 0x14);

    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_034, arg0->unk_0C4);
    arg0->unk_0B8->unk_1C[2] = arg0->unk_0C4;

    arg0->unk_0C8 = mem_pool_alloc(argF, sizeof(unk_func_882173EC));
    func_883156E8(arg0->unk_0C8, 0, 0, D_88317228[0], 0x14);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_034, arg0->unk_0C8);
    arg0->unk_0B8->unk_1C[3] = arg0->unk_0C8;
    arg0->unk_CB8 = 0;

    func_883051F8(arg0);
    func_883051B0(arg0);
    func_88305270(arg0);
}

void func_88304350(s32 arg0, s32 arg1, s32 arg2, u8* arg3, s32 arg4) {
    Color_RGBA8 sp2C;
    s32 sp28;
    UNUSED s32 pad;
    char* sp20;

    if ((*arg3 <= 0) || (*arg3 >= 0x98)) {
        if (arg4 != 1) {
            sp2C = ((func884000C4)Memmap_GetFragmentVaddr(func_884000C4))(0)->unk_04;
            sp20 = "????";
        } else {
            return;
        }
    } else {
        sp28 = func_8002ED78(arg3, arg4);
        if (sp28 != -1) {
            sp2C = ((func884000C4)Memmap_GetFragmentVaddr(func_884000C4))(sp28)->unk_04;
            sp20 = func_8002D7C0(NULL, 0, D_8831A4D4, func_800219FC(sp28));
        } else {
            return;
        }
    }

    func_8001F3F4();
    func_8001EBE0(4, 0);
    func_8001F324(sp2C.r, sp2C.g, sp2C.b, sp2C.a);
    func_8001F1E8(((arg2 - func_8001F5B0(0, 0, sp20)) / 2) + arg0, arg1, sp20);
    func_8001F444();
}

void func_88304490(s32 arg0, s32 arg1, s32 arg2, u8* arg3, s32 arg4) {
    static Color_RGBA8 D_88317278 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp2C;
    Color_RGBA8 sp28;
    ret_func_8002ED08* sp24;
    u8* sp18 = &arg3[arg4];

    if (arg4 < func_8002ECDC(arg3)) {
        sp24 = func_8002ED08(sp18[9]);
        if (sp24 == NULL) {
            sp28 = D_88317278;
            sp2C = " ????? ";
        } else {
            sp28 = ((func884000C4)Memmap_GetFragmentVaddr(func_884000C4))(sp24->unk_00[1])->unk_04;
            sp2C = func_8002D7C0(NULL, 0, D_8831A4CC, sp18[9] - 1);
        }
        func_8001F3F4();
        func_8001EBE0(4, 0);
        func_8001F324(sp28.r, sp28.g, sp28.b, sp28.a);
        func_8001F1E8(((arg2 - func_8001F5B0(0, 0, sp2C)) / 2) + arg0, arg1, sp2C);
        func_8001F444();
    }
}

Color_RGBA8 D_8831727C = { 0xF0, 0x96, 0x96, 0xFF };
Color_RGBA8 D_88317280 = { 0xF0, 0xD2, 0x8C, 0xFF };
Color_RGBA8 D_88317284 = { 0x96, 0xDC, 0xB4, 0xFF };

void func_883045C0(s32 arg0, s32 arg1, s32 arg2, unk_func_88304850_arg2* arg3) {
    func_883157D0(arg0, arg1, arg2, 0x14, *(s32*)arg3->unk_00[0], arg3->unk_00[1], 0xFF);
}

void func_88304608(s32 arg0, s32 arg1, s8* arg2, s32 arg3) {
    static Color_RGBA8 D_88317288 = { 0xF0, 0xF0, 0xF0, 0xFF };

    func_8001F3F4();
    func_8001F324(D_88317288.r, D_88317288.g, D_88317288.b, D_88317288.a);
    func_8001EBE0(4, 0);
    func_8001F1E8(arg0, arg1, arg2, arg3);
    func_8001F444();
}

void func_88304680(s32 arg0, s32 arg1, char* arg2, s32 arg3) {
    static Color_RGBA8 D_8831728C = { 0xF0, 0xF0, 0xF0, 0xFF };
    char sp1C[12];

    func_8001F3F4();
    func_8001F324(D_8831728C.r, D_8831728C.g, D_8831728C.b, D_8831728C.a);
    func_8001EBE0(4, 0);

    sprintf(&sp1C, arg2, arg3);

    func_8001F1E8(arg0 - func_8001F5B0(0, 0, sp1C), arg1, sp1C);
    func_8001F444();
}

void func_88304718(s32 arg0, s32 arg1, char* arg2, s32 arg3, u8* arg4) {
    static Color_RGBA8 D_88317290 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static char D_88317294[] = "?";

    if ((*arg4 <= 0) || (*arg4 >= 0x98)) {
        func_8001F3F4();
        func_8001F324(D_88317290.r, D_88317290.g, D_88317290.b, D_88317290.a);
        func_8001EBE0(4, 0);
        func_8001F1E8(arg0 - func_8001F5B0(0, 0, D_88317294), arg1, D_88317294);
        func_8001F444();
    } else {
        func_88304680(arg0, arg1, arg2, arg3);
    }
}

typedef struct unk_D_88317298 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} unk_D_88317298; // size = 0x8

s32 func_883047CC(unk_func_8830867C_02C* arg0, unk_func_88304850_arg2* arg1) {
    static unk_D_88317298 D_88317298[] = {
        { 0x19, 0x1E }, { 0xF, 0x14 }, { 0x32, 0x37 }, { 0x1, 0x1E }, { 0x1, 0x32 },
    };

    unk_D_88317298* ptr;
    s32 sp18 = 0;

    if (func_88305220(arg0, 0x20) != 0) {
        ptr = &D_88317298[arg0->unk_C54.unk_2C];
        if (arg1->unk_2C < ptr->unk_00) {
            sp18 = 1;
        } else if (ptr->unk_04 < arg1->unk_2C) {
            sp18 = 2;
        }
    }
    return sp18;
}

#ifdef NON_MATCHING
void func_88304850(s32 arg0, s32 arg1, unk_func_88304850_arg2* arg2, s32 arg3, s32 arg4,
                   unk_func_8830867C_02C_034* arg5) {
    static Color_RGBA8 D_883172C0[] = {
        { 0xF0, 0xF0, 0xF0, 0xFF },
        { 0xB2, 0xFF, 0xC3, 0xFF },
        { 0xFF, 0xB2, 0xC3, 0xFF },
    };
    static Color_RGBA8 D_883172CC[][2] = {
        {
            { 0x50, 0x51, 0x54, 0xFF },
            { 0x59, 0x5B, 0x5E, 0xFF },
        },
        {
            { 0x43, 0x44, 0x46, 0xFF },
            { 0x4B, 0x4C, 0x4F, 0xFF },
        },
    };

    s32 i;
    Color_RGBA8 spBC;
    s32 spA8;
    s32 sp58;
    s32 sp50;
    s32 var_s1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a3;
    s32 temp_s7;
    s32 var_s6;
    unk_func_8830867C_02C* temp_s5;

    temp_s5 = arg5->unk_70;
    if (temp_s5->unk_0AC->unk_2C->unk_30 & 2) {
        var_s1 = temp_s5->unk_0AC->unk_00.unk_10.unk_00 - temp_s5->unk_000.unk_10.unk_00;
    } else {
        var_s1 = arg5->unk_00.unk_00.unk_14.unk_00;
    }

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    temp_a3 = ((D_883171D0[arg3 & 1].r << 8) & 0xF800) | ((D_883171D0[arg3 & 1].g << 3) & 0x7C0) |
              ((D_883171D0[arg3 & 1].b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a3 << 0x10) | temp_a3);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, arg0 + 0x25, arg1 + 0x13);

    temp_a0 = ((D_883171D0[(arg3 & 1) + 1].r << 8) & 0xF800) | ((D_883171D0[(arg3 & 1) + 1].g << 3) & 0x7C0) |
              ((D_883171D0[(arg3 & 1) + 1].b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0 + 0x26, arg1, arg0 + 0x81, arg1 + 0x13);

    sp50 = arg0 + 0x84;
    var_s6 = temp_s5->unk_CD4[temp_s5->unk_CD0];

    for (i = arg0 + 0x84; i < var_s1 + arg0; i++) {
        temp_a0_2 = ((D_883172CC[arg3 & 1][var_s6 & 1].r << 8) & 0xF800) |
                    ((D_883172CC[arg3 & 1][var_s6 & 1].g << 3) & 0x7C0) |
                    ((D_883172CC[arg3 & 1][var_s6 & 1].b >> 2) & 0x3E) | 1;
        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (temp_a0_2 << 0x10) | temp_a0_2);
        gDPFillRectangle(gDisplayListHead++, sp50, arg1, (temp_s5->unk_0DC->unk_00[i] + sp50) - 1, arg1 + 0x13);

        sp50 += temp_s5->unk_0DC->unk_00[i];
        var_s6++;
    }

    if (arg2 != NULL) {
        func_8002E8E4(arg0 + 6, arg1 + 4, arg3 + 1, 3);
        spBC = D_883172C0[func_883047CC(temp_s5, arg2)];
        if (arg4 & 4) {
            spBC.a = 0x4D;
        } else {
            spBC.a = 0xFF;
        }
        func_8001F3F4();
        func_8001F324(spBC.r, spBC.g, spBC.b, spBC.a);
        func_8001EBE0(4, 0);
        spA8 = (0x5C - func_8001F5B0(0, 0, "WWWWWWWWWW")) / 2;

        if ((arg2->unk_08 <= 0) || (arg2->unk_08 >= 0x98)) {
            func_8001F1E8(arg0 + spA8 + 0x26, arg1 + 2, "?????");
        } else {
            func_8001F1E8(arg0 + spA8 + 0x26, arg1 + 2, func_8002D7C0(NULL, 0, D_8831A4D0, arg2->unk_08 - 1));
        }

        func_8001F444();

        var_s6 = temp_s5->unk_CD4[temp_s5->unk_CD0];

        for (i = sp50; i < var_s1 + arg0; i++) {
            switch (var_s6) {
                case 0:
                    func_88304608(sp50 + spA8, arg1 + 2, arg2->unk_40, 0);
                    break;

                case 1:
                    func_8002E8E4(sp50 + 4, arg1 + 4, arg2->unk_16, 5);
                    break;

                case 2:
                    func_88304608(sp50 + ((temp_s5->unk_0DC->unk_00[i] - func_8001F5B0(0, 0, "WWWWWWW")) / 2), arg1 + 2,
                                  arg2->unk_43, 0);
                    break;

                case 3:
                    func_883045C0(sp50, arg1, temp_s5->unk_0DC->unk_00[i], arg2);
                    break;

                case 4:
                case 5:
                    func_88304350(sp50, arg1 + 2, temp_s5->unk_0DC->unk_00[i], &arg2->unk_08, var_s6 - 4);
                    break;

                case 6:
                case 7:
                case 8:
                case 9:
                    func_88304490(sp50, arg1 + 2, temp_s5->unk_0DC->unk_00[i], &arg2->unk_08, var_s6 - 6);
                    break;

                case 10:
                    func_88304718(sp50 + (temp_s5->unk_0DC->unk_00[i] -
                                          ((temp_s5->unk_0DC->unk_00[i] - func_8001F5B0(0, 0, "000")) / 2)),
                                  arg1 + 2, "%3d", arg2->unk_2C, &arg2->unk_08);
                    break;

                case 11:
                    func_88304718(sp50 + (temp_s5->unk_0DC->unk_00[i] -
                                          ((temp_s5->unk_0DC->unk_00[i] - func_8001F5B0(0, 0, "000")) / 2)),
                                  arg1 + 2, "%3d", arg2->unk_36, &arg2->unk_08);
                    break;

                case 12:
                    func_88304718(sp50 + (temp_s5->unk_0DC->unk_00[i] -
                                          ((temp_s5->unk_0DC->unk_00[i] - func_8001F5B0(0, 0, "000")) / 2)),
                                  arg1 + 2, "%3d", arg2->unk_30, &arg2->unk_08);
                    break;

                case 13:
                    func_88304718(sp50 + (temp_s5->unk_0DC->unk_00[i] -
                                          ((temp_s5->unk_0DC->unk_00[i] - func_8001F5B0(0, 0, "000")) / 2)),
                                  arg1 + 2, "%3d", arg2->unk_32, &arg2->unk_08);
                    break;

                case 14:
                    func_88304718(sp50 + (temp_s5->unk_0DC->unk_00[i] -
                                          ((temp_s5->unk_0DC->unk_00[i] - func_8001F5B0(0, 0, "000")) / 2)),
                                  arg1 + 2, "%3d", arg2->unk_34, &arg2->unk_08);
                    break;

                case 15:
                    func_88304718(sp50 + (temp_s5->unk_0DC->unk_00[i] -
                                          ((temp_s5->unk_0DC->unk_00[i] - func_8001F5B0(0, 0, "000")) / 2)),
                                  arg1 + 2, "%3d", arg2->unk_36, &arg2->unk_08);
                    break;
            }

            var_s6++;
            sp50 += temp_s5->unk_0DC->unk_00[i];
        }
    }
}
#else
static Color_RGBA8 D_883172C0[] = {
    { 0xF0, 0xF0, 0xF0, 0xFF },
    { 0xB2, 0xFF, 0xC3, 0xFF },
    { 0xFF, 0xB2, 0xC3, 0xFF },
};
static Color_RGBA8 D_883172CC[][2] = {
    {
        { 0x50, 0x51, 0x54, 0xFF },
        { 0x59, 0x5B, 0x5E, 0xFF },
    },
    {
        { 0x43, 0x44, 0x46, 0xFF },
        { 0x4B, 0x4C, 0x4F, 0xFF },
    },
};
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_1CEA00/func_88304850.s")
#endif

void func_883050CC(unk_func_8830867C_02C* arg0) {
    arg0->unk_C84 = arg0->unk_C54;

    arg0->unk_CBC = arg0->unk_034->unk_00.unk_38;
    arg0->unk_CC0 = arg0->unk_034->unk_00.unk_38 - (arg0->unk_034->unk_58 / arg0->unk_034->unk_00.unk_3E);
    arg0->unk_CB4 = 1;
    arg0->unk_CB8 = 1;

    arg0->unk_088->unk_28 |= 1;
}

void func_88305168(unk_func_8830867C_02C* arg0) {
    arg0->unk_C54 = arg0->unk_C84;

    arg0->unk_CB4 = 0;
    arg0->unk_088->unk_28 &= ~1;
}

void func_883051B0(unk_func_8830867C_02C* arg0) {
    arg0->unk_C84 = arg0->unk_C54;
    arg0->unk_CB4 = 0;
    arg0->unk_088->unk_28 &= ~1;
}

void func_883051F8(unk_func_8830867C_02C* arg0) {
    arg0->unk_C54.unk_04 = NULL;
    arg0->unk_C54.unk_00 = 0;
    // clang-format off
    arg0->unk_C54.unk_08 = 1; arg0->unk_C54.unk_09 = 0x64;
    // clang-format on
    arg0->unk_C54.unk_0C = 0;
    arg0->unk_C54.unk_1C.unk_00 = 0;
    arg0->unk_C54.unk_24.unk_04 = 0;
}

s32 func_88305220(unk_func_8830867C_02C* arg0, s32 arg1) {
    return (arg0->unk_C54.unk_04 & arg1) != 0;
}

void func_88305230(unk_func_8830867C_02C* arg0, s32 arg1) {
    arg0->unk_C54.unk_04 |= arg1;
}

void func_88305240(unk_func_8830867C_02C* arg0, s32 arg1) {
    arg0->unk_C54.unk_04 &= ~arg1;
}

s32 func_88305254(unk_func_8830867C_02C* arg0, s32 arg1) {
    arg0->unk_C54.unk_04 ^= arg1;
    return arg0->unk_C54.unk_04 & arg1;
}

void func_88305268(unk_func_8830867C_02C* arg0, s32 arg1) {
    arg0->unk_C54.unk_00 = arg1;
}

void func_88305270(unk_func_8830867C_02C* arg0) {
    ((func88506EE4)Memmap_GetFragmentVaddr(func_88506EE4))(arg0->unk_034, &arg0->unk_03C);

    if (arg0->unk_C54.unk_04 != 0) {
        if (arg0->unk_C54.unk_04 & 1) {
            func_8002D1AC(arg0->unk_034->unk_00.unk_2C, &arg0->unk_0CC, func_88316214, &arg0->unk_C54.unk_08);
            ((func88506EE4)Memmap_GetFragmentVaddr(func_88506EE4))(arg0->unk_034, &arg0->unk_0CC);
        }

        if (arg0->unk_C54.unk_04 & 2) {
            func_8002D1AC(arg0->unk_034->unk_00.unk_2C, &arg0->unk_0CC, func_88316240, &arg0->unk_C54.unk_1C);
            ((func88506EE4)Memmap_GetFragmentVaddr(func_88506EE4))(arg0->unk_034, &arg0->unk_0CC);
        }

        if (arg0->unk_C54.unk_04 & 4) {
            func_8002D1AC(arg0->unk_034->unk_00.unk_2C, &arg0->unk_0CC, func_88316304, &arg0->unk_C54.unk_24);
            ((func88506EE4)Memmap_GetFragmentVaddr(func_88506EE4))(arg0->unk_034, &arg0->unk_0CC);
        }

        if (arg0->unk_C54.unk_04 & 8) {
            func_8002D1AC(arg0->unk_034->unk_00.unk_2C, &arg0->unk_0CC, func_883163A4, &arg0->unk_C54.unk_10);
            ((func88506EE4)Memmap_GetFragmentVaddr(func_88506EE4))(arg0->unk_034, &arg0->unk_0CC);
        }

        if (arg0->unk_C54.unk_04 & 0x10) {
            func_8002D1AC(arg0->unk_034->unk_00.unk_2C, &arg0->unk_0CC, func_883163B8, &arg0->unk_C54.unk_14);
            ((func88506EE4)Memmap_GetFragmentVaddr(func_88506EE4))(arg0->unk_034, &arg0->unk_0CC);
        }

        if (arg0->unk_C54.unk_04 & 0x20) {
            func_8002D1AC(arg0->unk_034->unk_00.unk_2C, &arg0->unk_0CC, func_88316480, &arg0->unk_C54.unk_2C);
            ((func88506EE4)Memmap_GetFragmentVaddr(func_88506EE4))(arg0->unk_034, &arg0->unk_0CC);
        }
    }

    func_8002D180(arg0->unk_034->unk_00.unk_2C, D_8831A1F8[arg0->unk_C54.unk_00]);
}

s32 func_88305458(unk_func_8830867C_02C* arg0) {
    s32 var_a0 = func_883168B4(&arg0->unk_144);
    s32 i;

    for (i = 0; i < 3; i++) {
        if ((arg0->unk_154[i].unk_04 != 0) && (arg0->unk_154[i].unk_08 != 0)) {
            if (i == 0) {
                var_a0 |= 2;
            } else if (i == 1) {
                var_a0 |= 8;
            } else {
                var_a0 |= 0x20;
            }
        }
    }

    return var_a0;
}

s32 func_883054DC(unk_func_8830867C_02C_0CC* arg0, unk_func_8830867C_02C_0CC_000* arg1) {
    unk_func_8830867C_02C_0CC_000** ptr = arg0->unk_00;
    s32 i;

    for (i = 0; i < arg0->unk_08; i++) {
        if (arg1 == ptr[i]) {
            return i;
        }
    }

    return -1;
}

void func_88305520(unk_func_8830867C_02C* arg0, unk_func_8830867C_02C_0CC_000* arg1, Controller* arg2) {
    func88500A6C temp_v0_4;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    unk_func_88001300_000_010 sp78;
    unk_func_8830867C_02C_0CC_000* sp74;
    s32 sp70;
    char sp50[0x20];
    char sp30[0x20];
    unk_func_88500994* tmp;

    sp84 = 0;
    sp80 = (arg1->unk_00->unk_00->unk_08 << 0x10) | arg1->unk_00->unk_04;
    sp88 = arg0->unk_0A8->unk_34->unk_38;

    if (sp88 != 0) {
        sp84 = arg0->unk_0A8->unk_38[arg0->unk_0A8->unk_4C->unk_1C]->unk_38;
    }

    sp90 = arg0->unk_034->unk_00.unk_38;
    sp8C = arg0->unk_034->unk_00.unk_38 - (arg0->unk_034->unk_58 / arg0->unk_034->unk_00.unk_3E);
    sp74 = arg0->unk_034->unk_00.unk_2C->unk_00[sp90];

    func_88305830(arg0, sp74, sp88, sp84);
    sp7C = (arg1->unk_00->unk_00->unk_08 << 0x10) | arg1->unk_00->unk_04;

    temp_v0_4 = ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C));
    tmp = arg0->unk_038;
    arg0->unk_CD0 = 0;
    temp_v0_4(tmp, 0);

    func_88303520(arg0);

    sp78.unk_00 = arg0->unk_0DC->unk_08 + (s32)arg0->unk_0DC->unk_00 + arg0->unk_0DC->unk_04 + 0x84;
    sp78.unk_02 = arg0->unk_034->unk_5C - arg0->unk_034->unk_58;

    func_88315C98(arg0->unk_0C8, sp80, sp7C, sp78);
    func_80048B90(0x0120000D);

    ((func8850CF00)Memmap_GetFragmentVaddr(func_8850CF00))(arg0->unk_0B8, arg2);

    func_80048B90(0x29);
    func_883167CC(&arg0->unk_03C, &arg0->unk_144);
    func_88305270(arg0);
    func_883051B0(arg0);

    sp70 = func_883054DC(arg0->unk_034->unk_00.unk_2C, sp74);
    if (sp70 == -1) {
        ((func88507C0C)Memmap_GetFragmentVaddr(func_88507C0C))(arg0->unk_034, sp90, sp8C);
        func_8002D5D4(0x1A, arg1->unk_38);
        func_88313950(sp50, sp80 >> 0x10, sp80 & 0xFFFF);
        func_8002D5D4(0x25, sp50);
        func_88313950(sp30, sp88, sp84);
        func_8002D5D4(0x28, sp30);
        func_8002D7C0(arg0->unk_CCC->unk_40, 0x140, D_8831A4C4, 0x5C);
        ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(arg0->unk_090, arg0->unk_CCC, 0, 0);
        ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_090, arg2);
    } else {
        ((func88507C0C)Memmap_GetFragmentVaddr(func_88507C0C))(arg0->unk_034, sp70, sp8C);
    }
}

void func_883057F4(unk_func_8830867C_02C_0CC_000_000* arg0) {
    unk_func_8830867C_02C_0CC_000_000_010_000* ptr = arg0->unk_10.unk_00;
    s32 i;

    for (i = 0; i < arg0->unk_10.unk_08; i++, ptr++) {
        ptr->unk_00->unk_04 = i;
    }
}

void func_88305830(unk_func_8830867C_02C* arg0, unk_func_8830867C_02C_0CC_000* arg1, s32 arg2, s32 arg3) {
    unk_func_8830867C_02C_144_000* ptr = arg0->unk_144.unk_00;
    unk_func_8830867C_02C_0CC_000_000* temp_s0 = &ptr[arg2].unk_0C[arg3];
    unk_func_8830867C_02C_0CC_000_000* sp24 = arg1->unk_00;

    func_8002CC80(&sp24->unk_10, arg1->unk_04);
    func_883057F4(sp24);

    arg1->unk_00 = &temp_s0->unk_00;
    arg1->unk_04 = temp_s0->unk_10.unk_08;

    func_8002CC2C(&temp_s0->unk_10, arg1, temp_s0->unk_10.unk_08);

    sp24->unk_0C = 1;
    temp_s0->unk_0C = 1;
}

s32 func_883058C4(unk_func_8830867C_02C_0CC_000* arg0, unk_func_8830867C_04C_030_02C_000* arg1, u32** arg2,
                  u32** arg3) {
    unk_func_8830867C_02C_0CC_000_008* temp_s0 = &arg0->unk_08;
    u16 sp3A;
    s32 sp34;

    switch (arg1->unk_00[0]->unk_00) {
        case 35:
            sp34 = 1;

            *arg2 = temp_s0->unk_26;
            temp_s0->unk_14 += 0xA00;
            if (temp_s0->unk_14 >= 0x6401) {
                temp_s0->unk_14 = 0x6400;
            }
            temp_s0->unk_26 = CalculateStatValue(STAT_HP, temp_s0->unk_00, temp_s0->unk_14, temp_s0->unk_24, temp_s0->unk_1E);
            *arg3 = temp_s0->unk_26;
            break;

        case 36:
            sp34 = 2;
            *arg2 = temp_s0->unk_28;
            temp_s0->unk_16 += 0xA00;
            if (temp_s0->unk_16 >= 0x6401) {
                temp_s0->unk_16 = 0x6400;
            }
            temp_s0->unk_28 = CalculateStatValue(STAT_SPECIAL, temp_s0->unk_00, temp_s0->unk_16, temp_s0->unk_24, temp_s0->unk_1E);
            *arg3 = temp_s0->unk_28;
            break;

        case 37:
            sp34 = 3;
            *arg2 = temp_s0->unk_2A;
            temp_s0->unk_18 += 0xA00;
            if (temp_s0->unk_18 >= 0x6401) {
                temp_s0->unk_18 = 0x6400;
            }
            temp_s0->unk_2A = CalculateStatValue(STAT_SPEED, temp_s0->unk_00, temp_s0->unk_18, temp_s0->unk_24, temp_s0->unk_1E);
            *arg3 = temp_s0->unk_2A;
            break;

        case 38:
            sp34 = 4;
            *arg2 = temp_s0->unk_2C;
            temp_s0->unk_1A += 0xA00;
            if (temp_s0->unk_1A >= 0x6401) {
                temp_s0->unk_1A = 0x6400;
            }
            temp_s0->unk_2C = CalculateStatValue(STAT_DEFENSE, temp_s0->unk_00, temp_s0->unk_1A, temp_s0->unk_24, temp_s0->unk_1E);
            *arg3 = temp_s0->unk_2C;
            break;

        case 39:
            sp34 = 5;
            *arg2 = temp_s0->unk_2E;
            temp_s0->unk_1C += 0xA00;
            if (temp_s0->unk_1C >= 0x6401) {
                temp_s0->unk_1C = 0x6400;
            }
            temp_s0->unk_2E = CalculateStatValue(STAT_ATTACK, temp_s0->unk_00, temp_s0->unk_1C, temp_s0->unk_24, temp_s0->unk_1E);
            *arg3 = temp_s0->unk_2E;
            break;

        case 40:
            sp34 = 0;
            *arg2 = temp_s0->unk_24;
            sp3A = temp_s0->unk_26;
            *(s32*)&temp_s0->unk_10 = func_800224B8(temp_s0->unk_00, (temp_s0->unk_24 + 1) & 0xFFFF);
            func_80022338(&arg0->unk_08);
            temp_s0->unk_02 = (temp_s0->unk_02 + temp_s0->unk_26) - sp3A;
            *arg3 = temp_s0->unk_24;
            break;
    }

    func_88317144(arg1);
    arg0->unk_00->unk_0C = 1;
    return sp34;
}

void func_88305BC4(unk_func_8830867C_02C_0CC_000* arg0, unk_func_8830867C_04C_030_02C_000* arg1, s32 arg2, s32* arg3,
                   s32* arg4) {
    s32 var_v1;
    unk_D_80072B00* temp_v0;
    unk_func_8830867C_02C_0CC_000_008* ptr = &arg0->unk_08;

    temp_v0 = func_8002ED40(ptr->unk_09[arg2]);

    var_v1 = temp_v0->unk_05 / 5;
    if (var_v1 >= 7) {
        var_v1 = 7;
    }

    *arg3 = ((ptr->unk_20[arg2] >> 6) * var_v1) + temp_v0->unk_05;
    *arg4 = *arg3 + var_v1;

    ptr->unk_20[arg2] += var_v1 + 0x40;

    func_88317144(arg1);

    arg0->unk_00->unk_0C = 1;
}

void func_88305C7C(unk_func_8830867C_02C_0CC_000_008* arg0, s32 arg1) {
    s32 i;

    for (i = arg1; i < 4; i++) {
        arg0->unk_09[i] = 0;
    }
}

void func_88305CDC(unk_func_8830867C_02C_0CC_000* arg0, unk_func_8830867C_04C_030_02C_000* arg1, s32 arg2) {
    unk_func_8830867C_02C_0CC_000_008* ptr = &arg0->unk_08;
    s32 var_a0;

    if (arg1->unk_00[0]->unk_00 >= 0xC9) {
        var_a0 = arg1->unk_00[0]->unk_00 - 0xC9;
    } else {
        var_a0 = arg1->unk_00[0]->unk_00 - 0x92;
    }

    ptr->unk_09[arg2] = func_80022A28(var_a0);
    ptr->unk_20[arg2] = func_8002ED40(ptr->unk_09[arg2])->unk_05;

    if (arg1->unk_00[0]->unk_00 >= 0xC9) {
        func_88317144(arg1);
    }
    arg0->unk_00->unk_0C = 1;
}

void func_88305D7C(unk_func_8830867C_02C* arg0, s32 arg1) {
    arg0->unk_000.unk_2A = arg1;
    arg0->unk_048->unk_00.unk_14(arg0->unk_048, arg1);
}

s32 func_88305DA8(unk_func_8830867C_02C* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_02C->unk_30 & 2) {
        var_v1 = arg0->unk_048->unk_00.unk_10(arg0->unk_048, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void func_88305DF4(unk_func_8830867C_02C* arg0, Controller* arg1) {
    s32 var_s3 = 0;
    s32 temp_v0;

    arg0->unk_048->unk_00.unk_14(arg0->unk_048, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_02C);

    while (!(arg0->unk_02C->unk_30 & 2)) {
        func_8002EEA8(NULL);
    }

    func_8830B2EC(arg0->unk_094, &arg0->unk_144);
    if (func_8830B954(arg0->unk_094, arg1) == 1) {
        func_883167CC(&arg0->unk_03C, &arg0->unk_144);
        func_88305270(arg0);
    }

    while (var_s3 == 0) {
        func_8002EEA8(NULL);
        temp_v0 = func_88305DA8(arg0, arg1);
        if (!(temp_v0 & 1) && (temp_v0 & 2)) {
            var_s3 = 1;
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(temp_v0);
    }
    arg0->unk_02C->unk_2C = 0xB;
}

#ifdef NON_MATCHING
void func_88305F28(unk_func_8830867C_02C* arg0) {
    unk_func_8830867C_04C_030_02C_000_000* spDC;
    unk_func_8830867C_02C_0CC_000* spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    unk_func_88001300_000_010 spC8;
    func88500A6C temp_v0_4;
    s32 spC0;
    s32 spBC;
    unk_func_88001300_000_010 spB8;
    s32 spB4;
    s32 spB0;
    s32 spAC;
    unk_func_88001300_000_010 spA8;
    unk_func_8830867C_02C_0CC_000 sp4C;
    char* sp48;
    char* sp44;
    s32 sp40;
    unk_func_8830867C_02C_0CC_000_008* sp34;

    spDC = arg0->unk_0AC->unk_30->unk_2C->unk_00->unk_00[arg0->unk_0AC->unk_30->unk_38];
    spD0 = arg0->unk_034->unk_00.unk_38;
    spD8 = arg0->unk_034->unk_00.unk_2C->unk_00[spD0];
    spCC = spD0 - (arg0->unk_034->unk_58 / arg0->unk_034->unk_00.unk_3E);

    if (spDC->unk_08 >= 0x64) {
        spC0 = func_8002ECDC(&spD8->unk_08);
        if (spC0 < 4) {
            func_88305C7C(&spD8->unk_08, spC0);
            spBC = -1;
            sp34 = (u8*)spD8 + spC0;
        } else {
            spC0 = arg0->unk_0AC->unk_78->unk_30->unk_38;
            sp34 = (u8*)spD8 + spC0;
            spBC = sp34->unk_11;
        }
        func_88305CDC(spD8, spDC, spC0);

        temp_v0_4 = ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C));
        arg0->unk_CD0 = 1;
        temp_v0_4(arg0->unk_038, 1);

        spC8.unk_00 = (arg0->unk_0DC->unk_18 * spC0) + 0x84;
        spC8.unk_02 = arg0->unk_034->unk_5C - arg0->unk_034->unk_58;

        func_88314920(arg0->unk_0BC, spBC, sp34->unk_11, spC8);
        func_88303520(arg0);
        ((func8850CF00)Memmap_GetFragmentVaddr(func_8850CF00))(arg0->unk_0B8, gPlayer1Controller);
        func_88305270(arg0);
        func_883051B0(arg0);
        spD4 = func_883054DC(arg0->unk_034->unk_00.unk_2C, spD8);
        if (spD4 == -1) {
            ((func88507C0C)Memmap_GetFragmentVaddr(func_88507C0C))(arg0->unk_034, spD0, spCC);
            func_8002D5D4(0x1A, spD8->unk_38);
            func_8002D5D4(0x1D, func_8002D7C0(NULL, 0, D_8831A4CC, spBC - 1));
            func_8002D5D4(0x1E, func_8002D7C0(NULL, 0, D_8831A4CC, sp34->unk_11 - 1));
            func_8002D7C0(arg0->unk_CCC->unk_40, 0x140, D_8831A4C4, 0x5D);
            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(arg0->unk_090, arg0->unk_CCC, 0, 0);
            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_090, gPlayer1Controller);
        } else {
            ((func88507C0C)Memmap_GetFragmentVaddr(func_88507C0C))(arg0->unk_034, spD4, spCC);
        }
    } else if (spDC->unk_08 >= 0x32) {
        spB4 = arg0->unk_0AC->unk_78->unk_30->unk_38;
        if ((!arg0) && (!arg0)) {}
        func_88305BC4(spD8, spDC, spB4, &spB0, &spAC);

        temp_v0_4 = ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C));
        arg0->unk_CD0 = 1;
        temp_v0_4(arg0->unk_038, 1);

        spB8.unk_00 = (arg0->unk_0DC->unk_18 * spB4) + 0x84;
        spB8.unk_02 = arg0->unk_034->unk_5C - arg0->unk_034->unk_58;
        func_883151B8(arg0->unk_0C0, spD8->unk_08.unk_09[spB4], spB0, spAC, spB8);
        func_88303520(arg0);
        ((func8850CF00)Memmap_GetFragmentVaddr(func_8850CF00))(arg0->unk_0B8, gPlayer1Controller);
    } else {
        sp4C = *spD8;

        sp40 = func_883058C4(&sp4C, spDC, &sp48, &sp44);

        temp_v0_4 = ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C));
        arg0->unk_CD0 = 2;
        temp_v0_4(arg0->unk_038, 2);

        spA8.unk_00 = (arg0->unk_0DC->unk_28 * sp40) + 0x84;
        spA8.unk_02 = arg0->unk_034->unk_5C - arg0->unk_034->unk_58;

        func_883156B8(arg0->unk_0C4, sp48, sp44, spA8);
        func_88303520(arg0);
        ((func8850CF00)Memmap_GetFragmentVaddr(func_8850CF00))(arg0->unk_0B8, gPlayer1Controller);

        *spD8 = sp4C;

        func_88305270(arg0);
        func_883051B0(arg0);
        spD4 = func_883054DC(arg0->unk_034->unk_00.unk_2C, spD8);
        if (spD4 == -1) {
            ((func88507C0C)Memmap_GetFragmentVaddr(func_88507C0C))(arg0->unk_034, spD0, spCC);
            func_8002D5D4(0x1A, spD8->unk_38);
            func_8002D600(2, sp48);
            func_8002D600(3, sp44);
            func_8002D7C0(arg0->unk_CCC->unk_40, 0x140, D_8831A4C4, 0x5E);
            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(arg0->unk_090, arg0->unk_CCC, 0, 0);
            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_090, gPlayer1Controller);
        } else {
            ((func88507C0C)Memmap_GetFragmentVaddr(func_88507C0C))(arg0->unk_034, spD4, spCC);
        }
    }
    func_88316F98(&arg0->unk_C48, arg0->unk_1A8, arg0->unk_154, 3, 0xAA);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_1CEA00/func_88305F28.s")
#endif

s32 func_88306544(unk_func_8830867C_02C* arg0, Controller* arg1) {
    char* sp28[6];
    u32 sp24;

    sp28[0] = func_8002D7C0(NULL, 0, D_8831A4C4, 0x17);
    sp28[1] = func_8002D7C0(NULL, 0, D_8831A4C4, 0x18);
    sp28[2] = func_8002D7C0(NULL, 0, D_8831A4C4, 0x19);
    sp28[3] = func_8002D7C0(NULL, 0, D_8831A4C4, 0x1A);
    sp28[4] = func_8002D7C0(NULL, 0, D_8831A4C4, 0x1B);
    sp28[5] = func_8002D7C0(NULL, 0, D_8831A4C4, 0x1C);

    func_8830BCE8(arg0->unk_08C, sp28, 6);

    arg0->unk_08C->unk_30 = arg0->unk_054->unk_10;
    arg0->unk_08C->unk_34 = arg0->unk_054->unk_14;

    func_8830BE3C(arg0->unk_08C);

    if ((arg0->unk_034->unk_00.unk_2C->unk_08 == 0) || (arg0->unk_C48.unk_08 == 0)) {
        arg0->unk_08C->unk_3C->unk_34[3] |= 4;
    }

    if ((arg0->unk_C54.unk_00 == 0) && (arg0->unk_C54.unk_04 == 0)) {
        arg0->unk_08C->unk_3C->unk_34[5] |= 4;
    }

    arg0->unk_04C->unk_14(arg0->unk_04C, 0x100);
    sp24 = func_8830C058(arg0->unk_08C, arg1, arg0->unk_CC4);
    arg0->unk_04C->unk_14(arg0->unk_04C, 1);

    arg0->unk_CC4 = arg0->unk_08C->unk_3C->unk_38;

    switch (sp24) {
        case 0:
            sp24 = 0;
            break;

        case 1:
            func_883050CC(arg0);
            func_88305268(arg0, 0x11);
            func_8002D180(arg0->unk_034->unk_00.unk_2C, D_8831A1F8[arg0->unk_C54.unk_00]);
            ((func88507AE4)Memmap_GetFragmentVaddr(func_88507AE4))(arg0->unk_034, 0);
            sp24 = 0;
            break;

        case 2:
            func_883050CC(arg0);
            func_88305268(arg0, 0x12);
            func_8002D180(arg0->unk_034->unk_00.unk_2C, D_8831A1F8[arg0->unk_C54.unk_00]);
            ((func88507AE4)Memmap_GetFragmentVaddr(func_88507AE4))(arg0->unk_034, 0);
            sp24 = 0;
            break;

        case 3:
            sp24 = 1;
            break;

        case 4:
            sp24 = 2;
            break;

        case 5:
            sp24 = 3;
            break;

        case 6:
            func_883051F8(arg0);
            func_88305270(arg0);
            func_883051B0(arg0);
            arg0->unk_CB8 = 0;
            sp24 = 0;
            break;
    }

    return sp24;
}

s32 func_8830681C(unk_func_8830867C_02C* arg0, Controller* arg1) {
    static char D_8831A500[0x20];

    char* sp44[5];
    u32 sp40;
    unk_func_8830867C_02C_0CC_000* sp3C;
    u32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;

    sp3C = arg0->unk_034->unk_00.unk_2C->unk_00[arg0->unk_034->unk_00.unk_38];
    if (arg0->unk_C54.unk_04 & 8) {
        sp38 = 0x24;
    } else {
        sp38 = 0x23;
    }

    func_8002D5D4(0x19, func_8002D7C0(NULL, 0, D_8831A4D0, sp3C->unk_08.unk_00 - 1));
    func_8002D7C0(D_8831A500, 0x20, D_8831A4C4, sp38);

    sp44[0] = D_8831A500;
    sp38 = (arg0->unk_C54.unk_04 & 0x10) ? (0x26) : (0x25);
    sp44[1] = func_8002D7C0(NULL, 0, D_8831A4C4, sp38);
    sp44[2] = func_8002D7C0(NULL, 0, D_8831A4C4, 0x27);
    sp44[3] = func_8002D7C0(NULL, 0, D_8831A4C4, 0x28);
    sp44[4] = func_8002D7C0(NULL, 0, D_8831A4C4, 0x29);

    func_8830BCE8(arg0->unk_08C, sp44, 5);

    arg0->unk_08C->unk_30.unk_00 = 0x26;
    arg0->unk_08C->unk_30.unk_02 = (arg0->unk_034->unk_5C - arg0->unk_034->unk_58) + 0x16;
    arg0->unk_08C->unk_34.unk_00 = 0x50;
    arg0->unk_08C->unk_34.unk_02 = 0x14;

    func_8830BE3C(arg0->unk_08C);

    if (arg0->unk_C48.unk_08 == 0) {
        arg0->unk_08C->unk_3C->unk_34[3] |= 4;
    }

    if ((sp3C->unk_08.unk_00 <= 0) || (sp3C->unk_08.unk_00 >= 0x98)) {
        arg0->unk_08C->unk_3C->unk_34[0] |= 4;
        arg0->unk_08C->unk_3C->unk_34[1] |= 4;
        arg0->unk_08C->unk_3C->unk_34[3] |= 4;
    }

    arg0->unk_034->unk_00.unk_00.unk_24(&arg0->unk_034->unk_00.unk_00, 0x100);

    sp40 = func_8830C058(arg0->unk_08C, arg1, arg0->unk_CC8);

    arg0->unk_034->unk_00.unk_00.unk_24(&arg0->unk_034->unk_00.unk_00, 1);
    arg0->unk_CC8 = arg0->unk_08C->unk_3C->unk_38;

    switch (sp40) {
        case 0:
            sp40 = 0;
            break;

        case 1:
            sp34 = arg0->unk_034->unk_00.unk_38 - (arg0->unk_034->unk_58 / arg0->unk_034->unk_00.unk_3E);

            func_883050CC(arg0);
            if (func_88305254(arg0, 8) != 0) {
                arg0->unk_C54.unk_10 = sp3C->unk_08.unk_00;
            }
            func_88305270(arg0);
            ((func88507C0C)Memmap_GetFragmentVaddr(func_88507C0C))(
                arg0->unk_034, func_883054DC(arg0->unk_034->unk_00.unk_2C, sp3C), sp34);
            sp40 = 0;
            break;

        case 2:
            sp30 = arg0->unk_034->unk_00.unk_38 - (arg0->unk_034->unk_58 / arg0->unk_034->unk_00.unk_3E);

            func_883050CC(arg0);
            if (func_88305254(arg0, 0x10) != 0) {
                sp2C = sp3C->unk_08.unk_00 - 1;

                arg0->unk_C54.unk_14.unk_00 = 1;

                arg0->unk_C54.unk_14.unk_04[0] = D_80070FA0[sp2C].unk_06;

                if (D_80070FA0[sp2C].unk_06 != D_80070FA0[sp2C].unk_07) {
                    arg0->unk_C54.unk_14.unk_04[1] = D_80070FA0[sp2C].unk_07;
                    arg0->unk_C54.unk_14.unk_00++;
                }
            }

            func_88305270(arg0);
            ((func88507C0C)Memmap_GetFragmentVaddr(func_88507C0C))(
                arg0->unk_034, func_883054DC(arg0->unk_034->unk_00.unk_2C, sp3C), sp30);
            sp40 = 0;
            break;

        case 3:
            sp40 = 1;
            break;

        case 4:
            sp40 = 2;
            break;

        case 5:
            sp40 = 3;
            break;
    }

    return sp40;
}

typedef struct unk_D_883172F4 {
    /* 0x00 */ u16* unk_00;
    /* 0x04 */ s32 unk_04;
} unk_D_883172F4; // size = 0x8

s32 func_88306C70(unk_func_8830867C_02C* arg0, unk_func_88001300_000* arg1, s32 arg2, Controller* arg3) {
    static s16 D_883172DC[] = {
        0x001E,
        0x001F,
        0x0020,
        0x0000,
    };
    static s16 D_883172E4[] = {
        0x001E,
        0x001F,
    };
    static s16 D_883172E8[] = {
        0x001D,
        0x0000,
    };
    static s16 D_883172EC[] = {
        0x0021,
        0x0000,
    };
    static s16 D_883172F0[] = {
        0x0022,
        0x0000,
    };
    static unk_D_883172F4 D_883172F4[] = {
        {
            D_883172EC,
            0x00000001,
        },
        {
            D_883172E8,
            0x00000001,
        },
        {
            D_883172EC,
            0x00000001,
        },
        {
            D_883172F0,
            0x00000001,
        },
        {
            NULL,
            0x00000000,
        },
        {
            NULL,
            0x00000000,
        },
        {
            D_883172DC,
            0x00000003,
        },
        {
            D_883172E4,
            0x00000002,
        },
        {
            D_883172E4,
            0x00000002,
        },
        {
            D_883172E4,
            0x00000002,
        },
        {
            D_883172E4,
            0x00000002,
        },
        {
            D_883172E4,
            0x00000002,
        },
    };

    u32 var_s0;
    s32 sp50;
    s32 i;
    char* sp40[3];

    for (i = 0; i < D_883172F4[arg2 - 2].unk_04; i++) {
        sp40[i] = func_8002D7C0(NULL, 0, D_8831A4C4, D_883172F4[arg2 - 2].unk_00[i]);
    }

    func_8830BCE8(arg0->unk_08C, sp40, D_883172F4[arg2 - 2].unk_04);

    arg0->unk_08C->unk_30 = arg1->unk_10;
    arg0->unk_08C->unk_34 = arg1->unk_14;

    func_8830BE3C(arg0->unk_08C);
    arg0->unk_04C->unk_14(arg0->unk_04C, 0x100);
    var_s0 = func_8830C058(arg0->unk_08C, arg3, 0);
    arg0->unk_04C->unk_14(arg0->unk_04C, 1);

    switch (var_s0) {
        case 0:
            var_s0 = 0;
            break;

        case 1:
            switch (arg2) {
                case 2:
                    sp50 = 0x10;
                    break;

                case 3:
                    sp50 = 0xE;
                    break;

                case 4:
                    sp50 = 0xF;
                    break;

                case 5:
                    sp50 = 1;
                    break;

                case 8:
                    sp50 = 3;
                    break;

                case 9:
                    sp50 = 5;
                    break;

                case 10:
                    sp50 = 7;
                    break;

                case 11:
                    sp50 = 9;
                    break;

                case 12:
                    sp50 = 0xB;
                    break;

                case 13:
                    sp50 = 0xD;
                    break;
            }

            func_883050CC(arg0);
            func_88305268(arg0, sp50);
            func_8002D180(arg0->unk_034->unk_00.unk_2C, D_8831A1F8[arg0->unk_C54.unk_00]);
            ((func88507AE4)Memmap_GetFragmentVaddr(func_88507AE4))(arg0->unk_034, 0);
            var_s0 = 0;
            break;

        case 2:
            switch (arg2) {
                case 8:
                    sp50 = 2;
                    break;

                case 9:
                    sp50 = 4;
                    break;

                case 10:
                    sp50 = 6;
                    break;

                case 11:
                    sp50 = 8;
                    break;

                case 12:
                    sp50 = 0xA;
                    break;

                case 13:
                    sp50 = 0xC;
                    break;
            }

            func_883050CC(arg0);
            func_88305268(arg0, sp50);
            func_8002D180(arg0->unk_034->unk_00.unk_2C, D_8831A1F8[arg0->unk_C54.unk_00]);

            ((func88507AE4)Memmap_GetFragmentVaddr(func_88507AE4))(arg0->unk_034, 0);
            var_s0 = 0;
            break;

        case 3:
            var_s0 = 1;
            break;
    }

    return var_s0;
}

u32 func_88306F90(unk_func_8830867C_02C* arg0) {
    s32 var_v1 = arg0->unk_04C->unk_24;

    if (var_v1 >= 2) {
        switch (arg0->unk_038->unk_2C) {
            case 0:
                break;

            case 1:
                var_v1 += 5;
                break;

            case 2:
                var_v1 += 6;
                break;
        }
    }

    return var_v1;
}

void func_88306FE4(void) {
}

void func_88306FEC(unk_func_8830867C_02C_048* arg0, unk_func_8830867C_02C* arg1) {
    ((func8850CBA8)Memmap_GetFragmentVaddr(func_8850CBA8))(arg0);
    arg0->unk_00.unk_10 = func_8830858C;
    arg0->unk_24 = arg1;
}

void func_88307038(unk_func_8830867C_02C* arg0, s32 arg1) {
    s32 sp24 = func_80029080();

    ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_0B0->unk_40, 2);

    func_8002EEA8(NULL);
    func_88316A58(&arg0->unk_144, arg1);
    func_88302C18(arg0);

    if (arg1 & 0x30) {
        func_800284B4(3);
    }

    if (arg1 & 0xF) {
        if (arg1 & 5) {
            func_80025540(sp24);
        }
        ((func88900970)Memmap_GetFragmentVaddr(func_88900970))(arg0->unk_0B0, sp24);
    }

    if (arg1 & 0x30) {
        func_80026E4C(3);
        func_800284B4(3);
    }
}

void func_88307110(unk_func_8830867C_02C* arg0) {
    s32 i;
    s32 var_v0;
    unk_func_8830867C_02C_0CC_000** temp_v0_2;
    unk_func_8830867C_04C_030_02C_000_000* temp_s1;

    temp_s1 = arg0->unk_0AC->unk_30->unk_2C->unk_00[arg0->unk_0AC->unk_30->unk_38].unk_00[0];
    temp_v0_2 = arg0->unk_034->unk_00.unk_2C->unk_00;

    for (i = 0; i < arg0->unk_034->unk_00.unk_2C->unk_08; i++) {
        if ((temp_v0_2[i]->unk_08.unk_00 <= 0) || (temp_v0_2[i]->unk_08.unk_00 >= 0x98)) {
            arg0->unk_034->unk_00.unk_34[i] |= 4;
        } else {
            if (temp_s1->unk_08 >= 0x64) {
                var_v0 = func_88311D6C(**(u8**)&temp_s1->unk_00, &temp_v0_2[i]->unk_08);
            } else if (temp_s1->unk_08 >= 0x32) {
                var_v0 = func_88311E28(&temp_v0_2[i]->unk_08);
            } else {
                var_v0 = func_88311EB4(**(u8**)&temp_s1->unk_00, &temp_v0_2[i]->unk_08);
            }

            if (var_v0 != 0) {
                arg0->unk_034->unk_00.unk_34[i] |= 4;
            }
        }
    }
}

s32 func_88307250(unk_func_8830867C_02C* arg0) {
    return arg0->unk_144.unk_00->unk_0C->unk_10.unk_08 == 0;
}

s32 func_88307264(unk_func_8830867C_02C* arg0, Controller* arg1, s32 arg2) {
    s32 sp34;
    s32 sp30;
    s32 temp_v0_2;

    sp34 = 1;
    sp30 = func_88305458(arg0);
    if (sp30 != 0) {
        arg0->unk_048->unk_00.unk_14(arg0->unk_048, 0);
        ((func889006D4)Memmap_GetFragmentVaddr(func_889006D4))(arg0->unk_0B0, func_88307250(arg0));

        temp_v0_2 = ((func88900808)Memmap_GetFragmentVaddr(func_88900808))(arg0->unk_0B0, arg1, 1);
        if (temp_v0_2 == 0) {
            func_88307038(arg0, sp30);
            ((func889007AC)Memmap_GetFragmentVaddr(func_889007AC))(arg0->unk_0B0);
        } else if (temp_v0_2 == 1) {
            ((func889007AC)Memmap_GetFragmentVaddr(func_889007AC))(arg0->unk_0B0);
        } else if (temp_v0_2 == 2) {
            ((func889007AC)Memmap_GetFragmentVaddr(func_889007AC))(arg0->unk_0B0);
            sp34 = 0;
        }

        arg0->unk_048->unk_00.unk_14(arg0->unk_048, 1);
    } else if ((arg2 == 0) && (arg0->unk_CB8 != 0)) {
        arg0->unk_048->unk_00.unk_14(arg0->unk_048, 0);
        if (func_88314340(arg0->unk_0B4, arg1) == 1) {
            sp34 = 0;
        }
        arg0->unk_048->unk_00.unk_14(arg0->unk_048, 1);
    }
    return sp34;
}

void func_883073E8(unk_func_8830867C_02C* arg0, s32 arg1) {
    if (arg1 != 0) {
        arg0->unk_02C->unk_00.unk_28 |= 0x200;
        arg0->unk_030->unk_00.unk_28 |= 1;
        arg0->unk_04C->unk_14(arg0->unk_04C, 1);
    } else {
        arg0->unk_02C->unk_00.unk_28 &= ~0x200;
        arg0->unk_030->unk_00.unk_28 &= ~1;
        arg0->unk_04C->unk_14(arg0->unk_04C, 0);
    }
}

void func_88307478(unk_func_8830867C_02C_048* arg0) {
    ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0->unk_24->unk_034);
    arg0->unk_24->unk_0E0 = 0;
    ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0, 1);
}

void func_883074D4(unk_func_8830867C_02C_048* arg0, Controller* arg1) {
    func_883073E8(arg0->unk_24, 0);
    func_8002EEA8(NULL);
    func_8002EEA8(NULL);

    if (func_88312998(arg0->unk_24->unk_0AC, arg1) == 2) {
        arg0->unk_24->unk_0E0 = 1;
        func_88307110(arg0->unk_24);
        ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0, 0);
    } else {
        func_8002EEA8(NULL);
        func_883073E8(arg0->unk_24, 1);
    }
}

s32 func_8830757C(unk_func_8830867C_02C_048* arg0, Controller* arg1) {
    s32 sp1C = 2;

    func_80048B90(3);

    if (arg0->unk_24->unk_CB4 != 0) {
        func_88305168(arg0->unk_24);
        func_88305270(arg0->unk_24);
        ((func88507C0C)Memmap_GetFragmentVaddr(func_88507C0C))(arg0->unk_24->unk_034, arg0->unk_24->unk_CBC,
                                                               arg0->unk_24->unk_CC0);
        sp1C = 3;
    } else if (func_88307264(arg0->unk_24, arg1, 0) == 0) {
        sp1C = 3;
    }
    return sp1C;
}

s32 func_88307628(unk_func_8830867C_02C_048* arg0, Controller* arg1) {
    s32 var_v1 = 0;

    if (gPlayer1Controller->buttonPressed & 2) {
        func_80048B90(2);
        if (arg0->unk_24->unk_CD0 == 0) {
            arg0->unk_24->unk_CD0 += 3;
        }
        arg0->unk_24->unk_CD0--;
        ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_24->unk_038, arg0->unk_24->unk_CD0);
        func_88303520(arg0->unk_24);
        var_v1 = 0x80000005;
    } else if (gPlayer1Controller->buttonPressed & 1) {
        func_80048B90(2);
        if (arg0->unk_24->unk_CD0 >= 2) {
            arg0->unk_24->unk_CD0 -= 3;
        }
        arg0->unk_24->unk_CD0++;
        ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_24->unk_038, arg0->unk_24->unk_CD0);
        func_88303520(arg0->unk_24);
        var_v1 = 0x80000005;
    }

    return var_v1;
}

s32 func_8830772C(unk_func_8830867C_02C_048* arg0, Controller* arg1, s32 arg2) {
    UNUSED s32 pad;
    s32 temp_v0;
    unk_func_8830867C_02C_0CC_000* sp24;
    unk_func_8830867C_02C_0CC_000* sp20;

    if (arg0->unk_24->unk_0E0 != 0) {
        if (arg2 & 2) {
            func_80048B90(3);
            func_88307478(arg0);
            func_883074D4(arg0, arg1);
            arg2 = 1;
        } else if (arg2 & 4) {
            if (arg0->unk_24->unk_034->unk_00.unk_34[arg0->unk_24->unk_034->unk_00.unk_38] & 4) {
                func_80048B90(8);
                arg2 = 1;
            } else {
                func_80048B90(2);
                func_88312018(
                    arg0->unk_24->unk_0AC,
                    &arg0->unk_24->unk_034->unk_00.unk_2C->unk_00[arg0->unk_24->unk_034->unk_00.unk_38]->unk_08);

                arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 0x100);

                if (func_88312998(arg0->unk_24->unk_0AC, arg1) == 1) {
                    func_8002EEA8(NULL);
                    func_88305F28(arg0->unk_24);
                    func_88307478(arg0);
                    func_883073E8(arg0->unk_24, 1);
                } else {
                    arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 1);
                }
            }
        }
        arg2 = 1;
    } else if (arg2 & 8) {
        if (arg1->buttonPressed & 0x800) {
            ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0, 1);
            ((func8850CB48)Memmap_GetFragmentVaddr(func_8850CB48))(arg0->unk_24->unk_04C, 1);
            arg2 |= 0x80000001;
        }
    } else {
        if (arg2 & 2) {
            arg2 = func_8830757C(arg0, arg1);
        } else if (arg2 & 4) {
            if (arg0->unk_24->unk_034->unk_00.unk_2C->unk_08 == 0) {
                func_80048B90(8);
                arg2 = 1;
            } else {
                func_80048B90(2);
                temp_v0 = func_8830681C(arg0->unk_24, arg1);
                if (temp_v0 == 1) {
                    sp24 = arg0->unk_24->unk_034->unk_00.unk_2C->unk_00[arg0->unk_24->unk_034->unk_00.unk_38];

                    func_883139E8(arg0->unk_24->unk_0A8, sp24->unk_00->unk_00->unk_08, sp24->unk_00->unk_04);
                    func_88313894(arg0->unk_24->unk_0A8, sp24);

                    arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 0x100);

                    func_8002EEA8(NULL);
                    func_8002EEA8(NULL);
                    if (func_88313E50(arg0->unk_24->unk_0A8, arg1) == 1) {
                        func_88305520(arg0->unk_24, sp24, arg1);
                    }
                    func_8002EEA8(NULL);

                    arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 1);

                    arg2 = 1;
                } else if (temp_v0 == 2) {
                    func_88311F70(arg0->unk_24->unk_0AC, &arg0->unk_24->unk_C48);
                    func_88312018(
                        arg0->unk_24->unk_0AC,
                        &arg0->unk_24->unk_034->unk_00.unk_2C->unk_00[arg0->unk_24->unk_034->unk_00.unk_38]->unk_08);
                    func_88312188(arg0->unk_24->unk_0AC, 0);

                    arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 0x100);

                    func_8002EEA8(NULL);
                    func_8002EEA8(NULL);
                    if (func_88312998(arg0->unk_24->unk_0AC, arg1) == 1) {
                        func_88305F28(arg0->unk_24);
                    }
                    func_8002EEA8(NULL);

                    arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 1);

                    arg2 = 1;
                } else {
                    if (temp_v0 == 3) {
                        sp20 = arg0->unk_24->unk_034->unk_00.unk_2C->unk_00[arg0->unk_24->unk_034->unk_00.unk_38];

                        arg0->unk_24->unk_CDC->unk_0C = &sp20->unk_08;
                        arg0->unk_24->unk_CDC->unk_10 = sp20->unk_00->unk_00->unk_08;

                        arg0->unk_24->unk_CD8(1, arg0->unk_24->unk_CDC);

                        arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 0x100);

                        if (arg0->unk_24->unk_CD8(4, arg0->unk_24->unk_CDC) == 1) {
                            sp20->unk_00->unk_0C = 1;
                        }
                        func_8002EEA8(NULL);

                        arg0->unk_24->unk_034->unk_00.unk_00.unk_24(&arg0->unk_24->unk_034->unk_00.unk_00, 1);
                    }
                    arg2 = 1;
                }
            }
        } else if (gPlayer1Controller->buttonPressed & 0x10) {
            ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0, 1);
            arg2 = 0x80000005;
        } else {
            arg2 = func_88307628(arg0, arg1);
        }
    }

    return arg2;
}

s32 func_88307C2C(unk_func_8830867C_02C_048* arg0, Controller* arg1, s32 arg2) {
    u32 sp34;
    s32 temp_s0_11;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 temp_s0_23;
    s32 temp_s0_27;
    s32 temp_v0_2;

    if (arg2 & 8) {
        if ((arg1->buttonPressed == 0x400) && (arg0->unk_24->unk_04C->unk_24 == 1)) {
            ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0, 0);
            ((func88507AE4)Memmap_GetFragmentVaddr(func_88507AE4))(
                arg0->unk_24->unk_034, arg0->unk_24->unk_034->unk_58 / arg0->unk_24->unk_034->unk_00.unk_3E);
            arg0->unk_24->unk_034->unk_6C = 8;
            arg0->unk_24->unk_034->unk_54 = 0x400;
            arg2 |= 0x80000001;
        }
    } else {
        if (arg2 & 2) {
            arg2 = func_8830757C(arg0, arg1);
        } else if (arg2 & 4) {
            sp34 = func_88306F90(arg0->unk_24);
            switch (sp34) {
                case 0:
                    func_80048B90(3);
                    arg2 = 2;
                    if (func_88307264(arg0->unk_24, arg1, 1) == 0) {
                        arg2 = 3;
                    }
                    break;

                case 1:
                    func_80048B90(2);
                    temp_v0_2 = func_88306544(arg0->unk_24, arg1);
                    if (temp_v0_2 == 1) {
                        sp2C = -1;
                        if (func_88305220(arg0->unk_24, 0x20) != 0) {
                            sp2C = arg0->unk_24->unk_C54.unk_2C;
                        }
                        func_8830CD4C(arg0->unk_24->unk_098, sp2C);

                        arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 0x100);

                        func_8002EEA8(NULL);
                        func_8002EEA8(NULL);

                        sp2C = func_8830CE84(arg0->unk_24->unk_098, arg1);
                        func_8002EEA8(NULL);

                        arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 1);

                        if (sp2C > 0) {
                            sp2C--;
                            func_883050CC(arg0->unk_24);

                            if ((sp2C + 1) == arg0->unk_24->unk_098->unk_30->unk_2C->unk_08) {
                                func_88305240(arg0->unk_24, 0x20);
                            } else {
                                func_88305230(arg0->unk_24, 0x20);
                                arg0->unk_24->unk_C54.unk_2C = sp2C;
                            }

                            func_88305270(arg0->unk_24);
                            arg2 = 1;
                        }
                    } else if (temp_v0_2 == 2) {
                        func_88311F70(arg0->unk_24->unk_0AC, &arg0->unk_24->unk_C48);
                        func_88312018(arg0->unk_24->unk_0AC, 0);
                        func_88312188(arg0->unk_24->unk_0AC, 1);
                        func_883074D4(arg0, arg1);
                        arg2 = 1;
                    } else {
                        if (temp_v0_2 == 3) {
                            func_8830B2EC(arg0->unk_24->unk_094, &arg0->unk_24->unk_144);

                            arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 0x100);

                            func_8002EEA8(NULL);
                            func_8002EEA8(NULL);
                            if (func_8830B954(arg0->unk_24->unk_094, arg1) == 1) {
                                func_883167CC(&arg0->unk_24->unk_03C, &arg0->unk_24->unk_144);
                                func_88305270(arg0->unk_24);
                                func_883051B0(arg0->unk_24);
                            }
                            func_8002EEA8(NULL);
                            arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 1);
                        }
                    }
                    arg2 = 1;
                    break;

                case 2:
                    func_80048B90(2);
                    func_88306C70(arg0->unk_24, arg0->unk_24->unk_058, sp34, arg1);
                    arg2 = 1;
                    break;

                case 3:
                    func_80048B90(2);
                    func_88306C70(arg0->unk_24, arg0->unk_24->unk_05C, sp34, arg1);
                    arg2 = 1;
                    break;

                case 4:
                    func_80048B90(2);
                    func_88306C70(arg0->unk_24, arg0->unk_24->unk_060, sp34, arg1);
                    arg2 = 1;
                    break;

                case 5:
                    func_80048B90(2);
                    func_88306C70(arg0->unk_24, arg0->unk_24->unk_064, sp34, arg1);
                    arg2 = 1;
                    break;

                case 8:
                    func_80048B90(2);
                    if (func_88306C70(arg0->unk_24, arg0->unk_24->unk_070, sp34, arg1) == 1) {
                        if (arg0->unk_24->unk_C54.unk_0C != 0) {
                            sp28 = arg0->unk_24->unk_C54.unk_09;
                            sp24 = arg0->unk_24->unk_C54.unk_08;
                        } else {
                            sp28 = arg0->unk_24->unk_C54.unk_08;
                            sp24 = arg0->unk_24->unk_C54.unk_09;
                        }
                        func_8830DAB8(arg0->unk_24->unk_0A4, sp28, sp24, func_88305220(arg0->unk_24, 1));

                        arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 0x100);

                        func_8002EEA8(NULL);
                        func_8002EEA8(NULL);
                        temp_s0_11 = func_8830DC58(arg0->unk_24->unk_0A4, arg1);
                        func_8002EEA8(NULL);

                        arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 1);

                        if (temp_s0_11 != 0) {
                            if (temp_s0_11 == 1) {
                                func_883050CC(arg0->unk_24);
                                if (arg0->unk_24->unk_0A4->unk_3C->unk_30.unk_00 >=
                                    arg0->unk_24->unk_0A4->unk_38->unk_30.unk_00) {
                                    arg0->unk_24->unk_C54.unk_0C = 0;
                                    arg0->unk_24->unk_C54.unk_08 = arg0->unk_24->unk_0A4->unk_38->unk_30.unk_00;
                                    arg0->unk_24->unk_C54.unk_09 = arg0->unk_24->unk_0A4->unk_3C->unk_30.unk_00;
                                    func_88305268(arg0->unk_24, 2);
                                } else {
                                    arg0->unk_24->unk_C54.unk_0C = 1;
                                    arg0->unk_24->unk_C54.unk_09 = arg0->unk_24->unk_0A4->unk_38->unk_30.unk_00;
                                    arg0->unk_24->unk_C54.unk_08 = arg0->unk_24->unk_0A4->unk_3C->unk_30.unk_00;
                                    func_88305268(arg0->unk_24, 3);
                                }
                                func_88305230(arg0->unk_24, 1);
                                func_88305270(arg0->unk_24);
                                arg2 = 1;
                            } else {
                                if (temp_s0_11 == 2) {
                                    func_883050CC(arg0->unk_24);
                                    arg0->unk_24->unk_C54.unk_08 = 1;
                                    arg0->unk_24->unk_C54.unk_09 = 0x64;
                                    arg0->unk_24->unk_C54.unk_0C = 0;
                                    func_88305240(arg0->unk_24, 1);
                                    func_88305270(arg0->unk_24);
                                }
                            }
                        }
                    }
                    arg2 = 1;
                    break;

                case 9:
                    func_80048B90(2);
                    func_88306C70(arg0->unk_24, arg0->unk_24->unk_074, sp34, arg1);
                    arg2 = 1;
                    break;

                case 10:
                    func_80048B90(2);
                    func_88306C70(arg0->unk_24, arg0->unk_24->unk_078, sp34, arg1);
                    arg2 = 1;
                    break;

                case 11:
                    func_80048B90(2);
                    func_88306C70(arg0->unk_24, arg0->unk_24->unk_07C, sp34, arg1);
                    arg2 = 1;
                    break;

                case 12:
                    func_80048B90(2);
                    func_88306C70(arg0->unk_24, arg0->unk_24->unk_080, sp34, arg1);
                    arg2 = 1;
                    break;

                case 13:
                    func_80048B90(2);
                    func_88306C70(arg0->unk_24, arg0->unk_24->unk_084, sp34, arg1);
                    arg2 = 1;
                    break;

                case 6:
                    func_80048B90(2);
                    func_8830EE58(arg0->unk_24->unk_09C, &arg0->unk_24->unk_C54.unk_1C);

                    arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 0x100);

                    temp_s0_23 = func_8830F114(arg0->unk_24->unk_09C, arg1);
                    arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 1);

                    if (temp_s0_23 != 0) {
                        if (temp_s0_23 == 1) {
                            func_883050CC(arg0->unk_24);
                            func_8830F05C(arg0->unk_24->unk_09C, &arg0->unk_24->unk_C54.unk_1C);
                            if (arg0->unk_24->unk_C54.unk_1C.unk_00 == 0) {
                                func_88305240(arg0->unk_24, 2);
                            } else {
                                func_88305230(arg0->unk_24, 2);
                            }
                            func_88305270(arg0->unk_24);
                        } else if (temp_s0_23 == 2) {
                            func_883050CC(arg0->unk_24);
                            func_88305240(arg0->unk_24, 2);
                            arg0->unk_24->unk_C54.unk_1C.unk_00 = 0;
                            func_88305270(arg0->unk_24);
                        }
                    }
                    arg2 = 1;
                    break;

                case 7:
                    func_80048B90(2);
                    func_883103CC(arg0->unk_24->unk_0A0, &arg0->unk_24->unk_C54.unk_24);

                    arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 0x100);

                    temp_s0_27 = func_883106C8(arg0->unk_24->unk_0A0, arg1);

                    arg0->unk_24->unk_04C->unk_14(arg0->unk_24->unk_04C, 1);

                    if (temp_s0_27 != 0) {
                        if (temp_s0_27 == 1) {
                            func_883050CC(arg0->unk_24);
                            func_883105D4(arg0->unk_24->unk_0A0, &arg0->unk_24->unk_C54.unk_24);
                            if (arg0->unk_24->unk_C54.unk_24.unk_04 == 0) {
                                func_88305240(arg0->unk_24, 4);
                            } else {
                                func_88305230(arg0->unk_24, 4);
                            }
                            func_88305270(arg0->unk_24);
                            arg2 = 1;
                        } else if (temp_s0_27 == 2) {
                            func_883050CC(arg0->unk_24);
                            func_88305240(arg0->unk_24, 4);
                            arg0->unk_24->unk_C54.unk_24.unk_04 = 0;
                            func_88305270(arg0->unk_24);
                        }
                    }
                    arg2 = 1;
                    break;
            }
        } else if (gPlayer1Controller->buttonPressed & 0x20) {
            ((func8850CD24)Memmap_GetFragmentVaddr(func_8850CD24))(arg0, 0);
            arg2 = 0x80000005;
        } else {
            arg2 = func_88307628(arg0, arg1);
        }
    }

    return arg2;
}

s32 func_8830858C(unk_func_8830867C_02C_048* arg0, Controller* arg1) {
    s32 i;
    s32 var_a2 = 0;
    unk_func_8830867C_02C_048* var_a0;

    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;

        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }

        var_a2 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

    if (var_a2 & 1) {
        return var_a2;
    }

    if (var_a2 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_a2 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_a2 = 0x80000004;
        }
    }

    switch (arg0->unk_00.unk_1C) {
        case 0:
            var_a2 = func_8830772C(arg0, arg1, var_a2);
            break;

        case 1:
            var_a2 = func_88307C2C(arg0, arg1, var_a2);
            break;
    }

    return var_a2;
}

void func_8830867C(unk_func_8830867C* arg0, s32 arg1, s32 arg2, MemoryPool* arg3, unk_D_800AC870* arg4, char** arg5,
                   char** arg6, char** arg7, char** arg8, char** arg9) {
    static Color_RGBA8 D_88317354 = { 0x1E, 0x50, 0x50, 0xFF };
    static Color_RGBA8 D_88317358 = { 0x00, 0x0A, 0x0A, 0xFF };

    unk_func_88001300_000* sp8C;
    unk_func_88001300_000* sp88;
    FragmentEntry sp84;
    unk_func_88500EE4* sp80;
    unk_func_885088F4* sp7C;
    unk_func_88509A2C* sp78;
    unk_func_88509E34* sp74;
    unk_func_88001300_000* sp70;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8830867C));

    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    sp8C = mem_pool_alloc(arg3, sizeof(unk_func_88001300_000));
    ((func885031E8)Memmap_GetFragmentVaddr(func_885031E8))(sp8C, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&arg0->unk_00.unk_00, &sp8C->unk_00);

    sp80 = mem_pool_alloc(arg3, sizeof(unk_func_88500EE4));
    ((func88500EE4)Memmap_GetFragmentVaddr(func_88500EE4))(sp80, 0, 0, 0x280, 0x1E0, D_88318898, D_88317354,
                                                           D_88317358);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&sp8C->unk_00, &sp80->unk_00.unk_00);

    sp7C = mem_pool_alloc(arg3, sizeof(unk_func_885088F4));
    ((func885088F4)Memmap_GetFragmentVaddr(func_885088F4))(sp7C, 0x41, 0x15C, 0xDC);
    sp7C->unk_2C = 5;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&sp8C->unk_00, &sp7C->unk_00.unk_00);

    sp78 = mem_pool_alloc(arg3, sizeof(unk_func_88509A2C));
    ((func88509A2C)Memmap_GetFragmentVaddr(func_88509A2C))(sp78, 0x38, 0x22, func_80029080(),
                                                           func_8002D7C0(NULL, 0, D_8831A4C0, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&sp7C->unk_00.unk_00, &sp78->unk_00.unk_00);

    sp74 = mem_pool_alloc(arg3, sizeof(unk_func_88509E34));
    ((func88509E34)Memmap_GetFragmentVaddr(func_88509E34))(sp74, 0, 0, func_8002D7C0(NULL, 0, D_8831A4C4, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&sp7C->unk_00.unk_00, &sp74->unk_00.unk_00);

    sp88 = mem_pool_alloc(arg3, sizeof(unk_func_88001300_000));
    ((func885031E8)Memmap_GetFragmentVaddr(func_885031E8))(sp88, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&arg0->unk_00.unk_00, &sp88->unk_00);

    arg0->unk_30 = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_030));
    func_8830BAC4(arg0->unk_30, sp88, arg3);

    arg0->unk_34 = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_034));
    func_8830ACA0(arg0->unk_34, 0x56, 0x78, sp88, arg3);

    arg0->unk_38 = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_038));
    func_8830C218(arg0->unk_38, 0x56, 0x96, sp88, arg3);

    arg0->unk_3C = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_03C));
    func_8830E504(arg0->unk_3C, 0xAA, 0x78, sp88, arg3);

    arg0->unk_40 = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_040));
    func_8830FA80(arg0->unk_40, 0xAA, 0x78, sp88, arg3);

    arg0->unk_44 = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_044));
    func_8830D2F8(arg0->unk_44, 0xAA, 0xF5, sp88, arg3);

    arg0->unk_48 = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_048));
    func_88312D7C(arg0->unk_48, 0xAA, 0x78, sp88, arg3);

    arg0->unk_4C = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_04C));
    func_883112B0(arg0->unk_4C, 0xE7, 0x94, sp88, arg3);

    arg0->unk_50 = mem_pool_alloc(arg3, sizeof(unk_func_889000C4));

    ((func889000C4)Memmap_GetFragmentVaddr(func_889000C4))(arg0->unk_50, 0, 0, 0, arg5, arg3);

    sp84 = FRAGMENT_LOAD(fragment27);

    arg0->unk_54.unk_04 = arg3;
    // clang-format off
    arg0->unk_54.unk_00 = 0x38; arg0->unk_54.unk_02 = 0x4E;
    // clang-format on
    arg0->unk_54.unk_14 = sp88;
    arg0->unk_6C = 0;
    arg0->unk_70 = arg6;
    arg0->unk_74 = D_8831A4D0;
    arg0->unk_78 = D_8831A4CC;
    arg0->unk_7C = D_8831A4D4;
    arg0->unk_80 = arg7;
    arg0->unk_84 = arg8;
    arg0->unk_88 = arg9;

    sp84(0, &arg0->unk_54);

    arg0->unk_2C = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_02C));
    func_883036AC(arg0->unk_2C, 0x2C, 0x48, sp8C, arg0->unk_30, arg0->unk_34, arg0->unk_38, arg0->unk_3C, arg0->unk_40,
                  arg0->unk_44, arg0->unk_48, arg0->unk_4C, arg0->unk_50, sp84, &arg0->unk_54, arg3, arg4);

    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&sp88->unk_00, &arg0->unk_2C->unk_000.unk_00);

    sp70 = mem_pool_alloc(arg3, sizeof(unk_func_88001300_000));

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(sp70, 0x2C);

    // clang-format off
    sp70->unk_10.unk_00 = 0x2C; sp70->unk_10.unk_02 = 0x7C;
    // clang-format on

    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&arg0->unk_00.unk_00, &sp70->unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&sp70->unk_00, &arg0->unk_30->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&arg0->unk_00.unk_00, &arg0->unk_34->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&arg0->unk_00.unk_00, &arg0->unk_38->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&arg0->unk_00.unk_00, &arg0->unk_3C->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&arg0->unk_00.unk_00, &arg0->unk_40->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&arg0->unk_00.unk_00, &arg0->unk_44->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&arg0->unk_00.unk_00, &arg0->unk_48->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&arg0->unk_00.unk_00, &arg0->unk_4C->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&arg0->unk_00.unk_00, &arg0->unk_50->unk_00.unk_00);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&arg0->unk_00.unk_00, &arg0->unk_54.unk_08->unk_00);

    arg0->unk_50->unk_00.unk_10.unk_00 =
        arg0->unk_2C->unk_000.unk_10.unk_00 +
        ((arg0->unk_2C->unk_02C->unk_00.unk_14.unk_00 - arg0->unk_50->unk_2C->unk_00.unk_14.unk_00) / 2);
    arg0->unk_50->unk_00.unk_10.unk_02 =
        arg0->unk_2C->unk_000.unk_10.unk_02 +
        ((arg0->unk_2C->unk_02C->unk_00.unk_14.unk_02 - arg0->unk_50->unk_2C->unk_00.unk_14.unk_02) / 2);
}

void func_88308D60(unk_func_8830867C* arg0) {
    s32 sp34 = 0;

    while (sp34 == 0) {
        func_800079C4();

        ((func885008C4)Memmap_GetFragmentVaddr(func_885008C4))(&arg0->unk_00);
        ((func88500828)Memmap_GetFragmentVaddr(func_88500828))(&arg0->unk_00, 0, 0);

        func_80007778();
        func_8002EF18(&sp34);
    }
}

void func_88308DFC(unk_func_8830867C* arg0) {
    func_8001F738(gPlayer1Controller);
    func_88305DF4(arg0->unk_2C, gPlayer1Controller);

    while (arg0->unk_2C->unk_02C->unk_00.unk_28 & 1) {
        func_8002EEA8(NULL);
    }

    func_8002EEA8(1);
    osStopThread(NULL);
}

s32 func_88308E84(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_D_800AC870* sp54;
    MemoryPool* sp50;
    void* sp4C;
    u8* sp48;
    func_88002628_sp38* sp44;
    char** sp40;
    char** sp3C;
    char** sp38;
    char** sp34;
    char** sp30;

    main_pool_push_state('PCHK');

    sp54 = func_8001E94C(0x1C, 0);

    ASSET_LOAD(D_04000000, fragment29_misc_1, 0);
    FRAGMENT_LOAD(fragment26);
    FRAGMENT_LOAD(fragment25);
    FRAGMENT_LOAD(fragment29);

    func_8002D510();

    D_8831A4C0 = func_8002D5AC(0x2A);
    D_8831A4CC = func_8002D5AC(0x25);
    D_8831A4D0 = func_8002D5AC(0x24);
    D_8831A4D4 = func_8002D5AC(0x26);
    D_8831A4C4 = func_8002D5AC(5);
    D_8831A4D8 = func_8002D5AC(0x27);
    D_8831A4C8 = func_8002D5AC(0xC);

    sp40 = func_8002D5AC(7);
    sp3C = func_8002D5AC(6);
    sp38 = func_8002D5AC(0x28);
    sp34 = func_8002D5AC(0x29);
    sp30 = func_8002D5AC(0xB);

    sp48 = main_pool_alloc(0x1000, 0);

    sp50 = mem_pool_try_init(0x18000, 0);

    sp4C = mem_pool_alloc(sp50, sizeof(unk_func_8830867C));
    func_8830867C(sp4C, 0, 0, sp50, sp54, sp40, sp3C, sp38, sp34, sp30);

    sp44 = ALIGN16((u32)mem_pool_alloc(sp50, sizeof(func_88002628_sp38)));

    osCreateThread(&sp44->thread, 0x32, func_88308DFC, sp4C, sp48 + 0x1000, osGetThreadPri(NULL) - 1);

    func_8002EE78();

    osStartThread(&sp44->thread);

    func_80007754();
    func_88308D60(sp4C);

    osDestroyThread(&sp44->thread);

    func_8000771C();

    main_pool_pop_state('PCHK');

    FRAGMENT_LOAD_AND_CALL2(fragment23, 4, 0);

    return 0x25;
}
