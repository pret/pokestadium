#ifndef _38BB0_H_
#define _38BB0_H_

#include "global.h"
#include "src/libnaudio/n_libaudio_sc.h"
#include "src/libnaudio/n_libaudio_sn_sc.h"
#include "src/libnaudio/n_synthInternals.h"

typedef struct sp38_func_800373D8 {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ u32 unk_08;
    /* 0x0C */ void* unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ u32 unk_14;
    /* 0x18 */ u32 unk_18;
    /* 0x1C */ u32 unk_1C;
    /* 0x20 */ u32 unk_20;
    /* 0x24 */ u32 unk_24;
    /* 0x28 */ u32 unk_28;
    /* 0x2C */ u32 unk_2C;
} sp38_func_800373D8; // size >= 0x30

typedef struct unk_D_800FC7D0_08C_010 {
    /* 0x00 */ char unk00[0x7];
} unk_D_800FC7D0_08C_010; // size = 0x7

typedef struct unk_D_800FC7D0_08C_008 {
    /* 0x00 */ u8 unk_00[4];
} unk_D_800FC7D0_08C_008; // size = 0x4

typedef struct unk_D_800FC7D0_08C {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u32* unk_04;
    /* 0x08 */ unk_D_800FC7D0_08C_008** unk_08;
    /* 0x0C */ u32* unk_0C;
    /* 0x10 */ unk_D_800FC7D0_08C_010* unk_10;
    /* 0x14 */ s32* unk_14;
    /* 0x18 */ char unk18[0x10];
    /* 0x28 */ f32* unk_28;
    /* 0x2C */ u32* unk_2C;
} unk_D_800FC7D0_08C; // size >= 0x18

typedef struct unk_D_800FC7D0_140 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ unk_D_800FC7D0_08C_008** unk_08;
    /* 0x0C */ u32* unk_0C;
} unk_D_800FC7D0_140; // size >= 0x10

typedef struct unk_D_800FC7D0_148 {
    /* 0x00 */ ALLink node;
    /* 0x08 */ N_ALVoice voice;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ u8 unk_2A;
} unk_D_800FC7D0_148; // size = 0x2C

