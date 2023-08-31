# generates the stogram binary file

CC = gcc

CFALGS = -Wall -Werror -Wextra -pedantic -std=gnu89

PY = python3

SRCS = stogram.c error.c parser.c read_file.c stack.c

INCLUDES = error.h parser.h read_file.h stack.h stogram.h

TARGET = stogram

$(TARGET): all

all: $(CC) -


