#include "sort.h"
/**
 * cocktail_sort_list - order an array using Cocktail shaker
 * @list: a duble linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *left, *right, *aux1, *aux2;
	int sw = 1;

	if (list == NULL || *list == NULL)
		return;
	head = *list;
	while (sw)
	{
		sw = 0;
		aux1 = head;
		while (aux1 && aux1->next)
		{
			right = aux1->next, left = aux1;
			if (left->n > right->n)
			{
				swap(left, right, list);
				print_list(*list), aux2 = left, left = right, right = aux2;
				aux1 = left;
				sw = 1;
			}
			aux1 = aux1->next;
		}
		aux1 = aux1->prev;
		if (sw == 0)
			break;
		sw = 0;
		while (aux1 && aux1->prev)
		{
			left = aux1->prev, right = aux1;
			if (left->n > right->n)
			{
				swap(left, right, list);
				print_list(*list), aux2 = left, left = right, right = aux2;
				aux1 = right;
				sw = 1;
			}
			aux1 = aux1->prev;
		}
	}
}

/**
 * swap - swap two nodes
 * @list: a duble linked list
 * @left: left node
 * @right: right node
 */

void swap(listint_t *left, listint_t *right, listint_t **list)
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
		right->next = left, left->prev = right, *list = right;
	}
	else
	{
		left->prev->next = right, right->prev = left->prev;
		left->next = right->next, right->next->prev = left;
		right->next = left, left->prev = right;
	}
}
