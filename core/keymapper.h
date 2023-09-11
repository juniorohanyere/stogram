#ifndef KEYMAPPER_H
#define KEYMAPPER_H

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
	int (*func)(char *buffer);
} keymap_t;

#endif	/* KEYMAPPER_H */
