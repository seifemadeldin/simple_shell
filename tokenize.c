#include "shell.h"
/**
 * tokenize - tokenize a string
 * @lineptr: comman user
 * Return: To a pointer
 */

char **tokenize(char *lineptr)
{
	char **user_command = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;

	if (lineptr == NULL)
		return (NULL);

	for (i = 0; lineptr[i]; i++)
	{
		if (lineptr[i] == ' ')
			size++;
	}
	if ((size + 1) == my_str_len(lineptr))
		return (NULL);
	user_command = malloc(sizeof(char *) * (size + 2));
	if (user_command == NULL)
		return (NULL);

	token = my_strtok(lineptr, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		user_command[i] = token;
		token = my_strtok(NULL, " \n\t\r");
	}
	user_command[i] = NULL;
	return (user_command);
}
