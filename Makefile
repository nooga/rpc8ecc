CC = bin/cc65
AS = bin/ca65
LD = bin/ld65
export CPU = 65c02

.PHONY: all
all: lib test

.PHONY: test
test:
	make -C test/

.PHONY: lib
lib:
	make -C lib/