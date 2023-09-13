# makefile to for the virtual filesystem

# c compiler
CC = gcc

# the c compiler flags
CFLAGS = -pedantic -std=gnu2x -Wall -Wdeclaration-after-statement -Werror \
	 -Wextra

# object files
OBJS = syspath.o

TARGET = ../launch/run

all: $(OBJS)

syspath.o: syspath.c syspath.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean clean-all run

run:
	@-valgrind --leak-check=full --track-origins=yes \
	--show-leak-kinds=all ./$(TARGET)

clean:
	@-rm -f $(OBJS)

clean-all:
	@-rm -f *.o ./$(TARGET)
