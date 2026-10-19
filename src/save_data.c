#include "save_data.h"
#include "src/save_data.h"
#include "src/gb_data.h"
#include "src/jpeg_stream.h"
#include "src/memory.h"

static s16 D_800AE4E0;
static SaveBank D_800AE4E8[4];

void Save_ResetBank(UNUSED MainPoolBlock* arg0, u32 arg1) {
    u32 bank_num = arg1 - 'BNK0';
    SaveBank* temp_v0 = &D_800AE4E8[bank_num];

    if ((arg1 >= 'BNK0') && (arg1 < 'BNK4')) {
        temp_v0->unk_00 &= ~3;
        temp_v0->unk_04.unk1 = NULL;
        temp_v0->unk_08.unk1 = NULL;
    }
}

u16 Save_Checksum(u8* arg0, s32 arg1) {
    u16 var_v1 = 0;

    while (arg1-- > 2) {
        var_v1 += *arg0++;
    }
    return var_v1;
}

s32 Save_RecordIsValid(u8* arg0, s32 arg1) {
    u16* temp_v1 = arg1 + arg0;

    temp_v1 -= 3;

    if (temp_v1[0] != 'PO') {
        return 0;
    }

    if (temp_v1[1] != 'KE') {
        return 0;
    }

    if (temp_v1[2] != Save_Checksum(arg0, arg1)) {
        return 0;
    }

    return 1;
}

void Save_WriteFooter(u8* arg0, s32 arg1, s32 arg2) {
    u16* temp_v1;

    if (arg2 != 0) {
        temp_v1 = arg1 + arg0;

        temp_v1 -= 3;
        *temp_v1++ = 'PO';
        *temp_v1++ = 'KE';
        *temp_v1++ = Save_Checksum(arg0, arg1);
    } else {
        temp_v1 = arg1 + arg0;
        temp_v1 -= 3;

        *temp_v1++ = 'XX';
        *temp_v1++ = 'XX';
        *temp_v1++ = Save_Checksum(arg0, arg1) ^ 0xFF;
    }
}

void Save_WriteRecord(u8* arg0, u8* arg1, s32 arg2, s32 arg3) {
    _bcopy(arg0, arg1, arg2);
    D_800AE4E8[arg3].unk_00 |= 2;
}

void Save_CommitRecord(u8* arg0, s32 arg1, s32 arg2) {
    if (*arg0 & 2) {
        *arg0 &= ~2;
        Save_WriteFooter(arg0, arg1, 1);
        D_800AE4E8[arg2].unk_00 |= 2;
    }
}

void Save_InvalidateRecord(u8* arg0, s32 arg1, s32 arg2) {
    if (*arg0 & 2) {
        Save_WriteFooter(arg0, arg1, 0);
        D_800AE4E8[arg2].unk_00 |= 2;
    }
}

void Save_RestoreRecord(u8* arg0, s32 arg1, s32 arg2) {
    u32 tmp = arg0 - (u8*)D_800AE4E8[arg2].unk_04.unk1;

    _bcopy(tmp + (u8*)D_800AE4E8[arg2].unk_08.unk1, arg0, arg1);
}

void Save_ClearRecord(u8* arg0, s32 arg1, s32 arg2) {
    bzero(arg0, arg1);
    *arg0 |= 2;
    D_800AE4E8[arg2].unk_00 |= 2;
}

