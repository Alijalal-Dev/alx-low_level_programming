#include "main.h"
/**
 * _memcpy - function that copies memory area
 * @dest: memory where to store
 * @src: memory from where to copie
 * @n: number of bytes to copie
 * Return: new array
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
