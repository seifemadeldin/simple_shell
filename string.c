#include "shell.h"

/**
 *my_str_cat - concatenate string to another string.
 *@dest: char
 *@src: char
 *Return: dest
 */
char *my_str_cat(char *dest, char *src)
{
	int d = 0;
	int s = 0;

	while (dest[d] != '\0')
	{
		d++;
	}
	while (src[s] != '\0')
	{
		dest[d] = src[s];
		d++;
		s++;
	}
	dest[d] = '\0';
	return (dest);
}

/**
 * str_cmp - compare the values of 2 strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0
 */
int str_cmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] != '\0' && s2[a] != '\0'; a++)
	{
		if (s1[a] != s2[a])
			return ((int)s1[a] - s2[a]);
	}
	return (0);
}

/**
 * my_str_len - finds length of a string
 * @s: string given
 * Return: length of the string
 */
int my_str_len(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * str_ncmp -  function that compares two strings with n number of chars
 * @s1: string one
 * @s2: string two
 * @n: number of characters
 * Return: diference
 */
size_t str_ncmp(char *s1, char *s2, size_t n)
{
	size_t i, j;

	for (j = 0; s1[j] != '\0' && j < n; j++)
	{
		i = s1[j] - s2[j];

		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}

/**
 * my_str_cpy - copies the string pointed to by src into dest
 * @dest: destination of the copy
 * @src: source of the copy
 * Return: char pointer to dest
 */
char *my_str_cpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = *(src + i);

	return (dest);
}
