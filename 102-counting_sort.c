#include "sort.h"
/**
 * counting_sort - an implementation of the counting sort
 * on an array of integers >= 0
 * @array: array to be sorted
 * @size: size of the array
 * Returns: nothing
*/
void counting_sort(int *array, size_t size)
{
	size_t i, j, count;
	int *count_array, *sorted_array, max, number;

	for (i = 0, max = array[0]; i < size; i++)
		(array[i] > max) ? max = array[i] : max;
	count_array = malloc(sizeof(int) * (max + 1));
	if (count_array == NULL)
		return;
	for (i = 0; i < (size_t)max + 1; i++)
		count_array[i] = 0;
	for (i = 0; i < size; i++)
	{
		number = array[i];
		count = 0;
		if (count_array[number] != 0)
			continue;
		for (j = 0; j < size; j++)
			(array[j] == number) ? count++ : count;
		count_array[number] = count;
	}
	for (i = 0; i < (size_t)max + 1; i++)
	{
		if (i == 0)
			continue;
		count_array[i] = count_array[i] + count_array[i - 1];
	}
	print_array(count_array, max + 1);
	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}
	for (i = 0; i < size; i++)
		sorted_array[--count_array[array[i]]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	free(sorted_array);
	free(count_array);
}
