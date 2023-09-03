#include <stdio.h>
#include <unistd.h>

#include "array.h"

/**
 * a_winlen - calculates the length of an array of WINDOW* objects
 *
 * @wins: array of window objects
 *
 * Return: return the length calculated
*/

size_t a_winlen(WINDOW **wins)
{
	int i;

	if (wins == NULL)
		return (0);

	for (i = 0; wins[i] != NULL; i++)
		;

	return (i);
}

/**
 * a_panlen - calculates the length of an array of PANEL* objects
 *
 * @pans: array of panel objects
 *
 * Return: return the length calculated
*/

size_t a_panlen(PANEL **pans)
{
	int i;

	if (pans == NULL)
		return (0);

	for (i = 0; pans[i] != NULL; i++)
		;

	return (i);
}

