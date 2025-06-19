#include "fragment62.h"
#include "src/6A40.h"

void func_84358FF0(void) {
}

void func_84358FF8(void) {
}

void func_84359000(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    gSPDisplayList(gDisplayListHead++, D_8140DDF8);

    func_814059C8(arg0, arg1, arg2, arg3);

    gSPTextureRectangle(gDisplayListHead++, 0, 0, 0x04FC, 0x03BC, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
    gSPDisplayList(gDisplayListHead++, D_8140DDD8);
}

void func_843590E0(unk_D_86002F34_00C* arg0) {
    func_8432CF74(arg0);
    D_8140E620 = func_80005F5C(sizeof(unk_D_8140E620));
    D_8140E624 = 0;
    D_843902A4 += 1;

    gSPDisplayList(gDisplayListHead++, D_8140DB30);

    func_814059C8(D_84390382, D_84390384, D_84390386, D_84390388);
    func_81405A90(D_84390392, D_84390394, D_84390396, D_84390398);
    func_81405A20(D_8439038A, D_8439038C, D_8439038E, D_84390390);
    func_81405B00(D_8439039A, D_8439039C, D_8439039E, D_843903A0);
    func_84300184(D_8439037A, D_8439037C, D_8439037E);
    func_8140C204(arg0);
    guOrtho(&D_8140E620->unk_5B80, 0.0f, 320.0f, 240.0f, 0.0f, -2.0f, 2.0f, 1.0f);

    gSPMatrix(gDisplayListHead++, (u32)&D_8140E620->unk_5B80 & 0x1FFFFFFF,
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gDisplayListHead++, D_8140DD78);

    func_81402410();
    func_8140C2D8(arg0);

    gSPDisplayList(gDisplayListHead++, D_8140DAE0);
}
