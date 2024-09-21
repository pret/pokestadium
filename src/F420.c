#include "F420.h"
#include "src/math_util.h"

extern u16 D_80073660[];

Vec3f D_8006F050 = { 0.0f, 0.0f, 0.0f };
Vec3s D_8006F05C = { 0, 0, 0 };
Vec3f D_8006F064 = { 1.0f, 1.0f, 1.0f };
u16 D_8006F070[] = { 1, 1, 1 };

Color_RGBA8_u32* func_8000E820(Color_RGBA8_u32* arg0, u8 r, u8 g, u8 b) {
    arg0->r = r;
    arg0->g = g;
    arg0->b = b;

    return arg0;
}

Color_RGBA8_u32* func_8000E840(Color_RGBA8_u32* arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    arg0->r = arg1;
    arg0->g = arg2;
    arg0->b = arg3;
    arg0->a = arg4;

    return arg0;
}

Vec3f* func_8000E868(Vec3f* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->x = arg1;
    arg0->y = arg2;
    arg0->z = arg3;

    return arg0;
}

Vec3f* func_8000E88C(Vec3f* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->x = arg1;
    arg0->y = arg2;
    arg0->z = arg3;

    return arg0;
}

Vec3f* func_8000E8B0(Vec3f* arg0, Vec3f* arg1) {
    arg0->x += arg1->x;
    arg0->y += arg1->y;
    arg0->z += arg1->z;

    return arg0;
}

Vec3f* func_8000E8E8(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2) {
    arg0->x = arg1->x + arg2->x;
    arg0->y = arg1->y + arg2->y;
    arg0->z = arg1->z + arg2->z;

    return arg0;
}

Vec3f* func_8000E920(Vec3f* arg0, Vec3f* arg1) {
    arg0->x -= arg1->x;
    arg0->y -= arg1->y;
    arg0->z -= arg1->z;

    return arg0;
}

Vec3f* func_8000E958(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2) {
    arg0->x = arg1->x - arg2->x;
    arg0->y = arg1->y - arg2->y;
    arg0->z = arg1->z - arg2->z;

    return arg0;
}

Vec3f* func_8000E990(Vec3f* arg0, Vec3s* arg1) {
    arg0->x = arg1->x;
    arg0->y = arg1->y;
    arg0->z = arg1->z;

    return arg0;
}

Vec3f* func_8000E9D4(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3) {
    arg0->x = ((arg2->y - arg1->y) * (arg3->z - arg2->z)) - ((arg3->y - arg2->y) * (arg2->z - arg1->z));
    arg0->y = ((arg2->z - arg1->z) * (arg3->x - arg2->x)) - ((arg3->z - arg2->z) * (arg2->x - arg1->x));
    arg0->z = ((arg2->x - arg1->x) * (arg3->y - arg2->y)) - ((arg3->x - arg2->x) * (arg2->y - arg1->y));

    return arg0;
}

Vec3f* func_8000EA84(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2) {
    arg0->x = (arg1->y * arg2->z) - (arg2->y * arg1->z);
    arg0->y = (arg1->z * arg2->x) - (arg2->z * arg1->x);
    arg0->z = (arg1->x * arg2->y) - (arg2->x * arg1->y);

    return arg0;
}

Vec3f* func_8000EAF4(Vec3f* arg0) {
    f32 temp_fv1_2 = 1.0f / sqrtf(SQ(arg0->x) + SQ(arg0->y) + SQ(arg0->z));

    arg0->x *= temp_fv1_2;
    arg0->y *= temp_fv1_2;
    arg0->z *= temp_fv1_2;

    return arg0;
}

Vec3s* func_8000EB70(Vec3s* arg0, s16 arg1, s16 arg2, s16 arg3) {
    arg0->x = arg1;
    arg0->y = arg2;
    arg0->z = arg3;

    return arg0;
}

Vec3s* func_8000EBA8(Vec3s* arg0, Vec3s* arg1) {
    arg0->x += arg1->x;
    arg0->y += arg1->y;
    arg0->z += arg1->z;

    return arg0;
}

Vec3s* func_8000EBE0(Vec3s* arg0, Vec3s* arg1, Vec3s* arg2) {
    arg0->x = arg1->x + arg2->x;
    arg0->y = arg1->y + arg2->y;
    arg0->z = arg1->z + arg2->z;

    return arg0;
}

Vec3s* func_8000EC18(Vec3s* arg0, Vec3s* arg1) {
    arg0->x -= arg1->x;
    arg0->y -= arg1->y;
    arg0->z -= arg1->z;

    return arg0;
}

