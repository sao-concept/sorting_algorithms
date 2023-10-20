#include "sort.h"

/**
 * cocktail_sort_list - This function sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *_temp;
char _swapped = 1;

if (list == NULL || *list == NULL)
return;
_temp = *list;
while (_swapped != 0)
{
_swapped = 0;
while (_temp->next != NULL)
{
if (_temp->next->n < _temp->n)
{
_swap_nodes(list, _temp);
_swapped = 1;
print_list(*list);
}
else
_temp = _temp->next;
}
if (_swapped == 0)
break;
_swapped = 0;
while (_temp->prev != NULL)
{
if (_temp->prev->n > _temp->n)
{
_swap_nodes(list, _temp->prev);
_swapped = 1;
print_list(*list);
}
else
_temp = _temp->prev;
}
}
}

/**
 * _swap_nodes - This function swaps a node with the next node in the list
 * @_list: double pointer to the beginning of the list
 * @_node: node to swap
 *
 * Return: void
 */
void _swap_nodes(listint_t **_list, listint_t *_node)
{
_node->next->prev = _node->prev;
if (_node->prev)
_node->prev->next = _node->next;
else
*_list = _node->next;
_node->prev = _node->next;
_node->next = _node->next->next;
_node->prev->next = _node;
if (_node->next)
_node->next->prev = _node;
}
