#ifndef _COMMON_H
#define _COMMON_H

#include <ultra64.h>
#include <PR/sched.h>

typedef unsigned int uintptr_t;

#include "macros.h"

#include "attributes.h"
#include "functions.h"
#include "variables.h"
#include "sections.h"
#include "gfx.h"
#include "color.h"
#include "sound.h"
#include "math.h"

typedef struct unk_D_86002F58_004_000_00C_028 {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char pad6[6];
    /* 0x0C */ s32* unk_0C;
    /* 0x10 */ s32* unk_10;
} unk_D_86002F58_004_000_00C_028; // size >= 0x14

typedef unk_D_86002F58_004_000_00C_028* (*unk_D_86002F58_004_000_00C_028_func)(s32, s32);

typedef struct unk_D_86002F58_004_000_00C {
    /* 0x00 */ char unk_00[0x28];
    /* 0x28 */ unk_D_86002F58_004_000_00C_028_func unk_28;
} unk_D_86002F58_004_000_00C; // size >= 0x2C

typedef union unk_D_86002F58_004_000_010_02C {
    struct {
        u16 unk_00;
        u16 unk_02;
    };
    u32 raw;
} unk_D_86002F58_004_000_010_02C; // size = 0x4

typedef struct unk_D_86002F58_004_000_010_024 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk02[0x6];
    /* 0x08 */ struct unk_D_86002F58_004_000_004* unk_08;
} unk_D_86002F58_004_000_010_024; // size >= 0xC

typedef struct unk_D_86002F58_004_000_010 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x04 */ s32 unk_04[1];
    /* 0x08 */ char pad8[0x10];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ unk_D_86002F58_004_000_010_024* unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ unk_D_86002F58_004_000_010_02C unk_2C;
    /* 0x30 */ OSMesgQueue unk_30;
    /* 0x48 */ OSMesg unk_48;
    /* 0x4C */ char pad4C[0x4];
    /* 0x50 */ OSMesgQueue unk_50;
    /* 0x68 */ OSMesg unk_68;
    /* 0x6C */ char pad6C[0x4];
} unk_D_86002F58_004_000_010; // size = 0x70

typedef struct unk_D_86002F58_004_000_004 {
    /* 0x00 */ struct unk_D_86002F58_004_000_004* unk_00[4];
    /* 0x04 */ unk_D_86002F58_004_000_00C* unk_04;
    /* 0x08 */ unk_D_86002F58_004_000_010* unk_08;
} unk_D_86002F58_004_000_004; // size >= 0x0C

typedef struct unk_D_86002F58_004_000_000 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ struct unk_D_86002F58_004_000_000* unk_04;
    /* 0x08 */ struct unk_D_86002F58_004_000_000* unk_08;
    /* 0x0C */ unk_D_86002F58_004_000_00C* unk_0C;
    /* 0x10 */ unk_D_86002F58_004_000_010* unk_10;
    /* 0x14 */ s32 unk_14;
} unk_D_86002F58_004_000_000; // size = 0x18

typedef struct unk_D_86002F58_004_000_040_004 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk02[0x2];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u32 unk_14;
    /* 0x18 */ u32 unk_18;
} unk_D_86002F58_004_000_040_004; // size >= 0x1C

typedef struct unk_D_86002F58_004_000_040 {
    /* 0x00 */ s16 unk_00;
    /* 0x04 */ unk_D_86002F58_004_000_040_004* unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ char unk10[0x2];
    /* 0x12 */ u16 unk_12;
} unk_D_86002F58_004_000_040; // size >= 0x14

typedef struct unk_D_86002F58_004_000_054_004 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[0x4];
    /* 0x0A */ u16 unk_0A;
} unk_D_86002F58_004_000_054_004; // size >= 0x0C

typedef struct unk_D_86002F58_004_000_054 {
    /* 0x00 */ s16 unk_00;
    /* 0x04 */ unk_D_86002F58_004_000_054_004* unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} unk_D_86002F58_004_000_054; // size = 0xC