Vec3s* func_8000EC50(Vec3s* arg0, Vec3s* arg1, Vec3s* arg2) {
    arg0->x = arg1->x - arg2->x;
    arg0->y = arg1->y - arg2->y;
    arg0->z = arg1->z - arg2->z;

    return arg0;
}

Vec3s* func_8000EC88(Vec3s* arg0, Vec3f* arg1) {
    arg0->x = ROUND_MAX(arg1->x);
    arg0->y = ROUND_MAX(arg1->y);
    arg0->z = ROUND_MAX(arg1->z);

    return arg0;
}

void func_8000ED4C(MtxF* dest, MtxF* src) {
    if (dest != src) {
        s32 i;
        u32* d = (u32*)dest;
        u32* s = (u32*)src;

        for (i = 0; i < 16; i++) {
            *d++ = *s++;
        }
    }
}

void func_8000ED98(MtxF* arg0) {
    s32 i;
    f32* dest;
    // These loops must be one line to match on -O2
    // clang-format off
    
    // initialize everything except the first and last cells to 0
    for (dest = (f32*)arg0 + 1, i = 0; i < 14; dest++, i++) { *dest = 0.0f; }

    // initialize the diagonal cells to 1
    for (dest = (f32*)arg0, i = 0; i < 4; dest += 5, i++) { *dest = 1.0f; }
    // clang-format on
}

void func_8000EDD8(MtxF* arg0, Vec3f* arg1) {
    func_8000ED98(arg0);

    arg0->mf[3][0] = arg1->x;
    arg0->mf[3][1] = arg1->y;
    arg0->mf[3][2] = arg1->z;
}

void func_8000EE1C(MtxF* mtx, Vec3f* from, Vec3f* to, u16 roll) {
    f32 invLength;
    f32 dx;
    f32 dz;
    f32 xColY;
    f32 yColY;
    f32 zColY;
    f32 xColZ;
    f32 yColZ;
    f32 zColZ;
    f32 xColX;
    f32 yColX;
    f32 zColX;

    dx = to->x - from->x;
    dz = to->z - from->z;

    invLength = -1.0 / sqrtf(dx * dx + dz * dz);
    dx *= invLength;
    dz *= invLength;

    yColY = COSS(roll);
    xColY = SINS(roll) * dz;
    zColY = -SINS(roll) * dx;

    xColZ = to->x - from->x;
    yColZ = to->y - from->y;
    zColZ = to->z - from->z;

    invLength = -1.0 / sqrtf(xColZ * xColZ + yColZ * yColZ + zColZ * zColZ);
    xColZ *= invLength;
    yColZ *= invLength;
    zColZ *= invLength;

    xColX = yColY * zColZ - zColY * yColZ;
    yColX = zColY * xColZ - xColY * zColZ;
    zColX = xColY * yColZ - yColY * xColZ;

    invLength = 1.0 / sqrtf(xColX * xColX + yColX * yColX + zColX * zColX);

    xColX *= invLength;
    yColX *= invLength;
    zColX *= invLength;

    xColY = yColZ * zColX - zColZ * yColX;
    yColY = zColZ * xColX - xColZ * zColX;
    zColY = xColZ * yColX - yColZ * xColX;

    invLength = 1.0 / sqrtf(xColY * xColY + yColY * yColY + zColY * zColY);
    xColY *= invLength;
    yColY *= invLength;
    zColY *= invLength;

    mtx->mf[0][0] = xColX;
    mtx->mf[1][0] = yColX;
    mtx->mf[2][0] = zColX;
    mtx->mf[3][0] = -(from->x * xColX + from->y * yColX + from->z * zColX);

    mtx->mf[0][1] = xColY;
    mtx->mf[1][1] = yColY;
    mtx->mf[2][1] = zColY;
    mtx->mf[3][1] = -(from->x * xColY + from->y * yColY + from->z * zColY);

    mtx->mf[0][2] = xColZ;
    mtx->mf[1][2] = yColZ;
    mtx->mf[2][2] = zColZ;
    mtx->mf[3][2] = -(from->x * xColZ + from->y * yColZ + from->z * zColZ);

    mtx->mf[0][3] = 0.0f;
    mtx->mf[1][3] = 0.0f;
    mtx->mf[2][3] = 0.0f;
    mtx->mf[3][3] = 1.0f;
}

