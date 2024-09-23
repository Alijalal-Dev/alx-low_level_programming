#include "main.h"
/**
 * _strstr - function that locates a substring
 * @haystack: string to search in
 * @needle: string to search for
 * Return: pointer to the beginning of the located
 *	substring, or nul int not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		int j = 0;

		for (; haystack[i + j] && needle[j] && haystack[i + j] == needle[j]; j++)
			;
		if (!needle[j])
			return (&haystack[i]);
	}
	return (NULL);
}
