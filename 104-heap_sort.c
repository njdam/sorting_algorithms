#include "sort.h"

/* A function CHILD to double a root index plus 1 */
#define CHILD(x) (2 * (x) + 1)

/**
 * swap - is a function to swap two integers of an array;
 * @a: is a pointer to the first integer of an array;
 * @b: is a pointer to the second integer of an array;
 *
 * Return: nothing.]
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * sift_down - is a func to sift down an element at index 'root' in a heap;
 * @array: is a converted array for representing the heap;
 * @root: is an index root of the subtree array;
 * @m_size: is a size of built heap array;
 * @size: is an orignal size of an array to be sorted by heap algorithm;
 *
 * Return: nothing.
 */
void sift_down(int *array, size_t root, size_t m_size, size_t size)
{
	size_t max_child, left_child;

	while ((left_child = CHILD(root)) < m_size)
	{
		max_child = left_child;
		if (max_child + 1 < m_size &&
				array[max_child + 1] > array[max_child])
			max_child++;

		if (array[root] >= array[max_child])
			break;

		swap(&array[root], &array[max_child]);
		print_array(array, size);
		root = max_child;
	}
}

/**
 * heapify - is a function to build a heap from an array;
 * @array: is an array to be converted into a heap to be sorted;
 * @size: is an orignal size of an array to be converted into a heap;
 *
 * Return: nothing.
 */
void heapify(int *array, size_t size)
{
	ssize_t i = (size - 1) / 2;

	while (i >= 0)
	{
		sift_down(array, i, size, size);
		i--;
	}
}

/**
 * heap_sort - is a function to sort an array by using heap sort algorithm;
 * @array: is an array to be sorted in ascending order;
 * @size: is a size of an array to be sorted using heap sort algorithm;
 *
 * Return: nothing.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (!array || size < 2)
		return;

	heapify(array, size);

	i = size - 1;
	while (i > 0)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, 0, i, size);
		i--;
	}
}
