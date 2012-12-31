//irc_client.c

#include <redbus.h>
#include <console.h>
#include <disk.h>

#define RB 0x0300

Console* 	con;
Disk*		dis;

#define DSTAT 32
#define DOUT  31
#define DIN   30

		
#define LPROMPT 49
#define LSTAT	48
#define LSTREAM 47

#define SCREEN_W 80
#define SCREEN_H 50

#define map_con() rb_map_device(0x01);
#define map_dis() rb_map_device(0x02);

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

#define LF 	13

void prepare_screen() {
	map_con();
	fill(0x20,0,0,SCREEN_W,SCREEN_H);
	invert(0,LSTAT,SCREEN_W,1);
	con->cursor_x = 0;
	con->cursor_y = LPROMPT;
	con->cursor_mode = 2;
}

char send = 0;
char recv = 0;
char outbuf[128];
char inbuf[128];

#define CONTROL 0
#define READPTR 1
#define WRITEPTR 2

unsigned char flush() {
	dis->command = WRITE; 
	while(dis->command != IDLE && dis->command != FAIL) ;
	return dis->command;
}

unsigned char wait() {
	dis->command = READ; 
	while(dis->command != IDLE && dis->command != FAIL) ;
	return dis->command;
}

void prepare_disk() {
	map_dis();
	dis->sector_num = DSTAT;
	dis->sector[CONTROL] = 'N';
	flush();
}

unsigned char cursor = 0;

void linefeed() {
	scroll(0,1,0,0,SCREEN_W,SCREEN_H-3);
	fill(0x20,0,LSTREAM,SCREEN_W,1);
}

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

void read_keyboard() {
	con->line = LPROMPT;
	while(con->kb_pos != con->kb_start) {
		outbuf[con->cursor_x] = con->kb_key;
		if(con->kb_key == LF) {
			outbuf[con->cursor_x+1] = 0;
			fill(0x20,0,LPROMPT,SCREEN_W,1);
			send = 1;
			con->cursor_x = 0;
			++con->kb_start;
			break;
		}
		con->display[con->cursor_x] = con->kb_key;
		++con->cursor_x;
		++con->kb_start;
	}
}

void perform_io() {
	unsigned int i = 0;

	map_dis();

	i = 0;
	dis->sector_num = DIN;
	wait();
	while(dis->sector[i] != 0 && i < 128) {
		inbuf[i] = dis->sector[i];
		dis->sector[i] = 0;
		++i;
	}
	inbuf[i] = 0;

	flush();

	i = 0;

	dis->sector_num = DOUT;
	if(send == 1) {
		while(outbuf[i] != 0 && i < 128) {
			dis->sector[i] = outbuf[i];
			++i;
		}
		//send = 0;
	} else dis->sector[i] == 0;
	if(!flush() && send == 1) send = 0;

	map_con();
}

void main() {

	rb_set_window((void*)RB);
	con = (Console*)RB;
	dis = (Disk*)RB;
	rb_enable();

	prepare_screen();

	print("IRC for RPC8/e\nInitializing IO buffer space... ");

	prepare_disk();

	map_con();

	print("[DONE]\nStarting IO loop.");

	while(1) {
		read_keyboard();
		perform_io();
		print(inbuf);
		inbuf[0] = 0;
	}
}