void Save_LoadWithRepair(s32 arg0, s32 arg1) {
    s32 sp34;
    s32 sp30;
    UNUSED s32 pad;
    s32 idx2;
    u8* sp24;
    u8* sp20;

    switch (arg0) {
        case 16:
            sp30 = D_800AE4E0 / 4;
            idx2 = D_800AE4E0 % 4;
            sp34 = 0x160;
            sp24 = (u8*)&D_800AE4E8[sp30].unk_04.unk1->unk_0000[idx2][arg1];
            sp20 = (u8*)&D_800AE4E8[sp30].unk_08.unk1->unk_0000[idx2][arg1];
            break;

        case 17:
            sp30 = 3;
            sp34 = 0x468;
            sp24 = (u8*)&D_800AE4E8[3].unk_04.unk3->unk_0000[arg1];
            sp20 = (u8*)&D_800AE4E8[3].unk_08.unk3->unk_0000[arg1];
            break;

        case 18:
            sp30 = 3;
            sp34 = 0xE0;
            sp24 = (u8*)&D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1];
            sp20 = (u8*)&D_800AE4E8[3].unk_08.unk3->unk_34E0[arg1];
            break;

        case 19:
            sp30 = 2;
            sp34 = 0xF60;
            sp24 = (u8*)&D_800AE4E8[2].unk_04.unk2->unk_0DC0;
            sp20 = (u8*)&D_800AE4E8[2].unk_08.unk2->unk_0DC0;
            break;

        case 20:
            sp30 = 2;
            sp34 = 0x28;
            sp24 = (u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EA0;
            sp20 = (u8*)&D_800AE4E8[2].unk_08.unk2->unk_1EA0;
            break;

        case 21:
            sp30 = 2;
            sp34 = 0x180;
            sp24 = (u8*)&D_800AE4E8[2].unk_04.unk2->unk_1D20;
            sp20 = (u8*)&D_800AE4E8[2].unk_08.unk2->unk_1D20;
            break;

        case 22:
            sp30 = 2;
            sp34 = 0x13B8;
            sp24 = (u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EC8;
            sp20 = (u8*)&D_800AE4E8[2].unk_08.unk2->unk_1EC8;
            break;

        case 23:
            sp30 = 2;
            sp34 = 0xB84;
            sp24 = (u8*)&D_800AE4E8[2].unk_04.unk2->unk_3280;
            sp20 = (u8*)&D_800AE4E8[2].unk_08.unk2->unk_3280;
            break;
    }

    switch ((Save_RecordIsValid(sp24, sp34) | Save_RecordIsValid(sp20, sp34) << 1)) {
        case 0:
            Save_ResetAndCommitTypedRecord(arg0, arg1);
            break;

        case 1:
            Save_WriteRecord(sp24, sp20, sp34, sp30);
            break;

        case 2:
            Save_WriteRecord(sp20, sp24, sp34, sp30);
            break;
    }
}

void GbSave_LoadBattleMonRecord(BattleMon* arg0, GbPokemonNamedRecord* arg1) {
    Pokemon_FromGbRecord(arg0, arg1);
    Pokemon_RecalcStats(arg0);

    arg0->unk_52 = 0;
    arg0->unk_53 = 0;
    arg0->unk_25 = 0;

    _bcopy(arg1->unk_2C, arg0->unk_46, 0xB);
    Text_UntranscodeFixedName(arg0->unk_30, arg1->unk_21);
    Text_UntranscodeFixedName(arg0->unk_3B, arg1->unk_2C);
}

void GbSave_SaveBattleMonRecord(BattleMon* arg0, GbPokemonNamedRecord* arg1) {
    arg0->unk_04 = arg0->unk_24;

    Pokemon_ToGbRecord(arg0, &arg1->unk_00);
    Text_TranscodeName(arg1->unk_21, arg0->unk_30);

    _bcopy(arg0->unk_46, arg1->unk_2C, 0xB);
}

s32 Save_IsTypedRecordFlagSet(s32 arg0, s32 arg1, s16 arg2) {
    s32 var_v1 = 0;
    s16 idx1 = D_800AE4E0 / 4;
    s16 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            var_v1 = (D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_000.unk_00 & arg2) != 0;
            break;

        case 17:
            var_v1 = (D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_000.unk_00 & arg2) != 0;
            break;

        case 18:
            var_v1 = (D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_00.unk_00 & arg2) != 0;
            break;

        case 19:
            var_v1 = (D_800AE4E8[2].unk_04.unk2->unk_0DC0.unk_000 & arg2) != 0;
            break;

        case 20:
            var_v1 = (D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_00 & arg2) != 0;
            break;

        case 21:
            var_v1 = (D_800AE4E8[2].unk_04.unk2->unk_1D20.unk_000 & arg2) != 0;
            break;

        case 22:
            var_v1 = (D_800AE4E8[2].unk_04.unk2->unk_1EC8.unk_0000 & arg2) != 0;
            break;

        case 23:
            var_v1 = (D_800AE4E8[2].unk_04.unk2->unk_3280.unk_0000 & arg2) != 0;
            break;
    }

    return var_v1;
}

void Save_MarkRecordDirty(s32 arg0, s32 arg1, s16 arg2) {
    s16 idx1 = D_800AE4E0 / 4;
    s16 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_000.unk_00 |= arg2;
            break;

        case 17:
            D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_000.unk_00 |= arg2;
            break;

        case 18:
            D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_00.unk_00 |= arg2;
            break;

        case 19:
            D_800AE4E8[2].unk_04.unk2->unk_0DC0.unk_000 |= arg2;
            break;

        case 20:
            D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_00 |= arg2;
            break;

        case 21:
            D_800AE4E8[2].unk_04.unk2->unk_1D20.unk_000 |= arg2;
            break;

        case 22:
            D_800AE4E8[2].unk_04.unk2->unk_1EC8.unk_0000 |= arg2;
            break;

        case 23:
            D_800AE4E8[2].unk_04.unk2->unk_3280.unk_0000 |= arg2;
            break;
    }
}

void func_8002667C(void) {
}

