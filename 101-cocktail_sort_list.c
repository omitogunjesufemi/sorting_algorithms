#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in bidirectional
 * movement
 * @list: The list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *head, *tail, *prev_ptr, *next_ptr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		head = *list;
		while (head->next != NULL)
		{
			next_ptr = head->next;
			if (head->n > next_ptr->n)
			{
				swap(head, next_ptr, list);
				head = head->prev;
				swapped = 1;
				print_list(*list);
			}
			head = head->next;
		}

		if (swapped == 0)
			break;

		tail = head;
		swapped = 0;
		while (tail->prev != NULL)
		{
			prev_ptr = tail->prev;
			if (tail->n < prev_ptr->n)
			{
				swap(prev_ptr, tail, list);
				tail = tail->next;
				swapped = 1;
				print_list(*list);
			}
			tail = tail->prev;
		}
	} while (swapped == 1);

}

/**
 * swap - swap nodes of a doubly linked list
 * @x: first node
 * @y: second node
 * @head: double pointer to head of doubly linked list
 * Return: nothing
*/
void swap(listint_t *x, listint_t *y, listint_t **head)
{
	x->next = y->next;
	if (y->next != NULL)
		y->next->prev = x;
	y->next = x;
	y->prev = x->prev;
	if (x->prev != NULL)
		x->prev->next = y;
	else
		*head = y;
	x->prev = y;
}
