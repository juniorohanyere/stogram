#ifndef ROUTINE_H
#define ROUTINE_H

/**
 * struct routine_s - structure for accessing system calls and their arguments
 *
 * @syscall: the system call
 * @params: the paramenters passed to the system call
 * @next: the next system call in the stack
 *
 * Return: return nothing
*/

typedef struct routine_s
{
	char *syscall;
	char **params;
	struct routine_s *next;
} routine_t;

#endif	/* ROUTINE_H */