void func_8000F174(MtxF* dest, Vec3s* translate, Vec3s* rotate) {
    f32 sx = SINS(rotate->x);
    f32 cx = COSS(rotate->x);

    f32 sy = SINS(rotate->y);
    f32 cy = COSS(rotate->y);

    f32 sz = SINS(rotate->z);
    f32 cz = COSS(rotate->z);

    dest->mf[0][0] = cy * cz + (sx * sy) * sz;
    dest->mf[0][1] = -cy * sz + (sx * sy) * cz;
    dest->mf[0][2] = cx * sy;
    dest->mf[0][3] = translate->x;

    dest->mf[1][0] = cx * sz;
    dest->mf[1][1] = cx * cz;
    dest->mf[1][2] = -sx;
    dest->mf[1][3] = translate->y;

    dest->mf[2][0] = -sy * cz + (sx * cy) * sz;
    dest->mf[2][1] = sy * sz + (sx * cy) * cz;
    dest->mf[2][2] = cx * cy;
    dest->mf[2][3] = translate->z;

    dest->mf[3][0] = 0.0f;
    dest->mf[3][1] = 0.0f;
    dest->mf[3][2] = 0.0f;
    dest->mf[3][3] = 1.0f;
}

void func_8000F2C4(MtxF* arg0, Vec3f* arg1, Vec3s* arg2) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 sp0;

    temp_fv0 = SINS(arg2->x);
    temp_fv1 = COSS(arg2->x);

    temp_fa0 = SINS(arg2->y);
    temp_fa1 = COSS(arg2->y);

    temp_ft4 = SINS(arg2->z);
    temp_ft5 = COSS(arg2->z);

    sp0 = temp_fv0 * temp_fa0;
    arg0->mf[0][0] = (temp_fa1 * temp_ft5) + (sp0 * temp_ft4);
    arg0->mf[1][0] = (-temp_fa1 * temp_ft4) + (sp0 * temp_ft5);
    arg0->mf[2][0] = temp_fv1 * temp_fa0;
    arg0->mf[3][0] = arg1->x;

    arg0->mf[0][1] = temp_fv1 * temp_ft4;
    arg0->mf[1][1] = temp_fv1 * temp_ft5;
    arg0->mf[2][1] = -temp_fv0;
    arg0->mf[3][1] = arg1->y;

    sp0 = temp_fv0 * temp_fa1;
    arg0->mf[0][2] = (-temp_fa0 * temp_ft5) + (sp0 * temp_ft4);
    arg0->mf[1][2] = (temp_fa0 * temp_ft4) + (sp0 * temp_ft5);
    arg0->mf[2][2] = temp_fv1 * temp_fa1;
    arg0->mf[3][2] = arg1->z;

    arg0->mf[0][3] = 0.0f;
    arg0->mf[1][3] = 0.0f;
    arg0->mf[2][3] = 0.0f;
    arg0->mf[3][3] = 1.0f;
}

void func_8000F3FC(MtxF* arg0, Vec3f* arg1, Vec3s* arg2) {
    f32 sx = SINS(arg2->x);
    f32 cx = COSS(arg2->x);
    f32 sy = SINS(arg2->y);
    f32 cy = COSS(arg2->y);
    f32 sz = SINS(arg2->z);
    f32 cz = COSS(arg2->z);

    arg0->mf[0][0] = (cy * cz) + ((sx * sy) * sz);
    arg0->mf[0][1] = (-cy * sz) + ((sx * sy) * cz);
    arg0->mf[0][2] = cx * sy;

    arg0->mf[1][0] = cx * sz;
    arg0->mf[1][1] = cx * cz;
    arg0->mf[1][2] = -sx;

    arg0->mf[2][0] = (-sy * cz) + ((sx * cy) * sz);
    arg0->mf[2][1] = (sy * sz) + ((sx * cy) * cz);
    arg0->mf[2][2] = cx * cy;

    arg0->mf[3][0] = (arg0->mf[0][0] * arg1->x) + (arg0->mf[1][0] * arg1->y) + (arg0->mf[2][0] * arg1->z);
    arg0->mf[3][1] = (arg0->mf[0][1] * arg1->x) + (arg0->mf[1][1] * arg1->y) + (arg0->mf[2][1] * arg1->z);
    arg0->mf[3][2] = (arg0->mf[0][2] * arg1->x) + (arg0->mf[1][2] * arg1->y) + (arg0->mf[2][2] * arg1->z);

    arg0->mf[0][3] = arg0->mf[1][3] = arg0->mf[2][3] = 0.0f;
    arg0->mf[3][3] = 1.0f;
}

