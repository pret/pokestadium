#ifndef _FRAGMENT62_H_
#define _FRAGMENT62_H_

#include "global.h"
#include "src/game_state.h"
#include "src/3D140.h"
#include "src/gfx_rect.h"
#include "src/stage_loader.h"
#include "src/fragments/demo_scenes/demo_scenes.h"
#include "src/fragments/particle_math/particle_math.h"

typedef s32 (*func_D_84390300)(void);
typedef void (*func_D_84390320)(void);

typedef struct unk_D_84390010_654_09C {
    /* 0x00 */ char unk00[0x10];
} unk_D_84390010_654_09C; // size = 0x10

typedef struct unk_D_84390010_654_0AC {
    /* 0x00 */ char unk00[0x10];
} unk_D_84390010_654_0AC; // size = 0x10

typedef struct unk_D_84390010_168 {
    /* 0x000 */ DisplayObject unk_000;
    /* 0x168 */ char unk168[0x1];
    /* 0x169 */ u8 unk_169;
    /* 0x16A */ s16 unk_16A;
    /* 0x16C */ s16 unk_16C;
    /* 0x16E */ char unk16E[0x2];
} unk_D_84390010_168; // size = 0x170

typedef struct BattlerState {
    /* 0x00 */ char unk00[0x4];
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ u32 unk_18;
    /* 0x1C */ u8 unk_1C;
    /* 0x1E */ u16 unk_1E;
    /* 0x20 */ char unk20[0x8];
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ u8 unk_2A;
    /* 0x2B */ u8 unk_2B;
    /* 0x2C */ u8 unk_2C;
    /* 0x2D */ u8 unk_2D;
    /* 0x2E */ u8 unk_2E;
    /* 0x2F */ u8 unk_2F;
    /* 0x30 */ u16 unk_30;
    /* 0x32 */ char unk32[0x2];
    /* 0x34 */ u16 unk_34;
    /* 0x36 */ u16 unk_36;
    /* 0x38 */ BattleMonRuntime unk_38;
    /* 0x9C */ unk_D_84390010_654_09C unk_9C;
    /* 0xAC */ unk_D_84390010_654_0AC unk_AC;
    /* 0xBC */ s16 unk_BC;
    /* 0xBE */ s16 unk_BE;
    /* 0xC0 */ char unkC0[1];
    /* 0xC1 */ u8 unk_C1[4];
    /* 0xC8 */ Controller* unk_C8;
} BattlerState; // size = 0xCC

typedef struct PresentationLayout {
    /* 0x00 */ DisplayNodeHeader node;
    /* 0x18 */ char unk18[0x4];
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ char unk22[0xA];
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ char unk30[0x4];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ char unk3C[0x6C];
    /* 0xA8 */ Vec3f unk_A8;
    /* 0xB4 */ Vec3f unk_B4;
} PresentationLayout; // size >= 0xC0

typedef struct PresentationState {
    /* 0x000 */ DisplayObject unk_000;
    /* 0x168 */ PresentationLayout* unk_168;
    /* 0x16C */ s32 unk_16C;
    /* 0x170 */ s32 unk_170;
    /* 0x174 */ char unk174[0x4];
    /* 0x178 */ s32 unk_178;
    /* 0x17C */ s32 unk_17C;
    /* 0x180 */ s32 unk_180;
    /* 0x184 */ s16 unk_184;
    /* 0x186 */ s16 unk_186;
    /* 0x188 */ f32 unk_188;
    /* 0x18C */ s32 unk_18C;
    /* 0x190 */ f32 unk_190;
    /* 0x194 */ f32 unk_194;
    /* 0x198 */ char unk198[0x4];
} PresentationState; // size = 0x19C

typedef struct MonCaptionState {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s8 unk_08[4];
    /* 0x0C */ char unk0C[0x3C];
    /* 0x48 */ s8 unk_48[4];
    /* 0x4C */ char unk4C[0x3C];
} MonCaptionState; // size = 0x88

typedef struct SpeciesLearnsetBuffer {
    /* 0x00 */ u8 unk_00[10];
    /* 0x0A */ u8 unk_0A[4];
    /* 0x0E */ char unk0E[0x12];
} SpeciesLearnsetBuffer; // size = 0x20

typedef struct SwayLayoutConfig {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ u8 unk_18;
    /* 0x19 */ u8 unk_19;
    /* 0x1A */ u8 unk_1A;
    /* 0x1B */ u8 unk_1B;
    /* 0x1C */ char unk1C[4];
} SwayLayoutConfig; // size = 0x20

typedef struct SwayState {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ SwayLayoutConfig unk_24;
    /* 0x44 */ s16 unk_44;
    /* 0x46 */ s16 unk_46;
    /* 0x48 */ char unk48[0x4];
    /* 0x4C */ f32 unk_4C;
} SwayState; // size >= 0x50

typedef struct Battler {
    /* 0x000 */ DisplayObject unk_000;
    /* 0x168 */ unk_D_84390010_168 unk_168[2];
    /* 0x448 */ SwayState unk_448;
    /* 0x498 */ f32 unk_498;
    /* 0x49C */ f32 unk_49C;
    /* 0x4A0 */ f32 unk_4A0;
    /* 0x4A4 */ s16 unk_4A4;
    /* 0x4A6 */ s16 unk_4A6;
    /* 0x4A8 */ s16 unk_4A8;
    /* 0x4AC */ s32 unk_4AC;
    /* 0x4B0 */ s32 unk_4B0;
    /* 0x4B4 */ s32 unk_4B4;
    /* 0x4B8 */ s32 unk_4B8;
    /* 0x4BC */ char unk4BC[0x4];
    /* 0x4C0 */ s32 unk_4C0;
    /* 0x4C4 */ s32 unk_4C4;
    /* 0x4C8 */ s32 unk_4C8;
    /* 0x4CC */ Vec3f unk_4CC;
    /* 0x4D8 */ Vec3f unk_4D8;
    /* 0x4E4 */ f32 unk_4E4;
    /* 0x4E8 */ u8 unk_4E8;
    /* 0x4E9 */ u8 unk_4E9;
    /* 0x4EC */ DisplayObject unk_4EC;
    /* 0x654 */ BattlerState unk_654;
    /* 0x720 */ BattleSessionTeams* unk_720;
    /* 0x724 */ TeamRoster* unk_724;
    /* 0x728 */ PresentationState unk_728;
    /* 0x8C4 */ MonCaptionState unk_8C4;
    /* 0x94C */ SpeciesLearnsetBuffer unk_94C;
    /* 0x96C */ SpeciesLearnsetBuffer unk_96C;
    /* 0x98C */ SpeciesLearnsetBuffer unk_98C;
    /* 0x9AC */ SpeciesLearnsetBuffer unk_9AC;
    /* 0x9CC */ SpeciesLearnsetBuffer unk_9CC;
    /* 0x9EC */ SpeciesLearnsetBuffer unk_9EC;
} Battler; // size = 0xA0C

typedef struct MovePresentationCue {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ u8 unk_0D;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ u8 unk_0F;
} MovePresentationCue; // size = 0x10

typedef struct unk_D_8438E7B0 {
    /* 0x000 */ MovePresentationCue unk_000[165];
    /* 0xA50 */ MovePresentationCue unk_A50;
    /* 0xA60 */ char unkA60[0x10];
    /* 0xA70 */ MovePresentationCue unk_A70;
    /* 0xA80 */ MovePresentationCue unk_A80;
    /* 0xA90 */ char unkA90[0x60];
    /* 0xAF0 */ MovePresentationCue unk_AF0;
    /* 0xB00 */ MovePresentationCue unk_B00;
    /* 0xB10 */ MovePresentationCue unk_B10;
    /* 0xB20 */ MovePresentationCue unk_B20;
    /* 0xB30 */ char unkB30[0x51];
    /* 0xB81 */ u8 unk_B81;
    /* 0xB82 */ char unkB82[0x5E];
} unk_D_8438E7B0; // size = 0xBE0

typedef struct BattleScene {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ s8 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ u16 unk_18;
    /* 0x1A */ u8 unk_1A;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ char unk28[0x2];
    /* 0x2A */ u16 unk_2A;
    /* 0x2C */ u16 unk_2C;
    /* 0x2E */ u16 unk_2E;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ u8 unk_54;
    /* 0x56 */ s16 unk_56;
    /* 0x58 */ s16 unk_58;
    /* 0x5A */ char unk5A[0x2];
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ char unk64[0x4];
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ f32 unk_74;
    /* 0x78 */ u8 unk_78;
    /* 0x7A */ s16 unk_7A;
    /* 0x7C */ char unk7C[0x8];
    /* 0x84 */ f32 unk_84;
    /* 0x88 */ char unk88[0xC];
    /* 0x94 */ Vec3f unk_94;
    /* 0xA0 */ Vec3f unk_A0;
    /* 0xAC */ char unkAC[0xC];
    /* 0xB8 */ Vec3f unk_B8;
    /* 0xC4 */ Vec3f unk_C4;
    /* 0xD0 */ Vec3f unk_D0;
    /* 0xDC */ unk_D_86002F34_00C* unk_DC;
} BattleScene; // size = 0xE0

typedef struct unk_D_84390240 {
    /* 0x00 */ BattleScene* unk_00;
    /* 0x04 */ char unk04[0x3C];
} unk_D_84390240; // size = 0x40

typedef void (*BattleSceneStateCallback)(Battler*);

typedef struct BattleSceneStateRow {
    /* 0x00 */ s16 unk_00;
    /* 0x04 */ BattleSceneStateCallback unk_04[7];
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
} BattleSceneStateRow; // size = 0x2C

typedef struct unk_D_843C4E44 {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ u8 unk_001;
    /* 0x3F2 */ char unk02[0x3F2];
} unk_D_843C4E44; // size >= 0x3F4

typedef struct unk_D_843C4DEC {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk04[0x54];
} unk_D_843C4DEC; // size = 0x58

typedef struct BattleSceneStateTickSlot {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ BattleSceneStateCallback unk_04;
} BattleSceneStateTickSlot; // size = 0x8

typedef struct TagTeamPartners {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk02[0xE];
} TagTeamPartners; // size = 0x10

typedef struct unk_D_84390178 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk04[0x14];
} unk_D_84390178; // size >= 0x18

typedef struct SpeciesModelTransform {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ char unk14[0xC];
} SpeciesModelTransform; // size = 0x20

typedef struct unk_D_84390028 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
} unk_D_84390028; // size = 0x10

typedef struct unk_D_84384608 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u16 unk_04;
} unk_D_84384608; // size = 0x8

typedef struct unk_D_843847BC {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s16 unk_14;
} unk_D_843847BC; // size = 0x18

typedef struct unk_D_843901B0 {
    /* 0x00 */Vec3f unk_00;
    /* 0x0C */s16 unk_0C;
    /* 0x0E */s16 unk_0E;
    /* 0x10 */char unk10[0x2];
    /* 0x12 */s16 unk_12;
    /* 0x14 */s16 unk_14;
    /* 0x18 */f32 unk_18;
    /* 0x1C */f32 unk_1C;
    /* 0x20 */s16 unk_20;
    /* 0x22 */s16 unk_22;
    /* 0x24 */char unk24[0x2];
    /* 0x26 */s16 unk_26;
    /* 0x28 */s16 unk_28;
    /* 0x2C */f32 unk_2C;
    /* 0x30 */f32 unk_30;
    /* 0x34 */f32 unk_34;
    /* 0x38 */f32 unk_38;
    /* 0x3C */f32 unk_3C;
} unk_D_843901B0; // size >= 0x40

typedef struct unk_D_843901A0_4C8 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ Vec3f unk_14;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s16 unk_28;
    /* 0x2A */ s16 unk_2A;
} unk_D_843901A0_4C8; // size = 0x2C

typedef struct unk_D_843901A0 {
    /* 0x000 */ u8 unk_000;
    /* 0x004 */ s32 unk_004;
    /* 0x008 */ u8 unk_008[4];
    /* 0x00C */ char unk00C[0x3C];
    /* 0x048 */ u8 unk_048[64];
    /* 0x088 */ s8 unk_088[64];
    /* 0x0C8 */ s8 unk_0C8[64];
    /* 0x148 */ s8 unk_108[64];
    /* 0x148 */ s8 unk_148[64];
    /* 0x188 */ s8 unk_188[64];
    /* 0x1C8 */ s8 unk_1C8[64];
    /* 0x208 */ s8 unk_208[64];
    /* 0x248 */ s8 unk_248[64];
    /* 0x288 */ s8 unk_288[64];
    /* 0x2C8 */ s8 unk_2C8[64];
    /* 0x2C8 */ s8 unk_308[64];
    /* 0x348 */ s8 unk_348[64];
    /* 0x388 */ s8 unk_388[64];
    /* 0x3C8 */ s8 unk_3C8[64];
    /* 0x408 */ s8 unk_408[64];
    /* 0x448 */ s8 unk_448[2][64];
    /* 0x4C8 */ unk_D_843901A0_4C8 unk_4C8;
} unk_D_843901A0; // size = 0x4F4

typedef struct unk_D_84385790 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Color_RGBA8 unk_04;
} unk_D_84385790; // size = 0x8

typedef struct arg1_func_84344CE8 {
    /* 0x00 */ char unk00[0x14];
    /* 0x14 */ u8* unk_14;
    /* 0x18 */ Gfx* unk_18;
} arg1_func_84344CE8; // size >= 0x1C

typedef struct arg1_func_8434E21C {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ u8* unk_04;
    /* 0x08 */ char unk08[0x2];
    /* 0x0A */ s16 unk_0A;
} arg1_func_8434E21C; // size >= 0xC

typedef struct RibbonMeshVertexState {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ Color_RGBA8 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
} RibbonMeshVertexState; // size = 0x1C

typedef struct RibbonMesh {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ f32 unk_004;
    /* 0x008 */ f32 unk_008;
    /* 0x00C */ f32 unk_00C;
    /* 0x010 */ f32 unk_010;
    /* 0x014 */ f32 unk_014;
    /* 0x018 */ s16 unk_018;
    /* 0x01A */ s16 unk_01A;
    /* 0x01C */ s16 unk_01C;
    /* 0x01E */ s16 unk_01E;
    /* 0x020 */ f32 unk_020;
    /* 0x024 */ s32 unk_024;
    /* 0x028 */ s32 unk_028;
    /* 0x02C */ s32 unk_02C;
    /* 0x030 */ s32 unk_030;
    /* 0x034 */ s32 unk_034;
    /* 0x038 */ s32 unk_038;
    /* 0x03C */ s32 unk_03C;
    /* 0x040 */ s32 unk_040;
    /* 0x044 */ s32 unk_044;
    /* 0x048 */ char unk048[0x8];
    /* 0x050 */ Vtx unk_050[31 * 2];
    /* 0x430 */ RibbonMeshVertexState unk_430[31 * 2];
} RibbonMesh; // size = 0xAF8

typedef struct unk_D_843975E8 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ char unk24[0x4];
} unk_D_843975E8; // size = 0x28

typedef struct Radial20Node {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ Vec3f unk_10;
    /* 0x1C */ Vec3f unk_1C;
    /* 0x28 */ char unk28[0x20];
} Radial20Node; // size = 0x48

typedef struct Radial20 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ s16 unk_004;
    /* 0x006 */ s16 unk_006;
    /* 0x008 */ s16 unk_008;
    /* 0x00A */ Color_RGBA8 unk_00A;
    /* 0x00E */ Color_RGB8 unk_00E;
    /* 0x014 */ f32 unk_014;
    /* 0x018 */ f32 unk_018;
    /* 0x01C */ Vtx* unk_01C;
    /* 0x020 */ char unk020[0x18];
    /* 0x038 */ s32 unk_038[3];
    /* 0x044 */ char unk044[0x4];
    /* 0x048 */ Radial20Node unk_048[20];
} Radial20; // size = 0x5E8

typedef struct Trail40Node {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
} Trail40Node; // size = 0x1C

typedef struct Trail40 {
    /* 0x0000 */ s16 unk_0000;
    /* 0x0002 */ s16 unk_0002;
    /* 0x0004 */ s16 unk_0004;
    /* 0x0008 */ f32 unk_0008;
    /* 0x000C */ Vtx* unk_000C;
    /* 0x0010 */ Mtx* unk_0010;
    /* 0x0014 */ Trail40Node unk_0014[16][16];
} Trail40; // size >= 0x1C14

typedef struct Trail40VariantNode {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ f32 unk_1C;
} Trail40VariantNode; // size = 0x20

typedef struct Trail40Variant {
    /* 0x0000 */ s16 unk_0000;
    /* 0x0002 */ s16 unk_0002;
    /* 0x0004 */ s16 unk_0004;
    /* 0x0008 */ f32 unk_0008;
    /* 0x000C */ Vtx* unk_000C;
    /* 0x0010 */ Mtx* unk_0010;
    /* 0x0014 */ Trail40VariantNode unk_0014[16][16];
} Trail40Variant; // size >= 0x2014

typedef struct TexturedRibbonSheetNode {
    /* 0x00 */ f32 unk_00;
    /* 0x08 */ u8 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ Vec3f unk_24;
    /* 0x30 */ Vtx unk_30[2];
} TexturedRibbonSheetNode; // size = 0x50

typedef struct TexturedRibbonSheet {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ s16 unk_004;
    /* 0x006 */ s16 unk_006;
    /* 0x008 */ s16 unk_008;
    /* 0x00A */ Color_RGB8 unk_00A;
    /* 0x010 */ f32 unk_010;
    /* 0x014 */ f32 unk_014;
    /* 0x018 */ Vtx* unk_018;
    /* 0x01C */ char unk01C[0x1C];
    /* 0x038 */ TexturedRibbonSheetNode unk_038[10];
} TexturedRibbonSheet; // size = 0x358

typedef struct FourStreamTrailNode {
    /* 0x00 */ u8 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ Vec3f unk_2C;
    /* 0x38 */ Vec3f unk_38;
} FourStreamTrailNode; // size = 0x44

typedef struct FourStreamTrail {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ s16 unk_004;
    /* 0x006 */ s16 unk_006;
    /* 0x008 */ Color_RGB8 unk_008;
    /* 0x00C */ f32 unk_00C;
    /* 0x010 */ f32 unk_010;
    /* 0x014 */ f32 unk_014;
    /* 0x018 */ Vtx* unk_018;
    /* 0x01C */ Vec3f unk_01C;
    /* 0x028 */ char unk028[0xC];
    /* 0x034 */ FourStreamTrailNode unk_034[15];
} FourStreamTrail; // size = 0x430

typedef struct OwnerLinkedFourStreamNode {
    /* 0x00 */ u8 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ Vec3f unk_2C;
    /* 0x38 */ Vec3f unk_38;
} OwnerLinkedFourStreamNode; // size = 0x44

typedef struct OwnerLinkedFourStream {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ s16 unk_004;
    /* 0x006 */ s16 unk_006;
    /* 0x008 */ Color_RGB8 unk_008;
    /* 0x00C */ f32 unk_00C;
    /* 0x010 */ f32 unk_010;
    /* 0x014 */ f32 unk_014;
    /* 0x018 */ Vtx* unk_018;
    /* 0x01C */ Vec3f unk_01C;
    /* 0x028 */ char unk028[0xC];
    /* 0x034 */ Particle* unk_034;
    /* 0x038 */ OwnerLinkedFourStreamNode unk_038[15];
} OwnerLinkedFourStream; // size = 0x434

typedef struct OwnerAnchoredFourStreamNode {
    /* 0x00 */ u8 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ Vec3f unk_2C;
    /* 0x38 */ Vec3f unk_38;
} OwnerAnchoredFourStreamNode; // size = 0x44

typedef struct OwnerAnchoredFourStream {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ s16 unk_004;
    /* 0x006 */ s16 unk_006;
    /* 0x008 */ Color_RGB8 unk_008;
    /* 0x010 */ f32 unk_00C;
    /* 0x010 */ f32 unk_010;
    /* 0x014 */ Vtx* unk_014;
    /* 0x018 */ Particle* unk_018;
    /* 0x01C */ OwnerAnchoredFourStreamNode unk_01C[15];
    /* 0x418 */ f32 unk_418;
} OwnerAnchoredFourStream; // size = 0x41C

typedef struct Trail50EffectNode {
    /* 0x00 */ u8 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ Vec3f unk_24;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ Vec3f unk_38;
    /* 0x44 */ Vec3f unk_44;
} Trail50EffectNode; // size = 0x50

typedef struct Trail50Effect {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ s16 unk_004;
    /* 0x006 */ s16 unk_006;
    /* 0x008 */ s16 unk_008;
    /* 0x00A */ Color_RGB8 unk_00A;
    /* 0x010 */ f32 unk_010;
    /* 0x014 */ f32 unk_014;
    /* 0x018 */ f32 unk_018;
    /* 0x01C */ char unk01C[0x4];
    /* 0x020 */ Vtx* unk_020;
    /* 0x024 */ Vec3f unk_024;
    /* 0x030 */ char unk030[0x10];
    /* 0x040 */ Trail50EffectNode unk_040[10];
} Trail50Effect; // size = 0x360

typedef struct unk_D_843C2C00_0B0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ Vec3f unk_10;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
} unk_D_843C2C00_0B0; // size = 0x28

typedef struct unk_D_843C2C00_064 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} unk_D_843C2C00_064; // size = 0xC

typedef struct unk_D_843C2C00_024 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
} unk_D_843C2C00_024; // size = 0x20

typedef struct unk_D_84389CE0 {
    /* 0x00 */ Color_RGBA8 unk_00;
    /* 0x04 */ u8 unk_04;
} unk_D_84389CE0; // size = 0x8

typedef struct DoubleTextureTrail {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ s16 unk_004;
    /* 0x008 */ f32 unk_008;
    /* 0x00C */ f32 unk_00C;
    /* 0x010 */ f32 unk_010;
    /* 0x014 */ f32 unk_014;
    /* 0x018 */ Vtx* unk_018;
    /* 0x01C */ s32 unk_01C;
    /* 0x020 */ s32 unk_020;
    /* 0x024 */ unk_D_843C2C00_024 unk_024;
    /* 0x044 */ unk_D_843C2C00_024 unk_044;
    /* 0x064 */ unk_D_843C2C00_064 unk_064;
    /* 0x070 */ unk_D_843C2C00_064 unk_070;
    /* 0x07C */ unk_D_84389CE0 unk_07C;
    /* 0x081 */ unk_D_84389CE0 unk_081;
    /* 0x086 */ Color_RGBA8 unk_086;
    /* 0x08C */ f32 unk_08C;
    /* 0x090 */ f32 unk_090;
    /* 0x094 */ s16 unk_094;
    /* 0x096 */ char unk096[0x1A];
    /* 0x0B0 */ unk_D_843C2C00_0B0 unk_0B0[10];
} DoubleTextureTrail; // size = 0x240

typedef struct AuxiliaryEffectNode {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ Vec3f unk_0C;
} AuxiliaryEffectNode; // size = 0x18

typedef struct AuxiliaryEffect {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ char pad002[2];
    /* 0x004 */ AuxiliaryEffectNode unk_004[20];
} AuxiliaryEffect; // size = 0x1E4

typedef struct unk_D_843C3508_0A4 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ Vec3f unk_18;
} unk_D_843C3508_0A4; // size = 0x24

