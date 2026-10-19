#include "gb_data.h"
#include "include/string.h"
#include "src/gb_data.h"
#include "src/save_data.h"
#include "src/text_system.h"
#include "src/gb_tower.h"
#include "src/hal_libc.h"
#include "src/util.h"

// Name strings for these tables live in status_icons.c.
extern const char sStatusNames[7][4];
extern const char sTypeNames[17][4];
extern const char sMoveNames[166][8];
extern const char D_8007BB50[];
extern const char D_8007BB60[];
extern const char D_8007BB70[];
extern const char D_8007BB80[];
extern const char D_8007BB94[];
extern const char D_8007BBA4[];
extern const char D_8007BBB0[];
extern const char D_8007BBBC[];
extern const char D_8007BBCC[];
extern const char D_8007BBDC[];
extern const char D_8007BBE8[];
extern const char D_8007BBF4[];
extern const char D_8007BC04[];
extern const char D_8007BC14[];
extern const char D_8007BC24[];
extern const char D_8007BC30[];
extern const char D_8007BC44[];
extern const char D_8007BC58[];
extern const char D_8007BC6C[];
extern const char D_8007BC7C[];
extern const char D_8007BC88[];
extern const char D_8007BC98[];
extern const char D_8007BCA8[];
extern const char D_8007BCB8[];
extern const char D_8007BCCC[];
extern const char D_8007BCDC[];
extern const char D_8007BCEC[];
extern const char D_8007BD00[];
extern const char D_8007BD10[];
extern const char D_8007BD20[];
extern const char D_8007BD34[];
extern const char D_8007BD44[];
extern const char D_8007BD54[];
extern const char D_8007BD64[];
extern const char D_8007BD70[];
extern const char D_8007BD80[];
extern const char D_8007BD8C[];
extern const char D_8007BD9C[];
extern const char D_8007BDAC[];
extern const char D_8007BDB8[];
extern const char D_8007BDC8[];
extern const char D_8007BDD8[];
extern const char D_8007BDE8[];
extern const char D_8007BDF8[];
extern const char D_8007BE04[];
extern const char D_8007BE14[];
extern const char D_8007BE24[];
extern const char D_8007BE34[];
extern const char D_8007BE40[];
extern const char D_8007BE4C[];
extern const char D_8007BE5C[];
extern const char D_8007BE70[];
extern const char D_8007BE80[];
extern const char D_8007BE90[];
extern const char D_8007BEA4[];
extern const char D_8007BEB8[];
extern const char D_8007BECC[];
extern const char D_8007BEE0[];
extern const char D_8007BEF4[];
extern const char D_8007BEFC[];
extern const char D_8007BF0C[];
extern const char D_8007BF1C[];
extern const char D_8007BF2C[];
extern const char D_8007BF3C[];
extern const char D_8007BF4C[];
extern const char D_8007BF5C[];
extern const char D_8007BF6C[];
extern const char D_8007BF78[];
extern const char D_8007BF8C[];
extern const char D_8007BF9C[];
extern const char D_8007BFAC[];
extern const char D_8007BFC0[];
extern const char D_8007BFD0[];
extern const char D_8007BFE0[];
extern const char D_8007BFF4[];
extern const char D_8007C008[];
extern const char D_8007C018[];
extern const char D_8007C028[];
extern const char D_8007C038[];
extern const char D_8007C048[];
extern const char D_8007C058[];
extern const char D_8007C06C[];
extern const char D_8007C080[];

