CC = gcc
CFLAGS = -Wall -O2 -I./include
AR = ar
LIB_NAME = obj/libgraph.a

SRC_DIR = src
OBJ_DIR = obj

OBJS = $(OBJ_DIR)/graph.o

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	$(AR) rcs $(LIB_NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(LIB_NAME)
	-rmdir $(OBJ_DIR) 