typedef struct unk_D_843C3508 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ s16 unk_004;
    /* 0x006 */ s16 unk_006;
    /* 0x008 */ unk_D_84389CE0 unk_008;
    /* 0x00D */ unk_D_84389CE0 unk_00D;
    /* 0x014 */ f32 unk_014;
    /* 0x018 */ f32 unk_018;
    /* 0x01C */ s16 unk_01C;
    /* 0x020 */ s32 unk_020;
    /* 0x024 */ s32 unk_024;
    /* 0x028 */ unk_D_843C2C00_024 unk_028;
    /* 0x048 */ unk_D_843C2C00_024 unk_048;
    /* 0x068 */ unk_D_843C2C00_064 unk_068;
    /* 0x074 */ unk_D_843C2C00_064 unk_074;
    /* 0x080 */ f32 unk_080;
    /* 0x084 */ f32 unk_084;
    /* 0x088 */ Vtx* unk_088;
    /* 0x08C */ char unk08C[0x18];
    /* 0x0A4 */ unk_D_843C3508_0A4 unk_0A4[20];
} unk_D_843C3508; // size = 0x374

typedef struct StatStageMultiplier {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
} StatStageMultiplier; // size = 0x2

typedef struct TypeEffectivenessEntry {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
} TypeEffectivenessEntry; // size = 0x3

typedef struct BattleAiMonState {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05[1];
    /* 0x0C */ char unk06[0xC];
    /* 0x12 */ BattleMonRuntime unk_12;
} BattleAiMonState; // size = 0x76

typedef struct BattleAiTeamState {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01[2];
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04[2];
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07[1];
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A[1];
    /* 0x0B */ char unk0B[0x5];
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ u8 unk_11;
    /* 0x12 */ u8 unk_12;
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ BattleAiMonState unk_14[1];
} BattleAiTeamState; // size >= 0x8A

typedef struct unk_D_843C5568 {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ u8 unk_001;
    /* 0x002 */ u8 unk_002;
    /* 0x003 */ u8 unk_003;
    /* 0x004 */ u8 unk_004;
    /* 0x005 */ u8 unk_005;
    /* 0x006 */ u8 unk_006;
    /* 0x007 */ u8 unk_007;
    /* 0x008 */ u8 unk_008;
    /* 0x009 */ char unk009[0x3];
    /* 0x00C */ u8 unk_00C[1];
    /* 0x00D */ char unk00D[0x5];
    /* 0x012 */ u8 unk_012;
    /* 0x013 */ char unk013[0x3];
    /* 0x016 */ BattleAiMonState unk_016[1];
    /* 0x08C */ char unk08C[0x510];
} unk_D_843C5568; // size = 0x59C

typedef struct BattleAiScoredMove {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ s16 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
} BattleAiScoredMove; // size = 0x2C

typedef struct SpeciesLevelUpLearnset {
    /* 0x00 */ u8 unk_00[1];
    /* 0x01 */ char unk01[9];
    /* 0x0A */ u8 unk_0A[1];
    /* 0x0B */ char unk0B[0x15];
} SpeciesLevelUpLearnset; // size = 0x20

typedef struct AIDecisionScratch {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x04 */ s32 unk_04[1];
    /* 0x08 */ char unk08[0xC];
} AIDecisionScratch; // size = 0x14

typedef struct AIDifficultyConfig {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ u8 unk_0D;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ u8 unk_0F;
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ char unk11[0x3];
} AIDifficultyConfig; // size = 0x14

typedef struct unk_D_843C60F0 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ char unk03[0x9];
    /* 0x0C */ AIDecisionScratch unk_0C[3];
} unk_D_843C60F0; // size >= 0x48

typedef struct unk_D_843C6148 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk06[0x2];
} unk_D_843C6148; // size <= 0x8

typedef struct unk_func_8438220C {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk01[0x3];
    /* 0x04 */ BattleAiScoredMove unk_04[4];
    /* 0xB4 */ u8 unk_B4;
    /* 0xB8 */ s32 unk_B8;
} unk_func_8438220C; // size = 0xBC

typedef struct unk_func_8437F85C_arg3 {
    /* 0x00 */ u8 unk_00[3][3];
} unk_func_8437F85C_arg3; // size = 0x3

extern unk_D_8438E7B0* D_84384570[];
extern SpeciesModelTransform* D_84384578[];
extern SpeciesModelTransform* D_84384580[];
extern TagTeamPartners* D_84384588[];
extern u8 D_84384590[];
extern u8 D_843845F0;
extern u8 D_843845F4;
extern u8 D_843845F8;
extern u8 D_843845FC[];
extern s16 D_84384670[];
extern unk_D_843847BC D_843847BC[2];
extern unk_D_86B0C160 D_843847EC[3];
extern unk_D_86B0C160 D_84384888[2];
extern unk_D_86B0C160 D_843848F0;
extern unk_D_86B0C160 D_84384924;
extern unk_D_86B0C160 D_84384958;
extern unk_D_86B0C160 D_8438498C;
extern unk_D_86B0C160 D_843849C0[];
extern unk_D_86B0C160 D_84384AF8;
extern unk_D_86B0C160 D_84384B2C[];
extern Vec3f D_84384C30[];
extern BattleSceneStateCallback gBattleSceneStateTickSentinel;
extern BattleSceneStateRow gBattleSceneStateRowTable[];
extern Vec3f D_84385B90;
extern Vec3f D_84385B9C;
extern u32 D_84385BC0[];
extern Vtx D_84385C80[];
extern Vtx D_84385CC0[];
extern Vtx D_84385D00[];
extern Vtx D_84385D40[];
extern Vtx D_84385DC0[];
extern Vtx D_84385E00[];
extern ParticleDescriptor gBattleAnimParticleDescriptors[86];
extern func_D_84390320 gMoveAnimEffectStartFuncs[];
extern func_D_84390320 gMoveAnimEffectEndFuncs[];
extern func_D_84390320 gMoveAnimEffectStartUpdateFuncs[];
extern func_D_84390320 gMoveAnimEffectEndUpdateFuncs[];
extern func_D_84390320 gMoveAnimEffectStartDrawFuncs[];
extern func_D_84390320 gMoveAnimEffectEndDrawFuncs[];
extern Gfx D_84389AE0[];
extern u32 D_8438A648[];
extern Gfx D_8438A980[];
extern u8 D_8438AC60[];
extern StatStageMultiplier gStatStageMultipliers[];
extern u8 D_8438ACD4[];
extern u8 gTypeEffects[];
extern u8* D_8438E778;
extern u8* D_8438E77C;

extern u8 gBattleMoveFailed;
extern u8 gBattleCritFlag;
extern u8 D_843C4DA9;
extern u8 D_843C4DAA;
extern s32 D_843C4DEC;
//extern unk_D_843C4E44 D_843C4E44;
extern u8 D_843C4E44;
extern u8 D_843C4E45;
extern u16 gBattleDamage;
extern BattleMonRuntime* gBattleUser;
extern BattleMonRuntime* gBattleTarget;


extern Battler* D_84390010[2];
extern Battler* D_84390018;
extern Battler* D_8439001C;
extern unk_D_84390028 D_84390028[2];
extern f32 D_843900A8[];
extern char** D_843900B0;
extern char** D_843900B4;
extern char** D_843900B8;
extern char** D_843900BC;
extern char** D_843900C0;
extern f32 D_84390124;
extern f32 D_84390128;
extern u8 D_84390134;
extern s32 D_84390174;
extern unk_D_84390178 D_84390178;
extern Vec3f D_84390190;
extern unk_D_843901A0* gBattleMessageQueues;
extern unk_D_843901B0 D_843901B0;
extern Battler* D_84390200;
extern Battler* D_84390204;
extern s32 D_8439022C;
extern s32 D_84390230;
extern s32 D_84390234;
extern unk_D_84390240 gBattleScene;
extern s32 D_84390288;
extern s32 gBattleAnimFrameCounter;
extern s32 gBattleAnimSpawnDelay;
extern s16 gBattleAnimCurrentAnchor;
extern s16 gBattleAnimDefaultAnchor;
extern Battler* gBattleAnimCurrentOwner;
extern Battler* gBattleAnimSecondaryOwner;
extern Battler* gBattleAnimTertiaryOwner;
extern s32 D_843902F4;
extern s32 D_843902F8;
extern func_D_84390300 gBattleAnimEffectUpdateFuncs[8];
extern func_D_84390320 gBattleAnimEffectDrawFuncs[8];
extern s32 D_84390340;
extern Vec3f D_84390348;
extern s16 D_8439037A;
extern s16 D_8439037C;
extern s16 D_8439037E;
extern s16 D_84390380;
extern s16 D_84390382;
extern s16 D_84390384;
extern s16 D_84390386;
extern s16 D_84390388;
extern s16 D_8439038A;
extern s16 D_8439038C;
extern s16 D_8439038E;
extern s16 D_84390390;
extern s16 D_84390392;
extern s16 D_84390394;
extern s16 D_84390396;
extern s16 D_84390398;
extern s16 D_8439039A;
extern s16 D_8439039C;
extern s16 D_8439039E;
extern s16 D_843903A0;
extern f32 D_84392058[26];
extern u8* gBattleAnimAssetPointers[256];
extern s16 gBattleAnimResourceList[0x10];
extern arg1_func_80019420* gBattleAnimResourceTablePointers[40];



