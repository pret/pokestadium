#include "fragment3.h"
#include "include/math.h"
#include "src/17300.h"
#include "src/18140.h"
#include "src/1C720.h"
#include "src/20330.h"
// #include "src/3FB0.h"
#include "src/controller.h"
#include "src/fragments/2/fragment2.h"

s16 minigameState = 0;
s16 minigameInputLock = 0;
s16 D_87903DA8 = 0;
s16 D_87903DAC = 0;
s16 minigameDebuggMode = 0;
s32 pad_D_87903DB4 = 0;
s16 D_87903DB8 = 0;
s16 D_87903DBC = 0;
s16 D_87903DC0 = 0;
s16 D_87903DC4 = 0; //	related to tutorial screen on minigames
s16 D_87903DC8 = 0;
s16 D_87903DCC = 0;
s16 D_87903DD0 = 0;
s16 D_87903DD4 = 0;

ret_func_80004454 func_87900020(void) {
    return func_87900020;
}

// func_8790002C
float MinigameGetVec3Distance_2d(minigameActor* arg0, minigameActor* arg1) {
    return sqrtf(SQ(arg1->unk_19C.x - arg0->unk_19C.x) + SQ(arg1->unk_19C.z - arg0->unk_19C.z));
}
// func_87900070
void MinigameGetVec3Distance_3d(minigameActor* arg0, minigameActor* arg1) {
    sqrtf(SQ(arg1->unk_19C.x - arg0->unk_19C.x) + SQ(arg1->unk_19C.y - arg0->unk_19C.y) +
          SQ(arg1->unk_19C.z - arg0->unk_19C.z));
}

//  unused,
s32 func_879000C4(minigameActor* arg0, minigameActor* arg1) {
    f32 totalX = arg1->unk_19C.x - arg0->unk_19C.x;
    f32 totalY = arg1->unk_19C.y - arg0->unk_19C.y;
    f32 totalZ = arg1->unk_19C.z - arg0->unk_19C.z;
    f32 var_fa1 = (arg0->unk_288 * arg0->scale.y) + (arg1->unk_288 * arg1->scale.y);
    s32 ret = FALSE;

    if (totalX < 0.0f) {
        totalX = -totalX;
    }

    if (totalY < 0.0f) {
        totalY = -totalY;
    }

    if (totalZ < 0.0f) {
        totalZ = -totalZ;
    }

    if (var_fa1 < 0.0f) {
        var_fa1 = -var_fa1;
    }

    if (CB(totalZ) < ((CB(var_fa1) - CB(totalX)) - CB(totalY))) {
        ret = TRUE;
    }

    return ret;
}

s32 metapodRockCollisionCheck(minigameActor* fallingRock, minigameActor* metapod) {
    f32 totalX;
    f32 totalY;
    f32 totalZ;
    f32 var_fa1;
    f32 var_fs0;
    f32 tmp;
    s32 ret;

    totalX = metapod->unk_19C.x - fallingRock->unk_19C.x;
    totalY = metapod->unk_19C.y - fallingRock->unk_19C.y;
    totalZ = metapod->unk_19C.z - fallingRock->unk_19C.z;
    ret = 0;

    var_fa1 = (fallingRock->unk_288 * fallingRock->scale.y) + (metapod->unk_288 * metapod->scale.y);
    var_fs0 = ((fallingRock->unk_28C * fallingRock->scale.y) + (metapod->unk_28C * metapod->scale.y)) / 2.0f;

    totalX = ABS(totalX);
    totalY = ABS(totalY);
    totalZ = ABS(totalZ);
    var_fa1 = ABS(var_fa1);
    var_fs0 = ABS(var_fs0);
    tmp = var_fs0 - totalY;

    if ((SQ(totalZ) < (SQ(var_fa1) - SQ(totalX))) && (tmp > 0)) {
        ret = 1;
    }

    return ret;
}

// change animation on ekans' and metapod's minigames ?
void func_879002B8(minigameActor* arg0, s16 arg1, s16 arg2, s16 arg3) {
    arg0->unk_248 = 1; //	animation flag ?
    arg0->unk_24A = arg1;
    arg0->unk_24C = arg2;
    arg0->unk_26A = arg3;
    arg0->unk_26C = 0; //	animation flag ?
    arg0->unk_26E = 0;
}

void func_879002FC(minigameActor* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk_248 = 1;
    arg0->unk_24A = arg1;
    arg0->unk_24C = arg2;
    arg0->unk_26A = arg3;
    arg0->unk_26C = 0;
    arg0->unk_26E = arg4;
}

