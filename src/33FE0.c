#include "global.h"
#include "33FE0.h"
#include "geo_render.h"
#include "battle_hud.h"
#include "memmap.h"

// .data
s16 D_800763B0[0x102] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4,
    5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10,
    10, 10, 11, 11, 11, 12, 12, 12, 13, 13, 13, 14, 14, 14, 15, 15,
    15, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4,
    5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10,
    10, 10, 11, 11, 11, 12, 12, 12, 13, 13, 13, 14, 14, 14, 15, 15,
    15, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4,
    5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10,
    10, 10, 11, 11, 11, 12, 12, 12, 13, 13, 13, 14, 14, 14, 15, 15,
    15, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4,
    5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10,
    10, 10, 11, 11, 11, 12, 12, 12, 13, 13, 13, 14, 14, 14, 15, 15,
    15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0,
};

s16 D_800765B4[0x102] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
    1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
    2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2,
    3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
    1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
    2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2,
    3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
    1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
    2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2,
    3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
    1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
    2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0,
};

s16 D_800767B8[0x102] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0,
};

s16 D_800769BC[0x102] = {
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0,
};

s16 D_80076BC0[0x102] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0,
};

s16 D_80076DC4[0x102] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0,
};

s16 D_80076FC8[0x102] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 0,
};

s16 D_800771CC[0x102] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0,
};

s16 D_800773D0[0x102] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0,
};

f32 D_800775D4[16] = {
    0.7f, 0.48999998f, 0.343f, 0.2401f,
    0.16806999f, 0.11764899f, 0.08235429f, 0.057648003f,
    0.0403536f, 0.02824752f, 0.019773263f, 0.013841284f,
    0.009688899f, 0.006782229f, 0.0047475602f, 0.0033232921f,
};

// Three zero words before the model tables at 0x80077620.
u32 D_80077614[3] = { 0, 0, 0 };

u32 D_80077620[40] = {
    0xFFCE00AA, 0x00000000, 0x00000000, 0xFFFF00FF, 0xFFCE0078, 0x00000000,
    0x00000200, 0xFFFF00FF, 0x00320078, 0x00000000, 0x04000200, 0xFFFF00FF,
    0x003200AA, 0x00000000, 0x04000000, 0xFFFF00FF, 0xFFCE0046, 0x00000000,
    0x00000400, 0xFFFF00FF, 0x00320046, 0x00000000, 0x04000400, 0xFFFF00FF,
    0xFFCE0014, 0x00000000, 0x00000600, 0xFFFFC0FF, 0x00320014, 0x00000000,
    0x04000600, 0xFFFFC0FF, 0xFFCEFFE2, 0x00000000, 0x00000800, 0xFFFF80FF,
    0x0032FFE2, 0x00000000, 0x04000800, 0xFFFF80FF,
};
u32 D_800776C0[6] = {
    0x00000001, 0x00020003, 0x00040005, 0x00060007, 0x00080009, 0x00000000,
};
u32 D_800776D8[12] = {
    0x0100A014, 0x0E000000, 0x06000204, 0x00000406, 0x0602080A, 0x00020A04,
    0x06080C0E, 0x00080E0A, 0x060C1012, 0x000C120E, 0xDF000000, 0x00000000,
};
u32 D_80077708[12] = {
    0x00000001, 0x00020000, 0x00020003, 0x00010004, 0x00050001, 0x00050002,
    0x00040006, 0x00070004, 0x00070005, 0x00060008, 0x00090006, 0x00090007,
};
u32 D_80077738[22] = {
    0x00010002, 0x0003FFFF, 0x00000002, 0x00040005, 0xFFFF0000, 0x00010003,
    0x0005FFFF, 0x00000002, 0xFFFF0001, 0x00050006, 0x0007FFFF, 0x00010004,
    0x00020007, 0xFFFF0004, 0x00070008, 0x0009FFFF, 0x00040006, 0x00050009,
    0xFFFF0006, 0x0009FFFF, 0x00060008, 0x0007FFFF,
};
u32 D_80077790[6] = {
    0x00CE00CB, 0x00CA00CD, 0x00980097, 0x00950094, 0x00920091, 0x00000000,
};
ModelSegment D_800777A8 = {
    0x000A, 0x0000, 0x000A, 0x0008,
    (u32) D_80077708, (u32) D_80077738, (u32) D_80077790,
    (u32) D_800776C0, (u32) D_80077620, (Gfx*) D_800776D8,
};

u32 D_800777C8[40] = {
    0xFFCE00C8, 0x00000000, 0x00000000, 0xFFFF00FF, 0xFFCE0096, 0x00000000,
    0x00000200, 0xFFFF00FF, 0x00320096, 0x00000000, 0x04000200, 0xFFFF00FF,
    0x003200C8, 0x00000000, 0x04000000, 0xFFFF00FF, 0xFFCE0064, 0x00000000,
    0x00000400, 0xFFFF00FF, 0x00320064, 0x00000000, 0x04000400, 0xFFFF00FF,
    0xFFCE0032, 0x00000000, 0x00000600, 0xFFFFC0FF, 0x00320032, 0x00000000,
    0x04000600, 0xFFFFC0FF, 0xFFCE0000, 0x00000000, 0x00000800, 0xFFFF80FF,
    0x00320000, 0x00000000, 0x04000800, 0xFFFF80FF,
};
u32 D_80077868[6] = {
    0x00000001, 0x00020003, 0x00040005, 0x00060007, 0x00080009, 0x00000000,
};
u32 D_80077880[12] = {
    0x0100A014, 0x0E000000, 0x06000204, 0x00000406, 0x0602080A, 0x00020A04,
    0x06080C0E, 0x00080E0A, 0x060C1012, 0x000C120E, 0xDF000000, 0x00000000,
};
u32 D_800778B0[12] = {
    0x00000001, 0x00020000, 0x00020003, 0x00010004, 0x00050001, 0x00050002,
    0x00040006, 0x00070004, 0x00070005, 0x00060008, 0x00090006, 0x00090007,
};
u32 D_800778E0[22] = {
    0x00010002, 0x0003FFFF, 0x00000002, 0x00040005, 0xFFFF0000, 0x00010003,
    0x0005FFFF, 0x00000002, 0xFFFF0001, 0x00050006, 0x0007FFFF, 0x00010004,
    0x00020007, 0xFFFF0004, 0x00070008, 0x0009FFFF, 0x00040006, 0x00050009,
    0xFFFF0006, 0x0009FFFF, 0x00060008, 0x0007FFFF,
};
u32 D_80077938[6] = {
    0x00CE00CB, 0x00CA00CD, 0x00980097, 0x00950094, 0x00920091, 0x00000000,
};
ModelSegment D_80077950 = {
    0x000B, 0x0000, 0x000A, 0x0008,
    (u32) D_800778B0, (u32) D_800778E0, (u32) D_80077938,
    (u32) D_80077868, (u32) D_800777C8, (Gfx*) D_80077880,
};

