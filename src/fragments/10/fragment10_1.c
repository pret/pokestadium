#include "fragment10.h"

u16 D_864029F0[4][14][8] = {
    {
        { 0x0005, 0x0014, 0x0046, 0x0046, 0x0046, 0x000A, 0x0000, 0x0003 },
        { 0x0002, 0x000F, 0x0041, 0x0041, 0x0041, 0x000A, 0x0000, 0x0003 },
        { 0x0001, 0x000C, 0x003C, 0x003C, 0x003C, 0x000A, 0x0000, 0x0003 },
        { 0x0000, 0x000A, 0x0037, 0x0037, 0x0037, 0x000A, 0x0000, 0x0003 },
        { 0x0000, 0x000A, 0x0032, 0x0032, 0x0032, 0x000A, 0x0000, 0x0003 },
        { 0x0000, 0x000A, 0x002D, 0x002D, 0x002D, 0x000A, 0x0000, 0x0003 },
        { 0x0000, 0x000A, 0x0028, 0x0028, 0x0028, 0x000A, 0x0000, 0x0003 },
        { 0x0000, 0x000A, 0x0023, 0x0023, 0x0023, 0x000A, 0x0001, 0x0003 },
        { 0x0000, 0x000A, 0x001E, 0x001E, 0x001E, 0x000A, 0x0005, 0x0003 },
        { 0x0000, 0x000A, 0x0019, 0x0019, 0x0019, 0x000A, 0x0009, 0x0003 },
        { 0x0001, 0x000A, 0x0014, 0x0014, 0x0014, 0x000F, 0x000F, 0x0004 },
        { 0x0002, 0x000A, 0x000F, 0x000F, 0x0014, 0x001E, 0x001E, 0x0006 },
        { 0x0004, 0x000A, 0x000A, 0x000A, 0x000A, 0x0032, 0x003C, 0x0008 },
        { 0x0006, 0x000A, 0x000A, 0x000A, 0x000A, 0x005A, 0x00FA, 0x000A },
    },
    {
        { 0x0002, 0x000F, 0x0046, 0x005D, 0x0046, 0x0005, 0x0000, 0x0002 },
        { 0x0001, 0x000C, 0x0041, 0x0056, 0x0041, 0x0005, 0x0000, 0x0002 },
        { 0x0000, 0x000A, 0x003C, 0x0050, 0x003C, 0x0005, 0x0000, 0x0002 },
        { 0x0000, 0x000A, 0x0037, 0x0049, 0x0037, 0x0005, 0x0000, 0x0002 },
        { 0x0000, 0x000A, 0x0032, 0x0043, 0x0032, 0x0005, 0x0000, 0x0002 },
        { 0x0000, 0x000A, 0x002D, 0x003C, 0x002D, 0x0005, 0x0000, 0x0002 },
        { 0x0000, 0x000A, 0x0028, 0x0035, 0x0028, 0x0005, 0x0000, 0x0002 },
        { 0x0000, 0x000A, 0x0023, 0x002F, 0x0023, 0x0005, 0x0000, 0x0002 },
        { 0x0000, 0x000A, 0x001E, 0x0028, 0x001E, 0x0005, 0x0000, 0x0002 },
        { 0x0000, 0x000A, 0x0019, 0x0021, 0x0019, 0x0005, 0x0001, 0x0002 },
        { 0x0000, 0x000A, 0x0014, 0x001B, 0x0014, 0x000A, 0x0004, 0x0002 },
        { 0x0001, 0x000A, 0x000F, 0x0014, 0x000F, 0x000F, 0x000A, 0x0002 },
        { 0x0002, 0x000A, 0x000A, 0x000C, 0x000F, 0x0014, 0x0014, 0x0003 },
        { 0x0004, 0x000A, 0x000A, 0x000A, 0x000F, 0x0028, 0x003C, 0x0004 },
    },
    {
        { 0x0000, 0x000C, 0x0046, 0x0075, 0x0046, 0x0002, 0x0000, 0x0001 },
        { 0x0000, 0x000A, 0x0041, 0x006D, 0x0041, 0x0002, 0x0000, 0x0001 },
        { 0x0000, 0x000A, 0x003C, 0x0064, 0x003C, 0x0002, 0x0000, 0x0001 },
        { 0x0000, 0x000A, 0x0037, 0x005C, 0x0037, 0x0002, 0x0000, 0x0001 },
        { 0x0000, 0x000A, 0x0032, 0x0053, 0x0032, 0x0002, 0x0000, 0x0001 },
        { 0x0000, 0x000A, 0x002D, 0x004B, 0x002D, 0x0002, 0x0000, 0x0001 },
        { 0x0000, 0x000A, 0x0028, 0x0043, 0x0028, 0x0002, 0x0000, 0x0001 },
        { 0x0000, 0x000A, 0x0023, 0x003A, 0x0023, 0x0002, 0x0000, 0x0001 },
        { 0x0000, 0x000A, 0x001E, 0x0032, 0x001E, 0x0002, 0x0000, 0x0001 },
        { 0x0000, 0x000A, 0x0019, 0x002A, 0x0019, 0x0002, 0x0000, 0x0001 },
        { 0x0000, 0x000A, 0x0014, 0x0021, 0x0014, 0x0002, 0x0001, 0x0001 },
        { 0x0000, 0x000A, 0x000F, 0x0019, 0x000F, 0x0003, 0x0002, 0x0001 },
        { 0x0001, 0x000A, 0x000A, 0x000F, 0x000F, 0x0007, 0x0004, 0x0001 },
        { 0x0002, 0x000A, 0x000A, 0x000A, 0x000F, 0x000F, 0x000A, 0x0003 },
    },
    {
        { 0x0000, 0x000A, 0x0046, 0x008C, 0x0046, 0x0001, 0x0000, 0x0000 },
        { 0x0000, 0x000A, 0x0041, 0x0082, 0x0041, 0x0001, 0x0000, 0x0000 },
        { 0x0000, 0x000A, 0x003C, 0x0078, 0x003C, 0x0001, 0x0000, 0x0000 },
        { 0x0000, 0x000A, 0x0037, 0x006E, 0x0037, 0x0001, 0x0000, 0x0000 },
        { 0x0000, 0x000A, 0x0032, 0x0064, 0x0032, 0x0001, 0x0000, 0x0000 },
        { 0x0000, 0x000A, 0x002D, 0x005A, 0x002D, 0x0001, 0x0000, 0x0000 },
        { 0x0000, 0x000A, 0x0028, 0x0050, 0x0028, 0x0001, 0x0000, 0x0000 },
        { 0x0000, 0x000A, 0x0023, 0x0046, 0x0023, 0x0001, 0x0000, 0x0000 },
        { 0x0000, 0x000A, 0x001E, 0x003C, 0x001E, 0x0001, 0x0000, 0x0000 },
        { 0x0000, 0x000A, 0x0019, 0x0032, 0x0019, 0x0001, 0x0000, 0x0000 },
        { 0x0000, 0x000A, 0x0014, 0x0028, 0x0014, 0x0001, 0x0000, 0x0000 },
        { 0x0000, 0x000A, 0x000F, 0x001E, 0x000F, 0x0001, 0x0000, 0x0000 },
        { 0x0000, 0x000A, 0x000A, 0x0014, 0x000A, 0x0001, 0x0000, 0x0001 },
        { 0x0001, 0x000A, 0x000A, 0x000A, 0x000A, 0x0002, 0x0001, 0x0002 },
    },
};

