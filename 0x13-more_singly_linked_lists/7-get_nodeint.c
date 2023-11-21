#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: The head of the list.
 * @index: The index of the node, starting at 0.
 *
 * Return: The nth node, or NULL if the node does not exist.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
listint_t *node;
unsigned int i;

if (head == NULL || index == 0)
return (head);
node = head;
i = 0;
while (node != NULL)
if (i == index)
return (node);
i++;
node = node->next;
return (NULL);
}
