#include "sort.h"

/**
 * node_swap - Swap two nodes in a doubly-linked list.
 * @head: A pointer to a pointer to the head of a doubly-linked list of
 * integers.
 * @node_a: A pointer to a pointer to the first node to swap.
 * @node_b: A pointer to the second node to swap.
 *
 * Description: Prints the list after each swap.
 */
void node_swap(listint_t **head, listint_t **node_a, listint_t *node_b)
{
	if (*node_a == NULL || node_b == NULL)
		return;

	(*node_a)->next = node_b->next;
	if (node_b->next != NULL)
		node_b->next->prev = *node_a;
	node_b->prev = (*node_a)->prev;
	node_b->next = *node_a;
	if ((*node_a)->prev != NULL)
		(*node_a)->prev->next = node_b;
	else
		*head = node_b;
	(*node_a)->prev = node_b;
	*node_a = node_b->prev ? node_b->prev : node_b;
}

/**
 * insertion_sort_list - Sort a doubly-linked list of integers in ascending
 * order using the insertion sort algorithm.
 * @list: A pointer to a pointer to the head of a doubly-linked list of
 * integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		current = *list;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				node_swap(list, &current, current->next);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
			{
				current = current->next;
			}
		}
	} while (swapped);
}