// .bss
Vec3fCounter* D_800B2F50;
PosBlend D_800B2F58[0x10];
Mtx D_800B3258;

s32 func_800333E0(s32 arg0) {
    u8 stack[4];
    u8* ptr = stack;

    return ((u8*)((s32)ptr + (arg0 * 0x94)) - ptr) + 0x170;
}

s32 func_80033410(s32 arg0) {
    u8 stack[4];
    u8* ptr = stack;

    return ((u8*)(s32)ptr + (arg0 * 0x10)) - ptr;
}

f32 Math_FAbs(f32 value) {
    if (value < 0.0f) {
        value = -value;
    }
    return value;
}

void Math_CrossProduct(f32 ax, f32 ay, f32 az, f32 bx, f32 by, f32 bz, f32* cx, f32* cy, f32* cz) {
    *cx = (ay * bz) - (az * by);
    *cy = (az * bx) - (ax * bz);
    *cz = (ax * by) - (ay * bx);
}

f32 func_800334C0(
    f32 px, f32 py, f32 pz,
    f32 ax, f32 ay, f32 az,
    f32 bx, f32 by, f32 bz
) {
    UNUSED s32 pad[4];
    f32 lenSq;

    lenSq = ((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay)) + ((bz - az) * (bz - az));

    if (lenSq == 0.0f) {
        return 0.0f;
    }

    return (((bx - ax) * (px - ax)) + ((by - ay) * (py - ay)) + ((bz - az) * (pz - az))) / lenSq;
}

f32 func_80033568(
    f32 px, f32 py, f32 pz,
    f32 ax, f32 ay, f32 az,
    f32 bx, f32 by, f32 bz,
    f32* outX, f32* outY, f32* outZ
) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 sp68;
    f32 t;
    f32 ex;
    f32 ey;
    f32 ez;
    f32 dx2;
    f32 pad[1];
    f32 lenSq;

    lenSq = SQ(bx - ax) + SQ(by - ay) + SQ(bz - az);
    if (lenSq == 0.0f) {
        return -1.0f;
    }
    dx = bx - ax;
    dy = by - ay;
    dz = bz - az;
    dx2 = px - ax;

    sp68 = t = ((dx * dx2) + (dy * (py - ay)) + (dz * (pz - az))) / lenSq;
    if (t < -0.5f || t > 1.5f) {
        return -2.0f;
    }
    *outX = ex = ax + (sp68 * dx);
    *outY = ey = ay + (sp68 * dy);
    *outZ = ez = az + (sp68 * dz);

    return sqrtf(SQ(ex - px) + SQ(ey - py) + SQ(ez - pz));
}

s16 Model_GetVertexClass(s16* table, s32 index) {
    s16 temp;
    s16 slot = table[index];
    
    temp = D_800769BC[slot];
    if (temp > 0) {
        return 0;
    }
    temp = D_800767B8[slot];
    if (temp > 0) {
        return 1;
    }
    temp = D_80076BC0[slot];
    if (temp > 0) {
        return 2;
    }
    temp = D_80076DC4[slot];
    if (temp > 0) {
        return 3;
    }
    temp = D_80076FC8[slot];
    if (temp > 0) {
        return 4;
    }
    temp = D_800771CC[slot];
    if (temp > 0) {
        return 5;
    }
    temp = D_800773D0[slot];
    if (temp > 0) {
        return 6;
    }
    return slot;
}

s16 Model_GetVertexThreshold(s16* arg0, s32 arg1) {
    s16 temp_v0;
    s16 temp_v1;

    temp_v0 = arg0[arg1];
    temp_v1 = D_800765B4[temp_v0];

    if (temp_v1 > 0) {
        return temp_v1;
    }

    return 0;
}

s16 Model_GetVertexJoint(s16* arg0, s32 arg1) {
    s16 temp_v1;
    s16 temp_a2;
    temp_v1 = *(arg0 + arg1);
    temp_a2 = D_800763B0[temp_v1];
    return temp_a2;
}

s16 Model_GetVertexMergeClass(s16* arg0, s32 arg1) {
    s16 temp_v1;
    s16 temp_a2;
    temp_v1 = *(arg0 + arg1);
    temp_a2 = D_800767B8[temp_v1];
    return temp_a2;
}

s16 Model_GetVertexTargetClass(s16* arg0, s32 arg1) {
    s16 temp_v1;
    s16 temp_a2;
    temp_v1 = *(arg0 + arg1);
    temp_a2 = D_80076BC0[temp_v1];
    return temp_a2;
}

s16 Model_GetVertexSourceClass(s16* arg0, s32 arg1) {
    s16 temp_v1;
    s16 temp_a2;
    temp_v1 = *(arg0 + arg1);
    temp_a2 = D_80076DC4[temp_v1];
    return temp_a2;
}

s16 Model_GetVertexMatrixClass(s16* arg0, s32 arg1) {
    s16 temp_v1;
    s16 temp_a2;
    temp_v1 = *(arg0 + arg1);
    temp_a2 = D_80076FC8[temp_v1];
    return temp_a2;
}

void func_800338B0(void) {

}

s16 Model_GetVertexHeightClass(s16* arg0, s32 arg1) {
    s16 temp_v1;
    s16 temp_a2;
    temp_v1 = *(arg0 + arg1);
    temp_a2 = D_800773D0[temp_v1];
    return temp_a2;
}

void Model_BuildVertexRuntimeData(StadiumModel* model, MtxF* mtx) {
    ModelSegment* segment;
    ModelVertex* base;
    ModelVertex* mvtx;
    Vtx* vtx;
    s16* indexTable;
    s16 temp_t0;
    s16 temp_v0_2;
    s16 var_a1;
    s16* temp_s2;
    s32 i;
    s32 var_a0;
    s32 var_s3;
    UNUSED s32 pad[8];

    segment = Memmap_GetSegmentVaddr(model->modelSegment);
    base = &model->mvtx;
    mvtx = base;
    vtx = Memmap_GetSegmentVaddr(segment->vertexSegment);

    for (var_a0 = 0; var_a0 < segment->vertexCount; var_a0++) {

        mvtx->position.base.x = (f32)vtx->v.ob[0];
        mvtx->position.base.y = (f32)vtx->v.ob[1];
        mvtx->position.base.z = (f32)vtx->v.ob[2];
        mvtx->position.color.r = (s8)vtx->v.cn[0];
        mvtx->position.color.g = (s8)vtx->v.cn[1];
        mvtx->position.color.b = (s8)vtx->v.cn[2];
        mvtx->position.texS = vtx->v.tc[0];
        mvtx->position.texT = vtx->v.tc[1];
        mvtx->position.alpha = vtx->v.cn[3];
        mvtx->position.offset.x = 0.0f;
        mvtx->position.offset.y = 0.0f;
        mvtx->position.offset.z = 0.0f;
        mvtx->position.disabled = 0;
        mvtx->position.drawGroup = 0;
        mvtx++;
        vtx++;
    }

    mvtx = base;
    Model_InitializeVertexPositions(segment, mtx, base);

    var_s3 = 0;
    i = 0;
    while (var_s3 < 0x10) {
        temp_s2 = Memmap_GetSegmentVaddr(segment->tableSegment);
        for (i = 0; i < segment->vertexCount; i++) {
            u16 temp_v0 = Model_GetVertexJoint(temp_s2, i);
            if (var_s3 == temp_v0) {
                mvtx->jointIndex = i;
                mvtx++;
            }
        }
        var_s3++;
    }

    mvtx = base;
    var_a1 = 0;
    indexTable = Memmap_GetSegmentVaddr(segment->unk_0C);
    for (i = 0; i < segment->vertexCount; i++) {
        mvtx->childIndex = var_a1;
        do {
            temp_v0_2 = *indexTable++;
            var_a1++;
        } while (temp_v0_2 != -1);
        mvtx++;
    }

    mvtx = base;
    for (i = 0; i < segment->vertexCount; i++) {
        ModelVertex* temp_v0 = &base[mvtx->jointIndex];
        mvtx->parentIndex = temp_v0->childIndex;
        mvtx++;
    }
}

