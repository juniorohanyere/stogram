# makefile to build the complete stogram program

# c compiler
CC = gcc

LIBS = -lpanel -lncurses

# object files
OBJS = core/*.o core/sys/*.o interpreter/*.o

TARGET = core/stogram

all: $(TARGET)

$(TARGET): subsystem
	$(CC) $(OBJS) $(LIBS) -o $@

subsystem:
	-$(MAKE) -C core
	-$(MAKE) -C core/sys
	-$(MAKE) -C interpreter

.PHONY: clean clean-all mem-check run

mem-check:
	@-valgrind --leak-check=full --track-origins=yes \
	--show-leak-kinds=all $(TARGET)
run:
	@./$(TARGET)

clean:
	-$(MAKE) -C core clean
	-$(MAKE) -C core/filesystem clean
	-$(MAKE) -C interpreter clean

clean-all:
	-$(MAKE) -C core clean-all
	-$(MAKE) -C core/filesystem clean-all
	-$(MAKE) -C interpreter clean-all
	@-rm $(TARGET)
