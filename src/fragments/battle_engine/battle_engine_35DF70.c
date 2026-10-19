#include "battle_engine.h"
#include "src/text_system.h"

typedef void (*func_D_8438AE50)(void);

static const char D_8438DC80[] = "は" "\n" "こんらんした";
static const char D_8438DC90[] = "SP %d\n";
static const char D_8438DC98[] = "index %d  step %d\n";
static const char D_8438DCAC[] = "index %d  step %d\n";
static const char D_8438DCC0[] = "index %d\n";
static const char D_8438DCCC[] = "paramStep %d index %d  step %d\n";
static const char D_8438DCEC[] = "\n%%%%%%%%%%%%%%%%%%%%%%%\n";
static const char D_8438DD08[] = "INDEX %d   WARIKOMI %d\n";
static const char D_8438DD20[] = "%%%%%%%%%%%%%%%%%%%%%%%\n\n";
static const char D_8438DD3C[] = "FAIL\n";
static const char D_8438DD44[] = "index %d\n";
static const char D_8438DD50[] = "index %d\n";
static const char D_8438DD5C[] = "FAIL\n";
static const char D_8438DD64[] = "FAIL2\n";
static const char D_8438DD6C[] = "FAIL3\n";
static const char D_8438DD74[] = "offp->count1 %d\n";
static const char D_8438DD88[] = "\n\n";
static const char D_8438DD8C[] = "******** spAttackMain ********\n";
static const char D_8438DDAC[] = "!!!! SPATTACK Num %d!!!!\n";
static const char D_8438DDC8[] = "******** spAttackMainEnd ********\n";

static char* D_8438AE50 = D_8438DC80;
static func_D_8438AE50 gMoveEffectHandlers[] = {
    Battle_Effect_Sleep, Battle_Effect_Poison, Battle_Effect_DrainHP, Battle_Effect_SecondaryStatusChance, Battle_Effect_SecondaryStatusChance, Battle_Effect_SecondaryStatusChance, Battle_Effect_Explosion,
    Battle_Effect_DrainHP, NULL,          Battle_Effect_RaiseOwnStat, Battle_Effect_RaiseOwnStat, Battle_Effect_RaiseOwnStat, Battle_Effect_RaiseOwnStat, Battle_Effect_RaiseOwnStat,
    Battle_Effect_RaiseOwnStat, Battle_Effect_PayDay, NULL,          Battle_Effect_LowerStat, Battle_Effect_LowerStat, Battle_Effect_LowerStat, Battle_Effect_LowerStat,
    Battle_Effect_LowerStat, Battle_Effect_LowerStat, Battle_Effect_Conversion, Battle_Effect_Haze, Battle_Effect_Bide, Battle_Effect_Thrash, Battle_Effect_ForceSwitchOrFlee,
    Battle_Effect_MultiHit, Battle_Effect_MultiHit, Battle_Effect_Flinch, Battle_Effect_Sleep, Battle_Effect_Poison, Battle_Effect_SecondaryStatusChance, Battle_Effect_SecondaryStatusChance,
    Battle_Effect_SecondaryStatusChance, Battle_Effect_Flinch, Battle_Effect_OHKO, Battle_Effect_TwoTurnMove, NULL,          NULL,          Battle_Effect_Trap,
    Battle_Effect_TwoTurnMove, Battle_Effect_MultiHit, NULL,          Battle_Effect_Mist, Battle_Effect_FocusEnergy, Battle_Effect_Recoil, Battle_Effect_Confuse,
    Battle_Effect_RaiseOwnStat, Battle_Effect_RaiseOwnStat, Battle_Effect_RaiseOwnStat, Battle_Effect_RaiseOwnStat, Battle_Effect_RaiseOwnStat, Battle_Effect_RaiseOwnStat, Battle_Effect_Heal,
    Battle_Effect_Transform, Battle_Effect_LowerStat, Battle_Effect_LowerStat, Battle_Effect_LowerStat, Battle_Effect_LowerStat, Battle_Effect_LowerStat, Battle_Effect_LowerStat,
    Battle_Effect_ReflectLightScreen, Battle_Effect_ReflectLightScreen, Battle_Effect_Poison, Battle_Effect_Paralyze, Battle_Effect_LowerStat, Battle_Effect_LowerStat, Battle_Effect_LowerStat,
    Battle_Effect_LowerStat, Battle_Effect_LowerStat, Battle_Effect_LowerStat, Battle_Effect_LowerStat, Battle_Effect_LowerStat, Battle_Effect_ConfuseChance, Battle_Effect_MultiHit,
    NULL,          Battle_Effect_Substitute, Battle_Effect_Recharge, Battle_Effect_Rage, Battle_Effect_Mimic, NULL,          Battle_Effect_LeechSeed,
    Battle_Effect_Splash, Battle_Effect_Disable, NULL,
};

u16 Battle_ApplyStatStageMultiplier(u16* arg0, u16 arg1, u8 arg2) {
    *arg0 = (arg1 * gStatStageMultipliers[arg2 - 1].unk_00) / gStatStageMultipliers[arg2 - 1].unk_01;

    if (*arg0 == 0) {
        *arg0 = 1;
    }

    if (*arg0 > 999) {
        *arg0 = 999;
    }

    return *arg0;
}

