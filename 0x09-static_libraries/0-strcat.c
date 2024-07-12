#include "main.h"
/**
 * _strcat - function that concatenates two strings
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 * Return: pointer to resulting string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (dest[i])
		i++;
	for (j = 0; src[j] != '\0'; j++)
		dest[i++] = src[j];
	return (dest);
}
