#include "sort.h"

/**
 * swap - swaping two elements
 */
static void swap(int *a, int *b, int *array, size_t size)
{
    int tmp;

    if (a == b || *a == *b)
        return;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
    print_array(array, size);
}

/**
 * lomuto_partitiron - lomuto patition scheme
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            swap(&array[i], &array[j], array, size);
            i++;
        }
    }

    swap(&array[i], &array[high], array, size);
    return (i);
}

/**
 * quick_sort_recursion - recursive quick sort
 */
static void quick_sort_recursion(int *array, int low, int high, size_t size)
{
    int p;

    if (low < high)
    {
        p = lomuto_partition(array, low, high, size);
        quick_sort_recursion(array, low, p - 1, size);
        quick_sort_recursion(array, p + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array of integers using the Quick sort algorithm
 * @array: array to sort
 * @size: size of an array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursion(array, 0, size - 1, size);
}