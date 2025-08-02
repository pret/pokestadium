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
s16 miniDebugMode = 0;
s32 pad_D_87903DB4 = 0;
s16 D_87903DB8 = 0;
s16 D_87903DBC = 0;
s16 D_87903DC0 = 0;
s16 miniTutoScreenState = 0;
s16 D_87903DC8 = 0;
s16 D_87903DCC = 0;
s16 D_87903DD0 = 0;
s16 D_87903DD4 = 0;

ret_func_80004454 func_87900020(void) {
    return func_87900020;
}

// func_8790002C
float MinigameGetVec3Distance_2d(MiniActor* arg0, MiniActor* arg1) {
    return sqrtf(SQ(arg1->totalPos_alt.x - arg0->totalPos_alt.x) + SQ(arg1->totalPos_alt.z - arg0->totalPos_alt.z));
}
// func_87900070
void MinigameGetVec3Distance_3d(MiniActor* arg0, MiniActor* arg1) {
    sqrtf(SQ(arg1->totalPos_alt.x - arg0->totalPos_alt.x) + SQ(arg1->totalPos_alt.y - arg0->totalPos_alt.y) +
          SQ(arg1->totalPos_alt.z - arg0->totalPos_alt.z));
}

//  unused,
s32 func_879000C4(MiniActor* arg0, MiniActor* arg1) {
    f32 totalX = arg1->totalPos_alt.x - arg0->totalPos_alt.x;
    f32 totalY = arg1->totalPos_alt.y - arg0->totalPos_alt.y;
    f32 totalZ = arg1->totalPos_alt.z - arg0->totalPos_alt.z;
    f32 totalTops = (arg0->cubeRadio * arg0->scale.y) + (arg1->cubeRadio * arg1->scale.y);
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

    if (totalTops < 0.0f) {
        totalTops = -totalTops;
    }

    if (CB(totalZ) < ((CB(totalTops) - CB(totalX)) - CB(totalY))) {
        ret = TRUE;
    }

    return ret;
}

