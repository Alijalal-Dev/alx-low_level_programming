#include "main.h"

/**
 * nbword - counts the number of words in a string
 * @s: string
 * Return: number of words
 */
int nbword(char *s)
{
	int i, n = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == ' ')
		{
			if (s[i + 1] != ' ' && s[i + 1] != '\0')
				n++;
		}
		else if (i == 0)
			n++;
	}
	n++;
	return (n);
}

/**
 * strtow - splites a string into words
 * @str: string
 * Return: array of words
 */

char **strtow(char *str)
{
	int i = 0, j, k, l, n = 0, wc = 0;
	char **w;

	if (str == NULL || *str == '\0')
		return (NULL);
	n = nbword(str);
	if (n == 1)
		return (NULL);
	w = (char **)malloc(sizeof(char *) * n);
	if (w == NULL)
		return (NULL);
	w[n - 1] = NULL;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			for (j = 1; str[i + j] != ' ' && str[i + j]; j++)
				;
			j++;
			w[wc] = (char *)malloc(j * sizeof(char));
			j--;
			if (w[wc] == NULL)
			{
				for (k = 0; k < wc; k++)
					free(w[wc]);
				free(w);
				return (NULL);
			}
			for (l = 0; l < j ; l++)
				w[wc][l] = str[i + l];
			w[wc][l] = '\0';
			wc++;
			i += j;
		}
		else
			i++;
	}
	return (w);
}
