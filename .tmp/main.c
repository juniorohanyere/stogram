#include <stdio.h>
#include <stdlib.h>

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
	char *lines[] = {"I", "am", "a", "boy", NULL};

	while (*lines != NULL)
	{
		printf("%s\n", lines);
	}

	return (0);
}
