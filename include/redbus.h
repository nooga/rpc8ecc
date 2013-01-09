// redbus.h

void rb_enable(void);
void rb_disable(void);
void rb_disable_ext(void);
void __fastcall__ rb_set_window(void* address);
void __fastcall__ rb_set_window_ext(void* address);
void __fastcall__ rb_map_device(unsigned char id);
void rb_enable_ext(void);


// 0x00 Map device in Reg A to redbus window.
// 0x80 Get mapped device to A.

// 0x01 Redbus Window offset to A
// 0x81 Get RB window offset to A.

// 0x02 Enable redbus
// 0x82 Disable redbus

// 0x03 Set external memory mapped window to A.
// 0x83 Get memory mapped window to A.

// 0x04 Enable external memory mapped window.
// 0x84 Disable external memory mapped window.

// 0x05 Set BRK address to A
// 0x85 Get BRK address to A

// 0x06 Set POR address to A
// 0x86 Get POR address to A

// 0xFF Output A register to MC logfile.

