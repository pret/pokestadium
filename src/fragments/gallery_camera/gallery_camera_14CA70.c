#include "gallery_camera.h"
#include "src/fragments/minigame_actor_framework/minigame_actor_framework.h"
#include "src/fragments/particle_data_library/particle_data_library.h"
#include "src/fragments/particle_math/particle_math.h"
#include "src/fragments/gallery_backgrounds/gallery_backgrounds.h"
#include "src/geo_node.h"
#include "src/geo_render.h"
#include "src/model_animation.h"
#include "src/model_animation_events.h"
#include "src/geo_layout.h"
#include "src/display_object_textures.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/gb_save.h"
#include "src/save_data.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/matrix.h"
#include "src/dp_intro.h"
#include "src/math_util.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "src/util.h"

typedef struct unk_D_8690A69C {
    /* 0x000 */ ModelLoadResult* unk_000;
    /* 0x004 */ DisplayObject unk_004;
    /* 0x16C */ s32 unk_16C;
} unk_D_8690A69C; // size = 0x170

typedef struct unk_D_8690A718 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk02[0xE];
} unk_D_8690A718; // size = 0x10

typedef struct unk_D_86908CA0 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x04 */ f32 unk_04;
} unk_D_86908CA0; // size = 0x8

typedef struct unk_D_86909168 {
    /* 0x0 */ s32 unk_00;
    /* 0x4 */ s32 unk_04;
} unk_D_86909168; // size = 0x8

typedef struct unk_D_869091B8 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ char unk14[0xC];
} unk_D_869091B8; // size = 0x20

static u8 D_86908A80[] = {
    0x00, 0x01, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x11,
};

static s32 gCameraTutorialTextIds[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xB, 0xFF };

static u32 D_86908ABC[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E, 0x00000000, 0x014000F0, 0x0000000F, 0x00000000, 0x00000000, 0x05000000,
    0x0D000000, 0x05000000, 0x07000000, 0x8690A610, 0x14000000, 0x002D0019, 0xFFFFFF28, 0x08000000, 0x86900020,
    0x00000000, 0x14000000, 0x002D0019, 0x80808028, 0x08000000, 0x86900088, 0x00000000, 0x16646464, 0x0F000002,
    0x05000000, 0x1F00FFFF, 0x00000000, 0x00000000, 0x00000000, 0x00640064, 0x00640000, 0x08000000, 0x869000F4,
    0x00000000, 0x05000000, 0x07000000, 0x8690A630, 0x06000000, 0x06000000, 0x0F000003, 0x05000000, 0x1F00FFFF,
    0x00000000, 0x00000000, 0x00000000, 0x00640064, 0x00640000, 0x08000000, 0x869000F4, 0x00000000, 0x05000000,
    0x07000000, 0x8690A648, 0x06000000, 0x06000000, 0x0F000002, 0x05000000, 0x1F00FFFF, 0x00000000, 0x00000000,
    0x00000000, 0x00640064, 0x00640000, 0x08000000, 0x869000F4, 0x00000000, 0x05000000, 0x07000000, 0x8690A660,
    0x06000000, 0x06000000, 0x0F000003, 0x05000000, 0x0A000000, 0x800AC840, 0x06000000, 0x0F000002, 0x05000000,
    0x0A000000, 0x800AC858, 0x06000000, 0x09000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};

Vec3f D_86908C20 = { 0.0f, 0.0f, 0.0f };
Vec3f D_86908C2C = { 0.0f, 0.0f, 0.0f };
Vec3f D_86908C38 = { 0.0f, 0.0f, 0.0f };
Vec3f D_86908C44 = { 0.0f, 0.0f, 0.0f };

Color_RGB8 D_86908C50 = { 0, 0, 150 };
Color_RGB8 D_86908C54 = { 0, 0, 250 };

char* D_86908C58[] = {
    D_8690A520, D_8690A52C, D_8690A538, D_8690A544, D_8690A550, D_8690A55C, D_8690A568, D_8690A574,
    D_8690A584, D_8690A594, D_8690A5A0, D_8690A5AC, D_8690A5B8, D_8690A5C8, D_8690A5D8, D_8690A5E8,
};

Color_RGB8 D_86908C98 = { 0, 100, 255 };
Color_RGB8 D_86908C9C = { 100, 255, 255 };

static unk_D_86908CA0 D_86908CA0[] = {
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 5.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 4.0f },   { 0xAB, 0xAC, 1.0f },   { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, -10.0f }, { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, -4.0f },  { 0xAB, 0xAC, 10.0f },  { 0xAB, 0xAC, 5.0f },   { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 15.0f },  { 0xAB, 0xAC, 35.0f },  { 0xAB, 0xAC, -5.0f },  { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 1.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0x5A, -8.0f },  { 0xAB, 0xAC, 11.0f },  { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, -8.0f },  { 0xAB, 0xAC, 5.0f },   { 0xAB, 0xAC, 5.0f },   { 0xAB, 0xAC, -5.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, -12.0f }, { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 10.0f },  { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 10.0f },
    { 0xAB, 0xAC, 25.0f },  { 0xAB, 0xAC, 18.0f },  { 0xAB, 0xAC, -8.0f },  { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 30.0f },  { 0xAB, 0xAC, -10.0f }, { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 10.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, -10.0f }, { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 5.0f },   { 0xAB, 0xAC, -5.0f },
    { 0xAB, 0xAC, 20.0f },  { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 13.0f },  { 0xAB, 0xAC, 5.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 5.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 10.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 5.0f },   { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 5.0f },   { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, -5.0f },  { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 6, 0.0f },      { 0xAB, 6, 5.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 13.0f },  { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 10.0f },  { 0xAB, 0xAC, 30.0f },
    { 0xAB, 0xAC, 5.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 10.0f },  { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 25.0f },  { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 10.0f },  { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 10.0f },  { 0xAB, 0xAC, -5.0f },
    { 0xAB, 0xAC, 15.0f },  { 0xAB, 0xAC, 35.0f },  { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 50.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 10.0f },  { 0xAB, 0xAC, 5.0f },   { 0xAB, 0xAC, 10.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 15.0f },  { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, -5.0f },  { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 5.0f },   { 0x75, 0xAC, 0.0f },   { 0xAB, 0xAC, 5.0f },   { 0xAB, 0x10, 7.0f },
    { 0xAB, 0xAC, 10.0f },  { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 5.0f },   { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 10.0f },  { 0xAB, 0xAC, 10.0f },  { 0xAB, 0xAC, -10.0f },
    { 0xAB, 0xAC, -20.0f }, { 0xAB, 0xAC, 15.0f },  { 0xAB, 0xAC, 5.0f },   { 0xAB, 0xAC, 0.0f },
    { 0xAB, 0xAC, 30.0f },  { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, -10.0f },
    { 0xAB, 0xAC, 10.0f },  { 0xAB, 0xAC, 20.0f },  { 0xAB, 0xAC, 0.0f },   { 0xAB, 0xAC, 20.0f },
    { 0xAB, 0xAC, 35.0f },  { 0xAB, 0xAC, 20.0f },  { 0xAB, 0xAC, 15.0f },  { 0xAB, 0xAC, 10.0f },
    { 0xAB, 0xAC, 10.0f },  { 0xAB, 0xAC, 20.0f },  { 0xAB, 0xAC, -1.0f },  { 0, 0, 0.0f },
    { 0xAB, 0xAC, -8.0f },
};

static unk_D_86909168 D_86909168[] = {
    { 0x1A, 0x60 },   { 0x7F, 0x117 },  { 0x135, 0x230 }, { 0x24A, 0x361 }, { 0x387, 0x46C },
    { 0x48D, 0x543 }, { 0x564, 0x653 }, { 0x673, 0x6D0 }, { 0x76C, 0x858 }, { 0x87D, 0x1FCC },
};

static unk_D_869091B8 D_869091B8[] = {
    { 0xC4, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 4, 0x8000, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0xD, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 4, 0x8000, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x10, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 6, 0x8000, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x7F, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x28, 0x200, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 9, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x10, 0x800, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 9, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x23, 0x100, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0xB, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x13, 0x400, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0xF, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0xF, 0x200, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x7C, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0xA, 2, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x15, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x14, 1, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x15, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0xC, 2, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x15, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 8, 8, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x15, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0xA, 4, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x15, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 4, 8, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x7B, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 2.0f, 0.0f, 2.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 3.0f, 0.0f, 3.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 5.0f, 0.0f, 5.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 7.0f, 0.0f, 7.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 8.0f, 0.0f, 8.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 9.0f, 0.0f, 9.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 10.0f, 0.0f, 10.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 12.0f, 0.0f, 12.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 13.0f, 0.0f, 13.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0xE, 0, 14.0f, 0.0f, 14.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 13.0f, 0.0f, 13.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 5.0f, 0.0f, 5.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x1E, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 2.0f, 0.0f, -2.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 3.0f, 0.0f, -3.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 4.472136f, 2.0f, -4.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 2, 0, 5.385165f, 2.0f, -5.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 6.708204f, 3.0f, -6.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 6, 0, 8.062257f, 4.0f, -7.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 8.602324f, 5.0f, -7.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 9.433981f, 5.0f, -8.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 2, 0, 10.816653f, 6.0f, -9.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 11.661903f, 6.0f, -10.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 3, 0, 12.206555f, 7.0f, -10.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x12, 0, 13.038404f, 7.0f, -11.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 10.816653f, 6.0f, -9.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x14, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 2.0f, 0.0f, 2.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 4.0f, 0.0f, 4.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 5.0f, 0.0f, 5.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 6.0f, 0.0f, 6.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 7.0f, 0.0f, 7.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 9.0f, 0.0f, 9.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 10.0f, 0.0f, 10.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 2, 0, 11.0f, 0.0f, 11.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 3, 0, 12.0f, 0.0f, 12.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x12, 0, 13.0f, 0.0f, 13.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 5.0f, 0.0f, 5.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x71, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 3.0f, 0.0f, 3.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 5.0f, 0.0f, 5.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 7.0f, 0.0f, 7.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 9.0f, 0.0f, 9.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 12.0f, 0.0f, 12.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 14.0f, 0.0f, 14.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 19.0f, 0.0f, 19.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 27.0f, 0.0f, 27.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 40.0f, 0.0f, 40.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 8, 0, 64.0f, 0.0f, 63.999996f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 64.0f, 0.0f, 63.999992f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 46.0f, 0.0f, 46.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 10.0f, 0.0f, 10.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 8, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 3.0f, 0.0f, -3.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 6, 0, 5.385165f, 2.0f, -5.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 3.0f, 0.0f, -3.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 8, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 55.0f, 0.0f, 55.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 64.0f, -2.52435f, 63.950195f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 64.0f, -5.869891f, 63.730244f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 64.0f, -8.349089f, 63.453075f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 64.0f, -9.981604f, 63.216824f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 4, 0, 64.0f, -11.743815f, 62.9133f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 64.0f, -7.83112f, 63.51908f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 46.09772f, -3.0f, 46.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 14.0f, 0.0f, 14.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 6, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 2.0f, 0.0f, -2.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 6.0f, 0.0f, -6.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 9.486833f, 3.0f, -9.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 3, 0, 11.7047f, 4.0f, -11.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 13.0f, 5.0f, -12.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 4, 0, 13.928388f, 5.0f, -13.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 10.29563f, 5.0f, -9.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 3.0f, 0.0f, -3.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 7, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 34.0f, 0.0f, 34.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0xA, 0, 64.0f, 0.0f, 63.999996f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 64.0f, 0.0f, 63.999992f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 60.0f, 0.0f, 60.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0, 29.0f, 0.0f, 29.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x8D, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 4, 0x10, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x28, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 4, 0x10, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x1A, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 4, 0x10, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x22, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 4, 0x10, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0xB9, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 4, 0x20, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0xF, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 5, 0x400, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0xF, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 5, 0x400, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0xF, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 5, 0x400, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0xF, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x30, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 3, 0x20, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x73, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 4, 0x2000, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x28, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 4, 0x2000, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x28, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 4, 0x2000, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0xB0, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x10, 0x100, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 2, 0x8100, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x12, 0x100, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 3, 0x8100, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x18, 0x100, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 4, 0x8100, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 3, 0x100, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 3, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 9, 0x100, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 4, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 3, 0x8000, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 0x34, 0, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 1, 0x1000, 0.0f, 0.0f, 0.0f, 0xFF, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
};

static unk_D_8690A610 D_8690A610;
static DisplayNodeHeader D_8690A630;
static DisplayNodeHeader D_8690A648;
static DisplayNodeHeader D_8690A660;
char** gCameraHelpText;
static s32 D_8690A67C;
static s32 D_8690A680;
static s32 pad_D_8690A684;
static u32 D_8690A688;
static Color_RGBA8_u32 D_8690A68C;
static s32 pad_D_8690A690;
static s32 pad_D_8690A694;
static BinArchive* D_8690A698;
static unk_D_8690A69C* D_8690A69C;
static BattleMon D_8690A6A0;
static s32 D_8690A6F4;
static s32 D_8690A6F8;
static s32 D_8690A6FC;
static s32 D_8690A700;
static s32 D_8690A704;
f32 D_8690A708;
static s32 D_8690A70C;
unk_D_8690A710* D_8690A710;
static unk_D_8690A718 D_8690A718[190];
unk_D_8690B2F8 D_8690B2F8;
unk_D_8690B308 D_8690B308;
static s32 D_8690B340;
s32 D_8690B344;
s32 D_8690B348;
unk_D_8690B350 D_8690B350;
unk_D_8690B360 D_8690B360;
static ModeSettings D_8690B378;
s32 D_8690B380;
s32 D_8690B384;
s32 D_8690B388;
s32 D_8690B38C;
Controller D_8690B390;
static u16 D_8690B3B4;
static s32 D_8690B3B8;
static u16 D_8690B3BC;
unk_D_8690B3C0 D_8690B3C0;
s8 D_8690B3D0[255];
static s8 D_8690B4D0[0x100];
static Controller D_8690B5D0;
static s32 D_8690B5F4;
static s32 D_8690B5F8;

s32 GalleryCamera_BgAngleCallbackA(s32 arg0, GraphNode* arg1) {
    unk_D_86002F34_alt18* ptr = (unk_D_86002F34_alt18*)arg1;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        Vec3f_CalculateDistanceAngles(&D_8006F088->unk_60.at, &D_8006F088->unk_60.eye, &sp28, &sp26, &sp24);
        ptr->unk_1C = sp26 + 0x2000;
        ptr->unk_1E = sp24 - 0x2000;
    }
    return 0;
}

s32 GalleryCamera_BgAngleCallbackB(s32 arg0, GraphNode* arg1) {
    unk_D_86002F34_alt18* ptr = (unk_D_86002F34_alt18*)arg1;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        Vec3f_CalculateDistanceAngles(&D_8006F088->unk_60.at, &D_8006F088->unk_60.eye, &sp28, &sp26, &sp24);
        ptr->unk_1C = -0x2000 - sp26;
        ptr->unk_1E = sp24 + 0x6000;
    }
    return 0;
}

s32 GalleryCamera_FogColorCallback(s32 arg0, GraphNode* arg1) {
    DisplayObject* ptr = (DisplayObject*)arg1;

    if (arg0 == 2) {
        ptr->textureTint.rgba = D_8690A68C.rgba;
    }
    return 0;
}

void Gallery_SetBackgroundTint(u8 arg0, u8 arg1, u8 arg2) {
    u8 v = arg0 & arg1 & arg2;

    D_8690A68C.r = arg0;
    D_8690A68C.g = arg1;
    D_8690A68C.b = arg2;

    if (v == 0xFF) {
        if (D_8690A610.node.callbackArg == 1) {
            D_8690A610.node.flags |= 1;
        }
    } else {
        D_8690A610.node.flags &= ~1;
    }
}

void Gallery_LoadPhotoTextures(void) {
    UNUSED s32 pad[2];
    u8* temp_a1 = (u32)_70D3A0_ROM_START + (D_80075BD0[D_8690A69C->unk_16C - 1] & 0xFFFFFF);
    u8* sp20 = (u32)_70D3A0_ROM_START +
               (((D_8690A69C->unk_16C * sizeof(unk_70D3A0)) - sizeof(unk_70D3A0) + (u32)D_70110) & 0xFFFFFF);
    u8* sp1C = sp20 + sizeof(unk_70D3A0);

    if (D_8690A69C->unk_16C == 153) {
        sp20 = (u32)_70D3A0_ROM_START + ((u32)D_70290 & 0xFFFFFF);
        sp1C = sp20 + sizeof(unk_70D3A0);
    }

    Dma_WriteChunks(&D_8690A718->unk_00, temp_a1, temp_a1 + 0xBC0, 0);
    Dma_WriteChunks(&D_8690B2F8, sp20, sp1C, 0);
}

ModelLoadResult* Gallery_LoadSurfingPikachuIcon(BattleMon* arg0) {
    arg1_func_80010CA8 sp1C;
    ModelLoadContext* sp18;

    arg0->unk_00.unk_00 = 25;
    sp18 = PokeIcon_AllocFramebuffers(1);
    Model_ComputeSizeVariant(&sp1C, arg0);
    PokeIcon_RequestFrameLoad(sp18, arg0->unk_00.unk_00 = 153, sp1C);
    PokeIcon_WaitFrameLoad(sp18);

    return sp18->loadedModel;
}

