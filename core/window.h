#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include <panel.h>

WINDOW *init_window(int height, int width, int y, int x);
void scroll_down(WINDOW *win);
void scroll_up(WINDOW *win);

#endif	/* WINDOW_H */
