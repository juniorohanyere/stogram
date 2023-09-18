#ifndef KEYBOARD_H
#define KEYBOARD_H

#define TRUE 1

#include <ncurses.h>

int _getline(WINDOW *win, char *buffer);
int new_line(char *buffer);

#endif	/* KEYBOARD_H */
