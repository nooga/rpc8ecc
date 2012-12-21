LD = ../bin/ld65
AS = ../bin/ca65
CC = ../bin/cc65
AL = ../bin/align

CINCLUDE = -I ../include
CFLAGS = -t none --cpu $(CPU)
LFLAGS = -C ../lib/rpc8e.cfg
LLIBS  = ../lib/rpc8e.lib

IMAGES = test_rb.img irc_client.img

.PHONY: all
all: $(IMAGES)

%.s: %.c
	$(CC) $(CFLAGS) $(CINCLUDE) $<

%.o: %.s
	$(AS) $(CFLAGS) $<

%.img: %.o
	$(LD) $(LFLAGS) $< $(LLIBS) -o $@
	$(AL) $@





clean:
	rm  *.o

.SUFFIXES: