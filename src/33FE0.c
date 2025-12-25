#include "global.h"
#include "33FE0.h"
#include "12D80.h"
#include "32D10.h"

typedef struct SomeStruct {
    u32 padding[0x0C];
} SomeStruct; // size = 0x30

extern s16 D_800763B0[];
extern s16 D_800765B4[];
extern s16 D_800767B8[0x102];
extern s16 D_800769BC[0x102];
extern s16 D_80076BC0[0x102];
extern s16 D_80076DC4[0x102];
extern s16 D_80076FC8[0x102];
extern s16 D_800771CC[0x102];
extern s16 D_800773D0[0x102];
extern f32 D_800775D4[];
extern f32 D_8007C5D0;
extern f32 D_8007C5D4;
extern f32 D_8007C5D8;
extern f32 D_8007C5DC;
extern f32 D_8007C5E0;
extern f32 D_8007C5E4;
extern f32 D_8007C5E8;
extern f32 D_8007C5EC;
extern Mtx D_800B3258;
extern Vec3fCounter* D_800B2F50;
extern SomeStruct* D_800B2F58[0x10];

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

f32 func_8003342C(f32 value) {
    if (value < 0.0f) {
        value = -value;
    }
    return value;
}

void func_80033450(f32 ax, f32 ay, f32 az, f32 bx, f32 by, f32 bz, f32* cx, f32* cy, f32* cz) {
    *cx = (ay * bz) - (az * by);
    *cy = (az * bx) - (ax * bz);
    *cz = (ax * by) - (ay * bx);
}

#ifdef NON_MATCHING
f32 func_800334C0(
    f32 px, f32 py, f32 pz,
    f32 ax, f32 ay, f32 az,
    f32 bx, f32 by, f32 bz
) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 lenSq;
    f32 dot;

    dx = bx - ax;
    dy = by - ay;
    dz = bz - az;

    lenSq = (dx * dx) + (dy * dy) + (dz * dz);

    if (lenSq == 0.0f) {
        return 0.0f;
    }

    dot = (dx * (px - ax))
        + (dy * (py - ay))
        + (dz * (pz - az));

    return dot / lenSq;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_800334C0.s")
#endif

