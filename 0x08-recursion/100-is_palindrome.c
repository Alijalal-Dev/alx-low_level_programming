#include "main.h"

/**
 * check - check for palindrome
 * @s: string to work with
 * @start: left index
 * @end: right index
 * @mod: check for middle character
 * Return: 0 or 1
 */
int check(char *s, int start, int end, int mod)
{
	if ((start == end && mod != 0) || (start == end + 1 && mod == 0))
		return (1);
	else if (s[start] != s[end])
		return (0);
	else
		return (check(s, start + 1, end - 1, mod));
}

/**
 * _strlen - return the length of the string
 * @s: the string to work with
 * Return: the length of @s
 */
int _strlen(char *s)
{
	int len = 0;

	if (*s != '\0')
		len += _strlen(s + 1) + 1;
	return (len);
}

/**
 * is_palindrome - function that returns 1 if a string
 *		is a palindrome and 0 if not.
 * @s: string to work with
 * Return: 1 or 0
 */
int is_palindrome(char *s)
{
	int len = _strlen(s);

	return (check(s, 0, len - 1, len % 2));
}
