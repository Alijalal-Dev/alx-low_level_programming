#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *current, *end;

	if (!head)
		return (NULL);
	for (end = head->next; end; end = end->next)
	{
		if (end == end->next)
			return (end);
		for (current = head; current != end; current = current->next)
			if (current == end->next)
				return (end->next);
	}
	return (NULL);
}
