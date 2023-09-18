#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

/**
 * struct routine_s - data structure for kernel routines
 *
 * @syscall: the system call
 * @params: parameters passed to the system call function
 *
 * Return: return nothing
*/

typedef struct routine_s
{
	char *syscall;
	char **params;
} routine_t;

void prompt(void);
int command_line(void);

#endif	/* COMMAND_LINE */
