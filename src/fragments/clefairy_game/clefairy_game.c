#include "clefairy_game.h"
#include "src/geo_render.h"
#include "src/model_animation.h"
#include "src/model_animation_events.h"
#include "src/geo_layout.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/ui_graphics.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/audio_loop_point.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/controller.h"
#include "src/fragments/widget_toolkit/widget_toolkit.h"
#include "src/fragments/minigame_shared_graphics/minigame_shared_graphics.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_861054C0 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ char pad4[4];
    /* 0x008 */ DisplayObject unk_008;
    /* 0x170 */ s16 unk_170;
    /* 0x172 */ u16 unk_172;
    /* 0x174 */ s16 unk_174[0xC];
    /* 0x18C */ s16 unk_18C;
    /* 0x18E */ s16 unk_18E[0xC];
    /* 0x1A6 */ s16 unk_1A6;
    /* 0x1A8 */ s16 unk_1A8;
    /* 0x1AA */ s16 unk_1AA;
    /* 0x1AC */ s16 unk_1AC;
    /* 0x1AE */ s16 unk_1AE;
    /* 0x1B0 */ s16 unk_1B0;
    /* 0x1B2 */ s16 unk_1B2;
    /* 0x1B4 */ s16 unk_1B4;
    /* 0x1B6 */ char pad1B6[2];
    /* 0x1B8 */ f32 unk_1B8;
    /* 0x1BC */ f32 unk_1BC;
} unk_D_861054C0; // size = 0x1C0

typedef struct unk_D_86105EA0 {
    /* 0x000 */ char unk000[0x4];
    /* 0x004 */ DisplayObject unk_004;
} unk_D_86105EA0; // size = 0x16C

typedef struct unk_D_86106450 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ DisplayObject unk_004;
    /* 0x16C */ ModelNodeView* unk_16C;
} unk_D_86106450; // size = 0x170

void ClefairyGame_DespawnPatternIcons(void);
void ClefairyGame_SpawnPatternIcons(void);

static u32 D_86104640[] = {
    0xFFFFFFD8, 0xFFFFFFF6, 0x00000014, 0x00000032, 0xA5D4A5C3, 0xA5D4A4CE, 0xA4E6A4D3, 0xA4D5A4EA, 0xA4ADA4E7,
    0xA4A6A4B7, 0xA4C40000, 0xA4B3A4AF, 0xA4D0A4F3, 0xA4CBA4AB, 0xA4ABA4EC, 0xA4BFA1A1, 0xA4E4A4B8, 0xA4EBA4B7,
    0xA4CEA1A1, 0xA4E0A4AD, 0xA4F2A1A1, 0xA4AAA4DC, 0xA4A8A4C6, 0x00000000, 0xA4BBA4F3, 0xA4BBA4A4, 0xA4ACA1A1,
    0xA1D6A4AA, 0xA4B7A4C6, 0xA1BCA1AA, 0xA1D7A4C8, 0xA4A4A4C3, 0xA4BFA4E9, 0xA1A1A5E1, 0xA1BCA5BF, 0xA1BCA4AC,
    0x00000000, 0xA4ADA4A8, 0xA4EBA4DE, 0xA4C7A4CB, 0xA1A1A1A1, 0xA1A1A1A1, 0xA1A1A1A1, 0xA1A1A4C7, 0xA1A1A4B8,
    0xA4E5A4F3, 0xA4D0A4F3, 0xA4C9A4AA, 0xA4EAA4CB, 0x00000000, 0xA4E4A4B8, 0xA4EBA4B7, 0xA4CEA1A1, 0xA4E0A4AD,
    0xA4F2A1A1, 0xA4A4A4EC, 0xA4E8A4A6, 0xA1A30000, 0xA4DEA4C1, 0xA4ACA4A4, 0xA4CEA1A1, 0xA4B9A4AF, 0xA4CAA4AB,
    0xA4C3A4BF, 0xA4D2A4C8, 0xA4ACA1A1, 0xA4ABA4C1, 0xA1A30000, 0xA4E6A4D3, 0xA4D5A4EA, 0xA4CEA4E0, 0xA4ADA4F2,
    0xA4ADA4E1, 0xA4EB0000, 0xA4C1A4E5, 0xA4A6A4E2, 0xA1BCA4AF, 0xA1AA0000, 0xA4AAA4DC, 0xA4A8A4C6, 0xA1BCA4C3,
    0xA1AA0000, 0xA4AAA4B7, 0xA4C6A1BC, 0xA4C3A1AA, 0x00000000, 0xA4BDA4B3, 0xA4DEA4C7, 0xA4C3A1AA, 0x00000000,
    0xA4B5A4F3, 0xA5CFA5A4, 0xA5C3A1AA, 0x00000000,
};

typedef struct unk_D_861047B8 {
    /* 0x00 */ u8 unk_00[6];
    /* 0x06 */ u8 unk_06[4];
} unk_D_861047B8; // size = 0xA

static unk_D_861047B8 D_861047B8[0x2E] = {
    { { 1, 1, 3, 2, 0, 0 }, { 1, 0, 0, 0 } }, { { 0, 1, 0, 1, 2, 2 }, { 1, 0, 0, 0 } },
    { { 2, 0, 2, 1, 0, 0 }, { 1, 1, 0, 0 } }, { { 0, 1, 2, 3, 0, 1 }, { 1, 1, 0, 0 } },
    { { 3, 3, 3, 2, 0, 2 }, { 1, 0, 0, 0 } }, { { 2, 3, 3, 2, 3, 2 }, { 1, 1, 0, 0 } },
    { { 1, 3, 1, 3, 3, 0 }, { 1, 1, 0, 0 } }, { { 3, 3, 1, 1, 2, 2 }, { 1, 0, 0, 0 } },
    { { 0, 1, 0, 1, 0, 1 }, { 1, 0, 0, 0 } }, { { 1, 2, 0, 2, 1, 2 }, { 1, 0, 0, 0 } },
    { { 0, 0, 2, 2, 2, 0 }, { 1, 0, 0, 0 } }, { { 2, 3, 3, 2, 1, 1 }, { 1, 0, 0, 0 } },
    { { 1, 1, 1, 0, 1, 0 }, { 1, 0, 0, 0 } }, { { 2, 2, 0, 3, 2, 3 }, { 1, 1, 0, 0 } },
    { { 0, 3, 0, 3, 2, 3 }, { 1, 0, 0, 0 } }, { { 2, 0, 3, 1, 0, 0 }, { 0, 1, 1, 0 } },
    { { 0, 2, 0, 3, 1, 3 }, { 0, 1, 0, 0 } }, { { 3, 1, 2, 3, 3, 0 }, { 0, 1, 0, 0 } },
    { { 0, 2, 2, 1, 2, 0 }, { 0, 1, 1, 0 } }, { { 2, 2, 0, 1, 0, 3 }, { 0, 1, 1, 0 } },
    { { 3, 0, 1, 2, 2, 3 }, { 0, 1, 0, 0 } }, { { 2, 1, 2, 3, 3, 2 }, { 0, 1, 1, 0 } },
    { { 3, 3, 1, 2, 0, 0 }, { 0, 1, 1, 0 } }, { { 1, 2, 1, 2, 0, 3 }, { 0, 1, 0, 0 } },
    { { 3, 1, 2, 3, 1, 2 }, { 0, 1, 0, 0 } }, { { 2, 1, 2, 0, 0, 3 }, { 0, 0, 1, 1 } },
    { { 1, 0, 3, 1, 2, 2 }, { 0, 0, 1, 0 } }, { { 1, 2, 3, 1, 2, 0 }, { 0, 0, 1, 1 } },
    { { 0, 3, 2, 0, 1, 2 }, { 0, 0, 1, 0 } }, { { 1, 1, 2, 0, 1, 2 }, { 0, 0, 1, 1 } },
    { { 0, 3, 3, 2, 0, 3 }, { 0, 0, 1, 0 } }, { { 3, 0, 3, 1, 2, 0 }, { 0, 0, 1, 1 } },
    { { 1, 2, 0, 1, 2, 0 }, { 0, 0, 1, 0 } }, { { 1, 1, 0, 3, 1, 3 }, { 0, 0, 1, 0 } },
    { { 3, 3, 1, 2, 0, 1 }, { 0, 0, 1, 1 } }, { { 1, 0, 2, 0, 2, 3 }, { 0, 0, 0, 1 } },
    { { 2, 1, 3, 0, 2, 3 }, { 0, 0, 0, 1 } }, { { 3, 0, 2, 1, 2, 0 }, { 0, 0, 0, 1 } },
    { { 0, 2, 1, 2, 3, 2 }, { 0, 0, 0, 1 } }, { { 3, 2, 1, 2, 3, 0 }, { 0, 0, 0, 1 } },
    { { 0, 3, 1, 0, 3, 0 }, { 0, 0, 0, 1 } }, { { 3, 1, 3, 2, 0, 2 }, { 0, 0, 0, 1 } },
    { { 0, 2, 0, 3, 1, 2 }, { 0, 0, 0, 1 } }, { { 3, 1, 2, 3, 0, 2 }, { 0, 0, 0, 1 } },
    { { 0, 2, 3, 2, 1, 3 }, { 0, 0, 0, 1 } }, { { 0xFF, -1, -1, -1, -1, -1 }, { 0xFF, 0xFF, 0xFF, 0xFF } },
};

typedef struct unk_D_86104984 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} unk_D_86104984; // size = 0xC

