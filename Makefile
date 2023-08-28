CC = gcc
CFLAGS = -O2 -Wall 
LDFLAGS = -Lgraph_lib/obj -lgraph


test: test.c
	${CC} test.c -o test ${CFLAGS} $(LDFLAGS)

clean:
	rm -f test

lib: 
	cd graph_lib && make 

lib_clean:
	cd graph_lib && make clean