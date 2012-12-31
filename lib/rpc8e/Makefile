#
# makefile for CC65 runtime library
#

.SUFFIXES: .o .s .c

#--------------------------------------------------------------------------
# Programs and flags

SYS	= none

AS	= ../../bin/ca65
CC	= ../../bin/cc65
LD	= ../../bin/ld65

AFLAGS	= -t $(SYS) --forget-inc-paths -I../asminc --cpu $(CPU)
CFLAGS	= -Osir -g -T -t $(SYS) --forget-inc-paths -I . -I ../../include --cpu $(CPU)

#--------------------------------------------------------------------------
# Rules

.c.s:
	@$(CC) $(CFLAGS) $<

.s.o:
	@$(AS) -g -o $@ $(AFLAGS) $<

#--------------------------------------------------------------------------
# Object files

OBJS = 	crt0.o \
		redbus.o \
		ctype.o

#COBJS = console.o

#--------------------------------------------------------------------------
# Targets

.PHONY:	all clean zap

all:   	$(OBJS) $(COBJS)

clean:
	@$(RM) *~ $(COBJS:.o=.s) $(OBJS)

zap:	clean