static unk_D_86104984 D_86104984[4] = {
    { 0x31, 0xD4, -1, -1, 0, -1 },
    { 0x73, 0xD4, -1, -1, 0xFF, 0xFF },
    { 0xB5, 0xD4, -1, -1, -0x100, 0xFF },
    { 0xF7, 0xD4, -1, -1, -1, 0xFF },
};

static s16 D_861049B4[5][6] = {
    { 0x87A0, 0x1190, 0x0028, 0x003C, 0x005A, 0x000A }, { 0x87A0, 0x1178, 0x0014, 0x0046, 0x005A, 0x0006 },
    { 0x87A0, 0x1180, 0x001E, 0x004B, 0x005F, 0x0002 }, { 0x87A0, 0x11A4, 0x0028, 0x005A, 0x0063, 0x0001 },
    { 0x0032, 0x001E, 0x0019, 0x0019, 0x000F, 0x0014 },
};

static u8 D_861049F0[] = { 0, 5, 0, 10 };

static unk_func_87801684 D_861049F4[] = {
    { 0x3040580, 0x12 }, { 0x3040980, 2 }, { 0x3040D80, 8 }, { 0x3040980, 2 }, { 0x0, 0x0 },
};

static unk_func_87801684 D_86104A1C[] = {
    { 0x03042E00, 0x0006 }, { 0x03044360, 0x0002 }, { 0x03044A80, 0x0006 }, { 0x03044360, 0x0002 },
    { 0x03042E00, 0x0006 }, { 0x03041180, 0x0002 }, { 0x030418A0, 0x0006 }, { 0x03041180, 0x0002 },
    { 0x03042E00, 0x0006 }, { 0x03043520, 0x0002 }, { 0x03043C40, 0x0006 }, { 0x03043520, 0x0002 },
    { 0x03042E00, 0x0006 }, { 0x03041FC0, 0x0002 }, { 0x030426E0, 0x0006 }, { 0x03041FC0, 0x0002 },
    { 0x00000000, 0x0000 },
};

static u32 D_86104AA4[] = {
    0x0C00FFFF, 0x5000000,  0x0B00001E, 0x00000000, 0x014000F0, 0x0000000F, 0x00000000, 0x00000000,
    0x5000000,  0x0D000000, 0x5000000,  0x14000000, 0x002B0012, 0xFFFFFF32, 0x16FFFFFF, 0x0F000003,
    0x5000000,  0x1F00FFFF, 0x00000000, 0x00000000, 0x00000000, 0x03E803E8, 0x03E80000, 0x5000000,
    0x0A000000, 0x800AC840, 0x6000000,  0x6000000,  0x6000000,  0x6000000,  0x3000000,  0x87806398,
    0x6000000,  0x1000000,  0x1,        0x00000000, 0x00000003, 0x00000002,
};

extern u32 D_86104C00[];
extern u32 D_86104DF0[];
extern u32 D_861051D0[];
extern u32 D_86104FE0[];
extern u32 D_86104CF8[];
extern u32 D_86104EE8[];
extern u32 D_861052C8[];
extern u32 D_861050D8[];

static u32* D_86104B3C[4][2] = {
    { D_86104C00, D_86104CF8 },
    { D_86104DF0, D_86104EE8 },
    { D_861051D0, D_861052C8 },
    { D_86104FE0, D_861050D8 },
};

typedef struct unk_D_86104B5C {
    /* 0x00 */ u8 unk_00[3];
} unk_D_86104B5C;

static unk_D_86104B5C D_86104B5C = { 0, 0, 30 };
static unk_D_86104B5C D_86104B60 = { 0, 0, 150 };

static s32 pad_86104B64[] = { 0, 0, 0 };
static Gfx D_86104B70[] = {
    gsSPEndDisplayList(),
};

static u32 D_86104B78[] = {
    0xFFFEFFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFE0001, 0x0001FFFE, 0xFFFE0001, 0x0001FFFE,
    0x0001F7CB, 0xF7CB0001, 0x0001F7CB, 0xF7CB0001, 0xFFFE0001, 0xFFCDF7CB, 0xF7CBF7CB, 0x0001FFFE,
    0xFFFEFFFE, 0x0001FFCD, 0xF7CB0001, 0xFFFEFFFE, 0xFFFE0001, 0xFFCDF7CB, 0xF7CBF7CB, 0x0001FFFE,
    0x0001F7CB, 0xF7CB0001, 0x0001F7CB, 0xF7CB0001, 0xFFFE0001, 0x0001FFFE, 0xFFFE0001, 0x0001FFFE,
};

static Gfx D_86104BF8[] = {
    gsSPEndDisplayList(),
};

u32 D_86104C00[] = {
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B50025, 0x00270025,
    0x0025D6B5, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFED6B5, 0x00270027, 0x00290029, 0x00270025, 0xD6B3FFFE, 0xFFFEFFFE,
    0xD6B50025, 0x00290869, 0x31AD086B, 0x00270027, 0x0025D6B5, 0xD6B5D6B5, 0xD6B50025, 0x002931AB, 0x842F31AD,
    0x00290025, 0x0025D6B5, 0xD6B5D6B5, 0xD6B50025, 0x00290869, 0x31AD086B, 0x00270027, 0x0025D6B5, 0xD6B5D6B5,
    0xD6B50025, 0x00270027, 0x00290029, 0x00250027, 0x0025D6B5, 0xD6B5D6B5, 0xFFFED6B5, 0x00250025, 0x00270025,
    0x00250025, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B50025, 0x00250025, 0x0025D6B5, 0xFFFEFFFE, 0xFFFEFFFE,
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE,
};

static Gfx D_86104CF0[] = {
    gsSPEndDisplayList(),
};

u32 D_86104CF8[] = {
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B50037, 0x08390039,
    0x0039D6B3, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFED6B5, 0x08792979, 0x31FD2939, 0x10B90039, 0xCE73FFFE, 0xFFFEFFFE,
    0xD6B50037, 0x213B5ABD, 0x7C3D52BD, 0x293B0039, 0x0039D6B3, 0xD6B5D6B5, 0xD6B50037, 0x39FB7BFF, 0xCE7F7BFF,
    0x31BB0879, 0x0037CEB5, 0xD6B5D6B5, 0xD6B50037, 0x213B52FD, 0x83FD52BD, 0x217B0037, 0x0039D6B3, 0xD6B5D6B5,
    0xD6B50037, 0x0879297B, 0x31BB2979, 0x08790039, 0x0039D6B3, 0xD6B5D6B5, 0xFFFED6B5, 0x00370039, 0x08770039,
    0x00390039, 0xD6B3FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B50037, 0x00390039, 0x0039D6B3, 0xFFFEFFFE, 0xFFFEFFFE,
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE,
};

static Gfx D_86104DE8[] = {
    gsSPEndDisplayList(),
};

u32 D_86104DF0[] = {
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B51A0B, 0x1A0B1A0B,
    0x1A0BCEB3, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFED6B5, 0x1A0B1A4B, 0x1A4B1A4B, 0x1A4B1A09, 0xCE75FFFE, 0xFFFEFFFE,
    0xD6B51209, 0x1A4B224D, 0x234F1A8B, 0x1A0B1A4B, 0x1A0BCEB3, 0xD6B5D6B5, 0xD6B51209, 0x1A4B230F, 0x3455234F,
    0x1A4B1A0B, 0x1A0BCEB3, 0xD6B5D6B5, 0xD6B51209, 0x1A4B224D, 0x234F1A8B, 0x1A0B1A4B, 0x1A0BCEB3, 0xD6B5D6B5,
    0xD6B51209, 0x1A0B1A4B, 0x1A4B1A4B, 0x1A0B1A4B, 0x1A0BCEB3, 0xD6B5D6B5, 0xFFFED6B5, 0x1A0B1A0B, 0x1A0B1A0B,
    0x1A0B1A0B, 0xCEB3FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B51A0B, 0x1A0B1A0B, 0x1A0BCEB3, 0xFFFEFFFE, 0xFFFEFFFE,
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE,
};

static Gfx D_86104EE0[] = {
    gsSPEndDisplayList(),
};

u32 D_86104EE8[] = {
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B52351, 0x2B51234F,
    0x2351D6B3, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFED6B5, 0x2B912BD3, 0x2C553415, 0x23912B51, 0xCEB3FFFE, 0xFFFEFFFE,
    0xD6B5234F, 0x2C153CD7, 0x3D5B34D7, 0x3415234F, 0x2351D6B3, 0xD6B5D6B5, 0xD6B52351, 0x34553D59, 0x9F6F3D9B,
    0x34152B91, 0x2351CE73, 0xD6B5D6B5, 0xD6B5234F, 0x2C153CD7, 0x3D5B34D7, 0x2C132B51, 0x2351D6B3, 0xD6B5D6B5,
    0xD6B5234F, 0x2B512C15, 0x2C553413, 0x23512B51, 0x2351D6B3, 0xD6B5D6B5, 0xFFFED6B5, 0x23512351, 0x2B512351,
    0x23512351, 0xD6B3FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B52351, 0x23512351, 0x2351D6B3, 0xFFFEFFFE, 0xFFFEFFFE,
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE,
};

static Gfx D_86104FD8[] = {
    gsSPEndDisplayList(),
};

