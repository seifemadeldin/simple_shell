#include "shell.h"
/**
 * main - main arguments functions
 * @ac:count of argumnents
 * @av: arguments
 * @env: environment
 * Return: _exit = 0.
 */
int main(int ac, char **av, char **env)
{
	char *getcommand = NULL, **user_command = NULL;
	int pathValue = 0, _exit = 0, n = 0;
	(void)ac;

	while (1)
	{
		/*using getline function*/
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
				n = separate_path(&user_command[0], env);
				_exit = fork_function(user_command, av, env, getcommand, pathValue, n);
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
