# makefile to build object files for the shell and/or
# interpreter of stogram

# c compiler
CC = gcc

# the c compiler flags
CFLAGS = -I../core -I../core/filesystem -pedantic -std=gnu2x -Wall \
	 -Wdeclaration-after-statement -Werror -Wextra

LIBS = -lpanel -lncurses

# object files
OBJS = convert_to_hex.o parser.o shell.o

all: $(OBJS)

convert_to_hex.o: convert_to_hex.c ../core/error.h ../core/exit.h \
		  ../core/stogram.h convert_to_hex.h
	$(CC) $(CFLAGS) -c $< -o $@

parser.o: parser.c ../core/exit.h ../core/exit.h ../core/stogram.h parser.h
	$(CC) $(CFLAGS) -c $< -o $@

shell.o: shell.c ../core/exit.h ../core/filesystem/executables.h \
	 ../core/keyboard.h ../core/stogram.h parser.h shell.h
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