void func_8000F5A8(MtxF* dest, Vec3f* b, Vec3s* c, Vec3f* arg3) {
    f32 sx = SINS(c->x);
    f32 cx = COSS(c->x);

    f32 sy = SINS(c->y);
    f32 cy = COSS(c->y);

    f32 sz = SINS(c->z);
    f32 cz = COSS(c->z);

    dest->mf[0][0] = (cy * cz) * arg3->x;
    dest->mf[0][1] = (cy * sz) * arg3->x;
    dest->mf[0][2] = (-sy) * arg3->x;
    dest->mf[0][3] = 0.0f;

    dest->mf[1][0] = (sx * sy * cz - cx * sz) * arg3->y;
    dest->mf[1][1] = (sx * sy * sz + cx * cz) * arg3->y;
    dest->mf[1][2] = (sx * cy) * arg3->y;
    dest->mf[1][3] = 0.0f;

    dest->mf[2][0] = (cx * sy * cz + sx * sz) * arg3->z;
    dest->mf[2][1] = (cx * sy * sz - sx * cz) * arg3->z;
    dest->mf[2][2] = (cx * cy) * arg3->z;
    dest->mf[2][3] = 0.0f;

    dest->mf[3][0] = b->x;
    dest->mf[3][1] = b->y;
    dest->mf[3][2] = b->z;
    dest->mf[3][3] = 1.0f;
}

void func_8000F730(MtxF* dest, Vec3f* b, Vec3s* c, Vec3f* arg3) {
    f32 sx = SINS(c->x);
    f32 cx = COSS(c->x);

    f32 sy = SINS(c->y);
    f32 cy = COSS(c->y);

    f32 sz = SINS(c->z);
    f32 cz = COSS(c->z);

    dest->mf[0][0] = cy * cz;
    dest->mf[0][1] = cy * sz;
    dest->mf[0][2] = -sy;
    dest->mf[0][3] = 0.0f;

    dest->mf[1][0] = sx * sy * cz - cx * sz;
    dest->mf[1][1] = sx * sy * sz + cx * cz;
    dest->mf[1][2] = sx * cy;
    dest->mf[1][3] = 0.0f;

    dest->mf[2][0] = cx * sy * cz + sx * sz;
    dest->mf[2][1] = cx * sy * sz - sx * cz;
    dest->mf[2][2] = cx * cy;
    dest->mf[2][3] = 0.0f;

    dest->mf[3][0] = b->x * arg3->x;
    dest->mf[3][1] = b->y * arg3->y;
    dest->mf[3][2] = b->z * arg3->z;
    dest->mf[3][3] = 1.0f;
}

void func_8000F88C(MtxF* arg0, MtxF* arg1, MtxF* arg2, Vec3f* arg3, f32 arg4) {
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    sp24 = sqrtf(SQ(arg2->mf[0][0]) + SQ(arg2->mf[0][1]) + SQ(arg2->mf[0][2])) * arg4;
    sp20 = sqrtf(SQ(arg2->mf[1][0]) + SQ(arg2->mf[1][1]) + SQ(arg2->mf[1][2])) * arg4;
    sp1C = sqrtf(SQ(arg2->mf[2][0]) + SQ(arg2->mf[2][1]) + SQ(arg2->mf[2][2])) * arg4;

    arg0->mf[0][0] = arg1->mf[0][0] * sp24;
    arg0->mf[0][1] = arg1->mf[1][0] * sp24;
    arg0->mf[0][2] = arg1->mf[2][0] * sp24;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = arg1->mf[0][1] * sp20;
    arg0->mf[1][1] = arg1->mf[1][1] * sp20;
    arg0->mf[1][2] = arg1->mf[2][1] * sp20;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = arg1->mf[0][2] * sp1C;
    arg0->mf[2][1] = arg1->mf[1][2] * sp1C;
    arg0->mf[2][2] = arg1->mf[2][2] * sp1C;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] =
        ((arg2->mf[0][0] * arg3->x) + (arg2->mf[1][0] * arg3->y) + (arg2->mf[2][0] * arg3->z)) + arg2->mf[3][0];
    arg0->mf[3][1] =
        ((arg2->mf[0][1] * arg3->x) + (arg2->mf[1][1] * arg3->y) + (arg2->mf[2][1] * arg3->z)) + arg2->mf[3][1];
    arg0->mf[3][2] =
        ((arg2->mf[0][2] * arg3->x) + (arg2->mf[1][2] * arg3->y) + (arg2->mf[2][2] * arg3->z)) + arg2->mf[3][2];
    arg0->mf[3][3] = 1.0f;
}

