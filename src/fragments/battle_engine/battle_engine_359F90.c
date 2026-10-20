#include "battle_engine.h"
#include "src/gb_data.h"
#include "src/text_system.h"
#include "src/matrix.h"
#include "moves.h"

typedef struct unk_D_843C4DA0 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk06[0x3];
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ char unk0A[0xA];
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ char unk14[0x1];
    /* 0x15 */ u8 unk_15;
    /* 0x16 */ char unk16[0x1];
    /* 0x17 */ u8 unk_17;
    /* 0x18 */ char unk18[0xB];
    /* 0x22 */ u8 unk_22;
    /* 0x24 */ u16 unk_24;
    /* 0x26 */ u16 unk_26;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ u16 unk_2A;
    /* 0x2C */ u16 unk_2C;
    /* 0x2E */ char unk2E[0x1E];
} unk_D_843C4DA0; // size = 0x4C

static u16 D_843C4DA0;
static u8 D_843C4DA2;
static u8 D_843C4DA3;
u8 sBattleMoveFailed;
u8 sBattleCritFlag;
static u8 D_843C4DA6;
static u8 D_843C4DA7;
static u8 D_843C4DA8;
u8 D_843C4DA9;
u8 D_843C4DAA;
static u8 D_843C4DAB;
static u8 D_843C4DAC;
static u8 D_843C4DAD;
static u8 D_843C4DAE;
static u8 D_843C4DAF;
static u8 D_843C4DB0;
static u8 D_843C4DB1;
static u8 D_843C4DB2;
static u8 D_843C4DB3;
static u8 D_843C4DB4;
static u8 D_843C4DB5;
static u8 D_843C4DB6;
static u8 D_843C4DB7;
static u8 D_843C4DB8;
static u8 D_843C4DB9;
static u8 D_843C4DBA;
static u8 D_843C4DBB;
static u8 D_843C4DBC;
static u8 D_843C4DBD;
static u8 D_843C4DBE;
static u8 D_843C4DBF;
static u8 D_843C4DC0;
static u8 D_843C4DC1;
static u8 D_843C4DC2;
u16 sBattleDamage;
static u16 D_843C4DC6;
static u16 D_843C4DC8;
static u16 D_843C4DCA;
static u16 D_843C4DCC;
static s32 pad_D_843C4DD0;
static s32 pad_D_843C4DD4;
static s32 pad_D_843C4DD8;
static s32 pad_D_843C4DDC;
static s32 pad_D_843C4DE0;
static s32 pad_D_843C4DE4;
static s32 pad_D_843C4DE8;
s32 D_843C4DEC;
static s32 pad_D_843C4DF0[21];
u8 sConfused;
u8 D_843C4E45;
static s32 pad_D_843C4E48[252];
BattleMonRuntime* sBattleUser;
BattleMonRuntime* sBattleTarget;
static BattleMonRuntime D_843C5240[2];

u8 D_8438AC60[] = {
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x4A, 0x00, 0x00,
    0x60, 0x69, 0x75, 0x78, 0x85, 0x00, 0x00, 0x00, 0x61, 0x64, 0x66, 0x68, 0x8C, 0x00, 0x00, 0x00,
    0x01, 0x0A, 0x0B, 0x11, 0x13, 0x14, 0x15, 0x1E, 0x22, 0x23, 0x25, 0x27, 0x2B, 0x2C, 0x2D, 0x2E,
    0x2F, 0x40, 0x44, 0x46, 0x47, 0x51, 0x59, 0x5A, 0x5B, 0x5C, 0x67, 0x6A, 0x6B, 0x6E, 0x6F, 0x76,
    0x7A, 0x80, 0x84, 0x8B, 0x8D, 0x91, 0x94, 0x96, 0x97, 0x9A, 0x9C, 0x9F, 0xA3, 0xA4, 0x00, 0x00,
};
static u8 D_8438ACB0[] = { 1, 0x20, 0x43, 0x54, 0x56 };
StatStageMultiplier gStatStageMultipliers[] = {
    { 0x19, 0x64 }, { 0x1C, 0x64 }, { 0x21, 0x64 }, { 0x28, 0x64 }, { 0x32, 0x64 }, { 0x42, 0x64 }, { 0x01, 0x01 },
    { 0x0F, 0x0A }, { 0x02, 0x01 }, { 0x19, 0x0A }, { 0x03, 0x01 }, { 0x23, 0x0A }, { 0x04, 0x01 },
};
u8 D_8438ACD4[] = {
    0x01, 0x03, 0x24, 0x64, 0x2B, 0x64, 0x01, 0x02, 0x42, 0x64, 0x4B, 0x64, 0x01,
    0x01, 0x85, 0x64, 0xA6, 0x64, 0x02, 0x01, 0xE9, 0x64, 0x85, 0x32, 0x03, 0x01,
};
u8 sTypeEffects[] = {
    0x15, 0x14, 0x14, 0x14, 0x16, 0x14, 0x14, 0x19, 0x14, 0x16, 0x15, 0x14, 0x17, 0x15, 0x14, 0x15, 5,    0x14,
    4,    2,    0,    0x15, 0x15, 5,    0x14, 0x14, 5,    0x17, 0x17, 5,    0x19, 0x19, 5,    0x16, 0x16, 5,
    0x18, 0x18, 5,    0x14, 0x15, 5,    0x16, 0x14, 5,    0x15, 0x16, 5,    0x17, 0x16, 5,    0,    5,    5,
    0,    8,    0,    8,    8,    0x14, 0x14, 7,    0x14, 0x14, 5,    5,    0x15, 4,    0x14, 0x17, 4,    0,
    0x17, 2,    0x14, 0x16, 4,    0x14, 0x16, 7,    5,    0x16, 3,    5,    0x16, 5,    0x14, 0x16, 2,    5,
    0x19, 0x15, 5,    0x19, 0x16, 0x14, 0x19, 4,    0x14, 0x19, 2,    0x14, 1,    0,    0x14, 1,    3,    5,
    1,    2,    5,    1,    0x18, 5,    1,    7,    5,    1,    5,    0x14, 1,    0x19, 0x14, 1,    8,    0,
    3,    0x16, 0x14, 3,    3,    5,    3,    4,    5,    3,    7,    0x14, 3,    5,    5,    3,    8,    5,
    4,    0x14, 0x14, 4,    0x17, 0x14, 4,    0x16, 5,    4,    7,    5,    4,    5,    0x14, 4,    3,    0x14,
    2,    0x17, 5,    2,    1,    0x14, 2,    7,    0x14, 2,    0x16, 0x14, 2,    5,    5,    0x18, 1,    0x14,
    0x18, 3,    0x14, 7,    0x14, 5,    7,    0x16, 0x14, 7,    1,    5,    7,    2,    5,    7,    0x18, 0x14,
    7,    8,    5,    7,    3,    0x14, 5,    0x14, 0x14, 5,    1,    5,    5,    4,    5,    5,    2,    0x14,
    5,    7,    0x14, 5,    0x19, 0x14, 8,    0,    0,    8,    0x18, 0,    0x14, 0x1A, 5,    0x15, 0x1A, 5,
    0x17, 0x1A, 5,    0x16, 0x1A, 5,    0x19, 0x1A, 0x14, 0x1A, 0x1A, 0x14, 0xFF, 0,    0,
};
static u32 D_8438ADEC[] = {
    0x18191C2E,
    0x2F313839,
    0x40414243,
    0x4F525455,
};
static u32 D_8438ADFC[] = {
    0x1B000000,
};
static u32 D_8438AE00[] = {
    0x28290000,
};
static u32 D_8438AE04[] = {
    0x010A0B0C, 0x0D0E0F12, 0x13141516, 0x171A2032, 0x33343536, 0x373A3B3C, 0x3D3E3F00,
};
static u32 D_8438AE20[] = {
    0x03070810,
    0x1D1E2C30,
    0x4D510000,
};
static u32 D_8438AE2C[] = {
    0x03070810,
    0x111D1E27,
    0x28292B2C,
    0x2D301B00,
};
static s32 D_8438AE3C = 0x4D2;
static u32 D_8438AE40 = 0x1A85;
static u32 D_8438AE44 = 0x3039;
static u32 D_8438AE48 = 0x10932;
static u8 sHighCritMoves[] = { KARATE_CHOP, RAZOR_LEAF, CRABHAMMER, SLASH };

