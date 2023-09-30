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

pcb.o: pcb.c child.h indicator.h pcb.h
	$(CC) $(CFLAGS) -c $< -o $@

skernel.o: skernel.c fdt.h indicator.h pcb.h skernel.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean clean-all

clean:
	@-rm -f $(OBJS)

clean-all:
	@-rm -f *.o $(TARGET)
