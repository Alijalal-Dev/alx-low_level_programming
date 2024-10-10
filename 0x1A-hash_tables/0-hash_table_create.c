#include "hash_tables.h"

/**
 * hash_table_create - Create a new hash table with a given size.
 * @size: The size of the new hash table.
 * Return: A pointer to the newly created hash table, or NULL on failure.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht = NULL;
	unsigned long int idx = 0;

	ht = malloc(sizeof(hash_table_t));
	if (!ht)
		return (NULL);
	ht->size = size;
	ht->array = malloc(sizeof(hash_table_t *) * size);
	if (!ht->array)
		return (NULL);
	for (; idx < size; ++idx)
		ht->array[idx] = NULL;
	return (ht);
}
