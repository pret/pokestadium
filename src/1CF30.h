#ifndef _1CF30_H_
#define _1CF30_H_

#include "global.h"

typedef struct unk_func_8001E680 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ u8 unk_0D;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ u8 unk_0F;
} unk_func_8001E680; // size = 0x10

void func_8001C4E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_8001C560(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6);
void func_8001C604(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void func_8001C6AC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u32 arg4, s16 arg5, s32 arg6);
void func_8001C8C4(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u32 arg4, s16 arg5, s32 arg6);
void func_8001CADC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u32 arg4, s16 arg5, s32 arg6);
void func_8001CCF8(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u32 arg4, s16 arg5, s32 arg6);
void func_8001CF10(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u32 arg4, s16 arg5, s32 arg6);
void func_8001D12C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u32 arg4, s16 arg5, s32 arg6);
void func_8001D348(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u32 arg4, s16 arg5, s32 arg6);
void func_8001D560(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u32 arg4, u32 arg5, s16 arg6, s32 arg7);
void func_8001D924(u32 arg0);
void func_8001DBDC(u32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_8001E000(s16 arg0, s16 arg1, s16 arg2, f32 arg3, Vtx* arg4, u32 arg5);
unk_func_8001E680* func_8001E490(void);
void func_8001E680(unk_func_8001E680* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9);
void func_8001E6E8(Vp* arg0, s16 arg1, s16 arg2);
u8 func_8001E730(u16 arg0);
u8 func_8001E78C(unk_D_800AC870_sub* arg0, u16 arg1);
void func_8001E7C0(UNUSED s32 arg0, UNUSED s32 arg1);
void func_8001E7D4(UNUSED s32 arg0, s32 arg1);
s32 func_8001E810(s32 arg0);
void func_8001E884(s32 arg0, s32 arg1, s32 arg2);
unk_D_800AC870* func_8001E94C(s32 arg0, s32 arg1);
void func_8001E9CC(void);
void func_8001E9F0(s32 arg0);
void func_8001EAD0(s32 arg0);
void func_8001EBE0(s32 arg0, s32 arg1);
s32 func_8001EC40(s32 arg0, unk_D_800AC870_sub* arg1);
s16 func_8001ECB4(s16 arg0, s16 arg1, s16 arg2);
char* func_8001F1C4(char* buffer, const char* data, u32 size);
void func_8001F1E8(s32 x, s32 y, const char* fmt, ...);
void func_8001F2E4(s32 arg0, s32 arg1, s32 arg2);
void func_8001F324(s32 r, s32 g, s32 b, s32 a);
void func_8001F36C(s32 r, s32 g, s32 b, s32 a);
void func_8001F3B4(s32 arg0);
void func_8001F3C4(void);
void func_8001F3DC(void);
void func_8001F3F4(void);
void func_8001F444(void);
void func_8001F470(void);
void func_8001F4C4(void);
void func_8001F504(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
s32 func_8001F5B0(s32 x, s32 y, const char* fmt, ...);
void func_8001F6E8(s32 arg0, s32 arg1);


#endif // _1CF30_H_
