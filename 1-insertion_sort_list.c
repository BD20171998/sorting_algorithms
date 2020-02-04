#include "sort.h"
/**
 * insertion_sort_list - algorithm to sort DLL
 * @list: List that needs to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *before, *dot;

	if (!list|| !*list|| !(*list)->next)
		return;

	curr = (*list)->next;
	before = *list;

	for (; curr; curr = curr->next)
	{
		before = curr;
		printf("curr->n: %d\n", curr->n);
		while (curr->n < before->prev->n && before && before->prev)
		{	
			dot = before->prev;
			printf("dot->n: %d\n", dot->n);
			printf("before->n: %d\n", dot->n);
			if (dot->prev)
				dot->prev->next = before;
			/**Re-assign head*/
			else
				*list = before;
			if (before->next != NULL)
				before->next->prev  = dot;
			dot->next = before->next;
			before->prev = dot->prev;
			before->next = dot;
			dot->prev = before;

			print_list(*list);
		}
	}
}
