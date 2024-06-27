#include<stdio.h>
#include<math.h>
/**
 * main - Entry point
 * Return: always 0 (success)
 */
int main(void)
{
	int nb_prime, largest;
	long int nb = 612852475143;

	while (nb % 2 == 0)
		nb /= 2;

	for (nb_prime = 3; nb_prime <= sqrt(nb); nb_prime += 2)
	{
		while (nb % nb_prime == 0)
		{
			nb /= nb_prime;
			largest = nb_prime;
		}
	}

	if (nb > 2)
		largest = nb;
	printf("%d\n", largest);
	return (0);
}
