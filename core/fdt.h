#ifndef FDT_H
#define FDT_H

#define	FDT fdt_t
#define	FDT_SIZE 1024

#include <unistd.h>
#include <stdint.h>

#include "indicator.h"

/**
 * struct fdt_s - structure to manage the file descriptor table
 *
 * @fd: system level file descriptor
 * @flag: the read-write mode of @fd
 * @offset: the offset from where read/write starts from in the file pointed to
 *	    by @fd
 * @filename: the name of the file to open
 *
 * Description: the file descriptor that will be associated with the stogram
 *		chat system is the index of the struct fdt_s array. The @fd is
 *		communicate with the host system
 *
 * Return: return nothing
*/

typedef struct fdt_s
{
	int fd, modes;
	off_t offset;
	char *filename;
	/* more fields ... */
} fdt_t;

FDT *init_fdt(void);
uint16_t open_file(uint16_t pid, const char *filename, int modes);

#endif	/* FDT_H */