void Gallery_SetupPhotoModel(void) {
    Gallery_CopyBattleMonFromPhotoMon(&D_8690A6A0, &D_83407AC8);
    D_8690A69C->unk_16C = D_83407AC8.unk_02;

    D_8690A708 = D_86908CA0[D_8690A69C->unk_16C - 1].unk_04;
    D_8690A700 = D_86908CA0[D_8690A69C->unk_16C - 1].unk_00 - 6;
    D_8690A704 = D_86908CA0[D_8690A69C->unk_16C - 1].unk_01 - 6;

    ModelRenderer_AttachDisplayObject(&D_8690A69C->unk_004);
    PokeIcon_OpenModelArchives();

    if (D_8690A69C->unk_16C == 153) {
        D_8690A69C->unk_000 = Gallery_LoadSurfingPikachuIcon(&D_8690A6A0);
    } else {
        D_8690A69C->unk_000 = Model_LoadForPokemon(&D_8690A6A0);
    }

    Model_InitDisplayObject(&D_8690A69C->unk_004, 0, D_8690A69C->unk_16C, D_8690A69C->unk_000->modelRoot->unk_00[0]);
    Gallery_LoadPhotoTextures();
    ModelAnim_SetAnimation(&D_8690A69C->unk_004, D_8690A718[D_8690A700].unk_00);

    D_8690A69C->unk_004.position.y += D_8690B2F8.unk_08;
    D_8690A69C->unk_004.effectSlot = 0;
}

void Gallery_FinalizeBackgroundLoad(void) {
    while (Display_IsFrameReady() == 0) {}

    GeoNode_CreateContainer(NULL, &D_8690A630);
    GeoNode_CreateContainer(NULL, &D_8690A648);
    GeoNode_CreateContainer(NULL, &D_8690A660);

    main_pool_pop_state('BACK');
}

void Gallery_LoadBackgroundSet(s32 arg0) {
    MemoryBlock* sp1C;
    FragmentEntry sp18;
    u32* temp_v0;
    unk_D_8690A610_018* temp_v1;

    main_pool_push_state('BACK');

    sp18 = BinArchive_GetFile(D_8690A698, D_86908A80[arg0]);
    sp1C = MainPool_AllocState(main_pool_get_available(), 0);

    temp_v0 = sp18(0, 0);
    if (temp_v0 != NULL) {
        GraphNode_AppendChild(&D_8690A630, process_geo_layout(sp1C, temp_v0));
    }

    temp_v0 = sp18(1, 0);
    if (temp_v0 != NULL) {
        GraphNode_AppendChild(&D_8690A648, process_geo_layout(sp1C, temp_v0));
    }

    temp_v0 = sp18(3, 0);
    if (temp_v0 != NULL) {
        GraphNode_AppendChild(&D_8690A660, process_geo_layout(sp1C, temp_v0));
    }

    D_8690A688 = sp18(2, 0);
    MainPool_FinalizeAllocation(sp1C);

    temp_v1 = sp18(4, 0);
    if (temp_v1 == NULL) {
        D_8690A610.node.callbackArg = 0;
        D_8690A610.node.flags &= ~1;
    } else {
        D_8690A610.unk_18.unk_00 = temp_v1->unk_00;
        D_8690A610.unk_18.unk_02 = temp_v1->unk_02;
        D_8690A610.unk_18.unk_04.rgba = temp_v1->unk_04.rgba;
        D_8690A610.node.callbackArg = 1;
    }

    Gallery_SetBackgroundTint(0xFF, 0xFF, 0xFF);
}

void Gallery_InitBackgroundScene(void) {
    MemoryBlock* sp2C;

    GeoNode_CreateFog(0, &D_8690A610, 0x3C0, 0x3E8, 0xFF, 0xFF, 0xFF, 0xFF);
    GeoNode_CreateContainer(NULL, &D_8690A630);
    GeoNode_CreateContainer(NULL, &D_8690A648);
    GeoNode_CreateContainer(NULL, &D_8690A660);
    Gallery_SetBackgroundTint(0xFF, 0xFF, 0xFF);
    sp2C = MainPool_AllocState(main_pool_get_available(), 0);
    D_87906050 = process_geo_layout(sp2C, &D_86908ABC);
    MainPool_FinalizeAllocation(sp2C);
    ModelRenderer_InitDisplayRoots();
}

void GalleryCamera_ComputeFrameCornerPos(f32* arg0, f32* arg1, s16* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s16 arg7) {
    *arg2 = MathUtil_Atan2s(arg4 - arg6, arg3 - arg5);

    *arg0 = COSS(*arg2 + arg7) * 60.0f + arg5;
    *arg1 = SINS(*arg2 + arg7) * 60.0f + arg6;
}

void GalleryCamera_InitIntroSequence(void) {
    D_8690B340 = 0;
    if (D_8690A70C == 1) {
        D_8690B344 = 0;
    } else {
        D_8690B344 = D_83402E20;
    }

    D_8690A710->unk_014 = 1;
    D_8690B380 = 0;
    D_8690B384 = 0;
    D_8690B388 = 0;
    D_8690A710->unk_00C = 0;
    D_8690A6F4 = 0;
    D_8690A6F8 = 0;
    D_8690A6FC = 0;
    D_8690B348 = 0;

    D_8690B360.unk_02 = 0;
    D_8690B360.unk_06 = 0;
    D_8690B360.unk_0A = 0;

    D_8690B308.unk_00[0] = 0xA0;
    D_8690B308.unk_00[4] = -0x14;
    D_8690B308.unk_00[1] = 0x14A;
    D_8690B308.unk_00[5] = 0x78;
    D_8690B308.unk_00[2] = 0xA0;
    D_8690B308.unk_00[6] = 0x104;
    D_8690B308.unk_00[3] = -0xA;
    D_8690B308.unk_00[7] = 0x78;

    GalleryCamera_ComputeFrameCornerPos(&D_8690B308.unk_10, &D_8690B308.unk_20, &D_8690B308.unk_30, 0.0f, 0.0f, 12.5f, 15.5f, 0);
    GalleryCamera_ComputeFrameCornerPos(&D_8690B308.unk_14, &D_8690B308.unk_24, &D_8690B308.unk_32, 320.0f, 0.0f, 307.5f, 15.5f, -0x8000);
    GalleryCamera_ComputeFrameCornerPos(&D_8690B308.unk_18, &D_8690B308.unk_28, &D_8690B308.unk_34, 320.0f, 240.0f, 308.8f, 224.5f, 0);
    GalleryCamera_ComputeFrameCornerPos(&D_8690B308.unk_1C, &D_8690B308.unk_2C, &D_8690B308.unk_36, 0.0f, 240.0f, 12.5f, 224.5f, -0x8000);

    D_8690B3C0.unk_00 = 0xFF;
    D_8690B3B8 = 0;
    D_8690B3BC = D_869091B8[0].unk_00;
    D_8690B3B4 = 0;
    D_8690B5F4 = 0;
    D_8690B5F8 = 0;
}

