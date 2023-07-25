#include "sort.h"

/**
 * shell_sort - is a func to sort an array by using shell sort algorithm;
 * @array: is an array of integers to be sorted;
 * @size: is size of an array to be sorted;
 *
 * Description: shell sorting by using Knuth interval sequence;
 *
 * Return: nothing.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || size < 2)
		return;

	gap = 1;
	while (gap < (size / 3))
		gap = (gap * 3) + 1;

	while (gap >= 1)
	{
		i = gap;
		while (i < size)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				temp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = temp;
				j -= gap;
			}
			i++;
		}
		print_array(array, size);
		gap /= 3;
	}
}
