#include "sort.h"

/**
 * swap_node_ahead - is a func to sort dll of ints with a node ahead it;
 * @list: is a pointer to double linked list head node;
 * @tail: is a pointer to tail of the doubly-linked list tail node;
 * @shaker: is a current swapping node of cocktail shaker algorithm;
 *
 * Return: nothing.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - is a func to sort dll of ints with a node behind it;
 * @list: is a pointer to double linked list head node;
 * @tail: is a pointer to tail of the doubly-linked list tail node;
 * @shaker: is a current swapping node of cocktail shaker algorithm;
 *
 * Return: nothing.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - is a func to sort using a cocktail shaker algorithm;
 * @list: is a pointer to double linked list head node;
 *
 * Return: nothing.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	int shaken_not_stirred = 0;

	if (!(list) || !(*list) || !((*list)->next))
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == 0)
	{
		shaken_not_stirred = 1;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = 0;
			}
		}
		for (shaker = shaker->prev; shaker != *list; shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = 0;
			}
		}
	}
}
