#include "shell.h"
/**
 * execmd - execute the command
 * @argv: arguments
 */
void execmd(char **argv)
{
	char *command = NULL;
	char *actual_command = NULL;

	if (argv)
	{
		/*get command from argv*/
		command = argv[0];
		/*generate the path to this command*/
		actual_command = get_location(command);
		/*execute the command*/
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Error: ");
		}
	}
}
