#include "sort.h"
/**
 * swap - swap values of two integers
 * @x: pointer to integer
 * @y: pointer to integer
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
 * heapify - converts array to max heap
 * @arr: array to be converted
 * @size: size of the array
 * @idx: index to start with
 * @original_size: original size of the array
 * this is because during the main heap sort loop,
 * a decreasing value will be passed as the size
 * Return: nothing
*/
void heapify(int *arr, size_t size, size_t idx, size_t original_size)
{
	size_t left, right, max;

	max = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;
	if (left < size && arr[left] > arr[max])
		max = left;
	if (right < size && arr[right] > arr[max])
		max = right;
	if (max != idx)
	{
		swap(&arr[idx], &arr[max]);
		print_array(arr, original_size);
		heapify(arr, size, max, original_size);
	}
}
/**
 * build_max_heap - build max heap using heapify
 * @arr: array of integers
 * @size: size of array to convert
 * Return: nothing
*/
void build_max_heap(int *arr, size_t size)
{
	int i;

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		heapify(arr, size, i, size);
	}
}
/**
 * heap_sort - an implementation of the heap sort
 * algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 * Return: nothing
*/
void heap_sort(int *array, size_t size)
{
	int i;

	build_max_heap(array, size);
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[i], &array[0]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