typedef struct unk_D_86002F58_004_000_0A8 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x04 */ Vec3f unk_04;
} unk_D_86002F58_004_000_0A8; // size = 0x10

typedef struct unk_D_86002F58_004_000 {
    /* 0x000 */ unk_D_86002F58_004_000_000 unk_000;
    /* 0x018 */ s16 unk_018;
    /* 0x01A */ s16 unk_01A;
    /* 0x01C */ u8 unk_01C;
    /* 0x01D */ u8 unk_01D;
    /* 0x01E */ Vec3s unk_01E;
    /* 0x024 */ Vec3f unk_024;
    /* 0x030 */ Vec3f unk_030;
    /* 0x03C */ Color_RGBA8_u32 unk_03C;
    /* 0x040 */ unk_D_86002F58_004_000_040 unk_040;
    /* 0x054 */ unk_D_86002F58_004_000_054 unk_054;
    /* 0x060 */ MtxF unk_060;
    /* 0x0A0 */ Color_RGBA8_u32 unk_0A0;
    /* 0x0A4 */ char pad0A4[2];
    /* 0x0A6 */ u8 unk_0A6;
    /* 0x0A7 */ u8 unk_0A7;
    /* 0x0A8 */ unk_D_86002F58_004_000_0A8 unk_0A8[1];
    /* 0x0B8 */ char pad0B8[0x24];
    /* 0x0DC */ Vec3f unk_0DC;
    /* 0x0E0 */ char pad0E0[0x4];
    /* 0x0EC */ Vec3f unk_0EC;
    /* 0x0F8 */ char pad0F8[0x4];
    /* 0x0FC */ Vec3f unk_0FC;
    /* 0x108 */ char pad108[0x60];
} unk_D_86002F58_004_000; // size = 0x168

typedef struct unk_D_86002F34_000_014_004 {
    /* 0x00 */ u8 unk_00[5];
} unk_D_86002F34_000_014_004; // size = 0x5

typedef struct unk_D_86002F34_000_014_010 {
    /* 0x00 */ u8 unk_00[4];
} unk_D_86002F34_000_014_010; // size = 0x4

typedef struct unk_D_86002F34_000_014 {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ u8* unk_04;
} unk_D_86002F34_000_014; // size >= 0x8

struct GraphNode;
typedef s32 (*func_D_86002F34_000_010)(s32, struct GraphNode*);

typedef struct GraphNode {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ struct GraphNode* unk_04;
    /* 0x08 */ struct GraphNode* unk_08;
    /* 0x0C */ struct unk_D_86002F34_00C* unk_0C;
    /* 0x10 */ func_D_86002F34_000_010 unk_10;
    /* 0x14 */ unk_D_86002F34_000_014* unk_14;
} GraphNode; // size = 0x18

typedef struct unk_D_86002F34_00C_018 {
    /* 0x00 */ Vp* vp;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ s16 width;
    /* 0x0A */ s16 height;
} unk_D_86002F34_00C_018; // size = 0xC

typedef struct unk_D_86002F34_00C_024 {
    /* 0x00 */ Mtx* mtx;
    /* 0x04 */ u16 perspNorm;
    /* 0x08 */ f32 fovy;
    /* 0x0C */ f32 aspect;
    /* 0x10 */ f32 near;
    /* 0x14 */ f32 far;
    /* 0x18 */ f32 scale;
} unk_D_86002F34_00C_024; // size = 0x1C

typedef struct unk_D_86002F34_00C_040 {
    /* 0x00 */ Mtx* mtx;
    /* 0x04 */ f32 l;
    /* 0x08 */ f32 r;
    /* 0x0C */ f32 b;
    /* 0x10 */ f32 t;
    /* 0x14 */ f32 n;
    /* 0x18 */ f32 f;
    /* 0x1C */ f32 scale;
} unk_D_86002F34_00C_040; // size = 0x20

