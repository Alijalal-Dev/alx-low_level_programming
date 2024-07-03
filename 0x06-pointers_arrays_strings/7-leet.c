#include "main.h"
/**
 * leet - function that encodes a string into 1337
 * @str: the string to incode it
 * Return: @str
 */
char *leet(char *str)
{
	char *strp = str;
	char key[] = {'A', 'E', 'O', 'T', 'L'};
	int value[] = {4, 3, 0, 7, 1};
	unsigned int i;

	while (*str)
	{
		for (i = 0; i < 5; i++)
			if (*str == key[i] || *str == key[i] + 32)
				*str = 48 + value[i];
		str++;
	}
	return (strp);
}
