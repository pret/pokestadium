#include "fragment43.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/49790.h"
#include "src/fragments/43/fragment43.h"

static s16 D_83407C00;
static Controller* D_83407C04;
static s16 D_83407C08;
static s16 D_83407C0A;

static s16 D_83402E40 = 0;
static s16 D_83402E44[] = { 3, 4, 1 };

static unk_D_83402E4C D_83402E4C[] = {
    {
        120,
        160,
        400,
        64,
        1,
        0,
        26889,
        NULL,
    },
    {
        120,
        160,
        400,
        64,
        1,
        0,
        26889,
        NULL,
    },
    {
        120,
        160,
        400,
        196,
        3,
        0,
        26889,
        NULL,
    },
    {
        120,
        160,
        400,
        176,
        3,
        0,
        26889,
        D_83402E44,
    },
    {
        220,
        160,
        200,
        64,
        1,
        0,
        26889,
        NULL,
    },
};

static s16 D_83402E9C[] = { 0x2B, 0x2C, 0x2D, 0 };
static s16 D_83402EA4[] = { 0, 0x22, 0x58, 0 };
static s16 D_83402EAC[] = {
    0x2F,
    0x30,
    0x31,
    0,
};

void func_83402430(unk_D_83402E4C* arg0, s16 arg1) {
    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    if (arg1 == 0) {
        func_8001F1E8(arg0->unk_00 + 0x18, arg0->unk_02 + 0x14, func_834023CC(0x29));
    } else {
        func_8001F1E8(arg0->unk_00 + 0x39, arg0->unk_02 + 0x14, func_834023CC(0x2A));
    }
    func_8001F444();
}

void func_834024C4(unk_D_83402E4C* arg0) {
    char* temp_v0;
    s32 i;
    s32 tmp;

    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    temp_v0 = func_83402374(0x2A);
    tmp = (arg0->unk_04 - func_8001F5B0(0, 0, temp_v0)) / 2;
    func_8001F1E8(arg0->unk_00 + tmp, arg0->unk_02 + 0x14, temp_v0);

    for (i = 0; i < arg0->unk_08; i++) {
        func_8001EBE0(0x10, 0);
        temp_v0 = func_83402374(D_83402E9C[i]);
        if (i == D_83407C0A) {
            func_8001F324(0xFF, 0xFF, 0, 0xFF);
        } else {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        }

        func_8001F1E8(arg0->unk_00 + 0x3C, D_83402EA4[i] + arg0->unk_02 + 0x40, temp_v0);

        if (i == 1) {
            func_8001EBE0(8, 0);
            func_8001F1E8(arg0->unk_00 + 0x3C, D_83402EA4[i] + arg0->unk_02 + 0x58, func_83402374(0x36));
        }
    }

    func_8001F444();

    if (D_83407C0A >= 0) {
        func_80020928(arg0->unk_00 + 0x10, D_83402EA4[D_83407C0A] + arg0->unk_02 + 0x48);
    }
}

void func_834026A4(unk_D_83402E4C* arg0) {
    s32 i;
    s32 tmp;
    char* temp_v0;

    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    temp_v0 = func_83402374(0x2E);
    tmp = (arg0->unk_04 - func_8001F5B0(0, 0, temp_v0)) / 2;
    func_8001F1E8(arg0->unk_00 + tmp, arg0->unk_02 + 0x14, temp_v0);

    for (i = 0; i < arg0->unk_08; i++) {
        func_8001EBE0(0x10, 0);
        temp_v0 = func_83402374(D_83402EAC[i]);
        if (i == D_83407C0A) {
            func_8001F324(0xFF, 0xFF, 0, 0xFF);
        } else {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        }
        func_8001F1E8(arg0->unk_00 + 0x3C, arg0->unk_02 + (i * 0x22) + 0x40, temp_v0);
    }

    func_8001F444();

    if (D_83407C0A >= 0) {
        func_80020928(arg0->unk_00 + 0x10, arg0->unk_02 + (D_83407C0A * 0x22) + 0x48);
    }
}

void func_83402834(unk_D_83402E4C* arg0) {
    UNUSED s32 pad;
    s32 sp18 = (0xC8 - func_8001F5B0(0x10, 0, func_83402374(0x41))) / 2;

    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8001F1E8(arg0->unk_00 + sp18, arg0->unk_02 + 0x14, func_83402374(0x41));
    func_8001F444();
}

void func_834028C4(void) {
    D_83402E40 = 0;
}

