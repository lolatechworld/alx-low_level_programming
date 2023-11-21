#include "lists.h"
/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL.
 * @head: The head of the list.
 */
void free_listint2(listint_t **head)
{
listint_t *freed;

if (head == NULL || *head == NULL)
return;

while (*head != NULL)
{
freed = *head;
*head = (*(head))->next;
free(freed);
}
*head = NULL;
}