u32 D_86104FE0[] = {
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B53981, 0x39413181,
    0x3981CE75, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFED6B5, 0x39813981, 0x41813981, 0x39813941, 0xCEB5FFFE, 0xFFFEFFFE,
    0xD6B53141, 0x418141C1, 0x520141C1, 0x39813981, 0x3981CE75, 0xD6B5D6B5, 0xD6B53941, 0x39815241, 0x73015A01,
    0x39813981, 0x3941CEB5, 0xD6B5D6B5, 0xD6B53141, 0x418141C1, 0x520141C1, 0x39813981, 0x3981CE75, 0xD6B5D6B5,
    0xD6B53141, 0x39814181, 0x39813981, 0x39813941, 0x3981CE75, 0xD6B5D6B5, 0xFFFED6B5, 0x39813981, 0x39413981,
    0x39813981, 0xCE75FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B53981, 0x39813981, 0x3981CE75, 0xFFFEFFFE, 0xFFFEFFFE,
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE,
};

static Gfx D_861050D0[] = {
    gsSPEndDisplayList(),
};

u32 D_861050D8[] = {
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B5940D, 0x9C4D940D,
    0x940DD6B5, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFED6B5, 0x9C4DB4D1, 0xC551B50F, 0x9C4D940D, 0xD675FFFE, 0xFFFEFFFE,
    0xD6B5940D, 0xB4CFCDD7, 0xD61DC595, 0xBCD1944D, 0x940DD6B5, 0xD6B5D6B5, 0xD6B5940D, 0xBD51D61D, 0xEEEBD61F,
    0xBD4F9C0F, 0x940DD6B3, 0xD6B5D6B5, 0xD6B5940D, 0xB4CFCDD7, 0xD61DC595, 0xB4D19C0D, 0x940DD6B5, 0xD6B5D6B5,
    0xD6B5940D, 0x9C4DB4CF, 0xBD51B4D1, 0xA44D940D, 0x940DD6B5, 0xD6B5D6B5, 0xFFFED6B5, 0x940D940D, 0x9C4D940F,
    0x940D940D, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B5940D, 0x940D940D, 0x940DD6B5, 0xFFFEFFFE, 0xFFFEFFFE,
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE,
};

static Gfx D_861051C8[] = {
    gsSPEndDisplayList(),
};

u32 D_861051D0[] = {
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B55801, 0x58015801,
    0x5801D6B5, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFED6B5, 0x58016001, 0x68016001, 0x58015801, 0xD6B5FFFE, 0xFFFEFFFE,
    0xD6B55801, 0x60016801, 0x88016801, 0x60015801, 0x5801D6B5, 0xD6B5D6B5, 0xD6B55801, 0x60018801, 0xB8018801,
    0x60015801, 0x5801D6B5, 0xD6B5D6B5, 0xD6B55801, 0x60016801, 0x88016801, 0x60015801, 0x5801D6B5, 0xD6B5D6B5,
    0xD6B55801, 0x58016001, 0x60016001, 0x60015801, 0x5801D6B5, 0xD6B5D6B5, 0xFFFED6B5, 0x58015801, 0x58015801,
    0x58015801, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B55801, 0x58015801, 0x5801D6B5, 0xFFFEFFFE, 0xFFFEFFFE,
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE,
};

static Gfx D_861052C0[] = {
    gsSPEndDisplayList(),
};

u32 D_861052C8[] = {
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B5B909, 0xC109B909,
    0xB909D6B5, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFED6B5, 0xC909D98D, 0xDA11E18D, 0xC14BC109, 0xCE73FFFE, 0xFFFEFFFE,
    0xD6B5B909, 0xD98DEB19, 0xEC21E319, 0xE18DB909, 0xB909D6B5, 0xD6B5D6B5, 0xD6B5B909, 0xE211EC21, 0xFEB5EC63,
    0xE211B909, 0xC109CE73, 0xD6B5D6B5, 0xD6B5B909, 0xD98DEB19, 0xEC21E319, 0xD98DC109, 0xB909D6B5, 0xD6B5D6B5,
    0xD6B5B909, 0xC909D98D, 0xDA11E18D, 0xC109C109, 0xB909D6B5, 0xD6B5D6B5, 0xFFFED6B5, 0xB909B909, 0xC109C14B,
    0xB909B909, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0xD6B5B909, 0xB909B909, 0xB909D6B5, 0xFFFEFFFE, 0xFFFEFFFE,
    0xFFFEFFFE, 0xFFFED6B5, 0xD6B5D6B5, 0xD6B5FFFE, 0xFFFEFFFE, 0xFFFEFFFE, 0x00000000, 0x00000000,
};

static unk_D_86002F30* D_86105480;
static unk_D_86002F34* D_86105484;
static unk_D_86002F34_00C* D_86105488;
static unk_D_86002F30* D_8610548C;
static s16 D_86105490;
static s16 D_86105492;
static s16 D_86105494;
static u16 D_86105496;
static s32 D_86105498;
static s32 D_8610549C;
static s16 D_861054A0;
static s16 D_861054A2;
static s16 D_861054A4;
static s16 D_861054A6;
static s16 D_861054A8;
static s32 D_861054AC;
static s32 D_861054B0;
static FontContext* D_861054B4;
static s16 D_861054B8;
static s16 D_861054BA;
static s32 D_861054BC;
static unk_D_861054C0 D_861054C0[4];
static s32 D_86105BC0;
static unk_D_861054C0* D_86105BC4;
static DisplayObject* D_86105BC8;
static s16 D_86105BCC;
static s16 D_86105BCE;
static DisplayObject D_86105BD0;
static DisplayObject D_86105D38;
static unk_D_86105EA0 D_86105EA0[4];
static unk_D_86106450 D_86106450[12];
static s16 D_86107590;

void ClefairyGame_HidePatternIcons(void) {
    ClefairyGame_DespawnPatternIcons();
}

void ClefairyGame_ShowPatternIcons(void) {
    ClefairyGame_SpawnPatternIcons();
}

void ClefairyGame_SetAllPlayerAnimSpeed(s32 arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_861054C0[i].unk_008.transformAnim.speedFixed = arg0;
    }
}

unk_D_861047B8* ClefairyGame_ChoosePatternEntry(s32 arg0, s32 arg1) {
    UNUSED s32 pad[4];
    unk_D_861047B8* sp34;
    s32 var_v1;
    unk_D_861047B8* var_s0;
    s32 i;
    u8 temp_s1;
    s16 tmp;
    u8 val;

    var_s0 = D_861047B8;
    tmp = 0;

    for (i = 0; i < arg0; i++) {
        var_v1 = 1;
        while (var_v1 != 0) {
            temp_s1 = var_s0->unk_06[D_861054B8 % 4];
            if (temp_s1 > 0) {
                var_v1 = 0;
            } else {
                tmp++;
                var_s0++;
            }
        }

        val = Rand_Range(arg1);
        if (val < temp_s1) {
            sp34 = var_s0;
            break;
        }

        arg1 -= temp_s1;
        tmp++;
        var_s0++;
    }

    return sp34;
}

void ClefairyGame_GeneratePattern(void) {
    unk_D_86106450* ptr;
    s32 var_a1;
    s32 var_s2;
    u8 temp_v0;
    u16 var_a3;
    unk_D_861047B8* temp_v0_2;
    unk_D_861047B8* var_v0;
    unk_D_861047B8* var_a0;
    s32 i;

    D_861054A0 = 4;
    var_s2 = 0;
    var_a0 = D_861047B8;
    var_a1 = 1;
    var_a3 = var_a3;
    ptr = &D_86106450[0];

    while (var_a1 != 0) {
        if (var_a0->unk_00[0] != 0xFF) {
            temp_v0 = var_a0->unk_06[D_861054B8 % 4];
            if ((temp_v0 > 0) && (temp_v0 != 0xFF)) {
                var_s2++;
                var_a3 += temp_v0;
            }
            var_a0++;
        } else {
            var_a1 = 0;
        }
    }

    temp_v0_2 = ClefairyGame_ChoosePatternEntry(var_s2, var_a3);

    for (i = 0; i < 6; i++, ptr++) {
        ptr->unk_000 = temp_v0_2->unk_00[i];
        ptr->unk_002 = 0;
        ptr->unk_16C = D_8610548C->unk_08->unk_00[ptr->unk_000];
    }

    var_v0 = ClefairyGame_ChoosePatternEntry(var_s2, var_a3);
    while (var_v0 == temp_v0_2) {
        var_v0 = ClefairyGame_ChoosePatternEntry(var_s2, var_a3);
    }

    for (i = 0; i < 6; i++) {
        ptr->unk_000 = var_v0->unk_00[i];
        ptr->unk_002 = 0;
        ptr->unk_16C = D_8610548C->unk_08->unk_00[ptr->unk_000];
        ptr++;
    }
}

void ClefairyGame_DrawPatternIcon(s16 arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4) {
    Gfx* gfx = gDisplayListHead;
    f32 a;
    f32 b;
    f32 c;
    f32 d;

    if (arg4 == 0.0f) {
        return;
    }

    a = (arg0 - 5.0f * arg4) * 4.0f;
    b = (arg1 - 5.0f * arg4) * 4.0f;
    c = (arg0 + 5.0f * arg4) * 4.0f;
    d = (arg1 + 5.0f * arg4) * 4.0f;

    arg4 += 0;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_2CYCLE);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetRenderMode(gfx++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_PASS2);
    gDPLoadTextureTile(gfx++, D_86104B3C[arg2][arg3], G_IM_FMT_RGBA, G_IM_SIZ_16b, 12, 0, 0, 0, 10, 10, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (s16)(a), (s16)(b), (s16)(c), (s16)(d), G_TX_RENDERTILE, 0, 0, 1024.0f / arg4,
                        1024.0f / arg4);

    gDisplayListHead = gfx;
}

