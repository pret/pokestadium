#include "fragment47.h"
#include "src/1AB70.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/232C0.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/6A40.h"
#include "src/controller.h"
#include "src/fragments/39/fragment39.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static s32 D_83805650;
static s32 D_83805654;
static void* D_83805658;
static unk_D_8380565C* D_8380565C;
static s32 D_83805660;
static s32 D_83805664;
static s32 D_83805668;

void func_83800020(s32 arg0) {
    D_83805654 = 0;
    D_83805650 = arg0;
    D_83805668 = -1;
    D_83805660 = -1;
    func_8002D510();
    func_83402340();
    func_83800EFC();
    func_8380252C(0x68, 0x8A, D_8380565C);
    func_834028C4();
}

void func_8380008C(s32 arg0) {
    D_83805668 = arg0;
}

void func_83800098(s32 arg0, s32 arg1) {
    func_8001C6AC(arg0, arg1, 0x40, 0x18, D_04000000, 0x40, 0);
    func_8001C6AC(arg0, arg1 + 0x18, 0x40, 0x18, D_4000C00, 0x40, 0);
}

void func_83800120(void) {
    char* sp2C = func_83402374(4);
    Color_RGBA8 sp28 = { 0x9A, 0x37, 0x54, 0xFF };
    Color_RGBA8 sp24 = { 0xC3, 0x54, 0x84, 0xFF };

    func_83401110(0x48, 0x28, 0x208, &sp28, &sp24);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_83800098(0x28, 0x20);
    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8001F324(0, 0, 0, 0xFF);
    func_8001F1E8(0x7A, 0x2D, sp2C);
    func_8001F324(0xFF, 0xFF, 0x77, 0xFF);
    func_8001F1E8(0x78, 0x2B, sp2C);
    func_8001F444();
}

void func_83800218(void) {
    func_800079C4();
    if (D_83805668 != 0) {
        func_8001D924(D_83805658);
        func_83800120();
    }
    func_838022C8(1);
    func_838043F8(1);
    func_834028D0(1);
    func_80007778();
    if (D_83805668 > 0) {
        D_83805668 -= 1;
    }
}

void func_83800294(s32 arg0) {
    D_83805654 = 2;
    func_8380008C(0xC);

    main_pool_push_state('glpc');

    if ((D_83805664 >= 0) && (D_83805664 < 4)) {
        func_80023D60(D_83805664);
    }

    if (arg0 != 0) {
        func_838029D4(D_83805664, &D_83407B18.unk_08);
    } else {
        func_838029D4(D_83805664, NULL);
    }
}

void func_83800320(void) {
    D_83805660 = func_83402DC8(2);

    if (D_83805660 != -1) {
        if (D_83805660 == -2) {
            D_83805660 = 2;
        }

        if (D_83805660 != 2) {
            D_83805654 = 4;
            func_80006CB4(0xF);
        } else {
            D_83805654 = 1;
            func_83801190(D_83805664);
            D_83805660 = -1;
        }
    }
}

s32 func_838003B4(void) {
    static s32 D_83804CB8 = 4;

    s32 sp7C = 1;
    s32 sp78 = 0;
    s32 sp74;
    unk_func_80026268_arg0 sp20;

    switch (D_83805654) {
        case 0:
            if (func_80007604() == 0) {
                D_83804CB8--;
                if (D_83804CB8 <= 0) {
                    D_83805654 = 1;
                    if (D_83805650 == 1) {
                        D_83805664 = D_83407B18.unk_08.unk_00;
                        func_83800294(1);
                    } else {
                        if (D_83805650 == 2) {
                            D_83805664 = 5;
                        } else {
                            D_83805664 = -1;
                        }
                        func_83801190(D_83805664);
                    }
                }
            }
            break;

        case 1:
            D_83805664 = func_8380248C();
            switch (D_83805664) {
                case -2:
                    if (D_83402E20 > 0) {
                        D_83805654 = 3;
                        func_83402CE4(2, gPlayer1Controller);
                    } else {
                        sp78 = 1;
                    }
                    break;

                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                    func_83800294(0);
                    break;

                case 5:
                    sp78 = 1;
                    _bcopy(&D_8380565C->unk_7E4, &sp20, sizeof(unk_func_80026268_arg0));
                    func_8003107C(&D_83407AC8, &sp20);
                    break;
            }

            if (sp78 != 0) {
                D_83805654 = 4;
                func_80006CB4(0xF);
            }
            break;

        case 2:
            sp74 = func_838024EC();
            if (sp74 != 0) {
                main_pool_pop_state('glpc');

                D_83805668 = -1;
                if (sp74 > 0) {
                    D_83805654 = 4;
                    func_80006CB4(0xF);
                } else {
                    D_83805654 = 1;
                    func_83801190(D_83805664);
                }
            }
            break;

        case 3:
            func_83800320();
            break;

        case 4:
            if (func_80007604() == 1) {
                sp7C = 0;
            }
            break;
    }
    return sp7C;
}

void func_83800610(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_83800640(void) {
    func_80006C6C(7);
    do {
        func_83800610();
        func_83801D64();
        func_83803488();
        func_83402C6C();
        func_83800218();
    } while (func_838003B4() != 0);
}

s32 func_83800698(void) {
    s32 var_v1;
    unk_D_83407B18_008* temp_a0 = &D_83407B18.unk_08;
    temp_a0 += 0;

    if (D_83805660 == 0) {
        var_v1 = 2;
    } else if (D_83805660 == 1) {
        var_v1 = 0;
    } else {
        switch (D_83805664) {
            case -2:
                var_v1 = 0;
                break;

            case 5:
                var_v1 = 6;
                break;

            default:
                var_v1 = 1;
                break;
        }
    }

    temp_a0->unk_00 = D_83805664;
    func_838024C0(temp_a0);
    return var_v1;
}

s32 func_83800730(s32 arg0, s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('SLCT');

    func_80005E40(0x20000, 0);
    sp24 = func_80007444(1, 0, 2, 0, 2, 1);
    D_8250A304 = func_8001E94C(0x1C, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);
    ASSET_LOAD(D_3000000, gallery_ui, 0);
    ASSET_LOAD(D_04000000, snap_select_ui, 0);

    D_83805658 = func_8000484C(ASSET_LOAD2(backgrounds, 1, 1), 0x14);
    D_8380565C = func_8000484C(func_800044F4(0x898000, NULL, 1, 0), 0x1A);

    func_8001B058();
    func_83800020(arg0);
    func_80007678(sp24);
    func_83800640();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('SLCT');

    return func_83800698();
}
