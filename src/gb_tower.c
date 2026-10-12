#include "gb_tower.h"
#include "hal_libc.h"
#include "controller.h"
#include "game_state.h"
#include "gb_mbc.h"

// gb_tower.c
// dont forget to pass -signed when compiling

OSPfs D_800A8100[4];
u8 D_800A82A0[4];
u8 D_800A82A4;
u8 D_800A82A5;
u8 D_800A82A6;
u8 D_800A82A7;
s32 D_800A82A8;
u8 D_800A82AC[4];

// these first 4 funcs might be part of a hal_libc file or something instead of GB Tower.

s32 GbPak_MbcRead(s32 arg0, void* arg1, u16 arg2, u16 arg3);
s32 GbPak_MbcWrite(s32 arg0, void* arg1, u16 arg2, u16 arg3);

// TODO: These 0x20 sizes probably belong to a struct size or something. Use
// that instead of assuming sizeof is the same
s32 GbPak_VerifyPattern(s32 arg0, void* arg1) {
    u8 sp47;
    u8 sp24[0x20];
    s32 sp20 = 0;
    UNUSED u8 padding[8];

    if ((GbPak_MbcWrite(arg0, arg1, 0, 0x20) == 0) && (GbPak_MbcRead(arg0, (uintptr_t)&sp24, 0, 0x20) == 0) &&
        (bcmp(&sp24, arg1, 0x20) == 0) && (osGbpakGetStatus(&D_800A8100[arg0], &sp47) == 0)) {
        sp20 = ((sp47 & 4) != 0) == 0;
    }
    return sp20;
}

s32 GbPak_DetectRam(s32 arg0, u8* arg1) {
    s32 var_s0 = 0;
    u8 sp34[0x20];

    if (arg1 == NULL) {
        arg1 = sp34;
    }
    HAL_Memset((char*)arg1, 0x55, 0x20);
    if (GbPak_VerifyPattern(arg0, arg1) != 0) {
        HAL_Memset((char*)arg1, 0xAA, 0x20);
        if (GbPak_VerifyPattern(arg0, arg1) != 0) {
            s32 i;
            for (i = 0; i < ARRAY_COUNT(sp34); i++) {
                arg1[i] = osGetCount();
            }
            var_s0 = GbPak_VerifyPattern(arg0, arg1);
        }
    }
    return var_s0;
}

s32 GbTower_ProbePak(s32 arg0, u8* arg1, u8* arg2) {
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
        Game_ShutdownAndLoadFragment(arg0, 1);
    }
    if ((status & OS_GBPAK_RSTB_STATUS) && (osGbpakCheckConnector(&D_800A8100[arg0], &status) == 0)) {
        osGbmbcRamEnable(&D_800A8100[arg0]);
        sp28 = GbPak_DetectRam(arg0, arg2);
    }
    D_800A82A0[arg0] = 1;
    return sp28;
}

s32 GbTower_CheckPakRemoved(s32 arg0, u8 arg1) {
    u8 status;
    s32 temp_v1;

    if (osGbpakGetStatus(&D_800A8100[arg0], &status) != 0) {
        Game_ShutdownAndLoadFragment(arg0, 1);
    }

    temp_v1 = !((status & OS_GBPAK_RSTB_DETECTION) != 0);
    if (arg1 == 0) {
        osGbpakPower(&D_800A8100[arg0], 0);
        D_800A82A0[arg0] = 0;
    }
    return temp_v1;
}

void GbTower_PowerOffAllPaks(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_800A82A4 & (1 << i)) {
            osGbpakPower(&D_800A8100[i], 0);
            D_800A82A0[i] = 0;
        }
    }
}

#if defined(VERSION_US_REV2)
#pragma GLOBAL_ASM("asm/us/nonmatchings/gb_tower/GbPak_IsPokemonCartridge.s")
#else
s32 GbPak_IsPokemonCartridge(OSGbpakId* header) {
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
#endif

s32 GbTower_ScanPaks(void) {
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
        if ((D_800A82A6 & (1 << i)) && ((i != 3) || (Controller_CheckAccessoryEeprom() == 0))) {
            if (osGbpakInit(&gSIEventMesgQueue, &D_800A8100[i], i) == 0) {
                D_800A82A4 |= (1 << i);
                temp_v0 = osGbpakReadId(&D_800A8100[i], &sp4C, &status);
                if (temp_v0 == 0) {
                    if (!(status & 8)) {
                        Game_ShutdownAndLoadFragment(i, 2);
                    }
                    if (GbPak_IsPokemonCartridge(&sp4C) != 0) {
                        if (temp_v0 == 4) {
                            // what. the redundant temp_v0 functionless check is apparently needed to match.
                        }
                        if (osGbpakCheckConnector(&D_800A8100[i], &status) == 0) {
                            osGbmbcRamEnable(&D_800A8100[i]);
                            D_800A82A0[i] = 1;
                            D_800A82A5 |= (1 << i);
                        } else {
                            Game_ShutdownAndLoadFragment(i, 2);
                        }
                    } else {
                        D_800A82A5 |= (1 << i);
                        D_800A82A0[i] = 1;
                    }
                } else {
                    D_800A82A0[i] = 0;
                    if (temp_v0 == 4) {
                        Game_ShutdownAndLoadFragment(i, 2);
                    }
                }
            }
        }
    }
    return (D_800A82A5 << 0x10) | D_800A82A4;
}