void ClefairyGame_DrawPenaltyDot(s16 arg0, s16 arg1, f32 arg2) {
    Gfx* gfx = gDisplayListHead;

    if (arg2 != 0.0f) {
        f32 a = (arg0 - 4.0f * arg2) * 4.0f;
        f32 b = (arg1 - 4.0f * arg2) * 4.0f;
        f32 c = (arg0 + 4.0f * arg2) * 4.0f;
        f32 d = (arg1 + 4.0f * arg2) * 4.0f;

        arg2 += 0;

        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_2CYCLE);
        gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPSetRenderMode(gfx++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
        gDPSetTexturePersp(gfx++, G_TP_NONE);
        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_PASS2);
        gDPLoadTextureTile(gfx++, D_86104B78, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, 8, 8, 0,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                           G_TX_NOLOD);

        gSPTextureRectangle(gfx++, (s16)(a), (s16)(b), (s16)(c), (s16)(d), G_TX_RENDERTILE, 0, 0, 1024.0f / arg2,
                            1024.0f / arg2);

        gDisplayListHead = gfx;
    }
}

void ClefairyGame_SnapshotInputs(void) {
    D_861054C0[0].unk_172 = gPlayer1Controller->buttonPressed;
    D_861054C0[1].unk_172 = gPlayer2Controller->buttonPressed;
    D_861054C0[2].unk_172 = gPlayer3Controller->buttonPressed;
    D_861054C0[3].unk_172 = gPlayer4Controller->buttonPressed;

    D_861054C0[0].unk_170 = gPlayer1Controller->buttonDown;
    D_861054C0[1].unk_170 = gPlayer2Controller->buttonDown;
    D_861054C0[2].unk_170 = gPlayer3Controller->buttonDown;
    D_861054C0[3].unk_170 = gPlayer4Controller->buttonDown;
}

void ClefairyGame_PollInputs(void) {
    if (StageContext_GetFadeMode() == 0) {
        D_861054BA = 1;
        Cont_StartReadInputs();
        Cont_ReadInputs();
        Input_ResetRepeatState();
    } else {
        D_861054BA = 0;
    }

    ClefairyGame_SnapshotInputs();
}

void ClefairyGame_InitCamera(void) {
    D_86105488 = D_86105484->node.children;
    MiniCam_SetActive(D_86105488);

    D_86105490 = 0x600;
    D_86105492 = 0;
    D_86105494 = 0xBB8;

    D_86105488->unk_24.near = 100.0f;
    D_86105488->unk_24.far = 12800.0f;
    D_86105488->unk_24.fovy = 30.0f;

    D_86105488->unk_60.at.x = 0.0f;
    D_86105488->unk_60.at.y = 371.2f;
    D_86105488->unk_60.at.z = -732.6f;

    D_86105488->unk_60.eye.x = 0.0f;
    D_86105488->unk_60.eye.y = 990.0f;
    D_86105488->unk_60.eye.z = 2659.0f;
}

void func_86100C28(void) {
}

void ClefairyGame_DrawOverlay(s32 arg0) {
    s32 i;
    UNUSED unk_D_86104B5C sp5C = D_86104B5C;
    UNUSED unk_D_86104B5C sp60 = D_86104B60;

    switch (arg0) {
        case 0:
            break;

        default:
            gSPDisplayList(gDisplayListHead++, D_8006F518);
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_861054A8);

            for (i = 0; i < 4; i++) {
                unk_D_86104984* ptr = &D_86104984[i];

                if (D_861054C0[i].unk_000 == 0) {
                    Widget_DrawPlayerIcon(i, ptr->unk_00, ptr->unk_02, 0.75f);
                } else {
                    Widget_DrawPlayerIcon(-1 - i, ptr->unk_00, ptr->unk_02, 0.75f);
                }
            }

            gSPDisplayList(gDisplayListHead++, D_8006F630);
            break;
    }

    if (arg0 == 0) {
        Ui_DrawBorderedPanel(0x18, 0x16, 0x110, 0x90, 0x15);
        Ui_DrawBorderedPanel(0x18, 0xA5, 0x110, 0x36, 0x14B);
    }

    Font_BeginTranslucentTextRendering();

    switch (arg0) {
        s32 sp48;
        s32 sp44;

        case 17:
            break;

        case 0:
            Font_EnableTwoCycleTexturing();
            Font_SetActive(2, 0);
            Font_SetLineHeight(0xC);
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetPrimColor(0xF9, 0xF4, 0, 0xFF);
            Font_Printf(0xA0 - (Text_MeasureStringWidth(D_861054B4, Text_GetString(NULL, 0, D_87806330, 0x1A)) / 2),
                        0x20, Text_GetString(NULL, 0, D_87806330, 0x1A));
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetPrimColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_Printf(0x28, 0x34, Text_GetString(NULL, 0, D_87806330, 0x1B));
            Font_Printf(0x28, 0x70, Text_GetString(NULL, 0, D_87806330, 0x1C));
            Gfx_SetEnvColor(0xE6, 0xD2, 0xFF, 0xFF);
            Gfx_SetPrimColor(0x82, 0x50, 0xD2, 0xFF);
            Widget_MeasureLabelBox(&sp48, &sp44, Text_GetString(NULL, 0, D_87806330, 0x1B),
                                   Text_GetString(NULL, 0, D_87806330, 0x61), 0xC);

            if (sp48 >= 0) {
                Font_Printf(sp48 + 0x28, sp44 + 0x34, Text_GetString(NULL, 0, D_87806330, 0x61));
            }

            Gfx_SetEnvColor(0xE6, 0xD2, 0xFF, 0xFF);
            Gfx_SetPrimColor(0x82, 0x50, 0xD2, 0xFF);
            Font_Printf(0x8C, 0xB0, Text_GetString(NULL, 0, D_87806330, 0x1D));
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetPrimColor(0xFF, 0x80, 0x80, 0xFF);
            Font_Printf(0xA2, 0xC8, Text_GetString(NULL, 0, D_87806330, 0x14));
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetPrimColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_Printf(0x75, 0xB0, Text_GetString(NULL, 0, D_87806330, 0x5C));
            Font_Printf(0x8B, 0xC8, Text_GetString(NULL, 0, D_87806330, 0x5C));
            Font_DisableTwoCycleTexturing();
            break;

        case 3:
            Font_SetActive(4, 0);
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_Printf(0xA4 - (Text_MeasureStringWidth(D_861054B4, Text_GetString(NULL, 0, D_87806330, 0x1E)) / 2),
                        0x40, Text_GetString(NULL, 0, D_87806330, 0x1E));
            break;

        case 5:
            Font_SetActive(4, 0);
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_Printf(0xA4 - (Text_MeasureStringWidth(D_861054B4, Text_GetString(NULL, 0, D_87806330, 0x1F)) / 2),
                        0x40, Text_GetString(NULL, 0, D_87806330, 0x1F));
            break;

        case 8:
            if (D_8610549C < 0x3C) {
                Font_SetActive(4, 0);
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
                Font_Printf(0xA4 - (Text_MeasureStringWidth(D_861054B4, Text_GetString(NULL, 0, D_87806330, 0x20)) / 2),
                            0x40, Text_GetString(NULL, 0, D_87806330, 0x20));
            }
            break;

        case 9:
        case 10:
            if (D_8610549C < 0x3C) {
                Font_SetActive(4, 0);
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
                Font_Printf(0xA4 - (Text_MeasureStringWidth(D_861054B4, Text_GetString(NULL, 0, D_87806330, 0x21)) / 2),
                            0x40, Text_GetString(NULL, 0, D_87806330, 0x21));
            }
            break;

        case 11:
            if ((D_8610549C >= 0x10) && (D_8610549C < 0x3C)) {
                Font_SetActive(4, 0);
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
                Font_Printf(0xA4 - (Text_MeasureStringWidth(D_861054B4, Text_GetString(NULL, 0, D_87806330, 0x22)) / 2),
                            0x40, Text_GetString(NULL, 0, D_87806330, 0x22));
            }
            break;
    }

    Font_EndTexturedTextRendering();

    if (arg0 == 0) {
        gSPDisplayList(gDisplayListHead++, D_8006F518);

        Widget_DrawAnimIcon24(0x56, 0xAC, D_86104A1C);
        Widget_DrawAnimIcon16C(0x74, 0xC6, D_861049F4);
        Widget_DrawSplitBanner(2, 0x19, 0xA6);
    }
}

void ClefairyGame_DrawPenaltyDots(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];

        if (D_86105BC4->unk_1AC == 0) {
            for (j = 0; j < D_86105BC4->unk_1A6; j++) {
                ClefairyGame_DrawPenaltyDot(((j % 6) * 8) + (i * 0x46) + 0x28, ((j / 6) * 8) + 0x82, 1.0f);
            }
        }
    }
}

void ClefairyGame_DrawEnteredPatterns(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];

        if (D_86105BC4->unk_1AC == 0) {
            for (j = 0; j < D_861054A0; j++) {
                s16 a = j % 6;
                s16 b = j / 6;

                ClefairyGame_DrawPatternIcon((a * 0xA) + (i * 0x46) + 0x1E, (b * 0xA) + 0x82, i, D_86105BC4->unk_174[j], 1.0f);
            }
        }
    }
}

