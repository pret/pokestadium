#include "fragment10.h"
#include "src/12D80.h"
#include "src/17300.h"
#include "src/18140.h"
#include "src/18480.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/4BDC0.h"
#include "src/4CBC0.h"
#include "src/50860.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/E890.h"
#include "src/fragments/2/fragment2.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "src/controller.h"

typedef struct unk_D_864027C0 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
} unk_D_864027C0; // size = 0x20

static unk_D_864027C0 D_864027C0[] = {
    { -68.0f, 0.0f, 68.0f, 1.0f, 1.0f, 1.0f, 0, 0x5E80, 0 },
    { -68.0f, 0.0f, -68.0f, 1.0f, 1.0f, 1.0f, 0, 0x1F80, 0 },
    { 68.0f, 0.0f, -68.0f, 1.0f, 1.0f, 1.0f, 0, -0x2380, 0 },
    { 68.0f, 0.0f, 68.0f, 1.0f, 1.0f, 1.0f, 0, 0x9D80, 0 },
};

static u16 D_86402840 = 0;
static u16 D_86402844 = 0;

u8 D_86402848 = 0;

static u8 D_8640284C[][8] = {
    { 0x12, 0x13, 0x14, 0x15, 0x3A, 0x3B, 0x3C, 0x3D }, { 0x10, 0x11, 0x12, 0x13, 0x34, 0x35, 0x36, 0x37 },
    { 0x0E, 0x0F, 0x10, 0x11, 0x2E, 0x2F, 0x30, 0x31 }, { 0x0D, 0x0E, 0x0F, 0x10, 0x2B, 0x2C, 0x2D, 0x2E },
    { 0x0C, 0x0D, 0x0E, 0x0F, 0x28, 0x29, 0x2A, 0x2B }, { 0x0B, 0x0C, 0x0D, 0x0E, 0x25, 0x26, 0x27, 0x28 },
    { 0x0A, 0x0B, 0x0C, 0x0D, 0x22, 0x23, 0x24, 0x25 }, { 0x09, 0x0A, 0x0B, 0x0C, 0x1F, 0x20, 0x21, 0x22 },
    { 0x08, 0x09, 0x0A, 0x0B, 0x1C, 0x1D, 0x1E, 0x1F }, { 0x07, 0x08, 0x09, 0x0A, 0x19, 0x1A, 0x1B, 0x1C },
    { 0x06, 0x07, 0x08, 0x09, 0x16, 0x17, 0x18, 0x19 }, { 0x05, 0x06, 0x07, 0x08, 0x13, 0x14, 0x15, 0x16 },
    { 0x04, 0x05, 0x06, 0x07, 0x10, 0x11, 0x12, 0x13 }, { 0x03, 0x04, 0x05, 0x06, 0x0D, 0x0E, 0x0F, 0x10 },
};

static unk_func_87801684 D_864028BC[] = {
    { 0x0303ED80, 14 }, { 0x0303F180, 2 }, { 0x0303F580, 6 }, { 0x0303F180, 2 }, { NULL, 0 },
};

static unk_func_87801684 D_864028E4[] = {
    { 0x03040580, 18 }, { 0x03040980, 2 }, { 0x03040D80, 8 }, { 0x03040980, 2 }, { NULL, 0 },
};

static u32 D_8640290C[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E, 0x00000000, 0x014000F0, 0x0000000F, 0x00000000, 0x00000000, 0x05000000,
    0x0D000000, 0x05000000, 0x14000000, 0x002B0012, 0xFFFFFF32, 0x16FFFFFF, 0x0F000003, 0x05000000, 0x1F00FFFF,
    0x00000000, 0x00000000, 0x00000000, 0x00640064, 0x00640000, 0x06000000, 0x05000000, 0x0A000000, 0x800AC840,
    0x06000000, 0x06000000, 0x06000000, 0x03000000, 0x87806398, 0x06000000, 0x01000000,
};

static unk_D_86002F58_004_000 D_86404070;

static unk_D_86002F58_004_000 D_864041D8[4];

static unk_D_86404778 D_86404778[4];

static unk_D_86405158 D_86405158;

static unk_D_86404778* D_864052C8;
static unk_D_86405158* D_864052CC;
static unk_D_86002F58_004_000* D_864052D0;
static u8 D_864052D4;
static s16 D_864052D6;