static u32 D_86402D70[] = {
    0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5CE73, 0xD6B5D6B5, 0xD6B5D6B5,
    0xD6B5D6B5, 0xCE73D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5,
    0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xCE73D6B5, 0xCE73D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xCE73D6B5,
    0xD6B5CE73, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5,
    0xD6B5CE73, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5DEF7, 0xD6B5DEF7, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5CE73,
    0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xCE73D6B5, 0xD6B5D6B5,
    0xDEF7D6B5, 0xDEF7DEF7, 0xDEF7DEF7, 0xDEF7DEF7, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xCE73D6B5, 0xD6B5D6B5,
    0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5CE75, 0xCE73D6B5, 0xDEF5D6B7, 0xDEF7E737, 0xDEF9E739,
    0xE739E737, 0xDEF9E737, 0xDEF9DEF5, 0xD6B7DEF5, 0xD6B5CE75, 0xD6B5D6B5, 0xCE73D6B5, 0xD6B5D6B5, 0xD6B5D6B5,
    0xD6B5D6B5, 0xCE73CE73, 0xCE73BDF1, 0xB52DBDF1, 0xD675D6F7, 0xDEF7E739, 0xE739EF3B, 0xE779EF7B, 0xE739E739,
    0xE739E739, 0xDEF7DEF7, 0xD6B7DEF5, 0xCE75D6B3, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5CE73, 0xCE73D6B5,
    0xBDF18C27, 0x621F7365, 0x9429A4ED, 0xB52FB571, 0xC633D677, 0xDEF7E73B, 0xEF7BEF3B, 0xEF7BE739, 0xE739E737,
    0xDEF7D6B7, 0xD6B5D6B5, 0xCEB3D675, 0xD6B5D6B5, 0xD6B5D6B5, 0xCE73CE73, 0xCE73CE73, 0xBDF183A5, 0x499D51DD,
    0x621F6B23, 0x8367942B, 0x9C6BAD2F, 0xBD73C635, 0xDEF7EF3B, 0xEF7BE73B, 0xEF79E739, 0xDEF9DEF7, 0xD6F5D675,
    0xD6B3CEB5, 0xD6B5D6B5, 0xD6B5CE73, 0xCE73CE73, 0xCE73C631, 0xC631AD6D, 0x94298BE7, 0x8C299CAB, 0xA4EDACEF,
    0xACED946B, 0x9C6DACED, 0xB571C5F5, 0xD675CE77, 0xD635CEB7, 0xE6F7DEF7, 0xD6B7DEF5, 0xCE75D6B3, 0xCE75D6B5,
    0xD6B5CE73, 0xCE73CE73, 0xC631C631, 0xBDEFBDEF, 0xBDEFBE31, 0xCE31D6B5, 0xD6B5D6B7, 0xCE33BDB1, 0xB571A4ED,
    0xA4AD9CAD, 0xACEFB531, 0xAD2FAD31, 0xD675DEF9, 0xDEF7DEF5, 0xD6B5CE75, 0xD6B3D6B5, 0xCE73CE73, 0xCE73CE73,
    0xC631B5AD, 0xB5ADB5AD, 0xB5ADB5AD, 0xC631CE73, 0xCE73D6B7, 0xDEF5D6B7, 0xDEF5C5F3, 0xAD2F9C6B, 0x9CADA4AD,
    0xACEFA4EF, 0xCE35E739, 0xDEF7DEB5, 0xD6B5CEB5, 0xD6B5D6B5, 0xCE73D6B5, 0xCE73C631, 0xBDEFB5AD, 0xAD6BA529,
    0xA529B5AD, 0xB5ADBDEF, 0xCE73CE73, 0xD6B5D6B5, 0xCE75ACED, 0x7B656AE3, 0x8BA7A4EF, 0xBDB1CE37, 0xE737E73B,
    0xDEF7DEF7, 0xD6B5D6B3, 0xCE75D6B5, 0xCE73D6B5, 0xCE73C631, 0xB5ADAD6B, 0xA5299CE7, 0x9CE7A529, 0xAD6BB5AD,
    0xBDEFCE73, 0xC631C5F1, 0x94696261, 0x5A5F8367, 0xA52DD675, 0xE6F9E77B, 0xEF7BE739, 0xDEF7DEF7, 0xD6B5D6B5,
    0xD675CEB3, 0xCE73CE73, 0xCE73C631, 0xBDEFA529, 0xA52994A5, 0x94A594A5, 0xA529AD6B, 0xB5ADB5AD, 0xA4ED7B63,
    0x51DD4159, 0x7325B56F, 0xD6B5E6F9, 0xDF39EF39, 0xE739E739, 0xE739D6B5, 0xD6B5D6B5, 0xD6B5CE73, 0xCE73CE73,
    0xCE73C631, 0xB5ADAD6B, 0x9CE794A5, 0x8C6394A5, 0x94A59CE7, 0x9CA77BA5, 0x5A1D3919, 0x499B7325, 0xB56DCE73,
    0xD6B7DEF5, 0xDEF9E737, 0xE739DEF7, 0xDEF7DEF7, 0xD6B5CE75, 0xD6B3CEB5, 0xCE73D6B5, 0xCE73C631, 0xB5ADAD6B,
    0x9CE794A5, 0x8C638C63, 0x83E373A1, 0x5A1D3959, 0x3897521D, 0x8C25B56F, 0xC631C673, 0xD673D6B5, 0xD6F7DEF7,
    0xDEF7DEF7, 0xDEF7D6B5, 0xD6B5CE73, 0xD6B5D6B5, 0xCE73D6B5, 0xCE73C631, 0xBDEFAD6B, 0xA52994A5, 0x8423735F,
    0x5A5B4159, 0x39194159, 0x6ADF8C67, 0xAD2BB5AD, 0xBDEFC631, 0xCE73CE73, 0xD6B5D6B5, 0xD6B5DEF5, 0xD6B5D6B5,
    0xD6B5D6B5, 0xCE73D6B5, 0xCE73D6B5, 0xCE73C631, 0xC631B5AD, 0xA4E98423, 0x6ADF4199, 0x30D738D7, 0x49D97321,
    0x8C639CE7, 0xA529A56B, 0xB56BB5EF, 0xBDEFCE31, 0xCE73CE75, 0xD6B3D6B5, 0xCEB5D6B5, 0xCE73D6B5, 0xD6B5D6B5,
    0xD6B5CE73, 0xCE73CE73, 0xC631BDEF, 0x946751DB, 0x30D72857, 0x311751DB, 0x6B1D83E1, 0x84238C63, 0x94A59CE7,
    0x9CE7AD6B, 0xAD6DBDAD, 0xBE31CE73, 0xCE73D673, 0xD6B5CE73, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5CE73, 0xCE73CE73,
    0xCE73BDEF, 0x83A530D7, 0x28573097, 0x30D53919, 0x4999521B, 0x525D5A5B, 0x629D6ADF, 0x6B1F7B63, 0x6B216ADF,
    0x7323B56F, 0xCE73CEB3, 0xCE73D675, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xCE73CE73, 0xCE73C631, 0xAD2D629F,
    0x499B499B, 0x49993919, 0x30D73095, 0x28973097, 0x30D738D7, 0x31174119, 0x30972855, 0x20578BE5, 0xCE73CE73,
    0xCE75D6B3, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xCE73CE73, 0xD6B5CE73, 0xBDEFB5AF, 0xA4E99CA9, 0x8C277BA1,
    0x62DF625D, 0x525D51DB, 0x49D9499B, 0x41994119, 0x419B5A1D, 0x7323B56D, 0xC633D6B3, 0xCE73D6B5, 0xD6B5D6B5,
    0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5CE73, 0xCE73D6B5, 0xC633CE71, 0xBDF1BDEF, 0xB5ADAD6B, 0xA529A4E7, 0x94E79465,
    0x84258BE3, 0x7BE383E5, 0x8C25AD6B, 0xBDB1C671, 0xCE73CE73, 0xCE73D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5,
    0xD6B5D6B5, 0xCE73CE73, 0xCE73CE73, 0xCE73C631, 0xC631B5AD, 0xBDEFAD6B, 0xAD6BAD6B, 0xA529AD6B, 0xAD6BAD6D,
    0xB5ADC62F, 0xC631CE73, 0xCE73CE75, 0xCE73D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5CE73,
    0xCE73D6B5, 0xCE73CE73, 0xC631C631, 0xC631BDEF, 0xBDEFB5AD, 0xBDEFBDEF, 0xB5ADBDEF, 0xC631C631, 0xCE73CE73,
    0xCE73D6B5, 0xCE73D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5CE73, 0xCE73D6B5,
    0xCE73C631, 0xCE73C631, 0xC631C631, 0xC631C631, 0xC631C631, 0xCE73CE73, 0xCE73CE73, 0xCE73D6B5, 0xD6B5D6B5,
    0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xCE73CE73, 0xD6B5CE73, 0xCE73CE73,
    0xCE73CE73, 0xCE73CE73, 0xCE73CE73, 0xCE73CE73, 0xCE73CE73, 0xD6B5CE73, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5,
    0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xCE73CE73, 0xCE73CE73, 0xD6B5CE73, 0xCE73CE73,
    0xCE73CE73, 0xD6B5CE73, 0xCE73D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5,
    0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xCE73CE73, 0xCE73D6B5, 0xCE73CE73, 0xCE73CE73, 0xCE73D6B5,
    0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5,
    0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5,
    0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5,
    0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5,
    0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5,
    0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5, 0xD6B5D6B5,
};

