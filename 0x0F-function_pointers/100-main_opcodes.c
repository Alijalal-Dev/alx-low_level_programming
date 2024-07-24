#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function.
 * @argc: number of arguments
 * @argv: arguments values
 * Return: 0 (Success)
 */

int main(int argc, char **argv)
{
	int nb;
	char *ptr = (char *)main;

	if (argc != 2)
		printf("Error\n"), exit(1);
	nb = atoi(argv[1]);
	if (nb < 0)
		printf("Error\n"), exit(2);
	while (nb--)
		printf("%02hhx%s", *ptr++, nb ? " " : "\n");
	return (0);
}
