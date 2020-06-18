#include "sort.h"
/**
 * quick_sort_hoare - quicksort function
 * @array: the array
 * @size: the size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, 0, size - 1, size);
}
/**
 * sort - recursive sort function
 * @array: the array
 * @size: the size
 * @low: the low limit
 * @high: the hish limit
 */
void sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		sort(array, low, pivot, size);
		sort(array, pivot + 1, high, size);
	}
}
/**
 * partition - partition and order the array
 * @array: the array
 * @size: the size
 * @low: the low limit
 * @high: the hish limit
 * Return: return the position of i (the new pivot)
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[(high + low) / 2];
	i = low;
	j = high;
	while (1)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i >= j)
			return (j);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
		i++;
		j--;
	}
}
