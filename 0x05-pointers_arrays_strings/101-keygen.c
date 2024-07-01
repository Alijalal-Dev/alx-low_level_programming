#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 * Return: Always 0
 */

int main(void)
{
	int sum = 0;
	char ch;

	srand(time(NULL));
	do {
		ch = rand() % 128;
		sum += ch;
		putchar(ch);
	} while (sum <= 2645);
	putchar(2772 - sum);
	return (0);
}
