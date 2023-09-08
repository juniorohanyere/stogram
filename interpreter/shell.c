#include <stdlib.h>
#include <string.h>

#include "shell.h"
#include "stogram.h"
#include "keyboard.h"
#include "convert_to_hex.h"
#include "executables.h"
#include "parser.h"
#include "error.h"
#include "exit.h"

/**
 * prompt - displays a prompt to enter commands
 *
 * @wins: array containing window objects
 * @w: the index of the window object to use
 *
 * Return: return nothing
*/

void prompt(WINDOW **wins, unsigned int w)
{
	wprintw(wins[w], "::: ");

	update_panels();
	doupdate();
}

/**
 * shell - handles the shell prompts
 *
 * @wins: array conatining window objects
 * @pans: array containing panel objects
 *
 * Return: return status of the called function(s)
*/

int shell(WINDOW **wins, PANEL **pans)
{
	int flag, y, status;
	char *buffer, *hex_string, *home = getenv("HOME");
	char **args;

	while (TRUE)
	{
		prompt(wins, 0); /* prompt prints the ::: sign */
		buffer = calloc(sizeof(char), BUFFER_SIZE);
		if (buffer == NULL)
		{
			malloc_error();
			clean_up(wins, pans), free(pans), free(wins);
			exit(EXIT_FAILURE);
		}
		flag = _getline(wins, 0, pans, 0, buffer);
		if (flag == -1)
		{
			free(buffer), free(args);
			return (1);
		}
		y = getcury(wins[0]);
		if (y == getmaxy(wins[0]) - 1)
			scroll(wins[0]), y = y - 1;

		/**
		 * if it works, don't touch it. That rule thus apply here this
		 * approach seem to be the only way out not to keep tracking
		 * the current height position for the automatic scrolling in
		 * every function, wprintw or printw can be used next time
		*/
		mvwprintw(wins[0], y + 1, 0, "%s", "\0");
		hex_string = convert_to_hex(wins, pans, buffer);
		args = parse(wins, pans, hex_string, " ");
		if (args != NULL)
			status = locate_command(wins[0], args, home);
		update_panels(), doupdate();
		free(hex_string), free(buffer), free(args);
	}
	return (status);
}
