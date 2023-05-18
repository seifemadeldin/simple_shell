#include "shell.h"
/**
 * exit_command - handlles exit command
 * @arg: pointer with the direction argument.
 * @lineptr: standar input string
 * @_exit: value of exit
 * Return: None
 */
void exit_command(char **arg, char *lineptr, int _exit)
{
	int exit_status = 0;

	if (!arg[1])
	{
		free(lineptr);
		free(arg);
		exit(_exit);
	}
	exit_status = atoi(arg[1]);

	free(lineptr);
	free(arg);
	exit(exit_status);
}

/**
 *get_env - function to get all env
 *@env: enviroment
 *Return: 0
 */
void get_env(char **env)
{
	size_t run = 0;

	while (env[run])
	{
		write(STDOUT_FILENO, env[run], my_str_len(env[run]));
		write(STDOUT_FILENO, "\n", 1);
		run++;
	}
}
