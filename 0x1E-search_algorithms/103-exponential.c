#include "search_algos.h"

/**
 * __binary_search - Searches for a value in a sorted array
 *		using binary search algorithm. This is a helper function
 *		used for internal binary search operations.
 *
 * @array: Pointer to the first element of the sorted array.
 * @left: Index of the left boundary of the search range.
 * @right: Index of the right boundary of the search range.
 * @value: Value to search for in the array.
 *
 * Return: Index of the first occurrence
 *		of @value in the specified range of @array, or -1 if not found.
 */
int __binary_search(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		i = left + (right - left) / 2;
		if (array[i] == value)
			return (i);
		if (array[i] > value)
			right = i - 1;
		else
			left = i + 1;
	}

	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array
 *		using exponential search algorithm.
 *
 * @array: Pointer to the first element of the sorted array.
 * @size: Number of elements in the array.
 * @value: Value to search for in the array.
 *
 * Return: Index of the first occurrence
 *		of @value in @array, or -1 if not found.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (i = 1; i < size && array[i] <= value; i = i * 2)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}

	right = i < size ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, right);
	return (__binary_search(array, i / 2, right, value));
}