void Save_CommitTypedRecord(s32 arg0, s32 arg1) {
    s16 idx1 = D_800AE4E0 / 4;
    s16 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            Save_CommitRecord((u8*)&D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1], 0x160, idx1);
            break;

        case 17:
            Save_CommitRecord((u8*)&D_800AE4E8[3].unk_04.unk3->unk_0000[arg1], 0x468, 3);
            break;

        case 18:
            Save_CommitRecord((u8*)&D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1], 0xE0, 3);
            break;

        case 19:
            Save_CommitRecord((u8*)&D_800AE4E8[2].unk_04.unk2->unk_0DC0, 0xF60, 2);
            break;

        case 20:
            Save_CommitRecord((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EA0, 0x28, 2);
            break;

        case 21:
            Save_CommitRecord((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1D20, 0x180, 2);
            break;

        case 22:
            Save_CommitRecord((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EC8, 0x13B8, 2);
            break;

        case 23:
            Save_CommitRecord((u8*)&D_800AE4E8[2].unk_04.unk2->unk_3280, 0xB84, 2);
            break;
    }
}

void Save_InvalidateTypedRecord(s32 arg0, s32 arg1) {
    s16 idx1 = D_800AE4E0 / 4;
    s16 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            Save_InvalidateRecord((u8*)&D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1], 0x160, idx1);
            break;

        case 17:
            Save_InvalidateRecord((u8*)&D_800AE4E8[3].unk_04.unk3->unk_0000[arg1], 0x468, 3);
            break;

        case 18:
            Save_InvalidateRecord((u8*)&D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1], 0xE0, 3);
            break;

        case 19:
            Save_InvalidateRecord((u8*)&D_800AE4E8[2].unk_04.unk2->unk_0DC0, 0xF60, 2);
            break;

        case 20:
            Save_InvalidateRecord((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EA0, 0x28, 2);
            break;

        case 21:
            Save_InvalidateRecord((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1D20, 0x180, 2);
            break;

        case 22:
            Save_InvalidateRecord((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EC8, 0x13B8, 2);
            break;

        case 23:
            Save_InvalidateRecord((u8*)&D_800AE4E8[2].unk_04.unk2->unk_3280, 0xB84, 2);
            break;
    }
}

void Save_RestoreTypedRecord(s32 arg0, s32 arg1) {
    s16 idx1 = D_800AE4E0 / 4;
    s16 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            Save_RestoreRecord((u8*)&D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1], 0x160, idx1);
            break;

        case 17:
            Save_RestoreRecord((u8*)&D_800AE4E8[3].unk_04.unk3->unk_0000[arg1], 0x468, 3);
            break;

        case 18:
            Save_RestoreRecord((u8*)&D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1], 0xE0, 3);
            break;

        case 19:
            Save_RestoreRecord((u8*)&D_800AE4E8[2].unk_04.unk2->unk_0DC0, 0xF60, 2);
            break;

        case 20:
            Save_RestoreRecord((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EA0, 0x28, 2);
            break;

        case 21:
            Save_RestoreRecord((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1D20, 0x180, 2);
            break;

        case 22:
            Save_RestoreRecord((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EC8, 0x13B8, 2);
            break;

        case 23:
            Save_RestoreRecord((u8*)&D_800AE4E8[2].unk_04.unk2->unk_3280, 0xB84, 2);
            break;
    }
}

void Save_ClearTypedRecord(s32 arg0, s32 arg1) {
    UNUSED s32 pad;
    RegisteredTeamSlot* sp38;
    unk_D_800AE4E8_004_3_0000* sp34;
    unk_D_800AE4E8_004_3_34E0* sp30;
    unk_D_800AE4E8_004_2_0DC0* sp2C;
    SaveOptionsRecord* sp28;
    ContinueRecordBlock* sp24;
    unk_D_800AE4E8_004_2_1EC8* sp20;
    unk_D_800AE4E8_004_2_3280* sp1C;
    s16 idx1 = D_800AE4E0 / 4;
    s16 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            sp38 = &D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1];
            Save_ClearRecord(sp38, 0x160, idx1);
            sp38->unk_000.unk_01 = 0x50;
            break;

        case 17:
            sp34 = &D_800AE4E8[3].unk_04.unk3->unk_0000[arg1];
            Save_ClearRecord(sp34, 0x468, 3);
            sp34->unk_000.unk_01 = 0x50;
            break;

        case 18:
            sp30 = &D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1];
            Save_ClearRecord(sp30, 0xE0, 3);
            sp30->unk_00.unk_01 = 0x50;
            break;

        case 19:
            sp2C = &D_800AE4E8[2].unk_04.unk2->unk_0DC0;
            Save_ClearRecord(sp2C, 0xF60, 2);
            sp2C->unk_000 |= 1;
            break;

        case 20:
            sp28 = &D_800AE4E8[2].unk_04.unk2->unk_1EA0;
            Save_ClearRecord(sp28, 0x28, 2);
            sp28->unk_00 |= 1;
            break;

        case 21:
            sp24 = &D_800AE4E8[2].unk_04.unk2->unk_1D20;
            Save_ClearRecord(sp24, 0x180, 2);
            break;

        case 22:
            sp20 = &D_800AE4E8[2].unk_04.unk2->unk_1EC8;
            Save_ClearRecord(sp20, 0x13B8, 2);
            sp20->unk_0000 |= 1;
            break;

        case 23:
            sp1C = &D_800AE4E8[2].unk_04.unk2->unk_3280;
            Save_ClearRecord(sp1C, 0xB84, 2);
            sp1C->unk_0000 |= 1;
            break;
    }
}

