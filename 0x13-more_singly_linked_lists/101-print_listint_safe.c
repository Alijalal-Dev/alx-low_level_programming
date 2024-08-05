#include "lists.h"

/**
 * new_list - Create a new list by appending an element to an existing list.
 * @list: Ptr to an array of ptrs to listint_t elements (existing list).
 * @size: Size of the existing list.
 * @new: Ptr to a listint_t element to be appended.
 * Return: Ptr to the new list (old elements + new), NULL if memory fails or
 *         if list is NULL and size is not 0.
 */

const listint_t **new_list(const listint_t **list,
		size_t size, const listint_t *new)
{
	const listint_t **newlist = malloc(sizeof(listint_t *) * size);
	size_t idx = 0;

	if (!newlist)
	{
		free(list);
		exit(98);
	}
	for (; idx < size - 1; idx++)
		newlist[idx] = list[idx];
	newlist[idx] = new;
	free(list);
	return (newlist);
}

/**
 * print_listint_safe - Prints a linked_list safely.
 * @head: pointer to the head.
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t idx, nbr = 0;
	const listint_t **list = NULL;

	while (head)
	{
		for (idx = 0; idx < nbr; idx++)
		{
			if (head == list[idx])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(list);
				return (nbr);
			}
		}
		nbr++;
		list = new_list(list, nbr, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (nbr);
}
