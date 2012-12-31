#include <redbus.h>
#include <console.h>

#include "test.h"

#define RB 0x0300
#define LSTREAM 47
#define SCREEN_W 80
#define SCREEN_H 50

Console* 	con;

void blit(char command, char x, char y, char xo, char yo, char w, char h) {
	con->blit_start_x = x;
	con->blit_start_y = y;
	con->blit_offset_x = xo;
	con->blit_offset_y = yo;
	con->blit_width = w;
	con->blit_height = h;
	con->blit_mode = command;
	while(con->blit_mode != 0) ; //WAI
}

void linefeed() {
	scroll(0,1,0,0,SCREEN_W,SCREEN_H-3);
	fill(0x20,0,LSTREAM,SCREEN_W,1);
}

unsigned char cursor = 0;

void print(char* buffer) {
	unsigned char i = 0;
	
	if(buffer[0] == 0) return;

	con->line = LSTREAM;

	if(cursor == 0) linefeed();

	while(buffer[i] != 0 && i < 128) {
		if(buffer[i] == '\n' || cursor == 80) {
			cursor = 0;
			linefeed();
		} else {
			con->display[cursor] = buffer[i];
			++cursor;
		}
		++i; 
	}

	if(i < 128)
		cursor = 0;
}

void init_tests() {
	rb_set_window((void*)RB);
	con = (Console*)RB;
	rb_enable();
}