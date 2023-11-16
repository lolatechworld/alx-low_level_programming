#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct list_t
{
    char *str;
    size_t len;
    struct list_t *next;
} list_t;
// Betty declaration
list_t *head;

size_t print_list(const list_t *h)
{
    size_t n = 0;
    while (h)
    {
        if (!h->str)
        {
            printf("[0] (nil)\n");
        }
        else
        {
            printf("[%zu] %s\n", h->len, h->str);
        }
        n++;
        h = h->next;
    }
    return n;
}
