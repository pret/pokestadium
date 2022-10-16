#include <os_internal.h>
#include "ultra64/controller.h"

s32 __osPfsSelectBank(OSPfs *pfs, u8 bank)
{
	u8 temp[8][4];
	int i, j;
	s32 ret;
	ret = 0;

	for (i = 0; i < 8; i++) {
        for(j = 0; j < 4; j++) {
		    temp[i][j] = bank;
        }
	}

	ret = __osContRamWrite(pfs->queue, pfs->channel, 1024, (u8*)temp, FALSE);

	if (ret == 0) {
		pfs->activebank = bank;
	}

	return ret;
}