//	diglett's pop out the ground on diglett's minigame
void func_87900344(minigameActor* arg0, s16 arg1, s16 arg2, s16 arg3) {
    arg0->unk_248 = 1;    //	colliding ?
    arg0->unk_24A = arg1; //	1
    arg0->unk_24C = arg2; // -1
    arg0->unk_26A = arg3; //	1
    arg0->unk_26C = 1;    //	animation id?
}

// just checks an object colliding flag?
s32 func_87900384(minigameActor* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_248 == 0) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_879003A0(minigameActor* arg0) {
    switch (arg0->unk_248) {
        case 1:
            func_8001BD04(&arg0->unk_000, arg0->unk_24A);
            if (arg0->unk_26C != 0) {
                func_800173DC(&arg0->unk_000, 0, arg0->unk_000.unk_040.unk_04, -0x10000);
                func_80017464(&arg0->unk_000, arg0->unk_000.unk_040.unk_04->unk_0A - 1);
            } else {
                func_800173DC(&arg0->unk_000, 0, arg0->unk_000.unk_040.unk_04, 0x10000);
                func_80017464(&arg0->unk_000, arg0->unk_26E);
                func_80017788(&arg0->unk_000);
                if (arg0->unk_24C != -1) {
                    func_8001BD9C(&arg0->unk_000, arg0->unk_24C);
                    func_80017804(&arg0->unk_000, arg0->unk_26E);
                }
            }
            arg0->unk_248++;
            break;

        case 2:
            if (arg0->unk_26C == 0) {
                if (func_800174E4(&arg0->unk_000) != 0) {
                    arg0->unk_248++;
                }
            } else {
                if (arg0->unk_000.unk_040.unk_08 == 0) {
                    arg0->unk_248++;
                }
            }
            break;

        case 3:
            if (arg0->unk_26A != 0) {
                func_8001BD04(&arg0->unk_000, 0);
            }
            arg0->unk_248 = 0;
            break;
    }
}

void func_879004F8(unk_D_86002F58_004_000* arg0) {
    func_80017464(arg0, arg0->unk_040.unk_04->unk_0A - 1);
}

void func_87900528(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();        // nothing
}

void hideMiniGameHUD(void) {
    showMinigameHUD = 0;
}

void func_87900564(minigameActor* actor) {
    actor->unk_1C0.x = 0.0f;
    actor->localOrigin.x = 0.0f;
    actor->unk_190.x = 0.0f;
    actor->unk_1C0.y = 0.0f;
    actor->localOrigin.y = 0.0f;
    actor->unk_190.y = 0.0f;
    actor->unk_1C0.z = 0.0f;
    actor->localOrigin.z = 0.0f;
    actor->unk_190.z = 0.0f;
}

void minigameActorLocalOriginToZero(minigameActor* arg0) {
    arg0->localOrigin.x = 0.0f;
    arg0->localOrigin.y = 0.0f;
    arg0->localOrigin.z = 0.0f;
}

void func_879005AC(minigameActor* arg0) {
    arg0->unk_1C0.x = 0.0f;
    arg0->unk_1C0.y = 0.0f;
    arg0->unk_1C0.z = 0.0f;
}

void func_879005C4(minigameActor* ekans) {
    ekans->unk_1FC = ekans->unk_1FC - ekans->unk_210;
    ekans->unk_1C0.x = ekans->unk_1C0.x + ekans->unk_1F8;
    ekans->unk_1C0.y = ekans->unk_1C0.y + (ekans->unk_1FC - ekans->unk_210);
    ekans->unk_1C0.z = ekans->unk_1C0.z + ekans->unk_200;
}