void func_8000FA94(MtxF* dest, Vec3f* upDir, Vec3f* pos, s16 yaw) {
    Vec3f lateralDir;
    Vec3f leftDir;
    Vec3f forwardDir;

    func_8000E88C(&lateralDir, SINS(yaw), 0, COSS(yaw));
    func_8000EAF4(upDir);

    func_8000EA84(&leftDir, upDir, &lateralDir);
    func_8000EAF4(&leftDir);

    func_8000EA84(&forwardDir, &leftDir, upDir);
    func_8000EAF4(&forwardDir);

    dest->mf[0][0] = leftDir.x;
    dest->mf[0][1] = leftDir.y;
    dest->mf[0][2] = leftDir.z;
    dest->mf[3][0] = pos->x;

    dest->mf[1][0] = upDir->x;
    dest->mf[1][1] = upDir->y;
    dest->mf[1][2] = upDir->z;
    dest->mf[3][1] = pos->y;

    dest->mf[2][0] = forwardDir.x;
    dest->mf[2][1] = forwardDir.y;
    dest->mf[2][2] = forwardDir.z;
    dest->mf[3][2] = pos->z;

    dest->mf[0][3] = 0.0f;
    dest->mf[1][3] = 0.0f;
    dest->mf[2][3] = 0.0f;
    dest->mf[3][3] = 1.0f;
}

void func_8000FBB0(MtxF* arg0, MtxF* arg1, MtxF* arg2) {
    f32 entry0;
    f32 entry1;
    f32 entry2;

    entry0 = arg1->mf[0][0];
    entry1 = arg1->mf[0][1];
    entry2 = arg1->mf[0][2];

    arg0->mf[0][0] = (entry0 * arg2->mf[0][0]) + (entry1 * arg2->mf[1][0]) + (entry2 * arg2->mf[2][0]);
    arg0->mf[0][1] = (entry0 * arg2->mf[0][1]) + (entry1 * arg2->mf[1][1]) + (entry2 * arg2->mf[2][1]);
    arg0->mf[0][2] = (entry0 * arg2->mf[0][2]) + (entry1 * arg2->mf[1][2]) + (entry2 * arg2->mf[2][2]);

    entry0 = arg1->mf[1][0];
    entry1 = arg1->mf[1][1];
    entry2 = arg1->mf[1][2];

    arg0->mf[1][0] = (entry0 * arg2->mf[0][0]) + (entry1 * arg2->mf[1][0]) + (entry2 * arg2->mf[2][0]);
    arg0->mf[1][1] = (entry0 * arg2->mf[0][1]) + (entry1 * arg2->mf[1][1]) + (entry2 * arg2->mf[2][1]);
    arg0->mf[1][2] = (entry0 * arg2->mf[0][2]) + (entry1 * arg2->mf[1][2]) + (entry2 * arg2->mf[2][2]);

    entry0 = arg1->mf[2][0];
    entry1 = arg1->mf[2][1];
    entry2 = arg1->mf[2][2];

    arg0->mf[2][0] = (entry0 * arg2->mf[0][0]) + (entry1 * arg2->mf[1][0]) + (entry2 * arg2->mf[2][0]);
    arg0->mf[2][1] = (entry0 * arg2->mf[0][1]) + (entry1 * arg2->mf[1][1]) + (entry2 * arg2->mf[2][1]);
    arg0->mf[2][2] = (entry0 * arg2->mf[0][2]) + (entry1 * arg2->mf[1][2]) + (entry2 * arg2->mf[2][2]);

    entry0 = arg1->mf[3][0];
    entry1 = arg1->mf[3][1];
    entry2 = arg1->mf[3][2];

    arg0->mf[3][0] = (entry0 * arg2->mf[0][0]) + (entry1 * arg2->mf[1][0]) + (entry2 * arg2->mf[2][0]) + arg2->mf[3][0];
    arg0->mf[3][1] = (entry0 * arg2->mf[0][1]) + (entry1 * arg2->mf[1][1]) + (entry2 * arg2->mf[2][1]) + arg2->mf[3][1];
    arg0->mf[3][2] = (entry0 * arg2->mf[0][2]) + (entry1 * arg2->mf[1][2]) + (entry2 * arg2->mf[2][2]) + arg2->mf[3][2];

    arg0->mf[0][3] = arg0->mf[1][3] = arg0->mf[2][3] = 0.0f;
    arg0->mf[3][3] = 1.0f;
}

void func_8000FDE4(MtxF* dest, MtxF* mtx, Vec3f* s) {
    s32 i;

    for (i = 0; i < 4; i++) {
        dest->mf[0][i] = mtx->mf[0][i] * s->x;
        dest->mf[1][i] = mtx->mf[1][i] * s->y;
        dest->mf[2][i] = mtx->mf[2][i] * s->z;
        dest->mf[3][i] = mtx->mf[3][i];
    }
}

