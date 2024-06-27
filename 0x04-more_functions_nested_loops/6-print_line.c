#include "main.h"

/**
 * print_line - prints a straight line of underscores in the terminal
 * @n: number of times the character '_' should be printed
 */
void print_line(int n)
{
	if (n <= 0)
	{
		_putchar('\n');  /* If n is 0 or less, print only a newline */
	}
	else
	{
		int i;

		for (i = 0; i < n; i++)
		{
			_putchar('_');  /* Print '_' n times */
		}
		_putchar('\n');  /* Print a newline after printing the underscores */
	}
}
