#include <ultra64.h>
#include "hal_libc.h"
#include "controller.h"

extern s32 func_8000DAFC(void*, s32, u16, s32, s32);

// gb_tower.c
// dont forget to pass -signed when compiling

extern OSPfs D_800A8100[];
extern u8 D_800A82A0[];
extern u8 D_800A82AC[];

extern u8 D_800A82A4;
extern u8 D_800A82A5;
extern u8 D_800A82A6;
extern u8 D_800A82A7;
extern s32 D_800A82A8;

// these first 4 funcs might be part of a hal_libc file or something instead of GB Tower.

s32 func_8000AEBC(s32 arg0, s32 arg1, u16 arg2, u16 arg3);
s32 func_8000AF40(s32 arg0, void* arg1, u16 arg2, u16 arg3);

// TODO: These 0x20 sizes probably belong to a struct size or something. Use
// that instead of assuming sizeof is the same
s32 func_8000A630(s32 arg0, void* arg1) {
    u8 sp47;
    u8 sp24[0x20];
    s32 sp20 = 0;
    UNUSED u8 padding[8];

    if ((func_8000AF40(arg0, arg1, 0, 0x20) == 0) && (func_8000AEBC(arg0, (uintptr_t)&sp24, 0, 0x20) == 0) &&
        (bcmp(&sp24, arg1, 0x20) == 0) && (osGbpakGetStatus(&D_800A8100[arg0], &sp47) == 0)) {
        sp20 = ((sp47 & 4) != 0) == 0;
    }
    return sp20;
}

s32 func_8000A6D8(s32 arg0, u8* arg1) {
    s32 var_s0 = 0;
    u8 sp34[0x20];

    if (arg1 == NULL) {
        arg1 = sp34;
    }
    HAL_Memset((char*)arg1, 0x55, 0x20);
    if (func_8000A630(arg0, arg1) != 0) {
        HAL_Memset((char*)arg1, 0xAA, 0x20);
        if (func_8000A630(arg0, arg1) != 0) {
            s32 i;
            for (i = 0; i < ARRAY_COUNT(sp34); i++) {
                arg1[i] = osGetCount();
            }
            var_s0 = func_8000A630(arg0, arg1);
        }
    }
    return var_s0;
}

s32 func_8000A798(s32 arg0, u8* arg1, u8* arg2) {
    u8 status;
    OSGbpakId gbpakId;
    s32 sp28 = 0;

    if (arg1 != NULL) {
        *arg1 = D_800A82A0[arg0];
    }

    if (D_800A82A0[arg0] == 1) {
        return 1;
    }

    if (osGbpakReadId(&D_800A8100[arg0], &gbpakId, &status) != 0) {
        func_8002B274(arg0, 1);
    }
    if ((status & OS_GBPAK_RSTB_STATUS) && (osGbpakCheckConnector(&D_800A8100[arg0], &status) == 0)) {
        func_8000D970(&D_800A8100[arg0]);
        sp28 = func_8000A6D8(arg0, arg2);
    }
    D_800A82A0[arg0] = 1;
    return sp28;
}

s32 func_8000A888(s32 arg0, u8 arg1) {
    u8 status;
    s32 temp_v1;

    if (osGbpakGetStatus(&D_800A8100[arg0], &status) != 0) {
        func_8002B274(arg0, 1);
    }

    temp_v1 = !((status & OS_GBPAK_RSTB_DETECTION) != 0);
    if (arg1 == 0) {
        osGbpakPower(&D_800A8100[arg0], 0);
        D_800A82A0[arg0] = 0;
    }
    return temp_v1;
}

void func_8000A924(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_800A82A4 & (1 << i)) {
            osGbpakPower(&D_800A8100[i], 0);
            D_800A82A0[i] = 0;
        }
    }
}

s32 func_8000A9D0(OSGbpakId* header) {
    // make sure its 0 terminated. dont want those dirty hackers abusing a Strcmp exploit
    header->game_title[15] = '\0';

    // is the cartridge non-Japanese?
    if (header->country_code == 1) {
        // Which supported POKeMON version is this?
        if (HAL_Strcmp((char*)header->game_title, "POKEMON RED") == 0) {
            return 1;
        }
        if (HAL_Strcmp((char*)header->game_title, "POKEMON GREEN") == 0) {
            return 1;
        }
        if (HAL_Strcmp((char*)header->game_title, "POKEMON BLUE") == 0) {
            return 1;
        }
        if (HAL_Strcmp((char*)header->game_title, "POKEMON YELLOW") == 0) {
            return 1;
        }
    }
    // This is not a supported cartridge.
    return 0;
}

