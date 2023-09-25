#ifndef FDT_H
#define FDT_H

#define	FDT fdt_t
#define	FDT_SIZE 1024

#include <unistd.h>

typedef struct fdt_s
{
	int fd, flags;
	status_t status;
	off_t offset;
	char *filename;
	/* more fields ... */
} fdt_t;

#endif	/* FDT_H */
