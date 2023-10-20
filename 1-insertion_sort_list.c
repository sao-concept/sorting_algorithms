#include "sort.h"

/**
 * insertion_sort_list - This function sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: The double pointer to the head of the linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
listint_t *_current, *_temp;

if (list == NULL || *list == NULL)
return;

_current = (*list)->next;
while (_current != NULL)
{
_temp = _current->next;
while (_current->prev != NULL && _current->prev->n > _current->n)
{
_current->prev->next = _current->next;
if (_current->next != NULL)
_current->next->prev = _current->prev;
_current->next = _current->prev;
_current->prev = _current->prev->prev;
_current->next->prev = _current;
if (_current->prev == NULL)
*list = _current;
else
_current->prev->next = _current;
print_list(*list);
}
_current = _temp;
}
}