void func_8436F6D0(void) {
}

u8 Battle_Random(void) {
    u8 var_v1;
    s32 ret;

    var_v1 = (osGetCount() & 0xFF0) >> 4;

    while (var_v1 > 0) {
        D_8438AE3C = (D_8438AE3C * 0x41C64E6D) + 0x303B;
        if (D_8438AE40 & 1) {
            D_8438AE40 ^= 0x11020;
        }
        D_8438AE40 >>= 1;
        var_v1--;
    }

    ret = D_8438AE3C ^ D_8438AE40;
    return ret;
}

u8 Battle_RandomAccuracy(void) {
    u8 var_v1;
    s32 ret;

    var_v1 = (osGetCount() & 0xFF0) >> 4;

    while (var_v1 > 0) {
        D_8438AE44 = (D_8438AE44 * 0x41C64E6D) + 0x303B;
        if (D_8438AE48 & 1) {
            D_8438AE48 ^= 0x11020;
        }
        D_8438AE48 >>= 1;
        var_v1--;
    }
    ret = D_8438AE44 ^ D_8438AE48;
    return ret;
}

void func_8436F838(s32 arg0, s32 arg1) {
    TeamRoster* temp_a3;
    BattleMonRuntime* temp_a2_2;
    ActivePokemonState* temp_v1;
    s32 sp18;

    temp_v1 = &sActivePokemon[arg0]->state;
    temp_a2_2 = &sActivePokemon[arg1]->state.runtime;
    temp_a3 = sActivePokemon[arg0]->sessionTeams->teamMember[temp_v1->unk_2C];

    if (temp_a2_2->unk_0C == 0) {
        Text_SetStringToken(0x19, temp_a3->pokemonPicked[temp_v1->unk_18].unk_30);
        Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x21);
        return;
    }

    temp_v1->unk_28 = temp_a2_2->unk_0C;
    sp18 = (temp_a2_2->unk_0C * 0x19) / (temp_a2_2->unk_28 >> 2);

    Text_SetStringToken(0x19, temp_a3->pokemonPicked[temp_v1->unk_18].unk_30);

    if (sp18 >= 0x46) {
        Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x21);
    } else if (sp18 >= 0x28) {
        Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x22);
    } else if (sp18 >= 0xA) {
        Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x23);
    } else {
        Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x24);
    }
}

void Battle_ResetTransientRuntimeState(s32 arg0, s32 arg1) {
    BattleMonRuntime* sp1C = &sActivePokemon[arg0]->state.runtime;
    BattleMonRuntime* sp18 = &sActivePokemon[arg1]->state.runtime;

    func_8436F838(arg0, arg1);
    D_843C4DC2 = 0;
    D_843C4DB3 = 0;
    sp1C->moveCache.lastMove = 0;
    sp1C->unk_58 = 0;
    sp18->unk_58 = 0;
    sp1C->unk_4A = 0;
    sp1C->unk_4B = 0;
    sp1C->unk_4C = 0;
    sp1C->unk_4D = 0;
    sp1C->unk_4E = 0;
    sp1C->unk_52 = 0;
    sp1C->unk_57 = 0;
    sp1C->unk_56 = 0;
    sp18->unk_4C &= ~0x20;
    D_843C4DA3 = 1;
}

void func_8436FA80(ActivePokemon* active_pokemon) {
    ActivePokemonState* sp1C = &sActivePokemon[0]->state;
    ActivePokemonState* sp18 = &sActivePokemon[1]->state;
    BattleMonRuntime* temp_a1 = &sActivePokemon[0]->state.runtime;
    BattleMonRuntime* temp_a2 = &sActivePokemon[1]->state.runtime;
    s32 var_v0;

    if (active_pokemon == sActivePokemon[0]) {
        var_v0 = ((sp1C->unk_28 - temp_a2->unk_0C) * 0x19) / (temp_a2->unk_28 >> 2);
    } else {
        var_v0 = ((sp18->unk_28 - temp_a1->unk_0C) * 0x19) / (temp_a1->unk_28 >> 2);
    }

    if (var_v0 == 0) {
        Battle_QueueMessage(gBattleMessageQueues->unk_1C8, 0x25);
    } else if (var_v0 < 0x1E) {
        Battle_QueueMessage(gBattleMessageQueues->unk_1C8, 0x26);
    } else if (var_v0 < 0x46) {
        Battle_QueueMessage(gBattleMessageQueues->unk_1C8, 0x27);
    } else {
        Battle_QueueMessage(gBattleMessageQueues->unk_1C8, 0x28);
    }

    if (sp1C->unk_2D == 0x10) {
        Battle_QueueMessage(gBattleMessageQueues->unk_1C8, 0);
    }
}

void Battle_ApplyDamageRandomFactor(void) {
    s32 temp_v0;

    if (sBattleDamage >= 2) {
        temp_v0 = 0;
        while (temp_v0 < 0xD9) {
            temp_v0 = Battle_Random();
        }
        sBattleDamage = (sBattleDamage * temp_v0) / 255;
    }
}

u16 Battle_DetermineMoveOrder(ActivePokemon* pokemon, ActivePokemon* other_pokemon) {
    BattleMonRuntime* runtime = &pokemon->state.runtime;
    BattleMonRuntime* other_runtime = &other_pokemon->state.runtime;

    if (runtime->usedMove == QUICK_ATTACK) {
        if (other_runtime->usedMove != QUICK_ATTACK) {
            return 0;
        }
    } else if (other_runtime->usedMove == QUICK_ATTACK) {
        return 1;
    }

    if (runtime->usedMove == COUNTER) {
        if (other_runtime->usedMove != COUNTER) {
            return 1;
        }
    } else if (other_runtime->usedMove == COUNTER) {
        return 0;
    }

    if (other_runtime->speed < runtime->speed) {
        return 0;
    }

    if (runtime->speed < other_runtime->speed) {
        return 1;
    }

    if (Battle_Random() < 0x80) {
        return 0;
    }
    return 1;
}

s32 func_8436FD54(u8 lookup, u8* array, s32 array_length) {
    while (array_length--) {
        if (lookup == *array) {
            return 1;
        }
        array++;
    }

    return 0;
}

void Battle_SetActiveMoveFromSlotIndex(void) {
    D_843C5240[0].usedMove = D_843C5240[0].moves[D_843C4DC2];
}

s32 func_8436FDBC(void) {
    Battle_ExecuteMoveEffect();

    if (sBattleMoveFailed == 1) {
        return 0;
    }
    return 1;
}

void func_8436FDF4(s32 arg0, BattleMon* arg1) {
    u16 i;
    u16 spC;
    u16 spA;
    u16 tmp;
    u16 sp6;
    u16 temp_a0;

    switch (arg0) {
        case 1:
            spA = gSpeciesData[arg1->unk_24].baseHitPoints;
            spC = arg1->unk_14;
            break;

        case 2:
            spA = gSpeciesData[arg1->unk_24].baseAttack;
            spC = arg1->unk_16;
            break;

        case 3:
            spA = gSpeciesData[arg1->unk_24].baseDefense;
            spC = arg1->unk_18;
            break;

        case 4:
            spA = gSpeciesData[arg1->unk_24].baseSpeed;
            spC = arg1->unk_1A;
            break;

        case 5:
            spA = gSpeciesData[arg1->unk_24].baseSpecial;
            spC = arg1->unk_1C;
            break;
    }

    for (i = 1; i < 255; i++) {
        if (SQ(i) >= spC) {
            break;
        }
    }

    tmp = D_843C5240[0].unk_24;

    switch (arg0) {
        case 1:
            sp6 = ((tmp & 0x1000) >> 9) | ((tmp & 0x100) >> 6) | ((tmp & 0x10) >> 3) | (tmp & 1);
            break;

        case 2:
            sp6 = (tmp >> 0xC) & 0xF;
            break;

        case 3:
            sp6 = (tmp >> 8) & 0xF;
            break;

        case 4:
            sp6 = (tmp >> 4) & 0xF;
            break;

        case 5:
            sp6 = tmp & 0xF;
            break;
    }

    temp_a0 = ((((spA + sp6) * 2) + (i >> 2)) * arg1->unk_24) / 100;
    if (arg0 == 1) {
        temp_a0 += arg1->unk_24 + 0xA;
    } else {
        temp_a0 += 5;
    }

    if (temp_a0 >= 0x3E8) {
        temp_a0 = 0x3E7;
    }

    switch (arg0) {
        case 1:
            arg1->unk_26 = temp_a0;
            break;

        case 2:
            arg1->unk_28 = temp_a0;
            break;

        case 3:
            arg1->unk_2A = temp_a0;
            break;

        case 4:
            arg1->unk_2C = temp_a0;
            break;

        case 5:
            arg1->unk_2E = temp_a0;
            break;
    }
}

