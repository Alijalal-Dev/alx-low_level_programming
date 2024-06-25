#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the number to create the times table up to (0 <= n <= 15)
 */
void print_times_table(int n)
{
	int i, j, product;

	if (n < 0 || n > 15)
		return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			product = i * j;
			if (j == 0)
				_putchar('0');
			else
			{
				_putchar(',');
				_putchar(' ');

				if (product < 10)
					_putchar(' ');

				if (product < 100)
					_putchar(' ');

				if (product >= 100)
					_putchar(product / 100 + '0');

				if (product >= 10)
					_putchar((product / 10) % 10 + '0');

				_putchar(product % 10 + '0');
			}
		}
		_putchar('\n');
	}
}
