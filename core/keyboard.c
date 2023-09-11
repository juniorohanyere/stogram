#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "exit.h"
#include "window.h"
#include "array.h"
#include "keyboard.h"
#include "keymapper.h"
#include "externs.h"

/**
 * _getline - gets keyboard input
 *
 * @w: index of window to use
 * @buffer: the variable to store keyboard input
 *
 * Description: @w and @p are integer values beginning from 0. The function is
 *		true for a_winlen(@wins) > @w >= 0 and a_panlen(@pans) > @p >=
 *		0. Otherwise, -1 is returned indicating an error
 *
 * Return: return the number of characters read on success
 *	   return -1 on failure
*/

int _getline(WINDOW *win, char *buffer)
{
	int ch, i, length = 0;
	keymap_t map[] = {
		{KEY_F(1), exit_st}, {KEY_UP, new_line}, {'\n', new_line},
		{ERR, NULL},
		/*{KEY_DOWN, history_down}, */
		/* {KEY_LEFT, TODO}, {KEY_RIGHT, TODO},*/
	};

	echo();
	while (TRUE)
	{
		ch = wgetch(win);

		for (i = 0; map[i].key != ERR; i++)
		{
			if (ch == map[i].key)
			{
				map[i].func(buffer);
				return (length);
			}
		}
		strcat(buffer, (char *)&ch);
		length++;
	}
	return (length);
}

/**
 * new_line - handles the enter key(new line) press
 *
 * @buffer: the variable to store keyboard input
 *
 * Return: always return 0
*/

int new_line(char __attribute__((unused))*buffer)
{
	return (0);
}
