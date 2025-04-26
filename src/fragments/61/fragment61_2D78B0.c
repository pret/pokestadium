#include "fragment61.h"
#include "src/19840.h"
#include "src/1AB70.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/20470.h"
#include "src/225A0.h"
#include "src/22630.h"
#include "src/232C0.h"
#include "src/26820.h"
#include "src/29BA0.h"
#include "src/2C1C0.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/DDC0.h"
#include "src/F420.h"
#include "src/fragments/61/fragment61.h"
#include "src/hal_libc.h"
#include "src/memory.h"
#include "src/stage_loader.h"

BinArchive* D_84211B30;
void* D_84211B34;
unk_D_842168A0_0013C* D_84211B38;
char** D_84211B3C;
char** D_84211B40;
char** D_84211B44;
char** D_84211B48;
char** D_84211B4C;
unk_D_84211B50 D_84211B50;
unk_D_842168A0 D_842168A0;
unk_D_84229EB0 D_84229EB0;
unk_D_8423D3A8 D_8423D3A8;
unk_D_8423D3D8 D_8423D3D8[4];
s16 D_8423D3F8;

s16 D_84210D40 = 2;
s16 D_84210D44 = 0x20;
s16 D_84210D48 = 0;
u8 D_84210D4C[] = {
    0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0F,
};

s32 func_84200020(s32 arg0) {
    u32 temp_a0 = osSetIntMask(1);

    if (!(IO_READ(PI_STATUS_REG) & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) &&
        (((D_B0000800 & 0xFFFF) & 0xFFFF) != 1)) {
        arg0 = -0x80;
    }
    osSetIntMask(temp_a0);
    return arg0;
}

char* func_84200088(s32 arg0) {
    return func_8002D7C0(NULL, 0, D_84211B3C, arg0 - 1);
}

char* func_842000C0(s32 arg0) {
    return func_8002D7C0(NULL, 0, D_84211B40, arg0 - 1);
}

char* func_842000F8(s32 arg0) {
    return func_8002D7C0(NULL, 0, D_84211B44, func_800219FC(arg0));
}

char* func_84200130(s32 arg0) {
    return func_8002D7C0(NULL, 0, D_84211B48, arg0);
}

char* func_84200160(s32 arg0) {
    return func_8002D7C0(NULL, 0, D_84211B4C, arg0);
}

char* func_84200190(char* arg0, s32 arg1, s32 arg2) {
    return func_8002D7C0(arg0, arg1, D_84211B48, arg2);
}

