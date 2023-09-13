#include <stdlib.h>
#include <string.h>
#include <term.h>

#include "window.h"
#include "externs.h"

/**
 * init_window - function to initialize ncurses and create a window
 *
 * @height: the heigth of the new window
 * @width: the width of the new window
 * @y: the starting position of @height
 * @x: the starting position of @width
 *
 * Return: return a pointer to the newly created window
*/

WINDOW *init_window(int height, int width, int y, int x)
{
	WINDOW *win;

	win = newwin(height, width, y, x);
	scrollok(win, TRUE);  /* enable scrolling */
	cbreak();
	keypad(win, TRUE);
	refresh();

	return (win);
}

/**
 * scroll_down - function to scroll the window by one line downward
 *
 * @win: the window to perform a down scroll on
 *
 * Return: return nothing
*/

void scroll_down(WINDOW *win)
{
	scroll(win);  /* scroll the window by one line downward */
}

/**
 * scroll_up - function to scroll the window by one line upward
 *
 * @win: the window to perform an up scroll on
 *
 * Return: return nothing
*/

void scroll_up(WINDOW *win)
{
	wscrl(win, -1);  /* scroll the window by one line upward */
}
