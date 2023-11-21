#include "sort.h"

void counting_sort(int *array, size_t size)
{
	int max = 0;
	size_t i;
	size_t k;
	int index;
	int *counting_array;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	k = max + 1;
	counting_array = (int *) malloc(k * sizeof(int));
	for (i = 0; i < k; i++)
		counting_array[i] = 0;

	for (i = 0; i < size; i++)
		counting_array[array[i]]++;

	print_array(counting_array, k);
	printf("\n");

	index = 0;
	for (i = 0; i < k; i++)
		while (counting_array[i]-- > 0)
			array[index++] = i;
	free(counting_array);
}
