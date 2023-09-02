#include <ultra64.h>
#include <leo.h>
#include "libleo/internal.h"

extern u16 LEOrw_flags;

// D_8007DA40
const u8 leo_sys_form_lbas[] = { 0, 1, 8, 9, 0, 0, 0, 0 }; // EXTRA 0 IS A HACK

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/leocmdex/leomain.s")

/*const LEOCmdRead leo_sys_read_cmd =
{
        {LEO_COMMAND_READ,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00000000},
        12,1,0,0
};*/

extern LEOCmdRead leo_sys_read_cmd;

u8 leoRead_system_area(void) {
    LEOCmdRead temp_cmd;
    LEOCmd* prev_cmd;
    u32 retry_cntr;
    s32 read_mode;

    prev_cmd = LEOcur_command;
    LEOcur_command = (LEOCmd*)&temp_cmd;
    read_mode = 0;
    retry_cntr = 0;

    while (1) {
        LEOdisk_type = 0;
        // For lba_to_phys to avoid dealing with alternative tracks on the disk
        LEO_sys_data.param.defect_num[0] = 0;
        LEOrw_flags = 0x3000;
        temp_cmd = leo_sys_read_cmd;
        temp_cmd.buff_ptr = &LEO_sys_data;

        if (read_mode == 0) {
            // read System LBA 12 (+0, this is an offset value for leoRead_common)
            // see leo_sys_read_cmd premade struct
            leoRead_common(0);
            switch (temp_cmd.header.sense) {
                case LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION:
                    do {
                        // if expecting a retail disk, LBA 12 is expected to do a read error, if not then freeze
                    } while (LEO_country_code != 0);
                    retry_cntr = 0;
                    read_mode--;
                    continue;
                case LEO_SENSE_UNRECOVERED_READ_ERROR:
                    do {
                        // if expecting a development disk, LBA 12 is expected to read correctly, if not then freeze
                    } while (LEO_country_code == 0);
                    retry_cntr = 0;
                    read_mode--;
                    continue;
            }
        } else {
            // read System LBA 0,1,8,9 (or 2,3,10,11 for dev)
            temp_cmd.lba = leo_sys_form_lbas[retry_cntr & 3];
            if (LEO_country_code == 0) {
                temp_cmd.lba += 2;
            }
            leoRead_common(0);
            if (temp_cmd.header.status == LEO_STATUS_GOOD) {
                do {
                    // if disk country and set country code in libleo mismatch, then freeze
                } while (LEO_sys_data.param.country != LEO_country_code);
                break;
            }
        }
    system_retry:
        if (leoChk_err_retry(temp_cmd.header.sense) != LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION) {
            break;
        }
        if (retry_cntr++ >= 0x40U) {
            break;
        }
        if ((retry_cntr & 7) == 0) {
            // Recalibrate drive every 8th tries
            if ((temp_cmd.header.sense = leoSend_asic_cmd_w(ASIC_RECAL, 0)) ==
                LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION) {
                continue;
            }
            goto system_retry;
        }
    }
    LEOcur_command = prev_cmd;
    prev_cmd->header.sense = temp_cmd.header.sense;
    return prev_cmd->header.sense;
}
