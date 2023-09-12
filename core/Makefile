# makefile to build object files for the core of stogram

# c compiler
CC = gcc

# the c compiler flags
CFLAGS = -I../interpreter -Ifilesystem -pedantic -std=gnu2x -Wall \
	 -Wdeclaration-after-statement -Werror -Wextra

LIBS = -lpanel -lncurses

# object files
OBJS = array.o error.o exit.o keyboard.o logo.o stogram.o window.o

# the target file to build
TARGET = ./stogram

all: $(OBJS)

array.o: array.c array.h externs.h
	$(CC) $(CFLAGS) -c $< -o $@

error.o: error.c error.h
	$(CC) $(CFLAGS) -c $< -o $@

exit.o: exit.c exit.h externs.h
	$(CC) $(CFLAGS) -c $< -o $@

keyboard.o: keyboard.c array.h exit.h externs.h keyboard.h keymapper.h window.h
	$(CC) $(CFLAGS) -c $< -o $@

logo.o: logo.c externs.h logo.h
	$(CC) $(CFLAGS) -c $< -o $@

stogram.o: stogram.c ../interpreter/shell.h exit.h logo.h stogram.h \
	   filesystem/syspath.h window.h
	$(CC) $(CFLAGS) -c $< -o $@

window.o: window.c externs.h window.h
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
