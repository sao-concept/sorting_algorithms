#include "sort.h"

/**
 * selection_sort - This function Sorts an array of integers in ascending
 * order using the Selection Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
size_t idx, idx2, min_index;

if (array == NULL || size < 2)
return;

for (idx = 0; idx < size - 1; idx++)
{
min_index = idx;
for (idx2 = idx + 1; idx2 < size; idx2++)
{
if (array[idx2] < array[min_index])
min_index = idx2;
}

if (min_index != idx)
{
_swap(&array[idx], &array[min_index]);
print_array(array, size);
}
}
}

/**
 * _swap - This function swap two numbers
 * @num1: 1st integer parameter
 * @num2: 2nd integer parameter
 *
 * Return: void
 **/
void _swap(int *num1, int *num2)
{
int _temp;
_temp = *num1;
*num1 = *num2;
*num2 = _temp;
}
