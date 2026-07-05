#include "48C60.h"
#include "38BB0.h"
#include "373A0.h"

extern s32 D_80078A18;
extern u8 D_80078A1C;

#ifdef NON_MATCHING
extern u8 D_80078A10;
extern u32 D_80078A14;
extern s8 D_80078A20;
void func_8004ADB0(u32, u32, u32);
void func_80050B40(s32, void*, s32);
void func_8004E810(u32, u32);
// Play a sound event: find (or evict+load) the sound's slot, then dispatch by
// event type to start/stop a voice using the slot's command table.
void func_80048060(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 soundId;
    u8 forced;
    s32 eventType;
    s32 subType;
    u8* search;
    s32 i;
    s32 found;
    s32 evict;
    s32 idx;
    s32 fileOff;
    s32 fileSize;
    s32 waveSize;
    u8** playerSlot;
    u8** cmdSlot;
    s32 mode;
    u8* cmd;
    s32 cmdId;
    u32* player;

    soundId = arg2;
    forced = 0;
    D_80078A20 = 0;
    func_800392A8(D_80078A18, 0xA);
    if (soundId == 0xC8) {
        forced = 1;
    } else if ((soundId == 0) || ((u32) soundId >= 0x98)) {
        return;
    }
    if ((soundId == 0) || ((u32) arg1 >= 0xA6)) {
        return;
    }
    eventType = arg3 & 0xFF;
    subType = (arg3 >> 8) & 0xFF;
    if (((eventType == 0xA) || (eventType == 0xB)) && ((subType == 0x10) || (subType == 0x20))) {
        return;
    }

    search = &D_80078A10;
    i = 0;
    while (soundId != *search) {
        i++;
        search++;
        if (i == 3) {
            evict = D_80078A14 % 3;
            D_80078A14++;
            (&D_80078A10)[evict] = (u8) soundId;
            if (forced) {
                soundId = 0x97;
            }
            idx = soundId - 1;
            if ((u32) idx < (u32) (D_800FC6FC->num_files - 1)) {
                fileOff = D_800FC6FC->files[idx];
                fileSize = D_800FC6FC->files[idx + 1] - fileOff;
            } else {
                fileOff = D_800FC6FC->files[idx];
                fileSize = *(s32*) ((u8*) D_800FC6E8 + 0x1C) - fileOff;
            }
            func_8004ADB0(fileOff, (u32) D_800FC6DC, fileSize);
            func_80050B40((s32) D_800FC6DC, D_800FC6B0[evict], 0x3E8);
            func_800397BC((unk_func_800397BC*) D_800FC6B0[evict]);
            if (forced) {
                idx = 0x97;
            }
            waveSize = D_800FC700->seqArray[idx].len;
            if (waveSize & 1) {
                waveSize++;
            }
            func_8004ADB0((u32) D_800FC700->seqArray[idx].offset, (u32) D_800FC6DC, waveSize);
            func_80050B40((s32) D_800FC6DC, D_800FC6C0[evict], 0x44C);
            found = evict;
            goto dispatch;
        }
    }
    found = i;

dispatch:
    switch (eventType) {
    case 0:
    case 2:
    case 3:
        mode = 0;
        playerSlot = &D_800FC6B0[found];
        cmdSlot = &D_800FC6C0[found];
    block_35:
        if (eventType == 0xB) {
            arg1 = 0;
        }
        cmd = *cmdSlot + 0x10 + (arg1 * 6) + mode;
        cmdId = cmd[0];
        D_80078A1C = cmd[1];
    block_38:
        player = (u32*) *playerSlot;
        if ((forced == 0) && ((u32) cmdId >= *player)) {
            return;
        }
        if (forced != 0) {
            if ((arg1 == 0x2D) || (arg1 == 0x2E)) {
                D_80078A20 = 1;
            }
            if (cmdId != 0) {
                func_8004E810(cmdId, 0xA);
            }
            return;
        }
        D_80078A18 = func_80039024((SoundBank*) D_800FC6AC, (s32) player, cmdId, 0x80, 0x80, -1);
        return;
    case 4:
        mode = 2;
        playerSlot = &D_800FC6B0[found];
        cmdSlot = &D_800FC6C0[found];
        goto block_35;
    case 1:
        mode = 4;
        playerSlot = &D_800FC6B0[found];
        cmdSlot = &D_800FC6C0[found];
        goto block_35;
    case 11:
        mode = 0;
        playerSlot = &D_800FC6B0[found];
        cmdSlot = &D_800FC6C0[found];
        goto block_35;
    case 16:
        cmdId = arg1;
        playerSlot = &D_800FC6B0[found];
        goto block_38;
    default:
        return;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/48C60/func_80048060.s")
#endif

void func_80048464(void) {
  if (D_80078A1C != 0) {
      func_800392A8(D_80078A18, (s32)D_80078A1C);
  }
}
