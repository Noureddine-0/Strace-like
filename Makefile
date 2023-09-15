CC = gcc
CFLAGS = -Wno-discarded-qualifiers

MAIN_SRC = strace.c

HELPER_SRC = console_writer_helper.c
FUNCTIONS_SRC = src/Prexit.c
HELPER_SRC = src/console_writer_helper.c


OBJ_DIR = obj
MAIN_OBJ = $(OBJ_DIR)/main.o
HELPER_OBJ = $(OBJ_DIR)/helper.o
INTER_OBJ =  $(OBJ_DIR)/inter.o

TEST_SRC = test.asm
TEST_OBJ = test.o
TEST = test

TARGET = my_program

all:$(TARGET)

$(TARGET):$(MAIN_OBJ) $(HELPER_OBJ) $(INTER_OBJ)
	$(CC) -o $@ $^

$(MAIN_OBJ):$(MAIN_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(HELPER_OBJ):$(HELPER_SRC)
	$(CC) -c -Wno-implicit-function-declaration $< -o $@

$(INTER_OBJ):$(FUNCTIONS_SRC)
	$(CC) -c $< -o $@


test:
	nasm -felf64 -o $(TEST_OBJ) $(TEST_SRC)
	ld $(TEST_OBJ) -o $(TEST)
	./$(TARGET) ./$(TEST)

clean:
	rm -f $(TARGET) $(MAIN_OBJ) $(HELPER_OBJ) $(INTER_OBJ) $(TEST) $(TEST_OBJ)
