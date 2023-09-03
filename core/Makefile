# makefile to build object files for the core of stogram

# c compiler
CC = gcc

# the c compiler flags
CFLAGS = -Wall -pedantic -Werror -Wextra -Wdeclaration-after-statement \
	 -std=gnu2x -I../interpreter

LIBS = -lpanel -lncurses

# object files
OBJS = array.o exit.o keyboard.o logo.o stogram.o window.o

# the target file to build
TARGET = ./stogram

all: $(OBJS)

array.o: array.c array.h
	$(CC) $(CFLAGS) -c $< -o $@

exit.o: exit.c exit.h
	$(CC) $(CFLAGS) -c $< -o $@

keyboard.o: keyboard.c array.h exit.h keyboard.h window.h
	$(CC) $(CFLAGS) -c $< -o $@

logo.o: logo.c logo.h
	$(CC) $(CFLAGS) -c $< -o $@

stogram.o: stogram.c ../interpreter/shell.h exit.h logo.h stogram.h window.h
	$(CC) $(CFLAGS) -c $< -o $@

window.o: window.c window.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean clean-all mem-check run

mem-check:
	@-valgrind --leak-check=full --track-origins=yes \
	--show-leak-kinds=all $(TARGET)
run:
	@./$(TARGET)

clean:
	@-rm $(OBJS)

clean-all:
	@-rm *.o
