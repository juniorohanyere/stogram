# makefile to for the virtual filesystem

# c compiler
CC = gcc

# the c compiler flags
CFLAGS = -Wall -pedantic -Werror -Wextra -Wdeclaration-after-statement \
	 -std=gnu2x

# object files
OBJS = objs.o

TARGET = ../core/stogram

all: $(OBJS)

objs.o: objs.c objs.h
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
