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
		fdt[i]._errno = OK;

		fdt[i].fd = 0;
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
 * Return: return a file descriptor of the opened file as integer on success
 *	   return -1 on failure and _errno set to indicate the error
*/

int open_file(const char *filename, int modes)
{
	int fd;
	int32_t i;	/* stogram file descriptor */

	for (i = 3; i < FDT_SIZE; i++)
	{
		if (fdt[i].filename == NULL)
		{
			/* empty slot found */
			fdt[i].filename = strdup(filename);
			if (fdt[i].filename == NULL)
			{
				fdt[i]._errno = MALLOC_ERR;
				return (-1);
			}

			fd = open(fdt[i].filename, modes);
			if (file == -1)
			{
				fdt[i]._errno = OFILE_ERR;
				free(fdt[i].filename);

				return (-1);
			}

			fdt[i].modes = modes;
			fdt[i].fd = fd;	/* will be used to handle close() */
			fdt[i]._errno = OK;

			return (i);	/* return the file descriptor */
		}
	}
	fdt[i]._errno = FDT_ERR;
	return (-1);
}
