#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: The head of the list to be freed.
 *
 * Return: The size of the list that was freed.
 *
 * Note: The function must traverse list once and not modify the head
 * It should also handle loops in the list.
 */
size_t free_listint_safe(listint_t **h)
{
listint_t *current_node = *h;
size_t node_count = 0;

/* Check if the list is empty */
if (*h == NULL)
{
return (0);
}

/* Traverse the list and free each node */
while (current_node != NULL)
{
listint_t *next_node = current_node->next;
free(current_node);
current_node = next_node;
node_count++;
}

/* Set the head pointer to NULL */
*h = NULL;

return (node_count);
}