void func_8000FF04(MtxF* arg0, Vec3f* arg1) {
    arg1->x = sqrtf(SQ(arg0->mf[0][0]) + SQ(arg0->mf[0][1]) + SQ(arg0->mf[0][2]));
    arg1->y = sqrtf(SQ(arg0->mf[1][0]) + SQ(arg0->mf[1][1]) + SQ(arg0->mf[1][2]));
    arg1->z = sqrtf(SQ(arg0->mf[2][0]) + SQ(arg0->mf[2][1]) + SQ(arg0->mf[2][2]));
}

void func_8000FFB8(MtxF* arg0, Vec3s* arg1) {
    f32 entry0 = arg1->x;
    f32 entry1 = arg1->y;
    f32 entry2 = arg1->z;

    arg1->x = ((entry0 * arg0->mf[0][0]) + (entry1 * arg0->mf[1][0]) + (entry2 * arg0->mf[2][0])) + arg0->mf[3][0];
    arg1->y = ((entry0 * arg0->mf[0][1]) + (entry1 * arg0->mf[1][1]) + (entry2 * arg0->mf[2][1])) + arg0->mf[3][1];
    arg1->z = ((entry0 * arg0->mf[0][2]) + (entry1 * arg0->mf[1][2]) + (entry2 * arg0->mf[2][2])) + arg0->mf[3][2];
}

#define GET_HIGH_S16_OF_32(var) (((s16*)&(var))[0])
#define GET_LOW_S16_OF_32(var) (((s16*)&(var))[1])

void func_80010090(MtxF* dest, MtxF* src) {
    s32 asFixedPoint;
    s32 i;
    s16* a3 = (s16*)dest;      // all integer parts stored in first 16 bytes
    s16* t0 = (s16*)dest + 16; // all fraction parts stored in last 16 bytes
    f32* t1 = (f32*)src;

    for (i = 0; i < 16; i++) {
        asFixedPoint = *t1++ * (1 << 16);         //! float-to-integer conversion responsible for PU crashes
        *a3++ = GET_HIGH_S16_OF_32(asFixedPoint); // integer part
        *t0++ = GET_LOW_S16_OF_32(asFixedPoint);  // fraction part
    }
}

void func_80010228(MtxF* arg0, Vec3f* arg1, Vec3s* arg2, Vec3f* arg3, MtxF* arg4, MtxF* arg5) {
    MtxF sp60;
    MtxF sp20;

    func_8000F88C(&sp60, arg4, arg5, arg1, 1.0f);
    func_8000F2C4(&sp20, &D_8006F050, arg2);
    func_8000FBB0(&sp20, &sp20, &sp60);
    func_8000FDE4(arg0, &sp20, arg3);
}

void func_800102A4(Vec3f* arg0, Vec3f* arg1, f32* arg2, s16* arg3, s16* arg4) {
    f32 sp2C = arg1->x - arg0->x;
    f32 sp28 = arg1->y - arg0->y;
    f32 sp24 = arg1->z - arg0->z;

    *arg2 = sqrtf(SQ(sp2C) + SQ(sp28) + SQ(sp24));
    *arg3 = MathUtil_Atan2s(sqrtf(SQ(sp2C) + SQ(sp24)), sp28);
    *arg4 = MathUtil_Atan2s(sp24, sp2C);
}

void func_80010354(Vec3f* from, Vec3f* to, f32 dist, s16 pitch, s16 yaw) {
    to->x = from->x + (dist * COSS(pitch) * SINS(yaw));
    to->y = from->y + (dist * SINS(pitch));
    to->z = from->z + (dist * COSS(pitch) * COSS(yaw));
}

s16 func_800103F0(s16 current, s16 target, s16 inc) {
    s16 temp_v0 = target - current;

    if (temp_v0 < 0) {
        temp_v0 += inc;
        if (temp_v0 > 0) {
            temp_v0 = 0;
        }
    } else {
        temp_v0 -= inc;
        if (temp_v0 < 0) {
            temp_v0 = 0;
        }
    }

    return target - temp_v0;
}

s32 func_8001046C(s32 current, s32 target, s32 inc, s32 dec) {
    //! If target is close to the max or min s32, then it's possible to overflow
    // past it without stopping.

    if (current < target) {
        current += inc;
        if (current > target) {
            current = target;
        }
    } else {
        current -= dec;
        if (current < target) {
            current = target;
        }
    }
    return current;
}

f32 func_800104AC(f32 current, f32 target, f32 inc, f32 dec) {
    if (current < target) {
        current += inc;
        if (current > target) {
            current = target;
        }
    } else {
        current -= dec;
        if (current < target) {
            current = target;
        }
    }
    return current;
}

