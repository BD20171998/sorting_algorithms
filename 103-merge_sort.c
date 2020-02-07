#include "sort.h"

/**
 * printer - function that swaps memory addressed for 2 elements from an
 * integer array
 * @text: Char pointer for text to print during merge
 * @a: Int array
 * @start: Size_t beginning index for left side of array to print
 * @end_inc:  Size_t ending index for right side of array to print
 * Return: Void
 */

void printer(char *text, int a[], size_t start, size_t end_inc)
{
	size_t n;

	printf("%s: ", text);

	for (n = start; n <= end_inc; ++n)
	{
		if (n  == end_inc || !end_inc || end_inc == start)
		{
			printf("%d\n", a[n]);
			break;
		}

			printf("%d, ", a[n]);
	}
}

/**
 * merge - helper function that sorts and merges array elements
 * @copy: copy of original int array to be sorted
 * @begin: Size_t beginning index for left side of partition
 * @mid: Size_t index for midpoint of partition
 * @end: Size_t index for endpoint of partition
 * @arr: Most recently sorted partition
 * Return: Void
 */

void merge(int copy[], size_t begin, size_t mid, size_t end, int arr[])
{
	size_t i = begin, j = mid, k = begin;

	printf("Merging...\n");
	printer("[left]", copy, begin, mid == 0 ? 0 : mid - 1);
	printer("[right]", copy, mid, end);

	while (i < mid && j <= end)
	{
		if (copy[i] <= copy[j])
		{
			arr[k] = copy[i];
			++i;
		}

		else
		{
			arr[k] = copy[j];
			++j;
		}

		++k;
	}

	while (i < mid)
	{
		arr[k] = copy[i];
		i++;
		k++;
	}

	while (j <= end)
	{
		arr[k] = copy[j];
		j++;
		k++;
	}
	printer("[Done]", arr, begin, end);
}

/**
 * qs - Function that passes updated arguments and creates recursion calls for
 * the merge function
 * @copy: copy of original int array to be sorted
 * @begin: Size_t beginning index for left side of partition
 * @end: Size_t index for endpoint of partition
 * @arr: Most recently sorted partition
 * Return: Void
 */

void qs(int copy[], size_t begin, size_t end, int arr[])
{
	size_t mid, diff;

	if (end - begin < 1)
		return;

	diff = (end - begin);
	diff += diff % 2;
	mid = begin + diff / 2;

	qs(arr, begin, mid - 1, copy);
	qs(arr, mid, end, copy);
	merge(copy, begin, mid, end, arr);
}

/**
 * merge_sort - Function that sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: Integer array to be sorted
 * @size: Size_t variable denoting size of array to be sorted
 * Return: Void
 */

void merge_sort(int *array, size_t size)
{
	size_t i;

	int *copy;

	if (array == NULL || size < 2)
		return;

	copy = malloc(sizeof(int) * size);

	if (copy == NULL)
		return;

	for (i = 0; i < size; i++)
		copy[i] = array[i];

	qs(copy, 0, size - 1, array);
	free(copy);
}
