#include <ultra64.h>
#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "ultra64/controller.h"

extern s32 __osPfsLastChannel;

#define READFORMAT(ptr) ((__OSContRamReadFormat*)(ptr))

s32 __osContRamWrite(OSMesgQueue* mq, int channel, u16 address, u8* buffer, int force) {
    s32 ret = 0;
    s32 i;
    u8* ptr;
    s32 retry = 2;
    u8 crc;

    if ((force != PFS_FORCE) && (address < PFS_LABEL_AREA) && (address != 0)) {
        return 0;
    }

    __osSiGetAccess();

    do {
        ptr = (u8*)(&__osPfsPifRam.ramarray);

        if (__osContLastCmd != CONT_CMD_WRITE_MEMPACK || __osPfsLastChannel != channel) {
            __osContLastCmd = CONT_CMD_WRITE_MEMPACK;
            __osPfsLastChannel = channel;

            // clang-format off
            for (i = 0; i < channel; i++) { *ptr++ = 0; }
            // clang-format on

            __osPfsPifRam.pifstatus = 1;

            READFORMAT(ptr)->dummy = CONT_CMD_NOP;
            READFORMAT(ptr)->txsize = CONT_CMD_WRITE_MEMPACK_TX;
            READFORMAT(ptr)->rxsize = CONT_CMD_WRITE_MEMPACK_RX;
            READFORMAT(ptr)->cmd = CONT_CMD_WRITE_MEMPACK;
            READFORMAT(ptr)->datacrc = 0xFF;

            ptr[sizeof(__OSContRamReadFormat)] = CONT_CMD_END;
        } else {
            ptr += channel;
        }
        READFORMAT(ptr)->hi = address >> 3;
        READFORMAT(ptr)->lo = ((address << 5) | __osContAddressCrc(address));

        _bcopy(buffer, READFORMAT(ptr)->data, BLOCKSIZE);

        ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
        crc = __osContDataCrc(buffer);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);

        ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);

        ret = ((((__OSContRamReadFormat*)ptr)->rxsize & 0xC0) >> 4);
        if (!ret) {
            if (crc != ((__OSContRamReadFormat*)ptr)->datacrc) {
                if ((ret = __osPfsGetStatus(mq, channel))) {
                    break;
                } else {
                    ret = PFS_ERR_CONTRFAIL;
                }
            }
        } else {
            ret = PFS_ERR_NOPACK;
        }
    } while ((ret == PFS_ERR_CONTRFAIL) && (retry-- >= 0));
    __osSiRelAccess();

    return ret;
}
