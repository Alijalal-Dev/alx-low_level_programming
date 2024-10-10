#include "hash_tables.h"

/**
 * hash_table_print - Print the contents of a hash table.
 *
 * @ht: The hash table to be printed.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node = NULL;
	unsigned long int idx = 0;
	unsigned char comma_flag = 0;

	if (!ht)
		return;
	printf("{");
	for (; idx < ht->size; ++idx)
		if (ht->array[idx])
		{
			if (comma_flag)
				printf(", ");
			node = ht->array[idx];
			while (node)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node)
					printf(", ");
			}
			comma_flag = 1;
		}
	printf("}\n");
}
