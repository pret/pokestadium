#include "fragment31.h"
#include "12D80.h"

void func_81002490(Gfx* gfx, DisplayListAddresses* addresses) {
    if (D_8006F09C->unk_01C == 0) {
        gSPDisplayList(gfx++, addresses->segments[0]);
    }
    gSPDisplayList(gfx++, addresses->segments[1]);
    gSPEndDisplayList(gfx++);
}

void func_810024E4(s32 arg0, DisplayListState* state) {
    Gfx* gfx;
    DisplayListAddresses* addresses;

    if (arg0 == 2) {
        addresses = state->addresses;
        gfx = func_80005F5C(0x50);
        state->gfx = gfx;
        func_81002490(gfx, addresses);
    }
}
