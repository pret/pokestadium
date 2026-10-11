#ifndef _1AB70_H_
#define _1AB70_H_

#include "global.h"
#include "gfx_rect.h"
#include "matrix.h"
#include "game_state.h"

typedef struct unk_func_8001B1FC {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ ModelLoadContext* unk_1C;
    /* 0x20 */ GraphNode* unk_20;
    /* 0x24 */ DisplayObject* unk_24;
    /* 0x28 */ unk_D_80068BB0* unk_28;
    /* 0x2C */ unk_D_80068BB0* unk_2C;
} unk_func_8001B1FC; // size = 0x30

typedef union unk_func_8001A024_008_014 {
    struct {
        /* 0x00 */ s16 unk_00;
        /* 0x02 */ s16 unk_02;
    };
    u8* ptr;
    u32 raw;
} unk_func_8001A024_008_014; // size = 0x4

typedef struct unk_func_8001A024_008 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ unk_D_80068BB0* unk_0C;
    /* 0x10 */ arg1_func_80010CA8 unk_10;
    /* 0x14 */ unk_func_8001A024_008_014 unk_14;
} unk_func_8001A024_008; // size = 0x18

typedef struct unk_func_8001A024 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ ModelLoadContext* unk_04;
    /* 0x08 */ unk_func_8001A024_008* unk_08;
    /* 0x0C */ GraphNode* unk_0C;
    /* 0x10 */ DisplayObject* unk_10;
    /* 0x14 */ unk_D_80068BB0* unk_14;
    /* 0x18 */ unk_D_8006FF00* unk_18;
} unk_func_8001A024; // size = 0x1C

typedef struct unk_D_84B25A28 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x04 */ DisplayObject* unk_04;
    /* 0x08 */ unk_D_86002F34_00C* unk_08;
    /* 0x0C */ GraphNode* unk_0C;
    /* 0x10 */ GraphNode* unk_10;
    /* 0x14 */ GraphNode* unk_14;
    /* 0x18 */ GraphNode* unk_18;
    /* 0x1C */ GraphNode* unk_1C;
    /* 0x20 */ unk_func_8001A024* unk_20;
    /* 0x24 */ unk_D_80068BB0* unk_24;
    /* 0x28 */ unk_D_80068BB0* unk_28;
    /* 0x2C */ char unk2C[0x4];
} unk_D_84B25A28; // size = 0x30

unk_func_8001A024* PokeIcon_CreateRenderList(ModelLoadContext*, s16, s16, s16);
void PokeIcon_AttachDepthBuffer(unk_func_8001A024*, ModelLoadContext*, unk_D_80068BB0*);
void PokeIcon_SetNameTable(unk_func_8001A024*, unk_D_8006FF00*);
void PokeIcon_ResetRenderList(unk_func_8001A024*);
void func_8001A324(unk_func_8001A024*, s32, s32, u16);
void func_8001A46C(unk_func_8001A024*, s32, BattleMon*, u16);
s32 PokeIcon_ProcessNextSlot(unk_func_8001A024*, s32);
s32 PokeIcon_ProcessAllSlots(unk_func_8001A024*, s32);
s32 PokeIcon_RenderNextSlotBlocking(unk_func_8001A024*, s32);
u8* PokeIcon_GetImage(unk_func_8001A024*, s32);
s32 PokeIcon_AreSlotsIdle(unk_func_8001A024*);
void PokeIcon_OpenModelArchive(void);
void PokeIcon_LoadModelTextureForMon(u16*, s32, BattleMon*);
unk_func_8001B1FC* PokeIcon_CreateModelPreview(ModelLoadContext*, s16, s16, s16, s16, s16, s16, u8*);
void PokeIcon_SetPreviewMon(unk_func_8001B1FC* arg0, BattleMon* arg1, u16 arg2);
void PokeIcon_SetPreviewSpecies(unk_func_8001B1FC*, s32, u16);
u8* PokeIcon_RenderPreview(unk_func_8001B1FC*);

#endif // _1AB70_H_
