#include <stdio.h>

/**
 * main - Entry point, computes and prints the sum of even Fibonacci numbers
 *        below 4,000,000
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long a = 1, b = 2, next, sum = 0;

	while (b < 4000000)
	{
		if (b % 2 == 0)
		{
			sum += b;
		}
		next = a + b;
		a = b;
		b = next;
	}

	printf("%lu\n", sum);
	return (0);
}
