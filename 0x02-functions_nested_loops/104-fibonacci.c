
#include <stdio.h>

/**
 * main - Entry point, prints the first 98 Fibonacci numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	unsigned long a = 1, b = 2, next;
	unsigned long a_half1, a_half2, b_half1, b_half2;
	unsigned long half1, half2;

	printf("%lu, %lu", a, b);

	for (i = 2; i < 98; i++)
	{
		if (b > 10000000000)
		{
			a_half1 = a / 10000000000;
			a_half2 = a % 10000000000;
			b_half1 = b / 10000000000;
			b_half2 = b % 10000000000;
			half1 = a_half1 + b_half1;
			half2 = a_half2 + b_half2;
			if (half2 > 10000000000)
			{
				half1 += 1;
				half2 %= 10000000000;
			}
			printf(", %lu%010lu", half1, half2);
			a = b;
			b = half1 * 10000000000 + half2;
		}
		else
		{
			next = a + b;
			printf(", %lu", next);
			a = b;
			b = next;
		}
	}

	printf("\n");
	return (0);
}
