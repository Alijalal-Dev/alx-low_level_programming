#include "main.h"
/**
 * _atoi - convert a string to an integer
 * @s: string to convert it
 * Return: converted integer from the string
 */
int _atoi(char *s)
{
	unsigned int num = 0;
	int sign = 1;

	do {
		if (*s == '-')
			sign *= -1;
		else if (*s >= 48 && *s <= 57)
			num = (num * 10) + (*s - 48);
		else if (num > 0)
			break;
	} while (*s++);
	return (num * sign);
}
