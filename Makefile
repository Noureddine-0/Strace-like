CC = gcc
CFLAGS = -Wno-discarded-qualifiers

MAIN_SRC = strace.c

HELPER_SRC = console_writer_helper.c
SYSCALL_TRACER_SRC = src/syscall_tracer.c
FUNCTIONS_SRC = src/Prbrk.c
HELPER_SRC = src/console_writer_helper.c


OBJ_DIR = obj
MAIN_OBJ = $(OBJ_DIR)/main.o
HELPER_OBJ = $(OBJ_DIR)/helper.o
SYSCALL_TRACER_OBJ = $(OBJ_DIR)/syscall_tracer.o
INTER_OBJ =  $(OBJ_DIR)/inter.o

TARGET = emutrace

all:$(TARGET)

$(TARGET):$(MAIN_OBJ) $(HELPER_OBJ) $(INTER_OBJ) $(SYSCALL_TRACER_OBJ)
	$(CC) -o $@ $^

$(MAIN_OBJ):$(MAIN_SRC)
	$(CC)  $(CFLAGS) -c $< -o $@

$(HELPER_OBJ):$(HELPER_SRC)
	$(CC) -c -Wno-implicit-function-declaration $< -o $@

$(INTER_OBJ):$(FUNCTIONS_SRC)
	$(CC) -c $< -o $@

$(SYSCALL_TRACER_OBJ):$(SYSCALL_TRACER_SRC)
	$(CC) $(CFLAGS) -o $@ -c $^



clean:
	rm -f $(TARGET) $(MAIN_OBJ) $(HELPER_OBJ) $(INTER_OBJ) $(SYSCALL_TRACER_OBJ)
