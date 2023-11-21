#include "lists.h"

/**
* print_listint -prints all the elements of a listint_t list.
* @h: The head of the list.
*
* Return: The number of nodes in the list.
*/

size_t print_listint(const listint_t *h)
{
	size_t count = 0;
	const listint_t *node = h;

	while (node != NULL)
	{
	printf("%d\n", node->n);
	++count;
	node = node->next;
	}

	return (count);
}
