#include "sort.h"


/**
 * selection_sort -  function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: Int array to be sorted
 * @size: size_t variable denoting the size of the array to be sorted
 * Return: void
 */

void selection_sort(int *array, size_t size)
{

	size_t i, j, s;

	int min, temp;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];

		for (j = i + 1; j < size; j++)
		{
			if (array[j] <= min)
			{
				min = array[j];
				s = j;
				temp = array[i];
				array[i] = array[s];
				array[s] = temp;
				print_array(array, size);
			}
		}
	}

}
