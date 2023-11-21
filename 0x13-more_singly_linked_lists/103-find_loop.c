#include "lists.h"

/**
 * find_listint_loop - Finds the node where the loop starts in a linked list.
 * @head: The head of the list to be checked for a loop.
 *
 * Return: The address of the node where the loop starts, or NULL if no loop.
 *
 * Note: The function must not use malloc and it can only declare two variable
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *slow = head;
listint_t *fast = head;
/* Move the fast pointer twice as fast as the slow pointer */
while (fast != NULL && fast->next != NULL)
{
slow = slow->next;
fast = fast->next->next;
/* Check if the pointers meet, indicating a loop */
if (slow == fast)
{
break;
}
}
/* If the pointers met, find the starting node of the loop */
if (slow == fast)
{
slow = head;
while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}
return (slow);
}
/* No loop found */
return (NULL);
}
