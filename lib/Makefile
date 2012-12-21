AR = ../bin/ar65
export CPU = 65c02


#.PHONY: all
all: rpc8e.lib

rpc8e.lib: runtime common rpc8e
	rm -f rpc8e.lib
	$(AR) a rpc8e.lib runtime/*.o rpc8e/*.o common/*.o

.PHONY: runtime rpc8e common

rpc8e:
	make -C rpc8e/

runtime:
	make -C runtime/

common:
	make -C common/