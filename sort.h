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

#endif /* SORT_H */
