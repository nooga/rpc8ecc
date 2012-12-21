//disk.h

// 0x00-0x7F: Disk sector buffer
// 0x80-0x81: Sector number
// 0x82: Disk command:
//  0: Idle/success
//  1: Read Disk Name
//  2: Write Disk Name
//  3: Read Disk Serial
//  4: Read Disk Sector
//  5: Write Disk Sector
//  0xFF: Command failure

typedef enum {
	IDLE 	  	= 0,
	READ_NAME 	= 1,
	WRITE_NAME 	= 2,
	READ_SERIAL = 3,
	READ 		= 4,
	WRITE 		= 5,
	FAIL 		= 0xFF 
} DiskCommand;

typedef struct Disk {
	char sector[0x80];
	unsigned int sector_num;
	DiskCommand command;
} Disk;

