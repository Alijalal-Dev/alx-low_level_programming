#include "main.h"

/**
 * print_square - prints a square of '#' characters in the terminal
 * @size: size of the square
 */
void print_square(int size)
{
	if (size <= 0)
	{
		_putchar('\n');  /* If size is 0 or less, print only a newline */
	}
	else
	{
		int i, j;

		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				_putchar('#');  /* Print '#' characters to form the square */
			}
			_putchar('\n');  /* Move to the next line after printing each row */
		}
	}
}
