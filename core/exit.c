#include <stdio.h>
#include <stdlib.h>
#include <term.h>

#include "exit.h"

/**
 * exit_st - exits the stogram application
 *
 * @wins: an array of windows
 * @w: index of window to use
 * @pans: array of panels
 * @p: indes of panel to use
 * @buffer: the variable to store keyboard input
 *
 * Return: always return 0 (always exit successfully)
*/

int exit_st(WINDOW **wins, unsigned int __attribute__((unused))w, PANEL **pans,
	unsigned int __attribute__((unused))p, char *buffer)
{
	clean_up(wins, pans);
	free(buffer);
	free(pans);
	free(wins);
	exit(EXIT_SUCCESS);
}

/**
 * clean_up - makes a final memory allocation clean up
 *
 * @wins: array of window objects
 * @pans: array of panel objects
 *
 * Description: note that this function does not free all memory. Hence proper
 *		handling of other frees not defined here is necessary. This
 *		function ends aims at easing the strain of having to free up
 *		some constant or global variables
 *
 * Return: return nothing
*/

void clean_up(WINDOW **wins, PANEL **pans)
{
	int i;

	if (pans != NULL)
	{
		for (i = 0; pans[i] != NULL; i++)
			del_panel(pans[i]);
	}

	if (wins != NULL)
	{
		for (i = 0; wins[i] != NULL; i++)
			delwin(wins[i]);
	}

	endwin();
	del_curterm(cur_term);
	delwin(stdscr);
	delwin(curscr);
	delwin(newscr);
}