void Battle_Effect_Sleep(void) {
    s32 sp24;
    s32 var_v1;

    sBattleScene.unk_00->unk_48 = 0x16;
    sp24 = gBattleTarget->unk_4D & 0x20;
    gBattleTarget->unk_4D &= ~0x20;

    if (sp24 == 0) {
        if (gBattleTarget->unk_15 & 7) {
            D_843C4E44 = 0;
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x80);
            return;
        }

        if (gBattleTarget->unk_15 == 0) {
            func_843708CC();
            if ((sBattleMoveFailed == 0) &&
                ((Battle_HasUsableMajorStatusTarget(sActivePokemon[!sBattleScene.unk_00->unk_2C]) == 0) || (D_8438AC60[0] == 2))) {
                goto block_9;
            }
        }
        gBattleDamage = 0;
        sBattleMoveFailed = 1;
        D_843C4E44 = 0;
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x7F);
        return;
    }

block_9:
    if ((Battle_HasUsableMajorStatusTarget(sActivePokemon[!sBattleScene.unk_00->unk_2C]) != 0) && (D_8438AC60[0] != 2)) {
        D_843C4E44 = 0;
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x7F);
        if ((sp24 != 0) && (D_8438AC60[0] == 1)) {
            gBattleTarget->unk_4D |= 0x20;
        }
    } else {
        do {
            if (D_8438AC60[0] == 2) {
                var_v1 = Battle_Random() & 7;
            } else {
                var_v1 = Battle_Random() & 3;
            }
        } while (var_v1 == 0);
        sBattleMoveFailed = 0;
        gBattleTarget->unk_15 = var_v1;
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x7E);
    }
}

void Battle_Effect_Poison(void) {
    char* sp1C = gBattleMessageQueues->unk_088;

    if (!(gBattleTarget->unk_4D & 0x10) && (gBattleTarget->unk_15 == 0) && (gBattleTarget->unk_16[6] != 3) &&
        (gBattleTarget->unk_16[7] != 3)) {
        switch (gBattleUser->moveCache.unk_01) {
            case 2:
                if (sBattleScene.unk_00->unk_48 != 0x18) {
                    sBattleScene.unk_00->unk_48 = 0;
                    sp1C = gBattleMessageQueues->unk_208;
                } else {
                    sp1C = gBattleMessageQueues->unk_308;
                }

                if (Battle_Random() >= 0x34) {
                    return;
                }
                break;

            case 33:
                sBattleScene.unk_00->unk_48 = 0;
                sp1C = gBattleMessageQueues->unk_208;
                if (Battle_Random() >= 0x67) {
                    return;
                }
                break;

            default:
                sBattleScene.unk_00->unk_48 = 0x16;
                D_843C4DEC = 0xA;
                func_843708CC();
                if (sBattleMoveFailed != 0) {
                    Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
                    Battle_QueueMessage(sp1C, -0x7D);
                    return;
                }
                break;
        }

        gBattleTarget->unk_15 |= 8;
        if (gBattleUser->moveCache.lastMove == 0x5C) {
            gBattleTarget->unk_4E |= 1;
            gBattleTarget->unk_51 = 0;
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(sp1C, -0x7C);
        } else {
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(sp1C, -0x7B);
        }
    } else if (gBattleUser->moveCache.unk_01 == 0x42) {
        if (sBattleScene.unk_00->unk_48 != 0x18) {
            sBattleMoveFailed = 1;
            sBattleScene.unk_00->unk_48 = 0x16;
            D_843C4E44 = 0;
        }
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(sp1C, -0x7A);
    }
}

void Battle_Effect_DrainHP(void) {
    gBattleDamage /= 2;
    if (gBattleDamage == 0) {
        gBattleDamage = 1;
    }

    if (gBattleUser->unk_28 < gBattleUser->unk_0C + gBattleDamage) {
        gBattleUser->unk_0C = gBattleUser->unk_28;
    } else {
        gBattleUser->unk_0C += gBattleDamage;
    }

    if (gBattleUser->moveCache.unk_01 == 8) {
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_208, -0x79);
    } else {
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_208, -0x78);
    }
}

void Battle_Effect_Explosion(void) {
    sBattleScene.unk_00->unk_48 = 0x1E;
    gBattleUser->unk_0C = 0;
    gBattleUser->unk_15 = 0;
    gBattleUser->unk_4D &= ~0x80;
}