void func_80033B2C(StadiumModel* model, void* arg1,  void* arg2, void* arg3) {
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    MtxF* temp_s0;
    ModelSegment* segment;
    ModelSegment* temp_v0;

    model = Memmap_GetSegmentVaddr(model);
    arg1 = Memmap_GetSegmentVaddr(arg1);
    temp_s0 = Memmap_GetSegmentVaddr(arg2);
    temp_v0 = Memmap_GetSegmentVaddr(arg3);
    segment = &model->unkSegment;
    D_800B2F50 = arg1;
    *segment = *temp_v0;
    model->unk_00 = 1;
    model->unk_02 = 0;
    model->modelSegment = segment;
    sp40 = temp_s0->xx;
    sp3C = temp_s0->yx;
    sp38 = temp_s0->zx;
    sp34 = temp_s0->xy;
    sp30 = temp_s0->yy;
    sp2C = temp_s0->zy;
    sp28 = temp_s0->xz;
    sp24 = temp_s0->yz;
    sp20 = temp_s0->zz;
    sp4C = sqrtf((sp40 * sp40) + (sp3C * sp3C) + (sp38 * sp38));
    sp48 = sqrtf((sp34 * sp34) + (sp30 * sp30) + (sp2C * sp2C));
    sp44 = sqrtf((sp28 * sp28) + (sp24 * sp24) + (sp20 * sp20));
    if (sp4C == 0.0f) {
        sp4C = 1.0f;
    }
    if (sp48 == 0.0f) {
        sp48 = 1.0f;
    }
    if (sp44 == 0.0f) {
        sp44 = 1.0f;
    }
    model->position.x = sp4C;
    model->position.y = sp48;
    model->position.z = sp44;
    guScale(&D_800B3258, 0.1f, 0.1f, 0.1f);
    Model_BuildVertexRuntimeData(model, temp_s0);
    func_800357F4(model);
}

void func_80033D1C(StadiumModel* model, MtxF* mtx) {
    Model_BuildVertexRuntimeData(model, mtx);
    func_800357F4(model);
}