void ClefairyGame_DrawProgressBars(s32 arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        unk_D_86104984* ptr = &D_86104984[i];

        D_86105BC4 = &D_861054C0[i];
        Widget_DrawProgressBar(ptr->unk_00 - 0xE, ptr->unk_02 - 5, 0x32, D_86105BC4->unk_1A8, D_86105BC4->unk_1AA);
    }

    if ((arg0 == 8) && (D_86105BC0 != 0)) {
        Widget_DrawProgressBar(0x78, 0x37, 0x50, D_86105BC0 - D_8610549C, D_86105BC0);
    }
}

void ClefairyGame_DrawFrame(s32 arg0) {
    ClefairyGame_PollInputs();

    switch (arg0) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
            if ((D_86107590 == 0) && (D_8780FC94 != 0)) {
                ClefairyGame_HidePatternIcons();
            }

            if ((D_86107590 != 0) && (D_8780FC94 == 0)) {
                ClefairyGame_ShowPatternIcons();
            }

            D_86107590 = D_8780FC94;
            break;
    }

    BgStage_DrawFrame();
    GfxImage_ClearDepthRectangle(&gDisplayListHead, 0, 0, 0x140, 0xF0);

    if (D_8780FC94 == 0) {
        GeoRender_AdvanceFrameCounter();
    }

    Widget_CountdownUpdate();
    Geo_RenderRootNode(D_86105484);

    gDisplayListHead = MiniCam_ApplyProjection(gDisplayListHead);

    if (D_8780FC98 == 0) {
        ClefairyGame_DrawProgressBars(arg0);

        switch (arg0) {
            case 8:
                ClefairyGame_DrawEnteredPatterns();
                break;

            case 12:
            case 13:
            case 14:
                ClefairyGame_DrawPenaltyDots();
                break;
        }

        ClefairyGame_DrawOverlay(arg0);
    }

    Widget_PauseMenuUpdate();
    BgStage_AdvanceFrame();
    D_86105496 += 1;
}

s32 ClefairyGame_WaitForStart(void) {
    s32 var_s0;
    u16 temp_v1;
    s32 i;

    StageLoader_RunFrames(0xA);
    StageFade_StartFromOpaque(0x10);

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];
        D_86105BC8 = &D_86105BC4->unk_008;
        ModelAnim_SetAnimation(D_86105BC8, 0);
        ModelAnim_ClearEventTrack(D_86105BC8);
        D_86105BC8->transformAnim.speedFixed = 0x10000;
        D_86105BC4->unk_1AA = 0x64;
        D_86105BC4->unk_1A8 = D_86105BC4->unk_1AA;
        D_86105BC4->unk_1AC = 0;
        D_86105BC4->unk_1AE = 0;
    }

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];
        if (D_8780FA30[i] == 0) {
            D_86105BC4->unk_000 = 0;
        } else {
            D_86105BC4->unk_000 = D_861054B8 + 1;
        }
    }

    D_861054A6 = 0;
    var_s0 = 1;
    D_86105498 = 0;

    while (var_s0 == 1) {
        Rand_Range(0x3E8);

        temp_v1 = gPlayer1Controller->buttonPressed;
        if (temp_v1 & 0x1000) {
            var_s0 = 0;
        }

        if ((D_8780FA2A == 0) && (temp_v1 & 0x4000) && (D_861054BA == 1)) {
            Audio_PlaySoundEffectById(SFX_MENU_BACK);
            Widget_PauseMenuTrigger(2);
            return -1;
        }

        ClefairyGame_DrawFrame(D_86105498);
    }

    return 0;
}

void ClefairyGame_UpdateStartCountdown(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];
        D_86105BC8 = &D_86105BC4->unk_008;
        if (D_86105BC4->unk_1AC == 0) {
            ModelAnim_SetAnimation(D_86105BC8, 0);
            ModelAnim_ClearEventTrack(D_86105BC8);
            D_86105BC8->transformAnim.speedFixed = 0x10000;
        }
    }

    ModelAnim_SetAnimation(&D_86105BD0, 0);
    ModelAnim_ClearEventTrack(&D_86105BD0);

    D_86105BD0.transformAnim.frameFixed = 0;
    D_86105BCC = 1;
    D_86105BCE = 0x5A;

    Widget_CountdownStart(1);
    D_86105498 = 1;

    while (D_86105BCC == 1) {
        switch (Widget_CountdownGetState()) {
            case 3:
                MiniSound_DispatchCommand(0x90001, 0, 0);
                break;

            case 1:
            case 2:
                MiniSound_DispatchCommand(0x90001, 0, 0);
                break;

            case 0:
                MiniSound_DispatchCommand(0x90001, 0, 0);
                D_86105BCC = 0;
                break;
        }

        ClefairyGame_DrawFrame(D_86105498);
    }
}

void ClefairyGame_ResetFinishedAnims(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];
        if (D_86105BC4->unk_1AC == 0) {
            D_86105BC8 = &D_86105BC4->unk_008;
            if (ModelAnim_IsFinished(D_86105BC8) != 0) {
                ModelAnim_SetAnimation(D_86105BC8, 0);
                ModelAnim_ClearEventTrack(D_86105BC8);
            }
        }
    }
}

void ClefairyGame_BeginRound(void) {
    D_86105498 = 2;
    D_8610549C = 0;
}

void ClefairyGame_BeginPatternDemo(void) {
    D_86105498 = 3;
    D_8610549C = 0;
    MiniSound_DispatchCommand(0x90005, 0, 0);
    MiniSound_DispatchCommand(0x90003, 0, 0);
    ModelAnim_SetAnimation(&D_86105BD0, 1);
    ModelAnim_ClearEventTrack(&D_86105BD0);
    D_86105BD0.transformAnim.frameFixed = 0;
    ModelAnim_SetEventTrack(&D_86105BD0, 0);
}

void ClefairyGame_BeginDemoPlayerAnims(void) {
    s32 i;
    DisplayObject* temp_s0;

    D_86105498 = 4;
    D_8610549C = 0;
    ModelAnim_SetAnimation(&D_86105BD0, 0);
    ModelAnim_ClearEventTrack(&D_86105BD0);
    D_86105BD0.transformAnim.frameFixed = 0;

    for (i = 0; i < 4; i++) {
        temp_s0 = &D_861054C0[i].unk_008;
        if (D_861054C0[i].unk_1AC == 0) {
            ModelAnim_SetAnimation(temp_s0, 2);
            ModelAnim_ClearEventTrack(temp_s0);
            temp_s0->transformAnim.speedFixed = 0x20000;
        }
    }
}

s32 ClefairyGame_WaitRoundStart(void) {
    ClefairyGame_ResetFinishedAnims();
    if ((D_8610549C >= 0x19) || (ModelAnim_IsFinished(&D_86105BD0) != 0)) {
        return -1;
    }

    D_8610549C++;
    return 0;
}

s32 ClefairyGame_WaitDemoIntro(void) {
    ClefairyGame_ResetFinishedAnims();
    if (D_8610549C >= 0xF) {
        return -1;
    }

    D_8610549C++;
    return 0;
}

s32 ClefairyGame_UpdateDemoPlayerAnims(void) {
    s32 i;
    DisplayObject* temp_s0;

    for (i = 0; i < 4; i++) {
        temp_s0 = &D_861054C0[i].unk_008;
        if ((D_861054C0[i].unk_1AC == 0) && (ModelAnim_IsFinished(temp_s0) != 0)) {
            ModelAnim_SetAnimation(temp_s0, 1);
            ModelAnim_ClearEventTrack(temp_s0);
            temp_s0->transformAnim.speedFixed = 0x10000;
        }
    }

    if (D_8610549C >= 0x19) {
        ClefairyGame_SetAllPlayerAnimSpeed(0x10000);
        return -1;
    }

    D_8610549C++;
    return 0;
}

void ClefairyGame_AdvancePatternDemo(void) {
    D_86105498 = 5;
    D_8610549C = 0;
    MiniSound_DispatchCommand(0x90006, 0, 0);
    ModelAnim_SetAnimation(&D_86105BD0, 2);
    ModelAnim_ClearEventTrack(&D_86105BD0);
    D_86105BD0.transformAnim.frameFixed = 0;
}

void ClefairyGame_PreparePatternIconSpawn(void) {
    D_86105498 = 6;
    D_8610549C = 0;
    ModelAnim_SetAnimation(&D_86105BD0, 0);
    ModelAnim_ClearEventTrack(&D_86105BD0);
    D_86105BD0.transformAnim.frameFixed = 0;
}

s32 ClefairyGame_WaitDemoAdvance(void) {
    if ((ModelAnim_IsFinished(&D_86105BD0) != 0) || (D_8610549C >= 0x1E)) {
        return -1;
    }

    D_8610549C++;
    return 0;
}

s32 ClefairyGame_SpawnPatternIconStep(void) {
    UNUSED s32 pad[2];
    unk_D_86106450* sp1C;
    s16 index;

    if (((D_861054A0 - 1) * D_861054A4) < D_8610549C) {
        D_86105498 = 7;
        D_8610549C = 0;
        return -1;
    }

    index = (D_8610549C / D_861054A4) % 12;
    sp1C = &D_86106450[index];
    if (sp1C->unk_002 == 0) {
        Model_InitDisplayObject(&sp1C->unk_004, 0, 0xB4, sp1C->unk_16C);
        sp1C->unk_002 = 1;
    }

    D_8610549C++;

    return 0;
}

