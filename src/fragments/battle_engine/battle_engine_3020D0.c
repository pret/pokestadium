#include "battle_engine.h"
#include "src/graphics_textures.h"
#include "src/ui_graphics.h"
#include "src/status_icons.h"
#include "src/game_state.h"
#include "src/text_system.h"
#include "src/3D140.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/matrix.h"
#include "src/controller.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "stdarg.h"

unk_D_843901A0* gBattleMessageQueues;

static u8 D_84385990[] = { 0xE, 0x4A };
static u8 D_84385994[] = { 0x60, 0x69, 0x75, 0x78, 0x85 };
static u8 D_8438599C[] = { 0x61, 0x64, 0x66, 0x68, 0x8C };
static u8 D_843859A4[] = {
    1,    0xA,  0xB,  0x11, 0x13, 0x14, 0x15, 0x1E, 0x22, 0x23, 0x25, 0x27, 0x2B, 0x2C, 0x2D, 0x2E,
    0x2F, 0x40, 0x44, 0x46, 0x47, 0x51, 0x59, 0x5A, 0x5B, 0x5C, 0x67, 0x6A, 0x6B, 0x6E, 0x6F, 0x76,
    0x7A, 0x80, 0x84, 0x8B, 0x8D, 0x91, 0x94, 0x96, 0x97, 0x9A, 0x9C, 0x9F, 0xA3, 0xA4,
};

void Battle_ClearAllMessageQueues(void) {
    gBattleMessageQueues->unk_088[0] = 0;
    gBattleMessageQueues->unk_088[1] = 0;
    gBattleMessageQueues->unk_0C8[0] = 0;
    gBattleMessageQueues->unk_0C8[1] = 0;
    gBattleMessageQueues->unk_108[0] = 0;
    gBattleMessageQueues->unk_108[1] = 0;
    gBattleMessageQueues->unk_148[0] = 0;
    gBattleMessageQueues->unk_148[1] = 0;
    gBattleMessageQueues->unk_188[0] = 0;
    gBattleMessageQueues->unk_188[1] = 0;
    gBattleMessageQueues->unk_1C8[0] = 0;
    gBattleMessageQueues->unk_1C8[1] = 0;
    gBattleMessageQueues->unk_448[0][0] = 0;
    gBattleMessageQueues->unk_448[0][1] = 0;
    gBattleMessageQueues->unk_448[1][0] = 0;
    gBattleMessageQueues->unk_448[1][1] = 0;
    gBattleMessageQueues->unk_208[0] = 0;
    gBattleMessageQueues->unk_208[1] = 0;
    gBattleMessageQueues->unk_308[0] = 0;
    gBattleMessageQueues->unk_308[1] = 0;
    gBattleMessageQueues->unk_2C8[0] = 0;
    gBattleMessageQueues->unk_2C8[1] = 0;
    gBattleMessageQueues->unk_348[0] = 0;
    gBattleMessageQueues->unk_348[1] = 0;
    gBattleMessageQueues->unk_388[0] = 0;
    gBattleMessageQueues->unk_388[1] = 0;
    gBattleMessageQueues->unk_3C8[0] = 0;
    gBattleMessageQueues->unk_3C8[1] = 0;
    gBattleMessageQueues->unk_408[0] = 0;
    gBattleMessageQueues->unk_408[1] = 0;
}

void Battle_ClearMessageCursor(void) {
    gBattleMessageQueues->unk_004 = 0;
    gBattleMessageQueues->unk_048[0] = 0;
    gBattleMessageQueues->unk_048[1] = 0;
    gBattleMessageQueues->unk_008[0] = 0;
    gBattleMessageQueues->unk_008[1] = 0;
}

void func_84317940(s8* arg0, s8* arg1, ...) {
    va_list args;
    s8* src;
    s8* fmt;
    s32 len;

    len = 0;
    va_start(args, arg1);
    fmt = arg1;

    while (*fmt != 0) {
        if (*fmt != 0x25) {
            arg0[len++] = *fmt;
        } else {
            fmt++;
            if (*fmt == 0x73) {
                src = va_arg(args, s8*);
                while (*src != 0) {
                    arg0[len] = *src;
                    src++;
                    len++;
                }
            }
        }
        fmt++;
    }
    arg0[len] = 0;
}

