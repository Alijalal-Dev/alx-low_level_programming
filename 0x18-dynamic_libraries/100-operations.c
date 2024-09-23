#include <stdio.h>

/**
 * add - Adds two integers
 * @a: The first integer
 * @b: The second integer
 *
 * Return: The sum of the two integers
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - Subtracts two integers
 * @a: The first integer
 * @b: The second integer
 *
 * Return: The result of subtracting the second integer from the first
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - Multiplies two integers
 * @a: The first integer
 * @b: The second integer
 *
 * Return: The product of the two integers
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * div - Divides two integers
 * @a: The numerator
 * @b: The denominator
 *
 * Return: The result of dividing the numerator by the denominator
 */
int div(int a, int b)
{
	if (!b)
	{
		printf("Error: Division by zero\n");
		return (0);
	}
	return (a / b);
}

/**
 * mod - Computes the remainder of dividing two integers
 * @a: The dividend
 * @b: The divisor
 *
 * Return: The remainder of dividing the dividend by the divisor
 */
int mod(int a, int b)
{
	if (!b)
	{
		printf("Error: Division by zero\n");
		return (0);
	}
	return (a % b);
}
