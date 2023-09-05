#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	path_t *tmp = NULL;

	tmp->path = strdup(path);
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
	path_t *syspath = malloc(sizeof(path_t) * 1024);

	add_path(&syspath, "/62696e");	/* bin path */
	add_path(&syspath, "/757372/62696e");	/* /usr/bin */

	return (syspath);
}