void Battle_Effect_SecondaryStatusChance(void) {
    BattleMonRuntime* temp_a2 = &sActivePokemon[!sBattleScene.unk_00->unk_2C]->state.runtime;
    ActivePokemonState* temp_a0 = &sActivePokemon[!sBattleScene.unk_00->unk_2C]->state;

    if (gBattleTarget->unk_4D & 0x10) {
        return;
    }

    if (gBattleTarget->unk_15 != 0) {
        if ((gBattleTarget->unk_15 & 0x20) && (gBattleUser->moveCache.unk_03 == 0x14)) {
            gBattleTarget->unk_15 = 0;
            if (temp_a0->unk_14 != 4) {
                temp_a2->usedMove = temp_a2->moves[temp_a0->unk_0C];
            } else {
                temp_a0->unk_14 = 0;
                temp_a0->unk_0C = 0;
                temp_a2->usedMove = 0xA5;
            }
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x77);
        }
        return;
    }

    if ((gBattleTarget->unk_16[6] != (*gBattleUser).moveCache.unk_03) &&
        (gBattleTarget->unk_16[7] != (*gBattleUser).moveCache.unk_03)) {
        if ((gBattleUser->moveCache.unk_01 < 7) || ((D_8438AC60[0] != 2) && (gBattleUser->moveCache.lastMove == 0x3B))) {
            if (Battle_Random() >= 0x1A) {
                return;
            }
        } else if (Battle_Random() >= 0x4D) {
            return;
        }

        switch (gBattleUser->moveCache.unk_01) {
            case 4:
            case 34:
                gBattleTarget->unk_15 = 0x10;
                func_84370B44(sActivePokemon[!sBattleScene.unk_00->unk_2C]);
                Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
                Battle_QueueMessage(gBattleMessageQueues->unk_208, -0x76);
                break;

            case 5:
            case 35:
                if (Battle_HasUsableSleepStatusTarget(sActivePokemon[!sBattleScene.unk_00->unk_2C]) == 0) {
                    gBattleTarget->unk_4D &= ~0x20;
                    gBattleTarget->unk_15 = 0x20;
                    Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
                    Battle_QueueMessage(gBattleMessageQueues->unk_208, -0x75);
                }
                break;

            case 6:
            case 36:
                gBattleTarget->unk_15 = 0x40;
                func_84370B0C(sActivePokemon[!sBattleScene.unk_00->unk_2C]);
                Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
                Battle_QueueMessage(gBattleMessageQueues->unk_208, -0x74);
                break;
        }
    }
}

void Battle_ApplyRageStatBoost(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 var_a3;
    u16* sp1C;
    u16* sp18;

    sBattleScene.unk_00->unk_4C = 0xA;

    var_a3 = 1;
    sp24 = gBattleUser->moveCache.unk_01 - 0xA;

    if (sp24 >= 8) {
        var_a3 = 2;
        sp24 -= 0x28;
    }

    if (gBattleUser->unk_5C[sp24] != 0xD) {
        gBattleUser->unk_5C[sp24] += var_a3;
        if (gBattleUser->unk_5C[sp24] >= 0xE) {
            gBattleUser->unk_5C[var_a3] = 0xD;
        }

        sp28 = 0;
        sp2C = 0;

        if (sp24 < 4) {
            switch (sp24) {
                case 0:
                    sp18 = &gBattleUser->unk_38;
                    sp1C = &gBattleUser->unk_2A;
                    sp2C = 1;
                    break;

                case 1:
                    sp18 = &gBattleUser->unk_3A;
                    sp1C = &gBattleUser->unk_2C;
                    break;

                case 2:
                    sp18 = &gBattleUser->unk_3C;
                    sp1C = &gBattleUser->unk_2E;
                    sp28 = 1;
                    break;

                case 3:
                    sp18 = &gBattleUser->unk_3E;
                    sp1C = &gBattleUser->unk_30;
                    break;
            }

            if (*sp1C != 0x3E7) {
                *sp1C = (*sp18 * gStatStageMultipliers[gBattleUser->unk_5C[sp24] - 1].unk_00) /
                        gStatStageMultipliers[gBattleUser->unk_5C[sp24] - 1].unk_01;
                if (*sp1C >= 0x3E8) {
                    *sp1C = 0x3E7;
                }
            } else {
                goto block_29;
            }
        }

        if (gBattleUser->moveCache.lastMove == 0x6B) {
            gBattleUser->unk_56 = 1;
        }

        if (var_a3 == 2) {
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_2C8, sp24 + 0x8D);
        } else {
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_2C8, sp24 + 0x93);
        }

        if ((sp28 != 0) || (D_8438AC60[0] != 1)) {
            func_84370B0C(sActivePokemon[!sBattleScene.unk_00->unk_2C]);
        }

        if ((sp2C != 0) || (D_8438AC60[0] != 1)) {
            func_84370B44(sActivePokemon[!sBattleScene.unk_00->unk_2C]);
        }
    } else {
    block_29:
        Battle_QueueMessage(gBattleMessageQueues->unk_2C8, -0x67);
    }
}

