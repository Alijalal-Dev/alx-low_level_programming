#include "main.h"
/**
 * _strlen_recursion - function that returns the length of a string
 * @s: the string to get it's length
 * Return: length of @s
 */
int _strlen_recursion(char *s)
{
	int length = 0;

	if (*s != '\0')
		length += _strlen_recursion(s + 1) + 1;
	return (length);
}
