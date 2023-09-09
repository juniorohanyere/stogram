#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "exit.h"
#include "window.h"
#include "array.h"
#include "keyboard.h"
#include "keymapper.h"

/**
 * _getline - gets keyboard input
 *
 * @wins: an array of windows
 * @w: index of window to use
 * @pans: array of panels
 * @p: indes of panel to use
 * @buffer: the variable to store keyboard input
 *
 * Description: @w and @p are integer values beginning from 0. The function is
 *		true for a_winlen(@wins) > @w >= 0 and a_panlen(@pans) > @p >=
 *		0. Otherwise, -1 is returned indicating an error
 *
 * Return: return the number of characters read on success
 *	   return -1 on failure
*/

int _getline(WINDOW **wins, unsigned int w, PANEL **pans, unsigned int p,
	char *buffer)
{
	int ch, i, length = 0;
	keymap_t map[] = {
		{KEY_F(1), exit_st}, {KEY_UP, new_line}, {'\n', new_line},
		{ERR, NULL},
		/*{KEY_DOWN, history_down}, */
		/* {KEY_LEFT, TODO}, {KEY_RIGHT, TODO},*/
	};

	if (a_winlen(wins) <= w || a_panlen(pans) <= p)
		return (-1);

	echo();
	while (TRUE)
	{
		ch = wgetch(wins[w]);

		for (i = 0; map[i].key != ERR; i++)
		{
			if (ch == map[i].key)
			{
				map[i].func(wins, w, pans, p, buffer);
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
 * @wins: an array of windows
 * @w: index of window to use
 * @pans: array of panels
 * @p: indes of panel to use
 * @buffer: the variable to store keyboard input
 *
 * Return: always return 0
*/

int new_line(WINDOW __attribute__((unused))**wins,
	unsigned int __attribute__((unused))w,
	PANEL __attribute__((unused))**pans,
	unsigned int __attribute__((unused))p,
	char __attribute__((unused))*buffer)
{
	return (0);
}
