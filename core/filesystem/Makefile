# makefile to for the virtual filesystem

# c compiler
CC = gcc

# the c compiler flags
CFLAGS = -Wall -pedantic -Werror -Wextra -Wdeclaration-after-statement \
	 -std=gnu2x

# object files
OBJS = executables.o syscmd.o syspath.o

TARGET = ../core/stogram

all: $(OBJS)

executables.o: executables.c executables.h syspath.h
	$(CC) $(CFLAGS) -c $< -o $@

syscmd.o: syscmd.c syscmd.h
	$(CC) $(CFLAGS) -c $< -o $@

syspath.o: syspath.c syspath.h
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
