#include "sort.h"

/**
 * index_partitioner - a func to swap and return parted index;
 * @array: is an array to be sorted;
 * @size: is a size of array to be sorted;
 * @low: is index in array as minimum point in sorting;
 * @high: is index in array as maximum point in sorting;
 *
 * Description: lomuto partition scheme to swap and return index;
 *
 * Return: parted index where next pivot is.
 */
size_t index_partitioner(int *array, size_t size, int low, int high)
{
	int min, max, temp, pivot = array[high];

	min = max = low;
	while (min < high)
	{
		if (array[min] < pivot)
		{
			if (min > max)
			{/* if min index surpass max index, swap numbers */
				temp = array[min];
				array[min] = array[max];
				array[max] = temp;
				print_array(array, size);
			}
			max++;
		}
		min++;
	}

	if (array[max] > pivot)
	{/* swap a number at index + 1 with number at high index */
		temp = array[max];
		array[max] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (max);
}

/**
 * recursive_quick_sort - is a quick sort algorithm to call itself;
 * @array: is an array to be sorted;
 * @size: is a size of array to be sorted;
 * @low: is index in array as minimum point in sorting;
 * @high: is index in array as maximum point in sorting;
 *
 * Return: nothing.
 */
void recursive_quick_sort(int *array, size_t size, int low, int high)
{
	int parted_index;

	if (high - low > 0)
	{
		parted_index = index_partitioner(array, size, low, high);
		recursive_quick_sort(array, size, low, parted_index - 1);
		recursive_quick_sort(array, size, parted_index + 1, high);
	}
}

/**
 * quick_sort - is a func to sort an array of ints by Quick sort algorithm;
 * @array: is an array to be sorted;
 * @size: is a size of array to be sorted;
 *
 * Return: nothing.
 */
void quick_sort(int *array, size_t size)
{
	int i = 0;

	if (!array || size < 2)
		return;

	recursive_quick_sort(array, size, i, size - 1);
}
