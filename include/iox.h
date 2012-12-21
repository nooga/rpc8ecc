// iox.h


// device struct

typedef struct Iox {
	unsigned int in;
	unsigned int out;
} Iox;

// Bit   Dec     Hex  Color
//  0      1     0x1  White
//  1      2     0x2  Orange
//  2      4     0x4  Magenta
//  3      8     0x8  Light Blue
//  4     16    0x10  Yellow
//  5     32    0x20  Lime
//  6     64    0x40  Pink
//  7    128    0x80  Gray
//  8    256   0x100  Light Gray
//  9    512   0x200  Cyan
// 10   1024   0x400  Purple
// 11   2048   0x800  Blue
// 12   4096  0x1000  Brown
// 13   8192  0x2000  Green
// 14  16384  0x4000  Red
// 15  32768  0x8000  Black

typedef enum {
	WHITE 	= 0x0001,
	ORANGE 	= 0x0002,
	MAGENTA = 0x0004,
	LBLUE	= 0x0008,
	YELLOW 	= 0x0010,
	LIME 	= 0x0020,
	PINK 	= 0x0040,
	GRAY    = 0x0080,
	LGRAY   = 0x0100,
	CYAN 	= 0x0200,
	PURPLE 	= 0x0400,
	BLUE 	= 0x0800,
	BROWN 	= 0x1000,
	GREEN 	= 0x2000,
	RED 	= 0x4000,
	BLACK 	= 0x8000
} WireColor;