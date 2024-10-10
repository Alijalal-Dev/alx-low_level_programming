#include "hash_tables.h"

/**
 * hash_table_get - Retrieve the value associated
 * with a given key from a hash table.
 *
 * @ht: The hash table to search for the key.
 * @key: The key to look up in the hash table.
 *
 * Return: The value associated with the key,
 * or NULL if the key is not found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node = NULL;
	unsigned long int idx;

	if (!ht || !key || *key == '\0')
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);
	if (idx >= ht->size)
		return (NULL);
	node = ht->array[idx];
	while (node && strcmp(node->key, key) != 0)
		node = node->next;
	return (!node ? NULL : node->value);
}
