#include "lists.h"
/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list.
 * @head: The head of the list.
 * @n: The data to store in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node;

/* Allocate memory for the new node*/
new_node = (listint_t *)malloc(sizeof(listint_t));
if (new_node == NULL)
{
printf("Error: malloc failed\n");
return (NULL);
}
/* Set the data of the new node*/
new_node->n = n;
/* Make the new node point to the current head of the list*/
new_node->next = *head;
/* Update the head of the list to point to the new node*/
*head = new_node;
return (new_node);
}
