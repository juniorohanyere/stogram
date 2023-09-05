#include <stdlib.h>
#include <string.h>

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
 * Return: return 0 on success
 *	   return 1 on failure
*/

int shell(WINDOW **wins, PANEL **pans)
{
	int flag, y;
	char *buffer;

	while (TRUE)
	{
		prompt(wins, 0); //prompt prints the $ sign

		buffer = malloc(sizeof(char) * BUFFER_SIZE);
		memset(buffer,0, sizeof(char) * 1024);
		flag = _getline(wins, 0, pans, 0, buffer);
		if (flag == -1)
		{
			free(buffer);
			return (1);
		}

		y = getcury(wins[0]);
		if (y == getmaxy(wins[0]) - 1)
		{
			scroll(wins[0]);
			y = y - 1;
		}
		mvwprintw(wins[0], y + 1, 0, "%s\n", buffer);
		update_panels();
		doupdate();
		free(buffer);
	}
	return (0);
}