void Battle_Effect_RaiseOwnStat(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 var_a3;
    u16* sp1C;
    u16* sp18;

    if (gBattleUser->moveCache.lastMove == 0x6E) {
        sBattleScene.unk_00->unk_48 = 0x26;
    } else {
        sBattleScene.unk_00->unk_48 = 7;
    }

    var_a3 = 1;
    sp24 = gBattleUser->moveCache.unk_01 - 0xA;
    if (sp24 >= 8) {
        var_a3 = 2;
        sp24 -= 0x28;
    }

    if (gBattleUser->unk_5C[sp24] != 0xD) {
        gBattleUser->unk_5C[sp24] += var_a3;
        if (gBattleUser->unk_5C[sp24] >= 0xE) {
            gBattleUser->unk_5C[sp24] = 0xD;
        }

        sp28 = 0;
        sp2C = 0;

        if (sp24 < 4) {
            switch (sp24) {
                case 0:
                    sp18 = &gBattleUser->unk_38;
                    sp1C = &gBattleUser->unk_2A;
                    sp2C = 1;
                    break;

                case 1:
                    sp18 = &gBattleUser->unk_3A;
                    sp1C = &gBattleUser->unk_2C;
                    break;

                case 2:
                    sp18 = &gBattleUser->unk_3C;
                    sp1C = &gBattleUser->unk_2E;
                    sp28 = 1;
                    break;

                case 3:
                    sp18 = &gBattleUser->unk_3E;
                    sp1C = &gBattleUser->unk_30;
                    break;
            }

            if (*sp1C != 0x3E7) {
                *sp1C = (*sp18 * gStatStageMultipliers[gBattleUser->unk_5C[sp24] - 1].unk_00) /
                        gStatStageMultipliers[gBattleUser->unk_5C[sp24] - 1].unk_01;
                if (*sp1C >= 0x3E8) {
                    *sp1C = 0x3E7;
                }
            } else {
                goto block_32;
            }
        }

        if (gBattleUser->moveCache.lastMove == 0x6B) {
            gBattleUser->unk_56 = 1;
        }

        if (var_a3 == 2) {
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_088, sp24 + 0x8D);
        } else {
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_088, sp24 + 0x93);
        }

        if ((sp28 != 0) || (D_8438AC60[0] != 1)) {
            func_84370B0C(sActivePokemon[sBattleScene.unk_00->unk_2C]);
        }

        if ((sp2C != 0) || (D_8438AC60[0] != 1)) {
            func_84370B44(sActivePokemon[sBattleScene.unk_00->unk_2C]);
        }
    } else {
    block_32:
        D_843C4E45 = 0;
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x67);
    }
}

void Battle_Effect_LowerStat(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    u16* sp1C;
    u16* sp18;

    if (gBattleUser->moveCache.unk_01 < 0x44) {
        sBattleScene.unk_00->unk_48 = 0x1A;
    } else {
        sBattleScene.unk_00->unk_1A = 3;
    }

    if (gBattleTarget->unk_4D & 0x10) {
        goto end;
    }

    sp24 = gBattleUser->moveCache.unk_01;
    sp20 = 1;

    if (sp24 >= 0x44) {
        if (Battle_Random() < 0x55) {
            sp24 -= 0x44;
            goto block_14;
        }
    } else {
        func_843708CC();

        if (sBattleMoveFailed != 0) {
            goto end;
        }

        if (gBattleTarget->unk_4C & 0x40) {
            goto end;
        }

        sp24 -= 0x12;
        if (sp24 >= 9) {
            sp20 = 2;
            sp24 -= 0x28;
        }

    block_14:
        if (gBattleTarget->unk_5C[sp24] != 1) {
            gBattleTarget->unk_5C[sp24] -= sp20;
            if (gBattleTarget->unk_5C[sp24] <= 0) {
                gBattleTarget->unk_5C[sp24] = 1;
            }

            sp28 = 0;
            sp2C = 0;

            if (sp24 < 4) {
                switch (sp24) {
                    case 0:
                        sp2C = 1;
                        sp18 = &gBattleTarget->unk_38;
                        sp1C = &gBattleTarget->unk_2A;
                        break;

                    case 1:
                        sp18 = &gBattleTarget->unk_3A;
                        sp1C = &gBattleTarget->unk_2C;
                        break;

                    case 2:
                        sp28 = 1;
                        sp18 = &gBattleTarget->unk_3C;
                        sp1C = &gBattleTarget->unk_2E;
                        break;

                    case 3:
                        sp18 = &gBattleTarget->unk_3E;
                        sp1C = &gBattleTarget->unk_30;
                        break;
                }

                if (*sp1C != 1) {
                    *sp1C = (*sp18 * gStatStageMultipliers[gBattleTarget->unk_5C[sp24] - 1].unk_00) /
                            gStatStageMultipliers[gBattleTarget->unk_5C[sp24] - 1].unk_01;
                    if (*sp1C == 0) {
                        *sp1C = 1;
                    }
                } else {
                    goto block_39;
                }
            }

            if (sp20 == 2) {
                Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
                Battle_QueueMessage(gBattleMessageQueues->unk_208, sp24 + 0x9A);
            } else {
                Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
                Battle_QueueMessage(gBattleMessageQueues->unk_208, sp24 + 0xA0);
            }

            if ((sp28 != 0) || (D_8438AC60[0] != 1)) {
                func_84370B0C(sActivePokemon[!sBattleScene.unk_00->unk_2C]);
            }

            if ((sp2C != 0) || (D_8438AC60[0] != 1)) {
                func_84370B44(sActivePokemon[!sBattleScene.unk_00->unk_2C]);
            }
            return;
        }
    }

block_39:
    if (gBattleUser->moveCache.unk_01 < 0x44) {
        D_843C4E44 = 0;
        D_843C4E45 = 0;
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x5A);
        return;
    }