void func_84370090(BattleMon* arg0) {
    func_8436FDF4(0, arg0);
    func_8436FDF4(1, arg0);
    func_8436FDF4(2, arg0);
    func_8436FDF4(3, arg0);
    func_8436FDF4(4, arg0);
}

void func_843700F0(void) {
    sBattleDamage = 0;
    D_843C4DC6 = sBattleUser->moveCache.unk_02;
    if (D_843C4DC6) {
        if (sBattleUser->moveCache.unk_03 < 0x14) {
            D_843C4DCA = sBattleTarget->unk_2C;
            if (sBattleTarget->unk_4E & 4) {
                D_843C4DCA *= 2;
            }

            if (sBattleCritFlag != 0) {
                D_843C4DCA = sBattleTarget->unk_3A;
                D_843C4DC8 = sBattleUser->unk_38;
            } else {
                D_843C4DC8 = sBattleUser->unk_2A;
            }
        } else {
            D_843C4DCA = sBattleTarget->unk_30;
            if (sBattleTarget->unk_4E & 2) {
                D_843C4DCA *= 2;
            }

            if (sBattleCritFlag != 0) {
                D_843C4DCA = sBattleTarget->unk_3E;
                D_843C4DC8 = sBattleUser->unk_3E;
            } else {
                D_843C4DC8 = sBattleUser->unk_30;
            }
        }

        if (D_843C4DC8 & 0xFF00) {
            if (D_843C4DCA & 0xFF00) {
                D_843C4DC8 >>= 2;
                D_843C4DCA >>= 2;
                if (D_843C4DC8 == 0) {
                    D_843C4DC8 = 1;
                }
            }
        }

        D_843C4DCC = sBattleUser->unk_26;
        if (sBattleCritFlag != 0) {
            D_843C4DCC *= 2;
        }
    }
}

s32 Battle_CalcDamage(void) {
    s32 temp_v0 = sBattleUser->moveCache.unk_01;

    if (temp_v0 == 7) {
        D_843C4DCA >>= 1;
        if (D_843C4DCA == 0) {
            D_843C4DCA = 1;
        }
    }

    if ((temp_v0 != 0x1D) && (temp_v0 != 0x1E)) {
        if (temp_v0 == 0x26) {
            return func_8436FDBC();
        }

        if (D_843C4DC6 == 0) {
            return 0;
        }
    }

    sBattleDamage += (((((D_843C4DCC * 2) / 5) + 2) * D_843C4DC6 * D_843C4DC8) / D_843C4DCA) / 50;
    if (sBattleDamage > 0x3E4) {
        sBattleDamage = 0x3E4;
    }
    sBattleDamage += 2;

    return 1;
}

void Battle_ApplyDamage(void) {
    if (sBattleTarget->unk_4D & 0x10) {
        if (sBattleScene.unk_00->unk_48 == 0x14) {
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_208, 0x2B);
            if (sBattleTarget->unk_59 < sBattleDamage) {
                sBattleTarget->unk_4D &= 0xFFEF;
                Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
                Battle_QueueMessage(gBattleMessageQueues->unk_208, 0x2C);

                if ((D_8438AC60[0] == 1) && (sBattleUser->moveCache.unk_01 == 0x1D)) {
                    Battle_ExecuteMoveEffect();
                    sBattleUser->unk_4F = 1;
                }

                if ((D_8438AC60[0] != 1) || (sBattleUser->moveCache.unk_01 != 7)) {
                    sBattleUser->moveCache.unk_01 = 0;
                }

                Battle_SetRuntimeFlags(sActivePokemon[sBattleScene.unk_00->unk_2C], 0x1000);
            } else {
                sBattleTarget->unk_59 -= sBattleDamage;
            }
        } else {
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_208, 0x2B);
            if (sBattleTarget->unk_59 < sBattleDamage) {
                sBattleTarget->unk_4D &= 0xFFEF;
                Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
                Battle_QueueMessage(gBattleMessageQueues->unk_208, 0x2C);

                if ((D_8438AC60[0] == 1) && (sBattleUser->moveCache.unk_01 == 0x1D)) {
                    Battle_ExecuteMoveEffect();
                    sBattleUser->unk_4F = 1;
                }

                if ((D_8438AC60[0] != 1) || (sBattleUser->moveCache.unk_01 != 7)) {
                    sBattleUser->moveCache.unk_01 = 0;
                }

                Battle_SetRuntimeFlags(sActivePokemon[!sBattleScene.unk_00->unk_2C], 0x1000);
            } else {
                sBattleTarget->unk_59 -= sBattleDamage;
            }
        }
    } else if (D_84390288 == 0) {
        if (sBattleDamage < sBattleTarget->unk_0C) {
            sBattleTarget->unk_0C -= sBattleDamage;
        } else {
            sBattleDamage = sBattleTarget->unk_0C;
            sBattleTarget->unk_0C = 0;
        }
    }
}

void Battle_DecrementPP(s32 arg0) {
    BattleMonRuntime* temp_v0;
    ActivePokemonState* temp_a1;
    BattleMon* temp_a2;

    temp_v0 = &sActivePokemon[arg0]->state.runtime;
    temp_a1 = &sActivePokemon[arg0]->state;
    temp_a2 = &sActivePokemon[arg0]->unk_724->pokemonPicked[temp_a1->unk_08];

    if ((temp_v0->usedMove != 0xA5) && !(temp_v0->unk_4C & 7) && !(temp_v0->unk_4D & 0x40)) {
        temp_v0->unk_32[temp_a1->unk_0C]--;
        if (!(temp_v0->unk_4E & 8)) {
            temp_a2->unk_20[temp_a1->unk_0C] -= 1;
        }
    }
}

void func_84370790(void) {
    StatStageMultiplier* var_v0;
    s32 var_a2;
    s32 idx;
    s32 idx2;

    if (D_8438AC60[0] == 1) {
        var_v0 = D_8438ACD4;
    } else {
        var_v0 = gStatStageMultipliers;
    }

    idx = sBattleUser->unk_5C[4];
    idx2 = sBattleTarget->unk_5C[5];
    idx2 = 0xE - idx2;

    var_a2 = (sBattleUser->moveCache.unk_04 * var_v0[idx - 1].unk_00) / var_v0[idx - 1].unk_01;
    if (var_a2 == 0) {
        var_a2 = 1;
    }

    var_a2 = (var_a2 * var_v0[idx2 - 1].unk_00) / var_v0[idx2 - 1].unk_01;
    if (var_a2 == 0) {
        var_a2 = 1;
    }

    if (var_a2 >= 0x100) {
        var_a2 = 0xFF;
    }
    sBattleUser->moveCache.unk_04 = var_a2;
}

void func_843708A0(void) {
    sBattleDamage = 0;
    sBattleMoveFailed = 1;
    sBattleUser->unk_4C &= ~0x20;
}