typedef struct unk_D_800FC7D0 {
    /* 0x000 */ struct unk_D_800FC7D0* unk_000;
    /* 0x004 */ char unk004[0x4];
    /* 0x008 */ u64 unk_008;
    /* 0x010 */ u64 unk_010;
    /* 0x018 */ u64 unk_018;
    /* 0x020 */ u64 unk_020;
    /* 0x028 */ u64 unk_028;
    /* 0x030 */ u64 unk_030;
    /* 0x038 */ u8* unk_038;
    /* 0x03C */ s32 unk_03C;
    /* 0x040 */ s32 unk_040;
    /* 0x044 */ s32 unk_044;
    /* 0x048 */ f32 unk_048;
    /* 0x04C */ f32 unk_04C;
    /* 0x050 */ f32 unk_050;
    /* 0x054 */ f32 unk_054;
    /* 0x058 */ f32 unk_058;
    /* 0x05C */ u8* unk_05C;
    /* 0x060 */ u8* unk_060;
    /* 0x064 */ s32 unk_064;
    /* 0x067 */ s32 unk_068;
    /* 0x06C */ f32 unk_06C;
    /* 0x070 */ f32 unk_070;
    /* 0x074 */ f32 unk_074;
    /* 0x078 */ f32 unk_078;
    /* 0x07C */ s32 unk_07C;
    /* 0x080 */ f32 unk_080;
    /* 0x084 */ f32 unk_084;
    /* 0x088 */ f32 unk_088;
    /* 0x08C */ unk_D_800FC7D0_08C* unk_08C;
    /* 0x090 */ unk_D_800FC7D0_08C* unk_090;
    /* 0x094 */ u8* unk_094;
    /* 0x098 */ u8* unk_098;
    /* 0x09C */ u8* unk_09C;
    /* 0x0A0 */ u8* unk_0A0;
    /* 0x0A4 */ f32 unk_0A4;
    /* 0x0A8 */ u32 unk_0A8;
    /* 0x0AC */ s16 unk_0AC;
    /* 0x0AE */ u16 unk_0AE;
    /* 0x0B0 */ u16 unk_0B0;
    /* 0x0B2 */ s16 unk_0B2;
    /* 0x0B4 */ u16 unk_0B4;
    /* 0x0B6 */ u16 unk_0B6;
    /* 0x0B8 */ u16 unk_0B8;
    /* 0x0BA */ u16 unk_0BA;
    /* 0x0BC */ u16 unk_0BC;
    /* 0x0BE */ u16 unk_0BE;
    /* 0x0C0 */ u16 unk_0C0;
    /* 0x0C2 */ u16 unk_0C2;
    /* 0x0C4 */ s16 unk_0C4;
    /* 0x0C6 */ u16 unk_0C6;
    /* 0x0C8 */ u16 unk_0C8;
    /* 0x0CA */ u8 unk_0CA;
    /* 0x0CB */ u8 unk_0CB;
    /* 0x0CC */ u8 unk_0CC;
    /* 0x0CD */ s8 unk_0CD;
    /* 0x0CE */ u8 unk_0CE;
    /* 0x0CF */ u8 unk_0CF;
    /* 0x0D0 */ u8 unk_0D0;
    /* 0x0D1 */ u8 unk_0D1;
    /* 0x0D2 */ u8 unk_0D2;
    /* 0x0D3 */ u8 unk_0D3;
    /* 0x0D4 */ u8 unk_0D4;
    /* 0x0D5 */ u8 unk_0D5;
    /* 0x0D6 */ u8 unk_0D6;
    /* 0x0D7 */ u8 unk_0D7;
    /* 0x0D8 */ u8 unk_0D8;
    /* 0x0D9 */ u8 unk_0D9;
    /* 0x0DA */ u8 unk_0DA;
    /* 0x0DB */ u8 unk_0DB;
    /* 0x0DC */ u32 unk_0DC;
    /* 0x0E0 */ u8 unk_0E0;
    /* 0x0E1 */ u8 unk_0E1;
    /* 0x0E2 */ u8 unk_0E2;
    /* 0x0E3 */ u8 unk_0E3;
    /* 0x0E4 */ u8 unk_0E4;
    /* 0x0E5 */ u8 unk_0E5;
    /* 0x0E6 */ u8 unk_0E6;
    /* 0x0E7 */ u8 unk_0E7;
    /* 0x0E8 */ s8 unk_0E8;
    /* 0x0E9 */ u8 unk_0E9;
    /* 0x0EA */ u8 unk_0EA;
    /* 0x0EB */ u8 unk_0EB;
    /* 0x0EC */ u8 unk_0EC;
    /* 0x0ED */ u8 unk_0ED;
    /* 0x0EE */ u8 unk_0EE;
    /* 0x0EF */ s8 unk_0EF;
    /* 0x0F0 */ u8 unk_0F0;
    /* 0x0F1 */ u8 unk_0F1;
    /* 0x0F2 */ u8 unk_0F2;
    /* 0x0F4 */ u8* unk_0F4[4];
    /* 0x104 */ u8* unk_104[4];
    /* 0x114 */ u8* unk_114[4];
    /* 0x124 */ u16 unk_124[4];
    /* 0x12C */ u16 unk_12C[4];
    /* 0x134 */ u8 unk_134[4];
    /* 0x138 */ u8 unk_138[4];
    /* 0x13C */ u8 unk_13C[4];
    /* 0x140 */ unk_D_800FC7D0_140* unk_140;
    /* 0x144 */ char unk144[0x4];
    /* 0x148 */ unk_D_800FC7D0_148* unk_148;
    /* 0x14C */ char unk14C[0x4];
} unk_D_800FC7D0; // size = 0x150

typedef struct unk_func_800397BC {
    /* 0x00 */ u32 num_entries;
    /* 0x04 */ u32 flags;
    /* 0x08 */ u32* unk_offset;
    /* 0x0C */ u32* entries_offset;
} unk_func_800397BC; // size = 0x10

extern ALHeap* D_800FC810;
extern u32 D_800FC814;
extern s32 D_800FC818;
extern s32 D_800FC81C;