void Save_CommitBankRecords(s16 arg0) {
    s32 i;
    s32 sp28;

    if (D_800AE4E8[arg0].unk_00 & 1) {
        sp28 = D_800AE4E0;

        switch (arg0) {
            case 0:
                for (D_800AE4E0 = 0; D_800AE4E0 < 4; D_800AE4E0++) {
                    for (i = 0; i < 10; i++) {
                        Save_CommitTypedRecord(0x10, i);
                    }
                }
                break;

            case 1:
                for (D_800AE4E0 = 4; D_800AE4E0 < 8; D_800AE4E0++) {
                    for (i = 0; i < 10; i++) {
                        Save_CommitTypedRecord(0x10, i);
                    }
                }
                break;

            case 2:
                D_800AE4E0 = 8;

                for (i = 0; i < 10; i++) {
                    Save_CommitTypedRecord(0x10, i);
                }

                Save_CommitTypedRecord(0x13, 0);
                Save_CommitTypedRecord(0x14, 0);
                Save_CommitTypedRecord(0x15, 0);
                Save_CommitTypedRecord(0x16, 0);
                Save_CommitTypedRecord(0x17, 0);
                break;

            case 3:
                for (i = 0; i < 12; i++) {
                    Save_CommitTypedRecord(0x11, i);
                }

                for (i = 0; i < 4; i++) {
                    Save_CommitTypedRecord(0x12, i);
                }

                break;
        }

        D_800AE4E0 = sp28;
    }
}

void Save_CommitAllBankRecords(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        Save_CommitBankRecords(i);
    }
}

void Save_ResetAndCommitTypedRecord(s32 arg0, s32 arg1) {
    Save_ClearTypedRecord(arg0, arg1);
    Save_CommitTypedRecord(arg0, arg1);
}

s32 Deck_GetSaveRecordCapacity(s32 arg0) {
    s32 var_v1 = 0;

    switch (arg0) {
        case 16:
            var_v1 = 6;
            break;

        case 17:
            var_v1 = 0x14;
            break;

        case 18:
            var_v1 = 0x64;
            break;

        case 19:
            var_v1 = 0x97;
            break;

        case 22:
            var_v1 = 0x24;
            break;

        case 23:
            var_v1 = 0x15;
            break;
    }

    return var_v1;
}

s32 Deck_GetSaveRecordSize(s32 arg0) {
    s32 var_v1 = 0;

    switch (arg0) {
        case 16:
            var_v1 = 0x54;
            break;

        case 17:
            var_v1 = 0x54;
            break;

        case 18:
            var_v1 = 2;
            break;

        case 19:
            var_v1 = 0x1A;
            break;

        case 22:
            var_v1 = 0x8C;
            break;

        case 23:
            var_v1 = 0x8C;
            break;
    }

    return var_v1;
}

s32 Deck_IsSaveEntryPresent(s32 arg0, s32 arg1) {
    return Save_IsTypedRecordFlagSet(arg0, arg1, 1);
}

s32 Deck_GetSaveEntryTrainerId(s32 arg0, s32 arg1) {
    s32 sp1C = -1;

    if (Deck_IsSaveEntryPresent(arg0, arg1) != 0) {
        s16 idx1 = D_800AE4E0 / 4;
        s16 idx2 = D_800AE4E0 % 4;

        switch (arg0) {
            case 16:
                sp1C = D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_000.unk_0C;
                break;

            case 17:
                sp1C = D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_000.unk_0C;
                break;

            case 18:
                sp1C = D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_00.unk_0C;
                break;
        }
    }
    return sp1C;
}

char* Deck_GetSaveEntryName(s32 arg0, s32 arg1, char* arg2) {
    char* sp1C = NULL;
    char* var_a1;

    *arg2 = '\x00';

    if (Deck_IsSaveEntryPresent(arg0, arg1) != 0) {
        s16 idx1 = D_800AE4E0 / 4;
        s16 idx2 = D_800AE4E0 % 4;

        var_a1 = NULL;

        switch (arg0) {
            case 16:
                var_a1 = &D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_000.unk_01;
                break;

            case 17:
                var_a1 = &D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_000.unk_01;
                break;

            case 18:
                var_a1 = &D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_00.unk_01;
                break;
        }

        if (var_a1 != NULL) {
            sp1C = Text_UntranscodeName(arg2, var_a1);
        }
    }

    return sp1C;
}

