#include "lists.h"

/**
 * sum_listint - Calculates the sum of all the data (n) of a listint_t linked list.
 * @head: The head of the list.
 *
 * Return: The sum of the data in the list, or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
    int sum = 0;
    listint_t *node;

    if (head == NULL) {
        return 0;
    }

    node = head;
    while (node != NULL) {
        sum += node->n;
        node = node->next;
    }

    return sum;
}
