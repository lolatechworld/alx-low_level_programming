#include "lists.h"

/**
 * pop_listint - Deletes head node of a listint_t list, return node’s data
 * @head: The head of the list.
 *
 * Return: the head node’s data (n), or 0 if the list is empty.
 */

int pop_listint(listint_t **head)
{
listint_t *temp;
int data;

if (*head == NULL)
return (0);

temp = *head;
data = temp->n;
*head = temp->next;

free(temp);

return (data);
}