s32 func_8000AA7C(void) {
    s32 i;
    s32 temp_v0;
    u8 status;
    OSGbpakId sp4C;

    D_800A82A5 = 0;
    D_800A82A4 = 0;
    D_800A82A7 = 0;
    D_800A82A8 = 0;
    osPfsIsPlug(&gSIEventMesgQueue, &D_800A82A6);

    for (i = 0; i < 4; i++) {
        if ((D_800A82A6 & (1 << i)) && ((i != 3) || (func_8000B4C4() == 0))) {
            if (osGbpakInit(&gSIEventMesgQueue, &D_800A8100[i], i) == 0) {
                D_800A82A4 |= (1 << i);
                temp_v0 = osGbpakReadId(&D_800A8100[i], &sp4C, &status);
                if (temp_v0 == 0) {
                    if (!(status & 8)) {
                        func_8002B274(i, 2);
                    }
                    if (func_8000A9D0(&sp4C) != 0) {
                        if (temp_v0 == 4) {
                            // what. the redundant temp_v0 functionless check is apparently needed to match.
                        }
                        if (osGbpakCheckConnector(&D_800A8100[i], &status) == 0) {
                            func_8000D970(&D_800A8100[i]);
                            D_800A82A0[i] = 1;
                            D_800A82A5 |= (1 << i);
                        } else {
                            func_8002B274(i, 2);
                        }
                    } else {
                        D_800A82A5 |= (1 << i);
                        D_800A82A0[i] = 1;
                    }
                } else {
                    D_800A82A0[i] = 0;
                    if (temp_v0 == 4) {
                        func_8002B274(i, 2);
                    }
                }
            }
        }
    }
    return (D_800A82A5 << 0x10) | D_800A82A4;
}

s32 func_8000AC7C(s32 arg0) {
    u8 status;
    s32 ret = osGbpakGetStatus(&D_800A8100[arg0], &status);
    UNUSED u8 filler;

    // check the error code returned (if applicable) by the osGbpakGetStatus
    // call.
    if ((ret == PFS_ERR_NOPACK) || (ret == PFS_ERR_DEVICE) || (ret == PFS_ERR_CONTRFAIL)) {
        func_8002B274(arg0, 1);
    }
    return !((status & OS_GBPAK_GBCART_ON) != 0);
}

s32 func_8000ACF4(s32 arg0) {
    u8 status;
    s32 ret = osGbpakGetStatus(&D_800A8100[arg0], &status);

    if ((ret == PFS_ERR_NOPACK) || (ret == PFS_ERR_DEVICE) || (ret == PFS_ERR_CONTRFAIL)) {
        func_8002B274(arg0, 1);
    }
    return ((status & OS_GBPAK_GBCART_ON) != 0);
}

s32 func_8000AD68(s32 arg0) {
    UNUSED u8 filler[4];
    u8 status;
    OSGbpakId sp28;

    D_800A82A0[arg0] = 0;
    if ((osGbpakInit(&gSIEventMesgQueue, &D_800A8100[arg0], arg0) == 0) &&
        (osGbpakReadId(&D_800A8100[arg0], &sp28, &status) == 0) && (status & OS_GBPAK_RSTB_STATUS) &&
        (osGbpakCheckConnector(&D_800A8100[arg0], &status) == 0)) {

        func_8000D970(&D_800A8100[arg0]);
        D_800A82A0[arg0] = 1;
    }

    return D_800A82A0[arg0] == 1;
}

s32 func_8000AE28(s32 arg0, void* arg1) {
    u8 status;
    u8 sp1C[0x20];
    s32 sp18;

    sp18 = 0;
    if ((func_8000AEBC(arg0, (uintptr_t)&sp1C, 0, 0x20) == 0) && (bcmp(&sp1C, arg1, 0x20) == 0) &&
        (osGbpakGetStatus(&D_800A8100[arg0], &status) == 0) && !(status & OS_GBPAK_RSTB_DETECTION)) {
        sp18 = 1;
    }
    return sp18;
}

s32 func_8000AEBC(s32 arg0, s32 arg1, u16 arg2, u16 arg3) {
    s32 var_v1;

    var_v1 = 1;
    if (D_800A82A5 & (1 << arg0)) {
        var_v1 = func_8000DAFC(&D_800A8100[arg0], 0, arg2, arg1, arg3);
    }
    return var_v1;
}

