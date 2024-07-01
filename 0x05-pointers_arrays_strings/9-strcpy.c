#include "main.h"
/**
 * *_strcpy - copies the string pointer to by src,
 *		including the terminating null byte,
 *		to the butter pointer to by des.
 * @src: source string
 * @dest: destination to copy the string
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');
	return (dest);
}