#ifdef NON_MATCHING
f32 func_80033568(
    f32 px, f32 py, f32 pz,
    f32 ax, f32 ay, f32 az,
    f32 bx, f32 by, f32 bz,
    f32* outX, f32* outY, f32* outZ
) {
    f32 dx = bx - ax;
    f32 dy = by - ay;
    f32 dz = bz - az;
    f32 ex;
    f32 ey;
    f32 ez;
    f32 lenSq;
    f32 t;

    lenSq = (dx * dx) + (dy * dy) + (dz * dz);

    if (lenSq == 0.0f) {
        return -1.0f;
    }

    t = ((dx * (px - ax)) +
             (dy * (py - ay)) +
             (dz * (pz - az))) / lenSq;

    if (t < -0.5f || t > 1.5f) {
        return -2.0f;
    }

    *outX = ax + (t * dx);
    *outY = ay + (t * dy);
    *outZ = az + (t * dz);


    ex = *outX - px;
    ey = *outY - py;
    ez = *outZ - pz;

    return sqrtf((ex * ex) + (ey * ey) + (ez * ez));
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80033568.s")
#endif

s16 func_800336F8(s16* table, s32 index) {
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

s16 func_800337D8(s16* arg0, s32 arg1) {
    s16 temp_v0;
    s16 temp_v1;

    temp_v0 = arg0[arg1];
    temp_v1 = D_800765B4[temp_v0];

    if (temp_v1 > 0) {
        return temp_v1;
    }

    return 0;
}

s16 func_80033810(s16* arg0, s32 arg1) {
    s16 temp_v1;
    s16 temp_a2;
    temp_v1 = *(arg0 + arg1);
    temp_a2 = D_800763B0[temp_v1];
    return temp_a2;
}

s16 func_80033830(s16* arg0, s32 arg1) {
    s16 temp_v1;
    s16 temp_a2;
    temp_v1 = *(arg0 + arg1);
    temp_a2 = D_800767B8[temp_v1];
    return temp_a2;
}

s16 func_80033850(s16* arg0, s32 arg1) {
    s16 temp_v1;
    s16 temp_a2;
    temp_v1 = *(arg0 + arg1);
    temp_a2 = D_80076BC0[temp_v1];
    return temp_a2;
}

s16 func_80033870(s16* arg0, s32 arg1) {
    s16 temp_v1;
    s16 temp_a2;
    temp_v1 = *(arg0 + arg1);
    temp_a2 = D_80076DC4[temp_v1];
    return temp_a2;
}

s16 func_80033890(s16* arg0, s32 arg1) {
    s16 temp_v1;
    s16 temp_a2;
    temp_v1 = *(arg0 + arg1);
    temp_a2 = D_80076FC8[temp_v1];
    return temp_a2;
}

void func_800338B0(void) {

}

s16 func_800338B8(s16* arg0, s32 arg1) {
    s16 temp_v1;
    s16 temp_a2;
    temp_v1 = *(arg0 + arg1);
    temp_a2 = D_800773D0[temp_v1];
    return temp_a2;
}

#ifdef NON_MATCHING
void func_800338D8(StadiumModel* model, MtxF* mtx) {
    ModelSegment* segment;
    ModelVertex* base;
    ModelVertex* mvtx;
    Vtx* vtx;
    s16* indexTable;
    s16 temp_t0;
    s16 temp_v0_2;
    s16 var_a1;
    s16 var_s0;
    s16* temp_s2;
    s32 i;
    s32 var_a0;
    s32 var_s3;

    segment = Memmap_GetSegmentVaddr(model->modelSegment);
    base = &model->mvtx;
    mvtx = base;
    vtx = Memmap_GetSegmentVaddr(segment->vertexSegment);
    for(var_a0 = 0; var_a0 < segment->vertexCount;) {
        var_a0++;
        mvtx++;

        mvtx->position.base.x = (f32) vtx->v.ob[0];
        mvtx->position.base.y = (f32) vtx->v.ob[1];
        mvtx->position.base.z = (f32) vtx->v.ob[2];
        mvtx->colorR = (f32) vtx->v.cn[0];
        mvtx->colorG = (f32) vtx->v.cn[1];
        mvtx->colorB = (f32) vtx->v.cn[2];
        mvtx->texS = (s16) vtx->v.tc[0];
        mvtx->texT = (s16) vtx->v.tc[1];
        mvtx->position.offset.x = 0.0f;
        mvtx->position.offset.y = 0.0f;
        mvtx->position.offset.z = 0.0f;
        mvtx->disabled = 0;
        mvtx->drawGroup = 0;
        mvtx->alpha = vtx->v.cn[3];
        vtx++;
    }
    mvtx = base;
    func_800350E4(segment, mtx, base);
    for(var_s3 = 0; var_s3 < 0x10; var_s3++) {
        temp_s2 = Memmap_GetSegmentVaddr(segment->tableSegment);
        for(var_s0 = 0; var_s0 < segment->vertexCount; var_s0++) {
            if (var_s3 == (func_80033810(temp_s2, var_s0) & 0xFFFF)) {
                mvtx->jointIndex = var_s0;
                mvtx++;
            }
        }
    }
    mvtx = base;
    var_a1 = 0;
    indexTable = Memmap_GetSegmentVaddr(segment->unk_0C);
    for(i = 0; i < segment->vertexCount; i++) {
        mvtx->childIndex = var_a1;
        do {
            temp_v0_2 = *indexTable++;
            var_a1++;
        } while (temp_v0_2 != -1);
        mvtx++;
    }
    mvtx = base;
    for(i = 0; i < segment->vertexCount; i++) {
        temp_t0 = mvtx->jointIndex;
        mvtx->parentIndex = (s16) base[temp_t0].childIndex;
        mvtx++;
    }
}
#else
void func_800338D8(StadiumModel*, MtxF* mtx);
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_800338D8.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80033B2C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80033D1C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80033D44.s")

#ifdef NON_MATCHING
void func_80034254(StadiumModel* model) {
    static f32 D_8007C5B8 = 10000.0f;
    f32 var_fv0;
    s16 temp_v1;
    s32 j;
    ModelSegment* segment;
    s16* temp_v0_2;
    s16* var_t1;
    s32 i;
    ModelVertex* temp_a1;
    ModelVertex* var_a0;
    ModelVertex* var_a2;

    segment = Memmap_GetSegmentVaddr(model->modelSegment);
    temp_v0_2 = Memmap_GetSegmentVaddr(segment->tableSegment);
    temp_a1 = &model->mvtx;
    var_a2 = temp_a1;
    for(i = 0; i < segment->vertexCount; i++) {
        var_a2->nextIndex = -1;
        var_a2++;
    }
    var_a2 = temp_a1;
    var_t1 = temp_v0_2;
    for(i = 0; i < segment->vertexCount; i++) {
        temp_v1 = *var_t1++;
        if (temp_v1 == i) {
            var_fv0 = D_8007C5B8;
            var_a0 = var_a2;
            for(j = 0; j < model->unk_02; j++) {
                if (var_a0->unk_20 < var_fv0) {
                    var_fv0 = var_a0->unk_20;
                    var_a2->nextIndex = j;
                }
                var_a0 += 1;
            }
        }
        var_a2++;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80034254.s")
#endif

void func_80034348(ModelSegment*, ModelVertex*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80034348.s")

void func_80034824(ModelSegment*, StadiumTransform*, s32, ModelVertex*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80034824.s")

void func_80034B28(StadiumModel* model) {
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
    func_800359FC(segment, mvtx, model, 1.0f);
}

void func_80034BD4(StadiumModel*, StadiumTransform*, s32, ModelVertex*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80034BD4.s")

void func_80034F68(MtxF* mtx, Vec3f* out, Vec3s* in) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;

    sp34 = (f32) in->x;
    sp30 = (f32) in->y;
    sp2C = (f32) in->z;

    guMtxXFMF(mtx->mf, sp34, sp30, sp2C, &sp34, &sp30, &sp2C);

    out->x = sp34;
    out->y = sp30;
    out->z = sp2C;
}

void func_80035000(MtxF* mtx, PosBlend* position, Vec3s* target, f32 alpha) {
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 dx;
    f32 dy;
    f32 dz;

    sp44 = (f32) target->x;
    sp40 = (f32) target->y;
    sp3C = (f32) target->z;

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

void func_800350E4(ModelSegment* segment, MtxF* mtx, ModelVertex* mvtx) {
    s16* indexTable;
    s32 i;
    Vec3sPad* var_s3;
    PosBlend* position;
    ModelVertex* tmp;

    indexTable = Memmap_GetSegmentVaddr(segment->tableSegment);
    var_s3 = Memmap_GetSegmentVaddr(segment->vertexSegment);
    Memmap_GetSegmentVaddr(segment->remapSegment);
    tmp = mvtx;
    
    for(i = 0; i < segment->vertexCount; i++) {
        position = &tmp->position;
        switch (func_800336F8(indexTable, i)) {
            case 0:
            default:
                func_80034F68(mtx, &position->base, &var_s3->vec);
                position->offset.x = 0.0f;
                position->offset.y = 0.0f;
                position->offset.z = 0.0f;
                break;
            case 4:
                func_80034F68(mtx + func_80033890(indexTable, i), &position->base, &var_s3->vec);
                position->offset.x = 0.0f;
                position->offset.y = 0.0f;
                position->offset.z = 0.0f;
                break;
        }
        var_s3++;
        tmp++;
    }
}

void func_80035208(struct SomeStruct* src, struct SomeStruct* dst) {
    *dst = *src;
}

void func_80035208_empty() {

}

#ifdef NON_MATCHING
void func_80035248(ModelSegment* segment, MtxF* mtx, ModelVertex* mvtx) {
    Vec3sPad* var_s2;
    ModelVertex* tmp;
    s16* var_s7;
    s32 i;
    PosBlend* position;
    s16* temp_s5;
    s16 temp_v0;

    temp_s5 = Memmap_GetSegmentVaddr(segment->tableSegment);
    var_s2 = Memmap_GetSegmentVaddr(segment->vertexSegment);
    var_s7 = Memmap_GetSegmentVaddr(segment->remapSegment);
    tmp = mvtx;

    for(i = 0; i < segment->vertexCount; i++) {
        position = &tmp->position;
        if (i == *var_s7) {
            temp_v0 = func_800336F8(temp_s5, i);
            switch (temp_v0) {
            case 0:
                func_80034F68(mtx, &position->base, &var_s2->vec);
                break;
            case 4:
                func_80034F68(mtx + func_80033890(temp_s5, i), &position->base, &var_s2->vec);
                break;
            case 1:
                func_80035000(mtx, position, &var_s2->vec, D_800775D4[func_80033830(temp_s5, i)]);
                break;
            case 2:
                func_80034F68(mtx, &position->base, &var_s2->vec);
                func_80035208((SomeStruct*)&position->base, D_800B2F58[func_80033850(temp_s5, i)]);
                break;
            case 3:
                func_80034F68(mtx, &position->base, &var_s2->vec);
                func_80035208((SomeStruct*)&position->base, D_800B2F58[func_80033870(temp_s5, i)]);
                break;
            }
        }
        var_s2++;
        var_s7++;
        tmp++;
    }
}
#else
void func_80035248(ModelSegment*, MtxF*, ModelVertex*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80035248.s")
#endif

void func_80035434(Vec3f* a, Vec3f* b, Vec3f* scale) {
    f32 dx;
    f32 dy;
    f32 dz;

    dx = (a->x - b->x) / scale->x;
    dy = (a->y - b->y) / scale->y;
    dz = (a->z - b->z) / scale->z;

    if (func_8003342C(dx) < D_8007C5D0) {
        dx = 0.0f;
    }
    if (func_8003342C(dy) < D_8007C5D4) {
        dy = 0.0f;
    }
    if (func_8003342C(dz) < D_8007C5D8) {
        dz = 0.0f;
    }
    sqrtf((dx * dx) + (dy * dy) + (dz * dz));
}

void func_80035538(Vec3s* a, Vec3s* b) {
    f32 dx;
    f32 dy;
    f32 dz;

    dx = (f32) (a->x - b->x);
    dy = (f32) (a->y - b->y);
    dz = (f32) (a->z - b->z);
    sqrtf((dx * dx) + (dy * dy) + (dz * dz));
}

#ifdef NON_MATCHING
void func_800355A8(Vec3f* from, Vec3f* to, f32 currentTime, f32 deltaTime) {
    f32 sp14;
    f32 temp_ft4;
    f32 temp_fv1;
    f32 scale;

    if (deltaTime < D_8007C5DC) {
        return;
    }
    temp_ft4 = to->y;
    temp_fv1 = to->x;
    sp14 = to->z;
    scale = ((currentTime - deltaTime) / deltaTime);
    if (deltaTime < currentTime) {
        scale *= 0.5f;
    }
    to->x = (f32) (temp_fv1 + ((temp_fv1 - from->x) * scale));
    to->y = (f32) (temp_ft4 + ((temp_ft4 - from->y) * scale));
    to->z = (f32) (sp14 + ((sp14 - from->z) * scale));
}
#else
void func_800355A8(Vec3f*, Vec3f*, f32, f32);
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_800355A8.s")
#endif

#ifdef NON_MATCHING
void func_80035660(PosBlend* src, PosBlend* dst, f32 totalTime, f32 elapsed, f32 stiffness) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp20;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft1;
    f32 temp_ft2;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv1;
    f32 var_fv0;

    if (!(elapsed < D_8007C5E0)) {
        if (func_8003342C(dst->base.x) < D_8007C5E4) {
            dst->base.x = 0.0f;
        }
        if (func_8003342C(dst->base.y) < D_8007C5E8) {
            dst->base.y = 0.0f;
        }
        if (func_8003342C(dst->base.z) < D_8007C5EC) {
            dst->base.z = 0.0f;
        }
        temp_fa1 = dst->base.x;
        temp_ft1 = temp_fa1 - src->base.x;
        sp3C = temp_ft1;
        temp_ft4 = dst->base.y;
        sp38 = temp_ft4 - src->base.y;
        temp_ft5 = dst->base.z;
        sp34 = temp_ft5 - src->base.z;
        var_fv0 = stiffness * ((totalTime - elapsed) / elapsed);
        if (elapsed < totalTime) {
            var_fv0 *= 0.5f;
        }
        temp_fv1 = temp_ft1 * var_fv0;
        dst->base.x = (f32) (temp_fa1 + temp_fv1);
        temp_fa0 = sp38 * var_fv0;
        dst->base.y = (f32) (temp_ft4 + temp_fa0);
        temp_ft2 = sp34 * var_fv0;
        sp20 = temp_ft2;
        dst->base.z = (f32) (temp_ft5 + temp_ft2);
        dst->offset.x += temp_fv1;
        dst->offset.y += temp_fa0;
        dst->offset.z += sp20;
    }
}
#else
void func_80035660(PosBlend*, PosBlend*, f32, f32, f32);
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80035660.s")
#endif

void func_800357F4(StadiumModel*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_800357F4.s")

#ifdef NON_MATCHING
void func_800359FC(ModelSegment* segment, ModelVertex* vertices, StadiumModel* model, f32 deltaTime) {
    f32 temp_fs0;
    s16 temp_v1;
    s16 var_a0;
    s16 var_a2;
    ModelVertex* temp_a3;
    Vec3f* temp_s0;
    Vec3f* temp_s1;
    ModelTransformCmd* temp_v0;
    ModelVertex* temp_v0_2;
    ModelVertex* var_s2;

    Memmap_GetSegmentVaddr(segment->remapSegment);
    var_s2 = vertices;
    while(1) {
        temp_v0 = (ModelTransformCmd*)var_s2 + 8;
        temp_v1 = var_s2->cmd.targetIndex;
        var_s2++;
        if (temp_v1 == -1) {
            break;
        }
        var_a2 = temp_v0->enableFrom;
        var_a0 = temp_v0->enableTo;
        temp_fs0 = temp_v0->blendWeight;
        temp_a3 = &vertices[temp_v1];
        if (temp_a3->disabled != 0) {
            var_a2 = 0;
        }
        temp_v0_2 = &vertices[temp_v0->sourceIndex];
        if (temp_v0_2->disabled != 0) {
            var_a0 = 0;
        }
        if ((var_a0 != 0) || (var_a2 != 0)) {
            temp_s0 = &temp_a3->position.base;
            temp_s1 = &temp_v0_2->position.base;
            func_80035434(temp_s0, temp_s1, &model->position);
            func_800355A8(temp_s0, temp_s1, temp_fs0, deltaTime);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_800359FC.s")
#endif

void func_80035B20(ModelSegment*, ModelVertex*, StadiumModel*, f32);
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80035B20.s")

void func_80035C4C(ModelSegment* segment, ModelVertex* vertices, f32 yOffset) {
    s16* indexTable;
    s16* remap;
    s32 i;
    ModelVertex* tmp;

    indexTable = Memmap_GetSegmentVaddr(segment->tableSegment);
    remap = Memmap_GetSegmentVaddr(segment->remapSegment);
    tmp = vertices;
    for(i = 0; i < segment->vertexCount; i++) {
        if ((func_800336F8(indexTable, i) != 0) && (i == *remap)) {
            tmp->position.base.y += yOffset;
        }
        tmp++;
        remap++;
    }
}

#ifdef NON_MATCHING
void func_80035D08(ModelSegment* segment, ModelVertex* vertices, f32 yOffset) {
    s16* indexTable;
    s16* var_s2;
    s32 temp_v0;
    s32 i;
    ModelVertex* tmp;
    PosBlend* temp_v0_2;
    PosBlend* temp_v0_3;

    indexTable = Memmap_GetSegmentVaddr(segment->tableSegment);
    var_s2 = Memmap_GetSegmentVaddr(segment->remapSegment);
    tmp = vertices;
    for(i = 0; i < segment->vertexCount; i++) {
        if ((func_800336F8(indexTable, i) != 0) && (i == *var_s2)) {
            temp_v0 = func_800338B8(indexTable, i);
            switch (temp_v0) {                  /* irregular */
            case 1:
                temp_v0_2 = &tmp->position;
                temp_v0_2->base.y += yOffset;
                break;
            case 2:
                temp_v0_3 = &tmp->position;
                temp_v0_3->base.y += yOffset * 0.25f;
                break;
            }
        }
        tmp++;
        var_s2++;
    }
}
#else
void func_80035D08(ModelSegment*, ModelVertex*, f32);
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80035D08.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80035E2C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80035FA8.s")

void func_800361C4(StadiumModel* model, MtxF*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_800361C4.s")

void func_8003658C(StadiumModel* model, Vtx* vtxBuf) {
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
        vtx->v.cn[0] = (s16)mvtx->colorR;
        vtx->v.cn[1] = (s16)mvtx->colorG;
        vtx->v.cn[2] = (s16)mvtx->colorB;
        vtx->v.tc[0] = mvtx->texS;
        vtx->v.tc[1] = mvtx->texT;
        vtx->v.cn[3] = mvtx->alpha;
        vtx++;
        mvtx++;
    }
}

Gfx* func_800366A4(Gfx* gfx, StadiumModel* model, Vtx* vtxBuf) {
    ModelSegment* segment;

    segment = Memmap_GetSegmentVaddr(model->modelSegment);
    if ((s32) segment->type >= 0xC) {
        return gfx;
    }
    func_8003658C(model, vtxBuf);
    gSPSegment(gfx++, 0x0E, vtxBuf);
    gSPMatrix(gfx++, &D_800B3258, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPDisplayList(gfx++, segment->displayList);
    gSPPopMatrixN(gfx++, G_MTX_MODELVIEW, 1);
    return gfx;
}
