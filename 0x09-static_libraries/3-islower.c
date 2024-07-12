#include "main.h"
/**
 * _islower - check if character is lowercase
 * @ch: is the character to be checked
 * Return: Always 0 (Success)
 */
int _islower(int ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
