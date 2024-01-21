#include "sort.h"

/**
 * swap - swap two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partition the array
 * @array: array to partition
 * @low: low index
 * @high: high index
 * @size: size of array
 * Return: index of pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_helper - helper function for quick_sort
 * @array: array to sort
 * @low: low index
 * @high: high index
 * @size: size of array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	while (low < high)
	{
		int pi = partition(array, low, high, size);

		if (pi - low < high - pi)
		{
			quick_sort_helper(array, low, pi - 1, size);
			low = pi + 1;
		}
		else
		{
			quick_sort_helper(array, pi + 1, high, size);
			high = pi - 1;
		}
	}
}

/**
 * quick_sort - sort an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
