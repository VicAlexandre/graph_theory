CC = gcc
CFLAGS = -Wall -O2 
AR = ar
LIB_NAME = obj/libgraph.a

SRC_DIR = src
OBJ_DIR = obj

OBJS = $(OBJ_DIR)/graph.o

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	$(AR) rcs $(LIB_NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(LIB_NAME)