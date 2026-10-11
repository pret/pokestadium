#include "particle_data_library.h"
#include "src/gfx_buffer.h"
#include "src/geo_render.h"
#include "src/battle_hud.h"

void DisplayList_BuildRotationMatrixSegmentAlt(Gfx* gfx) {
    Mtx* mtx;
    u8 angle;

    angle = D_8006F09C->effectSlot & 3;
    mtx = Gfx_AllocDisplayList(0x40);
    guRotate(mtx, D_800AF780[angle], 1.0f, 0.0f, 0.0f);
    gSPMatrix(gfx++, mtx, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPEndDisplayList(gfx++);
}

void DisplayList_InitRotationMatrixSegmentAlt(s32 arg0, DisplayListState* state) {
    Gfx* gfx;

    if (arg0 == 2) {
        gfx = Gfx_AllocDisplayList(0x50);
        state->gfx = gfx;
        DisplayList_BuildRotationMatrixSegmentAlt(gfx);
    }
}
