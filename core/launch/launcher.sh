#!/bin/bash

# LAUNCHER
# sets up the environment for launching the stogram application
# (take it like a bootloader)

STOGRAM="stogram"
S_BIN="62696e"	# hexadecimal representation of bin
S_USR="757372"	# hexadecimal representation of usr

echo -e "Launching...\n"

export STOGRAM_ROOT=$HOME/".stogram/2f"
export STOGRAM_PATH=$STOGRAM_ROOT/${S_BIN}:$STOGRAM_ROOT/${S_USR}/$S_BIN

# load the stogram application
../stogram

echo -e "Exited"
