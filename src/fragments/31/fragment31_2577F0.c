#include "fragment31.h"
#include "32D10.h"
#include "12D80.h"

void func_81002530(Gfx*, DisplayListAddresses*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2577F0/func_81002530.s")

void func_810027E0(s32 arg0, DisplayListState* state) {
    Gfx* gfx;
    DisplayListAddresses* addresses;

    if (arg0 == 2) {
        addresses = state->addresses;
        gfx = func_80005F5C(0xF0);
        state->gfx = gfx;
        func_81002530(gfx, addresses);
    }
}