#ifdef NON_MATCHING
void func_80033D44(StadiumModel* model, s16 maxDist, f32 radius, f32 ax, f32 ay, f32 az, f32 bx, f32 by, f32 bz, MtxF* mtx) {
    ModelSegment* segment;
    f32 cx, cy, cz;
    f32 dx, dy, dz;
    f32 tax, tay, taz;
    f32 tbx, tby, tbz;
    f32 tcx, tcy, tcz;
    f32 tdx, tdy, tdz;
    f32 x, y, z;
    f32 nx, ny, nz;
    f32 dir[3];
    ModelVertex* mvtx;
    f32 up[3];
    f32 px, py, pz;
    f32 dist;
    f32 len;
    ModelBlendWeight* w;
    f32 vx, vy, vz;
    StadiumTransform* t;
    s16 index;
    s32 i;

    segment = (ModelSegment*) Memmap_GetSegmentVaddr(model->modelSegment);
    index = model->unk_02++;

    vx = bx - ax;
    vy = by - ay;
    vz = bz - az;
    len = sqrtf((vx * vx) + (vy * vy) + (vz * vz));
    if (len != 0.0f) {
        dir[0] = vz / len;
        dir[2] = vx / len;
        up[0] = up[1] = 0;
        up[2] = -1.0f;
        x = vy / len;
        dist = Math_FAbs((dir[2] * -1.0f) + ((x * up[1]) + (up[1] * dir[0])));
        vx = up[1];
        vz = up[0];
        if (0.9f < dist) {
            vx = 1.0f;
            up[2] = 0.0f;
            vz = 0.0f;
            if (0.9f < Math_FAbs(x)) {
                vz = 1.0f;
                vx = 0.0f;
            }
        }
        Math_CrossProduct(dir[2], x, dir[0], up[2], vx, vz, &px, &py, &pz);
        cx = ax + px;
        cy = ay + py;
        cz = az + pz;
        Math_CrossProduct(dir[2], x, dir[0], px, py, pz, &px, &py, &pz);
        dx = ax + px;
        dy = ay + py;
        dz = az + pz;

        t = &model->transforms[index];
        t->unk_00 = maxDist;
        t->maxDist = radius;
        t->x0 = ax;
        t->y0 = ay;
        t->z0 = az;
        t->x1 = bx;
        t->y1 = by;
        t->z1 = bz;
        t->x2 = cx;
        t->y2 = cy;
        t->z2 = cz;
        t->x3 = dx;
        t->y3 = dy;
        t->z3 = dz;
        t->mtx = mtx;

        guMtxXFMF(mtx->mf, ax, ay, az, &tax, &tay, &taz);
        guMtxXFMF(mtx->mf, bx, by, bz, &tbx, &tby, &tbz);
        guMtxXFMF(mtx->mf, cx, cy, cz, &tcx, &tcy, &tcz);
        guMtxXFMF(mtx->mf, dx, dy, dz, &tdx, &tdy, &tdz);

        mvtx = &model->mvtx;
        for (i = 0; i < segment->vertexCount; i++) {
            x = mvtx->position.base.x;
            y = mvtx->position.base.y;
            z = mvtx->position.base.z;
            dist = func_80033568(x, y, z, tax, tay, taz, tbx, tby, tbz, &nx, &ny, &nz);
            if (dist > 0.0f) {
                x = (((x - nx) * radius) / dist) + nx;
                y = (((y - ny) * radius) / dist) + ny;
                z = (((z - nz) * radius) / dist) + nz;
            }
            w = &mvtx->cmd.weights[index];
            w->w0 = func_800334C0(x, y, z, tax, tay, taz, tbx, tby, tbz);
            w->w1 = func_800334C0(x, y, z, tax, tay, taz, tcx, tcy, tcz);
            w->w2 = func_800334C0(x, y, z, tax, tay, taz, tdx, tdy, tdz);
            w->dist = dist;
            mvtx++;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80033D44.s")
#endif

void func_80034254(StadiumModel* model) {
    u32 pad[2];
    ModelSegment* segment;
    s16* indexTable;
    f32 var_fv0;
    s16 temp_v1;
    s32 j;
    s32 i;
    ModelVertex* temp_a1;
    ModelVertex* var_a2;
    ModelBlendWeight* var_a0;

    segment = Memmap_GetSegmentVaddr(model->modelSegment);
    indexTable = Memmap_GetSegmentVaddr(segment->remapSegment);
    temp_a1 = &model->mvtx;
    var_a2 = temp_a1;
    for(i = 0; i < segment->vertexCount; i++) {
        var_a2->position.nextIndex = -1;
        var_a2++;
    }
    var_a2 = temp_a1;
    for (i = 0; i < segment->vertexCount; i++) {
        temp_v1 = indexTable[i];
        if (temp_v1 == i) {
            var_fv0 = 10000.0f;
            for (j = 0; j < model->unk_02; j++) {
                var_a0 = &var_a2->cmd.weights[j];
                if (var_a0->dist < var_fv0) {
                    var_fv0 = var_a0->dist;
                    var_a2->position.nextIndex = j;
                }
            }
        }
        var_a2++;
    }
}

void func_80034348(ModelSegment* segment, ModelVertex* vertices) {
    s32 i;
    f32 x0, y0, z0;
    f32 x1, y1, z1;
    f32 x2, y2, z2;
    f32 nx, ny, nz;
    f32 len;
    s16 i0, i1, i2;
    f32 scale;
    s16* indices;
    s16 triangleCount;
    s16 vertexCount;
    ModelVertex* v0;
    ModelVertex* v1;
    ModelVertex* v2;
    ModelVertex* vtx;
    Vec3fCounter* counter;
    UNUSED s32 pad[4];
    s16* remap;
    UNUSED s32 pad2[5];

    triangleCount = segment->triangleCount;
    vertexCount = segment->vertexCount;
    indices = Memmap_GetSegmentVaddr(segment->indexSegment);
    remap = Memmap_GetSegmentVaddr(segment->remapSegment);
    counter = D_800B2F50;
    for (i = 0; i < vertexCount; i++) {
        counter->x = 0.0f;
        counter->y = 0.0f;
        counter->z = 0.0f;
        counter->count = 0;
        counter++;
    }
    for (i = 0; i < triangleCount; i++) {
        i0 = remap[indices[0]];
        v0 = &vertices[i0];
        x0 = v0->position.base.x;
        y0 = v0->position.base.y;
        z0 = v0->position.base.z;
        i1 = remap[indices[1]];
        v1 = &vertices[i1];
        x1 = v1->position.base.x;
        y1 = v1->position.base.y;
        z1 = v1->position.base.z;
        i2 = remap[indices[2]];
        v2 = &vertices[i2];
        x2 = v2->position.base.x;
        y2 = v2->position.base.y;
        z2 = v2->position.base.z;
        indices += 3;
        nx = ((y1 - y0) * (z2 - z1)) - ((z1 - z0) * (y2 - y1));
        ny = ((z1 - z0) * (x2 - x1)) - ((x1 - x0) * (z2 - z1));
        nz = ((x1 - x0) * (y2 - y1)) - ((y1 - y0) * (x2 - x1));
        len = sqrtf((nx * nx) + (ny * ny) + (nz * nz));
        if ((s32) len > 0) {
            scale = 120.0f / len;
            nx *= scale;
            ny *= scale;
            nz *= scale;
        }
        counter = &D_800B2F50[i0];
        counter->x += nx;
        counter->y += ny;
        counter->z += nz;
        counter->count++;
        counter = &D_800B2F50[i1];
        counter->x += nx;
        counter->y += ny;
        counter->z += nz;
        counter->count++;
        counter = &D_800B2F50[i2];
        counter->x += nx;
        counter->y += ny;
        counter->z += nz;
        counter->count++;
    }
    counter = D_800B2F50;
    vtx = vertices;
    for (i = 0; i < vertexCount; i++) {
        if (counter->count > 0) {
            len = counter->count;
            vtx->position.color.r = counter->x / len;
            vtx->position.color.g = counter->y / len;
            vtx->position.color.b = counter->z / len;
        }
        counter++;
        vtx++;
    }
}

void func_80034824(ModelSegment* segment, StadiumTransform* xf, s32 index, ModelVertex* vertices) {
    f32 x0, y0, z0;
    f32 x1, y1, z1;
    f32 x2, y2, z2;
    MtxF* mtx;
    s32 pad0[4];
    f32 sp184, sp180, sp17C;
    f32 sp178, sp174, sp170;
    f32 sp16C, sp168, sp164;
    f32 sp160, sp15C, sp158;
    f32 sp154, sp150, sp14C;
    f32 sp148, sp144, sp140;
    f32 sp13C, sp138, sp134;
    f32 sp130, sp12C, sp128;
    f32 w0, w1, w2;
    f32 bx, by, bz;
    s32 pad1[27];
    s16* spA0;
    s16 temp_s6;
    s16* temp_v0;
    s32 i;
    s32 temp_s0;
    ModelVertex* var_s1;
    PosBlend* temp_v0_2;

    temp_s6 = segment->vertexCount;
    spA0 = Memmap_GetSegmentVaddr(segment->remapSegment);
    temp_v0 = Memmap_GetSegmentVaddr(segment->tableSegment);
    x0 = xf->x0;
    y0 = xf->y0;
    z0 = xf->z0;
    x1 = xf->x1;
    y1 = xf->y1;
    z1 = xf->z1;
    x2 = xf->x2;
    y2 = xf->y2;
    z2 = xf->z2;
    sp184 = xf->x3;
    sp180 = xf->y3;
    sp17C = xf->z3;
    mtx = xf->mtx;

    guMtxXFMF(mtx->mf, x0, y0, z0, &sp178, &sp174, &sp170);
    guMtxXFMF(mtx->mf, x1, y1, z1, &sp16C, &sp168, &sp164);
    guMtxXFMF(mtx->mf, x2, y2, z2, &sp160, &sp15C, &sp158);
    guMtxXFMF(mtx->mf, sp184, sp180, sp17C, &sp154, &sp150, &sp14C);
    sp148 = sp16C - sp178;
    sp144 = sp168 - sp174;
    sp140 = sp164 - sp170;
    sp13C = sp160 - sp178;
    sp138 = sp15C - sp174;
    sp134 = sp158 - sp170;
    sp130 = sp154 - sp178;
    sp12C = sp150 - sp174;
    sp128 = sp14C - sp170;
    var_s1 = vertices;
    for (i = 0; i < temp_s6; i++) {
        temp_s0 = spA0[i];
        if (Model_GetVertexClass(temp_v0, temp_s0) != 0) {
            temp_v0_2 = &var_s1->position;
            if (temp_s0 == i) {
                if (index == temp_v0_2->nextIndex) {
                    w0 = var_s1->cmd.weights[index].w0;
                    w1 = var_s1->cmd.weights[index].w1;
                    w2 = var_s1->cmd.weights[index].w2;
                    x1 = (w0 * sp148) + sp178 + (w1 * sp13C) + (w2 * sp130);
                    y1 = (w0 * sp144) + sp174 + (w1 * sp138) + (w2 * sp12C);
                    bx = temp_v0_2->base.x;
                    by = temp_v0_2->base.y;
                    bz = temp_v0_2->base.z;
                    z1 = (w0 * sp140) + sp170 + (w1 * sp134) + (w2 * sp128);
                    temp_v0_2->disabled |= (1 << index);
                    temp_v0_2->offset.x = x1 - bx;
                    temp_v0_2->offset.y = y1 - by;
                    temp_v0_2->offset.z = z1 - bz;
                }
            }
        }
        var_s1++;
    }
}

void Model_ApplyVertexTransforms(StadiumModel* model) {
    ModelSegment* segment;
    s32 count;
    s32 i;
    ModelVertex* mvtx;

    segment = Memmap_GetSegmentVaddr(model->modelSegment);
    mvtx = &model->mvtx;
    count = model->unk_02;

    for (i = 0; i < count; i++) {
        func_80034824(segment, &model->transforms[i], i, mvtx);
    }

    func_80035FA8(segment, mvtx);
    Model_ApplyTransformCommands(segment, mvtx, model, 1.0f);
}

void func_80034BD4(u32 modelSegment, StadiumTransform* xf, s32 index, ModelVertex* vertices) {
    ModelBlendWeight* wt;
    ModelVertex* vtx;
    s32 pad0[3];
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    s32 pad1[10];
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 one = 1.0f;
    f32 w0;
    f32 w1;
    f32 w2;
    f32 x;
    f32 y;
    f32 z;
    f32 temp_fv0;
    s32 pad2[4];
    s16 spCA;
    s32 pad3[1];
    s16* spC0;
    MtxF* mtx;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    s16 temp_s1_2;
    s16* temp_s1;
    ModelSegment* temp_v0;
    s32 temp_s1_3;
    s32 i;
    PosBlend* temp_v0_2;

    temp_v0 = Memmap_GetSegmentVaddr(modelSegment);
    spCA = temp_v0->vertexCount;
    temp_s1 = Memmap_GetSegmentVaddr(temp_v0->remapSegment);
    spC0 = Memmap_GetSegmentVaddr(temp_v0->tableSegment);
    mtx = xf->mtx;
    guMtxXFMF(mtx->mf, xf->x0, xf->y0, xf->z0, &sp180, &sp17C, &sp178);
    guMtxXFMF(mtx->mf, xf->x1, xf->y1, xf->z1, &sp174, &sp170, &sp16C);
    guMtxXFMF(mtx->mf, xf->x2, xf->y2, xf->z2, &sp168, &sp164, &sp160);
    guMtxXFMF(mtx->mf, xf->x3, xf->y3, xf->z3, &sp15C, &sp158, &sp154);
    sp150 = sp174 - sp180;
    sp14C = sp170 - sp17C;
    sp148 = sp16C - sp178;
    sp144 = sp168 - sp180;
    sp140 = sp164 - sp17C;
    sp13C = sp160 - sp178;
    sp138 = sp15C - sp180;
    sp134 = sp158 - sp17C;
    sp130 = sp154 - sp178;
    vtx = vertices;
    for (i = 0; i < spCA; i++) {
        temp_s1_2 = temp_s1[i];
        if ((Model_GetVertexClass(spC0, temp_s1_2) != 0) && (temp_s1_2 == i)) {
            temp_fs0 = vtx->position.base.x;
            temp_fs1 = vtx->position.base.y;
            temp_fs2 = vtx->position.base.z;
            temp_s1_3 = 1 << index;
            temp_fv0 = func_80033568(temp_fs0, temp_fs1, temp_fs2, sp180, sp17C, sp178, sp174, sp170, sp16C, &sp104, &sp100, &spFC);
            temp_v0_2 = &vtx->position;
            if ((temp_fv0 > 0.0f) && (temp_fv0 < xf->maxDist)) {
                wt = &vtx->cmd.weights[index];
                w0 = wt->w0;
                w1 = wt->w1;
                w2 = wt->w2;
                x = (w0 * sp150) + sp180 + (w1 * sp144) + (w2 * sp138);
                y = (w0 * sp14C) + sp17C + (w1 * sp140) + (w2 * sp134);
                z = (w0 * sp148) + sp178 + (w1 * sp13C) + (w2 * sp130);
                temp_v0_2->disabled |= temp_s1_3;
                temp_v0_2->offset.x = (x - temp_fs0) * one;
                temp_v0_2->offset.y = (y - temp_fs1) * one;
                temp_v0_2->offset.z = (z - temp_fs2) * one;
            } else {
                temp_v0_2->disabled &= ~temp_s1_3;
            }
        }
        vtx++;
    }
}

void Model_TransformPoint(MtxF* mtx, Vec3f* out, s16 (*in)[3]) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;

    sp34 = (f32) (*in)[0];
    sp30 = (f32) (*in)[1];
    sp2C = (f32) (*in)[2];

    guMtxXFMF(mtx->mf, sp34, sp30, sp2C, &sp34, &sp30, &sp2C);

    out->x = sp34;
    out->y = sp30;
    out->z = sp2C;
}

void Model_AccumulateVertexOffset(MtxF* mtx, PosBlend* position, s16 (*target)[3], f32 alpha) {
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 dx;
    f32 dy;
    f32 dz;

    sp44 = (f32) (*target)[0];
    sp40 = (f32) (*target)[1];
    sp3C = (f32) (*target)[2];

    guMtxXFMF(mtx->mf, sp44, sp40, sp3C, &sp44, &sp40, &sp3C);

    dx = sp44 - position->base.x;
    dy = sp40 - position->base.y;
    dz = sp3C - position->base.z;

    dx *= alpha;
    dy *= alpha;
    dz *= alpha;

    position->offset.x += dx;
    position->offset.y += dy;
    position->offset.z += dz;
}

void Model_InitializeVertexPositions(ModelSegment* segment, MtxF* mtx, ModelVertex* mvtx) {
    s16* indexTable;
    s32 i;
    Vtx* vtx;
    PosBlend* position;
    ModelVertex* tmp;

    indexTable = Memmap_GetSegmentVaddr(segment->tableSegment);
    vtx = Memmap_GetSegmentVaddr(segment->vertexSegment);
    Memmap_GetSegmentVaddr(segment->remapSegment);
    tmp = mvtx;
    
    for(i = 0; i < segment->vertexCount; i++) {
        position = &tmp->position;
        switch (Model_GetVertexClass(indexTable, i)) {
            case 0:
            default:
                Model_TransformPoint(mtx, &position->base, &vtx->v.ob);
                position->offset.x = 0.0f;
                position->offset.y = 0.0f;
                position->offset.z = 0.0f;
                break;
            case 4:
                Model_TransformPoint(mtx + Model_GetVertexMatrixClass(indexTable, i), &position->base, &vtx->v.ob);
                position->offset.x = 0.0f;
                position->offset.y = 0.0f;
                position->offset.z = 0.0f;
                break;
        }
        vtx++;
        tmp++;
    }
}

void Model_CopyPositionBuffer(PosBlend* src, PosBlend* dst) {
    *dst = *src;
}

void func_80035208_empty() {

}

void func_80035248(ModelSegment* segment, MtxF* mtx, ModelVertex* mvtx) {
    ModelVertex* tmp;
    Vtx* vtx;
    PosBlend* position;
    s16* var_s7;
    s32 i;
    s16* temp_s5;
    temp_s5 = Memmap_GetSegmentVaddr(segment->tableSegment);
    vtx = Memmap_GetSegmentVaddr(segment->vertexSegment);
    var_s7 = Memmap_GetSegmentVaddr(segment->remapSegment);
    tmp = mvtx;

    for(i = 0; i < segment->vertexCount; i++) {
        position = &tmp->position;
        if (i == *var_s7) {
            switch (Model_GetVertexClass(temp_s5, i)) {
            case 0:
                Model_TransformPoint(mtx, &position->base, &vtx->v.ob);
                break;
            case 4:
                Model_TransformPoint(mtx + Model_GetVertexMatrixClass(temp_s5, i), &position->base, &vtx->v.ob);
                break;
            case 1:
                Model_AccumulateVertexOffset(mtx, position, &vtx->v.ob, D_800775D4[Model_GetVertexMergeClass(temp_s5, i)]);
                break;
            case 2:
                Model_TransformPoint(mtx, &position->base, &vtx->v.ob);
                Model_CopyPositionBuffer(position, &D_800B2F58[Model_GetVertexTargetClass(temp_s5, i)]);
                break;
            case 3:
                Model_TransformPoint(mtx, &position->base, &vtx->v.ob);
                Model_CopyPositionBuffer(position, &D_800B2F58[Model_GetVertexSourceClass(temp_s5, i)]);
                break;
            default:
                break;
            }
        }
        vtx++;
        var_s7++;
        tmp++;
    }
}
f32 Model_ComputeScaledDistance(Vec3f* a, Vec3f* b, Vec3f* scale) {
    f32 dx;
    f32 dy;
    f32 dz;

    dx = (a->x - b->x) / scale->x;
    dy = (a->y - b->y) / scale->y;
    dz = (a->z - b->z) / scale->z;

    if (Math_FAbs(dx) < 10e-05f) {
        dx = 0.0f;
    }
    if (Math_FAbs(dy) < 10e-05f) {
        dy = 0.0f;
    }
    if (Math_FAbs(dz) < 10e-05f) {
        dz = 0.0f;
    }
    return sqrtf((dx * dx) + (dy * dy) + (dz * dz));
}

f32 Model_ComputeDistance(s16 (*a)[3], s16 (*b)[3]) {
    f32 dx;
    f32 dy;
    f32 dz;

    dx = (f32) ((*a)[0] - (*b)[0]);
    dy = (f32) ((*a)[1] - (*b)[1]);
    dz = (f32) ((*a)[2] - (*b)[2]);
    return sqrtf((dx * dx) + (dy * dy) + (dz * dz));
}

void Model_ExtrapolateVertexPosition(Vec3f* from, Vec3f* to, f32 currentTime, f32 deltaTime, f32 scale) {
    s32 pad;
    f32 temp_fv0;
    f32 temp_fa1;
    f32 temp_ft5;

    if (deltaTime < 10e-05f) {
        return;
    }

    temp_fv0 = to->x - from->x;
    temp_fa1 = to->y - from->y;
    temp_ft5 = to->z - from->z;

    scale *= (currentTime - deltaTime) / deltaTime;
    if (deltaTime < currentTime) {
        scale /= 2.0f;
    }

    to->x += temp_fv0 * scale;
    to->y += temp_fa1 * scale;
    to->z += temp_ft5 * scale;
}

void func_80035660(PosBlend* src, PosBlend* dst, f32 totalTime, f32 elapsed, f32 stiffness) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 var_fv0;

    if (!(elapsed < 10e-05f)) {
        if (Math_FAbs(dst->base.x) < 10e-05f) {
            dst->base.x = 0.0f;
        }
        if (Math_FAbs(dst->base.y) < 10e-05f) {
            dst->base.y = 0.0f;
        }
        if (Math_FAbs(dst->base.z) < 10e-05f) {
            dst->base.z = 0.0f;
        }
        sp3C = dst->base.x - src->base.x;
        sp38 = dst->base.y - src->base.y;
        sp34 = dst->base.z - src->base.z;
        stiffness *= ((totalTime - elapsed) / elapsed);
        if (elapsed < totalTime) {
            stiffness /= 2.0f;
        }
        dst->base.x += sp3C * stiffness;
        dst->base.y += sp38 * stiffness;
        dst->base.z += sp34 * stiffness;
        dst->offset.x += sp3C * stiffness;
        dst->offset.y += sp38 * stiffness;
        dst->offset.z += sp34 * stiffness;
    }
}

void func_800357F4(StadiumModel* model) {
    s32 i;
    s32 pad1[4];
    s16* sp70;
    s32 pad2[1];
    s16* sp68;
    s32 pad3[7];
    ModelVertex* sp48;
    f32 temp_fv0;
    ModelSegment* sp40;
    s16 temp_s0;
    s16 temp_s1;
    s16 temp_s1_2;
    s16 temp_s2;
    s16 temp_s4;
    s16 temp_s4_2;
    s16 temp_s5;
    s16 temp_v0_2;
    s16* var_s6;
    s32 temp_t4;
    s32 temp_t7;
    Vtx* temp_fp;
    s16* temp_s3;
    ModelSegment* segment;
    ModelTransformCmd* cmd;
    ModelVertex* mvtx;

    segment = Memmap_GetSegmentVaddr(model->modelSegment);
    sp40 = segment;
    temp_s3 = Memmap_GetSegmentVaddr(segment->tableSegment);
    sp70 = Memmap_GetSegmentVaddr(sp40->remapSegment);
    temp_fp = Memmap_GetSegmentVaddr(sp40->vertexSegment);
    sp68 = Memmap_GetSegmentVaddr(sp40->unk_0C);
    mvtx = &model->mvtx;
    sp48 = mvtx;
    for (i = 0; i < sp40->vertexCount; i++) {
        temp_s2 = sp48->jointIndex;
        var_s6 = &sp68[sp48->parentIndex];
        while (1) {
            temp_v0_2 = *var_s6;
            var_s6++;
            if (temp_v0_2 == -1) {
                break;
            }
            temp_s0 = *(&sp70[temp_v0_2]);
            temp_s4 = Model_GetVertexJoint(temp_s3, temp_s2);
            temp_s5 = Model_GetVertexJoint(temp_s3, temp_s0);
            temp_s1 = Model_GetVertexThreshold(temp_s3, temp_s2);
            temp_t7 = Model_GetVertexThreshold(temp_s3, temp_s0) << 0x10;
            if ((temp_s4 < temp_s5) && (temp_s1 == (temp_t7 >> 0x10)) && (temp_s1 > 0)) {
                temp_s1_2 = Model_GetVertexClass(temp_s3, temp_s2);
                temp_s4_2 = Model_GetVertexClass(temp_s3, temp_s0);
                temp_fv0 = Model_ComputeDistance(&temp_fp[temp_s2].v.ob, &temp_fp[temp_s0].v.ob);
                cmd = &mvtx->cmd;
                mvtx++;
                cmd->targetIndex = temp_s2;
                cmd->sourceIndex = temp_s0;
                cmd->enableFrom = temp_s1_2;
                cmd->enableTo = temp_s4_2;
                cmd->blendWeight = temp_fv0;
            }
        }
        sp48++;
    }
    mvtx->cmd.targetIndex = -1;
    mvtx->cmd.sourceIndex = -1;
    mvtx->cmd.blendWeight = -1.0f;
}

void Model_ApplyTransformCommands(ModelSegment* segment, ModelVertex* vertices, StadiumModel* model, f32 deltaTime) {
    f32 temp_fs0;
    f32 temp_fv0;
    s16 temp_v1;
    s16 var_a0;
    s16 var_a1;
    s16 var_a2;
    ModelTransformCmd* temp_v0;
    ModelVertex* temp_a3;
    Vec3f* temp_s0;
    Vec3f* temp_s1;
    ModelVertex* temp_v0_2;
    ModelVertex* var_s2;

    Memmap_GetSegmentVaddr(segment->remapSegment);
    var_s2 = vertices;

    while (1) {
        temp_v0 = &var_s2->cmd;
        var_s2++;
        temp_v1 = temp_v0->targetIndex;
        if (temp_v1 == -1) {
            break;
        }
    
        var_a1 = temp_v0->sourceIndex;
        var_a2 = temp_v0->enableFrom;
        var_a0 = temp_v0->enableTo;
        temp_fs0 = temp_v0->blendWeight;
        temp_a3 = &vertices[temp_v1];
    
        if (temp_a3->position.disabled != 0) {
            var_a2 = 0;
        }
    
        temp_v0_2 = &vertices[var_a1];
        if (temp_v0_2->position.disabled != 0) {
            var_a0 = 0;
        }
    
        if ((var_a0 != 0) || (var_a2 != 0)) {
            temp_fv0 = Model_ComputeScaledDistance(&temp_a3->position.base, &temp_v0_2->position.base, &model->position);
            Model_ExtrapolateVertexPosition(&temp_a3->position.base, &temp_v0_2->position.base, temp_fs0, temp_fv0, deltaTime);
        }
        
    }
}

void func_80035B20(ModelSegment* segment, ModelVertex* vertices, StadiumModel* model, f32 deltaTime) {
    f32 temp_fs0;
    s16 temp_v1;
    s16 var_a0;
    s16 var_a1;
    s16 var_a2;
    ModelVertex* temp_a3;
    PosBlend* temp_s0;
    PosBlend* temp_s1;
    ModelTransformCmd* temp_v0;
    ModelVertex* temp_v0_2;
    ModelVertex* var_s2;

    Memmap_GetSegmentVaddr(segment->tableSegment);
    Memmap_GetSegmentVaddr(segment->remapSegment);
    var_s2 = vertices;
    while (1) {
        temp_v0 = &var_s2->cmd;
        var_s2++;
        temp_v1 = temp_v0->targetIndex;
        if (temp_v1 != -1) {
            var_a1 = temp_v0->sourceIndex;
            var_a2 = temp_v0->enableFrom;
            var_a0 = temp_v0->enableTo;
            temp_fs0 = temp_v0->blendWeight;
            temp_a3 = &vertices[temp_v1];
            if (temp_a3->position.disabled != 0) {
                var_a2 = 0;
            }
            temp_v0_2 = &vertices[var_a1];
            if (temp_v0_2->position.disabled != 0) {
                var_a0 = 0;
            }
            if ((var_a0 != 0) || (var_a2 != 0)) {
                temp_s0 = &temp_a3->position;
                temp_s1 = &temp_v0_2->position;
                func_80035660(temp_s0, temp_s1, temp_fs0, Model_ComputeScaledDistance(&temp_s0->base, &temp_s1->base, &model->position), deltaTime);
            }
            continue;
        }
        break;
    }
}

void Model_OffsetVertexHeights(ModelSegment* segment, ModelVertex* vertices, f32 yOffset) {
    s16* indexTable;
    s16* remap;
    s32 i;
    ModelVertex* tmp;

    indexTable = Memmap_GetSegmentVaddr(segment->tableSegment);
    remap = Memmap_GetSegmentVaddr(segment->remapSegment);
    tmp = vertices;
    for(i = 0; i < segment->vertexCount; i++) {
        if ((Model_GetVertexClass(indexTable, i) != 0) && (i == *remap)) {
            tmp->position.base.y += yOffset;
        }
        tmp++;
        remap++;
    }
}

void func_80035D08(ModelSegment* segment, ModelVertex* vertices, f32 yOffset) {
    s16* indexTable;
    s16* var_s2;
    s32 temp_v0;
    ModelVertex* tmp;
    s32 i;
    PosBlend* temp_v0_2;

    indexTable = Memmap_GetSegmentVaddr(segment->tableSegment);
    var_s2 = Memmap_GetSegmentVaddr(segment->remapSegment);
    tmp = vertices;
    for(i = 0; i < segment->vertexCount; i++) {
        if ((Model_GetVertexClass(indexTable, i) != 0) && (i == *var_s2)) {
            temp_v0 = Model_GetVertexHeightClass(indexTable, i);
            temp_v0_2 = &tmp->position;
            switch (temp_v0) {
            case 1:
                temp_v0_2->base.y += yOffset;
                break;
            case 2:
                temp_v0_2->base.y += yOffset * 0.25f;
                break;
            }
        }
        tmp++;
        var_s2++;
    }
}

void func_80035E2C(ModelSegment* segment, ModelVertex* vertices, f32 arg2, StadiumModel* arg3) {
    s16* indexTable;
    s16* remap;
    s32 type;
    ModelVertex* vertex;
    s32 i;
    PosBlend* position;
    f32 zero = 0.0f;
    f32 one = 1.0f;
    f32 quarter = 0.25f;

    indexTable = Memmap_GetSegmentVaddr(segment->tableSegment);
    remap = Memmap_GetSegmentVaddr(segment->remapSegment);
    vertex = vertices;
    for (i = 0; i < segment->vertexCount; i++) {
        if ((Model_GetVertexClass(indexTable, i) != 0) && (i == *remap)) {
            type = Model_GetVertexHeightClass(indexTable, i);
            position = &vertex->position;
            switch (type) {
            case 1:
                position->base.x += zero;
                position->base.y += arg2 * one;
                position->base.z += zero;
                break;
            case 2:
                position->base.x = position->base.x + zero;
                position->base.y = position->base.y + (quarter * arg2 * one);
                position->base.z = position->base.z + zero;
                break;
            }
        }
        vertex++;
        remap++;
    }
}

void func_80035FA8(ModelSegment* segment, ModelVertex* vertices) {
    f32 drawGroup;
    s16* indexTable;
    s16* remap;
    s32 i;
    PosBlend* position;
    ModelVertex* vertex;

    vertex = vertices;
    indexTable = Memmap_GetSegmentVaddr(segment->tableSegment);
    remap = Memmap_GetSegmentVaddr(segment->remapSegment);
    for (i = 0; i < segment->vertexCount; i++) {
        position = &vertex->position;
        if ((Model_GetVertexClass(indexTable, i) != 0) && (i == *remap)) {
            if (Math_FAbs(position->offset.x) < 9.999999747e-05f) {
                position->offset.x = 0.0f;
            }
            if (Math_FAbs(position->offset.y) < 9.999999747e-05f) {
                position->offset.y = 0.0f;
            }
            if (Math_FAbs(position->offset.z) < 9.999999747e-05f) {
                position->offset.z = 0.0f;
            }
            if ((s32)position->drawGroup > 0) {
                drawGroup = (f32)position->drawGroup;
                position->base.x = position->base.x + (position->offset.x / drawGroup);
                position->base.y = position->base.y + (position->offset.y / drawGroup);
                position->base.z = position->base.z + (position->offset.z / drawGroup);
                position->offset.x = position->offset.x - (0.3f * position->offset.x);
                position->offset.y = position->offset.y - (0.3f * position->offset.y);
                position->offset.z = position->offset.z - (0.3f * position->offset.z);
            } else {
                position->base.x = position->base.x + position->offset.x;
                position->base.y = position->base.y + position->offset.y;
                position->base.z = position->base.z + position->offset.z;
                position->offset.x = position->offset.x - (0.3f * position->offset.x);
                position->offset.y = position->offset.y - (0.3f * position->offset.y);
                position->offset.z = position->offset.z - (0.3f * position->offset.z);
            }
        }
        position->drawGroup = 0;
        vertex++;
        remap++;
    }
}

void func_800361C4(StadiumModel* model, MtxF* mtx) {
    s32 var_s0;
    s32 var_v1;

    ModelVertex* mvtx = &model->mvtx;
    ModelSegment* segment = Memmap_GetSegmentVaddr(model->modelSegment);
    switch (segment->type) {
    case 3:
        func_80035248(segment, mtx, mvtx);
        Model_OffsetVertexHeights(segment, mvtx, model->position.y * -10.0f);
        func_80034348(segment, mvtx);
        for(var_s0 = 0; var_s0 < model->unk_02; var_s0++) {
            func_80034BD4(segment, &model->transforms[var_s0], var_s0, mvtx);
        }
        func_80035FA8(segment, mvtx);
        Model_ApplyTransformCommands(segment, mvtx, model, 0.7f);        
        break;
    case 4:
        func_80035248(segment, mtx, mvtx);
        Model_OffsetVertexHeights(segment, mvtx, model->position.y * -10.0f);
        func_80034348(segment, mvtx);
        func_80035FA8(segment, mvtx);
        break;
    case 10:
        func_80035248(segment, mtx, mvtx);
        func_80035D08(segment, mvtx, model->position.y * 160.0f);
        func_80035FA8(segment, mvtx);
        func_80035B20(segment, mvtx, model, 1.0f);
        break;
    case 11:
        func_80035248(segment, mtx, mvtx);
        func_80035E2C(segment, mvtx, 160.0f, model);
        func_80035FA8(segment, mvtx);
        func_80035B20(segment, mvtx, model, 1.0f);
        break;
    case 1:
        func_80035248(segment, mtx, mvtx);
        func_80034348(segment, mvtx);
        func_80035FA8(segment, mvtx);
        break;
    case 2:
        func_80035248(segment, mtx, mvtx);
        Model_OffsetVertexHeights(segment, mvtx, model->position.y * -10.0f);
        func_80034348(segment, mvtx);
        func_80035FA8(segment, mvtx);
        break;
    case 5:
        func_80035248(segment, mtx, mvtx);
        func_80034348(segment, mvtx);
        func_80035FA8(segment, mvtx);
        break;
    case 6:
        func_80035248(segment, mtx, mvtx);
        func_80034348(segment, mvtx);
        func_80035FA8(segment, mvtx);
        break;
    case 9:
        func_80035248(segment, mtx, mvtx);
        Model_ApplyVertexTransforms(model);
        func_80034348(segment, mvtx);
        break;
    default:
        return;
    }
    {
        s16* var_a0 = Memmap_GetSegmentVaddr(segment->remapSegment);
        for(var_v1 = 0; var_v1 < segment->vertexCount; var_v1++) {
            s16 segment_2 = *var_a0;
            if (segment_2 != var_v1) {
                 *(PosBlend*)&(var_v1 + mvtx)->position = *(PosBlend*)&mvtx[segment_2].position;
            }
            var_a0++;
        }
    }
}

void Model_WriteVtxBuffer(StadiumModel* model, Vtx* vtxBuf) {
    ModelSegment* segment;
    ModelVertex* mvtx;
    Vtx* vtx;
    s32 i;

    segment = Memmap_GetSegmentVaddr(model->modelSegment);
    if ((s32) segment->type >= 0xC) {
        return;
    }
    mvtx = &model->mvtx;
    vtx = vtxBuf;
    for(i = 0; i < segment->vertexCount; i++) {
        vtx->v.ob[0] = (s16)(mvtx->position.base.x * 10.0f);
        vtx->v.ob[1] = (s16)(mvtx->position.base.y * 10.0f);
        vtx->v.ob[2] = (s16)(mvtx->position.base.z * 10.0f);
        vtx->v.cn[0] = (s16)mvtx->position.color.r;
        vtx->v.cn[1] = (s16)mvtx->position.color.g;
        vtx->v.cn[2] = (s16)mvtx->position.color.b;
        vtx->v.tc[0] = mvtx->position.texS;
        vtx->v.tc[1] = mvtx->position.texT;
        vtx->v.cn[3] = mvtx->position.alpha;
        vtx++;
        mvtx++;
    }
}

Gfx* Model_Draw(Gfx* gfx, StadiumModel* model, Vtx* vtxBuf) {
    ModelSegment* segment;

    segment = Memmap_GetSegmentVaddr(model->modelSegment);
    if ((s32) segment->type >= 0xC) {
        return gfx;
    }
    Model_WriteVtxBuffer(model, vtxBuf);
    gSPSegment(gfx++, 0x0E, vtxBuf);
    gSPMatrix(gfx++, &D_800B3258, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPDisplayList(gfx++, segment->displayList);
    gSPPopMatrixN(gfx++, G_MTX_MODELVIEW, 1);
    return gfx;
}