typedef struct unk_D_86002F34_00C_060 {
    /* 0x00 */ MtxF* p_mtxf;
    /* 0x04 */ MtxF mtxf;
    /* 0x44 */ LookAt* lookat;
    /* 0x48 */ Vec3f eye;
    /* 0x54 */ Vec3f at;
    /* 0x60 */ Vec3f up;
} unk_D_86002F34_00C_060; // size >= 0x6C

typedef struct unk_D_86002F34_00C_0CC {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ Color_RGBA8_u32 color;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ u8* texture;
} unk_D_86002F34_00C_0CC; // size >= 0x20

typedef struct unk_D_86002F34_00C {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ unk_D_86002F34_00C_018 unk_18;
    /* 0x24 */ unk_D_86002F34_00C_024 unk_24;
    /* 0x40 */ unk_D_86002F34_00C_040 unk_40;
    /* 0x60 */ unk_D_86002F34_00C_060 unk_60;
    /* 0xCC */ unk_D_86002F34_00C_0CC unk_CC;
    /* 0xEC */ char unkEC[0x4];
} unk_D_86002F34_00C; // size = 0xF0

typedef struct unk_D_86002F34_alt1 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ u16 unk_1A;
    /* 0x1C */ s8 unk_1C;
    /* 0x1D */ s8 unk_1D;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ Lights7* lights;
} unk_D_86002F34_alt1; // size >= 0x28

typedef struct unk_D_86002F34_alt2 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ GraphNode* unk_18;
} unk_D_86002F34_alt2; // size >= 0x1C

typedef struct unk_D_86002F34_alt3 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s32 unk_1C;
} unk_D_86002F34_alt3; // size >= 0x20

typedef struct unk_D_86002F34_alt4 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ Color_RGBA8_u32 unk_18;
    /* 0x1C */ u16 unk_1C;
    /* 0x1E */ u16 unk_1E;
} unk_D_86002F34_alt4; // size >= 0x20

typedef struct unk_D_86002F34_alt5 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ Vec3s unk_24;
} unk_D_86002F34_alt5; // size = 0x2C

typedef struct unk_D_86002F34_alt6 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ Vec3s unk_18;
    /* 0x1E */ Vec3s unk_1E;
    /* 0x24 */ Vec3f unk_24;
    /* 0x30 */ u8 unk_30;
    /* 0x31 */ u8 unk_31;
    /* 0x32 */ s16 unk_32;
} unk_D_86002F34_alt6; // size = 0x34

typedef struct unk_D_86002F34_alt7 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ Gfx* unk_18;
    /* 0x1C */ s16 unk_1C;
} unk_D_86002F34_alt7; // size = 0x20

typedef struct unk_D_86002F34_alt8 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ Gfx* unk_18;
    /* 0x1C */ MtxF unk_1C;
} unk_D_86002F34_alt8; // size = 0x5C

typedef struct unk_D_86002F34_alt9 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ Gfx* unk_18;
    /* 0x1C */ Vec3f unk_1C;
    /* 0x28 */ f32 unk_28;
} unk_D_86002F34_alt9; // size = 0x2C

typedef struct unk_D_86002F34_alt10 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ Gfx* unk_18;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ u8 unk_22;
    /* 0x24 */ Color_RGBA8_u32 unk_24;
} unk_D_86002F34_alt10; // size >= 0x28

typedef struct unk_D_86002F34_alt11_018 {
    /* 0x00 */ u8 fmt;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ char unk04[0x4];
    /* 0x08 */ u8* texture;
} unk_D_86002F34_alt11_018; // size >= 0xC

typedef struct unk_D_86002F34_alt11 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ unk_D_86002F34_alt11_018* unk_18;
    /* 0x1C */ unk_D_86002F34_alt11_018* unk_1C;
} unk_D_86002F34_alt11; // size >= 0x20

typedef struct unk_D_86002F34_alt12 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
} unk_D_86002F34_alt12; // size = 0x20

