#include "sort.h"


/**
 * bubble_sort - function that that sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: Array of integers
 * @size: Size_t variable for size of integer array
 * Return: Void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (size == 1)
	{
		print_array(array, size);
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] <= array[j + 1])
				continue;

			else
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}

}
