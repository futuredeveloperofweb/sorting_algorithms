#include "sort.h"

/**
 * swap_nodes - swap two nodes in list
 * @node_a: first node
 * @node_b: second node
 * Return: nothing
 */
void swap_nodes(listint_t *node_a, listint_t *node_b)
{
	if (node_a->prev)
		node_a->prev->next = node_b;
	if (node_b->next)
		node_b->next->prev = node_a;
	node_a->next = node_b->next;
	node_b->prev = node_a->prev;
	node_a->prev = node_b;
	node_b->next = node_a;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: the list to sort
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *nodeA;
	listint_t *nodeB;

	if (!list || !*list || !(*list)->next)
		return;
	nodeA = (*list)->next;
	while (nodeA)
	{
		nodeB = nodeA;
		nodeA = nodeA->next;
		while (nodeB && nodeB->prev)
		{
			if (nodeB->prev->n > nodeB->n)
			{
				swap_nodes(nodeB->prev, nodeB);
				if (!nodeB->prev)
					*list = nodeB;
				print_list((const listint_t *)*list);
			}
			else
				nodeB = nodeB->prev;
		}
	}
}
