#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the minimum number of coins
 *	to make change for an amount of money.
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int i, leastcents = 0, money = atoi(argv[1]);
		int cents[] = {25, 10, 5, 2, 1};

		for (i = 0; i < 5; i++)
		{
			if (money >= cents[i])
			{
				leastcents += money / cents[i];
				money %= cents[i];
				if (money % cents[i] == 0)
					break;
			}
		}
		printf("%d\n", leastcents);
	}
	else
		return (printf("Error\n"), 1);
	return (0);
}
