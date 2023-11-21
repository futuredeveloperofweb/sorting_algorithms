#include "sort.h"
#define parent(x) (((x) - 1) / 2)
#define left(x) (((x) * 2) + 1)

/**
 * swap - swap two elements
 * @array: the array to sort
 * @size: the size of the array
 * @A: the first element
 * @B: the second element
 * Return: nothing
 */
void swap(int *array, size_t size, int *A, int *B)
{
	if (*A != *B)
	{
		*A = *A + *B;
		*B = *A - *B;
		*A = *A - *B;
		print_array(array, size);
	}
}

/**
 * sift - for  implementation
 * @array: the array to sort
 * @size: the size of the array
 * @start: the beginning of the array
 * @end: the end of the array
 * Return: void
 */
void sift(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, s, ch;

	while (left(root) <= end)
	{
		ch = left(root);
		s = root;
		if (array[s] < array[ch])
			s = ch;
		if (ch + 1 <= end && array[s] < array[ch + 1])
			s = ch + 1;
		if (s == root)
			return;
		swap(array, size, &array[root], &array[s]);
		root = s;
	}
}

/**
 * heap - put the heap in place
 * @array: the array to sort
 * @size: size of the array
 * Return: nothing
 */
void heap(int *array, size_t size)
{
	ssize_t start;

	start = parent(size - 1);
	while (start >= 0)
	{
		sift(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - sorts an array of integers using the Heap sort algorithm
 * @array: the array to sort
 * @size: the size of array
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;
	heap(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(array, size, &array[end], &array[0]);
		end--;
		sift(array, 0, end, size);
	}
}
