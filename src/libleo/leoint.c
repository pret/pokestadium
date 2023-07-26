#include <ultra64.h>
#include "libleo/internal.h"

extern vu16 LEOrw_flags;

void* read_write_track();

void leointerrupt(void* arg) {
    u32 result;
    u32 tg_blocks;

    osCreateMesgQueue(&LEOc2ctrl_que, (OSMesg)&LEOc2ctrl_que_buf, 1);

    while (true) {
        osStopThread(&LEOinterruptThread);
        tg_blocks = LEOcur_command->data.readwrite.xfer_blks;
        LEOwrite_pointer = LEOcur_command->data.readwrite.buff_ptr;
        do {
            leoLba_to_phys(LEOtgt_param.lba);
            if (LEOrw_flags & 0x8000) {
                result = leoSeek_i(1);
            } else {
                result = leoSeek_i(0);
            }

            if (result != 0) {
                goto complete;
            }

            if (LEOrw_flags & 0x2000) {
                LEOtgt_param.rdwr_blocks = 1;
            } else if (LEOtgt_param.rdwr_blocks > tg_blocks) {
                LEOtgt_param.rdwr_blocks = tg_blocks;
            }
            LEOtgt_param.lba += LEOtgt_param.rdwr_blocks;
            tg_blocks -= LEOtgt_param.rdwr_blocks;
            result = read_write_track();
            if (result != 0) {
                goto complete;
            }

            LEOcur_command->data.readwrite.rw_bytes = LEOwrite_pointer - (u8*)LEOcur_command->data.readwrite.buff_ptr;
        } while (tg_blocks != 0);
        result = 0x90000; // Inaccessible?

    complete:;

        osSendMesg(&LEOcontrol_que, result, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/leoint/read_write_track.s")

u32 leoChk_mecha_int(void) {
    u32 stat = leoWait_mecha_cmd_done(ASIC_RD_SEEK);
    u32 index_stat;

    if (stat == 0) {
        osEPiReadIo(LEOPiInfo, LEO_CUR_TK, &index_stat);
        if ((index_stat & LEO_CUR_TK_INDEX_LOCK) != LEO_CUR_TK_INDEX_LOCK) {
            stat = 0x18;
        }
    }
    return stat;
}

void leosetup_BM(void) {
    osEPiWriteIo(LEOPiInfo, 0x05000510U, LEOasic_bm_ctl_shadow | 0x10000000);
    osEPiWriteIo(LEOPiInfo, 0x05000510U, LEOasic_bm_ctl_shadow);
    if (LEOtgt_param.start_block != 0) {
        LEOasic_bm_ctl_shadow = 0x5A0000;
    } else {
        LEOasic_bm_ctl_shadow = 0;
    }
    if (!(LEOrw_flags & 0x8000)) {
        LEOasic_bm_ctl_shadow |= 0x40000000;
    }
    if (LEOtgt_param.rdwr_blocks == 2) {
        LEOasic_bm_ctl_shadow |= 0x02000000;
    }
    osEPiWriteIo(LEOPiInfo, 0x05000510U, LEOasic_bm_ctl_shadow);
}

#ifdef NON_MATCHING
u32 leochk_err_reg(void) {
    u32 sense;
    u32 index_status;

    osEPiReadIo(LEOPiInfo, 0x05000514U, &sense);
    osEPiWriteIo(LEOPiInfo, 0x05000510U, LEOasic_bm_ctl_shadow | 0x10000000);
    osEPiWriteIo(LEOPiInfo, 0x05000510U, LEOasic_bm_ctl_shadow);
    if (sense & 0x04000000) {
        return 0x31;
    }
    if (sense & 0x10000000) {
        return 4;
    }
    if (sense & 0x42000000) {
        if (LEOrw_flags & 0x8000) {
            return 0x16;
        }
        return 0x17;
    }
    if (sense & 0x80000000) {
        return 0x18;
    }
    osEPiReadIo(LEOPiInfo, 0x0500050CU, &index_status);
    if ((index_status & 0x60000000) == 0x60000000) {
        return 0x19;
    }
    return 0x18;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libleo/leoint/leochk_err_reg.s")
#endif
