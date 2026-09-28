#include "48C60.h"
#include "373A0.h"
#include "4B940.h"
#include "4F410.h"
#include "51740.h"
#include "libnumus/player.h"

// .data
u8 D_80078A10[3] = { 0xFF, 0xFF, 0xFF };
u32 D_80078A14 = 0;
s32 D_80078A18 = 0;
u8 D_80078A1C[4] = { 0 };
u8 D_80078A20[16] = { 0 };

s32 func_80048060(s32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 i;
    u32 temp_v0;
    u32 slot;
    s32 romAddr;
    s32 size;
    MoveSoundEntry* var_a0;
    u8 var_v1;
    u32* seq;
    u8* entry;
    u8 flag;

    flag = 0;
    D_80078A20[0] = 0;
    MusSetDurationScale(D_80078A18, 0xA);

    if (arg2 == 0xC8) {
        flag = 1;
    } else if ((arg2 == 0) || (arg2 >= 0x98U)) {
        return 0;
    }
    if ((arg2 == 0) || (arg1 >= 0xA6U)) {
        return 0;
    }

    var_v1 = ((arg3 & 0xFF00) >> 8) & 0xFF;
    arg3 &= 0xFF;
    if (((arg3 == 0xA) || (arg3 == 0xB)) && ((var_v1 == 0x10) || (var_v1 == 0x20))) {
        return 0;
    }

    for (i = 0; i < 3; i++) {
        if (arg2 == D_80078A10[i]) {
            slot = i;
            goto found;
        }
    }

    slot = D_80078A14 % 3;
    D_80078A14++;
    D_80078A10[slot] = arg2;
    if (flag) {
        arg2 = 0x97;
    }
    arg2--;
    if (arg2 < (D_800FC6FC->num_files - 1)) {
        romAddr = ((u32*)D_800FC6FC)[arg2 + 3];
        size = ((u32*)D_800FC6FC)[arg2 + 4] - romAddr;
    } else {
        romAddr = ((u32*)D_800FC6FC)[arg2 + 3];
        size = D_800FC6E8->seqArray[3].offset - romAddr;
    }
    func_8004ADB0(romAddr, D_800FC6DC, size);
    func_80050B40(D_800FC6DC, D_800FC6B0[slot], 0x3E8);
    RemapBankPointers(D_800FC6B0[slot]);
    if (flag) {
        arg2 = 0x97;
    }
    size = D_800FC700->seqArray[arg2].len;
    if (size & 1) {
        size++;
    }
    func_8004ADB0((u32)D_800FC700->seqArray[arg2].offset, D_800FC6DC, size);
    func_80050B40(D_800FC6DC, D_800FC6C0[slot], 0x44C);

found:
    switch (arg3) {
    case 0:
    case 2:
    case 3:
        size = 0;
        break;
    case 4:
        size = 2;
        break;
    case 1:
        size = 4;
        break;
    case 11:
        size = 0;
        break;
    case 16:
        arg2 = arg1;
        goto block_38;
    default:
        return 0;
    }
    if (arg3 == 0xB) {
        arg1 = 0;
    }
    var_a0 = D_800FC6C0[slot]->entries;
    entry = &(var_a0 + arg1)->unk0[size];
    arg2 = entry[0];
    D_80078A1C[0] = entry[1];

block_38:
    seq = D_800FC6B0[slot];
    temp_v0 = *seq;
    if (!flag && (arg2 >= temp_v0)) {
        return 0;
    }
    if (flag) {
        if ((arg1 == 0x2D) || (arg1 == 0x2E)) {
            D_80078A20[0] = 1;
        }
        if (arg2 != 0) {
            func_8004E810(arg2, 0xA);
        }
        return 0;
    }
    temp_v0 = MusStartSoundEffect(D_800FC6AC, seq, arg2, 0x80, 0x80, -1);
    D_80078A18 = temp_v0;
    return temp_v0;
}

void func_80048464(void) {
  if (D_80078A1C[0] != 0) {
      MusSetDurationScale(D_80078A18, (s32)D_80078A1C[0]);
  }
}
