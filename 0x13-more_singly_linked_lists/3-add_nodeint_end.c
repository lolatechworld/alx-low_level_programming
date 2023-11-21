#include "lists.h"
/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: The head of the list.
 * @n: The data to store in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node;
listint_t *last_node;

/* Allocate memory for the new node */
new_node = (listint_t *)malloc(sizeof(listint_t));
if (new_node == NULL)
{
printf("Error: malloc failed\n");
return (NULL);
}

/* Set the data of the new node */
new_node->n = n;

/* If the list is empty, make the new node the head */
if (*head == NULL)
{
*head = new_node;
new_node->next = NULL;
return (new_node);
}

/* Traverse the list to find the last node */
last_node = *head;
while (last_node->next != NULL)
{
last_node = last_node->next;
}

/* Make the new node the last node */
last_node->next = new_node;
new_node->next = NULL;

return (new_node);
}
