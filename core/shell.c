#include <stdlib.h>

#include "shell.h"
#include "stogram.h"
#include "keyboard.h"

/**
 * prompt - displays a prompt to enter commands
 *
 * Return: return nothing
*/

void prompt(WINDOW **wins, unsigned int w)
{
	mvwprintw(wins[w], getcury(wins[w]) + 1, 0, "::: ");

	update_panels();
	doupdate();
}

/**
 * shell - handles the shell prompts
 *
 * @wins: array conatining window objects
 * @pans: array containing panel objects
 *
 * Return: return 0 on success
 *	   return 1 on failure
*/

int shell(WINDOW **wins, PANEL **pans)
{
	int flag;
	char *buffer;

	while (TRUE)
	{
		prompt(wins, 0);

		buffer = malloc(sizeof(char) * BUFFER_SIZE);

		flag = _getline(wins, 0, pans, 0, buffer);
		if (flag == -1)
			return (1);
		//mvwprintw(wins[0], getcury(wins[0]) + 1, 0, "%s", buffer);
		prompt(wins, 0);
		update_panels();
		doupdate();
	}
	return (0);
}
