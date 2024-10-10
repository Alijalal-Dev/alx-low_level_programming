#include "hash_tables.h"

/**
 * shash_table_create - Create a new sorted hash table
 * with a given size.
 *
 * @size: The size of the new sorted hash table.
 *
 * Return: A pointer to the newly created sorted hash table,
 * or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * make_shash_node - Create a new sorted hash table node
 * with a given key and value.
 *
 * @key: The key for the new node.
 * @value: The value for the new node.
 *
 * Return: A pointer to the newly created sorted hash table node,
 * or NULL on failure.
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *sh_node = NULL;

	sh_node = malloc(sizeof(shash_node_t));
	if (!sh_node)
		return (NULL);
	sh_node->key = strdup(key);
	if (!sh_node->key)
	{
		free(sh_node);
		return (NULL);
	}
	sh_node->value = strdup(value);
	if (!sh_node->value)
	{
		free(sh_node->key);
		free(sh_node);
		return (NULL);
	}
	sh_node->next = sh_node->snext = sh_node->sprev = NULL;
	return (sh_node);
}

/**
 * add_to_sorted_list - Add a sorted hash table node
 * to a sorted list within the table.
 *
 * @table: The sorted hash table.
 * @node: The node to be added to the sorted list.
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *tmp = NULL;

	if (!table->shead && !table->stail)
	{
		table->shead = table->stail = node;
		return;
	}
	tmp = table->shead;
	for (; tmp; tmp = tmp->snext)
		if (strcmp(node->key, tmp->key) < 0)
		{
			node->snext = tmp;
			node->sprev = tmp->sprev;
			tmp->sprev = node;
			if (node->sprev)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - Add an element to a sorted hash table
 * or update its value.
 *
 * @ht: The sorted hash table where the element will be added or updated.
 * @key: The key of the element to be added or updated.
 * @value: The value associated with the key.
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmp;
	char *value_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		tmp = tmp->snext;
	}
	new = make_shash_node(key, value);
	if (!new)
		return (0);
	new->next = ht->array[index];
	ht->array[index] = new;
	add_to_sorted_list(ht, new);
	return (1);
}

/**
 * shash_table_get - Retrieve the value associated
 * with a given key from a sorted hash table.
 *
 * @ht: The sorted hash table to search for the key.
 * @key: The key to look up in the sorted hash table.
 *
 * Return: The value associated with the key,
 * or NULL if the key is not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Print the contents of a sorted hash table.
 * @ht: The sorted hash table to be printed.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Print the contents
 * of a sorted hash table in reverse order.
 * @ht: The sorted hash table to be printed in reverse order.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Delete a sorted hash table
 * and its elements.
 * @ht: The sorted hash table to be deleted.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *tmp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}

	free(head->array);
	free(head);
}
