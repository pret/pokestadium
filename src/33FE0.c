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

#ifdef NON_MATCHING
void func_800357F4(StadiumModel*);
void func_80033D1C(StadiumModel* model, MtxF* mtx) {
    func_800338D8(model, mtx);
    func_800357F4(model);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80033D1C.s")
#endif

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
#ifdef NON_MATCHING
// Smooth vertex normals: accumulate each triangle's (length-120) face normal
// into its three vertices, then store the per-vertex average as the color.
void func_80034348(ModelSegment* arg0, ModelVertex* arg1) {
    Vec3fCounter* acc;
    ModelVertex* vtx;
    ModelVertex* v0;
    ModelVertex* v1;
    ModelVertex* v2;
    s16* tri;
    s16* remap;
    s16 triangleCount;
    s16 vertexCount;
    s16 a, b, c;
    s16 n;
    s32 i;
    f32 e1x, e1y, e1z;
    f32 e2x, e2y, e2z;
    f32 nx, ny, nz;
    f32 len;
    f32 scale;
    f32 fn;

    triangleCount = arg0->triangleCount;
    vertexCount = arg0->vertexCount;
    tri = (s16*) Memmap_GetSegmentVaddr(arg0->indexSegment);
    remap = (s16*) Memmap_GetSegmentVaddr(arg0->remapSegment);

    for (i = 0; i < vertexCount; i++) {
        D_800B2F50[i].vec.x = 0.0f;
        D_800B2F50[i].vec.y = 0.0f;
        D_800B2F50[i].vec.z = 0.0f;
        D_800B2F50[i].count = 0;
    }

    for (i = 0; i < triangleCount; i++) {
        a = remap[tri[0]];
        b = remap[tri[1]];
        c = remap[tri[2]];
        tri += 3;
        v0 = &arg1[a];
        v1 = &arg1[b];
        v2 = &arg1[c];
        e1x = v1->position.base.x - v0->position.base.x;
        e1y = v1->position.base.y - v0->position.base.y;
        e1z = v1->position.base.z - v0->position.base.z;
        e2x = v2->position.base.x - v1->position.base.x;
        e2y = v2->position.base.y - v1->position.base.y;
        e2z = v2->position.base.z - v1->position.base.z;
        nx = (e1y * e2z) - (e1z * e2y);
        ny = (e1z * e2x) - (e1x * e2z);
        nz = (e1x * e2y) - (e1y * e2x);
        len = sqrtf((nx * nx) + (ny * ny) + (nz * nz));
        if ((s32) len > 0) {
            scale = 120.0f / len;
            nx *= scale;
            ny *= scale;
            nz *= scale;
        }
        acc = &D_800B2F50[a];
        acc->vec.x += nx;
        acc->vec.y += ny;
        acc->vec.z += nz;
        acc->count += 1;
        acc = &D_800B2F50[b];
        acc->vec.x += nx;
        acc->vec.y += ny;
        acc->vec.z += nz;
        acc->count += 1;
        acc = &D_800B2F50[c];
        acc->vec.x += nx;
        acc->vec.y += ny;
        acc->vec.z += nz;
        acc->count += 1;
    }

    vtx = arg1;
    for (i = 0; i < vertexCount; i++) {
        n = D_800B2F50[i].count;
        if (n > 0) {
            fn = (f32) n;
            vtx->colorR = D_800B2F50[i].vec.x / fn;
            vtx->colorG = D_800B2F50[i].vec.y / fn;
            vtx->colorB = D_800B2F50[i].vec.z / fn;
        }
        vtx += 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80034348.s")
#endif

void func_80034824(ModelSegment*, StadiumTransform*, s32, ModelVertex*);
#ifdef NON_MATCHING
// Barycentric deform: transform a StadiumTransform's 4 corners by its matrix,
// then set each flagged vertex's offset to the interpolated corner minus base.
void func_80034824(ModelSegment* arg0, StadiumTransform* arg1, s32 arg2, ModelVertex* arg3) {
    ModelVertex* vtx;
    PosBlend* pos;
    s16* indexTable;
    s16* remap;
    MtxF* mtx;
    f32* weights;
    s16 vi;
    s16 vertexCount;
    s32 i;
    f32 p0x, p0y, p0z;
    f32 p1x, p1y, p1z;
    f32 p2x, p2y, p2z;
    f32 p3x, p3y, p3z;
    f32 e2x, e2y, e2z;
    f32 e3x, e3y, e3z;
    f32 w0, w1, w2;

    vertexCount = arg0->vertexCount;
    remap = (s16*) Memmap_GetSegmentVaddr(arg0->remapSegment);
    indexTable = (s16*) Memmap_GetSegmentVaddr(arg0->tableSegment);
    mtx = arg1->mtx;
    guMtxXFMF((f32(*)[4]) mtx, arg1->x0, arg1->y0, arg1->z0, &p0x, &p0y, &p0z);
    guMtxXFMF((f32(*)[4]) mtx, arg1->x1, arg1->y1, arg1->z1, &p1x, &p1y, &p1z);
    guMtxXFMF((f32(*)[4]) mtx, arg1->x2, arg1->y2, arg1->z2, &p2x, &p2y, &p2z);
    guMtxXFMF((f32(*)[4]) mtx, arg1->x3, arg1->y3, arg1->z3, &p3x, &p3y, &p3z);
    vtx = arg3;
    i = 0;
    e2x = p2x - p0x;
    e2y = p2y - p0y;
    e2z = p2z - p0z;
    e3x = p3x - p0x;
    e3y = p3y - p0y;
    e3z = p3z - p0z;
    if (vertexCount > 0) {
        do {
            vi = *remap;
            remap += 1;
            if (func_800336F8(indexTable, vi) != 0) {
                pos = &vtx->position;
                if (vi == i) {
                    weights = (f32*) ((u8*) vtx + (arg2 * 0x10));
                    if (arg2 == vtx->nextIndex) {
                        w0 = weights[5];
                        w1 = weights[6];
                        w2 = weights[7];
                        vtx->disabled = (u16) (vtx->disabled | (1 << arg2));
                        pos->offset.x = ((w0 * (p1x - p0x)) + p0x + (w1 * e2x) + (w2 * e3x)) - pos->base.x;
                        pos->offset.y = ((w0 * (p1y - p0y)) + p0y + (w1 * e2y) + (w2 * e3y)) - pos->base.y;
                        pos->offset.z = ((w0 * (p1z - p0z)) + p0z + (w1 * e2z) + (w2 * e3z)) - pos->base.z;
                    }
                }
            }
            i += 1;
            vtx += 1;
        } while (i != vertexCount);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80034824.s")
#endif

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
#ifdef NON_MATCHING
// Like func_80034824, but only deforms a vertex when its projection onto the
// transform's p0->p1 edge lies within (0, maxDist); otherwise clears the bit.
void func_80034BD4(StadiumModel* arg0, StadiumTransform* arg1, s32 arg2, ModelVertex* arg3) {
    ModelSegment* segment;
    ModelVertex* vtx;
    PosBlend* pos;
    s16* indexTable;
    s16* remap;
    MtxF* mtx;
    f32* weights;
    s16 vertexCount;
    s16 vi;
    s32 i;
    s32 bit;
    f32 bx, by, bz;
    f32 outX, outY, outZ;
    f32 dist;
    f32 w0, w1, w2;
    f32 p0x, p0y, p0z;
    f32 p1x, p1y, p1z;
    f32 p2x, p2y, p2z;
    f32 p3x, p3y, p3z;

    segment = (ModelSegment*) Memmap_GetSegmentVaddr((u32) arg0);
    vertexCount = segment->vertexCount;
    remap = (s16*) Memmap_GetSegmentVaddr(segment->remapSegment);
    indexTable = (s16*) Memmap_GetSegmentVaddr(segment->tableSegment);
    mtx = arg1->mtx;
    guMtxXFMF((f32(*)[4]) mtx, arg1->x0, arg1->y0, arg1->z0, &p0x, &p0y, &p0z);
    guMtxXFMF((f32(*)[4]) mtx, arg1->x1, arg1->y1, arg1->z1, &p1x, &p1y, &p1z);
    guMtxXFMF((f32(*)[4]) mtx, arg1->x2, arg1->y2, arg1->z2, &p2x, &p2y, &p2z);
    guMtxXFMF((f32(*)[4]) mtx, arg1->x3, arg1->y3, arg1->z3, &p3x, &p3y, &p3z);
    vtx = arg3;
    i = 0;
    if (vertexCount > 0) {
        do {
            vi = *remap;
            if ((func_800336F8(indexTable, vi) != 0) && (vi == i)) {
                bx = vtx->position.base.x;
                by = vtx->position.base.y;
                bz = vtx->position.base.z;
                bit = 1 << arg2;
                dist = func_80033568(bx, by, bz, p0x, p0y, p0z, p1x, p1y, p1z, &outX, &outY, &outZ);
                pos = &vtx->position;
                if ((dist > 0.0f) && (dist < arg1->maxDist)) {
                    weights = (f32*) ((u8*) vtx + (arg2 * 0x10));
                    w0 = weights[5];
                    w1 = weights[6];
                    w2 = weights[7];
                    vtx->disabled = (u16) (vtx->disabled | bit);
                    pos->offset.x = (((w0 * (p1x - p0x)) + p0x + (w1 * (p2x - p0x)) + (w2 * (p3x - p0x))) - bx) * 1.0f;
                    pos->offset.y = (((w0 * (p1y - p0y)) + p0y + (w1 * (p2y - p0y)) + (w2 * (p3y - p0y))) - by) * 1.0f;
                    pos->offset.z = (((w0 * (p1z - p0z)) + p0z + (w1 * (p2z - p0z)) + (w2 * (p3z - p0z))) - bz) * 1.0f;
                } else {
                    vtx->disabled = (u16) (vtx->disabled & ~bit);
                }
            }
            i += 1;
            remap += 1;
            vtx += 1;
        } while (i != vertexCount);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80034BD4.s")
#endif

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

#ifdef NON_MATCHING
// Per-vertex Y nudge for flagged vertices (mode 1: +arg2; mode 2: +0.25*arg2).
void func_80035E2C(ModelSegment* segment, ModelVertex* arg1, f32 arg2, StadiumModel* arg3) {
    s16* indexTable;
    s16* remap;
    ModelVertex* vtx;
    s16 mode;
    s32 i;

    indexTable = (s16*) Memmap_GetSegmentVaddr(segment->tableSegment);
    remap = (s16*) Memmap_GetSegmentVaddr(segment->remapSegment);
    vtx = arg1;
    for (i = 0; i < segment->vertexCount; i++) {
        if ((func_800336F8(indexTable, i) != 0) && (i == *remap)) {
            mode = func_800338B8(indexTable, i);
            switch (mode) {
            case 1:
                vtx->position.base.x += 0.0f;
                vtx->position.base.y += arg2 * 1.0f;
                vtx->position.base.z += 0.0f;
                break;
            case 2:
                vtx->position.base.x += 0.0f;
                vtx->position.base.z += 0.0f;
                vtx->position.base.y += 0.25f * arg2 * 1.0f;
                break;
            }
        }
        vtx += 1;
        remap += 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80035E2C.s")
#endif

#ifdef NON_MATCHING
extern f32 D_8007C5F0;
extern f32 D_8007C5F4;
// Settle each flagged vertex: zero tiny offsets, fold the accumulated offset
// (averaged by drawGroup count) into base, then decay the offset by stiffness.
void func_80035FA8(ModelSegment* arg0, ModelVertex* arg1) {
    ModelVertex* vtx;
    PosBlend* pos;
    s16* indexTable;
    s16* remap;
    s32 i;
    f32 threshold;
    f32 stiffness;
    f32 fx;
    f32 fy;
    f32 fz;
    f32 ftz;
    f32 divisor;
    u16 count;

    vtx = arg1;
    indexTable = (s16*) Memmap_GetSegmentVaddr(arg0->tableSegment);
    remap = (s16*) Memmap_GetSegmentVaddr(arg0->remapSegment);
    if (arg0->vertexCount > 0) {
        threshold = D_8007C5F0;
        stiffness = D_8007C5F4;
        i = 0;
        do {
            pos = &vtx->position;
            if ((func_800336F8(indexTable, i) != 0) && (i == *remap)) {
                if (func_8003342C(pos->offset.x) < threshold) {
                    pos->offset.x = 0.0f;
                }
                if (func_8003342C(pos->offset.y) < threshold) {
                    pos->offset.y = 0.0f;
                }
                if (func_8003342C(pos->offset.z) < threshold) {
                    pos->offset.z = 0.0f;
                }
                count = vtx->drawGroup;
                fx = pos->offset.x;
                fy = pos->offset.y;
                fz = pos->offset.z;
                if ((s32) count > 0) {
                    divisor = (f32) count;
                    pos->base.x += fx / divisor;
                    pos->base.y += fy / divisor;
                    pos->base.z += fz / divisor;
                } else {
                    pos->base.x += fx;
                    pos->base.y += fy;
                    pos->base.z += fz;
                }
                pos->offset.x = fx - (stiffness * fx);
                ftz = fz - (stiffness * fz);
                pos->offset.y = fy - (stiffness * fy);
                pos->offset.z = ftz;
            }
            vtx->drawGroup = 0;
            i += 1;
            vtx += 1;
            remap += 1;
        } while (i < arg0->vertexCount);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_80035FA8.s")
#endif

void func_800361C4(StadiumModel* model, MtxF*);
#ifdef NON_MATCHING
// Dispatch a model's per-frame transform pass by model type, then apply the
// vertex remap table (copying the 0x30-byte pos/color/tex tail between vertices).
void func_800361C4(StadiumModel* model, MtxF* arg1) {
    ModelSegment* segment;
    ModelVertex* vtx;
    s16* remap;
    StadiumTransform* transform;
    s32 i;

    segment = (ModelSegment*) Memmap_GetSegmentVaddr(model->modelSegment);
    vtx = &model->mvtx;
    switch (segment->type) {
    case 3:
        func_80035248(segment, arg1, vtx);
        func_80035C4C(segment, vtx, model->position.y * -10.0f);
        func_80034348(segment, vtx);
        transform = model->transforms;
        for (i = 0; i < model->unk_02; i++) {
            func_80034BD4((StadiumModel*) segment, transform, i, vtx);
            transform += 1;
        }
        func_80035FA8(segment, vtx);
        func_800359FC(segment, vtx, model, 0.7f);
        break;
    case 4:
        func_80035248(segment, arg1, vtx);
        func_80035C4C(segment, vtx, model->position.y * -10.0f);
        func_80034348(segment, vtx);
        func_80035FA8(segment, vtx);
        break;
    case 10:
        func_80035248(segment, arg1, vtx);
        func_80035D08(segment, vtx, model->position.y * 160.0f);
        func_80035FA8(segment, vtx);
        func_80035B20(segment, vtx, model, 1.0f);
        break;
    case 11:
        func_80035248(segment, arg1, vtx);
        func_80035E2C(segment, vtx, 160.0f, model);
        func_80035FA8(segment, vtx);
        func_80035B20(segment, vtx, model, 1.0f);
        break;
    case 1:
        func_80035248(segment, arg1, vtx);
        func_80034348(segment, vtx);
        func_80035FA8(segment, vtx);
        break;
    case 2:
        func_80035248(segment, arg1, vtx);
        func_80035C4C(segment, vtx, model->position.y * -10.0f);
        func_80034348(segment, vtx);
        func_80035FA8(segment, vtx);
        break;
    case 5:
        func_80035248(segment, arg1, vtx);
        func_80034348(segment, vtx);
        func_80035FA8(segment, vtx);
        break;
    case 6:
        func_80035248(segment, arg1, vtx);
        func_80034348(segment, vtx);
        func_80035FA8(segment, vtx);
        break;
    case 9:
        func_80035248(segment, arg1, vtx);
        func_80034B28(model);
        func_80034348(segment, vtx);
        break;
    default:
        return;
    }

    remap = (s16*) Memmap_GetSegmentVaddr(segment->remapSegment);
    for (i = 0; i < segment->vertexCount; i++) {
        s16 src = remap[i];
        if (src != i) {
            s32* dst_p = (s32*) ((u8*) &vtx[i] + 0x64);
            s32* src_p = (s32*) ((u8*) &vtx[src] + 0x64);
            s32 j;
            for (j = 0; j < 0xC; j++) {
                dst_p[j] = src_p[j];
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/33FE0/func_800361C4.s")
#endif

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
