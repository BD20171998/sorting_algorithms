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
 * edge_cases - function that handles certain edge cases
 * @arr: Integer array to be sorted
 * @s: Size_t variable denoting size of array to be sorted
 * Return: Void
 */

void edge_cases(int *arr, size_t s)
{
	if (arr == NULL || s < 2)
		return;
}

/**
 * minimum - function that finds minimum from passed int array
 * @arr: Integer array to be sorted
 * @s: Size_t variable denoting size of array to be sorted
 * Return: minimum value of array
 */

int minimum(int *arr, size_t s)
{
	int m;
	size_t i;

	m = arr[0];

	for (i = 0; i < s; i++)
	{
		if (arr[i] < m)
			m = arr[i];
	}

	return (m);
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
	int *count, *index, *sumCount, *sorted;

	edge_cases(array, size);
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
	sorted = malloc(size * sizeof(int));

	for (i = 0; i <= (int) size; i++)
		if (array[i] == index[array[i]])
			sorted[sumCount[array[i]] - 1] = array[i];

	for (i = 0; i < (int) size; i++)
		array[i] = sorted[i];

	cleanup(index, count, sumCount, sorted);
}
