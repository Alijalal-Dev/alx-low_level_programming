#include "main.h"

/**
 * set_bit - Sets the bit at a given index to 1.
 * @n: A pointer to the number in which to set the bit.
 * @index: The index of the bit to be set.
 * Return: 1 if the operation is successful, or -1 if index is out of bounds.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);
	return (!!(*n |= 1L << index));
}
