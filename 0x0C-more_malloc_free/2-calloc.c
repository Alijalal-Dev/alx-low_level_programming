#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: memory area to be filled
 * @b: constant to be used
 * @n: number of byte to use
 * Return: pointer to the memory area @s
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *ptr = s;

	while (n--)
		*s++ = b;
	return (ptr);
}

/**
 * _calloc - funtion that allocates memory for an arry using malloc
 * @nmemb: array lenght
 * @size: size of each element
 * Return: pointer
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;

	if (size == 0 || nmemb == 0)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (ptr == NULL)
		return (NULL);
	_memset(ptr, 0, size * nmemb);
	return (ptr);
}
