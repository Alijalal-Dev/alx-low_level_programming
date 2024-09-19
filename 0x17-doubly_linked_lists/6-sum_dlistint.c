#include "lists.h"

/**
 * sum_dlistint - Computes the sum of all the data in a doubly linked list.
 * @head: A pointer to the head of the doubly linked list.
 *
 * Return: The sum of all data in the list.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *node;

	if (!head)
		return (0);
	node = head;

	if (!node->next)
		while (node)
		{
			sum += node->n;
			node = node->prev;
		}
	else if (!node->prev)
		while (node)
		{
			sum += node->n;
			node = node->next;
		}
	else
	{
		while (node->prev)
			node = node->prev;
		while (node)
		{
			sum += node->n;
			node = node->next;
		}
	}
	return (sum);
}