void func_86400020(void) {
    u8 i;

    for (i = 0; i < 4; i++) {
        D_864052C8 = &D_86404778[i];

        if (D_864052C8->unk_000 == 4) {
            continue;
        }

        D_864052C8->unk_008 =
            D_8640284C[D_864052CC->unk_000][2] + func_864026D0(D_864052CC->unk_000, D_864052C8->unk_000);
        D_864052C8->unk_00A =
            D_8640284C[D_864052CC->unk_000][6] + func_864026D0(D_864052CC->unk_000, D_864052C8->unk_000);
    }
}

u16 func_86400128(u8 arg0) {
    if ((D_864052D6 == D_86404778[arg0].unk_008) || (D_864052D6 == D_86404778[arg0].unk_00A)) {
        return 1;
    }
    return 0;
}

void func_86400184(unk_D_86404778* arg0, s32 arg1, u8 arg2, s32 arg3, u8 arg4) {
    arg0->unk_018 = arg1;
    arg0->unk_01C = arg2;
    arg0->unk_020 = arg3;
    arg0->unk_024 = arg4;
}

void func_864001A0(void) {
    s8 i;

    for (i = 0; i < 4; i++) {
        if (D_8780FA30[i] == 0) {
            D_86404778[i].unk_000 = 4;
        } else {
            D_86404778[i].unk_000 = D_8780FA38;
        }
    }
}

void func_86400220(void) {
    if (func_80017514(&D_86404070) != 0) {
        func_80017464(&D_86404070, 0);
    }
}

void func_86400258(unk_D_86405158* arg0) {
    static u8 D_86402994 = 0;
    static u8 D_86402998[] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x08, 0x08, 0x09,
        0x09, 0x09, 0x0A, 0x0A, 0x0A, 0x0B, 0x0B, 0x0B, 0x0C, 0x0C, 0x0C, 0x0D,
    };

    if (func_80017514(&arg0->unk_004) != 0) {
        arg0->unk_001 = arg0->unk_000;

        if (arg0->unk_000 != 0xD) {
            D_86402994++;
            arg0->unk_000 = D_86402998[D_86402994];
        }

        if (arg0->unk_001 != arg0->unk_000) {
            func_8001BD04(&arg0->unk_004, arg0->unk_000);
        } else {
            func_80017464(&arg0->unk_004, 0);
        }

        func_86400020();
    }
}

void func_864002F8(void) {
    u8 i;
    f32 temp_fv0;
    f32 var_fv1;
    s8 temp_ft2;
    s32 temp_s1;

    if (D_8780FC94 == 0) {
        for (i = 0; i < 4; i++) {
            D_864052C8 = &D_86404778[i];

            if ((func_80017514(&D_864052C8->unk_028) != 0) ||
                ((D_864052C8->unk_010 == 0) && (D_864052C8->unk_012 > 0)) ||
                ((D_87B000C8 != 0) && (D_864052C8->unk_00C == 1) && (D_86402840 == 0x3C) && (D_87B000D4 == 1))) {
                temp_s1 = D_864052C8->unk_004;

                if ((D_87B000C8 != 0) && (D_864052C8->unk_00C == 1) &&
                    ((D_86402840 == 0x3C) || (D_864052C8->unk_004 == 6))) {
                    D_864052C8->unk_004 = 6;
                } else {
                    temp_fv0 = (D_864052C8->unk_010 * 100.0f) / D_864052C8->unk_00E;
                    if (temp_fv0 > 0.0f) {
                        var_fv1 = 0.5f;
                    } else {
                        var_fv1 = -0.5f;
                    }
                    temp_ft2 = var_fv1 + temp_fv0;

                    if (temp_ft2 >= 0x51) {
                        D_864052C8->unk_004 = 0;
                    } else if (temp_ft2 >= 0x3D) {
                        D_864052C8->unk_004 = 1;
                    } else if (temp_ft2 >= 0x29) {
                        D_864052C8->unk_004 = 2;
                    } else if (temp_ft2 >= 0x15) {
                        D_864052C8->unk_004 = 3;
                    } else if (D_864052C8->unk_010 != 0) {
                        D_864052C8->unk_004 = 4;
                    } else {
                        D_864052C8->unk_004 = 5;
                    }
                }

                if (temp_s1 != D_864052C8->unk_004) {
                    func_8001BD04(&D_864052C8->unk_028, D_864052C8->unk_004);
                    if (D_864052C8->unk_004 != 0) {
                        func_8001BD9C(&D_864052C8->unk_028, D_864052C8->unk_004);
                    }
                } else if (D_864052C8->unk_004 == 5) {
                    func_80017464(&D_864052C8->unk_028, 0x18);
                    func_80017804(&D_864052C8->unk_028, 0x18);
                } else if (D_864052C8->unk_004 == 6) {
                    func_80017464(&D_864052C8->unk_028, 0x77);
                    func_80017804(&D_864052C8->unk_028, 0x77);
                } else {
                    func_80017464(&D_864052C8->unk_028, 0);
                    if (D_864052C8->unk_004 != 0) {
                        func_80017804(&D_864052C8->unk_028, 0);
                    }
                }
            }
        }
    }
}

