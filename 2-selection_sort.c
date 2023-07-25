#include "sort.h"

/**
 * selection_sort - is a function for selection sorting algorithm of array;
 * @array: is array of integers to be sorted;
 * @size: is size of array;
 *
 * Return: nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j = 0, min_index;
	int min, temp;

	while (j < size - 1)
	{
		min_index = j; /* Initiate min_index where min number is */
		i = j + 1;
		while (i < size)
		{
			min = array[min_index]; /* min num at min_index */
			if (array[i] < min)
				/* updating min_index where min number is */
				min_index = i;
			i++;
		}
		if (min_index != j)
		{/* swap min_num in unsorted with num next 2 prev_min_num */
			temp = array[min_index]; /* min_num */
			array[min_index] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
		j++;
	}
}
