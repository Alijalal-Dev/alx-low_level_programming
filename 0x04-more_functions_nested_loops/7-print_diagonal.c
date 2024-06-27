#include "main.h"

/**
 * print_diagonal - prints a diagonal line of backslashes in the terminal
 * @n: number of times the character '\' should be printed
 */
void print_diagonal(int n)
{
	if (n <= 0)
	{
		_putchar('\n');  /* If n is 0 or less, print only a newline */
	}
	else
	{
		int i, spaces;

		for (i = 0; i < n; i++)
		{
			for (spaces = 0; spaces < i; spaces++)
			{
				_putchar(' ');  /* Print spaces before printing the backslash */
			}
			_putchar('\\');  /* Print the backslash character */
			_putchar('\n');  /* Move to the next line after printing each backslash */
		}
	}
}
