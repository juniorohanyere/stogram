#ifndef EXIT_H
#define EXIT_H

#include <ncurses.h>
#include <panel.h>

int exit_st(WINDOW **wins, unsigned int w, PANEL **pans, unsigned int p,
	char *buffer);
void clean_up(WINDOW **wins, PANEL **pans);

#endif	/* EXIT_H */
