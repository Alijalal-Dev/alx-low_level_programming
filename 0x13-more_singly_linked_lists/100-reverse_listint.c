#include "lists.h"

/**
 * reverse_listint - reverses a linked_list
 * @head: pointer to the head
 * Return: pointer to the head of the new linked_list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *node, *next;

	if (!head || !*head)
		return (NULL);
	node = *head;
	*head = NULL;
	while (node)
	{
		next = node->next;
		node->next = *head;
		*head = node;
		node = next;
	}
	return (*head);
}
