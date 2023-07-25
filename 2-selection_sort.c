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

	while (j < size)
	{
		min_index = j;
		i = j + 1;
		while (i < size)
		{
			min = array[i];
			if (min < array[min_index])
				min_index = i;
			i++;
		}
		if (min_index != j)
		{
			temp = array[min_index];
			array[min_index] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
		j++;
	}
}
