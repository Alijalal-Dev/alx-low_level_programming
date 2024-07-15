#include "main.h"

/**
 * str_concat - concatenates two strings.
 * @s1: fist string
 * @s2: second string
 * Return: pointer to the newly string or NULL
 */

char *str_concat(char *s1, char *s2)
{
	int size1 = 0, size2 =  0, i;
	char *s;

	if (s1 == NULL)
		s1 = "\0";
	if (s2 == NULL)
		s2 = "\0";
	while (s1[size1] != '\0')
		size1++;
	while (s2[size2] != '\0')
		size2++;
	s = malloc(sizeof(char) * (size1 + size2 + 1));
	if (s == 0)
		return (NULL);
	for (i = 0; i < (size1 + size2); i++)
	{
		if (i < size1)
			s[i] = s1[i];
		else
			s[i] = s2[i - size1];
	}
	s[i] = '\0';
	return (s);
}
