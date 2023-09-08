#include <unistd.h>
#include <stdio.h>

/**
 * malloc_error - prints an error message to stderr when there is a failure on
 *		  memory allocation
 *
 * Return: return nothing
*/

void malloc_error(void)
{
	dprintf(STDERR_FILENO,
		"Insufficient memory: Memory allocation failed\n");
}