void func_843708CC(void) {
    if (sBattleUser->moveCache.unk_01 == 0x50) {
        if (!(sBattleUser->unk_4D & 0x20) && (D_8438AC60[0] == 1)) {
            sBattleUser->unk_4D |= 0x20;
        }
    }

    if ((sBattleUser->moveCache.unk_01 == 8) && !(sBattleTarget->unk_15 & 7)) {
        func_843708A0();
        return;
    }

    if (sBattleTarget->unk_4D & 0x10) {
        if (sBattleUser->moveCache.unk_01 == 17) {
            return;
        }

        if (sBattleUser->moveCache.unk_01 == 3 || sBattleUser->moveCache.unk_01 == 8 ||
            ((D_8438AC60[0] == 1) && (func_8436FD54(sBattleUser->moveCache.unk_01, D_8438ACB0, 5) != 0))) {
            func_843708A0();
            return;
        }
    }

    if (sBattleTarget->unk_4C & 0x40) {
        if (sBattleUser->moveCache.unk_01 != 0x11) {
            func_843708A0();
        }
    } else {
        if ((((sBattleUser->moveCache.unk_01 >= 0x12) && (sBattleUser->moveCache.unk_01 < 0x1A)) ||
             ((sBattleUser->moveCache.unk_01 >= 0x3A) && (sBattleUser->moveCache.unk_01 < 0x42))) &&
            (sBattleTarget->unk_4D & 2)) {
            func_843708A0();
            return;
        }

        if (!(sBattleUser->unk_4D & 1)) {
            if ((D_8438AC60[0] != 1) || (sBattleUser->moveCache.unk_01 != 0x11)) {
                func_84370790();
            }

            D_843C4DA2 = Battle_RandomAccuracy();
            if (D_843C4DA2 == 0xFF) {
                D_843C4DA2 = Battle_RandomAccuracy();
            }

            if (D_843C4DA2 >= sBattleUser->moveCache.unk_04) {
                func_843708A0();
            }
        }
    }
}

void func_84370ADC(ActivePokemon* arg0) {
    BattleMon* ptr = &arg0->unk_724->pokemonPicked[arg0->state.unk_08];

    ptr->statusCondition = arg0->state.runtime.unk_15;
}

void func_84370B0C(ActivePokemon* arg0) {
    BattleMonRuntime* temp_v0 = &arg0->state.runtime;

    if (arg0->state.runtime.unk_15 & 0x40) {
        temp_v0->speed >>= 2;
        if (temp_v0->speed == 0) {
            temp_v0->speed = 1;
        }
    }
}

void func_84370B44(ActivePokemon* arg0) {
    BattleMonRuntime* temp_v0 = &arg0->state.runtime;

    if (arg0->state.runtime.unk_15 & 0x10) {
        temp_v0->unk_2A >>= 1;
        if (temp_v0->unk_2A == 0) {
            temp_v0->unk_2A = 1;
        }
    }
}

void func_84370B7C(ActivePokemon* arg0) {
    ActivePokemonState* sp28;
    BattleMonRuntime* sp24;
    BattleMon* sp34;
    s32 i;
    s32 j;

    sp28 = &arg0->state;
    sp24 = &arg0->state.runtime;
    sp34 = &arg0->sessionTeams->teamMember[sp28->unk_2C]->pokemonPicked[sp28->unk_18];

    sp24->unk_14 = sp28->unk_08;
    sp24->id = sp34->unk_00.unk_00;
    sp24->unk_0C = sp34->unk_02;
    sp24->unk_15 = sp34->statusCondition;
    sp24->unk_16[6] = sp34->unk_06;
    sp24->unk_16[7] = sp34->unk_07;
    sp24->unk_16[8] = sp34->unk_08;

    sp24->moves[0] = sp34->unk_09[0];
    sp24->moves[1] = sp34->unk_09[1];
    sp24->moves[2] = sp34->unk_09[2];
    sp24->moves[3] = sp34->unk_09[3];
    sp24->unk_24 = sp34->unk_1E;

    sp24->unk_32[0] = sp34->unk_20[0];
    sp24->unk_32[1] = sp34->unk_20[1];
    sp24->unk_32[2] = sp34->unk_20[2];
    sp24->unk_32[3] = sp34->unk_20[3];

    if ((sp34->unk_09[0] == 0) || (sp34->unk_09[0] >= 0xA6)) {
        sp24->unk_32[0] = 0;
    }

    if ((sp34->unk_09[1] == 0) || (sp34->unk_09[1] >= 0xA6)) {
        sp24->unk_32[1] = 0;
    }

    if ((sp34->unk_09[2] == 0) || (sp34->unk_09[2] >= 0xA6)) {
        sp24->unk_32[2] = 0;
    }

    if ((sp34->unk_09[3] == 0) || (sp34->unk_09[3] >= 0xA6)) {
        sp24->unk_32[3] = 0;
    }

    for (i = 0; i < 4; i++) {
        if (sp34->unk_09[i] == 0) {
            for (j = i; j < 4; j++) {
                sp24->unk_32[j] = 0;
                sp24->moves[j] = sp34->unk_09[j] = 0;
            }
            break;
        }
    }

    sp24->unk_26 = sp34->unk_24;
    sp24->unk_28 = sp34->unk_26;
    sp24->unk_2A = sp34->unk_28;
    sp24->unk_2C = sp34->unk_2A;
    sp24->speed = sp34->unk_2C;
    sp24->unk_30 = sp34->unk_2E;

    func_84370B0C(arg0);
    func_84370B44(arg0);

    sp24->unk_36 = gBaseStats[sp24->id].baseHP;
    sp24->unk_38 = sp34->unk_28;
    sp24->unk_3A = sp34->unk_2A;
    sp24->unk_3C = sp34->unk_2C;
    sp24->unk_3E = sp34->unk_2E;

    // clang-format off
    for (i = 0; i < 8; i++) { sp24->unk_5C[i] = 7; }
    // clang-format on
}

s32 Battle_IsPartyMemberAlive(ActivePokemon* arg0) {
    if (arg0->unk_724->pokemonPicked[arg0->state.unk_18 - 1].unk_02 != 0) {
        return 1;
    }
    return 0;
}

void func_84370E70(void) {
}

void func_84370E78(void) {
}

void func_84370E80(void) {
    sBattleUser->moveCache.lastMove = gMoveData[sBattleUser->usedMove - 1].unk_00;
    sBattleUser->moveCache.unk_01 = gMoveData[sBattleUser->usedMove - 1].unk_01;
    sBattleUser->moveCache.unk_02 = gMoveData[sBattleUser->usedMove - 1].unk_02;
    sBattleUser->moveCache.unk_03 = gMoveData[sBattleUser->usedMove - 1].unk_03;
    sBattleUser->moveCache.unk_04 = gMoveData[sBattleUser->usedMove - 1].unk_04;
    sBattleUser->moveCache.unk_05 = gMoveData[sBattleUser->usedMove - 1].unk_05;
}

void Battle_ApplyRageContinuation(void) {
    BattleMonRuntime* sp24;

    if ((sBattleTarget->unk_4D & 0x40) && ((sBattleTarget->unk_5C[0]) != 0xD)) {
        sp24 = sBattleUser;

        sBattleUser = sBattleTarget;
        sBattleUser->moveCache.lastMove = 0;
        sBattleUser->moveCache.unk_01 = 10;

        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_348, 0x1F);
        Battle_ApplyRageStatBoost();

        sBattleUser->moveCache.lastMove = 0x63;
        sBattleUser->moveCache.unk_01 = 0;

        sBattleUser = sp24;
    }
}

void func_84371010(void) {
    D_843C4DEC = D_843C4DB3 & 0x7F;
    if (D_843C4DEC >= 0xB) {
        Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x29);
    } else if (D_843C4DEC < 0xA) {
        Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x2A);
    }
}

void func_84371080(void) {
    BattleMonRuntime* sp1C = &sActivePokemon[!sBattleScene.unk_00->unk_2C]->state.runtime;

    switch (sBattleCritFlag) {
        case 1:
            Battle_QueueMessage(gBattleMessageQueues->unk_148, 0x1D);
            sBattleScene.unk_00->unk_1A = 2;
            break;
        case 2:
            Battle_QueueMessage(gBattleMessageQueues->unk_148, 0x1E);
            sBattleScene.unk_00->unk_1A = 2;
            break;
    }
    sp1C->unk_5B = sBattleCritFlag;
    sBattleCritFlag = 0;
}

