#include "sort.h"
/**
 * swap - change the nodes
 * @a: variable of struct
 * @b: variable of struct
 * Return: void.
 */
void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}
/**
 * insertion_sort_list - insertion algorithm
 * @list: douable pointer to struct
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *new = NULL, *current = NULL;

	if (!list || !*list || !(*list)->next)
		return;
	current = (*list)->next;
	while (current)
	{
		new = current;
		current = current->next;
		while (new && new->prev)
		{
			if (new->prev->n > new->n)
			{
				swap(new->prev, new);
				if (new->prev == NULL)
					*list = new;
				print_list(*list);
			}
			else
			{
				new = new->prev;
			}
		}
	}
}
