#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "parser.h"
#include "exit.h"
#include "error.h"
#include "externs.h"

/**
 * parse - parses a buffer into tokens based on a specific delimiter
 *
 * @wins: array of WINDOW* objects
 * @pans: array of PANEL* objects
 * @buffer: the buffer to be parsed
 * @delimiter: the delimiter
 *
 * Return: return an array of the parsed buffer
*/

char **parse(char *buffer, char *delimiter)
{
	int i, buffer_size = BUFFER_SIZE;
	char *token;
	char **tokens;

	tokens = calloc(sizeof(char *), buffer_size);
	if (tokens == NULL)
	{
		malloc_error();
		clean_up(), free(pans), free(wins);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, delimiter);
	if (token == NULL)
	{
		free(token), free(tokens);
		return (NULL);
	}
	for (i = 0; token != NULL; i++)
	{
		if (i >= buffer_size)
		{
			buffer_size += BUFFER_SIZE;
			tokens = realloc(tokens,
				buffer_size  * sizeof(char *));
			if (!tokens)
			{
				malloc_error();
				free(token), free(tokens);
				clean_up();
				free(pans), free(wins), exit(EXIT_FAILURE);
			}
		}
		tokens[i] = token, token = strtok(NULL, "\n");
	}
	tokens[i] = NULL;
	free(token);
	return (tokens);
}