static u32 D_86403570[] = {
    0x00000000, 0x00001111, 0x11110000, 0x00000000, 0x00000000, 0x012579AA, 0xAA975210, 0x00000000, 0x00000001,
    0x48BEEFFF, 0xFFFEEB84, 0x10000000, 0x00000038, 0xCEFFFFFF, 0xFFFFFFEC, 0x83000000, 0x000005AE, 0xFFFFFFFF,
    0xFFFFFFFF, 0xEA500000, 0x00005CFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFC50000, 0x0004BFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFC4000, 0x002AFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFA200, 0x017EFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFE710,
    0x02BFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFB20, 0x05EFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFE50, 0x18FFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFF81, 0x19FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFF91, 0x1AFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFA1, 0x1AFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFA1, 0x19FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFF91, 0x18FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFF81, 0x05EFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFE50,
    0x02BFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFB30, 0x017EFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFE710, 0x002AFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFA200, 0x0005CFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFC5000, 0x00016CFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFC61000, 0x000015BE, 0xFFFFFFFF, 0xFFFFFFFF, 0xEB510000, 0x00000038, 0xDEFFFFFF, 0xFFFFFFFD,
    0x83000000, 0x00000001, 0x48CEEFFF, 0xFFFFEC84, 0x10000000, 0x00000000, 0x012579DF, 0xFDA85210, 0x00000000,
    0x00000000, 0x0000127E, 0xE7210000, 0x00000000, 0x00000000, 0x0000004E, 0xD4000000, 0x00000000, 0x00000000,
    0x0000003C, 0xA2000000, 0x00000000, 0x00000000, 0x00000018, 0x71000000, 0x00000000, 0x00000000, 0x00000003,
    0x20000000, 0x00000000,
};