void GalleryCamera_CopyControllerState(Controller* arg0, Controller* arg1) {
    arg0->buttonPressed = arg1->buttonPressed;
    arg0->buttonDown = arg1->buttonDown;
    arg0->stickX = arg1->stickX;
    arg0->stickY = arg1->stickY;
    arg0->stickMag = arg1->stickMag;
}

void func_86900A14(void) {
    Controller* c = &D_8690B5D0;

    D_8690B3B4 = D_869091B8[D_8690B3B8].unk_02;
    if (D_8690B3BC == 0) {
        D_8690B3B8++;
        D_8690B3BC = D_869091B8[D_8690B3B8].unk_00;
    }

    c->stickMag = D_869091B8[D_8690B3B8].unk_04;
    c->stickY = D_869091B8[D_8690B3B8].unk_0C;
    c->buttonPressed = D_869091B8[D_8690B3B8].unk_02 & (D_869091B8[D_8690B3B8].unk_02 ^ D_8690B3B4);
    c->buttonDown = D_869091B8[D_8690B3B8].unk_02;

    if (D_8690B3BC > 0) {
        D_8690B3BC--;
    }

    GalleryCamera_CopyControllerState(&D_8690B390, &D_8690B5D0);
}

void GalleryCamera_AddPolarOffset(f32* arg0, f32* arg1, s16 arg2, s16 arg3) {
    *arg0 += arg3 * COSS(arg2);
    *arg1 += arg3 * SINS(arg2);
}

