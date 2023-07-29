#include "sort.h"

/**
 * swap - is a function  to swap two integers in an array;
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
 * hoare_partition - is to order subset of array by hoare partition scheme;
 * @array: is an array of integers to be sorted in ascending order;
 * @size: is size of an array to be sorted;
 * @st: is a starting index of parted array to be ordered;
 * @end: is an ending index of parted array to be ordered;
 *
 * Description: print an array after each time of two elements are swapped
 * by using last element of parted array as a pivot.
 *
 * Return: final parted index.
 */
int hoare_partition(int *array, size_t size, int st, int end)
{
	int pivot, above, below;

	pivot = array[end];
	above = st - 1;
	below = end + 1;
	while (above < below)
	{
		do {
			above++;
		} while (array[above] < pivot);

		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap(&array[above], &array[below]);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * recursive_hoare_sort - is implementation of quicksort algorithm;
 * @array: is an array of integers to be sorted in ascending order;
 * @size: is size of an array to be sorted;
 * @st: is a starting index of parted array to be ordered;
 * @end: is an ending index of parted array to be ordered;
 *
 * Description: by using Hoare partition scheme to sort.
 *
 * Return: nothing.
 */
void recursive_hoare_sort(int *array, size_t size, int st, int end)
{
	int parted;

	if (end - st > 0)
	{
		parted = hoare_partition(array, size, st, end);
		recursive_hoare_sort(array, size, st, (parted - 1));
		recursive_hoare_sort(array, size, parted, end);
	}
}

/**
 * quick_sort_hoare - funct to sort an array by using a quicksort algorithm;
 * @array: is an array of integers to be sorted in ascending order;
 * @size: is size of an array to be sorted;
 *
 * Description: The implementation of Hoare partition scheme and
 * Printing of an array after each time two elements are swapped;
 *
 * Return: nothing.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursive_hoare_sort(array, size, 0, (size - 1));
}
