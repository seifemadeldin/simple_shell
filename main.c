#include "shell.h"
/**
 * main - entry point
 * @argc:count of argumnents
 * @argv: arguments
 * @env: environment variable
 * Return: _exit = 0
 */
int main(int argc, char **argv, char **env)
{
	char *getcommand = NULL, **user_command = NULL;
	int pathValue = 0, _exit = 0, n = 0;
	(void)argc;

	while (1) /* prompting */
	{
		getcommand = my_getline();
		if (getcommand)
		{
			pathValue++;
			user_command = tokenize(getcommand);
			if (!user_command)
			{
				free(getcommand);
				continue;
			}
			if ((!str_cmp(user_command[0], "exit")) && user_command[1] == NULL)
				exit_command(user_command, getcommand, _exit);
			if (!str_cmp(user_command[0], "env"))
				get_env(env);
			else
			{
				n = my_split(&user_command[0], env);
				_exit = _fork(user_command, argv, env, getcommand, pathValue, n);
				if (n == 0)
					free(user_command[0]);
			}
			free(user_command);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(_exit);
		}
		free(getcommand);
	}
	return (_exit);
}
