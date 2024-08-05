#include "lists.h"

/**
 * find_loop_in_list - Finds a loop in a linked list.
 * @head: Pointer to the head of the linked list.
 * Return: If a loop is found, the function returns a pointer to the node
 *         where the loop starts; otherwise, it returns NULL.
 */

listint_t *find_loop_in_list(listint_t *head)
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

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the head of the linked list
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *next, *lnode;
	size_t size;
	int loop = 1;

	if (!h || !*h)
		return (0);
	lnode = find_loop_in_list(*h);
	for (size = 0; (*h != lnode || loop) && *h; *h = next)
	{
		size++;
		next = (*h)->next;
		if (*h == lnode && loop)
		{
			if (lnode == lnode->next)
			{
				free(*h);
				break;
			}
			size++;
			next = next->next;
			free((*h)->next);
			loop = 0;
		}
		free(*h);
	}
	*h = NULL;
	return (size);
}