s32 ClefairyGame_FinishPatternIconSpawn(void) {
    s32 i;

    if ((D_861054A0 * D_861054A4) < D_8610549C) {
        for (i = 0; i < D_861054A0; i++) {
            unk_D_86106450* ptr = &D_86106450[i];

            ModelRenderer_ClearDisplayObject(&ptr->unk_004);
            ptr->unk_002 = 0;
        }

        ModelAnim_SetAnimation(&D_86105BD0, 1);
        ModelAnim_ClearEventTrack(&D_86105BD0);
        D_86105BD0.transformAnim.frameFixed = 0;
        return -1;
    }

    D_8610549C++;
    return 0;
}

void ClefairyGame_DespawnPatternIcons(void) {
    s32 i;

    for (i = 0; i < D_861054A0; i++) {
        if (D_86106450[i].unk_002 == 1) {
            ModelRenderer_ClearDisplayObject(&D_86106450[i].unk_004);
        }
    }
}

void ClefairyGame_SpawnPatternIcons(void) {
    s32 i;

    for (i = 0; i < D_861054A0; i++) {
        if (D_86106450[i].unk_002 == 1) {
            Model_InitDisplayObject(&D_86106450[i].unk_004, 0, 0xB4, D_86106450[i].unk_16C);
        }
    }
}

s16 ClefairyGame_ChooseCpuMove(s32 arg0) {
    s16 var_v1;
    u32 temp_v0;

    if (Rand_Range(0x64) < arg0) {
        var_v1 = D_86106450[D_86105BC4->unk_18C].unk_000;
    } else {
        temp_v0 = Rand_Range(4);
        switch (temp_v0) {
            case 0:
                var_v1 = 0;
                break;

            case 1:
                var_v1 = 1;
                break;

            case 2:
                var_v1 = 2;
                break;

            case 3:
                var_v1 = 3;
                break;

            default:
                var_v1 = 3;
                break;
        }
    }
    return var_v1;
}

void ClefairyGame_BeginPatternResponse(void) {
    s32 i;
    s32 j;

    D_86105498 = 8;
    D_86105BC0 = (D_861054A0 * 0xF) + 0x1E;
    D_8610549C = 0;
    MiniSound_DispatchCommand(0x90007, 0, 0);

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];
        D_86105BC4->unk_18C = 0;

        for (j = 0; j < 12; j++) {
            D_86105BC4->unk_174[j] = 0;
            D_86105BC4->unk_18E[j] = 4;
        }
    }

    ClefairyGame_SetAllPlayerAnimSpeed(0x10000);
}

void ClefairyGame_EndPatternResponse(void) {
    D_86105498 = 9;
    D_8610549C = 0;
    ModelAnim_SetAnimation(&D_86105BD0, 1);
    ModelAnim_ClearEventTrack(&D_86105BD0);
    D_86105BD0.transformAnim.frameFixed = 0;
    MiniSound_DispatchCommand(0x90008, 0, 0);
    MiniSound_DispatchCommand(0x90003, 0, 0);
}

void ClefairyGame_StartPlaybackTransition(void) {
    s32 i;

    D_86105498 = 0xA;
    D_8610549C = 0;

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];
        if (D_86105BC4->unk_1AC == 0) {
            D_86105BC8 = &D_86105BC4->unk_008;
            ModelAnim_SetAnimation(D_86105BC8, 2);
            ModelAnim_ClearEventTrack(D_86105BC8);
            D_86105BC8->transformAnim.frameFixed = 0x200000;
            D_86105BC8->transformAnim.speedFixed = 0xFFFE0000;
        }
    }
}

s32 ClefairyGame_UpdatePatternResponse(void) {
    s16 temp_a0;
    s32 var_s0;
    s32 i;

    if (((D_861054A0 * 0xF) + 0x1E) < D_8610549C) {
        return -1;
    }

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];
        if (D_86105BC4->unk_1AC == 0) {
            temp_a0 = D_86105BC4->unk_18C;
            if (temp_a0 < D_861054A0) {
                var_s0 = 4;
                if (D_86105BC4->unk_000 == 0) {
                    if (D_86105BC4->unk_172 & 0x800) {
                        var_s0 = 0;
                    }

                    if (D_86105BC4->unk_172 & 0x400) {
                        var_s0 = 1;
                    }

                    if (D_86105BC4->unk_172 & 0x200) {
                        var_s0 = 2;
                    }

                    if (D_86105BC4->unk_172 & 0x100) {
                        var_s0 = 3;
                    }
                } else {
                    if (D_86105BC4->unk_1B0 > 0) {
                        D_86105BC4->unk_1B0--;
                    } else {
                        if (((temp_a0 > 0) && (D_86106450[temp_a0].unk_000 == D_86106450[temp_a0 - 1].unk_000)) ||
                            ((temp_a0 < 0xB) && (D_86106450[temp_a0].unk_000 == D_86106450[temp_a0 + 1].unk_000))) {
                            var_s0 = ClefairyGame_ChooseCpuMove(D_861049B4[D_86105BC4->unk_000 - 1][4]);
                        } else {
                            var_s0 = ClefairyGame_ChooseCpuMove(D_861049B4[D_86105BC4->unk_000 - 1][3]);
                        }

                        D_86105BC4->unk_1B0 = Rand_Range(0xA) + D_861049B4[D_86105BC4->unk_000 - 1][5] + 5;
                    }
                }

                D_86105BC4->unk_1AE++;

                if (var_s0 != 4) {
                    D_86105BC4->unk_18E[D_86105BC4->unk_18C] = var_s0;
                    D_86105BC4->unk_174[D_86105BC4->unk_18C] = 1;
                    D_86105BC4->unk_18C++;
                }
            }
        }
    }

    if (ModelAnim_IsFinished(&D_86105BD0) != 0) {
        ModelAnim_SetAnimation(&D_86105BD0, 0);
        ModelAnim_ClearEventTrack(&D_86105BD0);
    }

    D_8610549C++;
    return 0;
}

s32 ClefairyGame_WaitPatternResponseEnd(void) {
    if (D_8610549C >= 0x1E) {
        return -1;
    }

    D_8610549C++;
    return 0;
}

s32 ClefairyGame_WaitPlaybackTransition(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];
        D_86105BC8 = &D_86105BC4->unk_008;
        if ((D_86105BC4->unk_1AC == 0) && (D_86105BC8->transformAnim.frameFixed == 0)) {
            return -1;
        }
    }

    D_8610549C++;
    return 0;
}

void ClefairyGame_PreparePatternPlayback(void) {
    s32 i;

    D_86105498 = 0xB;
    D_8610549C = 0;

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];
        if (D_86105BC4->unk_1AC == 0) {
            D_86105BC8 = &D_86105BC4->unk_008;
            D_86105BC4->unk_18C = 0;
            ModelAnim_SetAnimation(D_86105BC8, 3);
            ModelAnim_ClearEventTrack(D_86105BC8);
            ModelAnim_SetEventTrack(D_86105BC8, 4);
            D_86105BC8->transformAnim.frameFixed = 0;
            D_86105BC8->transformAnim.speedFixed = 0x10000;
        }
    }

    ModelAnim_SetAnimation(&D_86105BD0, 3);
    ModelAnim_ClearEventTrack(&D_86105BD0);
    D_86105BD0.transformAnim.frameFixed = 0;
    ModelAnim_SetEventTrack(&D_86105BD0, 1);
}

s32 ClefairyGame_WaitPlaybackIntro(void) {
    s32 i;

    if (D_8610549C == 0x10) {
        Audio_UpdateSpecialSequence(0x1F, D_861054A6);
    }

    for (i = 0; i < 4; i++) {
        if ((D_861054C0[i].unk_1AC == 0) && (ModelAnim_IsFinished(&D_861054C0[i].unk_008) != 0)) {
            return -1;
        }
    }

    D_8610549C++;
    return 0;
}

s32 ClefairyGame_ComputeMaxRemainingHealth(void) {
    s32 var_v0;
    s32 var_v1 = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        s32 tmp = ((D_861054C0[i].unk_1A8 - (D_861054C0[i].unk_1A6 * 0x14)) / 20) + 1;

        if (tmp > 0) {
            var_v0 = D_861054C0[i].unk_1A6;
        } else {
            var_v0 = D_861054C0[i].unk_1A8 / 20;
        }

        if (var_v1 < var_v0) {
            var_v1 = var_v0;
        }
    }

    return var_v1;
}

void ClefairyGame_BeginPatternPlayback(void) {
    s32 i;

    D_86105498 = 0xC;
    D_8610549C = 0;
    ModelAnim_SetAnimation(&D_86105BD0, 4);
    ModelAnim_ClearEventTrack(&D_86105BD0);
    D_86105BD0.transformAnim.frameFixed = 0;

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];
        D_86105BC4->unk_1A6 = 0;
    }
}

