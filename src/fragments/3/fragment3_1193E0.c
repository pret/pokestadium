#include "fragment3.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/F420.h"
#include "src/controller.h"

s16 D_87906040;
s16 pad_D_87906042;
s16 D_87906044;
s16 D_87906046;
s16 D_87906048;
s16 D_8790604A;
s32 pad_D_8790604C;
s32 D_87906050;
unk_D_86002F34_00C* D_87906054;
s32 pad_D_87906058[2];
s16 D_87906060;
s16 D_87906062;
s16 D_87906064;
s16 D_87906066;
s16 D_87906068;
s16 D_8790606A;
Vec3s D_8790606C;
s16 D_87906072;
s16 pad_D_87906074;
s16 D_87906076;
s16 D_87906078;
f32 D_8790607C;
f32 D_87906080;
s32 pad_D_87906084;
Vec3f D_87906088;
s16 D_87906094;
s16 D_87906096;
s16 D_87906098;
s16 D_8790609A;
Vec3s D_8790609C;
s16 D_879060A2;
s16 D_879060A4;
s16 D_879060A6;
s16 D_879060A8;
Vec3s D_879060AC;
s32 pad_D_879060B4;
s32 pad_D_879060B8;
s16 D_879060BC;
s16 D_879060BE;
s16 D_879060C0;
s16 D_879060C2;
s8 D_879060C4;
s8 D_879060C5;
s8 D_879060C6;
s8 D_879060C7;
s16 D_879060C8;
s16 D_879060CA;
s32 pad_D_879060D0[4];
Vec3f D_879060E0;
Vec3f pad_D_879060F0;
Vec3f D_87906100;
Vec3f D_87906110;

void func_87900A50(void) {
    D_87906060 = D_879060A2 + D_87906094;
    D_87906062 = D_879060A4 + D_87906096;

    D_8790606C.x = D_879060AC.x + D_8790609C.x;
    D_8790606C.y = D_879060AC.y + D_8790609C.y;
    D_8790606C.z = D_879060AC.z + D_8790609C.z;

    D_87906064 = D_879060A6 + D_87906098;
    D_87906066 = D_879060A8 + D_8790609A;

    if (D_87906064 < 0x32) {
        D_87906064 = 0x32;
        D_87906098 = D_87906064 - D_879060A6;
    }

    if (D_87906066 < 0xA) {
        D_87906066 = 0xA;
        D_8790609A = D_87906066 - D_879060A8;
    }
}

void func_87900B64(void) {
    D_87906054->unk_24.fovy = D_87906066;
    D_87906054->unk_24.near = D_87906068;
    D_87906054->unk_24.far = D_8790606A;

    D_87906054->unk_60.at.x = D_8790606C.x;
    D_87906054->unk_60.at.y = D_8790606C.y;
    D_87906054->unk_60.at.z = D_8790606C.z;

    func_80010354(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, D_87906064, D_87906060, D_87906062);
}

s32 func_87900C5C(void) {
    s16 sp6;

    if (D_87903DB0 == 0) {
        return;
    }

    if (gPlayer1Controller->buttonPressed & 0x20) {
        D_87903DB8++;
        if (D_87903DB8 == 1) {
            D_87903DB8 = 0;
        }
    }

    if (gPlayer1Controller->buttonPressed & 0x10) {
        D_87903DB8--;
        if (D_87903DB8 < 0) {
            D_87903DB8 = 0;
        }
    }

    if (gPlayer1Controller->buttonPressed & 0x1000) {
        D_8790609C.x = 0;
        D_8790609C.y = 0;
        D_8790609C.z = 0;

        D_87906094 = 0;
        D_87906096 = 0;
        D_87906098 = 0;
        D_8790609A = 0;
    }

    if (D_87903DB8 == 0) {
        if (gPlayer1Controller->buttonDown & 0xCF00) {
            if (gPlayer1Controller->buttonDown & 0x800) {
                sp6 = D_87906062 + 0x8000;
            }

            if (gPlayer1Controller->buttonDown & 0x400) {
                sp6 = D_87906062;
            }

            if (gPlayer1Controller->buttonDown & 0x200) {
                sp6 = D_87906062 + 0xC000;
            }

            if (gPlayer1Controller->buttonDown & 0x100) {
                sp6 = D_87906062 + 0x4000;
            }

            if (gPlayer1Controller->buttonDown & 0x8000) {
                sp6 = D_87906062 + 0x8000;
            }

            if (gPlayer1Controller->buttonDown & 0x4000) {
                sp6 = D_87906062;
            }

            D_8790609C.x += SINS(sp6) * 16.0f;
            D_8790609C.z += COSS(sp6) * 16.0f;
        }

        D_87906096 += gPlayer1Controller->stickX * 4.0f;
        D_87906094 += gPlayer1Controller->stickY * 4.0f;

        if (gPlayer1Controller->buttonDown & 8) {
            D_8790609C.y += 4;
        }

        if (gPlayer1Controller->buttonDown & 4) {
            D_8790609C.y -= 4;
        }

        if (gPlayer1Controller->buttonDown & 1) {
            D_87906098 += 0xA;
        }

        if (gPlayer1Controller->buttonDown & 2) {
            D_87906098 -= 0xA;
        }
    }
}

