CC  = clang
CFLAGS = -Wall -Wextra -Iinclude
AR = ar
ARFLAGS = rcs
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

SLIB = $(LIB_DIR)/ds_lib.a
DLIB = $(LIB_DIR)/ds_lib.so
TARGET = testbench.out

all: $(DLIB) $(SLIB) $(TARGET)

.PHONY: all

$(DLIB): $(OBJS)
	@mkdir -p $(LIB_DIR)
	$(CC) -shared -fPIC $^ -o $@

$(SLIB): $(OBJS)
	@mkdir -p $(LIB_DIR)
	$(AR) $(ARFLAGS) $@ $^

$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) -r $(OBJ_DIR) $(LIB_DIR) $(TARGET)
