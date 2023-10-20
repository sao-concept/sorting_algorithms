#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
size_t _pass, _index;
int _temp;
int _is_sorted = 0;

if (array == NULL || size < 2)
return;

for (_pass = 0; _pass < size - 1 && !_is_sorted; _pass++)
{
_is_sorted = 1;
for (_index = 0; _index < size - _pass - 1; _index++)
{
if (array[_index] > array[_index + 1])
{
_temp = array[_index];
array[_index] = array[_index + 1];
array[_index + 1] = _temp;
print_array(array, size);
_is_sorted = 0;
}
}
}
}
