#include "newtopaz.h"
#include <nds.h>

using namespace WoopsiGfx;

static const u16 NewTopaz_glyphdata[373] = {
/* '!' */	0x3FF3,0x0000,
/* '"' */	0x06F6,0x0000,0x0000,0x0000,
/* '#' */	0x00D9,0xB7F6,0xDFDB,0x3600,0x0000,
/* '$' */	0x00C7,0xF078,0x3F8C,0x0000,
/* '%' */	0x0001,0x9D6D,0x86DA,0xE600,0x0000,
/* '&' */	0x0038,0x6C68,0x76DC,0xCE7B,0x0000,
/* ''' */	0x0DE0,0x0000,
/* '(' */	0x036C,0xCC63,0x0000,
/* ')' */	0x0C63,0x336C,0x0000,
/* '*' */	0x0001,0x99EF,0xE799,0x8000,0x0000,
/* '+' */	0x0003,0x0CFC,0xC300,0x0000,
/* ',' */	0x0000,0x1BC0,
/* '-' */	0x0000,0x00FC,0x0000,0x0000,
/* '.' */	0x0000,0x1B00,
/* '/' */	0x0003,0x060C,0x1830,0x60C0,0x0000,
/* '0' */	0x01EC,0xF7FF,0xBCDE,0x0000,
/* '1' */	0x037F,0x3333,0x0000,
/* '2' */	0x01EC,0xC318,0xC63F,0x0000,
/* '3' */	0x01EC,0xC338,0x3CDE,0x0000,
/* '4' */	0x0038,0xF36C,0xDFC3,0x0600,0x0000,
/* '5' */	0x03FC,0x3E0C,0x3CDE,0x0000,
/* '6' */	0x00E6,0x30FB,0x3CDE,0x0000,
/* '7' */	0x03F0,0xC318,0xC30C,0x0000,
/* '8' */	0x01EC,0xF37B,0x3CDE,0x0000,
/* '9' */	0x01EC,0xF37C,0x319C,0x0000,
/* ':' */	0x0F0F,0x0000,
/* ';' */	0x01B0,0x1BC0,
/* '<' */	0x0000,0xCCC0,0xC0C0,0x0000,
/* '=' */	0x0000,0x3F03,0xF000,0x0000,
/* '>' */	0x000C,0x0C0C,0xCC00,0x0000,
/* '?' */	0x0079,0x9830,0xC300,0x0C00,0x0000,
/* '@' */	0x00FB,0x1EFD,0x7BF0,0x3C00,0x0000,
/* 'A' */	0x01EC,0xF3FF,0x3CF3,0x0000,
/* 'B' */	0x03EC,0xF3FB,0x3CFE,0x0000,
/* 'C' */	0x00F6,0x30C3,0x060F,0x0000,
/* 'D' */	0x03CD,0xB3CF,0x3DBC,0x0000,
/* 'E' */	0x03FC,0x30F3,0x0C3F,0x0000,
/* 'F' */	0x03FC,0x30F3,0x0C30,0x0000,
/* 'G' */	0x01EC,0xF0DF,0x3CDF,0x0000,
/* 'H' */	0x033C,0xF3FF,0x3CF3,0x0000,
/* 'I' */	0x0F66,0x666F,0x0000,
/* 'J' */	0x0030,0xC30C,0x3CDE,0x0000,
/* 'K' */	0x018F,0x36CF,0x1B33,0x6300,0x0000,
/* 'L' */	0x030C,0x30C3,0x0C3F,0x0000,
/* 'M' */	0x018F,0xBFFD,0x78F1,0xE300,0x0000,
/* 'N' */	0x0063,0x737B,0x6F67,0x6363,0x0000,
/* 'O' */	0x01EC,0xF3CF,0x3CDE,0x0000,
/* 'P' */	0x03EC,0xF3FB,0x0C30,0x0000,
/* 'Q' */	0x00F3,0x366C,0xD9B7,0x3F00,0x0000,
/* 'R' */	0x03EC,0xF3FB,0x6CF3,0x0000,
/* 'S' */	0x01EC,0xF878,0x7CDE,0x0000,
/* 'T' */	0x03F3,0x0C30,0xC30C,0x0000,
/* 'U' */	0x033C,0xF3CF,0x3CDE,0x0000,
/* 'V' */	0x033C,0xF3CD,0xE78C,0x0000,
/* 'W' */	0x018F,0x1E3D,0x7FFB,0xE300,0x0000,
/* 'X' */	0x00C3,0x663C,0x183C,0x66C3,0x0000,
/* 'Y' */	0x00C3,0x663C,0x1818,0x1818,0x0000,
/* 'Z' */	0x01FC,0x30C3,0x0C30,0x7F00,0x0000,
/* '[' */	0x0FCC,0xCCCF,0x0000,
/* '\' */	0x00C0,0x6030,0x180C,0x0603,0x0000,
/* ']' */	0x0F33,0x333F,0x0000,
/* '^' */	0x0020,0xE36C,0x6000,0x0000,0x0000,
/* '_' */	0x0000,0x0000,0x0000,0x7C00,
/* '`' */	0xAC00,0x0000,
/* 'a' */	0x0000,0x1E0D,0xFCDF,0x0000,
/* 'b' */	0x030C,0x3ECF,0x3CFE,0x0000,
/* 'c' */	0x0000,0xFC63,0x0F00,0x0000,
/* 'd' */	0x0030,0xDFCF,0x3CDF,0x0000,
/* 'e' */	0x0000,0x1ECF,0xFC1E,0x0000,
/* 'f' */	0x01D9,0xF631,0x8C00,0x0000,
/* 'g' */	0x0000,0x1FCF,0x37C3,0x7800,
/* 'h' */	0x030C,0x3ECF,0x3CF3,0x0000,
/* 'i' */	0x186D,0xB300,
/* 'j' */	0x00C0,0x318C,0x63F0,0x0000,
/* 'k' */	0x030C,0x33DB,0xCDB3,0x0000,
/* 'l' */	0x1B6D,0xB300,
/* 'm' */	0x0000,0x076F,0xFAF1,0xE300,0x0000,
/* 'n' */	0x0000,0x03E6,0x6CD9,0xB300,0x0000,
/* 'o' */	0x0000,0x1ECF,0x3CDE,0x0000,
/* 'p' */	0x0000,0x3ECF,0x3FB0,0xC000,
/* 'q' */	0x0000,0x1FCF,0x37C3,0x0C00,
/* 'r' */	0x0000,0x3ECF,0x0C30,0x0000,
/* 's' */	0x0000,0x1EC1,0xE0FE,0x0000,
/* 't' */	0x0319,0xF631,0x8700,0x0000,
/* 'u' */	0x0000,0x33CF,0x3CDF,0x0000,
/* 'v' */	0x0000,0x33CF,0x378C,0x0000,
/* 'w' */	0x0000,0x063C,0x7AFF,0xB600,0x0000,
/* 'x' */	0x0000,0x0636,0xC71B,0x6300,0x0000,
/* 'y' */	0x0000,0x33CF,0x378C,0x3000,
/* 'z' */	0x0000,0x3F18,0xC63F,0x0000,
/* '{' */	0x0073,0x0CE0,0xC307,0x0000,
/* '|' */	0x3FFF,0x0000,
/* '}' */	0x0383,0x0C1C,0xC338,0x0000,
/* '~' */	0x00E6,0x7000,0x0000,0x0000,0x0000,
};