s16 func_80010500(s16* arg0, s32 arg1, s32 arg2) {
    Vec2s_s32 spC;
    s16* temp_a3 = &arg0[(arg1 * arg2) / 16];
    s16* p_spC = &spC.x;

    p_spC[0] = temp_a3[0];
    p_spC[1] = temp_a3[1];

    spC.xy <<= ((arg1 * arg2) % 16);
    spC.xy >>= -arg2;
    return spC.y;
}

void func_80010570(f32 arg0, f32 arg1, f32 arg2, Vec3f* arg3) {
    f32 temp_ft4;
    f32 var_ft5;
    f32 var_fv0;
    f32 var_fv1;
    s32 var_v0;

    var_v0 = 0x47;
    if (arg1 <= arg0) {
        var_fv0 = arg0;
        var_v0 = 0x52;
    } else {
        var_fv0 = arg1;
    }

    if (var_fv0 < arg2) {
        var_fv0 = arg2;
        var_v0 = 0x42;
    }

    if (arg0 <= arg1) {
        var_fv1 = arg0;
    } else {
        var_fv1 = arg1;
    }

    if (arg2 < var_fv1) {
        var_fv1 = arg2;
    }

    temp_ft4 = var_fv0 + var_fv1;
    arg3->z = temp_ft4 - 1.0f;
    if (var_fv0 == var_fv1) {
        arg3->y = 0.0f;
        arg3->x = 0.0f;
        return;
    }

    if (arg3->z <= 0.0f) {
        var_ft5 = var_fv0 - var_fv1;
        arg3->y = var_ft5 / temp_ft4;
    } else {
        var_ft5 = var_fv0 - var_fv1;
        arg3->y = var_ft5 / (2.0 - temp_ft4);
    }

    if (var_v0 == 0x52) {
        arg3->x = (arg1 - arg2) / var_ft5;
    } else if (var_v0 == 0x47) {
        arg3->x = ((arg2 - arg0) / var_ft5) + 2.0;
    } else {
        arg3->x = ((arg0 - arg1) / var_ft5) + 4.0;
    }

    arg3->x *= 60.0f;
    if (arg3->x < 0.0f) {
        arg3->x += 360.0f;
    }
}

void func_80010720(Color_RGBA8_u32 arg0, Vec3f* arg1) {
    func_80010570((s32)arg0.r / 255.0f, (s32)arg0.g / 255.0f, (s32)arg0.b / 255.0f, arg1);
}

void func_80010780(u16 arg0, Vec3f* arg1) {
    func_80010570(((arg0 & 0xF800) >> 0xB) / 31.0f, ((arg0 & 0x7C0) >> 6) / 31.0f, ((arg0 & 0x3E) >> 1) / 31.0f, arg1);
}

f32 func_800107F0(f32 arg0, f32 arg1, f32 arg2) {
    f32 ret;

    if (arg0 < 0.0f) {
        arg0 += 360.0f;
    } else {
        while (arg0 >= 360.0f) {
            arg0 -= 360.0f;
        }
    }

    if (arg0 < 60.0f) {
        ret = (((arg2 - arg1) * arg0) / 60.0f) + arg1;
    } else if ((arg0 >= 60.0f) && (arg0 < 180.0f)) {
        ret = arg2;
    } else if ((arg0 >= 180.0f) && (arg0 < 240.0f)) {
        ret = arg1 + (((arg2 - arg1) * (240.0 - arg0)) / 60.0);
    } else {
        ret = arg1;
    }

    return ret;
}

void func_80010930(f32* arg0, f32* arg1, f32* arg2, Vec3f* arg3) {
    f32 sp24;
    f32 sp20;
    f32 temp_ft4;

    if (arg3->z < -1.0f) {
        arg3->z = -1.0f;
    } else if (arg3->z > 1.0f) {
        arg3->z = 1.0f;
    }

    if (arg3->y < 0.0f) {
        arg3->y = 0.0f;
    } else {
        sp24 = 1.0f;
        if (arg3->y > 1.0f) {
            arg3->y = 1.0f;
        }
    }

    if (arg3->x < 0.0f) {
        arg3->x += 360.0f;
    } else {
        while (arg3->x >= 360.0f) {
            arg3->x -= 360.0f;
        }
    }

    if (arg3->z <= 0.0f) {
        temp_ft4 = arg3->z + 1.0f;
        sp24 = temp_ft4 * 0.5f * (1.0f - arg3->y);
        sp20 = temp_ft4 - sp24;
    } else {
        temp_ft4 = arg3->z + 1.0f;
        sp20 = (temp_ft4 * 0.5 * (1.0f - arg3->y)) + arg3->y;
        sp24 = temp_ft4 - sp20;
    }

    *arg0 = func_800107F0(arg3->x + 120.0f, sp24, sp20);
    *arg1 = func_800107F0(arg3->x, sp24, sp20);
    *arg2 = func_800107F0(arg3->x - 120.0f, sp24, sp20);
}

