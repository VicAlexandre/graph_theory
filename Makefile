CC = gcc
CFLAGS = -O2 -Wall 
LDFLAGS = -Lgraph_lib/obj -lgraph

.PHONY: all lib examples clean lib_clean

all: lib examples

lib:
	cd graph_lib && $(MAKE)

examples:
	cd examples && $(MAKE) && make dfs

clean: lib_clean
	cd examples && $(MAKE) clean

lib_clean:
	cd graph_lib && $(MAKE) clean