s32 ClefairyGame_UpdatePatternPlayback(void) {
    s32 temp_lo;
    s32 i;

    temp_lo = D_8610549C / 17;
    if ((temp_lo + 1) == D_861054A0) {
        D_861054BC = ClefairyGame_ComputeMaxRemainingHealth();
    }

    if (temp_lo >= D_861054A0) {
        ModelAnim_SetAnimation(&D_86105BD0, 0);
        ModelAnim_ClearEventTrack(&D_86105BD0);
        D_86105BD0.transformAnim.frameFixed = 0;

        for (i = 0; i < 4; i++) {
            D_86105BC4 = &D_861054C0[i];
            if (D_86105BC4->unk_1AC == 0) {
                D_86105BC8 = &D_86105BC4->unk_008;
                ModelAnim_SetAnimation(D_86105BC8, 0);
                ModelAnim_ClearEventTrack(D_86105BC8);
                D_86105BC8->transformAnim.speedFixed = 0x10000;
            }
        }

        return -1;
    }

    if ((D_8610549C % 17) == 0) {
        for (i = 0; i < 4; i++) {
            D_86105BC4 = &D_861054C0[i];
            if (D_86105BC4->unk_1AC == 0) {
                D_86105BC8 = &D_86105BC4->unk_008;
                switch (D_86105BC4->unk_18E[temp_lo]) {
                    case 0:
                        ModelAnim_SetAnimation(D_86105BC8, 4);
                        ModelAnim_ClearEventTrack(D_86105BC8);
                        break;
                    case 1:
                        ModelAnim_SetAnimation(D_86105BC8, 5);
                        ModelAnim_ClearEventTrack(D_86105BC8);
                        break;
                    case 2:
                        ModelAnim_SetAnimation(D_86105BC8, 7);
                        ModelAnim_ClearEventTrack(D_86105BC8);
                        break;
                    case 3:
                        ModelAnim_SetAnimation(D_86105BC8, 6);
                        ModelAnim_ClearEventTrack(D_86105BC8);
                        break;
                    default:
                        ModelAnim_SetAnimation(D_86105BC8, 8);
                        ModelAnim_ClearEventTrack(D_86105BC8);
                        ModelAnim_SetEventTrack(D_86105BC8, 2);
                        break;
                }

                D_86105BC8->transformAnim.frameFixed = 0;
                D_86105BC8->transformAnim.speedFixed = 0x10000;

                if (D_86105BC4->unk_18E[temp_lo] != D_86106450[temp_lo].unk_000) {
                    D_86105BC4->unk_1A6++;
                }
            }
        }

        MiniSound_DispatchCommand(0x9000C, temp_lo + 1, 0);
    }

    D_8610549C++;
    return 0;
}

void ClefairyGame_DeductPlayerHealth(void) {
    D_86105BC4->unk_1A8 -= 0x14;
    if (D_86105BC4->unk_1A8 <= 0) {
        D_86105BC4->unk_1A8 = 0;
        ModelAnim_SetAnimation(D_86105BC8, 0xA);
        ModelAnim_ClearEventTrack(D_86105BC8);
        ModelAnim_SetEventTrack(D_86105BC8, 1);
        D_86105BC8->transformAnim.frameFixed = 0;
        D_86105BC8->transformAnim.speedFixed = 0x10000;
        D_86105BC4->unk_1AC = 1;
    }
}

void ClefairyGame_ClearLastSurvivorMistakes(void) {
    s32 i;
    s32 var_v0 = 0;
    s32 var_v1 = -1;

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];
        if (D_86105BC4->unk_1AC == 0) {
            var_v1 = i;
        } else {
            var_v0++;
        }
    }

    if (var_v0 == 3) {
        D_861054C0[var_v1].unk_1A6 = 0;
    }
}

void ClefairyGame_BeginRoundScoring(void) {
    D_86105498 = 0xD;
    D_861054A6++;
}

s32 ClefairyGame_UpdateRoundScoring(void) {
    s32 var_v1 = 0;
    DisplayObject* temp_s0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if ((D_861054C0[i].unk_1AC == 0) && (D_861054C0[i].unk_1A6 > 0)) {
            var_v1 += 1;
        }
    }

    if (var_v1 == 0) {
        return -1;
    }

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];
        D_86105BC4->unk_1B2 = 0;
        if (D_86105BC4->unk_1AC == 0) {
            D_86105BC8 = &D_86105BC4->unk_008;
            if (D_86105BC4->unk_1A6 > 0) {
                temp_s0 = &D_86105EA0[i].unk_004;
                ModelAnim_SetAnimation(temp_s0, 0);
                ModelAnim_ClearEventTrack(temp_s0);
                temp_s0->transformAnim.frameFixed = 0;
            }
        }
    }

    D_86105498 = 0xE;
    return 0;
}

s32 ClefairyGame_UpdatePenaltyPhase(void) {
    s32 var_fp;
    s32 var_s5;
    s32 var_v0;
    s32 i;

    var_fp = 0;

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];
        D_86105BC8 = &D_86105BC4->unk_008;
        if (D_86105BC4->unk_1AC == 0) {
            if ((D_86105BC4->unk_1A6 > 0) && (ModelAnim_IsFinished(&D_86105EA0[i].unk_004) == 0)) {
                var_fp++;
            }

            if ((D_86105BC4->unk_1B2 == 1) && (ModelAnim_IsFinished(&D_86105EA0[i].unk_004) != 0)) {
                D_86105BC4->unk_1B2 = 0;
                ClefairyGame_DeductPlayerHealth();
                D_86105BC4->unk_1A6--;
            }

            if (D_86105BC4->unk_1B2 == 1) {
                var_fp++;
            }

            if (ModelAnim_IsFinished(D_86105BC8) != 0) {
                ModelAnim_SetAnimation(D_86105BC8, 0);
                ModelAnim_ClearEventTrack(D_86105BC8);
                D_86105BC8->transformAnim.speedFixed = 0x10000;
            }
        }
    }

    if (var_fp > 0) {
        ClefairyGame_ClearLastSurvivorMistakes();
        var_s5 = 0;

        for (i = 0; i < 4; i++) {
            D_86105BC4 = &D_861054C0[i];
            if ((D_86105BC4->unk_1B2 == 0) && (D_86105BC4->unk_1AC == 0)) {
                D_86105BC8 = &D_86105BC4->unk_008;
                if (D_86105EA0[i].unk_004.transformAnim.frameFixed == 0xD0000) {
                    if (var_s5 == 0) {
                        MiniSound_DispatchCommand(0x90004, 0, 0);
                        var_s5 = 1;
                    }
                    ModelAnim_SetAnimation(D_86105BC8, 9);
                    ModelAnim_ClearEventTrack(D_86105BC8);
                    ModelAnim_SetEventTrack(D_86105BC8, 0);
                    D_86105BC8->transformAnim.frameFixed = 0;
                    D_86105BC8->transformAnim.speedFixed = 0x10000;
                    D_86105BC4->unk_1B2 = 1;
                }
            }
        }
    }

    var_v0 = 0;
    for (i = 0; i < 4; i++) {
        if (D_861054C0[i].unk_1AC == 1) {
            var_v0++;
        }
    }

    if (var_v0 >= 3) {
        return -1;
    }

    if (var_fp == 0) {
        D_86105498 = 0xD;
        return 0;
    }

    return 0;
}

void ClefairyGame_MainLoop(void) {
    ClefairyGame_BeginRound();
    D_861054BC = 0;

    while (true) {
        Audio_UpdateSpecialSequence(0x1E, 0);
        Audio_UpdateSpecialSequence(0x20, D_861054BC);

        if (D_8780FC94 == 0) {
            switch (D_86105498) {
                case 2:
                    if (ClefairyGame_WaitRoundStart() != 0) {
                        ClefairyGame_BeginPatternDemo();
                    }
                    break;

                case 3:
                    if (ClefairyGame_WaitDemoIntro() != 0) {
                        ClefairyGame_BeginDemoPlayerAnims();
                    }
                    break;

                case 4:
                    if (ClefairyGame_UpdateDemoPlayerAnims() != 0) {
                        ClefairyGame_AdvancePatternDemo();
                    }
                    break;

                case 5:
                    if (ClefairyGame_WaitDemoAdvance() != 0) {
                        ClefairyGame_PreparePatternIconSpawn();
                    }
                    break;

                case 6:
                    ClefairyGame_SpawnPatternIconStep();
                    break;

                case 7:
                    if (ClefairyGame_FinishPatternIconSpawn() != 0) {
                        ClefairyGame_BeginPatternResponse();
                    }
                    break;
                case 8:
                    if (ClefairyGame_UpdatePatternResponse() != 0) {
                        ClefairyGame_EndPatternResponse();
                    }
                    break;

                case 9:
                    if (ClefairyGame_WaitPatternResponseEnd() != 0) {
                        ClefairyGame_StartPlaybackTransition();
                    }
                    break;

                case 10:
                    if (ClefairyGame_WaitPlaybackTransition() != 0) {
                        ClefairyGame_PreparePatternPlayback();
                    }
                    break;

                case 11:
                    if (ClefairyGame_WaitPlaybackIntro() != 0) {
                        ClefairyGame_BeginPatternPlayback();
                    }
                    break;

                case 12:
                    if (ClefairyGame_UpdatePatternPlayback() != 0) {
                        ClefairyGame_BeginRoundScoring();
                    }
                    break;

                case 13:
                    if (ClefairyGame_UpdateRoundScoring() != 0) {
                        D_861054A0 += 2;
                        if (D_861054A0 < 0xD) {
                            ClefairyGame_BeginRound();
                            break;
                        }
                        return;
                    }
                    break;

                case 14:
                    if (ClefairyGame_UpdatePenaltyPhase() == 0) {
                        break;
                    }
                    return;
            }
        }

        if (D_8780FC92 != 0) {
            break;
        }

        ClefairyGame_DrawFrame(D_86105498);
    }
}

