#include "particle_data_library.h"
#include "src/gfx_buffer.h"
#include "src/geo_render.h"

void DisplayList_BuildTwoSegmentChain(Gfx* gfx, DisplayListAddresses* addresses) {
    gSPDisplayList(gfx++, addresses->segments[0]);
    gSPDisplayList(gfx++, addresses->segments[1]);
    gSPEndDisplayList(gfx++);
}

void DisplayList_InitTwoSegmentChain(s32 arg0, DisplayListState* state) {
    Gfx* gfx;
    DisplayListAddresses* addresses;

    if (arg0 == 2) {
        addresses = state->addresses;
        gfx = Gfx_AllocDisplayList(0x18);
        state->gfx = gfx;
        DisplayList_BuildTwoSegmentChain(gfx, addresses);
    }
}

void DisplayList_BuildConditionalSegment(Gfx* gfx, s32* address) {
    if (D_8006F09C->textureMode == 0) {
        gSPDisplayList(gfx++, *address);
    }
    gSPEndDisplayList(gfx++);
}

void DisplayList_InitConditionalSegment(s32 arg0, DisplayListState* state) {
    Gfx* gfx;
    DisplayListAddresses* addresses;

    if (arg0 == 2) {
        addresses = state->addresses;
        gfx = Gfx_AllocDisplayList(0x50);
        state->gfx = gfx;
        DisplayList_BuildConditionalSegment(gfx, addresses);
    }
}
