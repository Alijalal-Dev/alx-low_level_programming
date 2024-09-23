#include "main.h"
/**
 * _strchr - function that locates a character in a string
 * @s: the string to seach in
 * @c: the character to search for
 * Return: the pointer to the first occurrence
 *	or null if the charcter is not found
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return (s + i);
	if (s[i] == c)
		return (s + i);
	return (NULL);
}