void func_864005EC(u8 arg0) {
    u8 i;
    u8 sp40[] = {
        0,
        0,
        0,
        0,
    };
    static s8 D_864029B4 = 4;

    sp40[arg0] = 1;

    for (i = 0; i < 4; i++) {
        if (i != arg0) {
            D_864052C8 = &D_86404778[i];

            if ((D_864052C8->unk_010 <= 0) && (D_864052C8->unk_012 > 0)) {
                D_864029B4--;
                sp40[i] = 1;
            }
        }
    }

    for (i = 0; i < 4; i++) {
        D_864052C8 = &D_86404778[i];

        if (sp40[i] != 0) {
            D_864052C8->unk_00C = D_864029B4;
            func_86400184(D_864052C8, 0, 0, 0, 0);
        }
    }

    D_864029B4--;
    if (D_864029B4 < 2) {
        D_864052CC->unk_004.unk_04C = 0;
        D_87B000C8 = 1;

        func_8004B9C4(0xA);

        for (i = 0; i < 4; i++) {
            D_864052C8 = &D_86404778[i];

            if (D_864052C8->unk_00C == 0) {
                D_864052C8->unk_00C = 1;
                func_86400184(D_864052C8, 0, 0, 0, 0);
            }
        }

        D_87B000D4 = 0;

        for (i = 0; i < 4; i++) {
            if (D_86404778[i].unk_00C == 1) {
                D_87B000D4++;
            }
        }

        if (D_87B000D4 == 1) {
            for (i = 0; i < 4; i++) {
                if (D_86404778[i].unk_00C == 1) {
                    func_87802F00(i);
                    break;
                }
            }
        }
    }
}

void func_86400860(UNUSED s32 arg0) {
    u8 i;
    f32 temp_fs0;
    s16 temp_a3;
    Gfx* temp_v0;

    temp_fs0 = 0.1f;

    for (i = 0; i < 4; i++) {
        D_864052C8 = &D_86404778[i];

        temp_v0 = func_80005F5C(0x80);
        D_864052C8->unk_190->unk_18 = temp_v0;

        if ((D_864052C8->unk_010 == 0) || (D_864052C8->unk_00C == 1)) {
            temp_a3 = D_864052C8->unk_028.unk_048 >> 0x10;

            gSPDisplayList(temp_v0++, D_86403F30);
            gDPSetTileSize(temp_v0++, G_TX_RENDERTILE, 0x0000, (0x40 - (D_87B000C0 % 64)) << 2, 0x007C,
                           ((0x80 - (D_87B000C0 % 64)) & 0x3F) << 2);
            gSPDisplayList(temp_v0++, D_86403FA0);

            if ((D_864052C8->unk_004 == 5) && (temp_a3 >= 0x18)) {
                if (D_864052C8->unk_015 == 0) {
                    D_864052C8->unk_015 = 1;
                    if ((D_8780FC92 == 0) && (D_8780FC94 == 0)) {
                        func_8004D9B0(0x70005, i + 1, 0);
                    }
                }
                D_864052C8->unk_190->unk_28 = temp_fs0;
            } else if ((D_864052C8->unk_00C == 1) && (D_864052C8->unk_004 == 6) && (temp_a3 >= 0x77)) {
                if (D_864052C8->unk_015 == 0) {
                    D_864052C8->unk_015 = 1;
                    if ((D_8780FC92 == 0) && (D_8780FC94 == 0)) {
                        func_8004D9B0(0x70006, i + 1, 0);
                    }
                }
                D_864052C8->unk_190->unk_28 = temp_fs0;
            } else {
                D_864052C8->unk_190->unk_28 = 0.0f;
            }
        } else {
            gSPDisplayList(temp_v0++, D_86403BB0);

            if (D_864052C8->unk_018 == 2) {
                switch (D_864052C8->unk_01C) {
                    default:
                        D_864052C8->unk_190->unk_28 = 0.5f;
                        break;

                    case 20:
                        D_864052C8->unk_190->unk_28 = temp_fs0;
                        if ((D_8780FC92 == 0) && (D_8780FC94 == 0)) {
                            func_8004D9B0(0x70004, i + 1, 0);
                        }
                        break;

                    case 19:
                        D_864052C8->unk_190->unk_28 = 0.2f;
                        break;

                    case 18:
                        D_864052C8->unk_190->unk_28 = 0.3f;
                        break;
                }
            } else {
                D_864052C8->unk_190->unk_28 = 0.0f;
            }
        }

        gSPEndDisplayList(temp_v0++);

        D_864052C8->unk_190->unk_1C = D_864052C8->unk_028.unk_0AC;
    }
}

