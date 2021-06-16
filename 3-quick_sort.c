#include "sort.h"
/**
 * swap - changes the numbers of list
 * @a: array
 * @b: size
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - do the swap on quick sort
 * @array: list of integers
 * @init: init position
 *@last: last position
 * @size: size of array
 * Return: quick + 1
 */

int partition(int *array, int init, int last, size_t size)
{
	int quick = init - 1, pivot = array[last], i;

	for (i = init; i <= last - 1; i++)
	{
		if (array[i] < pivot)
		{
			quick++;
			if (quick != i)
			{
				swap(&array[quick], &array[i]);
				print_array(array, size);
			}
		}
	}
	if (array[quick + 1] > array[last])
	{
		swap(&array[quick + 1], &array[last]);
		print_array(array, size);
	}
	return (quick + 1);
}

/**
 * recursion - do a recursion
 * @array: list of integers
 * @init: init position
 *@last: last position
 * @size: size of array
 * Return: void
 */

void recursion(int *array, int init, int last, size_t size)
{
	int tmp;

	if (init < last)
	{
		tmp = partition(array, init, last, size);
		recursion(array, init, tmp - 1, size);
		recursion(array, tmp + 1, last, size);
	}
}
/**
 * quick_sort - do the swap on quick sort
 * @array: list of integers
 * @size: init position
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	int init, last;

	if (array == NULL || size < 2)
		return;
	init = 0;
	last = size - 1;
	recursion(array, init, last, size);
}
