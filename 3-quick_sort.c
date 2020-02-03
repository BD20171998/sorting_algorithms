#include "sort.h"

/**
 * swap - function that swaps memory addressed for 2 elements from an
 * integer array
 * @a: Int pointer for first element that will be swapped
 * @b: Int pointer for second element that will be swapped
 * Return: Void
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Function that partitions elements to the left of the pivot
 * element and sorts the partition
 * @arr: Int array to be partitioned
 * @low: Int that represents the lower bound of the partition
 * @high: Int that represents the upper bound of the partition
 * @s: size_t variable that represents the total length of the int array
 * Return: Int for index of new pivot for next partition check
 */

int partition(int arr[], int low, int high, size_t s)
{
	int pivot = arr[high];
	int i = (low - 1), j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	print_array(arr, s);
	return (i + 1);
}

/**
 * quickSort - Function that sets up the partitions to be sorted
 * https://www.geeksforgeeks.org/quick-sort/
 * @arr: Int array to be partitioned
 * @low: Int that represents the lower bound of the partition
 * @high: Int that represents the upper bound of the partition
 * @s: size_t variable that represents the total length of the int array
 * Return: Void
 */

void quickSort(int arr[], int low, int high, size_t s)
{
	if (low < high)
	{
		int pi = partition(arr, low, high, s);

		quickSort(arr, low, pi - 1, s);
		quickSort(arr, pi + 1, high, s);
	}
}

/**
 * quick_sort - Driver function for the quick sort algorithm
 * @array: Int array to be partitioned
 * @size: size_t variable that represents the total length of the int array
 * Return: Void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quickSort(array, 0, size - 1, size);

}
