#include "sort.h"

/**
 * bubble_sort - is a function to sort element of array by O(n^2);
 * @array: is a pointer to array to be sorted;
 * @size: is a size of array to be sorted;
 *
 * Return: nothing.
 */
void bubble_sort(int *array, size_t size)
{
	int max, swapped;
	size_t i, j = 0;

	if (!array || size < 2) /* if array is NULL or has 1 element */
		return;

	while (j < size)
	{
		swapped = 0;
		i = 0; /* To restart an array every time(swapped)/less */
		while (i < size - 1) /* `<lens-1` because of array[i+1]*/
		{
			if (array[i] > array[i + 1])
			{
				max = array[i];
				array[i] = array[i + 1];
				array[i + 1] = max; /* stored max at end */
				swapped = 1;
				print_array(array, size);
			}
			i++;
		}

		if (!swapped) /* This means array is ordered */
			break;
		j++;
	}
}