void Battle_QueueMessage(s8* arg0, s8 arg1) {
    u8 tmp = arg1;
    *arg0 = arg1;

    if (tmp >= 0x80) {
        if ((tmp - 0x80) >= 0xB) {
            Text_GetString(arg0 + 1, 0x40, D_843900B0, tmp - 0x48);
        } else {
            Text_GetString(arg0 + 1, 0x40, D_843900B0, tmp - 0x49);
        }
    } else {
        Text_GetString(arg0 + 1, 0x40, D_843900B0, D_84385BC0[arg1]);
    }
}

void Battle_QueueStatusText(char* arg0, s32 arg1) {
    UNUSED s32 pad[3];
    ActivePokemonState* sp28 = &sActivePokemon[arg1]->state;
    UNUSED s32 pad2[2];

    Battle_ClearMessageCursor();
    gBattleMessageQueues->unk_000 = sActivePokemon[arg1]->sessionTeams->teamMember[sp28->unk_2B]->unk_001;
    func_84317940(gBattleMessageQueues->unk_048, arg0 + 1);
    *arg0 = 0;
}

void func_84317B38(void) {
}

void Battle_DrawCompactStatusBoxesIfVisible(void) {
    ActivePokemon* ptr1 = sActivePokemon[0];
    ActivePokemon* ptr2 = sActivePokemon[1];

    if ((gSessionContext.mode != 0x10) && (gBattleScene.unk_00->unk_30 == 0)) {
        BattleHud_DrawCompactMonStatusBox(ptr1, 0x15, 0xF, ptr1->sessionTeams->teamMember[ptr1->unk_728.unk_16C]->unk_001);
        BattleHud_DrawCompactMonStatusBox(ptr2, 0xE1, 0xF, ptr2->sessionTeams->teamMember[ptr2->unk_728.unk_16C]->unk_001);
    }
}

void Battle_QueueMoveCategoryUsedMessage(void) {
    u32 sp1C;
    BattleMonRuntime* sp18 = &sActivePokemon[gBattleScene.unk_00->unk_2C]->state.runtime;

    sp18->unk_58 = sp18->unk_44.unk_00;

    if (BattleScene_ByteArrayContains(sp18->unk_44.unk_00, D_84385990, 2) != 0) {
        sp1C = 0;
    } else if (BattleScene_ByteArrayContains(sp18->unk_44.unk_00, D_84385994, 5) != 0) {
        sp1C = 1;
    } else if (BattleScene_ByteArrayContains(sp18->unk_44.unk_00, D_8438599C, 5) != 0) {
        sp1C = 2;
    } else if (BattleScene_ByteArrayContains(sp18->unk_44.unk_00, D_843859A4, 0x2E) != 0) {
        sp1C = 3;
    } else {
        sp1C = 4;
    }

    if ((sp18->unk_44.unk_00 == 0x76) || (sp18->unk_44.unk_00 == 0x77)) {
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[gBattleScene.unk_00->unk_2C]));
        Text_SetStringToken(0x1D, Battle_GetActiveMoveName(sActivePokemon[gBattleScene.unk_00->unk_2C]));

        switch (sp1C) {
            case 0:
                Battle_QueueMessage(gBattleMessageQueues->unk_388, 0x14);
                break;

            case 1:
                Battle_QueueMessage(gBattleMessageQueues->unk_388, 0x15);
                break;

            case 2:
                Battle_QueueMessage(gBattleMessageQueues->unk_388, 0x16);
                break;

            case 3:
                Battle_QueueMessage(gBattleMessageQueues->unk_388, 0x17);
                break;

            case 4:
                Battle_QueueMessage(gBattleMessageQueues->unk_388, 0x18);
                break;
        }
    } else {
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[gBattleScene.unk_00->unk_2C]));
        Text_SetStringToken(0x1D, Battle_GetActiveMoveName(sActivePokemon[gBattleScene.unk_00->unk_2C]));

        switch (sp1C) {
            case 0:
                Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x14);
                break;

            case 1:
                Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x15);
                break;

            case 2:
                Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x16);
                break;

            case 3:
                Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x17);
                break;

            case 4:
                Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x18);
                break;
        }
    }
}