u8* func_80037FB0(unk_D_800FC7D0* arg0, UNUSED u8* arg1);
u8* func_80037FD0(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038008(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_8003802C(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038038(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800381B4(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038268(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_8003827C(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800382AC(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038304(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038360(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038374(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800383B8(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800383C8(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800383D8(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800383E8(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_8003844C(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800384AC(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800384BC(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800384C8(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800384D8(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800384E4(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800385D0(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038688(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800386A8(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800386B4(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800386C4(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800386D0(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800386E4(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038704(UNUSED unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038710(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038738(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038744(UNUSED unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038750(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800387B4(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800387C4(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038814(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038864(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800388B4(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800388C4(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_800389C0(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038A10(unk_D_800FC7D0* arg0, u8* arg1);
u8* func_80038A34(unk_D_800FC7D0* arg0, u8* arg1);
void func_80038B30(u8* arg0, u32 arg1);
void func_80038B54(u8* arg0, u32 arg1);
s32 func_80038B68(sp38_func_800373D8* arg0);
void func_80038E98(s32 arg0, u32 arg1);
s32 func_80038F30(SoundBank* arg0, s32 arg1);
s32 func_80039024(SoundBank* arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5);
void func_8003916C(s32 arg0, u32 arg1);
s32 func_80039204(s32 arg0);
void func_800392A8(s32 arg0, u32 arg1);
s32 func_80039354(s32 arg0);
void func_800393DC(s32 arg0, u32 arg1);
void func_80039488(s32 arg0, u16 arg1);
void func_80039534(s32 arg0, f32 arg1);
void func_800395FC(s32 arg0, s32 arg1);
void func_800396D0(u32 arg0, s32 arg1);
void func_8003979C(s32 arg0, s32 arg1);
void func_800397BC(unk_func_800397BC* arg0);
void func_8003986C(s32 arg0);
void func_800398F0(s32 arg0);
void func_80039940(void);
s32 func_80039A7C(SoundBank* arg0, s32 arg1, s32 arg2);
s32 func_80039B88(s32 arg0, u8 arg1, u8 arg2, u32 arg3);
u32 func_80039C84(u8* arg0);
u16 func_80039CB4(u8* arg0);
void func_80039CD0(void);
u8* func_80039D58(u8* arg0);
u8* func_80039F28(u8* arg0);
u8* func_8003A10C(u8* arg0);
u8* func_8003A234(u8* arg0);
u8* func_8003A2F0(u8* arg0);
u8* func_8003A39C(u8* arg0);
u8* func_8003A438(u8* arg0);
u8* func_8003A4D8(u8* arg0);
u8* func_8003A564(u8* arg0);
u8* func_8003A614(u8* arg0);
u8* func_8003A6D4(u8* arg0);
u8* func_8003A744(u8* arg0);
s32 func_8003A78C(void* arg0);
void func_8003AD58(unk_D_800FC7D0* arg0);
s32 func_8003B00C(unk_D_800FC7D0* arg0);
f32 func_8003B0DC(unk_D_800FC7D0* arg0, f32 arg1);
void func_8003B214(unk_D_800FC7D0* arg0);
void func_8003B2B4(unk_D_800FC7D0* arg0);
void func_8003B76C(unk_D_800FC7D0* arg0);
void func_8003B788(unk_D_800FC7D0* arg0);
f32 func_8003B854(unk_D_800FC7D0* arg0);
f32 func_8003B8A4(unk_D_800FC7D0* arg0);
void func_8003B94C(unk_D_800FC7D0* arg0);
void func_8003BA44(unk_D_800FC7D0* arg0);
f32 func_8003BBA4(f32 arg0);
void func_8003BD2C(u8* arg0, s32 arg1);
s32 func_8003BEF4(s32 arg0);
void func_8003BFF4(unk_D_800FC7D0* arg0);
s32 func_8003C180(unk_D_800FC7D0_08C* arg0, s32 arg1);
void func_8003C1D0(u8* arg0, u8 arg1, u32 arg2);
void func_8003C204(u8* arg0, u32 arg1, u32 arg2);
s32 func_8003C2A4(unk_D_800FC7D0* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_8003C2F8(unk_D_800FC7D0_148* arg0);
unk_D_800FC7D0_148* func_8003C35C(void);
void func_8003C3A0(unk_D_800FC7D0_148* arg0);
void func_8003C408(void);

#endif // _38BB0_H_
