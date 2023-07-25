#include "sort.h"

/**
 * swap_nodes - is a function to swap nodes of doubly linked list;
 * @head: is a double point to a list of doubly linked list;
 * @node1: is a first node;
 * @node2: is a second node to first node;
 *
 * Return: nothing.
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next) /* Setting previous node of node2->next */
		(node2->next)->prev = node1;

	node2->prev = node1->prev;
	node2->next = node1;
	if (node1->prev) /* Setting next node of node1->prev */
		(node1->prev)->next = node2;
	else
		*head = node2;

	node1->prev = node2;
	node1 = node2->prev;
}

/**
 * insertion_sort_list - a func for insertion Sort algorithm for dl list;
 * @list: is a double point to singly linked list;
 *
 * Return: nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *insert;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current->next;
		insert = current->prev;
		while (insert && current->n < insert->n)
		{
			swap_nodes(list, insert, current);
			print_list(*list);
			insert = current->prev;
		}
		current = temp;
	}
}
