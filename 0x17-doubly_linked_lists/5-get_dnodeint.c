#include "lists.h"

/**
 * get_dnodeint_at_index - Return node at index in a doubly linked list.
 * @head: Pointer to the list's head.
 * @index: Index of the desired node.
 *
 * Return: Node at the specified index, or NULL if not found.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *node = NULL;

	if (!head)
		return (NULL);
	node = head;
	if (node->prev)
		node = node->prev;
	while (i < index && node)
	{
		node = node->next;
		i++;
	}
	return (node);
}
