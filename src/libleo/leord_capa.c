#include <ultra64.h>
#include "libleo/internal.h"

void leoRd_capacity(void) {
    if (LEOcur_command->header.control & LEO_CONTROL_WRT) {
        LEOcur_command->data.readwrite.lba = LEORAM_START_LBA[LEOdisk_type] - 0x18;
        LEOcur_command->data.readwrite.xfer_blks = LEO_LBA_MAX;
        LEOcur_command->data.readwrite.buff_ptr = LEORAM_BYTE[LEOdisk_type];
    } else {
        LEOcur_command->data.readwrite.lba = 0;
        LEOcur_command->data.readwrite.xfer_blks = LEO_LBA_MAX;
        LEOcur_command->data.readwrite.buff_ptr = 0x3D78F40; // Total capacity, approx. 64.45 MB
    }
    LEOcur_command->header.status = LEO_STATUS_GOOD;
}