s32 func_8000AF40(s32 arg0, void* arg1, u16 arg2, u16 arg3) {
    s32 var_v1;

    var_v1 = 1;
    if (D_800A82A5 & (1 << arg0)) {
        var_v1 = func_8000DAFC(&D_800A8100[arg0], 1, arg2, (uintptr_t)arg1, arg3);
    }
    return var_v1;
}

s32 func_8000AFC4(s32 arg0, u8* arg1, u16 arg2, u16 arg3) {
    s32 var_v1;

    var_v1 = 1;
    if (D_800A82A5 & (1 << arg0)) {
        var_v1 = osGbpakReadWrite(&D_800A8100[arg0], 0, arg2, arg1, arg3);
    }
    return var_v1;
}

s32 func_8000B048(s32 arg0, u8* arg1, u16 arg2, u16 arg3) {
    s32 var_v1;

    var_v1 = 1;
    if (D_800A82A5 & (1 << arg0)) {
        var_v1 = osGbpakReadWrite(&D_800A8100[arg0], 1, arg2, arg1, arg3);
    }
    return var_v1;
}

int func_8000B0CC(s32 arg0, s32 arg1) {
    u8 sp28[0x20];
    int i;
    int ret;

    for (i = 0; i < 0x20; i++) {
        sp28[i] = 0;
    }
    ret = func_8000B048(arg0, sp28, 0x5000U, 0x20U);
    if (ret) {
        return ret;
    }
    for (i = 0; i < 0x20; i++) {
        sp28[i] = (arg1 / 32);
    }
    ret = func_8000B048(arg0, sp28, 0x4000U, 0x20U);
    if (ret) {
        return ret;
    }
    for (i = 0; i < 0x20; i++) {
        sp28[i] = (arg1 % 32);
    }
    return func_8000B048(arg0, sp28, 0x2000U, 0x20U);
}

s32 func_8000B1C4(s32 arg0, u8* arg1, s32 arg2, s32 arg3) {
    s32 ret = 1;
    u32 temp_s1 = (arg2 & ~0x1F);
    u32 temp_s4 = ((arg2 + arg3) + 0x1F) & ~0x1F;

    s32 temp_s1_2;
    s32 temp_v0_4;
    u32 temp_v0_5;
    u32 var_v1_2;

    if (temp_s1 < 0x4000U) {
        if (temp_s4 < 0x4001U) {
            var_v1_2 = temp_s4;
        } else {
            var_v1_2 = 0x4000;
        }
        temp_v0_4 = var_v1_2 - temp_s1;
        ret = func_8000AFC4(arg0, arg1, temp_s1, temp_v0_4);
        if (ret != 0) {
            return ret;
        }
        temp_s1 += temp_v0_4;
        arg1 = &arg1[temp_v0_4];
    }
    while (temp_s1 < temp_s4) {
        temp_v0_5 = (temp_s1 & ~0x3FFF) + 0x4000;
        if (temp_v0_5 >= temp_s4) {
            var_v1_2 = temp_s4;
        } else {
            var_v1_2 = temp_v0_5;
        }
        temp_s1_2 = var_v1_2 - temp_s1;
        ret = func_8000B0CC(arg0, temp_s1 >> 0xE);
        if (ret != 0) {
            return ret;
        }
        ret = func_8000AFC4(arg0, arg1, ((temp_s1 & 0x3FFF) + 0x4000) & 0xFFFF, temp_s1_2);
        if (ret != 0) {
            return ret;
        }
        temp_s1 += temp_s1_2;
        arg1 = &arg1[temp_s1_2];
    }
    return ret;
}

u8 func_8000B318(u8 arg0) {
    u8 temp_v0 = D_800A82A7;

    D_800A82A7 = arg0;
    return temp_v0;
}

void func_8000B330(void) {
    u8 sp1F;
    static s32 D_800697D0 = 0; // .data

    if (D_800A82A8 == 0) {
        if (D_800A82A7 & (1 << D_800697D0)) {
            if (osGbpakGetStatus(&D_800A8100[D_800697D0], &sp1F) == 0) {
                D_800A82AC[D_800697D0] = 0;
            } else {
                D_800A82AC[D_800697D0]++;
                if (D_800A82AC[D_800697D0] == 3) {
                    D_800A82A8 = 1;
                    func_8002B274(D_800697D0, 1);
                }
            }
        }
        D_800697D0 = (D_800697D0 + 1) & 3;
    }
}