void func_834028D0(UNUSED s32 arg0) {
    s16 var_a3;
    unk_D_83402E4C* temp_s0;
    s16 tmp;

    if ((D_83402E40 != 0) && (D_83407C08 > 0)) {
        temp_s0 = &D_83402E4C[D_83407C00];
        if (D_83407C08 < 4) {
            var_a3 = (temp_s0->unk_06 * D_83407C08) / 4;
            if (var_a3 < 16) {
                var_a3 = 16;
            }
            tmp = temp_s0->unk_02 + ((temp_s0->unk_06 - var_a3) / 2);

            func_80020460(temp_s0->unk_00, tmp, temp_s0->unk_04, var_a3, temp_s0->unk_0A);
        } else {
            func_80020460(temp_s0->unk_00, temp_s0->unk_02, temp_s0->unk_04, temp_s0->unk_06, temp_s0->unk_0A);

            switch (D_83407C00) {
                case 0:
                    func_83402430(temp_s0, 0);
                    break;

                case 1:
                    func_83402430(temp_s0, 1);
                    break;

                case 2:
                    func_834024C4(temp_s0);
                    break;

                case 3:
                    func_834026A4(temp_s0);
                    break;

                case 4:
                    func_83402834(temp_s0);
                    break;
            }
        }
    }
}

void func_83402A38(void) {
    s32 tmpA;
    unk_D_83402E4C* temp_v0;
    s16* temp_a3;
    s32 tmp8;

    temp_v0 = &D_83402E4C[D_83407C00];
    tmp8 = temp_v0->unk_08;
    temp_a3 = temp_v0->unk_0C;

    if (D_83407C04 != NULL) {

        if (tmp8 >= 2) {
            tmpA = D_83407C0A;
            if (D_83407C04->buttonPressed & 0x800) {
                D_83407C0A--;
                if (D_83407C0A < 0) {
                    D_83407C0A = tmp8 - 1;
                }
            }

            if (D_83407C04->buttonPressed & 0x400) {
                D_83407C0A++;
                if (D_83407C0A >= tmp8) {
                    D_83407C0A = 0;
                }
            }

            if (tmpA != D_83407C0A) {
                func_80048B90(1);
            }
        }

        if (D_83407C04->buttonPressed & 0x8000) {
            if (temp_a3 == NULL) {
                func_80048B90(2);
            } else {
                switch (temp_a3[D_83407C0A]) {
                    case 1:
                        func_80048B90(3);
                        break;

                    case 2:
                        func_80048B90(2);
                        break;

                    case 3:
                        func_80048B90(0x1D);
                        break;

                    case 4:
                        func_80048B90(0x21);
                        break;
                }
            }
            D_83402E40 = 3;
        } else if (D_83407C04->buttonPressed & 0x4000) {
            func_80048B90(3);
            D_83407C0A = -2;
            D_83402E40 = 3;
        }
    }
    D_83407C08 = 4;
}

void func_83402BF4(void) {
    D_83407C08++;
    if (D_83407C08 >= 5) {
        D_83407C08 = 4;
        D_83402E40 = 2;
    }
}

void func_83402C34(void) {
    D_83407C08--;
    if (D_83407C08 < 0) {
        D_83407C08 = 0;
        D_83402E40 = 4;
    }
}

s32 func_83402C6C(void) {
    s32 sp1C = 0;

    switch (D_83402E40) {
        case 2:
            func_83402A38();
            sp1C = 0;
            break;

        case 1:
            func_83402BF4();
            sp1C = 0;
            break;

        case 3:
            func_83402C34();
            sp1C = 1;
            break;
    }
    return sp1C;
}

s32 func_83402CE4(s16 arg0, Controller* arg1) {
    if (D_83402E40 == 0) {
        func_80048B90(4);
        D_83407C00 = arg0;
        D_83407C0A = D_83402E4C[arg0].unk_09;
        D_83407C08 = 0;
        D_83407C04 = arg1;
        D_83402E40 = 1;
        return 1;
    }
    return 0;
}

s32 func_83402D74(s16 arg0) {
    if ((D_83402E40 == 2) && (arg0 == D_83407C00)) {
        D_83407C0A = -1;
        D_83402E40 = 3;
        return 1;
    }
    return 0;
}

s16 func_83402DC8(s16 arg0) {
    if ((D_83402E40 == 4) && (arg0 == D_83407C00)) {
        D_83402E40 = 0;
        return D_83407C0A;
    }
    return -1;
}
