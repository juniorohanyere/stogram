# makefile to for the stogram kernel
# SKERNEL
# builds a kernel as a shared library

# c compiler
CC = gcc

# the c compiler flags
CFLAGS = -I../core -pedantic -std=gnu2x -Wall -Wdeclaration-after-statement \
	 -Werror -Wextra

# object files
OBJS = child.o fdt.o pcb.o skernel.o

TARGET = skernel

all: $(OBJS)

child.o: child.c child.h pcb.h
	$(CC) $(CFLAGS) -c $< -o $@

fdt.o: fdt.c fdt.h
	$(CC) $(CFLAGS) -c $< -o $@

pcb.o: pcb.c child.h fdt.h fdtp.h indicator.h pcb.h
	$(CC) $(CFLAGS) -c $< -o $@

skernel.o: skernel.c fdt.h indicator.h pcb.h skernel.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean clean-all test

test: tests/test.c
	@$(CC) $< $(OBJS) -o $@
	@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all \
	./$@
	@./$@
	@echo "\nOK"
clean:
	@-rm -f $(OBJS)

clean-all:
	@-rm -f *.o $(TARGET)