void func_8437114C(void) {
    s32 var_s0;
    s32 temp_v0;

    switch (sBattleUser->moveCache.unk_01) {
        case 38:
            break;

        case 40:
            sBattleDamage = sBattleTarget->unk_0C / 2;
            if (sBattleDamage == 0) {
                sBattleDamage = 1;
            }
            break;

        case 41:
            switch (sBattleUser->moveCache.lastMove) {
                case 0x45:
                case 0x65:
                    var_s0 = sBattleUser->unk_26;
                    break;

                case 0x31:
                    var_s0 = 0x14;
                    break;

                case 0x52:
                    var_s0 = 0x28;
                    break;

                default:
                    var_s0 = sBattleUser->unk_26;
                    var_s0 = (var_s0 >> 1) + var_s0;
                    do {
                        do {
                            temp_v0 = Battle_Random();
                        } while (temp_v0 == 0);
                    } while (temp_v0 >= var_s0);
                    var_s0 = temp_v0;
            }
            sBattleDamage = var_s0;
            break;

        default:
            if (sBattleUser->moveCache.unk_02 != 0) {
                if (sBattleUser->unk_4C & 4) {
                    D_843C4DA0 += sBattleDamage;
                } else {
                    D_843C4DA0 = sBattleDamage;
                }
                break;
            }
            return;
    }

    if (sBattleDamage != 0) {
        Battle_ApplyDamage();
    }
}

void Battle_QueueMoveFailureAndApplyRecoil(void) {
    BattleMonRuntime* sp1C;

    if (D_843C4DB3 & 0x7F) {
        if (sBattleCritFlag == 0xFF) {
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x19);
        } else {
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x1A);
        }
    } else {
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x1B);
    }

    sBattleCritFlag = 0;

    if (sBattleUser->moveCache.unk_01 == 0x2D) {
        sBattleScene.unk_00->unk_48 = 0x10;
        sBattleDamage >>= 3;
        if (sBattleDamage == 0) {
            sBattleDamage++;
        }

        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x1C);

        sp1C = sBattleUser;
        sBattleUser = sBattleTarget;
        sBattleTarget = sp1C;
        sBattleScene.unk_00->unk_2C = !sBattleScene.unk_00->unk_2C;
        Battle_ApplyDamage();
        sBattleScene.unk_00->unk_2C = !sBattleScene.unk_00->unk_2C;
        sBattleTarget = sBattleUser;
        sBattleUser = sp1C;
    }
}

void func_843714D8(void) {
    BattleMonRuntime* ptr;
    BattleMon* temp_a0;
    ActivePokemonState* temp_a1;

    ptr = &sActivePokemon[sBattleScene.unk_00->unk_2C]->state.runtime;
    temp_a0 =
        &sActivePokemon[sBattleScene.unk_00->unk_2C]->unk_724->pokemonPicked[sActivePokemon[sBattleScene.unk_00->unk_2C]->state.unk_08];
    temp_a1 = &sActivePokemon[sBattleScene.unk_00->unk_2C]->state;

    sBattleUser->unk_32[temp_a1->unk_0C]++;
    if (!(ptr->unk_4E & 8)) {
        temp_a0->unk_20[temp_a1->unk_0C]++;
    }
}

s32 Battle_Effect_Metronome(void) {
    s32 move_pulled;

    func_843714D8();
    do {
        do {
            move_pulled = Battle_Random();
        } while (move_pulled == 0 || move_pulled >= 0xA5);
    } while (move_pulled == METRONOME);
    sBattleUser->usedMove = move_pulled;
    func_84370E80();
    return 1;
}

void Battle_ApplyPoisonOrBurnDamage(void) {
    u16 var_a0;

    if (sBattleUser->unk_12 != 0xFFFF) {
        sBattleUser->unk_0E = sBattleUser->unk_12;
    } else {
        sBattleUser->unk_0E = sBattleUser->unk_0C;
    }

    var_a0 = (sBattleUser->unk_28 >> 4) & 0xFFFF;
    if (var_a0 == 0) {
        var_a0++;
    }

    if (sBattleUser->unk_4E & 1) {
        sBattleUser->unk_51++;
        var_a0 *= sBattleUser->unk_51;
    }

    if (sBattleUser->unk_0E < var_a0) {
        sBattleUser->unk_0E = 0;
    } else {
        sBattleUser->unk_0E -= var_a0;
    }

    sBattleUser->unk_10 = sBattleUser->unk_0E;
}

void Battle_ApplyLeechSeedDamage(void) {
    u16 var_a0;

    if (!(sBattleUser->unk_15 & 0x18)) {
        if (sBattleUser->unk_12 != 0xFFFF) {
            sBattleUser->unk_10 = sBattleUser->unk_12;
        } else {
            sBattleUser->unk_10 = sBattleUser->unk_0C;
        }
    }

    var_a0 = (sBattleUser->unk_28 >> 4) & 0xFFFF;
    if (var_a0 == 0) {
        var_a0++;
    }

    if (sBattleUser->unk_4E & 1) {
        sBattleUser->unk_51++;
        var_a0 *= sBattleUser->unk_51;
    }

    if (sBattleUser->unk_10 < var_a0) {
        var_a0 = sBattleUser->unk_10;
        sBattleUser->unk_10 = 0;
    } else {
        sBattleUser->unk_10 -= var_a0;
    }

    sBattleTarget->unk_10 = sBattleTarget->unk_0C;
    sBattleTarget->unk_10 += var_a0;

    if (sBattleTarget->unk_28 < sBattleTarget->unk_10) {
        sBattleTarget->unk_10 = sBattleTarget->unk_28;
    }
}

s32 Battle_ApplyResidualEffects(void) {
    if (sBattleTarget->unk_0C == 0) {
        return 0;
    }

    if (sBattleUser->unk_15 & 0x18) {
        if (sBattleUser->unk_15 & 8) {
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_248, 0);
        } else {
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_248, 1);
        }
        Battle_ApplyPoisonOrBurnDamage();
        sBattleTarget->unk_0E = sBattleTarget->unk_0C;
    }

    if (sBattleUser->unk_4D & 0x80) {
        Battle_ApplyLeechSeedDamage();
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_288, 2);
    }

    if (sBattleUser->unk_0C != 0) {
        return 0;
    }
    return 1;
}

void func_843718DC(void) {
}

s32 Battle_TryLoadFollowupMoveFromTarget(void) {
    if ((sBattleTarget->unk_58 == 0x77) || (sBattleTarget->unk_58 == 0)) {
        gBattleMessageQueues->unk_388[0] = 0;
        gBattleMessageQueues->unk_388[1] = 0;
        sBattleScene.unk_00->unk_48 = 0x1C;
        Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x20);
        return 0;
    }

    sBattleUser->usedMove = sBattleTarget->unk_58;
    func_843714D8();
    func_84370E80();
    return 1;
}

void Battle_ApplyTypeEffectAndSTAB(void) {
    u8 var_v0;
    u8 var_v1;
    u8 temp_a0;
    u8 temp_a1;
    u8 temp_a3;
    u8 temp_t1;
    TypeEffectivenessEntry* var_a3;

    var_v0 = 3;

    temp_a1 = sBattleUser->unk_16[6];
    temp_a3 = sBattleUser->unk_16[7];

    var_v1 = sBattleTarget->unk_16[6];
    temp_a0 = sBattleTarget->unk_16[7];

    temp_t1 = sBattleUser->moveCache.unk_03;

    if ((D_8438AC60[0] != 1) || (sBattleUser->moveCache.lastMove != 0xA5)) {
        if ((temp_t1 == temp_a1) || (temp_t1 == temp_a3)) {
            sBattleDamage += sBattleDamage >> 1;
            D_843C4DB3 |= 0x80;
        }

        var_a3 = &sTypeEffects[0];
        while (var_a3->unk_00 != 0xFF) {
            if ((var_a3->unk_00 == temp_t1) && ((var_a3->unk_01 == var_v1) || (var_a3->unk_01 == temp_a0))) {
                if (var_a3->unk_02 != 0) {
                    if (var_a3->unk_02 >= 0xB) {
                        var_v0++;
                    } else {
                        var_v0--;
                    }
                }

                sBattleDamage = (sBattleDamage * var_a3->unk_02) / 10;

                if (sBattleDamage == 0) {
                    sBattleMoveFailed = 1;
                }
            }
            var_a3++;
        }

        switch (var_v0) {
            case 1:
            case 2:
                D_843C4DB3 = (D_843C4DB3 & 0x80) + 5;
                break;

            case 3:
                break;

            case 4:
            case 5:
                D_843C4DB3 = (D_843C4DB3 & 0x80) + 0x14;
                break;
        }
    }
}