static u32 D_86403770[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00444444,
    0x44444444, 0x44444444, 0x44444300, 0x00EFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFD00, 0x00EFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFD00, 0x00EFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFD00, 0x00FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFD00, 0x00788888, 0x88888888, 0x8888EFFF, 0xFFFFF900, 0x00000000, 0x00000000, 0x0009FFFF, 0xFFFF9000,
    0x00000000, 0x00000000, 0x00AFFFFF, 0xFFF80000, 0x00000000, 0x00000000, 0x1BFFFFFF, 0xFF700000, 0x00000000,
    0x00000001, 0xCFFFFFFF, 0xF6000000, 0x00000000, 0x0000002C, 0xFFFFFFFF, 0x50000000, 0x00000000, 0x000002DF,
    0xFFFFFFF5, 0x00000000, 0x00000000, 0x00003EFF, 0xFFFFFE40, 0x00000000, 0x00000000, 0x0004EFFF, 0xFFFFE300,
    0x00000000, 0x00000000, 0x004EFFFF, 0xFFFD3000, 0x00000000, 0x00000000, 0x05FFFFFF, 0xFFD20000, 0x00000000,
    0x00000000, 0x6FFFFFFF, 0xFC100000, 0x00000000, 0x00000007, 0xFFFFFFFF, 0xB1000000, 0x00000000, 0x0000008F,
    0xFFFFFFFB, 0x10000000, 0x00000000, 0x000008FF, 0xFFFFFFA0, 0x00000000, 0x00000000, 0x00009FFF, 0xFFFFF900,
    0x00000000, 0x00000000, 0x000AFFFF, 0xFFFF8000, 0x00000000, 0x00000000, 0x01BFFFFF, 0xFFF80000, 0x00000000,
    0x00000000, 0x06FFFFFF, 0xFFFDDDDD, 0xDDDDDDDD, 0xDDDDDB00, 0x06FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFE00,
    0x06FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFD00, 0x06FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFE00, 0x05DDDDDD,
    0xDDDDDDDD, 0xDDDDDDDD, 0xDDDDDB00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

static Vtx D_86403B70[] = {
    VTX(-16, 32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, 32, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, 0, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, 0, 0, 1024, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
};

Gfx D_86403BB0[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    gsDPLoadTextureTile(D_86402D70, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsDPLoadMultiTile_4b(D_86403570, 0x0100, 1, G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_86403B70, 4, 0),
    gsSP2Triangles(0, 3, 1, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

static Vtx D_86403C70[] = {
    VTX(-152, 676, 0, 0, -1146, 0xFF, 0x96, 0x96, 0x40), VTX(-158, 594, 0, 0, -655, 0xFF, 0x96, 0x96, 0x40),
    VTX(12, 583, 0, 1024, -655, 0xFF, 0x96, 0x96, 0x40), VTX(62, 683, 0, 1024, -1146, 0xFF, 0x96, 0x96, 0x40),
    VTX(-181, 553, 0, 0, -163, 0xFF, 0x96, 0x96, 0x53),  VTX(-30, 527, 0, 1024, -163, 0xFF, 0x96, 0x96, 0x53),
    VTX(-204, 520, 0, 0, 327, 0xFF, 0x96, 0x96, 0x53),   VTX(-40, 498, 0, 1024, 327, 0xFF, 0x96, 0x96, 0x53),
    VTX(-194, 470, 0, 0, 819, 0xFF, 0x96, 0xFF, 0x66),   VTX(-72, 478, 0, 1024, 819, 0xFF, 0x96, 0xFF, 0x66),
    VTX(-183, 404, 0, 0, 1310, 0xFF, 0x96, 0xFF, 0x66),  VTX(-70, 432, 0, 1024, 1310, 0xFF, 0x96, 0xFF, 0x66),
    VTX(-175, 377, 0, 0, 1802, 0xFF, 0x96, 0xFF, 0x79),  VTX(-69, 393, 0, 1024, 1802, 0xFF, 0x96, 0xFF, 0x79),
    VTX(-178, 342, 0, 0, 2293, 0xFF, 0x96, 0xFF, 0x79),  VTX(-48, 375, 0, 1024, 2293, 0xFF, 0x96, 0xFF, 0x79),
    VTX(-135, 324, 0, 0, 2785, 0x96, 0x96, 0xFF, 0x8C),  VTX(-46, 349, 0, 1024, 2785, 0x96, 0x96, 0xFF, 0x8C),
    VTX(-112, 312, 0, 0, 3276, 0x96, 0x96, 0xFF, 0x8C),  VTX(-24, 329, 0, 1024, 3276, 0x96, 0x96, 0xFF, 0x8C),
    VTX(-91, 275, 0, 0, 3768, 0x96, 0x96, 0xFF, 0x9F),   VTX(-8, 298, 0, 1024, 3768, 0x96, 0x96, 0xFF, 0x9F),
    VTX(-83, 245, 0, 0, 4259, 0x96, 0x96, 0xFF, 0x9F),   VTX(-1, 256, 0, 1024, 4259, 0x96, 0x96, 0xFF, 0x9F),
    VTX(-73, 221, 0, 0, 4751, 0x96, 0xFF, 0x96, 0xB2),   VTX(-11, 218, 0, 1024, 4751, 0x96, 0xFF, 0x96, 0xB2),
    VTX(-69, 177, 0, 0, 5242, 0x96, 0xFF, 0x96, 0xB2),   VTX(4, 177, 0, 1024, 5242, 0x96, 0xFF, 0x96, 0xB2),
    VTX(-51, 144, 0, 0, 5734, 0x96, 0xFF, 0x96, 0xC5),   VTX(-5, 134, 0, 1024, 5734, 0x96, 0xFF, 0x96, 0xC5),
    VTX(-64, 113, 0, 0, 6225, 0x96, 0xFF, 0x96, 0xC5),   VTX(-21, 102, 0, 1024, 6225, 0x96, 0xFF, 0x96, 0xC5),
};

static Vtx D_86403E70[] = {
    VTX(-64, 113, 0, 0, 6225, 0xFF, 0xFF, 0x96, 0xD8),   VTX(-69, 94, 0, 0, 6717, 0xFF, 0xFF, 0x96, 0xD8),
    VTX(-20, 86, 0, 1024, 6717, 0xFF, 0xFF, 0x96, 0xD8), VTX(-21, 102, 0, 1024, 6225, 0xFF, 0xFF, 0x96, 0xD8),
    VTX(-65, 55, 0, 0, 7208, 0xFF, 0xFF, 0x96, 0xEB),    VTX(-22, 53, 0, 1024, 7208, 0xFF, 0xFF, 0x96, 0xEB),
    VTX(-46, 34, 0, 0, 7700, 0xFF, 0xFF, 0x96, 0xEB),    VTX(-15, 34, 0, 1024, 7700, 0xFF, 0xFF, 0x96, 0xEB),
    VTX(-32, 18, 0, 0, 8192, 0xFF, 0xFF, 0xFF, 0xFE),    VTX(-3, 18, 0, 1024, 8192, 0xFF, 0xFF, 0xFF, 0xFE),
    VTX(-2, 0, 0, 0, 8683, 0xFF, 0xFF, 0xFF, 0xFE),      VTX(4, 0, 0, 1024, 8683, 0xFF, 0xFF, 0xFF, 0xFE),
};

Gfx D_86403F30[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_PASS2),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock_4b(D_86403770, G_IM_FMT_I, 32, 64, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5,
                            6, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};

Gfx D_86403FA0[] = {
    gsDPPipeSync(),
    gsSPVertex(D_86403C70, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSP2Triangles(4, 6, 7, 0, 4, 7, 5, 0),
    gsSP2Triangles(6, 8, 9, 0, 6, 9, 7, 0),
    gsSP2Triangles(8, 10, 11, 0, 8, 11, 9, 0),
    gsSP2Triangles(10, 12, 13, 0, 10, 13, 11, 0),
    gsSP2Triangles(12, 14, 15, 0, 12, 15, 13, 0),
    gsSP2Triangles(14, 16, 17, 0, 14, 17, 15, 0),
    gsSP2Triangles(16, 18, 19, 0, 16, 19, 17, 0),
    gsSP2Triangles(18, 20, 21, 0, 18, 21, 19, 0),
    gsSP2Triangles(20, 22, 23, 0, 20, 23, 21, 0),
    gsSP2Triangles(22, 24, 25, 0, 22, 25, 23, 0),
    gsSP2Triangles(24, 26, 27, 0, 24, 27, 25, 0),
    gsSP2Triangles(26, 28, 29, 0, 26, 29, 27, 0),
    gsSP2Triangles(28, 30, 31, 0, 28, 31, 29, 0),
    gsSPVertex(D_86403E70, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSP2Triangles(4, 6, 7, 0, 4, 7, 5, 0),
    gsSP2Triangles(6, 8, 9, 0, 6, 9, 7, 0),
    gsSP2Triangles(8, 10, 11, 0, 8, 11, 9, 0),
    gsSPEndDisplayList(),
};

s8 func_864026D0(u8 arg0, s32 arg1) {
    u8 i;
    u16 var_a0;
    u16 var_a1;
    u16 temp_a1;

    for (var_a0 = 0, i = 0; i < 8; i++) {
        var_a0 += D_864029F0[arg1][arg0][i];
    }

    temp_a1 = func_87B00050(var_a0);

    for (var_a1 = 0, i = 0; i < 7; i++) {
        if ((temp_a1 >= var_a1) && (temp_a1 < (D_864029F0[arg1][arg0][i] + var_a1))) {
            return i - 3;
        }
        var_a1 += D_864029F0[arg1][arg0][i];
    }

    return 0x64;
}
