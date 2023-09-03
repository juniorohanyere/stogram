#ifndef KEYBOARD_H
#define KEYBOARD_H

#define TRUE 1

#include <ncurses.h>
#include <panel.h>

int _getline(WINDOW **wins, unsigned int w, PANEL **pans, unsigned int p,
	char *buffer);
int new_line(WINDOW **wins, unsigned int w, PANEL **pans, unsigned int p,
	char *buffer);

#endif	/* KEYBOARD_H */
