#include "sushi_game.h"
#include "src/geo_node.h"
#include "src/model_renderer.h"
#include "src/audio_loop_point.h"
#include "src/audio_commands_category2.h"
#include "src/gfx_buffer.h"
#include "src/matrix.h"
#include "src/fragments/widget_toolkit/widget_toolkit.h"
#include "src/memory.h"

static const u32 D_868074B0[] = { 0xA4A2A4AC, 0xA4EA0000 }; // "あがり"
static const u32 D_868074B8[] = { 0xA4A8A4D3, 0x00000000 }; // "えび"
static const u32 D_868074C0[] = { 0xA4A4A4AF, 0xA4E90000 }; // "いくら"
static const u32 D_868074C8[] = { 0xA4ABA4C3, 0xA4D10000 }; // "かっぱ"
static const u32 D_868074D0[] = { 0xA4C8A4ED, 0x00000000 }; // "とろ"
static const u32 D_868074D8[] = { 0xA4C6A4C3, 0xA4AB0000 }; // "てっか"
static const u32 D_868074E0[] = { 0xA4BFA4DE, 0xA4B40000 }; // "たまご"
static const u32 D_868074E8[] = { 0xA4A6A4CB, 0x00000000 }; // "うに"

static f32 D_86807140 = 230.0f;
static Vec3f D_86807144 = { 0.0f, 35.0f, 0.0f };
static Vec3f D_86807150 = { 3.0f, 0.0f, 17.0f };
static f32 D_8680715C = 10.0f;
s32 D_86807160[] = {
    8, 5, 2, 3, 6, 7, 4, 1,
};
unk_D_86807180 D_86807180[9] = {
    {
        0x00000000,
        NULL,
        NULL,
        NULL,
        0x0000,
        0x0000,
        0x00000000,
        0x0000,
    },
    {
        0x00000014,
        0x04000000,
        0x04004000,
        D_868074B0,
        0x0000,
        0x0014,
        0x00000000,
        0x0000,
    },
    {
        0x0000015E,
        0x04000800,
        0x04005000,
        D_868074B8,
        0x0014,
        0x000A,
        0x00050005,
        0x0001,
    },
    {
        0x000000FA,
        0x04001000,
        0x04006000,
        D_868074C0,
        0x0000,
        0x000C,
        0x00000000,
        0x0000,
    },
    {
        0x00000032,
        0x04001800,
        0x04007000,
        D_868074C8,
        0x0000,
        0x0014,
        0x00000000,
        0x0000,
    },
    {
        0x00000258,
        0x04002000,
        0x04008000,
        D_868074D0,
        0x0019,
        0x0005,
        0x00050006,
        0x0001,
    },
    {
        0x000000C8,
        0x04002800,
        0x04009000,
        D_868074D8,
        0x0000,
        0x000D,
        0x00000000,
        0x0000,
    },
    {
        0x00000096,
        0x04003000,
        0x0400A000,
        D_868074E0,
        0x0000,
        0x0011,
        0x00000000,
        0x0000,
    },
    {
        0x000003E8,
        0x04003800,
        0x0400B000,
        D_868074E8,
        0x001E,
        0x0003,
        0x00050007,
        0x0001,
    },
};
static Vtx D_86807280[] = {
    VTX(-16, 0, -16, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, 0, -16, 992, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, 0, 15, 0, 992, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, 0, 15, 992, 992, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_868072C0[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_86807280, 4, 0),
    gsDPLoadTextureBlock(0x0400C000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 3, 1, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static Gfx D_86807338[] = {
    gsSPEndDisplayList(),
};
static Vtx D_86807340[] = {
    VTX(-16, 31, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, 31, 0, 992, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, 0, 0, 0, 992, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, 0, 0, 992, 992, 0xFF, 0xFF, 0xFF, 0xFF),
};

static s32 D_868084D0;
static f32 D_868084D4;
unk_D_868084D8 D_868084D8[12];
static unk_D_86808808 D_86808808[12];
static s32 D_86809A08;
static s16 D_86809A0C;
static s16 D_86809A10[9];

void SushiGame_GetConveyorSlotPosition(s16 arg0, Vec3f* arg1) {
    f32 var_fv0 = D_868084D4 + (arg0 * 30.0f);

    if (var_fv0 >= 360.0f) {
        var_fv0 -= 360.0f;
    }
    var_fv0 = (var_fv0 * 65536.0f) / 360.0f;

    arg1->x = D_86807144.x + (SINS(var_fv0) * D_86807140);
    arg1->y = D_86807144.y;
    arg1->z = D_86807144.z + (COSS(var_fv0) * D_86807140);
}

f32 SushiGame_ComputePlateDistance(unk_D_868084D8* arg0, Vec3f* arg1, Vec3f* arg2) {
    f32 var_fv1;
    unk_D_868084D8_038* ptr = arg0->unk_38;

    var_fv1 = (0.5f * D_8680715C) + D_868084D4 + (30.0f * ptr->unk_000);
    if (var_fv1 >= 360.0f) {
        var_fv1 -= 360.0f;
    }

    arg2->x = ((SINS(((s32)var_fv1 << 0xF) / 180) * D_86807140) + D_86807144.x) - arg1->x;
    arg2->y = 0.0f;
    arg2->z = ((COSS(((s32)var_fv1 << 0xF) / 180) * D_86807140) + D_86807144.z) - arg1->z;
    return SQ(arg2->x) + SQ(arg2->z);
}

void SushiGame_InitConveyorCup(unk_D_86808808* arg0, s32 arg1) {
    unk_D_86808808_018* sp1C = &arg0->unk_018;

    arg0->unk_000 = arg1;
    arg0->unk_002 = 0;
    arg0->unk_004 = 0;
    arg0->unk_006 = 0;
    arg0->unk_008 = 0;

    SushiGame_GetConveyorSlotPosition(arg0->unk_000, &arg0->unk_00C);
    ModelRenderer_AttachDisplayObject(&sp1C->node);

    sp1C->unk_030.x = sp1C->unk_030.y = sp1C->unk_030.z = 2.0f;
}

void SushiGame_SetPlateSpawnPosition(unk_D_868084D8* arg0) {
    unk_D_868084D8_038* ptr;

    switch (arg0->unk_10) {
        case 0:
            arg0->unk_14 = D_8006F050;
            arg0->unk_20 = arg0->unk_14;
            break;

        case 1:
        case 2:
            arg0->unk_14.x = arg0->unk_38->unk_00C.x;
            arg0->unk_14.y = arg0->unk_38->unk_00C.y;
            arg0->unk_14.z = arg0->unk_38->unk_00C.z;

            arg0->unk_20.x = arg0->unk_14.x + D_86807150.x;
            arg0->unk_20.y = arg0->unk_14.y + D_86807150.y;
            arg0->unk_20.z = arg0->unk_14.z + D_86807150.z;
            break;

        case 3:
            ptr = arg0->unk_38;
            arg0->unk_14 = ptr->unk_1D0;
            arg0->unk_20 = arg0->unk_14;
            break;
    }
}

s32 SushiGame_PickRandomSushiType(void) {
    UNUSED s32 pad[4];
    s32 i;
    s32 sp20;
    s32 sp1C = 1;
    s16 var_v0;
    s32 temp_a0;
    s32 var_a1;
    s32 temp_v0;

    if (D_86809A10[1] < 3) {
        sp20 = 0;
        var_v0 = D_86809A0C;
    } else {
        sp20 = 1;
        var_v0 = D_86809A0C - D_86807180[1].unk_12;
    }

    temp_v0 = Rand_Range(var_v0);
    var_a1 = 0;

    for (i = 0; i < 9; i++) {
        if ((sp20 != 0) && (i == 1)) {
            continue;
        }

        temp_a0 = D_86807180[i].unk_12 + var_a1;
        if ((temp_v0 >= var_a1) && (temp_v0 < temp_a0)) {
            sp1C = i;
            break;
        }

        var_a1 = temp_a0;
    }

    return sp1C;
}

void SushiGame_InitPlate(s32 arg0, unk_D_868084D8* arg1, s32 arg2, unk_D_868084D8_038* arg3) {
    if (arg0 == 0) {
        if (arg2 != -1) {
            arg1->unk_00 = arg2;
        }
        arg1->unk_02 = 0;
        arg1->unk_04 = 0;
        arg1->unk_06 = 0;
        arg1->unk_08.rgba = -1;
        arg1->unk_0C = 0;
        arg1->unk_10 = 0;
        arg1->unk_38 = NULL;
        arg1->unk_2C = 0.0f;
        arg1->unk_40->node.flags &= ~1;
    } else {
        arg3->unk_008 = arg1;
        arg1->unk_02 = 0;
        arg1->unk_04 = 0;
        arg1->unk_06 = 0;
        arg1->unk_08.rgba = 0xFFFFFF80;
        arg1->unk_0C = SushiGame_PickRandomSushiType();

        D_86809A10[arg1->unk_0C]++;

        arg1->unk_10 = 1;
        arg1->unk_2C = 0.0f;
        arg1->unk_38 = arg3;

        if ((s16)Rand_Range(100) < D_86807180[arg1->unk_0C].unk_10) {
            arg1->unk_02 |= 2;
        }

        arg1->unk_40->node.flags |= 1;

        if (arg3->unk_006 >= 2) {
            if ((D_86807180[arg1->unk_0C].unk_18 != 0) && (D_86807510 >= 0x3D)) {
                Audio_DispatchSoundBankCommand(D_86807180[arg1->unk_0C].unk_14, 0, 0);
            }
        }
    }

    arg1->unk_30 = 1.0f;
    arg1->unk_34 = 0.0f;

    SushiGame_SetPlateSpawnPosition(arg1);

    arg1->unk_3C = &D_86807338;
}

unk_D_868084D8* SushiGame_FindFreePlate(void) {
    s32 i;
    unk_D_868084D8* var_v1 = D_868084D8;

    for (i = 0; i < 12; i++, var_v1++) {
        if (var_v1->unk_0C == 0) {
            break;
        }
    }

    if (i == 0xC) {
        var_v1 = NULL;
    }
    return var_v1;
}

void SushiGame_UpdateConveyorCup(unk_D_86808808* arg0) {
    unk_D_868084D8* sp24;

    SushiGame_GetConveyorSlotPosition(arg0->unk_000, &arg0->unk_00C);

    if ((D_8780FC94 == 0) && (arg0->unk_008 == 0) && (arg0->unk_004 & 1)) {
        arg0->unk_002 -= 1;
        if (arg0->unk_002 <= 0) {
            arg0->unk_002 = 0;
            sp24 = SushiGame_FindFreePlate();
            if (sp24 != NULL) {
                arg0->unk_006++;
                if (D_868084D0 == 0) {
                    D_868084D0 = 1;
                    Audio_DispatchSoundBankCommand(0x50003, 0, 0);
                    Audio_StartMusicTrack(0x17);
                }
                SushiGame_InitPlate(1, sp24, -1, arg0);
            }
        }
    }

    arg0->unk_018.unk_024 = arg0->unk_00C;
}

void SushiGame_UpdatePlate(unk_D_868084D8* arg0) {
    Gfx* gfx;
    f32 var_fv0;
    s32 var_v0;

    if (D_8780FC94 == 0) {
        switch (arg0->unk_10) {
            case 1:
                if (arg0->unk_30 >= 0.0f) {
                    arg0->unk_34 -= 0.05f;
                } else {
                    arg0->unk_34 += 0.05f;
                }

                var_v0 = 0;
                var_fv0 = arg0->unk_30;
                arg0->unk_30 += arg0->unk_34;
                if ((arg0->unk_30 * var_fv0) < 0.0f) {
                    if (arg0->unk_34 < 0.0f) {
                        var_fv0 = arg0->unk_34;
                        var_fv0 = 0.0f - var_fv0;
                    } else {
                        var_fv0 = arg0->unk_34;
                    }

                    if (var_fv0 < 0.1f) {
                        var_v0 = 1;
                        arg0->unk_2C = 1.5f;
                    }
                }

                if (var_v0 == 0) {
                    arg0->unk_34 *= 0.8f;
                    arg0->unk_2C = (arg0->unk_30 * -1.5f) + 1.5f;
                } else {
                    SushiGame_SetPlateState(arg0, 2, NULL);
                }
                break;

            case 3:
                if (arg0->unk_04 > 0) {
                    arg0->unk_04--;
                    if (arg0->unk_04 > 0) {
                        var_fv0 = 1.0f - ((f32)(arg0->unk_06 - arg0->unk_04) / arg0->unk_06);
                        arg0->unk_2C = 1.5f * var_fv0;
                    } else {
                        arg0->unk_2C = 0.0f;
                        arg0->unk_40->node.flags &= ~1;
                    }
                }
                break;
        }
    }

    SushiGame_SetPlateSpawnPosition(arg0);
    gfx = Gfx_AllocDisplayList(sizeof(Gfx) * 16);
    arg0->unk_3C = gfx;

    gSPVertex(gfx++, D_86807340, 4, 0);

    if (arg0->unk_08.a != 0xFF) {
        gDPPipeSync(gfx++);

        gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_PASS2);
        gDPSetPrimColor(gfx++, 0, 0, arg0->unk_08.r, arg0->unk_08.g, arg0->unk_08.b, arg0->unk_08.a);
    }

    gDPLoadTextureBlock(gfx++, D_86807180[arg0->unk_0C].unk_04, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);
    gSPEndDisplayList(gfx++);

    if (arg0->unk_08.a != 0xFF) {
        arg0->unk_40->node.renderLayer = 5;
    } else {
        arg0->unk_40->node.renderLayer = 4;
    }

    arg0->unk_40->unk_18 = arg0->unk_3C;
    arg0->unk_40->unk_1C = arg0->unk_20;
    arg0->unk_40->unk_28 = arg0->unk_2C;
}

void func_86806860(void) {
}

void SushiGame_SetPlateState(unk_D_868084D8* arg0, s32 arg1, unk_D_86807558* arg2) {
    unk_D_868084D8_038* temp_v0;

    arg0->unk_10 = arg1;

    switch (arg1) {
        case 2:
            arg0->unk_02 |= 1;
            arg0->unk_04 = 0;
            arg0->unk_08.a = 0xFF;
            arg0->unk_2C = 1.5f;
            break;

        case 3:
            temp_v0 = arg0->unk_38;
            temp_v0->unk_008 = 0;
            temp_v0->unk_002 = 0x78;
            arg0->unk_38 = arg2;
            arg0->unk_04 = arg0->unk_06 = arg2->unk_0CC;
            break;

        case 0:
            D_86809A10[arg0->unk_0C]--;
            SushiGame_InitPlate(0, arg0, -1, NULL);
            break;
    }
}

s32 SushiGame_GetPlateValue(unk_D_868084D8* arg0) {
    return D_86807180[arg0->unk_0C].unk_00;
}

s16 SushiGame_GetActivePlateCount(s32 arg0) {
    return D_86809A10[arg0];
}

void SushiGame_SetGamePhase(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 3)) {
        D_86809A08 = arg0;
    }
}