void Deck_GetSaveEntryNameWrapper(s32 arg0, s32 arg1, char* arg2) {
    Deck_GetSaveEntryName(arg0, arg1, arg2);
}

void Deck_SetSaveEntryTrainerIdAndName(s32 arg0, s32 arg1, s32 arg2, char* arg3, u16 arg4) {
    RegisteredTeamSlot* temp_v0;
    unk_D_800AE4E8_004_3_0000* temp_v0_2;
    unk_D_800AE4E8_004_3_34E0* temp_v0_3;
    s16 idx1 = D_800AE4E0 / 4;
    s16 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            temp_v0 = &D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1];
            if (arg4 >= 0) {
                temp_v0->unk_000.unk_0C = arg4;
            }

            if (arg3 != NULL) {
                Text_TranscodeName(&temp_v0->unk_000.unk_01, arg3);
            }

            Save_MarkRecordDirty(arg0, arg1, 3);
            break;

        case 17:
            temp_v0_2 = &D_800AE4E8[3].unk_04.unk3->unk_0000[arg1];
            if (arg4 >= 0) {
                temp_v0_2->unk_000.unk_0C = arg4;
            }

            if (arg3 != NULL) {
                Text_TranscodeName(&temp_v0_2->unk_000.unk_01, arg3);
            }

            Save_MarkRecordDirty(arg0, arg1, 3);
            break;

        case 18:
            temp_v0_3 = &D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1];
            if (arg4 >= 0) {
                temp_v0_3->unk_00.unk_0C = arg4;
            }

            if (arg3 != NULL) {
                Text_TranscodeName(&temp_v0_3->unk_00.unk_01, arg3);
            }

            Save_MarkRecordDirty(arg0, arg1, 3);
            break;
    }
}

s16 Deck_GetSaveEntryCount(s32 arg0, s32 arg1) {
    s16 var_v1 = 0;
    s32 idx1 = D_800AE4E0 / 4;
    s32 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            var_v1 = D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_000.unk_0E;
            break;

        case 17:
            var_v1 = D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_000.unk_0E;
            break;

        case 18:
            var_v1 = D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_00.unk_0E;
            break;

        case 19:
            var_v1 = 0x97;
            break;

        case 22:
            var_v1 = 0x24;
            break;

        case 23:
            var_v1 = 0x15;
            break;
    }

    return var_v1;
}

void Deck_SetSaveEntryCount(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp1C = D_800AE4E0 / 4;
    s32 sp18 = D_800AE4E0 % 4;

    if (arg2 < Deck_GetSaveEntryCount(arg0, arg1)) {
        switch (arg0) {
            case 16:
                D_800AE4E8[sp1C].unk_04.unk1->unk_0000[sp18][arg1].unk_000.unk_0E = arg2;
                break;

            case 17:
                D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_000.unk_0E = arg2;
                break;

            case 18:
                D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_00.unk_0E = arg2;
                break;
        }

        Save_MarkRecordDirty(arg0, arg1, 2);
    }
}

void Deck_IncrementSaveEntryCount(s32 arg0, s32 arg1) {
    s32 idx1;
    s32 idx2;
    s32 sp1C;

    idx1 = D_800AE4E0 / 4;
    idx2 = D_800AE4E0 % 4;

    sp1C = Deck_GetSaveEntryCount(arg0, arg1);
    if (sp1C < Deck_GetSaveRecordCapacity(arg0)) {
        switch (arg0) {
            case 16:
                D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_000.unk_0E = sp1C + 1;
                break;

            case 17:
                D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_000.unk_0E = sp1C + 1;
                break;

            case 18:
                D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_00.unk_0E = sp1C + 1;
                break;
        }
        Save_MarkRecordDirty(arg0, arg1, 2);
    }
}

s32 Deck_ReadSaveEntry(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    s32 sp2C = 0;
    s32 idx1 = D_800AE4E0 / 4;
    s32 idx2 = D_800AE4E0 % 4;

    if (arg2 < Deck_GetSaveEntryCount(arg0, arg1)) {
        switch (arg0) {
            case 16:
                GbSave_LoadBattleMonRecord(arg3, &D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_010[arg2]);
                break;

            case 17:
                GbSave_LoadBattleMonRecord(arg3, &D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_010[arg2]);
                break;

            case 18:
                *(unk_D_800AE4E8_004_3_34E0_010*)arg3 = D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_10[arg2];
                break;

            case 19:
                *(unk_D_800AE4E8_004_2_0DC0_002*)arg3 = D_800AE4E8[2].unk_04.unk2->unk_0DC0.unk_002[arg2];
                break;

            case 22:
                _bcopy(&D_800AE4E8[2].unk_04.unk2->unk_1EC8.unk_0002[arg2], arg3,
                       sizeof(unk_D_800AE4E8_004_2_1EC8_0002));
                break;

            case 23:
                _bcopy(&D_800AE4E8[2].unk_04.unk2->unk_3280.unk_0002[arg2], arg3,
                       sizeof(unk_D_800AE4E8_004_2_1EC8_0002));
                break;
        }
        sp2C = 1;
    }

    return sp2C;
}

