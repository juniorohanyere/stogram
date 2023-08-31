#include <ncurses.h>
#include <stdlib.h>

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
	char *str;

	str = malloc(sizeof(char) * 1024);

	initscr();

	printw("The stogram program has begun!, see it in action\n");
	getstr(str);

	printw("%s\nPress any key to exit", str);
	getch();
	free(str);
	refresh();
	endwin();
}
