#include "sort.h"

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void bubble_sort(int *array, size_t size)
{
	size_t i, j, swapped;

	for (i = 0; i < size; i++)
	{
		swapped = 0;
		for (j = 1; j < size - i; j++)
		{
			if (array[j] < array[j - 1])
			{
				swap(&array[j], &array[j - 1]);
				swapped++;
				print_array(array, size);
			}
		}
		if (swapped == 0)
		{
			return;
		}
	}
}