end:
    if (gBattleUser->moveCache.unk_01 < 0x44) {
        D_843C4E44 = 0;
        D_843C4E45 = 0;
        if (D_843C4DA9 == 0) {
            Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x59);
        }
    } else {
        D_843C4E45 = 0;
    }
}

void Battle_Effect_Bide(void) {
    sBattleScene.unk_00->unk_48 = 0x1B;
    gBattleUser->moveCache.unk_01 = 0;
    gBattleUser->unk_4C |= 1;
    gBattleUser->unk_54 = 0;
    gBattleUser->unk_4F = (Battle_Random() & 1) + 2;
}

void Battle_Effect_Thrash(void) {
    gBattleUser->moveCache.unk_01 = 0;
    gBattleUser->unk_4C |= 2;
    gBattleUser->unk_4F = (Battle_Random() & 1) + 2;
}

void Battle_Effect_ForceSwitchOrFlee(void) {
    if (gBattleUser->moveCache.lastMove == 0x64) {
        sBattleScene.unk_00->unk_48 = 0x27;
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x53);
        return;
    }
    sBattleScene.unk_00->unk_48 = 8;
    Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
    Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x52);
}

void Battle_Effect_MultiHit(void) {
    s32 var_v1;

    if (!(gBattleUser->unk_4C & 4)) {
        gBattleUser->unk_4C |= 4;

        switch (gBattleUser->moveCache.unk_01) {
            case 0x4D:
                gBattleUser->moveCache.unk_01 = 2;

            case 0x2C:
                gBattleUser->unk_54 = 2;
                gBattleUser->unk_4F = gBattleUser->unk_54;
                break;

            default:
                var_v1 = Battle_Random() & 3;
                if (var_v1 >= 2) {
                    var_v1 = Battle_Random() & 3;
                }
                gBattleUser->unk_4F = gBattleUser->unk_54 = var_v1 + 2;
                break;
        }

        D_8439022C = gBattleUser->unk_54 - 1;
        sBattleScene.unk_00->unk_48 = 0x18;
    }
}

void Battle_Effect_Flinch(void) {
    if (!(gBattleTarget->unk_4D & 0x10)) {
        if (D_8438AC60[0] == 1) {
            if (gBattleUser->moveCache.unk_01 == 0x1F) {
                if (Battle_Random() >= 0x1A) {
                    return;
                }
            } else if (Battle_Random() >= 0x4D) {
                return;
            }
        } else {
            gBattleTarget->unk_4D &= ~0x20;
            if (gBattleUser->moveCache.unk_01 == 0x1F) {
                if (Battle_Random() >= 0x1A) {
                    return;
                }
            } else if (Battle_Random() >= 0x4D) {
                return;
            }
        }
        gBattleTarget->unk_4C |= 8;
    }
}

void Battle_Effect_OHKO(void) {
    gBattleDamage = 0;
    sBattleCritFlag = 0xFF;
    if (gBattleUser->unk_2E < gBattleTarget->unk_2E) {
        sBattleMoveFailed = 1;
        return;
    }
    gBattleDamage = 0xFFFF;
    sBattleCritFlag = 2;
}

void Battle_Effect_TwoTurnMove(void) {
    sBattleScene.unk_00->unk_48 = 0xE;
    gBattleUser->unk_4C |= 0x10;

    if ((gBattleUser->moveCache.unk_01 == 0x2B) || (gBattleUser->moveCache.lastMove == 0x5B)) {
        gBattleUser->unk_4C |= 0x40;
        if (gBattleUser->moveCache.lastMove == 0x5B) {
            sBattleScene.unk_00->unk_48 = 0xD;
        }

        if (gBattleUser->moveCache.unk_01 == 0x2B) {
            sBattleScene.unk_00->unk_48 = 0xC;
        }
    }

    Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));

    switch (gBattleUser->moveCache.lastMove) {
        case 0xD:
            Battle_QueueMessage(gBattleMessageQueues->unk_0C8, -0x51);
            break;

        case 0x4C:
            Battle_QueueMessage(gBattleMessageQueues->unk_0C8, -0x50);
            break;

        case 0x82:
            Battle_QueueMessage(gBattleMessageQueues->unk_0C8, -0x4F);
            break;

        case 0x8F:
            Battle_QueueMessage(gBattleMessageQueues->unk_0C8, -0x4E);
            break;

        case 0x13:
            Battle_QueueMessage(gBattleMessageQueues->unk_148, -0x4D);
            break;

        case 0x5B:
            Battle_QueueMessage(gBattleMessageQueues->unk_148, -0x4C);
            break;
    }
}

