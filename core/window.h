#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

WINDOW *init_window(int height, int width, int y, int x);
void scroll_down(WINDOW *win);
void scroll_up(WINDOW *win);
void clean_up(void);

#endif	/* WINDOW_H */
