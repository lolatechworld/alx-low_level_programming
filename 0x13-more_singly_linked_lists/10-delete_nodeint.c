#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes node at specified index in listint_t list.
 * @head: The head of the list.
 * @index: The index of the node to be deleted. Index starts at 0.
 *
 * Return: 1 if the node was successfully deleted, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *previous_node;
listint_t *node_to_delete;
unsigned int i;

/* Check if the list is empty or the index is 0 */
if (*head == NULL || index == 0)
{
(return -1);
}

/* Traverse the list to find the previous node */
i = 0;
previous_node = *head;
while (i < index - 1 && previous_node != NULL)
{
previous_node = previous_node->next;
i++;
}

/* Check if the index is valid*/
if (previous_node == NULL || previous_node->next == NULL)
{
(return -1);
}
/* Get the node to be deleted */
node_to_delete = previous_node->next;

/* Update the previous node's next pointer to skip the deleted node */
previous_node->next = node_to_delete->next;

/* Free the memory allocated to the deleted node */
free(node_to_delete);

return (1);
}