void Battle_QueueMoveCategoryMessage(void) {
    u32 sp24;
    UNUSED s32 pad;
    BattleMonRuntime* sp1C = &sActivePokemon[gBattleScene.unk_00->unk_2C]->state.runtime;

    if (BattleScene_ByteArrayContains(sp1C->usedMove, D_84385990, 2) != 0) {
        sp24 = 0;
    } else if (BattleScene_ByteArrayContains(sp1C->usedMove, D_84385994, 5) != 0) {
        sp24 = 1;
    } else if (BattleScene_ByteArrayContains(sp1C->usedMove, D_8438599C, 5) != 0) {
        sp24 = 2;
    } else if (BattleScene_ByteArrayContains(sp1C->usedMove, D_843859A4, 0x2E) != 0) {
        sp24 = 3;
    } else {
        sp24 = 4;
    }

    Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[gBattleScene.unk_00->unk_2C]));
    Text_SetStringToken(0x1D, Battle_GetActiveMoveName(sActivePokemon[gBattleScene.unk_00->unk_2C]));

    switch (sp24) {
        case 0:
            Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x14);
            break;

        case 1:
            Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x15);
            break;

        case 2:
            Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x16);
            break;

        case 3:
            Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x17);
            break;

        case 4:
            Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x18);
            break;
    }
}

void Battle_QueueMetronomeMoveMessage(void) {
    s32 sp2C;
    s32 tmp;
    BattleMonRuntime* sp24;

    sp24 = &sActivePokemon[gBattleScene.unk_00->unk_2C]->state.runtime;

    if (BattleScene_ByteArrayContains(sp24->usedMove, D_84385990, 2) != 0) {
        sp2C = 0;
    } else if (BattleScene_ByteArrayContains(sp24->usedMove, D_84385994, 5) != 0) {
        sp2C = 1;
    } else if (BattleScene_ByteArrayContains(sp24->usedMove, D_8438599C, 5) != 0) {
        sp2C = 2;
    } else if (BattleScene_ByteArrayContains(sp24->usedMove, D_843859A4, 0x2E) != 0) {
        sp2C = 3;
    } else {
        sp2C = 4;
    }

    if (sp24->usedMove == 0x76) {
        do {
            tmp = Battle_Random();
        } while ((tmp == 0) || (tmp >= 0xA5) || tmp == 0x76);

        sp24->usedMove = tmp;

        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[gBattleScene.unk_00->unk_2C]));
        Text_SetStringToken(0x1D, Battle_GetActiveMoveName(sActivePokemon[gBattleScene.unk_00->unk_2C]));

        switch (sp2C) {
            case 0:
                Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x14);
                break;

            case 1:
                Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x15);
                break;

            case 2:
                Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x16);
                break;

            case 3:
                Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x17);
                break;

            case 4:
                Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x18);
                break;
        }

        sp24->usedMove = 0x76;

        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[gBattleScene.unk_00->unk_2C]));
        Text_SetStringToken(0x1D, Battle_GetActiveMoveName(sActivePokemon[gBattleScene.unk_00->unk_2C]));

        switch (sp2C) {
            case 0:
                Battle_QueueMessage(gBattleMessageQueues->unk_388, 0x14);
                break;

            case 1:
                Battle_QueueMessage(gBattleMessageQueues->unk_388, 0x15);
                break;

            case 2:
                Battle_QueueMessage(gBattleMessageQueues->unk_388, 0x16);
                break;

            case 3:
                Battle_QueueMessage(gBattleMessageQueues->unk_388, 0x17);
                break;

            case 4:
                Battle_QueueMessage(gBattleMessageQueues->unk_388, 0x18);
                break;
        }
    } else {
        Text_SetStringToken(0x19, Battle_GetActiveMonNickname(sActivePokemon[gBattleScene.unk_00->unk_2C]));
        Text_SetStringToken(0x1D, Battle_GetActiveMoveName(sActivePokemon[gBattleScene.unk_00->unk_2C]));

        switch (sp2C) {
            case 0:
                Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x14);
                break;

            case 1:
                Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x15);
                break;

            case 2:
                Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x16);
                break;

            case 3:
                Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x17);
                break;

            case 4:
                Battle_QueueMessage(gBattleMessageQueues->unk_0C8, 0x18);
                break;
        }
    }
}

