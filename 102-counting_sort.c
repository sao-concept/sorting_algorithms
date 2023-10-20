#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - This function sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
int _max = 0;
size_t idx, idx2;
int *_count, *_output;

if (array == NULL || size < 2)
return;

for (idx = 0; idx < size; idx++)
{
if (array[idx] > _max)
_max = array[idx];
}

_count = malloc(sizeof(int) * (_max + 1));
_output = malloc(sizeof(int) * size);

if (_count == NULL || _output == NULL)
{
free(_count);
free(_output);
return;
}

for (idx = 0; idx <= (size_t)_max; idx++)
_count[idx] = 0;

for (idx = 0; idx < size; idx++)
_count[array[idx]]++;

for (idx = 1; idx <= (size_t)_max; idx++)
_count[idx] += _count[idx - 1];

for (idx2 = size - 1; (int)idx2 >= 0; idx2--)
{
_output[_count[array[idx2]] - 1] = array[idx2];
_count[array[idx2]]--;
}

for (idx = 0; idx < size; idx++)
array[idx] = _output[idx];

print_array(_count, _max + 1);

free(_count);
free(_output);
}
