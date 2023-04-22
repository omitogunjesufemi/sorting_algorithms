#include "sort.h"
/**
 * knuth - get appropriate knuth value for size
 * @size: size of array
 * Return: greatest value from knuth series < size
 */
size_t knuth(size_t size)
{
	size_t h;

	if (size <= 0)
		return 1;
	for (h = 0; h < size; h = h * 3 + 1)
		;
	return ((h - 1) / 3);
}
/**
 * swap - swap values of 2 integers
 * @x: pointer to first
 * @y: pointer to second
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
 * shell_sort - an implementation of the shell sort
 * uses the knuth sequence for gap
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	for (gap = knuth(size); gap > 0; gap = (gap - 1) / 3)
	{
		for (i = 0; i + gap < size; i++)
		{
			j = i;
			while (j >= 0 && array[j] > array[j + gap])
			{
				swap(&array[j], &array[j + gap]);
				j = j - gap;
			}
		}
		print_array(array, size);
	}
}