void ClefairyGame_ShowWinnerSequence(void) {
    s32 i;
    s32 j;

    D_86105498 = 0xF;

    while ((D_8780FC94 != 0) || (Audio_GetSpecialSequenceState() != 1)) {
        Audio_UpdateSpecialSequence(0x1E, 1);
        Audio_UpdateSpecialSequence(0x20, 0);
        ClefairyGame_DrawFrame(D_86105498);
    }

    for (i = 0; i < 2; i++) {
        ClefairyGame_DrawFrame(D_86105498);
    }

    Widget_PauseMenuTrigger(1);

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];
        D_86105BC8 = &D_86105BC4->unk_008;
        if ((i == D_861054A2) ||
            ((D_861054A2 < 0) && (D_861054AC == D_86105BC4->unk_1A8) && (D_86105BC4->unk_1A8 > 0))) {
            ModelAnim_SetAnimation(D_86105BC8, 0xB);
            ModelAnim_ClearEventTrack(D_86105BC8);
            ModelAnim_SetEventTrack(D_86105BC8, 3);
            if (D_861054C0[i].unk_000 == 0) {}
        } else {
            ModelAnim_SetAnimation(D_86105BC8, 0xA);
            ModelAnim_ClearEventTrack(D_86105BC8);
            ModelAnim_SetEventTrack(D_86105BC8, 1);
        }
    }

    if (D_861054A2 == -2) {
        MiniSound_DispatchCommand(0x9000B, 0, 0);
    } else {
        MiniSound_DispatchCommand(0x9000A, 0, 0);
    }

    if (D_861054A0 >= 0xD) {
        D_861054A0 = 0xC;
    }

    for (i = 0; i < D_861054A0; i++) {
        unk_D_86106450* ptr = &D_86106450[i];

        if (ptr->unk_002 == 0) {
            Model_InitDisplayObject(&ptr->unk_004, 0, 0xB4, ptr->unk_16C);
        }
        ptr->unk_002 = 1;
    }

    for (j = 0; j < 0x5A; j++) {
        ClefairyGame_DrawFrame(D_86105498);
    }
}

void ClefairyGame_FadeOutLoop(void) {
    s32 i;

    Audio_FadeOutAll(0x1E);
    StageFade_StartFromTransparent(0x1E);

    for (i = 0; i < 30; i++) {
        ClefairyGame_DrawFrame(D_86105498);
    }
}

void ClefairyGame_DrawIdleFrames(s32 arg0) {
    s32 i;

    D_86105498 = 0x12;

    for (i = 0; i < arg0; i++) {
        ClefairyGame_PollInputs();
        ClefairyGame_DrawFrame(D_86105498);
    }
}

void ClefairyGame_WaitForExit(void) {
    D_86105498 = 0x11;

    while (D_8780FC96 == 0) {
        if ((D_8780FA2A == 1) && (D_861054A8 > 0)) {
            D_861054A8 -= 0xA;
            if (D_861054A8 < 0) {
                D_861054A8 = 0;
            }
        }
        ClefairyGame_DrawFrame(D_86105498);
    }
}

void ClefairyGame_LoadAssets(void) {
    s32 i;
    MemoryBlock* temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);

    D_861054B8 = D_8780FA38;

    if (D_8780FA2C == 4) {
        D_861054B8 = 2;
    }

    D_86105484 = (unk_D_86002F34*)process_geo_layout(temp_v0, D_86104AA4);
    MainPool_FinalizeAllocation(temp_v0);
    ModelRenderer_InitDisplayRoots();
    PokeIcon_OpenModelArchives();
    D_861054BA = 0;
    D_861054A8 = 0xFF;
    D_86105480 = Model_LoadByArchiveIndex(0xB1);

    for (i = 0; i < 4; i++) {
        D_86105BC4 = &D_861054C0[i];

        if (i == 0) {
            D_86105BC4->unk_000 = 0;
        } else {
            D_86105BC4->unk_000 = D_861054B8 + 1;
        }

        D_86105BC4->unk_002 = i;
        D_86105BC4->unk_1B0 = Rand_Range(0xA) + 0xA;
        D_86105BC8 = &D_86105BC4->unk_008;

        ModelRenderer_AttachDisplayObject(D_86105BC8);
        Model_InitDisplayObject(D_86105BC8, 0, 0xB1, D_86105480->unk_08->unk_00[0]);

        D_86105BC8->position.x = (i - 1.5f) * 40.0f;
        D_86105BC8->position.y = 0.0f;
        D_86105BC8->position.z = 0.0f;
        D_86105BC8->scale.x = 1.0f;
        D_86105BC8->scale.y = 1.0f;
        D_86105BC8->scale.z = 1.0f;

        ModelAnim_SetAnimation(D_86105BC8, 0);
        ModelAnim_ClearEventTrack(D_86105BC8);

        D_86105BC8->transformAnim.frameFixed = 0;
        D_86105BC4->unk_1B4 = 0;
        D_86105BC4->unk_1B8 = 0.0f;
        D_86105BC4->unk_1BC = 0.0f;
    }

    D_86105480 = Model_LoadByArchiveIndex(0xB2);
    D_86105BC8 = &D_86105BD0;
    ModelRenderer_AttachDisplayObject(D_86105BC8);
    Model_InitDisplayObject(D_86105BC8, 0, 0xB2, D_86105480->unk_08->unk_00[0]);
    D_86105BC8->position.x = 0.0f;
    D_86105BC8->position.y = 10.0f;
    D_86105BC8->position.z = -145.0f;
    D_86105BC8->scale.x = 1.0f;
    D_86105BC8->scale.y = 1.0f;
    D_86105BC8->scale.z = 1.0f;
    ModelAnim_SetAnimation(D_86105BC8, 0);
    ModelAnim_ClearEventTrack(D_86105BC8);
    D_86105480 = Model_LoadByArchiveIndex(0xB3);
    D_86105BC8 = &D_86105D38;
    ModelRenderer_AttachDisplayObject(D_86105BC8);
    Model_InitDisplayObject(D_86105BC8, 0, 0xB3, D_86105480->unk_08->unk_00[0]);
    D_8610548C = Model_LoadByArchiveIndex(0xB4);

    for (i = 0; i < 12; i++) {
        D_86106450[i].unk_002 = 0;
        D_86105BC8 = &D_86106450[i].unk_004;
        ModelRenderer_AttachDisplayObject(D_86105BC8);
    }

    D_86105480 = Model_LoadByArchiveIndex(0xB5);

    for (i = 0; i < 4; i++) {
        D_86105BC8 = &D_86105EA0[i].unk_004;
        ModelRenderer_AttachDisplayObject(D_86105BC8);
        Model_InitDisplayObject(D_86105BC8, 0, 0xB5, D_86105480->unk_08->unk_00[0]);
        D_86105BC8->position.x = (i - 1.5f) * 40.0f;
        D_86105BC8->position.y = 0.0f;
        D_86105BC8->position.z = 0.0f;
        ModelAnim_SetAnimation(D_86105BC8, 0);
        ModelAnim_ClearEventTrack(D_86105BC8);
        D_86105BC8->transformAnim.frameFixed = 0x320000;
    }

    ClefairyGame_InitCamera();
    Widget_CountdownInit();
}

void ClefairyGame_PositionPatternIcons(void) {
    s32 i;
    Vec3f sp48;

    BgStage_DrawFrame();
    GeoRender_AdvanceFrameCounter();
    Geo_RenderRootNode(D_86105484);

    for (i = 0; i < 12; i++) {
        if (GeoRender_FindAnchorPosition(&D_86105D38, (s16)(i + 1), &sp48) != 0) {
            D_86105BC8 = &D_86106450[i].unk_004;
            D_86105BC8->position.x = sp48.x / 10.0f;
            D_86105BC8->position.y = sp48.y / 10.0f;
            D_86105BC8->position.z = sp48.z / 10.0f;
        }
    }

    BgStage_AdvanceFrame();
}

s32 ClefairyGame_DetermineWinner(void) {
    s32 var_s4;
    s32 var_v1;
    s32 i;
    s32* new_var = &D_861054AC;

    D_861054AC = 0;
    D_861054B0 = 0;
    var_s4 = -1;

    for (i = 0, var_v1 = 0; i < 4; i++) {
        if (D_861054C0[i].unk_1A8 >= var_v1) {
            D_861054B0 = var_v1;
            var_s4 = i;
            var_v1 = D_861054C0[i].unk_1A8;
            D_861054AC = D_861054C0[i].unk_1A8;
        }
    }

    if (var_v1 == 0) {
        return -2;
    }

    for (i = 0; i < 4; i++) {
        if (D_861054C0[i].unk_1A8 == var_v1) {
            Widget_PauseMenuRecordWin(i);
            var_v1 = *new_var;
        }
    }

    if ((var_v1 ^ 0) == D_861054B0) {
        return -1;
    }

    return var_s4;
}

void ClefairyGame_Main(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('MINI');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    D_861054B4 = Font_Init(0x36, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    FRAGMENT_LOAD(fragment31);

    Fragment_Load((((u32)D_8D000000 & 0x0FF00000) >> 0x14) - 0x10, _5C7A70_ROM_START, _5C7A70_ROM_END);

    ClefairyGame_LoadAssets();
    Widget_PauseMenuInit();
    StageContext_Activate(sp24);
    ClefairyGame_PositionPatternIcons();

    if (ClefairyGame_WaitForStart() != -1) {
        Audio_FadeOutAll(0x3C);
        ClefairyGame_DrawIdleFrames(5);
        D_861054A4 = 0xA;
        ClefairyGame_GeneratePattern();
        ClefairyGame_UpdateStartCountdown();
        D_86107590 = D_8780FC94;
        ClefairyGame_MainLoop();

        if (D_8780FC92 == 0) {
            D_861054A2 = ClefairyGame_DetermineWinner();
            ClefairyGame_ShowWinnerSequence();
            ClefairyGame_WaitForExit();
        }
    }

    ClefairyGame_FadeOutLoop();
    StageContext_Deactivate();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('MINI');

    Widget_PauseMenuGetResult();
}
