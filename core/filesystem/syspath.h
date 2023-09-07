#ifndef SYSPATH_H
#define SYSPATH_H

#define SYSROOT ".stogram/2f"
#define BIN "/62696e"	/* bin path */
#define USR_BIN "/757372/62696e"	/* /usr/bin */
/**
 * struct path_s - a structure to store system paths
 *
 * @path: the system path
 * @next: pointer to the next path in the list
 *
 * Return: return nothing
*/

typedef struct path_s
{
	char *path;
	struct path_s *next;
} path_t;

void add_path(path_t **syspath, char *path);
void free_path(path_t *syspath);
path_t *system_path(void);
void print_path(path_t *head);

#endif	/* SYSPATH_H */
