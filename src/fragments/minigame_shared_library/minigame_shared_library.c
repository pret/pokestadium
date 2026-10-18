#include "minigame_shared_library.h"
#include "src/input.h"
#include "src/controller.h"

u16 D_87B000C0 = 0;
u16 D_87B000C4 = 0x0069;
u8 D_87B000C8 = 0;
u8 D_87B000CC = 0;
u8 D_87B000D0 = 0;
u8 D_87B000D4 = 0;

FontContext* D_87B000E0;
unk_D_86002F30* D_87B000E4;
unk_D_86002F34* D_87B000E8;
CameraNode* D_87B000EC;
s16 D_87B000F0;
s16 D_87B000F2;
s16 D_87B000F4;

void MiniGame_ReadInputs(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

u32 MiniGame_RandomRange(u32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return ((guRandom() + osGetCount()) / 10) % arg0;
}
