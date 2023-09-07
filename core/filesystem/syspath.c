#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

#include "syspath.h"

/**
 * add_path - adds a system path to the list
 *
 * @syspath: pointer to a list of system paths
 * @path: the path to add
 *
 * Return: return nothing
*/

void add_path(path_t **syspath, char *path)
{
	path_t *tmp = calloc(sizeof(path_t), 1);

	tmp->path = path;
	tmp->next = *syspath;

	*syspath = tmp;
}

/**
 * free_path - frees memory allocated to a path_t type
 *
 * @syspath: pointer to the system paths
 *
 * Return: return nothing
*/

void free_path(path_t *syspath)
{
	path_t *current = syspath;
	path_t *next_path;

	while (current != NULL)
	{
		next_path = current->next;
		free(current->path);
		free(current);
		current = next_path;
	}
}

/**
 * system_path - function to store the system paths
 *
 * Return: return a pointer to the system paths
*/

path_t *system_path(void)
{
	path_t *syspath = NULL;

	add_path(&syspath, BIN);	/* bin path */
	add_path(&syspath, USR_BIN);	/* /usr/bin */

	return (syspath);
}

void print_path(path_t *head)
{
	path_t *current = head;

	while (current != NULL)
	{
		printw("path: %s\n", current->path);
		current = current->next;
	}
}
