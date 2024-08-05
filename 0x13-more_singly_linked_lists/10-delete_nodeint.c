#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node at the given index
 * @head: pointer to the head
 * @index: index of the node to delete
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *node, *prev_node;
	unsigned int idx = 0;

	if (!head || !*head)
		return (-1);
	node = *head;
	if (!index)
	{
		*head = (*head)->next;
		free(node);
		return (1);
	}
	while (node)
	{
		if (idx == index)
		{
			prev_node->next = node->next;
			free(node);
			return (1);
		}
		idx++;
		prev_node = node;
		node = node->next;
	}
	return (-1);
}
