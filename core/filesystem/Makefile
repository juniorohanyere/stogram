# makefile to for the virtual filesystem

# c compiler
CC = gcc

# the c compiler flags
CFLAGS = -I.. -I../../interpreter -Wall -pedantic -Werror -Wextra -Wdeclaration-after-statement \
	 -std=gnu2x

# object files
OBJS = changedir.o executables.o listdir.o syspath.o

TARGET = ../core/stogram

all: $(OBJS)

changedir.o: changedir.c ../array.h ../externs.h changedir.h syspath.h
	$(CC) $(CFLAGS) -c $< -o $@

executables.o: executables.c ../externs.h ../../interpreter/convert.h \
	       executables.h syspath.h
	$(CC) $(CFLAGS) -c $< -o $@

listdir.o: listdir.c ../externs.h listdir.h
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
