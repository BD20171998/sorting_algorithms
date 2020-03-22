#include "sort.h"

/**
 * count_sort_radix - helper function that sorts an array after being
 * given the updated divisor
 * @array: Int array to be sorted
 * @size: Size_t variable for size of array to be sorted
 * @mod: divisor to be used to help capture the next significant digit
 * Return: Void
 */

void count_sort_radix(int *array, size_t size, int mod)
{
	int i, count[10] = {0};
	int *output;

	output = malloc(sizeof(int) * size);

	for (i = 0; i < (int) size; i++)
		++count[(array[i] / mod) % 10];

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (int) size - 1; i >= 0; i--)
	{
		output[count[(array[i] / mod) % 10] - 1] = array[i];
		--count[(array[i] / mod) % 10];
	}

	for (i = 0; i < (int) size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - function that sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * https://www.geeksforgeeks.org/radix-sort/
 * @array: Int array to be sorted
 * @size: Size_t variable for size of array to be sorted
 * Return: Void
 */

void radix_sort(int *array, size_t size)
{
	int i, len = 0, max = 0, mod = 1;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] >= max)
			max = array[i];
	}

	while (max > 0)
	{
		max = max / 10;
		len++;
	}

	for (i = 0; i < len; i++)
	{
		count_sort_radix(array, size, mod);
		print_array(array, size);
		mod *= 10;
	}
}