void BattleBox_Open(s32 arg0) {
    unk_D_843901A0_4C8* ptr = &gBattleMessageQueues->unk_4C8;

    ptr->unk_00 = 0;
    ptr->unk_04 = arg0;
}

void BattleBox_Close(void) {
    unk_D_843901A0_4C8* ptr = &gBattleMessageQueues->unk_4C8;

    ptr->unk_00 = 0xFF;
}

void BattleBox_PlayTextBlip(s8* arg0) {
    s32 temp_v0;

    if (arg0[1] == '\x00') {
        return;
    }

    temp_v0 = arg0[0] & 0x7F;

    if ((arg0[0] & 0x80) == '\x00') {
        Audio_QueuePendingSoundId(arg0[0]);
    } else if (temp_v0 == 'Q') {
        Audio_QueuePendingSoundId(0xBC);
    } else if (temp_v0 == 'R') {
        Audio_QueuePendingSoundId(0xB5);
    } else if (temp_v0 == 'S') {
        Audio_QueuePendingSoundId(0xB6);
    } else if (temp_v0 == 'T') {
        Audio_QueuePendingSoundId(0xB7);
    } else if (temp_v0 == 'U') {
        Audio_QueuePendingSoundId(0xB8);
    } else if (temp_v0 == 'V') {
        Audio_QueuePendingSoundId(0xB9);
    } else if (temp_v0 == 'W') {
        Audio_QueuePendingSoundId(0xBA);
    } else if (temp_v0 == 'X') {
        Audio_QueuePendingSoundId(0xBB);
    } else {
        Audio_QueuePendingSoundId(temp_v0 + 0x64);
    }
}

