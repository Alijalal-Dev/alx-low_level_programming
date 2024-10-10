#include "hash_tables.h"

/**
 * hash_table_delete - Delete a hash table and its elements.
 *
 * @ht: The hash table to be deleted.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *node = NULL, *tmp = NULL;
	unsigned long int idx = 0;

	for (; idx < ht->size; ++idx)
		if (ht->array[idx])
		{
			node = ht->array[idx];
			while (node)
			{
				tmp = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = tmp;
			}
		}
	free(head->array);
	free(head);
}
