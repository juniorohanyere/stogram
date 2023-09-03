#ifndef SHELL_H
#define SHELL_H

#include <ncurses.h>
#include <panel.h>

void prompt(WINDOW **wins, unsigned int w);
int shell(WINDOW **wins, PANEL **pans);

#endif	/* SHELL_H */