s32 GbPak_IsCartOff(s32 arg0) {
    u8 status;
    s32 ret = osGbpakGetStatus(&D_800A8100[arg0], &status);
    UNUSED u8 filler;

    // check the error code returned (if applicable) by the osGbpakGetStatus
    // call.
    if ((ret == PFS_ERR_NOPACK) || (ret == PFS_ERR_DEVICE) || (ret == PFS_ERR_CONTRFAIL)) {
        Game_ShutdownAndLoadFragment(arg0, 1);
    }
    return !((status & OS_GBPAK_GBCART_ON) != 0);
}

s32 GbPak_IsCartOn(s32 arg0) {
    u8 status;
    s32 ret = osGbpakGetStatus(&D_800A8100[arg0], &status);

    if ((ret == PFS_ERR_NOPACK) || (ret == PFS_ERR_DEVICE) || (ret == PFS_ERR_CONTRFAIL)) {
        Game_ShutdownAndLoadFragment(arg0, 1);
    }
    return ((status & OS_GBPAK_GBCART_ON) != 0);
}

s32 GbTower_ReinitPak(s32 arg0) {
    UNUSED u8 filler[4];
    u8 status;
    OSGbpakId sp28;

    D_800A82A0[arg0] = 0;
    if ((osGbpakInit(&gSIEventMesgQueue, &D_800A8100[arg0], arg0) == 0) &&
        (osGbpakReadId(&D_800A8100[arg0], &sp28, &status) == 0) && (status & OS_GBPAK_RSTB_STATUS) &&
        (osGbpakCheckConnector(&D_800A8100[arg0], &status) == 0)) {

        osGbmbcRamEnable(&D_800A8100[arg0]);
        D_800A82A0[arg0] = 1;
    }

    return D_800A82A0[arg0] == 1;
}

s32 GbTower_VerifyPakStillInserted(s32 arg0, void* arg1) {
    u8 status;
    u8 sp1C[0x20];
    s32 sp18;

    sp18 = 0;
    if ((GbPak_MbcRead(arg0, (uintptr_t)&sp1C, 0, 0x20) == 0) && (bcmp(&sp1C, arg1, 0x20) == 0) &&
        (osGbpakGetStatus(&D_800A8100[arg0], &status) == 0) && !(status & OS_GBPAK_RSTB_DETECTION)) {
        sp18 = 1;
    }
    return sp18;
}

s32 GbPak_MbcRead(s32 arg0, void* arg1, u16 arg2, u16 arg3) {
    s32 var_v1;

    var_v1 = 1;
    if (D_800A82A5 & (1 << arg0)) {
        var_v1 = osGbmbcReadWrite(&D_800A8100[arg0], 0, arg2, arg1, arg3);
    }
    return var_v1;
}

s32 GbPak_MbcWrite(s32 arg0, void* arg1, u16 arg2, u16 arg3) {
    s32 var_v1;

    var_v1 = 1;
    if (D_800A82A5 & (1 << arg0)) {
        var_v1 = osGbmbcReadWrite(&D_800A8100[arg0], 1, arg2, (uintptr_t)arg1, arg3);
    }
    return var_v1;
}

s32 GbPak_RawRead(s32 arg0, u8* arg1, u16 arg2, u16 arg3) {
    s32 var_v1;

    var_v1 = 1;
    if (D_800A82A5 & (1 << arg0)) {
        var_v1 = osGbpakReadWrite(&D_800A8100[arg0], 0, arg2, arg1, arg3);
    }
    return var_v1;
}

s32 GbPak_RawWrite(s32 arg0, u8* arg1, u16 arg2, u16 arg3) {
    s32 var_v1;

    var_v1 = 1;
    if (D_800A82A5 & (1 << arg0)) {
        var_v1 = osGbpakReadWrite(&D_800A8100[arg0], 1, arg2, arg1, arg3);
    }
    return var_v1;
}

int GbPak_SelectRomBank(s32 arg0, s32 arg1) {
    u8 sp28[0x20];
    int i;
    int ret;

    for (i = 0; i < 0x20; i++) {
        sp28[i] = 0;
    }
    ret = GbPak_RawWrite(arg0, sp28, 0x5000U, 0x20U);
    if (ret) {
        return ret;
    }
    for (i = 0; i < 0x20; i++) {
        sp28[i] = (arg1 / 32);
    }
    ret = GbPak_RawWrite(arg0, sp28, 0x4000U, 0x20U);
    if (ret) {
        return ret;
    }
    for (i = 0; i < 0x20; i++) {
        sp28[i] = (arg1 % 32);
    }
    return GbPak_RawWrite(arg0, sp28, 0x2000U, 0x20U);
}

s32 GbPak_ReadRom(s32 arg0, u8* arg1, s32 arg2, s32 arg3) {
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
        ret = GbPak_RawRead(arg0, arg1, temp_s1, temp_v0_4);
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
        ret = GbPak_SelectRomBank(arg0, temp_s1 >> 0xE);
        if (ret != 0) {
            return ret;
        }
        ret = GbPak_RawRead(arg0, arg1, ((temp_s1 & 0x3FFF) + 0x4000) & 0xFFFF, temp_s1_2);
        if (ret != 0) {
            return ret;
        }
        temp_s1 += temp_s1_2;
        arg1 = &arg1[temp_s1_2];
    }
    return ret;
}

u8 GbTower_SetPollMask(u8 arg0) {
    u8 temp_v0 = D_800A82A7;

    D_800A82A7 = arg0;
    return temp_v0;
}

void GbTower_PollPakConnection(void) {
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
                    Game_ShutdownAndLoadFragment(D_800697D0, 1);
                }
            }
        }
        D_800697D0 = (D_800697D0 + 1) & 3;
    }
}
