# makefile to build the complete stogram program

# python compiler
PYC = nuitka

# python interpreter
PYTHON = python3

# python flag
PYFLAG = --onefile

# source file, entry point
SRC = stogram.py

# folders and files generated during build time
BUILD = stogram.build stogram.dist stogram.onefile-build

# the target file
TARGET = stogram.bin

all: $(TARGET)

$(TARGET): $(SRC) subsystem
	$(PYTHON) -m $(PYC) $(PYFLAG) $< -o $@

.PHONY: clean clean-all subsystem

subsystem: kernel
	-$(MAKE) -C kernel

machine: machine
	-$(MAKE) -C machine

clean:
	-$(MAKE) -C kernel clean

# NOTE: recompilation time increases after using this rule
clean-all:
	-$(MAKE) -C kernel clean-all
	-rm -rf $(BUILD)
	-rm -f $(TARGET)
