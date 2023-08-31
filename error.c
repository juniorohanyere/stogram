#include <stdio.h>
#include <unistd.h>

/**
 * malloc_error - function that prints an error message afer a malloc failure
 *
 * Return: return nothing
*/

void malloc_error(void)
{
	dprintf(STDERR_FILENO,
		"Error: Insufficient memory, please free up some memory\n");
}

/**
 * usage_error - prints an usage message when the wrong command line arguments
 *		 is used
 *
 * @progname: the name of the program (stogram)
 *
 * Return: return nothing
*/

void usage_error(const char *progname)
{
	dprintf(STDERR_FILENO, "Usage: %s <filename>\n", progname);
}

/**
 * access_error - prints an error message when a file cannot be accessed or
 *		  read from
 *
 * @filename: the name of the file that cannot be accessed
 *
 * Return: return nothing
*/

void access_error(const char *filename)
{
	dprintf(STDERR_FILENO, "Error: Unable to access file: %s: ", filename);
	dprintf(STDERR_FILENO, "check that it is a valid file(name)\n");
}