void func_8790060C(minigameActor* actor) {
    actor->unk_214.x = actor->unk_214.y = actor->unk_214.z = 0;
    actor->unk_21A = actor->unk_21C = actor->unk_21E = 0;
    actor->unk_220 = actor->unk_222 = actor->unk_224 = 0;
    actor->unk_226 = actor->unk_228 = actor->unk_22A = 0;
    actor->unk_22C = actor->unk_22E = actor->unk_230 = 0;
    actor->unk_232 = actor->unk_234 = actor->unk_236 = 0;
    actor->unk_23E = actor->unk_240 = actor->unk_242 = actor->unk_248 = 0;

    actor->unk_254 = 0;
    actor->unk_272 = 0;
    actor->unk_238 = 0;
    actor->unk_25A = 0;
    actor->unk_2A8 = 0;
    actor->unk_2A4 = 0;
    actor->unk_2A2 = 0;
    actor->unk_29A = 0;
    actor->unk_2AA = 0;
    actor->unk_29C = 0;
    actor->unk_2A0 = 0;
    actor->unk_29E = 0;
    actor->unk_296 = 0;
    actor->unk_298 = 0;

    actor->scale.x = actor->scale.y = actor->scale.z = 1.0f;
    actor->unk_190.x = actor->unk_190.y = actor->unk_190.z = 0.0f;
    actor->localOrigin.x = actor->localOrigin.y = actor->localOrigin.z = 0.0f;

    actor->unk_1B4.z = 0.0f;
    actor->unk_1B4.y = 0.0f;
    actor->unk_1B4.x = 0.0f;
    actor->unk_1C0.x = actor->unk_1C0.y = actor->unk_1C0.z = 0.0f;

    actor->unk_1D4 = 0.0f;
    actor->unk_1D0 = 0.0f;
    actor->unk_1CC = 0.0f;
    actor->unk_1E4 = 0.0f;
    actor->unk_210 = 0.0f;
    actor->unk_20C = 0.0f;
    actor->unk_208 = 0.0f;
    actor->unk_204 = 0.0f;
    actor->unk_200 = 0.0f;
    actor->unk_1FC = 0.0f;
    actor->unk_1F8 = 0.0f;
    actor->unk_1F4 = 0.0f;
    actor->unk_1F0 = 0.0f;
    actor->unk_1EC = 0.0f;
    actor->unk_284 = 0.0f;
    actor->unk_280 = 0.0f;
    actor->unk_27C = 0.0f;
    actor->unk_274 = 0.0f;

    actor->unk_260 = actor->unk_262 = actor->unk_264 = actor->unk_266 = 0;
    actor->unk_290 = actor->unk_292 = actor->unk_294 = 0;
}

void func_87900770(minigameActor* poke) {
    poke->unk_190.x = poke->unk_19C.x = poke->localOrigin.x + poke->unk_1C0.x;
    poke->unk_190.y = poke->unk_19C.y = poke->localOrigin.y + poke->unk_1C0.y;
    poke->unk_190.z = poke->unk_19C.z = poke->localOrigin.z + poke->unk_1C0.z;

    poke->unk_19C.y = poke->unk_19C.y + poke->unk_1E4;

    poke->unk_214.x = poke->unk_21A + poke->unk_226 + poke->unk_232;
    poke->unk_214.y = poke->unk_21C + poke->unk_228 + poke->unk_234;
    poke->unk_214.z = poke->unk_21E + poke->unk_22A + poke->unk_236;
}

void func_87900808(minigameActor* arg0) {
    arg0->unk_000.unk_030.x = arg0->scale.x;
    arg0->unk_000.unk_030.y = arg0->scale.y;
    arg0->unk_000.unk_030.z = arg0->scale.z;

    arg0->unk_000.unk_024.x = arg0->unk_190.x;
    arg0->unk_000.unk_024.y = arg0->unk_190.y;
    arg0->unk_000.unk_024.z = arg0->unk_190.z;

    arg0->unk_000.unk_01E.x = arg0->unk_214.x;
    arg0->unk_000.unk_01E.y = arg0->unk_214.y;
    arg0->unk_000.unk_01E.z = arg0->unk_214.z;
}

void func_87900854(void) {
    s16* ptr = D_8780FA30;

    minigameInputLock = 0;
    D_87903DA8 = 0;
    D_87903DAC = 0;
    minigameInputLockTimer = 0;
    D_87906048 = 0;
    D_8790604A = 0;
    D_87903DC0 = 0;
    D_87903DC4 = 0;
    D_87903DC8 = 0;
    D_87903DCC = 0;
    D_87903DD0 = 0;
    D_87906072 = 0;

    func_878029C0();
    func_87802528();

    D_879060C4[0] = ptr[0];
    D_879060C4[1] = ptr[1];
    D_879060C4[2] = ptr[2];
    D_879060C4[3] = ptr[3];

    minigameHUDTransparency = 0xFF;
}

void func_87900920(void) {
    D_8790607C = minigameCameraDistance;
    D_87906080 = minigameCameraFOV;

    D_87906088.x = minigameCameraCoords.x;
    D_87906088.y = minigameCameraCoords.y;
    D_87906088.z = minigameCameraCoords.z;

    D_87906076 = minigameCameraXRot;
    D_87906078 = minigameCameraYRot;
}

void func_879009B4(void) {
    minigameCameraDistance = D_8790607C;
    minigameCameraFOV = D_87906080;

    minigameCameraCoords.x = D_87906088.x;
    minigameCameraCoords.y = D_87906088.y;
    minigameCameraCoords.z = D_87906088.z;

    minigameCameraXRot = D_87906076;
    minigameCameraYRot = D_87906078;
}
