#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

#include "listdir.h"

/**
 * list_dir - lists the content of a directory
 *
 * @command: the command to execute
 * @args: list of command lin arguments entered
 *
 * Description: the @command might be useful in case a command was renamed
 *		accidentally, or by any specific reason, as every commands
 *		contain a hexadecimal instructions of their functions
 *
 *
 * Return: return 0 on success
 *	   return 1 on failure
*/

int list_dir(WINDOW *win, char __attribute__((unused))*command, char *args[])
{
	DIR *dir;
	dirent_t *rdir;

	if (args[1] == NULL)
		dir = opendir(getenv("_PWD"));
	else if (args[1] != NULL && args[2] == NULL)
		dir = opendir(args[1]);
	else
	{
		/* implement when multiple dirs are specified */
		wprintw(win, "WARNING: feature under construction!");
		return (0);
	}
	if (dir == NULL)
	{
		/**
		 * args is in hexadecimals, convert the index of args needed to
		 * original string befor printing to stderr
		*/

		/* convert: receive data from socket */

		dprintf(STDERR_FILENO,
			"%s: cannot access '%s': No such file or directory\n",
			args[0], args[1]);
		return (1);
	}

	while ((rdir = readdir(dir)) != NULL)
	{
		wprintw(win, "%s\n", rdir->d_name);
	}

	closedir(dir);

	return (0);
}