void func_86400BE8(s32 arg0) {
    s32 temp;
    s16 sp24[] = {
        0xFB1E,
        0xFED4,
        0x0120,
        0x04B0,
    };
    u8 i;

    func_878025D0();

    if (D_8780FC94 == 0) {
        if (arg0 == 2) {
            static u8 D_864029C0 = 0;

            D_864052D6 = D_864052CC->unk_004.unk_048 >> 0x10;
            D_864052D4 = 0;

            for (i = 0; i < 8; i++) {
                temp = D_864052D6;
                if (temp == D_8640284C[D_864052CC->unk_000][i]) {
                    D_864052D4 = 1;
                    break;
                }
            }

            D_86402848 = 0;

            if (D_87B000C8 == 0) {
                for (i = 0; i < 8; i++) {
                    temp = D_864052D6;
                    if ((temp + 1) == D_8640284C[D_864052CC->unk_000][i]) {
                        D_86402848 = 1;
                        break;
                    }
                }
            }

            for (i = 0; i < 4; i++) {
                D_864052C8 = &D_86404778[i];

                D_864052C8->unk_012 = D_864052C8->unk_010;

                if ((D_87B000C8 != 0) && (D_864052C8->unk_00C == 1) && (D_86402840 >= 0x3C) && (D_87B000D4 == 1) &&
                    (D_864029C0 < 0x10)) {
                    D_864052C8->unk_028.unk_01E.y += sp24[i];
                }
            }

            if (D_87B000C8 != 0) {
                if (D_86402840 < 0x3C) {
                    D_86402840++;
                } else {
                    if (D_86402840 < 0x6A) {
                        if (D_86402840 == 0x69) {
                            D_87B000CC = 1;
                            func_87802EB8(1);
                        }
                        D_86402840++;
                    }

                    if (D_864029C0 < 0x10) {
                        D_864029C0++;
                    }
                }
            }
        }

        if (D_87B000C8 != 0) {
            static f32 D_864029C4 = 1.0f;

            D_864029C4 -= 0.06f;
            if (D_864029C4 < 0.0f) {
                D_864029C4 = 0.0f;
            }

            D_86405158.unk_004.unk_030.x = D_86405158.unk_004.unk_030.y = D_86405158.unk_004.unk_030.z = D_864029C4;
        }
    }
}

