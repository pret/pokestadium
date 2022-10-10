#include <ultra64.h>
#include "ultra64/controller.h"

// .bss
extern OSTimer var80090ab0;
extern OSMesgQueue g_GbpakMesgQueue;
extern OSMesg var80090ae8;

s32 osGbpakInit(OSMesgQueue *queue, OSPfs *pfs, int channel)
{
	s32 ret;
	s32 i;
	u8 buffer[32];

	pfs->status = 0;

	for (i = 0; i < 32; i++) {
		buffer[i] = 0xfe;
	}

	ret = __osContRamWrite(queue, channel, 0x400, buffer, 0);

	if (ret == PFS_ERR_NEW_PACK) {
		ret = __osContRamWrite(queue, channel, 0x400, buffer, 0);
	}

	if (ret != 0) {
		return ret;
	}

	ret = __osContRamRead(queue, channel, 0x400, buffer);

	if (ret == PFS_ERR_NEW_PACK) {
		ret = PFS_ERR_CONTRFAIL;
	}

	if (ret != 0) {
		return ret;
	}

	if (buffer[31] == 0xfe) {
		return PFS_ERR_DEVICE;
	}

    // ok but why tho. the earlier loop isnt like this
	for (i = 0; i < 32; i+=4) {
		buffer[i+0] = 0x84;
        buffer[i+1] = 0x84;
        buffer[i+2] = 0x84;
        buffer[i+3] = 0x84;
	}

	ret = __osContRamWrite(queue, channel, 0x400, buffer, 0);

	if (ret == PFS_ERR_NEW_PACK) {
		ret = PFS_ERR_CONTRFAIL;
	}

	if (ret != 0) {
		return ret;
	}

	ret = __osContRamRead(queue, channel, 0x400, buffer);

	if (ret == 2) {
		ret = PFS_ERR_CONTRFAIL;
	}

	if (ret != 0) {
		return ret;
	}

	if (buffer[31] != 0x84) {
		return PFS_ERR_DEVICE;
	}

	ret = __osPfsGetStatus(queue, channel);

	if (ret != 0) {
		return ret;
	}

	osCreateMesgQueue(&g_GbpakMesgQueue, &var80090ae8, 1);
	osSetTimer(&var80090ab0, 9000000, 0, &g_GbpakMesgQueue, &var80090ae8);
	osRecvMesg(&g_GbpakMesgQueue, 0, OS_MESG_BLOCK);

	pfs->queue = queue;
	pfs->status = 0x10;
	pfs->channel = channel;
	pfs->activebank = 0x84;
	pfs->banks = 0xff;
	pfs->version = 0xff;
	pfs->dir_size = 0xff;

	return 0;
}
