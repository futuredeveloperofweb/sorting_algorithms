#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * counting_sort - sort an array using counting algorithm.
  * @array: array to sort.
  * @size: the size of the array.
  * Return: Nothing.
  */
void counting_sort(int *array, size_t size)
{
	unsigned int i = 1;
	int *cnt = NULL, k = 0, j = 0;

	if (!array || size < 2)
		return;

	k = array[0];
	for (; i < size; i++)
		if (array[i] > k)
			k = array[i];

	cnt = malloc(sizeof(int) * (k + 1));
	if (!cnt)
		return;
	for (j = 0; j <= k; j++)
		cnt[j] = 0;
	for (i = 0; i < size; i++)
		cnt[array[i]] += 1;
	for (j = 0; j < k; j++)
	{
		cnt[j + 1] += cnt[j];
		printf("%d, ", cnt[j]);
	}
	cnt[j + 1] += cnt[j];
	printf("%d\n", cnt[j + 1]);
	for (i = 0; i < size; i++)
	{
		j = cnt[array[i]] - 1;
		if (array[i] != array[j])
		{
			k = array[i];
			array[i] = array[j];
			array[j] = k;
		}
	}
	free(cnt);
}
