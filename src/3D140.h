#ifndef _3D140_H_
#define _3D140_H_

#include "global.h"

typedef struct unk_D_800FCB18 {
    /* 0x00 */ char pad00[0xC];
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ char pad0E[0x7];
    /* 0x15 */ u8 unk_15;
    /* 0x16 */ char pad16[0x6];
    /* 0x1C */ u8 unk_1C;
    /* 0x1D */ u8 unk_1D;
    /* 0x1E */ char pad1E[0x8];
    /* 0x26 */ u8 unk_26;
    /* 0x28 */ u16 unk_28;
} unk_D_800FCB18; // size >= 0x2C

typedef struct amConfig {
    /* 0x00 */ u32 outputRate;
    /* 0x04 */ u32 framesPerField;
    /* 0x08 */ u32 maxACMDSize;
} amConfig; // size = 0xC

extern s32 D_80077DC4;
extern f32 D_80077DC8;
extern u8 D_80077DCC;
extern f32 D_80077DD0;
extern f32 D_80077DD4;
extern f32 D_80077DD8;
extern f32 D_80077DDC;
extern f32 D_80077DE0;
extern u8 D_80077DE4;

extern unk_D_800FCB18* D_800FCB18[2];

void amCreateAudioMgr(ALSynConfig*, amConfig*, u32, s32, s32);
OSTask* func_8003CADC(OSTask*);
void __clearAudioDMA(void);
void func_8003D2B8(s32);
void func_8003D32C(void);
s32 func_8003D494(void);
s32 func_8003D4A0(s32);
void func_8003D68C(s32);
void func_8003D918(u32 arg0, u32 arg1);
void func_8003DB84(s32 arg0);
void func_8003F1AC(s32);
void func_8003F4C0(s32);
void func_8003F624(u32 arg0);
void func_8003F660(s32);
void func_800414B8(s32);
void func_8004153C(void);
void func_80041688(void);
void func_800416BC(void);
void func_80041A98(void);
void func_80041C70(u32 arg0);
void func_80041D50(u8* arg0, u8* arg1);
u16 func_80041D70(u16 arg0);
void func_80041DF4(u16 arg0);
void func_80041E40(u16 arg0);
u32 func_80041EF4(u16* arg0);
void func_800420C0(u16* arg0);
void func_80048014(void);

#endif // _3D140_H_
