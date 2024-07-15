#include "main.h"

/**
 * create_array - function that creates an array of chars,
 *		and initializes it with a specific char.
 * @size: size of the array
 * @c: char to initialize
 * Return: pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *ptr = malloc(size);

	if (size == 0 || ptr == 0)
		return (NULL);
	while (size--)
		ptr[size] = c;
	return (ptr);
}
