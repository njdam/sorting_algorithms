#include "sort.h"

/**
 * get_max - is a function to find the maximum integer in an array;
 * @array: is an array of integer for where to find the max int;
 * @size: is a size of an array to be used;
 *
 * Return: a maximum integer in a given array;
 */
int get_max(int *array, int size)
{
	int i = 1, max = array[0];

	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}

	return (max);
}

/**
 * sort_counter - is a function for counting sort of specific signif digit;
 * @array: is an array of integers to be sorted using radix algorithm;
 * @size: is a size of an array to be sorted;
 * @expo: is an exponent for a significant digit;
 * @buffer: is a pointer to a buffer of an integers;
 *
 * Return: nothing.
 */
void sort_counter(int *array, size_t size, int expo, int *buffer)
{
	int count[10] = {0};
	size_t i;

	i = 0;
	while (i < size)
	{
		count[(array[i] / expo) % 10]++;
		i++;
	}

	i = 0;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}

	i = size - 1;
	while ((int)i >= 0)
	{
		buffer[count[(array[i] / expo) % 10] - 1] = array[i];
		count[(array[i] / expo) % 10]--;
		i--;
	}

	i = 0;
	while (i < size)
	{
		array[i] = buffer[i];
		i++;
	}
}

/**
 * radix_sort - is a func to sort an array using Radix sort algorithm (LSD);
 * @array: is an array of integers to be sorted in ascending order;
 * @size: is a size of an array to be sorted using Radix sort algorithm;
 *
 * Description: the implementation of the Radix sort algorithm using LSD
 * (Least Significant Digit) in C, we'll first need to create a function
 * for finding the maximum element in the array to determine the number
 * of digits in the largest element. Then, we'll create a function
 * to perform the counting sort for each significant digit.
 * Finally, we'll implement the radix_sort function that uses the counting
 * sort for each digit from the least significant to the most significant.
 *
 * Return: nothing.
 */
void radix_sort(int *array, size_t size)
{
	int *buffer, expo = 1, max = get_max(array, size);

	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	while (max / expo > 0)
	{
		sort_counter(array, size, expo, buffer);
		print_array(array, size);

		expo *= 10;
	}

	free(buffer);
}
