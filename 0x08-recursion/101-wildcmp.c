#include "main.h"
/**
 * wildcmp - function that compares two string and returns
 *	1 if the strings can be considered identical,
 *	otherwire return 0
 * @s1: first string
 * @s2: string to check with
 * Return: 0 or 1
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0')
	{
		if (*s2 != '\0' && *s2 == '*')
			return (wildcmp(s1, s2 + 1));
		return (*s2 == '\0');
	}
	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	else if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
