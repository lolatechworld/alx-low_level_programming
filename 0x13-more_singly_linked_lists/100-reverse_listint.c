#include "lists.h"

/**
 * reverse_listint - Reverses a given listint_t linked list.
 * @head: The head of the list to be reversed.
 *
 * Return: A pointer to the first node of the reversed list.
 *
 * Note: The function must not use more than one loop
 * only declare a maximum of two variables.
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *previous_node = NULL;
listint_t *current_node = *head;
listint_t *next_node;

while (current_node != NULL)
{
next_node = current_node->next;
current_node->next = previous_node;
previous_node = current_node;
current_node = next_node;
}

*head = previous_node;
return (*head);
}
