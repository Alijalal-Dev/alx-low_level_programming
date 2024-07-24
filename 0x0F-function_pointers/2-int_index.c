#include "function_pointers.h"

/**
 * int_index - searches for a integer
 * @array: array of integers
 * @size: the size of the array
 * @cmp: pointer to function
 * Return: 0 (Success)
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (array && size && cmp)
		while (i < size)
		{
			if (cmp(array[i]))
				return (i);
			i++;
		}
	return (-1);
}
