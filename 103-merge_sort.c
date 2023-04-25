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
	size_t division_point;
	int left_array[10000];
	int right_array[10000];
	size_t left_len, right_len;

	if (size < 2)
		return;

	division_point = size / 2;
	left_len = division_point;
	right_len = size - division_point;
	create_subarrays(array, 0, division_point, left_array);
	create_subarrays(array, division_point, size, right_array);

	merge_sort(left_array, left_len);
	merge_sort(right_array, right_len);

	printf("Merging...\n");
	sort_array(array, left_array, right_array,
		   left_len, right_len);

}

/**
 * sort_array - This sorts the left and right arrays in ascending order
 * @array: The main array
 * @left_array: The left array
 * @right_array: The right array
 * @left_len: Size of left array
 * @right_len: Size of right array
 */
void sort_array(int *array, int *left_array, int *right_array,
		size_t left_len, size_t right_len)
{
	size_t left_idx, right_idx, sub_idx;

	right_idx = 0, left_idx = 0, sub_idx = 0;
	while (left_idx < left_len && right_idx < right_len)
	{
		if (left_array[left_idx] < right_array[right_idx])
		{
			array[sub_idx] = left_array[left_idx];
			left_idx++;
		}
		else
		{
			array[sub_idx] = right_array[right_idx];
			right_idx++;
		}
		sub_idx++;
	}

	while (left_idx < left_len)
	{
		array[sub_idx] = left_array[left_idx];
		left_idx++;
		sub_idx++;
	}

	while (right_idx < right_len)
	{
		array[sub_idx] = right_array[right_idx];
		right_idx++;
		sub_idx++;
	}

	printf("[left]:");
	print_array(left_array, left_len);
	printf("[right]:");
	print_array(right_array, right_len);
	printf("[Done]:");
	print_array(array, right_len + left_len);
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