void func_842001B8(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001CADC(arg0 - 3, arg1 - 3, 8, 8, D_2000340, 8, 0);
    func_8001CADC((arg0 + arg2) - 5, arg1 - 3, 8, 8, D_2000380, 8, 0);
    func_8001C330(arg0 + 4, arg1 - 3, arg2 - 8, 8, 0, 0, 0, 0x400, 0);
    func_8001CADC(arg0 - 3, (arg1 + arg3) - 5, 8, 8, D_20002C0, 8, 0);
    func_8001C330(arg0 - 3, arg1 + 4, 8, arg3 - 8, 0, 0, 0x400, 0, 0);
    func_8001CADC((arg0 + arg2) - 5, (arg1 + arg3) - 5, 8, 8, D_2000300, 8, 0);
    func_8001C330(arg0 + 4, (arg1 + arg3) - 5, arg2 - 8, 8, 0, 0, 0, 0x400, 0);
    func_8001C330((arg0 + arg2) - 5, arg1 + 4, 8, arg3 - 8, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84200420(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    func_8001CADC(arg0, arg1, 8, 8, D_2000B40, 8, 0);
    func_8001CADC((arg0 + arg2) - 8, arg1, 8, 8, D_2000B80, 8, 0);
    func_8001C330(arg0 + 8, arg1, arg2 - 0x10, 8, 0, 0, 0, 0x400, 0);
    func_8001CADC(arg0, (arg1 + arg3) - 8, 8, 8, D_2000BC0, 8, 0);
    func_8001C330(arg0, arg1 + 8, 8, arg3 - 0x10, 0, 0, 0x400, 0, 0);
    func_8001CADC((arg0 + arg2) - 8, (arg1 + arg3) - 8, 8, 8, D_2000C00, 8, 0);
    func_8001C330(arg0 + 8, (arg1 + arg3) - 8, arg2 - 0x10, 8, 0, 0, 0, 0x400, 0);
    func_8001C330((arg0 + arg2) - 8, arg1 + 8, 8, arg3 - 0x10, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    func_8001C604(arg0 + 8, arg1 + 8, arg2 - 0x10, arg3 - 0x10, arg4, arg5, arg6, arg7);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84200738(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    static s16 D_84210D58 = 0;

    s16 sp56 = SINS(D_84210D58) * 2;
    UNUSED s32 pad[2];

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 240, 212, 104, 255);

    func_8001CADC(arg0 + sp56, arg1 + sp56, 0x10, 0x10, D_2000C80, 0x10, 0);
    func_8001CADC(arg0 + sp56, ((arg1 + arg3) - sp56) - 0x10, 0x10, 0x10, D_2000F80, 0x10, 0);
    func_8001CADC(((arg0 + arg2) - sp56) - 0x10, arg1 + sp56, 0x10, 0x10, D_2000D80, 0x10, 0);
    func_8001CADC(((arg0 + arg2) - sp56) - 0x10, ((arg1 + arg3) - sp56) - 0x10, 0x10, 0x10, D_2000E80, 0x10, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    D_84210D58 += 0x2000;
}

void func_8420092C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 temp_a2;
    s16 temp_s0_32;
    s16 var_s2;
    s16 var_s3;

    if (arg2 >= 0x20) {
        var_s3 = 0x10;
    } else {
        var_s3 = arg2 / 2;
    }
    if (arg3 >= 0x20) {
        var_s2 = 0x10;
    } else {
        var_s2 = arg3 / 2;
    }
    temp_a2 = arg2 - (var_s3 * 2);
    temp_s0_32 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20288E0, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028960, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20287E0, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028860, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3,
                  0x4000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    if ((temp_a2 > 0) && (temp_s0_32 > 0)) {
        func_8001C604(arg0 + var_s3, arg1, temp_a2, var_s2, arg4, arg5, arg6, arg7);
        func_8001C604(arg0, arg1 + var_s3, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
        func_8001C604(arg0 + var_s3, arg1 + var_s3 + temp_s0_32, temp_a2, var_s2, arg4, arg5, arg6, arg7);
    } else if (temp_a2 > 0) {
        func_8001C604(arg0 + var_s3, arg1, temp_a2, arg3, arg4, arg5, arg6, arg7);
    } else if (temp_s0_32 > 0) {
        func_8001C604(arg0, arg1 + var_s2, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_8420112C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 temp_a2;
    s16 temp_s0_32;
    s16 var_s2;
    s16 var_s3;

    if (arg2 >= 0x10) {
        var_s3 = 8;
    } else {
        var_s3 = arg2 / 2;
    }
    if (arg3 >= 0x10) {
        var_s2 = 8;
    } else {
        var_s2 = arg3 / 2;
    }
    temp_a2 = arg2 - (var_s3 * 2);
    temp_s0_32 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028A60, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028AA0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20289E0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028A20, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3,
                  0x2000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    if ((temp_a2 > 0) && (temp_s0_32 > 0)) {
        func_8001C604(arg0 + var_s3, arg1, temp_a2, var_s2, arg4, arg5, arg6, arg7);
        func_8001C604(arg0, arg1 + var_s3, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
        func_8001C604(arg0 + var_s3, arg1 + var_s3 + temp_s0_32, temp_a2, var_s2, arg4, arg5, arg6, arg7);
    } else if (temp_a2 > 0) {
        func_8001C604(arg0 + var_s3, arg1, temp_a2, arg3, arg4, arg5, arg6, arg7);
    } else if (temp_s0_32 > 0) {
        func_8001C604(arg0, arg1 + var_s2, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_8420192C(s16 arg0, s16 arg1) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC(arg0, arg1, 0x30, 0x18, D_2006C00, 0x30, 0);
    func_8001C6AC(arg0, arg1 + 0x18, 0x30, 0x18, D_2007500, 0x30, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84201A00(s16 arg0, s16 arg1) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC(arg0, arg1, 0x30, 0x18, &D_2028AE0, 0x30, 0);
    func_8001C6AC(arg0, arg1 + 0x18, 0x30, 0x18, &D_20293E0, 0x30, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84201AD4(s16 arg0, s16 arg1, s16 arg2) {
    static u8* D_84210D5C[] = { D_200DFA0, D_200F3E0, D_2010820, D_2011C60, D_20130A0 };

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC(arg0, arg1, 0x48, 0x12, D_84210D5C[arg2], 0x48, 0);
    func_8001C6AC(arg0, arg1 + 0x12, 0x48, 0x12, D_84210D5C[arg2] + 0xA20, 0x48, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84201BC4(s16 arg0, s16 arg1, s16 arg2, Color_RGBA8* arg3, Color_RGBA8* arg4) {
    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, arg3->r, arg3->g, arg3->b, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, arg4->r, arg4->g, arg4->b, 255);

    func_8001CADC(arg0, arg1, 0x10, 0x20, D_20003C0, 0x10, 0);
    func_8001CADC((arg0 + arg2) - 0x10, arg1, 0x10, 0x20, D_20005C0, 0x10, 0);
    func_8001C330(arg0 + 0x10, arg1, arg2 - 0x20, 0x20, 0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84201D6C(void) {
    static s32 D_84210D70[] = {
        0x3B, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3D, 0x3E,
    };

    Color_RGBA8 sp2C;
    Color_RGBA8 sp28;

    func_8000E820(&sp2C, 0x64, 0x64, 0xC8);
    func_8000E820(&sp28, 0x28, 0x28, 0x8C);
    func_84201BC4(0x48, 0x28, 0x208, &sp2C, &sp28);
    func_8420192C(0x30, 0x20);
    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8001F324(0, 0, 0, 0xFF);
    func_8001F1E8(0x6A, 0x2C, func_84200130(D_84210D70[D_800AE540.unk_0000]));
    func_8001F324(0xFF, 0xFF, 0x77, 0xFF);
    func_8001F1E8(0x68, 0x2A, func_84200130(D_84210D70[D_800AE540.unk_0000]));
    func_8001F444();
}

void func_84201E70(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    if (arg2 == D_8423D3F8) {
        func_8001F324(0xFF, 0xFF, 0, 0xFF);
    } else {
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_8001F1E8(arg0 + 0x36, arg1 + (arg2 * 0x1E) + 0x2C, arg3);
}

void func_84201F04(s16 arg0, s16 arg1, s16 arg2) {
    UNUSED s32 pad[2];
    char* sp30;
    s16 temp_a3;
    s16 temp_v0;

    func_800079C4();
    func_8001D924(D_84211B34);
    func_84201D6C();
    if (arg2 > 0) {
        temp_a3 = (((arg2 * 0x9A) - 0x9A) / 8) + 0x10;
        func_80020754(0x6D, (s16)(((0xAA - temp_a3) / 2) + 0x81), 0x1A6, temp_a3);
        temp_v0 = (((arg2 * 0x5C) - 0x5C) / 8) + 0x10;
        if (1) {}
        func_8420112C(0x38, ((0x6C - temp_v0) / 2) + 0x14C, 0x210, (((arg2 * 0x5C) - 0x5C) / 8) + 0x10, 0x1E, 0x1E,
                      0x82, 0x96);
        if (arg2 == 9) {
            func_84200420(0x74, 0x88, 0x198, 0x20, 0x8C, 0x28, 0x8C, 0xFF);
            func_84200420(0x74, 0xA8, 0x198, 0x7C, 0x64, 0x1E, 0x64, 0xFF);
            func_80020928(0x79, (D_8423D3F8 * 0x1E) + 0xAD);
            func_8001F3F4();
            func_8001EBE0(0x10, 0);
            func_8001F1E8(0x7D, 0x8B, "%s %s", func_84200130(D_800AE540.unk_0001 + 0x3F), func_84200130(0x48));
            func_84201E70(0x6D, 0x81, 0, func_84200130(0x49));
            func_84201E70(0x6D, 0x81, 1, func_84200130(0x4A));
            func_84201E70(0x6D, 0x81, 2, func_84200130(0x4B));
            func_84201E70(0x6D, 0x81, 3, func_84200130(0x4C));
            func_8001EBE0(8, 0);
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F3B4(0x18);
            func_8001F1E8(0x58, 0x154, func_8002D7C0(NULL, 0, D_84211B48, 0x4D));
            func_8001F444();
        }
    }
    func_8420D4F8(0);
    func_80007778();
}

void func_84202208(void) {
    func_80048B90(8);
    func_8420DA28(0x10, gPlayer1Controller);

    while (func_8420DB48(0x10) == -1) {
        func_8420D9B0();
        func_84201F04(0x8C, 0xBC, 9);
        func_800290B4();
    }
}

s32 func_84202284(void) {
    s32 sp1C = 'exec';

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        if ((D_8423D3F8 == 0) && (func_80028E68() == 0xA)) {
            func_84202208();
        } else {
            if (D_8423D3F8 < 3) {
                func_80048B90(0x1C);
            } else {
                func_80048B90(3);
            }
            sp1C = 'btnA';
        }
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        func_80048B90(3);
        D_8423D3F8 = 3;
        sp1C = 'btnB';
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        func_80048B90(1);
        D_8423D3F8--;
        if (D_8423D3F8 < 0) {
            D_8423D3F8 = 3;
        }
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
        func_80048B90(1);
        D_8423D3F8++;
        if (D_8423D3F8 >= 4) {
            D_8423D3F8 = 0;
        }
    }
    return sp1C;
}

s16 func_842023E4(void) {
    s16 i;
    s32 temp_s0;

    D_8423D3F8 = 0;
    func_80048B90(4);

    for (i = 0; i < 9; i++) {
        func_800290B4();
        func_84201F04(0x8C, 0xBC, i);
    }

    do {
        func_800290B4();
        temp_s0 = func_84202284();
        func_84201F04(0x8C, 0xBC, 9);
    } while (temp_s0 == 'exec');

    for (i = 8; i >= 0; i--) {
        func_800290B4();
        func_84201F04(0x8C, 0xBC, i);
    }

    func_84201F04(0x8C, 0xBC, 0);
    return func_84200020(D_8423D3F8);
}

void func_842024DC(s16 arg0, s16 arg1) {
    Color_RGBA8 sp34;
    Color_RGBA8 sp30;
    s32 var_t0 = 0;

    if ((D_800AE540.unk_0000 == 0) && (arg1 >= 0)) {
        if (D_84210D48 == 0) {
            var_t0 = 1;
        } else {
            if ((D_84210D48 % 12) >= 5) {
                var_t0 = 1;
            }
            D_84210D48--;
        }
    }

    if (arg0 == 0) {
        func_8000E820(&sp34, 0x64, 0x64, 0xC8);
        func_8000E820(&sp30, 0x28, 0x28, 0x8C);
        func_84201BC4(0x48, 0x28, 0x208, &sp34, &sp30);
        func_8420192C(0x30, 0x20);
        if (var_t0 != 0) {
            func_84201AD4(0x1AE, 0x26, arg1);
        }
    } else {
        func_8000E820(&sp34, 0xB4, 0x5A, 0xA0);
        func_8000E820(&sp30, 0x78, 0x28, 0x64);
        func_84201BC4(0x48, 0x28, 0x208, &sp34, &sp30);
        func_84201A00(0x30, 0x20);
    }

    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8001F324(0, 0, 0, 0xFF);

    func_8001F1E8(0x6A, 0x2C, func_8002D7C0(NULL, 0, D_84211B48, arg0 + 0x37));
    func_8001F324(0xFF, 0xFF, 0x77, 0xFF);
    func_8001F1E8(0x68, 0x2A, func_8002D7C0(NULL, 0, D_84211B48, arg0 + 0x37));

    if ((arg0 == 0) && (var_t0 != 0)) {
        func_8001EBE0(4, 0);
        func_8001F1E8(0x1F9, 0x2F, func_8002D7C0(NULL, 0, D_84211B48, 0x4E));
    }
    func_8001F444();
}

void func_84202718(UNUSED s16 arg0, s16 arg1, s16 arg2) {
    s32 temp_s0 = D_84210D40 > 0;

    func_800079C4();

    if (temp_s0 != 0) {
        D_84210D40--;
        func_8001D924(D_84211B34);
        func_842024DC(arg1, arg2);
    }

    if (D_84210D44 & 8) {
        func_84204760(temp_s0);
    }

    if (D_84210D44 & 1) {
        func_842062D4(&D_84211B50, temp_s0);
    }

    if (D_84210D44 & 2) {
        func_84209340(&D_842168A0, temp_s0);
    }

    if (D_84210D44 & 4) {
        func_8420EE54(&D_84229EB0, temp_s0);
    }

    if (D_84210D44 & 0x10) {
        func_8420B8CC(&D_8423D3A8, temp_s0);
    }

    if (D_84210D44 & 0x20) {
        func_8420D4F8(temp_s0);
    }

    func_80007778();
}

s16 func_84202844(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 temp_s1 = -1;
    s16 i;

    D_84210D48 = 0x27;

    for (i = 0; i < 4; i++) {
        D_84210D40 = 2;
        func_84202718(-1, arg1, arg2);
    }

    func_84205D48(arg0, arg3);

    while (temp_s1 == -1) {
        func_800290B4();
        func_8420570C();
        func_8420D9B0();
        temp_s1 = func_84205E54();
        D_84210D40 = 2;
        func_84202718(-1, arg1, arg2);
    }

    func_84202718(-1, arg1, arg2);
    return temp_s1;
}

void func_84202974(UNUSED s16 arg0, UNUSED s32 arg1) {
    s32 var_a1 = 0;

    if (D_84210D44 & 1) {
        var_a1 = func_8420776C(&D_84211B50);
    }

    if (D_84210D44 & 2) {
        var_a1 |= func_8420B0C8(&D_842168A0);
    }

    if (D_84210D44 & 4) {
        var_a1 |= func_842106FC(&D_84229EB0);
    }

    if (D_84210D44 & 0x10) {
        var_a1 |= func_8420C580(&D_8423D3A8);
    }

    if (D_84210D44 & 0x20) {
        var_a1 |= func_8420D9B0();
    }

    if (var_a1 != 0) {
        D_84210D40 = 2;
    }
}

void func_84202A64(s16 arg0, s32 arg1, s16 arg2) {
    func_80048B90(4);
    if (arg0 == 4) {
        func_84210A18(&D_84229EB0);
    } else {
        func_842079B4(&D_84211B50, 0);
        func_8420B1D0(&D_842168A0, 0);
    }
    func_800290B4();
    func_84202974(arg0, 0);
    func_84202718(arg0, arg1, arg2);
}

void func_84202AF4(s16 arg0, s16 arg1, s16 arg2) {
    s32 var_s0 = 1;

    func_8001F738(&gControllers[D_842168A0.unk_00003]);

    while (var_s0 != 0) {
        func_800290B4();
        func_84202974(arg0, func_8001F750() & 0xFFFF);
        func_84202718(arg0, arg1, arg2);

        if (arg0 == 4) {
            var_s0 = func_84210B54(&D_84229EB0) == 0;
        } else {
            var_s0 = !func_842081A8(&D_84211B50);
            var_s0 |= !func_8420B37C(&D_842168A0);
        }
    }
}

void func_84202C20(void) {
    s16 i;
    unk_D_800AE540_0004* var_v0 = D_800AE540.unk_0004;

    for (i = 0; i < 4; i++) {
        D_8423D3D8[i].unk_00 = 0;
        D_8423D3D8[i].unk_01 = i;
        D_8423D3D8[i].unk_02 = i;
    }

    for (i = 0; i < 4; i++, var_v0++) {
        if (var_v0->unk_000 & 1) {
            if (!(var_v0->unk_000 & 2)) {
                D_8423D3D8[var_v0->unk_001].unk_00 = 1;
                D_8423D3D8[var_v0->unk_001].unk_04 = var_v0;
            } else if (D_800AE540.unk_0000 == 0) {
                D_8423D3D8[var_v0->unk_001].unk_00 = 1;
                D_8423D3D8[var_v0->unk_001].unk_04 = var_v0;
                D_8423D3D8[var_v0->unk_001].unk_01 = 4;
                D_8423D3D8[var_v0->unk_001].unk_02 = 0;
            }
        }
    }
}

void func_84202D18(unk_D_8423D3D8* arg0, s16 arg1) {
    char sp50[16];
    UNUSED s32 pad;
    u16 var_v1;
    unk_D_800AC910_040 sp38;

    if (arg1 == 4) {
        D_84210D44 |= func_8421089C(&D_84229EB0, &D_84211B50, &D_842168A0, &D_8423D3A8, 0, 0x2C, 0x54, arg0->unk_02);
        return;
    }

    if (arg1 < 4) {
        func_80025040(arg1, &sp38);
        func_80021A90(sp50, sp38.unk_02);
        var_v1 = sp38.unk_00;
    } else {
        HAL_Strcpy(sp50, func_8002311C(1));
        var_v1 = 0;
    }

    D_84210D44 |= func_842078C0(&D_84211B50, &D_842168A0, &D_8423D3A8, NULL, 0, var_v1, sp50, 0x40, 0x54, arg0->unk_02);
    D_84210D44 |= func_8420AF1C(&D_842168A0, &D_84211B50, &D_8423D3A8, 0, 0x68, 0xE4, arg0->unk_02, arg1, D_84211B38);
}

s32 func_84202EB0(unk_D_8423D3D8* arg0, s16 arg1) {
    s32 temp_s3;
    s32 var_s0 = 0;
    unk_D_84229EB0_00024* sp34;
    s32 i;

    arg0->unk_04->unk_002 = 0;
    if (arg1 == 4) {
        temp_s3 = func_84210B60(&D_84229EB0, &sp34);
        if (sp34 != NULL) {
            arg0->unk_04->unk_018 = sp34->unk_4D10;
            if (D_800AE540.unk_0000 != 0) {
                HAL_Strcpy(arg0->unk_04->unk_008, sp34->unk_4D12);
            }
            HAL_Strcpy(arg0->unk_04->unk_214->unk_014, sp34->unk_4D12);

            for (i = 0; i < temp_s3; i++) {
                func_8002B888(arg0->unk_04, &sp34->unk_0000[i].unk_004);
            }
            var_s0 = 1;
        }
    } else {
        arg0->unk_04->unk_018 = D_84211B50.unk_001C;
        if (D_800AE540.unk_0000 != 0) {
            HAL_Strcpy(arg0->unk_04->unk_008, D_84211B50.unk_001E);
        }
        HAL_Strcpy(arg0->unk_04->unk_214->unk_014, D_84211B50.unk_001E);

        if (D_84211B50.unk_0006 > 0) {
            for (i = 0; i < D_84211B50.unk_0006; i++) {
                func_8002B888(arg0->unk_04, &D_84211B50.unk_0030[i].unk_004);
            }
            var_s0 = 1;
        }
    }
    return var_s0;
}

void func_8420305C(s32 arg0) {
    s32 i;

    func_80007990(1);
    func_8000D278(0x10);
    func_80006CB4(8);

    for (i = 0; i < 8; i++) {
        func_800290B4();
        func_800079C4();
        func_8001D924(D_84211B34);
        if (arg0 != 0) {
            func_842024DC(0, -1);
        }
        func_80007778();
    }

    func_800077B4(2);
}

void func_84203100(void) {
    s32 i;

    if (func_80007604() == 1) {
        func_80006C6C(8);
        for (i = 0; i < 10; i++) {
            func_800290B4();
            func_800079C4();
            func_8001D924(D_84211B34);
            func_842024DC(0, -1);
            func_80007778();
        }
    }
}

void func_8420318C(s16 arg0, s16 arg1) {
    unk_D_800AE540_0004* temp_v1 = D_8423D3D8[arg0].unk_04;

    if (temp_v1->unk_002 != 0) {
        if (arg1 == 4) {
            func_84210C80(&D_84229EB0, temp_v1->unk_214->unk_028[0].unk_53);
        } else {
            func_842081B4(&D_84211B50, &temp_v1->unk_214->unk_028, temp_v1->unk_214->unk_002);
        }
    }
}

s32 func_84203210(void) {
    s16 var_s1 = 0;
    s16 var_s2;

    if ((D_800AE540.unk_0000 == 7) && (D_800AE540.unk_0002 == 9)) {
        func_8420305C(0);
        func_8002B6BC();
        return 1;
    }

    switch (D_800AE540.unk_0000) {
        case 0:
            func_8000D1F0(0x2D);
            break;

        case 7:
            func_8000D1F0(0x2B);
            break;

        case 8:
            func_8000D1F0(0x30);
            break;

        default:
            func_8000D1F0(0x15);
            break;
    }

    func_84202C20();
    func_84203100();

    D_84210D44 |= func_84205C18(0);
    D_84210D44 |= func_8420C504(&D_8423D3A8);

    while (var_s1 >= 0 && var_s1 < 4) {
        if (D_8423D3D8[var_s1].unk_00 != 0) {
            var_s2 = func_84202844(D_8423D3D8[var_s1].unk_02, 0, D_8423D3D8[var_s1].unk_01, 1);
            D_8423D3D8[var_s1].unk_04->unk_002 = 0;

            if (var_s2 < 0) {
                var_s1 -= 1;
                while (var_s1 >= 0) {
                    if (D_8423D3D8[var_s1].unk_00 != 0) {
                        var_s2 = (D_8423D3D8[var_s1].unk_04->unk_01C[0].unk_52 & 0x70) >> 4;
                        break;
                    }
                    var_s1--;
                }
            }

            if (var_s1 >= 0) {
                s32 idx = var_s1;

                main_pool_push_state('pkgb');

                if (var_s2 < 4) {
                    func_80023D60(var_s2);
                    func_80024208(var_s2);
                    D_800AE540.unk_11F0 = func_80025328(var_s2);
                } else {
                    D_800AE540.unk_11F0 = 0;
                }

                func_84202D18(&D_8423D3D8[(unsigned long)idx], var_s2);
                func_8420318C(var_s1, var_s2);
                func_84202A64(var_s2, 0, D_8423D3D8[var_s1].unk_01);
                func_84202AF4(var_s2, 0, D_8423D3D8[var_s1].unk_01);

                if (func_84202EB0(&D_8423D3D8[(unsigned long)idx], var_s2) != 0) {
                    var_s1++;
                }

                main_pool_pop_state('pkgb');
            }
        } else {
            var_s1++;
        }
    }

    if (var_s1 == -1) {
        return 0;
    }

    func_8420305C(1);
    func_8002B6BC();
    return 1;
}

s32 func_842034E4(void) {
    s16 var_s1 = 0;
    s16 var_s2;

    switch (D_800AE540.unk_0000) {
        case 0:
            func_8000D1F0(0x2D);
            break;

        case 7:
            func_8000D1F0(0x2B);
            break;

        case 8:
            func_8000D1F0(0x30);
            break;

        default:
            func_8000D1F0(0x15);
            break;
    }

    func_84202C20();
    func_84203100();

    D_84210D44 |= func_84205C18(0);
    D_84210D44 |= func_8420C504(&D_8423D3A8);

    while ((var_s1 >= 0) && (var_s1 < 4)) {
        if (D_8423D3D8[var_s1].unk_00 != 0) {
            if (D_8423D3D8[var_s1].unk_04->unk_002 == 0) {
                var_s2 = func_84202844(D_8423D3D8[var_s1].unk_02, 0, D_8423D3D8[var_s1].unk_01, 1);
            } else {
                var_s2 = ((D_8423D3D8[var_s1].unk_04->unk_01C[0].unk_52 & 0x70) >> 4);
            }

            if (var_s2 < 0) {
                var_s1--;

                while (var_s1 >= 0) {
                    if (D_8423D3D8[var_s1].unk_00 != 0) {
                        var_s2 = (D_8423D3D8[var_s1].unk_04->unk_01C[0].unk_52 & 0x70) >> 4;
                        break;
                    }
                    var_s1--;
                }
            }

            if (var_s1 >= 0) {
                s32 idx = var_s1;

                main_pool_push_state('pkgb');

                if (var_s2 < 4) {
                    func_80023D60(var_s2);
                    func_80024208(var_s2);
                    D_800AE540.unk_11F0 = func_80025328(var_s2);
                } else {
                    D_800AE540.unk_11F0 = 0;
                }
                func_84202D18(&D_8423D3D8[(unsigned long)idx], var_s2);
                func_8420318C(var_s1, var_s2);
                func_84202A64(var_s2, 0, D_8423D3D8[var_s1].unk_01);
                func_84202AF4(var_s2, 0, D_8423D3D8[var_s1].unk_01);
                if (func_84202EB0(&D_8423D3D8[(unsigned long)idx], var_s2) != 0) {
                    var_s1++;
                }

                main_pool_pop_state('pkgb');
            }
        } else {
            var_s1++;
        }
    }

    if (var_s1 == -1) {
        return 0;
    }

    func_8420305C(1);
    func_8002B6BC();
    return 1;
}

void func_842037AC(void) {
    unk_D_84229EB0* ptr;
    char sp74[16];
    s16 temp_v0;
    u16 var_s1;
    unk_D_800AC910_040 sp60;

    while (true) {
        temp_v0 = func_84202844(0, 1, 0, 1);
        if (temp_v0 < 0) {
            return;
        }

        main_pool_push_state('regi');

        if (temp_v0 < 4) {
            func_80023D60(temp_v0);
            func_80024208(temp_v0);
            func_80025040(temp_v0, &sp60);
            func_80021A90(sp74, sp60.unk_02);
            var_s1 = sp60.unk_00;
        } else {
            HAL_Strcpy(sp74, func_8002311C(1));
            var_s1 = 0;
        }

        ptr = &D_84229EB0;
        D_84210D44 |= func_8421089C(ptr, &D_84211B50, &D_842168A0, &D_8423D3A8, 3, 0x2C, 0xBC, 0);
        D_84210D44 |= func_842078C0(&D_84211B50, &D_842168A0, &D_8423D3A8, ptr, 1, var_s1, sp74, 0x40, 0x54, 0);
        D_84210D44 |= func_8420AF1C(&D_842168A0, &D_84211B50, &D_8423D3A8, 1, 0x68, 0xE4, 0, temp_v0, D_84211B38);

        func_84202A64(temp_v0, 1, 0);
        func_84202AF4(temp_v0, 1, 0);

        main_pool_pop_state('regi');

        if (D_84211B50.unk_0006 != 0) {
            break;
        }
    }
}

void func_842039B4(void) {
    D_84210D44 |= func_8421089C(&D_84229EB0, &D_84211B50, &D_842168A0, &D_8423D3A8, 1, 0x2C, 0x54, 0);

    func_84210A18(&D_84229EB0);
    func_800290B4();
    func_84202974(4, 0);
    func_84202718(4, 2, 0);
    func_8001F738(&gControllers[D_842168A0.unk_00003]);

    do {
        func_800290B4();
        func_84202974(4, func_8001F750() & 0xFFFF);
        func_84202718(4, 2, 0);
    } while (func_84210B54(&D_84229EB0) == 0);
}

void func_84203AB8(void) {
    D_84210D44 |= func_8421089C(&D_84229EB0, &D_84211B50, &D_842168A0, &D_8423D3A8, 2, 0x2C, 0x54, 0);

    func_84210A18(&D_84229EB0);
    func_800290B4();
    func_84202974(4, 0);
    func_84202718(4, 3, 0);
    func_8001F738(&gControllers[D_842168A0.unk_00003]);

    do {
        func_800290B4();
        func_84202974(4, func_8001F750() & 0xFFFF);
        func_84202718(4, 3, 0);
    } while (func_84210B54(&D_84229EB0) == 0);
}

s32 func_84203BBC(void) {
    s16 temp_v0;

    D_84210D44 |= func_84205C18(1);
    D_84210D44 |= func_8420C504(&D_8423D3A8);

    do {
        temp_v0 = func_842023E4();
        switch (temp_v0) {
            case 0:
                func_842037AC();
                break;

            case 1:
                func_842039B4();
                break;

            case 2:
                func_84203AB8();
                break;
        }
    } while (temp_v0 != 3);

    return 1;
}

void func_84203C90(void) {
    BinArchive* temp_a0;
    s16 var_a1;

    temp_a0 = func_800044F4(0x898000, NULL, 1, 0);

    switch (D_800AE540.unk_0001) {
        case 0:
            var_a1 = 0x1A;
            break;

        case 1:
            var_a1 = 0x1A;
            break;

        case 2:
            var_a1 = 0x1B;
            break;

        case 3:
            var_a1 = 0x1C;
            break;

        case 4:
            var_a1 = 0x17;
            break;

        case 5:
            var_a1 = 0x18;
            break;

        case 6:
            var_a1 = 0x19;
            break;

        case 7:
            var_a1 = 0x1E;
            break;

        case 8:
            var_a1 = 0x19;
            break;

        default:
            var_a1 = 0;
            break;
    }

    if (var_a1 == 0) {
        D_84211B38 = NULL;
    } else {
        if (D_800AE540.unk_11F2 != 0) {
            var_a1 += 0x1F;
        }
        D_84211B38 = func_8000484C(temp_a0, var_a1);
    }
}

void func_84203D74(void) {
    unk_func_80027FA0 sp20;

    D_84211B30 = ASSET_LOAD2(backgrounds, 1, 1);
    if (D_800AE540.unk_0000 == 7) {
        if (D_800AE540.unk_0002 >= 8) {
            D_84211B34 = func_8000484C(D_84211B30, 0xE);
        } else {
            func_80028AFC(2);
            func_80027FA0(&sp20, D_800AE540.unk_11F2);
            if (sp20.unk_04 < 8) {
                D_84211B34 = func_8000484C(D_84211B30, 0xD);
            } else {
                D_84211B34 = func_8000484C(D_84211B30, 0x10);
            }
        }
    } else {
        D_84211B34 = func_8000484C(D_84211B30, D_84210D4C[D_800AE540.unk_0000]);
    }
}

s32 func_84203E6C(s32 arg0, UNUSED s32 arg1) {
    s32 var_v1;

    main_pool_push_state('PICK');

    func_8001E94C(0x1C, 0);
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);
    FRAGMENT_LOAD(fragment31);
    func_8001987C();
    func_8002D510();

    D_84211B3C = func_8002D5AC(0x24);
    D_84211B40 = func_8002D5AC(0x25);
    D_84211B44 = func_8002D5AC(0x26);
    D_84211B48 = func_8002D5AC(0x1A);
    D_84211B4C = func_8002D5AC(6);

    func_80028AFC(D_800AE540.unk_0001 / 4);
    func_80028C48(D_800AE540.unk_0001);
    func_80028EB8();
    func_84203D74();
    func_8001B058();
    func_84203C90();
    func_80007754();

    if (arg0 == 1) {
        var_v1 = func_84203BBC();
    } else if (D_800AE540.unk_11F6 & 0x20) {
        var_v1 = func_842034E4();
        D_800AE540.unk_11F6 = D_800AE540.unk_11F6 & 0xFFDF;
    } else {
        D_800AE540.unk_11F5 &= 0xFFFD;
        var_v1 = func_84203210();
    }

    func_8000771C();

    main_pool_pop_state('PICK');

    return var_v1;
}
