#include "sort.h"

/*
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: the list to sort
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *tmp;
	int tp;

	while (current)
	{
		tmp = current->prev;
		while (tmp && tmp->n > current->n)
		{
			tp = tmp->n;
			tmp->n = current->n;
			current->n = tp;

			print_list(*list);
			tmp = tmp->prev;
		}
		current = current->next;
	}
}
