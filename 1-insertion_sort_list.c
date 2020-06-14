#include "sort.h"
/**
 * insertion_sort_list - order an array using insertion sort
 * @list: a duble linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *left, *right, *aux1, *aux2;

	if (list == NULL || *list == NULL)
		return;
	head = *list;
	while (head != NULL)
	{right = head, left = head->prev, aux1 = head;
		while (aux1 && aux1->prev)
		{right = aux1, left = aux1->prev;
			if (left->n > right->n)
			{
				if (right->next == NULL && left->prev == NULL)
				{
					left->next = NULL, right->prev = NULL;
					right->next = left, left->prev = right, *list = right;
				}
				else if (right->next == NULL)
				{
					left->prev->next = right, right->prev = left->prev;
					left->next = NULL, right->next = left, left->prev = right;
				}
				else if (left->prev == NULL)
				{
					right->prev = NULL, left->next = right->next, right->next->prev = left;
					right->next = left,	left->prev = right, *list = right;
				}
				else
				{
					left->prev->next = right, right->prev = left->prev;
					left->next = right->next, right->next->prev = left;
					right->next = left, left->prev = right;
				}
				print_list(*list), aux2 = left, left = right, right = aux2;
			}
			else
				break;
			aux1 = right, aux1 = aux1->prev;
		}
		head = aux1, head = head->next;
	}
}