void func_86400EB4(void) {
    static u8 D_864029C8 = 0;

    u8 i;
    u8 j;
    s32 var_a2;
    UNUSED s32 pad;

    if ((D_8780FC92 == 0) && (D_8780FC94 == 0)) {
        D_864052CC->unk_16D = D_864052CC->unk_16C;
        if (D_864052D6 < (D_864052CC->unk_004.unk_044->unk_0A / 2)) {
            D_864052CC->unk_16C = 0;
        } else {
            D_864052CC->unk_16C = 1;
        }

        if (D_864052CC->unk_16C != D_864052CC->unk_16D) {
            func_8004D9B0(0x70003, 1 - D_864052CC->unk_16C, 0);

            for (i = 0; i < 4; i++) {
                D_864052C8 = &D_86404778[i];

                if ((D_864052C8->unk_274 == 0) && (D_864052C8->unk_010 > 0)) {
                    if (D_864052CC->unk_16D != 0) {
                        D_864052C8->unk_194[D_864052CC->unk_001][7]++;
                    } else {
                        D_864052C8->unk_194[D_864052CC->unk_000][7]++;
                    }
                } else {
                    D_864052C8->unk_274 = 0;
                }
            }
        }

        for (i = 0; i < 4; i++) {
            D_864052C8 = &D_86404778[i];

            if (D_864052C8->unk_012 != 0) {
                if (D_864052C8->unk_01C >= 2) {
                    D_864052C8->unk_01C--;
                } else {
                    func_86400184(D_864052C8, D_864052C8->unk_020, D_864052C8->unk_024, 0, 0);
                }

                if (D_864052C8->unk_000 == 4) {
                    D_86402844 = gControllers[i].buttonPressed & 0x8000;
                } else {
                    D_86402844 = func_86400128(i);
                }

                if (D_86402844 != 0) {
                    if (D_864052D4 != 0) {
                        if (D_864052C8->unk_014 == 0) {
                            if (D_864029C8 == 0) {
                                func_8004D9B0(0x70009, 0, 0);
                                D_864029C8 = 1;
                            }

                            D_864052C8->unk_014 = 1;
                            func_80017464(&D_864041D8[i], 0);

                            for (j = 0; j < 4; j++) {
                                if (i != j) {
                                    D_86404778[j].unk_010 -= 2;
                                }
                            }

                            if (D_864052C8->unk_018 == 0) {
                                func_86400184(D_864052C8, 1, 0x14, 0, 0);
                            } else {
                                func_86400184(D_864052C8, 0, 1, 1, 0x14);
                            }
                        }
                    } else {
                        D_864052C8->unk_010 -= 1;
                        if (D_864052C8->unk_018 == 0) {
                            func_86400184(D_864052C8, 2, 0x14, 0, 0);
                        } else {
                            func_86400184(D_864052C8, 0, 1, 2, 0x14);
                        }
                    }

                    D_864052C8->unk_274 = 1;
                    if (D_864052CC->unk_16C == 0) {
                        var_a2 = 2;
                    } else {
                        var_a2 = 6;
                    }

                    if ((D_8640284C[D_864052CC->unk_000][var_a2] - 3) >= D_864052D6) {
                        D_864052C8->unk_194[D_864052CC->unk_000][0]++;
                    } else if ((D_864052D6 + 2) == D_8640284C[D_864052CC->unk_000][var_a2]) {
                        D_864052C8->unk_194[D_864052CC->unk_000][1]++;
                    } else if ((D_864052D6 + 1) == D_8640284C[D_864052CC->unk_000][var_a2]) {
                        D_864052C8->unk_194[D_864052CC->unk_000][2]++;
                    } else if (D_864052D6 == D_8640284C[D_864052CC->unk_000][var_a2]) {
                        D_864052C8->unk_194[D_864052CC->unk_000][3]++;
                    } else if (D_864052D6 == (D_8640284C[D_864052CC->unk_000][var_a2] + 1)) {
                        D_864052C8->unk_194[D_864052CC->unk_000][4]++;
                    } else if (D_864052D6 == (D_8640284C[D_864052CC->unk_000][var_a2] + 2)) {
                        D_864052C8->unk_194[D_864052CC->unk_000][5]++;
                    } else if (D_864052D6 >= (D_8640284C[D_864052CC->unk_000][var_a2] + 3)) {
                        D_864052C8->unk_194[D_864052CC->unk_000][6]++;
                    }
                }

                if ((D_864052D6 == D_8640284C[D_864052CC->unk_000][3]) ||
                    (D_864052D6 == D_8640284C[D_864052CC->unk_000][7])) {
                    if (D_864052C8->unk_014 == 0) {
                        D_864052C8->unk_010--;
                        if (D_864052C8->unk_018 == 0) {
                            func_86400184(D_864052C8, 2, 0x14, 0, 0);
                        } else {
                            func_86400184(D_864052C8, 0, 1, 2, 0x14);
                        }
                    } else {
                        D_864052C8->unk_014 = 0;
                    }
                }
            }
        }

        if ((D_864052D6 == D_8640284C[D_864052CC->unk_000][3]) || (D_864052D6 == D_8640284C[D_864052CC->unk_000][7])) {
            D_864029C8 = 0;
        }

        for (i = 0; i < 4; i++) {
            D_864052C8 = &D_86404778[i];

            if (D_864052C8->unk_010 <= 0) {
                D_864052C8->unk_010 = 0;
                if ((D_864052C8->unk_012 > 0) && (D_864052C8->unk_00C == 0)) {
                    func_864005EC(i);
                }
            }
        }
    }
}

