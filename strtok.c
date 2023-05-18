#include "shell.h"

/**
 * my_strchr - locates the ﬁrst occurrence of c (converted to a char) in the
 * string pointed to by s. The terminating null character is considered to be
 * part of the string.
 * @s: string
 * @c: character
 * Return: a pointer to the located character, or a null pointer
 * if the character does not occur in the string.
 **/
char *my_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

/**
 * my_strcspn - computes the length of the maximum segment of the string
 * pointed to by s1which consists entirely of characters not from the
 * string pointed to by s2.
 * @s1: string to check
 * @s2: string useful to compare
 * Return: the length of the segment.
 **/
size_t my_strcspn(const char *s1, const char *s2)
{
	size_t ret = 0;

	while (*s1)
	{
		if (my_strchr(s2, *s1))
			return (ret);
		s1++, ret++;
	}
	return (ret);
}

/**
 * my_strspn - computes the length of the maximum initial segment of the string
 * pointed to by s1 which consists entirely of characters from the string
 * pointed to by s2.
 * @s1: strint to compute the lengh
 * @s2: string delimit
 * Return: the length of the segment.
 **/
size_t my_strspn(const char *s1, const char *s2)
{
	size_t ret = 0;

	while (*s1 && my_strchr(s2, *s1++))
		ret++;
	return (ret);
}

/**
 * my_strtok - breaks the string s1 into tokens and make null-terminated
 * Delimiter-Characters at the beginning and end
 * of str are skipped. On each subsequent call delim may change.
 * @str: string to tokenize
 * @delim: string with the character that delimit srt.
 * Return: the first/next token if possible, a null-pointer otherwise.
 **/
char *my_strtok(char *str, const char *delim)
{
	static char *p;

	if (str)
		p = str;
	else if (!p)
		return (0);
	str = p + my_strspn(p, delim);
	p = str + my_strcspn(str, delim);
	if (p == str)
		return (p = 0);
	p = *p ? *p = 0, p + 1 : 0;
	return (str);
}
