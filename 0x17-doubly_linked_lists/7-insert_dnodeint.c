#include "lists.h"

/**
 * new_node - Creates a new node with the given integer value.
 * @n: The integer value to be stored in the new node.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */
static dlistint_t *new_node(int n)
{
	dlistint_t *node;

	node = malloc(sizeof(dlistint_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->next = node->prev = NULL;

	return (node);
}

/**
 * insert_dnodeint_at_index - Inserts a new node at a specified index in a
 *                  doubly linked list.
 * @h: A pointer to a pointer to the head of the doubly linked list.
 * @idx: The index at which the new node should be inserted.
 * @n: The integer value to be stored in the new node.
 *
 * Return: A pointer to the newly inserted node, or NULL on failure.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node = NULL, *new = NULL;
	unsigned int i = 0;

	if (!(*h) && !idx)
		return (*h = new_node(n));
	else if (!idx)
		return (*h = add_dnodeint(h, n));
	node = *h;
	if (node->prev)
		while (node->prev)
			node = node->prev;
	else if (!node->next)
		while (node->prev)
			node = node->prev;

	while (++i < idx && node->next)
		node = node->next;
	if (i < idx)
		return (NULL);
	else if (node)
	{
		new = new_node(n);
		if (!new)
			return (NULL);
		if (node->next)
			node->next->prev = new;
		new->prev = node;
		new->next = node->next;
		node->next = new;
	}
	return (new);
}
