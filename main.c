#include "shell.h"
/**
 * main - entry point
 * @ac:count of argumnents
 * @av: arguments
 * @env: environment variable
 * Return: _exit = 0.
 */
int main(int ac, char **av, char **env)
{
	char *getcommand = NULL, **user_command = NULL;
	int pathValue = 0, _exit = 0, n = 0;
	(void)ac;

	while (1)
	{
		getcommand = my_getline();
		if (getcommand)
		{
			pathValue++;
			user_command = get_token(getcommand);
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
				_exit = _fork(user_command, av, env, getcommand, pathValue, n);
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