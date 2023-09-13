#include <stdlib.h>
#include <string.h>

#include "command_line.h"
#include "keyboard.h"
#include "convert.h"
#include "syscall.h"
#include "parser.h"
#include "error.h"
#include "exit.h"
#include "externs.h"

/**
 * prompt - displays a prompt to enter commands
 *
 * @wins: array containing window objects
 * @w: the index of the window object to use
 *
 * Return: return nothing
*/

void prompt(void)
{
	wprintw(wins[0], "::: ");

	update_panels();
	doupdate();
}

/**
 * command_line - handles the shell prompts
 *
 * Return: return status of the called function(s)
*/

int command_line(void)
{
	int flag, y, status;
	char *buffer, *hex_string, *home = getenv("HOME");
	char **args;

	while (TRUE)
	{
		prompt(); /* prompt prints the ::: sign */
		buffer = calloc(sizeof(char), BUFFER_SIZE);
		if (buffer == NULL)
		{
			malloc_error();
			clean_up(), free(pans), free(wins);
			exit(EXIT_FAILURE);
		}
		flag = _getline(wins[0], buffer);
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
		hex_string = convert_to_hex(buffer);
		args = parse(hex_string, " ");
		if (args != NULL)
			status = route(args, home);
		update_panels(), doupdate();
		free(hex_string), free(buffer), free(args);
	}
	return (status);
}