void Gallery_CameraReadInput(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

void GalleryCamera_UpdatePokemonIdleAnim(void) {
    if (D_8690A6F4 <= 0x96) {
        D_8690A6F4++;
    }

    if ((D_8690A6F4 >= 0x96) && (ModelAnim_IsAnimationDone(&D_8690A69C->unk_004) != 0) && (D_8690A6FC == 0)) {
        ModelAnim_SetAnimation(&D_8690A69C->unk_004, D_8690A718[D_8690A704].unk_00);
        ModelAnim_SetFrame(&D_8690A69C->unk_004, 0);
        ModelAnim_SetEventFrame(&D_8690A69C->unk_004, 0);
        ModelAnim_SetEventTrack(&D_8690A69C->unk_004, D_8690A718[D_8690A704].unk_01);
        D_8690A6FC = 1;
    }

    if ((ModelAnim_IsAnimationDone(&D_8690A69C->unk_004) != 0) && (D_8690A6FC == 1)) {
        ModelAnim_SetAnimation(&D_8690A69C->unk_004, D_8690A718[D_8690A700].unk_00);
        ModelAnim_SetFrame(&D_8690A69C->unk_004, 0);
        D_8690A6F4 = 0;
        D_8690A6FC = 0;
    }
}

void GalleryCamera_UpdatePokemonEventLoop(void) {
    D_8690A6F8++;
    if (D_8690A6F8 == 60) {
        D_8690A6F8 = 0;
        if (D_8690A6FC == 0) {
            ModelAnim_SetEventFrame(&D_8690A69C->unk_004, 0);
            ModelAnim_SetEventTrack(&D_8690A69C->unk_004, D_8690A718[D_8690A700].unk_01);
        }
    }
}

void GalleryCamera_ClearFinishedEventTrack(void) {
    if ((D_8690A69C->unk_004.eventTrack.trackId != -1) && (ModelAnim_IsEventTrackNearEnd(&D_8690A69C->unk_004) == 1)) {
        ModelAnim_SetEventFrame(&D_8690A69C->unk_004, 0);
        ModelAnim_SetEventTrack(&D_8690A69C->unk_004, -1);
    }
}

void Gallery_CapturePhoto(void) {
    if ((D_8690B390.buttonPressed & 0x8000) && (D_8690B344 < 0x18)) {
        Audio_PlaySoundEffectById(SFX_PHOTO_CAPTURE);
        D_8690B340 = 0xA;
        if (D_8690A70C != 1) {
            Vec3f_SetComponentsDuplicate(&D_83402EE0[D_8690B344].unk_50, D_87906054->unk_60.eye.x, D_87906054->unk_60.eye.y,
                          D_87906054->unk_60.eye.z);
            Vec3f_SetComponentsDuplicate(&D_83402EE0[D_8690B344].unk_5C, D_87906054->unk_60.at.x, D_87906054->unk_60.at.y,
                          D_87906054->unk_60.at.z);
            D_83402EE0[D_8690B344].unk_6C = 0;

            D_83402EE0[D_8690B344].unk_6C = D_8690A710->unk_014 * 4;
            if (D_8690A710->unk_008 == 25.0f) {
                D_83402EE0[D_8690B344].unk_6C |= 2;
            }

            D_83402EE0[D_8690B344].unk_6C |= D_8690A710->unk_00C * 0x10;
            D_83402EE0[D_8690B344].unk_68 = gParticleFrameCounter;

            D_83402EE0[D_8690B344].unk_00 = D_8690A69C->unk_004.position.y;
            D_83402EE0[D_8690B344].unk_04 = D_8690A69C->unk_16C;
            D_83402EE0[D_8690B344].unk_06 = D_8690A69C->unk_004.transformAnim.frameFixed >> 0x10;
            D_83402EE0[D_8690B344].unk_05 = D_8690A69C->unk_004.transformAnim.animationId;
            D_83402EE0[D_8690B344].unk_08 = D_8690A69C->unk_004.eventTrack.trackId;
            D_83402EE0[D_8690B344].unk_09 = D_8690A69C->unk_004.eventTrack.frame;

            Particle31_PackSlotData(D_83402EE0[D_8690B344].unk_0A);
            Gallery_CopyPhotoMonFromBattleMon(&D_83402EE0[D_8690B344].unk_70, &D_8690A6A0);
        }

        D_8690B360.unk_00 = 0x14;

        D_8690B344++;
        if (D_8690A70C != 1) {
            D_83402E20 = D_8690B344;
        }

        StageLoader_RunFrames(1);
    }
}

void Gallery_SwitchBackgroundSet(u16 arg0) {
    if (arg0 & 0xC00) {
        Gallery_FinalizeBackgroundLoad();
        Gallery_LoadBackgroundSet(D_8690A710->unk_00C);
        D_8690B340 = 5;
    }
}

s32 Gallery_HandleBackgroundSwitchInput(void) {
    u16 sp1E;

    if ((D_8690B390.buttonPressed & 0x8020) && (D_8690B380 == 1)) {
        D_8690B380 = ~D_8690B380 + 2;
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        return 1;
    }

    if (D_8690B390.buttonPressed & 0x20) {
        D_8690B380 = ~D_8690B380 + 2;
        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
    }

    if (D_8690B380 == 0) {
        return 0;
    }

    if (!(D_8690B390.buttonDown & 0xC00)) {
        D_8690A680 = -1;
        return 1;
    }

    sp1E = D_8690B390.buttonDown;
    D_8690A680++;
    if ((D_8690A680 >= 8) || (D_8690A680 == 0)) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        if (D_8690A680 != 0) {
            D_8690A680 = 6;
        }
    } else {
        return 1;
    }

    D_8690B38C = 0xF;
    if (D_8690B378.unk_07 == 0) {
        if (D_8690B378.unk_04 == 8) {
            D_8690B38C--;
        } else if (D_8690B378.unk_04 == 7) {
            D_8690B38C -= 2;
        } else {
            D_8690B38C -= 2;
            D_8690B38C += D_8690B378.unk_04 - 7;
        }
    }

    if ((sp1E & 0x800) && (D_8690B388 == 0) && (D_8690B384 == 0) && (D_8690A710->unk_00C == 0)) {
        D_8690B384 = D_8690B38C - 4;
        D_8690A710->unk_00C = D_8690B38C;
        D_8690B388 = 4;
        Gallery_SwitchBackgroundSet(sp1E);
    } else if ((sp1E & 0x400) && (D_8690B388 == 4) && (D_8690B384 == (D_8690B38C - 4)) &&
               (D_8690B38C == D_8690A710->unk_00C)) {
        D_8690B384 = 0;
        D_8690A710->unk_00C = 0;
        D_8690B388 = 0;
        Gallery_SwitchBackgroundSet(sp1E);
    } else {
        if (sp1E & 0x800) {
            if (D_8690A710->unk_00C > 0) {
                D_8690A710->unk_00C--;
            }
        }

        if (sp1E & 0x400) {
            if (D_8690A710->unk_00C < D_8690B38C) {
                D_8690A710->unk_00C++;
            }
        }

        if ((sp1E & 0x800) && (D_8690B388 == 0) && (D_8690B384 > 0)) {
            D_8690B384--;
        }

        if ((sp1E & 0x400) && (D_8690B388 == 4) && (D_8690B384 < (D_8690B38C - 4))) {
            D_8690B384++;
        }

        if ((sp1E & 0x800) && (D_8690B388 > 0)) {
            D_8690B388--;
        }

        if ((sp1E & 0x400) && (D_8690B388 < 4)) {
            D_8690B388++;
        }

        Gallery_SwitchBackgroundSet(sp1E);
    }

    return 1;
}

void Gallery_CameraUpdateTutorialText(void) {
    s32 i;

    if ((D_8690A70C == 1) && (gCameraTutorialTextIds[D_8690B5F4] != 0xFF)) {
        D_8690B5F8++;
        if (D_8690B5F8 == D_86909168[D_8690B5F4].unk_00) {
            D_8690B3C0.unk_00 = 0;
        }

        if (D_8690B5F8 == D_86909168[D_8690B5F4].unk_04) {
            D_8690B3C0.unk_00 = 0xFF;
            D_8690B5F4++;
        }

        switch (D_8690B3C0.unk_00) {
            case 0x0:
                D_8690B3C0.unk_04 = 0;
                D_8690B3C0.unk_08 = 0xC8;
                D_8690B3C0.unk_0C = 0x14;

                // clang-format off
                for (i = 0; i < 255; i++) { D_8690B3D0[i] = 0; }
                // clang-format on

                sprintf(D_8690B4D0, Text_GetString(NULL, 0, gCameraHelpText, gCameraTutorialTextIds[D_8690B5F4]));
                D_8690B3C0.unk_00++;
                break;

            case 0x1:
                D_8690B3C0.unk_0C = Math_StepToS32(D_8690B3C0.unk_0C, 0x23, 0xA, 0xA);
                if (D_8690B3C0.unk_0C == 0x23) {
                    D_8690B3C0.unk_00++;
                }
                break;

            case 0x2:
                if (D_8690B4D0[D_8690B3C0.unk_04] != 0) {
                    D_8690B3D0[D_8690B3C0.unk_04] = D_8690B4D0[D_8690B3C0.unk_04];
                    D_8690B3C0.unk_04++;
                    Audio_PlaySoundEffectById(SFX_CAMERA_TEXT);
                }
                break;

            case 0xFF:
                break;
        }
    }
}

