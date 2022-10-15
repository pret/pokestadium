/**************************************************************************
 *									  *
 *		 Copyright (C) 1994, Silicon Graphics, Inc.		  *
 *									  *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *									  *
 **************************************************************************/

#include "guint.h"

// conflict with gu.h
#define M_DTOR_2 (3.1415926f / 180.0f)

extern float D_80103870;

extern float __cosf(float angle);

/*
 *  Return rotation matrix given roll, pitch, and yaw in degrees
 *   
 */

void guRotateRPYF(float mf[4][4], float r, float p, float h)
{
    // float	dtor = ;
	float	sinr, sinp, sinh;
	float	cosr, cosp, cosh;

	r *= M_DTOR_2;
	p *= M_DTOR_2;
	h *= M_DTOR_2;

    D_80103870 = M_DTOR_2;
    
	sinr = sinf(r);
	cosr = __cosf(r);
	sinp = sinf(p);
	cosp = __cosf(p);
	sinh = sinf(h);
	cosh = __cosf(h);

	guMtxIdentF(mf);

	mf[0][0] = cosp*cosh;
	mf[0][1] = cosp*sinh;
	mf[0][2] = -sinp;

	mf[1][0] = sinr*sinp*cosh - cosr*sinh;
	mf[1][1] = sinr*sinp*sinh + cosr*cosh;
	mf[1][2] = sinr*cosp;

	mf[2][0] = cosr*sinp*cosh + sinr*sinh;
	mf[2][1] = cosr*sinp*sinh - sinr*cosh;
	mf[2][2] = cosr*cosp;
}

void guRotateRPY(Mtx *m, float r, float p, float h)
{
	Matrix	mf;

	guRotateRPYF(mf, r, p, h);

	guMtxF2L(mf, m);
}
