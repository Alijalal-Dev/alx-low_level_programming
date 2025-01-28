#include "search_algos.h"

/**
 * binary_recursive - Searches for a value in a sorted array
 *		using binary search algorithm recursively.
 *		This is a helper function used for internal binary search operations.
 *
 * @array: Pointer to the first element of the sorted array.
 * @left: Index of the left boundary of the search range.
 * @right: Index of the right boundary of the search range.
 * @value: Value to search for in the array.
 *
 * Return: Index of the first occurrence
 *		of @value in the specified range of @array, or -1 if not found.
 */
int binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	i = left + (right - left) / 2;
	if (array[i] == value && (i == left || array[i - 1] != value))
		return (i);
	if (array[i] >= value)
		return (binary_recursive(array, left, i, value));
	return (binary_recursive(array, i + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array
 *		using binary search algorithm.
 *
 * @array: Pointer to the first element of the sorted array.
 * @size: Number of elements in the array.
 * @value: Value to search for in the array.
 *
 * Return: Index of the first occurrence
 *		of @value in @array, or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_recursive(array, 0, size - 1, value));
}
