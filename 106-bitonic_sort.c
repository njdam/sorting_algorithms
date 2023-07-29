#include "sort.h"

/**
 * swap - is a function to sort two integers;
 * @a: is a pointer to the first integer to be swapped;
 * @b: is a pointer to the second integer to be swapped;
 *
 * Return: nothing.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * recursive_bitonic_merge - sort a bitonic sequence inside of an array;
 * @array: is an array of integers to be sorted in ascending order;
 * @size: is a size of an array to be sorted using bitonic sort algorithm;
 * @st: is a starting index of bulding block of bitonic sequence;
 * @seq: is a size of building block of bitonic sequence;
 * @flow: is a direction to sort in block of bitonic sequence;
 *
 * Return: nothing.
 */
void recursive_bitonic_merge(int *array, size_t size, size_t st, size_t seq,
		char flow)
{
	size_t i, jmp = seq / 2;

	if (seq > 1)
	{
		i = st;
		while (i < (st + jmp))
		{
			if ((flow == UP && array[i] > array[i + jmp]) ||
				(flow == DOWN && array[i] < array[i + jmp]))
				swap(&array[i], &array[i + jmp]);
			i++;
		}
		recursive_bitonic_merge(array, size, st, jmp, flow);
		recursive_bitonic_merge(array, size, (st + jmp), jmp, flow);
	}
}

/**
 * recursive_bitonic_seq - convert an array of ints into a bitonic sequence;
 * @array: is an array of integers to be sorted in ascending order;
 * @size: is a size of an array to be sorted using bitonic sort algorithm;
 * @st: is a starting index of bulding block of bitonic sequence;
 * @seq: is a size of building block of bitonic sequence;
 * @flow: is a direction to sort in block of bitonic sequence;
 *
 * Return: nothing.
 */
void recursive_bitonic_seq(int *array, size_t size, size_t st, size_t seq,
		char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(&array[st], seq);

		recursive_bitonic_seq(array, size, st, cut, UP);
		recursive_bitonic_seq(array, size, (st + cut), cut, DOWN);
		recursive_bitonic_merge(array, size, st, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(&array[st], seq);
	}
}

/**
 * bitonic_sort - is a func to sort array using the bitonic sort algorithm;
 * @array: is an array of integers to be sorted in ascending order;
 * @size: is a size of an array to be sorted using bitonic sort algorithm;
 *
 * Description: assume that size = 2^k where k >= 0 and
 * print an array each time two elements swapped.
 *
 * Return: nothing.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursive_bitonic_seq(array, size, 0, size, UP);
}
