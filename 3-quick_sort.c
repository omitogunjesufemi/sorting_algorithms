#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 * Quick sort algorithm
 *
 * @array: Array of integers to be sorted
 *
 * @size: size of the array
 *
 * The Lomuto Partition scheme was use for the implementation of this
 * quick sorting algorithm program
 */
void quick_sort(int *array, size_t size)
{
	int start_point, end_point;

	start_point = 0;
	end_point = size - 1;
	helper_function(array, start_point, end_point, size);
}

/**
 * helper_function - This function does the recursive call for the quick sort
 * @array: The array or sub arrays to be sorted
 * @start_point: The index pointing to the first element of the sub-array
 * @end_point: The index pointing to the last element of the sub-array
 * @n: This is the total size of the array, to be used for printing the arrays
 */
void helper_function(int *array, int start_point, int end_point, int n)
{
	int partition;

	if (start_point > end_point)
		return;
	partition = lomuto_partition_scheme(array, start_point, end_point);
	print_array(array, n);
	/*Left Partition*/
	helper_function(array, start_point, partition - 1, n);
	/*Right Partition*/
	helper_function(array, partition + 1, end_point, n);
}

/**
 * lomuto_partition_scheme - The partiton scheme used in this implementation
 * @array: The array or sub arrays to be sorted
 * @start_point: The index pointing to the first element of the sub-array
 * @end_point: The index pointing to the last element of the sub-array
 * @n: This is the total size of the array, to be used for printing the arrays
* Return: partition position
 */
int lomuto_partition_scheme(int *array, int start_point, int end_point)
{
	int i, j, pivot;

	j = start_point;
	pivot = array[end_point];

	for (i = start_point; i < end_point; i++)
	{
		if (array[i] <= pivot)
		{
			swap_elements(&(array[i]), &(array[j]));
			j++;
		}
	}
	swap_elements(&(array[end_point]), &(array[j]));
	return (j);
}

/**
 * swap_elements - Swap the two elements from their position
 * @element_1: An element to be swapped
 * @element_2: Second element to be swapped
 */
void swap_elements(int *element_1, int *element_2)
{
	int temp;

	temp = *element_1;
	*element_1 = *element_2;
	*element_2 = temp;
}
