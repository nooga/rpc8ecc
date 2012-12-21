//test_rb.c

#include <redbus.h>
#include <console.h>

#define redbus 0x0300
#define default_console_id 0x01

void main() {
	Console* console;

	rb_set_window((void*)redbus);
	rb_map_device(default_console_id);
	rb_enable();

	
	console = (Console*)redbus;

	console->cursor_mode = 2;
	console->display[0] = 'X';
	console->display[1] = inv('Y');
}