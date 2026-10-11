#include "particle_data_library.h"
#include "geo_render.h"

void DisplayList_BuildOptionalPlusSegment(Gfx* gfx, DisplayListAddresses* addresses) {
    if (D_8006F09C->textureMode == 0) {
        gSPDisplayList(gfx++, addresses->segments[0]);
    }
    gSPDisplayList(gfx++, addresses->segments[1]);
    gSPEndDisplayList(gfx++);
}

void DisplayList_InitOptionalPlusSegment(s32 arg0, DisplayListState* state) {
    Gfx* gfx;
    DisplayListAddresses* addresses;

    if (arg0 == 2) {
        addresses = state->addresses;
        gfx = Gfx_AllocDisplayList(0x50);
        state->gfx = gfx;
        DisplayList_BuildOptionalPlusSegment(gfx, addresses);
    }
}
