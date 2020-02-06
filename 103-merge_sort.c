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


void merge(int copy[], size_t begin, size_t mid, size_t end, int arr[])
{
	size_t i = 0, j = mid, k = begin, n, n1 = mid - begin + 1, n2 = end - mid;

	while (i <= n1 && j <= n2)
	{
 		printf("Merging...\n");
/*		printf("[left]: ");
		for (n = i; n < mid; ++n)
		{
			if (n == i - 1)
			{
				printf("%d\n", arr[n]);
				break;
			}

		        printf("%d, ", arr[n]);
		}

		printf("\n[right]: ");

		for (n = mid; n < end; ++n)
		{
			if (n == mid - 1)
			{
				printf("%d\n", arr[n]);
				break;
			}

		        printf("%d, ", arr[n]);
		}
*/
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

		printf("\n[Done]: ");

		for (n = 0; n < end; ++n)
		{
			if (n == end - 1)
			{
				printf("%d\n", arr[n]);
				break;
			}

		        printf("%d, ", arr[n]);
		}
		++k;
	}

	while (i < n1)
	{
		arr[k] = copy[i];
		i++;
		k++;

	printf("\n[Done]: ");

		for (n = 0; n < end; ++n)
		{
			if (n == end - 1)
			{
				printf("%d\n", arr[n]);
				break;
			}

		        printf("%d, ", arr[n]);
		}

	}

	while (j < n2)
	{
		arr[k] = copy[j];
		j++;
		k++;

	printf("\n[Done]: ");

		for (n = 0; n < end; ++n)
		{
			if (n == end - 1)
			{
				printf("%d\n", arr[n]);
				break;
			}

		        printf("%d, ", arr[n]);
		}
	}

}

void qs(int copy[], size_t begin, size_t end, int arr[])
{
	size_t mid, diff;

	printf("Lo:%u Hi:%u\n", (unsigned int)begin, (unsigned int)end);

	if (end - begin < 2)
		return;

	if (begin < end)
	{
		diff = (end - begin);
		diff += diff % 2;
		mid = begin + diff / 2;

		qs(arr, begin, mid - 1, copy);
		qs(arr, mid, end, copy);
		merge(copy, begin, mid, end, arr);
	}
}

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
}
