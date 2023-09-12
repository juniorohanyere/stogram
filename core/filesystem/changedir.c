#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "changedir.h"
#include "array.h"
#include "externs.h"

/**
 * change_dir - changes the current working directory of a user to the
 *		directory specified
 *
 * @win: the current window
 * @command: the command found in the executable that brought about this
 *	     function
 * @args: a list of command line arguments
 *
 * Return: return 0 on success
 *	   return 1 on failure
*/

int change_dir(char __attribute__((unused))*command, char **args)
{
	if (a_strlen(args) == 2)
	{
		if (access(args[1], F_OK) == 0)
		{
			/* convert hexadecimal to oringinal string */

			if (setenv("_PWD", args[1], 1) == -1)
			{
				dprintf(STDERR_FILENO, "An error occurred\n");
				return (1);
			}
		}
	}
	return (0);
}
