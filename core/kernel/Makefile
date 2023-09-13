# makefile to build object files for the core of stogram

# c compiler
CC = gcc

# the c compiler flags
CFLAGS = -I../interpreter -Ifilesystem -I../sys/syscalls -pedantic -std=gnu2x \
	 -Wall -Wdeclaration-after-statement -Werror -Wextra

LIBS = -lpanel -lncurses

# object files
OBJS = array.o command_line.o convert.o error.o exit.o keyboard.o logo.o \
       parser.o stogram.o window.o

# the target file to build
TARGET = ../launch/run

all: $(OBJS)

array.o: array.c array.h externs.h
	$(CC) $(CFLAGS) -c $< -o $@

command_line.o: command_line.c ../sys/syscalls/syscall.h command_line.h \
		convert.h error.h exit.h externs.h keyboard.h parser.h
	$(CC) $(CFLAGS) -c $< -o $@

convert.o: convert.c convert.h error.h exit.h externs.h
	$(CC) $(CFLAGS) -c $< -o $@

error.o: error.c error.h
	$(CC) $(CFLAGS) -c $< -o $@

exit.o: exit.c exit.h externs.h
	$(CC) $(CFLAGS) -c $< -o $@

keyboard.o: keyboard.c array.h exit.h externs.h keyboard.h keymapper.h window.h
	$(CC) $(CFLAGS) -c $< -o $@

logo.o: logo.c externs.h logo.h
	$(CC) $(CFLAGS) -c $< -o $@

parser.o: parser.c error.h exit.h externs.h parser.h
	$(CC) $(CFLAGS) -c $< -o $@

stogram.o: stogram.c ../sys/syspath.h command_line.h exit.h logo.h stogram.h \
	   window.h
	$(CC) $(CFLAGS) -c $< -o $@

window.o: window.c externs.h window.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean clean-all run

run:
	@-valgrind --leak-check=full --track-origins=yes \
	--show-leak-kinds=all ./$(TARGET)

clean:
	@-rm $(OBJS)

clean-all:
	@-rm *.o
