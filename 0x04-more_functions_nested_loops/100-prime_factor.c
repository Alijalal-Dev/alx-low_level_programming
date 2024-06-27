#include <stdio.h>

/**
 * largest_prime_factor - finds the largest prime factor of a given number
 * @n: the number to find the largest prime factor of
 *
 * Return: the largest prime factor of n
 */
long largest_prime_factor(long n)
{
	long largest = -1;

	while (n % 2 == 0)
	{
		largest = 2;
		n /= 2;
	}

	for (long i = 3; i * i <= n; i += 2)
	{
		while (n % i == 0)
		{
			largest = i;
			n /= i;
		}
	}

	if (n > 2)
		largest = n;

	return (largest);
}

int main(void)
{
	long number = 612852475143;
	long largest_prime = largest_prime_factor(number);

	printf("%ld\n", largest_prime);

	return (0);
}
