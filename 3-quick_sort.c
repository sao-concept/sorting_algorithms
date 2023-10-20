#include "sort.h"

/**
 * quick_sort - This function sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

  recurse_lomuto_sort(array, size, 0, size - 1);
}


/**
 * subset_lomuto_partition - This function order a subset of an array of integers using the
 * Lomuto partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @_left: The starting index of the subset to order.
 * @_right: The ending index of the subset to order.
 * 
 * Return: The final partition index.
 */
int subset_lomuto_partition(int *array, size_t size, int _left, int _right)
{
    int pivot = array[_right];
    int idx = _left - 1;
    int idx2;

    for (idx2 = _left; idx2 <= _right - 1; idx2++)
    {
        if (array[idx2] < pivot)
        {
            idx++;
            if (idx != idx2)
            {
                _swap(&array[idx], &array[idx2]);
                print_array(array, size);
            }
        }
    }

    if (array[idx + 1] != array[_right])
    {
        _swap(&array[idx + 1], &array[_right]);
        print_array(array, size);
    }

    return idx + 1;
}

/**
 * recurse_lomuto_sort - This function implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @_left: The starting index of the array partition to order.
 * @_right: The ending index of the array partition to order.
 */
void recurse_lomuto_sort(int *array, size_t size, int _left, int _right)
{
    if (_left < _right)
    {
        int _part = subset_lomuto_partition(array, size, _left, _right);
      recurse_lomuto_sort(array, size, _left, _part - 1);
      recurse_lomuto_sort(array, size, _part + 1, _right);
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
