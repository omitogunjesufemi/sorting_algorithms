#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include<stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the insertion sort algorithm
 *
 * @list: Address to the head of the head of the doubly linked list
 *
 * The integer n of the node are not to be modififed, but the nodes
 * themselves to be swapped
 *
 * It prints the list after each time two elements are swapped
 */
void insertion_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);

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
void quick_sort(int *array, size_t size);

/**
 * helper_function - This function does the recursive call for the quick sort
 * @array: The array or sub arrays to be sorted
 * @start_point: The index pointing to the first element of the sub-array
 * @end_point: The index pointing to the last element of the sub-array
 * @n: This is the total size of the array, to be used for printing the arrays
 */
void helper_function(int *array, int start_point, int end_point, int n);

/**
 * lomuto_partition_scheme - The partiton scheme used in this implementation
 * @array: The array or sub arrays to be sorted
 * @start_point: The index pointing to the first element of the sub-array
 * @end_point: The index pointing to the last element of the sub-array
 * @n: This is the total size of the array, to be used for printing the arrays
 * Return: partition position
 */
int lomuto_partition_scheme(int *array, int start_point, int end_point);

/**
 * swap_elements - Swap the two elements from their position
 * @element_1: An element to be swapped
 * @element_2: Second element to be swapped
 */
void swap_elements(int *element_1, int *element_2);


#endif /* SORT_H */
