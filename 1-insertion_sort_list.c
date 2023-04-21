#include "sort.h"

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
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *position;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		print_list(*list);

	current = (*list)->next;
	while (current != NULL)
	{
		position = find_position(*list, current);
		if (position != current)
		{
			current->prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = current->prev;

			current->next = position;
			current->prev = position->prev;

			if (position->prev != NULL)
				position->prev->next = current;
			else
				*list = current;

			position->prev = current;
			print_list(*list);
		}
		else
		{
			print_list(*list);
			current = current->next;
		}

	}
}

/**
 * find_postion - Returns a pointer to a node for comparison with
 * current node to determine whether they would be swapped
 * @head: Head pointer to the list
 * @curr: Current pointer
 * Return: Pointer to a node for comparison
 */
listint_t *find_position(listint_t *head, listint_t *curr)
{
	listint_t *position;

	position = head;
	while (position != curr && position->n <= curr->n)
	{
		position = position->next;
	}

	return (position);
}
