#include "sort.h"

/**
 * merge_cmp - compare two elements before sorting
 * @array: the array to sort
 * @start: the index of the element to sort
 * @stop: the index of the element wher to stop
 * @new: the new array
 * Return: nothing
 */
void merge_cmp(int *array, size_t start, size_t stop, int *new)
{
	size_t i = start;
	size_t j, k, mid;

	j = mid = (start + stop) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, stop -  mid);
	for (k = start; k < stop; k++)
		if (i < mid && (j >= stop || array[i] <= array[j]))
			new[k] = array[i++];
		else
			new[k] = array[j++];
	printf("[Done]: ");
	print_array(new + start, stop - start);
}

/**
 * merge_top_down - sort both top and down
 * @array: the array to sort
 * @start: the top of the array
 * @stop: the down of the array
 * @new: the new output of the array
 * Return: nothing
 */
void merge_top_down(int *array, size_t start, size_t stop, int *new)
{
	size_t mid;

	mid = (start + stop) / 2;
	if (stop - start < 2)
		return;
	merge_top_down(new, start, mid, array);
	merge_top_down(new, mid, stop, array);
	merge_cmp(array, start, stop, new);
}

/**
 * merge_sort - sorts an array of integers using the Merge sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	int *new;
	size_t i;

	if (!array || size < 2)
		return;
	new = malloc(sizeof(int) * size);
	if (!new)
		return;
	for (i = 0; i < size; i++)
		new[i] = array[i];
	merge_top_down(new, 0, size, array);
	free(new);
}
