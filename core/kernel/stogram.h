#ifndef STOGRAM_H
#define STOGRAM_H

#define BUFFER_SIZE 1024

#include <ncurses.h>
#include <panel.h>

WINDOW **wins;
PANEL **pans;

int launch(void);
int stogram(void);

#endif	/* STOGRAM_H */
