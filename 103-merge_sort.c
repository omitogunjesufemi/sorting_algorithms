#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order by splitting
 * arrays into sub arrays, till it is a sub-array of length 1, then merge
 *
 * @array: Array to be sorted
 * @size: Array size
 *
 * It is implemented using the top-down merge sort algorithm
 */
void merge_sort(int *array, size_t size)
{
	recursive_array_division(array, size);
}

/**
 * sort_array - This sorts the left and right arrays in ascending order
 * @array: The main array
 * @left_array: The left array
 * @right_array: The right array
 */
void sort_array(int *array, int *left_array, int *right_array)
{
	int left_len, int right_len;

	left_len = array_len(left_array);
	right_len = array_len(right_array);
}

/**
 * array_len - Returns the length of an array
 * @array: Array, whose length is to be returned
 * Return: integer
 */
size_t array_len(int *array)
{
	size_t i;

	while (array[i] != NULL)
		i++;
	return (i);
}

/**
 * recursive_array_division - Divides the array recursively
 * @array - Array to be divided
 * @size - Size of the array
 */
void recursive_array_division(int *array, size_t size)
{
	if (size < 2)
		return;

	size_t division_point;
	int left_array[100];
	int right_array[100];

	division_point = size / 2;
	create_subarrays(array, 0, division_point, left_array);
	create_subarrays(array, division_point, size, right_array);
	print_array(left_array, division_point);
	print_array(right_array, size - division_point);
	recursive_array_division(left_array, division_point);
	recursive_array_division(right_array, size - division_point);
}

/**
 * create_subarrays - Creates a division of the arrays in almost equal halves
 * @array: Array to be divided
 * @start: Index to the first element of the sub-array
 * @end: Index to the last element of the sub-array
 * @sub_array: Pointer to the sub_array
 * Return: Sub-array with range of start to end
 */
void create_subarrays(int *array, int start, int end, int *sub_array)
{
	int i, j;

	for (j = 0, i = start; i < end; i++, j++)
	{
		sub_array[j] = array[i];
	}
}
