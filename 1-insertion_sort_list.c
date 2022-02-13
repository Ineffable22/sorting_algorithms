#include "sort.h"
/**
 * insertion_sort_list - swap and order nodes
 * @list: double pointer to linked list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL, *right = NULL, *left = NULL;
	listint_t *tmp1 = NULL, *tmp2 = NULL;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	while (head)
	{
		tmp1 = head;
		tmp2 = head->next;
		while (tmp1 && tmp2 && tmp1->n > tmp2->n)
		{
			right = tmp2->next;
			left = tmp1->prev;

			tmp1->next = right;
			if (right)
				right->prev = tmp1;

			tmp1->prev = tmp2;
			tmp2->prev = left;

			if (left)
				left->next = tmp2;
			else
				*list = tmp2;

			tmp2->next = tmp1;
			tmp1 = left;
			print_list(*list);
		}
		head = tmp2;
	}
}
