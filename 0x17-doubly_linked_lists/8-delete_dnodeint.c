#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at a specified index in a
 *                                      doubly linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to delete.
 *
 * Return: 1 on success, -1 on failure.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node = NULL;
	size_t idx = 0;

	if (!head || !(*head))
		return (-1);
	node = *head;

	if (index == 0)
	{
		if (node->next)
		{
			*head = node->next;
			(*head)->prev = NULL;
		}
		else
			*head = NULL;

		free(node);
		return (1);
	}
	while (idx++ < index && node)
		node = node->next;
	if (!node)
		return (-1);
	else if (node->prev && node->next)
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
		free(node);
	}
	else if (!node->next)
	{
		node->prev->next = NULL;
		free(node);
	}

	return (1);
}
