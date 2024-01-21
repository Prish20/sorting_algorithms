#include "sort.h"

/**
 * swap_elements - swaps two elements of an array
 * @a: first element
 * @b: second element
 */
void swap_elements(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition_scheme - partitions the array
 * @array: array to partition
 * @size: size of the array
 * @start: starting index
 * @end: ending index
 * Return: partition index
 */
int partition_scheme(int *array, size_t size, int start, int end)
{
	int pivot = array[end];
	int lower = start - 1;

	int upper;

	for (upper = start; upper < end; upper++)
	{
		if (array[upper] < pivot)
		{
			lower++;
			swap_elements(&array[lower], &array[upper]);
			print_array(array, size);
		}
	}

	swap_elements(&array[lower + 1], &array[end]);
	print_array(array, size);

	return (lower + 1);
}

/**
 * quicksort_recursive - recursive function for quicksort
 * @array: array to sort
 * @size: size of the array
 * @start: starting index
 * @end: ending index
 */
void quicksort_recursive(int *array, size_t size, int start, int end)
{
	if (start < end)
	{
		int partition_index = partition_scheme(array, size, start, end);

		quicksort_recursive(array, size, start, partition_index - 1);
		quicksort_recursive(array, size, partition_index + 1, end);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, size, 0, size - 1);
}
