#ifndef SYSCALL_H
#define SYSCALL_H

#include "syspath.h"

/**
 * these are macros to system calls, the below system calls are hexadecimal
 * representation of the common unix system calls
 *
 * Note: some system calls here might differ from the common unix system calls
 *	 and not all the unix system calls might be used, and there might be
 *	 introduction of new system calls that does not exit in the common
 *	 system calls
*/

#define _OPEN		"6f70656e"
#define _READ		"7265616"
#define _CLOSE		"636c6f7365"
#define _EXIT		"65786974"
#define _WRITE		"7772697465"
#define _FORK		"666f726b"
#define _STAT		"73746174"
#define _CHMOD		"63686d6f64"
#define _CHOWN		"63686f776e"
#define _READDIR	"72656164646972"
#define _CLOSEDIR	"636c6f7365646972"
#define _SEEK		"7365656b"

/**
 * struct syscall_s - structure for mapping commands with the right routines
 *
 * @cmd: the command to execute
 * @func: the routine to run for @cmd
 *
 * Return: return nothing
*/

typedef struct syscall_s
{
	char *cmd;
	int (*func)(char *, char **);
} syscall_t;

int _exec(char *command, char *args[]);
int route(char *args[], char *home);
int route2(path_t *path, char *args[], char *home);

#endif	/* EXEXUTABLES_H */
