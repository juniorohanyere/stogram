#ifndef STOGRAM_H
#define STOGRAM_H

#define BUFFER_SIZE 1024

#include <ncurses.h>
#include <panel.h>

int stogram(void);
void commandline(WINDOW **wins, PANEL **pans);

#endif	/* STOGRAM_H */
