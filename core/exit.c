#include <stdio.h>
#include <stdlib.h>
#include <term.h>

#include "exit.h"
#include "externs.h"

/**
 * exit_st - exits the stogram application
 *
 * @buffer: the variable to store keyboard input
 *
 * Return: always return 0 (always exit successfully)
*/

int exit_st(char *buffer)
{
	clean_up();
	free(buffer);
	free(pans);
	free(wins);
	exit(EXIT_SUCCESS);
}

/**
 * clean_up - makes a final memory allocation clean up
 *
 * Description: note that this function does not free all memory. Hence proper
 *		handling of other frees not defined here is necessary. This
 *		function ends aims at easing the strain of having to free up
 *		some constant or global variables
 *
 * Return: return nothing
*/

void clean_up(void)
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
