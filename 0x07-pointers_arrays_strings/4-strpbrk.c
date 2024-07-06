#include "main.h"
/**
 * _strpbrk - function that searches a string for any of set of bytes
 * @s: string to search in
 * @accept: string to search for
 * Return: pointer to the byte in @s that matches
 *	one of the bytes in @accept, or null if not found
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
		for (j = 0; accept[j] != '\0'; j++)
			if (accept[j] == s[i])
				return (&s[i]);
	return (NULL);
}
