CC = gcc

CFLAGS = -Wall -pedantic -Werror -Wextra -std=gnu18

OBJS = \

TARGET = stogram

all: subsystem $(TARGET)

$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

subsystem:
	-$(MAKE) -C core

obj: deps.h
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean clean-all

clean:
	@-rm $(OBJS)

clean-all:
	@-rm *.o
