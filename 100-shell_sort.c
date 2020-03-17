#include "sort.h"


/**
 * power - function that returns power of a int
 * @base: Int of base number to be exponentiated
 * @exp: Int - exponent
 * Return: exponentiated value as int
 */

int power(int base, int exp)
{
	int j, num = 1;

	for (j = 1; j <= exp; j++)
		num *= base;

	return (num);
}

/**
 * shell_sort - function that sorts an array of integers in ascending order
 * sing the Shell sort algorithm, using the Knuth sequence
 * https://www.thecrazyprogrammer.com/2016/09/program-shell-sort-c.html
 * @array: Int array to be sorted
 * @size: Size_t variable for size of array to be sorted
 * Return: Void
 */

void shell_sort(int *array, size_t size)
{
	int gap = 0, i = 1, j, k, temp;

	if (array == NULL || size < 2)
		return;

	while (gap <= (int) size)
	{
		gap = ((power(3, i)) - 1) / 2;
		++i;
	}

	for (k = i - 1; gap > 0; --k)
	{

		gap = ((power(3, k - 1)) - 1) / 2;

		for (i = gap; i < (int) size; ++i)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}

		if (gap == 0)
			break;

		print_array(array, size);
	}
}
