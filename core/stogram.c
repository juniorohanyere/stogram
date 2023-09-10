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
 * Return: return status of the called function
*/

int main(int __attribute__((unused))argc, char __attribute__((unused))**argv)
{
	int status;

	status = stogram();
	return (status);
}

/**
 * stogram - handles windowing and other stuff for the stogram program before
 *	     transferring control to the main function
 *
 * Return: return the status of the called function(s)
*/

int stogram(void)
{
	int height, width, status;
	WINDOW **windows = calloc(sizeof(WINDOW *), BUFFER_SIZE);
	PANEL **panels = calloc(sizeof(PANEL *), BUFFER_SIZE);

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

	/* logo_stg(windows[0], 4, 15); */

	wprintw(windows[0], "\n");
	update_panels();
	doupdate();

	status = commandline(windows, panels);

	/* clean up */
	clean_up(windows, panels);
	free(panels);
	free(windows);

	return (status);
}

/**
 * commandline - calls the shell function
 *
 * @wins: array of window objects
 * @pans: array of panel objects
 *
 * Return: return the status of the called function(s)
*/

int commandline(WINDOW **wins, PANEL **pans)
{
	int status;

	status = shell(wins, pans);
	update_panels();
	doupdate();

	return (status);
}