void Battle_Effect_Trap(void) {
    s32 var_v1;

    if (!(gBattleUser->unk_4C & 0x20) && ((D_8438AC60[0] != 1) || (gBattleUser->moveCache.unk_03 != 0) ||
                                         ((gBattleTarget->unk_16[6] != 8) && (gBattleTarget->unk_16[7] != 8)))) {
        gBattleTarget->unk_4D &= 0xFFDF;
        gBattleUser->unk_4C |= 0x20;
        var_v1 = Battle_Random() & 3;
        if (var_v1 >= 2) {
            var_v1 = Battle_Random() & 3;
        }
        gBattleUser->unk_4F = var_v1 + 1;
    }
}

void Battle_Effect_Mist(void) {
    if (gBattleUser->unk_4D & 2) {
        sBattleScene.unk_00->unk_48 = 7;
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x4B);
        return;
    }
    sBattleScene.unk_00->unk_48 = 7;
    gBattleUser->unk_4D |= 2;
    Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
    Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x4A);
}

void Battle_Effect_FocusEnergy(void) {
    sBattleScene.unk_00->unk_48 = 7;
    if (gBattleUser->unk_4D & 4) {
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x49);
        return;
    }
    gBattleUser->unk_4D |= 4;
    Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
    Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x48);
}

void Battle_Effect_Recoil(void) {
    s32 var_v1;

    gBattleUser->unk_12 = gBattleUser->unk_0C;

    if (gBattleUser->moveCache.lastMove == 0xA5) {
        var_v1 = gBattleDamage >> 1;
    } else {
        var_v1 = gBattleDamage >> 2;
    }

    if (var_v1 == 0) {
        var_v1 += 1;
    }

    if (gBattleUser->unk_12 < var_v1) {
        gBattleUser->unk_12 = 0;
    } else {
        gBattleUser->unk_12 -= var_v1;
    }

    gBattleTarget->unk_12 = gBattleTarget->unk_0C;
    Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
    Battle_QueueMessage(gBattleMessageQueues->unk_408, -0x47);
    sBattleScene.unk_00->unk_48 = 9;
}

void Battle_Effect_ConfuseChance(void) {
    if (!(gBattleTarget->unk_4D & 0x10) && (Battle_Random() < 0x1A) && !(gBattleTarget->unk_4C & 0x80)) {
        sBattleScene.unk_00->unk_1A = 3;
        D_843C4E45 = 0;
        gBattleTarget->unk_4C |= 0x80;
        gBattleTarget->unk_50 = (Battle_Random() & 3) + 2;
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_208, -0x46);
    }
}

void Battle_Effect_Confuse(void) {
    sBattleScene.unk_00->unk_48 = 0x16;
    D_843C4E44 = 0;

    if (!(gBattleTarget->unk_4D & 0x10)) {
        func_843708CC();
        if ((sBattleMoveFailed == 0) && !(gBattleTarget->unk_4C & 0x80)) {
            D_843C4E44 = 1;
            gBattleTarget->unk_4C |= 0x80;
            gBattleTarget->unk_50 = (Battle_Random() & 3) + 2;
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x45);
            return;
        }
    }

    if (D_843C4DA9 == 0) {
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x44);
    }
}

void Battle_Effect_Paralyze(void) {
    sBattleScene.unk_00->unk_48 = 0x16;
    if (gBattleTarget->unk_15 == 0) {
        if ((gBattleUser->moveCache.unk_03 != 0x17) || ((gBattleTarget->unk_16[6] != 4) && (gBattleTarget->unk_16[7] != 4))) {
            func_843708CC();
            if (sBattleMoveFailed == 0) {
                gBattleTarget->unk_15 |= 0x40;
                func_84370B0C(sActivePokemon[!sBattleScene.unk_00->unk_2C]);
                Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
                Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x43);
                return;
            }
        } else {
            sBattleScene.unk_00->unk_48 = 8;
            D_843C4E44 = 0;
            Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x42);
            return;
        }
    }

    sBattleScene.unk_00->unk_48 = 8;
    D_843C4E44 = 0;
    Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
    Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x41);
}

void Battle_Effect_Substitute(void) {
    s32 temp_v1;

    sBattleScene.unk_00->unk_48 = 0x1C;
    if (gBattleUser->unk_4D & 0x10) {
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x2A);
        return;
    }

    temp_v1 = gBattleUser->unk_28 >> 2;
    if (temp_v1 >= gBattleUser->unk_0C) {
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x29);
        return;
    }

    sBattleScene.unk_00->unk_48 = 0x19;
    gBattleUser->unk_59 = temp_v1;
    gBattleUser->unk_0C -= temp_v1;
    gBattleUser->unk_4D |= 0x10;
    Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
    Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x28);
}

void Battle_Effect_Recharge(void) {
    gBattleUser->unk_4D |= 0x20;
}

void Battle_Effect_Rage(void) {
    gBattleUser->unk_4D |= 0x40;
}

void Battle_Effect_Mimic(void) {
    ActivePokemonState* sp24 = &sActivePokemon[sBattleScene.unk_00->unk_2C]->state;
    s32 var_t0;
    u8 temp_v0;

    sBattleScene.unk_00->unk_48 = 7;
    func_843708CC();

    if ((sBattleMoveFailed == 0) && !(gBattleTarget->unk_4C & 0x40)) {
        D_843C4DAA = 1;
        do {
            var_t0 = BattleAnim_RandomRange(4);
            if (var_t0 >= 4) {
                var_t0 = 3;
            }
            temp_v0 = gBattleTarget->moves[var_t0];
        } while (temp_v0 == 0);

        gBattleUser->moves[sp24->unk_0C] = temp_v0;
        Text_SetStringToken(0x1E, Text_GetString(NULL, 0, sMoveNameTable, gBattleTarget->moves[var_t0] - 1));
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x40);
        return;
    }

    Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x3F);
}

