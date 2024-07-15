#include "main.h"

/**
 * _strdup - function that returns a pointer to a newly allocated space
 *	in memory, which contains a copy of the string given as a parameter.
 * @str: string to copy
 * Return: pointer to the newly string or NULL
 */

char *_strdup(char *str)
{
	int i, size;
	char *s;

	if (str == NULL)
		return (NULL);
	for (size = 0; str[size] != '\0'; size++)
		;
	s = malloc(size * sizeof(*str) + 1);
	if (s == 0)
		return (NULL);
	for (i = 0; i < size; i++)
		s[i] = str[i];
	return (s);
}
