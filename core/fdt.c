#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "fdt.h"
#include "externs.h"

/**
 * init_fdt - initializes the file descriptor table
 *
 * Description: ==>(OK; MALLOC_ERR)<==
 *
 * Return: return nothing
*/

FDT *init_fdt(void)
{
	FDT *fdt;
	int i;

	fdt = malloc(sizeof(FDT) * FDT_SIZE);
	if (fdt == NULL)
	{
		pcb->status = MALLOC_ERR;
		return (fdt);
	}

	/* index 0, 1, and 2 is reserved for stdin, stdout, and stderr */
	for (i = 0; i < 3; i++)
	{
		fdt[i].filename = malloc(sizeof(char) * 1024);
		if (fdt[i].filename == NULL)
		{
			pcb->status = MALLOC_ERR;

			return (fdt);
		}
	}

	pcb->status = OK;

	fdt[0].fd = STDIN_FILENO;
	fdt[1].fd = STDOUT_FILENO;
	fdt[2].fd = STDERR_FILENO;

	for (i = 3; i < FDT_SIZE; i++)
	{
		fdt[i].fd = 0;
		fdt[i].modes = 0;

		fdt[i].offset = 0;

		fdt[i].filename = NULL;
	}
	return (fdt);
}

/**
 * open_file - manages open file descriptors
 *
 * @filename: the name of the file to open
 * @modes: the modes to open the file
 *
 * Description: ==>(OK; MALLOC_ERR; OFILE_ERR; FDT_FULL)<==
 *
 * Return: return a file descriptor success
 *	   return 0 if file descriptor table is full
*/

uint16_t open_file(uint16_t pid, const char *filename, int modes)
{
	int fd;	/* file descriptor provided by the underlying OS */
	uint16_t i;	/* Stogram file descriptor */

	for (i = 3; i < FDT_SIZE; i++)
	{
		if (pcb[pid].fdt[i].filename == NULL)
		{
			/* empty slot found */
			pcb[pid].fdt[i].filename = strdup(filename);
			if (pcb[pid].fdt[i].filename == NULL)
			{
				pcb->status = MALLOC_ERR;
				return (i);
			}

			fd = open(pcb[pid].fdt[i].filename, modes);
			if (fd == -1)
			{
				pcb->status = OFILE_ERR;

				return (i);
			}

			pcb->status = OK;
			pcb[pid].fdt[i].modes = modes;
			/* fd will be used to handle close() function */
			pcb[pid].fdt[i].fd = fd;

			return (i);	/* Stogram file descriptor */
		}
	}
	pcb->status = FDT_FULL;
	return (0);
}

/**
 * close_file - destroys the file descriptor number associated with an open
 *		file and closes the file
 *
 * @fd: the file descriptor number of an open file (see open_file())
 *
 * Description: ==>(INV_FD)<==
 *
 * Return: return nothing
*/

void close_file(uint16_t pid, uint16_t fd)
{
	if (fd < FDT_SIZE && pcb[pid].fdt[fd].filename != NULL)
	{
		pcb->status = OK;
		free(pcb[pid].fdt[fd].filename);

		if (fd > 2)
			close(pcb[pid].fdt[fd].fd);
		return;
	}
	pcb->status = INV_FD;
}
