#include "sort.h"

/**
 * get_max_gap - get the max gap
 * @size: the size of the array
 * Return: size_t
 */
size_t get_max_gap(size_t size)
{
        size_t n;

        n = 1;
        while (n < size)
                n = n * 3 + 1;
        return ((n - 1) / 3);
}

/**
 * shell_sort - sorts an array of integers using the Shell sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: nothing
 */
void shell_sort(int * array, size_t size)
{
        size_t gap, i, j;
        int tmp;

        if (!array || !size)
                return;
        for (gap = get_max_gap(size); gap; gap = (gap - 1) / 3)
        {
                for (i = gap; i < size; i++)
                {
                        tmp = array[i];
                        for (j = i; j > gap - 1 && array[j - gap] > tmp; j = j - gap)
                                array[j] = array[j - gap];
                        array[j] = tmp;
                }
                print_array(array, size);
        }
}
