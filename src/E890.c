#include "E890.h"
#include "PR/leo.h"
#include "src/dma.h"

unk_D_800AA680 D_800AA680;
static unk_D_800AA690 D_800AA690;
static OSMesgQueue D_800AA698;
static OSMesg D_800AA6B0;

s32 func_8000DC90(void) {
    static char D_8006F000[] = "P2J";
    static char D_8006F004[] = "01";

    if (osMemSize < 0x800000) {
        return 2;
    }

    if (bcmp(D_800818E0.company, D_8006F004, sizeof(D_800818E0.company)) != 0) {
        return 1;
    }

    if (bcmp(&D_800818E0.gameName[1], D_8006F000, 3) != 0) {
        return 1;
    }

    if (D_800818E0.gameName[0] < 'E') {
        return 1;
    }

    if (D_800818E0.gameName[0] > 'Z') {
        return 1;
    }

    if (D_800818E0.diskNumber != 1) {
        return 1;
    }

    _bcopy(&D_800818E0, &leoBootID, sizeof(LEODiskID));
    return 0;
}

s32 func_8000DD68(unk_D_800AA680* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_00 == 'POKE') {
        var_v1 = 1;
        D_800AA680 = *arg0;
    }

    return var_v1;
}

s32 func_8000DDB0(void) {
    func_80001124(&D_800AA698, 0);
    D_800AA690.unk_00 = 3;
    return 0;
}

s32 func_8000DDE4(void) {
    func_8000123C(&D_800AA698, 0);
    D_800AA690.unk_00 = 5;
    return 0;
}

s32 func_8000DE18(unk_D_800AA680* arg0) {
    func_80001098(0, arg0, 0x230, 1, &D_800AA698, 1);
    D_800AA690.unk_04 = 0;
    D_800AA690.unk_02 = 0;
    D_800AA690.unk_00 = 7;
    return 0;
}

s32 func_8000DE70(void) {
    func_80001098(0, D_800AA680.unk_08, D_800AA680.unk_04, D_800AA680.unk_06, &D_800AA698, 1);
    D_800AA690.unk_04 = 0;
    D_800AA690.unk_02 = 0;
    D_800AA690.unk_00 = 9;
    return 0;
}

s32 func_8000DED0(void) {
    s32 sp1C;

    if (osRecvMesg(&D_800AA698, &sp1C, 0) != -1) {
        switch (sp1C) {
            case 0:
                switch (func_8000DC90()) {
                    case 0:
                        D_800AA690.unk_04 = sp1C;
                        D_800AA690.unk_02 = 0;
                        D_800AA690.unk_00 = 6;
                        break;

                    case 1:
                        D_800AA690.unk_04 = sp1C;
                        D_800AA690.unk_02 = 5;
                        D_800AA690.unk_00 = 4;
                        break;

                    case 2:
                        D_800AA690.unk_02 = 4;
                        D_800AA690.unk_00 = 4;
                        D_800AA690.unk_04 = 0x2C;
                        break;
                }
                break;

            case 42:
                D_800AA690.unk_00 = 2;
                break;

            case 35:
                D_800AA690.unk_00 = 2;
                break;

            case 49:
                D_800AA690.unk_04 = sp1C;
                D_800AA690.unk_02 = 2;
                D_800AA690.unk_00 = 2;
                break;

            case 2:
                D_800AA690.unk_04 = sp1C;
                D_800AA690.unk_02 = 3;
                D_800AA690.unk_00 = 4;
                break;

            case 11:
                D_800AA690.unk_04 = sp1C;
                D_800AA690.unk_02 = 1;
                D_800AA690.unk_00 = 4;
                break;

            case 34:
                D_800AA690.unk_04 = sp1C;
                D_800AA690.unk_02 = 1;
                D_800AA690.unk_00 = 4;
                break;

            case 43:
                if (D_800AA690.unk_06++ >= 0x1F) {
                    D_800AA690.unk_02 = 1;
                }
                LeoResetClear();
                D_800AA690.unk_00 = 2;
                break;

            default:
                D_800AA690.unk_04 = sp1C;
                D_800AA690.unk_02 = 1;
                D_800AA690.unk_00 = 4;
                break;
        }

        return 1;
    }

    return 0;
}

s32 func_8000E0EC(void) {
    s32 sp1C;

    if (osRecvMesg(&D_800AA698, &sp1C, 0) != -1) {
        switch (sp1C) {
            default:
                D_800AA690.unk_02 = 1;
                D_800AA690.unk_00 = 1;
                D_800AA690.unk_04 = sp1C;
                break;

            case 0:
                D_800AA690.unk_00 = 4;
                break;

            case 35:
                D_800AA690.unk_00 = 4;
                break;

            case 2:
                D_800AA690.unk_00 = 4;
                break;

            case 42:
                D_800AA690.unk_04 = 0;
                D_800AA690.unk_02 = 0;
                D_800AA690.unk_00 = 2;
                break;

            case 47:
                D_800AA690.unk_04 = 0;
                D_800AA690.unk_02 = 0;
                D_800AA690.unk_00 = 2;
                break;

            case 34:
                D_800AA690.unk_04 = sp1C;
                D_800AA690.unk_02 = 1;
                D_800AA690.unk_00 = 1;
                break;
        }
        return 1;
    }

    return 0;
}

