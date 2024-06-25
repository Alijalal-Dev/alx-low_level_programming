#include <stdio.h>

/**
 * nbrLength - returns the number of digits in a number
 * @nbr: the number to get its length
 *
 * Return: number of digits
 */
int nbrLength(unsigned long nbr)
{
	int length = 0;

	if (nbr == 0)
		return (1);

	while (nbr != 0)
	{
		nbr /= 10;
		length++;
	}
	return (length);
}

/**
 * main - Entry point, prints the first 98 Fibonacci numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int count, initial_zero;
	unsigned long first = 1, second = 2, next, max = 100000000;
	unsigned long first_part = 0, second_part = 0, next_part = 0;

	for (count = 1; count <= 98; count++)
	{
		if (first_part > 0)
			printf("%lu", first_part);
		initial_zero = nbrLength(max) - 1 - nbrLength(first);
		while (first_part > 0 && initial_zero > 0)
		{
			printf("%d", 0);
			initial_zero--;
		}
		printf("%lu", first);
		next = (first + second) % max;
		next_part = first_part + second_part + (first + second) / max;
		first = second;
		first_part = second_part;
		second = next;
		second_part = next_part;
		if (count != 98)
			printf(", ");
		else
			printf("\n");
	}
	return (0);
}
