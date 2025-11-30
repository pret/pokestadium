#include "fragment31.h"
#include "src/6A40.h"
#include "src/12D80.h"

void func_810004E0(Gfx* gfx, DisplayListAddresses* addresses) {
    gSPDisplayList(gfx++, addresses->segments[0]);
    gSPDisplayList(gfx++, addresses->segments[1]);
    gSPEndDisplayList(gfx++);
}

void func_81000518(s32 arg0, DisplayListState* state) {
    Gfx* gfx;
    DisplayListAddresses* addresses;

    if (arg0 == 2) {
        addresses = state->addresses;
        gfx = func_80005F5C(0x18);
        state->gfx = gfx;
        func_810004E0(gfx, addresses);
    }
}

void func_81000560(Gfx* gfx, s32* address) {
    if (D_8006F09C->unk_01C == 0) {
        gSPDisplayList(gfx++, *address);
    }
    gSPEndDisplayList(gfx++);
}

void func_8100059C(s32 arg0, DisplayListState* state) {
    Gfx* gfx;
    DisplayListAddresses* addresses;

    if (arg0 == 2) {
        addresses = state->addresses;
        gfx = func_80005F5C(0x50);
        state->gfx = gfx;
        func_81000560(gfx, addresses);
    }
}