s32 Battle_Effect_Counter(void) {
    if (sBattleUser->usedMove != 0x44) {
        return 1;
    }

    sBattleMoveFailed = 1;

    if (sBattleTarget->usedMove == 0x44) {
        return 0;
    }

    if (sBattleTarget->moveCache.unk_02 == 0) {
        return 0;
    }

    if ((sBattleTarget->moveCache.unk_03 == 0) || (sBattleTarget->moveCache.unk_03 == 1)) {
        if (sBattleDamage == 0) {
            return 0;
        }

        if (sBattleDamage >= 0x8000) {
            sBattleDamage = 0xFFFF;
        } else {
            sBattleDamage *= 2;
        }

        sBattleMoveFailed = 0;
        sBattleCritFlag = 0;
        func_843708CC();
        return 0;
    }
    return 0;
}

s32 Battle_CheckCriticalHit(void) {
    UNUSED s32 pad;
    s32 sp18;

    sBattleCritFlag = 0;
    if (D_8438AC60[0] == 1) {
        sp18 = (gBaseStats[sBattleUser->id].baseDefense + 0x4C) >> 2;
    } else {
        sp18 = gBaseStats[sBattleUser->id].baseDefense >> 1;
    }

    if (sBattleUser->moveCache.unk_02 == 0) {
        return 0;
    }

    if (D_8438AC60[0] == 1) {
        if (sBattleUser->unk_4D & 4) {
            sp18 = (sp18 * 4) + 0xA0;
        } else {
            sp18 *= 2;
        }

        if (func_8436FD54(sBattleUser->moveCache.lastMove, sHighCritMoves, 4) != 0) {
            sp18 *= 4;
        } else {
            sp18 >>= 1;
        }
    } else {
        if (sBattleUser->unk_4D & 4) {
            sp18 >>= 1;
        } else {
            sp18 *= 2;
            if (sp18 >= 0x100) {
                sp18 = 0xFF;
            }
        }

        if (func_8436FD54(sBattleUser->moveCache.lastMove, sHighCritMoves, 4) != 0) {
            sp18 *= 4;
            if (sp18 >= 0x100) {
                sp18 = 0xFF;
            }
        } else {
            sp18 >>= 1;
        }
    }

    if (sp18 >= 0x100) {
        sp18 = 0xFF;
    }

    if (sp18 <= 0) {
        sp18 = 1;
    }

    D_843C4DA2 = Battle_Random();
    if (D_843C4DA2 >= sp18) {
        return 0;
    }
    sBattleCritFlag = 1;
    return 1;
}

s32 Battle_CheckMonCanAct(void) {
    BattleMonRuntime* sp2C;
    ActivePokemonState* temp_v0;
    u16 sp26;
    u8 sp25;
    BattleMonRuntime* temp_v1;

    temp_v0 = &sActivePokemon[sBattleScene.unk_00->unk_2C]->state;
    temp_v1 = &sActivePokemon[sBattleScene.unk_00->unk_2C]->state.runtime;

    if (sBattleUser->unk_15 & 7) {
        sBattleUser->unk_15 = (sBattleUser->unk_15 & 7) - 1;
        if (temp_v1->unk_16[temp_v0->unk_08 + temp_v0->unk_2B * 3] != 0) {
            temp_v1->unk_16[temp_v0->unk_08 + temp_v0->unk_2B * 3]--;
        }

        if (sBattleUser->unk_15 != 0) {
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_088, 5);
            sBattleScene.unk_00->unk_48 = 0x11;
        } else {
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_088, 6);
            sBattleScene.unk_00->unk_48 = 0x11;
        }

        sBattleUser->unk_58 = 0;
        return 0;
    }

    if (sBattleUser->unk_15 & 0x20) {
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_088, 7);
        sBattleUser->unk_58 = 0;
        sBattleScene.unk_00->unk_48 = 0x11;
        return 0;
    }

    if (sBattleTarget->unk_4C & 0x20) {
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_088, 8);
        sBattleScene.unk_00->unk_48 = 0x11;
        return 0;
    }

    if (sBattleUser->unk_4C & 8) {
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_088, 9);
        sBattleUser->unk_4D &= 0xFFDF;
        sBattleUser->unk_4C &= 0xFFF7;
        sBattleScene.unk_00->unk_48 = 0x1C;
        return 0;
    }

    if (sBattleUser->unk_4D & 0x20) {
        sBattleUser->unk_4D &= ~0x20;
        if (D_8438AC60[0] == 1) {
            sBattleDamage = 0;
        }
        sBattleScene.unk_00->unk_48 = 0x11;
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_088, 0xA);
        return 0;
    }

    if (sBattleUser->unk_52 != 0) {
        sBattleUser->unk_52--;
        if (!(sBattleUser->unk_52 & 0xF)) {
            sBattleUser->unk_52 = 0;
            sBattleUser->unk_57 = 0;
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_388, 0xB);
        }
    }

    if (sBattleUser->unk_4C & 0x80) {
        sBattleUser->unk_50--;
        if (sBattleUser->unk_50 == 0) {
            sBattleUser->unk_4C &= 0xFF7F;
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_188, 0xC);
        } else {
            Battle_QueueMoveCategoryMessage();
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_188, 0xD);
            D_843C4DA2 = Battle_Random();
            if (D_843C4DA2 >= 0x80) {
                Battle_QueueMetronomeMoveMessage();
                sBattleScene.unk_00->unk_48 = 0x14;
                sBattleUser->unk_4C &= 0x80;
                Battle_QueueMessage(gBattleMessageQueues->unk_148, 0xE);

                sp26 = sBattleTarget->unk_2C;
                sBattleTarget->unk_2C = sBattleUser->unk_2C;
                sp25 = sBattleUser->moveCache.unk_01;
                sBattleUser->moveCache.unk_01 = 0;
                sBattleCritFlag = 0;
                sBattleUser->moveCache.unk_02 = 0x28;
                sBattleUser->moveCache.unk_03 = 0;
                func_843700F0();
                Battle_CalcDamage();
                sBattleUser->moveCache.unk_01 = sp25;
                sBattleTarget->unk_2C = sp26;

                sp2C = sBattleUser;
                sBattleUser = sBattleTarget;
                sBattleTarget = sp2C;
                Battle_ApplyDamage();
                sBattleTarget = sBattleUser;
                sBattleUser = sp2C;
                goto label1;
            }
        }
    }

    if ((sBattleUser->unk_57 != 0) && (sBattleUser->unk_57 == sBattleUser->usedMove)) {
        sBattleUser->unk_4C &= 0xFFEF;
        Text_SetStringToken(0x1D, gMoveDisplayInfo[sBattleUser->usedMove - 1].unk_04);
        Battle_QueueMessage(gBattleMessageQueues->unk_088, 0xF);
        sBattleScene.unk_00->unk_48 = 0x11;
        return 0;
    }

    if (sBattleUser->unk_15 & 0x40) {
        D_843C4DA2 = Battle_Random();
        if (D_843C4DA2 < 0x3F) {
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x10);
            sBattleScene.unk_00->unk_48 = 0x1F;
            sBattleDamage = 0;
        label1:
            sBattleUser->unk_4C &= 0xFF8C;
            return 0;
        }
    }

    if (sBattleUser->unk_4C & 1) {
        sBattleUser->moveCache.lastMove = 0;
        sBattleUser->unk_54 += sBattleDamage;
        sBattleUser->unk_4F -= 1;
        if (sBattleUser->unk_4F != 0) {
            sBattleScene.unk_00->unk_48 = 0x1B;
            return 0;
        }
        sBattleUser->unk_4C &= 0xFFFE;
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x11);
        sBattleUser->moveCache.unk_02 = 1;

        sBattleDamage = sBattleUser->unk_54 * 2;
        if (!sBattleDamage) {
            sBattleMoveFailed = 1;
        }

        if ((D_8438AC60[0] == 1) && (sBattleTarget->unk_4C & 0x40)) {
            sBattleMoveFailed = 1;
        }

        sBattleUser->unk_54 = 0;
        sBattleUser->moveCache.lastMove = 0x75;
        return 5;
    }

    if (sBattleUser->unk_4C & 2) {
        sBattleUser->moveCache.lastMove = 0x25;
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x12);
        sBattleUser->unk_4F -= 1;
        if (sBattleUser->unk_4F != 0) {
            return 4;
        }

        Battle_QueueMessage(gBattleMessageQueues->unk_188, -0x45);
        sBattleUser->unk_4C &= 0xFFFD;
        sBattleUser->unk_4C |= 0x80;
        sBattleUser->unk_50 = (Battle_Random() & 3) + 2;
        return 4;
    }

    if (sBattleUser->unk_4C & 0x20) {
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x13);
        sBattleUser->unk_4F -= 1;
        return 6;
    }

    if (sBattleUser->unk_4D & 0x40) {
        sBattleUser->moveCache.unk_01 = 0;
        return 3;
    }
    return 2;
}