u16 func_80010B20(Vec3f* arg0) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;

    func_80010930(&sp2C, &sp28, &sp24, arg0);

    var_a1 = (sp2C * 31.0f) + 0.5f;
    if (var_a1 >= 0x20) {
        var_a1 = 0x1F;
    }

    var_v1 = (sp28 * 31.0f) + 0.5f;
    if (var_v1 >= 0x20) {
        var_v1 = 0x1F;
    }

    var_a0 = (sp24 * 31.0f) + 0.5f;
    if (var_a0 >= 0x20) {
        var_a0 = 0x1F;
    }

    return (var_a1 << 0xB) | (var_v1 << 6) | (var_a0 * 2) | 1;
}

Color_RGBA8_u32* func_80010BD4(Color_RGBA8_u32* arg0, Vec3f* arg1, s32 arg2) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;
    Color_RGBA8_u32 sp1C;

    func_80010930(&sp34, &sp30, &sp2C, arg1);

    var_a1 = (sp34 * 255.0f) + 0.5f;
    if (var_a1 >= 0x100) {
        var_a1 = 0xFF;
    }

    var_v1 = (sp30 * 255.0f) + 0.5f;
    if (var_v1 >= 0x100) {
        var_v1 = 0xFF;
    }

    var_a0 = (sp2C * 255.0f) + 0.5f;
    if (var_a0 >= 0x100) {
        var_a0 = 0xFF;
    }

    sp1C.r = var_a1;
    sp1C.g = var_v1;
    sp1C.b = var_a0;
    sp1C.a = arg2;

    *arg0 = sp1C;

    return arg0;
}

#ifdef NON_MATCHING
u16 func_80010CA8(u16 arg0, AllTypeS32 arg1) {
    Vec3f sp24;
    s32 a;
    s32 b;

    if (arg0 & 1) {
        func_80010780(arg0, &sp24);

        if (arg1.rg != 0) {
            sp24.x += (arg1.b * 0.015625f);
        }

        if (arg1.b != 0) {
            if (arg1.a > 0) {
                sp24.y += ((1.0f - sp24.y) * arg1.a * 0.125f);
            } else {
                sp24.y += (sp24.y * arg1.a * 0.125f);
            }
        }

        if (arg1.a != 0) {
            a = (((sp24.z + 1.0f) * 0.5f * 255.0f));
            b = (((arg1.a > 0) ? arg1.a + 7 : arg1.a + 8) << 8);

            sp24.z = (2.0f * (D_80073660[b + a] / 65535.0f)) - 1.0f;
        }

        arg0 = func_80010B20(&sp24);
    }
    return arg0;
}
#else
// const f32 D_8007B580 = 65535.0f;
#pragma GLOBAL_ASM("asm/us/nonmatchings/F420/func_80010CA8.s")
#endif

#ifdef NON_MATCHING
Color_RGBA8_u32* func_80010E20(Color_RGBA8_u32 arg0, AllTypeS32 arg1) {
    Vec3f sp2C;
    Color_RGBA8_u32* a0 = &arg0;
    s32 var_v1;
    s32 a;

    if (a0->a > 0) {
        func_80010720(arg0, &sp2C);

        if (arg1.rg != 0) {
            sp2C.x += (arg1.b * 0.015625f);
        }

        if (arg1.b != 0) {
            if (arg1.a > 0) {
                sp2C.y += ((1.0f - sp2C.y) * arg1.a * 0.125f);
            } else {
                sp2C.y += (sp2C.y * arg1.a * 0.125f);
            }
        }

        if (arg1.a != 0) {
            a = (((sp2C.z + 1.0f) * 0.5f * 255.0f));

            if (arg1.a > 0) {
                var_v1 = arg1.a + 7;
            } else {
                var_v1 = arg1.a + 8;
            }

            sp2C.z = (2.0f * (D_80073660[(var_v1 << 8) + a] / 65535.0f)) - 1.0f;
        }

        func_80010BD4(a0, &sp2C, arg0.a);
    }

    return a0;
}
#else
// const f32 D_8007B584 = 65535.0f;
#pragma GLOBAL_ASM("asm/us/nonmatchings/F420/func_80010E20.s")
#endif
