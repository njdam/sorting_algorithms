#include "deck.h"

/**
 * str_cmp - is a function to compare two strings as two values for cards;
 * @str1: is a pointer to the first string to be compared;
 * @str2: is a pointer to the second string to be compared;
 *
 * Return: a positive byte difference if str1 > str2, or
 * value 0 if str1 == str2, or a negative byte difference if str1 < str2.
 */
int str_cmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);

	return (0);
}

/**
 * getValue - is a function to retrieve a numerical value of a card;
 * @card: is a pointer to a card of deck_node_t doubly linked list;
 *
 * Return: a numerical value of a given card.
 */
char getValue(deck_node_t *card)
{
	if (str_cmp(card->card->value, "Ace") == 0)
		return (0);
	if (str_cmp(card->card->value, "1") == 0)
		return (1);
	if (str_cmp(card->card->value, "2") == 0)
		return (2);
	if (str_cmp(card->card->value, "3") == 0)
		return (3);
	if (str_cmp(card->card->value, "4") == 0)
		return (4);
	if (str_cmp(card->card->value, "5") == 0)
		return (5);
	if (str_cmp(card->card->value, "6") == 0)
		return (6);
	if (str_cmp(card->card->value, "7") == 0)
		return (7);
	if (str_cmp(card->card->value, "8") == 0)
		return (8);
	if (str_cmp(card->card->value, "9") == 0)
		return (9);
	if (str_cmp(card->card->value, "10") == 0)
		return (10);
	if (str_cmp(card->card->value, "Jack") == 0)
		return (11);
	if (str_cmp(card->card->value, "Queen") == 0)
		return (12);

	return (13);
}

/**
 * sort_deck_kind_inserter - is a function to sort a deck of cards
 * from spades to diamonds;
 * @deck: is a pointer to head node of a deck_node_t doubly-linked list;
 *
 * Return: nothing.
 */
void sort_deck_kind_inserter(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *temp;

	iter = (*deck)->next;
	while (iter)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next)
				iter->next->prev = insert;

			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev)
				insert->prev->next = iter;
			else
				*deck = iter;

			insert->prev = iter;
			insert = iter->prev;
		}

		iter = temp;
	}
}

/**
 * sort_deck_value_inserter - is a function to sort a deck of cards
 * from ace to king, sorted from spades to diamonds;
 * @deck: is a pointer to head node of a deck_node_t doubly-linked list;
 *
 * Return: nothing.
 */
void sort_deck_value_inserter(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *temp;

	iter = (*deck)->next;
	while (iter)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert && insert->card->kind == iter->card->kind &&
				getValue(insert) > getValue(iter))
		{
			insert->next = iter->next;
			if (iter->next)
				iter->next->prev = insert;

			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev)
				insert->prev->next = iter;
			else
				*deck = iter;

			insert->prev = iter;
			insert = iter->prev;
		}

		iter = temp;
	}
}

/**
 * sort_deck - is function to sort a deck of cards;
 * @deck: is a head node of a deck_node_t doubly-linked list;
 *
 * Return: nothing.
 */
void sort_deck(deck_node_t **deck)
{
	if (!deck || !(*deck) || !((*deck)->next))
		return;

	sort_deck_kind_inserter(deck);
	sort_deck_value_inserter(deck);
}
