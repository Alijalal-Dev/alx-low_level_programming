#include "main.h"
#include <stdio.h>

/**
 * isDelimiter - determines whether the charachater is a delimiter or not
 * @ch: charachater to check
 * Return: 1 if true, 0 if false
 */

int isDelimiter(char ch)
{
	int i;
	char delimiter[] = " \t\n,;.!?\"(){}";

	for (i = 0; i < 12; i++)
		if (ch == delimiter[i])
			return (1);
	return (0);
}

/**
 * cap_string - function that capitalizes all words of a string
 * @str: string to capitalize its words
 * Return: @str
 */
char *cap_string(char *str)
{
	int i = 0, foundDelimiter = 1;

	while (str[i] != '\0')
	{
		if (isDelimiter(str[i]))
			foundDelimiter = 1;
		else if ((str[i] >= 97 && str[i] <= 122) && foundDelimiter)
		{
			str[i] -= 32;
			foundDelimiter = 0;
		}
		else
			foundDelimiter = 0;
		i++;
	}
	return (str);
}