void func_87900F44(void) {
    u8 sp24[3] = { 0, 0, 30 };  // D_87903DE0
    u8 sp20[3] = { 0, 0, 250 }; // D_87903DE4

    func_80020460(0x14, 0x14, 0x122, 0x3C, 0x141);
    func_8001F3F4();
    func_8001EBE0(2, -2);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);

    if (D_87903DB8 == 0) {
        func_8001F1E8(0x19, 0x1C, "TRANSRATE");
    }

    func_8001F1E8(0x19, 0x28, "CAMERA X:%d", D_8790606C.x);
    func_8001F1E8(0x19, 0x34, "CAMERA Y:%d", D_8790606C.y);
    func_8001F1E8(0x19, 0x40, "CAMERA Z:%d", D_8790606C.z);
    func_8001F1E8(0xA7, 0x28, "CAMERA D:%d", D_87906064);
    func_8001F1E8(0xA7, 0x34, "CAMERA F:%d", D_87906066);
    func_8001F1E8(0xA7, 0x40, "X:%04hX Y:%04hX", D_87906060, D_87906062);
    func_8001F444();
}

void func_879010A4(void) {
    u8 sp2C[3] = { 0, 0, 30 };  // D_87903DE8
    u8 sp28[3] = { 0, 0, 250 }; // D_87903DEC

    func_80020460(0x78, 0x80, 0xB4, 0x64, 0x141);
    func_8001F3F4();
    func_8001EBE0(2, -2);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001F1E8(0x82, 0x8C, "FORCE   :%2.2f", gPlayer1Controller->stickMag);
    func_8001F1E8(0x82, 0x98, "LEVEL X :%2.2f", gPlayer1Controller->stickX);
    func_8001F1E8(0x82, 0xA4, "LEVEL Y :%2.2f", gPlayer1Controller->stickY);
    func_8001F1E8(0x82, 0xB0, "STICK X :%d", gPlayer1Controller->rawStickX);
    func_8001F1E8(0x82, 0xBC, "STICK Y :%d", gPlayer1Controller->rawStickY);
    func_8001F1E8(0x82, 0xC8, "ANGLE   :%04hx", gPlayer1Controller->angle);
    func_8001F444();
}

void func_87901200(void) {
    UNUSED s32 pad;
    u8 sp30[3] = { 0, 0, 30 };  // D_87903DF0
    u8 sp2C[3] = { 0, 0, 250 }; // D_87903DF4

    if (gPlayer1Controller->buttonPressed & 8) {
        D_879060CA--;
        if (D_879060CA < 0) {
            D_879060CA = 4;
        }
    }

    if (gPlayer1Controller->buttonPressed & 4) {
        D_879060CA++;
        if (D_879060CA >= 5) {
            D_879060CA = 0;
        }
    }

    switch (D_879060CA) {
        case 0:
            if (gPlayer1Controller->buttonPressed & 2) {
                D_87906100.x -= 0.1f;
            }
            if (gPlayer1Controller->buttonPressed & 1) {
                D_87906100.x += 0.1f;
            }
            break;

        case 1:
            if (gPlayer1Controller->buttonPressed & 2) {
                D_87906100.y -= 0.1;
            }
            if (gPlayer1Controller->buttonPressed & 1) {
                D_87906100.y += 0.1;
            }
            break;

        case 2:
            if (gPlayer1Controller->buttonPressed & 2) {
                D_879060E0.x -= 1.0;
            }
            if (gPlayer1Controller->buttonPressed & 1) {
                D_879060E0.x += 1.0;
            }
            break;

        case 3:
            if (gPlayer1Controller->buttonPressed & 2) {
                D_879060E0.y -= 1.0;
            }
            if (gPlayer1Controller->buttonPressed & 1) {
                D_879060E0.y += 1.0;
            }
            break;

        case 4:
            if (gPlayer1Controller->buttonPressed & 2) {
                D_87906110.y -= 0.02;
            }
            if (gPlayer1Controller->buttonPressed & 1) {
                D_87906110.y += 0.02;
            }
            break;
    }

    func_80020460(0x78, 0x80, 0xB4, 0x64, 0x141);
    func_8001F3F4();
    func_8001EBE0(2, -2);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001F1E8(0x7C, 0x8C + (D_879060CA * 0xC), "@");

    func_8001F1E8(0x82, 0x8C, "VX:%2.2f", D_87906100.x);
    func_8001F1E8(0x82, 0x98, "VY:%2.2f", D_87906100.y);
    func_8001F1E8(0x82, 0xA4, "BX:%2.2f", D_879060E0.x);
    func_8001F1E8(0x82, 0xB0, "BY:%2.2f", D_879060E0.y);
    func_8001F1E8(0x82, 0xBC, "GV:%2.2f", D_87906110.y);
    func_8001F1E8(0x82, 0xC8, "PW:%2.2f", D_87906110.x);

    func_8001F444();
}
