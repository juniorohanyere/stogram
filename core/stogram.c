#include <string.h>
#include <stdlib.h>

#include "window.h"
#include "stogram.h"
#include "logo.h"
#include "exit.h"
#include "shell.h"
#include "syspath.h"

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
	stogram();
	return (0);
}

/**
 * window - handles windowing for the stogram program
 *
 * Return: return nothing
*/

int stogram(void)
{
	int height, width;
	WINDOW **windows = calloc(sizeof(WINDOW *), 1024);
	PANEL **panels = calloc(sizeof(PANEL *), 1024);

	/* initialize ncurses */
	initscr();
	cbreak();
	echo();
	keypad(stdscr, TRUE);
	refresh();

	getmaxyx(stdscr, height, width);

	/* create new windows */
	windows[0] = init_window(height, width, 0, 0);

	/* create panel */
	panels[0] = new_panel(windows[0]);

	logo_stg(windows[0], 4, 15);

	mvwprintw(windows[0], getcury(windows[0]), 0, "\n");
	update_panels();
	doupdate();

	commandline(windows, panels);

	/* clean up */
	clean_up(windows, panels);
	free(panels);
	free(windows);

	return (0);
}

void commandline(WINDOW **wins, PANEL **pans)
{
	char *home = getenv("HOME");

	/* set the cwd to home and keep record of it */
	strcat(home, "/");
	strcat(home, SYSROOT);
	strcat(home, "/");
	strcat(home, HOME);
	setenv("_PWD", home, 1);

	shell(wins, pans);
	update_panels();
	doupdate();
	/* wait for user input */

	free(home);
}
