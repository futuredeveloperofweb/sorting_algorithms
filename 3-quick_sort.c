#include "sort.h"

/**
 * swap - swap two position
 * @array: the array of integer
 * @size: the size of the array
 * @A: first value's add
 * @B: second value's add
 * Return: nothing
 */
void swap(int *array, size_t size, int *A, int *B)
{
	int tmp;

	if (*A != *B)
	{
		tmp = *B;
		*A = *B;
		*B = tmp;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto - partise the array
 * @array: the array to fix
 * @size: the size of the array
 * @lo: the low index
 * @hi: the height index
 * Return: size_t
 */
size_t lomuto(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	int i, j, pivot = array[hi];

	for (i = j = lo; j < hi; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[hi]);
	return (i);
}

/**
 * quicksort - sorts via lumoto schema
 * @array: the array to fix
 * @size: the size of the array
 * @lo: the low index
 * @hi: the height index
 * Return: size_t
 */
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	size_t p;

	if (lo < hi)
	{
		p = lomuto(array, size, lo, hi);
		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - sorts an array of integers using Quik sort algo
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
