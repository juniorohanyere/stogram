#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

#include "syspath.h"
#include "parser.h"

path_t *new_path(const char *path)
{
	path_t *new = (path_t *)malloc(sizeof(path_t));

	new->next = NULL;

	new->path = (char *)malloc((strlen(path) + 1) * sizeof(char));
	strcpy(new->path, path);

	return (new);
}

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
	path_t *tmp = new_path(path);

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
	int i;
	path_t *syspath = NULL;
	char *path = getenv("STOGRAM_PATH");
	char **paths;

	paths = parse(path, ":");
	for (i = 0; paths[i] != NULL; i++)
		add_path(&syspath, BIN);

	return (syspath);
}
