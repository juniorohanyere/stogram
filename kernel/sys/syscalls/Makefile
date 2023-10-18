# makefile to for the virtual filesystem

# c compiler
CC = gcc

# the c compiler flags
CFLAGS = -I.. -I../../core -pedantic -std=gnu2x -Wall \
	 -Wdeclaration-after-statement -Werror -Wextra

# object files
OBJS = syscall.o

TARGET = ../core/stogram

all: $(OBJS)

syscall.o: syscall.c ../../core/externs.h ../../core/convert.h ../../core/routine.h \
	   syscall.h ../syspath.h
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
