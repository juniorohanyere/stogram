# makefile to build object files for the core of stogram

# c compiler
CC = gcc

# the c compiler flags
CFLAGS = -Wall -pedantic -Werror -Wextra -Wdeclaration-after-statement \
	 -std=gnu2x

LIBS = -lncurses

# object files
OBJS = stogram.o window.o

# the target file to build
TARGET = ./stogram

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

stogram.o: stogram.c stogram.h window.h
	$(CC) $(CFLAGS) -c $< -o $@

window.o: window.c window.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: mem-check clean clean-all

mem-check:
	@valgrind --leak-check=full --track-origins=yes \
	--show-leak-kinds=all $(TARGET)

clean:
	@-rm $(OBJS)

clean-all:
	@-rm *.o