void Battle_Effect_LeechSeed(void) {
    func_843708CC();

    if ((sBattleMoveFailed == 0) && (gBattleTarget->unk_16[6] != 0x16) && (gBattleTarget->unk_16[7] != 0x16)) {
        if (!(gBattleTarget->unk_4D & 0x80)) {
            gBattleTarget->unk_4D |= 0x80;
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x3E);
            return;
        }
    }

    sBattleScene.unk_00->unk_48 = 8;
    Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
    Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x3D);
}

void Battle_Effect_Splash(void) {
    sBattleScene.unk_00->unk_48 = 7;
    Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x3C);
}

void Battle_Effect_Disable(void) {
    s32 sp24;
    s32 temp_v1;

    func_843708CC();

    if (sBattleMoveFailed == 0) {
        sBattleScene.unk_00->unk_48 = 0x20;
        if (gBattleTarget->unk_52 == 0) {
            do {
                sp24 = Battle_Random() & 3;
            } while (gBattleTarget->moves[sp24] == 0);
            temp_v1 = (Battle_Random() & 7) + 1;
            gBattleTarget->unk_52 = (sp24 * 0x10) + temp_v1;
            gBattleTarget->unk_57 = gBattleTarget->moves[sp24];
            Text_SetStringToken(0x1E, Text_GetString(NULL, 0, sMoveNameTable, gBattleTarget->unk_57 - 1));
            Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x3B);
            return;
        }
    }

    sBattleScene.unk_00->unk_48 = 8;
    Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x3A);
}

void Battle_Effect_PayDay(void) {
    Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x39);
}

void Battle_Effect_Conversion(void) {
    sBattleScene.unk_00->unk_48 = 7;
    if (!(gBattleTarget->unk_4C & 0x40)) {
        gBattleUser->unk_16[6] = gBattleTarget->unk_16[6];
        gBattleUser->unk_16[7] = gBattleTarget->unk_16[7];
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x38);
    } else {
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x37);
    }
}

void Battle_Effect_Haze(void) {
    s32 i;
    BattleMonRuntime* temp_t0 = &sActivePokemon[0]->state.runtime;
    BattleMonRuntime* temp_a3 = &sActivePokemon[1]->state.runtime;

    sBattleScene.unk_00->unk_48 = 0x1D;

    for (i = 0; i < 8; i++) {
        temp_t0->unk_5C[i] = 7;
        temp_a3->unk_5C[i] = 7;
    }

    temp_t0->unk_2A = temp_t0->unk_38;
    temp_t0->unk_2C = temp_t0->unk_3A;
    temp_t0->unk_2E = temp_t0->unk_3C;
    temp_t0->unk_30 = temp_t0->unk_3E;
    temp_a3->unk_2A = temp_a3->unk_38;
    temp_a3->unk_2C = temp_a3->unk_3A;
    temp_a3->unk_2E = temp_a3->unk_3C;
    temp_a3->unk_30 = temp_a3->unk_3E;

    if ((gBattleTarget->unk_15 & 0x27) && !(gBattleTarget->unk_4C & 0x10)) {
        gBattleTarget->usedMove = 0xFE;
    }

    gBattleTarget->unk_15 = 0;
    // clang-format off
    if (D_8438AC60[0] == 1) { gBattleUser->unk_15 = 0; }
    // clang-format on

    temp_t0->unk_52 = temp_a3->unk_52 = 0;
    temp_t0->unk_57 = temp_a3->unk_57 = 0;
    temp_t0->unk_4C &= ~0x80;
    temp_t0->unk_4D &= 0x78;
    temp_t0->unk_4E &= 8;
    temp_a3->unk_4C &= ~0x80;
    temp_a3->unk_4D &= 0x78;
    temp_a3->unk_4E &= 8;
    gBattleUser->unk_56 = 0;
    gBattleTarget->unk_56 = 0;

    Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x36);
}

