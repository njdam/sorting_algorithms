#include "sort.h"

/**
 * get_max - a fumction to search a maximum value in an array;
 * @array: is an array of integers to be searched;
 * @size: is size of an arrray to be searched;
 *
 * Return: maximum value in an array.
 */
int get_max(int *array, int size)
{
	int max = array[0], i = 1;

	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}

	return (max);
}

/**
 * counting_sort - func to sort array by using counting sort algorithm;
 * @array: is an array of integers to be searched;
 * @size: is size of an arrray to be searched;
 *
 * Return: nothing.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (!array || size < 2)
		return;

	sorted = malloc(size * sizeof(int));
	if (!sorted)
		return;

	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
