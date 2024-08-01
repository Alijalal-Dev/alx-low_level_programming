#include "lists.h"

/**
 * _strlen - Function to calculate the length of a string.
 * @s: The input string.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length])
		length++;
	return (length);
}

/**
 * print_list - prints a linked lists
 * @h: pointer to first node
 * Return: size of list
 */

size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
		printf("[%u] %s\n", !h->str ? 0 : h->len, h->str ? h->str : "(nil)"),
			h = h->next, i++;
	return (i);
}
