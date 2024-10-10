#include "hash_tables.h"


/**
 * key_index - Computes the index of a key in a hash table.
 * @key: The key to be hashed.
 * @size: The size of the hash table.
 *
 * Return: The index where the key should be stored in the hash table.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
