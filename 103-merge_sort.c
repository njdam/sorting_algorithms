#include "sort.h"

/**
 * merge_sub_array - is a func to merge & sort a sub or an array;
 * @array: is a sub or an array of integers to be sorted;
 * @buf: is a buffer for storing sorted integers of an array;
 * @l_size: is a size of left part of an array;
 * @mid: is a half size of a sub or an array plus a remainder;
 * @r_size: is a size of right part of an array;
 *
 * Return: nothing.
 */
void merge_sub_array(int *array, int *buf, size_t l_size, size_t mid,
		size_t r_size)
{
	size_t i = l_size, j = mid, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + l_size, mid - l_size);

	printf("[right]: ");
	print_array(array + mid, r_size - mid);

	/* Comparing left part and right part elements to store smallest */
	while (i < mid && j < r_size)
	{
		buf[k] = (array[i] < array[j]) ? array[i++] : array[j++];
		k++;
	}

	/* To store remain element in left part if l_size > r_size, /- 0% */
	while (i < mid)
	{
		buf[k++] = array[i];
		i++;
	}

	/* To store remain element in right part if r_size > l_size, /odd */
	while (j < r_size)
	{
		buf[k++] = array[j];
		j++;
	}

	i = l_size;
	k = 0;
	while (i < r_size)
	{
		array[i] = buf[k++];
		i++;
	}

	printf("[Done]: ");
	print_array(array + l_size, r_size - l_size);
}

/**
 * recursive_merge_sort - a recursive function of sorting merge algorithm;
 * @array: is a sub or an array of integers to be sorted;
 * @buf: is a buffer for storing sorted integers of an array;
 * @left: is size of left(front) part of an array;
 * @right: is size of right(back) part of an array;
 *
 * Return: nothing.
 */
void recursive_merge_sort(int *array, int *buf, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		recursive_merge_sort(array, buf, left, mid);
		recursive_merge_sort(array, buf, mid, right);
		merge_sub_array(array, buf, left, mid, right);
	}
}

/**
 * merge_sort - is a function to sort an array using merge sort algorithm;
 * @array: is an array of integers to be sorted;
 * @size: is a size of array to be sorted;
 *
 * Return: nothing.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(size * sizeof(int));
	if (!buffer)
		return;

	recursive_merge_sort(array, buffer, 0, size);

	free(buffer);
}
