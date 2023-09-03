# makefile to build object files for the shell and/or
# interpreter of stogram

# c compiler
CC = gcc

# the c compiler flags
CFLAGS = -Wall -pedantic -Werror -Wextra -Wdeclaration-after-statement \
	 -std=gnu2x -I../core

LIBS = -lpanel -lncurses

# object files
OBJS = shell.o

all: $(OBJS)

shell.o: shell.c ../core/keyboard.h ../core/stogram.h shell.h
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
