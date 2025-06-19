#include "fragment62.h"

void func_8432FF20(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 0.1f);
    func_8140BAC8(arg0, 0xFF, 0xFF, 0xFF);
    func_8140BB74(arg0, 0x64, 0xC8, 0xFF);
    func_8140BC20(arg0, 0xFF);
    func_814081BC(arg0);
}

void func_8432FF8C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8432FF20(arg0);
            break;

        case 2:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140BC2C(arg0, 0x20, 8);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8140B98C(arg0, 0.5f, 0.05f);
    }
}

void func_84330048(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 0.1f);
    func_8140BAC8(arg0, 0xFF, 0xFF, 0xFF);
    func_8140BB74(arg0, 0x64, 0xC8, 0xFF);
    func_8140BC20(arg0, 0xFF);
    func_814081BC(arg0);
}

void func_843300B4(unk_D_8140E720* arg0) {
    if (arg0->unk_B2 == 1) {
        func_84330048(arg0);
    }

    if (func_8140819C(arg0) != 0) {
        func_8140B98C(arg0, 0.8f, 0.08f);
    }
}

void func_8433010C(unk_D_8140E720* arg0, u8 arg1) {
    switch (arg1) {
        case 1:
            arg0->unk_08 = func_8432FF8C;
            arg0->unk_0C = &D_843861D0[25];
            break;

        case 2:
            arg0->unk_08 = func_843300B4;
            arg0->unk_0C = &D_843861D0[22];
            break;
    }
}
