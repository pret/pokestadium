#include <ultra64.h>
#include "libleo/internal.h"

const u16 LEOVZONE_TBL[][0x10] = {
    { 0x0124, 0x0248, 0x035A, 0x047E, 0x05A2, 0x06B4, 0x07C6, 0x08D8, 0x09EA, 0x0AB6, 0x0B82, 0x0C94, 0x0DA6, 0x0EB8,
      0x0FCA, 0x10DC },
    { 0x0124, 0x0248, 0x035A, 0x046C, 0x057E, 0x06A2, 0x07C6, 0x08D8, 0x09EA, 0x0AFC, 0x0BC8, 0x0C94, 0x0DA6, 0x0EB8,
      0x0FCA, 0x10DC },
    { 0x0124, 0x0248, 0x035A, 0x046C, 0x057E, 0x0690, 0x07A2, 0x08C6, 0x09EA, 0x0AFC, 0x0C0E, 0x0CDA, 0x0DA6, 0x0EB8,
      0x0FCA, 0x10DC },
    { 0x0124, 0x0248, 0x035A, 0x046C, 0x057E, 0x0690, 0x07A2, 0x08B4, 0x09C6, 0x0AEA, 0x0C0E, 0x0D20, 0x0DEC, 0x0EB8,
      0x0FCA, 0x10DC },
    { 0x0124, 0x0248, 0x035A, 0x046C, 0x057E, 0x0690, 0x07A2, 0x08B4, 0x09C6, 0x0AD8, 0x0BEA, 0x0D0E, 0x0E32, 0x0EFE,
      0x0FCA, 0x10DC },
    { 0x0124, 0x0248, 0x035A, 0x046C, 0x057E, 0x0690, 0x07A2, 0x086E, 0x0980, 0x0A92, 0x0BA4, 0x0CB6, 0x0DC8, 0x0EEC,
      0x1010, 0x10DC },
    { 0x0124, 0x0248, 0x035A, 0x046C, 0x057E, 0x0690, 0x07A2, 0x086E, 0x093A, 0x0A4C, 0x0B5E, 0x0C70, 0x0D82, 0x0E94,
      0x0FB8, 0x10DC },
};

u16 leoLba_to_phys(u32 lba) {
    u32 vzone;
    u32 pzone;
    u16 pzone_cylinder_start;
    u16 defect_offset;
    u16 defect_amount;

    //A cylinder track is made of two blocks, so we may be able to only read one of it if the next block is on the next cylinder
    LEOtgt_param.rdwr_blocks = 2 - (lba & 1);

    //Blocks are interleaved between cylinders
    if (((lba & 3) != 0) && ((lba & 3) != 3)) {
        LEOtgt_param.start_block = 1;
    } else {
        LEOtgt_param.start_block = 0;
    }

    //Get Virtual & Physical Disk Zones from LBA
    vzone = leoLba_to_vzone(lba);
    pzone = LEOVZONE_PZONEHD_TBL[LEOdisk_type][vzone];

    //Set Parameter Disk Head & Zone
    LEOtgt_param.head = 0;
    LEOtgt_param.zone = pzone;
    if (LEOtgt_param.zone > 7)
    {
        LEOtgt_param.zone -= 7;
        LEOtgt_param.head = 1;
    }

    //Get the start cylinder from current zone
    pzone_cylinder_start = LEOZONE_SCYL_TBL[pzone];

    {
        //Get Virtual Zone LBA start, if Zone 0, it's LBA 0
        u16 vzone_lba_start = (vzone != 0) ? LEOVZONE_TBL[LEOdisk_type][vzone - 1] : 0;
        //Get Cylinder relative of the current Zone
        u16 zone_cylinder = ((lba - vzone_lba_start) >> 1);
        //Calculate Physical Cylinder
        if (LEOtgt_param.head != 0) {
            LEOtgt_param.cylinder = pzone_cylinder_start - zone_cylinder;
            pzone_cylinder_start = LEOZONE_OUTERCYL_TBL[LEOtgt_param.zone - 1];
        } else {
            LEOtgt_param.cylinder = pzone_cylinder_start + zone_cylinder;
        } 
    }

    {
        u32 pzone_prev = pzone - 1;
        //Get the relative offset to defect tracks for the current zone (if Zone 0, then it's 0)
        defect_offset = (pzone != 0) ? LEO_sys_data.param.defect_num[pzone_prev] : 0;
        //Get amount of defect tracks for the current zone
        defect_amount = LEO_sys_data.param.defect_num[pzone] - defect_offset;
    }

    //Skip defective cylinders
    while (defect_amount != 0) {
        u16 defect_cylinder = (pzone_cylinder_start + LEO_sys_data.param.defect_data[defect_offset]);
        if (LEOtgt_param.cylinder < defect_cylinder) break;
        
        LEOtgt_param.cylinder++;
        defect_offset++;
        defect_amount--;
    }

    //Set sector and block size info
    LEOtgt_param.sec_bytes = LEOBYTE_TBL1[LEOtgt_param.zone];
    LEOtgt_param.blk_bytes = LEOBYTE_TBL2[LEOtgt_param.zone];

    //For development disks
    if ((LEO_country_code == 0) && (lba < 0xC)) {
        LEOtgt_param.sec_bytes = 0xC0;
        LEOtgt_param.blk_bytes = 0x3FC0;
    }

    return 0;
}


u16 leoLba_to_vzone(u32 lba) {
    u16 i;
    const u16* ptr = LEOVZONE_TBL[LEOdisk_type];

    for (i = 0; i < ARRAY_COUNT(LEOVZONE_TBL[LEOdisk_type]); i++, ptr++) {
        if (lba < *ptr) {
            return i;
        }
    }

    return 0xFF;
}
