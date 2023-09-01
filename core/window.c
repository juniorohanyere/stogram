#include <stdlib.h>
#include <string.h>

#include <ncurses.h>
#include <term.h>

/**
 * init_window - function to initialize ncurses and create a window
 *
 * @height: the heigth of the new window
 * @width: the width of the new window
 * @y: the starting point of @height
 * @the starting point of @width
 *
 * Return: return a pointer to the newly created window
*/

WINDOW *init_window(int height, int width, int starty, int startx)
{
	WINDOW *win;

	win = newwin(height, width, starty, startx);
	scrollok(win, TRUE);  /* enable scrolling */

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

/**
 * clean_up - makes a final memory allocation clean up
 *
 * Description: note that this function does not free all memory. Hence proper
 *		handling of other frees not defined her is necessary. This
 *		function ends aims at easing the strain of having to free up
 *		some constant or global variables
 *
 * Return: return nothing
*/

void clean_up(void)
{
	endwin();
	del_curterm(cur_term);
	delwin(stdscr);
	delwin(curscr);
	delwin(newscr);
}