s32 Gallery_CameraExitState_Active(void) {
    Gallery_CameraUpdateTutorialText();

    if (D_8690B360.unk_00 != 0) {
        D_8690B360.unk_02 -= 3;
    }

    D_8690B360.unk_00 = Math_StepToS32(D_8690B360.unk_00, 0, 2, 2);

    if (D_8690B340) {
        D_8690B340--;
        return 0;
    }

    if (D_8690B344 && D_8690B344 && D_8690B344) {}

    if (D_8690B344 == 0x18) {
        D_8690B360.unk_00 = 0x14;
        D_8690B350.unk_04 = 0;
        D_8690B348 = 1;
        D_8690B344--;
        Audio_PlaySoundEffectById(SFX_CAMERA_FULL);
        return 0;
    }

    if (Gallery_HandleBackgroundSwitchInput() != 0) {
        return 0;
    }

    if (GalleryCamera_UpdateZoomFov() != 0) {
        return 0;
    }

    if (gPlayer1Controller->buttonPressed & 0x4000) {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        D_8690A67C = 1;
        return D_8690A67C;
    }

    if (D_8690B390.buttonPressed & 0x1000) {
        Audio_PlaySoundEffectById(SFX_CAMERA_EXIT);
        D_8690A67C = 2;
        return D_8690A67C;
    }

    if (D_8690B390.buttonPressed & 0x2000) {
        D_8690A710->unk_014++;
        if (D_8690A710->unk_014 == 3) {
            D_8690A710->unk_014 = 0;
        }

        if (D_8690A710->unk_014 == 0) {
            Audio_PlaySoundEffectById(SFX_MENU_BACK);
        } else {
            Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
        }
    }

    GalleryCamera_HandleDPadInput();
    GalleryCamera_HandleFreeMoveInput();
    Gallery_CapturePhoto();
    return 0;
}

s32 Gallery_CameraExitState_CountDown(void) {
    D_8690B360.unk_04 = 0;
    D_8690B360.unk_02 += 4;

    if (D_8690B360.unk_00 == 0) {
        if (D_8690B344 != 0) {
            D_8690B344--;
            D_8690B360.unk_00 = 0x14;
        } else {
            D_8690B348 = 2;
            Audio_PlaySoundEffectById(SFX_CAMERA_EXIT);
            D_8690B360.unk_08 = 0xE38;
        }
    }

    D_8690B360.unk_00 = Math_StepToS32(D_8690B360.unk_00, 0, 0xF, 0xF);
    return 0;
}

s32 Gallery_CameraExitState_SpinOut(void) {
    D_8690B360.unk_02 += 4;
    D_8690B360.unk_04 = Math_StepToS32(D_8690B360.unk_04, 0x30, 0xA, 0xA);

    if (D_8690B360.unk_04 >= 0x30) {
        D_8690B360.unk_08 = Math_StepToS32(D_8690B360.unk_08, 0, 0xC8, 0xC8);
        D_8690B360.unk_0A -= 0x31C7;
        D_8690B360.unk_06 = SINS(D_8690B360.unk_0A) * D_8690B360.unk_08;
        if (D_8690B360.unk_08 == 0) {
            D_8690B360.unk_06 = 0;
            D_8690B348 = 3;
        }
    }
    return 0;
}

s32 Gallery_CameraExitState_ExpandBox(void) {
    D_8690B350.unk_04 = Math_StepToS32(D_8690B350.unk_04, 0x50, 0xA, 0xA);
    if (D_8690B350.unk_04 == 0x50) {
        D_8690B350.unk_0C = 0xAA;
        D_8690B350.unk_0E = 0xA;
        D_8690B350.unk_08 = 0xA0 - (D_8690B350.unk_0C / 2);
        D_8690B350.unk_0A = 0x78;
        D_8690B350.unk_00 = 0;
        D_8690B348 = 4;
        Audio_PlaySoundEffectById(0x30);
    }
    return 0;
}

s32 Gallery_CameraExitState_FadeOut(void) {
    D_8690B350.unk_0E = Math_StepToS32(D_8690B350.unk_0E, 0x32, 0xA, 0xA);

    if (D_8690B350.unk_0E == 0x32) {
        D_8690B350.unk_00++;
    }

    if (D_8690B350.unk_00 == 0x32) {
        D_8690A67C = 2;
        return D_8690A67C;
    }

    return 0;
}

s32 Gallery_CameraCheckExit(void) {
    switch (D_8690B348) {
        case 0:
            return Gallery_CameraExitState_Active();

        case 1:
            return Gallery_CameraExitState_CountDown();

        case 2:
            return Gallery_CameraExitState_SpinOut();

        case 3:
            return Gallery_CameraExitState_ExpandBox();

        case 4:
            return Gallery_CameraExitState_FadeOut();
    }
}

void Gallery_CameraDraw(void) {
    BgStage_DrawFrame();

    if ((D_8690A688 == -1) || (D_8690A688 == 0)) {
        GfxImage_FillCurrent(&gDisplayListHead, 1);
    } else if (D_8690A688 < 0x10000) {
        GfxImage_FillCurrent(&gDisplayListHead, D_8690A688);
    } else {
        GfxImage_FillCurrent(&gDisplayListHead, 0xA6BF);
    }

    GeoRender_AdvanceFrameCounter();
    Geo_RenderRootNode(D_87906050);
    Gallery_DrawFrameMarkers();
    Gallery_CameraDrawHelpBalloon();
    Gallery_DrawPhotoCounterReel();
    Gallery_DrawPhotoCounterReelExit();
    Gallery_DrawTutorialTextBox();
    Gallery_DrawNicknameBanner(D_8690A6A0.unk_30);
    Gallery_DrawBackgroundSelectMenu(D_8690A710->unk_00C);
    BgStage_AdvanceFrame();
}

