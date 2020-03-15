#include "sort.h"

/**
 * cleanup - function that frees memory allocated for main driver
 * function
 * @ind: int array for index array used
 * @cnt: int array for count array used
 * @sum: int array for sumCount array used
 * @srt: int array for sorted array used
 * Return: void
 */

void cleanup(int *ind, int *cnt, int *sum, int *srt)
{
	free(cnt);
	free(ind);
	free(sum);
	free(srt);
}

/**
 * copy - function that copies an int array to another
 * @arr1: Integer array to be copied
 * @arr2: Integer array to copy to
 * @s: Size_t variable denoting size of array to be sorted
 * Return: Void
 */

void copy(int *arr1, int *arr2, size_t s)
{
	int i;

	for (i = 0; i < (int) s; i++)
		arr1[i] = arr2[i];
}

/**
 * sorted - function that creates sorted array
 * @array: Integer array to be sorted
 * @size: Size_t variable denoting size of array to be sorted
 * @index: int array for index array used
 * @sumCount: int array for sumCount array used
 * Return: Pointer to new sorted array
 */

int *sorted(int *array, size_t size, int *index, int *sumCount)
{
	int *sorted;
	int i;

	sorted = malloc(size * sizeof(int));

	if (size == 2)
	{
		if (array[0] >= array[1])
		{
			sorted[1] = array[0];
			sorted[0] = array[1];
			return (sorted);
		}

		else
		{
			sorted[0] = array[0];
			sorted[1] = array[1];
			return (sorted);
		}
	}

	for (i = 0; i <= (int) size; i++)
	{
		if (array[i] == index[array[i]])
		{
			sorted[sumCount[array[i]] - 1] = array[i];
			--sumCount[array[i]];
		}
	}
	return (sorted);
}

/**
 * maximum - function that finds maximum from passed int array
 * @arr: Integer array to be sorted
 * @s: Size_t variable denoting size of array to be sorted
 * Return: maximum value of array
 */

int maximum(int *arr, size_t s)
{
	int m;
	size_t i;

	m = arr[0];

	for (i = 0; i < s; i++)
	{
		if (arr[i] > m)
			m = arr[i];
	}

	return (m);
}

/**
 * counting_sort - function that sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: Integer array to be sorted
 * @size: Size_t variable denoting size of array to be sorted
 * Return: Void
 */

void counting_sort(int *array, size_t size)
{
	int i, max, s_index;
	int *count, *index, *sumCount, *sort;

	if (array == NULL || size < 2)
		return;

	max = maximum(array, size);
	s_index = max + 1;
	index = malloc((s_index) * sizeof(int));

	for (i = 0; i < s_index; i++)
		index[i] = i;

	count =  malloc((s_index) * sizeof(int));

	for (i = 0; i < s_index; i++)
		count[i] = 0;

	for (i = 0; i < (int) size; i++)
	{
		if (array[i] == index[array[i]])
			count[array[i]] += 1;
	}

	sumCount = malloc((s_index) * sizeof(int));
	sumCount[0] = count[0];

	for (i = 1; i < s_index; i++)
		sumCount[i] = count[i] + sumCount[i - 1];

	print_array(sumCount, (size_t) s_index);

	sort = sorted(array, size, index, sumCount);

	copy(array, sort, size);

	cleanup(index, count, sumCount, sort);
}
