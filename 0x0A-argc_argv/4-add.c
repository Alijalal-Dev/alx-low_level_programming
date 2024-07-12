#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the sum of positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	int sum = 0;
	char *ch;

	while (--argc)
	{
		for (ch = argv[argc]; *ch; ch++)
			if (*ch < 48 || *ch > 57)
				return (printf("Error\n"), 1);
		sum += atoi(argv[argc]);
	}
	printf("%d\n", sum);
	return (0);
}
