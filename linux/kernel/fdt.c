#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "fdt.h"

/**
 * init_fdt - initializes the file descriptor table
 *
 * @pcb: process control block
 *
 * Description: ==>(OK; MALLOC_ERR)<==
 *
 * Return: return fdt_t type on success
 *	   return NULL on failure
*/

FDT *init_fdt(PCB *pcb)
{
	int i;
	FDT *fdt;

	fdt = malloc(sizeof(FDT) * FDT_SIZE);
	if (fdt == NULL)
	{
		pcb->status = MALLOC_ERR;

		return (NULL);
	}

	/* index 0, 1, and 2 is reserved for stdin, stdout, and stderr */
	for (i = 0; i < 3; i++)
	{
		fdt[i].filename = malloc(sizeof(char) * 1024);
		if (fdt[i].filename == NULL)
		{
			pcb->status = MALLOC_ERR;

			for (i = 0; fdt[i].filename != NULL; i++)
				free(fdt[i].filename);
			free(fdt);

			return (NULL);
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
 * open_file - generates a file decriptor for a given process id
 *
 * @pcb: process control block
 * @pid: process id to generate a file descriptor for
 * @filename: the name of the file to open
 * @modes: the modes to open the file
 *
 * Description: ==>(OK, MALLOC_ERR, OFILE_ERR, FDT_FULL)<==
 *
 * Return: return a file descriptor success
 *	   return 0 if file descriptor table is full
*/

uint16_t open_file(PCB *pcb, uint16_t pid, const char *filename, int modes)
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
 * clear_file - clears and destroys the file descriptor number associated with
 *		an open file and closes the file. If the file is stdin, stdout,
 *		or stderr, only clears the memory assigned
 *
 * @pcb: process control block
 * @pid: the pid of the file descriptor to destroy
 * @fd: the file descriptor number of an open file (see open_file())
 *
 * Description: ==>(OK, INV_FD)<==
 *
 * Return: return nothing
*/

void clear_file(PCB *pcb, uint16_t pid, uint16_t fd)
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

/**
 * destroy_fdt - function that frees memory allocated by all the file
 *		 descriptors accociated with a process
 *
 * @pcb: process control block
 * @pid: process id of the FDTs to free
 *
 * Return: return nothing
*/

void destroy_fdt(PCB *pcb, uint16_t pid)
{
	int i;

	for (i = 0; i < FDT_SIZE; i++)
	{
		if (pcb[pid].fdt[i].filename != NULL)
			free(pcb[pid].fdt[i].filename);
	}
	free(pcb[pid].fdt);
}