void BattleBox_DrawMessage(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2) {
    UNUSED s32 pad;
    s32 temp_s1;

    if (1) {}

    switch (arg0->unk_04) {
        case 0:
            if (Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_388[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_0C8[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_188[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }
            break;

        case 3:
            if (Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_088[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_148[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_208[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }
            break;

        case 1:
            if (Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_3C8[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_088[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_148[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if ((arg0->unk_10 < 3) &&
                (Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_208[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0)) {
                arg0->unk_10 += 1;
            }
            break;

        case 2:
            if (Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_088[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_148[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_208[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }
            break;

        case 4:
            Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_248[1], arg1 + 4, arg2 + 3);
            break;

        case 5:
            Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_288[1], arg1 + 4, arg2 + 3);
            break;

        case 6:
            Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_408[1], arg1 + 4, arg2 + 3);
            break;

        case 7:
            Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_348[1], arg1 + 4, arg2 + 3);
            Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_2C8[1], arg1 + 4, arg2 + 0x10);
            break;

        case 8:
            Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_448[arg0->unk_0C][1], arg1 + 4, arg2 + 3);
            break;

        case 9:
        case 10:
            Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_1C8[1], arg1 + 4, arg2 + 3);
            break;

        case 11:
            Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_088[1], arg1 + 4, arg2 + 3);
            break;

        case 12:
            Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_088[1], arg1 + 4, arg2 + 3);
            break;

        case 13:
            temp_s1 = Font_MeasureTextExtent(1, 0, Text_GetString(NULL, 0, D_843900B0, 0xA4)) / 2;
            Battle_DrawTextIfNonEmpty(Text_GetString(NULL, 0, D_843900B0, 0xA4), 0xA1 - temp_s1, 0x71);
            break;

        case 14:
            Battle_DrawSpectatorModeIndicator();
            break;

        case 15:
            Battle_DrawTextIfNonEmpty(&gBattleMessageQueues->unk_088[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3);
            break;
    }

    arg0->unk_10 = 0;
}

s32 BattleBox_SelectMessage(unk_D_843901A0_4C8* arg0) {
    unk_D_843901A0* temp_v0;
    s32 tmp;

    arg0->unk_10 = 0;

    switch (arg0->unk_04) {
        case 0:
            if ((gBattleMessageQueues->unk_0C8[1] == 0) && (gBattleMessageQueues->unk_388[1] == 0) && (gBattleMessageQueues->unk_188[1] == 0)) {
                arg0->unk_00 = 0xFF;
                return 1;
            }

            arg0->unk_0C = gBattleScene.unk_00->unk_2C;
            if (gBattleMessageQueues->unk_0C8[1] != 0) {
                BattleBox_PlayTextBlip(gBattleMessageQueues->unk_0C8);
            }

            if (gBattleMessageQueues->unk_388[1] != 0) {
                BattleBox_PlayTextBlip(gBattleMessageQueues->unk_388);
            }

            if (gBattleMessageQueues->unk_188[1] != 0) {
                BattleBox_PlayTextBlip(gBattleMessageQueues->unk_188);
            }
            arg0->unk_00 += 1;
            break;

        case 1:
        case 3:
            arg0->unk_0C = gBattleScene.unk_00->unk_2C;
            BattleBox_PlayTextBlip(gBattleMessageQueues->unk_088);
            BattleBox_PlayTextBlip(gBattleMessageQueues->unk_148);
            BattleBox_PlayTextBlip(gBattleMessageQueues->unk_208);
            BattleBox_PlayTextBlip(gBattleMessageQueues->unk_3C8);
            BattleBox_PlayTextBlip(gBattleMessageQueues->unk_308);
            if ((gBattleMessageQueues->unk_088[1] == 0) && (gBattleMessageQueues->unk_148[1] == 0) && (gBattleMessageQueues->unk_208[1] == 0) &&
                (gBattleMessageQueues->unk_3C8[1] == 0) && (gBattleMessageQueues->unk_308[1] == 0)) {
                arg0->unk_00 = 0xFF;
                return 1;
            }
            arg0->unk_00 += 1;
            break;

        case 2:
            arg0->unk_0C = gBattleScene.unk_00->unk_2C;
            BattleBox_PlayTextBlip(gBattleMessageQueues->unk_088);
            BattleBox_PlayTextBlip(gBattleMessageQueues->unk_148);
            BattleBox_PlayTextBlip(gBattleMessageQueues->unk_208);
            if ((gBattleMessageQueues->unk_088[1] == 0) && (gBattleMessageQueues->unk_148[1] == 0) && (gBattleMessageQueues->unk_208[1] == 0)) {
                arg0->unk_00 = 0xFF;
                return 1;
            }
            arg0->unk_00 += 1;
            break;

        case 15:
            arg0->unk_0C = gBattleScene.unk_00->unk_2C;
            BattleBox_PlayTextBlip(gBattleMessageQueues->unk_088);
            if (gBattleMessageQueues->unk_088[1] == 0) {
                arg0->unk_00 = 0xFF;
                return 1;
            }
            arg0->unk_00 += 1;
            break;

        case 8:
            if (gBattleMessageQueues->unk_448[arg0->unk_0C][1] == 0) {
                arg0->unk_00 = 0xFF;
                return 1;
            }
            tmp = gBattleScene.unk_00->unk_2C == 0;
            arg0->unk_00 += 1;
            arg0->unk_0C = tmp;
            break;

        case 9:
            tmp = gBattleScene.unk_00->unk_2C == 0;
            arg0->unk_00 += 1;
            arg0->unk_0C = tmp;
            break;

        case 4:
        case 5:
        case 6:
            BattleBox_PlayTextBlip(gBattleMessageQueues->unk_248);
            BattleBox_PlayTextBlip(gBattleMessageQueues->unk_288);
            BattleBox_PlayTextBlip(gBattleMessageQueues->unk_408);
            arg0->unk_00 += 1;
            break;

        case 14:
            D_84390190.z = 0.0f;
            D_84390190.x = 321.0f;
            D_84390190.y = 160.0f;
            arg0->unk_0C = gBattleScene.unk_00->unk_2C;
            arg0->unk_00 += 1;
            break;

        default:
            arg0->unk_0C = gBattleScene.unk_00->unk_2C;
            arg0->unk_00 += 1;
            break;
    }
    return 0;
}

void BattleBox_Update(s16 arg0, s16 arg1) {
    unk_D_843901A0_4C8* temp_s0 = &gBattleMessageQueues->unk_4C8;

    if (gSessionContext.mode == 0x10) {
        return;
    }

    switch (temp_s0->unk_00) {
        case 0:
            temp_s0->unk_08 = 0;
            if (temp_s0->unk_04 == 0xD) {
                BattleHud_InitCaptionBoxPopupBlack(temp_s0, 0xA0, 0x78);
                temp_s0->unk_00++;
            } else if (temp_s0->unk_04 == 0xE) {
                BattleBox_SelectMessage(temp_s0);
            } else if (BattleBox_SelectMessage(temp_s0) == 0) {
                BattleHud_InitCaptionBoxPopup(temp_s0, arg0, arg1);
            }
            break;

        case 1:
            if (temp_s0->unk_04 == 0xD) {
                if (BattleHud_UpdateCaptionBoxPopupBlack(temp_s0, 0xA0, 0x78) != 0) {
                    BattleBox_DrawMessage(temp_s0, temp_s0->unk_14.x, temp_s0->unk_14.y);
                    temp_s0->unk_00++;
                }
            } else {
                if (temp_s0->unk_04 == 0xE) {
                    func_8003F660(BattleScene_GetParticipantDisplayPlayerNumber(sActivePokemon[temp_s0->unk_0C]));
                    BattleBox_DrawMessage(temp_s0, temp_s0->unk_14.x, temp_s0->unk_14.y);
                    temp_s0->unk_00++;
                } else if (BattleHud_UpdateCaptionBoxPopup(temp_s0, arg0, arg1) != 0) {
                    func_8003F660(BattleScene_GetParticipantDisplayPlayerNumber(sActivePokemon[temp_s0->unk_0C]));
                    BattleBox_DrawMessage(temp_s0, temp_s0->unk_14.x, temp_s0->unk_14.y);
                    temp_s0->unk_00++;
                }
            }
            break;

        case 2:
            if (temp_s0->unk_04 == 0xD) {
                BattleHud_UpdateCaptionBoxPopupBlack(temp_s0, 0xA0, 0x78);
                BattleBox_DrawMessage(temp_s0, temp_s0->unk_14.x, temp_s0->unk_14.y);

                temp_s0->unk_08++;
                if (temp_s0->unk_08 == 0x46) {
                    temp_s0->unk_00++;
                }
            } else {
                if (temp_s0->unk_04 == 0xE) {
                    BattleBox_DrawMessage(temp_s0, temp_s0->unk_14.x, temp_s0->unk_14.y);
                } else {
                    BattleHud_UpdateCaptionBoxPopup(temp_s0, arg0, arg1);
                    BattleBox_DrawMessage(temp_s0, temp_s0->unk_14.x, temp_s0->unk_14.y);

                    temp_s0->unk_08++;
                    if (temp_s0->unk_08 == 0x2D) {
                        temp_s0->unk_00++;
                    }
                }
            }
            break;
    }
}

void BattleScene_ClearParticipantMessageBuffer(ActivePokemon* arg0) {
    arg0->unk_8C4.unk_00 = 0;
    arg0->unk_8C4.unk_04 = 0;
    arg0->unk_8C4.unk_48[0] = 0;
    arg0->unk_8C4.unk_08[0] = 0;
}

void BattleScene_BuildParticipantMessage(ActivePokemon* arg0, s32 arg1) {
    gBattleMessageQueues->unk_000 = arg0->sessionTeams->teamMember[arg0->state.unk_2C]->unk_001;
    arg0->unk_8C4.unk_00 = 1;
    Text_SetStringToken(0x19, arg0->unk_724->pokemonPicked[arg0->state.unk_08].unk_30);
    Text_GetString(arg0->unk_8C4.unk_48, 0x40, D_843900B0, arg1);
}

void BattleScene_RevealParticipantMessageChars(ActivePokemon* arg0) {
    TeamRoster* temp_t0 = arg0->sessionTeams->teamMember[arg0->state.unk_2C];

    if (arg0->unk_8C4.unk_48[arg0->unk_8C4.unk_04] != '\x00') {
        arg0->unk_8C4.unk_08[arg0->unk_8C4.unk_04] = arg0->unk_8C4.unk_48[arg0->unk_8C4.unk_04];
        arg0->unk_8C4.unk_04++;
    }

    if (arg0->unk_8C4.unk_48[arg0->unk_8C4.unk_04] != '\x00') {
        arg0->unk_8C4.unk_08[arg0->unk_8C4.unk_04] = arg0->unk_8C4.unk_48[arg0->unk_8C4.unk_04];
        arg0->unk_8C4.unk_04++;
    }

    arg0->unk_8C4.unk_08[arg0->unk_8C4.unk_04] = '\x00';

    if (arg0->unk_8C4.unk_48[0] != 0) {
        if (arg0 == sSide1ActivePokemon) {
            BattleHud_DrawTextBox(temp_t0->unk_001, 0x5F, 0xE, &arg0->unk_8C4.unk_08);
        } else {
            BattleHud_DrawTextBox(temp_t0->unk_001, 0x17, 0xBB, &arg0->unk_8C4.unk_08);
        }
    }
}

void BattleScene_TickHudTimers(void) {
    ActivePokemonState* sp1C = &sActivePokemon[0]->state;
    ActivePokemonState* sp18 = &sActivePokemon[1]->state;

    if ((gSessionContext.timeLimitsEnabled != 0) && (sActivePokemon[1]->unk_728.unk_168->unk_1C == 0x103) &&
        (sActivePokemon[0]->unk_728.unk_168->unk_1C == 0x17)) {
        BattleHud_DrawBattleTimer(0x101, 0x64);
        if (D_84390134 == 0) {
            if (sp1C->unk_10 != 3) {
                BattleHud_DrawParticipantTimer(0x46, 0x4D);
            }

            if (sp18->unk_10 != 3) {
                BattleHud_DrawParticipantTimer(0xE8, 0x96);
            }
        }
    }
}

void Battle_InitMessageQueues(void) {
    gBattleMessageQueues = main_pool_alloc(sizeof(unk_D_843901A0), 0);
    bzero(gBattleMessageQueues, sizeof(unk_D_843901A0));
}

void BattleScene_ResetMessageQueue(void) {
    gBattleMessageQueues->unk_004 = 0;
    gBattleMessageQueues->unk_008[gBattleMessageQueues->unk_004] = 0;
    Battle_ClearMessageCursor();
}

void Battle_RenderHud(void) {
    ActivePokemonState* sp1C = &sActivePokemon[0]->state;
    ActivePokemonState* sp18 = &sActivePokemon[1]->state;

    if (1) {}

    BattleBox_Update(0xA0, 0xC8);

    if (gSessionContext.mode == 0x10) {
        Battle_DrawSpectatorModeScrollingText();
        Battle_DrawSpectatorModeBackgroundPanel();
    }

    switch (gBattleScene.unk_00->unk_1C) {
        case 1:
            BattleHud_DrawOwnSideStatus(sActivePokemon[0], sp1C);
            BattleHud_DrawOpponentSideStatus(sActivePokemon[1], sp18);
            BattleScene_RevealParticipantMessageChars(sActivePokemon[0]);
            BattleScene_RevealParticipantMessageChars(sActivePokemon[1]);
            BattleScene_TickHudTimers();
            BattleScene_DrawStripWipeIfActive();
            break;

        case 2:
            Battle_DrawCompactStatusBoxesIfVisible();
            BattleScene_DrawStripWipeIfActive();
            break;
    }
}
