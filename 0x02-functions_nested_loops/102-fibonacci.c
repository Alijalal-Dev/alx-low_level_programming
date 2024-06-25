#include <stdio.h>

/**
 * main - Entry point, prints the first 50 Fibonacci numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	unsigned long a = 1, b = 2, next;

	printf("%lu, %lu", a, b);

	for (i = 2; i < 50; i++)
	{
		next = a + b;
		printf(", %lu", next);
		a = b;
		b = next;
	}

	printf("\n");
	return (0);
}
