#include "sort.h"

/**
 * heapify - helper function that sorts elements on current heap and
 * swaps highest values to the end of the original array
 * @a: Int array to be sorted
 * @i: Size_t variable that is assumed to be the current max for a given heap
 * @end: Size_t variable that denotes the end of the current unsorted heap
 * @n: Size_t variable that represents the original size of the original
 * array to be sorted to be used for printer function
 * Return: Void
 */

void heapify(int a[], size_t i, size_t end, size_t n)
{
	int temp;
	size_t left, right, max;

	max = i;
	left = (2 * i) + 1;
	right = (2 * i) + 2;

	if (left < end && a[left] > a[max])
		max = left;

	if (right < end && a[right] > a[max])
		max = right;

	if (max != i && max < n)
	{
		temp = a[i];
		a[i] = a[max];
		a[max] = temp;
		print_array(a, n);
		heapify(a, max, end, n);
	}

}

/**
 * build_max_heap - helper function that sets up initial heap
 * @arr: Int array to be sorted
 * @s: Size_t variable for size of array to be sorted
 * Return: Void
 */

void build_max_heap(int arr[], size_t s)
{
	size_t i;

	for (i = s / 2; i > 0; i--)
		heapify(arr, i - 1, s, s);
}

/**
 * heap_sort - function that sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: Int array to be sorted
 * @size: Size_t variable for size of array to be sorted
 * Return: Void
 */

void heap_sort(int *array, size_t size)
{
	int temp;
	size_t n;

	if (array == NULL || size < 2)
		return;

	build_max_heap(array, size);

	for (n = size; n >= 2; n--)
	{
		temp = array[n - 1];
		array[n - 1] = array[0];
		array[0] = temp;
		print_array(array, size);
		heapify(array, 0, n - 1, size);
	}
}
