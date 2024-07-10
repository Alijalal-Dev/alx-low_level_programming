/**
 * square - function that find the square root
 * @n: the base number
 * @val: the square root of @n
 * Return: @val
 */
int square(int n, int val)
{
	if (val * val == n)
		return (val);
	else if (val * val < n)
		return (square(n, val + 1));
	else
		return (-1);
}

/**
 * _sqrt_recursion - function that returns the natural
 *			square root of a number
 * @n: the number to work with
 * Return: the square root of @n
 */
int _sqrt_recursion(int n)
{
	return (square(n, 1));
}
