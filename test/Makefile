LD = ../bin/ld65
AS = ../bin/ca65
CC = ../bin/cc65
AL = ../bin/align

CINCLUDE = -I../include
CFLAGS = -t none --cpu $(CPU)
LFLAGS = -C ../lib/rpc8e.cfg
LLIBS  = ../lib/rpc8e.lib

#gonna leave this here for now
CPU = 65c02 


IMAGES = test_rb.img test_stdlib.img 

.PHONY: all

all: $(IMAGES)

%.s: %.c
	$(CC) $(CFLAGS) $(CINCLUDE) $<

%.o: %.s
	$(AS) $(CFLAGS) $<

%.img: %.o test.o
	$(LD) $(LFLAGS) $< test.o $(LLIBS) -o $@
	$(AL) $@


clean:
	rm  *.o *.s

.SUFFIXES: