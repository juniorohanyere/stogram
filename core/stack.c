#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "error.h"

/**
 * new_stack - creates a new stack
 *
 * @n: line number
 * @lineptr: pointer to the lines in a file
 *
 * Return: return the new node created
*/

stacks_t new_stack(int n, char *lineptr)
{
	stacks_t *node;

	node = malloc(sizeof(stacks_t *));
	if (node == NULL)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}

	node->n = n;

	node->lineptr = malloc(sizeof(char) * strlen(lineptr + 1));
	if (node->lineptr == NULL)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}
	strcpy(node->lineptr, lineptr);

	node->next = NULL;

	return (node);
}
