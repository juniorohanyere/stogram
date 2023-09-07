#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "listdir.h"
#include "changedir.h"
#include "executables.h"

int locate_command(WINDOW __attribute__((unused))*win, char *args[], char __attribute__((unused))*home)
{
	int status = 0;
	path_t *path;
	char *sysroot = calloc(sizeof(char), 1024);
	char *command = malloc(sizeof(char) * 1024);
	char __attribute__((unused))*alt_command;

	path = system_path();

	strcat(sysroot, home);
	strcat(sysroot, "/");
	strcat(sysroot, SYSROOT);	/* ~/.stogram/46 */
	strcat(sysroot, "/");

	strcpy(command, sysroot);
	strcat(command, args[0]);	/* ~/.stogram/46/path/to/executable */

	if (access(command, F_OK) == 0)
	{
		/* read content of the command */
		/* pass the content as an argument to an execution function */
		/* execute_command(@content, args[]) */

		/*return (status);*/
	}

	wprintw(win, "%s\n", command);
	refresh();

	locate_command2(win, path, args, home);

	free(sysroot);
	free(command);
	free_path(path);
	return (status);
}


int locate_command2(WINDOW *win, path_t *path, char **args, char *home)
{
	path_t *syspath = path;
	char *sysroot = calloc(sizeof(char), 1024);
	char *command = malloc(sizeof(char) * 1024);

	strcat(sysroot, home);
	strcat(sysroot, "/");
	strcat(sysroot, SYSROOT);
	strcat(sysroot, "/");

	while (syspath != NULL)
	{
		memset(command, 0, 1024);
		strcpy(command, sysroot);
		strcat(command, syspath->path);
		strcat(command, "/");
		strcat(command, args[0]);

		wprintw(win, "path: %s\n", command);
		syspath = syspath->next;
	}
	free(command);
	free(sysroot);
	return (0);
}

/**
 * execute_commands - handles the execution of valid commands
 *
 * @args: the stogram command line arguments
 *
 * Return: return the status of the executed command
*/

int execute_command(WINDOW *win, char *command, char *args[])
{
	int status, i;
	command_t commands[] = {
		{LS, list_dir}, {CD, change_dir}, {NULL, NULL},
	};

	for (i = 0; commands[i].cmd != NULL; i++)
	{
		if (strcmp(command, commands[i].cmd) == 0)
			status = commands[i].func(win, command, args);
	}

	return (status);
}
