#ifndef _3D140_H_
#define _3D140_H_

#include "global.h"

extern s32 D_80077DC4;
extern f32 D_80077DC8;
extern u8 D_80077DCC;
extern f32 D_80077DD0;
extern f32 D_80077DD4;
extern f32 D_80077DD8;
extern f32 D_80077DDC;
extern f32 D_80077DE0;
extern u8 D_80077DE4;

typedef struct amConfig {
    /* 0x00 */ u32 outputRate;
    /* 0x04 */ u32 framesPerField;
    /* 0x08 */ u32 maxACMDSize;
} amConfig; // size = 0xC


void amCreateAudioMgr(ALSynConfig*, amConfig*, u32, s32, s32);
OSTask* func_8003CADC(OSTask*);
void __clearAudioDMA(void);
void func_8003D32C(void);
s32 func_8003D494(void);
s32 func_8003D4A0(s32);
void func_8003D68C(s32);
void func_8003D918(u32 arg0, u32 arg1);
void func_8003DB84(s32 arg0);
void func_800416BC(void);
void func_80041A98(void);
void func_80041C70(u32 arg0);
void func_80041D50(u8* arg0, u8* arg1);
u16 func_80041D70(u16 arg0);
void func_80041DF4(u16 arg0);
void func_80041E40(u16 arg0);
u32 func_80041EF4(u16* arg0);
void func_800420C0(u16* arg0);

#endif // _3D140_H_
