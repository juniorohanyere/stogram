#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "read_file.h"

/**
 * main - entry point for stogram
 *
 * @argc: the argument counter
 * @argv: variable containing the list of command line arguments
 *
 * Return: always return 0
*/

int main(int argc, char **argv)
{
	int i;
	char **lines;
	const char *progname = argv[0];
	const char *filename = argv[1];

	if (argc != 2)
	{
		usage_error(progname);
		exit(EXIT_FAILURE);
	}

	lines = read_file(filename);
	for (i = 0; lines[i] != NULL; i++)
		printf("%d %s\n", i, lines[i]);

	for (i = 0; lines[i] != NULL; i++)
		free(lines[i]);
	free(lines);
	return (0);
}
