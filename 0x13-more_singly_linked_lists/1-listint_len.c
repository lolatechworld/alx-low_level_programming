#include "lists.h"

/**
 * listint_len - Counts the number of elements in a listint_t list.
 * @h: The head of the list.
 *
 * Return: The number of elements in the list.
 */

size_t listint_len(const listint_t *h)
{
size_t count = 0;
const listint_t *node = h;
while (node != NULL)
{
++count;
node = node->next;
}
return (count);
}
