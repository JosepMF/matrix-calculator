CC = gcc
CFLAGS = -Wall -Wextra -Ilib

APP_DIR = app
LIB_DIR = lib
OBJ_DIR = build

APP_SRC = $(wildcard $(APP_DIR)/*.c)
LIB_SRC = $(wildcard $(LIB_DIR)/*.c)

APP_OBJ = $(patsubst $(APP_DIR)/%.c, $(OBJ_DIR)/%.o,$(APP_SRC))
LIB_OBJ = $(patsubst $(LIB_DIR)/%.c,$(OBJ_DIR)/%.o,$(LIB_SRC))

TARGET = xmatrixcalc
STATIC_LIB = $(OBJ_DIR)/matrixlib.a

all: $(TARGET)

$(TARGET): $(STATIC_LIB) $(APP_OBJ)
	$(CC) $(APP_OBJ) $(STATIC_LIB) -o $@

$(STATIC_LIB): $(LIB_OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(APP_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

rebuild: clean all
