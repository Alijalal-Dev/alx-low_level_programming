#include "main.h"
/**
 * _strlen - returns the length of a string
 * @s: string paramater
 * Return: the length of s
 */
int _strlen(char *s)
{
	int length;

	for (length = 0; *s != '\0'; s++)
		++length;
	return (length);
}
