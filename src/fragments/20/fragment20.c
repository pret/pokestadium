#include "fragment20.h"
#include "src/12D80.h"
#include "src/17300.h"
#include "src/18140.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/490A0.h"
#include "src/49790.h"
#include "src/4BA90.h"
#include "src/4BDC0.h"
#include "src/4CBC0.h"
#include "src/50860.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/fragments/2/fragment2.h"
#include "src/fragments/34/fragment34.h"
#include "src/geo_layout.h"
#include "src/memory.h"
#include "src/stage_loader.h"

extern u8 D_0303ED80[];
extern u8 D_0303F580[];
extern u8 D_0303F180[];
extern u8 D_03040580[];
extern u8 D_03040D80[];
extern u8 D_03040980[];

typedef struct unk_D_86E04BFC {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ Vec3s unk_0C;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
} unk_D_86E04BFC; // size = 0x18

static minigameActor metadodPlayers[4];
static minigameActor metapodMinigameFallingRocks[20];
static s16 D_86E08E40;
static unk_D_800AC870* D_86E08E44;

static u32 D_86E02FB0[] = {
    0xE8E0CBB4, 0xAAAAAFB6, 0xB6AEABBC, 0xD6BBA5A5, 0xA6BCC4C9, 0xC3B5BBBB, 0xB8B5B9C0, 0xBDB9C3D7, 0xDED2CBBD,
    0xB9BBC8E6, 0xDEB2A7BB, 0xD6BAA5A5, 0xA5ADAEA9, 0xABB1BBCD, 0xD1CCCEDA, 0xDCD4D4D8, 0xDECEC9C0, 0xCCDEE3EF,
    0xE5B5A9AD, 0xB3AAA5A5, 0xA6A9ACAE, 0xB1B8C1E0, 0xF3E9DADC, 0xE8ECF0E9, 0xE5C2B4B4, 0xBAC6C5C1, 0xBBAFAFC9,
    0xC7A7A5A5, 0xA8B0B9C3, 0xCACCCADC, 0xECE0DFE9, 0xF0F4F1ED, 0xDAB8AFB5, 0xB1AEB2B1, 0xAEAEB2CD, 0xC7A7A5A6,
    0xABB3BCCF, 0xDFD7CAC4, 0xC2C0DEF3, 0xF8FBF7E4, 0xCBC4BDC2, 0xB6B0B5B4, 0xB1B2B1AD, 0xA9A7A7A7, 0xACB0B2BA,
    0xC4C2BDB4, 0xAEB2CAE8, 0xEAEFE8CE, 0xD3D7BEAF, 0xABB3BFC4, 0xC2C6BBAC, 0xAAADADAA, 0xAAABAAAA, 0xB1BCBEB2,
    0xAAAAB7CC, 0xCDCAC9C3, 0xDADBB8A7, 0xA9B7D3EB, 0xE0CBBBB1, 0xAEB4B4AD, 0xA9A9AAB0, 0xBFD0D0C2, 0xB8B2B0B7,
    0xBDC2BFC0, 0xCDC9B0A6, 0xA8B8DFFB, 0xF0C7B8B2, 0xAEB2B2AB, 0xA7A7B0C5, 0xDBEEE7CE, 0xC0B7B6AC, 0xACB5BABD,
    0xBBADA7A6, 0xA9B6D5F5, 0xECD3CBBB, 0xAEABABA8, 0xA5A7B5D2, 0xE6EEE2C7, 0xB3B5B7A7, 0xA5A9B6C6, 0xBCA7A7AB,
    0xAFB9D0E2, 0xDDE1E9CB, 0xB0B0B9B0, 0xA7A6B2C9, 0xD7D5C7B5, 0xABACAEA7, 0xA6ABB9CB, 0xB6A7A9BE, 0xD3D2DED6,
    0xCED6D8C1, 0xADB7CABC, 0xAEAAB0C3, 0xD0C6B8AC, 0xA6A5B0B6, 0xAFB7D2D3, 0xBBAEAACD, 0xF4EBDAC7, 0xC0C2BEB6,
    0xAEBECAC3, 0xBBB1B6D2, 0xDFCEC0B1, 0xA8A5AEB9, 0xB3B6CCC7, 0xB6B1A9B7, 0xD5DAC5B7, 0xB6BFCAD0, 0xD1E1D3BE,
    0xC3BCC7E1, 0xE0D3CDC3, 0xBAB3B2B0, 0xABAAACAE, 0xA5A5A6A9, 0xAFB2AFAD, 0xB6CEE7F2, 0xF6F0C8B6, 0xC3C7D7E1,
    0xCED1DDE1, 0xDED4CABC, 0xACA6A5A5, 0xA5A5A5A5, 0xA6A6A7AD, 0xBEDBF3F9, 0xF6D8B0AF, 0xC1D0D8CB, 0xBBD0EAF4,
    0xF6EEDCC2, 0xAEA5A5A5, 0xA5A5A5A5, 0xA5A5A6B2, 0xC7DFEFF1, 0xE1BEA9AA, 0xB8C9CABA, 0xB4CCE9F6, 0xF9F5DDBC,
    0xA9A5A5A5, 0xA6A5A5A5, 0xA6AAA9B1, 0xC6D9DFD7, 0xC2AFA7A6, 0xABB2B3AE, 0xB7CEE7F7, 0xF9F3D6B2, 0xA6A6A7A7,
    0xB3AAA5A5, 0xBAD8C0AB, 0xB5C3C6BB, 0xB1ACA8A5, 0xA5A6A7AD, 0xC6E4F2F9, 0xFAF1D0AF, 0xA7B0B9BB, 0xD2B9A9A8,
    0xCAE4C2A7, 0xA9ADAFAC, 0xABACAAA7, 0xA7A7A7AD, 0xCAECF7FA, 0xFAF1D1B0, 0xAEC3D9E0, 0xEEC9B0AB, 0xBCBEADA6,
    0xA5A6A6A6, 0xA9AEB3B5, 0xB6B7B4AE, 0xBBDAECF1, 0xF3EBD0B2, 0xB2CEEEFA, 0xF2CBB6B2, 0xB2ADA9A8, 0xA9A9ABAC,
    0xAEBBCED6, 0xD3D2CBB7, 0xAFB9C7D2, 0xDBDDCCB2, 0xAEC4E7FB, 0xDBC4BEC4, 0xC1B3ACB0, 0xB9C6C9C2, 0xBED3E8E6,
    0xE1E8EACD, 0xB2AAACB7, 0xC9CFC1AE, 0xA8B0C2DC, 0xDFD3CEE1, 0xE5C7B1B7, 0xD1F4F4DC, 0xD2F0F4DE, 0xDDF5FBE5,
    0xBAABA8B2, 0xC5CAB5A9, 0xA5A6AAC1, 0xE2E1D8DC, 0xF0E1C0B7, 0xCAE9EAD3, 0xD2EEE9D0, 0xCCE1EFD6, 0xB8AAA7AB,
    0xB7C3BDAC, 0xA6A5A6BC, 0xB8C2BDB7, 0xCEF0E9C3, 0xB4B8BBBB, 0xC8E5E0C3, 0xB6BBC0B9, 0xB3AAA5A6, 0xA9BCD2BC,
    0xACAFB3B1, 0xA9A9A9A7, 0xB4EEFBDE, 0xB3ABACB4, 0xC4EAE2B8, 0xAAAAABAB, 0xB2B0A7A9, 0xABC4E0C7, 0xB0B2C0B7,
    0xB1ABA6A5, 0xACDDF4D2, 0xB2AAABB2, 0xBBC7C0AC, 0xA6A5A5A6, 0xB2BCB1B6, 0xC1CED9C2, 0xB2AEBCC0, 0xC9BBAEB5,
    0xB5B3BAB1, 0xACA7A8AD, 0xB2B0AAA6, 0xA5A5A5A7, 0xB0BDB4C0, 0xD9CEBAB3, 0xB4B6C5CF, 0xEAD6C5CE, 0xCCB3A7BA,
    0xC9B2A6A8, 0xAAA9A6A5, 0xA5A5A8B6, 0xB9AFAAB4, 0xCAC0A8A7, 0xB0C0DCEF, 0xF6F3E4D0, 0xC0B3ADC6, 0xE2C6B2AA,
    0xA7A6A5A5, 0xA5A5AFD0, 0xD0AFA6A9, 0xB6BAACA6, 0xB2C6E5F8, 0xF1F2E1BF, 0xABABAFB6, 0xC5BEB6B0, 0xB1AAA5A5,
    0xA5B0C1E4, 0xDBB7AFAC, 0xB1B2AEAD, 0xB2BED0E6,
};

static u32 D_86E033B0[] = {
    0x34BD34BD, 0x34BD34BD, 0x34FD34BD, 0x3CBD34FD, 0x3CFD3CFD, 0x3CFD34FD, 0x3CFD3CFD, 0x3CFD3CFD, 0x3CFD3CFD,
    0x3CFD3CFD, 0x3CFD3CFD, 0x3CFD3CFD, 0x3CFD3CFD, 0x3CFD3CFD, 0x3CFB3CFB, 0x3CFD3CFD, 0x3CFB3CFB, 0x3CFB3CFB,
    0x3D3B3CFB, 0x3D3B3D3B, 0x3D3B3D3B, 0x3D3B3D3B, 0x3D3B3D3B, 0x3D3B3D3B, 0x453B453B, 0x453B453B, 0x453B453B,
    0x453B453B, 0x453B453B, 0x453B453B, 0x453B453B, 0x453B453B, 0x457B457B, 0x457B457B, 0x457B457B, 0x457B457B,
    0x457B457B, 0x457B457B, 0x457B457B, 0x457B457B, 0x457B457B, 0x457B457B, 0x457B457B, 0x457B457B, 0x457B457B,
    0x457B457B, 0x45BB45BB, 0x4D7B457B, 0x4DBB4DBB, 0x4DBB4DBB, 0x4DBB4DBB, 0x4DBB4DBB, 0x4DBB4DBB, 0x4DBB4DBB,
    0x4DBB4DBB, 0x4DBB4DBB, 0x4DBB4DBB, 0x4DBB4DBB, 0x4DBB4DBB, 0x4DBB4DBB, 0x4DBB4DBB, 0x4DBB4DBB, 0x4DFB4DFB,
    0x4DFB4DFB, 0x4DFB4DFB, 0x4DFB4DFB, 0x4DFB55FB, 0x55FB4DFB, 0x55FB55FB, 0x55FB55FB, 0x55FB55FB, 0x55FB55FB,
    0x55FB55FB, 0x55FB55FB, 0x5DFB5E3B, 0x5DFB5E3B, 0x5E3B5E3B, 0x5E3B5E3B, 0x663B663B, 0x663B663B, 0x663B663B,
    0x663B663B, 0x6E3B6E3B, 0x6E3B6E3B, 0x6E3B6E3B, 0x6E3B6E3B, 0x767B767B, 0x763B767B, 0x767B767B, 0x767B767B,
    0x7E7B7E7B, 0x7E7B7E7B, 0x7E7B7E7B, 0x7E7B7E7B, 0x867B867B, 0x867B867B, 0x867B867B, 0x867B867B, 0x8EBB8EBB,
    0x8EBB8EBB, 0x8EBB8EBB, 0x8EBB8EBB, 0x96BB96BB, 0x96BB96BB, 0x96BB96BB, 0x96BB96BB, 0x9EBB9EBB, 0x9EBB9EBB,
    0xA6FBA6FB, 0xA6FBA6FB, 0xA6FDA6FD, 0xA6FDA6FB, 0xAEFDAEFD, 0xAEFDAEFD, 0xAEFDAEFD, 0xAEFDAEFD, 0xB6FDB6FD,
    0xB6FDB6FD, 0xB73DB73D, 0xB73DB73D, 0xBF3DBF3D, 0xBF3DBF3D, 0xBF3DBF3D, 0xBF3DBF3D, 0xC73DC73D, 0xC73DC73D,
    0xC73DC73D, 0xC73DC73D,
};