typedef struct unk_D_86002F34_alt13 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
} unk_D_86002F34_alt13; // size = 0x1C

typedef struct unk_D_86002F34_alt14 {
    /* 0x00 */ GraphNode unk_00;
} unk_D_86002F34_alt14; // size = 0x18

typedef struct unk_D_86002F34_alt15 {
    /* 0x00 */ GraphNode unk_00;
} unk_D_86002F34_alt15; // size = 0x18

typedef struct unk_D_86002F34_alt16 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ u32 unk_18;
} unk_D_86002F34_alt16; // size = 0x1C

typedef struct unk_D_86002F34_alt17 {
    /* 0x00 */ GraphNode unk_00;
} unk_D_86002F34_alt17; // size = 0x18

typedef struct unk_D_86002F34_alt18 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ u8 r;
    /* 0x19 */ u8 g;
    /* 0x1A */ u8 b;
    /* 0x1B */ u8 a;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
} unk_D_86002F34_alt18; // size = 0x20

typedef struct unk_D_86002F34_alt19 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ u8 r;
    /* 0x19 */ u8 g;
    /* 0x1A */ u8 b;
} unk_D_86002F34_alt19; // size = 0x1C

typedef struct unk_D_86002F34_alt20 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
} unk_D_86002F34_alt20; // size = 0x1C

typedef struct unk_D_86002F34_alt21 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
} unk_D_86002F34_alt21; // size = 0x1C

typedef struct unk_D_86002F34_alt22 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ Vec3f unk_18;
} unk_D_86002F34_alt22; // size = 0x24

typedef struct unk_D_86002F34_alt23 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
} unk_D_86002F34_alt23; // size = 0x1C

typedef struct unk_D_86002F34_alt24 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ Color_RGBA8_u32 unk_28;
} unk_D_86002F34_alt24; // size = 0x2C

typedef void* (*func_unk_D_800ABE10)(s32, s32);

typedef struct unk_D_86002F34_018 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8* unk_08;
} unk_D_86002F34_018; // size = 0xC

typedef struct unk_D_86002F34_01C {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s16* unk_04;
    /* 0x08 */ char unk08[0x4];
} unk_D_86002F34_01C; // size = 0xC

typedef struct unk_D_86002F34 {
    /* 0x00 */ GraphNode unk_00;
    /* 0x18 */ unk_D_86002F34_018* unk_18;
    /* 0x1C */ unk_D_86002F34_01C* unk_1C;
    /* 0x20 */ Vtx* unk_20;
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ func_unk_D_800ABE10 unk_28;
} unk_D_86002F34; // size = 0x2C

// Are unk_D_86002F30 and unk_D_800AC840 the same?
typedef struct unk_D_86002F30 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ unk_D_86002F58_004_000_004* unk_08;
} unk_D_86002F30; // size = 0x18 ??

typedef struct UnkInputStruct8000D738 {
    /* 0x00 */ s16 unk_00;
    /* 0x00 */ s32 unk_04;
} UnkInputStruct8000D738; // size = 0x8

typedef struct UnkStruct800AA660 {
    /* 0x0000 */ OSThread thread;
    /* 0x01B0 */ char unk01B0[0x28];
    /* 0x01D8 */ struct UnkStruct800AA660* unk_01D8;
    /* 0x01DC */ char unk01DC[0x2004];
    /* 0x21E0 */ OSMesg mesg;
    /* 0x21E4 */ OSMesgQueue queue;
    /* 0x21FC */ s32 unk_21FC;
    /* 0x2200 */ s32 unk_2200;
    /* 0x2204 */ UnkInputStruct8000D738 unk_2204;
} UnkStruct800AA660; // size >= 0x220C

typedef struct unk_D_864027C0 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
} unk_D_864027C0; // size = 0x20

typedef struct arg1_func_81407874_014_000_010 {
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
} arg1_func_81407874_014_000_010; // size >= 0x10

#endif