s32 Save_WriteTypedRecord(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    s32 sp34 = 0;
    s32 idx1 = D_800AE4E0 / 4;
    s32 idx2 = D_800AE4E0 % 4;
    s32 sp28 = Deck_GetSaveRecordCapacity(arg0);
    s32 sp24 = Deck_GetSaveEntryCount(arg0, arg1);

    if ((arg2 < sp24) || ((arg2 == sp24) && (arg2 < sp28))) {
        switch (arg0) {
            case 16:
                GbSave_SaveBattleMonRecord(arg3, &D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_010[arg2]);
                break;
            case 17:
                GbSave_SaveBattleMonRecord(arg3, &D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_010[arg2]);
                break;
            case 18:
                D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_10[arg2] = *(unk_D_800AE4E8_004_3_34E0_010*)arg3;
                break;
            case 19:
                D_800AE4E8[2].unk_04.unk2->unk_0DC0.unk_002[arg2] = *(unk_D_800AE4E8_004_2_0DC0_002*)arg3;
                break;
            case 22:
                _bcopy(arg3, &D_800AE4E8[2].unk_04.unk2->unk_1EC8.unk_0002[arg2], 0x8C);
                break;
            case 23:
                _bcopy(arg3, &D_800AE4E8[2].unk_04.unk2->unk_3280.unk_0002[arg2], 0x8C);
                break;
        }

        if (arg2 == sp24) {
            Deck_IncrementSaveEntryCount(arg0, arg1);
        } else {
            Save_MarkRecordDirty(arg0, arg1, 2);
        }

        sp34 = 1;
    }
    return sp34;
}

void Save_GetOptions(GameOptions* options) {
    *options = D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_04;
}

void Save_SetOptions(GameOptions* arg0) {
    if (bcmp(arg0, &D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_04, 8) != 0) {
        D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_04 = *arg0;
        Save_MarkRecordDirty(0x14, 0, 2);
    }
}

void Save_GetModeSettings(ModeSettings* settings, s16 round_index) {
    *settings = D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_0C[round_index];
}

void Save_SetModeSettings(ModeSettings* arg0, s16 arg1) {
    if (bcmp(arg0, &D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_0C[arg1], sizeof(ModeSettings)) != 0) {
        D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_0C[arg1] = *arg0;
        Save_MarkRecordDirty(0x14, 0, 2);
    }
}

void Save_GetOptionsField02(u16* arg0) {
    *arg0 = D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_02;
}

void Save_SetOptionsField02(u16* arg0) {
    u16 tmp = *arg0;
    unk_D_800AE4E8_004_2* temp_v1 = D_800AE4E8[2].unk_04.unk2;

    if (temp_v1->unk_1EA0.unk_02 != tmp) {
        temp_v1->unk_1EA0.unk_02 = tmp;
        Save_MarkRecordDirty(0x14, 0, 2);
    }
}

s32 Save_GetOptionsField1E(void) {
    return D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_1E;
}

void Save_SetOptionsField1E(u8 arg0) {
    unk_D_800AE4E8_004_2* temp_v0 = D_800AE4E8[2].unk_04.unk2;

    if (temp_v0->unk_1EA0.unk_1E != arg0) {
        temp_v0->unk_1EA0.unk_1E = arg0;
        Save_MarkRecordDirty(0x14, 0, 2);
    }
}

s32 Save_GetOptionsField1F(void) {
    return D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_1F;
}

void Save_SetOptionsField1F(u8 arg0) {
    unk_D_800AE4E8_004_2* temp_v0 = D_800AE4E8[2].unk_04.unk2;

    if (temp_v0->unk_1EA0.unk_1F != arg0) {
        temp_v0->unk_1EA0.unk_1F = arg0;
        Save_MarkRecordDirty(0x14, 0, 2);
    }
}

s32 Save_GetSelectedPokemonId(void) {
    return D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_1C;
}

void Save_SetSelectedPokemonId(u8 arg0, u8 arg1) {
    s32 temp_v0 = (((arg1 & 1) << 8) | arg0) & 0xFFFF;
    unk_D_800AE4E8_004_2* temp_v1 = D_800AE4E8[2].unk_04.unk2;

    if (temp_v1->unk_1EA0.unk_1C != temp_v0) {
        temp_v1->unk_1EA0.unk_1C = temp_v0;
        Save_MarkRecordDirty(0x14, 0, 2);
    }
}

