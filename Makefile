CC = gcc
CFLAGS = -O2 -Wall 
LDFLAGS = -Lgraph_lib/obj -lgraph


test: test.c
	cd graph_lib && mkdir -p obj && make 
	${CC} test.c -o test ${CFLAGS} $(LDFLAGS)

clean:
	rm -f test && make lib_clean

lib_clean:
	cd graph_lib && make clean