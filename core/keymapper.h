#ifndef KEYMAPPER_H
#define KEYMAPPER_H

#include <ncurses.h>
#include <panel.h>

/**
 * struct keymap - type definition for a key mapper structure
 *
 * @key: the keyboard input
 * @func: the function to execute
 *
 * Description: the @key is an integer value representing key press values
 *
 * Return: return nothing
*/

typedef struct keymap
{
	int key;
	int (*func)(WINDOW **wins, unsigned int w, PANEL **pans,
		unsigned int p, char *buffer);
} keymap_t;

#endif	/* KEYMAPPER_H */
