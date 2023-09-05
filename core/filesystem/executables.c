#include "syspath.h"
#include "executables.h"

int locate_command(char *args[])
{
	path_t *path;
	char *sysroot = malloc(sizeof(char) * 1024);
	char *command, *alt_command;
	path = system_path();

	sysroot = getenv("HOME");
	strcat(sysroot, SYSROOT);	/* ~/.stogram/46 */

	command = strdup(sysroot);
	alt_command = strdup(sysroot);
	strcat(command, args[0]);	/* ~/.stogram/46/path/to/executable */

	if (access(command, F_OK) == 0)
	{
		/* read content of the command */
		/* pass the content as an argument to an execution function */
		/* execute_command(@content, args[]) */

		return (status);
	}

	while (path != NULL)
	{
		strcat(alt_command, path->path);	/* ~/.stogram/46/path */
		strcat(alt_command, "/");	/* ~/.stogram/46/path/ */
		strcat(alt_command, args[0]);	/* ~/.stogram/46/path/executable */

		if (access(command, F_OK) == 0)
		{
			/* read content of the command */
			/* pass the content as an argument to an execution function */
			/* execute_command(@content, args[]) */

			return (status);
		}
	}
}
/**
 * execute_commands - handles the execution of valid commands
 *
 * @args: the stogram command line arguments
 *
 * Return: return the status of the executed command
*/

int execute_commands(char *command, char *args[])
{
	int status;
	command_t *commands = {
		{LS, list_dir}, {CD, change_dir},
	};

	for (; *commands != NULL; *commands++)
	{
		if (strcmp(command, *commands.cmd) == 0)
			status = *commands.execute(command, args);
	}

	return (status);
}
