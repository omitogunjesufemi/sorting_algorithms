#include "sort.h"
/**
 * swap_list_nodes - swap nodes of a doubly linked list
 * @x: first node
 * @y: second node
 * @head: double pointer to head of doubly linked list
 * Return: nothing
*/
void swap_list_nodes(listint_t *x, listint_t *y, listint_t **head)
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
/**
 * insertion_sort_list - an implementation of the
 * insertion sort algorithm on a doubly linked list
 * @head: double pointer to head of the linked list
 * Return: nothing
*/
void insertion_sort_list(listint_t **head)
{
	listint_t *node, *tmp;

	if (*head == NULL)
		return;
	node = (*head)->next;
	while (node != NULL)
	{
		tmp = node;
		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			swap_list_nodes(tmp->prev, tmp, head);
			print_list(*head);
		}
		node = node->next;
	}
}
