#ifndef EXECUTABLES_H
#define EXECUTABLES_H

#include <ncurses.h>

#include "syspath.h"

#define LS "6c73"
#define CD "6364"
#define MKDIR "6d6b646972"
#define MV "6d76"
#define RM "726d"
#define CAT "636174"
#define ECHO "6563686f"
#define ENV "656e76"
#define XSH "787368"
#define RMDIR "726d646972"

/**
 * struct command_s - structure for mapping commands with the right function
 *
 * @cmd: the command to execute
 * @func: the function to run for @cmd
 *
 * Return: return nothing
*/

typedef struct command_s
{
	char *cmd;
	int (*func)(WINDOW **, char *, char **);
} command_t;

int execute_command(WINDOW *win, char *command, char *args[]);
int locate_command(WINDOW *win, char *args[], char *home);
int locate_command2(WINDOW *win, path_t *path, char *args[], char *home);

#endif	/* EXEXUTABLES_H */