s32 metapodRockCollisionCheck(MiniActor* fallingRock, MiniActor* metapod) {
    f32 totalX;
    f32 totalY;
    f32 totalZ;
    f32 var_fa1;
    f32 var_fs0;
    f32 tmp;
    s32 ret;

    totalX = metapod->totalPos_alt.x - fallingRock->totalPos_alt.x;
    totalY = metapod->totalPos_alt.y - fallingRock->totalPos_alt.y;
    totalZ = metapod->totalPos_alt.z - fallingRock->totalPos_alt.z;
    ret = 0;

    var_fa1 = (fallingRock->cubeRadio * fallingRock->scale.y) + (metapod->cubeRadio * metapod->scale.y);
    var_fs0 = ((fallingRock->halfHeight * fallingRock->scale.y) + (metapod->halfHeight * metapod->scale.y)) / 2.0f;

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

void miniChangeActorAnim(MiniActor* poke, s16 anim, s16 arg2, s16 arg3) {
    poke->unk_248 = 1;
    poke->unk_24A = anim;
    poke->unk_24C = arg2;
    poke->unk_26A = arg3;
    poke->unk_26C = 0;
    poke->unk_26E = 0;
}

//	unused
void miniChangeActorAnim_alt1(MiniActor* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk_248 = 1;
    arg0->unk_24A = arg1;
    arg0->unk_24C = arg2;
    arg0->unk_26A = arg3;
    arg0->unk_26C = 0;
    arg0->unk_26E = arg4;
}

void miniChangeActorAnim_alt2(MiniActor* diglett, s16 anim, s16 arg2, s16 arg3) {
    diglett->unk_248 = 1;
    diglett->unk_24A = anim;
    diglett->unk_24C = arg2;
    diglett->unk_26A = arg3;
    diglett->unk_26C = 1;
}

s32 miniPokeIsIdleCheck(MiniActor* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_248 == 0) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_879003A0(MiniActor* poke) {
    switch (poke->unk_248) {
        case 1:
            func_8001BD04(&poke->unk_000, poke->unk_24A);
            if (poke->unk_26C != 0) {
                func_800173DC(&poke->unk_000, 0, poke->unk_000.unk_040.unk_04, -0x10000);
                func_80017464(&poke->unk_000, poke->unk_000.unk_040.unk_04->unk_0A - 1);
            } else {
                func_800173DC(&poke->unk_000, 0, poke->unk_000.unk_040.unk_04, 0x10000);
                func_80017464(&poke->unk_000, poke->unk_26E);
                func_80017788(&poke->unk_000);
                if (poke->unk_24C != -1) {
                    func_8001BD9C(&poke->unk_000, poke->unk_24C);
                    func_80017804(&poke->unk_000, poke->unk_26E);
                }
            }
            poke->unk_248++;
            break;

        case 2:
            if (poke->unk_26C == 0) {
                if (func_800174E4(&poke->unk_000) != 0) {
                    poke->unk_248++;
                }
            } else {
                if (poke->unk_000.unk_040.unk_08 == 0) {
                    poke->unk_248++;
                }
            }
            break;

        case 3:
            if (poke->unk_26A != 0) {
                func_8001BD04(&poke->unk_000, 0);
            }
            poke->unk_248 = 0;
            break;
    }
}

void func_879004F8(unk_D_86002F58_004_000* arg0) {
    func_80017464(arg0, arg0->unk_040.unk_04->unk_0A - 1);
}

void func_87900528(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730(); // nothing
}

void hideMiniGameHUD(void) {
    miniShowHUB = 0;
}

void func_87900564(MiniActor* actor) {
    actor->position_2.x = 0.0f;
    actor->position_1.x = 0.0f;
    actor->totalPos.x = 0.0f;

    actor->position_2.y = 0.0f;
    actor->position_1.y = 0.0f;
    actor->totalPos.y = 0.0f;

    actor->position_2.z = 0.0f;
    actor->position_1.z = 0.0f;
    actor->totalPos.z = 0.0f;
}

void minigameActorLocalOriginToZero(MiniActor* arg0) {
    arg0->position_1.x = 0.0f;
    arg0->position_1.y = 0.0f;
    arg0->position_1.z = 0.0f;
}

void func_879005AC(MiniActor* arg0) {
    arg0->position_2.x = 0.0f;
    arg0->position_2.y = 0.0f;
    arg0->position_2.z = 0.0f;
}

void miniEkansUpdatePos(MiniActor* ekans) {
    ekans->ySpeed = ekans->ySpeed - ekans->antiAcceleration;
    ekans->position_2.x = ekans->position_2.x + ekans->xSpeed;
    ekans->position_2.y = ekans->position_2.y + (ekans->ySpeed - ekans->antiAcceleration);
    ekans->position_2.z = ekans->position_2.z + ekans->zSpeed;
}

void miniActorAllToZero(MiniActor* actor) {
    actor->totalRot.x = actor->totalRot.y = actor->totalRot.z = 0;
    actor->xRot_1 = actor->yRot_1 = actor->zRot_1 = 0;
    actor->unk_220 = actor->unk_222 = actor->unk_224 = 0;
    actor->xRot_2 = actor->yRot_2 = actor->zRot_2 = 0;
    actor->unk_22C = actor->ySpinSpeed = actor->unk_230 = 0;
    actor->xRot_3 = actor->yRot_3 = actor->zRot_3 = 0;
    actor->mainState = actor->isSquashed = actor->compState = actor->unk_248 = 0;

    actor->unk_254 = 0;
    actor->unk_272 = 0;
    actor->unk_238 = 0;
    actor->damageTimer = 0;
    actor->isWinner = 0;
    actor->unk_2A4 = 0;
    actor->ekansScore = 0;
    actor->unk_29A = 0;
    actor->unk_2AA = 0;
    actor->diglettIsGold = 0;
    actor->unk_2A0 = 0;
    actor->unk_29E = 0;
    actor->unk_296 = 0;
    actor->unk_298 = 0;

    actor->scale.x = actor->scale.y = actor->scale.z = 1.0f;
    actor->totalPos.x = actor->totalPos.y = actor->totalPos.z = 0.0f;
    actor->position_1.x = actor->position_1.y = actor->position_1.z = 0.0f;

    actor->closestDiglettPos.z = 0.0f;
    actor->closestDiglettPos.y = 0.0f;
    actor->closestDiglettPos.x = 0.0f;
    actor->position_2.x = actor->position_2.y = actor->position_2.z = 0.0f;

    actor->dist2DiglettLevelZ = 0.0f;
    actor->dist2DiglettLevelY = 0.0f;
    actor->dist2DiglettLevelX = 0.0f;
    actor->middleHeight = 0.0f;
    actor->antiAcceleration = 0.0f;
    actor->zAccel = 0.0f;
    actor->yAccel = 0.0f;
    actor->xAccel = 0.0f;
    actor->zSpeed = 0.0f;
    actor->ySpeed = 0.0f;
    actor->xSpeed = 0.0f;
    actor->unk_1F4 = 0.0f;
    actor->unk_1F0 = 0.0f;
    actor->unk_1EC = 0.0f;
    actor->stickMagnitude2 = 0.0f;
    actor->unk_280 = 0.0f;
    actor->diggingAccel2 = 0.0f;
    actor->unk_274 = 0.0f;

    actor->midAirState = actor->ekansIsMidAir = actor->unk_264 = actor->collidingActorId = 0;
    actor->unk_290 = actor->unk_292 = actor->unk_294 = 0;
}

void miniActorUpdateTransform(MiniActor* poke) {
    poke->totalPos.x = poke->totalPos_alt.x = poke->position_1.x + poke->position_2.x;
    poke->totalPos.y = poke->totalPos_alt.y = poke->position_1.y + poke->position_2.y;
    poke->totalPos.z = poke->totalPos_alt.z = poke->position_1.z + poke->position_2.z;

    poke->totalPos_alt.y = poke->totalPos_alt.y + poke->middleHeight;

    poke->totalRot.x = poke->xRot_1 + poke->xRot_2 + poke->xRot_3;
    poke->totalRot.y = poke->yRot_1 + poke->yRot_2 + poke->yRot_3;
    poke->totalRot.z = poke->zRot_1 + poke->zRot_2 + poke->zRot_3;
}

//  updates an object's collider ?
void func_87900808(MiniActor* arg0) {
    arg0->unk_000.unk_030.x = arg0->scale.x;
    arg0->unk_000.unk_030.y = arg0->scale.y;
    arg0->unk_000.unk_030.z = arg0->scale.z;

    arg0->unk_000.unk_024.x = arg0->totalPos.x;
    arg0->unk_000.unk_024.y = arg0->totalPos.y;
    arg0->unk_000.unk_024.z = arg0->totalPos.z;

    arg0->unk_000.unk_01E.x = arg0->totalRot.x;
    arg0->unk_000.unk_01E.y = arg0->totalRot.y;
    arg0->unk_000.unk_01E.z = arg0->totalRot.z;
}

void func_87900854(void) {
    s16* ptr = D_8780FA30;

    minigameInputLock = 0;
    D_87903DA8 = 0;
    D_87903DAC = 0;
    miniInputLockTimer = 0;
    D_87906048 = 0;
    D_8790604A = 0;
    D_87903DC0 = 0;
    miniTutoScreenState = 0;
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

    miniHudTransparency = 0xFF;
}

void func_87900920(void) {
    D_8790607C = miniCameraDistance;
    D_87906080 = miniCameraFov;

    D_87906088.x = miniCameraCoords.x;
    D_87906088.y = miniCameraCoords.y;
    D_87906088.z = miniCameraCoords.z;

    D_87906076 = miniCameraXRot;
    D_87906078 = miniCameraYRot;
}

void func_879009B4(void) {
    miniCameraDistance = D_8790607C;
    miniCameraFov = D_87906080;

    miniCameraCoords.x = D_87906088.x;
    miniCameraCoords.y = D_87906088.y;
    miniCameraCoords.z = D_87906088.z;

    miniCameraXRot = D_87906076;
    miniCameraYRot = D_87906078;
}