void Battle_Effect_Heal(void) {
    u8 temp_v0;
    ActivePokemonState* temp_a1;
    BattleMonRuntime* temp_a2;

    temp_a1 = &sActivePokemon[sBattleScene.unk_00->unk_2C]->state;
    temp_a2 = &sActivePokemon[sBattleScene.unk_00->unk_2C]->state.runtime;

    sBattleScene.unk_00->unk_48 = 0x15;
    if (gBattleUser->unk_0C != gBattleUser->unk_28) {
        if (gBattleUser->moveCache.lastMove == 0x9C) {
            temp_v0 = gBattleUser->unk_15;

            gBattleUser->unk_15 = 2;
            temp_a2->unk_16[temp_a1->unk_08 + temp_a1->unk_2B * 3] = 2;

            if (temp_v0 != 0) {
                if (D_8438AC60[0] == 1) {
                    gBattleUser->unk_4E &= ~1;
                    Battle_ApplyStatStageMultiplier(&gBattleUser->unk_2A, gBattleUser->unk_38, gBattleUser->unk_5C[0]);
                    Battle_ApplyStatStageMultiplier(&gBattleUser->unk_2E, gBattleUser->unk_3C, gBattleUser->unk_5C[2]);
                }
                Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
                Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x35);
            } else {
                Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
                Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x34);
            }
            gBattleUser->unk_0C += gBattleUser->unk_28;
        } else {
            gBattleUser->unk_0C += gBattleUser->unk_28 / 2;
        }

        if (gBattleUser->unk_28 < gBattleUser->unk_0C) {
            gBattleUser->unk_0C = gBattleUser->unk_28;
        }

        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_148, -0x33);
        return;
    }

    sBattleScene.unk_00->unk_48 = 0x1C;
    sBattleMoveFailed = 1;
    Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x32);
}

void Battle_Effect_Transform(void) {
    s32 i;
    ActivePokemonState* sp20;
    ActivePokemonState* sp1C;
    BattleMonRuntime* ptr;

    sp20 = &sActivePokemon[sBattleScene.unk_00->unk_2C]->state;
    sp1C = &sActivePokemon[!sBattleScene.unk_00->unk_2C]->state;

    if ((D_8438AC60[0] == 1) && ((((gBattleTarget->unk_4E & 8) == 0) && (gBattleTarget->id == 0x84)) ||
                                 (((gBattleTarget->unk_4E & 8) != 0) && (sp1C->unk_BE == 0x84)))) {
        sBattleScene.unk_00->unk_48 = 0x1C;
        Text_SetStringToken(0x1B, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x2F);
        return;
    }

    ptr = gBattleUser;
    if (!(ptr->unk_4C & 0x40) &&
        ((D_8438AC60[0] != 1) || (gBattleTarget->moves[0] != 0x90) || (gBattleTarget->moves[1] != 0))) {
        sBattleScene.unk_00->unk_48 = 0xF;
        Text_SetStringToken(0x1B, Battle_GetActiveMonNickname(sActivePokemon[!sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_148, -0x31);
        gBattleUser->unk_4E |= 8;

        if (gBattleTarget->unk_4E & 8) {
            sp20->unk_BE = sp1C->unk_BE;
        } else {
            sp20->unk_BE = gBattleTarget->id;
        }

        gBattleUser->unk_16[6] = gBattleTarget->unk_16[6];
        gBattleUser->unk_16[7] = gBattleTarget->unk_16[7];
        gBattleUser->moves[0] = gBattleTarget->moves[0];
        gBattleUser->moves[1] = gBattleTarget->moves[1];
        gBattleUser->moves[2] = gBattleTarget->moves[2];
        gBattleUser->moves[3] = gBattleTarget->moves[3];
        gBattleUser->unk_24 = gBattleTarget->unk_24;
        gBattleUser->unk_2A = gBattleTarget->unk_2A;
        gBattleUser->unk_2C = gBattleTarget->unk_2C;
        gBattleUser->unk_2E = gBattleTarget->unk_2E;
        gBattleUser->unk_30 = gBattleTarget->unk_30;

        for (i = 0; i < 4; i++) {
            if (gBattleTarget->moves[i] == 0) {
                break;
            }
            gBattleUser->unk_32[i] = 5;
        }

        gBattleUser->unk_38 = gBattleTarget->unk_38;
        gBattleUser->unk_3A = gBattleTarget->unk_3A;
        gBattleUser->unk_3C = gBattleTarget->unk_3C;
        gBattleUser->unk_3E = gBattleTarget->unk_3E;

        for (i = 0; i < 8; i++) {
            gBattleUser->unk_5C[i] = gBattleTarget->unk_5C[i];
        }
        return;
    }

    sBattleScene.unk_00->unk_48 = 0x1C;
    Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x30);
}

void Battle_Effect_ReflectLightScreen(void) {
    sBattleScene.unk_00->unk_48 = 7;
    if (gBattleUser->moveCache.unk_01 == 0x40) {
        if (!(gBattleUser->unk_4E & 2)) {
            gBattleUser->unk_4E |= 2;
            Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
            Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x2E);
        } else {
            Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x2D);
        }
    } else if (!(gBattleUser->unk_4E & 4)) {
        gBattleUser->unk_4E |= 4;
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[sBattleScene.unk_00->unk_2C]));
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x2C);
    } else {
        Battle_QueueMessage(gBattleMessageQueues->unk_088, -0x2B);
    }
}

void Battle_RunMoveEffect(void) {
    BattleMonRuntime* ptr = &sActivePokemon[sBattleScene.unk_00->unk_2C]->state.runtime;
    s32 idx = ptr->moveCache.unk_01;

    if (gMoveEffectHandlers[idx - 1] != NULL) {
        gMoveEffectHandlers[idx - 1]();
    }
}

void Battle_ExecuteMoveEffect(void) {
    Battle_RunMoveEffect();
}
