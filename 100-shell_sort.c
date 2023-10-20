#include "sort.h"

/**
 * shell_sort - This function sorts an array of integers in ascending order using
 * the Shell sort algorithm with Knuth sequence.
 * @array: Parameter representing the array to be sorted.
 * @size: Parameter representing the size of the array.
 */
void shell_sort(int *array, size_t size)
{
    int _insert;
    size_t _gap, idx, idx2;

    if (array == NULL || size < 2)
        return;

    _gap = 1;
    while (_gap < size / 3)
        _gap = _gap * 3 + 1;

    for (; _gap > 0; _gap = (_gap - 1) / 3)
    {
        for (idx = _gap; idx < size; idx++)
        {
            _insert = array[idx];
            for (idx2 = idx; idx2 >= _gap && array[idx2 - _gap] > _insert; idx2 -= _gap)
            {
                array[idx2] = array[idx2 - _gap];
            }
            array[idx2] = _insert;
        }
        print_array(array, size);
    }
}
