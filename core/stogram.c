#include <stdlib.h>
#include <string.h>

#include <term.h>

#include "window.h"
#include "stogram.h"

/**
 * main - entry point for stogram
 *
 * @argc: the argument counter
 * @argv: variable containing the list of command line arguments
 *
 * Return: always return 0
*/

int main(int __attribute__((unused))argc, char __attribute__((unused))**argv)
{
	window();
	return (0);
}

/**
 * window - handles windowing for the stogram program
 *
 * Return: return nothing
*/

void window(void)
{
	int max_y, max_x, ch, x, y;
	WINDOW *scroll_win;
	char *buffer = malloc(sizeof(char) * 1024);

	initscr();  /* initialize ncurses */
	cbreak();
	/* noecho(); */
	keypad(stdscr, TRUE);

	getmaxyx(stdscr, max_y, max_x);

	/* create a window larger than the terminal screen */
	scroll_win = init_window(max_y * 100, max_x, 0, 0);

	/* fill the window with some text */
	while (1)
	{
		getyx(scroll_win, y, x);

		mvwprintw(scroll_win, y, x, "$ ");
		wrefresh(scroll_win);

		getyx(scroll_win, y, x);
		ch = mvwgetstr(scroll_win, y, x, buffer);
		if (ch == ERR)
		{
			free(buffer);
			delwin(scroll_win);
			clean_up();
			exit(EXIT_FAILURE);
		}
		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			delwin(scroll_win);
			clean_up();
			exit(EXIT_SUCCESS);
		}
	}

	/* clean up */
	delwin(scroll_win);
	clean_up();
}
