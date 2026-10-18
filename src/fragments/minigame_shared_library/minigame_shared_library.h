#ifndef _FRAGMENT5_H_
#define _FRAGMENT5_H_

#include "global.h"

extern u16 D_87B000C0;
extern u16 D_87B000C4;
extern u8 D_87B000C8;
extern u8 D_87B000CC;
extern u8 D_87B000D0;
extern u8 D_87B000D4;

extern FontContext* D_87B000E0;
extern unk_D_86002F30* D_87B000E4;
extern unk_D_86002F34* D_87B000E8;
extern CameraNode* D_87B000EC;
extern s16 D_87B000F0;
extern s16 D_87B000F2;
extern s16 D_87B000F4;

void MiniGame_ReadInputs(void);
u32 MiniGame_RandomRange(u32);


#endif // _FRAGMENT5_H_