void func_86401544(s32 arg0) {
    if ((arg0 == 0) || ((arg0 == 3) && (D_87B000D0 == 1))) {
        func_80020460(0x18, 0x16, 0x110, 0x90, 0x15);
        func_80020460(0x18, 0xA5, 0x110, 0x36, 0x14B);

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        func_87801F48(2, 0x19, 0xA6);
        func_87801684(0x74, 0xB0, D_864028BC);
        func_87801824(0x74, 0xC6, D_864028E4);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

    } else if ((arg0 == 1) || (arg0 == 2) || ((arg0 == 3) && (D_87B000D0 == 0))) {
        u8 i;
        s16 sp74[] = {
            0x0025,
            0x003D,
            0x00E5,
            0x00FD,
        };
        s16 sp6C[] = {
            0x00BA,
            0x0034,
            0x0034,
            0x00BA,
        };

        gSPDisplayList(gDisplayListHead++, D_8006F518);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

        for (i = 0; i < 4; i++) {
            if (D_86404778[i].unk_000 == 4) {
                func_87801644(i, sp74[i], sp6C[i], 0.75f);
            } else {
                func_87801644(-1 - i, sp74[i], sp6C[i], 0.75f);
            }
        }

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    }

    func_8001F3F4();
    func_8001F470();

    if ((arg0 == 0) || ((arg0 == 3) && (D_87B000D0 == 1))) {
        char* temp_s2 = func_8002D7C0(NULL, 0, D_87806330, 0x29);
        s32 sp58;
        s32 sp54;
        s32 temp_s0;

        func_8001EBE0(2, 0);
        func_8001F3B4(0xC);
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F36C(0xF9, 0xF4, 0, 0xFF);
        func_8001F1E8(0xA0 - (func_878013D4(D_87B000E0, func_8002D7C0(NULL, 0, D_87806330, 0x28)) / 2), 0x20,
                      func_8002D7C0(NULL, 0, D_87806330, 0x28));
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F36C(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F1E8(0x28, 0x34, temp_s2);

        temp_s0 = ((func_8002D80C(temp_s2) * 0xC) + 0xC);
        func_8001F1E8(0x28, temp_s0 + 0x34, func_8002D7C0(NULL, 0, D_87806330, 0x2A));
        func_8001F1E8(0x8B, 0xB2, func_8002D7C0(NULL, 0, D_87806330, 0x5C));
        func_8001F1E8(0x8B, 0xC8, func_8002D7C0(NULL, 0, D_87806330, 0x5C));
        func_8001F324(0xC8, 0xC8, 0xFF, 0xFF);
        func_8001F36C(0x50, 0x50, 0xFF, 0xFF);
        func_87801290(&sp58, &sp54, temp_s2, func_8002D7C0(NULL, 0, D_87806330, 0x5F), 0xC);
        func_8001F1E8(sp58 + 0x28, sp54 + 0x34, func_8002D7C0(NULL, 0, D_87806330, 0x5F));
        func_8001F324(0xC8, 0xC8, 0xFF, 0xFF);
        func_8001F36C(0x50, 0x50, 0xFF, 0xFF);
        func_8001F1E8(0xA2, 0xB2, func_8002D7C0(NULL, 0, D_87806330, 0x2B));
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F36C(0xFF, 0x80, 0x80, 0xFF);
        func_8001F1E8(0xA2, 0xC8, func_8002D7C0(NULL, 0, D_87806330, 0x14));
    }

    func_8001F4C4();
    func_8001F444();
}

void func_86401A9C(s32 arg0) {
    func_800079C4();
    func_8000699C(&gDisplayListHead, 0xA6BF);

    if (D_8780FC94 == 0) {
        func_80015348();
    }

    func_80015094(D_87B000E8);

    if (D_8780FC98 == 0) {
        func_86401544(arg0);
    }

    func_87804FD4();
    func_80007778();

    if (D_8780FC94 == 0) {
        D_87B000C0++;
    }
}

void func_86401B3C(void) {
    u8 i;
    u8 var_s1;
    s32 var_s2;

    var_s1 = 0;
    var_s2 = 1;
    func_800077B4(5);
    func_80006C6C(0x10);

    while (var_s2 != 0) {
        if (var_s1 >= 0x11) {
            if (D_80068BA0->unk_08 & 0x1000) {
                var_s2 = 0;
            } else if ((D_8780FA2A == 0) && (D_80068BA0->unk_08 & 0x4000)) {
                func_80048B90(3);
                func_87802EB8(2);
                D_87B000D0 = 1;
                return;
            }
        }

        func_87B00020();
        func_86400BE8(0);
        func_86400860(0);
        func_864002F8();
        func_86400220();
        func_86401A9C(0);

        if (var_s1 < 0x11) {
            var_s1++;
        }
    }

    func_8004B9C4(0x3C);
    if (D_8780FC92 == 0) {
        while (true) {
            if (D_87B000C4 <= 0) {
                break;
            }

            for (i = 3; i > 0; i--) {
                if (D_87B000C4 == ((i * 0x3C) / 2)) {
                    if (i == 3) {
                        func_8780295C(1);
                    }
                    func_8004D9B0(0x70001, 0, 0);
                }
            }

            D_87B000C4--;

            func_87B00020();
            func_86400BE8(1);
            func_86400860(1);
            func_864002F8();
            func_86400220();
            func_86401A9C(1);
        }
    }
}

void func_86401D1C(void) {
    static u8 D_864029DC = 0;
    static u8 D_864029E0 = 0;

    s32 var_s2 = 1;

    if (D_8780FC92 == 0) {
        func_8004D9B0(0x70002, 0, 0);
        func_87B00020();
        func_86400BE8(2);
        func_86400860(2);
        func_864002F8();
        func_86400220();
        func_86401A9C(2);

        while (var_s2 != 0) {
            if (D_8780FC92 != 0) {
                break;
            }

            if ((D_864029DC == 0) && (func_87802974() == -2)) {
                func_8004B1CC(0x18);
                D_864029DC = 1;
            }

            func_87B00020();
            func_86400BE8(2);

            if (D_87B000C8 == 0) {
                if (D_864029E0 < 0x1E) {
                    if (D_8780FC94 == 0) {
                        D_864029E0++;
                    }
                } else if (D_864029E0 == 0x1E) {
                    if (D_8780FC94 == 0) {
                        func_8004D9B0(0x70003, 1, 0);
                        D_864029E0++;
                    }
                    func_80017464(&D_864052CC->unk_004, 1);
                } else {
                    func_86400EB4();
                    func_86400258(D_864052CC);
                }
            } else if (D_8780FC96 != 0) {
                var_s2 = 0;
            }

            func_86400860(2);
            func_864002F8();
            func_86400220();
            func_86401A9C(2);
        }
    }
}

void func_86401EEC(void) {
    u8 i;

    func_8004FC60(1, 0x1E);
    func_8004FC60(2, 0x1E);
    func_80006CB4(0x1E);

    for (i = 0; i < 30; i++) {
        func_87B00020();
        func_86400BE8(3);
        func_86400860(3);
        func_864002F8();
        func_86400220();
        func_86401A9C(3);
    }
}

void func_86401F74(void) {
    D_87B000EC = D_87B000E8->unk_0C;

    D_87B000F0 = 0x900;
    D_87B000F2 = 0;
    D_87B000F4 = 0x190;

    D_87B000EC->unk_034 = 50.0f;
    D_87B000EC->unk_038 = 6400.0f;
    D_87B000EC->unk_02C = 27.5f;

    D_87B000EC->unk_0B4.y = 25.0f;

    func_80010354(&D_87B000EC->unk_0B4, &D_87B000EC->unk_0A8, D_87B000F4, D_87B000F0, D_87B000F2);
}

void func_8640203C(void) {
    u8 i;
    MemoryBlock* temp_s5 = func_80002D10(main_pool_get_available(), 0);

    for (i = 0; i < 4; i++) {
        D_864052C8 = &D_86404778[i];
        D_864052C8->unk_190 = func_80011B10(temp_s5, 0, 4, 0, &D_8006F050, 0.0f);
        func_80012094(&D_800AC840, &D_864052C8->unk_190->unk_00);
    }

    func_80002D60(temp_s5);
}

void func_86402130(void) {
    u8 i;
    u8 x;
    u8 y;
    MemoryBlock* temp_v0 = func_80002D10(main_pool_get_available(), 0);

    D_87B000E8 = func_80018B70(temp_v0, D_8640290C);
    func_80002D60(temp_v0);
    func_8001BB20();
    func_8001987C();
    D_87B000E4 = func_80019D18(0xC7);
    D_864052D0 = &D_86404070;
    func_8001BB58(D_864052D0);
    func_8001BC34(D_864052D0, 0, 0xC7, D_87B000E4->unk_08[0]->unk_00);
    func_8001BD04(D_864052D0, 0);
    func_80017464(D_864052D0, 0);
    D_87B000E4 = func_80019D18(0xC4);

    for (i = 0; i < 4; i++) {
        D_864052C8 = &D_86404778[i];
        D_864052D0 = &D_864052C8->unk_028;

        func_8001BB58(D_864052D0);
        func_8001BC34(D_864052D0, 0, 0xC4, D_87B000E4->unk_08[0]->unk_00);
        D_864052C8->unk_004 = 0;
        func_8001BD04(D_864052D0, D_864052C8->unk_004);
        func_80017464(D_864052D0, func_87B00050(D_864052D0->unk_044->unk_0A));

        D_864052D0->unk_024.x = D_864027C0[i].unk_00;
        D_864052D0->unk_024.y = D_864027C0[i].unk_04;
        D_864052D0->unk_024.z = D_864027C0[i].unk_08;

        D_864052D0->unk_030.x = D_864027C0[i].unk_0C;
        D_864052D0->unk_030.y = D_864027C0[i].unk_10;
        D_864052D0->unk_030.z = D_864027C0[i].unk_14;

        D_864052D0->unk_01E.x = D_864027C0[i].unk_18;
        D_864052D0->unk_01E.y = D_864027C0[i].unk_1A;
        D_864052D0->unk_01E.z = D_864027C0[i].unk_1C;

        D_864052C8->unk_00C = 0;
        D_864052C8->unk_00E = 0x14A;
        D_864052C8->unk_010 = D_864052C8->unk_00E;
        D_864052C8->unk_014 = 0;
        D_864052C8->unk_015 = 0;

        func_86400184(D_864052C8, 0, 0, 0, 0);

        for (x = 0; x < 14; x++) {
            for (y = 0; y < 8; y++) {
                D_864052C8->unk_194[x][y] = 0;
            }
        }

        D_864052C8->unk_274 = 0;
    }

    D_87B000E4 = func_80019D18(0xC3);
    D_864052CC = &D_86405158;
    D_864052D0 = &D_864052CC->unk_004;
    func_8001BB58(D_864052D0);
    func_8001BC34(D_864052D0, 0, 0xC3, D_87B000E4->unk_08[0]->unk_00);

    D_864052CC->unk_001 = D_864052CC->unk_000 = 0;

    func_8001BD04(D_864052D0, D_864052CC->unk_000);
    func_80017464(D_864052D0, D_864052D0->unk_044->unk_0A);

    D_864052D0->unk_024.y = 20.0f;
    D_864052D0->unk_030.x = 1.0f;
    D_864052D0->unk_030.y = 1.0f;
    D_864052D0->unk_030.z = 1.0f;
    D_864052D0->unk_01E.x = -0xB00;

    D_864052CC->unk_16C = 0;
    D_864052CC->unk_16D = 0;
    D_87B000E4 = func_80019D18(0xD2);

    for (i = 0; i < 4; i++) {
        D_864052D0 = &D_864041D8[i];

        func_8001BB58(D_864052D0);
        func_8001BC34(D_864052D0, 0, 0xD2, D_87B000E4->unk_08[0]->unk_00);
        func_8001BD04(D_864052D0, 0);
        func_80017464(D_864052D0, D_864052D0->unk_044->unk_0A);

        D_864052D0->unk_024.x = D_864027C0[i].unk_00;
        D_864052D0->unk_024.y = 25.0f;
        D_864052D0->unk_024.z = D_864027C0[i].unk_08;
        D_864052D0->unk_01E.x = D_864027C0[i].unk_18;
        D_864052D0->unk_01E.y = D_864027C0[i].unk_1A;
        D_864052D0->unk_01E.z = D_864027C0[i].unk_1C;
    }

    func_8640203C();
    func_864001A0();
    func_86400020();
    func_86401F74();
    func_87802528();
    func_878029C0();
}

void func_864025A0(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state(0x4D494E49);
    func_80005E40(0x18000, 0);
    sp24 = func_80007444(0, 1, 3, 1, 2, 1);
    D_87B000E0 = func_8001E94C(0x16, 0);
    func_80004258(((u32)&D_1000000 & 0x0F000000) >> 0x18, _4BD6B0_ROM_START, _4BE810_ROM_START, 0);
    func_80004454((((u32)&D_81000000 & 0x0FF00000) >> 0x14) - 0x10, fragment31_ROM_START, fragment32_ROM_START);
    func_86402130();
    func_80007678(sp24);
    func_86401B3C();
    func_86401D1C();
    func_86401EEC();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();
    main_pool_pop_state(0x4D494E49);
    func_87803118();
}
