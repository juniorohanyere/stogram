#ifndef FDT_H
#define FDT_H

#define	FDT fdt_t
#define	FDT_SIZE 1024

#include <unistd.h>

/**
 * struct fdt_s - structure to manage the file descriptor table
 *
 * @fd: the file descriptor of opened files
 * @flag: the read-write mode of @fd
 * @offset: the offset from where read/write starts from in the file pointed to
 *	    by @fd
 * @filename: the name of the file to open
 *
 * Return: return nothing
*/

typedef struct fdt_s
{
	int fd, flag;
	off_t offset;
	char *filename;
	/* more fields ... */
} fdt_t;

void init_fdt(void);
int open_file(const char *filename, int flag);

#endif	/* FDT_H */
