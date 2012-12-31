//console.h

// 0x00 Memory access row. Used to set which line of characters appears in the display memory window.
 
// 0x01 cursor x
// 0x02 cursor y
// 0x03 cursor mode (0: hidden, 1: solid, 2: blink)
 
// 0x04 key buffer start (16 byte buffer)
// 0x05 key buffer position
// 0x06 key value at buffer start
 
// 0x07 blit mode (1: fill, 2: invert; 3: shift)
// 0x08 blit x start / fill value
// 0x09 blit y start
// 0x0A blit x offset
// 0x0B blit y offset
// 0x0C blit width
// 0x0D blit height
 
// 0x10 -> 0x60 display memory window

typedef struct Console {
	char line;
	char cursor_x;
	char cursor_y;
	char cursor_mode;

	char kb_start;
	char kb_pos;
	char kb_key;

	char blit_mode;
	char blit_start_x;
	char blit_start_y;
	char blit_offset_x;
	char blit_offset_y;
	char blit_width;
	char blit_height;

	unsigned int padding; 

	char display[0x50];
} Console;

//character with inverted colors
#define inv(c) ((c) | 0x80)

//void blit(char command, char x, char y, char xo, char yo, char w, char h);

#define fill(b, x, y, w, h) 		blit(1, b, 0, x, y, w, h)
#define invert(x, y, w, h) 			blit(2, 0, 0, x, y, w, h)
#define scroll(x, y, ox, oy, w, h) 	blit(3, x, y, ox, oy, w, h)


