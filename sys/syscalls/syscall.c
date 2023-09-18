#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "syscall.h"
#include "convert.h"
#include "externs.h"

int route(char *syscall)
{
	int status = 0;
	path_t *path = system_path();
	char *sysroot = getenv("STOGRAM_ROOT");
	char *command = malloc(sizeof(char) * 1024);
	char *c;

	strcpy(command, sysroot);
	strcat(command, args[0]);	/* ~/.stogram/2f/{path/to/executable} */

	if (access(command, F_OK) == 0)
	{
		/* read content of the command */
		/* pass the content as an argument to an execution function */
		/* execute_command(@content, args[]) */

		/*return (status);*/
	}

	wprintw(wins[0], "%s\n", command);
	c = convert_to_string(args[0]);
	wprintw(wins[0], "%s\n", c);
	free(c);
	refresh();

	route2(path, args, home);

	free(command);
	free_path(path);
	return (status);
}


int route2(path_t *path, char **args, char *home)
{
	path_t *syspath = path;
	char *command = malloc(sizeof(char) * 1024);

	while (syspath != NULL)
	{
		memset(command, 0, 1024);
		strcpy(command, syspath->path);
		strcat(command, "/");
		strcat(command, args[0]);

		wprintw(wins[0], "path: %s\n", command);
		syspath = syspath->next;
	}
	free(command);
	return (0);
}

/**
 * execute_commands - handles the execution of valid commands
 *
 * @args: the stogram command line arguments
 *
 * Return: return the status of the executed command
*/

/**
 * int execute_command(char *command, char *args[])
 * {
 *	int status, i;
 *	command_t commands[] = {
 *		{LS, list_dir}, {CD, change_dir}, {NULL, NULL},
 *	};
 *
 *	for (i = 0; commands[i].cmd != NULL; i++)
 *	{
 *		if (strcmp(command, commands[i].cmd) == 0)
 *			status = commands[i].func(command, args);
 *	}
 *
 *	return (status);
 * }
*/
