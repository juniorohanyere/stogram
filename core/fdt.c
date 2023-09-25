#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include "fdt.h"
#include "externs.h"

void init_fdt(void)
{
	int i;

	for (i = 0; i < FDT_SIZE; i++)
	{
		fdt[i].status = OK;

		fdt[i].fd = i;
		fdt[i].flags = 0;

		fdt[i].offet = 0;

		fdt[i].filename = NULL;
	}
}

int open_file(const char *filename, int flags)
{
	int i;

	for (i = 3; i < FDT_SIZE; i++)
	{
		/* ... */
	}
	return (0);
}
