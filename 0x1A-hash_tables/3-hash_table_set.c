#include "hash_tables.h"

/**
 * hash_table_set - Add an element to a hash table or update its value.
 * @ht: The hash table where the element will be added or updated.
 * @key: The key of the element to be added or updated.
 * @value: The value associated with the key.
 *
 * Return: 1 on success, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node = NULL;
	char *value_cp = NULL;
	unsigned long int idx = 0, i = 0;

	if (!ht || !key || *key == '\0' || !value)
		return (0);
	value_cp = strdup(value);
	if (!value_cp)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	for (i = idx; ht->array[i]; ++i)
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = value_cp;
			return (1);
		}
	new_node = malloc(sizeof(hash_table_t));
	if (!new_node)
	{
		free(value_cp);
		return (0);
	}
	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		return (0);
	}
	new_node->value = value_cp;
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;
	return (1);
}
