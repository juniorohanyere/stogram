#ifndef SYSCALL_H
#define SYSCALL_H

#include "syspath.h"
#include "routine.h"

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
 * struct syscall_s - structure for accessing a system call along with its
 *		      arguments if any
 *
 * @name: the name of the system call
 * @args: the system call arguments
 *
 * Return: return nothing
*/

typedef struct syscall_s
{
	char *name;
	char **args;
} syscall_t;

/**
 * struct route_s - structure for mapping commands with the right routines
 *
 * @syscall: the system call to execute
 * @routine: the routine to run for @syscall
 *
 * Return: return nothing
*/

typedef struct route_s
{
	char *syscall;
	int (*routine)(routine_t *);
} route_t;

int _exec(char *command, char *args[]);
int route(char *args[]);
int route2(path_t *path, char *args[], char *home);

#endif	/* EXEXUTABLES_H */
