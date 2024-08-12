#include "global.h"
#include "libleo/internal.h"

extern vu16 LEOrw_flags;

void leoRead(void) {
    LEOrw_flags = 0;
    leoRead_common(0x18);
}

void leoRead_common(u32 offset) {
    u32 tg_lba = LEOcur_command->data.readwrite.lba;
    u32 tg_blocks = LEOcur_command->data.readwrite.xfer_blks;
    u32 message;

    if ((tg_lba | tg_blocks) >> 0x10 != 0) {
        goto invalid_lba;
    }

    tg_lba += offset;
    if ((tg_lba + tg_blocks) > 0x10DC) { // Unclear what this number represents
    invalid_lba:
        LEOcur_command->header.sense = LEO_SENSE_LBA_OUT_OF_RANGE;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }

    if (tg_blocks == 0) {
        if (tg_lba < 0x10DC) {
            LEOcur_command->header.sense = LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
            LEOcur_command->header.status = LEO_STATUS_GOOD;
            return;
        }
        goto invalid_lba;
    }

    LEOtgt_param.lba = tg_lba;
    LEOrw_flags &= 0x3FFF;
    osSendMesg(&LEOc2ctrl_que, NULL, OS_MESG_NOBLOCK);
    osStartThread(&LEOinterruptThread);

    while (true) {
        osRecvMesg(&LEOcontrol_que, (OSMesg)&message, OS_MESG_BLOCK);

        switch (message) {
            case 0x80000:
                leoC2_Correction();
                LEOrw_flags &= ~0x4000;
                osSendMesg(&LEOc2ctrl_que, NULL, OS_MESG_NOBLOCK);
                break;

            default:
                LEOcur_command->header.sense = message;
                LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                return;

            case 0x90000:
                LEOcur_command->header.sense = LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
                LEOcur_command->header.status = LEO_STATUS_GOOD;
                return;
        }
    }
}
