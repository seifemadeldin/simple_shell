#include "shell.h"
/**
 * separate_path - separate the path in new strings.
 * @arg: command input of user.
 * @env: enviroment.
 * Return:  a pointer to strings.
 */
int separate_path(char **arg, char **env)
{
	char *token = NULL, *path_rela = NULL, *path_absol = NULL;
	size_t value_path, command;
	struct stat stat_lineptr;

	if (stat(*arg, &stat_lineptr) == 0)
		return (-1);
	path_rela = get_path(env);
	if (!path_rela)
		return (-1);
	token = my_strtok(path_rela, ":");
	command = str_len(*arg);
	while (token)
	{
		value_path = str_len(token);
		path_absol = malloc(sizeof(char) * (value_path + command + 2));
		if (!path_absol)
		{
			free(path_rela);
			return (-1);
		}
		path_absol = str_cpy(path_absol, token);
		str_cat(path_absol, "/");
		str_cat(path_absol, *arg);

		if (stat(path_absol, &stat_lineptr) == 0)
		{
			*arg = path_absol;
			free(path_rela);
			return (0);
		}
		free(path_absol);
		token = my_strtok(NULL, ":");
	}
	free(path_rela);
	return (-1);
}