s32 Battle_StageGeoDispatchCallback(s32 arg0, GraphNode* arg1);
s32 Battle_StageLightAngleCallbackA(s32 arg0, unk_D_86002F34_alt18* arg1);
s32 Battle_StageLightAngleCallbackB(s32 arg0, unk_D_86002F34_alt18* arg1);
s32 Battle_StageMaterialTintCallback(s32 arg0, DisplayObject* arg1);
void Battle_SetStageTintColor(u8 arg0, u8 arg1, u8 arg2);
void BattleScene_SetModelUniformScale(f32 arg0);
u16 Battle_TintTexel16(u16 arg0);
void Battle_DrawStageBackdrop(void);
void Battle_RenderStageThumbnail(GraphNode* arg0, unk_D_80068BB0* arg1);
void Battle_DrawClippedTextureRect(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void Battle_DrawTexturedRectSegment(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4, s32 arg5);
void Battle_DrawFaintOrderMarker(GraphNode* arg0, unk_D_80068BB0* arg1);
void func_84300D44(void);
void func_84300DC0(void);
void func_84300E78(void);
void func_84300E80(void);
s32 BattleScene_UpdateFrame(s32 arg0);
s32 BattleScene_UpdatePausedFrame(s32 arg0);
void Battle_UpdateCompletionGate(void);
s32 Battle_FrameCallback(s32 arg0);
void func_8430123C(u8* arg0, s32 arg1);
void func_8430128C(void);
void BattleScene_InitializeParticipantPresentation(BattleSessionTeams* arg0, unk_D_86002F30* arg1);
void func_84301430(unk_func_80007444* arg0);
void func_84301A24(void);
s32 Battle_Main(s32 arg0, SessionContext* arg1);

void BattleScene_ClearStateTickCallbacks(void);
void BattleScene_QueueRowEffectList3(Battler* arg0, s32 arg1);
void BattleAnim_PlayMoveEffectScriptA(Battler* arg0, s32 arg1);
void BattleAnim_PlayMoveEffectScriptB(Battler* arg0, s32 arg1);
void BattleAnim_PlayMoveEffectEnd(Battler* arg0, s32 arg1);
void BattleScene_TickClearAnimRecordIfLoaded(Battler* arg0);
void BattleScene_TickStartRowAnimRecord(Battler* arg0);
void BattleScene_TickQueueRowEffectList3AtAnimEnd(Battler* arg0);
void BattleScene_ResetStateFrameCounter(Battler* arg0);
void BattleScene_ResetOpponentStateFrameCounter(Battler* arg0);
void BattleAnim_SetOverlayFlagForSpecialMoves(Battler* arg0);
void BattleAnim_ClearOverlayFlag(Battler* arg0);
s32 BattleAnim_IsAssetLoadBusy(Battler* arg0);
s32 BattleAnim_PollAssetLoadBusyFlags(Battler* arg0);
s32 BattleAnim_IsSessionBusy(Battler* arg0);
s32 BattleAnim_TryRegisterAssetTables(Battler* arg0);
void BattleScene_LoadMoveResourceList(Battler* arg0);
void BattleScene_LoadRowResourceList(Battler* arg0);
void BattleScene_ReloadMoveResourceList(Battler* arg0);
void BattleAnim_BeginSessionRequest(Battler* arg0);
void BattleAnim_BeginSessionRequestForActiveMon(Battler* arg0);
s32 BattleScene_FindU16InByteArray(u16 arg0, u8* arg1, s32 arg2);
void Battle_FilterUnusableMoves(Battler* arg0, u16 arg1, SpeciesLearnsetBuffer* arg2, SpeciesLearnsetBuffer* arg3);
void Battle_InitializeMoveUsabilityMask(Battler* arg0);
void Battle_DmaLoadAnimRecord(u8 arg0, u32 arg1);
void Battle_DmaLoadAnimRecordPair(s32 arg0, SpeciesLearnsetBuffer* arg1, SpeciesLearnsetBuffer* arg2);
void func_84302658(Battler* arg0, s32 arg1);
void BattleScene_TickRow10CleanupAndEnterState18(Battler* arg0);
void BattleScene_EnterRow3StartMoveAnim(Battler* arg0);
void BattleScene_TickRow3PlayMoveEffectScript(Battler* arg0);
void BattleScene_TickRow3PostEffectCamera(Battler* arg0);
void BattleScene_TickRow3QueueEffectList6(Battler* arg0);
void func_843031A0(Battler* arg0);
void BattleScene_EnterRow21StartAnimRecord0(Battler* arg0);
void BattleScene_TickRow21PlaySpeciesSound(Battler* arg0);
void BattleScene_EnterRow19StartMoveAnimMidFrame(Battler* arg0);
void BattleScene_TickRow19PlayMoveEffectScript(Battler* arg0);
void BattleScene_TickRow19PostEffectCamera(Battler* arg0);
void BattleScene_EnterRow4StartHitReactionAnim(Battler* arg0);
void BattleScene_TickPlayMoveEffectEnd(Battler* arg0);
void BattleScene_TickRow4PostEndCamera(Battler* arg0);
void BattleScene_EnterRow15StartAnimA80Seq30(Battler* arg0);
s32 BattleScene_IsOpponentRowCheckpointReached(Battler* arg0);
s32 BattleScene_IsRowZeroCheckpointReached(Battler* arg0);
void func_84303E58(Battler* arg0);
void BattleScene_EnterRowAnim166WithCry(Battler* arg0);
void BattleScene_TickRow1PlayOwnerCry(Battler* arg0);
void BattleScene_TickRow16PlayCryAndSpeciesSound(Battler* arg0);
void BattleScene_TickRow18PlayCryAndSpeciesSound(Battler* arg0);
void BattleScene_TickAssetLoadQueueRowEffectList3(Battler* arg0);
void func_843046BC(Battler* arg0);
void BattleScene_TickRow20CleanupAndEnterState18(Battler* arg0);
void func_84304800(Battler* arg0);
void BattleScene_EnterRow8StartMappedMoveAnim(Battler* arg0);
void BattleScene_TickRow8PlayMoveEffectScriptB(Battler* arg0);
void BattleScene_EnterRow9SetEventTrack(Battler* arg0);
void BattleScene_EnterRow9QueueEffectList6(Battler* arg0);
void BattleScene_Row12Slot1CameraCleanup(Battler* arg0);
void BattleScene_Row13PlaySequences14And21(Battler* arg0);
void BattleScene_TickPlaySpeciesSequence33(Battler* arg0);
void BattleScene_TickQueueList3Selector2OrC(Battler* arg0);
void BattleScene_TickQueueList3Selector2OrCFromB10(Battler* arg0);
void func_8430506C(Battler* arg0);
void BattleScene_TickRow14PlayMoveEffectEnd(Battler* arg0);
s32 func_84305458(Battler* arg0);
void BattleScene_TickRow11QueueEffectList6(Battler* arg0);
void BattleScene_TickRow11PostEndCamera(Battler* arg0);
void BattleScene_StateCallbackNop(Battler* arg0);
void BattleScene_RegisterStateTickCallback(Battler* arg0, BattleSceneStateCallback arg1);
void BattleScene_SetOpponentEventTrackA6(Battler* arg0);
void BattleScene_EnterStateRow(Battler* arg0, s32 arg1);
void BattleScene_TickStateCallbacks(void);
void Battle_ResetCryEventIfStruggle(Battler* arg0);
void BattleAnim_SetModelEventTrackFromRow(Battler* arg0, s32 arg1);
s32 BattleAnim_TrySetModelEventTrackFromRow(Battler* arg0, s32 arg1, s32 arg2);
void BattleAnim_SetModelEventTrackAndState(Battler* arg0, s32 arg1, s32 arg2);
s32 BattleScene_IsParticipantIncapacitated(Battler* arg0);
s32 BattleScene_IsRowWaitComplete(Battler* arg0, s32 arg1);
s32 BattleScene_IsRowWaitCompleteWithEventCount(Battler* arg0, s32 arg1);
s32 Battle_IsRowAnimationSettled(Battler* arg0, s32 arg1);
s32 BattleScene_IsMoveKeyedRowWaitComplete(Battler* arg0, s32 arg1);
s32 BattleScene_IsRowAnimWaitComplete(Battler* arg0, s32 arg1);
void func_843060EC(Battler* arg0);
void Battle_SetRuntimeFlags(Battler* arg0, u16 arg1);
s32 Battle_ClearRuntimeFlags(Battler* arg0, u16 arg1);
void BattleScene_ResetParticipantAnimationFlags(Battler* arg0);
void BattleScene_ResetBothParticipantsAnimationState(void);
void Battle_ClearOpponentHopFlagAndSyncMove(Battler* arg0);
void BattleScene_CleanupParticipantHideFlag(Battler* arg0);
void BattleScene_CleanupOpponentSpecialAnimFlag(Battler* arg0);
void BattleScene_CleanupOpponentAnimationFlags(Battler* arg0);
void BattleScene_CleanupParticipantEffectMode(Battler* arg0);
void BattleAnim_TickParticipantStatusAnimation(Battler* arg0);
void BattleAnim_TriggerStatusAfflictionCry(Battler* arg0);
void BattleScene_AllocateParticipantRecord(BattleSessionTeams* arg0, s32 arg1);
void BattleScene_AllocateParticipants(BattleSessionTeams* arg0);
void BattleScene_InitializeParticipantController(Battler* arg0);
void BattleScene_InitializeParticipantModel(Battler* arg0);
void BattleScene_InitializeParticipantOwnerModel(Battler* arg0);
void BattleScene_InitializeParticipantSecondaryModels(Battler* arg0, s32* arg1);
void BattleScene_InitializeParticipantAuxiliaryModel(Battler* arg0);
void BattleScene_InitializePresentation(BattleSessionTeams* arg0);
void BattleScene_ResetParticipantAuxTransform(Battler* arg0, Battler* arg1, s32 arg2);
void BattleScene_InitializeRuntime(BattleSessionTeams* arg0);
void BattleScene_UpdateParticipantsAndQueueEffects(Battler* arg0, Battler* arg1);
s32 BattleScene_DispatchLifecycle(s32 arg0, BattleSessionTeams* arg1);
void func_84307414(Battler* arg0);
void BattleScene_StateRow56EnterNop(Battler* arg0);
void BattleScene_StateRow5Slot3Nop(Battler* arg0);
void BattleScene_StateRow5Slot4Nop(Battler* arg0);
void BattleScene_StateRow5Slot5Nop(Battler* arg0);
void BattleScene_StateRow5Slot6Nop(Battler* arg0);
void BattleScene_StateRow7Slot5Nop(Battler* arg0);
void BattleScene_StateRow6Slot6Nop(Battler* arg0);
void BattleScene_StateRow6Slot5Nop(Battler* arg0);
void BattleScene_StateRow6Slot4Nop(Battler* arg0);
void BattleScene_StateRow6Slot3Nop(Battler* arg0);
void func_8430746C(Battler* arg0);
void func_84307474(Battler* arg0, s32 arg1);
void func_84307480(Battler* arg0, s32 arg1);
void BattleScene_StateRow7Slot4Nop(Battler* arg0);


void BattleScene_TriggerOwnerModelAnimation(Battler* arg0);
void BattleScene_ClearParticipantOwnerActiveFlag(Battler* arg0);
void BattleScene_SetParticipantOwnerActiveFlag(Battler* arg0);
void BattleScene_ClearBothOwnerActiveFlags(void);
void BattleScene_SetBothOwnerActiveFlags(void);
void BattleScene_SetOwnerPoseFlag(PresentationLayout* arg0);
void BattleScene_LoadOwnerCameraFramingConstants(Battler* arg0);
void BattleScene_SetupOwnerCameraFraming(Battler* arg0, Battler* arg1);
void BattleScene_OwnerCameraLifecycleNop(void);
void BattleScene_ApplyOwnerCameraFraming(Battler* arg0);
void BattleScene_TickOwnerCameraFraming(Battler* arg0);
void BattleScene_InitializeOwnerCameraFraming(unk_D_86002F34_00C* arg0, Battler* arg1, unk_D_86002F34_00C* arg2, Battler* arg3);
void BattleScene_TickOwnerSlideIn(Battler* arg0, s32 arg1);
void BattleScene_TickOwnerSlideOut(Battler* arg0, s32 arg1);
void BattleScene_TickOwnerSlideAnimation(Battler* arg0);
void BattleScene_TickBothOwnerSlideAnimations(Battler* arg0, Battler* arg1);
s32 BattleScene_DispatchOwnerCameraLifecycle(s32 arg0, unk_D_86002F34_00C* arg1, unk_D_86002F34_00C* arg2);

s32 BattleScene_ByteArrayContains(u8 arg0, u8* arg1, s32 arg2);
BattleMon* BattleScene_GetParticipantSessionMon(Battler* arg0);
s32 BattleScene_IsPartnerPikachu(Battler* arg0);
f32 BattleScene_GetParticipantModelHeight(Battler* arg0);
f32 BattleScene_GetParticipantModelRadius(Battler* arg0);
f32 BattleScene_GetParticipantModelWidth(Battler* arg0);
f32 BattleScene_GetParticipantEyeHeight(Battler* arg0);
void BattleScene_PositionParticipantModel(Battler* arg0);
f32 BattleScene_GetParticipantModelXOffset(Battler* arg0);
void BattleScene_SetParticipantModelScale(Battler* arg0, f32 arg1);
s32 BattleScene_GetSelectedSideTeamSize(Battler* arg0);
s32 BattleScene_GetOpposingSelectedSideTeamSize(Battler* arg0);
s32 BattleScene_GetParticipantSideIndex(Battler* arg0);
u8 Battle_GetCameraShotFieldB(Battler* arg0);
u8 Battle_GetCameraShotFieldC(Battler* arg0);
s16 Battle_GetSideAnimTableFieldB(Battler* arg0);
s32 Battle_GetSideAnimTableFieldC(Battler* arg0);
f32 Battle_GetScaledHeightY(Battler* arg0);
f32 Battle_GetScaleRatio(Battler* arg0);
s16 BattleScene_GetActiveAnimRowId(Battler* arg0);
void BattleScene_GetParticipantModelBoundsScaled(Battler* arg0, Vec3f* arg1);
void BattleScene_GetParticipantModelRotation(Battler* arg0, Vec3s* arg1);
u16 Battle_GetActiveMonHp(Battler* arg0);
s16 BattleScene_GetParticipantFacingAngle(Battler* arg0);
s32 BattleAnim_GetSpeciesBySideIndex(s32 arg0);
s32 BattleAnim_GetOwnerSpecies(Battler* arg0);
u8 BattleScene_IsParticipantModelVisible(Battler* arg0);
void BattleScene_GetParticipantModelPosition(Battler* arg0, Vec3f* arg1);
void BattleAnim_GetOwnerDefaultAnchorPosition(Battler* arg0, Vec3f* arg1);
void BattleScene_ComputeParticipantModelOffset(Battler* arg0, Vec3f* arg1);
void BattleScene_GetParticipantAuxiliaryModelPosition(Battler* arg0, Vec3f* arg1);
f32 BattleAnim_GetOwnerModelHeight(Battler* arg0);
f32 BattleScene_GetParticipantModelRadiusScaled(Battler* arg0);
ModelNodeView* Battle_GetMoveEffectListEntry(Battler* arg0, s32 arg1);
s32 Battle_GetTrainerId(Battler* arg0, UNUSED s32 arg1);
char* Battle_GetActiveMoveName(Battler* arg0);
u8* Battle_GetActiveMonNickname(Battler* arg0);
void BattleScene_SetParticipantModelFlags(Battler* arg0, s32 arg1, s32 arg2);
void Battle_AdvanceSecondaryModelAnimIfFinished(Battler* arg0, Battler* arg1);
void Battle_ResetModelToIdleAnim(Battler* arg0);
void Battle_SetModelToStatusAnim(Battler* arg0);
void BattleScene_BindParticipantRosterForSide(Battler* arg0, s32 arg1);
void BattleScene_SetParticipantSelectedSide(Battler* arg0, s32 arg1);
void BattleScene_SetParticipantController(Battler* arg0, Controller* arg1);
void BattleScene_RebindParticipantToSide(Battler* arg0, s32 arg1);
s32 Battle_HasUsableSleepStatusTarget(Battler* arg0);
s32 Battle_HasUsableMajorStatusTarget(Battler* arg0);
s32 BattleScene_GetCombinedTeamSize(Battler* arg0);
u8 BattleScene_GetRosterTeamSize(TeamRoster* arg0);
s32 BattleScene_GetParticipantDisplayPlayerNumber(Battler* arg0);
void BattleScene_ReinitParticipantBodyModel(Battler* arg0, Battler* arg1, s32 arg2, s32 arg3);
void BattleScene_ReinitParticipantOwnerModel(Battler* arg0, PresentationState* arg1, s16 arg2);
void BattleScene_ReinitParticipantSecondaryModels(Battler* arg0, s16 arg1);
void Battle_ResetEventTrack(Battler* arg0);
void Battle_LoadOwnerModelForSpecies(Battler* arg0);
void Battle_LoadOwnerModelForSwitchIn(Battler* arg0);
void Battle_ResetOwnerModelToNeutralPlaceholder(Battler* arg0);
void Battle_ReloadNeutralPlaceholderModel(Battler* arg0);
void Battle_ReloadModelForActiveMove(Battler* arg0);


void BattleAnim_InitSwayOffset(Battler* arg0, f32 arg1, s16 arg2);
void BattleAnim_UpdateSwayPhysicsToOwner(Battler* arg0, Battler* arg1, f32 arg2, f32 arg3, s32 arg4);
void BattleAnim_UpdateSwayPhysicsToTarget(UNUSED Battler* arg0, Battler* arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5);
void BattleScene_HideParticipantSecondaryModels(Battler* arg0);
void BattleScene_ShowSecondaryModelsAtMainTransform(Battler* arg0);
void BattleScene_UpdateSecondaryModelOrbit(Battler* arg0);
void BattleScene_ShowSecondaryModelsAtMainPose(Battler* arg0);
s32 BattleScene_ShrinkSecondaryModelsToScale(Battler* arg0);
void BattleScene_ShowSecondaryModelsStaggeredFrame(Battler* arg0);
void BattleScene_UpdateSecondaryModelTrailPosition(Battler* arg0, s16 arg1);
void BattleScene_ResetParticipantModelFlags(Battler* arg0);
void BattleAnim_StatusIdleCase1Sub0(UNUSED Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase1Sub1(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase1(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase2Sub0(UNUSED Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase2Sub1(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase2(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase3Sub0(UNUSED Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase3Sub1(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase3(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase14Sub0(UNUSED Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase14Sub1(Battler* arg0, Battler* arg1);
void func_8430A4E0(UNUSED Battler* arg0, UNUSED Battler* arg1);
void BattleAnim_StatusIdleCase14(Battler* arg0, Battler* arg1);
s32 BattleAnim_ApproachAngleAndCheckThreshold(Battler* arg0, s16 arg1, s16 arg2);
void BattleAnim_StatusIdleCase4Sub0(UNUSED Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase4Sub1(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase4Sub2(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase4(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase5Sub0(UNUSED Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase5Sub1(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase5Sub2(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase5(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase6Sub0(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase6Sub1(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase6Sub2(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase6(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase7Sub0(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase7Sub1(UNUSED Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase7(Battler* arg0, Battler* arg1);
void BattleAnim_ResetOwnerFacingAndExitStatusIdle(Battler* arg0);
void BattleAnim_StatusIdleCase8Sub0(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase8Sub1(UNUSED Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase8(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase9Sub0(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase9Sub1(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase9(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase12Sub0(UNUSED Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase12Sub1(Battler* arg0, UNUSED Battler* arg1);
void BattleAnim_StatusIdleCase12(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase13Sub0(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase13Sub1(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase13Sub2(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase13(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase15Sub0(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase15Sub1(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase15(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase16Sub0(UNUSED Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase16Sub1(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase16(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase10Sub0(UNUSED Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase10Sub1(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase10(Battler* arg0, Battler* arg1);
void BattleAnim_StatusIdleCase0(UNUSED Battler* arg0, UNUSED Battler* arg1);
void BattleAnim_UpdateOwnerStatusIdleAnimation(s32 arg0);
void BattleAnim_SetOwnerSecondaryStatusFlags(Battler* arg0, u8 arg1, u8 arg2);
void BattleAnim_ClearOwnerSecondaryStatusFlags(Battler* arg0);
void BattleAnim_InitSecondarySwayOffset(Battler* arg0, f32 arg1, s16 arg2);
void BattleAnim_UpdateSecondarySwayPhysics(Battler* arg0, Battler* arg1, f32 arg2, f32 arg3, s32 arg4);
void BattleAnim_SecondaryStatusCaseBSub0(Battler* arg0, Battler* arg1);
void BattleAnim_SecondaryStatusCaseBSub1(Battler* arg0, Battler* arg1);
void BattleAnim_SecondaryStatusCaseB(Battler* arg0, Battler* arg1);
void BattleAnim_SecondaryStatusDefault(Battler* arg0, Battler* arg1);
void BattleAnim_UpdateOwnerSecondaryStatusAnimation(s32 arg0);


void BattleAnim_CalculateDistanceAngles(Vec3f* arg0, Vec3f* arg1, f32* arg2, s16* arg3, s16* arg4);
Vec3f* BattleAnim_Vec3fSetZero(Vec3f* arg0);
Vec3f* BattleAnim_Vec3fOffsetByPolarXZ(Vec3f* arg0, Vec3f* arg1, f32 arg2, s16 arg3);
void BattleAnim_Vec3fSetPolarXZ(Vec3f* arg0, f32 arg1, s16 arg2);
Vec3f* BattleAnim_Vec3fCopy(Vec3f* arg0, Vec3f* arg1);
Vec3s* BattleAnim_Vec3sCopy(Vec3s* arg0, Vec3s* arg1);
Vec3f* BattleAnim_Vec3fScaleComponents(Vec3f* arg0, f32 arg1, f32 arg2, f32 arg3);
s16 BattleAnim_Atan2sFromPoints(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
f32 BattleAnim_Vec3fDistance(Vec3f arg0, Vec3f arg1);
f32 BattleAnim_Distance2D(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
s32 BattleAnim_RandomIntWithWarmup(f32 arg0);
u16 BattleAnim_RandomRange(s32 arg0);
s32 BattleAnim_StepToS16(s16* arg0, s16 arg1, s16 arg2);
s32 BattleAnim_StepToS16VariableRate(s16* arg0, s16 arg1, f32 arg2);
void BattleAnim_ApproachF(f32* arg0, f32 arg1, f32 arg2);
void BattleAnim_ApproachS16(s16* arg0, s16 arg1, s16 arg2);
void BattleAnim_ApproachU16(u16* arg0, u16 arg1, s16 arg2);
void Battle_ComputeSplineWeightsVariantA(f32* arg0, f32 arg1);
void Battle_ComputeSplineWeightsVariantB(f32* arg0, f32 arg1);
void Battle_ComputeSplineWeightsVariantC(f32* arg0, f32 arg1);
void Battle_ComputeSplineWeightsVariantD(f32* arg0, f32 arg1);
void Battle_ComputeSplineWeightsVariantE(f32* arg0, f32 arg1);


void BattleScene_InitializePresentationTimers(void);
void BattleScene_QuantizePresentationTimer(void);
s32 BattleScene_TickPresentationTimer(void);
s32 BattleScene_IsPresentationCountdownComplete(void);
s32 Battle_ClassifyHpTier(s32 arg0, s32 arg1);
s32 BattleScene_DetermineWinner(void);
s32 BattleScene_UpdateResultPresentation(void);
s32 BattleScene_IsActionSelectionTimerExpired(void);
void BattleScene_ResetActionSelectionTimer(void);
s32 BattleScene_TickActionSelectionTimers(void);
void BattleScene_ResetActionSelectionTimers(void);
s32 BattleScene_ApplyForcedActionDelay(Battler* arg0);
void BattleScene_SyncActiveHpToPartyState(void);
s32 BattleScene_SelectFallbackWhenNoUsableMoves(Battler* arg0);
s32 BattleScene_IsMoveUnavailable(Battler* arg0, s32 arg1);
void BattleScene_AutoSelectAvailableMove(Battler* arg0);
void BattleScene_AutoSelectReplacementMon(Battler* arg0);
void BattleScene_SelectActiveController(Battler* arg0);
void BattleScene_HandleActionSelectionCancel(s32 arg0);
void Battle_InitializeActiveRuntimeState(void);
s32 BattleScene_CpuHasNoUsableMoves(Battler* arg0);
s32 BattleScene_WaitForCpuChoice(Battler* arg0, Battler* arg1);
void BattleScene_CompleteCpuForcedAction(Battler* arg0, UNUSED Battler* arg1);
void BattleScene_CompleteCpuMoveAction(Battler* arg0, Battler* arg1);
void BattleScene_ApplyCpuChoice(Battler* arg0, Battler* arg1);
s32 BattleScene_ApplyCpuSwitchChoice(Battler* arg0, Battler* arg1);
s32 BattleScene_CollectCpuAction(Battler* arg0, Battler* arg1);
void BattleScene_ForfeitPrompt(Battler* arg0);
void BattleScene_CommitPlayerSwitchAction(Battler* arg0);
s32 BattleScene_ValidateSelectedPartyMember(Battler* arg0);
void BattleScene_QueuePartySelectionConfirmMessage(Battler* arg0);
void BattleScene_AssignActiveCoopController(Battler* arg0, s32 arg1);
void BattleScene_HandlePartySlotCursorInput(Battler* arg0, Controller* arg1);
void BattleScene_HandlePlayerPartySelection(Battler* arg0);
void BattleScene_CommitSelectedMoveAction(Battler* arg0);
s32 BattleScene_HandleNoUsableMoveSelection(Battler* arg0);
s32 BattleScene_ValidateSelectedMove(Battler* arg0);
void BattleScene_SelectMoveFromButtons(Battler* arg0);
void BattleScene_HandlePlayerMoveSelection(Battler* arg0);
s32 BattleScene_HandlePlayerMoveSelectionLocked(Battler* arg0, UNUSED Controller* arg1);
void BattleScene_ConfirmForcedMoveRepeat(Battler* arg0);
void BattleScene_PollActionMenuRequestButtons(Battler* arg0);
s32 BattleScene_HandlePlayerActionInput(Battler* arg0);
s32 BattleScene_HandlePlayerForcedActionState(Battler* arg0, Battler* arg1);
void BattleScene_ShowParticipantOwnerAndSecondaryModels(void);
void BattleScene_HideParticipantOwnerAndSecondaryModels(void);
void BattleScene_AdvanceAttractInputScript(void);
void BattleScene_CheckForcedActionCondition(Battler* arg0, Battler* arg1);
void BattleScene_TickAttractModeInput(void);
void BattleScene_CollectPlayerAction(Battler* arg0, Battler* arg1);
void BattleScene_CollectActions(void);
void BattleScene_UpdateActionCollection(void);
void BattleScene_UpdateActionSelectPhase(void);


void func_8430FC10(void);
void BattleHud_DrawTranslucentShadowRect(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void BattleHud_DrawGradientRect(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGB8* arg4, Color_RGB8* arg5);
void Battle_DrawGradientRectWrapper(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGB8* arg4, Color_RGB8* arg5);
void func_84310360(void);
void BattleHud_DrawHpBar(s32 arg0, s32 arg1, f32 arg2, s32 arg3);
void func_843109EC(void);
void BattleHud_DrawLevelNumber(s32 arg0, s32 arg1, s32 arg2);
void BattleHud_DrawHpFractionText(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void BattleHud_DrawSpeciesNameLabel(s16 arg0, s16 arg1, s32 arg2, char* arg3, s32 arg4);
void BattleHud_DrawSpeciesNameLabelBlink(s16 arg0, s16 arg1, s32 arg2, u8* arg3, s32 arg4, s32 arg5);
void BattleHud_DrawSpeciesNameLabelAuto(Battler* arg0, TeamRoster* arg1, s16 arg2, s16 arg3, s32 arg4, u16 arg5, s32 arg6);
void BattleHud_DrawMonInfoPanel(Battler* arg0, BattleMon* arg1, unk_D_84385790* arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA);
s32 BattleHud_DrawBorderTile(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4);
void func_84311420(void);
void BattleHud_DrawBoxBorder(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void BattleHud_DrawParticipantTimer(s16 arg0, s16 arg1);
void BattleHud_DrawBattleTimer(s16 arg0, s16 arg1);
void BattleHud_DrawPartyBallRow(Battler* arg0, s16 arg1, s16 arg2);
void BattleHud_DrawMonStatusBoxPlayer(Battler* arg0, s16 arg1, s16 arg2, u16 arg3, s32 arg4);
void BattleHud_DrawMonStatusBoxOpponent(Battler* arg0, s16 arg1, s16 arg2, u16 arg3, s32 arg4);
void BattleHud_DrawThreeOptionLabelBar(Battler* arg0, s16 arg1, s16 arg2, s32 arg3);
void BattleHud_DrawTwoOptionLabelBar(Battler* arg0, s16 arg1, s16 arg2, s32 arg3);
void BattleHud_DrawOneOptionLabelBar(Battler* arg0, s16 arg1, s16 arg2, s32 arg3);
void Battle_DrawRightAlignedText(s32 arg0, s32 arg1, char* arg2);
s32 BattleHud_DrawMovePpTextLTR(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 BattleHud_DrawMovePpTextRTL(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void BattleHud_DrawMoveSelectMenu(Battler* arg0, s16 arg1, s16 arg2, s32 arg3);
void BattleHud_DrawForfeitConfirmDialog(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
void BattleHud_DrawPlainText(s16 arg0, s16 arg1, char* arg2);
void BattleHud_DrawDoublesRosterRow(Battler* arg0, TeamRoster* arg1, BattleMon* arg2, s32 arg3, s32 arg4, s32 arg5);
void BattleHud_DrawPartyRosterRow(Battler* arg0, TeamRoster* arg1, BattleMon* arg2, s32 arg3, s32 arg4, s32 arg5);
void BattleHud_DrawTeamStatusList(Battler* arg0, TeamRoster* arg1, s16 arg2, s16 arg3, s32 arg4);
void BattleHud_DrawDoublesTeamStatusList(Battler* arg0, s16 arg1, s16 arg2, s32 arg3);
void BattleHud_DrawCompactMonStatusBox(Battler* arg0, s16 arg1, s16 arg2, s32 arg3);
void BattleHud_DrawMessageBox(s32 arg0, s16 arg1, s16 arg2, char* arg3);
s32 Battle_DrawTextIfNonEmpty(char* arg0, s16 arg1, s16 arg2);
void BattleHud_DrawExpandingCaptionBox(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2, Vec3f arg3);
void BattleHud_InitCaptionBoxPopup(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2);
s32 BattleHud_UpdateCaptionBoxPopup(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2);
void BattleHud_DrawExpandingCaptionBoxBlack(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2, Vec3f arg3);
void BattleHud_InitCaptionBoxPopupBlack(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2);
s32 BattleHud_UpdateCaptionBoxPopupBlack(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2);
void BattleHud_DrawTextBox(s32 arg0, s16 arg1, s16 arg2, char* arg3);
void BattleHud_DrawTwoOptionCursorMenu(Battler* arg0, s16 arg1, s16 arg2, s32 arg3);
void BattleScene_DrawStripWipeIfActive(void);
void Battle_DrawScrollingTextureRect(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7);
void Battle_DrawTiledStripSegment(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4, s32 arg5);
void Battle_DrawSpectatorModeBackgroundPanel(void);
void Battle_DrawSpectatorModeIndicator(void);
void Battle_DrawSpectatorModeScrollingText(void);
void BattleHud_DrawOwnSideStatus(Battler* arg0, BattlerState* arg1);
void BattleHud_DrawOpponentSideStatus(Battler* arg0, BattlerState* arg1);


void Battle_ClearAllMessageQueues(void);
void Battle_ClearMessageCursor(void);
void func_84317940(s8* arg0, s8* arg1, ...);
void Battle_QueueMessage(s8* arg0, s8 arg1);
void Battle_QueueStatusText(char* arg0, s32 arg1);
void func_84317B38(void);
void Battle_DrawCompactStatusBoxesIfVisible(void);
void Battle_QueueMoveCategoryUsedMessage(void);
void Battle_QueueMoveCategoryMessage(void);
void Battle_QueueMetronomeMoveMessage(void);
void BattleBox_Open(s32 arg0);
void BattleBox_Close(void);
void BattleBox_PlayTextBlip(s8* arg0);
void BattleBox_DrawMessage(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2);
s32 BattleBox_SelectMessage(unk_D_843901A0_4C8* arg0);
void BattleBox_Update(s16 arg0, s16 arg1);
void BattleScene_ClearParticipantMessageBuffer(Battler* arg0);
void BattleScene_BuildParticipantMessage(Battler* arg0, s32 arg1);
void BattleScene_RevealParticipantMessageChars(Battler* arg0);
void BattleScene_TickHudTimers(void);
void Battle_InitMessageQueues(void);
void BattleScene_ResetMessageQueue(void);
void Battle_RenderHud(void);


s32 BattleScene_AreBothParticipantModelsCompact(void);
s32 BattleScene_SkipIntroIfFainted(UNUSED Battler* arg0, unk_D_86002F34_00C* arg1);
s32 BattleScene_IsEitherBattlerFainted(UNUSED Battler* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleScene_IntroCameraStep0(unk_D_86002F34_00C* arg0);
void BattleScene_IntroCameraStep2(unk_D_86002F34_00C* arg0);
void BattleScene_IntroCameraStep4Or6(unk_D_86002F34_00C* arg0, s32 arg1);
void BattleScene_IntroCameraStep8Or10(unk_D_86002F34_00C* arg0, s32 arg1);
void BattleScene_IntroCameraStep12Or14(unk_D_86002F34_00C* arg0, s32 arg1);
void BattleScene_IntroCameraStep16(unk_D_86002F34_00C* arg0);
void BattleScene_IntroCameraStep18(unk_D_86002F34_00C* arg0);
void BattleScene_IntroCameraStep20(unk_D_86002F34_00C* arg0);
void BattleScene_IntroCameraStep22Or24(unk_D_86002F34_00C* arg0, s32 arg1);
void BattleScene_SelectNextIntroCameraShot(unk_D_86002F34_00C* arg0);
void BattleScene_IntroCameraRollStep(unk_D_86002F34_00C* arg0);
void BattleScene_IntroCameraRollStepNoFov(unk_D_86002F34_00C* arg0);
void BattleScene_IntroCameraAnimationHoldStep(unk_D_86002F34_00C* arg0);
void BattleScene_IntroCameraPresetHoldStep(unk_D_86002F34_00C* arg0);
void BattleScene_IntroCameraWideHoldStep(unk_D_86002F34_00C* arg0);
void BattleScene_IntroCameraHeightShotSwapStep(unk_D_86002F34_00C* arg0);
void BattleScene_IntroCameraHeightShotStep(unk_D_86002F34_00C* arg0);
void BattleScene_IntroCameraTimedHoldStep(unk_D_86002F34_00C* arg0);
void BattleScene_IntroCameraFinalHoldStep(unk_D_86002F34_00C* arg0);
void BattleScene_UpdateIntroCameraSequence(unk_D_86002F34_00C* arg0);


f32 BattleScene_ScaleCameraDistance(Battler* arg0, f32 arg1, f32 arg2);
s32 BattleScene_AdvanceCameraSubstepCounter(s32 arg0);
s32 BattleScene_AdvanceCameraFrameCounter(s32 arg0);
s32 BattleScene_AdvanceCameraFrameCounterUntil(s32 arg0);
s32 BattleScene_IsCameraFrameCounterAtLeast(s32 arg0);
void BattleScene_SetActiveBattlerIndex(s32 arg0);
void BattleScene_ResetCameraFrameCounter(void);
void BattleScene_ResetCameraSubstepCounter(void);
void BattleScene_SetCameraAtAndEyeFromAngles(unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s16 arg5, s16 arg6);
void BattleScene_GetOwnerCameraAnchor(Battler* arg0, Vec3f* arg1);
void BattleScene_GetOwnerBoneOrDefaultAnchor(Battler* arg0, Vec3f* arg1, s32 arg2);
void BattleScene_SetCameraModeAndStep(s32 arg0, s32 arg1);
void BattleScene_SetCameraClipPlanes(unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2);
void BattleScene_SetCameraSubstate(s32 arg0, u16 arg1);
void BattleScene_ApplyCameraPhaseDefaults(void);
void BattleScene_SetDamageShakeAmplitude(Battler* arg0);
void BattleScene_ApplyCameraShake(unk_D_86002F34_00C* arg0);
void BattleScene_StartCameraShake(UNUSED Battler* arg0);
s32 BattleScene_IsCameraAngleSettled(s16 arg0, s16 arg1);
s32 BattleScene_ApproachCameraRoll(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2);
s32 BattleScene_ApproachCameraRollNoEyeUpdate(UNUSED unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2);
void BattleScene_SetCameraAnglesAndDistance(s16 arg0, s16 arg1, f32 arg2);
void BattleScene_SetCameraSendOutShot(unk_D_86002F34_00C* arg0, s32 arg1);
void BattleScene_ClampCameraEyeFloor(unk_D_86002F34_00C* arg0);
void BattleScene_UpdateCameraModelOffset(Battler* arg0, unk_D_86002F34_00C* arg1);
void BattleScene_ClearCameraOffsetVectors(void);
void BattleScene_SetCameraAtFromAnchor(Battler* arg0, unk_D_86002F34_00C* arg1, Vec3f arg2, s16 arg3, s16 arg4, f32 arg5, f32 arg6);
void BattleScene_SetCameraAtFromPosition(unk_D_86002F34_00C* arg0, Vec3f arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5);
void BattleScene_SetCameraEyeFromPosition(unk_D_86002F34_00C* arg0, Vec3f arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5);
void BattleScene_SetCameraEyeFromAt(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4);
void BattleScene_SetCameraEyeAndStoreAngles(unk_D_86002F34_00C* arg0, Vec3f arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5);
void BattleScene_SetCameraEyeAndStoreAnglesFromAt(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4);
void BattleScene_CameraHelperNop(UNUSED unk_D_86002F34_00C* arg0);
void BattleScene_SnapFloatPair(f32* arg0, f32* arg1);
void BattleScene_ApplyOwnerFramingAdjustments(unk_D_86002F34_00C* arg0, Battler* arg1, UNUSED f32 arg2);
void BattleScene_RecomputeCameraDistance(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_ReframeAndRecomputeDistance(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_ReframeAndRecomputeDistanceForSwitch(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_ApplyOwnerFramingOnly(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_UpdateCameraTargetFromOwner(unk_D_86002F34_00C* arg0, Battler* arg1);
s32 BattleScene_FrameCamera(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_ApproachCameraTargetFromOwner(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_UpdateCameraVerticalFraming(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_RecenterCameraOnOwner(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_ApproachCameraTarget(unk_D_86002F34_00C* arg0, Battler* arg1, UNUSED s32 arg2);
void BattleScene_ApproachCameraZoom(unk_D_86002F34_00C* arg0, Battler* arg1);
s32 BattleScene_ApproachCloseCameraShot(unk_D_86002F34_00C* arg0, Battler* arg1);
s32 BattleScene_AnimateCameraPreset(unk_D_86002F34_00C* arg0, Battler* arg1, s32 arg2, s32 arg3);
s32 BattleScene_AnimateCameraPresetToOwner(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_CameraPresetNop(UNUSED unk_D_86002F34_00C* arg0);
void BattleScene_ApplyCameraPreset(unk_D_86002F34_00C* arg0, Battler* arg1, s32 arg2);
void BattleScene_SetCameraPresetAtAngles(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void BattleScene_SetCameraPresetAtDistances(f32 arg0, f32 arg1);
void BattleScene_SetCameraPresetEyeAngles(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void BattleScene_SetCameraPresetEyeDistances(f32 arg0, f32 arg1);
void BattleScene_SetCameraPresetSmoothing(f32 arg0, f32 arg1);
void BattleScene_LoadCameraPreset(unk_D_86B0C160* arg0, unk_D_86002F34_00C* arg1, Battler* arg2);
void BattleScene_LoadCameraPresetUnscaled(unk_D_86B0C160* arg0, unk_D_86002F34_00C* arg1);
s32 BattleScene_AnimateCameraIntro(unk_D_86002F34_00C* arg0, Battler* arg1);
s32 BattleScene_AreBattlerHeightsSeparated(UNUSED unk_D_86002F34_00C* arg0);
void BattleScene_SetCameraBattlerHeightShot(unk_D_86002F34_00C* arg0, s32 arg1);
s32 BattleScene_ApproachCameraBattlerHeightShot(unk_D_86002F34_00C* arg0, s32 arg1);
void BattleScene_SetCameraOwnerShot(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_SetCameraOwnerWideShot(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_SetCameraPresetClose(unk_D_86002F34_00C* arg0, Battler* arg1, s32 arg2);
void BattleScene_SetCameraPresetAngledClose(unk_D_86002F34_00C* arg0, Battler* arg1, s32 arg2);
void BattleScene_SetCameraPresetOffsetClose(unk_D_86002F34_00C* arg0, Battler* arg1, s32 arg2);
void BattleScene_SetCameraPresetLowClose(unk_D_86002F34_00C* arg0, Battler* arg1, s32 arg2);
void BattleScene_SetCameraPresetWide(unk_D_86002F34_00C* arg0, Battler* arg1, s32 arg2);
void BattleScene_SetCameraPresetWideStatic(unk_D_86002F34_00C* arg0, Battler* arg1, s32 arg2);
void BattleScene_SetCameraPresetFromTable(unk_D_86002F34_00C* arg0, Battler* arg1, s32 arg2, s32 arg3);
void BattleScene_CameraShotTargetStandard(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_CameraShotTargetAngled(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_CameraShotTargetHigh(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_CameraShotTargetLow(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_CameraShotTargetClose(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_SetCameraFollowPresetNear(unk_D_86002F34_00C* arg0, Battler* arg1, s32 arg2);
void BattleScene_SetCameraOwnerStandardShot(unk_D_86002F34_00C* arg0, Battler* arg1);
void BattleScene_SelectCameraPreset(Battler* arg0, unk_D_86002F34_00C* arg1, s32 arg2, s32 arg3);
void BattleScene_SelectCameraFollowPreset(Battler* arg0, unk_D_86002F34_00C* arg1, s32 arg2);
void BattleScene_SelectCameraShot(Battler* arg0, unk_D_86002F34_00C* arg1, s32 arg2);


void BattleScene_ApplyModelAnimationSlot5A(Battler* arg0);
void BattleScene_ResetAnimationStep(void);
s32 BattleScene_AdvanceOwnerAnimation(Battler* arg0);
s32 BattleScene_AdvanceOwnerAnimation98(Battler* arg0);
s32 BattleScene_AdvanceOwnerAnimationAndClearFlags(Battler* arg0);
s32 BattleScene_AdvanceDoublesOwnerAnimation(Battler* arg0);
s32 BattleScene_AdvanceBothOwnerAnimations(void);
void BattleScene_ClearInactiveOwnerAnimationFlags(void);
void func_8431FCC4(void);
s32 BattleScene_AnimateDisplayedHpToRuntime(Battler* arg0);
void BattleScene_ClearPhaseFlag(void);
void BattleScene_SetPhaseFlag(void);
void BattleScene_SetPhase(UNUSED unk_D_86002F34_00C* arg0, s32 arg1);
void BattleScene_SaveCameraFov(unk_D_86002F34_00C* arg0);
void BattleScene_ResetCameraFov(unk_D_86002F34_00C* arg0);
s32 BattleScene_GetAnimationTimingField0D(Battler* arg0);
s32 BattleScene_GetMappedAnimationTimingField0D(Battler* arg0);
s32 BattleScene_GetAnimationTimingField0E(Battler* arg0);
s32 BattleScene_GetMappedAnimationTimingField0E(Battler* arg0);
s32 BattleScene_GetCameraShotDuration(Battler* arg0);
void Battle_StartTurn(void);
void BattleScene_InitializeSwitchActions(void);
s32 BattleScene_PrepareReplacementTransition(void);
void BattleScene_BeginBattlePhase(void);
s32 BattleScene_TransitionToPhaseFull(s32 arg0);
s32 BattleScene_TransitionToPhase(s32 arg0);
s32 BattleScene_TransitionToPhaseDuplicate(s32 arg0);
void BattleScene_SwitchActiveSideAndSetPhase(unk_D_86002F34_00C* arg0);
void Battle_ActSecondAttacker(u8 arg0);
void BattleScene_PhaseResumeSaved(void);
void BattleScene_CleanupActionAndAdvance(void);
s32 BattleScene_HandleFaintStatusCompletion(void);
void BattleScene_CompleteActionPhase(void);
void BattleScene_ResolveDisplayedHpCompletion(unk_D_86002F34_00C* arg0);
void BattleScene_UpdateDisplayedHpAndTransition(unk_D_86002F34_00C* arg0);
void BattleScene_WaitForDisplayedHpAnimations(unk_D_86002F34_00C* arg0);
s32 BattleScene_ActionPresentationTransitionCheck(void);
s32 BattleScene_ActionPresentationCleanupCheck(void);
s32 BattleScene_PrepareResidualStatusPresentation(void);
void BattleScene_UpdateActiveOwnerPointers(void);
void BattleScene_InitializeBattlePresentation(unk_D_86002F34_00C* arg0);
void BattleScene_SendOutPresentationFinalize(unk_D_86002F34_00C* arg0);
s32 BattleScene_ResetOwnerStatusPresentation(Battler* arg0);
void BattleScene_AdvanceSendOutPreparation(unk_D_86002F34_00C* arg0);
void BattleScene_AdvanceSendOutCamera(unk_D_86002F34_00C* arg0);
void BattleScene_AdvanceSendOutCameraClose(unk_D_86002F34_00C* arg0);
void BattleScene_FinishSendOutCameraClose(unk_D_86002F34_00C* arg0);
void BattleScene_CompleteSendOutPresentation(unk_D_86002F34_00C* arg0);
void func_84321D34(UNUSED unk_D_86002F34_00C* arg0);
void BattleScene_SetupSendOutOwnerShot(unk_D_86002F34_00C* arg0);
void BattleScene_CompleteSendOutCameraFade(UNUSED unk_D_86002F34_00C* arg0);
void BattleScene_CompleteSendOutExtendedFade(UNUSED unk_D_86002F34_00C* arg0);
void BattleScene_AdvanceSendOutFollowupCamera(unk_D_86002F34_00C* arg0);
void BattleScene_PhaseSendOut(unk_D_86002F34_00C* arg0);
void BattleScene_CompleteSendOutFollowup(UNUSED unk_D_86002F34_00C* arg0);
void BattleScene_PhaseSendOutAfterFaint(unk_D_86002F34_00C* arg0);
void BattleScene_ResetOwnerPresentationFlags(Battler* arg0);
void BattleScene_InitializeIntroCamera(unk_D_86002F34_00C* arg0);
void BattleScene_AdvanceIntroCamera(unk_D_86002F34_00C* arg0);
void BattleScene_PhaseIntro(unk_D_86002F34_00C* arg0);
void BattleScene_SetMonMoveResourceFlag(Battler* arg0);
void BattleScene_PrepareMoveResourcePresentation(UNUSED unk_D_86002F34_00C* arg0);
void BattleScene_SelectActionCameraPreset(unk_D_86002F34_00C* arg0);
s32 BattleScene_AdvanceActionPresentationSetup(unk_D_86002F34_00C* arg0);
void BattleScene_ActionSetupCameraStep(unk_D_86002F34_00C* arg0);
void BattleScene_RefreshActionCameraPreset(unk_D_86002F34_00C* arg0);
void BattleScene_SelectActionCameraPresetFromTiming(unk_D_86002F34_00C* arg0, s32 arg1);
s32 BattleScene_ApplyActionCameraMode(unk_D_86002F34_00C* arg0, s32 arg1);
void BattleScene_CleanupActionPresentation(UNUSED unk_D_86002F34_00C* arg0);
s32 BattleScene_WaitForActionCameraDuration(UNUSED unk_D_86002F34_00C* arg0);
void BattleScene_ActionSetupAnimationDefault(unk_D_86002F34_00C* arg0);
void BattleScene_ActionSetupAnimationVariantA(unk_D_86002F34_00C* arg0);
void BattleScene_ActionSetupAnimationVariantB(unk_D_86002F34_00C* arg0);
void BattleScene_ActionSetupAnimationVariantC(unk_D_86002F34_00C* arg0);
void BattleScene_ActionSetupAnimationVariantD(unk_D_86002F34_00C* arg0);
void BattleScene_ActionSetupAnimationStep(unk_D_86002F34_00C* arg0);
void BattleScene_StopSpecialOwnerAnimation(Battler* arg0);
s32 BattleScene_IsSpecialOwnerAnimation(Battler* arg0);
void BattleScene_CompleteHpUpdateTransition(unk_D_86002F34_00C* arg0, s32* arg1, s32* arg2);
void BattleScene_RunBasicHpTransition(unk_D_86002F34_00C* arg0);
void BattleScene_RunConditionalHpTransition(unk_D_86002F34_00C* arg0);
void BattleScene_RunMoveEffectEndHpTransition(unk_D_86002F34_00C* arg0);
void BattleScene_RunActionEffectHpTransition(unk_D_86002F34_00C* arg0);
void func_84324404(void);
void func_8432440C(void);
void BattleScene_RunRepeatedHitHpTransition(unk_D_86002F34_00C* arg0);
void BattleScene_ActionSetupFinalizeStep(unk_D_86002F34_00C* arg0);
void BattleScene_Phase2(unk_D_86002F34_00C* arg0);
void BattleScene_Phase3(unk_D_86002F34_00C* arg0);
s32 BattleScene_PhaseSelectMoveAnim(void);
void BattleScene_Phase7(unk_D_86002F34_00C* arg0);
void BattleScene_Phase38(unk_D_86002F34_00C* arg0);
void BattleScene_Phase27(unk_D_86002F34_00C* arg0);
void BattleScene_Phase30(unk_D_86002F34_00C* arg0);
void BattleScene_Phase28(unk_D_86002F34_00C* arg0);
void BattleScene_Phase15(unk_D_86002F34_00C* arg0);
void BattleScene_Phase25(unk_D_86002F34_00C* arg0);
s32 BattleScene_EndStatusAnimationsAndCommit(Battler* arg0);
void BattleScene_Phase29(unk_D_86002F34_00C* arg0);
void BattleScene_Phase12(unk_D_86002F34_00C* arg0);
void BattleScene_Phase13(unk_D_86002F34_00C* arg0);
void BattleScene_Phase14(unk_D_86002F34_00C* arg0);
void BattleScene_Phase17(unk_D_86002F34_00C* arg0);
void BattleScene_PhaseFaint(unk_D_86002F34_00C* arg0);
void BattleScene_Phase31(unk_D_86002F34_00C* arg0);
void func_84326A70(void);
void BattleScene_Phase4(UNUSED unk_D_86002F34_00C* arg0);
void BattleScene_Phase16(unk_D_86002F34_00C* arg0);
void BattleScene_PhaseMoveFailedMessage(unk_D_86002F34_00C* arg0);
void BattleScene_PhaseAttackHit(unk_D_86002F34_00C* arg0);
void BattleScene_PhaseDrainDamage(unk_D_86002F34_00C* arg0);
void BattleScene_Phase10(unk_D_86002F34_00C* arg0);
void BattleScene_PhaseAttackHitRecoil(unk_D_86002F34_00C* arg0);
void BattleScene_PhaseCheckFaintedEndTurn(unk_D_86002F34_00C* arg0);
void BattleScene_ClearMonStatusAnimations(Battler* arg0);
void BattleScene_PhaseWithdrawFainted(unk_D_86002F34_00C* arg0);
void BattleScene_PhaseWithdrawSwitch(unk_D_86002F34_00C* arg0);
void BattleScene_UpdatePhase(unk_D_86002F34_00C* arg0);


void BattleScene_IntroSetupCamera(unk_D_86002F34_00C* arg0);
void BattleScene_IntroSendOutFirstMon(UNUSED unk_D_86002F34_00C* arg0);
void BattleScene_IntroSendOutSecondMon(UNUSED unk_D_86002F34_00C* arg0);
void BattleScene_IntroNarrowFov(unk_D_86002F34_00C* arg0);
void BattleScene_IntroPanCamera(unk_D_86002F34_00C* arg0);
void BattleScene_IntroWaitFirstMonAnim(UNUSED unk_D_86002F34_00C* arg0);
void BattleScene_IntroRevealFirstMon(unk_D_86002F34_00C* arg0);
void BattleScene_IntroFirstMonSettle(unk_D_86002F34_00C* arg0);
void BattleScene_IntroRevealSecondMon(unk_D_86002F34_00C* arg0);
void BattleScene_IntroSecondMonSettle(unk_D_86002F34_00C* arg0);
void BattleScene_IntroStepNop(UNUSED unk_D_86002F34_00C* arg0);
void BattleScene_IntroInitNop(void);
void BattleScene_UpdateIntroSequence(unk_D_86002F34_00C* arg0);


void BattleScene_FinalPresentationFrameActiveOwner(unk_D_86002F34_00C* arg0);
void BattleScene_FinalPresentationFrameOwner0(unk_D_86002F34_00C* arg0);
void BattleScene_RunFinalPresentation(unk_D_86002F34_00C* arg0, UNUSED Battler* arg1, UNUSED Battler* arg2);
void BattleScene_Init(void);
void func_843297E8(UNUSED unk_D_86002F34_00C* arg0);
void func_843297F0(UNUSED unk_D_86002F34_00C* arg0);
void BattleScene_AvoidDegenerateCameraLookAt(unk_D_86002F34_00C* arg0);
void BattleScene_TickCameraSubstateDefault(unk_D_86002F34_00C* arg0);
void BattleScene_TickCameraSubstateStripWipe(unk_D_86002F34_00C* arg0);
void BattleScene_TickCameraSubstate(unk_D_86002F34_00C* arg0);
u16 BattleScene_IsOwnerInViewWedge(Battler* arg0, unk_D_86002F34_00C* arg1, Battler* a2, s16 arg3, f32 arg4);
u16 BattleScene_IsOwnerInViewWedgeAlt(Battler* arg0, unk_D_86002F34_00C* arg1, Battler* a2, s16 arg3, f32 arg4);
void BattleScene_UpdateBothOwnersVisibilityCulling(unk_D_86002F34_00C* arg0);
void BattleScene_UpdateOpponentVisibilityCulling(unk_D_86002F34_00C* arg0);
void func_8432A414(void);
void BattleScene_ShowBothOwners(void);
void BattleScene_HideOpponentOwner(void);
void BattleScene_HideActiveOwner(void);
void BattleScene_HideFaintedOwners(void);
void BattleScene_UpdateOwnerVisibilitySingle(unk_D_86002F34_00C* arg0);
void BattleScene_UpdateOwnerVisibilityDouble(unk_D_86002F34_00C* arg0);
void BattleScene_Update(unk_D_86002F34_00C* arg0);
s32 BattleScene_Dispatch(s32 arg0, unk_D_86002F34_00C* arg1);


void BattleAnim_StartFreezeStatusAnimation(Battler* arg0);
void BattleAnim_RestoreBaseModelAnimation(Battler* arg0);
void BattleAnim_ClearFreezeStatusAnimation(Battler* arg0);
void BattleAnim_ResetFreezeStatusAndRestoreAnimation(Battler* arg0);
void BattleAnim_ClearFreezeStatusAnimationIfThawed(Battler* arg0);
void BattleAnim_UpdateSleepStatusAnimation(Battler* arg0);
void BattleAnim_EndSleepStatusAnimation(Battler* arg0);
void BattleAnim_ClearSleepStatusAnimation(Battler* arg0);


void BattleAnim_PlaySoundEffect1(void);
void BattleAnim_PlaySoundEffect2(void);
void BattleAnim_PlaySoundEffect3(void);
void BattleAnim_PlaySoundEffect8(void);
void BattleAnim_PlayOwnerCry(Battler* arg0, s16 arg1);
void BattleAnim_PlaySpeciesSequence33(Battler* arg0);
void Battle_TriggerTrainerPresentationCue(Battler* arg0);
void BattleAnim_PlaySpeciesReactionSound(Battler* arg0, BattleMonRuntime* arg1, s32 arg2);
void BattleScene_ConfigureAudioChannelGroupsByTeam(void);
void BattleScene_ConfigureAudioChannelGroupCounts(void);
void BattleScene_SelectBattleMusic(void);
void BattleScene_StartBattleMusic(void);
void BattleAnim_PlayBattleSequenceById(Battler* arg0, s32 arg1);
void BattleAnim_RunEffectInitStart(s16 arg0);
void BattleAnim_RunEffectInitEnd(s16 arg0);
void BattleAnim_RegisterEffectSlot(func_D_84390300 arg0, func_D_84390320 arg1);
void BattleAnim_RunEffectList(s32 arg0, s32 arg1, s32 arg2);
void BattleAnim_ProcessQueuedEffects(void);
void BattleAnim_UpdateFrame(UNUSED unk_D_86002F34_00C* arg0);
void BattleAnim_SetQueuedEffectList(u8 arg0);
u8 BattleAnim_GetCurrentEffectList(void);
void BattleAnim_SetQueuedResourceListId(u8 arg0);
u8 BattleAnim_GetQueuedResourceListId(void);
s16 BattleAnim_GetQueuedMoveId(void);
void BattleAnim_QueueMoveEffect(s32 arg0, Battler* arg1, Battler* arg2, s16 arg3, s16 arg4);
void BattleAnim_QueueMoveEffectScriptA(s32 arg0, Battler* arg1, Battler* arg2, s16 arg3, s16 arg4);
void BattleAnim_QueueMoveEffectEnd(s32 arg0, Battler* arg1, Battler* arg2, s16 arg3, s16 arg4);
void BattleAnim_QueueMoveEffectScriptB(s32 arg0, Battler* arg1, Battler* arg2, s16 arg3, s16 arg4);
void BattleAnim_QueueEffectList3(s32 arg0, Battler* arg1, Battler* arg2, s16 arg3, s16 arg4);
void BattleAnim_QueueEffectList6(s32 arg0, Battler* arg1);
void BattleAnim_QueueEffectList5(s32 arg0, Battler* arg1);
void BattleAnim_QueueEffectList6Alt(s32 arg0, Battler* arg1);
void BattleAnim_QueueEffectList9(s32 arg0);
void BattleAnim_QueueEffectList(u8 arg0, Battler* arg1);
void BattleAnim_StopOwnerCategoryParticles(u8 arg0, Battler* arg1);
void BattleAnim_RegisterAssetTable(arg1_func_80019420* arg0);
void BattleAnim_ResetAssetTable(void);
void BattleAnim_BuildResourceListForMove(s16 arg0);
void BattleAnim_LoadMoveResourceList(BattleSessionTeams* arg0, s16 arg1);
void BattleAnim_LoadModeResourceList(BattleSessionTeams* arg0, s16 arg1);
void BattleAnim_RegisterAllAssetTables(void);
void BattleAnim_RegisterAssetTablesForSession(BattleSessionTeams* arg0);
void BattleAnim_ResetDisplayContexts(void);
Particle* BattleAnim_GetOwnerContextParticle(DisplayObject* arg0);
DisplayObject* BattleAnim_AllocOwnerDisplayContext(Particle* arg0);
void BattleAnim_FreeOwnerDisplayContext(DisplayObject* arg0);
DisplayObject* BattleAnim_AllocParticleDisplayContext(Particle* arg0);
void BattleAnim_FreeParticleDisplayContext(DisplayObject* arg0);
void BattleAnim_InitModelWithAnim(DisplayObject* arg0, s16 arg1, s16 arg2);
void BattleAnim_SetModelAnimFrame(DisplayObject* arg0, s16 arg1);
void BattleAnim_InitModel(DisplayObject* arg0, s16 arg1);
void BattleAnim_BindModelAnim(DisplayObject* arg0, s16 arg1);
void BattleAnim_BindModelAnimReversed(DisplayObject* arg0, s16 arg1);
s32 BattleAnim_IsModelAnimComplete(DisplayObject* arg0);
void BattleAnim_UpdateEffectCallbacks(UNUSED unk_D_86002F34_00C* arg0);
void BattleAnim_DrawEffectCallbacks(UNUSED unk_D_86002F34_00C* arg0);
void BattleAnim_UpdateCamera(unk_D_86002F34_00C* arg0);
s32 BattleAnim_DispatchPresentation(s32 arg0, unk_D_86002F34_00C* arg1);
void BattleAnim_Initialize(void);
void BattleAnim_Reset(void);
void BattleAnim_GetPointAlongCameraRay(Vec3f* arg0, f32 arg1);
void BattleAnim_GetCameraEyeAngles(s16* arg0, s16* arg1);
void BattleAnim_GetCameraEyeYaw(s16* arg0);
void BattleAnim_GetCameraLookAngles(s16* arg0, s16* arg1);
void BattleAnim_GetCameraLookYaw(s16* arg0);
void BattleAnim_GetCameraStoredAngles76(s16* arg0, s16* arg1);
void BattleAnim_GetCameraStoredYaw78(s16* arg0);
void BattleAnim_GetCameraStoredAngles70(s16* arg0, s16* arg1);
void BattleAnim_GetCameraStoredYaw72(s16* arg0);


void BattleAnim_InitParticleSystem(void);
BattleAnimEffectSlot* BattleAnim_AllocEffectSlot(void);
void BattleAnim_FreeEffectSlot(BattleAnimEffectSlot* arg0);
void BattleAnim_InitializeParticleChain(Particle* arg0, Vec3f arg1, Vec3s arg2, s32 arg3, s32 arg4);
void BattleAnim_CloneParticleState(Particle* arg0, Particle* arg1, ParticleUpdateCallback arg2, ParticleDescriptor* arg3, s32 arg4);
void BattleAnim_EmitParticleBurst(Particle* arg0, ParticleUpdateCallback arg1, ParticleDescriptor* arg2, s16 arg3);
void BattleAnim_EmitParticleBurstWithMetadata(Particle* arg0, ParticleUpdateCallback arg1, ParticleDescriptor* arg2, s16 arg3, s16 arg4, s16 arg5);
Particle* BattleAnim_CreateProceduralParticle(s16 arg0, s16 arg1, s32 arg2, f32 arg3);
void BattleAnim_ReleaseParticleModel(Particle* arg0);
void BattleAnim_DestroyParticle(Particle* arg0);
void BattleAnim_InitializeParticleAnchor(Particle* arg0);
void BattleAnim_UpdateParticleAnchor(Particle* arg0);
void BattleAnim_UpdateParticleCameraScale(Particle* arg0);
void BattleAnim_UpdateOrDestroyParticle(Particle* arg0);
void BattleAnim_UpdateParticlePool(void);
void BattleAnim_InitializeParticleFromEffect(Particle* arg0, Battler* arg1, BattleAnimEffectSlot* arg2, s16 arg3);
void BattleAnim_SpawnEffectParticles(BattleAnimEffectSlot* arg0, s32 arg1);
void BattleAnim_SpawnStandardParticles(BattleAnimEffectSlot* arg0);
void BattleAnim_SpawnBatchedParticles(BattleAnimEffectSlot* arg0);
void BattleAnim_SpawnSingleParticle(BattleAnimEffectSlot* arg0);
void BattleAnim_DispatchParticleEmission(BattleAnimEffectSlot* arg0);
void BattleAnim_TickEffectSlots(void);
void BattleAnim_UpdateEffects(void);
void BattleAnim_CleanupEffectsRetainingCategories47(void);
void BattleAnim_CleanupEffectsRetainingCategory4(void);
s32 BattleAnim_GetMoveFailedFlag(void);
void BattleAnim_UpdateMoveFailedFlag(void);
void BattleAnim_ClearEffectCallbacks(void);
s32 BattleAnim_IsEffectSpawningEnabled(void);
void BattleAnim_DisableEffectSpawning(void);
void BattleAnim_EnableEffectSpawning(void);
void BattleAnim_DisableEffectSpawningAlias(void);
void BattleAnim_CleanupEffects(s32 arg0);
void BattleAnim_StopParticlesForOwnerCategory(u8 arg0, Battler* arg1);
void BattleAnim_ResetSpawnDelay(void);
void BattleAnim_SetSpawnDelay(s32 arg0);
void BattleAnim_AddSpawnDelay(s32 arg0);
void BattleAnim_ResetSpawnDelayAlias(void);
BattleAnimEffectSlot* BattleAnim_CreateEffectSlot(s32 arg0, s32 arg1, s8 arg2, func_unk_D_8140E724 arg3, ParticleDescriptor* arg4, Battler* arg5, s16 arg6, s16 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB);
BattleAnimEffectSlot* BattleAnim_CreateEffectSlotForCurrentOwner(s32 arg0, func_unk_D_8140E724 arg1, ParticleDescriptor* arg2, s16 arg3, s16 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8);
BattleAnimEffectSlot* BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(s32 arg0, s32 arg1, s8 arg2, func_unk_D_8140E724 arg3, ParticleDescriptor* arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA);
BattleAnimEffectSlot* BattleAnim_SpawnGlobalTintColorFadeDetach(s32 arg0, s16 arg1, u8 arg2);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHoldOut(s32 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(s32 arg0, s16 arg1, s16 arg2, u8 arg3);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(s32 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldFadeOutRepeating(s32 arg0, s32 arg1, s8 arg2, s16 arg3, s16 arg4, u8 arg5, u8 arg6);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHoldFullAlpha(s32 arg0, s16 arg1, s16 arg2, u8 arg3);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHold(s32 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHoldRepeating(s32 arg0, s32 arg1, s8 arg2, s16 arg3, s16 arg4, u8 arg5, u8 arg6);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldDetachFullAlpha(s32 arg0, s16 arg1, u8 arg2);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldDetach(s32 arg0, s16 arg1, u8 arg2, u8 arg3);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldDetachRepeating(s32 arg0, s32 arg1, s8 arg2, s16 arg3, u8 arg4, u8 arg5);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25PaletteFadeOut(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25PaletteFadeIn(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintRampDetach(s32 arg0, u8 arg1, s16 arg2, s16 arg3, s16 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPulseDetach(s32 arg0, s16 arg1, u8 arg2, s16 arg3, s16 arg4, s16 arg5);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintHoldFadeDetach(s32 arg0, s16 arg1, u8 arg2, s16 arg3, s16 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteApproachInactive(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteApproachInactiveAlt(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteCycle(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteCycleVariant(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteFade(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintRandomPaletteCycle(s32 arg0, s16 arg1, u8 arg2);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteRotateFadeDetach(s32 arg0, s16 arg1, s16 arg2, u8 arg3);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelAlphaFade(s32 arg0, s16 arg1, s16 arg2, s16 arg3);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelAlphaFadeFullPreset(s32 arg0);
BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelAlphaFadeZeroStartPreset(s32 arg0);
BattleAnimEffectSlot* BattleAnim_SpawnCategory17MarkerSlot(s32 arg0, u8 arg1);
BattleAnimEffectSlot* BattleAnim_SpawnCategory19MarkerSlot(s32 arg0, u8 arg1);
void BattleAnim_EffectStartNop(void);
void BattleAnim_EffectEndNop(void);
void BattleAnim_SetEffectStateFlag(s32 arg0);
void BattleAnim_ClearEffectStateFlag(void);
s32 BattleAnim_GetEffectStateFlag(void);
s32 BattleAnim_IsCurrentOwnerSpecies(s32 arg0);
s32 BattleAnim_GetSecondaryOwnerSpecies(void);
s32 BattleAnim_GetTertiaryOwnerSpecies(void);
void BattleAnim_GetOwnerBonePosition(Battler* arg0, s16 arg1, Vec3f* arg2);
void BattleAnim_GetCurrentOwnerBonePosition(Vec3f* arg0);
void BattleAnim_GetSecondaryOwnerBonePosition(Vec3f* arg0);
void BattleAnim_GetTertiaryOwnerBonePosition(Vec3f* arg0);
void BattleAnim_GetSecondaryOwnerAnchorPosition(Vec3f* arg0);
void BattleAnim_GetTertiaryOwnerBone9Position(Vec3f* arg0);
void BattleAnim_GetOwnerModelBoundsScaled(Battler* arg0, Vec3f* arg1);
f32 BattleAnim_GetSpeciesBaseScale(Battler* arg0);
f32 BattleAnim_GetOwnerModelScale(Battler* arg0);
void BattleAnim_GetOwnerSpeciesBaseScaleAlias(Battler* arg0);
f32 BattleAnim_GetSecondaryOwnerModelScale(void);
void BattleAnim_GetSecondaryOwnerSpeciesBaseScale(void);
f32 BattleAnim_GetTertiaryOwnerModelScale(void);
void BattleAnim_GetTertiaryOwnerSpeciesBaseScale(void);
unk_D_86002F34_00C* BattleAnim_GetCameraContext(void);
Particle* BattleAnim_SpawnSecondaryOwnerParticle(Vec3f arg0, u8 arg1);
void BattleAnim_SetParticlePosition(Particle* arg0, Vec3f arg1);
void BattleAnim_MarkParticleInactive(Particle* arg0);
s16 BattleAnim_GetParticleAngleYToTertiaryOwner(Particle* arg0);
void BattleAnim_SetGlobalTintFromParticle(Particle* arg0);
void BattleAnim_LoadGlobalTintToParticle(Particle* arg0);


void BattleAnim_InitSecondaryOwnerParticleBlueFadeGrow(Particle* arg0);
void BattleAnim_UpdateSecondaryOwnerParticleBlueFadeGrow(Particle* arg0);
void BattleAnim_InitSecondaryOwnerParticleBlueGrow(Particle* arg0);
void BattleAnim_UpdateSecondaryOwnerParticleBlueGrow(Particle* arg0);
void BattleAnim_ConfigureSecondaryOwnerParticleVariant(Particle* arg0, u8 arg1);


s32 BattleAnim_DrawAsset95Ia8Billboard(Particle* arg0, unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset76Ia8FrameWithAsset77I4Overlay(Particle* arg0, unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset76Ia8FrameWithAsset77I4OverlayPipelineA(Particle* arg0, unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset76Ia8FrameWithAsset77I4OverlayPipelineB(Particle* arg0, unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset1FAnimatedI4WithAsset20DisplayList(Particle* arg0, unk_D_86002F34_00C* arg1);
s32 BattleAnim_DrawAssetBcRgba16WithAssetBdDisplayList(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAssets27And28LayeredI4QuadVariantA(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAssets27And28LayeredI4QuadVariantB(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset29DualI4LayeredQuad(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset87AnimatedI4Quad(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawI4AtlasYScaled(Particle* arg0, u8* arg1);
void BattleAnim_DrawAsset19I4AtlasYScaled(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset5EI4AtlasYScaled(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset1AFrameI4Quad(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset1CRgba16Quad(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset1ERgba16Quad(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAssetC3Rgba16Quad(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset1DRotatedI4Quad(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawParticleNoop(UNUSED Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset13FrameI4YScaledQuadA(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset13FrameI4YScaledQuadB(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset13FrameI4YScaledQuadC(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset13FrameI4ModelQuadA(Particle* arg0, unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset13FrameI4ModelQuadB(Particle* arg0, unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset13FrameI4ModelQuadC(Particle* arg0, unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset1BI4TriangleA(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset1BI4TriangleB(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset13FrameDiv2I4Quad(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAsset18FrameI4ModelQuad(Particle* arg0, unk_D_86002F34_00C* arg1);
void BattleAnim_DrawAssetA9I4XYScaledQuad(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void BattleAnim_DrawParticleFullScreenColorOverlay(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);


void BattleAnim_SetupGlobalTintColorFadeDetach(Particle* arg0);
void BattleAnim_CallbackGlobalTintColorFadeDetach(Particle* arg0);
void BattleAnim_SetupOwnerModelTintRampDetach(Particle* arg0);
void BattleAnim_CallbackOwnerModelTintRampDetach(Particle* arg0);
void BattleAnim_SetupOwnerModelTintPulseDetach(Particle* arg0);
void BattleAnim_CallbackOwnerModelTintPulseDetach(Particle* arg0);
void func_8433209C(void);
void BattleAnim_CallbackOwnerModelTintHoldFadeDetach(Particle* arg0);
void BattleAnim_SetupOwnerModelTintPaletteApproachInactive(Particle* arg0);
void BattleAnim_CallbackOwnerModelTintPaletteApproachInactive(Particle* arg0);
void BattleAnim_SetupOwnerModelTintPaletteApproach(Particle* arg0);
void BattleAnim_CallbackOwnerModelTintPaletteApproach(Particle* arg0);
void BattleAnim_SetupOwnerModelTintPaletteCycle(Particle* arg0);
void BattleAnim_CallbackOwnerModelTintPaletteCycle(Particle* arg0);
void BattleAnim_SetupOwnerModelTintPaletteApproachRampDown(Particle* arg0);
void BattleAnim_CallbackOwnerModelTintPaletteApproachRampDown(Particle* arg0);
void BattleAnim_SetupOwnerModelTintPaletteFade(Particle* arg0);
void BattleAnim_CallbackOwnerModelTintPaletteFade(Particle* arg0);
void BattleAnim_SetupOwnerModelTintRandomPaletteCycle(Particle* arg0);
void BattleAnim_CallbackOwnerModelTintRandomPaletteCycle(Particle* arg0);
void BattleAnim_SetupOwnerModelTintPaletteRotateFadeDetach(Particle* arg0);
void BattleAnim_CallbackOwnerModelTintPaletteRotateFadeDetach(Particle* arg0);
void BattleAnim_SetupOwnerModelAlphaFade(Particle* arg0);
void BattleAnim_CallbackOwnerModelAlphaFade(Particle* arg0);
void BattleAnim_SetupParticleRecolorTransparent(Particle* arg0);
void BattleAnim_CallbackStartEffect125OwnerColorAlphaFade(Particle* arg0);
void BattleAnim_SetupDescriptor25AlphaFadeInHoldOut(Particle* arg0);
void BattleAnim_CallbackDescriptor25AlphaFadeInHoldOut(Particle* arg0);
void BattleAnim_SetupDescriptor25AlphaHoldFadeOut(Particle* arg0);
void BattleAnim_CallbackDescriptor25AlphaHoldFadeOut(Particle* arg0);
void BattleAnim_SetupDescriptor25AlphaFadeInHold(Particle* arg0);
void BattleAnim_CallbackDescriptor25AlphaFadeInHold(Particle* arg0);
void BattleAnim_SetupDescriptor25AlphaHoldDetach(Particle* arg0);
void BattleAnim_CallbackDescriptor25AlphaHoldDetach(Particle* arg0);
void BattleAnim_SetupDescriptor25PaletteFadeOut(Particle* arg0);
void BattleAnim_CallbackDescriptor25PaletteFadeOut(Particle* arg0);
void BattleAnim_SetupDescriptor25PaletteFadeIn(Particle* arg0);
void BattleAnim_CallbackDescriptor25PaletteFadeIn(Particle* arg0);


void BattleAnim_CallbackStartEffects23And35And84Descriptor4FColorCycleScaleFade_InitParticle(Particle* arg0, s16 arg1);
void BattleAnim_CallbackStartEffects23And35And84Descriptor4FColorCycleScaleFade_AdvancePhase(Particle* arg0);
void BattleAnim_CallbackStartEffects23And35And84Descriptor4FColorCycleScaleFade(Particle* arg0);
void BattleAnim_SetupUnusedDescriptor4FColorCycleScaleFadeVariant(Particle* arg0);
void BattleAnim_MotionUnusedDescriptor4FColorCycleScaleFadeVariant(Particle* arg0);
void BattleAnim_CallbackUnusedDescriptor4FColorCycleScaleFadeVariant(Particle* arg0);
void BattleAnim_CallbackStartEffects23And35And84Descriptor3DAlphaScaleFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects23And35And84Descriptor3DAlphaScaleFade_AdvancePhase(Particle* arg0);
void BattleAnim_CallbackStartEffects23And35And84Descriptor3DAlphaScaleFade(Particle* arg0);
void BattleAnim_CallbackStartEffects23And35And84Descriptor4FRotatingFallColorCycle_InitParticle(Particle* arg0, s16 arg1);
void BattleAnim_CallbackStartEffects23And35And84Descriptor4FRotatingFallColorCycle_AdvancePhase(Particle* arg0);
void BattleAnim_CallbackStartEffects23And35And84Descriptor4FRotatingFallColorCycle(Particle* arg0);
void BattleAnim_CallbackSharedGrowFadeSetup(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor04GrowFade(Particle* arg0);
void BattleAnim_CallbackEndEffect68Descriptor1BExpandingFadeDrift(Particle* arg0);
void BattleAnim_CallbackUnusedGrowFadeVariant(Particle* arg0);
void BattleAnim_CallbackStartEffect104DelayedSpiralFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect104DelayedSpiralFade(Particle* arg0);
void BattleAnim_CallbackEndEffect29Descriptor02RotatingScaleGrow_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect29Descriptor02RotatingScaleGrow(Particle* arg0);
void BattleAnim_SetupUnusedVariant2(Particle* arg0);
void BattleAnim_CallbackUnusedVariant2(Particle* arg0);
void BattleAnim_CallbackStartEffect22Descriptor4ABurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect22Descriptor4ABurstChild(Particle* arg0);
void BattleAnim_CallbackStartEffect22Descriptor46BurstEmitter_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect22Descriptor46BurstEmitter(Particle* arg0);
void BattleAnim_CallbackStartEffect22Descriptor34RotatingPaletteScaleFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect22Descriptor34RotatingPaletteScaleFade(Particle* arg0);
void BattleAnim_CallbackStartEffect22Descriptor3DRotatingAlphaPaletteFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect22Descriptor3DRotatingAlphaPaletteFade(Particle* arg0);
void BattleAnim_SetParticleColorFromVariantIndex(Particle* arg0, u8 arg1);
void func_84334B04(void);
void BattleAnim_ApproachParticleColorFromVariantIndex(Particle* arg0);
void BattleAnim_CallbackEndEffect40Descriptor46DelayedScaleAlphaFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect40Descriptor46DelayedScaleAlphaFade(Particle* arg0);
void BattleAnim_CallbackEndEffects81And82Descriptor46AnimatedFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffects81And82Descriptor46AnimatedFade(Particle* arg0);
void BattleAnim_CallbackEndEffect40Descriptor48SpreadScaleAlphaFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect40Descriptor48SpreadScaleAlphaFade(Particle* arg0);
void BattleAnim_CallbackEndEffect40Descriptor3DSpreadRisingColorFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect40Descriptor3DSpreadRisingColorFade(Particle* arg0);
void BattleAnim_CallbackEndEffect56Descriptor46RisingScaleAlphaFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect56Descriptor46RisingScaleAlphaFade(Particle* arg0);
void BattleAnim_CallbackEndEffect56Descriptor47SpreadScaleAlphaRise_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect56Descriptor47SpreadScaleAlphaRise(Particle* arg0);
void BattleAnim_CallbackEndEffects54And56Descriptor3DRisingColorScaleFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffects54And56Descriptor3DRisingColorScaleFade(Particle* arg0);
void BattleAnim_CallbackEndEffects40And54Descriptor46SpreadScaleFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffects40And54Descriptor46SpreadScaleFade(Particle* arg0);
void BattleAnim_CallbackEndEffect54Descriptor46DelayedColorAlphaFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect54Descriptor46DelayedColorAlphaFade(Particle* arg0);
void BattleAnim_CallbackSharedRotatingColorFadeSetup(Particle* arg0, s16 arg1, s16 arg2);
void BattleAnim_CallbackSharedRotatingColorFadeMotion(Particle* arg0, s32 arg1);
void BattleAnim_CallbackEndEffects15And22Descriptor4ERotatingColorFadeVariant0(Particle* arg0);
void BattleAnim_CallbackEndEffects15And22Descriptor4ERotatingColorFadeVariant1(Particle* arg0);
void BattleAnim_CallbackEndEffects15And22And59Descriptor3DRotatingAlphaScaleFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffects15And22And59Descriptor3DRotatingAlphaScaleFade_AdvancePhase(Particle* arg0);
void BattleAnim_CallbackEndEffects15And22And59Descriptor3DRotatingAlphaScaleFade(Particle* arg0);
void BattleAnim_CallbackEndEffect59Descriptor4FRotatingColorScaleFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect59Descriptor4FRotatingColorScaleFade_AdvancePhase(Particle* arg0);
void BattleAnim_CallbackEndEffect59Descriptor4FRotatingColorScaleFade(Particle* arg0);
void BattleAnim_CallbackEndEffect59Descriptor4FColorScaleFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect59Descriptor4FColorScaleFade(Particle* arg0);
void func_84336B8C(void);
void func_84336C80(void);
void func_84336DD8(void);
void func_84336EE8(void);
void func_84337000(void);
void func_843371C0(void);
void func_843372D8(void);
void func_843374A4(void);
void func_843375B0(void);
void func_8433765C(void);
void func_84337664(void);
void func_8433766C(void);
void func_843378CC(void);
void func_843378D4(void);


void BattleAnim_CallbackEndEffect16Descriptor45DelayedRotatingMotion_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect16Descriptor45DelayedRotatingMotion(Particle* arg0);
void BattleAnim_CallbackStartEffect48Descriptor45RisingSparkFade_InitParticle(Particle* arg0, s16 arg1);
void BattleAnim_CallbackStartEffect48Descriptor45RisingSparkFade(Particle* arg0);
void BattleAnim_CallbackStartEffects77And120Descriptor45DeceleratingSparkFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects77And120Descriptor45DeceleratingSparkFade_AdvancePhase(Particle* arg0);
void BattleAnim_CallbackStartEffects77And120Descriptor45DeceleratingSparkFade(Particle* arg0);
void BattleAnim_CallbackStartEffects77And120Descriptor45AimedSparkFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects77And120Descriptor45AimedSparkFade(Particle* arg0);
void BattleAnim_SetupUnusedRotatingSparkVariant(Particle* arg0);
void BattleAnim_MotionUnusedRotatingSparkVariant(Particle* arg0);
void BattleAnim_CallbackUnusedRotatingSparkVariant(Particle* arg0);
void BattleAnim_SetupUnusedAimedSparkVariant(Particle* arg0);
void BattleAnim_CallbackUnusedAimedSparkVariant(Particle* arg0);
void BattleAnim_CallbackStartEffects6And58AnimatedScaleAlphaFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects6And58AnimatedScaleAlphaFade(Particle* arg0);
void BattleAnim_CallbackStartEffect58Descriptor0ABurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect58Descriptor0ABurstChild(Particle* arg0);
void BattleAnim_CallbackStartEffect58Descriptor08MetadataBurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect58Descriptor08MetadataBurstChild(Particle* arg0);
void BattleAnim_CallbackStartEffect58Descriptor08MetadataBurstEmitter_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect58Descriptor08MetadataBurstEmitter(Particle* arg0);
void BattleAnim_CallbackStartEffect6Descriptor0ABurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect6Descriptor0ABurstChild(Particle* arg0);
void BattleAnim_CallbackStartEffect6Descriptor08MetadataBurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect6Descriptor08MetadataBurstChild(Particle* arg0);
void BattleAnim_CallbackStartEffect6DefaultDescriptorBurstEmitter_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect6DefaultDescriptorBurstEmitter(Particle* arg0);
void BattleAnim_CallbackStartEffect47Descriptor4AAnimatedScaleFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect47Descriptor4AAnimatedScaleFade_AdvancePhase(Particle* arg0);
void BattleAnim_CallbackStartEffect47Descriptor4AAnimatedScaleFade(Particle* arg0);
void BattleAnim_CallbackStartEffects2And15Descriptor08IndexedScaleDelayFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects2And15Descriptor08IndexedScaleDelayFade(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor53ScaleGrowAnimFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor53ScaleGrowAnimFade(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor53ScalePulseCycle_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor53ScalePulseCycle(Particle* arg0);
void BattleAnim_CallbackSharedExpandingScaleAlphaFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedExpandingScaleAlphaFade(Particle* arg0);
void BattleAnim_CallbackEndEffect68Descriptor54FlickerExpandingFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect68Descriptor54FlickerExpandingFade(Particle* arg0);
void BattleAnim_CallbackEndEffect69Descriptor54ExpandingHoldFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect69Descriptor54ExpandingHoldFade(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor19AnimatedFadeMotion_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor19AnimatedFadeMotion(Particle* arg0);
void BattleAnim_CallbackEndEffect23Descriptor19AnimatedFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect23Descriptor19AnimatedFade(Particle* arg0);
void BattleAnim_CallbackEndEffect2Descriptor19AnimatedAlphaFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect2Descriptor19AnimatedAlphaFade(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor19RecolorAnimatedFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor19RecolorAnimatedFade(Particle* arg0);
void BattleAnim_CallbackEndEffect86Descriptor19ModePositionedAnimFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect86Descriptor19ModePositionedAnimFade(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor19DelayedAnimatedGrowFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor19DelayedAnimatedGrowFade(Particle* arg0);
void BattleAnim_SetupUnusedIndexedFadeVariantA(Particle* arg0);
void BattleAnim_CallbackUnusedIndexedFadeVariantA(Particle* arg0);
void BattleAnim_SetupUnusedIndexedFadeVariantB(Particle* arg0);
void BattleAnim_CallbackUnusedIndexedFadeVariantB(Particle* arg0);
void BattleAnim_CallbackEndEffects34And53Descriptor45RotatingBounceFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffects34And53Descriptor45RotatingBounceFade(Particle* arg0);
void BattleAnim_CallbackEndEffect27Descriptor4BGrowColorShiftFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect27Descriptor4BGrowColorShiftFade(Particle* arg0);
void BattleAnim_CallbackEndEffect2Descriptor4BModeColorShiftFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect2Descriptor4BModeColorShiftFade(Particle* arg0);
void BattleAnim_CallbackEndEffects2And27Descriptor0AFallingSparkFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffects2And27Descriptor0AFallingSparkFade(Particle* arg0);
void BattleAnim_StartEffect15Descriptor08IndexedScaleDelayFade(void);
void BattleAnim_StartEffect2Descriptor08IndexedScaleDelayFade(void);
void func_8433B374(void);
void func_8433B3D8(void);
void BattleAnim_StartEffect6AnimatedScaleAndBurstEmitter(void);
void func_8433B58C(void);
void func_8433B6FC(void);
void func_8433B7E4(void);
void func_8433B988(void);
void BattleAnim_StartEffect4TintDescriptor53ScalePulse(void);
void func_8433BB78(void);
void func_8433BC38(void);
void func_8433BD08(void);
void func_8433BDFC(void);
void func_8433BECC(void);
void func_8433BF54(void);
void func_8433C06C(void);
void func_8433C284(void);
void func_8433C3A0(void);
void func_8433C4EC(void);
void func_8433C604(void);
void func_8433C784(void);
void BattleAnim_EndEffect25Descriptor13DelegateSequence(void);
void func_8433CAFC(void);


void BattleAnim_SetupStartEffects18And73Descriptor11ScatterRiseFade(Particle* arg0);
void BattleAnim_CallbackStartEffects18And73Descriptor11ScatterRiseFade(Particle* arg0);
void BattleAnim_ApplyStartEffect18MoveKeyedRadialOffset(Particle* arg0);
void BattleAnim_SetupStartEffect18MoveKeyedRadialPulse(Particle* arg0);
void BattleAnim_CallbackStartEffect18MoveKeyedRadialPulse(Particle* arg0);
void BattleAnim_SetupSharedDescriptor0FDelayedRisingColumnFade(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor0FDelayedRisingColumnFade(Particle* arg0);
void BattleAnim_SetupSharedDescriptor0FDelayedRisingColumnRandomScale(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor0FDelayedRisingColumnRandomScale(Particle* arg0);
void BattleAnim_SetupSharedDirectionalSprayFade(Particle* arg0);
void BattleAnim_CallbackSharedDirectionalSprayFade(Particle* arg0);
void BattleAnim_SetupSharedDescriptor13DirectionalSprayScaledFade(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor13DirectionalSprayScaledFade(Particle* arg0);
void BattleAnim_SetupStartEffect59EndEffect28DirectionalStreamFade(Particle* arg0);
void BattleAnim_CallbackStartEffect59EndEffect28DirectionalStreamFade(Particle* arg0);
void BattleAnim_SetupUnregisteredStraightDirectionalStreamFade(Particle* arg0);
void BattleAnim_CallbackUnregisteredStraightDirectionalStreamFade(Particle* arg0);
void BattleAnim_SetupEndEffect28Descriptor10UpwardBurstFade(Particle* arg0);
void BattleAnim_CallbackEndEffect28Descriptor10UpwardBurstFade(Particle* arg0);
void BattleAnim_SetupEndEffect28Descriptor10WideScatterBurstFade(Particle* arg0);
void BattleAnim_CallbackEndEffect28Descriptor10WideScatterBurstFade(Particle* arg0);
void BattleAnim_StartEffect18ScatterRadialAndColumnSequence(void);
void func_8433DECC(void);
void func_8433DFF4(void);
void func_8433E124(void);
void func_8433E33C(void);
void func_8433E46C(void);
void BattleAnim_EndEffect70Descriptor0F_13SprayColumnSequence(void);


void BattleAnim_InitStartEffect135Descriptor1CRisingScale(Particle* arg0);
void BattleAnim_CallbackStartEffect135Descriptor1CRisingScaleFade(Particle* arg0);
void BattleAnim_InitStartEffect135ExpandingFlash(Particle* arg0);
void BattleAnim_CallbackStartEffect135ExpandingFlashFade(Particle* arg0);
void BattleAnim_InitStartEffect139Descriptor42FallingScale(Particle* arg0);
void BattleAnim_CallbackStartEffect139Descriptor42FallingScaleFade(Particle* arg0);
void BattleAnim_InitStartEffect139Descriptor22SpinFade(Particle* arg0);
void BattleAnim_CallbackStartEffect139Descriptor22SpinFadeSpark(Particle* arg0);
void BattleAnim_InitStartEffect141Descriptor1CGridRise(Particle* arg0);
void BattleAnim_CallbackStartEffect141Descriptor1CGridRiseFade(Particle* arg0);
void BattleAnim_InitStartEffects133And134And143Descriptor44ModeOrbit(Particle* arg0);
void BattleAnim_CallbackStartEffects133And134And143Descriptor44ModeOrbitSwirl(Particle* arg0);
void BattleAnim_InitStartEffects133And134And143Descriptor38MetadataBurst(Particle* arg0);
void BattleAnim_CallbackStartEffects133And134And143Descriptor38MetadataBurstEmitter(Particle* arg0);
s16 BattleAnim_GetSessionModeEffectParam(void);
void BattleAnim_StartEffect139DualRepeatingSparks(void);
void BattleAnim_StartEffect140StartEffect139Alias(void);
void BattleAnim_StartEffect141GridRiseAndFallingBurst(void);
void BattleAnim_StartEffect142StartEffect141Alias(void);
void BattleAnim_StartEffect135ExpandingFlashAndRisingScaleFade(void);
void BattleAnim_StartEffect134ModeOrbitAndMetadataBurst(void);
void BattleAnim_StartEffect143ModeOrbitAndMetadataBurst(void);
void BattleAnim_StartEffect133ModeOrbitBurstAndEffect135Followup(void);
void BattleAnim_StartEffect122GlobalAndOwnerTintFade(void);


void BattleAnim_UnusedResetAppearanceAndAdvance(Particle* arg0);
void BattleAnim_CallbackUnusedGenericFadeApproach(Particle* arg0);
void BattleAnim_SetupOrphanDescriptor2BSpinFade(Particle* arg0);
void BattleAnim_CallbackOrphanDescriptor2BSpinFade(Particle* arg0);
void BattleAnim_SetupOrphanDescriptor2EScatterFade(Particle* arg0);
void BattleAnim_CallbackOrphanDescriptor2EScatterFade(Particle* arg0);
void BattleAnim_SetupEndEffect26Descriptor2CGravityScatterFall(Particle* arg0);
void BattleAnim_CallbackEndEffect26Descriptor2CGravityScatterFall(Particle* arg0);
void BattleAnim_SetupEndEffects85And87GravityFallDelay(Particle* arg0);
void BattleAnim_CallbackEndEffects85And87GravityFallDelay(Particle* arg0);
void func_84340AC4(void);
void BattleAnim_OrphanDescriptor2BAnd2EEmitterSequence(void);
void func_84340CB0(void);
void func_84340D14(void);


void func_84342808(void);
void func_84342908(void);
void BattleAnim_StartEffect1Descriptor2FPhaseFadeOut(void);
void BattleAnim_StartEffect12DelayedModelAnim(void);
void BattleAnim_ApplySpeciesMotionOffset(Particle*);
void BattleAnim_StartEffect14ModelAnimAndMoveKeyedTintParticles(void);
void func_84344094(void);
void func_84344248(void);
void func_843443E0(void);
void func_84344474(void);
void func_84344508(void);
void BattleAnim_StartEffect8ModelBurstAndVerticalFade(void);
void func_84344B04(void);
void func_84344BDC(void);
void func_84345038(void);
void func_843450B4(void);
void func_8434575C(void);
void func_84345B28(void);
void func_84345B84(void);
void func_84345D74(void);
void func_84345EC0(void);
void func_84346B58(void);
void func_84346BE0(void);
void func_84346DC4(void);
void func_84346E50(void);
void func_84346EEC(void);
void func_84346F40(void);
void BattleAnim_StartEffect10Model60AndModelAnimWait(void);
void BattleAnim_ApplySpeciesXZOffsetVariantA(Particle*);
void func_84347448(void);


void BattleAnim_SetupReflectiveCamera(void);
void BattleAnim_SelectParticleModelFrames(Particle* arg0, s32 arg1);
void BattleAnim_CallbackInitModelAnimWait(Particle* arg0);
void BattleAnim_CallbackInitModelAnim(Particle* arg0);
void BattleAnim_CallbackStartEffects83And103ModelAlphaFadeIn(Particle* arg0);
void BattleAnim_CallbackInitModelAnimWaitCleanup(Particle* arg0);
void func_84341830(Particle* arg0);
void BattleAnim_CallbackInitModelAnimMode2Update(Particle* arg0);
Gfx* BattleAnim_BuildAnimatedTileDisplayList(Gfx* arg0, u8* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, s16 argA, s16 argB);
Gfx* BattleAnim_BuildAnimatedTileDisplayListFromStruct(Gfx* arg0, arg1_func_8434E21C* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, s16 argA, s16 argB);
void func_84341E50(Gfx* arg0);
void func_84341F08(s32 arg0, arg1_func_84344CE8* arg1);
void func_84341F44(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void func_84342304(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_SetupMove86EndDescriptor24(Particle* arg0);
void BattleAnim_CallbackMove86EndDescriptor24(Particle* arg0);
void BattleAnim_ApplyMove86SpeciesOffset(Particle* arg0);
void BattleAnim_SetupMove86StartDescriptor24(Particle* arg0);
void BattleAnim_CallbackMove86StartDescriptor24(Particle* arg0);
void func_84342808(void);
void func_84342908(void);
void BattleAnim_ApplyEffect1SpeciesMotion(Particle* arg0);
void BattleAnim_SetupEffect1Descriptor2F(Particle* arg0);
void BattleAnim_CallbackStartEffect1Descriptor2FPhaseFadeOut(Particle* arg0);
void BattleAnim_StartEffect1Descriptor2FPhaseFadeOut(void);
void BattleAnim_ApplyModelSpeciesOffset(Particle* arg0);
void BattleAnim_InitModelAnimationSlot(Particle* arg0, s16 arg1);
void BattleAnim_CallbackStartEffects12And129DelayedModelAnimWait(Particle* arg0);
void BattleAnim_StartEffect12DelayedModelAnim(void);
void BattleAnim_ApplySpeciesMotionOffset(Particle* arg0);
void BattleAnim_StartEffect14ModelAnimAndMoveKeyedTintParticles(void);
void BattleAnim_BuildReflectiveTextureDisplayList(Gfx* arg0, s32 arg1, u16 arg2);
void BattleAnim_AllocateReflectiveTextureDisplayList(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_ApplyEffect125ModelScaleOffset(Particle* arg0);
void BattleAnim_InitEffect125Model(Particle* arg0, UNUSED s16 arg1);
void BattleAnim_CallbackStartEffect125ModelBurstEmitter(Particle* arg0);
void BattleAnim_BuildEffect125DisplayList(Gfx* arg0, u16 arg1);
void BattleAnim_AllocateEffect125DisplayList(s32 arg0, arg1_func_84344CE8* arg1);
void func_84344094(void);
void BattleAnim_InitEffect65Overlay(Particle* arg0);
void BattleAnim_CallbackStartEffect65Descriptors31And32FadeIn(Particle* arg0);
void func_84344248(void);
void BattleAnim_InitEffect28Overlay(Particle* arg0);
void BattleAnim_CallbackStartEffects28And53And76Descriptor33FadeIn(Particle* arg0);
void func_843443E0(void);
void func_84344474(void);
void func_84344508(void);
void BattleAnim_InitEffect8Descriptor4A(Particle* arg0);
void BattleAnim_CallbackStartEffect8Descriptor4ABurstChild(Particle* arg0);
void BattleAnim_InitEffect8ModelBurst(Particle* arg0);
void BattleAnim_CallbackStartEffect8ModelBurstEmitter(Particle* arg0);
void BattleAnim_ApplyEffect31SpeciesOffset(Particle* arg0);
void BattleAnim_InitEffect31Model(Particle* arg0);
void BattleAnim_CallbackMove73EndEffect31SpawnDescriptor42(Particle* arg0);
void BattleAnim_StartEffect8ModelBurstAndVerticalFade(void);
void func_84344B04(void);
void func_84344BDC(void);
void func_84344C7C(Gfx* arg0, u8* arg1);
void func_84344CE8(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_CallbackStartEffect34SpecialModelFadeIn_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect34SpecialModelFadeIn(Particle* arg0);
void BattleAnim_CallbackEndEffect23Descriptor4AAnimatedFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect23Descriptor4AAnimatedFade(Particle* arg0);
void func_84345038(void);
void func_843450B4(void);
void func_8434523C(Gfx* arg0, s32 arg1, u16 arg2);
void func_843452F0(s32 arg0, arg1_func_84344CE8* arg1);
void func_84345338(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void func_8434539C(s32 arg0, arg1_func_84344CE8* arg1);
void func_843453E4(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void func_84345448(s32 arg0, arg1_func_84344CE8* arg1);
void func_84345490(void);
void BattleAnim_ApplyMove146SpeciesOffset(Particle* arg0);
void BattleAnim_InitMove146Model(Particle* arg0);
void BattleAnim_CallbackMove146EndEffect6ModelAnimWait(Particle* arg0);
void func_8434575C(void);
void BattleAnim_InitEffect49Model(Particle* arg0);
void BattleAnim_CallbackEndEffect49Model33Anim34WaitCleanup(Particle* arg0);
void BattleAnim_CallbackEndEffect21ModelAnimWait(Particle* arg0);
void BattleAnim_BuildEffect49DisplayList(Gfx* arg0, UNUSED s32 arg1, UNUSED u16 arg2);
void BattleAnim_AllocateEffect49DisplayList(s32 arg0, arg1_func_84344CE8* arg1);
void func_84345B28(void);
void func_84345B84(void);
void BattleAnim_InitEffect40Model(Particle* arg0);
void BattleAnim_CallbackStartEffect40ModelFadeCycle(Particle* arg0);
void func_84345D74(void);
void BattleAnim_InitEffect86Model(Particle* arg0);
void BattleAnim_CallbackStartEffect86ModelFadeCycle(Particle* arg0);
void func_84345EC0(void);
void BattleAnim_BuildEffect63DisplayList(Gfx* arg0, s32 arg1, u16 arg2);
void BattleAnim_AllocateEffect63DisplayList(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_BuildEffect75DisplayList(Gfx* arg0, UNUSED s32 arg1, UNUSED u16 arg2);
void BattleAnim_AllocateEffect75DisplayList(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_InitEffects63And75Model(Particle* arg0);
void BattleAnim_CallbackStartEffects63And75ModelAnimWait(Particle* arg0);
void BattleAnim_InitEffects10And50Model(Particle* arg0);
void BattleAnim_CallbackEndEffects10And50ModelAnimColorFade(Particle* arg0);
void BattleAnim_ApplyEffects63And75SpeciesScaleOffset(Particle* arg0);
void BattleAnim_InitEffects63And75Model38(Particle* arg0);
void BattleAnim_CallbackStartEffects63And75Model38FadeIn(Particle* arg0);
void func_843466EC(Gfx* arg0, s32 arg1, u16 arg2);
void func_843467B0(s32 arg0, arg1_func_84344CE8* arg1);
void func_843467F8(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void func_84346960(s32 arg0, arg1_func_84344CE8* arg1);
void func_843469A8(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void func_84346B10(s32 arg0, arg1_func_84344CE8* arg1);
void func_84346B58(void);
void func_84346BE0(void);
void func_84346DC4(void);
void func_84346E50(void);
void func_84346EEC(void);
void func_84346F40(void);
void BattleAnim_CallbackStartEffect10Model60AlphaFadeIn_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect10Model60AlphaFadeIn(Particle* arg0);
void func_8434719C(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void func_84347254(s32 arg0, arg1_func_84344CE8* arg1);
void func_8434729C(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void func_84347374(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_StartEffect10Model60AndModelAnimWait(void);
void func_84347448(void);
void BattleAnim_ApplySpeciesXZOffsetVariantA(Particle* arg0);
void BattleAnim_CallbackStartEffects50And82ModelDelay(Particle* arg0);
void BattleAnim_CallbackStartEffects50And82ScalePulse_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects50And82ScalePulse(Particle* arg0);
void BattleAnim_CallbackStartEffects50And82Descriptor48AnimatedScaleFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects50And82Descriptor48AnimatedScaleFade(Particle* arg0);
void BattleAnim_CallbackStartEffects50And82Descriptor4AAnimatedVerticalFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects50And82Descriptor4AAnimatedVerticalFade(Particle* arg0);
void func_84347BF4(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void func_84347D2C(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_CallbackStartEffects50And82CenterModelScalePaletteFade(Particle* arg0);
void BattleAnim_CallbackStartEffects50And82OffsetModelsScalePaletteFade(Particle* arg0);
void BattleAnim_CallbackEndEffects81And82ModelScalePaletteFade(Particle* arg0);
void BattleAnim_CallbackEndEffects81And82Descriptor4AAnimatedColorFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffects81And82Descriptor4AAnimatedColorFade(Particle* arg0);
void BattleAnim_CallbackEndEffects81And82Descriptor4FAnimatedPaletteFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffects81And82Descriptor4FAnimatedPaletteFade(Particle* arg0);
void func_84348630(void);
void func_843489FC(void);
void func_84348C6C(UNUSED s32 arg0, UNUSED s32 arg1);
void func_84348C78(UNUSED s32 arg0, UNUSED s32 arg1);
void BattleAnim_CallbackStartEffects71And74And111SpecialModelColorCycle_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects71And74And111SpecialModelColorCycle(Particle* arg0);
void func_84348F24(Gfx* arg0, s32 arg1, u16 arg2);
void func_84349010(s32 arg0, arg1_func_84344CE8* arg1);
void func_84349058(void);
void func_843490A8(void);
void func_84349108(void);
void func_8434915C(void);
void func_8434917C(void);
void func_843491D4(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void func_84349264(s32 arg0, arg1_func_84344CE8* arg1);
void func_843492AC(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void func_8434933C(s32 arg0, arg1_func_84344CE8* arg1);
void func_84349384(void);
f32 BattleAnim_GetSpeciesScaleAdjust(Particle* arg0);
void BattleAnim_CallbackStartEffect69ModelPhaseWait(Particle* arg0);
void func_84349504(void);
void BattleAnim_ApplySpeciesXZOffsetVariantB(Particle* arg0);
void func_84349628(void);
void func_8434967C(void);
void BattleAnim_ApplySpeciesYOffsetVariantA(Particle* arg0);
void func_84349830(void);
void func_843498D8(void);
void BattleAnim_ApplySpeciesYOffsetVariantB(Particle* arg0);
void func_84349A14(void);
void BattleAnim_CallbackStartEffect17ModelAnimFinish_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect17ModelAnimFinish(Particle* arg0);
void BattleAnim_CallbackEndEffect7ModelScaleAlphaFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect7ModelScaleAlphaFade(Particle* arg0);
void func_84349D10(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void func_84349F80(s32 arg0, arg1_func_84344CE8* arg1);
void func_84349FC8(Gfx* arg0, UNUSED arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void func_8434A18C(s32 arg0, arg1_func_84344CE8* arg1);
s16 BattleAnim_GetMoveKeyedModelVariantIndex(void);
s16 BattleAnim_GetMoveKeyedTintRampParam(void);
s16 BattleAnim_GetMoveKeyedTrailVariantParam(void);
void BattleAnim_StartEffect17ModelAnimFinish(void);
void func_8434A384(void);
f32 BattleAnim_GetSpeciesScaleAndApplyYOffset(Particle* arg0);
void func_8434A654(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void func_8434A6D8(s32 arg0, arg1_func_84344CE8* arg1);
void func_8434A720(Gfx* arg0, UNUSED arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void func_8434A794(s32 arg0, arg1_func_84344CE8* arg1);
void func_8434A7DC(void);
void BattleAnim_StartEffect39Descriptor26ModelAnimWaitSequence(void);
void func_8434A898(void);
void func_8434A930(void);
void func_8434A9CC(void);
void func_8434A9EC(void);
void func_8434AA6C(void);
void func_8434AAEC(Gfx* arg0, u8 arg1, UNUSED u16 arg2);
void func_8434AC44(s32 arg0, arg1_func_84344CE8* arg1);
void func_8434AC8C(void);
void func_8434ACEC(void);
void func_8434AD1C(void);
void func_8434AD70(void);
f32 BattleAnim_GetSpeciesScaleAndOffset(Particle* arg0);
void func_8434B000(void);
void func_8434B064(void);
void BattleAnim_ApplySpeciesYOffsetVariantC(Particle* arg0);
void BattleAnim_CallbackStartEffects95To97EndEffects62And63ModelFadeIn_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects95To97EndEffects62And63ModelFadeIn(Particle* arg0);
void func_8434B2B8(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void func_8434BA28(s32 arg0, arg1_func_84344CE8* arg1);
void func_8434BA70(void);
void func_8434BCD4(void);
void func_8434BF2C(void);
void func_8434C070(void);
void func_8434C0C4(void);
void func_8434C144(void);
void BattleAnim_CallbackStartEffects21And93ModelAlphaAnchorFollow_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects21And93ModelAlphaAnchorFollow(Particle* arg0);
void BattleAnim_CallbackEndEffect60Model42AnimC2RotationYFollow_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect60Model42AnimC2RotationYFollow(Particle* arg0);
void func_8434C3F0(Gfx* arg0, u8 arg1, UNUSED u16 arg2);
void func_8434C548(s32 arg0, arg1_func_84344CE8* arg1);
void func_8434C590(void);
void func_8434C5F0(void);
void func_8434C618(void);
void func_8434C720(void);
void func_8434C814(Gfx* arg0, u8* arg1, UNUSED u16 arg2);
void func_8434CA48(s32 arg0, arg1_func_84344CE8* arg1);
f32 BattleAnim_GetSpeciesScaleAdjustSmall(Particle* arg0);
void func_8434CAD8(void);
void func_8434CC68(void);
void func_8434CE14(void);
void func_8434CF64(void);
void func_8434D0F8(void);
void BattleAnim_CallbackStartEffect101EndEffect65Descriptor4ABurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect101EndEffect65Descriptor4ABurstChild(Particle* arg0);
void BattleAnim_CallbackStartEffect101ModelBurstEmitter_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect101ModelBurstEmitter(Particle* arg0);
void func_8434D448(void);
void BattleAnim_CallbackMove140EndEffect65EmitDescriptor4A_InitParticle(Particle* arg0);
void BattleAnim_CallbackMove140EndEffect65EmitDescriptor4A(Particle* arg0);
void func_8434D5EC(void);
void BattleAnim_CallbackStartEffect49EndEffect66ModelFadeIn_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect49EndEffect66ModelFadeIn(Particle* arg0);
void func_8434D77C(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void func_8434D890(s32 arg0, arg1_func_84344CE8* arg1);
void func_8434D8D8(void);
void func_8434D938(void);
void BattleAnim_CallbackEndEffects73And74DefaultDescriptorFade(Particle* arg0);
void func_8434DA94(void);
void func_8434DB40(void);
void func_8434DBEC(void);
void func_8434DD08(void);
f32 BattleAnim_GetSpeciesScaleAdjustTiny(Particle* arg0);
void BattleAnim_StartEffect3ModelTintAndVerticalFade(void);
void BattleAnim_EndEffect85TintAndDescriptorMode2Sequence(void);
void func_8434E02C(void);
void func_8434E0CC(void);
void func_8434E1B8(void);
void func_8434E21C(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2);
void func_8434E6AC(s32 arg0, arg1_func_84344CE8* arg1);
void BattleAnim_EndEffect72Descriptor20ModelAnimWaitSequence(void);
void func_8434E74C(void);
void BattleAnim_CallbackEndEffect76DefaultDescriptorModelFade(Particle* arg0);
void func_8434E870(void);
void func_8434E8E0(void);
void func_8434E940(void);
void func_8434E9A0(void);
void func_8434EA10(void);
void BattleAnim_CallbackStartEffects118And119ModelPalettePulse(Particle* arg0);
void func_8434EBA0(void);
void func_8434EC08(void);
void BattleAnim_CallbackEndEffect79DefaultDescriptorPaletteFade(Particle* arg0);
void func_8434ECF4(void);
void func_8434ED48(void);
void BattleAnim_CallbackStartEffects127And128Descriptor39ScaleFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects127And128Descriptor39ScaleFade(Particle* arg0);
void func_8434EF68(void);
void func_8434EFBC(void);
void func_8434F010(void);
void func_8434F060(void);
void func_8434F0B8(void);
void BattleAnim_CallbackStartEffect132Descriptor39DelayedRiseFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect132Descriptor39DelayedRiseFade(Particle* arg0);
void func_8434F350(void);
void BattleAnim_CallbackSharedDescriptor29ScaleAnimFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor29ScaleAnimFade(Particle* arg0);
void BattleAnim_CallbackEndEffect3Descriptor29DirectionalScaleFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect3Descriptor29DirectionalScaleFade(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade(Particle* arg0);
void BattleAnim_CallbackSharedOwnerKeyedGrowColorFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedOwnerKeyedGrowColorFade(Particle* arg0);
void BattleAnim_CallbackSharedOwnerKeyedGrowColorAlphaFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedOwnerKeyedGrowColorAlphaFade(Particle* arg0);
void BattleAnim_CallbackSharedOwnerKeyedAnimGrowFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedOwnerKeyedAnimGrowFade(Particle* arg0);
void BattleAnim_CallbackEndEffect88Descriptor2AOwnerKeyedAnimGrowFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect88Descriptor2AOwnerKeyedAnimGrowFade(Particle* arg0);
void BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor3DMetadataBurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor3DMetadataBurstChild(Particle* arg0);
void BattleAnim_CallbackSharedTieredSmallRiseImpulseFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedTieredSmallRiseImpulseFade(Particle* arg0);
void BattleAnim_CallbackSharedTieredLargeRiseImpulseFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedTieredLargeRiseImpulseFade(Particle* arg0);
void BattleAnim_CallbackStartEffect31Descriptor49TieredRiseImpulseFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect31Descriptor49TieredRiseImpulseFade(Particle* arg0);
void BattleAnim_SetupUnusedRiseImpulseVariant(Particle* arg0);
void BattleAnim_CallbackUnusedRiseImpulseVariant(Particle* arg0);
void BattleAnim_CallbackEndEffect55Descriptor49RiseGravityFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect55Descriptor49RiseGravityFade(Particle* arg0);
void BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade(Particle* arg0);
void BattleAnim_CallbackEndEffect67Descriptor3DAnimatedGravityFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect67Descriptor3DAnimatedGravityFade(Particle* arg0);
void BattleAnim_CallbackOrphanDescriptor34ColorFadeDetach_InitParticle(Particle* arg0);
void BattleAnim_CallbackOrphanDescriptor34ColorFadeDetach(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade(Particle* arg0);
void BattleAnim_SetupUnusedGlitterVariant(Particle* arg0);
void BattleAnim_CallbackUnusedGlitterVariant(Particle* arg0);
void BattleAnim_CallbackEndEffects37And38Descriptor38BurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffects37And38Descriptor38BurstChild(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion(Particle* arg0);
void BattleAnim_CallbackEndEffect52Descriptor42BurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect52Descriptor42BurstChild(Particle* arg0);
void BattleAnim_SetupEndEffect52DefaultBurstChild(Particle* arg0);
void BattleAnim_CallbackEndEffect52DefaultBurstEmitter(Particle* arg0);
void BattleAnim_SetupSharedScalePulseFallSetup(Particle* arg0);
void BattleAnim_CallbackSharedDescriptors42And44ScaleFall(Particle* arg0);
void BattleAnim_CallbackEndEffect23Descriptor44ScalePulse_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect23Descriptor44ScalePulse(Particle* arg0);
void BattleAnim_CallbackEndEffect67Descriptor42ScalePulseFallFade(Particle* arg0);
void BattleAnim_CallbackEndEffect43Descriptor40DelayedAnimFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffect43Descriptor40DelayedAnimFade(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion(Particle* arg0);
void BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter_InitParticle(Particle* arg0);
void BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter(Particle* arg0);
void BattleAnim_CallbackEndEffects37And38Descriptor34BurstEmitter_InitParticle(Particle* arg0);
s32 BattleAnim_CallbackEndEffects37And38Descriptor34BurstEmitter(Particle* arg0);
void BattleAnim_CallbackStartEffect56Descriptor40AnimScaleFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect56Descriptor40AnimScaleFade(Particle* arg0);
void BattleAnim_CallbackStartEffect56Descriptor46AnimColorImpulseFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect56Descriptor46AnimColorImpulseFade(Particle* arg0);
void BattleAnim_CallbackStartEffect73Descriptor15AnimatedColorImpulseFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect73Descriptor15AnimatedColorImpulseFade(Particle* arg0);
void BattleAnim_RecolorParticleByQueuedMoveId(Particle* arg0);
void BattleAnim_CallbackStartEffects28And53And65And76Descriptor47AnimatedScaleMotion_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects28And53And65And76Descriptor47AnimatedScaleMotion(Particle* arg0);
void BattleAnim_CallbackStartEffect81Descriptor4BGrowColorShiftFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect81Descriptor4BGrowColorShiftFade(Particle* arg0);
void BattleAnim_CallbackStartEffect81Descriptor3DRisingAnimFade_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect81Descriptor3DRisingAnimFade(Particle* arg0);
void BattleAnim_InitSharedVerticalFadeParticle_ApplySpeciesOffset(Particle* arg0);
void BattleAnim_InitSharedVerticalFadeParticle(Particle* arg0);
void BattleAnim_CallbackSharedAnimatedVerticalFade(Particle* arg0);
void BattleAnim_ApplySpeciesKeyedSpawnOffset(Particle* arg0);
void BattleAnim_CallbackEndEffect16MultiDescriptorAnimatedFallFade(Particle* arg0);
void BattleAnim_CallbackStartEffect69EndEffect78Descriptor4AFallFade(Particle* arg0);
void BattleAnim_CallbackStartEffect69EndEffect78Descriptor30YThresholdFall(Particle* arg0);
void BattleAnim_CallbackStartEffect101Descriptor3DMetadataBurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffect101Descriptor3DMetadataBurstChild(Particle* arg0);
void BattleAnim_CallbackDescriptor50BurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackDescriptor50BurstChild(Particle* arg0);
void BattleAnim_CallbackDescriptor50BurstEmitter_InitParticle(Particle* arg0);
void BattleAnim_CallbackDescriptor50BurstEmitter(Particle* arg0);
void func_843553B4(void);
void BattleAnim_CallbackUnusedFallingTrailVariant(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor3CExpandingFadeIn_InitParticle(Particle* arg0);
void BattleAnim_CallbackSharedDescriptor3CExpandingFadeIn(Particle* arg0);
void BattleAnim_CallbackStartEffects29And60And104And110Descriptor44BurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects29And60And104And110Descriptor44BurstChild(Particle* arg0);
void BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter_InitParticle(Particle* arg0);
void BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter(Particle* arg0);
void BattleAnim_CallbackDescriptor26BurstChild_InitParticle(Particle* arg0);
void BattleAnim_CallbackDescriptor26BurstChild(Particle* arg0);
void BattleAnim_CallbackDescriptor26BurstEmitter_InitParticle(Particle* arg0);
void BattleAnim_CallbackDescriptor26BurstEmitter(Particle* arg0);
void BattleAnim_SetupUnusedGrowingSparkVariant(Particle* arg0);
void BattleAnim_CallbackUnusedGrowingSparkVariant(Particle* arg0);
void func_84355E58(void);
void func_84355EF0(void);
void func_84355F88(void);
void func_84356020(void);
void func_843560B4(void);
void func_84356148(void);
void func_843561A0(void);
void func_843561F8(void);
void func_84356254(void);
void func_8435643C(void);
void func_843565DC(void);
void BattleAnim_OrphanDescriptor34Emitter(void);
void func_8435674C(void);
void func_843567F4(void);
void func_843568C8(void);
void func_843569A0(void);
void BattleAnim_EndEffects41And83Descriptor34BurstSequence(void);
void BattleAnim_StartEffect7GlobalTintFade(void);
void func_84356AF0(void);
void BattleAnim_StartEffect137Descriptor3FRisingFade(void);
void func_84356D04(void);
void func_84356DBC(void);
void func_84356EF4(void);
void BattleAnim_StartEffect13SecondaryOwnerSpeciesBranch(void);
void func_84357110(void);
void func_8435727C(void);
void func_8435742C(void);
void func_843574FC(void);
void func_84357700(void);
void func_8435783C(void);
void func_843579C0(void);
void func_84357A64(void);
void BattleAnim_StartEffect11GlobalTintFade(void);
void func_84357AE0(void);
void func_84357B80(void);
void BattleAnim_EndEffect26DelayedDescriptor29ScatterSequence(void);
void func_84357CC8(void);
void func_84357E60(void);
void func_84357F64(void);
void func_84358034(void);
void BattleAnim_StartEffect16TintDescriptor34Sequence(void);
void func_843581FC(void);
void func_84358288(void);
void func_8435839C(void);
void func_843584C0(void);
void func_84358538(void);
void BattleAnim_EndEffect58Descriptor4AAnd51Sequence(void);
void BattleAnim_EndEffectUnusedVerticalFadeAndDelayedFrameSequence(void);
void BattleAnim_StartEffects87And88Descriptor3DVerticalFadeSequence(void);
void func_84358A5C(void);
void BattleAnim_SpawnDefaultDescriptorBurstEmitterSequence(s32 arg0);
void func_84358DE4(void);
void BattleAnim_StartEffect105TintDefaultBurstAndDescriptor3CSequence(void);
void func_84358EA0(void);
void func_84358EDC(void);
void func_84358F6C(void);


void BattleAnim_RenderNop1(void);
void BattleAnim_RenderNop2(void);
void BattleAnim_DrawFullScreenColorOverlay(u8, u8, u8, u8);
void BattleAnim_RenderEffectsFrame(unk_D_86002F34_00C*);


void BattleAnim_NoopUpdateHook(void);
void func_843592E8(void);
void func_843592F0(void);
void func_843592F8(void);
void func_84359300(void);
void func_84359308(void);
void func_84359310(void);
void func_84359318(void);
void func_84359320(void);
void func_84359328(void);
void func_84359330(UNUSED s32 arg0);
void func_84359338(UNUSED s32 arg0);
void func_84359340(void);
void BattleAnim_DrawStoredColorOverlay(void);
void BattleAnim_ReinitAuxiliaryEffects(void);
void BattleAnim_DefaultStartEffect_Init(void);
void BattleAnim_DefaultEndEffect_Init(void);
s32 BattleAnim_DefaultStartEffect_CompleteImmediately(void);
s32 BattleAnim_DefaultEndEffect_CompleteImmediately(void);
void BattleAnim_DefaultStartEffect_Draw(void);
void BattleAnim_DefaultEndEffect_Draw(void);
void Battle_GetTertiaryOwnerBonePositionUnused(Vec3f* arg0);
void BattleAnim_EffectSecondaryOwnerAnchorPosition(Vec3f* arg0);
void BattleAnim_EffectTertiaryOwnerBonePosition(Vec3f* arg0);
void BattleAnim_EffectSecondaryOwnerBonePosition(Vec3f* arg0);
f32 BattleAnim_EffectTertiaryOwnerModelScale(void);
f32 BattleAnim_EffectSecondaryOwnerModelScale(void);
void BattleAnim_CalcVectorAtToDm(f32* arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5);
void BattleAnim_CalcVectorAtToDm2(f32* arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5);
void BattleAnim_ResetSharedEffectMatrix(void);
void BattleAnim_Effect5RibbonMesh_Init(void);
s32 BattleAnim_Effect5RibbonMesh_Update(void);
void BattleAnim_Effect5RibbonMesh_Draw(void);
void BattleAnim_EndEffect1RibbonMesh_Init(void);
s32 BattleAnim_EndEffect1RibbonMesh_Update(void);
void BattleAnim_EndEffect1RibbonMesh_Draw(void);
void BattleAnim_EndEffect19RibbonMesh_Init(void);
s32 BattleAnim_EndEffect19RibbonMesh_Update(void);
void BattleAnim_EndEffect19RibbonMesh_Draw(void);
void BattleAnim_Effect54RibbonMesh_Init(void);
s32 BattleAnim_Effect54RibbonMesh_Update(void);
void BattleAnim_Effect54RibbonMesh_Draw(void);
void BattleAnim_StartEffect34TerrainGrid_Init(void);
s32 BattleAnim_StartEffect34TerrainGrid_Update(void);
void BattleAnim_StartEffect34TerrainGrid_Draw(void);
void BattleAnim_EndEffect16_NoOpInit(void);
s32 BattleAnim_EndEffect16_CompleteImmediately(void);
void BattleAnim_EndEffect16_NoOpDraw(void);
void BattleAnim_StartEffect19Radial20_EmitVariantD(void);
void BattleAnim_StartEffect19Radial20_Init(void);
s32 BattleAnim_StartEffect19Radial20_Update(void);
void BattleAnim_StartEffect19Radial20_Draw(void);
void BattleAnim_EndEffect9Radial20_Init(void);
s32 BattleAnim_EndEffect9Radial20_Update(void);
void BattleAnim_EndEffect9Radial20_Draw(void);
void BattleAnim_StartEffect7TexturedRibbonSheet_Emit(void);
void BattleAnim_StartEffect7TexturedRibbonSheet_Init(void);
s32 BattleAnim_StartEffect7TexturedRibbonSheet_Update(void);
void BattleAnim_StartEffect7TexturedRibbonSheet_Draw(void);
void BattleAnim_StartEffect33Radial20_EmitVariantC(void);
void BattleAnim_StartEffect33Radial20_Init(void);
s32 BattleAnim_StartEffect33Radial20_Update(void);
void BattleAnim_StartEffect33Radial20_Draw(void);
void BattleAnim_EndEffect32Radial20_Init(void);
s32 BattleAnim_EndEffect32Radial20_Update(void);
void BattleAnim_EndEffect32Radial20_Draw(void);
void BattleAnim_EndEffect33Radial20_Init(void);
s32 BattleAnim_EndEffect33Radial20_Update(void);
void BattleAnim_EndEffect33Radial20_Draw(void);
void BattleAnim_StartEffect98Radial20_EmitVariantD(void);
void BattleAnim_StartEffect98Radial20_Init(void);
s32 BattleAnim_StartEffect98Radial20_Update(void);
void BattleAnim_StartEffect98Radial20_Draw(void);
void BattleAnim_StartEffect11Trail50Alt_Init(void);
s32 BattleAnim_StartEffect11Trail50Alt_Update(void);
void BattleAnim_StartEffect11Trail50Alt_Draw(void);
void BattleAnim_StartEffect57Trail50_Init(void);
s32 BattleAnim_StartEffect57Trail50_Update(void);
void BattleAnim_StartEffect57Trail50_Draw(void);
void BattleAnim_StartEffect42Trail40_Init(void);
s32 BattleAnim_StartEffect42Trail40_Update(void);
void BattleAnim_StartEffect42Trail40_Draw(void);
void BattleAnim_StartEffect43Trail40Variant_Init(void);
s32 BattleAnim_StartEffect43Trail40Variant_Update(void);
void BattleAnim_StartEffect43Trail40Variant_Draw(void);
void BattleAnim_StartEffect44Trail40GridAlt_Init(void);
s32 BattleAnim_StartEffect44Trail40GridAlt_Update(void);
void BattleAnim_StartEffect44Trail40GridAlt_Draw(void);
void BattleAnim_StartEffect45FourStreamTrail_Init(void);
s32 BattleAnim_StartEffect45FourStreamTrail_Update(void);
void BattleAnim_StartEffect45FourStreamTrail_Draw(void);
void BattleAnim_StartEffect62OwnerLinkedFourStream_Init(void);
s32 BattleAnim_StartEffect62OwnerLinkedFourStream_Update(void);
void BattleAnim_StartEffect62OwnerLinkedFourStream_Draw(void);
void BattleAnim_StartEffect67OwnerAnchoredFourStream_Init(void);
s32 BattleAnim_StartEffect67OwnerAnchoredFourStream_Update(void);
void BattleAnim_StartEffect67OwnerAnchoredFourStream_Draw(void);
void BattleAnim_StartEffect78Radial20_EmitVariantA(void);
void BattleAnim_StartEffect78Radial20_Init(void);
s32 BattleAnim_StartEffect78Radial20_Update(void);
void BattleAnim_StartEffect78Radial20_Draw(void);
void BattleAnim_StartEffect26DoubleTextureTrail_Seed(void);
void BattleAnim_StartEffect26DoubleTextureTrail_Init(void);
s32 BattleAnim_StartEffect26DoubleTextureTrail_Update(void);
void BattleAnim_StartEffect26DoubleTextureTrail_Draw(void);
void BattleAnim_StartEffect47SixSlotTrail_Seed(void);
void BattleAnim_StartEffect47SixSlotTrail_Init(void);
s32 BattleAnim_StartEffect47SixSlotTrail_Update(void);
void BattleAnim_StartEffect47SixSlotTrail_Draw(void);
void BattleAnim_StartEffect4DoubleTextureTrail_Seed(void);
void BattleAnim_StartEffect4DoubleTextureTrail_Init(void);
s32 BattleAnim_StartEffect4DoubleTextureTrail_Update(void);
void BattleAnim_StartEffect4DoubleTextureTrail_Draw(void);
void BattleAnim_StartEffect77DoubleTextureTrail_Seed(void);
void BattleAnim_StartEffect77DoubleTextureTrail_Init(void);
s32 BattleAnim_StartEffect77DoubleTextureTrail_Update(void);
void BattleAnim_StartEffect77DoubleTextureTrail_Draw(void);
void BattleAnim_StartEffect70DoubleTextureTrail_Seed(void);
void BattleAnim_StartEffect70DoubleTextureTrail_Init(void);
s32 BattleAnim_StartEffect70DoubleTextureTrail_Update(void);
void BattleAnim_StartEffect70DoubleTextureTrail_Draw(void);
void BattleAnim_StartEffect39DoubleTextureTrail_Seed(void);
void BattleAnim_StartEffect39SixSlotTrail_Seed(void);
void BattleAnim_StartEffect39CombinedTrail_Init(void);
s32 BattleAnim_StartEffect39CombinedTrail_Update(void);
void BattleAnim_StartEffect39CombinedTrail_Draw(void);


void RibbonMesh_Init(void);
void RibbonMesh_Configure(RibbonMesh* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9);
void RibbonMesh_Spawn(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
void RibbonMesh_UpdateEnvAlpha(RibbonMesh* arg0);
s32 RibbonMesh_Update(RibbonMesh* arg0);
s32 RibbonMesh_UpdatePool(void);
Gfx* RibbonMesh_Draw(Gfx* arg0, RibbonMesh* arg1);
Gfx* RibbonMesh_DrawPool(Gfx* arg0);
void TerrainGrid_BuildCameraBounds(unk_D_843975E8* arg0, f32 arg1);
f32 TerrainGrid_SampleHeightAndSlope(f32 arg0, f32 arg1, f32* arg2);
s32 TerrainGrid_UpdateWaves(void);
void TerrainGrid_Init(s32 arg0, s16 arg1, s16 arg2);
s32 TerrainGrid_Update(void);
Gfx* TerrainGrid_Draw(Gfx* arg0);


void Radial20_Init(f32 arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9);
f32 Strip400_GetTailFadeRatio(void);
s32 Radial20_Update(void);
Gfx* Strip400_Draw(Gfx* arg0);
void Radial20_ResetPool(void);
void Radial20_VariantA(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, f32 argB, f32 argC, f32 argD, s16 argE);
void Radial20_VariantB(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, f32 argB, f32 argC, f32 argD, s16 argE);
void Radial20_VariantC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB, u8 argC, u8 argD, f32 argE, f32 argF, f32 arg10, s16 arg11);
void Radial20_VariantD(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB, u8 argC, u8 argD, f32 argE, f32 argF, f32 arg10, s16 arg11);
void Radial20_VariantE(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, f32 argB, f32 argC, f32 argD, s16 argE);
void Radial20_RotateVertexOffset(f32 arg0, UNUSED Vec3f* arg1, Vec3f* arg2, f32 arg3, UNUSED f32 arg4, UNUSED f32 arg5, UNUSED f32 arg6);
void Radial20_UpdateNode(Radial20* arg0);
s32 Radial20_IsComplete(void);
Gfx* func_84362084(Gfx* arg0);


void Trail40_Init(s16 arg0);
void Trail40_Start(s32 arg0, s32 arg1);
void Trail40Node_FillVertex(Trail40Node* arg0, Vtx* arg1);
s32 Trail40_IsComplete(void);
void Trail40_Reset(void);
Gfx* Trail40_Draw(Gfx* arg0);


void Trail40Variant_ApplyRippleAtPoint(s16 arg0, s16 arg1);
void Trail40Variant_InitPool(s16 arg0);
void Trail40Variant_UpdateNodes(s32 arg0, s32 arg1);
void Trail40Variant_WriteVertex(Trail40VariantNode* arg0, Vtx* arg1);
s32 Trail40Variant_AdvanceTimer(void);
void Trail40Variant_SetupCameraTransform(void);
Gfx* Trail40Variant_BuildGfx(Gfx* arg0);


void Trail40GridAlt_Init(s16 arg0);
void Trail40GridAlt_Start(s32 arg0, s32 arg1);
void Trail40GridAlt_FillVertex(Trail40Node* arg0, Vtx* arg1);
s32 Trail40GridAlt_IsComplete(void);
void Trail40GridAlt_Reset(void);
Gfx* Trail40GridAlt_Draw(Gfx* arg0);


void TexturedRibbonSheet_Init(void);
void TexturedRibbonSheet_Start(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, f32 argA, s16 argB);
void TexturedRibbonSheet_Update(f32 arg0, Vec3f* arg1, f32 arg2);
void TexturedRibbonSheet_UpdateRecord(TexturedRibbonSheet* arg0);
s32 TexturedRibbonSheet_IsComplete(void);
Gfx* TexturedRibbonSheet_Draw(Gfx* arg0);


Gfx* func_84367660(Gfx* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8);


void FourStreamTrail_Init(void);
void FourStreamTrail_Start(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, f32 argA, f32 argB, f32 argC, s16 argD);
void FourStreamTrail_Update(f32 arg0, Vec3f* arg1, f32 arg2, f32 arg3);
void FourStreamTrail_UpdateNodeChain(FourStreamTrail* arg0);
s32 FourStreamTrail_IsComplete(void);
Gfx* FourStreamTrail_Draw(Gfx* arg0);


void OwnerLinkedFourStream_Init(void);
void OwnerLinkedFourStream_Start(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, f32 argA, f32 argB, f32 argC, s16 argD);
void OwnerLinkedFourStream_Update(f32 arg0, Vec3f* arg1, f32 arg2);
void OwnerLinkedFourStream_UpdateNodeChain(OwnerLinkedFourStream* arg0);
s32 OwnerLinkedFourStream_IsComplete(void);
Gfx* OwnerLinkedFourStream_Draw(Gfx* arg0);


void OwnerAnchoredFourStream_Init(void);
void OwnerAnchoredFourStream_Start(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, f32 argA, f32 argB, f32 argC, s16 argD);
void OwnerAnchoredFourStream_Update(f32 arg0, Vec3f* arg1, f32 arg2);
void OwnerAnchoredFourStream_UpdateNodeChain(OwnerAnchoredFourStream* arg0);
s32 OwnerAnchoredFourStream_IsComplete(void);
Gfx* OwnerAnchoredFourStream_Draw(Gfx* arg0);


void Trail50Effect_Init(void);
void Trail50Effect_Start(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, f32 argA, f32 argB, f32 argC, s16 argD);
void Trail50Effect_Update(f32 arg0, Vec3f* arg1, f32 arg2);
void Trail50Effect_AdvanceNodes(Trail50Effect* arg0);
s32 Trail50Effect_IsComplete(void);
Gfx* Trail50Effect_Draw(Gfx* arg0);


void Trail50EffectAlt_Init(void);
void Trail50EffectAlt_Start(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, f32 argA, f32 argB, f32 argC, s16 argD);
void Trail50EffectAlt_Update(f32 arg0, Vec3f* arg1, f32 arg2);
void Trail50EffectAlt_AdvanceNodes(Trail50Effect* arg0);
s32 Trail50EffectAlt_IsComplete(void);
Gfx* Trail50EffectAlt_Draw(Gfx* arg0);


void DoubleTextureTrail_InitPool(void);
void DoubleTextureTrail_Spawn(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, s16 argB, s32 argC, s32 argD, s16 argE, s16 argF, s16 arg10, s16 arg11, s16 arg12, s16 arg13, s16 arg14, s16 arg15, unk_D_843C2C00_024* arg16, unk_D_843C2C00_024* arg17, u8 arg18, u8 arg19, u8 arg1A, u8 arg1B, u8 arg1C, u8 arg1D, u8 arg1E, u8 arg1F, u8 arg20, u8 arg21, u8 arg22, u8 arg23, u8 arg24);
void DoubleTextureTrail_RotateVertexOffset(f32 arg0, Vec3f* arg1, f32 arg2);
void DoubleTextureTrail_Update(DoubleTextureTrail* arg0);
s32 DoubleTextureTrail_UpdateAll(void);
Gfx* func_8436C6A4(Gfx* arg0, DoubleTextureTrail* arg1, s16 arg2, s16 arg3);
Gfx* DoubleTextureTrail_LoadTextures(Gfx* arg0, DoubleTextureTrail* arg1);
Gfx* DoubleTextureTrail_DrawAll(Gfx* arg0);


void BattleAnim_SixSlotTrail_ResetPool(void);
void BattleAnim_SixSlotTrail_Spawn(s16 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB, u8 argC, u8 argD, u8 argE, u8 argF, f32 arg10, f32 arg11, f32 arg12, s16 arg13, s32 arg14, s32 arg15, s16 arg16, s16 arg17, s16 arg18, s16 arg19, s16 arg1A, s16 arg1B, s16 arg1C, s16 arg1D, unk_D_843C2C00_024* arg1E, unk_D_843C2C00_024* arg1F);
void BattleAnim_SixSlotTrail_ComputeCameraRelativeOffset(s32 arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
void BattleAnim_SixSlotTrail_ComputeRotatedOffset(f32 arg0, Vec3f* arg1, Vec3f* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void BattleAnim_SixSlotTrail_UpdateSlot(unk_D_843C3508* arg0);
s32 BattleAnim_SixSlotTrail_UpdateAll(void);
Gfx* BattleAnim_SixSlotTrail_DrawSegments(Gfx* arg0, unk_D_843C3508* arg1);
Gfx* BattleAnim_SixSlotTrail_LoadTextures(Gfx* arg0, unk_D_843C3508* arg1);
Gfx* BattleAnim_SixSlotTrail_DrawAll(Gfx* arg0);
void AuxiliaryEffect_Init(void);
s16 AuxiliaryEffect_Alloc(void);
void AuxiliaryEffect_Spawn(s16 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, f32 arg5);
void AuxiliaryEffect_Update(s16 arg0);
Gfx* AuxiliaryEffect_DrawOne(Gfx* arg0, AuxiliaryEffectNode* arg1, MtxF* arg2);
Gfx* AuxiliaryEffect_Draw(s16 arg0, Gfx* arg1);
void func_8436EED4(void);
void func_8436EEDC(void);
s32 func_8436EEE4(s32 arg0);


void BattleScene_SetStripWipeState(s32 arg0, s32 arg1);
s32 BattleScene_GetStripWipeState(void);
void BattleScene_UpdateStripWipe(void);
Gfx* BattleScene_BuildStripWipeDisplayList(Gfx* arg0, s32 arg1);
void BattleScene_DrawStripWipe(void);


void func_8436F6C0(void);


void func_8436F6D0(void);
u8 Battle_Random(void);
u8 Battle_RandomAccuracy(void);
void func_8436F838(s32 arg0, s32 arg1);
void Battle_ResetTransientRuntimeState(s32 arg0, s32 arg1);
void func_8436FA80(Battler* arg0);
void Battle_ApplyDamageRandomFactor(void);
u16 Battle_DetermineMoveOrder(Battler* arg0, Battler* arg1);
s32 func_8436FD54(u8 arg0, u8* arg1, s32 arg2);
void Battle_SetActiveMoveFromSlotIndex(void);
s32 func_8436FDBC(void);
void func_8436FDF4(s32 arg0, BattleMon* arg1);
void func_84370090(BattleMon* arg0);
void func_843700F0(void);
s32 Battle_CalcDamage(void);
void Battle_ApplyDamage(void);
void Battle_DecrementPP(s32 arg0);
void func_84370790(void);
void func_843708A0(void);
void func_843708CC(void);
void func_84370ADC(Battler* arg0);
void func_84370B0C(Battler* arg0);
void func_84370B44(Battler* arg0);
void func_84370B7C(Battler* arg0);
s32 Battle_IsPartyMemberAlive(Battler* arg0);
void func_84370E70(void);
void func_84370E78(void);
void func_84370E80(void);
void Battle_ApplyRageContinuation(void);
void func_84371010(void);
void func_84371080(void);
void func_8437114C(void);
void Battle_QueueMoveFailureAndApplyRecoil(void);
void func_843714D8(void);
s32 Battle_Effect_Metronome(void);
void Battle_ApplyPoisonOrBurnDamage(void);
void Battle_ApplyLeechSeedDamage(void);
s32 Battle_ApplyResidualEffects(void);
void func_843718DC(void);
s32 Battle_TryLoadFollowupMoveFromTarget(void);
void Battle_ApplyTypeEffectAndSTAB(void);
s32 Battle_Effect_Counter(void);
s32 Battle_CheckCriticalHit(void);
s32 Battle_CheckMonCanAct(void);
void func_84372670(void);
void Battle_HandleFaint(Battler* arg0);
void func_84372C40(Battler* arg0);
void func_84372D88(Battler* arg0);
void func_84372ED0(Battler* arg0);
void func_84373018(Battler* arg0);
s32 Battle_CheckSideDefeatAfterResidualStatus(Battler* arg0);
s32 Battle_CheckFaintAfterMove(void);
void Battle_ResolveMonAction(void);
void func_84373570(Battler* arg0);


u16 Battle_ApplyStatStageMultiplier(u16* arg0, u16 arg1, u8 arg2);
void Battle_Effect_Sleep(void);
void Battle_Effect_Poison(void);
void Battle_Effect_DrainHP(void);
void Battle_Effect_Explosion(void);
void Battle_Effect_SecondaryStatusChance(void);
void Battle_ApplyRageStatBoost(void);
void Battle_Effect_RaiseOwnStat(void);
void Battle_Effect_LowerStat(void);
void Battle_Effect_Bide(void);
void Battle_Effect_Thrash(void);
void Battle_Effect_ForceSwitchOrFlee(void);
void Battle_Effect_MultiHit(void);
void Battle_Effect_Flinch(void);
void Battle_Effect_OHKO(void);
void Battle_Effect_TwoTurnMove(void);
void Battle_Effect_Trap(void);
void Battle_Effect_Mist(void);
void Battle_Effect_FocusEnergy(void);
void Battle_Effect_Recoil(void);
void Battle_Effect_ConfuseChance(void);
void Battle_Effect_Confuse(void);
void Battle_Effect_Paralyze(void);
void Battle_Effect_Substitute(void);
void Battle_Effect_Recharge(void);
void Battle_Effect_Rage(void);
void Battle_Effect_Mimic(void);
void Battle_Effect_LeechSeed(void);
void Battle_Effect_Splash(void);
void Battle_Effect_Disable(void);
void Battle_Effect_PayDay(void);
void Battle_Effect_Conversion(void);
void Battle_Effect_Haze(void);
void Battle_Effect_Heal(void);
void Battle_Effect_Transform(void);
void Battle_Effect_ReflectLightScreen(void);
void Battle_RunMoveEffect(void);
void Battle_ExecuteMoveEffect(void);


void BattleAI_LoadConfiguration(s32 arg0, u32 arg1);
void func_843767DC(void);
s32 BattleAI_RandomBelowInclusive(s32 arg0);
void BattleAI_SeedRandomState(u8 arg0);
u8 BattleAI_EstimateCriticalHitChance(BattleMonRuntime* arg0, BattleMonRuntime* arg1, u8 arg2);
u16 BattleAI_ApplyMoveEffectDamageOverride(BattleMonRuntime* arg0, BattleMonRuntime* arg1);
void BattleAI_ClampDamageRatio(void);
void BattleAI_ApplyTypeEffectAndStab(BattleMonRuntime* arg0, BattleMonRuntime* arg1);
void BattleAI_PrepareDamageCalcState(BattleMonRuntime* arg0, BattleMonRuntime* arg1, u8 arg2);
void BattleAI_CalcDamage(BattleMonRuntime* arg0, BattleMonRuntime* arg1);
u16 BattleAI_PredictDamage(BattleMonRuntime* arg0, BattleMonRuntime* arg1, u8 arg2, u8 arg3);
void BattleAI_ResetTeamState(BattleAiMonState* arg0);
s32 BattleAI_ScaleSignedRatio(s32 arg0, s32 arg1);
void BattleAI_AppendTrainerTeamSpecies(TeamRoster* arg0);
s32 BattleAI_FindSpeciesIndex(s32 arg0);
s32 BattleAI_IsThresholdMet(u8 arg0, u8 arg1);
u16 BattleAI_ScaleStatHigh(BattleMonRuntime* arg0);
u16 BattleAI_ScaleStatLow(BattleMonRuntime* arg0);
f32 Battle_GetTypeEffectiveness(u8 arg0, BattleMonRuntime* arg1);
s32 BattleAI_AllCandidatesResistType(u8 arg0, BattleAiTeamState* arg1);
s32 BattleAI_IsTypeMatchupAllowed(u8 arg0, u8 arg1);
s32 BattleAI_HasCandidateStatusMask(BattleAiTeamState* arg0, u8 arg1);
u8 BattleAI_ClassifyMoveAvailability(BattleAiMonState* arg0, BattleAiMonState* arg1, u8 arg2);
void func_843779C0(void);
u8 BattleAI_FindHeuristicMove(BattleAiMonState* arg0, BattleAiMonState* arg1, u8 arg2, u8* arg3);
u8 BattleAI_SelectBestHeuristicCandidate(BattleAiMonState* arg0, BattleAiTeamState* arg1, u8* arg2, u8 arg3, u8* arg4);
s32 BattleAI_IsPriorityTableMove(u8 arg0, u8 arg1);
u8 BattleAI_ScoreCategorySetLowPP(BattleAiMonState* arg0, BattleAiMonState* arg1);
u8 BattleAI_ScoreCategorySetReady(BattleAiMonState* arg0, BattleAiMonState* arg1);
u8 BattleAI_HasExactlyOneUsableCandidate(BattleAiTeamState* arg0);
void BattleAI_InitializeOrderCandidates(TeamRoster* arg0, TeamRoster* arg1, TeamRoster* arg2, unk_D_843C5568* arg3, s32 arg4);
void BattleAI_UpdateRememberedMoveCandidate(BattleAiMonState* arg0, u8 arg1);
u16 BattleAI_ScoreMove(BattleMonRuntime* arg0, BattleMonRuntime* arg1, u8 arg2);
void BattleAI_PickBestMove(BattleMonRuntime* arg0, BattleMonRuntime* arg1, u16* arg2, u8* arg3, u8 arg4, u8 arg5);
s32 BattleAI_ScoreAllCandidateMoves(BattleAiMonState* arg0, BattleAiMonState* arg1, u8* arg2, u8 arg3);
s32 BattleAI_ScoreAllCandidateMovesRatioToMaxHp(BattleAiMonState* arg0, BattleAiMonState* arg1, u8* arg2, u8 arg3);
s32 BattleAI_ScoreAllCandidateMovesRatioToCurrentHp(BattleAiMonState* arg0, BattleAiMonState* arg1, u8* arg2, u8 arg3);
void func_8437921C(void);
u8 BattleAI_CalcStagedMovePower(BattleMonRuntime* arg0, BattleMonRuntime* arg1, u8 arg2, u8 arg3);
void BattleAI_ApplyInverseWeightScale(u8 arg0, u8* arg1);
void BattleAI_BuildMoveCandidateScores(BattleAiMonState* arg0, BattleAiMonState* arg1, s32 arg2, u8 arg3, u8 arg4, BattleAiScoredMove* arg5);
s32 BattleAI_HasScoredMoveAtValue(BattleAiScoredMove* arg0, u8 arg1, u8 arg2);
s32 BattleAI_IsCandidateScoreBelowPeers(BattleAiScoredMove* arg0, u8 arg1, u8 arg2, u8 arg3);
u8 BattleAI_HasOtherCandidateAtLeastScore(BattleAiScoredMove* arg0, u8 arg1, u8 arg2, u8 arg3);
void func_8437B0CC(BattleAiTeamState* arg0, BattleAiTeamState* arg1, u8 arg2, BattleAiScoredMove* arg3, u8 arg4);
s32 BattleAI_IsScoreBetter(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 BattleAI_SelectBestScoredMove(BattleAiMonState* arg0, UNUSED BattleAiMonState* arg1, u8 arg2, BattleAiScoredMove* arg3);
s32 BattleAI_ChooseMoveForCandidate(void);
u16 BattleAI_ComputeDifficultyThreshold(u8 arg0, u8 arg1);
u8 BattleAI_GetPpWeight(u8 arg0);
void BattleAI_InitTeamContext(TeamRoster* arg0, TeamRoster* arg1, BattleAiTeamState* arg2, u8 arg3);
s32 BattleAI_IsSpeciesUnselected(BattleAiTeamState* arg0, u8* arg1, u8 arg2);
s32 BattleAI_IsSpeciesInList(BattleAiTeamState* arg0, u8* arg1, u8 arg2, u8 arg3);
s32 BattleAI_MeetsHpBudgetConstraint(BattleAiTeamState* arg0, u8* arg1, u8 arg2, s32 arg3);
s32 BattleAI_IsCandidateEligible(BattleAiTeamState* arg0, u8* arg1, u8 arg2, u8 arg3);
s32 BattleAI_GroupSharesTypeWeakness(BattleAiTeamState* arg0, u8* arg1, u8 arg2);
s32 BattleAI_ScoreAllTeamCandidates(BattleAiTeamState* arg0, BattleAiTeamState* arg1, u8* arg2, s32* arg3);
s32 BattleAI_InsertRankedCandidateGroup(BattleAiTeamState* arg0, s32* arg1, s32 arg2, unk_func_8437F85C_arg3* arg3, u8* arg4, u8 arg5, u8 arg6);
void BattleAI_SelectRandomFallbackOrder(BattleAiTeamState* arg0, u8* arg1, s32 arg2);
s32 BattleAI_SelectRandomUsableCandidate(BattleAiTeamState* arg0);
s32 BattleAI_SelectRandomUsableMoveSlot(BattleMonRuntime* arg0);
s32 func_8437FD74(BattleAiTeamState* arg0, u8* arg1, s32* arg2, u8 arg3);
s32 BattleAI_SelectLeadFromScoredGroup(BattleAiTeamState* arg0, BattleAiTeamState* arg1, u8* arg2, u8* arg3, s32* arg4);
s32 BattleAI_TryBuildScoredOrder(BattleAiTeamState* arg0, BattleAiTeamState* arg1, u8* arg2, u8* arg3, s32 arg4);
void BattleAI_UpdateTeamAdvantageBias(void);
u8 BattleAI_SelectBestSwitchCandidateIndex(BattleAiTeamState* arg0, BattleAiTeamState* arg1);
u8 BattleAI_SelectBestAttackTargetIndex(BattleAiMonState* arg0, s32* arg1, s32* arg2, BattleAiTeamState* arg3, u8 arg4, s32 arg5);
s32 BattleAI_ScoreSwitchUrgencyFromThreatMove(BattleAiMonState* arg0, BattleAiMonState* arg1, u8 arg2);
s32 BattleAI_ComputeAttackTargetScore(unk_func_8438220C* arg0);
s32 BattleAI_ScoreAttackOption(BattleAiMonState* arg0, BattleAiMonState* arg1, BattleAiTeamState* arg2, u8* arg3, s32* arg4, s32* arg5, s32* arg6, s32* arg7, s32* arg8);
s32 BattleAI_ScoreAttackOptionDoubles(BattleAiMonState* arg0, BattleAiMonState* arg1, BattleAiTeamState* arg2, u8* arg3, unk_func_8438220C* arg4);
u8 BattleAI_ScoreAttackVsSwitch(BattleAiMonState* arg0, BattleAiMonState* arg1, BattleAiTeamState* arg2, BattleAiTeamState* arg3, u8* arg4, unk_func_8438220C* arg5);
u16 BattleAI_ApplyStatStageModifier(u16* arg0, u16 arg1, u8 arg2);
void BattleAI_SimulateStatBoostGuess(BattleMonRuntime* arg0, BattleMonRuntime* arg1, u8 arg2, u8 arg3);
void BattleAI_BuildAllCandidateMoveScores(unk_func_8438220C* arg0);
void BattleAI_RefineAllCandidateMoveScores(unk_func_8438220C* arg0);
u8 BattleAI_DecideFinalAction(unk_func_8438220C* arg0);
s32 BattleAI_DecideAction(void);
s32 BattleAI_ResolveTiedActionChoice(s32 arg0);
s32 BattleAI_MatchesLastMoveCategory(u8 arg0, u8 arg1);
s32 BattleAI_IsDiscouragedRepeatCategory(u8 arg0, u8 arg1);
s32 BattleAI_IsBannedRandomMove(u8 arg0);
s32 BattleAI_IsRestrictedRandomMove(u8 arg0);
s32 BattleAI_IsMoveExcludedForSpecies(BattleMonRuntime* arg0, s32 arg1, u8 arg2, u8 arg3);
s32 BattleAI_IsMoveIneffective(BattleMonRuntime* arg0, BattleMonRuntime* arg1, u8 arg2);
void BattleAI_SyncTeamStateFromRuntime(void);
s32 func_843831A0(TeamRoster* arg0, TeamRoster* arg1, TeamRoster* arg2, s32 arg3, u8* arg4, s32 arg5, s32 arg6);
void BattleAI_RecordUsedMove(UNUSED s32 arg0, UNUSED s32 arg1, s32 arg2);
s32 BattleAI_ChooseAction(UNUSED s32 arg0);
void BattleAI_InitTrainerRecords(void);
s32 BattleAI_ResolveRandomMove(s32 arg0, s32 arg1);

#endif // _FRAGMENT62_H_
