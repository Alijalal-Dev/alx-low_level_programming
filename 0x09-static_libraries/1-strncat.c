#include "main.h"
/**
 * _strncat - function that concatenates two strings
 * @dest: the destination string
 * @src: the source string
 * @n: most number bytes from src
 * Return: @dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int count = 0, i;

	while (dest[count])
		count++;
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[count + i] = src[i];
	dest[count + i] = '\0';
	return (dest);
}
