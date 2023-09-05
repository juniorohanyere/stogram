# makefile to for the virtual filesystem

# c compiler
CC = gcc

# the c compiler flags
CFLAGS = -Wall -pedantic -Werror -Wextra -Wdeclaration-after-statement \
	 -std=gnu2x

# object files
OBJS = executables.o listdir.o syscmd.o syspath.o

TARGET = ../core/stogram

all: $(OBJS)

executables.o: executables.c executables.h syspath.h
	$(CC) $(CFLAGS) -c $< -o $@

listdir.o: listdir.c listdir.h
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
	@-rm -f $(OBJS)

clean-all:
	@-rm -f *.o