void Session_SaveContinueRecord(SessionContinueData* arg0, BattleMon* arg1, s32 arg2) {
    ContinueRecordBlock* temp_v0;
    s32 i;

    if (D_800AE4E8[2].unk_00 & 1) {
        temp_v0 = &D_800AE4E8[2].unk_04.unk2->unk_1D20;

        temp_v0->unk_000 |= 3;
        temp_v0->unk_002 = *arg0;
        temp_v0->unk_022 = arg2;

        for (i = 0; i < arg2; i++) {
            GbSave_SaveBattleMonRecord(&arg1[i], &temp_v0->unk_024[i]);
            temp_v0->unk_16E[i] = arg1[i].unk_52;
            temp_v0->unk_174[i] = arg1[i].unk_53;
        }
    }
}

s32 Session_LoadContinueRecord(SessionContinueData* arg0, BattleMon* arg1) {
    s16 var_s5 = -1;
    ContinueRecordBlock* temp_v0;
    s32 i;

    if (D_800AE4E8[2].unk_00 & 1) {
        temp_v0 = &D_800AE4E8[2].unk_04.unk2->unk_1D20;

        if (temp_v0->unk_000 & 1) {
            *arg0 = temp_v0->unk_002;
            var_s5 = temp_v0->unk_022;
            if (arg1 != NULL) {
                for (i = 0; i < var_s5; i++) {
                    GbSave_LoadBattleMonRecord(&arg1[i], &temp_v0->unk_024[i]);
                    arg1[i].unk_52 = temp_v0->unk_16E[i];
                    arg1[i].unk_53 = temp_v0->unk_174[i];
                }
            }
        }
    }
    return var_s5;
}

s32 Save_ContinueRecordExists(void) {
    s32 var_v1 = 0;

    if (D_800AE4E8[2].unk_00 & 1) {
        ContinueRecordBlock* temp_v0 = &D_800AE4E8[2].unk_04.unk2->unk_1D20;

        var_v1 = (temp_v0->unk_000 & 1) != 0;
    }
    return var_v1;
}

s32 Save_FlushBank(s16 arg0) {
    static u32 D_80073650[] = {
        0x3700,
        0x3700,
        0x3F80,
        0x3880,
    };

    s32 sp38;
    s32 var_s0;
    s16 temp_s5;

    temp_s5 = D_80073650[arg0] >> 7;

    if ((D_800AE4E8[arg0].unk_00 & 1) && (D_800AE4E8[arg0].unk_00 & 2)) {
        _bcopy(D_800AE4E8[arg0].unk_04.unk1, D_800AE4E8[arg0].unk_08.unk1, D_80073650[arg0]);
        var_s0 = 0;
        while (Flash_EraseSectorByIndex(arg0) == -1) {
            var_s0++;
            if (var_s0 == 4) {
                return -1;
            }
        }

        var_s0 = 0;
        sp38 = arg0 << 7;
        while (Flash_ProgramPages((u8*)D_800AE4E8[arg0].unk_04.unk1, sp38, temp_s5, 1) == -1) {
            var_s0++;
            if (var_s0 == 4) {
                return -1;
            }
        }

        var_s0 = 0;
        while (Flash_EraseSectorByIndex(arg0 + 4) == -1) {
            var_s0 += 1;
            if (var_s0 == 4) {
                return -1;
            }
        }

        sp38 = arg0 << 7;
        sp38 += 0x200;
        var_s0 = 0;
        while (Flash_ProgramPages((u8*)D_800AE4E8[arg0].unk_08.unk1, sp38, temp_s5, 1) == -1) {
            var_s0++;
            if (var_s0 == 4) {
                return 0;
            }
        }

        D_800AE4E8[arg0].unk_00 &= ~2;
    }

    return 0;
}

s32 Save_FlushDirtyBanks(void) {
    s32 i;
    s32 var_s1 = 0;

    for (i = 0; i < 4; i++) {
        if (Save_FlushBank(i) != 0) {
            var_s1 |= 1 << i;
        }
    }

    return var_s1;
}

s32 Save_AllocateBank(s16 arg0, u32 arg1) {
    s32 sp2C = 0;
    u8* sp28;

    if (D_800AE4E8[arg0].unk_04.unk1 == NULL) {
        sp28 = main_pool_alloc_with_func(arg1 * 2, 0, 'BNK0' + arg0, Save_ResetBank);
        if (sp28 != NULL) {
            bzero(sp28, arg1 * 2);
            D_800AE4E8[arg0].unk_04.unk1 = sp28;
            D_800AE4E8[arg0].unk_08.unk1 = sp28 + arg1;
            Flash_ProgramPages(sp28, arg0 << 7, arg1 >> 7, 0);
            Flash_ProgramPages(D_800AE4E8[arg0].unk_08.unk1, (arg0 << 7) + 0x200, arg1 >> 7, 0);
            sp2C = 1;
        }
    }

    return sp2C;
}