void SushiGame_ApplyGamePhase(void) {
    s32 i;
    unk_D_86808808* var_v1;

    switch (D_86809A08) {
        case 1:
            for (i = 0, var_v1 = D_86808808; i < 12; i++, var_v1++) {
                var_v1->unk_004 |= 1;
            }
            break;

        case 2:
            for (i = 0, var_v1 = D_86808808; i < 12; i++, var_v1++) {
                var_v1->unk_004 &= ~1;
            }
            break;
    }

    D_86809A08 = 0;
}

void SushiGame_InitConveyorBelt(void) {
    s32 i;
    MainPoolState* temp_s2;
    unk_D_868084D8* var_s0;
    unk_func_80011B94* temp_a1;
    unk_D_86808808* ptr;
    Gfx* gfx = D_86807338;

    D_868084D4 = 0.0f;
    D_86809A08 = 0;
    D_86809A0C = 0;

    for (i = 0; i < 9; i++) {
        D_86809A0C += D_86807180[i].unk_12;
        D_86809A10[i] = 0;
    }

    D_868084D0 = 0;
    temp_s2 = MainPool_AllocState(main_pool_get_available(), 0);

    for (i = 0, ptr = D_86808808; i < 12; i++, ptr++) {
        SushiGame_InitConveyorCup(ptr, i);
        temp_a1 = GeoNode_CreateDisplayList(temp_s2, NULL, 4, D_868072C0);
        ptr->unk_018.node.flags |= 1;
        GraphNode_AppendChild(&ptr->unk_018, &temp_a1->display_node_header);
    }

    for (i = 0, var_s0 = D_868084D8; i < 12; i++, var_s0++) {
        var_s0->unk_40 = GeoNode_CreateScale(temp_s2, NULL, 5, gfx, &D_8006F050, var_s0->unk_2C);
        SushiGame_InitPlate(0, var_s0, i, NULL);
        GraphNode_AppendChild(&D_800AC840, var_s0->unk_40);
    }

    MainPool_FinalizeAllocation(temp_s2);
}

void SushiGame_UpdateConveyorBelt(void) {
    unk_D_86808808* ptr;
    unk_D_868084D8* var_s0;
    s32 i;

    if (D_86809A08 != 0) {
        SushiGame_ApplyGamePhase();
    }

    if (D_8780FC94 == 0) {
        D_868084D4 += 0.5f;
        if (D_868084D4 >= 360.0f) {
            D_868084D4 -= 360.0f;
        }
    }

    for (i = 0, ptr = D_86808808; i < 12; i++, ptr++) {
        SushiGame_UpdateConveyorCup(ptr);
    }

    for (i = 0, var_s0 = D_868084D8; i < 12; i++, var_s0++) {
        if (var_s0->unk_0C != 0) {
            SushiGame_UpdatePlate(var_s0);
        }
    }
}