SpeciesData gSpeciesData[152] = {
    { 1, 45, 49, 49, 45, 65, 22, 3, 45, 64, {33, 45, 0, 0}, 3, {0xA4, 0x03, 0x38, 0xC0, 0x03, 0x08, 0x06}, 0 },
    { 2, 60, 62, 63, 60, 80, 22, 3, 45, 141, {33, 45, 73, 0}, 3, {0xA4, 0x03, 0x38, 0xC0, 0x03, 0x08, 0x06}, 0 },
    { 3, 80, 82, 83, 80, 100, 22, 3, 45, 208, {33, 45, 73, 22}, 3, {0xA4, 0x43, 0x38, 0xC0, 0x03, 0x08, 0x06}, 0 },
    { 4, 39, 52, 43, 65, 50, 20, 20, 45, 65, {10, 45, 0, 0}, 3, {0xB5, 0x03, 0x4F, 0xC8, 0xE3, 0x08, 0x26}, 0 },
    { 5, 58, 64, 58, 80, 65, 20, 20, 45, 142, {10, 45, 52, 0}, 3, {0xB5, 0x03, 0x4F, 0xC8, 0xE3, 0x08, 0x26}, 0 },
    { 6, 78, 84, 78, 100, 85, 20, 2, 45, 209, {10, 45, 52, 43}, 3, {0xB5, 0x43, 0x4F, 0xCE, 0xE3, 0x08, 0x26}, 0 },
    { 7, 44, 48, 65, 43, 50, 21, 21, 45, 66, {33, 39, 0, 0}, 3, {0xB1, 0x3F, 0x0F, 0xC8, 0x83, 0x08, 0x32}, 0 },
    { 8, 59, 63, 80, 58, 65, 21, 21, 45, 143, {33, 39, 145, 0}, 3, {0xB1, 0x3F, 0x0F, 0xC8, 0x83, 0x08, 0x32}, 0 },
    { 9, 79, 83, 100, 78, 85, 21, 21, 45, 210, {33, 39, 145, 55}, 3, {0xB1, 0x7F, 0x0F, 0xCE, 0x83, 0x08, 0x32}, 0 },
    { 10, 45, 30, 35, 45, 20, 7, 7, 0xFF, 53, {33, 81, 0, 0}, 0, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0 },
    { 11, 50, 20, 55, 30, 25, 7, 7, 120, 72, {106, 0, 0, 0}, 0, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0 },
    { 12, 60, 45, 50, 70, 80, 7, 2, 45, 160, {93, 0, 0, 0}, 0, {0x2A, 0x43, 0x38, 0xF0, 0x43, 0x28, 0x02}, 0 },
    { 13, 40, 35, 30, 50, 20, 7, 3, 0xFF, 52, {40, 81, 0, 0}, 0, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0 },
    { 14, 45, 25, 50, 35, 25, 7, 3, 120, 71, {106, 0, 0, 0}, 0, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0 },
    { 15, 65, 80, 40, 75, 45, 7, 3, 45, 159, {31, 0, 0, 0}, 0, {0x24, 0x43, 0x18, 0xC0, 0xC3, 0x08, 0x06}, 0 },
    { 16, 40, 45, 40, 56, 35, 0, 2, 0xFF, 55, {16, 0, 0, 0}, 3, {0x2A, 0x03, 0x08, 0xC0, 0x43, 0x0C, 0x0A}, 0 },
    { 17, 63, 60, 55, 71, 50, 0, 2, 120, 113, {16, 28, 0, 0}, 3, {0x2A, 0x03, 0x08, 0xC0, 0x43, 0x0C, 0x0A}, 0 },
    { 18, 83, 80, 75, 91, 70, 0, 2, 45, 172, {16, 28, 98, 0}, 3, {0x2A, 0x43, 0x08, 0xC0, 0x43, 0x0C, 0x0A}, 0 },
    { 19, 30, 56, 35, 72, 25, 0, 0, 0xFF, 57, {33, 39, 0, 0}, 0, {0xA0, 0x2F, 0x88, 0xC9, 0xC2, 0x08, 0x02}, 0 },
    { 20, 55, 81, 60, 97, 50, 0, 0, 90, 116, {33, 39, 98, 0}, 0, {0xA0, 0x7F, 0x88, 0xC9, 0xC2, 0x08, 0x02}, 0 },
    { 21, 40, 60, 30, 70, 31, 0, 2, 0xFF, 58, {64, 45, 0, 0}, 0, {0x2A, 0x03, 0x08, 0xC0, 0x42, 0x0C, 0x0A}, 0 },
    { 22, 65, 90, 65, 100, 61, 0, 2, 90, 162, {64, 45, 43, 0}, 0, {0x2A, 0x43, 0x08, 0xC0, 0x42, 0x0C, 0x0A}, 0 },
    { 23, 35, 60, 44, 55, 40, 3, 3, 0xFF, 62, {35, 43, 0, 0}, 0, {0xA0, 0x03, 0x18, 0xCE, 0x82, 0x88, 0x22}, 0 },
    { 24, 60, 85, 69, 80, 65, 3, 3, 90, 147, {35, 43, 40, 0}, 0, {0xA0, 0x43, 0x18, 0xCE, 0x82, 0x88, 0x22}, 0 },
    { 25, 35, 55, 30, 90, 50, 23, 23, 190, 82, {84, 45, 0, 0}, 0, {0xB1, 0x83, 0x8D, 0xC1, 0xC3, 0x18, 0x42}, 0 },
    { 26, 60, 90, 55, 100, 90, 23, 23, 75, 122, {84, 45, 86, 0}, 0, {0xB1, 0xC3, 0x8D, 0xC1, 0xC3, 0x18, 0x42}, 0 },
    { 27, 50, 75, 85, 40, 30, 4, 4, 0xFF, 93, {10, 0, 0, 0}, 0, {0xA4, 0x03, 0x0D, 0xCE, 0xC2, 0x88, 0x26}, 0 },
    { 28, 75, 100, 110, 65, 55, 4, 4, 90, 163, {10, 28, 0, 0}, 0, {0xA4, 0x43, 0x0D, 0xCE, 0xC2, 0x88, 0x26}, 0 },
    { 29, 55, 47, 52, 41, 40, 3, 3, 235, 59, {45, 33, 0, 0}, 3, {0xA0, 0x23, 0x88, 0xC1, 0x83, 0x08, 0x02}, 0 },
    { 30, 70, 62, 67, 56, 55, 3, 3, 120, 117, {45, 33, 10, 0}, 3, {0xE0, 0x3F, 0x88, 0xC1, 0x83, 0x08, 0x02}, 0 },
    { 31, 90, 82, 87, 76, 75, 3, 4, 45, 194, {33, 10, 39, 34}, 3, {0xF1, 0xFF, 0x8F, 0xC7, 0xA3, 0x88, 0x32}, 0 },
    { 32, 46, 57, 40, 50, 40, 3, 3, 235, 60, {43, 33, 0, 0}, 3, {0xE0, 0x23, 0x88, 0xC1, 0x83, 0x08, 0x02}, 0 },
    { 33, 61, 72, 57, 65, 55, 3, 3, 120, 118, {43, 33, 30, 0}, 3, {0xE0, 0x3F, 0x88, 0xC1, 0x83, 0x08, 0x02}, 0 },
    { 34, 81, 92, 77, 85, 75, 3, 4, 45, 195, {33, 30, 40, 37}, 3, {0xF1, 0xFF, 0x8F, 0xC7, 0xA3, 0x88, 0x32}, 0 },
    { 35, 70, 45, 48, 35, 60, 0, 0, 150, 68, {1, 45, 0, 0}, 4, {0xB1, 0x3F, 0xAF, 0xF1, 0xA7, 0x38, 0x63}, 0 },
    { 36, 95, 70, 73, 60, 85, 0, 0, 25, 129, {47, 3, 107, 118}, 4, {0xB1, 0x7F, 0xAF, 0xF1, 0xA7, 0x38, 0x63}, 0 },
    { 37, 38, 41, 40, 65, 65, 20, 20, 190, 63, {52, 39, 0, 0}, 0, {0xA0, 0x03, 0x08, 0xC8, 0xE3, 0x08, 0x02}, 0 },
    { 38, 73, 76, 75, 100, 100, 20, 20, 75, 178, {52, 39, 98, 46}, 0, {0xA0, 0x43, 0x08, 0xC8, 0xE3, 0x08, 0x02}, 0 },
    { 39, 115, 45, 20, 20, 25, 0, 0, 170, 76, {47, 0, 0, 0}, 4, {0xB1, 0x3F, 0xAF, 0xF1, 0xA3, 0x38, 0x63}, 0 },
    { 40, 140, 70, 45, 45, 50, 0, 0, 50, 109, {47, 50, 111, 3}, 4, {0xB1, 0x7F, 0xAF, 0xF1, 0xA3, 0x38, 0x63}, 0 },
    { 41, 40, 45, 35, 55, 40, 3, 2, 0xFF, 54, {141, 0, 0, 0}, 0, {0x2A, 0x03, 0x18, 0xC0, 0x42, 0x08, 0x02}, 0 },
    { 42, 75, 80, 70, 90, 75, 3, 2, 90, 171, {141, 103, 44, 0}, 0, {0x2A, 0x43, 0x18, 0xC0, 0x42, 0x08, 0x02}, 0 },
    { 43, 45, 50, 55, 30, 75, 22, 3, 0xFF, 78, {71, 0, 0, 0}, 3, {0x24, 0x03, 0x38, 0xC0, 0x03, 0x08, 0x06}, 0 },
    { 44, 60, 65, 70, 40, 85, 22, 3, 120, 132, {71, 77, 78, 0}, 3, {0x24, 0x03, 0x38, 0xC0, 0x03, 0x08, 0x06}, 0 },
    { 45, 75, 80, 85, 50, 100, 22, 3, 45, 184, {78, 79, 51, 80}, 3, {0xA4, 0x43, 0x38, 0xC0, 0x03, 0x08, 0x06}, 0 },
    { 46, 35, 70, 55, 25, 55, 7, 22, 190, 70, {10, 0, 0, 0}, 0, {0xA4, 0x03, 0x38, 0xC8, 0x83, 0x08, 0x06}, 0 },
    { 47, 60, 95, 80, 30, 80, 7, 22, 75, 128, {10, 78, 141, 0}, 0, {0xA4, 0x43, 0x38, 0xC8, 0x83, 0x08, 0x06}, 0 },
    { 48, 60, 55, 50, 45, 40, 7, 3, 190, 75, {33, 50, 0, 0}, 0, {0x20, 0x03, 0x38, 0xD0, 0x03, 0x28, 0x02}, 0 },
    { 49, 70, 65, 60, 90, 90, 7, 3, 75, 138, {33, 50, 77, 141}, 0, {0x2A, 0x43, 0x38, 0xF0, 0x43, 0x28, 0x02}, 0 },
    { 50, 10, 55, 25, 95, 45, 4, 4, 0xFF, 81, {10, 0, 0, 0}, 0, {0xA0, 0x03, 0x08, 0xCE, 0x02, 0x88, 0x02}, 0 },
    { 51, 35, 80, 50, 120, 70, 4, 4, 50, 153, {10, 45, 91, 0}, 0, {0xA0, 0x43, 0x08, 0xCE, 0x02, 0x88, 0x02}, 0 },
    { 52, 40, 45, 35, 90, 40, 0, 0, 0xFF, 69, {10, 45, 0, 0}, 0, {0xA0, 0x8F, 0x88, 0xC1, 0xC2, 0x08, 0x02}, 0 },
    { 53, 65, 70, 60, 115, 65, 0, 0, 90, 148, {10, 45, 44, 103}, 0, {0xA0, 0xCF, 0x88, 0xC1, 0xC2, 0x08, 0x02}, 0 },
    { 54, 50, 52, 48, 55, 50, 21, 21, 190, 80, {10, 0, 0, 0}, 0, {0xB1, 0xBF, 0x0F, 0xC8, 0xC2, 0x08, 0x32}, 0 },
    { 55, 80, 82, 78, 85, 80, 21, 21, 75, 174, {10, 39, 50, 0}, 0, {0xB1, 0xFF, 0x0F, 0xC8, 0xC2, 0x08, 0x32}, 0 },
    { 56, 40, 80, 35, 70, 35, 1, 1, 190, 74, {10, 43, 0, 0}, 0, {0xB1, 0x83, 0x8F, 0xC9, 0xC6, 0x88, 0x22}, 0 },
    { 57, 65, 105, 60, 95, 60, 1, 1, 75, 149, {10, 43, 2, 154}, 0, {0xB1, 0xC3, 0x8F, 0xC9, 0xC6, 0x88, 0x22}, 0 },
    { 58, 55, 70, 45, 60, 50, 20, 20, 190, 91, {44, 46, 0, 0}, 5, {0xA0, 0x03, 0x48, 0xC8, 0xE3, 0x08, 0x02}, 0 },
    { 59, 90, 110, 80, 95, 80, 20, 20, 75, 213, {46, 52, 43, 36}, 5, {0xA0, 0x43, 0x48, 0xE8, 0xE3, 0x08, 0x02}, 0 },
    { 60, 40, 50, 40, 90, 40, 21, 21, 0xFF, 77, {145, 0, 0, 0}, 3, {0xA0, 0x3F, 0x08, 0xD0, 0x82, 0x28, 0x12}, 0 },
    { 61, 65, 65, 65, 90, 50, 21, 21, 120, 131, {145, 95, 55, 0}, 3, {0xB1, 0x3F, 0x0F, 0xD6, 0x86, 0x28, 0x32}, 0 },
    { 62, 90, 85, 95, 70, 70, 21, 1, 45, 185, {95, 55, 3, 34}, 3, {0xB1, 0x7F, 0x0F, 0xD6, 0x86, 0x28, 0x32}, 0 },
    { 63, 25, 20, 15, 90, 105, 24, 24, 200, 73, {100, 0, 0, 0}, 3, {0xB1, 0x03, 0x0F, 0xF0, 0x87, 0x38, 0x43}, 0 },
    { 64, 40, 35, 30, 105, 120, 24, 24, 100, 145, {100, 93, 50, 0}, 3, {0xB1, 0x03, 0x0F, 0xF8, 0x87, 0x38, 0x43}, 0 },
    { 65, 55, 50, 45, 120, 135, 24, 24, 50, 186, {100, 93, 50, 0}, 3, {0xB1, 0x43, 0x0F, 0xF8, 0x87, 0x38, 0x43}, 0 },
    { 66, 70, 80, 50, 35, 35, 1, 1, 180, 88, {2, 0, 0, 0}, 3, {0xB1, 0x03, 0x0F, 0xCE, 0xA6, 0x88, 0x22}, 0 },
    { 67, 80, 100, 70, 45, 50, 1, 1, 90, 146, {2, 67, 43, 0}, 3, {0xB1, 0x03, 0x0F, 0xCE, 0xA6, 0x88, 0x22}, 0 },
    { 68, 90, 130, 80, 55, 65, 1, 1, 45, 193, {2, 67, 43, 0}, 3, {0xB1, 0x43, 0x0F, 0xCE, 0xA6, 0x88, 0x22}, 0 },
    { 69, 50, 75, 35, 40, 70, 22, 3, 0xFF, 84, {22, 74, 0, 0}, 3, {0x24, 0x03, 0x38, 0xC0, 0x03, 0x08, 0x06}, 0 },
    { 70, 65, 90, 50, 55, 85, 22, 3, 120, 151, {22, 74, 35, 0}, 3, {0x24, 0x03, 0x38, 0xC0, 0x03, 0x08, 0x06}, 0 },
    { 71, 80, 105, 65, 70, 100, 22, 3, 45, 191, {79, 78, 51, 75}, 3, {0xA4, 0x43, 0x38, 0xC0, 0x03, 0x08, 0x06}, 0 },
    { 72, 40, 40, 35, 70, 100, 21, 3, 190, 105, {51, 0, 0, 0}, 5, {0x24, 0x3F, 0x18, 0xC0, 0x83, 0x08, 0x16}, 0 },
    { 73, 80, 70, 65, 100, 120, 21, 3, 60, 205, {51, 48, 35, 0}, 5, {0x24, 0x7F, 0x18, 0xC0, 0x83, 0x08, 0x16}, 0 },
    { 74, 40, 80, 100, 20, 30, 5, 4, 0xFF, 86, {33, 0, 0, 0}, 3, {0xA1, 0x03, 0x0F, 0xCE, 0x2E, 0xC8, 0x22}, 0 },
    { 75, 55, 95, 115, 35, 45, 5, 4, 120, 134, {33, 111, 0, 0}, 3, {0xA1, 0x03, 0x0F, 0xCE, 0x2E, 0xC8, 0x22}, 0 },
    { 76, 80, 110, 130, 45, 55, 5, 4, 45, 177, {33, 111, 0, 0}, 3, {0xB1, 0x43, 0x0F, 0xCE, 0x2E, 0xC8, 0x22}, 0 },
    { 77, 50, 85, 55, 90, 65, 20, 20, 190, 152, {52, 0, 0, 0}, 0, {0xE0, 0x03, 0x08, 0xC0, 0xE3, 0x08, 0x02}, 0 },
    { 78, 65, 100, 70, 105, 80, 20, 20, 60, 192, {52, 39, 23, 45}, 0, {0xE0, 0x43, 0x08, 0xC0, 0xE3, 0x08, 0x02}, 0 },
    { 79, 90, 65, 65, 15, 40, 21, 24, 190, 99, {93, 0, 0, 0}, 0, {0xA0, 0xBF, 0x08, 0xFE, 0xE3, 0x38, 0x73}, 0 },
    { 80, 95, 75, 110, 30, 80, 21, 24, 75, 164, {93, 50, 29, 0}, 0, {0xB1, 0xFF, 0x0F, 0xFE, 0xE3, 0x38, 0x73}, 0 },
    { 81, 25, 35, 70, 45, 95, 23, 23, 190, 89, {33, 0, 0, 0}, 0, {0x20, 0x03, 0x88, 0xE1, 0x43, 0x18, 0x42}, 0 },
    { 82, 50, 60, 95, 70, 120, 23, 23, 60, 161, {33, 49, 84, 0}, 0, {0x20, 0x43, 0x88, 0xE1, 0x43, 0x18, 0x42}, 0 },
    { 83, 52, 65, 55, 60, 58, 0, 2, 45, 94, {64, 28, 0, 0}, 0, {0xAE, 0x03, 0x08, 0xC0, 0xC3, 0x08, 0x0E}, 0 },
    { 84, 35, 85, 45, 75, 35, 0, 2, 190, 96, {64, 0, 0, 0}, 0, {0xA8, 0x03, 0x08, 0xC0, 0x83, 0x0C, 0x0B}, 0 },
    { 85, 60, 110, 70, 100, 60, 0, 2, 45, 158, {64, 45, 31, 0}, 0, {0xA8, 0x43, 0x08, 0xC0, 0x83, 0x0C, 0x0B}, 0 },
    { 86, 65, 45, 55, 45, 70, 21, 21, 190, 100, {29, 0, 0, 0}, 0, {0xE0, 0xBF, 0x08, 0xC0, 0x82, 0x08, 0x32}, 0 },
    { 87, 90, 70, 80, 70, 95, 21, 25, 75, 176, {29, 45, 62, 0}, 0, {0xE0, 0xFF, 0x08, 0xC0, 0x82, 0x08, 0x32}, 0 },
    { 88, 80, 80, 50, 25, 40, 3, 3, 190, 90, {1, 50, 0, 0}, 0, {0xA0, 0x00, 0x98, 0xC1, 0x2A, 0x48, 0x02}, 0 },
    { 89, 105, 105, 75, 50, 65, 3, 3, 75, 157, {1, 50, 139, 0}, 0, {0xA0, 0x40, 0x98, 0xC1, 0x2A, 0x48, 0x02}, 0 },
    { 90, 30, 65, 100, 40, 45, 21, 21, 190, 97, {33, 110, 0, 0}, 5, {0x20, 0x3F, 0x08, 0xE0, 0x4B, 0x48, 0x13}, 0 },
    { 91, 50, 95, 180, 70, 85, 21, 25, 60, 203, {110, 48, 128, 62}, 5, {0x20, 0x7F, 0x08, 0xE0, 0x4B, 0x48, 0x13}, 0 },
    { 92, 30, 35, 30, 80, 100, 8, 3, 190, 95, {122, 109, 101, 0}, 3, {0x20, 0x00, 0x98, 0xD1, 0x0A, 0x6A, 0x02}, 0 },
    { 93, 45, 50, 45, 95, 115, 8, 3, 90, 126, {122, 109, 101, 0}, 3, {0x20, 0x00, 0x98, 0xD1, 0x0A, 0x6A, 0x02}, 0 },
    { 94, 60, 65, 60, 110, 130, 8, 3, 45, 190, {122, 109, 101, 0}, 3, {0xB1, 0x43, 0x9F, 0xD1, 0x8E, 0x6A, 0x22}, 0 },
    { 95, 35, 45, 160, 70, 30, 5, 4, 45, 108, {33, 103, 0, 0}, 0, {0xA0, 0x03, 0x08, 0xCE, 0x8A, 0xC8, 0x22}, 0 },
    { 96, 60, 48, 45, 42, 90, 24, 24, 190, 102, {1, 95, 0, 0}, 0, {0xB1, 0x03, 0x0F, 0xF0, 0x87, 0x3A, 0x43}, 0 },
    { 97, 85, 73, 70, 67, 115, 24, 24, 75, 165, {1, 95, 50, 93}, 0, {0xB1, 0x43, 0x0F, 0xF0, 0x87, 0x3A, 0x43}, 0 },
    { 98, 30, 105, 90, 50, 25, 21, 21, 225, 115, {145, 43, 0, 0}, 0, {0xA4, 0x3F, 0x08, 0xC0, 0x02, 0x08, 0x36}, 0 },
    { 99, 55, 130, 115, 75, 50, 21, 21, 60, 206, {145, 43, 11, 0}, 0, {0xA4, 0x7F, 0x08, 0xC0, 0x02, 0x08, 0x36}, 0 },
    { 100, 40, 30, 50, 100, 55, 23, 23, 190, 103, {33, 103, 0, 0}, 0, {0x20, 0x01, 0x88, 0xE1, 0x4B, 0x58, 0x42}, 0 },
    { 101, 60, 50, 70, 140, 80, 23, 23, 60, 150, {33, 103, 49, 0}, 0, {0x20, 0x41, 0x88, 0xE1, 0xCB, 0x58, 0x42}, 0 },
    { 102, 60, 40, 80, 40, 60, 22, 24, 90, 98, {140, 95, 0, 0}, 5, {0x20, 0x03, 0x08, 0xF0, 0x1B, 0x68, 0x02}, 0 },
    { 103, 95, 95, 85, 55, 125, 22, 24, 45, 212, {140, 95, 0, 0}, 5, {0x20, 0x43, 0x38, 0xF0, 0x1B, 0x68, 0x22}, 0 },
    { 104, 50, 50, 95, 35, 40, 4, 4, 190, 87, {125, 45, 0, 0}, 0, {0xB1, 0x3F, 0x0F, 0xCE, 0xA2, 0x08, 0x22}, 0 },
    { 105, 60, 80, 110, 45, 50, 4, 4, 75, 124, {125, 45, 43, 116}, 0, {0xB1, 0x7F, 0x0F, 0xCE, 0xA2, 0x08, 0x22}, 0 },
    { 106, 50, 120, 53, 87, 35, 1, 1, 45, 139, {24, 96, 0, 0}, 0, {0xB1, 0x03, 0x0F, 0xC0, 0xC6, 0x08, 0x22}, 0 },
    { 107, 50, 105, 79, 76, 35, 1, 1, 45, 140, {4, 97, 0, 0}, 0, {0xB1, 0x03, 0x0F, 0xC0, 0xC6, 0x08, 0x22}, 0 },
    { 108, 90, 55, 75, 30, 60, 0, 0, 45, 127, {35, 48, 0, 0}, 0, {0xB5, 0x7F, 0x8F, 0xC7, 0xA2, 0x08, 0x36}, 0 },
    { 109, 40, 65, 95, 35, 60, 3, 3, 190, 114, {33, 123, 0, 0}, 0, {0x20, 0x00, 0x88, 0xC1, 0x2A, 0x48, 0x02}, 0 },
    { 110, 65, 90, 120, 60, 85, 3, 3, 60, 173, {33, 123, 124, 0}, 0, {0x20, 0x40, 0x88, 0xC1, 0x2A, 0x48, 0x02}, 0 },
    { 111, 80, 85, 95, 25, 30, 4, 5, 120, 135, {30, 0, 0, 0}, 5, {0xE0, 0x03, 0x88, 0xCF, 0xA2, 0x88, 0x22}, 0 },
    { 112, 105, 130, 120, 40, 45, 4, 5, 60, 204, {30, 23, 39, 31}, 5, {0xF1, 0xFF, 0x8F, 0xCF, 0xA2, 0x88, 0x32}, 0 },
    { 113, 250, 5, 5, 50, 105, 0, 0, 30, 0xFF, {1, 3, 0, 0}, 4, {0xB1, 0x7F, 0xAF, 0xF1, 0xB7, 0x39, 0x63}, 0 },
    { 114, 65, 55, 115, 60, 100, 22, 22, 45, 166, {132, 20, 0, 0}, 0, {0xA4, 0x43, 0x38, 0xC0, 0x82, 0x08, 0x06}, 0 },
    { 115, 105, 95, 80, 90, 40, 0, 0, 45, 175, {4, 99, 0, 0}, 0, {0xB1, 0x7F, 0x8F, 0xC7, 0xA2, 0x88, 0x32}, 0 },
    { 116, 30, 40, 70, 60, 70, 21, 21, 225, 83, {145, 0, 0, 0}, 0, {0x20, 0x3F, 0x08, 0xC0, 0xC2, 0x08, 0x12}, 0 },
    { 117, 55, 65, 95, 85, 95, 21, 21, 75, 155, {145, 108, 0, 0}, 0, {0x20, 0x7F, 0x08, 0xC0, 0xC2, 0x08, 0x12}, 0 },
    { 118, 45, 67, 60, 63, 50, 21, 21, 225, 111, {64, 39, 0, 0}, 0, {0x60, 0x3F, 0x08, 0xC0, 0xC2, 0x08, 0x12}, 0 },
    { 119, 80, 92, 65, 68, 80, 21, 21, 60, 170, {64, 39, 48, 0}, 0, {0x60, 0x7F, 0x08, 0xC0, 0xC2, 0x08, 0x12}, 0 },
    { 120, 30, 45, 55, 85, 70, 21, 21, 225, 106, {33, 0, 0, 0}, 5, {0x20, 0x3F, 0x88, 0xF1, 0xC3, 0x38, 0x53}, 0 },
    { 121, 60, 75, 85, 115, 100, 21, 24, 60, 207, {33, 55, 106, 0}, 5, {0x20, 0x7F, 0x88, 0xF1, 0xC3, 0x38, 0x53}, 0 },
    { 122, 40, 45, 65, 90, 100, 24, 24, 45, 136, {93, 112, 0, 0}, 0, {0xB1, 0x43, 0xAF, 0xF1, 0x87, 0x38, 0x42}, 0 },
    { 123, 70, 110, 80, 105, 55, 7, 2, 45, 187, {98, 0, 0, 0}, 0, {0x24, 0x43, 0x08, 0xC0, 0xC2, 0x08, 0x06}, 0 },
    { 124, 65, 50, 35, 95, 95, 25, 24, 45, 137, {1, 142, 0, 0}, 0, {0xB1, 0x7F, 0x0F, 0xF0, 0x87, 0x28, 0x02}, 0 },
    { 125, 65, 83, 57, 105, 85, 23, 23, 45, 156, {98, 43, 0, 0}, 0, {0xB1, 0x43, 0x8F, 0xF1, 0xC7, 0x38, 0x62}, 0 },
    { 126, 65, 95, 57, 93, 85, 20, 20, 45, 167, {52, 0, 0, 0}, 0, {0xB1, 0x43, 0x0F, 0xF0, 0xA6, 0x28, 0x22}, 0 },
    { 127, 65, 125, 100, 85, 55, 7, 7, 45, 200, {11, 0, 0, 0}, 5, {0xA4, 0x43, 0x0D, 0xC0, 0x02, 0x08, 0x26}, 0 },
    { 128, 75, 100, 95, 110, 70, 0, 0, 45, 211, {33, 0, 0, 0}, 5, {0xE0, 0x73, 0x88, 0xC7, 0xA2, 0x08, 0x22}, 0 },
    { 129, 20, 10, 55, 80, 20, 21, 21, 0xFF, 20, {150, 0, 0, 0}, 5, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0 },
    { 130, 95, 125, 79, 81, 100, 21, 2, 45, 214, {44, 82, 43, 56}, 5, {0xA0, 0x7F, 0xC8, 0xC1, 0xA3, 0x08, 0x32}, 0 },
    { 131, 130, 85, 80, 60, 95, 21, 25, 45, 219, {55, 45, 0, 0}, 5, {0xE0, 0x7F, 0xE8, 0xD1, 0x83, 0x28, 0x32}, 0 },
    { 132, 48, 48, 48, 48, 48, 0, 0, 35, 61, {144, 0, 0, 0}, 0, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0 },
    { 133, 55, 55, 50, 55, 65, 0, 0, 45, 92, {33, 28, 0, 0}, 0, {0xA0, 0x03, 0x08, 0xC0, 0xC3, 0x08, 0x02}, 0 },
    { 134, 130, 65, 60, 65, 110, 21, 21, 45, 196, {33, 28, 98, 55}, 0, {0xA0, 0x7F, 0x08, 0xC0, 0xC3, 0x08, 0x12}, 0 },
    { 135, 65, 65, 60, 130, 110, 23, 23, 45, 197, {33, 28, 98, 84}, 0, {0xA0, 0x43, 0x88, 0xC1, 0xC3, 0x18, 0x42}, 0 },
    { 136, 65, 130, 60, 65, 110, 20, 20, 45, 198, {33, 28, 98, 52}, 0, {0xA0, 0x43, 0x08, 0xC0, 0xE3, 0x08, 0x02}, 0 },
    { 137, 65, 60, 70, 40, 75, 0, 0, 45, 130, {33, 159, 160, 0}, 0, {0x20, 0x73, 0x88, 0xF1, 0xC3, 0x38, 0x43}, 0 },
    { 138, 35, 40, 100, 35, 90, 5, 21, 45, 120, {55, 110, 0, 0}, 0, {0xA0, 0x3F, 0x08, 0xC0, 0x03, 0x08, 0x12}, 0 },
    { 139, 70, 60, 125, 55, 115, 5, 21, 45, 199, {55, 110, 30, 0}, 0, {0xE0, 0x7F, 0x0D, 0xC0, 0x83, 0x08, 0x12}, 0 },
    { 140, 30, 80, 90, 55, 45, 5, 21, 45, 119, {10, 106, 0, 0}, 0, {0xA0, 0x3F, 0x08, 0xC0, 0x03, 0x08, 0x12}, 0 },
    { 141, 60, 115, 105, 80, 70, 5, 21, 45, 201, {10, 106, 71, 0}, 0, {0xB6, 0x7F, 0x0D, 0xC0, 0x83, 0x08, 0x12}, 0 },
    { 142, 80, 105, 65, 130, 60, 5, 2, 45, 202, {17, 97, 0, 0}, 5, {0x2A, 0x43, 0x48, 0xC0, 0x63, 0x0C, 0x0A}, 0 },
    { 143, 160, 110, 65, 30, 65, 0, 0, 25, 154, {29, 133, 156, 0}, 5, {0xB1, 0xFF, 0xAF, 0xD7, 0xAF, 0xA8, 0x32}, 0 },
    { 144, 90, 85, 100, 85, 125, 25, 2, 3, 215, {64, 58, 0, 0}, 5, {0x2A, 0x7F, 0x08, 0xC0, 0x43, 0x0C, 0x0A}, 0 },
    { 145, 90, 90, 85, 100, 125, 23, 2, 3, 216, {84, 65, 0, 0}, 5, {0x2A, 0x43, 0x88, 0xC1, 0x43, 0x1C, 0x4A}, 0 },
    { 146, 90, 100, 90, 90, 125, 20, 2, 3, 217, {64, 83, 0, 0}, 5, {0x2A, 0x43, 0x08, 0xC0, 0x63, 0x0C, 0x0A}, 0 },
    { 147, 41, 64, 45, 50, 50, 26, 26, 45, 67, {35, 43, 0, 0}, 5, {0xA0, 0x3F, 0xC8, 0xC1, 0xE3, 0x18, 0x12}, 0 },
    { 148, 61, 84, 65, 70, 70, 26, 26, 45, 144, {35, 43, 86, 0}, 5, {0xE0, 0x3F, 0xC8, 0xC1, 0xE3, 0x18, 0x12}, 0 },
    { 149, 91, 134, 95, 80, 100, 26, 2, 45, 218, {35, 43, 86, 97}, 5, {0xE2, 0x7F, 0xC8, 0xC1, 0xE3, 0x18, 0x32}, 0 },
    { 150, 106, 110, 90, 130, 154, 24, 24, 3, 220, {93, 50, 129, 94}, 5, {0xB1, 0xFF, 0xAF, 0xF1, 0xAF, 0x38, 0x63}, 0 },
    { 151, 100, 100, 100, 100, 100, 24, 24, 45, 64, {1, 0, 0, 0}, 3, {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 0xFF },
    { 152, 100, 100, 100, 100, 100, 2, 4, 45, 64, {1, 0, 0, 0}, 3, {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 0xFF },
};

unk_D_80071D88 sStatusDisplayInfo[8] = {
    { NULL, { 0x00, 0x00, 0x00, 0x00 } },
    { (char*) sStatusNames[0], { 0xFF, 0xFF, 0xFF, 0xFF } },
    { (char*) sStatusNames[1], { 0x4D, 0x4D, 0x4D, 0xFF } },
    { (char*) sStatusNames[2], { 0x9F, 0x91, 0xE8, 0xFF } },
    { (char*) sStatusNames[3], { 0x96, 0x50, 0xFF, 0xFF } },
    { (char*) sStatusNames[4], { 0xF0, 0x5A, 0x46, 0xFF } },
    { (char*) sStatusNames[5], { 0x85, 0xD5, 0xF1, 0xFF } },
    { (char*) sStatusNames[6], { 0xFF, 0xFF, 0x00, 0xFF } },
};

unk_D_80071D88 D_80071D88[17] = {
    { (char*) sTypeNames[0], { 0xF0, 0xF0, 0xF0, 0xFF } },
    { (char*) sTypeNames[1], { 0xF0, 0x96, 0x32, 0xFF } },
    { (char*) sTypeNames[2], { 0x50, 0x96, 0xF0, 0xFF } },
    { (char*) sTypeNames[3], { 0xC8, 0x96, 0xF0, 0xFF } },
    { (char*) sTypeNames[4], { 0xF0, 0xC8, 0x78, 0xFF } },
    { (char*) sTypeNames[5], { 0x64, 0xB4, 0xB4, 0xFF } },
    { (char*) sTypeNames[6], { 0x50, 0x96, 0xF0, 0xFF } },
    { (char*) sTypeNames[7], { 0xC8, 0xF0, 0x50, 0xFF } },
    { (char*) sTypeNames[8], { 0xDC, 0xC8, 0xF0, 0xFF } },
    { (char*) sTypeNames[9], { 0xF0, 0x64, 0x64, 0xFF } },
    { (char*) sTypeNames[10], { 0x46, 0xB4, 0xF0, 0xFF } },
    { (char*) sTypeNames[11], { 0x64, 0xC8, 0x64, 0xFF } },
    { (char*) sTypeNames[12], { 0xF0, 0xF0, 0x32, 0xFF } },
    { (char*) sTypeNames[13], { 0xF0, 0x8C, 0xB4, 0xFF } },
    { (char*) sTypeNames[14], { 0xB4, 0xF0, 0xF0, 0xFF } },
    { (char*) sTypeNames[15], { 0x64, 0xDC, 0xC8, 0xFF } },
    { NULL, { 0x00, 0x00, 0x00, 0x00 } },
};

char sMoveComments[165][8] = {
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
    "comment", "comment", "comment", "comment", "comment",
};

unk_D_80072338 gMoveDisplayInfo[166] = {
    { {1}, 0, {0, 0}, (char*) sMoveNames[0], sMoveComments[0] },
    { {2}, 0, {0, 0}, (char*) sMoveNames[1], sMoveComments[1] },
    { {3}, 0, {0, 0}, (char*) sMoveNames[2], sMoveComments[2] },
    { {4}, 0, {0, 0}, (char*) sMoveNames[3], sMoveComments[3] },
    { {5}, 0, {0, 0}, (char*) sMoveNames[4], sMoveComments[4] },
    { {6}, 0, {0, 0}, (char*) sMoveNames[5], sMoveComments[5] },
    { {7}, 9, {0, 0}, (char*) sMoveNames[6], sMoveComments[6] },
    { {8}, 14, {0, 0}, (char*) sMoveNames[7], sMoveComments[7] },
    { {9}, 12, {0, 0}, (char*) sMoveNames[8], sMoveComments[8] },
    { {10}, 0, {0, 5}, (char*) sMoveNames[9], sMoveComments[9] },
    { {11}, 0, {0, 0}, (char*) sMoveNames[10], sMoveComments[10] },
    { {12}, 0, {0, 0}, (char*) sMoveNames[11], sMoveComments[11] },
    { {13}, 0, {0, 0}, (char*) sMoveNames[12], sMoveComments[12] },
    { {14}, 0, {0, 0}, (char*) sMoveNames[13], sMoveComments[13] },
    { {15}, 0, {0, 0}, (char*) sMoveNames[14], sMoveComments[14] },
    { {16}, 0, {0, 0}, (char*) sMoveNames[15], sMoveComments[15] },
    { {17}, 2, {0, 0}, (char*) sMoveNames[16], sMoveComments[16] },
    { {18}, 0, {0, 0}, (char*) sMoveNames[17], sMoveComments[17] },
    { {19}, 2, {0, 0}, (char*) sMoveNames[18], sMoveComments[18] },
    { {20}, 0, {0, 0}, (char*) sMoveNames[19], sMoveComments[19] },
    { {21}, 0, {0, 0}, (char*) sMoveNames[20], sMoveComments[20] },
    { {22}, 11, {0, 0}, (char*) sMoveNames[21], sMoveComments[21] },
    { {23}, 0, {0, 0}, (char*) sMoveNames[22], sMoveComments[22] },
    { {24}, 1, {0, 0}, (char*) sMoveNames[23], sMoveComments[23] },
    { {25}, 0, {0, 6}, (char*) sMoveNames[24], sMoveComments[24] },
    { {26}, 1, {0, 0}, (char*) sMoveNames[25], sMoveComments[25] },
    { {27}, 1, {0, 0}, (char*) sMoveNames[26], sMoveComments[26] },
    { {28}, 0, {0, 0}, (char*) sMoveNames[27], sMoveComments[27] },
    { {29}, 0, {0, 0}, (char*) sMoveNames[28], sMoveComments[28] },
    { {30}, 0, {0, 0}, (char*) sMoveNames[29], sMoveComments[29] },
    { {31}, 0, {0, 0}, (char*) sMoveNames[30], sMoveComments[30] },
    { {32}, 0, {0, 0}, (char*) sMoveNames[31], sMoveComments[31] },
    { {33}, 0, {0, 0}, (char*) sMoveNames[32], sMoveComments[32] },
    { {34}, 0, {0, 7}, (char*) sMoveNames[33], sMoveComments[33] },
    { {35}, 0, {0, 0}, (char*) sMoveNames[34], sMoveComments[34] },
    { {36}, 0, {0, 0}, (char*) sMoveNames[35], sMoveComments[35] },
    { {37}, 0, {0, 0}, (char*) sMoveNames[36], sMoveComments[36] },
    { {38}, 0, {0, 0}, (char*) sMoveNames[37], sMoveComments[37] },
    { {39}, 0, {0, 0}, (char*) sMoveNames[38], sMoveComments[38] },
    { {40}, 3, {0, 0}, (char*) sMoveNames[39], sMoveComments[39] },
    { {41}, 7, {0, 0}, (char*) sMoveNames[40], sMoveComments[40] },
    { {42}, 7, {0, 0}, (char*) sMoveNames[41], sMoveComments[41] },
    { {43}, 0, {0, 0}, (char*) sMoveNames[42], sMoveComments[42] },
    { {44}, 0, {0, 0}, (char*) sMoveNames[43], sMoveComments[43] },
    { {45}, 0, {0, 0}, (char*) sMoveNames[44], sMoveComments[44] },
    { {46}, 0, {0, 0}, (char*) sMoveNames[45], sMoveComments[45] },
    { {47}, 0, {0, 0}, (char*) sMoveNames[46], sMoveComments[46] },
    { {48}, 0, {0, 0}, (char*) sMoveNames[47], sMoveComments[47] },
    { {49}, 0, {0, 0}, (char*) sMoveNames[48], sMoveComments[48] },
    { {50}, 0, {0, 0}, (char*) sMoveNames[49], sMoveComments[49] },
    { {51}, 3, {0, 0}, (char*) sMoveNames[50], sMoveComments[50] },
    { {52}, 9, {0, 0}, (char*) sMoveNames[51], sMoveComments[51] },
    { {53}, 9, {0, 4}, (char*) sMoveNames[52], sMoveComments[52] },
    { {54}, 14, {0, 0}, (char*) sMoveNames[53], sMoveComments[53] },
    { {55}, 10, {0, 0}, (char*) sMoveNames[54], sMoveComments[54] },
    { {56}, 10, {0, 10}, (char*) sMoveNames[55], sMoveComments[55] },
    { {57}, 10, {0, 0}, (char*) sMoveNames[56], sMoveComments[56] },
    { {58}, 14, {0, 0}, (char*) sMoveNames[57], sMoveComments[57] },
    { {59}, 14, {0, 0}, (char*) sMoveNames[58], sMoveComments[58] },
    { {60}, 13, {0, 0}, (char*) sMoveNames[59], sMoveComments[59] },
    { {61}, 10, {0, 5}, (char*) sMoveNames[60], sMoveComments[60] },
    { {62}, 14, {0, 0}, (char*) sMoveNames[61], sMoveComments[61] },
    { {63}, 0, {0, 0}, (char*) sMoveNames[62], sMoveComments[62] },
    { {64}, 2, {0, 0}, (char*) sMoveNames[63], sMoveComments[63] },
    { {65}, 2, {0, 0}, (char*) sMoveNames[64], sMoveComments[64] },
    { {66}, 1, {0, 0}, (char*) sMoveNames[65], sMoveComments[65] },
    { {67}, 1, {0, 0}, (char*) sMoveNames[66], sMoveComments[66] },
    { {68}, 1, {0, 0}, (char*) sMoveNames[67], sMoveComments[67] },
    { {69}, 1, {0, 0}, (char*) sMoveNames[68], sMoveComments[68] },
    { {70}, 0, {0, 0}, (char*) sMoveNames[69], sMoveComments[69] },
    { {71}, 11, {0, 0}, (char*) sMoveNames[70], sMoveComments[70] },
    { {72}, 11, {0, 0}, (char*) sMoveNames[71], sMoveComments[71] },
    { {73}, 11, {0, 0}, (char*) sMoveNames[72], sMoveComments[72] },
    { {74}, 0, {0, 0}, (char*) sMoveNames[73], sMoveComments[73] },
    { {75}, 11, {0, 0}, (char*) sMoveNames[74], sMoveComments[74] },
    { {76}, 11, {0, 0}, (char*) sMoveNames[75], sMoveComments[75] },
    { {77}, 3, {0, 0}, (char*) sMoveNames[76], sMoveComments[76] },
    { {78}, 11, {0, 0}, (char*) sMoveNames[77], sMoveComments[77] },
    { {79}, 11, {0, 0}, (char*) sMoveNames[78], sMoveComments[78] },
    { {80}, 11, {0, 0}, (char*) sMoveNames[79], sMoveComments[79] },
    { {81}, 7, {0, 0}, (char*) sMoveNames[80], sMoveComments[80] },
    { {82}, 15, {0, 0}, (char*) sMoveNames[81], sMoveComments[81] },
    { {83}, 9, {0, 4}, (char*) sMoveNames[82], sMoveComments[82] },
    { {84}, 12, {0, 0}, (char*) sMoveNames[83], sMoveComments[83] },
    { {85}, 12, {0, 0}, (char*) sMoveNames[84], sMoveComments[84] },
    { {86}, 12, {0, 0}, (char*) sMoveNames[85], sMoveComments[85] },
    { {87}, 12, {0, 0}, (char*) sMoveNames[86], sMoveComments[86] },
    { {88}, 5, {0, 0}, (char*) sMoveNames[87], sMoveComments[87] },
    { {89}, 4, {0, 0}, (char*) sMoveNames[88], sMoveComments[88] },
    { {90}, 4, {0, 0}, (char*) sMoveNames[89], sMoveComments[89] },
    { {91}, 4, {0, 0}, (char*) sMoveNames[90], sMoveComments[90] },
    { {92}, 3, {0, 0}, (char*) sMoveNames[91], sMoveComments[91] },
    { {93}, 13, {0, 0}, (char*) sMoveNames[92], sMoveComments[92] },
    { {94}, 13, {0, 0}, (char*) sMoveNames[93], sMoveComments[93] },
    { {95}, 13, {0, 0}, (char*) sMoveNames[94], sMoveComments[94] },
    { {96}, 13, {0, 0}, (char*) sMoveNames[95], sMoveComments[95] },
    { {97}, 13, {0, 0}, (char*) sMoveNames[96], sMoveComments[96] },
    { {98}, 0, {0, 0}, (char*) sMoveNames[97], sMoveComments[97] },
    { {99}, 0, {0, 0}, (char*) sMoveNames[98], sMoveComments[98] },
    { {100}, 13, {0, 0}, (char*) sMoveNames[99], sMoveComments[99] },
    { {101}, 8, {0, 0}, (char*) sMoveNames[100], sMoveComments[100] },
    { {102}, 0, {0, 0}, (char*) sMoveNames[101], sMoveComments[101] },
    { {103}, 0, {0, 0}, (char*) sMoveNames[102], sMoveComments[102] },
    { {104}, 0, {0, 0}, (char*) sMoveNames[103], sMoveComments[103] },
    { {105}, 0, {0, 0}, (char*) sMoveNames[104], sMoveComments[104] },
    { {106}, 0, {0, 0}, (char*) sMoveNames[105], sMoveComments[105] },
    { {107}, 0, {0, 0}, (char*) sMoveNames[106], sMoveComments[106] },
    { {108}, 0, {0, 0}, (char*) sMoveNames[107], sMoveComments[107] },
    { {109}, 8, {0, 0}, (char*) sMoveNames[108], sMoveComments[108] },
    { {110}, 10, {0, 0}, (char*) sMoveNames[109], sMoveComments[109] },
    { {111}, 0, {0, 0}, (char*) sMoveNames[110], sMoveComments[110] },
    { {112}, 13, {0, 0}, (char*) sMoveNames[111], sMoveComments[111] },
    { {113}, 13, {0, 0}, (char*) sMoveNames[112], sMoveComments[112] },
    { {114}, 14, {0, 0}, (char*) sMoveNames[113], sMoveComments[113] },
    { {115}, 13, {0, 0}, (char*) sMoveNames[114], sMoveComments[114] },
    { {116}, 0, {0, 0}, (char*) sMoveNames[115], sMoveComments[115] },
    { {117}, 0, {0, 0}, (char*) sMoveNames[116], sMoveComments[116] },
    { {118}, 0, {0, 0}, (char*) sMoveNames[117], sMoveComments[117] },
    { {119}, 2, {0, 0}, (char*) sMoveNames[118], sMoveComments[118] },
    { {120}, 0, {0, 0}, (char*) sMoveNames[119], sMoveComments[119] },
    { {121}, 0, {0, 0}, (char*) sMoveNames[120], sMoveComments[120] },
    { {122}, 8, {0, 0}, (char*) sMoveNames[121], sMoveComments[121] },
    { {123}, 3, {0, 0}, (char*) sMoveNames[122], sMoveComments[122] },
    { {124}, 3, {0, 0}, (char*) sMoveNames[123], sMoveComments[123] },
    { {125}, 4, {0, 0}, (char*) sMoveNames[124], sMoveComments[124] },
    { {126}, 9, {0, 0}, (char*) sMoveNames[125], sMoveComments[125] },
    { {127}, 10, {0, 0}, (char*) sMoveNames[126], sMoveComments[126] },
    { {128}, 10, {0, 0}, (char*) sMoveNames[127], sMoveComments[127] },
    { {129}, 0, {0, 0}, (char*) sMoveNames[128], sMoveComments[128] },
    { {130}, 0, {0, 0}, (char*) sMoveNames[129], sMoveComments[129] },
    { {131}, 0, {0, 0}, (char*) sMoveNames[130], sMoveComments[130] },
    { {132}, 0, {0, 0}, (char*) sMoveNames[131], sMoveComments[131] },
    { {133}, 13, {0, 0}, (char*) sMoveNames[132], sMoveComments[132] },
    { {134}, 13, {0, 0}, (char*) sMoveNames[133], sMoveComments[133] },
    { {135}, 0, {0, 0}, (char*) sMoveNames[134], sMoveComments[134] },
    { {136}, 1, {0, 0}, (char*) sMoveNames[135], sMoveComments[135] },
    { {137}, 0, {0, 0}, (char*) sMoveNames[136], sMoveComments[136] },
    { {138}, 13, {0, 0}, (char*) sMoveNames[137], sMoveComments[137] },
    { {139}, 3, {0, 0}, (char*) sMoveNames[138], sMoveComments[138] },
    { {140}, 0, {0, 0}, (char*) sMoveNames[139], sMoveComments[139] },
    { {141}, 7, {0, 0}, (char*) sMoveNames[140], sMoveComments[140] },
    { {142}, 0, {0, 0}, (char*) sMoveNames[141], sMoveComments[141] },
    { {143}, 2, {0, 0}, (char*) sMoveNames[142], sMoveComments[142] },
    { {144}, 0, {0, 0}, (char*) sMoveNames[143], sMoveComments[143] },
    { {145}, 10, {0, 0}, (char*) sMoveNames[144], sMoveComments[144] },
    { {146}, 0, {0, 0}, (char*) sMoveNames[145], sMoveComments[145] },
    { {147}, 11, {0, 0}, (char*) sMoveNames[146], sMoveComments[146] },
    { {148}, 0, {0, 0}, (char*) sMoveNames[147], sMoveComments[147] },
    { {149}, 13, {0, 0}, (char*) sMoveNames[148], sMoveComments[148] },
    { {150}, 0, {0, 0}, (char*) sMoveNames[149], sMoveComments[149] },
    { {151}, 3, {0, 0}, (char*) sMoveNames[150], sMoveComments[150] },
    { {152}, 10, {0, 0}, (char*) sMoveNames[151], sMoveComments[151] },
    { {153}, 0, {0, 0}, (char*) sMoveNames[152], sMoveComments[152] },
    { {154}, 0, {0, 0}, (char*) sMoveNames[153], sMoveComments[153] },
    { {155}, 4, {0, 0}, (char*) sMoveNames[154], sMoveComments[154] },
    { {156}, 13, {0, 0}, (char*) sMoveNames[155], sMoveComments[155] },
    { {157}, 5, {0, 0}, (char*) sMoveNames[156], sMoveComments[156] },
    { {158}, 0, {0, 0}, (char*) sMoveNames[157], sMoveComments[157] },
    { {159}, 0, {0, 0}, (char*) sMoveNames[158], sMoveComments[158] },
    { {160}, 0, {0, 0}, (char*) sMoveNames[159], sMoveComments[159] },
    { {161}, 0, {0, 0}, (char*) sMoveNames[160], sMoveComments[160] },
    { {162}, 0, {0, 0}, (char*) sMoveNames[161], sMoveComments[161] },
    { {163}, 0, {0, 0}, (char*) sMoveNames[162], sMoveComments[162] },
    { {164}, 0, {0, 0}, (char*) sMoveNames[163], sMoveComments[163] },
    { {165}, 0, {0, 0}, (char*) sMoveNames[164], sMoveComments[164] },
    { {0}, 0, {0, 0}, NULL, NULL },
};

MoveData gMoveData[165] = {
    {1, 0, 40, 0, 0xFF, 35}, {2, 0, 50, 0, 0xFF, 25}, {3, 29, 15, 0, 216, 10}, {4, 29, 18, 0, 216, 15},
    {5, 0, 80, 0, 216, 20}, {6, 16, 40, 0, 0xFF, 20}, {7, 4, 75, 20, 0xFF, 15}, {8, 5, 75, 25, 0xFF, 15},
    {9, 6, 75, 23, 0xFF, 15}, {10, 0, 40, 0, 0xFF, 35}, {11, 0, 55, 0, 0xFF, 30}, {12, 38, 1, 0, 76, 5},
    {13, 39, 80, 0, 191, 10}, {14, 50, 0, 0, 0xFF, 30}, {15, 0, 50, 0, 242, 30}, {16, 0, 40, 0, 0xFF, 35},
    {17, 0, 35, 2, 0xFF, 35}, {18, 28, 0, 0, 216, 20}, {19, 43, 70, 2, 242, 15}, {20, 42, 15, 0, 191, 20},
    {21, 0, 80, 0, 191, 20}, {22, 0, 35, 22, 0xFF, 10}, {23, 37, 65, 0, 0xFF, 20}, {24, 44, 30, 1, 0xFF, 30},
    {25, 0, 120, 0, 191, 5}, {26, 45, 70, 1, 242, 25}, {27, 37, 60, 1, 216, 15}, {28, 22, 0, 0, 0xFF, 15},
    {29, 37, 70, 0, 0xFF, 15}, {30, 0, 65, 0, 0xFF, 25}, {31, 29, 15, 0, 216, 20}, {32, 38, 1, 0, 76, 5},
    {33, 0, 35, 0, 242, 35}, {34, 36, 85, 0, 0xFF, 15}, {35, 42, 15, 0, 216, 20}, {36, 48, 90, 0, 216, 20},
    {37, 27, 90, 0, 0xFF, 20}, {38, 48, 100, 0, 0xFF, 15}, {39, 19, 0, 0, 0xFF, 30}, {40, 2, 15, 3, 0xFF, 35},
    {41, 77, 25, 7, 0xFF, 20}, {42, 29, 14, 7, 216, 20}, {43, 19, 0, 0, 0xFF, 30}, {44, 31, 60, 0, 0xFF, 25},
    {45, 18, 0, 0, 0xFF, 40}, {46, 28, 0, 0, 0xFF, 20}, {47, 32, 0, 0, 140, 15}, {48, 49, 0, 0, 140, 20},
    {49, 41, 1, 0, 229, 20}, {50, 86, 0, 0, 140, 20}, {51, 69, 40, 3, 0xFF, 30}, {52, 4, 40, 20, 0xFF, 25},
    {53, 4, 95, 20, 0xFF, 15}, {54, 46, 0, 25, 0xFF, 30}, {55, 0, 40, 21, 0xFF, 25}, {56, 0, 120, 21, 204, 5},
    {57, 0, 95, 21, 0xFF, 15}, {58, 5, 95, 25, 0xFF, 10}, {59, 35, 120, 25, 229, 5}, {60, 76, 65, 24, 0xFF, 20},
    {61, 70, 65, 21, 0xFF, 20}, {62, 68, 65, 25, 0xFF, 20}, {63, 80, 150, 0, 229, 5}, {64, 0, 35, 2, 0xFF, 35},
    {65, 0, 80, 2, 0xFF, 20}, {66, 48, 80, 1, 204, 25}, {67, 37, 50, 1, 229, 20}, {68, 0, 1, 1, 0xFF, 20},
    {69, 41, 1, 1, 0xFF, 20}, {70, 0, 80, 0, 0xFF, 15}, {71, 3, 20, 22, 0xFF, 20}, {72, 3, 40, 22, 0xFF, 10},
    {73, 84, 0, 22, 229, 10}, {74, 13, 0, 0, 0xFF, 40}, {75, 0, 55, 22, 242, 25}, {76, 39, 120, 22, 0xFF, 10},
    {77, 66, 0, 3, 191, 35}, {78, 67, 0, 22, 191, 30}, {79, 32, 0, 22, 191, 15}, {80, 27, 70, 22, 0xFF, 20},
    {81, 20, 0, 7, 242, 40}, {82, 41, 1, 26, 0xFF, 10}, {83, 42, 15, 20, 178, 15}, {84, 6, 40, 23, 0xFF, 30},
    {85, 6, 95, 23, 0xFF, 15}, {86, 67, 0, 23, 0xFF, 20}, {87, 6, 120, 23, 178, 10}, {88, 0, 50, 5, 165, 15},
    {89, 0, 100, 4, 0xFF, 10}, {90, 38, 1, 4, 76, 5}, {91, 39, 100, 4, 0xFF, 10}, {92, 66, 0, 3, 216, 10},
    {93, 76, 50, 24, 0xFF, 25}, {94, 71, 90, 24, 0xFF, 10}, {95, 32, 0, 24, 153, 20}, {96, 10, 0, 24, 0xFF, 40},
    {97, 52, 0, 24, 0xFF, 30}, {98, 0, 40, 0, 0xFF, 30}, {99, 81, 20, 0, 0xFF, 20}, {100, 28, 0, 24, 0xFF, 20},
    {101, 41, 0, 8, 0xFF, 15}, {102, 82, 0, 0, 0xFF, 10}, {103, 59, 0, 0, 216, 40}, {104, 15, 0, 0, 0xFF, 15},
    {105, 56, 0, 0, 0xFF, 20}, {106, 11, 0, 0, 0xFF, 30}, {107, 15, 0, 0, 0xFF, 20}, {108, 22, 0, 0, 0xFF, 20},
    {109, 49, 0, 8, 0xFF, 10}, {110, 11, 0, 21, 0xFF, 40}, {111, 11, 0, 0, 0xFF, 40}, {112, 51, 0, 24, 0xFF, 30},
    {113, 64, 0, 24, 0xFF, 30}, {114, 25, 0, 25, 0xFF, 30}, {115, 65, 0, 24, 0xFF, 20}, {116, 47, 0, 0, 0xFF, 30},
    {117, 26, 0, 0, 0xFF, 10}, {118, 83, 0, 0, 0xFF, 10}, {119, 9, 0, 2, 0xFF, 20}, {120, 7, 130, 0, 0xFF, 5},
    {121, 0, 100, 0, 191, 10}, {122, 36, 20, 8, 0xFF, 30}, {123, 33, 20, 3, 178, 20}, {124, 33, 65, 3, 0xFF, 20},
    {125, 31, 65, 4, 216, 20}, {126, 34, 120, 20, 216, 5}, {127, 0, 80, 21, 0xFF, 15}, {128, 42, 35, 21, 191, 10},
    {129, 17, 60, 0, 0xFF, 20}, {130, 39, 100, 0, 0xFF, 15}, {131, 29, 20, 0, 0xFF, 15}, {132, 70, 10, 0, 0xFF, 35},
    {133, 53, 0, 24, 0xFF, 20}, {134, 22, 0, 24, 204, 15}, {135, 56, 0, 0, 0xFF, 10}, {136, 45, 85, 1, 229, 20},
    {137, 67, 0, 0, 191, 30}, {138, 8, 100, 24, 0xFF, 15}, {139, 66, 0, 3, 140, 40}, {140, 29, 15, 0, 216, 20},
    {141, 3, 20, 7, 0xFF, 15}, {142, 32, 0, 0, 191, 10}, {143, 39, 140, 2, 229, 5}, {144, 57, 0, 0, 0xFF, 10},
    {145, 70, 20, 21, 0xFF, 30}, {146, 0, 70, 0, 0xFF, 10}, {147, 32, 0, 22, 0xFF, 15}, {148, 22, 0, 0, 178, 20},
    {149, 41, 1, 24, 204, 15}, {150, 85, 0, 0, 0xFF, 40}, {151, 51, 0, 3, 0xFF, 40}, {152, 0, 90, 21, 216, 10},
    {153, 7, 170, 0, 0xFF, 5}, {154, 29, 18, 0, 204, 15}, {155, 44, 50, 4, 229, 10}, {156, 56, 0, 24, 0xFF, 10},
    {157, 0, 75, 5, 229, 10}, {158, 31, 80, 0, 229, 15}, {159, 10, 0, 0, 0xFF, 30}, {160, 24, 0, 0, 0xFF, 30},
    {161, 0, 80, 0, 0xFF, 10}, {162, 40, 1, 0, 229, 10}, {163, 0, 70, 0, 0xFF, 20}, {164, 79, 0, 0, 0xFF, 10},
    {165, 48, 50, 0, 0xFF, 10},
};

char* D_80072EE0[84] = {
    (char*) D_8007BB50, (char*) D_8007BB60, (char*) D_8007BB70, (char*) D_8007BB80,
    (char*) D_8007BB94, (char*) D_8007BBA4, (char*) D_8007BBB0, (char*) D_8007BBBC,
    (char*) D_8007BBCC, (char*) D_8007BBDC, (char*) D_8007BBE8, (char*) D_8007BBF4,
    (char*) D_8007BC04, (char*) D_8007BC14, (char*) D_8007BC24, (char*) D_8007BC30,
    (char*) D_8007BC44, (char*) D_8007BC58, (char*) D_8007BC6C, (char*) D_8007BC7C,
    (char*) D_8007BC88, (char*) D_8007BC98, (char*) D_8007BCA8, (char*) D_8007BCB8,
    (char*) D_8007BCCC, (char*) D_8007BCDC, (char*) D_8007BCEC, (char*) D_8007BD00,
    (char*) D_8007BD10, (char*) D_8007BD20, (char*) D_8007BD34, (char*) D_8007BD44,
    (char*) D_8007BD54, (char*) D_8007BD64, (char*) D_8007BD70, (char*) D_8007BD80,
    (char*) D_8007BD8C, (char*) D_8007BD9C, (char*) D_8007BDAC, (char*) D_8007BDB8,
    (char*) D_8007BDC8, (char*) D_8007BDD8, (char*) D_8007BDE8, (char*) D_8007BDF8,
    (char*) D_8007BE04, (char*) D_8007BE14, (char*) D_8007BE24, (char*) D_8007BE34,
    (char*) D_8007BE40, (char*) D_8007BE4C, (char*) D_8007BE5C, (char*) D_8007BE70,
    (char*) D_8007BE80, (char*) D_8007BE90, (char*) D_8007BEA4, (char*) D_8007BEB8,
    (char*) D_8007BECC, (char*) D_8007BEE0, (char*) D_8007BEF4, (char*) D_8007BEFC,
    (char*) D_8007BF0C, (char*) D_8007BF1C, (char*) D_8007BF2C, (char*) D_8007BF3C,
    (char*) D_8007BF4C, (char*) D_8007BF5C, (char*) D_8007BF6C, (char*) D_8007BF78,
    (char*) D_8007BF8C, (char*) D_8007BF9C, (char*) D_8007BFAC, (char*) D_8007BFC0,
    (char*) D_8007BFD0, (char*) D_8007BFE0, (char*) D_8007BFF4, (char*) D_8007C008,
    (char*) D_8007C018, (char*) D_8007C028, (char*) D_8007C038, (char*) D_8007C048,
    (char*) D_8007C058, (char*) D_8007C06C, (char*) D_8007C080, NULL,
};

s8 D_80073030[0x100] = {
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 65, 66, 67, 68,
    69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
    81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 40, 41,
    58, 59, 91, 93, 97, 98, 99, 100, 101, 102, 103, 104,
    105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116,
    117, 118, 119, 120, 121, 122, 224, 232, 233, 249, 223, 231,
    196, 214, 220, 228, 246, 252, 235, 239, 226, 244, 251, 234,
    238, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 39, 188, 189, 45,
    43, 32, 63, 33, 32, 32, 32, 32, 32, 32, 32, 169,
    165, 215, 46, 47, 44, 190, 48, 49, 50, 51, 52, 53,
    54, 55, 56, 57,
};

u8 D_80073130[0x100] = {
#if defined(VERSION_US_REV2)
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 127, 231, 0, 0,
    0, 0, 0, 224, 154, 155, 0, 228, 244, 227, 242, 243,
    246, 247, 248, 249, 250, 251, 252, 253, 254, 0xFF, 156, 157,
    0, 0, 0, 230, 0, 128, 129, 130, 131, 132, 133, 134,
    135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146,
    147, 148, 149, 150, 151, 152, 153, 158, 0, 159, 0, 0,
    0, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170,
    171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182,
    183, 184, 185, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0,
    0, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 225, 226, 245, 0,
    0, 0, 0, 0, 192, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 193, 241,
    0, 0, 0, 0, 194, 0, 0, 190, 186, 0, 200, 0,
    195, 0, 0, 191, 187, 188, 203, 198, 0, 0, 204, 199,
    0, 0, 0, 0, 201, 0, 196, 0, 0, 189, 0, 202,
    197, 0, 0, 0,
#else
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 231, 0, 0,
    0, 0, 0, 224, 154, 155, 0, 228, 244, 227, 242, 243,
    246, 247, 248, 249, 250, 251, 252, 253, 254, 0xFF, 156, 157,
    0, 0, 0, 230, 0, 128, 129, 130, 131, 132, 133, 134,
    135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146,
    147, 148, 149, 150, 151, 152, 153, 158, 0, 159, 0, 0,
    0, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170,
    171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182,
    183, 184, 185, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0,
    0, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 225, 226, 245, 0,
    0, 0, 0, 0, 192, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 193, 241,
    0, 0, 0, 0, 194, 0, 0, 190, 186, 0, 200, 0,
    195, 0, 0, 191, 187, 188, 203, 198, 0, 0, 204, 199,
    0, 0, 0, 0, 201, 0, 196, 0, 0, 189, 0, 202,
    197, 0, 0, 0,
#endif
};


u16 GbData_ReadU16BE(u8* arg0) {
    return (arg0[0] << 8) | arg0[1];
}

u32 GbData_ReadU24BE(u8* arg0) {
    return (arg0[0] << 16) | (arg0[1] << 8) | arg0[2];
}

void GbData_WriteU16BE(u8* arg0, s32 arg1) {
    arg0[0] = (arg1 >> 8) & 0xFF;
    arg0[1] = arg1 & 0xFF;
}

void GbData_WriteU24BE(u8* arg0, s32 arg1) {
    arg0[0] = (arg1 >> 16) & 0xFF;
    arg0[1] = (arg1 >> 8) & 0xFF;
    arg0[2] = (arg1) & 0xFF;
}

char* Text_UntranscodeName(char* arg0, char* arg1) {

    char* sp34 = arg0;
    char* sp18;
    char* temp_s1 = Text_GetPlayerLabel(1);

    while (*arg1 != 'P') {
        if (*arg1 == ']') {
            memcpy(arg0, temp_s1, strlen(temp_s1) + 1);
            arg0 += strlen(temp_s1);
        } else {
            *arg0++ = D_80073030[*arg1];
        }
        arg1++;
    }

    *arg0++ = '\x0';

    return sp34;
}

void Text_UntranscodeNameWrapper(char* arg0, char* arg1) {
    Text_UntranscodeName(arg0, arg1);
}

char* Text_TranscodeName(char* arg0, char* arg1) {

    char* sp1C = arg0;
    char* sp18 = arg1;

    if (HAL_Strcmp(sp18, Text_GetPlayerLabel(1)) == 0) {
        *arg0++ = ']';
    } else {
        while (*sp18 != 0) {
            *arg0++ = D_80073130[*sp18++];
        }
    }

    *arg0++ = 'P';

    return sp1C;
}

char* Text_TranscodeNameWrapper(char* arg0, char* arg1) {
    return Text_TranscodeName(arg0, arg1);
}

char* Text_UntranscodeFixedName(char* arg0, char* arg1) {
    char sp1C[11];

    _bcopy(arg1, sp1C, 10);

    sp1C[10] = 'P';

    return Text_UntranscodeName(arg0, sp1C);
}

char* Text_CopyString(char* arg0, char* arg1) {
    HAL_Strcpy(arg0, arg1);
    return arg0;
}

char* Text_CopySpeciesName(char* arg0, s32 arg1) {
    Text_CopyString(arg0, (char*)*(u32*)D_8006FEE8[arg1]);
    return arg0;
}

char* Text_GetTmHmName(s32 arg0, char* arg1) {
    // "ひでんマシン%02d"
    static const char D_0007CCA0[] = { 164, 210, 164, 199, 164, 243, 165, 222, 165, 183,
                                       165, 243, 37, 48, 50, 100, 0, 0, 0, 0 };
    // "わざマシン%02d"
    static const char D_0007CCB4[] = { 164, 239, 164, 182, 165, 222, 165, 183,
                                       165, 243, 37, 48, 50, 100, 0, 0 };

    if ((arg0 > 0) && (arg0 < 84)) {
        HAL_Strcpy(arg1, D_80072EE0[arg0 - 1]);
    } else if ((arg0 >= 196) && (arg0 < 201)) {
        sprintf(arg1, D_0007CCA0, arg0 - 195, arg0);
    } else if ((arg0 >= 201) && (arg0 < 0xFF)) {
        sprintf(arg1, D_0007CCB4, arg0 - 200, arg0);
    } else {
        HAL_Strcpy(arg1, D_80072EE0[6]);
    }

    return arg1;
}

void Pokemon_FromGbRecord(BattleMon* arg0, GbPokemonRecord* arg1) {
    arg0->unk_00.unk_00 = Species_FromInternalIndex(arg1->unk_00);
    arg0->unk_00.unk_01 = arg1->unk_00;
    arg0->unk_02 = GbData_ReadU16BE(arg1->unk_01);

    arg0->unk_04 = arg1->unk_03;
    arg0->unk_05 = arg1->unk_04;
    arg0->unk_06 = arg1->unk_05;
    arg0->unk_07 = arg1->unk_06;
    arg0->unk_08 = arg1->unk_07;

    arg0->unk_0E = GbData_ReadU16BE(arg1->unk_0C);
    arg0->unk_10 = GbData_ReadU24BE(arg1->unk_0E);
    arg0->unk_14 = GbData_ReadU16BE(arg1->unk_11);
    arg0->unk_16 = GbData_ReadU16BE(arg1->unk_13);
    arg0->unk_18 = GbData_ReadU16BE(arg1->unk_15);
    arg0->unk_1A = GbData_ReadU16BE(arg1->unk_17);
    arg0->unk_1C = GbData_ReadU16BE(arg1->unk_19);
    arg0->unk_1E = GbData_ReadU16BE(arg1->unk_1B);

    memcpy(arg0->unk_09, arg1->unk_08, 4);
    memcpy(arg0->unk_20, arg1->unk_1D, 4);
}

void Pokemon_FromGbRecordExt(BattleMon* arg0, GbPokemonRecordExt* arg1) {
    Pokemon_FromGbRecord(arg0, &arg1->unk_00);
    arg0->unk_24 = arg1->unk_21;
    arg0->unk_26 = GbData_ReadU16BE(&arg1->unk_22);
    arg0->unk_28 = GbData_ReadU16BE(&arg1->unk_24);
    arg0->unk_2A = GbData_ReadU16BE(&arg1->unk_26);
    arg0->unk_2C = GbData_ReadU16BE(&arg1->unk_28);
    arg0->unk_2E = GbData_ReadU16BE(&arg1->unk_2A);
}

void Pokemon_ToGbRecord(BattleMon* arg0, GbPokemonRecord* arg1) {
    if (Species_ToInternalIndex(arg0->unk_00.unk_00) & 0xFF) {
        arg1->unk_00 = Species_ToInternalIndex(arg0->unk_00.unk_00);
    } else {
        arg1->unk_00 = arg0->unk_00.unk_01;
    }

    GbData_WriteU16BE(arg1->unk_01, (u16)arg0->unk_02);

    arg1->unk_03 = arg0->unk_04;
    arg1->unk_04 = arg0->unk_05;
    arg1->unk_05 = arg0->unk_06;
    arg1->unk_06 = arg0->unk_07;
    arg1->unk_07 = arg0->unk_08;

    GbData_WriteU16BE(arg1->unk_0C, arg0->unk_0E);
    GbData_WriteU24BE(arg1->unk_0E, arg0->unk_10);
    GbData_WriteU16BE(arg1->unk_11, arg0->unk_14);
    GbData_WriteU16BE(arg1->unk_13, arg0->unk_16);
    GbData_WriteU16BE(arg1->unk_15, arg0->unk_18);
    GbData_WriteU16BE(arg1->unk_17, arg0->unk_1A);
    GbData_WriteU16BE(arg1->unk_19, arg0->unk_1C);
    GbData_WriteU16BE(arg1->unk_1B, arg0->unk_1E);

    memcpy(arg1->unk_08, arg0->unk_09, 4);
    memcpy(arg1->unk_1D, arg0->unk_20, 4);
}

void Pokemon_ToGbRecordExt(unk_func_88205880_00D0* arg0, GbPokemonRecordExt* arg1) {
    Pokemon_ToGbRecord(arg0->unk_000, arg1);
    arg1->unk_21 = arg0->unk_000[0].unk_24;
    GbData_WriteU16BE(&arg1->unk_22, arg0->unk_000[0].unk_26);
    GbData_WriteU16BE(&arg1->unk_24, arg0->unk_000[0].unk_28);
    GbData_WriteU16BE(&arg1->unk_26, arg0->unk_000[0].unk_2A);
    GbData_WriteU16BE(&arg1->unk_28, arg0->unk_000[0].unk_2C);
    GbData_WriteU16BE(&arg1->unk_2A, arg0->unk_000[0].unk_2E);
}

u16 StatExpSqrt(u16 square) {
    u16 i;

    for (i = 1; i < 255; i++) {
        if (SQ(i) >= square) {
            break;
        }
    }
    return i;
}

void func_800220C4(void) {
}

u16 GetPokemonDV(s32 statId, u16 dvBits) { //GetPokemonDV
    u16 dvValue;

    switch (statId) {
        case STAT_HP: // HP DV (derived from the LSBs of other DVs)
            dvValue = ((dvBits & 0x1000) >> 9)  // Special DV bit 0 → HP DV bit 0
                    | ((dvBits & 0x0100) >> 6)  // Speed DV bit 0 → HP DV bit 1
                    | ((dvBits & 0x0010) >> 3)  // Defense DV bit 0 → HP DV bit 2
                    | (dvBits & 0x0001);        // Attack DV bit 0 → HP DV bit 3
            break;

        case STAT_SPECIAL: // Special DV
            dvValue = (dvBits >> 12) & 0xF;
            break;

        case STAT_SPEED: // Speed DV
            dvValue = (dvBits >> 8) & 0xF;
            break;

        case STAT_DEFENSE: // Defense DV
            dvValue = (dvBits >> 4) & 0xF;
            break;

        case STAT_ATTACK: // Attack DV
            dvValue = dvBits & 0xF;
            break;
    }

    return dvValue;
}

u32 CalculateStatValue(s32 statId, s32 speciesId, u16 statModifier, u16 level, u16 dvBits) {
    u16 statValue;
    u16 baseStat;
    u16 dvValue;

    switch (statId) {
        case STAT_HP:
            baseStat = gBaseStats[speciesId].baseHP;
            break;
        case STAT_SPECIAL:
            baseStat = gBaseStats[speciesId].baseSpecial;
            break;
        case STAT_SPEED:
            baseStat = gBaseStats[speciesId].baseSpeed;
            break;
        case STAT_DEFENSE:
            baseStat = gBaseStats[speciesId].baseDefense;
            break;
        case STAT_ATTACK:
            baseStat = gBaseStats[speciesId].baseAttack;
            break;
    }

    // Get the Pokémon's DV for the stat (or HP DV)
    dvValue = GetPokemonDV(statId, dvBits);

    // Compute the preliminary stat value
    statValue = (((StatExpSqrt(statModifier) / 4) + ((baseStat + dvValue) * 2)) * level) / 100;

    // Add final adjustments
    if (statId == STAT_HP) {
        statValue += level + 10;
    } else {
        statValue += 5;
    }

    // Cap at 999
    if (statValue > 999) {
        statValue = 999;
    }

    return statValue;
}

void Pokemon_RecalcStats(BattleMon* arg0) {
    arg0->unk_24 = Pokemon_LevelFromExp(arg0->unk_00.unk_00, arg0->unk_10);
    arg0->unk_26 = CalculateStatValue(1, arg0->unk_00.unk_00, arg0->unk_14, arg0->unk_24, arg0->unk_1E);
    arg0->unk_28 = CalculateStatValue(2, arg0->unk_00.unk_00, arg0->unk_16, arg0->unk_24, arg0->unk_1E);
    arg0->unk_2A = CalculateStatValue(3, arg0->unk_00.unk_00, arg0->unk_18, arg0->unk_24, arg0->unk_1E);
    arg0->unk_2C = CalculateStatValue(4, arg0->unk_00.unk_00, arg0->unk_1A, arg0->unk_24, arg0->unk_1E);
    arg0->unk_2E = CalculateStatValue(5, arg0->unk_00.unk_00, arg0->unk_1C, arg0->unk_24, arg0->unk_1E);
}

u16 Pokemon_StatExpForTarget(s32 arg0, s32 arg1, u16 arg2, u16 arg3, u16 arg4) {
    s32 i;
    s32 tmp;

    for (i = 1; i < 0xFFFF; i += 2) {
        tmp = CalculateStatValue(arg0, arg1, i + 2, arg3, arg4);
        if (arg2 < tmp) {
            break;
        }
    }

    return i;
}

u32 Pokemon_ExpForLevel(s32 arg0, u16 arg1) {
    u32 sp4;

    switch (gBaseStats[arg0].unk_13) {
        case 0:
            sp4 = arg1 * arg1 * arg1;
            break;

        case 1:
            sp4 = (((arg1 * arg1 * arg1 * 3) / 4) + (arg1 * 10 * arg1)) - 30;
            break;

        case 2:
            sp4 = (((arg1 * arg1 * arg1 * 3) / 4) + (arg1 * 20 * arg1)) - 30;
            break;

        case 3:
            sp4 = ((((arg1 * arg1 * arg1 * 6) / 5) - (arg1 * 15 * arg1)) + (arg1 * 100)) - 140;
            break;

        case 4:
            sp4 = (arg1 * arg1 * arg1 * 4) / 5;
            break;

        case 5:
            sp4 = (arg1 * arg1 * arg1 * 5) / 4;
            break;
    }

    return sp4;
}
