#include "main.h"

/**
 * string_nconcat - function that concatenates two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * @n: number of bytes from @s2 to concatenate
 * Return: pointer to the newly string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s;
	unsigned int i, j, s1_len, s2_len;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (s1_len = 0; s1[s1_len] != '\0'; s1_len++)
		;
	for (s2_len = 0; s2[s2_len] != '\0'; s2_len++)
		;
	if (n > s2_len)
		s = malloc(s1_len + s2_len + 1);
	else
		s = malloc(s1_len + n + 1);
	if (s == NULL)
		return (NULL);
	for (i = 0; s1[i] != '\0'; i++)
		s[i] = s1[i];
	for (j = 0; j < n && s2[j] != '\0'; j++, i++)
		s[i] = s2[j];
	s[i] = '\0';
	return (s);
}
