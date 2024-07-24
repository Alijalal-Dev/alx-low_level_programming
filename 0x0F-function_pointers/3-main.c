#include "3-calc.h"

/**
 * main - execute a simple operation between two integers
 * @argc: the number of arguments
 * @argv: the arguments values
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	int (*op_f)(int, int), a, b;

	if (argc != 4)
		printf("Error\n"), exit(98);
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	op_f = get_op_func(argv[2]);
	if (!op_f || argv[2][1] != '\0')
		printf("Error\n"), exit(99);
	if (!b && (argv[2][0] == '/' || argv[2][0] == '%'))
		printf("Error\n"), exit(100);
	printf("%d\n", op_f(a, b));
	return (0);
}
