#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: the number to check
 *
 * Return: the last digit of @n
 */
int print_last_digit(int n)
{
	int last_digit = n % 10;

	if (last_digit < 0)
		last_digit = -last_digit;

	_putchar('0' + last_digit);

	return (last_digit);
}