static u32 D_86E035B0[] = {
    0xA45BA45B, 0x9C179BD7, 0x93D593D5, 0x9C179C17, 0x9C199C19, 0x9C199C19, 0xA45BAC9D, 0xA45B9C19, 0x9C199C19,
    0x9C1993D7, 0x8B538351, 0x8B518B93, 0x93959C17, 0xA49BB4DF, 0xB4DFAC9F, 0xB4DFB521, 0xAC9DA45B, 0xA4599C17,
    0x9BD793D5, 0x93D593D5, 0x93D79BD7, 0x93D593D5, 0x9BD7A45B, 0xA45B9BD7, 0x93D79C19, 0xA45B9C19, 0x93958B51,
    0x8B519393, 0x93D59C17, 0x9C19A45B, 0xA49DAC9F, 0xACDFB521, 0xACDFA45B, 0xA459A459, 0x9C1993D7, 0x93959393,
    0x93D59BD7, 0x93D58B93, 0x8B939C17, 0x9BD79395, 0x8B539BD7, 0xA459A459, 0x9BD78B93, 0x8B5193D5, 0x9BD593D5,
    0x93959BD7, 0x9C19A45B, 0xAC9DB4E1, 0xACDFAC9D, 0xA45BA45B, 0x9C1993D7, 0x93959393, 0x93D59C17, 0x9BD78B93,
    0x83518B93, 0x8B938351, 0x7B0F8B51, 0x93959BD7, 0x9BD793D5, 0x8B939393, 0x93938B93, 0x939393D5, 0x9BD79C17,
    0xA45BAC9D, 0xAC9DA45B, 0xA45BA419, 0x9C1793D5, 0x93939393, 0x93D59C17, 0x9C1993D7, 0x8B538351, 0x8B938351,
    0x7B0F7B0F, 0x835193D5, 0x93D793D5, 0x93938B93, 0x8B518B51, 0x8B9393D5, 0x93D59393, 0x93959BD7, 0xA45B9C19,
    0xA459A459, 0x9C1793D7, 0x93D59393, 0x8B939395, 0x93D793D7, 0x8B959395, 0x9BD793D7, 0x8B938B53, 0x93D59C17,
    0x9C1793D5, 0x93938B91, 0x8B518B51, 0x8B539393, 0x93939393, 0x8B938B53, 0x93D793D7, 0x9C179C19, 0x9C1793D5,
    0x93D59395, 0x8B518311, 0x83518B53, 0x8B939BD7, 0xA45BA45B, 0x93D79395, 0x9C19A45B, 0xA4599C17, 0x9C179393,
    0x8B518B51, 0x8B538B53, 0x939393D5, 0x8B938B53, 0x8B959395, 0x93D793D7, 0x93938B51, 0x8B938B93, 0x83517ACD,
    0x7ACD7ACD, 0x8B5193D5, 0xA4599C19, 0x8B958B95, 0x93D7A45B, 0xAC9DAC9D, 0xA49B9C17, 0x93958B93, 0x8B938B53,
    0x8B939393, 0x8B938B93, 0x939593D7, 0x9C199395, 0x83517ACF, 0x830F8311, 0x7B0F72CD, 0x7B0F8B51, 0x939393D5,
    0x9BD593D5, 0x83537B11, 0x93D7A45B, 0xAC9DB4DF, 0xACDFA45B, 0x9C1993D5, 0x93938B93, 0x8B518B51, 0x8B538B93,
    0x9C19A419, 0x9C199395, 0x83117ACF, 0x7ACD7ACF, 0x7ACF7ACF, 0x8B539C17, 0x9C1993D5, 0x93938B51, 0x830F7B11,
    0x9395A45B, 0xB4DFB4E1, 0xB4DFAC9D, 0xA45B9BD7, 0x93938B93, 0x8B518B51, 0x8B9393D5, 0xA459A459, 0x9C1793D5,
    0x8B938351, 0x8311830F, 0x830F8311, 0x93959C19, 0x9C1993D5, 0x8B938B51, 0x830F830F, 0x8B93A459, 0xB4DFB4DF,
    0xAC9DAC9B, 0xA45B9C17, 0x93D59393, 0x8B938B91, 0x939393D3, 0xA457A417, 0x9C179BD7, 0x9BD793D5, 0x93938B53,
    0x83518351, 0x8B9393D5, 0x93D59393, 0x8B518B51, 0x830F830F, 0x8B519BD7, 0xAC9BAC9B, 0xA459A459, 0xAC9BA45B,
    0x9C1793D5, 0x8B938B51, 0x8B519393, 0x9BD59C17, 0x9C179C17, 0x9C179C17, 0x9BD79395, 0x8B938B51, 0x8B518B51,
    0x8B939393, 0x93938B51, 0x8B51830F, 0x835193D5, 0xA459A417, 0x9C17A459, 0xAC9BA49B, 0xA41993D5, 0x93938B51,
    0x8B519393, 0x93959BD7, 0x9C179C17, 0x9BD59C17, 0x9C179BD7, 0x93958B93, 0x8B518B51, 0x8B518B93, 0x8B938B51,
    0x830F7B0F, 0x835193D5, 0x9C179C19, 0x9C19A459, 0xA459A459, 0x9C1793D5, 0x93938B91, 0x8B518B91, 0x93D59BD7,
    0x9C179C17, 0x9BD79BD5, 0x9BD59BD5, 0x93D58B93, 0x8B518B51, 0x8B518B51, 0x8B518B51, 0x830F7B0F, 0x83519393,
    0x93D59C17, 0x9C199C17, 0x9C179C17, 0x9C199BD7, 0x93939393, 0x8B938B53, 0x939593D5, 0x9BD59C17, 0x9BD79395,
    0x93939393, 0x93938B93, 0x8B518B51, 0x83518351, 0x83518B51, 0x83118311, 0x8B518B51, 0x8B919395, 0x9BD593D5,
    0x93D59BD7, 0x9C199C17, 0x93D593D3, 0x93938B93, 0x83118311, 0x8B939C17, 0x9C199395, 0x8B518B51, 0x8B938B51,
    0x83117B0F, 0x7ACF830F, 0x8B518B93, 0x8B938B51, 0x8351830F, 0x834F8B93, 0x93938B93, 0x939393D5, 0x93D59395,
    0x93D593D3, 0x93D593D5, 0x728D728D, 0x7B119395, 0x9C179BD7, 0x93938B51, 0x8B518351, 0x7ACF728D, 0x7ACF8351,
    0x8B938B93, 0x8B938B51, 0x7ACF7ACD, 0x830F8B51, 0x8B518B51, 0x8B938B53, 0x8B538B93, 0x93939393, 0x939393D5,
    0x728D6A4D, 0x728D8311, 0x93D59C19, 0x9C1993D5, 0x93938B53, 0x7B117ACF, 0x83119393, 0x93938B51, 0x8B51830F,
    0x7ACF7ACD, 0x830F8351, 0x83518311, 0x83518B51, 0x8B9393D3, 0x93D39393, 0x8B518B53, 0x7ACF7ACD, 0x7ACD7ACD,
    0x835193D7, 0xA4599C17, 0x93D59393, 0x8B538311, 0x8B519393, 0x93918B4F, 0x830F830F, 0x7ACF7ACF, 0x830F830F,
    0x834F834F, 0x834F8B51, 0x93D39C13, 0x9BD39391, 0x8351830F, 0x830F830F, 0x830F7ACD, 0x7ACF8B53, 0x9BD79BD5,
    0x93D59393, 0x8B938351, 0x8B518B51, 0x8B51830F, 0x7ACD7ACD, 0x7ACD7ACD, 0x7ACD830F, 0x830F834F, 0x834F834F,
    0x8B519391, 0x93918B4F, 0x830F830F, 0x7B0F7ACF, 0x7ACD72CD, 0x72CD830F, 0x8B518B51, 0x8B518B51, 0x8B518311,
    0x830F830F, 0x830F7B0F, 0x7ACD7ACD, 0x728D6A8D, 0x6A4D728D, 0x7B0F830F, 0x830F7ACF, 0x7ACD7ACD, 0x830D834F,
    0x834F8B51, 0x728D6A8D, 0x6A4D728D, 0x728D7ACD, 0x7ACF7B0F, 0x7B0F830F, 0x830F7ACF, 0x72CD72CD, 0x72CD728D,
    0x728D728D, 0x728D6A4D, 0x620B624D, 0x72CD830F, 0x7ACF728D, 0x6A4B728D, 0x7ACD830F, 0x8B518B93, 0x72CF728D,
    0x6A4D6A4B, 0x6A4D72CD, 0x830F830F, 0x7ACF7ACD, 0x728D6A4D, 0x6A4D6A4B, 0x6A4B6A4B, 0x6A4B728B, 0x728D728D,
    0x624D624B, 0x728D7ACF, 0x72CD6A8D, 0x6A4D728D, 0x7ACD7ACF, 0x83518B93, 0x83538311, 0x7ACF6A4D, 0x620B6A4D,
    0x7ACF830F, 0x7ACF728D, 0x6A4B624D, 0x620D5A0B, 0x5A0B620B, 0x6A4B6A4B, 0x728D728F, 0x6A8D6A4D, 0x728D728D,
    0x728D6A4D, 0x6A8D728D, 0x728D728F, 0x72CF7B11, 0x9C199395, 0x835372CF, 0x624D624D, 0x6A8D7ACF, 0x72CF6A4D,
    0x624D6A4D, 0x624D5A0D, 0x59CB5A0B, 0x620B624B, 0x6A4D6A4D, 0x624D624D, 0x6A4D6A8D, 0x6A4D624D, 0x6A4D6A4D,
    0x6A4D624D, 0x624D6A8F, 0xA45B9BD7, 0x93958B55, 0x7B13728F, 0x6A8D6A8D, 0x6A8F6A8F, 0x6A8F728F, 0x6A8F624D,
    0x5A0B5A0B, 0x624B6A4B, 0x620B5A0B, 0x5A0B5A0B, 0x624D6A8D, 0x6A4D624D, 0x5A0B5A0B, 0x5A0B5A0B, 0x5A0D624D,
    0x9C1B93D9, 0x939793D7, 0x93978353, 0x72D1728F, 0x72CF7AD1, 0x7AD17AD1, 0x7AD1728F, 0x624D624D, 0x6A8D6A4D,
    0x624B5A0B, 0x520B51CB, 0x5A0D624D, 0x624D620D, 0x5A0B51CB, 0x59CB5A0B, 0x624D624F, 0x9BD993D7, 0x93959397,
    0x93979395, 0x83538313, 0x83138B53, 0x8B558B95, 0x8B958353, 0x72D1728F, 0x72CF728D, 0x6A4D624D, 0x620B5A0B,
    0x520B5A0B, 0x5A0B5A0B, 0x5A0B51CB, 0x59CB624D, 0x6A8F72CF, 0x93979395, 0x8B958B95, 0x8B958B95, 0x8B959395,
    0x93D79C19, 0x9C199C19, 0x9C199397, 0x831372CF, 0x72CF728F, 0x6A8D6A4D, 0x6A4D620B, 0x5A0B5A0B, 0x5A0D620D,
    0x5A0B5A0B, 0x624D728F, 0x7B118353, 0x8B978B97, 0x93978B95, 0x8B958B95, 0x93D79BD9, 0xA45BA45B, 0xA45BA45B,
    0x9BD98B95, 0x83137AD1, 0x72CF728F, 0x7AD17ACF, 0x728F6A4D, 0x620D624D, 0x624D6A8F, 0x6A4D6A8D, 0x72CF8313,
    0x8B959397, 0x93D793D7, 0x93D793D9, 0x93D793D7, 0x9BD99C1B, 0xA45DAC9D, 0xA45D9C19, 0x8B978353, 0x83137B11,
    0x72D172D1, 0x83538B53, 0x7B116A8F, 0x624F624F, 0x6A8F72D1, 0x7AD17B11, 0x83538B95, 0x93D793D9,
};

