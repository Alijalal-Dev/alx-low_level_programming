#include "main.h"

/**
 * check_prime - check if the n can divide with a number less than it
 * @n: the base number
 * @other_n: to check with
 * Return: 0 or 1
 */
int check_prime(int n, int other_n)
{
	if (other_n >= n && n > 1)
		return (1);
	else if (n % other_n == 0 || n <= 1)
		return (0);
	else
		return (check_prime(n, other_n + 1));
}

/**
 * is_prime_number - function that returns 1 if the input integer
 *		is a prime number, otherwise return 0
 * @n: the integer to check
 * Return: 0 or 1
 */
int is_prime_number(int n)
{
	return (check_prime(n, 2));
}