static const u16 NewTopaz_offset[94] = {
    0,    2,    6,   11,   15,   20,   25,   27,   30,   33,   38,   42,   44,   48,   50,   55,
   59,   62,   66,   70,   75,   79,   83,   87,   91,   95,   97,   99,  103,  107,  111,  116,
  121,  125,  129,  133,  137,  141,  145,  149,  153,  156,  160,  165,  169,  174,  179,  183,
  187,  192,  196,  200,  204,  208,  212,  217,  222,  227,  232,  235,  240,  243,  248,  252,
  254,  258,  262,  266,  270,  274,  278,  282,  286,  288,  292,  296,  298,  303,  308,  312,
  316,  320,  324,  328,  332,  336,  340,  345,  350,  354,  358,  362,  364,  368
};

static const u8 NewTopaz_width[94] = {
 2, 5, 7, 6, 7, 8, 3, 4, 4, 7, 6, 3, 6, 3, 8, 6,
 4, 6, 6, 7, 6, 6, 6, 6, 6, 2, 3, 6, 6, 6, 7, 7,
 6, 6, 6, 6, 6, 6, 6, 6, 4, 6, 7, 6, 7, 8, 6, 6,
 7, 6, 6, 6, 6, 6, 7, 8, 8, 7, 4, 8, 4, 7, 6, 2,
 6, 6, 5, 6, 6, 5, 6, 6, 3, 5, 6, 3, 7, 7, 6, 6,
 6, 6, 6, 5, 6, 6, 7, 7, 6, 6, 6, 2, 6, 7
};

NewTopaz::NewTopaz(u8 fixedWidth) : PackedFont1 (
	33,
	126,
	NewTopaz_glyphdata,
	NewTopaz_offset,
	NewTopaz_width,
	10,
	3,
	8) {
	if (fixedWidth) setFontWidth(fixedWidth);
};
