#include "main.h"

/**
 * clear_bit - Clears the bit at a given index (sets it to 0).
 * @n: A pointer to the number in which to clear the bit.
 * @index: The index of the bit to be cleared.
 * Return: 1 if the operation is successful, or -1 if index is out of bounds.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);
	if (*n & 1L << index)
		*n ^= 1L << index;
	return (1);
}
