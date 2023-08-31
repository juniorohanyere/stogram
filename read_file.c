#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "read_file.h"
#include "error.h"

/**
 * read_file - function that reads the content of a file line by line
 *
 * @filename: the name of the file to read
 *
 * Return: return each line read in form of an array to char pointers
*/

char **read_file(const char *filename)
{
	int i;
	FILE *file;
	char **lines;
	char *line, *line_dup;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		access_error(filename);
		exit(EXIT_FAILURE);
	}

	lines = calloc(sizeof(char *), BUFFER_SIZE);
	line = calloc(sizeof(char), BUFFER_SIZE);

	if (!lines || !line)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}

	for (i = 0; fgets(line, BUFFER_SIZE, file) != NULL; i++)
	{
		line_dup = strdup(line);
		line_dup[strcspn(line_dup, "\n")] = '\0';
		lines[i] = line_dup;
	}
	fclose(file);
	free(line);
	return (lines);
}