void Save_InitializeBank0(void) {
    s32 j;
    s32 sp28;

    if (Save_AllocateBank(0, 0x3700) != 0) {
        sp28 = D_800AE4E0;

        for (D_800AE4E0 = 0; D_800AE4E0 < 4; D_800AE4E0++) {
            for (j = 0; j < 10; j++) {
                Save_LoadWithRepair(0x10, j);
            }
        }

        D_800AE4E8->unk_00 |= 1;
        D_800AE4E0 = sp28;
    }
}

void Save_InitializeBank1(void) {
    s32 i;
    s32 sp28;

    if (Save_AllocateBank(1, 0x3700) != 0) {
        sp28 = D_800AE4E0;
        D_800AE4E0 = 4;
        while (D_800AE4E0 < 8) {
            for (i = 0; i < 10; i++) {
                Save_LoadWithRepair(16, i);
            }
            D_800AE4E0++;
        }
        D_800AE4E8[1].unk_00 |= 1;
        D_800AE4E0 = sp28;
    }
}

void Save_InitializeBank2(void) {
    s32 i;
    s32 sp20;

    if (Save_AllocateBank(2, 0x3F80) != 0) {
        sp20 = D_800AE4E0;
        D_800AE4E0 = 8;

        for (i = 0; i < 10; i++) {
            Save_LoadWithRepair(16, i);
        }

        Save_LoadWithRepair(19, 0);
        Save_LoadWithRepair(20, 0);
        Save_LoadWithRepair(21, 0);
        Save_LoadWithRepair(22, 0);
        Save_LoadWithRepair(23, 0);

        D_800AE4E8[2].unk_00 |= 1;
        D_800AE4E0 = sp20;
    }
}

void Save_InitializeBank3(void) {
    s32 i;

    if (Save_AllocateBank(3, 0x3880) != 0) {
        for (i = 0; i < 12; i++) {
            Save_LoadWithRepair(17, i);
        }

        for (i = 0; i < 4; i++) {
            Save_LoadWithRepair(18, i);
        }

        D_800AE4E8[3].unk_00 |= 1;
    }
}

s32 Save_EnsureBankLoaded(s16 arg0) {
    if (!((D_800AE4E8[arg0].unk_00 & 1) != 0)) {
        switch (arg0) {
            case 0:
                Save_InitializeBank0();
                break;

            case 1:
                Save_InitializeBank1();
                break;

            case 2:
                Save_InitializeBank2();
                break;

            case 3:
                Save_InitializeBank3();
                break;
        }
    }

    return (D_800AE4E8[arg0].unk_00 & 1) != 0;
}

void Save_EnsureAllBanksLoaded(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        Save_EnsureBankLoaded(i);
    }
}

void Save_EnsureBank3Loaded(void) {
    Save_EnsureBankLoaded(3);
}

s32 Save_SetActiveRecordBank(s16 arg0) {
    s32 tmp = D_800AE4E0;

    if ((arg0 >= 0) && (arg0 < 9)) {
        D_800AE4E0 = arg0;
    }
    return tmp;
}

s32 RegisteredTeam_ReadSlot(RegisteredTeamSlot* arg0, s32 arg1) {
    s32 var_v1 = 0;
    s32 idx1 = D_800AE4E0 / 4;
    s32 idx2 = D_800AE4E0 % 4;

    if ((arg1 >= 0) && (arg1 < 0xA)) {
        *arg0 = D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1];
        var_v1 = 1;
    }
    return var_v1;
}

s32 RegisteredTeam_WriteSlot(RegisteredTeamSlot* arg0, s32 arg1) {
    s32 var_v1 = 0;
    s32 idx1 = D_800AE4E0 / 4;
    s32 idx2 = D_800AE4E0 % 4;

    if ((arg1 >= 0) && (arg1 < 0xA)) {
        D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1] = *arg0;
        Save_MarkRecordDirty(0x10, arg1, 2);
        var_v1 = 1;
    }
    return var_v1;
}

s32 Deck_FindFirstFreeTeamSlot(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (Deck_IsSaveEntryPresent(0x10, i) == 0) {
            break;
        }
    }

    return i;
}

void Deck_CompactRegisteredTeams(void) {
    RegisteredTeamSlot sp40;
    s32 i;
    s32 j;

    for (i = 9; i >= 0; i--) {
        if (Deck_IsSaveEntryPresent(0x10, i) != 0) {
            break;
        }
    }

    for (j = i - 1; j >= 0; j--) {
        if (Deck_IsSaveEntryPresent(0x10, j) != 0) {
            continue;
        }

        for (i = j; i < 9; i++) {
            if (i && i) {}

            RegisteredTeam_ReadSlot(&sp40, i + 1);
            RegisteredTeam_WriteSlot(&sp40, i);
            Save_CommitTypedRecord(0x10, i);
        }

        Save_ResetAndCommitTypedRecord(0x10, 9);
    }
}
