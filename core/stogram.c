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
	wins = calloc(sizeof(WINDOW *), 1);
	pans = calloc(sizeof(PANEL), 1);

	/* initialize ncurses */
	initscr();
	cbreak();
	echo();
	keypad(stdscr, TRUE);
	refresh();

	getmaxyx(stdscr, height, width);

	/* create new windows */
	wins[0] = init_window(height, width, 0, 0);

	/* create panel */
	pans[0] = new_panel(wins[0]);

	/* logo_stg(windows[0], 4, 15); */

	wprintw(wins[0], "\n");
	update_panels();
	doupdate();

	status = commandline();

	/* clean up */
	clean_up();
	free(wins);

	return (status);
}

/**
 * commandline - calls the shell function
 *
 * Return: return the status of the called function(s)
*/

int commandline(void)
{
	int status;

	status = shell();
	update_panels();
	doupdate();

	return (status);
}
