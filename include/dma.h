#ifndef _DMA_H_
#define _DMA_H_

struct UnkStruct80000E80 {
    char unk0;
    char filler4[0x18];
    s32 unk1C;
    void *unk20;
    s32 unk24;
    s32 unk28;
};

s32 func_80000E80(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
s32 func_80000F0C(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_80000F80(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
s32 func_8000100C(s32 arg0, void *arg1, s16 arg2, s32 arg3, s32 arg4);
s32 func_80001098(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
s32 func_80001124(s32 arg0, s32 arg1);
s32 func_80001184(s32 arg0, s32 arg1, s32 arg2);
s32 func_800011E4(s32 arg0, s32 arg1);
s32 func_8000123C(s32 arg0, s32 arg1);
s32 func_80001298(void *arg0, s32 arg1, s32 arg2);
s16 func_800012F8(void);
s32 func_80001304(void *arg0, s32 arg1, s32 arg2);

#endif // _DMA_H_
