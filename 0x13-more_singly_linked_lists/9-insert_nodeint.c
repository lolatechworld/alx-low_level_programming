#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position in a listint_t list.
 * @head: The head of the list.
 * @idx: The index of the list where the new node should be added. Index starts at 0.
 * @n: The data to store in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 *
 * Note: If it is not possible to add the new node at the specified index, the function should not add the new node and return NULL.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node;
    listint_t *previous_node;
    unsigned int i;

    /* Allocate memory for the new node */
    new_node = (listint_t *)malloc(sizeof(listint_t));
    if (new_node == NULL) 
    {
        return NULL;
    }

    /* Set the data of the new node */
    new_node->n = n;

    /* Check if the list is empty or the index is 0 */
    if (*head == NULL || idx == 0) 
    {
        new_node->next = *head;
        *head = new_node;
        return *head;
    }

    /* Traverse the list to find the previous node */
    i = 0;
    previous_node = *head;
    while (i < idx - 1 && previous_node != NULL) 
    {
        previous_node = previous_node->next;
        i++;
    }

    /* Check if the index is valid */
    if (previous_node == NULL) 
    {
        free(new_node);
        return NULL;
    }

    /* Insert the new node after the previous node */
    new_node->next = previous_node->next;
    previous_node->next = new_node;

    return new_node;
}
