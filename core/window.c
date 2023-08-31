#include <ncurses.h>

/**
 * window - creates a window
 *
 * Description: this function uses the ncurses library to create a new window
 *		rather than relying on the usual shell view, the screen is
 *		cleared to imply that the stogram program has begun!
 *
 * Return: return nothing
*/

void window(void)
{
	initscr();

	printw("The stogram program has begun!, see it in action\n");
	getch();

	refresh();
	endwin();
}
