#include "main.h"

/**
 * _strlen - length of a string
 * @s: string
 * Return: lenght
 */

int _strlen(char *s)
{
	int size;

	for (size = 0; s[size] != '\0'; size++)
		;
	return (size);
}

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: number of arguments
 * @av: argumants values
 * Return: pointer to a new string or null
 */

char *argstostr(int ac, char **av)
{
	int i, nc = 0, j, k = 0;
	char *s;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++, nc++)
		nc += _strlen(av[i]);
	s = malloc(sizeof(char) * (nc + 1));
	if (s == 0)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++, k++)
			s[k] = av[i][j];
		s[k] = '\n';
		k++;
	}
	s[k] = '\0';
	return (s);
}
