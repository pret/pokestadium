#include "fragment31.h"
#include "src/6A40.h"
#include "src/fragments/10/fragment10.h"

void func_81003D70(s32 arg0, GraphicState* state) {
    Gfx* gfx;

    if (arg0 == 2) {
        gfx = (Gfx*)func_80005F5C(0x10);
        state->gfx = gfx;
        if (D_86402848 == 0) {
            {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xFC119604;    _gfx->words.w1 = 0xFF13FFFF;    }
        } else {
            {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xFCFFFFFF;    _gfx->words.w1 = 0xFFFDF638;    }
        }
        gSPEndDisplayList(gfx++);
    }
}