void Gallery_CameraIntro(void) {
    f32 temp_fv0;
    f32 tmp1;
    f32 tmp2;
    f32 tmp3;
    f32 tmp4;
    s32 i;
    s16 var_s3 = 0;

    StageFade_StartFromOpaque(0x14);
    D_8690B360.unk_10 -= 0.8;
    D_8690B360.unk_14 = 0.0f;
    D_8690B360.unk_0C = 351.0f;

    for (i = 0; i < 15; i++) {
        Gallery_CameraReadInput();
        Gallery_CameraDraw();
    }

    tmp2 = 5.7f;
    tmp3 = 0.6f;
    tmp1 = 19.0f;
    Audio_PlaySoundEffectById(0x2F);
    tmp4 = tmp2 * tmp3;

    while (true) {
        Gallery_CameraReadInput();
        var_s3 = Math_StepToS32(var_s3, 0x46, 0xA, 0xA);
        D_8690B308.unk_00[0] = Math_StepToS32(D_8690B308.unk_00[0], 0xA0, 0xA, 0xA);
        D_8690B308.unk_00[4] = Math_StepToS32(D_8690B308.unk_00[4], 0x24, 0xA, 0xA);
        D_8690B308.unk_00[1] = Math_StepToS32(D_8690B308.unk_00[1], 0x120, 0xA, 0xA);
        D_8690B308.unk_00[5] = Math_StepToS32(D_8690B308.unk_00[5], 0x78, 0xA, 0xA);
        D_8690B308.unk_00[2] = Math_StepToS32(D_8690B308.unk_00[2], 0xA0, 0xA, 0xA);
        D_8690B308.unk_00[6] = Math_StepToS32(D_8690B308.unk_00[6], 0xCC, 0xA, 0xA);
        D_8690B308.unk_00[3] = Math_StepToS32(D_8690B308.unk_00[3], 0x20, 0xA, 0xA);
        D_8690B308.unk_00[7] = Math_StepToS32(D_8690B308.unk_00[7], 0x78, 0xA, 0xA);

        if (var_s3 < 0x3D) {
            GalleryCamera_AddPolarOffset(&D_8690B308.unk_10, &D_8690B308.unk_20, D_8690B308.unk_30 + 0x8000, 0xA);
            GalleryCamera_AddPolarOffset(&D_8690B308.unk_14, &D_8690B308.unk_24, D_8690B308.unk_32, 0xA);
            GalleryCamera_AddPolarOffset(&D_8690B308.unk_18, &D_8690B308.unk_28, D_8690B308.unk_34 + 0x8000, 0xA);
            GalleryCamera_AddPolarOffset(&D_8690B308.unk_1C, &D_8690B308.unk_2C, D_8690B308.unk_36, 0xA);
        }

        D_8690B360.unk_10 = -tmp1;

        temp_fv0 = -(D_8690B360.unk_0C - (tmp4 + 251.0f));
        if (temp_fv0 >= 0.0) {
            D_8690B360.unk_10 -= tmp2 * (0.0 - temp_fv0);
        }

        D_8690B360.unk_10 *= tmp3;
        D_8690B360.unk_14 += D_8690B360.unk_10;
        D_8690B360.unk_14 *= tmp3;

        D_8690B360.unk_0C += D_8690B360.unk_14;

        if ((D_8690B360.unk_14 >= 0.0f) && (D_8690B360.unk_14 <= 1.0f)) {
            break;
        }

        Gallery_CameraDraw();
    }

    Gallery_CameraReadInput();
    D_8690B360.unk_0C = 251.0f;
    Gallery_CameraDraw();
}

void Gallery_CameraLoop(void) {
    s32 var_s0 = 1;
    void (*temp_s1)(void) = Util_ConvertAddrToVirtAddr(Particle_UpdateFrameCountersAlias);

    while (var_s0 != 0) {
        Gallery_CameraReadInput();

        if (D_8690A70C != 1) {
            GalleryCamera_CopyControllerState(&D_8690B390, gPlayer1Controller);
        } else {
            func_86900A14();
        }

        if (Gallery_CameraCheckExit() != 0) {
            var_s0 = 0;
        }

        GalleryCamera_UpdatePokemonIdleAnim();
        GalleryCamera_UpdatePokemonEventLoop();
        GalleryCamera_ClearFinishedEventTrack();

        temp_s1();

        Gallery_CameraDraw();
    }
}

void Gallery_CameraOutro(void) {
    s32 i;

    StageFade_StartFromTransparent(0x1E);

    for (i = 0; i < 30; i++) {
        Gallery_CameraReadInput();
        Gallery_CameraDraw();
    }
}

void Gallery_CameraInit(s32 arg0) {
    D_8690A70C = arg0;
    Gallery_InitBackgroundScene();

    D_8690A69C = main_pool_alloc(sizeof(unk_D_8690A69C), 0);
    bzero(D_8690A69C, sizeof(unk_D_8690A69C));

    D_8690A710 = main_pool_alloc(sizeof(unk_D_8690A710), 0);
    bzero(D_8690A710, sizeof(unk_D_8690A710));

    GalleryCamera_InitIntroSequence();
    Gallery_SetupPhotoModel();
    GalleryCamera_InitFreeView();
    Gallery_LoadBackgroundSet(D_8690A710->unk_00C);
}

s32 Gallery_CameraMain(s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('SNAP');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    Font_Init(0x16, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_5000000, snap_mode_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);

    Save_EnsureBankLoaded(2);
    Save_GetModeSettings(&D_8690B378, 0);

    D_8690A698 = ASSET_LOAD2(stadium_models, 1, 1);
    Text_InitStringTables();
    gCameraHelpText = Text_GetStringTable(0x2B);
    Gallery_CameraInit(arg0);
    StageContext_Activate(sp24);
    Gallery_CameraIntro();
    Gallery_CameraLoop();
    Gallery_CameraOutro();
    StageContext_Deactivate();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('SNAP');

    return D_8690A67C;
}
