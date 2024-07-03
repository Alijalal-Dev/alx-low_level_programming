#include "main.h"

/**
 * rev_string - reverse a string
 * @s: the string to reverse
 */
void rev_string(char *s)
{
	int i = 0, j = 0;
	char temp;

	while (*(s + i) != '\0')
		i++;
	i--;
	for (j = 0; j < i; j++, i--)
	{
		temp = *(s + j);
		*(s + j) = *(s + i);
		*(s + i) = temp;
	}
}

/**
 * infinite_add - function that adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer's pointer
 * @size_r: buffer size
 * Return: @r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int overflow = 0, i = 0, j = 0, digits = 0;
	int val1 = 0, val2 = 0, tempTotal = 0;

	while (*(n1 + i) != '\0')
		i++;
	while (*(n2 + j) != '\0')
		j++;
	i--;
	j--;
	if (j >= size_r || i >= size_r)
		return (0);
	while (j >= 0 || i >= 0 || overflow == 1)
	{
		if (i < 0)
			val1 = 0;
		else
			val1 = *(n1 + i) - 48;
		if (j < 0)
			val2 = 0;
		else
			val2 = *(n2 + j) - 48;
		tempTotal = val1 +  val2 + overflow;
		if (tempTotal >= 10)
			overflow = 1;
		else
			overflow = 0;
		if (digits >= (size_r - 1))
			return (0);
		*(r + digits) = (tempTotal % 10) + 48;
		digits++;
		i--;
		j--;
	}
	if (digits == size_r)
		return (0);
	*(r + digits) = '\0';
	rev_string(r);
	return (r);
}
