#!/usr/bin/env bash

export LD_LIBRARY_PATH=/home/twinj/juniorohanyere/stogram/core:$LD_LIBRARY_PATH

valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./test

./test
