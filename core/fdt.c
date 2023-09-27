#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include "fdt.h"
#include "externs.h"

/**
 * init_stdio - the stogram standard input and output
 *
 * Description: assigns an amount of memory each to stdin, stdout, and stderr
 *
 * Return: return nothing
*/

void init_stdio(void)
{
	int i;

	for (i = 0; i < 3; i++)
	{
		_stdio[i] = malloc(sizeof(char

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
	for (i = 3; i < FDT_SIZE; i++)
	{
		pcb->status = OK;
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
 * Description: ==>(OK; MALLOC_ERR; OFILE_ERR; FDT_ERR)<==
 *
 * Return: return a file descriptor success
 *	   return 0 if file descriptor table is full
*/

uint16_t openfd(uint16_t pid, const char *filename, int modes)
{
	int fd;	/* file descriptor provided by the underlying OS */
	uint16_t i;	/* Stogram file descriptor */

	for (i = 0; i < FDT_SIZE; i++)
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
			if (file == -1)
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
	pcb->status = FDT_ERR;
	return (0);
}
