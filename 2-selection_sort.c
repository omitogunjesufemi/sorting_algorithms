#include "sort.h"
/**
 * swap - swap values of two integer variables
 * @x: pointer to first variable
 * @y: pointer to second variable
 * Return: nothing
*/
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
/**
 * selection_sort - an implementation of the selection
 * sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: nothing
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, minIndex;

	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			swap(&array[minIndex], &array[i]);
			print_array(array, size);
		}
	}
}
