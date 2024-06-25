#include <stdio.h>

/**
 * sum_multiples - computes the sum of all multiples of 3 or 5 below 1024
 */
void sum_multiples(void)
{
	int i;
	int sum = 0;

	for (i = 0; i < 1024; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}

	printf("%d\n", sum);
}