s32 func_8000E21C(unk_D_800AA680* arg0) {
    s32 sp24;
    UNUSED s32 pad;

    if (osRecvMesg(&D_800AA698, &sp24, 0) != -1) {
        switch (sp24) {
            case 0:
                if (func_8000DD68(arg0) != 0) {
                    D_800AA690.unk_00 = 8;
                } else {
                    D_800AA690.unk_02 = 5;
                    D_800AA690.unk_00 = 4;
                }
                break;

            case 0x23:
                D_800AA690.unk_00 = 8;
                break;

            case 0x2A:
                D_800AA690.unk_00 = 2;
                break;

            case 0x2F:
                D_800AA690.unk_00 = 2;
                break;

            case 0x31:
                D_800AA690.unk_04 = sp24;
                D_800AA690.unk_02 = 2;
                D_800AA690.unk_00 = 2;
                break;

            case 2:
                D_800AA690.unk_04 = sp24;
                D_800AA690.unk_02 = 3;
                D_800AA690.unk_00 = 4;
                break;

            case 0x22:
                D_800AA690.unk_04 = sp24;
                D_800AA690.unk_02 = 1;
                D_800AA690.unk_00 = 4;
                break;

            default:
                D_800AA690.unk_04 = sp24;
                D_800AA690.unk_02 = 1;
                D_800AA690.unk_00 = 4;
                break;
        }
        return 1;
    }

    return 0;
}

s32 func_8000E3B4(void) {
    s32 sp1C;

    if (osRecvMesg(&D_800AA698, &sp1C, 0) != -1) {
        switch (sp1C) {
            case 0:
                D_800AA690.unk_00 = 0xA;
                break;

            case 0x23:
                D_800AA690.unk_00 = 8;
                break;

            case 0x2A:
                D_800AA690.unk_00 = 2;
                break;

            case 0x2F:
                D_800AA690.unk_00 = 2;
                break;

            case 0x31:
                D_800AA690.unk_04 = sp1C;
                D_800AA690.unk_02 = 2;
                D_800AA690.unk_00 = 2;
                break;

            case 2:
                D_800AA690.unk_04 = sp1C;
                D_800AA690.unk_02 = 3;
                D_800AA690.unk_00 = 4;
                break;

            case 0x22:
                D_800AA690.unk_04 = sp1C;
                D_800AA690.unk_02 = 1;
                D_800AA690.unk_00 = 4;
                break;

            default:
                D_800AA690.unk_04 = sp1C;
                D_800AA690.unk_02 = 1;
                D_800AA690.unk_00 = 4;
                break;
        }
        return 1;
    }

    return 0;
}

s32 func_8000E51C(void) {
    UNUSED s32 pad;
    u8 sp23;
    s32 temp_v0 = LeoTestUnitReady(&sp23);

    switch (temp_v0) {
        case 0:
        case 8:
        case 35:
            break;

        default:
            D_800AA690.unk_04 = temp_v0;
            D_800AA690.unk_02 = 1;
            break;

        case 42:
            D_800AA690.unk_04 = 0;
            D_800AA690.unk_02 = 0;
            D_800AA690.unk_00 = 2;
            break;

        case 47:
            D_800AA690.unk_04 = 0;
            D_800AA690.unk_02 = 0;
            D_800AA690.unk_00 = 2;
            break;
    }
    return 0;
}

void func_8000E5B4(void) {
}

s32 func_8000E5BC(unk_D_800AA680* arg0) {
    s32 sp24 = 1;

    if (func_800012F8() != 0) {
        while (sp24 != 0) {
            switch (D_800AA690.unk_00) {
                case 0:
                    sp24 = 0;
                    break;

                case 1:
                    sp24 = func_8000E51C();
                    break;

                case 2:
                    sp24 = func_8000DDB0();
                    break;

                case 3:
                    sp24 = func_8000DED0();
                    break;

                case 4:
                    sp24 = func_8000DDE4();
                    break;

                case 5:
                    sp24 = func_8000E0EC();
                    break;

                case 6:
                    sp24 = func_8000DE18(arg0);
                    break;

                case 7:
                    sp24 = func_8000E21C(arg0);
                    break;

                case 8:
                    sp24 = func_8000DE70();
                    break;

                case 9:
                    sp24 = func_8000E3B4();
                    break;

                case 10:
                    sp24 = 0;
                    break;
            }
        }
    }

    return (D_800AA690.unk_00 << 0x10) | (D_800AA690.unk_02 << 8) | D_800AA690.unk_04;
}

s32 func_8000E6EC(void) {
    s32 sp1C = func_800012F8();

    if (sp1C != 0) {
        D_800AA690.unk_00 = 2;
    } else {
        D_800AA690.unk_00 = 0;
    }

    D_800AA690.unk_04 = 0;
    D_800AA690.unk_02 = 0;
    D_800AA690.unk_06 = 0;

    osCreateMesgQueue(&D_800AA698, &D_800AA6B0, 1);
    return sp1C;
}

void func_8000E760(void) {
    s32 tmp = D_800AA690.unk_00;

    if (tmp == 3) {
        osRecvMesg(&D_800AA698, NULL, 1);
        D_800AA690.unk_00 = 2;
    } else {
        switch (tmp) {
            case 5:
            case 7:
            case 9:
                osRecvMesg(&D_800AA698, NULL, 1);
                D_800AA690.unk_00 = 4;
                break;
        }
    }
}

void func_8000E7E4(void) {
    if (func_800012F8() != 0) {
        D_800AA690.unk_00 = 2;
        D_800AA690.unk_04 = 0;
        D_800AA690.unk_02 = 0;
    }
}
