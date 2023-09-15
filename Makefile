CC = gcc
CFLAGS = -Wno-discarded-qualifiers

MAIN_SRC = strace.c
<<<<<<< HEAD
FUNCTIONS_SRC = Propen.c
HELPER_SRC = console_writer_helper.c
=======
FUNCTIONS_SRC = src/Propen.c
HELPER_SRC = src/console_writer_helper.c
>>>>>>> 8565ea9 (Modify the repo and make it more clean)

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
<<<<<<< HEAD
	$(CC) -c $< -o $@
=======
	$(CC) -c -Wno-implicit-function-declaration $< -o $@
>>>>>>> 8565ea9 (Modify the repo and make it more clean)

$(INTER_OBJ):$(FUNCTIONS_SRC)
	$(CC) -c $< -o $@

<<<<<<< HEAD
clean:
	rm -f $(TARGET) $(MAIN_OBJ) $(HELPER_OBJ) $(INTER_OBJ)
<<<<<<< HEAD
=======
=======
test:
	nasm -felf64 -o $(TEST_OBJ) $(TEST_SRC)
	ld $(TEST_OBJ) -o $(TEST)
	./$(TARGET) ./$(TEST)

clean:
	rm -f $(TARGET) $(MAIN_OBJ) $(HELPER_OBJ) $(INTER_OBJ) $(TEST) $(TEST_OBJ)
>>>>>>> 455a26f (update)

>>>>>>> 8565ea9 (Modify the repo and make it more clean)