static unk_D_86002F34_018 D_86E03DB0[3] = {
    {
        0x04,
        unk_D_86002F34_018_GFX_TYPE_1,
        32,
        32,
        1024,
        D_86E02FB0,
    },
    {
        0x00,
        unk_D_86002F34_018_GFX_TYPE_2,
        4,
        64,
        256,
        D_86E033B0,
    },
    {
        0x00,
        unk_D_86002F34_018_GFX_TYPE_2,
        32,
        32,
        1024,
        D_86E035B0,
    },
};
static Gfx D_86E03DD8[] = {
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C),
    gsSPEndDisplayList(),
};
static Gfx D_86E03E10[] = {
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_CLAMP, 2, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 255, 2048),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_CLAMP, 2, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x000C, 0x00FC),
    gsSPEndDisplayList(),
};
static Gfx D_86E03E48[] = {
    gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 511, 512),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x017C, 0x037C),
    gsSPEndDisplayList(),
};
static Vtx D_86E03E88[] = {
    VTX(-2544, 844, -2221, 392, 3180, 0x4D, 0x73, 0x20, 0xFF),
    VTX(-1824, 587, -2393, 641, 3314, 0x4D, 0x73, 0x20, 0xFF),
    VTX(-1848, 250, -2970, 633, 3759, 0x5E, 0x2F, 0x04, 0xFF),
    VTX(3500, 250, 1500, 2749, 404, 0x84, 0x5E, 0x3E, 0xFF),
    VTX(3500, 250, -937, 2941, 2288, 0x84, 0x5E, 0x3E, 0xFF),
    VTX(1990, 250, -937, 2419, 2288, 0xBD, 0x97, 0x5E, 0xFF),
    VTX(1824, 362, -4141, 2383, 4864, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(1824, 362, -3604, 2458, 4448, 0x5E, 0x2F, 0x04, 0xFF),
    VTX(2784, 587, -3392, 2790, 4285, 0x5E, 0x2F, 0x04, 0xFF),
    VTX(2760, 587, -4295, 2707, 4983, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(0, 250, -3727, 1827, 4543, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(-1894, 909, -3842, 1172, 4633, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(864, 250, -2125, 1571, 3106, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(1894, 684, -1980, 1927, 2995, 0x4F, 0x73, 0x3E, 0xFF),
    VTX(1752, 1031, -2893, 1878, 3700, 0x4F, 0x73, 0x3E, 0xFF),
    VTX(-2769, 1295, -4034, 581, 4681, 0x97, 0x59, 0x26, 0xFF),
    VTX(-4052, 1005, -4585, 9, 5356, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(-3500, 250, -2780, 62, 3612, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(-3278, 941, -2048, 69, 3047, 0x4D, 0x73, 0x20, 0xFF),
    VTX(3624, 1310, -2586, 2526, 3462, 0x4F, 0x73, 0x3E, 0xFF),
    VTX(3792, 1101, -3143, 2850, 3993, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(-2625, 1358, -5254, 503, 5874, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(-1822, 1182, -4421, 1069, 5329, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(-1803, 250, -5615, 787, 6152, 0xBF, 0xA2, 0x7D, 0xFF),
    VTX(-3298, 587, -1750, 62, 2817, 0x4D, 0x73, 0x20, 0xFF),
    VTX(-2206, 587, -1462, 389, 2594, 0x2D, 0x46, 0x09, 0xFF),
    VTX(-1345, 587, -1750, 667, 2817, 0x4D, 0x73, 0x20, 0xFF),
    VTX(-739, 250, -2086, 957, 3076, 0x84, 0x5E, 0x3E, 0xFF),
    VTX(-644, 250, -2563, 970, 3445, 0x5E, 0x2F, 0x04, 0xFF),
    VTX(3153, 941, -5254, 2736, 5774, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(3792, 1101, -4141, 3064, 4864, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(4028, 1471, -5000, 3049, 5453, 0xCC, 0xAA, 0x6F, 0xFF),
};
static Vtx D_86E04088[] = {
    VTX(-749, 250, -5106, 1152, 5759, 0xBF, 0xA2, 0x7D, 0xFF),
    VTX(566, 791, -6840, 1841, 7000, 0x9D, 0xDF, 0xCC, 0xFF),
    VTX(-243, 675, -6701, 1561, 6892, 0x9D, 0xDF, 0xCC, 0xFF),
    VTX(-1803, 250, -5615, 787, 6152, 0xBF, 0xA2, 0x7D, 0xFF),
    VTX(3624, 1310, -2586, 2526, 3462, 0x4F, 0x73, 0x3E, 0xFF),
    VTX(1752, 1031, -2893, 1878, 3700, 0x4F, 0x73, 0x3E, 0xFF),
    VTX(1894, 684, -1980, 1927, 2995, 0x4F, 0x73, 0x3E, 0xFF),
    VTX(875, 250, -3438, 2129, 4321, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(1032, 250, -3085, 1896, 3948, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(1824, 362, -3604, 2458, 4448, 0x5E, 0x2F, 0x04, 0xFF),
    VTX(1824, 362, -4141, 2383, 4864, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(1145, 250, -4986, 1935, 5417, 0xBF, 0xA2, 0x7D, 0xFF),
    VTX(1055, 579, -4219, 2192, 4924, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(1919, 676, -4571, 2203, 5096, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(2760, 587, -4295, 2707, 4983, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(2784, 587, -3392, 2790, 4285, 0x5E, 0x2F, 0x04, 0xFF),
    VTX(3792, 1101, -3143, 2850, 3993, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(3792, 1101, -4141, 3064, 4864, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(3500, 1101, -1961, 2483, 2980, 0x4F, 0x73, 0x3E, 0xFF),
    VTX(2784, 587, -3392, 2361, 3948, 0x5E, 0x2F, 0x04, 0xFF),
    VTX(1824, 362, -3604, 2790, 4285, 0x5E, 0x2F, 0x04, 0xFF),
    VTX(1752, 1031, -2893, 2458, 4448, 0x4F, 0x73, 0x3E, 0xFF),
    VTX(-2544, 844, -2221, 392, 3180, 0x4D, 0x73, 0x20, 0xFF),
    VTX(-2206, 587, -1462, 389, 2594, 0x2D, 0x46, 0x09, 0xFF),
    VTX(-1345, 587, -1750, 667, 2817, 0x4D, 0x73, 0x20, 0xFF),
    VTX(-1824, 587, -2393, 641, 3314, 0x4D, 0x73, 0x20, 0xFF),
    VTX(-3298, 587, -1750, 62, 2817, 0x4D, 0x73, 0x20, 0xFF),
    VTX(-3298, 652, -938, 520, 2288, 0x4D, 0x73, 0x20, 0xFF),
    VTX(-2452, 806, -984, 823, 2288, 0x4D, 0x73, 0x20, 0xFF),
    VTX(-3500, 250, -125, 520, 1660, 0x84, 0x5E, 0x3E, 0xFF),
    VTX(1990, 250, -937, 2419, 2288, 0xBD, 0x97, 0x5E, 0xFF),
    VTX(3500, 250, -937, 2941, 2288, 0x84, 0x5E, 0x3E, 0xFF),
};
static Vtx D_86E04288[] = {
    VTX(-2206, 587, -1462, 389, 2594, 0x2D, 0x46, 0x09, 0xFF),
    VTX(-2452, 806, -984, 823, 2288, 0x4D, 0x73, 0x20, 0xFF),
    VTX(-1230, 250, -938, 1126, 2288, 0xBD, 0x97, 0x5E, 0xFF),
    VTX(-739, 250, -2086, 957, 3076, 0x84, 0x5E, 0x3E, 0xFF),
    VTX(-1345, 587, -1750, 667, 2817, 0x4D, 0x73, 0x20, 0xFF),
    VTX(-2480, 250, -125, 823, 1660, 0xBD, 0x97, 0x5E, 0xFF),
    VTX(1990, 250, -937, 2419, 2288, 0xBD, 0x97, 0x5E, 0xFF),
    VTX(1894, 684, -1980, 1927, 2995, 0x4F, 0x73, 0x3E, 0xFF),
    VTX(864, 250, -2125, 1571, 3106, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(566, 791, -6840, 1841, 7000, 0x9D, 0xDF, 0xCC, 0xFF),
    VTX(-749, 250, -5106, 1152, 5759, 0xBF, 0xA2, 0x7D, 0xFF),
    VTX(1145, 250, -4986, 1935, 5417, 0xBF, 0xA2, 0x7D, 0xFF),
    VTX(2415, 595, -5476, 2481, 5945, 0xBF, 0xA2, 0x7D, 0xFF),
    VTX(1577, 675, -6655, 2191, 6857, 0x9D, 0xDF, 0xCC, 0xFF),
    VTX(-1894, 909, -3842, 1172, 4633, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(-1822, 1182, -4421, 1069, 5329, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(-2625, 1358, -5254, 503, 5874, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(0, 250, -3727, 1827, 4543, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(-791, 836, -4459, 1425, 5359, 0x97, 0x59, 0x26, 0xFF),
    VTX(-2769, 1295, -4034, 581, 4681, 0x97, 0x59, 0x26, 0xFF),
    VTX(240, 547, -4363, 1910, 5036, 0xBB, 0x8E, 0x48, 0xFF),
    VTX(875, 250, -3438, 2129, 4321, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(1055, 579, -4219, 2192, 4924, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(1824, 362, -4141, 2383, 4864, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(1919, 676, -4571, 2203, 5096, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(2760, 587, -4295, 2707, 4983, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(3153, 941, -5254, 2736, 5774, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(-3500, 250, -2780, 62, 3612, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(-1848, 250, -2970, 633, 3759, 0x5E, 0x2F, 0x04, 0xFF),
    VTX(1752, 1031, -2893, 1878, 3700, 0x4F, 0x73, 0x3E, 0xFF),
    VTX(1824, 362, -3604, 2458, 4448, 0x5E, 0x2F, 0x04, 0xFF),
    VTX(1032, 250, -3085, 1896, 3948, 0xCC, 0xAA, 0x6F, 0xFF),
};
static Vtx D_86E04488[] = {
    VTX(-1848, 250, -2970, 633, 3759, 0x5E, 0x2F, 0x04, 0xFF),
    VTX(-3500, 250, -2780, 62, 3612, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(-2544, 844, -2221, 392, 3180, 0x4D, 0x73, 0x20, 0xFF),
    VTX(3500, 1101, -1961, 2483, 2980, 0x4F, 0x73, 0x3E, 0xFF),
    VTX(1894, 684, -1980, 1927, 2995, 0x4F, 0x73, 0x3E, 0xFF),
    VTX(1990, 250, -937, 2419, 2288, 0xBD, 0x97, 0x5E, 0xFF),
    VTX(-1803, 250, -5615, 787, 6152, 0xBF, 0xA2, 0x7D, 0xFF),
    VTX(-1822, 1182, -4421, 1069, 5329, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(-791, 836, -4459, 1425, 5359, 0x97, 0x59, 0x26, 0xFF),
    VTX(-749, 250, -5106, 1152, 5759, 0xBF, 0xA2, 0x7D, 0xFF),
    VTX(240, 547, -4363, 1910, 5036, 0xBB, 0x8E, 0x48, 0xFF),
    VTX(1055, 579, -4219, 2192, 4924, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(1145, 250, -4986, 1935, 5417, 0xBF, 0xA2, 0x7D, 0xFF),
    VTX(1577, 675, -6655, 2191, 6857, 0x9D, 0xDF, 0xCC, 0xFF),
    VTX(566, 791, -6840, 1841, 7000, 0x9D, 0xDF, 0xCC, 0xFF),
    VTX(0, 250, -3727, 1827, 4543, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(-644, 250, -2563, 970, 3445, 0x5E, 0x2F, 0x04, 0xFF),
    VTX(875, 250, -3438, 2129, 4321, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(864, 250, -2125, 1571, 3106, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(1032, 250, -3085, 1896, 3948, 0xCC, 0xAA, 0x6F, 0xFF),
    VTX(-739, 250, -2086, 957, 3076, 0x84, 0x5E, 0x3E, 0xFF),
    VTX(-1230, 250, -938, 1126, 2288, 0xBD, 0x97, 0x5E, 0xFF),
    VTX(-2480, 250, -125, 823, 1660, 0xBD, 0x97, 0x5E, 0xFF),
    VTX(-1345, 587, -1750, 667, 2817, 0x4D, 0x73, 0x20, 0xFF),
    VTX(-2206, 587, -1462, 389, 2594, 0x2D, 0x46, 0x09, 0xFF),
    VTX(-3500, 250, -125, 520, 1660, 0x84, 0x5E, 0x3E, 0xFF),
    VTX(-2452, 806, -984, 823, 2288, 0x4D, 0x73, 0x20, 0xFF),
    VTX(-3500, 250, 1500, 328, 404, 0x84, 0x5E, 0x3E, 0xFF),
    VTX(3500, 250, 1500, 2749, 404, 0x84, 0x5E, 0x3E, 0xFF),
    VTX(2784, 587, -3392, 2790, 4285, 0x5E, 0x2F, 0x04, 0xFF),
    VTX(1752, 1031, -2893, 2361, 3948, 0x4F, 0x73, 0x3E, 0xFF),
    VTX(3624, 1310, -2586, 2526, 3462, 0x4F, 0x73, 0x3E, 0xFF),
};
static Vtx D_86E04688[] = {
    VTX(-250, 0, 250, 0, 2880, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(250, 0, 250, 128, 2880, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(250, 620, 250, 128, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-250, 620, 250, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_86E046C8[] = {
    VTX(-206, -33, 80, 0, 974, 0x8E, 0xF2, 0x20, 0xFF),    VTX(-111, 68, 137, 233, 556, 0xAC, 0x30, 0x46, 0xFF),
    VTX(-159, 120, 14, 116, 339, 0x9D, 0x40, 0x11, 0xFF),  VTX(-82, -45, 202, 305, 1024, 0xDB, 0xE4, 0x6E, 0xFF),
    VTX(-25, 125, 193, 447, 318, 0xEE, 0x40, 0x63, 0xFF),  VTX(185, -19, -121, 968, 917, 0x5C, 0xD9, 0xBE, 0xFF),
    VTX(185, 94, -29, 967, 449, 0x6C, 0x2E, 0xED, 0xFF),   VTX(208, -44, -16, 1024, 1018, 0x72, 0xDE, 0x0C, 0xFF),
    VTX(-61, 102, -170, 358, 415, 0xD1, 0x29, 0x9A, 0xFF), VTX(-73, 202, -75, 328, 0, 0xC0, 0x5C, 0xD9, 0xFF),
    VTX(74, 200, -112, 693, 6, 0x22, 0x65, 0xCB, 0xFF),    VTX(80, 19, -211, 707, 758, 0x0F, 0x21, 0x8E, 0xFF),
    VTX(146, 21, 169, 871, 749, 0x52, 0x0C, 0x56, 0xFF),   VTX(121, 184, 54, 809, 73, 0x3D, 0x5F, 0x27, 0xFF),
    VTX(-60, 191, 78, 361, 46, 0xD7, 0x69, 0x27, 0xFF),    VTX(-181, 22, -65, 61, 744, 0x9A, 0x00, 0xC2, 0xFF),
};
static Gfx D_86E047C8[] = {
    gsSPVertex(D_86E046C8, 16, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(6, 11, 10, 0, 12, 13, 4, 0),
    gsSP2Triangles(14, 2, 1, 0, 9, 8, 15, 0),
    gsSP2Triangles(10, 13, 6, 0, 3, 1, 0, 0),
    gsSP2Triangles(12, 7, 6, 0, 10, 14, 13, 0),
    gsSP2Triangles(6, 13, 12, 0, 11, 8, 10, 0),
    gsSP2Triangles(6, 5, 11, 0, 15, 8, 11, 0),
    gsSP2Triangles(10, 9, 14, 0, 9, 2, 14, 0),
    gsSP2Triangles(15, 2, 9, 0, 4, 14, 1, 0),
    gsSP2Triangles(2, 15, 0, 0, 3, 12, 4, 0),
    gsSP1Triangle(4, 13, 14, 0),
    gsSPEndDisplayList(),
};
static Gfx D_86E04840[] = {
    gsSPClearGeometryMode(G_LIGHTING),      gsSPVertex(D_86E04688, 4, 0),    gsSPSetGeometryMode(G_CULL_BACK),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0), gsSPSetGeometryMode(G_LIGHTING), gsSPEndDisplayList(),
};
static Gfx D_86E04870[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_86E03E88, 32, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSP2Triangles(10, 11, 2, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 2, 11, 15, 0),
    gsSP2Triangles(17, 18, 0, 0, 19, 20, 8, 0),
    gsSP2Triangles(21, 22, 23, 0, 18, 24, 25, 0),
    gsSP2Triangles(18, 25, 0, 0, 1, 26, 27, 0),
    gsSP2Triangles(1, 27, 28, 0, 2, 1, 28, 0),
    gsSP2Triangles(29, 9, 30, 0, 29, 30, 31, 0),
    gsSP1Triangle(15, 21, 16, 0),
    gsSPVertex(D_86E04088, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(7, 9, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 14, 16, 17, 0),
    gsSP2Triangles(6, 18, 4, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 22, 24, 25, 0),
    gsSP2Triangles(23, 26, 27, 0, 23, 27, 28, 0),
    gsSP2Triangles(28, 27, 29, 0, 30, 31, 18, 0),
    gsSPVertex(D_86E04288, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(2, 1, 5, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 13, 11, 0),
    gsSP2Triangles(14, 15, 16, 0, 14, 17, 18, 0),
    gsSP2Triangles(16, 19, 14, 0, 18, 15, 14, 0),
    gsSP2Triangles(20, 17, 21, 0, 20, 21, 22, 0),
    gsSP2Triangles(22, 21, 23, 0, 22, 23, 24, 0),
    gsSP2Triangles(24, 23, 25, 0, 24, 25, 26, 0),
    gsSP2Triangles(10, 18, 20, 0, 11, 26, 12, 0),
    gsSP2Triangles(11, 24, 26, 0, 17, 20, 18, 0),
    gsSP2Triangles(19, 27, 28, 0, 29, 30, 31, 0),
    gsSP1Triangle(31, 8, 29, 0),
    gsSPVertex(D_86E04488, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 12, 9, 10, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 0, 16, 0),
    gsSP2Triangles(15, 16, 17, 0, 17, 18, 19, 0),
    gsSP2Triangles(17, 16, 18, 0, 18, 16, 20, 0),
    gsSP2Triangles(20, 5, 18, 0, 20, 21, 5, 0),
    gsSP2Triangles(21, 22, 5, 0, 21, 23, 24, 0),
    gsSP2Triangles(25, 22, 26, 0, 22, 25, 27, 0),
    gsSP2Triangles(28, 5, 22, 0, 22, 27, 28, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPEndDisplayList(),
};

static u32 D_86E049F8[] = {
    0x09000000, 0x05000000, 0x1D030100, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0x00010000, 0x00010000,
    0x05000000, 0x1D020101, 0x0000FF06, 0x00000000, 0x00000000, 0x0000CCCC, 0x00010000, 0x00010000, 0x05000000,
    0x2303FFFF, D_86E03E48, 0x0000FFFF, 0xFFFFFFFF, 0x22010000, D_86E04870, 0x1D010102, 0x03F400E0, 0xFB500000,
    0x00000000, 0x00014000, 0x00010000, 0x00010000, 0x05000000, 0x2301FFFF, D_86E03DD8, 0x0002FFFF, 0xFFFFFFFF,
    0x22010000, D_86E047C8, 0x06000000, 0x1D000103, 0x000000FA, 0xE3D40000, 0x00000000, 0x00117869, 0x0005FADE,
    0x00010000, 0x05000000, 0x2306FFFF, D_86E03E10, 0x0001FFFF, 0xFFFFFFFF, 0x22010000, D_86E04840, 0x06000000,
    0x06000000, 0x06000000, 0x06000000, 0x04000000,
};

static u32 D_86E04AE0[] = {
    0x17000003, 0x00000094, D_86E03DB0, 0x00000000, D_86E03E88, 0x05000000, 0x1C000000, 0x00001999,
    0x00001999, 0x00001999, 0x05000000, 0x03000000, D_86E049F8, 0x06000000, 0x06000000, 0x01000000,
};

static s16 D_86E04B20 = 0;
static s16 D_86E04B24 = 1;
static s16 D_86E04B28 = 0;
static minigameActor* tempMetadodPlayer = metadodPlayers;
static minigameActor* tempFallingRock = metapodMinigameFallingRocks;
static u32 D_86E04B34[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E, 0x00000000, 0x014000F0, 0xFFE20032, 0x00000000,  0x00000000,
    0x05000000, 0x0D000000, 0x05000000, 0x14000000, 0x002B0012, 0xFFFFFF32, 0x16FFFFFF,  0x0F000003,
    0x05000000, 0x1F00FFFF, 0x00000000, 0x00000000, 0xFFFE0000, 0x00640064, 0x00640000,  0x05000000,
    0x00000000, D_86E04AE0, 0x06000000, 0x06000000, 0x05000000, 0x0A000000, &D_800AC840, 0x06000000,
    0x06000000, 0x06000000, 0x03000000, D_87806398, 0x06000000, 0x01000000,
};
static Vec3f D_86E04BCC[] = {
    { -54.0f, 0.0f, 0.0f },
    { -18.0f, 0.0f, 0.0f },
    { 18.0f, 0.0f, 0.0f },
    { 54.0f, 0.0f, 0.0f },
};
static unk_D_86E04BFC D_86E04BFC[] = {
    { { -54.0f, 0.0f, -300.0f }, { 0, 0, 0 }, 20, 40, 0 },
    { { -18.0f, 0.0f, -300.0f }, { 0, 0, 0 }, 20, 40, 0 },
    { { 18.0f, 0.0f, -300.0f }, { 0, 0, 0 }, 20, 40, 0 },
    { { 54.0f, 0.0f, -300.0f }, { 0, 0, 0 }, 20, 40, 0 },
};
static unk_func_87801684 D_86E04C5C[] = {
    { D_0303ED80, 0xE }, { D_0303F180, 2 }, { D_0303F580, 6 }, { D_0303F180, 2 }, { NULL, 0 },
};
static unk_func_87801684 D_86E04C84[] = {
    { D_03040580, 0x12 }, { D_03040980, 2 }, { D_03040D80, 8 }, { D_03040980, 2 }, { NULL, 0 },
};

void func_86E00020(s16 arg0, s16 arg1) {
    s32 var_s0 = 0;
    s32 sp28;
    s32 sp24;

    if (arg1 == -1) {
        sp24 = 0;
        sp28 = 0;
    } else {
        sp28 = arg1;
        sp24 = 4;
    }

    switch (arg0) {
        case 1:
            var_s0 = 0x40001;
            break;

        case 2:
            var_s0 = 0x40002;
            break;

        case 5:
            var_s0 = 0x40003;
            break;

        case 6:
            var_s0 = 0x40004;
            break;

        case 7:
            var_s0 = 0x40005;
            break;

        case 8:
            var_s0 = 0x40006;
            break;

        case 9:
            var_s0 = 0x40007;
            break;

        case 10:
            func_8004B1CC(0x11);
            break;

        case 11:
            func_8004B9C4(0x3C);
            break;

        case 12:
            func_8004B1CC(0xC1);
            break;

        case 13:
            func_80048B90(3);
            break;

        case 14:
            func_8004FC60(1, arg1);
            func_8004FC60(2, arg1);
            D_8790604A = 1;
            break;

        case 15:
            func_8004B094(arg1);
            break;

        case 16:
            func_8004B154();
            break;
    }

    if (var_s0 != 0) {
        D_87903DBC++;
        func_8004D9B0(var_s0, sp28, sp24);
    }
}

void func_86E001A0(s16 arg0, s16 arg1) {
    if (D_8790604A == 0) {
        func_86E00020(arg0, arg1);
    }
}

void func_86E001E4(minigameActor* arg0, s32 arg1) {
    func_8790060C(arg0);

    arg0->scale.x = 1.0f;
    arg0->scale.y = 1.0f;
    arg0->scale.z = 1.0f;

    arg0->unk_1A8.x = D_86E04BCC[arg1].x;
    arg0->unk_1A8.y = D_86E04BCC[arg1].y;
    arg0->unk_1A8.z = D_86E04BCC[arg1].z;

    if (arg0->unk_23C == 0x9E) {
        arg0->unk_1A8.z -= 10.0f;
    }

    arg0->unk_21A = 0;
    arg0->unk_21C = 0;
    arg0->unk_21E = 0;
    arg0->unk_25C = 0x190;
    arg0->unk_258 = arg0->unk_25C;
    arg0->unk_2A6 = 5;
    arg0->unk_1E4 = arg0->unk_28C * 0.5f;

    func_8001BD04(&arg0->unk_000, 0);
    func_80017788(&arg0->unk_000);
    arg0->unk_000.unk_01C = 0;
    func_87900770(arg0);
    arg0->isHuman = D_879060C4[arg1];
}

void initMetapodPlayers(void) {
    s32 i;

    tempMetadodPlayer = metadodPlayers;
    for (i = 0; i < 4; i++) {
        func_86E001E4(tempMetadodPlayer, i);
        tempMetadodPlayer++;
    }
}

void func_86E0034C(minigameActor* arg0) {
    arg0->unk_25A++;
    arg0->unk_272 = 4;
    arg0->unk_000.unk_01C = 1;
}

void func_86E0036C(minigameActor* arg0) {
    if (arg0->unk_29A != 0) {
        arg0->unk_29A--;
    }

    if ((BTN_IS_DOWN(tempControllerPtr, BTN_A)) && (arg0->unk_23E == 0) && (arg0->unk_240 == 0) &&
        (arg0->unk_2AA == 0) && (arg0->unk_29A == 0)) {
        arg0->unk_23E = 1;
    }

    switch (arg0->unk_23E) {
        case 1:
            func_86E0034C(arg0);
            func_879002B8(arg0, 1, -1, 1);
            func_81407D48(1.0f, arg0->unk_190, arg0->unk_214, func_879029F0, &D_87903E40, 4);
            arg0->unk_23E++;
            break;

        case 2:
            if (func_80017484(&arg0->unk_000, 5) != 0) {
                arg0->unk_000.unk_000.unk_02 &= ~0x20;
            }

            if (!(BTN_IS_DOWN(tempControllerPtr, BTN_A)) || (arg0->unk_2AA != 0)) {
                arg0->unk_23E = 0;
                arg0->unk_000.unk_000.unk_02 |= 0x20;
            } else if (BTN_IS_DOWN(tempControllerPtr, BTN_A)) {
                func_86E0034C(arg0);
            }
            break;
    }
}

void func_86E004FC(minigameActor* metapod) {
    if (metapod->isHuman != 0) {
        metapod->unk_244 = 0;
        metapod->unk_242 = 0;
    }
}

s32 func_86E00518(minigameActor* arg0, s32 arg1) {
    s32 sp1C;
    s32 sp18;
    s32 var_v1;
    s32 temp_v0;

    switch (D_87906046) {
        case 0:
            if (arg1 < 0xA) {
                sp1C = 0x32;
            } else {
                sp1C = 0x46;
            }
            break;

        case 1:
            if (arg1 < 0xA) {
                sp1C = 0x50;
            } else {
                sp1C = 0x5A;
            }
            break;

        case 2:
            if (arg1 < 3) {
                sp1C = 0x5A;
            } else if (arg1 < 8) {
                sp1C = 0x5F;
            } else {
                sp1C = 0x62;
            }
            break;

        case 3:
            if (arg1 < 3) {
                sp1C = 0x60;
            } else if (arg1 < 8) {
                sp1C = 0x61;
            } else {
                sp1C = 0x62;
            }
            break;
    }

    sp18 = func_878001E8(0x64);
    temp_v0 = func_878001E8(0x64);

    if (sp18 < sp1C) {
        var_v1 = 0;
    } else if (temp_v0 < 0x32) {
        var_v1 = 1;
    } else {
        var_v1 = 2;
    }

    return var_v1;
}

void func_86E0063C(minigameActor* arg0, s32 arg1) {
    s32 sp2C;
    s32 sp28;
    u32 sp24;
    u32 temp_s1 = func_878001E8(arg1);

    switch (D_87906046) {
        case 0:
            sp2C = func_878001E8(0xA) + 2;
            sp28 = arg1 - temp_s1;
            sp2C += sp28;
            sp24 = func_878001E8(3);
            break;

        case 1:
            sp2C = func_878001E8(5) + 2;
            sp28 = arg1 - temp_s1;
            sp2C += sp28;
            sp24 = 0;
            break;

        case 2:
            sp2C = func_878001E8(4);
            sp28 = arg1 - temp_s1;
            sp2C += sp28;
            sp24 = 0;
            break;

        case 3:
            sp2C = func_878001E8(3);
            sp28 = arg1 - temp_s1;
            sp2C += sp28;
            sp24 = 0;
            break;
    }

    arg0->unk_244 = temp_s1;
    arg0->unk_29E = sp2C;
    arg0->unk_2B2 = sp24;
}

void func_86E0073C(minigameActor* arg0, s32 arg1) {
    u32 sp2C;
    UNUSED s32 pad[3];
    u32 sp1C;
    s32 var_a0;
    s32 var_a2;
    u32 temp_v0_2;

    if (arg1 < 5) {
        sp2C = 0;
        var_a0 = 0;
        var_a2 = arg1;
    } else {
        sp1C = arg1 - 4;
        sp2C = func_878001E8(sp1C);
        temp_v0_2 = func_878001E8(sp1C - sp2C);
        var_a0 = temp_v0_2 + 2;
        var_a2 = ((arg1 - sp2C) - temp_v0_2) - 2;
    }

    arg0->unk_244 = sp2C;
    arg0->unk_29E = var_a0;
    arg0->unk_2B2 = var_a2;
}

void func_86E007BC(minigameActor* arg0, s32 arg1) {
    arg0->unk_244 = arg1;
    arg0->unk_29E = 0;
    arg0->unk_2B2 = 0;
}

void func_86E007CC(minigameActor* metapod, s32 player) {
    s32 i;
    s32 sp20;
    s32 var_t0 = 0;

    if (metapod->unk_240 == 0) {
        switch (D_87906046) {
            case 0:
                sp20 = 0x1E;
                break;

            case 1:
                sp20 = 0x14;
                break;

            case 2:
                sp20 = 0xD;
                break;

            case 3:
                sp20 = 0xC;
        }

        tempFallingRock = metapodMinigameFallingRocks;
        for (i = 0; i < 20; i++) {
            if ((tempFallingRock->unk_270 != 0) && (player == tempFallingRock->unk_266)) {
                if (tempFallingRock->unk_29E < sp20) {
                    var_t0 = 1;
                    sp20 = tempFallingRock->unk_29E;
                }
            }
            tempFallingRock++;
        }

        sp20--;
        if (var_t0 != 0) {
            if (sp20 < 0) {
                sp20 = 0;
            }
            metapod->unk_242 = 1;

            switch (func_86E00518(metapod, sp20)) {
                case 0:
                    func_86E0063C(metapod, sp20);
                    break;

                case 1:
                    func_86E0073C(metapod, sp20);
                    break;

                case 2:
                    func_86E007BC(metapod, sp20);
                    break;
            }
        }
    }
}

void func_86E00924(minigameActor* arg0, s32 arg1) {
    if (arg0->unk_242 == 0) {
        func_86E007CC(arg0, arg1);
    }

    switch (arg0->unk_242) {
        case 0x1:
            arg0->unk_244--;
            if (arg0->unk_244 < 0) {
                if ((arg0->unk_2AA == 0) && (arg0->unk_240 == 0)) {
                    if (arg0->unk_29E > 0) {
                        func_879002B8(arg0, 1, -1, 1);
                        arg0->unk_23E = 1;
                        arg0->unk_272 = 4;
                        arg0->unk_242++;
                        func_81407D48(1.0f, arg0->unk_190, arg0->unk_214, func_879029F0, &D_87903E40, 4);
                    } else {
                        arg0->unk_242 = 0x64;
                    }
                } else {
                    arg0->unk_242 = 0;
                }
            }
            break;

        case 0x2:
            arg0->unk_29E--;
            if (arg0->unk_29E < 0) {
                arg0->unk_000.unk_000.unk_02 |= 0x20;
                arg0->unk_242 = 0x64;
                return;
            }

            arg0->unk_25A++;
            arg0->unk_272 = 4;
            arg0->unk_000.unk_01C = 1;
            if (func_80017484(&arg0->unk_000, 5) != 0) {
                arg0->unk_000.unk_000.unk_02 &= ~0x20;
            }
            break;

        case 0x64:
            arg0->unk_2B2--;
            if (arg0->unk_2B2 <= 0) {
                arg0->unk_23E = 0;
                arg0->unk_242 = 0;
            }
            break;
    }
}

void func_86E00AF4(void) {
    s32 i;

    tempControllerPtr = gPlayer1Controller;
    tempMetadodPlayer = metadodPlayers;

    for (i = 0; i < 4; i++) {
        tempMetadodPlayer->unk_000.unk_01C = 0;
        tempMetadodPlayer->unk_272 = 0;

        if (minigameInputLock != 0) {
            if (tempMetadodPlayer->isHuman == 0) {
                func_86E0036C(tempMetadodPlayer);
            } else {
                func_86E00924(tempMetadodPlayer, i);
            }
        }

        func_87900770(tempMetadodPlayer);
        func_87900808(tempMetadodPlayer);

        tempMetadodPlayer++;
        tempControllerPtr++;
    }
}

s32 metapodRockCollisionCheck_void(void) {
    return metapodRockCollisionCheck(tempFallingRock, &metadodPlayers[tempFallingRock->unk_266]);
}

s32 func_86E00C34(s32 arg0) {
    s32 sp1C = 0;

    if (metapodRockCollisionCheck_void() != 0) {
        tempMetadodPlayer->unk_260 = 1;
        if (tempMetadodPlayer->unk_272 != 0) { //  if hardened ? colliding ?
            func_86E001A0(7, arg0);
            sp1C = 1;
        } else {
            tempMetadodPlayer->unk_240 = 1; // set the metapod's squashing animation
            func_86E004FC(tempMetadodPlayer);
            sp1C = 2;
        }
    }
    return sp1C;
}

void func_86E00CAC(minigameActor* arg0, s32 arg1) {
    s32 i;
    s32 colliding;

    tempFallingRock = metapodMinigameFallingRocks;

    for (i = 0; i < 20; i++) {
        if ((tempFallingRock->unk_270 != 0) && (arg1 == tempFallingRock->unk_266) && (tempFallingRock->unk_260 == 0)) {
            colliding = func_86E00C34(arg1);
            if (colliding != 0) {
                tempFallingRock->unk_260 = 1;
                if (colliding == 1) {
                    tempFallingRock->unk_272 = 1;
                } else {
                    tempFallingRock->unk_272 = 0;
                }
                break;
            }
        }
        tempFallingRock++;
    }
}

void func_86E00D78(minigameActor* arg0, s32 arg1) {
    if ((tempMetadodPlayer->unk_25A > 0) && (arg0->unk_2A8 == 0)) {
        if (tempMetadodPlayer->unk_25A >= 0x28) {
            tempMetadodPlayer->unk_258 -= tempMetadodPlayer->unk_25A;
            tempMetadodPlayer->unk_25A = 0;
        } else {
            tempMetadodPlayer->unk_25A--;
            tempMetadodPlayer->unk_258--;
        }

        if (tempMetadodPlayer->unk_258 < 0) {
            tempMetadodPlayer->unk_258 = 0;
        }
    }

    if (tempMetadodPlayer->unk_258 == 0) {
        if (tempMetadodPlayer->unk_2A4 == 0) {
            func_86E001A0(9, arg1);
            func_879002B8(tempMetadodPlayer, 3, 1, 0);
            tempMetadodPlayer->unk_2A4 = 1;
            tempMetadodPlayer->unk_2AA = 1;
        }
    } else {
        switch (tempMetadodPlayer->unk_240) {
            case 1:
                tempMetadodPlayer->unk_25A += 0x1E;
                func_879002B8(tempMetadodPlayer, 2, 0, 1);
                func_86E001A0(8, arg1);
                tempMetadodPlayer->unk_240++;
                break;

            case 2:
                if (tempMetadodPlayer->unk_248 == 0) {
                    tempMetadodPlayer->unk_240 = 0;
                }
                break;
        }
    }
}

void func_86E00ED0(void) {
    s32 i;

    tempMetadodPlayer = metadodPlayers;

    for (i = 0; i < 4; i++) {
        if (minigameInputLock != 0) {
            func_86E00CAC(tempMetadodPlayer, i);
            func_86E00D78(tempMetadodPlayer, i);
        }
        tempMetadodPlayer++;
    }
}

void func_86E00F60(void) {
    func_879003A0(tempMetadodPlayer);

    tempMetadodPlayer->unk_000.unk_024.x = tempMetadodPlayer->unk_190.x;
    tempMetadodPlayer->unk_000.unk_024.y = tempMetadodPlayer->unk_190.y;
    tempMetadodPlayer->unk_000.unk_024.z = tempMetadodPlayer->unk_190.z;

    tempMetadodPlayer->unk_000.unk_01E.x = tempMetadodPlayer->unk_214.x;
    tempMetadodPlayer->unk_000.unk_01E.y = tempMetadodPlayer->unk_214.y;
    tempMetadodPlayer->unk_000.unk_01E.z = tempMetadodPlayer->unk_214.z;
}

void func_86E00FD8(void) {
    s32 i;

    tempMetadodPlayer = metadodPlayers;

    for (i = 0; i < 4; i++) {
        func_86E00F60();
        tempMetadodPlayer++;
    }
}

void func_86E0103C(minigameActor* arg0, s32 arg1) {
    func_8790060C(arg0);
    arg0->unk_266 = arg1;

    arg0->unk_1A8.x = D_86E04BFC[arg1].unk_00.x;
    arg0->unk_1A8.y = D_86E04BFC[arg1].unk_00.y;
    arg0->unk_1A8.z = D_86E04BFC[arg1].unk_00.z;

    arg0->unk_270 = 0;
    arg0->unk_288 = D_86E04BFC[arg1].unk_12;
    arg0->unk_28C = D_86E04BFC[arg1].unk_14;

    arg0->scale.x = 0.5f;
    arg0->scale.y = 0.5f;
    arg0->scale.z = 0.5f;

    arg0->unk_000.unk_000.unk_01 &= ~1;

    func_87900770(arg0);
}

void initFallingRocks(void) {
    s32 i;
    s32 j;

    tempFallingRock = metapodMinigameFallingRocks;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            func_86E0103C(tempFallingRock, i);
            tempFallingRock++;
        }
    }

    D_86E04B20 = 0;
    D_86E04B24 = 1;
}

void func_86E01188(void) {
    s32 i;
    s32 j;
    s32 var_s1;
    s32 sp40;
    s32 var_s5;
    minigameActor* ptr;

    switch (D_87906046) {
        default:
            var_s5 = sp40;
            break;

        case 0:
            var_s5 = func_878001E8(0x14) + 0xF;
            break;

        case 1:
            var_s5 = func_878001E8(0x14) + 0xA;
            break;

        case 2:
            var_s5 = func_878001E8(0x1E) + 5;
            break;

        case 3:
            var_s5 = func_878001E8(0x1E) + 5;
            break;
    }

    ptr = metadodPlayers;
    for (i = 0; i < 4; i++, ptr++) {
        if (ptr->unk_2AA == 0) {
            var_s1 = 0;
            tempFallingRock = &metapodMinigameFallingRocks[i * 5];

            for (j = 0; j < D_86E04B24; j++) {
                func_86E0103C(tempFallingRock, i);

                tempFallingRock->unk_23E = 1;
                tempFallingRock->unk_29E = var_s1;

                var_s1 += var_s5;
                tempFallingRock++;
            }
        }
    }
}

void func_86E01310(minigameActor* arg0) {
    s16 temp_v1 = (D_86E04B20 * 4) + 0x28;
    s16 temp_a1 = arg0->unk_266;

    arg0->unk_29E = temp_v1 - 1;
    arg0->unk_1A8.y += D_86E04BFC[temp_a1].unk_00.y + metadodPlayers[temp_a1].unk_28C;

    arg0->unk_210 = 0.7f;
    arg0->unk_1F8 = 0.0f;
    arg0->unk_1FC = temp_v1 * arg0->unk_210 * 0.5f;

    arg0->unk_200 =
        ((metadodPlayers[temp_a1].unk_1A8.z + (metadodPlayers[temp_a1].unk_288 * 0.5f)) - arg0->unk_1A8.z) / temp_v1;
    arg0->unk_270 = 1;

    arg0->unk_000.unk_000.unk_01 |= 1;
    func_8001BD04(&arg0->unk_000, 0);
}

void func_86E01414(minigameActor* arg0) {
    arg0->unk_23E = 0;
    arg0->unk_000.unk_000.unk_01 &= ~1;
}

void func_86E01428(minigameActor* arg0) {
    UNUSED s32 pad[3];
    s16 temp_a1 = arg0->unk_266;
    Vec3f sp3C;

    if ((D_87903DA8 != 0) || (metadodPlayers[temp_a1].unk_258 == 0)) {
        switch (arg0->unk_23E) {
            case 1:
                arg0->unk_23E = 0;
                break;

            case 2:
                arg0->unk_270 = 0;
                arg0->unk_23E = 0x64;
                break;
        }
    }

    switch (arg0->unk_23E) {
        case 0x1:
            arg0->unk_29E--;
            if (arg0->unk_29E <= 0) {
                func_86E001A0(5, temp_a1);
                func_86E01310(arg0);
                arg0->unk_23E++;
            }
            break;

        case 0x2:
            arg0->unk_29E--;
            if (arg0->unk_29E < 0) {
                arg0->unk_29E = 0;
            }

            if (arg0->unk_260 != 0) {
                arg0->unk_270 = 0;
                if (arg0->unk_272 != 0) {
                    arg0->unk_1FC = 5.0f;
                    arg0->unk_200 = 1.5f;
                    func_86E01414(arg0);
                    func_81407D48(1.0f, arg0->unk_190, arg0->unk_214, func_87901F04, &D_87903E28, 4);
                } else {
                    arg0->unk_23E++;
                }
            }
            break;

        case 0x3:
            arg0->unk_1FC = 7.0f;
            arg0->unk_200 = 3.0f;

            sp3C.x = arg0->unk_190.x;
            sp3C.y = 0.0f;
            sp3C.z = arg0->unk_190.z;

            func_81407D48(1.0f, sp3C, arg0->unk_214, func_87902068, &D_87903E10, 4);
            arg0->unk_23E++;
            break;

        case 0x4:
            if (arg0->unk_190.y < -10.0f) {
                func_86E01414(arg0);
            }
            break;

        case 0x64:
            if (func_814004D8(&arg0->unk_000.unk_01D, 0, 0x40) != 0) {
                func_86E01414(arg0);
            }
            break;
    }
}

void func_86E016EC(minigameActor* arg0) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;

    arg0->unk_190.x = arg0->unk_19C.x = arg0->unk_1A8.x + arg0->unk_1C0.x;
    arg0->unk_190.y = arg0->unk_19C.y = arg0->unk_1A8.y + arg0->unk_1C0.y;
    arg0->unk_190.z = arg0->unk_19C.z = arg0->unk_1A8.z + arg0->unk_1C0.z;
}

void func_86E0172C(minigameActor* arg0) {
    if (arg0->unk_23E != 0) {
        arg0->unk_1F8 += arg0->unk_204;
        arg0->unk_1FC += arg0->unk_208 - arg0->unk_210;
        arg0->unk_200 += arg0->unk_20C;
        arg0->unk_1C0.x += arg0->unk_1F8;
        arg0->unk_1C0.y += arg0->unk_1FC;
        arg0->unk_1C0.z += arg0->unk_200;
    }

    func_86E016EC(arg0);
}

void func_86E017C0(void) {
    s32 i;

    tempFallingRock = metapodMinigameFallingRocks;
    for (i = 0; i < 20; i++) {
        func_86E01428(tempFallingRock);
        func_86E0172C(tempFallingRock);
        tempFallingRock++;
    }
}

void func_86E0182C(minigameActor* arg0) {
    func_879003A0(arg0);

    arg0->unk_000.unk_030.x = arg0->scale.x;
    arg0->unk_000.unk_030.y = arg0->scale.y;
    arg0->unk_000.unk_030.z = arg0->scale.z;

    arg0->unk_000.unk_024.x = arg0->unk_190.x;
    arg0->unk_000.unk_024.y = arg0->unk_190.y;
    arg0->unk_000.unk_024.z = arg0->unk_190.z;

    arg0->unk_000.unk_01E.x = arg0->unk_214.x;
    arg0->unk_000.unk_01E.y = arg0->unk_214.y;
    arg0->unk_000.unk_01E.z = arg0->unk_214.z;
}

void func_86E01898(void) {
    s32 var_s1;

    tempFallingRock = metapodMinigameFallingRocks;
    var_s1 = 0;
    do {
        func_86E016EC(tempFallingRock);
        func_86E0182C(tempFallingRock);
        var_s1 += 1;
        tempFallingRock = &tempFallingRock[1];
    } while (var_s1 != 0x14);
}

void func_86E01904(void) {
    D_87906054 = D_87906050->unk_00.unk_0C;

    minigameCameraXRot = -0x200;
    minigameCameraYRot = 0;
    minigameCameraDistance = 0xBE;
    minigameCameraFOV = 0x23;
    minigameCameraNear = 0x32;
    minigameCameraFar = 0x1900;

    minigameCameraCoords.x = 0;
    minigameCameraCoords.y = 0x2A;
    minigameCameraCoords.z = 0;

    func_87900B64();
}

void func_86E01990(void) {
    minigameDebuggModeControll();
    func_87900B64();
}

void initMetapodMinigameAssets(void) {
    func_87900854(); //	minigame variables
    initFallingRocks();
    initMetapodPlayers();
    func_86E01904(); //	camera
    minigameInputLock = 0;
}

void func_86E019F4(void) {
    s32 i;
    s32 var_a2;

    tempFallingRock = metapodMinigameFallingRocks;
    switch (D_86E04B28) {
        case 1:
            func_86E01188();
            D_86E04B28 += 1;
            break;

        case 2:
            var_a2 = 1;
            for (i = 0; i < 20; i++) {
                if (tempFallingRock->unk_23E != 0) {
                    var_a2 = 0;
                    break;
                }
                tempFallingRock++;
            }

            if (var_a2 != 0) {
                if (D_87903DA8 != 0) {
                    D_86E04B28 = 0;
                    return;
                }

                D_86E04B28 = 1;
                D_86E04B20++;
                if (D_86E04B20 >= 5) {
                    D_86E04B20 = 0;
                    D_86E04B24++;
                    if (D_86E04B24 >= 6) {
                        D_86E04B24 = 1;
                    }
                }
            }
    }
}

s32 func_86E01B08(void) {
    UNUSED s32 pad[2];
    s32 i;
    s32 var_a3 = 5;
    s32 var_t2 = 0;
    s32 var_t1 = 0;
    s32 var_t3 = 0;
    s32 var_v0_5;

    tempMetadodPlayer = metadodPlayers;

    for (i = 0; i < 4; i++) {
        if (tempMetadodPlayer->unk_2A6 < var_a3) {
            var_a3 = tempMetadodPlayer->unk_2A6;
        }

        if (tempMetadodPlayer->unk_2A4 == 1) {
            var_t1++;
        }

        if (tempMetadodPlayer->unk_2A4 == 2) {
            var_t2++;
        }

        tempMetadodPlayer++;
    }

    if (var_t1 != 0) {
        var_a3 -= var_t1;
        tempMetadodPlayer = metadodPlayers;
        for (i = 0; i < 4; i++) {
            if (tempMetadodPlayer->unk_2A4 == 1) {
                tempMetadodPlayer->unk_2A4 = 2;
                tempMetadodPlayer->unk_2A6 = var_a3;
            }
            tempMetadodPlayer++;
        }
    }

    var_a3 = var_t1 + var_t2;
    var_v0_5 = 0;
    if (3 == var_a3) {
        var_v0_5 = 1;
    } else if (var_t1 == 4) {
        var_v0_5 = 2;
    } else if ((var_t1 >= 2) && (var_a3 == 4)) {
        var_v0_5 = 3;
    }

    tempMetadodPlayer = metadodPlayers;

    switch (var_v0_5) {
        case 1:
            for (i = 0; i < 4; i++) {
                if (tempMetadodPlayer->unk_2A6 == 5) {
                    tempMetadodPlayer->unk_2A8 = 1;
                    tempMetadodPlayer->unk_2AA = 1;
                    tempMetadodPlayer->unk_2A6 = 1;
                    var_t3 = 1;
                    func_87802F00(i);
                    break;
                }
                tempMetadodPlayer++;
            }
            break;

        case 2:
            var_t3 = 1;
            for (i = 0; i < 4; i++) {
                tempMetadodPlayer->unk_2AA = 1;
                tempMetadodPlayer->unk_2A6 = 0;
                tempMetadodPlayer++;
            }
            break;

        case 3:
            for (i = 0; i < 4; i++) {
                if (tempMetadodPlayer->unk_2A6 == 1) {
                    tempMetadodPlayer->unk_2AA = 1;
                    tempMetadodPlayer->unk_2A6 = 5;
                    var_t3 = 1;
                }
                tempMetadodPlayer++;
            }
            break;
    }

    if (var_t3 != 0) {
        D_87903DA8 = 1;
    }
    return var_t3;
}

s32 func_86E01E34(void) {
    s32 i;
    s32 var_s3 = 0;
    minigameActor* var_s0;

    for (i = 0, var_s0 = metadodPlayers; i < 4; i++, var_s0++) {
        if (var_s0->unk_2A8 != 0) {
            func_879002B8(var_s0, 4, -1, 0);
            var_s3 = 1;
        }
    }

    return var_s3;
}

void func_86E01EB0(void) {
    s32 i;

    tempMetadodPlayer = metadodPlayers;
    for (i = 0; i < 4; i++) {
        if (tempMetadodPlayer) {}

        tempMetadodPlayer++;
    }
}

s32 func_86E01EE8(void) {
    s32 sp1C = 0;
    s32 temp_v0 = func_87802974();

    if (temp_v0 == -2) {
        sp1C = 1;
    }

    if (temp_v0 > 0) {
        func_86E001A0(1, 0);
    } else if (temp_v0 == 0) {
        func_86E001A0(2, 0);
        func_86E001A0(0xA, 0);
    }

    return sp1C;
}

s32 func_86E01F50(void) {
    s32 i;
    s32 ret = 1;
    minigameActor* var_v0 = metapodMinigameFallingRocks;

    for (i = 0; i < 20; i++, var_v0++) {
        if (var_v0->unk_23E != 0) {
            ret = 0;
            break;
        }
    }
    return ret;
}

void func_86E01F8C(void) {
    switch (minigameState) {
        case 1:
            minigameInputLockTimer = 0xF;
            minigameState++;
            break;

        case 2:
            minigameInputLockTimer--;
            if (minigameInputLockTimer < 0) {
                func_8780295C(1);
                minigameState++;
            }
            break;

        case 3:
            if (func_86E01EE8() != 0) {
                D_86E04B28 = 1;
                minigameInputLock = 1;
                D_87903DC4 = 0;
                minigameState++;
            }
            break;

        case 4:
            if (1) {}

            if (func_86E01B08() != 0) {
                minigameState++;
            } else {
                func_86E019F4();
            }
            break;

        case 5:
            if (func_86E01F50() != 0) {
                minigameInputLockTimer = 0xA;
                minigameState++;
            }
            break;

        case 6:
            minigameInputLockTimer--;
            if (minigameInputLockTimer < 0) {
                func_86E01E34();
                func_87802EB8(1);
                minigameState++;
            }
            break;

        case 7:
            if (D_8780FC96 != 0) {
                minigameState++;
                D_87903DAC = 1;
            }
            break;
    }

    func_878025D0();
    func_86E01EB0();
}

void func_86E02150(void) {
    func_87901C20();
}

void func_86E02170(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_8780024C(0x1A + i * 0x4A, 0xD0, 0x32, metadodPlayers[i].unk_258, metadodPlayers[i].unk_25C);
    }
}

void fixMetapodMinigameHUD(void) {
    s32 i;
    s32 tmp;

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, minigameHUDTransparency);

    for (i = 0, tmp = 0x26; i < 4; tmp += 0x4A, i++) {
        if (D_879060C4[i] == 0) {
            func_87801644(i, tmp, 0xD6, 0.7f); //  draw player icon
        } else {
            func_87801644(-1 - i, tmp, 0xD6, 0.7f); //  draw player icon
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_86E02308(void) {
    UNUSED s32 pad;
    s32 sp38;
    s32 sp34;

    func_80020460(0x18, 0x16, 0x110, 0x90, 0x15);
    func_80020460(0x18, 0xA5, 0x110, 0x36, 0x14B);
    func_8001F3F4();
    func_8001F470();
    func_8001EBE0(2, 0);
    func_8001F3B4(0xC);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001F36C(0xF9, 0xF4, 0, 0xFF);
    func_8001F1E8(0xA0 - (func_878013D4(D_86E08E44, func_8002D7C0(NULL, 0, D_87806330, 0x44)) / 2), 0x20,
                  func_8002D7C0(NULL, 0, D_87806330, 0x44));
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001F36C(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001F1E8(0x28, 0x34, func_8002D7C0(NULL, 0, D_87806330, 0x45));
    func_8001F1E8(0x28, 0x58, func_8002D7C0(NULL, 0, D_87806330, 0x46));
    func_8001F1E8(0x28, 0x7C, func_8002D7C0(NULL, 0, D_87806330, 0x47));
    func_8001F1E8(0x28, 0x94, func_8002D7C0(NULL, 0, D_87806330, 0x48));
    func_8001F324(0xC8, 0xC8, 0xFF, 0xFF);
    func_8001F36C(0x50, 0x50, 0xFF, 0xFF);
    func_87801290(&sp38, &sp34, func_8002D7C0(NULL, 0, D_87806330, 0x45), func_8002D7C0(NULL, 0, D_87806330, 0x5F),
                  0xC);
    func_8001F1E8(sp38 + 0x28, sp34 + 0x34, func_8002D7C0(NULL, 0, D_87806330, 0x5F));
    func_87801290(&sp38, &sp34, func_8002D7C0(NULL, 0, D_87806330, 0x46), func_8002D7C0(NULL, 0, D_87806330, 0x5F),
                  0xC);
    func_8001F1E8(sp38 + 0x28, sp34 + 0x58, func_8002D7C0(NULL, 0, D_87806330, 0x5F));
    func_8001F1E8(0x8B, 0xB2, func_8002D7C0(NULL, 0, D_87806330, 0x5C));
    func_8001F1E8(0x8B, 0xC8, func_8002D7C0(NULL, 0, D_87806330, 0x5C));
    func_8001F324(0xC8, 0xC8, 0xFF, 0xFF);
    func_8001F36C(0x50, 0x50, 0xFF, 0xFF);
    func_8001F1E8(0xA2, 0xB2, func_8002D7C0(NULL, 0, D_87806330, 0x49));
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001F36C(0xFF, 0x80, 0x80, 0xFF);
    func_8001F1E8(0xA2, 0xC8, func_8002D7C0(NULL, 0, D_87806330, 0x14));
    func_8001F4C4();
    func_8001F444();
}

void func_86E026D0(void) {
    switch (D_87903DCC) {
        case 3:
            func_86E02308();

            gSPDisplayList(gDisplayListHead++, D_8006F518);

            func_87801F48(2, 0x19, 0xA6);
            func_87801684(0x74, 0xB0, D_86E04C5C);
            func_87801824(0x74, 0xC6, D_86E04C84);

            gSPDisplayList(gDisplayListHead++, D_8006F630);
            break;

        case 5:
            func_879032BC(0x3E8);
            break;
    }

    if (D_87903DC4 == -2) {
        func_8001EBE0(0x10, -2);
        func_8001EBE0(4, -2);
    }
}

void func_86E027D4(void) {
    func_87903260();
    func_86E026D0();
}

void func_86E027FC(s32 arg0) {
    u8 sp1C[] = { 0, 0, 30 };
    u8 sp18[] = { 0, 0, 250 };

    func_8001F3F4();
    func_8001EBE0(4, -2);
    func_86E027D4();
    func_8001F444();

    if (showMinigameHUD != 0) {
        func_86E02170();
        fixMetapodMinigameHUD();
    }
}

void func_86E02880(s32 arg0) {
    func_800079C4();
    func_8000699C(&gDisplayListHead, 0xA6BF);

    if (D_8780FC94 == 0) {
        func_80015348();
    }

    func_80015094(&D_87906050->unk_00);
    func_87901C98();

    if (minigameDebuggMode == 0) {
        if (D_8780FC98 == 0) {
            func_86E027FC(arg0);
        }
        func_87804FD4();
    } else {
        showDebuggCameraInfo();
    }

    func_80007778();
}

void metapodMinigameInit(void) {
    initMetapodMinigameAssets();
    func_800077B4(0xA);
    func_80006C6C(0x10);
    D_87903DC4 = 3;
    D_87906046 = D_8780FA38;
}

void func_86E0296C(void) {
}

void func_86E02974(void) {
    if ((minigameDebuggMode == 0) && (showMinigameHUD == 0) && (func_80007604() == 0)) {
        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_START)) {
            D_87903DC4 = 1;
            minigameState = 1;
            showMinigameHUD = 1;
            func_86E001A0(0xB, 0);
        } else if ((D_8780FA2A == 0) && (BTN_IS_PRESSED(gPlayer1Controller, BTN_B))) {
            func_86E001A0(0xD, 0);
            func_87802EB8(2);
        }
    }
}

void func_86E02A28(void) {
    minigameActor* metapod = metadodPlayers;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A) && (metapod->unk_23E == 0)) {
        metapod->unk_29A = 4;
    }
}

void func_86E02A64(void) {
    s32 var_s1 = 1;

    D_87903DBC = 0;

    func_87901620();
    hideMiniGameHUD();

    while (var_s1 != 0) {
        func_87900528();

        if (minigameState == 0) {
            D_87906042 += 1;
            if (D_87906042 < 0) {
                D_87906042 = 0;
            }
        }

        func_86E02974();

        if (D_8780FC94 == 0) {
            func_8140C5D0();
            func_86E01F8C();
            func_86E00AF4();
            func_86E017C0();
            func_86E00ED0();
            func_86E01898();
            func_86E00FD8();
            func_86E02150();
            func_86E01990();
        } else {
            func_86E02A28();
        }

        if ((D_87903DAC != 0) || (D_8780FC92 != 0)) {
            var_s1 = 0;
        }

        func_86E02880(1);
    }
}

void func_86E02BB0(void) {
    s32 i;

    func_80006CB4(0x1E);
    if (D_86E08E40 != 0) {
        func_86E001A0(0xF, 0x1E);
    } else {
        func_86E001A0(0xE, 0x1E);
    }

    for (i = 0; i < 30; i++) {
        func_87900528();  // input reading
        func_86E02880(2); // display text ?
    }

    while (func_800484E0() != 0) {}

    func_86E001A0(0x10, 0);
}

void func_86E02C5C(void) {
    static s16 D_86E04CB4[6][4] = {
        { 0x9B, 0xA, 0x23, 0 }, { 0x9E, 0xA, 0x1E, 0 }, { 0, 0x13, 0, 0x28 },
        { -1, -0x19, 0, 0 },    { 0, 0x3C, 0, 0x20 },   { 0, 6, -1, -0x14 },
    };

    s32 i;
    MemoryBlock* temp_v0;
    unk_D_86002F30* temp_s1_2;
    s32 var_v1;

    temp_v0 = func_80002D10(main_pool_get_available(), 0);
    D_87906050 = process_geo_layout(temp_v0, D_86E04B34);
    func_80002D60(temp_v0);
    func_8001BB20();

    for (i = 0; i < 4; i++) {
        func_8001BB58(&metadodPlayers[i].unk_000);
    }

    for (i = 0; i < 20; i++) {
        func_8001BB58(&metapodMinigameFallingRocks[i].unk_000);
    }

    func_8001987C();

    for (i = 0; i < 4; i++) {
        var_v1 = D_8780FA68[i] - 1;
        if (D_8780FA68[i] == 0) {
            var_v1 = func_878001E8(2);
        }

        metadodPlayers[i].unk_23C = D_86E04CB4[var_v1][0];
        metadodPlayers[i].unk_168 = func_80019D18(metadodPlayers[i].unk_23C);
        metadodPlayers[i].unk_288 = D_86E04CB4[var_v1][1];
        metadodPlayers[i].unk_28C = D_86E04CB4[var_v1][2];

        func_8001BC34(&metadodPlayers[i].unk_000, 0, metadodPlayers[i].unk_23C,
                      metadodPlayers[i].unk_168->unk_08->unk_00[0]);
        func_8001BD04(&metadodPlayers[i].unk_000, 0);

        if (metadodPlayers) {}
    }

    temp_s1_2 = func_80019D18(0x9C);
    for (i = 0; i < 20; i++) {
        metapodMinigameFallingRocks[i].unk_23C = 0x9C;
        metapodMinigameFallingRocks[i].unk_168 = temp_s1_2;

        func_8001BC34(&metapodMinigameFallingRocks[i].unk_000, 0, metapodMinigameFallingRocks[i].unk_23C,
                      temp_s1_2->unk_08->unk_00[0]);
        func_8001BD04(&metapodMinigameFallingRocks[i].unk_000, 0);

        metapodMinigameFallingRocks[i].unk_000.unk_000.unk_01 &= ~1;
    }
}

s32 metapodMinigameLoad(s32 arg0, s32 arg1) {
    unk_func_80007444* sp24;

    if (arg0 == 1) {
        D_86E08E40 = 1;
    } else {
        D_86E08E40 = 0;
    }

    main_pool_push_state('MINI');

    func_80005E40(0x40000, 0);
    sp24 = func_80007444(0, 1, 3, 1, 2, 1);
    D_86E08E44 = func_8001E94C(0x16, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    FRAGMENT_LOAD(fragment31);
    func_80004454((((u32)D_8D000000 & 0x0FF00000) >> 0x14) - 0x10, _5C7A70_ROM_START, pokedex_area_model_ROM_START);

    func_86E02C5C();
    func_80007678(sp24);
    metapodMinigameInit();
    func_86E02A64(); //	tutorial screen ?
    func_86E02BB0();
    func_800076C0();
    func_8001E9CC(); //	main_pool_try_free(D_800AC870);
    func_80005EAC(); //	main_pool_try_free(D_800A7428.unk4); main_pool_try_free(D_800A7428.unk0);

    main_pool_pop_state('MINI');

    return func_87803118();
}