#define PRINTF(x) ((void)(x))

void func_84372670(void) {
    s8 sp2C[12];

    if (sBattleUser->usedMove != 0xFF) {
        sBattleMoveFailed = 0;
        D_843C4DB5 = 0;
        D_843C4DA9 = 0;
        D_843C4DB3 = 0xA;
    
        switch (Battle_CheckMonCanAct()) {
            case 2:
                func_84370E80();
                if (sBattleUser->unk_4C & 0x10) {
                    sBattleUser->unk_4C &= ~(0x40 | 0x10);
                    Battle_SetRuntimeFlags(sActivePokemon[sBattleScene.unk_00->unk_2C], 8);
                } else {
            block_5:
                    switch (sBattleUser->moveCache.unk_01) {
                        case 0x27:
                        case 0x2B:
                            if (D_8438AC60[0] == 1) {
                                sBattleDamage = 0;
                            }
                
                            Battle_ExecuteMoveEffect();
                            sBattleUser->unk_58 = sBattleUser->usedMove;
                            return;
                    }
                }
            case 3:
                Battle_QueueMoveCategoryUsedMessage();
                Battle_DecrementPP(sBattleScene.unk_00->unk_2C);
                if (func_8436FD54(sBattleUser->moveCache.unk_01, D_8438ADEC, 0x10) != 0) {
                    if (D_8438AC60[0] == 1) {
                        sBattleDamage = 0;
                    }

                    Battle_ExecuteMoveEffect();
                    return;
                }

                if (func_8436FD54(sBattleUser->moveCache.unk_01, D_8438ADFC, 1) != 0) {
                    Battle_ExecuteMoveEffect();
                }
            case 4:
                if (func_8436FD54(sBattleUser->moveCache.unk_01, D_8438AE00, 2) == 0) {
                    Battle_CheckCriticalHit();
                    if (Battle_Effect_Counter() != 0) {
                        func_843700F0();
                        if (Battle_CalcDamage() == 0) {
                            goto block_29;
                        }
                        Battle_ApplyTypeEffectAndSTAB();
                        Battle_ApplyDamageRandomFactor();
                    } else {
                        goto block_24;
                    }
                }
                if (D_8438AC60[0] == 1) {
                    sBattleUser->moveCache.unk_04 = gMoveData[sBattleUser->usedMove - 1].unk_04;
                }

                func_843708CC();
            case 5:
            block_24:
                if (sBattleMoveFailed != 0) {
                    switch (sBattleUser->moveCache.unk_01) {
                        case 7:
                            goto block_28;
                        default:
                            goto block_28;
                    }
                }
            case 6:
            block_28:
            block_29:
                switch (sBattleUser->moveCache.unk_01) {
                    case 9:
                        if (Battle_TryLoadFollowupMoveFromTarget() == 0) {
                            break;
                        }
                        D_843C4DB5 = 0;
                        goto block_5;
                    case 0x53:
                        Battle_Effect_Metronome();
                        goto block_5;
                    default:
                        if (func_8436FD54(sBattleUser->moveCache.unk_01, D_8438AE04, 0x1B) != 0) {
                            Battle_ExecuteMoveEffect();
                            return;
                        }
        
                        if (sBattleMoveFailed != 0) {
                            Battle_QueueMoveFailureAndApplyRecoil();
            
                            if (sBattleUser->moveCache.unk_01 != 7) {
                                break;
                            }
                        } else {
                            func_8437114C();
                            func_84371080();
                            func_84371010();
                            D_843C4DA9 = 1;
                        }
                        if (func_8436FD54(sBattleUser->moveCache.unk_01, D_8438AE20, 0xA) != 0) {
                            Battle_ExecuteMoveEffect();
                        }
                        if (sBattleTarget->unk_0C == 0) {
                            if (D_8438AC60[0] != 1) {
                                return;
                            }
                            if (sBattleUser->moveCache.unk_01 != 0x50) {
                                return;
                            }
                            sBattleDamage = 0;
                            return;
                        }
                        Battle_ApplyRageContinuation();
                        if (sBattleUser->unk_4C & 4) {
                            sBattleUser->unk_4F--;
                            if (sBattleUser->unk_4F != 0) {
                                goto block_28;
                            }
                            sBattleUser->unk_4C &= ~4;
                            sprintf(sp2C, "%d", sBattleUser->unk_54);
                            // separate stubbed print
                            PRINTF(" SpAttackTbl6\n");
                            Text_SetNumberToken(2, sBattleUser->unk_54);
                            Battle_QueueMessage(gBattleMessageQueues->unk_3C8, 4);
                            sBattleScene.unk_00->unk_1A = 1;
                            sBattleUser->unk_54 = 0;
                            sBattleDamage = D_843C4DA0;
                        }
                        if (sBattleUser->moveCache.unk_01 == 0) {
                            break;
                        }
                        if (func_8436FD54(sBattleUser->moveCache.unk_01, D_8438AE2C, 0xF) != 0) {
                            break;
                        }
                        Battle_ExecuteMoveEffect();
                        break;
                }
                break;
            default:
                break;
        }
    }
    D_843C4DB7 = 0;
}

void Battle_HandleFaint(ActivePokemon* arg0) {
    s32 sp1C = BattleScene_GetParticipantSideIndex(arg0);
    ActivePokemonState* temp_a10;
    BattleMonRuntime* temp_a11;
    BattleMonRuntime* temp_a01;

    temp_a10 = &sActivePokemon[sp1C]->state;
    temp_a11 = &sActivePokemon[sp1C]->state.runtime;
    temp_a01 = &sActivePokemon[!sp1C]->state.runtime;

    temp_a01->unk_54 = 0;
    temp_a01->unk_58 = 0;
    temp_a01->unk_4C &= ~4;

    temp_a11->unk_4A = 0;
    temp_a11->unk_4B = 0;
    temp_a11->unk_4C = 0;
    temp_a11->unk_4D &= 0x80;
    temp_a11->unk_4E = 0;
    temp_a11->unk_52 = 0;
    temp_a11->unk_57 = 0;
    temp_a11->unk_56 = 0;
    temp_a11->unk_58 = 0;

    if (temp_a10->unk_2D != 0xF) {
        temp_a10->unk_2D = 0x11;
    }

    func_8436FA80(arg0);
    Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sp1C]));
    Battle_QueueMessage(gBattleMessageQueues->unk_448[sp1C], 3);
}

void func_84372C40(ActivePokemon* arg0) {
    ActivePokemonState* ptr1 = &arg0->state;
    BattleMon* temp_v0;
    s32 i;
    s32 var_s2 = 0;

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(arg0); i++) {
        if (i == ptr1->unk_08) {
            var_s2 += arg0->state.runtime.unk_0E;
        } else {
            temp_v0 = &arg0->unk_724->pokemonPicked[i];
            var_s2 += temp_v0->unk_02;
        }
    }

    if (arg0->sessionTeams->unk_01 == 2) {
        for (i = 0; i < BattleScene_GetOpposingSelectedSideTeamSize(arg0); i++) {
            temp_v0 = &arg0->sessionTeams->teamMember[!ptr1->unk_2B]->pokemonPicked[i];
            var_s2 += temp_v0->unk_02;
        }
    }

    if (var_s2 == 0) {
        func_8436FA80(arg0);
        ptr1->unk_2D = 0x12;
    } else {
        Battle_HandleFaint(arg0);
    }
}

