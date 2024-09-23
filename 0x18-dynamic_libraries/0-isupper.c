#include "main.h"
/**
 * _isupper - chacks for uppercase character
 * @c: the character to check
 * Return: 1 if c is uppercase or 0
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
