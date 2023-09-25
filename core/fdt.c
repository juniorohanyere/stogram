#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include "fdt.h"
#include "externs.h"

/**
 * init_fdt - initializes the file descriptor table
 *
 * Return: return nothing
*/

void init_fdt(void)
{
	int i;

	/* index 0, 1, and 2 is reserved for stdin, stdout, and stderr */
	for (i = 3; i < FDT_SIZE; i++)
	{
		fdt[i].status = OK;

		fdt[i].fd = i;
		fdt[i].flags = 0;

		fdt[i].offet = 0;

		fdt[i].filename = NULL;
	}
}

/**
 * open_file - manages open file descriptors
 *
 * @filename: the name of the file to open
 * @flag: the mode to open the file
 *
 * Return: return a file descriptor of the opened file as integer
*/

int open_file(const char *filename, int flag)
{
	int i;

	for (i = 3; i < FDT_SIZE; i++)
	{
		/* ... */
	}
	return (0);
}
