#include "sort.h"

void swap(listint_t **n2, listint_t **n1)
{

	listint_t **temp1, **temp2;

	temp1 = n2;
	temp2 = n1;

	(*temp1)->prev = *temp2;
	(*temp1)->next = (*temp2)->next;
	(*temp2)->prev = (*temp1)->prev;
	(*temp2)->next = *temp1;

}

/**
 * insertion_sort_list - insertion sort algo
 * @list: Pointer to a linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *n1 = *list;
	listint_t *n2 = n1->next;
	listint_t *p = n1->next;

	if (n1 == NULL || n1->next == NULL)
		return;

	for(; p; p = p->next)
	{
		if (n2->n < n1->n)
			swap(&n2, &n1);

		while(1)
		{
			if (n1->prev == NULL)
				break;
			if (n1->n > n1->prev->n)
				break;
			if (n1->n < n1->prev->n)
			{
				n1->prev = n1;
				n2->prev = n2;
				swap(&n2, &n1);
			}
		}
	}
}