void func_84372D88(ActivePokemon* arg0) {
    ActivePokemonState* ptr1 = &arg0->state;
    BattleMon* temp_v0;
    s32 i;
    s32 var_s2 = 0;

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(arg0); i++) {
        if (i == ptr1->unk_08) {
            var_s2 += arg0->state.runtime.unk_10;
        } else {
            temp_v0 = &arg0->unk_724->pokemonPicked[i];
            var_s2 += temp_v0->unk_02;
        }
    }

    if (arg0->sessionTeams->unk_01 == 2) {
        for (i = 0; i < BattleScene_GetOpposingSelectedSideTeamSize(arg0); i++) {
            temp_v0 = &arg0->sessionTeams->teamMember[!ptr1->unk_2B]->pokemonPicked[i];
            var_s2 += temp_v0->unk_02;
        }
    }

    if (var_s2 == 0) {
        func_8436FA80(arg0);
        ptr1->unk_2D = 0x12;
    } else {
        Battle_HandleFaint(arg0);
    }
}

void func_84372ED0(ActivePokemon* arg0) {
    ActivePokemonState* ptr1 = &arg0->state;
    BattleMon* temp_v0;
    s32 i;
    s32 var_s2 = 0;

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(arg0); i++) {
        if (i == ptr1->unk_08) {
            var_s2 += arg0->state.runtime.unk_12;
        } else {
            temp_v0 = &arg0->unk_724->pokemonPicked[i];
            var_s2 += temp_v0->unk_02;
        }
    }

    if (arg0->sessionTeams->unk_01 == 2) {
        for (i = 0; i < BattleScene_GetOpposingSelectedSideTeamSize(arg0); i++) {
            temp_v0 = &arg0->sessionTeams->teamMember[!ptr1->unk_2B]->pokemonPicked[i];
            var_s2 += temp_v0->unk_02;
        }
    }

    if (var_s2 == 0) {
        func_8436FA80(arg0);
        ptr1->unk_2D = 0x12;
    } else {
        Battle_HandleFaint(arg0);
    }
}

void func_84373018(ActivePokemon* arg0) {
    ActivePokemonState* ptr1 = &arg0->state;
    BattleMon* temp_v0;
    s32 i;
    s32 var_s2 = 0;

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(arg0); i++) {
        if (i == ptr1->unk_08) {
            var_s2 += arg0->state.runtime.unk_0C;
        } else {
            temp_v0 = &arg0->unk_724->pokemonPicked[i];
            var_s2 += temp_v0->unk_02;
        }
    }

    if (arg0->sessionTeams->unk_01 == 2) {
        for (i = 0; i < BattleScene_GetOpposingSelectedSideTeamSize(arg0); i++) {
            temp_v0 = &arg0->sessionTeams->teamMember[!ptr1->unk_2B]->pokemonPicked[i];
            var_s2 += temp_v0->unk_02;
        }
    }

    if (var_s2 == 0) {
        func_8436FA80(arg0);
        ptr1->unk_2D = 0x12;
    } else {
        Battle_HandleFaint(arg0);
    }
}

s32 Battle_CheckSideDefeatAfterResidualStatus(ActivePokemon* arg0) {
    ActivePokemonState* ptr1 = &arg0->state;
    BattleMon* temp_v0;
    s32 i;
    s32 var_s2;

    if (arg0->state.runtime.unk_15 & 0x18) {
        var_s2 = 0;
        if (arg0->state.runtime.unk_0E == 0) {
            for (i = 0; i < BattleScene_GetSelectedSideTeamSize(arg0); i++) {
                temp_v0 = &arg0->unk_724->pokemonPicked[i];
                var_s2 += temp_v0->unk_02;
            }

            if (arg0->sessionTeams->unk_01 == 2) {
                for (i = 0; i < BattleScene_GetOpposingSelectedSideTeamSize(arg0); i++) {
                    temp_v0 = &arg0->sessionTeams->teamMember[!ptr1->unk_2B]->pokemonPicked[i];
                    var_s2 += temp_v0->unk_02;
                }
            }

            if (var_s2 == 0) {
                ptr1->unk_2D = 0x12;
                return 1;
            }
            Battle_HandleFaint(arg0);
        }
        return 1;
    }
    return 0;
}

s32 Battle_CheckFaintAfterMove(void) {
    if (sBattleTarget->unk_0C == 0) {
        func_84373018(sActivePokemon[!sBattleScene.unk_00->unk_2C]);
    }

    if (sBattleUser->unk_0C == 0) {
        func_84373018(sActivePokemon[sBattleScene.unk_00->unk_2C]);
    }

    if ((sBattleUser->unk_0C != 0) && (sBattleTarget->unk_0C != 0) && (sBattleUser->unk_12 == 0)) {
        func_84372ED0(sActivePokemon[sBattleScene.unk_00->unk_2C]);
        return 0;
    } else if ((sBattleUser->unk_0C != 0) && (sBattleTarget->unk_0C != 0) && (sBattleUser->unk_15 & 0x18) &&
               (sBattleUser->unk_0E == 0)) {
        func_84372C40(sActivePokemon[sBattleScene.unk_00->unk_2C]);
        return 0;
    } else if ((sBattleUser->unk_0C != 0) && (sBattleTarget->unk_0C != 0) && (sBattleUser->unk_4D & 0x80) &&
               (sBattleUser->unk_10 == 0)) {
        func_84372D88(sActivePokemon[sBattleScene.unk_00->unk_2C]);
        return 0;
    }
}

void Battle_ResolveMonAction(void) {
    BattleMonRuntime* sp1C = &sActivePokemon[sBattleScene.unk_00->unk_2C]->state.runtime;
    BattleMonRuntime* sp18 = &sActivePokemon[!sBattleScene.unk_00->unk_2C]->state.runtime;
    ActivePokemonState* ptr1 = &sActivePokemon[0]->state;
    ActivePokemonState* ptr2 = &sActivePokemon[1]->state;

    ptr1->unk_2A = 0;
    ptr2->unk_2A = 0;

    sConfused = 1;
    D_843C4E45 = 1;

    sBattleScene.unk_00->unk_1A = 0;

    sBattleScene.unk_00->unk_4C = 0;
    sBattleScene.unk_00->unk_48 = 0;

    sp1C->unk_12 = 0xFFFF;
    sp18->unk_12 = 0xFFFF;

    D_843C4DA0 = 0;

    Battle_ClearAllMessageQueues();
    func_84370ADC(sActivePokemon[0]);
    func_84370ADC(sActivePokemon[1]);

    sBattleUser = sp1C;
    sBattleTarget = sp18;
    func_84372670();
    Battle_ApplyResidualEffects();

    if (D_84390288 == 0) {
        Battle_CheckFaintAfterMove();
    }
}

void func_84373570(ActivePokemon* arg0) {
    ActivePokemonState* sp24;
    ActivePokemonState* sp20;
    BattleMonRuntime* ptr1;
    BattleMonRuntime* ptr2;

    ptr1 = &arg0->state.runtime;

    sp24 = &sActivePokemon[0]->state;
    sp20 = &sActivePokemon[1]->state;

    ptr2 = &sActivePokemon[BattleScene_GetParticipantSideIndex(arg0) == 0]->state.runtime;

    sp24->unk_2A = 0;
    sp20->unk_2A = 0;
    ptr1->unk_12 = 0xFFFF;
    ptr2->unk_12 = 0xFFFF;

    sConfused = 1;
    D_843C4E45 = 1;

    sBattleScene.unk_00->unk_48 = 0;
    sBattleScene.unk_00->unk_4C = 0;

    sBattleUser = ptr1;
    sBattleTarget = ptr2;

    func_8436FA80(arg0);
    Vec3f_SetComponentsDuplicate(&arg0->swayState.unk_00, 0.0f, 0.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&arg0->swayState.unk_0C, 0.0f, 0.0f, 0.0f);
    func_84370B7C(arg0);

    if (arg0 == sActivePokemon[0]) {
        Battle_ResetTransientRuntimeState(0, 1);
    } else {
        Battle_ResetTransientRuntimeState(1, 0);
    }
}
