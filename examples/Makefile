CC = gcc
CFLAGS = -O2 -Wall  -I../graph_lib/include
LDFLAGS = -L../graph_lib/obj -lgraph
TARGET_SRC = test.c
TARGET_EXE = $(basename $(TARGET_SRC))

all: $(TARGET_EXE)

$(TARGET_EXE): $(TARGET_SRC)
	$(CC) $(TARGET_SRC) -o ../$(TARGET_EXE) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET_EXE)